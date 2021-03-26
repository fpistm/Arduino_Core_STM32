/*
 *******************************************************************************
 * Copyright (c) 2011-2021, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#pragma once

//                  | DIGITAL | ANALOG | USART     | TWI      | SPI                    | SPECIAL   |
//                  |---------|--------|-----------|----------|------------------------|-----------|
#define PA0  A0  // | 0       | A0     |           |          |                        |           |
#define PA1  A1  // | 1       | A1     |           |          |                        |           |
#define PA2  A2  // | 2       | A2     | USART2_TX |          |                        |           |
#define PA3  A3  // | 3       | A3     | USART2_RX |          |                        |           |
#define PA4  A4  // | 4       | A4     |           |          | SPI1_SS, (SPI3_SS)     |           |
#define PA5  A5  // | 5       | A5     |           |          | SPI1_SCK               |           |
#define PA6  A6  // | 6       | A6     |           |          | SPI1_MISO              |           |
#define PA7  A7  // | 7       | A7     |           |          | SPI1_MOSI              |           |
#define PA8  8   // | 8       |        |           | TWI3_SCL |                        |           |
#define PA9  9   // | 9       |        | USART1_TX |          |                        |           |
#define PA10 10  // | 10      |        | USART1_RX |          |                        |           |
#define PA11 11  // | 11      |        | USART6_TX |          |                        |           |
#define PA12 12  // | 12      |        | USART6_RX |          |                        |           |
#define PA13 13  // | 13      |        |           |          |                        | SWD_SWDIO |
#define PA14 14  // | 14      |        |           |          |                        | SWD_SWCLK |
#define PA15 15  // | 15      |        |           |          | SPI3_SS, (SPI1_SS)     |           |
//                  |---------|--------|-----------|----------|------------------------|-----------|
#define PB0  A8  // | 16      | A8     |           |          |                        |           |
#define PB1  A9  // | 17      | A9     |           |          |                        |           |
#define PB2  18  // | 18      |        |           |          |                        | BOOT1     |
#define PB3  19  // | 19      |        |           | TWI2_SDA | SPI3_SCK,  (SPI1_SCK)  |           |
#define PB4  20  // | 20      |        |           | TWI3_SDA | SPI3_MISO, (SPI1_MISO) |           |
#define PB5  21  // | 21      |        |           |          | SPI3_MOSI, (SPI1_MOSI) |           |
#define PB6  22  // | 22      |        | USART1_TX | TWI1_SCL |                        |           |
#define PB7  23  // | 23      |        | USART1_RX | TWI1_SDA |                        |           |
#define PB8  24  // | 24      |        |           | TWI1_SCL |                        |           |
#define PB9  25  // | 25      |        |           | TWI1_SDA | SPI2_SS                |           |
#define PB10 26  // | 26      |        |           | TWI2_SCL | SPI2_SCK               |           |
#define PB12 27  // | 27      |        |           |          | SPI2_SS                |           |
#define PB13 28  // | 28      |        |           |          | SPI2_SCK               |           |
#define PB14 29  // | 29      |        |           |          | SPI2_MISO              |           |
#define PB15 30  // | 30      |        |           |          | SPI2_MOSI              |           |
//                  |---------|--------|-----------|----------|------------------------|-----------|
#define PC0  A10 // | 31      | A10    |           |          |                        |           |
#define PC1  A11 // | 32      | A11    |           |          |                        |           |
#define PC2  A12 // | 33      | A12    |           |          | SPI2_MISO              |           |
#define PC3  A13 // | 34      | A13    |           |          | SPI2_MOSI              |           |
#define PC4  A14 // | 35      | A14    |           |          |                        |           |
#define PC5  A15 // | 36      | A15    |           |          |                        |           |
#define PC6  37  // | 37      |        | USART6_TX |          |                        |           |
#define PC7  38  // | 38      |        | USART6_RX |          |                        |           |
#define PC8  39  // | 39      |        |           |          |                        |           |
#define PC9  40  // | 40      |        |           | TWI3_SDA |                        |           |
#define PC10 41  // | 41      |        |           |          | SPI3_SCK               |           |
#define PC11 42  // | 42      |        |           |          | SPI3_MISO              |           |
#define PC12 43  // | 43      |        |           |          | SPI3_MOSI              |           |
#define PC13 44  // | 44      |        |           |          |                        |           |
#define PC14 45  // | 45      |        |           |          |                        | OSC32_IN  |
#define PC15 46  // | 46      |        |           |          |                        | OSC32_OUT |
//                  |---------|--------|-----------|----------|------------------------|-----------|
#define PD2  47  // | 47      |        |           |          |                        |           |
//                  |---------|--------|-----------|----------|------------------------|-----------|
#define PH0  48  // | 48      |        |           |          |                        | OSC_IN    |
#define PH1  49  // | 49      |        |           |          |                        | OSC_OUT   |
//                  |---------|--------|-----------|----------|------------------------|-----------|

// Alternate pins number
#define PA0_ALT1                (PA0  | ALT1)
#define PA1_ALT1                (PA1  | ALT1)
#define PA2_ALT1                (PA2  | ALT1)
#define PA2_ALT2                (PA2  | ALT2)
#define PA3_ALT1                (PA3  | ALT1)
#define PA3_ALT2                (PA3  | ALT2)
#define PA4_ALT1                (PA4  | ALT1)
#define PA7_ALT1                (PA7  | ALT1)
#define PA15_ALT1               (PA15 | ALT1)
#define PB0_ALT1                (PB0  | ALT1)
#define PB1_ALT1                (PB1  | ALT1)
#define PB3_ALT1                (PB3  | ALT1)
#define PB4_ALT1                (PB4  | ALT1)
#define PB5_ALT1                (PB5  | ALT1)
#define PB8_ALT1                (PB8  | ALT1)
#define PB9_ALT1                (PB9  | ALT1)

// This must be a literal
#define NUM_DIGITAL_PINS        50
#define NUM_ANALOG_INPUTS       16

// On-board LED pin number
#define LED_GREEN               PB10
#ifndef LED_BUILTIN
  #define LED_BUILTIN           LED_GREEN
#endif

// On-board user button
#ifndef USER_BTN
  #define USER_BTN              ND
#endif

// SPI definitions
#ifndef PIN_SPI_SS
  #define PIN_SPI_SS            PA4
#endif
#ifndef PIN_SPI_SS1
  #define PIN_SPI_SS1           PA4
#endif
#ifndef PIN_SPI_SS2
  #define PIN_SPI_SS2           PB12
#endif
#ifndef PIN_SPI_SS3
  #define PIN_SPI_SS3           PA15
#endif
#ifndef PIN_SPI_MOSI
  #define PIN_SPI_MOSI          PA7
#endif
#ifndef PIN_SPI_MISO
  #define PIN_SPI_MISO          PA6
#endif
#ifndef PIN_SPI_SCK
  #define PIN_SPI_SCK           PA5
#endif

// I2C definitions
#ifndef PIN_WIRE_SDA
  #define PIN_WIRE_SDA          PB9
#endif
#ifndef PIN_WIRE_SCL
  #define PIN_WIRE_SCL          PB8
#endif

// Timer Definitions
#ifndef TIMER_TONE
  #define TIMER_TONE            TIM10
#endif
#ifndef TIMER_SERVO
  #define TIMER_SERVO           TIM11
#endif

// UART Definitions
#ifndef SERIAL_UART_INSTANCE
  #define SERIAL_UART_INSTANCE  1
#endif

// Default pin used for 'Serial' instance
// Mandatory for Firmata
#ifndef PIN_SERIAL_RX
  #define PIN_SERIAL_RX         PA10
#endif
#ifndef PIN_SERIAL_TX
  #define PIN_SERIAL_TX         PA9
#endif

// USB, pull this pin low to enable the USB attach pullup
// It is documented here, but not actually used, since there are also
// internal pullups which are automatically used and using both would
// violate the USB specification for pullup strength.
//#define USBD_ATTACH_PIN         PD2
//#define USBD_ATTACH_LEVEL       LOW

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
  // These serial port names are intended to allow libraries and architecture-neutral
  // sketches to automatically default to the correct port name for a particular type
  // of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
  // the first hardware serial port whose RX/TX pins are not dedicated to another use.
  //
  // SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
  //
  // SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
  //
  // SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
  //
  // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
  //
  // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
  //                            pins are NOT connected to anything by default.
  #ifndef SERIAL_PORT_MONITOR
    #define SERIAL_PORT_MONITOR   Serial
  #endif
  #ifndef SERIAL_PORT_HARDWARE
    #define SERIAL_PORT_HARDWARE  Serial
  #endif
#endif
