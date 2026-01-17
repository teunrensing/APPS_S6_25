#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_screen_home() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_home = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe6e6e6), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 196, 152);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Hello, world!");
        }
    }
    
    tick_screen_screen_home();
}

void tick_screen_screen_home() {
}

void create_screen_screen_train_voice() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_train_voice = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 90, 10);
            lv_obj_set_size(obj, 300, 300);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // VoiceTrainerCircles
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.voice_trainer_circles = obj;
                    lv_obj_set_pos(obj, 50, 50);
                    lv_obj_set_size(obj, 201, 201);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Circle_5
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.circle_5 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 200, 200);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff60000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // Circle_4
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.circle_4 = obj;
                            lv_obj_set_pos(obj, 20, 20);
                            lv_obj_set_size(obj, 160, 160);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff67700), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // Circle_3
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.circle_3 = obj;
                            lv_obj_set_pos(obj, 40, 40);
                            lv_obj_set_size(obj, 120, 120);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff6e400), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // Circle_2
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.circle_2 = obj;
                            lv_obj_set_pos(obj, 60, 60);
                            lv_obj_set_size(obj, 80, 80);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00f637), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // Circle_1
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.circle_1 = obj;
                            lv_obj_set_pos(obj, 80, 80);
                            lv_obj_set_size(obj, 40, 40);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00f6e7), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // Line_H
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.line_h = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            static lv_point_t line_points[] = {
                                { 0, 100 },
                                { 200, 100 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // Line_V
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.line_v = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            static lv_point_t line_points[] = {
                                { 100, 0 },
                                { 100, 200 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj0 = obj;
                            lv_obj_set_pos(obj, 95, 95);
                            lv_obj_set_size(obj, 11, 11);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
    }
    
    tick_screen_screen_train_voice();
}

void tick_screen_screen_train_voice() {
}

void create_screen_screen_sleep_alarm() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_sleep_alarm = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    
    tick_screen_screen_sleep_alarm();
}

void tick_screen_screen_sleep_alarm() {
}

void create_screen_screen_pill_alarm() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_pill_alarm = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    
    tick_screen_screen_pill_alarm();
}

void tick_screen_screen_pill_alarm() {
}

void create_screen_screen_edit_alarm() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_edit_alarm = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, LV_PCT(0), 0);
            lv_obj_set_size(obj, 258, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_EditHour
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_edit_hour = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_EditMinute
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_edit_minute = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_TimeSplit
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_time_split = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
    }
    
    tick_screen_screen_edit_alarm();
}

void tick_screen_screen_edit_alarm() {
    {
        const char *new_val = get_var_var_edit_hour();
        const char *cur_val = lv_label_get_text(objects.label_edit_hour);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_edit_hour;
            lv_label_set_text(objects.label_edit_hour, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_edit_hour();
        const char *cur_val = lv_label_get_text(objects.label_edit_minute);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_edit_minute;
            lv_label_set_text(objects.label_edit_minute, new_val);
            tick_value_change_obj = NULL;
        }
    }
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_screen_home,
    tick_screen_screen_train_voice,
    tick_screen_screen_sleep_alarm,
    tick_screen_screen_pill_alarm,
    tick_screen_screen_edit_alarm,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_screen_home();
    create_screen_screen_train_voice();
    create_screen_screen_sleep_alarm();
    create_screen_screen_pill_alarm();
    create_screen_screen_edit_alarm();
}
