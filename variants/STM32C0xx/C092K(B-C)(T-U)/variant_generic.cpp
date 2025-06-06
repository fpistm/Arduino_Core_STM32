/*
 *******************************************************************************
 * Copyright (c) 2020, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#if defined(ARDUINO_GENERIC_C092KBTX) || defined(ARDUINO_GENERIC_C092KBUX) ||\
    defined(ARDUINO_GENERIC_C092KCTX) || defined(ARDUINO_GENERIC_C092KCUX)
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
  PA_8,   // D8/A8
  PA_9,   // D9
  PA_10,  // D10
  PA_11,  // D11
  PA_12,  // D12
  PA_13,  // D13/A9
  PA_14,  // D14/A10
  PA_15,  // D15
  PB_0,   // D16/A11
  PB_1,   // D17/A12
  PB_2,   // D18/A13
  PB_3,   // D19
  PB_4,   // D20
  PB_5,   // D21
  PB_6,   // D22
  PB_7,   // D23
  PB_8,   // D24
  PB_9,   // D25
  PC_6,   // D26
  PC_14,  // D27
  PC_15,  // D28
  PF_2,   // D29
  PA_9_R, // D30
  PA_10_R // D31
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
  8,  // A8,  PA8
  13, // A9,  PA13
  14, // A10, PA14
  16, // A11, PB0
  17, // A12, PB1
  18  // A13, PB2
};

#endif /* ARDUINO_GENERIC_* */
