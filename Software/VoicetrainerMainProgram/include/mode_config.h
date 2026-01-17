#ifndef CONFIG_H
#define CONFIG_H

#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>

enum AppMode {
  MODE_HOME,
  MODE_VOICE_TRAINER,
  MODE_PILL_ALARM,
  MODE_SLEEP_ALARM
};

extern QueueHandle_t mode_change_queue;
extern QueueHandle_t log_queue;

#endif
