/*
 *******************************************************************************
 * Copyright (c) 2020-2021, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#if defined(ARDUINO_GENERIC_L151R6HX) || defined(ARDUINO_GENERIC_L151R6HXA) ||\
    defined(ARDUINO_GENERIC_L151R8HX) || defined(ARDUINO_GENERIC_L151R8HXA) ||\
    defined(ARDUINO_GENERIC_L151RBHX) || defined(ARDUINO_GENERIC_L151RBHXA) ||\
    defined(ARDUINO_GENERIC_L152R6HX) || defined(ARDUINO_GENERIC_L152R6HXA) ||\
    defined(ARDUINO_GENERIC_L152R8HX) || defined(ARDUINO_GENERIC_L152R8HXA) ||\
    defined(ARDUINO_GENERIC_L152RBHX) || defined(ARDUINO_GENERIC_L152RBHXA)
#include "pins_arduino.h"

// Digital PinName array
const PinName digitalPin[] = {
  PA_0,
  PA_1,
  PA_2,
  PA_3,
  PA_4,
  PA_5,
  PA_6,
  PA_7,
  PA_8,
  PA_9,
  PA_10,
  PA_11,
  PA_12,
  PA_13,
  PA_14,
  PA_15,
  PB_0,
  PB_1,
  PB_2,
  PB_3,
  PB_4,
  PB_5,
  PB_6,
  PB_7,
  PB_8,
  PB_9,
  PB_10,
  PB_11,
  PB_12,
  PB_13,
  PB_14,
  PB_15,
  PC_0,
  PC_1,
  PC_2,
  PC_4,
  PC_5,
  PC_6,
  PC_7,
  PC_8,
  PC_9,
  PC_10,
  PC_11,
  PC_12,
  PC_13,
  PC_14,
  PC_15,
  PD_2,
  PH_0,
  PH_1
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
  0,  // A0,  PA0
  1,  // A1,  PA1
  2,  // A2,  PA2
  3,  // A3,  PA3
  4,  // A4,  PA4
  5,  // A5,  PA5
  6,  // A6,  PA6
  7,  // A7,  PA7
  16, // A8,  PB0
  17, // A9,  PB1
  28, // A10, PB12
  29, // A11, PB13
  30, // A12, PB14
  31, // A13, PB15
  32, // A14, PC0
  33, // A15, PC1
  34, // A16, PC2
  35, // A17, PC4
  36  // A18, PC5
};

#endif /* ARDUINO_GENERIC_* */
