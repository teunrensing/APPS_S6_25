// activate and store alarms.

#ifndef ALARMS_H
#define ALARMS_H

#include <Arduino.h>

#define MAX_ALARMS 10

extern TaskHandle_t alarm_task_handle;

enum AlarmName : uint8_t
{
  SLEEPALARM_SLEEP = 1,
  SLEEPALARM_WAKE,
  PILLALARM_1,
  PILLALARM_2,
  PILLALARM_3,
  PILLALARM_4,
  PILLALARM_5,
  PILLALARM_6,
  PILLALARM_7,
  PILLALARM_8
};

struct Alarm
{
  uint8_t hour;
  uint8_t minute;
  AlarmName name;
  bool active;
};

void start_alarms_task();
const char *alarmNameToString(AlarmName name);
bool setAlarm(uint8_t hour, uint8_t minute, AlarmName name, bool active);
bool getAlarm(AlarmName name, Alarm &result);

#endif
