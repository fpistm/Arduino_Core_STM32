/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ARDUINO_STM32_
#define _VARIANT_ARDUINO_STM32_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/


#define PC0			0			// I_mirr_1mA

#define PC8			1			// Temp_AN_1
#define PC9			2			// Temp_AN_2
#define PA8			3			// Temp_AN_3
#define PA11		4			// Temp_AN_4
#define PA12		5			// Temp_intern_AN
#define PF7			6			// Temp_kal_3k_AN
#define PF6			7			// Temp_kal_30k_AN

#define PC4			8			// AI24_AN_2
#define PC5			9			// AI24_AN_1
#define PC6			10			// AI24_AN_4
#define PC7			11			// AI24_AN_3
#define PA7			12			// 0_20mA_1
#define PC1			13			// 0_20mA_2

#define PC2			14			// EN_DA_PWM_1
#define PC3			15			// EN_DA_PWM_2

#define PB1			16			// AI_1
#define PB2			17			// AI_2
#define PE8			18			// AI_3
#define PE9			19			// AI_4					20
#define PD8			20			// AI_temperatur
#define PB14		21			// AI_kal_3k
#define PB15		22			// AI_kal_30k
#define PB0			23			// AI_curr

#define PA15		24			// DI_1
#define PD2			25			// DI_2
#define PC12		26			// DI_3
#define PC11		27			// DI_4, USART3_RX
#define PB9			28			// DI_5, USART3_RX

#define PC10		29			// USART3_TX
#define PA4			30			// DA_PWM_1
#define PA5			31			// DA_PWM_2

#define PA2			32			// pSwitch_7
#define PA1			33			// nSwitch_7
#define PA3			34			// pSwitch_8
#define PA6			35			// nSwitch_8
#define PB4			36			// pSwitch_9
#define PB6			37			// nSwitch_9
#define PB5			38			// pSwitch_10
#define PB7			39			// nSwitch_10			40

#define PA9			40			// USART1_TX = A13_SOM_RX
#define PA10		41			// USART1_RX = A13_SOM_TX

#define PA13		42			// SWDIO
#define PA14		43			// SWCLK
#define PB3			44			// SWO

#define PC13		45
#define PA0			46
#define PB8			47


// This must be a literal
#define NUM_DIGITAL_PINS        60
// This must be a literal with a value less than or equal to to MAX_ANALOG_INPUTS
#define NUM_ANALOG_INPUTS       1
#define NUM_ANALOG_FIRST        46

// On-board LED pin number
#define LED_BUILTIN             45	//13??
#define LED_GREEN               LED_BUILTIN

// On-board user button
#define USER_BTN                PC13

// Timer Definitions
// Do not use timer used by PWM pins when possible. See PinMap_PWM.
#define TIMER_TONE              TIM6

//Do not use basic timer: OC is required
#define TIMER_SERVO             TIM2  //TODO: advanced-control timers don't work

// UART Definitions
#define SERIAL_UART_INSTANCE    1 //Connected to ST-Link

// Default pin used for 'Serial' instance (ex: ST-Link)
// Mandatory for Firmata
#define PIN_SERIAL_RX           41
#define PIN_SERIAL_TX           40



/* Extra HAL modules */
//#define HAL_DAC_MODULE_ENABLED
//#define HAL_SDADC_MODULE_ENABLED

#ifdef __cplusplus
} // extern "C"
#endif
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
#define SERIAL_PORT_MONITOR     Serial
#define SERIAL_PORT_HARDWARE    Serial
#endif

#endif /* _VARIANT_ARDUINO_STM32_ */
