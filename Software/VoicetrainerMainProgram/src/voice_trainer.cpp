#include "freertos_wrapper.h"
#include "voice_trainer.h"
#include <ui.h>
#include "microphone.h"
#include "driver/i2s.h"
#include <parameters.h>
#include <arduinoFFT.h>
#include "esp_log.h"
#include "screens.h"
#include <button_config.h>
#include <buttons.h>
#include <voice_trainer_ui.h>
#include <mode_controller.h>

#define FFT_SIZE 1024
#define moving_average_size 20

int16_t audio_buffer_a[FFT_SIZE];
int16_t audio_buffer_b[FFT_SIZE];

int16_t moving_average_freq[moving_average_size];
int16_t moving_average_amp[moving_average_size];

bool use_buffer_a = true;

QueueHandle_t fftQueue;

TaskHandle_t audioTaskHandle = NULL;
TaskHandle_t fftTaskHandle = NULL;
TaskHandle_t uiTaskHandle = NULL;

double vReal[FFT_SIZE];
double vImag[FFT_SIZE];

ArduinoFFT<double> FFT = ArduinoFFT<double>(vReal, vImag, FFT_SIZE, MIC_SAMPLE_RATE);

static inline lv_coord_t map_range(double value, double inMin, double inMax,
                                   double outMin, double outMax)
{
  if (value <= inMin)
    return (lv_coord_t)outMin;
  if (value >= inMax)
    return (lv_coord_t)outMax;

  double ratio = (value - inMin) / (inMax - inMin);
  return (lv_coord_t)(outMin + ratio * (outMax - outMin));
}

void collect_audio_samples_task(void *pv)
{
  i2s_start(I2S_PORT);

  while (true)
  {
    size_t bytes_read = 0;
    int16_t *target_buffer = use_buffer_a ? audio_buffer_a : audio_buffer_b;

    i2s_read(I2S_PORT, target_buffer, sizeof(int16_t) * FFT_SIZE, &bytes_read, portMAX_DELAY);

    if (bytes_read == FFT_SIZE * sizeof(int16_t))
    {
      xQueueSend(fftQueue, &target_buffer, portMAX_DELAY);
      use_buffer_a = !use_buffer_a;
    }
  }
}

void fft_task(void *pv)
{
  bool filled = false;
  uint moving_average_position = 0;
  lv_coord_t freqPos = 0;
  lv_coord_t ampPos = 0;
  int16_t *received_buffer;
  double average_dB = 0;
  double average_freq = 0;

  vTaskDelay(pdMS_TO_TICKS(500));
  while (true)
  {
    if (xQueueReceive(fftQueue, &received_buffer, portMAX_DELAY) == pdTRUE)
    {

      for (int i = 0; i < FFT_SIZE; i++)
      {
        vReal[i] = (double)received_buffer[i];
        vImag[i] = 0.0;
      }

      FFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);
      FFT.compute(FFTDirection::Forward);
      FFT.complexToMagnitude();

      // Frequentieresolutie
      double bin_resolution = (double)MIC_SAMPLE_RATE / FFT_SIZE;
      int low_bin = (int)(voiceMinFreq / bin_resolution);
      int high_bin = (int)(voiceMaxFreq / bin_resolution);

      double peak_value = 0;
      double peak_freq = 0;

      for (int i = low_bin; i <= high_bin; i++)
      {
        if (vReal[i] > peak_value)
        {
          peak_value = vReal[i];
          peak_freq = i * bin_resolution;
        }
      }

      double peak_dB = 20.0 * log10(peak_value);

      moving_average_freq[moving_average_position] = peak_freq;
      moving_average_amp[moving_average_position] = peak_dB;
      moving_average_position++;
      if (moving_average_position >= moving_average_size)
      {
        moving_average_position = 0;
        filled = true;
      }

      if (filled)
      {
        double sumFreq = 0;
        double sumAmp = 0;
        for (int i = 0; i < moving_average_size; i++)
        {
          sumFreq += moving_average_freq[i];
          sumAmp += moving_average_amp[i];
        }
        average_freq = sumFreq / (double)moving_average_size;
        average_dB = sumAmp / (double)moving_average_size;
      }

      if (average_dB >= voiceMinAmp)
      {
        if (average_freq < voiceAverageFreq)
        {
          freqPos = map_range(average_freq, voiceMinFreq, voiceAverageFreq, -100, 0);
        }
        else
        {
          freqPos = map_range(average_freq, voiceAverageFreq, voiceMaxFreq, 0, 100);
        }
        if (average_dB < voiceAverageAmp)
        {
          ampPos = map_range(average_dB, voiceMinAmp, voiceAverageAmp, 100, 0);
        }
        else
        {
          ampPos = map_range(average_dB, voiceAverageAmp, voiceMaxAmp, 0, -100);
        }
      }
      Serial.print(average_freq);
      Serial.print("   ");
      Serial.println(average_dB);

      lv_obj_set_pos(objects.circle_voice_position, freqPos, ampPos);
    }
  }
}

void update_trainer_ui_task(void *pv)
{
  loadScreen(SCREEN_ID_SCREEN_TRAIN_VOICE);
  loadButtons(ButtonConfiguration::VOICE_TRAINER);
  button_cmd_t receivedButton;
  while (true)
  {
    button_queue_receive(&receivedButton, portMAX_DELAY);
    handleButtonPressVoiceTrainer(receivedButton);
    vTaskDelay(pdMS_TO_TICKS(50));
  }
}

void start_voice_trainer()
{
  setup_i2s();
  i2s_start(I2S_PORT);

  fftQueue = xQueueCreate(2, sizeof(int16_t *));
  xTaskCreate(collect_audio_samples_task, "AudioTask", 4096, NULL, 1, &audioTaskHandle);
  xTaskCreate(fft_task, "FFTTask", 4096, NULL, 1, &fftTaskHandle);
  xTaskCreate(update_trainer_ui_task, "UITrainer", 2048, NULL, 1, &uiTaskHandle);
}

void stop_voice_trainer()
{
  i2s_stop(I2S_PORT);
  i2s_driver_uninstall(I2S_PORT);

  vQueueDelete(fftQueue);
  if (audioTaskHandle)
    vTaskDelete(audioTaskHandle);
  if (fftTaskHandle)
    vTaskDelete(fftTaskHandle);
  if (uiTaskHandle)
    vTaskDelete(uiTaskHandle);
}
