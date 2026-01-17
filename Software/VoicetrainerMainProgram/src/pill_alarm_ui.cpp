#include <pill_alarm_ui.h>
#include <button_config.h>
#include <mode_controller.h>
#include <ui.h>
#include <vars.h>
#include <helper_functions.h>
#include "screens.h"
#include "images.h"
#include <freertos_wrapper.h>
#include <logger.h>
#include <mode_controller.h>

PillAlarmUIState currentState = PillAlarmUIState::VIEW_ALARMS;
Alarm editAlarm;

void handleButtonPress(const button_cmd_t &btn)
{
    switch (currentState)
    {
    case PillAlarmUIState::VIEW_ALARMS:
        handleViewAlarmsState(btn);
        break;
    case PillAlarmUIState::EDIT_ALARM:
        handleEditAlarmState(btn);
        break;
    case PillAlarmUIState::SET_HOUR:
        handleSetHourState(btn);
        break;
    case PillAlarmUIState::SET_MINUTE:
        handleSetMinuteState(btn);
        break;
    default:
        currentState = PillAlarmUIState::VIEW_ALARMS;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}

void handleViewAlarmsState(const button_cmd_t &btn)
{
    switch (btn.icon)
    {
    case Display_Icon::Next:
        if (getLoadedButtonConfiguration() == ButtonConfiguration::PILLALARM_1_3)
            loadButtons(ButtonConfiguration::PILLALARM_4_5);
        else if (getLoadedButtonConfiguration() == ButtonConfiguration::PILLALARM_4_5)
            loadButtons(ButtonConfiguration::PILLALARM_6_8);
        break;
    case Display_Icon::Back:
        if (getLoadedButtonConfiguration() == ButtonConfiguration::PILLALARM_4_5)
            loadButtons(ButtonConfiguration::PILLALARM_1_3);
        else if (getLoadedButtonConfiguration() == ButtonConfiguration::PILLALARM_6_8)
            loadButtons(ButtonConfiguration::PILLALARM_4_5);
        break;
    case Display_Icon::Digit1:
        loadEditScreen(AlarmName::PILLALARM_1);
        currentState = PillAlarmUIState::EDIT_ALARM;
        break;
    case Display_Icon::Digit2:
        loadEditScreen(AlarmName::PILLALARM_2);
        currentState = PillAlarmUIState::EDIT_ALARM;
        break;
    case Display_Icon::Digit3:
        loadEditScreen(AlarmName::PILLALARM_3);
        currentState = PillAlarmUIState::EDIT_ALARM;
        break;
    case Display_Icon::Digit4:
        loadEditScreen(AlarmName::PILLALARM_4);
        currentState = PillAlarmUIState::EDIT_ALARM;
        break;
    case Display_Icon::Digit5:
        loadEditScreen(AlarmName::PILLALARM_5);
        currentState = PillAlarmUIState::EDIT_ALARM;
        break;
    case Display_Icon::Digit6:
        loadEditScreen(AlarmName::PILLALARM_6);
        currentState = PillAlarmUIState::EDIT_ALARM;
        break;
    case Display_Icon::Digit7:
        loadEditScreen(AlarmName::PILLALARM_7);
        currentState = PillAlarmUIState::EDIT_ALARM;
        break;
    case Display_Icon::Digit8:
        loadEditScreen(AlarmName::PILLALARM_8);
        currentState = PillAlarmUIState::EDIT_ALARM;
        break;
    default:
        currentState = PillAlarmUIState::VIEW_ALARMS;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}

void handleEditAlarmState(const button_cmd_t &btn)
{
    switch (btn.icon)
    {
    case Display_Icon::On:
        editAlarm.active = true;
        setAlarm(editAlarm.hour, editAlarm.minute, editAlarm.name, editAlarm.active);
        loadEditScreen(editAlarm.name);
        break;
    case Display_Icon::Off:
        editAlarm.active = false;
        setAlarm(editAlarm.hour, editAlarm.minute, editAlarm.name, editAlarm.active);
        loadEditScreen(editAlarm.name);
        break;
    case Display_Icon::Edit:
        loadButtons(ButtonConfiguration::EDIT_ALARM_HOUR);
        lv_obj_add_state(objects.label_edit_hour, LV_STATE_CHECKED);
        currentState = PillAlarmUIState::SET_HOUR;
        break;
    case Display_Icon::Back:
        loadOverviewScreen();
        currentState = PillAlarmUIState::VIEW_ALARMS;
        break;
    default:
        currentState = PillAlarmUIState::VIEW_ALARMS;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}

void handleSetHourState(const button_cmd_t &btn)
{
    switch (btn.icon)
    {
    case Display_Icon::Increase:
        editAlarm.hour++;
        if (editAlarm.hour >= 24)
        {
            editAlarm.hour = 0;
        }
        set_var_var_edit_hour(uint8ToString(editAlarm.hour));
        break;
    case Display_Icon::Decrease:
        editAlarm.hour--;
        if (editAlarm.hour >= 24)
        {
            editAlarm.hour = 23;
        }
        set_var_var_edit_hour(uint8ToString(editAlarm.hour));
        break;
    case Display_Icon::Back:
        loadEditScreen(editAlarm.name);
        currentState = PillAlarmUIState::EDIT_ALARM;
        break;
    case Display_Icon::Next:
        loadButtons(ButtonConfiguration::EDIT_ALARM_MINUTE);
        lv_obj_clear_state(objects.label_edit_hour, LV_STATE_CHECKED);
        lv_obj_add_state(objects.label_edit_minute, LV_STATE_CHECKED);
        currentState = PillAlarmUIState::SET_MINUTE;
        break;
    default:
        currentState = PillAlarmUIState::VIEW_ALARMS;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}

void handleSetMinuteState(const button_cmd_t &btn)
{
    switch (btn.icon)
    {
    case Display_Icon::Increase:
        editAlarm.minute += 5;
        if (editAlarm.minute >= 60)
        {
            editAlarm.minute = 0;
        }
        set_var_var_edit_minute(uint8ToString(editAlarm.minute, 2));
        break;
    case Display_Icon::Decrease:
        editAlarm.minute -= 5;
        if (editAlarm.minute >= 60)
        {
            editAlarm.minute = 55;
        }
        set_var_var_edit_minute(uint8ToString(editAlarm.minute, 2));
        break;
    case Display_Icon::Back:
        loadButtons(ButtonConfiguration::EDIT_ALARM_HOUR);
        lv_obj_add_state(objects.label_edit_hour, LV_STATE_CHECKED);
        lv_obj_clear_state(objects.label_edit_minute, LV_STATE_CHECKED);
        currentState = PillAlarmUIState::SET_HOUR;
        break;
    case Display_Icon::Confirm:
        setAlarm(editAlarm.hour, editAlarm.minute, editAlarm.name, editAlarm.active);
        loadEditScreen(editAlarm.name);
        currentState = PillAlarmUIState::EDIT_ALARM;
        break;
    default:
        currentState = PillAlarmUIState::VIEW_ALARMS;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}

void loadOverviewScreen()
{
    loadButtons(ButtonConfiguration::PILLALARM_1_3);
    printPillAlarms();
    loadScreen(SCREEN_ID_SCREEN_PILL_ALARM);
}

void loadEditScreen(AlarmName alarmName)
{
    lv_obj_clear_state(objects.label_edit_hour, LV_STATE_CHECKED);
    lv_obj_clear_state(objects.label_edit_minute, LV_STATE_CHECKED);
    getAlarm(alarmName, editAlarm);
    loadButtons(ButtonConfiguration::PILLALARM_OPTIONS);
    loadEditAlarmVars(editAlarm);
    loadScreen(ScreensEnum::SCREEN_ID_SCREEN_EDIT_ALARM);
}

void loadEditAlarmVars(Alarm _editAlarm)
{
    set_var_var_edit_hour(uint8ToString(_editAlarm.hour));
    set_var_var_edit_minute(uint8ToString(_editAlarm.minute, 2));
    set_var_var_alarm_type(alarmNameToString(_editAlarm.name));
    setClockIconActive(objects.alarm_edit, _editAlarm.active);
    if (!_editAlarm.active)
    {
        button_queue_send(Button_Name::UpLeft, Display_Icon::On);
    }
}

void printPillAlarms()
{
    Alarm pillAlarm;

    if (getAlarm(PILLALARM_1, pillAlarm))
    {
        set_var_var_alarm_hour1(uint8ToString(pillAlarm.hour));
        set_var_var_alarm_minute1(uint8ToString(pillAlarm.minute, 2));
        setClockIconActive(objects.alarm1, pillAlarm.active);
    }
    if (getAlarm(PILLALARM_2, pillAlarm))
    {
        set_var_var_alarm_hour2(uint8ToString(pillAlarm.hour));
        set_var_var_alarm_minute2(uint8ToString(pillAlarm.minute, 2));
        setClockIconActive(objects.alarm2, pillAlarm.active);
    }

    if (getAlarm(PILLALARM_3, pillAlarm))
    {
        set_var_var_alarm_hour3(uint8ToString(pillAlarm.hour));
        set_var_var_alarm_minute3(uint8ToString(pillAlarm.minute, 2));
        setClockIconActive(objects.alarm3, pillAlarm.active);
    }

    if (getAlarm(PILLALARM_4, pillAlarm))
    {
        set_var_var_alarm_hour4(uint8ToString(pillAlarm.hour));
        set_var_var_alarm_minute4(uint8ToString(pillAlarm.minute, 2));
        setClockIconActive(objects.alarm4, pillAlarm.active);
    }

    if (getAlarm(PILLALARM_5, pillAlarm))
    {
        set_var_var_alarm_hour5(uint8ToString(pillAlarm.hour));
        set_var_var_alarm_minute5(uint8ToString(pillAlarm.minute, 2));
        setClockIconActive(objects.alarm5, pillAlarm.active);
    }

    if (getAlarm(PILLALARM_6, pillAlarm))
    {
        set_var_var_alarm_hour6(uint8ToString(pillAlarm.hour));
        set_var_var_alarm_minute6(uint8ToString(pillAlarm.minute, 2));
        setClockIconActive(objects.alarm6, pillAlarm.active);
    }

    if (getAlarm(PILLALARM_7, pillAlarm))
    {
        set_var_var_alarm_hour7(uint8ToString(pillAlarm.hour));
        set_var_var_alarm_minute7(uint8ToString(pillAlarm.minute, 2));
        setClockIconActive(objects.alarm7, pillAlarm.active);
    }

    if (getAlarm(PILLALARM_8, pillAlarm))
    {
        set_var_var_alarm_hour8(uint8ToString(pillAlarm.hour));
        set_var_var_alarm_minute8(uint8ToString(pillAlarm.minute, 2));
        setClockIconActive(objects.alarm8, pillAlarm.active);
    }
}