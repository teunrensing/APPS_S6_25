#include <string.h>
#include "vars.h"


int32_t var_battery_level;

int32_t get_var_var_battery_level() {
    return var_battery_level;
}

void set_var_var_battery_level(int32_t value) {
    var_battery_level = value;
}


char var_greeting[100] = { 0 };

const char *get_var_var_greeting() {
    return var_greeting;
}

void set_var_var_greeting(const char *value) {
    strncpy(var_greeting, value, sizeof(var_greeting) / sizeof(char));
    var_greeting[sizeof(var_greeting) / sizeof(char) - 1] = 0;
}


char var_current_hour[100] = { 0 };

const char *get_var_var_current_hour() {
    return var_current_hour;
}

void set_var_var_current_hour(const char *value) {
    strncpy(var_current_hour, value, sizeof(var_current_hour) / sizeof(char));
    var_current_hour[sizeof(var_current_hour) / sizeof(char) - 1] = 0;
}


char var_current_minute[100] = { 0 };

const char *get_var_var_current_minute() {
    return var_current_minute;
}

void set_var_var_current_minute(const char *value) {
    strncpy(var_current_minute, value, sizeof(var_current_minute) / sizeof(char));
    var_current_minute[sizeof(var_current_minute) / sizeof(char) - 1] = 0;
}


char var_edit_hour[100] = { 0 };

const char *get_var_var_edit_hour() {
    return var_edit_hour;
}

void set_var_var_edit_hour(const char *value) {
    strncpy(var_edit_hour, value, sizeof(var_edit_hour) / sizeof(char));
    var_edit_hour[sizeof(var_edit_hour) / sizeof(char) - 1] = 0;
}


char var_edit_minute[100] = { 0 };

const char *get_var_var_edit_minute() {
    return var_edit_minute;
}

void set_var_var_edit_minute(const char *value) {
    strncpy(var_edit_minute, value, sizeof(var_edit_minute) / sizeof(char));
    var_edit_minute[sizeof(var_edit_minute) / sizeof(char) - 1] = 0;
}


char var_sleep_hour[100] = { 0 };

const char *get_var_var_sleep_hour() {
    return var_sleep_hour;
}

void set_var_var_sleep_hour(const char *value) {
    strncpy(var_sleep_hour, value, sizeof(var_sleep_hour) / sizeof(char));
    var_sleep_hour[sizeof(var_sleep_hour) / sizeof(char) - 1] = 0;
}


char var_sleep_minute[100] = { 0 };

const char *get_var_var_sleep_minute() {
    return var_sleep_minute;
}

void set_var_var_sleep_minute(const char *value) {
    strncpy(var_sleep_minute, value, sizeof(var_sleep_minute) / sizeof(char));
    var_sleep_minute[sizeof(var_sleep_minute) / sizeof(char) - 1] = 0;
}


char var_wake_hour[100] = { 0 };

const char *get_var_var_wake_hour() {
    return var_wake_hour;
}

void set_var_var_wake_hour(const char *value) {
    strncpy(var_wake_hour, value, sizeof(var_wake_hour) / sizeof(char));
    var_wake_hour[sizeof(var_wake_hour) / sizeof(char) - 1] = 0;
}


char var_wake_minute[100] = { 0 };

const char *get_var_var_wake_minute() {
    return var_wake_minute;
}

void set_var_var_wake_minute(const char *value) {
    strncpy(var_wake_minute, value, sizeof(var_wake_minute) / sizeof(char));
    var_wake_minute[sizeof(var_wake_minute) / sizeof(char) - 1] = 0;
}


char var_alarm_type[100] = { 0 };

const char *get_var_var_alarm_type() {
    return var_alarm_type;
}

void set_var_var_alarm_type(const char *value) {
    strncpy(var_alarm_type, value, sizeof(var_alarm_type) / sizeof(char));
    var_alarm_type[sizeof(var_alarm_type) / sizeof(char) - 1] = 0;
}


char var_alarm_hour1[100] = { 0 };

const char *get_var_var_alarm_hour1() {
    return var_alarm_hour1;
}

void set_var_var_alarm_hour1(const char *value) {
    strncpy(var_alarm_hour1, value, sizeof(var_alarm_hour1) / sizeof(char));
    var_alarm_hour1[sizeof(var_alarm_hour1) / sizeof(char) - 1] = 0;
}


char var_alarm_minute1[100] = { 0 };

const char *get_var_var_alarm_minute1() {
    return var_alarm_minute1;
}

void set_var_var_alarm_minute1(const char *value) {
    strncpy(var_alarm_minute1, value, sizeof(var_alarm_minute1) / sizeof(char));
    var_alarm_minute1[sizeof(var_alarm_minute1) / sizeof(char) - 1] = 0;
}


char var_alarm_hour2[100] = { 0 };

const char *get_var_var_alarm_hour2() {
    return var_alarm_hour2;
}

void set_var_var_alarm_hour2(const char *value) {
    strncpy(var_alarm_hour2, value, sizeof(var_alarm_hour2) / sizeof(char));
    var_alarm_hour2[sizeof(var_alarm_hour2) / sizeof(char) - 1] = 0;
}


char var_alarm_minute2[100] = { 0 };

const char *get_var_var_alarm_minute2() {
    return var_alarm_minute2;
}

void set_var_var_alarm_minute2(const char *value) {
    strncpy(var_alarm_minute2, value, sizeof(var_alarm_minute2) / sizeof(char));
    var_alarm_minute2[sizeof(var_alarm_minute2) / sizeof(char) - 1] = 0;
}


char var_alarm_hour3[100] = { 0 };

const char *get_var_var_alarm_hour3() {
    return var_alarm_hour3;
}

void set_var_var_alarm_hour3(const char *value) {
    strncpy(var_alarm_hour3, value, sizeof(var_alarm_hour3) / sizeof(char));
    var_alarm_hour3[sizeof(var_alarm_hour3) / sizeof(char) - 1] = 0;
}


char var_alarm_minute3[100] = { 0 };

const char *get_var_var_alarm_minute3() {
    return var_alarm_minute3;
}

void set_var_var_alarm_minute3(const char *value) {
    strncpy(var_alarm_minute3, value, sizeof(var_alarm_minute3) / sizeof(char));
    var_alarm_minute3[sizeof(var_alarm_minute3) / sizeof(char) - 1] = 0;
}


char var_alarm_hour4[100] = { 0 };

const char *get_var_var_alarm_hour4() {
    return var_alarm_hour4;
}

void set_var_var_alarm_hour4(const char *value) {
    strncpy(var_alarm_hour4, value, sizeof(var_alarm_hour4) / sizeof(char));
    var_alarm_hour4[sizeof(var_alarm_hour4) / sizeof(char) - 1] = 0;
}


char var_alarm_minute4[100] = { 0 };

const char *get_var_var_alarm_minute4() {
    return var_alarm_minute4;
}

void set_var_var_alarm_minute4(const char *value) {
    strncpy(var_alarm_minute4, value, sizeof(var_alarm_minute4) / sizeof(char));
    var_alarm_minute4[sizeof(var_alarm_minute4) / sizeof(char) - 1] = 0;
}


char var_alarm_hour5[100] = { 0 };

const char *get_var_var_alarm_hour5() {
    return var_alarm_hour5;
}

void set_var_var_alarm_hour5(const char *value) {
    strncpy(var_alarm_hour5, value, sizeof(var_alarm_hour5) / sizeof(char));
    var_alarm_hour5[sizeof(var_alarm_hour5) / sizeof(char) - 1] = 0;
}


char var_alarm_minute5[100] = { 0 };

const char *get_var_var_alarm_minute5() {
    return var_alarm_minute5;
}

void set_var_var_alarm_minute5(const char *value) {
    strncpy(var_alarm_minute5, value, sizeof(var_alarm_minute5) / sizeof(char));
    var_alarm_minute5[sizeof(var_alarm_minute5) / sizeof(char) - 1] = 0;
}


char var_alarm_hour6[100] = { 0 };

const char *get_var_var_alarm_hour6() {
    return var_alarm_hour6;
}

void set_var_var_alarm_hour6(const char *value) {
    strncpy(var_alarm_hour6, value, sizeof(var_alarm_hour6) / sizeof(char));
    var_alarm_hour6[sizeof(var_alarm_hour6) / sizeof(char) - 1] = 0;
}


char var_alarm_minute6[100] = { 0 };

const char *get_var_var_alarm_minute6() {
    return var_alarm_minute6;
}

void set_var_var_alarm_minute6(const char *value) {
    strncpy(var_alarm_minute6, value, sizeof(var_alarm_minute6) / sizeof(char));
    var_alarm_minute6[sizeof(var_alarm_minute6) / sizeof(char) - 1] = 0;
}


char var_alarm_hour7[100] = { 0 };

const char *get_var_var_alarm_hour7() {
    return var_alarm_hour7;
}

void set_var_var_alarm_hour7(const char *value) {
    strncpy(var_alarm_hour7, value, sizeof(var_alarm_hour7) / sizeof(char));
    var_alarm_hour7[sizeof(var_alarm_hour7) / sizeof(char) - 1] = 0;
}


char var_alarm_minute7[100] = { 0 };

const char *get_var_var_alarm_minute7() {
    return var_alarm_minute7;
}

void set_var_var_alarm_minute7(const char *value) {
    strncpy(var_alarm_minute7, value, sizeof(var_alarm_minute7) / sizeof(char));
    var_alarm_minute7[sizeof(var_alarm_minute7) / sizeof(char) - 1] = 0;
}


char var_alarm_hour8[100] = { 0 };

const char *get_var_var_alarm_hour8() {
    return var_alarm_hour8;
}

void set_var_var_alarm_hour8(const char *value) {
    strncpy(var_alarm_hour8, value, sizeof(var_alarm_hour8) / sizeof(char));
    var_alarm_hour8[sizeof(var_alarm_hour8) / sizeof(char) - 1] = 0;
}


char var_alarm_minute8[100] = { 0 };

const char *get_var_var_alarm_minute8() {
    return var_alarm_minute8;
}

void set_var_var_alarm_minute8(const char *value) {
    strncpy(var_alarm_minute8, value, sizeof(var_alarm_minute8) / sizeof(char));
    var_alarm_minute8[sizeof(var_alarm_minute8) / sizeof(char) - 1] = 0;
}


