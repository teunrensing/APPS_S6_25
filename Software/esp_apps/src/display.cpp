#include <Arduino.h>
#include <Wire.h>
#include <lvgl.h>
#include <vars.h>
#include <LovyanGFX.hpp>
#include "display.hpp"
#include "switch.hpp"

LGFX_ILI9488 tft;

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1,
                    area->x2 - area->x1 + 1,
                    area->y2 - area->y1 + 1);
  tft.pushPixels((uint16_t *)&color_p->full,
                 (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1),
                 true);
  tft.endWrite();
  lv_disp_flush_ready(disp);
}

void task_check_buttons(void *pvParameters)
{

  while (1)
  {
    Wire.requestFrom(BUTTON_CONTROLLER_ADDR, 1);
    if (Wire.available())
    {
      uint8_t button = Wire.read();
      if (button >= 1 && button <= 4)
      {
        statemachine(button);
        // Send back the result
        send_icons();
      }
    }
    vTaskDelay(pdMS_TO_TICKS(100)); // 100 ms
  }
}

void display_init()
{
  tft.init();
  tft.setRotation(3);
  // buttons.button1 = Display_Icon::SleepAlarm;
  // buttons.button2 = Display_Icon::PillAlarm;
  // buttons.button3 = Display_Icon::SpeechTrainer;
  // buttons.button4 = Display_Icon::Blank;
  // Wire.beginTransmission(BUTTON_CONTROLLER_ADDR);
  // Wire.write(buttons.button1);
  // Wire.write(buttons.button2);
  // Wire.write(buttons.button3);
  // Wire.write(buttons.button4);
  // Wire.endTransmission();
  init_icons();
  size_t buf_size = SCREEN_WIDTH * 40;

  buf1 = (lv_color_t *)heap_caps_malloc(buf_size * sizeof(lv_color_t), MALLOC_CAP_DMA);
  buf2 = (lv_color_t *)heap_caps_malloc(buf_size * sizeof(lv_color_t), MALLOC_CAP_DMA);

  if (!buf1 || !buf2)
  {
    Serial.println("Failed to allocate LVGL draw buffers");
    while (1)
      ; // halt
  }

  lv_init();

  lv_disp_draw_buf_init(&draw_buf, buf1, buf2, buf_size);

  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);

  disp_drv.hor_res = SCREEN_WIDTH;
  disp_drv.ver_res = SCREEN_HEIGHT;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;

  lv_disp_drv_register(&disp_drv);

  Serial.println("Display initialized");
}

// void buttons_function() {
//   if (digitalRead(BUTTON_PIN_1) == LOW && !button_pressed1) {
//     statemachine_button1();
//     button_pressed1 = true;
//   } else if (digitalRead(BUTTON_PIN_1) == HIGH) {
//     button_pressed1 = false;
//   }

//   // Button 2: Load Screen 2
//   if (digitalRead(BUTTON_PIN_2) == LOW && !button_pressed2) {
//       statemachine_button2();
//     button_pressed2 = true;
//   } else if (digitalRead(BUTTON_PIN_2) == HIGH) {
//     button_pressed2 = false;
//   }

//   // Button 3: Load Screen 3
//   if (digitalRead(BUTTON_PIN_3) == LOW && !button_pressed3) {
//      statemachine_button3();
//     button_pressed3 = true;
//   } else if (digitalRead(BUTTON_PIN_3) == HIGH) {
//     button_pressed3 = false;
//   }

//   // Button 4: Switch screens
//   if (digitalRead(BUTTON_PIN_4) == LOW && !button_pressed4) {
//      statemachine_button4();
//     button_pressed4 = true;
//   } else if (digitalRead(BUTTON_PIN_4) == HIGH) {
//     button_pressed4 = false;
//   }
//   //Serial.println("");
// }
static unsigned long lastUpdate = 0;
void update_time()
{

  if (millis() - lastUpdate >= 1000)
  {
    lastUpdate = millis();
    set_var_time(get_var_time()); // Trigger variable update for UI
  }
}
