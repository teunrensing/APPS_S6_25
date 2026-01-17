#include "freertos_wrapper.h"
#include "mode_config.h"
#include "mode_controller.h"
#include "voice_trainer.h"
#include "pill_alarm.h"
#include "sleep_alarm.h"
#include "home.h"

AppMode currentMode = MODE_HOME;

void mode_controller_task(void *pv)
{
  AppMode newMode;
  while (true)
  {
    if (xQueueReceive(mode_change_queue, &newMode, portMAX_DELAY))
    {
      stop_mode_tasks(currentMode);
      currentMode = newMode;
      start_mode_tasks(currentMode);
    }
  }
}

void start_mode_tasks(AppMode mode)
{
  if (mode == MODE_HOME)
    start_home();
  else if (mode == MODE_VOICE_TRAINER)
    start_voice_trainer();
  else if (mode == MODE_PILL_ALARM)
    start_pill_alarm();
  else if (mode == MODE_SLEEP_ALARM)
    start_sleep_alarm();
}

void stop_mode_tasks(AppMode mode)
{
  if (mode == MODE_HOME)
    stop_home();
  else if (mode == MODE_VOICE_TRAINER)
    stop_voice_trainer();
  else if (mode == MODE_PILL_ALARM)
    stop_pill_alarm();
  else if (mode == MODE_SLEEP_ALARM)
    stop_sleep_alarm();
}

void change_mode(AppMode _newMode)
{
  AppMode newMode = _newMode;
  xQueueSend(mode_change_queue, &newMode, 0);
}

void start_mode_controller_task()
{
  xTaskCreate(mode_controller_task, "ModeController", 2048, NULL, 1, NULL);
  AppMode startMode = MODE_HOME;
  xQueueSend(mode_change_queue, &startMode, 0);
}
