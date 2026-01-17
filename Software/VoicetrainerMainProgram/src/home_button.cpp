#include "home_button.h"
#include "parameters.h"
#include "mode_controller.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

static QueueHandle_t buttonQueue = nullptr;

void home_button_pressed()
{
    change_mode(AppMode::MODE_HOME);
}

void IRAM_ATTR homeButtonISR()
{
    uint8_t event = 1;
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xQueueSendFromISR(buttonQueue, &event, &xHigherPriorityTaskWoken);

    if (xHigherPriorityTaskWoken)
        portYIELD_FROM_ISR();
}

static void homeButtonTask(void *pv)
{
    uint8_t event;

    while (true)
    {
        if (xQueueReceive(buttonQueue, &event, portMAX_DELAY))
        {
            // simpele debounce
            vTaskDelay(pdMS_TO_TICKS(50));

            if (digitalRead(HOME_BUTTON_PIN) == LOW)
            {
                home_button_pressed();
            }
        }
    }
}

/**
 * Init button + interrupt + task
 */
void init_home_button()
{
    pinMode(HOME_BUTTON_PIN, INPUT_PULLUP);

    buttonQueue = xQueueCreate(5, sizeof(uint8_t));

    attachInterrupt(
        digitalPinToInterrupt(HOME_BUTTON_PIN),
        homeButtonISR,
        FALLING);

    xTaskCreatePinnedToCore(
        homeButtonTask,
        "HomeButtonTask",
        2048,
        nullptr,
        10,
        nullptr,
        1 // core 1
    );
}
