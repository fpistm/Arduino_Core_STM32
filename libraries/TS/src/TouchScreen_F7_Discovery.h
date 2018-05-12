// Touch screen library with X Y and Z (pressure) readings as well
// as oversampling to avoid 'bouncing'
// (c) ladyada / adafruit
// Code under MIT License
// adapted for STM32F746 Discovery 
// by ChrisMicro

#ifndef _ADAFRUIT_TOUCHSCREEN_H_
#define _ADAFRUIT_TOUCHSCREEN_H_
#include <stdint.h>

class TSPoint {
  public:
    TSPoint(void);
    TSPoint(int16_t x, int16_t y, int16_t z);

    bool operator==(TSPoint);
    bool operator!=(TSPoint);

    int16_t x, y, z;
};

class TouchScreen {
  public:
    TouchScreen(uint8_t xp, uint8_t yp, uint8_t xm, uint8_t ym, uint16_t rx);
    TouchScreen(void);
    bool isTouching(void);
    uint16_t pressure(void);
    int readTouchY();
    int readTouchX();
    TSPoint getPoint();
    int16_t pressureThreshhold;

  private:
    void Touch_Read(void);
    uint8_t isInitialized;
};

#endif

