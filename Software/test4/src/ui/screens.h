#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *screen1;
    lv_obj_t *screen2;
    lv_obj_t *screen3;
    lv_obj_t *screen_edit;
    lv_obj_t *screen_spraak;
    lv_obj_t *screen4;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *obj15;
    lv_obj_t *obj16;
    lv_obj_t *obj17;
    lv_obj_t *obj18;
    lv_obj_t *obj19;
    lv_obj_t *ball;
    lv_obj_t *obj20;
    lv_obj_t *obj21;
    lv_obj_t *obj22;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_SCREEN1 = 1,
    SCREEN_ID_SCREEN2 = 2,
    SCREEN_ID_SCREEN3 = 3,
    SCREEN_ID_SCREEN_EDIT = 4,
    SCREEN_ID_SCREEN_SPRAAK = 5,
    SCREEN_ID_SCREEN4 = 6,
};

void create_screen_screen1();
void tick_screen_screen1();

void create_screen_screen2();
void tick_screen_screen2();

void create_screen_screen3();
void tick_screen_screen3();

void create_screen_screen_edit();
void tick_screen_screen_edit();

void create_screen_screen_spraak();
void tick_screen_screen_spraak();

void create_screen_screen4();
void tick_screen_screen4();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/