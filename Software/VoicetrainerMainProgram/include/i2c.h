#ifndef I2C_H
#define I2C_H

#include <Wire.h>

extern TwoWire I2C_Primary;
extern TwoWire I2C_Secondary;

void i2cInit();

#endif
