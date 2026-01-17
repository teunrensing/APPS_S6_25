#ifndef SLEEP_ALARM_UI_H
#define SLEEP_ALARM_UI_H

#include <buttons.h>
#include "screens.h"
#include <ui.h>

enum VoiceTrainerUIState
{
    VOICE_TRAINING,
    VOICE_CALIBRATING
};

void handleButtonPressVoiceTrainer(const button_cmd_t &btn);
void handleVoiceTraining(const button_cmd_t &btn);
void handleVoiceCalibrating(const button_cmd_t &btn);

#endif