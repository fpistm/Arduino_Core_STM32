/*
   Touch example for STM32F476 Discvery

   using Adafruit compatible API

   June 2017, ChrisMicro
*/

#include "LTDC_F746_Discovery.h" // TFT
#include "TouchScreen_F7_Discovery.h" // TOUCH

LTDC_F746_Discovery tft;
TouchScreen         ts;

void setup()
{
  // The buffer is memory mapped
  // You can directly draw on the display by writing to the buffer
  uint16_t *buffer = (uint16_t *)malloc(LTDC_F746_ROKOTECH.width * LTDC_F746_ROKOTECH.height);

  tft.begin((uint16_t *)buffer);
  
  tft.fillScreen(LTDC_BLACK);
  //tft.setRotation(0);
  tft.setCursor(0, 0);
  tft.setTextColor(LTDC_BLUE);  tft.setTextSize(3);
  tft.println("STM32F746 Discovery Touch");
}

#define CURSOR_SIZE 100

TSPoint OldPoint;

void loop()
{
    TSPoint p = ts.getPoint();
    
    if( OldPoint != p )
    {
      OldPoint=p;
      
      tft.fillScreen( LTDC_BLACK );

      tft.setCursor(0, 0);

      tft.print(p.x); tft.print(" , "); tft.print(p.y);
      tft.print(" pressure: "); tft.println( p.z );

      if ( p.z )
      {
        tft.fillRect(p.x - CURSOR_SIZE/2, p.y - CURSOR_SIZE/2, CURSOR_SIZE, CURSOR_SIZE, LTDC_GREEN);
      }

      delay(10);
    }
}

