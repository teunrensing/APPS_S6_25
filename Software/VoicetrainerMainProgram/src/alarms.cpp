#include "alarms.h"
#include "mp3_player.h"
#include "time_utils.h"
#include "mode_controller.h"
#include <logger.h>
#include <Preferences.h>

Preferences prefs;
Alarm alarms[MAX_ALARMS];
TaskHandle_t alarm_task_handle = NULL;

void saveAlarms(const Alarm *alarms, size_t count)
{
  prefs.begin("alarms", false);
  prefs.putUInt("count", count);
  for (size_t i = 0; i < count; ++i)
  {
    char key[12];
    snprintf(key, sizeof(key), "alarm%u", i);
    prefs.putBytes(key, &alarms[i], sizeof(Alarm));
  }
  prefs.end();
}

size_t loadAlarms(Alarm *alarms, size_t maxCount)
{
  prefs.begin("alarms", true);
  size_t count = prefs.getUInt("count", 0);
  if (count > maxCount)
    count = maxCount;
  for (size_t i = 0; i < count; ++i)
  {
    char key[12];
    snprintf(key, sizeof(key), "alarm%u", i);
    prefs.getBytes(key, &alarms[i], sizeof(Alarm));
  }
  prefs.end();
  return count;
}

bool setAlarm(uint8_t hour, uint8_t minute, AlarmName name, bool active)
{
  size_t count = loadAlarms(alarms, MAX_ALARMS);

  for (size_t i = 0; i < count; ++i)
  {
    if (alarms[i].name == name)
    {
      alarms[i].hour = hour;
      alarms[i].minute = minute;
      alarms[i].active = active;
      saveAlarms(alarms, count);
      return true; // updated
    }
  }

  if (count >= MAX_ALARMS)
  {
    log_message("Geen ruimte om alarm toe te voegen.");
    return false;
  }
  alarms[count].hour = hour;
  alarms[count].minute = minute;
  alarms[count].name = name;
  alarms[count].active = active;
  count++;
  saveAlarms(alarms, count);
  return true; // nieuw toegevoegd
}

bool getAlarm(AlarmName name, Alarm &result)
{
  size_t count = loadAlarms(alarms, MAX_ALARMS);

  for (size_t i = 0; i < count; ++i)
  {
    if (alarms[i].name == name)
    {
      result = alarms[i];
      return true;
    }
  }

  setAlarm(0, 0, name, false);
  count = loadAlarms(alarms, MAX_ALARMS);

  for (size_t i = 0; i < count; ++i)
  {
    if (alarms[i].name == name)
    {
      result = alarms[i];
      return true;
    }
  }
  return false; // niet gevonden
}

void check_alarms()
{
  log_message("Alarms checked");
  int hour = getCurrentHour();
  int minute = getCurrentMinute();
  for (size_t i = 0; i < MAX_ALARMS; i++)
  {
    if (alarms[i].active)
    {
      if (alarms[i].hour == hour && alarms[i].minute == minute)
      {
        if (alarms[i].name == AlarmName::SLEEPALARM_WAKE)
        {
          change_mode(AppMode::MODE_SLEEP_ALARM);
          set_mp3_volume(30);
          play_mp3_sound(mp3Sounds::AlarmWakeUp);
        }
        else
        {
          change_mode(AppMode::MODE_PILL_ALARM);
          set_mp3_volume(20);
          play_mp3_sound(mp3Sounds::SpeechPillen);
          vTaskDelay(pdMS_TO_TICKS(5000));
          play_mp3_sound(mp3Sounds::AlarmPills);
          vTaskDelay(pdMS_TO_TICKS(8000));
          play_mp3_sound(mp3Sounds::SpeechPillen);
        }
      }
    }
  }
}

void alarm_task(void *pv)
{
  alarm_task_handle = xTaskGetCurrentTaskHandle();
  while (1)
  {
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    check_alarms();
  }
}

void start_alarms_task()
{
  xTaskCreate(alarm_task, "Buttons", 2048, NULL, 1, NULL);
}

const char *alarmNameToString(AlarmName name)
{
  switch (name)
  {
  case SLEEPALARM_SLEEP:
    return "Slaap wekker";
  case SLEEPALARM_WAKE:
    return "Wakker wekker";
  case PILLALARM_1:
    return "Pillen wekker 1";
  case PILLALARM_2:
    return "Pillen wekker 2";
  case PILLALARM_3:
    return "Pillen wekker 3";
  case PILLALARM_4:
    return "Pillen wekker 4";
  case PILLALARM_5:
    return "Pillen wekker 5";
  case PILLALARM_6:
    return "Pillen wekker 6";
  case PILLALARM_7:
    return "Pillen wekker 7";
  case PILLALARM_8:
    return "Pillen wekker 8";
  default:
    return "Onbekend";
  }
}
