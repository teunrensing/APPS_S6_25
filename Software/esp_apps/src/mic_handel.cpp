#include <Arduino.h>
#include "helperfn.hpp"
#include <vars.h>
#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <ui.h>
#include <screens.h>
#include "mic_handel.hpp"
#include "microphone_i2s.hpp"
#include "signalprocessing.hpp"
#include "display.hpp"
#include "pinout.hpp"


static constexpr bool is_powerof2(size_t size)
{
    return size && ((size & (size - 1)) == 0);
}

enum class AudioStatus
{
    WAIT,
    VEC1_READY,
    VEC2_READY
};
AudioStatus audio_status = AudioStatus::WAIT;

namespace dsp
{
    void remove_dc(std::vector<float> &vec);
    void hamming_windows(std::vector<float> &vec);
    void custom_logarithm_abs(std::vector<float> &vec);
    void fouriertransf(std::vector<float> &vec);
    void inversefouriertransf(std::vector<float> &vec);
}

// read_audio() globals
Microphone inmp441(I2S_NUM_0, MIC_CLK, MIC_WS, MIC_DATA);
constexpr size_t SAMPLES_LENGTH = Microphone::buffer_size * 4;
constexpr int sample_rate = Microphone::sample_rate;
std::vector<float> audio_vec1(SAMPLES_LENGTH);
std::vector<float> audio_vec2(SAMPLES_LENGTH);
static_assert(SAMPLES_LENGTH, "SAMPLES_LENGTH, which determines vector size, must be a power of 2!");
std::vector<float> audiodata;

int volumeValue = 0;
int frequencyValue = 0;
int thres_dB = 0;
int thres_Hz = 0;
bool dataReady = false;

void uiTask(void *pvParameters)
{
    while (true)
    {
        lv_timer_handler();
        ui_tick();
        //buttons_function();
        update_time();

        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

void update_ball_position_async(void *param)
{
    static constexpr int center_x = 210;
    static constexpr int center_y = 130;
    static constexpr int max_radius = 80;
    int ok_volume = 30; // x
    int ok_freq = 150;  // y
    // 70 -> 300 //335
    // 80px space
    int final_x = 0;
    int final_y = 0;
    int result_volume = volumeValue -ok_volume;
    int result_frequency = frequencyValue-ok_freq;

    //final_x = center_x+result_volume*4;
    final_x = 125 + 4 * volumeValue;

   // final_y = center_y +result_frequency;
    final_y = 245 - (frequencyValue - 70);
    if (final_y < 45)
    {
        final_y = 45;
    }

    Serial.printf("Ball: x,y(%d, %d)\n", final_x, final_y);

    if (final_x > (center_x + max_radius))
    {
        final_x = center_x + max_radius;
    }
    if (final_x < (center_x - max_radius))
    {
        final_x = center_x - max_radius;
    }

    lv_obj_set_pos(objects.ball, final_x, final_y);
    Serial.printf("ΔVol: %+d dB | ΔFreq: %+d Hz → Ball: (%d, %d)\n",
                  (volumeValue - thres_dB),
                  (frequencyValue - thres_Hz),
                  final_x, final_y);
}

void process_audio(std::vector<float> &audio)
{
    static constexpr size_t FREQ_PEAKS_MAX_LENGTH = 1.0f * sample_rate / SAMPLES_LENGTH * 2; // 2 seconds
    static constexpr unsigned int min_fundamental_frequency = 70;
    static constexpr unsigned int max_fundamental_frequency = 300; // frequency range of a male voice is between 70 and 200 hz
    static std::deque<float> frequency_peaks;
    static dsp::signal_point peak;

    dsp::remove_dc(audio);
    dsp::hamming_windows(audio);

    const size_t min_pos = sample_rate / max_fundamental_frequency;
    const size_t max_pos = sample_rate / min_fundamental_frequency;
    peak = dsp::get_peak(audio, min_pos, max_pos + 1, sample_rate);

    int Decibel = 20 * log10(peak.amplitude / 0.8);

    dsp::fouriertransf(audio);
    dsp::custom_logarithm_abs(audio);
    dsp::inversefouriertransf(audio);
    peak = dsp::get_peak(audio, min_pos, max_pos + 1, sample_rate);

    if (peak.amplitude > MIN_PEAK_AMPLITUDE)
    {
        volumeValue = Decibel;           // Final usable volume value
        frequencyValue = peak.frequency; // Final usable frequency value

        // Send data to statemachine to be used
        set_var_amplitude(volumeValue);
        set_var_frequency(frequencyValue);

        lv_async_call(update_ball_position_async, nullptr);
    }
}

void task_read_audio(void *params)
{
    while (true)
    {
        // Read 2 audio vectors
        if (inmp441.read_full(audio_vec1) == ESP_OK)
        {
            audio_status = AudioStatus::VEC1_READY;
            vTaskDelay(pdMS_TO_TICKS(2));
        }
        if (inmp441.read_full(audio_vec2) == ESP_OK)
        {
            audio_status = AudioStatus::VEC2_READY;
            vTaskDelay(pdMS_TO_TICKS(2));
        }
    }
}

void task_process_audio(void *params)
{

    while (true)
    {
        switch (audio_status)
        {
        case AudioStatus::VEC1_READY:
            audio_status = AudioStatus::WAIT;
            process_audio(audio_vec1);
            break;
        case AudioStatus::VEC2_READY:
            audio_status = AudioStatus::WAIT;
            process_audio(audio_vec2);
            break;
        default:
            vTaskDelay(pdMS_TO_TICKS(10));
            break;
        }
    }
}

static int volumeBuf[20];
static int freqBuf[20];

void calibration(int index, std::vector<float> &audio)
{
    static constexpr size_t FREQ_PEAKS_MAX_LENGTH = 1.0f * sample_rate / SAMPLES_LENGTH * 2; // 2 seconds
    static constexpr unsigned int min_fundamental_frequency = 70;
    static constexpr unsigned int max_fundamental_frequency = 300; // frequency range of a male voice is between 70 and 200 hz
    static std::deque<float> frequency_peaks;
    static dsp::signal_point peak;

    dsp::remove_dc(audio);
    dsp::hamming_windows(audio);

    const size_t min_pos = sample_rate / max_fundamental_frequency;
    const size_t max_pos = sample_rate / min_fundamental_frequency;
    peak = dsp::get_peak(audio, min_pos, max_pos + 1, sample_rate);

    int Decibel = 20 * log10(peak.amplitude / 0.8);

    dsp::fouriertransf(audio);
    dsp::custom_logarithm_abs(audio);
    dsp::inversefouriertransf(audio);

    peak = dsp::get_peak(audio, min_pos, max_pos + 1, sample_rate);

    if (peak.amplitude > MIN_PEAK_AMPLITUDE)
    {
        volumeValue = Decibel;           // Final usable volume value
        frequencyValue = peak.frequency; // Final usable frequency value

        // Send data to statemachine to be used
        volumeBuf[index] = volumeValue;
        freqBuf[index] = frequencyValue;
    }
}

void task_calibration(void *params)
{
    int index = 0;
    while (true)
    {
        // Read 2 audio vectors

        if (index > 19)
        {
            // get hoogste waardes voor freq en volume om de threshold te zetten.
            int volumeHigh = volumeBuf[0];
            int freqLow = freqBuf[0];
            for (int i = 0; i < 20; i++)
            {
                if (volumeBuf[i] > volumeHigh)
                {
                    volumeHigh = volumeBuf[i];
                }
                if (freqBuf[i] < freqLow)
                {
                    freqLow = freqBuf[i];
                }
            }
            thres_dB = volumeHigh - DB_CALIBRATION_OFFSET;
            thres_Hz = freqLow + HZ_CALIBRATION_OFFSET;

            trainerTreshold = false;

            vTaskDelete(nullptr); // Kill this task
        }
        else
        {
            if (inmp441.read_full(audio_vec1) == ESP_OK)
            {
                calibration(index, audio_vec1);
                index = index + 1;
            }
            if (inmp441.read_full(audio_vec2) == ESP_OK)
            {
                calibration(index, audio_vec2);
                index = index + 1;
            }
        }
    }
}
