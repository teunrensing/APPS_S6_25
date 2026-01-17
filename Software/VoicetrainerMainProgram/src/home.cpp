#include <home.h>
#include <freertos_wrapper.h>
#include <ui.h>
#include <buttons.h>
#include <mode_controller.h>
#include <button_config.h>

TaskHandle_t homeTaskHandle = NULL;

void home_task(void *pv)
{
  loadScreen(SCREEN_ID_SCREEN_HOME);
  loadButtons(ButtonConfiguration::HOME);
  button_cmd_t receivedButton;
  while (1)
  {
    button_queue_receive(&receivedButton, portMAX_DELAY);
    switch (receivedButton.icon)
    {
    case Display_Icon::SleepAlarm:
      change_mode(AppMode::MODE_SLEEP_ALARM);
      break;
    case Display_Icon::PillAlarm:
      change_mode(AppMode::MODE_PILL_ALARM);
      break;
    case Display_Icon::SpeechTrainer:
      change_mode(AppMode::MODE_VOICE_TRAINER);
      break;

    default:
      break;
    }
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void start_home()
{
  xTaskCreate(home_task, "Home", 2048, NULL, 1, &homeTaskHandle);
}

void stop_home()
{
  if (homeTaskHandle)
    vTaskDelete(homeTaskHandle);
}