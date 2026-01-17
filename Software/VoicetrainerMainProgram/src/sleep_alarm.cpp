#include <sleep_alarm.h>
#include <freertos_wrapper.h>
#include <ui.h>
#include <sleep_alarm_ui.h>

TaskHandle_t sleepAlarmTaskHandle = NULL;

void sleep_alarm_task(void *pv)
{
  loadSleepAlarmScreen();
  button_cmd_t receivedButton;
  while (1)
  {
    button_queue_receive(&receivedButton, portMAX_DELAY);
    handleButtonPressSleepAlarm(receivedButton);
    vTaskDelay(pdMS_TO_TICKS(50));
  }
}

void start_sleep_alarm()
{
  xTaskCreate(sleep_alarm_task, "sleep_alarm", 4096, NULL, 1, &sleepAlarmTaskHandle);
}

void stop_sleep_alarm()
{
  if (sleepAlarmTaskHandle)
    vTaskDelete(sleepAlarmTaskHandle);
}
