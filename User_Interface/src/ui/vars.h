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
    FLOW_GLOBAL_VARIABLE_VAR_EDIT_HOUR = 0,
    FLOW_GLOBAL_VARIABLE_VAR_EDIT_MINUTE = 1
};

// Native global variables

extern int32_t get_var_var_edit_hour();
extern void set_var_var_edit_hour(int32_t value);
extern int32_t get_var_var_edit_minute();
extern void set_var_var_edit_minute(int32_t value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/