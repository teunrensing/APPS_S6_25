#ifndef BUTTON_CONFIG_H
#define BUTTON_CONFIG_H

#include <Arduino.h>

enum ButtonConfiguration : uint8_t
{
    HOME,
    PILLALARM_1_3,
    PILLALARM_4_5,
    PILLALARM_6_8,
    PILLALARM_OPTIONS,
    SLEEPALARM_OPTIONS,
    EDIT_ALARM_HOUR,
    EDIT_ALARM_MINUTE,
    VOICE_TRAINER,
    VOICE_CALIBRATION
};

void loadButtons(ButtonConfiguration configuration);
ButtonConfiguration getLoadedButtonConfiguration();

#endif
