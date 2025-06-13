#include <LovyanGFX.hpp>
#include <ui.h>
#include <screens.h>
#include <vars.h>
#include "pinout.hpp"

//Screen 
#define SCREEN_WIDTH  480
#define SCREEN_HEIGHT 320
//Button pins

// --- Display config ---
class LGFX_ILI9488 : public lgfx::LGFX_Device {
    lgfx::Panel_ILI9488 _panel;
    lgfx::Bus_SPI _bus;

  public:
    LGFX_ILI9488(void) {
      lgfx::Bus_SPI::config_t bus_cfg;
      bus_cfg.spi_host = SPI2_HOST;
      bus_cfg.spi_mode = 0;
      bus_cfg.freq_write = 20000000;
      bus_cfg.freq_read = 16000000;

      bus_cfg.dma_channel = SPI_DMA_CH_AUTO;
      bus_cfg.pin_sclk = SPI0_CLK;
      bus_cfg.pin_mosi = SPI0_MOSI;
      bus_cfg.pin_miso = SPI0_MISO;
      bus_cfg.pin_dc = SPI0_DC;
      _bus.config(bus_cfg);
      _panel.setBus(&_bus);

      lgfx::Panel_ILI9488::config_t panel_cfg;
      panel_cfg.pin_cs = SPI0_CS;
      panel_cfg.pin_rst = SPI0_RST;
      panel_cfg.pin_busy = -1;
      panel_cfg.memory_width = 320;
      panel_cfg.memory_height = 480;
      panel_cfg.panel_width = 320;
      panel_cfg.panel_height = 480;
      panel_cfg.offset_x = 0;
      panel_cfg.offset_y = 0;
      panel_cfg.offset_rotation = 0;
      panel_cfg.dummy_read_pixel = 8;
      panel_cfg.dummy_read_bits = 8;
      panel_cfg.readable = true;
      panel_cfg.invert = false;
      panel_cfg.rgb_order = false;
      panel_cfg.dlen_16bit = false;
      panel_cfg.bus_shared = true;
      _panel.config(panel_cfg);

      setPanel(&_panel);
    }
};
// Display buffers
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *buf1 = nullptr;
static lv_color_t *buf2 = nullptr;
// buf1 = (lv_color_t *)heap_caps_malloc(SCREEN_WIDTH * 40 * sizeof(lv_color_t), MALLOC_CAP_DMA);
// buf2 = (lv_color_t *)heap_caps_malloc(SCREEN_WIDTH * 40 * sizeof(lv_color_t), MALLOC_CAP_DMA);

// Button states

static bool button_pressed1 = false;
static bool button_pressed2 = false;
static bool button_pressed3 = false;
static bool button_pressed4 = false;


void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);

void display_init();
// void buttons_init();
// void buttons_function();
void update_time();
//void handleButton(uint8_t id);
void task_check_buttons(void* pvParameters);