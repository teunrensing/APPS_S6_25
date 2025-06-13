#include <Arduino.h>
#include <lvgl.h>
#include <vars.h>
#include "display.hpp"
#include <string>

// --- Timekeeping ---
struct Time
{
  int hour;
  int minute;
  int second;
};


static Time baseTime = {0, 0, 0};
static unsigned long startMillis = 0;
static char timeStr[6] = "00:00";

// --- Alarm and Time Settings ---
static char alarm1[6] = "00:00";
static char alarm2[6] = "00:00";
static char alarm3[6] = "00:00";
static char alarm4[6] = "00:00";
static char slaap[6] = "00:00";
static char wakker[6] = "00:00";

static bool klok = false;
static int32_t battery = 100;
static int32_t volume = 80;
static int32_t frequency = 0;
static float amplitude = 0.0;

// --- New Global Variables ---
static std::string edit_text;
static char edit_time[6] = "00:00";
static bool edit_box1 = false;
static bool edit_box2 = false;
static bool edit_text_bool = false;

// Battery
extern "C" int32_t get_var_battery() { return battery; }
extern "C" void set_var_battery(int32_t value) { battery = value; }

extern "C" int32_t get_var_volume() { return volume; }
extern "C" void set_var_volume(int32_t value) { volume = value; }

// Time
extern "C" const char *get_var_time()
{
  unsigned long elapsed = (millis() - startMillis) / 1000;
  int s = baseTime.second + elapsed;
  int m = baseTime.minute + s / 60;
  int h = baseTime.hour + m / 60;
  s %= 60;
  m %= 60;
  h %= 24;
  snprintf(timeStr, sizeof(timeStr), "%02d:%02d", h, m);
  return timeStr;
}

extern "C" void set_var_time(const char *value)
{
  int hh, mm, ss = 0;
  if (sscanf(value, "%d:%d:%d", &hh, &mm, &ss) >= 2)
  {
    baseTime.hour = hh % 24;
    baseTime.minute = mm % 60;
    baseTime.second = ss % 60;
    startMillis = millis();
  }
}

// Alarm Setters
extern "C" void set_var_alarm1(const char *value)
{
  int hh, mm;
  if (sscanf(value, "%d:%d", &hh, &mm) == 2)
    snprintf(alarm1, sizeof(alarm1), "%02d:%02d", hh % 24, mm % 60);
}
extern "C" void set_var_alarm2(const char *value)
{
  int hh, mm;
  if (sscanf(value, "%d:%d", &hh, &mm) == 2)
    snprintf(alarm2, sizeof(alarm2), "%02d:%02d", hh % 24, mm % 60);
}
extern "C" void set_var_alarm3(const char *value)
{
  int hh, mm;
  if (sscanf(value, "%d:%d", &hh, &mm) == 2)
    snprintf(alarm3, sizeof(alarm3), "%02d:%02d", hh % 24, mm % 60);
}
extern "C" void set_var_alarm4(const char *value)
{
  int hh, mm;
  if (sscanf(value, "%d:%d", &hh, &mm) == 2)
    snprintf(alarm4, sizeof(alarm4), "%02d:%02d", hh % 24, mm % 60);
}
extern "C" void set_var_slaap(const char *value)
{
  int hh, mm;
  if (sscanf(value, "%d:%d", &hh, &mm) == 2)
    snprintf(slaap, sizeof(slaap), "%02d:%02d", hh % 24, mm % 60);
}
extern "C" void set_var_wakker(const char *value)
{
  int hh, mm;
  if (sscanf(value, "%d:%d", &hh, &mm) == 2)
    snprintf(wakker, sizeof(wakker), "%02d:%02d", hh % 24, mm % 60);
}

// Klok
extern "C" void set_var_klok(bool value) { klok = value; }
extern "C" bool get_var_klok() { return klok; }

// Alarm Getters
extern "C" const char *get_var_alarm1() { return alarm1; }
extern "C" const char *get_var_alarm2() { return alarm2; }
extern "C" const char *get_var_alarm3() { return alarm3; }
extern "C" const char *get_var_alarm4() { return alarm4; }
extern "C" const char *get_var_slaap() { return slaap; }
extern "C" const char *get_var_wakker() { return wakker; }

// edit_text
extern "C" const char *get_var_edit_text()
{
  return edit_text.c_str();
}
extern "C" void set_var_edit_text(const char *value)
{
  if (value)
  {
    edit_text = std::string(value).substr(0, 10);
  }
}
 extern "C" float get_var_amplitude()
  {
    return amplitude;
  }

 extern "C" void set_var_amplitude(float value)
  {
    amplitude = value;
  }

  extern "C" int32_t get_var_frequency()
  {
    return frequency;
  }

 extern "C"  void set_var_frequency(int32_t value)
  {
    frequency = value;
  }


// edit_time
extern "C" const char *get_var_edit_time()
{
  return edit_time;
}
extern "C" void set_var_edit_time(const char *value)
{
  int hh, mm;
  if (sscanf(value, "%d:%d", &hh, &mm) == 2)
    snprintf(edit_time, sizeof(edit_time), "%02d:%02d", hh % 24, mm % 60);
}

// edit_box1
extern "C" bool get_var_edit_box1() { return edit_box1; }
extern "C" void set_var_edit_box1(bool value) { edit_box1 = value; }

// edit_box2
extern "C" bool get_var_edit_box2() { return edit_box2; }
extern "C" void set_var_edit_box2(bool value) { edit_box2 = value; }

// edit_text_bool
extern "C" bool get_var_edit_text_bool() { return edit_text_bool; }
extern "C" void set_var_edit_text_bool(bool value) { edit_text_bool = value; }
