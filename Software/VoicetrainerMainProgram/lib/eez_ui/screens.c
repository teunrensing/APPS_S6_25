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
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_bitmap_flowers);
        }
        {
            // Label_Greeting
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_greeting = obj;
            lv_obj_set_pos(obj, 0, 20);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Group_CurrentTime
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_current_time = obj;
            lv_obj_set_pos(obj, LV_PCT(0), -30);
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
                    // Label_Hour
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_hour = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Minute
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_minute = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
        {
            // Group_Battery
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_battery = obj;
            lv_obj_set_pos(obj, 10, 10);
            lv_obj_set_size(obj, 63, 34);
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
                    // Bar_BatteryLevel
                    lv_obj_t *obj = lv_bar_create(parent_obj);
                    objects.bar_battery_level = obj;
                    lv_obj_set_pos(obj, -3, 0);
                    lv_obj_set_size(obj, 58, 34);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Image_Battery
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.image_battery = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_bitmap_battery);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    
    tick_screen_screen_home();
}

void tick_screen_screen_home() {
    {
        const char *new_val = get_var_var_greeting();
        const char *cur_val = lv_label_get_text(objects.label_greeting);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_greeting;
            lv_label_set_text(objects.label_greeting, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_current_hour();
        const char *cur_val = lv_label_get_text(objects.label_hour);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_hour;
            lv_label_set_text(objects.label_hour, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_current_minute();
        const char *cur_val = lv_label_get_text(objects.label_minute);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_minute;
            lv_label_set_text(objects.label_minute, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_var_battery_level();
        int32_t cur_val = lv_bar_get_value(objects.bar_battery_level);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.bar_battery_level;
            lv_bar_set_value(objects.bar_battery_level, new_val, LV_ANIM_ON);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_screen_train_voice() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_train_voice = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Group_VoiceTrainerFeedback
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_voice_trainer_feedback = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 300, 300);
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
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 115, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_bitmap_bird);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, -115, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_bitmap_elephant);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Label_Louder
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_louder = obj;
                    lv_obj_set_pos(obj, 0, -115);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "+");
                }
                {
                    // Label_Quiter
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_quiter = obj;
                    lv_obj_set_pos(obj, 0, 115);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "-");
                }
                {
                    // Group_VoiceTrainerCircles
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.group_voice_trainer_circles = obj;
                    lv_obj_set_pos(obj, 50, 50);
                    lv_obj_set_size(obj, 201, 201);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
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
                            // CircleVoicePosition
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.circle_voice_position = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 11, 11);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00118b), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
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
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Group_CurrentTime_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_current_time_1 = obj;
            lv_obj_set_pos(obj, 111, 48);
            lv_obj_set_size(obj, 258, 60);
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
                    // Label_Hour_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_hour_1 = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Minute_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_minute_1 = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split_1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 101, 108);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Slaap:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 47, 161);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Wakker:");
        }
        {
            // Group_SleepTime
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_sleep_time = obj;
            lv_obj_set_pos(obj, 209, 108);
            lv_obj_set_size(obj, 220, LV_SIZE_CONTENT);
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
                    // Label_Hour_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_hour_2 = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Minute_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_minute_2 = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split_2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
        {
            // Group_WakeTime
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_wake_time = obj;
            lv_obj_set_pos(obj, 210, 161);
            lv_obj_set_size(obj, 220, LV_SIZE_CONTENT);
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
                    // Label_Hour_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_hour_3 = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Minute_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_minute_3 = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split_3 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
        {
            // AlarmSleep
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.alarm_sleep = obj;
            lv_obj_set_pos(obj, 208, 222);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_bitmap_alarm_on);
        }
    }
    
    tick_screen_screen_sleep_alarm();
}

void tick_screen_screen_sleep_alarm() {
    {
        const char *new_val = get_var_var_current_hour();
        const char *cur_val = lv_label_get_text(objects.label_hour_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_hour_1;
            lv_label_set_text(objects.label_hour_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_current_minute();
        const char *cur_val = lv_label_get_text(objects.label_minute_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_minute_1;
            lv_label_set_text(objects.label_minute_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_sleep_hour();
        const char *cur_val = lv_label_get_text(objects.label_hour_2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_hour_2;
            lv_label_set_text(objects.label_hour_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_sleep_minute();
        const char *cur_val = lv_label_get_text(objects.label_minute_2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_minute_2;
            lv_label_set_text(objects.label_minute_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_wake_hour();
        const char *cur_val = lv_label_get_text(objects.label_hour_3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_hour_3;
            lv_label_set_text(objects.label_hour_3, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_wake_minute();
        const char *cur_val = lv_label_get_text(objects.label_minute_3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_minute_3;
            lv_label_set_text(objects.label_minute_3, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_screen_pill_alarm() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_pill_alarm = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Group_CurrentTime_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_current_time_2 = obj;
            lv_obj_set_pos(obj, 0, 10);
            lv_obj_set_size(obj, 258, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_Hour_5
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_hour_5 = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Minute_5
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_minute_5 = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split_5
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split_5 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
        {
            // Alarm1
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.alarm1 = obj;
            lv_obj_set_pos(obj, 40, 65);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_bitmap_alarm_off);
        }
        {
            // Alarm2
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.alarm2 = obj;
            lv_obj_set_pos(obj, 40, 128);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_bitmap_alarm_off);
        }
        {
            // Alarm3
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.alarm3 = obj;
            lv_obj_set_pos(obj, 40, 192);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_bitmap_alarm_off);
        }
        {
            // Alarm4
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.alarm4 = obj;
            lv_obj_set_pos(obj, 40, 256);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_bitmap_alarm_off);
        }
        {
            // Alarm5
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.alarm5 = obj;
            lv_obj_set_pos(obj, 72, 65);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_bitmap_alarm_off);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Alarm6
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.alarm6 = obj;
            lv_obj_set_pos(obj, 72, 128);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_bitmap_alarm_off);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Alarm7
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.alarm7 = obj;
            lv_obj_set_pos(obj, 72, 192);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_bitmap_alarm_off);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Alarm8
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.alarm8 = obj;
            lv_obj_set_pos(obj, 72, 256);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_bitmap_alarm_off);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 6, 72);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "1");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 1, 134);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "2");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 2, 198);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "3");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 3, 262);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "4");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 0, 60);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 0, 259 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 252, 73);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "5");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 247, 135);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "6");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 248, 199);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "7");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 249, 263);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "8");
        }
        {
            // Group_AlarmTime1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_alarm_time1 = obj;
            lv_obj_set_pos(obj, 37, 68);
            lv_obj_set_size(obj, 258, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_Hour_6
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_hour_6 = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Minute_6
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_minute_6 = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split_6
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split_6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
        {
            // Group_AlarmTime2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_alarm_time2 = obj;
            lv_obj_set_pos(obj, 37, 131);
            lv_obj_set_size(obj, 258, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_Hour_7
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_hour_7 = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Minute_7
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_minute_7 = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split_7
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split_7 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
        {
            // Group_AlarmTime3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_alarm_time3 = obj;
            lv_obj_set_pos(obj, 37, 194);
            lv_obj_set_size(obj, 258, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_Hour_8
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_hour_8 = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Minute_8
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_minute_8 = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split_8
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split_8 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
        {
            // Group_AlarmTime4
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_alarm_time4 = obj;
            lv_obj_set_pos(obj, 37, 259);
            lv_obj_set_size(obj, 258, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_Hour_9
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_hour_9 = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Minute_9
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_minute_9 = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split_9
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split_9 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
        {
            // Group_AlarmTime5
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_alarm_time5 = obj;
            lv_obj_set_pos(obj, 166, 68);
            lv_obj_set_size(obj, 258, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_Hour_10
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_hour_10 = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Minute_10
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_minute_10 = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split_10
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split_10 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
        {
            // Group_AlarmTime6
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_alarm_time6 = obj;
            lv_obj_set_pos(obj, 166, 131);
            lv_obj_set_size(obj, 258, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_Hour_12
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_hour_12 = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Minute_12
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_minute_12 = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split_12
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split_12 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
        {
            // Group_AlarmTime7
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_alarm_time7 = obj;
            lv_obj_set_pos(obj, 166, 195);
            lv_obj_set_size(obj, 258, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_Hour_13
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_hour_13 = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Minute_13
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_minute_13 = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split_13
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split_13 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
        {
            // Group_AlarmTime8
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_alarm_time8 = obj;
            lv_obj_set_pos(obj, 166, 259);
            lv_obj_set_size(obj, 258, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Label_Hour_14
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_hour_14 = obj;
                    lv_obj_set_pos(obj, -55, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Minute_14
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_minute_14 = obj;
                    lv_obj_set_pos(obj, 56, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split_14
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split_14 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
    }
    
    tick_screen_screen_pill_alarm();
}

void tick_screen_screen_pill_alarm() {
    {
        const char *new_val = get_var_var_current_hour();
        const char *cur_val = lv_label_get_text(objects.label_hour_5);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_hour_5;
            lv_label_set_text(objects.label_hour_5, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_current_minute();
        const char *cur_val = lv_label_get_text(objects.label_minute_5);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_minute_5;
            lv_label_set_text(objects.label_minute_5, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_hour1();
        const char *cur_val = lv_label_get_text(objects.label_hour_6);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_hour_6;
            lv_label_set_text(objects.label_hour_6, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_minute1();
        const char *cur_val = lv_label_get_text(objects.label_minute_6);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_minute_6;
            lv_label_set_text(objects.label_minute_6, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_hour2();
        const char *cur_val = lv_label_get_text(objects.label_hour_7);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_hour_7;
            lv_label_set_text(objects.label_hour_7, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_minute2();
        const char *cur_val = lv_label_get_text(objects.label_minute_7);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_minute_7;
            lv_label_set_text(objects.label_minute_7, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_hour3();
        const char *cur_val = lv_label_get_text(objects.label_hour_8);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_hour_8;
            lv_label_set_text(objects.label_hour_8, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_minute3();
        const char *cur_val = lv_label_get_text(objects.label_minute_8);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_minute_8;
            lv_label_set_text(objects.label_minute_8, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_hour4();
        const char *cur_val = lv_label_get_text(objects.label_hour_9);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_hour_9;
            lv_label_set_text(objects.label_hour_9, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_minute4();
        const char *cur_val = lv_label_get_text(objects.label_minute_9);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_minute_9;
            lv_label_set_text(objects.label_minute_9, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_hour5();
        const char *cur_val = lv_label_get_text(objects.label_hour_10);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_hour_10;
            lv_label_set_text(objects.label_hour_10, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_minute5();
        const char *cur_val = lv_label_get_text(objects.label_minute_10);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_minute_10;
            lv_label_set_text(objects.label_minute_10, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_hour6();
        const char *cur_val = lv_label_get_text(objects.label_hour_12);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_hour_12;
            lv_label_set_text(objects.label_hour_12, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_minute6();
        const char *cur_val = lv_label_get_text(objects.label_minute_12);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_minute_12;
            lv_label_set_text(objects.label_minute_12, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_hour7();
        const char *cur_val = lv_label_get_text(objects.label_hour_13);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_hour_13;
            lv_label_set_text(objects.label_hour_13, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_minute7();
        const char *cur_val = lv_label_get_text(objects.label_minute_13);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_minute_13;
            lv_label_set_text(objects.label_minute_13, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_hour8();
        const char *cur_val = lv_label_get_text(objects.label_hour_14);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_hour_14;
            lv_label_set_text(objects.label_hour_14, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_minute8();
        const char *cur_val = lv_label_get_text(objects.label_minute_14);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_minute_14;
            lv_label_set_text(objects.label_minute_14, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_screen_edit_alarm() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_edit_alarm = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Group_EditTime
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.group_edit_time = obj;
            lv_obj_set_pos(obj, 0, -10);
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
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // Label_Split_4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_split_4 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
            }
        }
        {
            // Label_AlarmType
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_alarm_type = obj;
            lv_obj_set_pos(obj, 0, -70);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // AlarmEdit
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.alarm_edit = obj;
            lv_obj_set_pos(obj, 209, 193);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_bitmap_alarm_off);
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
        const char *new_val = get_var_var_edit_minute();
        const char *cur_val = lv_label_get_text(objects.label_edit_minute);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_edit_minute;
            lv_label_set_text(objects.label_edit_minute, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_var_alarm_type();
        const char *cur_val = lv_label_get_text(objects.label_alarm_type);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_alarm_type;
            lv_label_set_text(objects.label_alarm_type, new_val);
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
