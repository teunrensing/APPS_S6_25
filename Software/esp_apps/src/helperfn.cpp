#include <Arduino.h>
#include <string>
#include <cstdio> // For snprintf
#include "display.hpp"
#include "helperfn.hpp"
#include "microphone_i2s.hpp"
#include "signalprocessing.hpp"
#include <vars.h>

int timeStringToMinutes(const char *timeStr)
{
    int hours = 0, minutes = 0;
    if (sscanf(timeStr, "%d:%d", &hours, &minutes) == 2)
    {
        return hours * 60 + minutes;
    }
    return 0; // Return 0 if parsing fails
}

// Convert total minutes as int back to "HH:MM" string (output buffer should be at least 6 bytes)
void minutesToTimeString(int totalMinutes, char *buffer, size_t bufferSize)
{
    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;
    snprintf(buffer, bufferSize, "%02d:%02d", hours, minutes);
}

void editTimeHourAdd()
{
    const char *original = get_var_edit_time();
    Serial.printf("[editTimeHourAdd] Original time: %s\n", original);

    int time = timeStringToMinutes(original);
    Serial.printf("[editTimeHourAdd] Time in minutes: %d\n", time);

    time += 60;
    if (time >= 24 * 60)
        time = 0;

    char time_string[6];
    minutesToTimeString(time, time_string, sizeof(time_string));
    Serial.printf("[editTimeHourAdd] New time string: %s\n", time_string);

    set_var_edit_time(time_string);
}

void editTimeHourMinus()
{
    const char *original = get_var_edit_time();
    Serial.printf("[editTimeHourMinus] Original time: %s\n", original);

    int time = timeStringToMinutes(original);
    Serial.printf("[editTimeHourMinus] Time in minutes: %d\n", time);

    time -= 60;
    if (time < 0)
        time = 23 * 60;

    char time_string[6];
    minutesToTimeString(time, time_string, sizeof(time_string));
    Serial.printf("[editTimeHourMinus] New time string: %s\n", time_string);

    set_var_edit_time(time_string);
}

void editTimeMinutsAdd()
{
    int time = timeStringToMinutes(get_var_edit_time());
    time = (time + 5) % (24 * 60); // Wraps to 0 after 1439
    char time_string[6];
    minutesToTimeString(time, time_string, sizeof(time_string));
    set_var_edit_time(time_string);
}

void editTimeMinutsMinus()
{
    int time = timeStringToMinutes(get_var_edit_time());
    time = (time - 5 + 24 * 60) % (24 * 60); // Handles negative wrap
    char time_string[6];
    minutesToTimeString(time, time_string, sizeof(time_string));
    set_var_edit_time(time_string);
}


