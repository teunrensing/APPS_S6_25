// Reads the button states and writes the icons.

#ifndef BUTTONS_H
#define BUTTONS_H

#include "freertos_wrapper.h"

enum Display_Icon // Needs to be the same as button_module
{
    // Empty screen
    Blank,

    // System Control
    Off,
    On,
    Edit,
    Confirm,
    Start,
    Stop,
    Retry,

    // Navigation

    Next,
    Back,

    // Media
    Play,
    Pause,
    VolumeUp,
    VolumeDown,

    // Devices
    PillAlarm,
    SleepAlarm,
    SpeechTrainer,

    // Adjustment
    Increase,
    Decrease,

    // Digits
    Digit0,
    Digit1,
    Digit2,
    Digit3,
    Digit4,
    Digit5,
    Digit6,
    Digit7,
    Digit8,
    Digit9,
};

enum Button_Name // Needs to be the same as button_module
{
    None,
    UpLeft,
    DownLeft,
    UpRight,
    DownRight
};

struct button_cmd_t
{
    Button_Name name;
    Display_Icon icon;
};

void button_init(void);
esp_err_t button_queue_send(Button_Name buttonName, Display_Icon icon);
esp_err_t button_queue_receive(button_cmd_t *received_button, TickType_t timeout);
void start_button_task();

#endif
