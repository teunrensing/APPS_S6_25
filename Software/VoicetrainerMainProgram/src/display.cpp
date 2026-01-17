#include "display.h"
#include "parameters.h"
#include "ui.h"

// In dit bestand definieer je de eigenlijke class
class LGFX_SPI : public lgfx::LGFX_Device
{
  lgfx::Panel_ILI9488 _panel_instance;
  lgfx::Bus_SPI _bus_instance;

public:
  LGFX_SPI(void)
  {
    // SPI-bus instellingen
    auto cfg = _bus_instance.config();

    cfg.spi_host = SPI2_HOST; // SPI2_HOST voor ESP32-S3
    cfg.spi_mode = 0;
    cfg.freq_write = 20000000;
    cfg.freq_read = 16000000;
    cfg.spi_3wire = false;
    cfg.use_lock = true;
    cfg.dma_channel = 1;
    cfg.pin_sclk = DISPLAY_CLK_PIN;
    cfg.pin_mosi = DISPLAY_MOSI_PIN;
    cfg.pin_miso = DISPLAY_MISO_PIN;
    cfg.pin_dc = DISPLAY_DC_PIN;

    _bus_instance.config(cfg);
    _panel_instance.setBus(&_bus_instance);

    auto panel_cfg = _panel_instance.config();

    panel_cfg.pin_cs = DISPLAY_CS_PIN;
    panel_cfg.pin_rst = DISPLAY_RST_PIN;
    panel_cfg.pin_busy = -1;

    panel_cfg.memory_width = 320;
    panel_cfg.memory_height = 480;
    panel_cfg.panel_width = 320;
    panel_cfg.panel_height = 480;
    panel_cfg.offset_x = 0;
    panel_cfg.offset_y = 0;
    panel_cfg.offset_rotation = 0;
    panel_cfg.dummy_read_pixel = 8;
    panel_cfg.dummy_read_bits = 1;
    panel_cfg.readable = true;
    panel_cfg.invert = false;
    panel_cfg.rgb_order = false;
    panel_cfg.dlen_16bit = false;
    panel_cfg.bus_shared = true;

    _panel_instance.config(panel_cfg);
    setPanel(&_panel_instance);
  }
};

// Define het globale object
LGFX_SPI mainDisplay;

// Buffers voor LVGL
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[320 * 40];

unsigned long last_tick = 0;

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = area->x2 - area->x1 + 1;
  uint32_t h = area->y2 - area->y1 + 1;
  mainDisplay.startWrite();
  mainDisplay.setAddrWindow(area->x1, area->y1, w, h);
  mainDisplay.pushImageDMA(area->x1, area->y1, w, h, (lgfx::rgb565_t *)&color_p->full);
  mainDisplay.endWrite();
  lv_disp_flush_ready(disp);
}

void init_display()
{
  mainDisplay.init();
  mainDisplay.setRotation(3);

  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf1, NULL, sizeof(buf1) / sizeof(lv_color_t));

  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  disp_drv.hor_res = 480;
  disp_drv.ver_res = 320;
  lv_disp_drv_register(&disp_drv);
}

void display_task(void *pv)
{
  while (true)
  {
    unsigned long now = millis();
    if (now - last_tick >= 1)
    {
      lv_tick_inc(now - last_tick); // geef verstreken tijd door
      last_tick = now;
    }

    lv_timer_handler(); // verwerk LVGL
    ui_tick();          // verwerk EEZ logica
    vTaskDelay(pdMS_TO_TICKS(5));
  }
}

void start_display_task()
{
  xTaskCreate(display_task, "Display", 8192, NULL, 1, NULL);
}
