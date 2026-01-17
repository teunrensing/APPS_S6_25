#include "freertos_wrapper.h"
#include "mode_config.h"
#include "mode_controller.h"
#include "buttons.h"
#include "logger.h"
#include "display.h"
#include "ui.h"
#include "time_utils.h"
#include "alarms.h"
#include "mp3_player.h"
#include "home_button.h"
#include <i2c.h>
#include <microphone.h>

QueueHandle_t mode_change_queue;
QueueHandle_t log_queue;

void setup()
{
  Serial.begin(115200);
  init_display();
  ui_init();
  init_mp3();
  i2cInit();
  button_init();
  init_home_button();

  mode_change_queue = xQueueCreate(5, sizeof(AppMode));
  log_queue = xQueueCreate(10, sizeof(char[128]));

  start_display_task();
  start_button_task();
  start_logger_task();
  start_time_task();
  start_alarms_task();
  start_mode_controller_task();
}

void loop()
{
  ;
}
