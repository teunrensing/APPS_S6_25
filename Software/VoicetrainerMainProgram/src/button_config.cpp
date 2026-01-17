// Pre defined configurations for the display buttons.
#include <button_config.h>
#include <buttons.h>

ButtonConfiguration loadedConfiguration = HOME;

void loadButtons(ButtonConfiguration configuration)
{
    loadedConfiguration = configuration;
    switch (configuration)
    {
    case ButtonConfiguration::HOME:
        button_queue_send(UpLeft, SleepAlarm);
        button_queue_send(DownLeft, PillAlarm);
        button_queue_send(UpRight, SpeechTrainer);
        button_queue_send(DownRight, Blank);
        break;
    case ButtonConfiguration::PILLALARM_1_3:
        button_queue_send(UpLeft, Digit1);
        button_queue_send(DownLeft, Digit2);
        button_queue_send(UpRight, Digit3);
        button_queue_send(DownRight, Next);
        break;
    case ButtonConfiguration::PILLALARM_4_5:
        button_queue_send(UpLeft, Digit4);
        button_queue_send(DownLeft, Back);
        button_queue_send(UpRight, Digit5);
        button_queue_send(DownRight, Next);
        break;
    case ButtonConfiguration::PILLALARM_6_8:
        button_queue_send(UpLeft, Digit6);
        button_queue_send(DownLeft, Back);
        button_queue_send(UpRight, Digit7);
        button_queue_send(DownRight, Digit8);
        break;
    case ButtonConfiguration::PILLALARM_OPTIONS:
        button_queue_send(UpLeft, Off); // Depends on alarm state
        button_queue_send(DownLeft, Back);
        button_queue_send(UpRight, Edit);
        button_queue_send(DownRight, Blank);
        break;
    case ButtonConfiguration::SLEEPALARM_OPTIONS:
        button_queue_send(UpLeft, Off); // Depends on alarm state
        button_queue_send(DownLeft, Blank);
        button_queue_send(UpRight, Edit);
        button_queue_send(DownRight, Blank);
        break;
    case ButtonConfiguration::EDIT_ALARM_HOUR:
        button_queue_send(UpLeft, Decrease);
        button_queue_send(DownLeft, Back); // Could replace for cancel icon
        button_queue_send(UpRight, Increase);
        button_queue_send(DownRight, Next);
        break;
    case ButtonConfiguration::EDIT_ALARM_MINUTE:
        button_queue_send(UpLeft, Decrease);
        button_queue_send(DownLeft, Back);
        button_queue_send(UpRight, Increase);
        button_queue_send(DownRight, Confirm);
        break;
    case ButtonConfiguration::VOICE_TRAINER:
        button_queue_send(UpLeft, Blank);
        button_queue_send(DownLeft, Blank);
        button_queue_send(UpRight, Blank);
        button_queue_send(DownRight, Edit);
        break;
    case ButtonConfiguration::VOICE_CALIBRATION:
        button_queue_send(UpLeft, Blank);
        button_queue_send(DownLeft, Blank);
        button_queue_send(UpRight, Blank);
        button_queue_send(DownRight, Confirm);
        break;

    default:
        break;
    }
}

ButtonConfiguration getLoadedButtonConfiguration()
{
    return loadedConfiguration;
}