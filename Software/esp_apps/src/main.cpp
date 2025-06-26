#include <Arduino.h>
#include <Wire.h>
#include <LovyanGFX.hpp>
#include <lvgl.h>
#include <ui.h>
#include <screens.h>
#include <vars.h>
#include "display.hpp"
#include "microphone_i2s.hpp"
#include "signalprocessing.hpp"
#include "helperfn.hpp"
#include "mic_handel.hpp"
#include "pinout.hpp"

// Setup and loop
void setup()
{
    Serial.begin(115200);
    Wire.begin(sda0,scl0,0); // SDA/SCL default or Wire.begin(sda, scl);

    // Wire.begin(5, 4);
    // //delay(1000);
    // Wire.beginTransmission(PCA6408_ADDR);
    // Wire.write(0x03); // Configuration register
    // Wire.write(0x03); // All outputs
    // Wire.endTransmission();
    Serial.println("dit is de start");
    
    // Wire.beginTransmission(PCA6408_ADDR);
    // Wire.write(0x01); // Configuration register
    // Wire.write(0xFC); // All outputs
    // Wire.endTransmission();
    display_init();
    // pinMode(BUTTON_PIN_1, INPUT_PULLUP);
    // pinMode(BUTTON_PIN_2, INPUT_PULLUP);
    // pinMode(BUTTON_PIN_3, INPUT_PULLUP);
    // pinMode(BUTTON_PIN_4, INPUT_PULLUP);



    set_var_time(__TIME__);
    set_var_battery(100);
    ui_init(); // EEZ Studio–generated UI init

    // Start FreeRTOS tasks
    // if (trainerTreshold) {
    // xTaskCreatePinnedToCore(task_calibration, "calibration", 8192, nullptr, 1, nullptr, 1);
    // }
    xTaskCreatePinnedToCore(task_read_audio, "read_audio", 4096, nullptr, 1, nullptr, 0);
    xTaskCreatePinnedToCore(task_process_audio, "process_audio", 8192, nullptr, 1, nullptr, 1);
    xTaskCreatePinnedToCore(uiTask, "ui_loop", 4096, nullptr, 1, nullptr, 1);
    xTaskCreatePinnedToCore(task_check_buttons, "CheckButtons", 4096, nullptr, 1, nullptr, 1);

}

void loop()
{
    // niks
}
