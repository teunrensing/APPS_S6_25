#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *screen_home;
    lv_obj_t *screen_train_voice;
    lv_obj_t *screen_sleep_alarm;
    lv_obj_t *screen_pill_alarm;
    lv_obj_t *screen_edit_alarm;
    lv_obj_t *label_greeting;
    lv_obj_t *group_current_time;
    lv_obj_t *label_hour;
    lv_obj_t *label_minute;
    lv_obj_t *label_split;
    lv_obj_t *group_battery;
    lv_obj_t *bar_battery_level;
    lv_obj_t *image_battery;
    lv_obj_t *group_voice_trainer_feedback;
    lv_obj_t *label_louder;
    lv_obj_t *label_quiter;
    lv_obj_t *group_voice_trainer_circles;
    lv_obj_t *circle_5;
    lv_obj_t *circle_4;
    lv_obj_t *circle_3;
    lv_obj_t *circle_2;
    lv_obj_t *circle_1;
    lv_obj_t *line_h;
    lv_obj_t *line_v;
    lv_obj_t *circle_voice_position;
    lv_obj_t *group_current_time_1;
    lv_obj_t *label_hour_1;
    lv_obj_t *label_minute_1;
    lv_obj_t *label_split_1;
    lv_obj_t *group_sleep_time;
    lv_obj_t *label_hour_2;
    lv_obj_t *label_minute_2;
    lv_obj_t *label_split_2;
    lv_obj_t *group_wake_time;
    lv_obj_t *label_hour_3;
    lv_obj_t *label_minute_3;
    lv_obj_t *label_split_3;
    lv_obj_t *alarm_sleep;
    lv_obj_t *group_current_time_2;
    lv_obj_t *label_hour_5;
    lv_obj_t *label_minute_5;
    lv_obj_t *label_split_5;
    lv_obj_t *alarm1;
    lv_obj_t *alarm2;
    lv_obj_t *alarm3;
    lv_obj_t *alarm4;
    lv_obj_t *alarm5;
    lv_obj_t *alarm6;
    lv_obj_t *alarm7;
    lv_obj_t *alarm8;
    lv_obj_t *group_alarm_time1;
    lv_obj_t *label_hour_6;
    lv_obj_t *label_minute_6;
    lv_obj_t *label_split_6;
    lv_obj_t *group_alarm_time2;
    lv_obj_t *label_hour_7;
    lv_obj_t *label_minute_7;
    lv_obj_t *label_split_7;
    lv_obj_t *group_alarm_time3;
    lv_obj_t *label_hour_8;
    lv_obj_t *label_minute_8;
    lv_obj_t *label_split_8;
    lv_obj_t *group_alarm_time4;
    lv_obj_t *label_hour_9;
    lv_obj_t *label_minute_9;
    lv_obj_t *label_split_9;
    lv_obj_t *group_alarm_time5;
    lv_obj_t *label_hour_10;
    lv_obj_t *label_minute_10;
    lv_obj_t *label_split_10;
    lv_obj_t *group_alarm_time6;
    lv_obj_t *label_hour_12;
    lv_obj_t *label_minute_12;
    lv_obj_t *label_split_12;
    lv_obj_t *group_alarm_time7;
    lv_obj_t *label_hour_13;
    lv_obj_t *label_minute_13;
    lv_obj_t *label_split_13;
    lv_obj_t *group_alarm_time8;
    lv_obj_t *label_hour_14;
    lv_obj_t *label_minute_14;
    lv_obj_t *label_split_14;
    lv_obj_t *group_edit_time;
    lv_obj_t *label_edit_hour;
    lv_obj_t *label_edit_minute;
    lv_obj_t *label_split_4;
    lv_obj_t *label_alarm_type;
    lv_obj_t *alarm_edit;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_SCREEN_HOME = 1,
    SCREEN_ID_SCREEN_TRAIN_VOICE = 2,
    SCREEN_ID_SCREEN_SLEEP_ALARM = 3,
    SCREEN_ID_SCREEN_PILL_ALARM = 4,
    SCREEN_ID_SCREEN_EDIT_ALARM = 5,
};

void create_screen_screen_home();
void tick_screen_screen_home();

void create_screen_screen_train_voice();
void tick_screen_screen_train_voice();

void create_screen_screen_sleep_alarm();
void tick_screen_screen_sleep_alarm();

void create_screen_screen_pill_alarm();
void tick_screen_screen_pill_alarm();

void create_screen_screen_edit_alarm();
void tick_screen_screen_edit_alarm();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/