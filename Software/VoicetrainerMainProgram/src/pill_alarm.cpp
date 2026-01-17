#include <pill_alarm.h>
#include <alarms.h>
#include <freertos_wrapper.h>
#include <ui.h>
#include <vars.h>
#include <helper_functions.h>

#include "screens.h"
#include "images.h"
#include <buttons.h>
#include <button_config.h>
#include <mode_controller.h>
#include <logger.h>
#include <pill_alarm_ui.h>

TaskHandle_t pillAlarmTaskHandle = NULL;

void pill_alarm_task(void *pv)
{
  loadOverviewScreen();
  button_cmd_t receivedButton;
  while (1)
  {
    button_queue_receive(&receivedButton, portMAX_DELAY);
    handleButtonPress(receivedButton);
    vTaskDelay(pdMS_TO_TICKS(50));
  }
}

void start_pill_alarm()
{
  xTaskCreate(pill_alarm_task, "pill_alarm", 4096, NULL, 1, &pillAlarmTaskHandle);
}

void stop_pill_alarm()
{
  if (pillAlarmTaskHandle)
    vTaskDelete(pillAlarmTaskHandle);
}
