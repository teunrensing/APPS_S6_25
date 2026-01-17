#include <helper_functions.h>
#include <Arduino.h>

const char *uint8ToString(uint8_t value, uint8_t minDigits)
{
    static char buffer[5];

    char format[6];
    snprintf(format, sizeof(format), "%%0%uu", minDigits);

    snprintf(buffer, sizeof(buffer), format, value);
    return buffer;
}

void setClockIconActive(lv_obj_t *alarmIcon, bool active)
{
    if (active)
    {
        lv_img_set_src(alarmIcon, &img_bitmap_alarm_on);
    }
    else
    {
        lv_img_set_src(alarmIcon, &img_bitmap_alarm_off);
    }
}
