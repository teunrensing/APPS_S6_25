#include <Arduino.h>
#include <Wire.h>

volatile uint8_t button_state = 0;
volatile bool data_requested = false;

void onRequest() {
  Wire.write(button_state);
  button_state = 0; // Reset after sending
}

void onReceive(int len) {
  if (len >= 4) {
    int value1 = Wire.read() | (Wire.read() << 8);
    int value2 = Wire.read() | (Wire.read() << 8);
    Serial.printf("Received: %d, %d\n", value1, value2);
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin(5, 4, 0x08); 
  Wire.onRequest(onRequest);
  Wire.onReceive(onReceive);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(42, INPUT_PULLUP);
  pinMode(41, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(1) == LOW) button_state = 1;
  else if (digitalRead(2) == LOW) button_state = 2;
  else if (digitalRead(42) == LOW) button_state = 3;
  else if (digitalRead(41) == LOW) button_state = 4;
  delay(50); // debounce
}
