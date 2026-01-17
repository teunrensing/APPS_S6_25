#include <Arduino.h>
#include <time.h>
#include "time_utils.h"
#include "wifi_handler.h"
#include "vars.h"
#include <logger.h>

extern TaskHandle_t alarm_task_handle;

void initTime()
{
  struct tm timeinfo;

  while (!isWiFiConnected())
  {
    connectToWiFi();
    vTaskDelay(pdMS_TO_TICKS(500));
  }

  configTime(0, 0, "pool.ntp.org", "time.nist.gov");

  // Wacht tot tijd geldig is
  while (!getLocalTime(&timeinfo))
  {
    vTaskDelay(pdMS_TO_TICKS(500));
  }

  setenv("TZ", "CET-1CEST,M3.5.0/2,M10.5.0/3", 1);
  tzset();

  disconnectWiFi();
}

static bool getTimeStruct(struct tm *timeinfo)
{
  if (!getLocalTime(timeinfo))
  {
    log_message("Kan lokale tijd niet ophalen");
    return false;
  }
  return true;
}

const char *getCurrentHourStr()
{
  static char buffer[3];
  struct tm timeinfo;
  if (getTimeStruct(&timeinfo))
  {
    snprintf(buffer, sizeof(buffer), "%02d", timeinfo.tm_hour);
    return buffer;
  }
  return "??";
}

const char *getCurrentMinuteStr()
{
  static char buffer[3];
  struct tm timeinfo;
  if (getTimeStruct(&timeinfo))
  {
    snprintf(buffer, sizeof(buffer), "%02d", timeinfo.tm_min);
    return buffer;
  }
  return "??";
}

int getCurrentHour()
{
  struct tm timeinfo;
  return getTimeStruct(&timeinfo) ? timeinfo.tm_hour : -1;
}

int getCurrentMinute()
{
  struct tm timeinfo;
  return getTimeStruct(&timeinfo) ? timeinfo.tm_min : -1;
}

void time_task(void *pv)
{
  initTime();
  int lastMinute = -1;
  while (1)
  {
    set_var_var_current_hour(getCurrentHourStr());
    set_var_var_current_minute(getCurrentMinuteStr());

    int currentMinute = getCurrentMinute();
    if (lastMinute != currentMinute)
    {
      lastMinute = currentMinute;
      if (alarm_task_handle != NULL)
      {
        xTaskNotifyGive(alarm_task_handle);
      };
    }

    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void start_time_task()
{
  xTaskCreate(time_task, "TimeTask", 4096, NULL, 1, NULL);
}
