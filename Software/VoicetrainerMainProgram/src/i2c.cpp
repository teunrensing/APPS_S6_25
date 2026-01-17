#include <i2c.h>
#include <Wire.h>
#include <parameters.h>

TwoWire I2C_Primary = TwoWire(0);   // Hardware bus 0
TwoWire I2C_Secondary = TwoWire(1); // Hardware bus 1

void i2cInit()
{
    I2C_Secondary.begin(SDA0, SCL0, I2C0_FREQ);
    I2C_Primary.begin(SDA1, SCL1, I2C1_FREQ);
}
