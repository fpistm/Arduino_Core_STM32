/*
 *******************************************************************************
 * Copyright (c) 2020-2026, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#if defined(ARDUINO_GENERIC_C531FBPX) || defined(ARDUINO_GENERIC_C531FBUX) ||\
    defined(ARDUINO_GENERIC_C531FCPX) || defined(ARDUINO_GENERIC_C531FCUX)
#include "pins_arduino.h"

// Digital PinName array
const PinName digitalPin[] = {
  PA_1,   // D0/A0
  PA_2,   // D1/A1
  PA_3,   // D2/A2
  PA_4,   // D3/A3
  PA_5,   // D4/A4
  PA_6,   // D5/A5
  PA_7,   // D6/A6
  PA_11,  // D7
  PA_12,  // D8
  PA_13,  // D9
  PA_14,  // D10
  PA_15,  // D11
  PB_0,   // D12/A7
  PB_1,   // D13/A8
  PB_2,   // D14
  PB_3,   // D15
  PB_4,   // D16
  PB_8,   // D17
  PB_15,  // D18
  PC_4,   // D19/A9
  PH_0,   // D20
  PH_1    // D21
};

// Analog (Ax) pin number array
const pin_size_t analogInputPin[] = {
  0,  // A0,  PA1
  1,  // A1,  PA2
  2,  // A2,  PA3
  3,  // A3,  PA4
  4,  // A4,  PA5
  5,  // A5,  PA6
  6,  // A6,  PA7
  12, // A7,  PB0
  13, // A8,  PB1
  19  // A9,  PC4
};

#endif /* ARDUINO_GENERIC_* */
