#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations



// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_VAR_BATTERY_LEVEL = 0,
    FLOW_GLOBAL_VARIABLE_VAR_GREETING = 1,
    FLOW_GLOBAL_VARIABLE_VAR_CURRENT_HOUR = 2,
    FLOW_GLOBAL_VARIABLE_VAR_CURRENT_MINUTE = 3,
    FLOW_GLOBAL_VARIABLE_VAR_EDIT_HOUR = 4,
    FLOW_GLOBAL_VARIABLE_VAR_EDIT_MINUTE = 5,
    FLOW_GLOBAL_VARIABLE_VAR_SLEEP_HOUR = 6,
    FLOW_GLOBAL_VARIABLE_VAR_SLEEP_MINUTE = 7,
    FLOW_GLOBAL_VARIABLE_VAR_WAKE_HOUR = 8,
    FLOW_GLOBAL_VARIABLE_VAR_WAKE_MINUTE = 9,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_TYPE = 10,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_HOUR1 = 11,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_MINUTE1 = 12,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_HOUR2 = 13,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_MINUTE2 = 14,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_HOUR3 = 15,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_MINUTE3 = 16,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_HOUR4 = 17,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_MINUTE4 = 18,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_HOUR5 = 19,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_MINUTE5 = 20,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_HOUR6 = 21,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_MINUTE6 = 22,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_HOUR7 = 23,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_MINUTE7 = 24,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_HOUR8 = 25,
    FLOW_GLOBAL_VARIABLE_VAR_ALARM_MINUTE8 = 26
};

// Native global variables

extern int32_t get_var_var_battery_level();
extern void set_var_var_battery_level(int32_t value);
extern const char *get_var_var_greeting();
extern void set_var_var_greeting(const char *value);
extern const char *get_var_var_current_hour();
extern void set_var_var_current_hour(const char *value);
extern const char *get_var_var_current_minute();
extern void set_var_var_current_minute(const char *value);
extern const char *get_var_var_edit_hour();
extern void set_var_var_edit_hour(const char *value);
extern const char *get_var_var_edit_minute();
extern void set_var_var_edit_minute(const char *value);
extern const char *get_var_var_sleep_hour();
extern void set_var_var_sleep_hour(const char *value);
extern const char *get_var_var_sleep_minute();
extern void set_var_var_sleep_minute(const char *value);
extern const char *get_var_var_wake_hour();
extern void set_var_var_wake_hour(const char *value);
extern const char *get_var_var_wake_minute();
extern void set_var_var_wake_minute(const char *value);
extern const char *get_var_var_alarm_type();
extern void set_var_var_alarm_type(const char *value);
extern const char *get_var_var_alarm_hour1();
extern void set_var_var_alarm_hour1(const char *value);
extern const char *get_var_var_alarm_minute1();
extern void set_var_var_alarm_minute1(const char *value);
extern const char *get_var_var_alarm_hour2();
extern void set_var_var_alarm_hour2(const char *value);
extern const char *get_var_var_alarm_minute2();
extern void set_var_var_alarm_minute2(const char *value);
extern const char *get_var_var_alarm_hour3();
extern void set_var_var_alarm_hour3(const char *value);
extern const char *get_var_var_alarm_minute3();
extern void set_var_var_alarm_minute3(const char *value);
extern const char *get_var_var_alarm_hour4();
extern void set_var_var_alarm_hour4(const char *value);
extern const char *get_var_var_alarm_minute4();
extern void set_var_var_alarm_minute4(const char *value);
extern const char *get_var_var_alarm_hour5();
extern void set_var_var_alarm_hour5(const char *value);
extern const char *get_var_var_alarm_minute5();
extern void set_var_var_alarm_minute5(const char *value);
extern const char *get_var_var_alarm_hour6();
extern void set_var_var_alarm_hour6(const char *value);
extern const char *get_var_var_alarm_minute6();
extern void set_var_var_alarm_minute6(const char *value);
extern const char *get_var_var_alarm_hour7();
extern void set_var_var_alarm_hour7(const char *value);
extern const char *get_var_var_alarm_minute7();
extern void set_var_var_alarm_minute7(const char *value);
extern const char *get_var_var_alarm_hour8();
extern void set_var_var_alarm_hour8(const char *value);
extern const char *get_var_var_alarm_minute8();
extern void set_var_var_alarm_minute8(const char *value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/