#ifndef SLEEP_ALARM_UI_H
#define SLEEP_ALARM_UI_H

#include <buttons.h>
#include <alarms.h>
#include <Arduino.h>
#include "screens.h"
#include "images.h"
#include <ui.h>

enum SleepAlarmUIState
{
    VIEW_SLEEP_ALARMS,
    EDIT_SLEEP_ALARM_HOUR,
    EDIT_SLEEP_ALARM_MINUTE,
    EDIT_WAKE_ALARM_HOUR,
    EDIT_WAKE_ALARM_MINUTE
};

void handleButtonPressSleepAlarm(const button_cmd_t &btn);
void handleViewSleepAlarmsState(const button_cmd_t &btn);
void handleEditSleepAlarmHourState(const button_cmd_t &btn);
void handleEditSleepAlarmMinuteState(const button_cmd_t &btn);
void handleEditWakeAlarmHourState(const button_cmd_t &btn);
void handleEditWakeAlarmMinuteState(const button_cmd_t &btn);

void loadSleepAlarmScreen();
void printSleepAlarms();
void loadSleepEditScreen(AlarmName alarmName);
void loadSleepEditAlarmVars(Alarm _editAlarm);

#endif