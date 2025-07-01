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
    FLOW_GLOBAL_VARIABLE_TIME = 0,
    FLOW_GLOBAL_VARIABLE_SLAAP = 1,
    FLOW_GLOBAL_VARIABLE_WAKKER = 2,
    FLOW_GLOBAL_VARIABLE_BATTERY = 3,
    FLOW_GLOBAL_VARIABLE_ALARM1 = 4,
    FLOW_GLOBAL_VARIABLE_ALARM2 = 5,
    FLOW_GLOBAL_VARIABLE_ALARM3 = 6,
    FLOW_GLOBAL_VARIABLE_ALARM4 = 7,
    FLOW_GLOBAL_VARIABLE_KLOK = 8,
    FLOW_GLOBAL_VARIABLE_EDIT_TIME = 9,
    FLOW_GLOBAL_VARIABLE_EDIT_TEXT = 10,
    FLOW_GLOBAL_VARIABLE_EDIT_BOX1 = 11,
    FLOW_GLOBAL_VARIABLE_EDIT_BOX2 = 12,
    FLOW_GLOBAL_VARIABLE_EDIT_TEXT_BOOL = 13,
    FLOW_GLOBAL_VARIABLE_FREQUENCY = 14,
    FLOW_GLOBAL_VARIABLE_AMPLITUDE = 15,
    FLOW_GLOBAL_VARIABLE_VOLUME = 16
};

// Native global variables

extern const char *get_var_time();
extern void set_var_time(const char *value);
extern const char *get_var_slaap();
extern void set_var_slaap(const char *value);
extern const char *get_var_wakker();
extern void set_var_wakker(const char *value);
extern int32_t get_var_battery();
extern void set_var_battery(int32_t value);
extern const char *get_var_alarm1();
extern void set_var_alarm1(const char *value);
extern const char *get_var_alarm2();
extern void set_var_alarm2(const char *value);
extern const char *get_var_alarm3();
extern void set_var_alarm3(const char *value);
extern const char *get_var_alarm4();
extern void set_var_alarm4(const char *value);
extern bool get_var_klok();
extern void set_var_klok(bool value);
extern const char *get_var_edit_time();
extern void set_var_edit_time(const char *value);
extern const char *get_var_edit_text();
extern void set_var_edit_text(const char *value);
extern bool get_var_edit_box1();
extern void set_var_edit_box1(bool value);
extern bool get_var_edit_box2();
extern void set_var_edit_box2(bool value);
extern bool get_var_edit_text_bool();
extern void set_var_edit_text_bool(bool value);
extern int32_t get_var_frequency();
extern void set_var_frequency(int32_t value);
extern float get_var_amplitude();
extern void set_var_amplitude(float value);
extern int32_t get_var_volume();
extern void set_var_volume(int32_t value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/