#include "bitmap.h"

#ifndef DISPLAY_ICONS_H
#define DISPLAY_ICONS_H

enum Display_Icon
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
    Digit9
};

#endif