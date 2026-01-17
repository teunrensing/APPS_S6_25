#ifndef PILL_ALARM_UI_H
#define PILL_ALARM_UI_H

#include <buttons.h>
#include <alarms.h>
#include <Arduino.h>
#include "screens.h"
#include "images.h"
#include <ui.h>

enum PillAlarmUIState
{
    VIEW_ALARMS,
    EDIT_ALARM,
    SET_HOUR,
    SET_MINUTE
};

void handleButtonPress(const button_cmd_t &btn);
void handleViewAlarmsState(const button_cmd_t &btn);
void handleEditAlarmState(const button_cmd_t &btn);
void handleSetHourState(const button_cmd_t &btn);
void handleSetMinuteState(const button_cmd_t &btn);

void printPillAlarms();
void loadEditScreen(AlarmName alarmName);
void loadEditAlarmVars(Alarm _editAlarm);
void loadOverviewScreen();

#endif