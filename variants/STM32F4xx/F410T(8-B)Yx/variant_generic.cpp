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
#if defined(ARDUINO_GENERIC_F410T8YX) || defined(ARDUINO_GENERIC_F410TBYX)
#include "pins_arduino.h"

// Digital PinName array
const PinName digitalPin[] = {
  PA_0,
  PA_2,
  PA_3,
  PA_5,
  PA_8,
  PA_12,
  PA_13,
  PA_14,
  PA_15,
  PB_2,
  PB_3,
  PB_4,
  PB_5,
  PB_6,
  PB_7,
  PB_8,
  PB_10,
  PB_12,
  PC_13,
  PC_14,
  PC_15,
  PH_0,
  PH_1
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
  0,  // A0,  PA0
  1,  // A1,  PA2
  2,  // A2,  PA3
  3   // A3,  PA5
};

#endif /* ARDUINO_GENERIC_* */
