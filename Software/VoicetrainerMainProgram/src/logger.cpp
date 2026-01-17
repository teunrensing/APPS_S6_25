#include "freertos_wrapper.h"
#include "mode_config.h"

void logger_task(void *pv) {
  char msg[128];
  while (true) {
    if (xQueueReceive(log_queue, &msg, portMAX_DELAY)) {
      Serial.println(msg);
    }
  }
}

void log_message(const char* msg) {
  xQueueSend(log_queue, msg, 0);
}

void start_logger_task() {
  xTaskCreate(logger_task, "Logger", 2048, NULL, 1, NULL);
}
