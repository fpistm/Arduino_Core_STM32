// Adafruit compatible touchscreen wrapper
// June 2017 by ChrisMicro

#include "TouchScreen_F7_Discovery.h"
#include <Wire.h>
#include "stm32_ub_touch_480x272.h"

uint8_t UB_I2C3_ReadByte(uint8_t addressI2cDevice, uint8_t registerId)
{
  uint8_t result;
  addressI2cDevice = addressI2cDevice >> 1;

  Wire.beginTransmission( addressI2cDevice  );
  Wire.write( registerId );
  uint8_t error;
  error = Wire.endTransmission();

  Wire.requestFrom( addressI2cDevice, (uint8_t) 1 , (uint8_t) true );

  while ( Wire.available() < 1 );

  result = Wire.read() ;

  return result;
}

void TouchScreen::Touch_Read()
{
  if (!isInitialized)
  {
    Wire.stm32SetInstance(I2C3);
    Wire.stm32SetSDA(PH8);
    Wire.stm32SetSCL(PH7);
    Wire.begin();

    UB_Touch_Init();
    isInitialized=true;
  }
  UB_Touch_Read();
}

TSPoint::TSPoint(void) {
  x = y = z = 0;
}

TSPoint::TSPoint(int16_t x0, int16_t y0, int16_t z0)
{
  x = x0;
  y = y0;
  z = z0;
}

bool TSPoint::operator==(TSPoint p1)
{
  return  ((p1.x == x) && (p1.y == y) && (p1.z == z));
}

bool TSPoint::operator!=(TSPoint p1)
{
  return  ((p1.x != x) || (p1.y != y) || (p1.z != z));
}

TSPoint TouchScreen::getPoint(void)
{
  TSPoint p;

  Touch_Read();

  p.x = Touch_Data.xp;
  p.y = Touch_Data.yp;
  p.z = P_Touch_GetContacts() * 500;

  return p;

}

TouchScreen::TouchScreen(uint8_t xp, uint8_t yp, uint8_t xm, uint8_t ym, uint16_t rxplate = 0)
{
  isInitialized = false;
}
TouchScreen::TouchScreen()
{
  isInitialized = false;
}

int TouchScreen::readTouchX(void)
{
  Touch_Read();
  return Touch_Data.xp;
}


int TouchScreen::readTouchY(void)
{
  Touch_Read();
  return Touch_Data.yp;
}


uint16_t TouchScreen::pressure(void)
{
  Touch_Read();

  return P_Touch_GetContacts() * 500;
}

