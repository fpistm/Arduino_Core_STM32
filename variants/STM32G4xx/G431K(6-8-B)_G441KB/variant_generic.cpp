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
#if defined(ARDUINO_GENERIC_G431K6TX) || defined(ARDUINO_GENERIC_G431K6UX) ||\
    defined(ARDUINO_GENERIC_G431K8TX) || defined(ARDUINO_GENERIC_G431K8UX) ||\
    defined(ARDUINO_GENERIC_G431KBTX) || defined(ARDUINO_GENERIC_G431KBUX) ||\
    defined(ARDUINO_GENERIC_G441KBTX) || defined(ARDUINO_GENERIC_G441KBUX)
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
  PB_3,
  PB_4,
  PB_5,
  PB_6,
  PB_7,
  PB_8,
  PF_0,
  PF_1,
  PG_10
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
  23, // A9,  PF0
  24  // A10, PF1
};

#endif /* ARDUINO_GENERIC_* */