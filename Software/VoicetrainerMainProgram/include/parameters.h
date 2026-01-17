#ifndef PARAMETER_H
#define PARAMETER_H

// My voice
#define voiceMinAmp 65
#define voiceAverageAmp 90
#define voiceMaxAmp 100
#define voiceMinFreq 150
#define voiceAverageFreq 460
#define voiceMaxFreq 3000

// Main Display
#define DISPLAY_MOSI_PIN 12 // SPI0 MOSI
#define DISPLAY_MISO_PIN -1 // 13 // SPI0 MISO
#define DISPLAY_CLK_PIN 13  // SPI0 CLK
#define DISPLAY_CS_PIN 10   // SPI0 CS
#define DISPLAY_DC_PIN 1
#define DISPLAY_RST_PIN -1

// Microphone
#define MIC_CLK_PIN 40  // I2S CLK
#define MIC_WS_PIN 41   // I2S WS
#define MIC_DATA_PIN 42 // I2S SD
#define MIC_SAMPLE_RATE 16000
#define I2S_PORT I2S_NUM_0

// I2C bus 0 ( for Secundair modules)
#define I2C0_FREQ 400000
#define SCL0 6
#define SDA0 3
#define BUTTON_MODULE_MCU_ADRESS 0x08 // Interactive button control ESP32-S3

// I2C bus 1 (for Primair modules)
#define I2C1_FREQ 400000
#define SCL1 4
#define SDA1 5
#define POWER_MODULE_GPIO_ARDRESS 0x20 // Power Module PCA6408A GPIO Expander

// MP3 Player
#define MP3_baud 9600
#define MP3_TX 43
#define MP3_RX 44

// Home button
#define HOME_BUTTON_PIN 39

// Wifi settings
#define WIFI_SSID "Voicetrainer"
#define WIFI_PASSWORD "APPSS62025"

#endif
