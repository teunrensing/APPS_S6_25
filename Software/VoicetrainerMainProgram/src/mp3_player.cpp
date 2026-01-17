#include <mp3_player.h>
#include <Arduino.h>
#include <parameters.h>
#include <HardwareSerial.h>

static HardwareSerial dfSerial(1);
static SemaphoreHandle_t mp3Mutex = nullptr;

/**
 * Low-level command sender
 */
static void sendCommand(uint8_t cmd, uint16_t param)
{
    uint8_t buffer[10];

    buffer[0] = 0x7E;
    buffer[1] = 0xFF;
    buffer[2] = 0x06;
    buffer[3] = cmd;
    buffer[4] = 0x00;         // no feedback
    buffer[5] = param >> 8;   // DH
    buffer[6] = param & 0xFF; // DL

    uint16_t checksum = 0xFFFF -
                        (buffer[1] + buffer[2] + buffer[3] +
                         buffer[4] + buffer[5] + buffer[6]) +
                        1;

    buffer[7] = checksum >> 8;
    buffer[8] = checksum & 0xFF;
    buffer[9] = 0xEF;

    dfSerial.write(buffer, 10);
}

/**
 * Initialize MP3 module
 */
void init_mp3()
{
    dfSerial.begin(MP3_baud, SERIAL_8N1, MP3_RX, MP3_TX);

    mp3Mutex = xSemaphoreCreateMutex();

    vTaskDelay(pdMS_TO_TICKS(2000));

    set_mp3_volume(20);
}

/**
 * Set volume (0–30)
 */
void set_mp3_volume(uint8_t volume)
{
    if (volume > 30)
        volume = 30;

    if (xSemaphoreTake(mp3Mutex, pdMS_TO_TICKS(500)) == pdTRUE)
    {
        sendCommand(0x06, volume);
        xSemaphoreGive(mp3Mutex);
    }
}

void play_mp3_sound(mp3Sounds sound)
{
    if (xSemaphoreTake(mp3Mutex, portMAX_DELAY) == pdTRUE)
    {
        sendCommand(0x03, static_cast<uint16_t>(sound));
        xSemaphoreGive(mp3Mutex);
    }
}