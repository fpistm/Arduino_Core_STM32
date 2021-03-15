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
#if defined(ARDUINO_GENERIC_G0B1KBTXN) || defined(ARDUINO_GENERIC_G0B1KBUXN) ||\
    defined(ARDUINO_GENERIC_G0B1KCTXN) || defined(ARDUINO_GENERIC_G0B1KCUXN) ||\
    defined(ARDUINO_GENERIC_G0B1KETXN) || defined(ARDUINO_GENERIC_G0B1KEUXN) ||\
    defined(ARDUINO_GENERIC_G0C1KCTXN) || defined(ARDUINO_GENERIC_G0C1KCUXN) ||\
    defined(ARDUINO_GENERIC_G0C1KETXN) || defined(ARDUINO_GENERIC_G0C1KEUXN)
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
  PB_0,
  PB_1,
  PB_6,
  PB_7,
  PB_8,
  PB_9,
  PB_15,
  PC_14,
  PC_15,
  PD_0,
  PD_1,
  PD_2,
  PD_3,
  PF_2,
  PA_9_R,
  PA_10_R
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
  15, // A8,  PB0
  16  // A9,  PB1
};

#endif /* ARDUINO_GENERIC_* */
