#ifndef DISPLAY_H
#define DISPLAY_H

#include <lvgl.h>
#include <LovyanGFX.hpp>

// Forward declaration van jouw LGFX_SPI class
class LGFX_SPI;

// Extern zodat je dit display object ook elders kunt gebruiken
extern LGFX_SPI mainDisplay;

void init_display();  // Call this from setup()

void start_display_task();

#endif
