#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <Arduino.h>
#include "screens.h"
#include "images.h"

const char *uint8ToString(uint8_t value, uint8_t minDigits = 0);
void setClockIconActive(lv_obj_t *alarmIcon, bool active);

#endif