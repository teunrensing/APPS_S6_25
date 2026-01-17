#include <sleep_alarm_ui.h>
#include <button_config.h>
#include <mode_controller.h>
#include <ui.h>
#include <vars.h>
#include <helper_functions.h>
#include "screens.h"
#include "images.h"
#include <freertos_wrapper.h>
#include <logger.h>

SleepAlarmUIState currentSleepAlarmState = SleepAlarmUIState::VIEW_SLEEP_ALARMS;
Alarm editSleepAlarm;

void handleButtonPressSleepAlarm(const button_cmd_t &btn)
{
    switch (currentSleepAlarmState)
    {
    case SleepAlarmUIState::VIEW_SLEEP_ALARMS:
        handleViewSleepAlarmsState(btn);
        break;
    case SleepAlarmUIState::EDIT_SLEEP_ALARM_HOUR:
        handleEditSleepAlarmHourState(btn);
        break;
    case SleepAlarmUIState::EDIT_SLEEP_ALARM_MINUTE:
        handleEditSleepAlarmMinuteState(btn);
        break;
    case SleepAlarmUIState::EDIT_WAKE_ALARM_HOUR:
        handleEditWakeAlarmHourState(btn);
        break;
    case SleepAlarmUIState::EDIT_WAKE_ALARM_MINUTE:
        handleEditWakeAlarmMinuteState(btn);
        break;
    default:
        currentSleepAlarmState = SleepAlarmUIState::VIEW_SLEEP_ALARMS;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}

void handleViewSleepAlarmsState(const button_cmd_t &btn)
{
    switch (btn.icon)
    {
    case Display_Icon::Off:
        getAlarm(AlarmName::SLEEPALARM_WAKE, editSleepAlarm);
        editSleepAlarm.active = false;
        setAlarm(editSleepAlarm.hour, editSleepAlarm.minute, editSleepAlarm.name, editSleepAlarm.active);
        loadSleepAlarmScreen();
        break;
    case Display_Icon::On:
        getAlarm(AlarmName::SLEEPALARM_WAKE, editSleepAlarm);
        editSleepAlarm.active = true;
        setAlarm(editSleepAlarm.hour, editSleepAlarm.minute, editSleepAlarm.name, editSleepAlarm.active);
        loadSleepAlarmScreen();
        break;
    case Display_Icon::Edit:
        loadButtons(ButtonConfiguration::EDIT_ALARM_HOUR);
        lv_obj_add_state(objects.label_edit_hour, LV_STATE_CHECKED);
        loadSleepEditScreen(AlarmName::SLEEPALARM_SLEEP);
        currentSleepAlarmState = SleepAlarmUIState::EDIT_SLEEP_ALARM_HOUR;
        break;
    default:
        currentSleepAlarmState = SleepAlarmUIState::VIEW_SLEEP_ALARMS;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}

void handleEditSleepAlarmHourState(const button_cmd_t &btn)
{
    switch (btn.icon)
    {
    case Display_Icon::Increase:
        editSleepAlarm.hour++;
        if (editSleepAlarm.hour >= 24)
        {
            editSleepAlarm.hour = 0;
        }
        set_var_var_edit_hour(uint8ToString(editSleepAlarm.hour));
        break;
    case Display_Icon::Decrease:
        editSleepAlarm.hour--;
        if (editSleepAlarm.hour >= 24)
        {
            editSleepAlarm.hour = 23;
        }
        set_var_var_edit_hour(uint8ToString(editSleepAlarm.hour));
        break;
    case Display_Icon::Back:
        loadSleepAlarmScreen();
        currentSleepAlarmState = SleepAlarmUIState::VIEW_SLEEP_ALARMS;
        break;
    case Display_Icon::Next:
        loadButtons(ButtonConfiguration::EDIT_ALARM_MINUTE);
        lv_obj_clear_state(objects.label_edit_hour, LV_STATE_CHECKED);
        lv_obj_add_state(objects.label_edit_minute, LV_STATE_CHECKED);
        currentSleepAlarmState = SleepAlarmUIState::EDIT_SLEEP_ALARM_MINUTE;
        break;
    default:
        currentSleepAlarmState = SleepAlarmUIState::VIEW_SLEEP_ALARMS;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}

void handleEditSleepAlarmMinuteState(const button_cmd_t &btn)
{
    switch (btn.icon)
    {
    case Display_Icon::Increase:
        editSleepAlarm.minute += 5;
        if (editSleepAlarm.minute >= 60)
        {
            editSleepAlarm.minute = 0;
        }
        set_var_var_edit_minute(uint8ToString(editSleepAlarm.minute, 2));
        break;
    case Display_Icon::Decrease:
        editSleepAlarm.minute -= 5;
        if (editSleepAlarm.minute >= 60)
        {
            editSleepAlarm.minute = 55;
        }
        set_var_var_edit_minute(uint8ToString(editSleepAlarm.minute, 2));
        break;
    case Display_Icon::Back:
        loadButtons(ButtonConfiguration::EDIT_ALARM_HOUR);
        lv_obj_add_state(objects.label_edit_hour, LV_STATE_CHECKED);
        lv_obj_clear_state(objects.label_edit_minute, LV_STATE_CHECKED);
        currentSleepAlarmState = SleepAlarmUIState::EDIT_SLEEP_ALARM_HOUR;
        break;
    case Display_Icon::Confirm:
        setAlarm(editSleepAlarm.hour, editSleepAlarm.minute, editSleepAlarm.name, editSleepAlarm.active);
        loadButtons(ButtonConfiguration::EDIT_ALARM_HOUR);
        lv_obj_add_state(objects.label_edit_hour, LV_STATE_CHECKED);
        lv_obj_clear_state(objects.label_edit_minute, LV_STATE_CHECKED);
        loadSleepEditScreen(AlarmName::SLEEPALARM_WAKE);
        currentSleepAlarmState = SleepAlarmUIState::EDIT_WAKE_ALARM_HOUR;
        break;
    default:
        currentSleepAlarmState = SleepAlarmUIState::VIEW_SLEEP_ALARMS;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}

void handleEditWakeAlarmHourState(const button_cmd_t &btn)
{
    switch (btn.icon)
    {
    case Display_Icon::Increase:
        editSleepAlarm.hour++;
        if (editSleepAlarm.hour >= 24)
        {
            editSleepAlarm.hour = 0;
        }
        set_var_var_edit_hour(uint8ToString(editSleepAlarm.hour));
        break;
    case Display_Icon::Decrease:
        editSleepAlarm.hour--;
        if (editSleepAlarm.hour >= 24)
        {
            editSleepAlarm.hour = 23;
        }
        set_var_var_edit_hour(uint8ToString(editSleepAlarm.hour));
        break;
    case Display_Icon::Back:
        loadSleepAlarmScreen();
        currentSleepAlarmState = SleepAlarmUIState::VIEW_SLEEP_ALARMS;
        break;
    case Display_Icon::Next:
        loadButtons(ButtonConfiguration::EDIT_ALARM_MINUTE);
        lv_obj_clear_state(objects.label_edit_hour, LV_STATE_CHECKED);
        lv_obj_add_state(objects.label_edit_minute, LV_STATE_CHECKED);
        currentSleepAlarmState = SleepAlarmUIState::EDIT_WAKE_ALARM_MINUTE;
        break;
    default:
        currentSleepAlarmState = SleepAlarmUIState::VIEW_SLEEP_ALARMS;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}

void handleEditWakeAlarmMinuteState(const button_cmd_t &btn)
{
    switch (btn.icon)
    {
    case Display_Icon::Increase:
        editSleepAlarm.minute += 5;
        if (editSleepAlarm.minute >= 60)
        {
            editSleepAlarm.minute = 0;
        }
        set_var_var_edit_minute(uint8ToString(editSleepAlarm.minute, 2));
        break;
    case Display_Icon::Decrease:
        editSleepAlarm.minute -= 5;
        if (editSleepAlarm.minute >= 60)
        {
            editSleepAlarm.minute = 55;
        }
        set_var_var_edit_minute(uint8ToString(editSleepAlarm.minute, 2));
        break;
    case Display_Icon::Back:
        loadButtons(ButtonConfiguration::EDIT_ALARM_HOUR);
        lv_obj_add_state(objects.label_edit_hour, LV_STATE_CHECKED);
        lv_obj_clear_state(objects.label_edit_minute, LV_STATE_CHECKED);
        currentSleepAlarmState = SleepAlarmUIState::EDIT_WAKE_ALARM_HOUR;
        break;
    case Display_Icon::Confirm:
        setAlarm(editSleepAlarm.hour, editSleepAlarm.minute, editSleepAlarm.name, editSleepAlarm.active);
        loadSleepAlarmScreen();
        currentSleepAlarmState = SleepAlarmUIState::VIEW_SLEEP_ALARMS;
        break;
    default:
        currentSleepAlarmState = SleepAlarmUIState::VIEW_SLEEP_ALARMS;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}

void loadSleepEditScreen(AlarmName alarmName)
{
    getAlarm(alarmName, editSleepAlarm);
    loadSleepEditAlarmVars(editSleepAlarm);
    loadScreen(ScreensEnum::SCREEN_ID_SCREEN_EDIT_ALARM);
}

void loadSleepEditAlarmVars(Alarm _editAlarm)
{
    set_var_var_edit_hour(uint8ToString(_editAlarm.hour));
    set_var_var_edit_minute(uint8ToString(_editAlarm.minute, 2));
    set_var_var_alarm_type(alarmNameToString(_editAlarm.name));
}

void loadSleepAlarmScreen()
{
    lv_obj_clear_state(objects.label_edit_hour, LV_STATE_CHECKED);
    lv_obj_clear_state(objects.label_edit_minute, LV_STATE_CHECKED);
    getAlarm(AlarmName::SLEEPALARM_WAKE, editSleepAlarm);
    loadButtons(ButtonConfiguration::SLEEPALARM_OPTIONS);
    printSleepAlarms();
    if (!editSleepAlarm.active)
    {
        button_queue_send(Button_Name::UpLeft, Display_Icon::On);
    }
    loadScreen(ScreensEnum::SCREEN_ID_SCREEN_SLEEP_ALARM);
}

void printSleepAlarms()
{
    Alarm sleepAlarm;

    if (getAlarm(AlarmName::SLEEPALARM_SLEEP, sleepAlarm))
    {
        set_var_var_sleep_hour(uint8ToString(sleepAlarm.hour));
        set_var_var_sleep_minute(uint8ToString(sleepAlarm.minute, 2));
    }
    if (getAlarm(AlarmName::SLEEPALARM_WAKE, sleepAlarm))
    {
        set_var_var_wake_hour(uint8ToString(sleepAlarm.hour));
        set_var_var_wake_minute(uint8ToString(sleepAlarm.minute, 2));
        setClockIconActive(objects.alarm_sleep, sleepAlarm.active);
    }
}
