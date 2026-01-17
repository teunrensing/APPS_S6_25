#include "mode_config.h"
#include "freertos_wrapper.h"
#include "lvgl.h"
#include "ui.h"
#include "buttons.h"
#include <i2c.h>
#include <parameters.h>
#include <logger.h>
#include <helper_functions.h>

static QueueHandle_t button_tx_queue;
static QueueHandle_t button_rx_queue;

void button_init(void)
{
  button_tx_queue = xQueueCreate(10, sizeof(button_cmd_t));
  button_rx_queue = xQueueCreate(10, sizeof(button_cmd_t));
}

esp_err_t button_queue_send(Button_Name buttonName, Display_Icon icon)
{
  button_cmd_t send_button;
  send_button.name = buttonName;
  send_button.icon = icon;
  return xQueueSend(button_tx_queue, &send_button, pdMS_TO_TICKS(10)) == pdTRUE ? ESP_OK : ESP_FAIL;
}

esp_err_t button_queue_receive(button_cmd_t *received_button, TickType_t timeout)
{
  return xQueueReceive(button_rx_queue, received_button, timeout) == pdTRUE ? ESP_OK : ESP_FAIL;
}

void i2c_write_task(void *pvParameters)
{
  button_cmd_t cmd;
  while (1)
  {
    if (xQueueReceive(button_tx_queue, &cmd, portMAX_DELAY))
    {
      I2C_Secondary.beginTransmission(BUTTON_MODULE_MCU_ADRESS);
      I2C_Secondary.write(cmd.name);
      I2C_Secondary.write(cmd.icon);
      I2C_Secondary.endTransmission();
    }
  }
}

void i2c_read_task(void *pvParameters)
{
  button_cmd_t cmd;
  Button_Name last_button_pressed = None;
  while (1)
  {
    I2C_Secondary.requestFrom(BUTTON_MODULE_MCU_ADRESS, 2);
    if (I2C_Secondary.available())
    {
      Button_Name current_button_pressed = (Button_Name)I2C_Secondary.read();
      Display_Icon current_icon_pressed = (Display_Icon)I2C_Secondary.read();
      if (current_button_pressed != last_button_pressed)
      {
        last_button_pressed = current_button_pressed;
        if (current_button_pressed != None)
        {
          log_message("Incoming:");
          log_message(uint8ToString(current_button_pressed));
          log_message(uint8ToString(current_icon_pressed));
          cmd.name = current_button_pressed;
          cmd.icon = current_icon_pressed;
          xQueueSend(button_rx_queue, &cmd, pdMS_TO_TICKS(10));
        }
      }
    }
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}

void start_button_task()
{
  xTaskCreate(i2c_write_task, "i2c_write_task", 4096, NULL, 1, NULL);
  xTaskCreate(i2c_read_task, "i2c_read_task", 4096, NULL, 1, NULL);
}
