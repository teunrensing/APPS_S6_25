#include <Arduino.h>
#include <Wire.h>
#include "SPI.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include "bitmap.h"
#include "display_icons.h"
#include "pinout.h"

void drawIconToDisplay(Adafruit_ST7735& display, const unsigned char* bitMap);
void writeTextToDisplay(Adafruit_ST7735& display, const char* text);
void writeDisplay(Adafruit_ST7735 display, Display_Icon icon);
void writeDisplays();

volatile uint8_t button_state = 0;
volatile bool data_requested = false;
bool received = 1;

SPIClass spiBus(FSPI);

Display_Icon display1Icon = Display_Icon::Blank;
Display_Icon display2Icon = Display_Icon::Blank;
Display_Icon display3Icon = Display_Icon::Blank;
Display_Icon display4Icon = Display_Icon::Blank;
 
Adafruit_ST7735 tft1 = Adafruit_ST7735(&spiBus, TFT_CS1, TFT_DC1, TFT_RST1);
Adafruit_ST7735 tft2 = Adafruit_ST7735(&spiBus, TFT_CS2, TFT_DC2, TFT_RST2);
Adafruit_ST7735 tft3 = Adafruit_ST7735(&spiBus, TFT_CS3, TFT_DC3, TFT_RST3);
Adafruit_ST7735 tft4 = Adafruit_ST7735(&spiBus, TFT_CS4, TFT_DC4, TFT_RST4);

void onRequest() {
  Wire.write(button_state);
  button_state = 0; // Reset after sending
}

void onReceive(int len) {
  if (len >= 4) {
    received = true;
    display1Icon = (Display_Icon)Wire.read();
    display2Icon = (Display_Icon)Wire.read();
    display3Icon = (Display_Icon)Wire.read();
    display4Icon = (Display_Icon)Wire.read();
  }
}

 
void setup() {
//   Serial.begin(115200);
  spiBus.begin(TFT_SCK, -1, TFT_MOSI, -1);
  Wire.begin(0x08,5, 4, 0); 
  Wire.onRequest(onRequest);
  Wire.onReceive(onReceive);
  // put your setup code here, to run once:
  tft1.initR();
  tft2.initR();
  tft3.initR();
  tft4.initR();

  tft1.setSPISpeed(40000000);
  tft2.setSPISpeed(40000000);
  tft3.setSPISpeed(40000000);
  tft4.setSPISpeed(40000000);

  tft1.fillScreen(ST7735_BLACK);
  tft2.fillScreen(ST7735_BLACK);
  tft3.fillScreen(ST7735_BLACK);
  tft4.fillScreen(ST7735_BLACK);

  tft1.setRotation(3);
  tft2.setRotation(3);
  tft3.setRotation(1);
  tft4.setRotation(1);

  pinMode(fibr1, OUTPUT);
  pinMode(fibr2, OUTPUT);
  pinMode(fibr3, OUTPUT);
  pinMode(fibr4, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
}
 
void loop() {
// for(int i = 0; i<=28; i++){
//     Display_Icon icon = (Display_Icon)i;
//     writeDisplay(tft1, icon);
//     writeDisplay(tft2, icon);
//     writeDisplay(tft3, icon);
//     writeDisplay(tft4, icon);
//     delay(500);
// }

if (received){
  received = 0;
  writeDisplays();
}

  if (digitalRead(button1) == LOW) button_state = 1;
  else if (digitalRead(button2) == LOW) button_state = 2;
  else if (digitalRead(button3) == LOW) button_state = 3;
  else if (digitalRead(button4) == LOW) button_state = 4;
  delay(50); // debounce
}

void writeDisplays(){
  writeDisplay(tft1, display1Icon);
  writeDisplay(tft2, display2Icon);
  writeDisplay(tft3, display3Icon);
  writeDisplay(tft4, display4Icon);
}

void writeDisplay(Adafruit_ST7735 display, Display_Icon icon){
switch (icon) {
    case Display_Icon::Blank:
        display.fillScreen(ST7735_WHITE);
        break;
    case Display_Icon::Digit0:
        writeTextToDisplay(display, "0");
        break;
    case Display_Icon::Digit1:
        writeTextToDisplay(display, "1");
        break;
    case Display_Icon::Digit2:
        writeTextToDisplay(display, "2");
        break;
    case Display_Icon::Digit3:
        writeTextToDisplay(display, "3");
        break;
    case Display_Icon::Digit4:
        writeTextToDisplay(display, "4");
        break;
    case Display_Icon::Digit5:
        writeTextToDisplay(display, "5");
        break;
    case Display_Icon::Digit6:
        writeTextToDisplay(display, "6");
        break;
    case Display_Icon::Digit7:
        writeTextToDisplay(display, "7");
        break;
    case Display_Icon::Digit8:
        writeTextToDisplay(display, "8");
        break;
    case Display_Icon::Digit9:
        writeTextToDisplay(display, "9");
        break;
    case Display_Icon::Off:
        writeTextToDisplay(display, "Off");
        break;
    case Display_Icon::On:
        writeTextToDisplay(display, "On");
        break;
    case Display_Icon::Edit:
        writeTextToDisplay(display, "Edit");
        break;
    case Display_Icon::Start:
        writeTextToDisplay(display, "Start");
        break;
    case Display_Icon::Stop:
        writeTextToDisplay(display, "Stop");
        break;
    case Display_Icon::Increase:
        writeTextToDisplay(display, "+");
        break;
    case Display_Icon::Decrease:
        writeTextToDisplay(display, "-");
        break;

    case Display_Icon::Confirm:
        drawIconToDisplay(display, iconConfirm);
        break;
    case Display_Icon::Retry:
        drawIconToDisplay(display, iconRetry);
        break;
    case Display_Icon::Next:
        drawIconToDisplay(display, iconNext);
        break;
    case Display_Icon::Back:
        drawIconToDisplay(display, iconBack);
        break;
    case Display_Icon::Play:
        drawIconToDisplay(display, iconPlay);
        break;
    case Display_Icon::Pause:
        drawIconToDisplay(display, iconPause);
        break;
    case Display_Icon::VolumeUp:
        drawIconToDisplay(display, iconVolumeUp);
        break;
    case Display_Icon::VolumeDown:
        drawIconToDisplay(display, iconVolumeDown);
        break;
    case Display_Icon::PillAlarm:
        drawIconToDisplay(display, iconPillAlarm);
        break;
    case Display_Icon::SleepAlarm:
        drawIconToDisplay(display, iconSleepAlarm);
        break;
    case Display_Icon::SpeechTrainer:
        drawIconToDisplay(display, iconSpeechTrainer);
        break;
      
    default:
        // Optioneel: iets doen als het geen cijfer is
        break;
}
}

void drawIconToDisplay(Adafruit_ST7735& display, const unsigned char* bitMap){
  display.fillScreen(ST7735_BLACK);
  display.drawBitmap(0,0,bitMap,128,128,ST77XX_WHITE);
}

void writeTextToDisplay(Adafruit_ST7735& display, const char* text) {
  display.fillScreen(ST7735_WHITE);
  display.setCursor(8, 48);
  display.setTextColor(ST77XX_BLACK);  
  display.setTextSize(5);
  display.println(text);
}
 
