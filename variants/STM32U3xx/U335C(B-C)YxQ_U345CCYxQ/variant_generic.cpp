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
#if defined(ARDUINO_GENERIC_U335CBYXQ) || defined(ARDUINO_GENERIC_U335CCYXQ) ||\
    defined(ARDUINO_GENERIC_U345CCYXQ)
#include "pins_arduino.h"

// Digital PinName array
const PinName digitalPin[] = {
  PA_0,   // D0/A0
  PA_1,   // D1/A1
  PA_2,   // D2/A2
  PA_3,   // D3/A3
  PA_4,   // D4/A4
  PA_5,   // D5/A5
  PA_6,   // D6/A6
  PA_7,   // D7/A7
  PA_8,   // D8
  PA_11,  // D9
  PA_12,  // D10
  PA_13,  // D11
  PA_14,  // D12
  PA_15,  // D13
  PB_0,   // D14/A8
  PB_1,   // D15/A9
  PB_3,   // D16
  PB_4,   // D17
  PB_7,   // D18
  PB_12,  // D19
  PB_13,  // D20
  PB_14,  // D21
  PB_15,  // D22
  PC_6,   // D23
  PC_7,   // D24
  PC_8,   // D25
  PC_9,   // D26
  PC_14,  // D27
  PC_15,  // D28
  PH_3    // D29
};

// Analog (Ax) pin number array
const pin_size_t analogInputPin[] = {
  0,  // A0,  PA0
  1,  // A1,  PA1
  2,  // A2,  PA2
  3,  // A3,  PA3
  4,  // A4,  PA4
  5,  // A5,  PA5
  6,  // A6,  PA6
  7,  // A7,  PA7
  14, // A8,  PB0
  15  // A9,  PB1
};

#endif /* ARDUINO_GENERIC_* */
