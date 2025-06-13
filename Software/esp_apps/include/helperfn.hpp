#include <string>
#include <Arduino.h>

static bool alarm1 = false;
static bool alarm2 = false;
static bool alarm3 = false;
static bool alarm4 = false;
static bool wake_alarm = false;
static bool trainer = false;



int timeStringToMinutes(const char* timeStr);

void minutesToTimeString(int totalMinutes, char* buffer, size_t bufferSize);

void editTimeHourAdd();
void editTimeHourMinus();
void editTimeMinutsAdd();
void editTimeMinutsMinus();
void voiceTrainer(void *pvParameters);