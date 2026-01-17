// Controls the MP3 player to play sounds on the speaker.
// NOTE! MP3 player is defect, might solve sound later.
#ifndef MP3_PLAYER_H
#define MP3_PLAYER_H

#include <Arduino.h>

enum mp3Sounds : uint8_t
{
    AlarmWakeUp = 1,
    AlarmPills,
    SpeechZachter,
    SpeechHarder,
    SpeechPillen,
    ZachtjesWakkerWorden,
    sound7,
    sound8,
    sound9,
    sound10
};

void init_mp3();
void set_mp3_volume(uint8_t volume);
void play_mp3_sound(mp3Sounds sound);

#endif
