#include "SPI.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include "bitMap.h"
 
#define TFT_SCLK        12
 
#define TFT_CS1          41
#define TFT_RST1         47// Or set to -1 and connect to Arduino RESET pin
#define TFT_DC1          14          
#define TFT_MOSI1        37
 
#define button1          42
#define fibr1            18
 
#define TFT_CS2          7
#define TFT_RST2         48// Or set to -1 and connect to Arduino RESET pin
#define TFT_DC2          15          
#define TFT_MOSI2        38
 
#define button2          8
#define fibr2            13
 
#define TFT_CS3          1
#define TFT_RST3         45// Or set to -1 and connect to Arduino RESET pin
#define TFT_DC3          9          
#define TFT_MOSI3        35
 
#define button3          2
#define fibr3            21
 
#define TFT_CS4          3
#define TFT_RST4         46// Or set to -1 and connect to Arduino RESET pin
#define TFT_DC4          10          
#define TFT_MOSI4        36
 
#define button4          40
#define fibr4            17
 
 
Adafruit_ST7735 tft1 = Adafruit_ST7735(TFT_CS1, TFT_DC1, TFT_MOSI1, TFT_SCLK, TFT_RST1);
Adafruit_ST7735 tft2 = Adafruit_ST7735(TFT_CS2, TFT_DC2, TFT_MOSI2, TFT_SCLK, TFT_RST2);
Adafruit_ST7735 tft3 = Adafruit_ST7735(TFT_CS3, TFT_DC3, TFT_MOSI3, TFT_SCLK, TFT_RST3);
Adafruit_ST7735 tft4 = Adafruit_ST7735(TFT_CS4, TFT_DC4, TFT_MOSI4, TFT_SCLK, TFT_RST4);
 
void UIT();
 
void setup() {
  // put your setup code here, to run once:
  tft1.initR(INITR_GREENTAB);
  tft2.initR(INITR_GREENTAB);
  tft3.initR(INITR_GREENTAB);
  tft4.initR(INITR_GREENTAB);
  tft1.fillScreen(ST7735_BLACK);
  tft2.fillScreen(ST7735_BLACK);
  tft3.fillScreen(ST7735_BLACK);
  tft1.drawBitmap(0, 0, sleepAlarm, 128, 128, ST7735_WHITE);
  tft2.drawBitmap(0, 0, medicineAlarm, 128, 128, ST7735_WHITE);
  tft3.drawBitmap(0, 0, spraakTrainer, 128, 128, ST7735_WHITE);
  UIT();
  pinMode(fibr1, OUTPUT);
  pinMode(fibr2, OUTPUT);
  pinMode(fibr3, OUTPUT);
  pinMode(fibr4, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("hI");
}
 
void loop() {
  // put your main code here, to run repeatedly:
 
}
 
 
void UIT() {
  tft2.fillScreen(ST7735_WHITE);
  tft2.setCursor(8, 48);
  tft2.setTextColor(ST77XX_BLACK);  
  tft2.setTextSize(5);
  tft2.println("UIT");
}
 

// #include <Arduino.h>
// #include <Wire.h>

// volatile uint8_t button_state = 0;
// volatile bool data_requested = false;

// void onRequest() {
//   Wire.write(button_state);
//   button_state = 0; // Reset after sending
// }

// void onReceive(int len) {
//   if (len >= 4) {
//     int value1 = Wire.read() | (Wire.read() << 8);
//     int value2 = Wire.read() | (Wire.read() << 8);
//     Serial.printf("Received: %d, %d\n", value1, value2);
//   }
// }

// void setup() {
//   Serial.begin(115200);
//   Wire.begin(5, 4, 0x08); 
//   Wire.onRequest(onRequest);
//   Wire.onReceive(onReceive);
//   pinMode(1, INPUT_PULLUP);
//   pinMode(2, INPUT_PULLUP);
//   pinMode(42, INPUT_PULLUP);
//   pinMode(41, INPUT_PULLUP);
// }

// void loop() {
//   if (digitalRead(1) == LOW) button_state = 1;
//   else if (digitalRead(2) == LOW) button_state = 2;
//   else if (digitalRead(42) == LOW) button_state = 3;
//   else if (digitalRead(41) == LOW) button_state = 4;
//   delay(50); // debounce
// }
