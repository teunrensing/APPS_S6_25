#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *screen_home;
    lv_obj_t *screen_train_voice;
    lv_obj_t *screen_sleep_alarm;
    lv_obj_t *screen_pill_alarm;
    lv_obj_t *screen_edit_alarm;
    lv_obj_t *voice_trainer_circles;
    lv_obj_t *circle_5;
    lv_obj_t *circle_4;
    lv_obj_t *circle_3;
    lv_obj_t *circle_2;
    lv_obj_t *circle_1;
    lv_obj_t *line_h;
    lv_obj_t *line_v;
    lv_obj_t *obj0;
    lv_obj_t *label_edit_hour;
    lv_obj_t *label_edit_minute;
    lv_obj_t *label_time_split;
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