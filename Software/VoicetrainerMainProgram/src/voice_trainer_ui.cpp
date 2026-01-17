#include <voice_trainer_ui.h>
#include <button_config.h>
#include <mode_controller.h>
#include <ui.h>
#include <vars.h>
#include <helper_functions.h>
#include "screens.h"
#include <freertos_wrapper.h>
#include <logger.h>

VoiceTrainerUIState currentVoiceTrainerState = VoiceTrainerUIState::VOICE_TRAINING;

void handleButtonPressVoiceTrainer(const button_cmd_t &btn)
{
    switch (currentVoiceTrainerState)
    {
    case VoiceTrainerUIState::VOICE_TRAINING:
        handleVoiceTraining(btn);
        break;
    case VoiceTrainerUIState::VOICE_CALIBRATING:
        handleVoiceCalibrating(btn);
        break;
    default:
        currentVoiceTrainerState = VoiceTrainerUIState::VOICE_TRAINING;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}

void handleVoiceTraining(const button_cmd_t &btn)
{
    switch (btn.icon)
    {
    case Display_Icon::Edit:
        loadButtons(ButtonConfiguration::VOICE_CALIBRATION);
        currentVoiceTrainerState = VoiceTrainerUIState::VOICE_CALIBRATING;
        break;
    default:
        currentVoiceTrainerState = VoiceTrainerUIState::VOICE_TRAINING;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}

void handleVoiceCalibrating(const button_cmd_t &btn)
{
    switch (btn.icon)
    {
    case Display_Icon::Confirm:
        loadButtons(ButtonConfiguration::VOICE_TRAINER);
        currentVoiceTrainerState = VoiceTrainerUIState::VOICE_TRAINING;
        break;
    default:
        currentVoiceTrainerState = VoiceTrainerUIState::VOICE_TRAINING;
        change_mode(AppMode::MODE_HOME);
        break;
    }
}