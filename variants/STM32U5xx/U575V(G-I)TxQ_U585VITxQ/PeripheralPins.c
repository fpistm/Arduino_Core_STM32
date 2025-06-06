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
/*
 * Automatically generated from STM32U575VGTxQ.xml, STM32U575VITxQ.xml
 * STM32U585VITxQ.xml
 * CubeMX DB release 6.0.140
 */
#if !defined(CUSTOM_PERIPHERAL_PINS)
#include "Arduino.h"
#include "PeripheralPins.h"

/* =====
 * Notes:
 * - The pins mentioned Px_y_ALTz are alternative possibilities which use other
 *   HW peripheral instances. You can use them the same way as any other "normal"
 *   pin (i.e. analogWrite(PA7_ALT1, 128);).
 *
 * - Commented lines are alternative possibilities which are not used per default.
 *   If you change them, you will have to know what you do
 * =====
 */

//*** ADC ***

#ifdef HAL_ADC_MODULE_ENABLED
WEAK const PinMap PinMap_ADC[] = {
  {PA_0,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 5, 0)}, // ADC1_IN5
  {PA_1,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 6, 0)}, // ADC1_IN6
  {PA_2,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 7, 0)}, // ADC1_IN7
  {PA_3,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 8, 0)}, // ADC1_IN8
  {PA_4,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 9, 0)}, // ADC1_IN9
  {PA_4_ALT1, ADC4, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 9, 0)}, // ADC4_IN9
  {PA_5,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 10, 0)}, // ADC1_IN10
  {PA_5_ALT1, ADC4, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 10, 0)}, // ADC4_IN10
  {PA_6,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 11, 0)}, // ADC1_IN11
  {PA_6_ALT1, ADC4, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 11, 0)}, // ADC4_IN11
  {PA_7,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 12, 0)}, // ADC1_IN12
  {PA_7_ALT1, ADC4, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 20, 0)}, // ADC4_IN20
  {PB_0,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 15, 0)}, // ADC1_IN15
  {PB_0_ALT1, ADC4, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 18, 0)}, // ADC4_IN18
  {PB_1,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 16, 0)}, // ADC1_IN16
  {PB_1_ALT1, ADC4, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 19, 0)}, // ADC4_IN19
  {PB_2,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 17, 0)}, // ADC1_IN17
  {PC_0,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 1, 0)}, // ADC1_IN1
  {PC_0_ALT1, ADC4, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 1, 0)}, // ADC4_IN1
  {PC_1,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 2, 0)}, // ADC1_IN2
  {PC_1_ALT1, ADC4, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 2, 0)}, // ADC4_IN2
  {PC_2,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 3, 0)}, // ADC1_IN3
  {PC_2_ALT1, ADC4, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 3, 0)}, // ADC4_IN3
  {PC_3,      ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 4, 0)}, // ADC1_IN4
  {PC_3_ALT1, ADC4, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 4, 0)}, // ADC4_IN4
  {PD_11,     ADC4, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 15, 0)}, // ADC4_IN15
  {PD_12,     ADC4, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 16, 0)}, // ADC4_IN16
  {PD_13,     ADC4, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 17, 0)}, // ADC4_IN17
  {NC,        NP,   0}
};
#endif

//*** DAC ***

#ifdef HAL_DAC_MODULE_ENABLED
WEAK const PinMap PinMap_DAC[] = {
  {PA_4, DAC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 1, 0)}, // DAC1_OUT1
  {PA_5, DAC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 2, 0)}, // DAC1_OUT2
  {NC,   NP,   0}
};
#endif

//*** I2C ***

#ifdef HAL_I2C_MODULE_ENABLED
WEAK const PinMap PinMap_I2C_SDA[] = {
  {PB_3,       I2C1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C1)},
  {PB_4,       I2C3, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C3)},
  {PB_7,       I2C1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C1)},
  {PB_7_ALT1,  I2C4, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF5_I2C4)},
  {PB_9,       I2C1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C1)},
  {PB_11,      I2C2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C2)},
  {PB_11_ALT1, I2C4, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF3_I2C4)},
  {PB_14,      I2C2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C2)},
  {PC_1,       I2C3, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C3)},
  {PD_13,      I2C4, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C4)},
  {NC,         NP,   0}
};
#endif

#ifdef HAL_I2C_MODULE_ENABLED
WEAK const PinMap PinMap_I2C_SCL[] = {
  {PA_7,       I2C3, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C3)},
  {PB_6,       I2C1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C1)},
  {PB_6_ALT1,  I2C4, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF5_I2C4)},
  {PB_8,       I2C1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C1)},
  {PB_10,      I2C2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C2)},
  {PB_10_ALT1, I2C4, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF3_I2C4)},
  {PB_13,      I2C2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C2)},
  {PC_0,       I2C3, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C3)},
  {PD_12,      I2C4, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF4_I2C4)},
  {NC,         NP,   0}
};
#endif

//*** No I3C ***

//*** TIM ***

#ifdef HAL_TIM_MODULE_ENABLED
WEAK const PinMap PinMap_TIM[] = {
  {PA_0,       TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 1, 0)}, // TIM2_CH1
  {PA_0_ALT1,  TIM5,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM5, 1, 0)}, // TIM5_CH1
  {PA_1,       TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 2, 0)}, // TIM2_CH2
  {PA_1_ALT1,  TIM5,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM5, 2, 0)}, // TIM5_CH2
  {PA_1_ALT2,  TIM15, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF14_TIM15, 1, 1)}, // TIM15_CH1N
  {PA_2,       TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 3, 0)}, // TIM2_CH3
  {PA_2_ALT1,  TIM5,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM5, 3, 0)}, // TIM5_CH3
  {PA_2_ALT2,  TIM15, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF14_TIM15, 1, 0)}, // TIM15_CH1
  {PA_3,       TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 4, 0)}, // TIM2_CH4
  {PA_3_ALT1,  TIM5,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM5, 4, 0)}, // TIM5_CH4
  {PA_3_ALT2,  TIM15, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF14_TIM15, 2, 0)}, // TIM15_CH2
  {PA_5,       TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 1, 0)}, // TIM2_CH1
  {PA_5_ALT1,  TIM8,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM8, 1, 1)}, // TIM8_CH1N
  {PA_6,       TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 1, 0)}, // TIM3_CH1
  {PA_6_ALT1,  TIM16, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF14_TIM16, 1, 0)}, // TIM16_CH1
  {PA_7,       TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 1, 1)}, // TIM1_CH1N
  {PA_7_ALT1,  TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 2, 0)}, // TIM3_CH2
  {PA_7_ALT2,  TIM8,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM8, 1, 1)}, // TIM8_CH1N
  {PA_7_ALT3,  TIM17, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF14_TIM17, 1, 0)}, // TIM17_CH1
  {PA_8,       TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 1, 0)}, // TIM1_CH1
  {PA_9,       TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 2, 0)}, // TIM1_CH2
  {PA_10,      TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 3, 0)}, // TIM1_CH3
  {PA_11,      TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 4, 0)}, // TIM1_CH4
  {PA_15,      TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 1, 0)}, // TIM2_CH1
  {PB_0,       TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 2, 1)}, // TIM1_CH2N
  {PB_0_ALT1,  TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 3, 0)}, // TIM3_CH3
  {PB_0_ALT2,  TIM8,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM8, 2, 1)}, // TIM8_CH2N
  {PB_1,       TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 3, 1)}, // TIM1_CH3N
  {PB_1_ALT1,  TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 4, 0)}, // TIM3_CH4
  {PB_1_ALT2,  TIM8,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM8, 3, 1)}, // TIM8_CH3N
  {PB_2,       TIM8,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM8, 4, 1)}, // TIM8_CH4N
  {PB_3,       TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 2, 0)}, // TIM2_CH2
  {PB_4,       TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 1, 0)}, // TIM3_CH1
  {PB_5,       TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 2, 0)}, // TIM3_CH2
  {PB_6,       TIM4,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM4, 1, 0)}, // TIM4_CH1
  {PB_6_ALT1,  TIM16, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF14_TIM16, 1, 1)}, // TIM16_CH1N
  {PB_7,       TIM4,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM4, 2, 0)}, // TIM4_CH2
  {PB_7_ALT1,  TIM17, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF14_TIM17, 1, 1)}, // TIM17_CH1N
  {PB_8,       TIM4,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM4, 3, 0)}, // TIM4_CH3
  {PB_8_ALT1,  TIM16, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF14_TIM16, 1, 0)}, // TIM16_CH1
  {PB_9,       TIM4,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM4, 4, 0)}, // TIM4_CH4
  {PB_9_ALT1,  TIM17, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF14_TIM17, 1, 0)}, // TIM17_CH1
  {PB_10,      TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 3, 0)}, // TIM2_CH3
  {PB_11,      TIM2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM2, 4, 0)}, // TIM2_CH4
  {PB_13,      TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 1, 1)}, // TIM1_CH1N
  {PB_13_ALT1, TIM15, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF14_TIM15, 1, 1)}, // TIM15_CH1N
  {PB_14,      TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 2, 1)}, // TIM1_CH2N
  {PB_14_ALT1, TIM8,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM8, 2, 1)}, // TIM8_CH2N
  {PB_14_ALT2, TIM15, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF14_TIM15, 1, 0)}, // TIM15_CH1
  {PB_15,      TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 3, 1)}, // TIM1_CH3N
  {PB_15_ALT1, TIM8,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM8, 3, 1)}, // TIM8_CH3N
  {PB_15_ALT2, TIM15, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF14_TIM15, 2, 0)}, // TIM15_CH2
  {PC_6,       TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 1, 0)}, // TIM3_CH1
  {PC_6_ALT1,  TIM8,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM8, 1, 0)}, // TIM8_CH1
  {PC_7,       TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 2, 0)}, // TIM3_CH2
  {PC_7_ALT1,  TIM8,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM8, 2, 0)}, // TIM8_CH2
  {PC_8,       TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 3, 0)}, // TIM3_CH3
  {PC_8_ALT1,  TIM8,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM8, 3, 0)}, // TIM8_CH3
  {PC_9,       TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 4, 0)}, // TIM3_CH4
  {PC_9_ALT1,  TIM8,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM8, 4, 0)}, // TIM8_CH4
  {PD_0,       TIM8,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM8, 4, 1)}, // TIM8_CH4N
  {PD_12,      TIM4,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM4, 1, 0)}, // TIM4_CH1
  {PD_13,      TIM4,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM4, 2, 0)}, // TIM4_CH2
  {PD_14,      TIM4,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM4, 3, 0)}, // TIM4_CH3
  {PD_15,      TIM4,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM4, 4, 0)}, // TIM4_CH4
  {PE_0,       TIM16, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF14_TIM16, 1, 0)}, // TIM16_CH1
  {PE_3,       TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 1, 0)}, // TIM3_CH1
  {PE_4,       TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 2, 0)}, // TIM3_CH2
  {PE_5,       TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 3, 0)}, // TIM3_CH3
  {PE_6,       TIM3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM3, 4, 0)}, // TIM3_CH4
  {PE_8,       TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 1, 1)}, // TIM1_CH1N
  {PE_9,       TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 1, 0)}, // TIM1_CH1
  {PE_10,      TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 2, 1)}, // TIM1_CH2N
  {PE_11,      TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 2, 0)}, // TIM1_CH2
  {PE_12,      TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 3, 1)}, // TIM1_CH3N
  {PE_13,      TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 3, 0)}, // TIM1_CH3
  {PE_14,      TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_TIM1, 4, 0)}, // TIM1_CH4
  {PE_15,      TIM1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_TIM1, 4, 1)}, // TIM1_CH4N
  {NC,         NP,    0}
};
#endif

//*** UART ***

#ifdef HAL_UART_MODULE_ENABLED
WEAK const PinMap PinMap_UART_TX[] = {
  {PA_0,       UART4,   STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_UART4)},
  {PA_2,       LPUART1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_LPUART1)},
  {PA_2_ALT1,  USART2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART2)},
  {PA_7,       USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {PA_9,       USART1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART1)},
  {PB_6,       USART1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART1)},
  {PB_10,      USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {PB_11,      LPUART1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_LPUART1)},
  {PC_1,       LPUART1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_LPUART1)},
  {PC_10,      UART4,   STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_UART4)},
  {PC_10_ALT1, USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {PC_12,      UART5,   STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_UART5)},
  {PD_5,       USART2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART2)},
  {PD_8,       USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {NC,         NP,      0}
};
#endif

#ifdef HAL_UART_MODULE_ENABLED
WEAK const PinMap PinMap_UART_RX[] = {
  {PA_1,       UART4,   STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_UART4)},
  {PA_3,       LPUART1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_LPUART1)},
  {PA_3_ALT1,  USART2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART2)},
  {PA_5,       USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {PA_10,      USART1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART1)},
  {PA_15,      USART2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_USART2)},
  {PB_7,       USART1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART1)},
  {PB_10,      LPUART1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_LPUART1)},
  {PB_11,      USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {PC_0,       LPUART1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_LPUART1)},
  {PC_11,      UART4,   STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_UART4)},
  {PC_11_ALT1, USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {PD_2,       UART5,   STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_UART5)},
  {PD_6,       USART2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART2)},
  {PD_9,       USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {NC,         NP,      0}
};
#endif

#ifdef HAL_UART_MODULE_ENABLED
WEAK const PinMap PinMap_UART_RTS[] = {
  {PA_1,       USART2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART2)},
  {PA_12,      USART1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART1)},
  {PA_15,      UART4,   STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_UART4)},
  {PA_15_ALT1, USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {PB_1,       LPUART1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_LPUART1)},
  {PB_1_ALT1,  USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {PB_3,       USART1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART1)},
  {PB_4,       UART5,   STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_UART5)},
  {PB_14,      USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {PD_2,       USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {PD_4,       USART2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART2)},
  {PD_12,      USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {NC,         NP,      0}
};
#endif

#ifdef HAL_UART_MODULE_ENABLED
WEAK const PinMap PinMap_UART_CTS[] = {
  {PA_0,       USART2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART2)},
  {PA_6,       LPUART1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_LPUART1)},
  {PA_6_ALT1,  USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {PA_11,      USART1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART1)},
  {PB_4,       USART1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART1)},
  {PB_5,       UART5,   STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_UART5)},
  {PB_7,       UART4,   STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_UART4)},
  {PB_13,      LPUART1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF8_LPUART1)},
  {PB_13_ALT1, USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {PD_3,       USART2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART2)},
  {PD_11,      USART3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF7_USART3)},
  {NC,         NP,      0}
};
#endif

//*** SPI ***

#ifdef HAL_SPI_MODULE_ENABLED
WEAK const PinMap PinMap_SPI_MOSI[] = {
  {PA_7,      SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {PA_12,     SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {PB_5,      SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {PB_5_ALT1, SPI3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF6_SPI3)},
  {PB_15,     SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI2)},
  {PC_1,      SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_SPI2)},
  {PC_3,      SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI2)},
  {PC_12,     SPI3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF6_SPI3)},
  {PD_4,      SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI2)},
  {PD_6,      SPI3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI3)},
  {PE_15,     SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {NC,        NP,   0}
};
#endif

#ifdef HAL_SPI_MODULE_ENABLED
WEAK const PinMap PinMap_SPI_MISO[] = {
  {PA_6,      SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {PA_11,     SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {PB_4,      SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {PB_4_ALT1, SPI3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF6_SPI3)},
  {PB_14,     SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI2)},
  {PC_2,      SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI2)},
  {PC_11,     SPI3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF6_SPI3)},
  {PD_3,      SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI2)},
  {PE_14,     SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {NC,        NP,   0}
};
#endif

#ifdef HAL_SPI_MODULE_ENABLED
WEAK const PinMap PinMap_SPI_SCLK[] = {
  {PA_1,      SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {PA_5,      SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {PA_9,      SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_SPI2)},
  {PB_3,      SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {PB_3_ALT1, SPI3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF6_SPI3)},
  {PB_10,     SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI2)},
  {PB_13,     SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI2)},
  {PC_10,     SPI3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF6_SPI3)},
  {PD_1,      SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI2)},
  {PD_3,      SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_SPI2)},
  {PE_13,     SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {NC,        NP,   0}
};
#endif

#ifdef HAL_SPI_MODULE_ENABLED
WEAK const PinMap PinMap_SPI_SSEL[] = {
  {PA_4,       SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {PA_4_ALT1,  SPI3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF6_SPI3)},
  {PA_15,      SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {PA_15_ALT1, SPI3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF6_SPI3)},
  {PB_0,       SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {PB_9,       SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI2)},
  {PD_0,       SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI2)},
  {PE_12,      SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_SPI1)},
  {NC,         NP,   0}
};
#endif

//*** FDCAN ***

#ifdef HAL_FDCAN_MODULE_ENABLED
WEAK const PinMap PinMap_CAN_RD[] = {
  {PA_11, FDCAN1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF9_FDCAN1)},
  {PB_8,  FDCAN1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF9_FDCAN1)},
  {PD_0,  FDCAN1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF9_FDCAN1)},
  {NC,    NP,     0}
};
#endif

#ifdef HAL_FDCAN_MODULE_ENABLED
WEAK const PinMap PinMap_CAN_TD[] = {
  {PA_12, FDCAN1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF9_FDCAN1)},
  {PB_9,  FDCAN1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF9_FDCAN1)},
  {PD_1,  FDCAN1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF9_FDCAN1)},
  {NC,    NP,     0}
};
#endif

//*** No ETHERNET ***

//*** OCTOSPI ***

#ifdef HAL_OSPI_MODULE_ENABLED
WEAK const PinMap PinMap_OCTOSPI_DATA0[] = {
  {PB_1,  OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO0
  {PE_12, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO0
  {NC,    NP,       0}
};
#endif

#ifdef HAL_OSPI_MODULE_ENABLED
WEAK const PinMap PinMap_OCTOSPI_DATA1[] = {
  {PB_0,  OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO1
  {PE_13, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO1
  {NC,    NP,       0}
};
#endif

#ifdef HAL_OSPI_MODULE_ENABLED
WEAK const PinMap PinMap_OCTOSPI_DATA2[] = {
  {PA_7,  OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO2
  {PE_14, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO2
  {NC,    NP,       0}
};
#endif

#ifdef HAL_OSPI_MODULE_ENABLED
WEAK const PinMap PinMap_OCTOSPI_DATA3[] = {
  {PA_6,  OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO3
  {PE_15, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO3
  {NC,    NP,       0}
};
#endif

#ifdef HAL_OSPI_MODULE_ENABLED
WEAK const PinMap PinMap_OCTOSPI_DATA4[] = {
  {PC_1, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO4
  {PD_4, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO4
  {NC,   NP,       0}
};
#endif

#ifdef HAL_OSPI_MODULE_ENABLED
WEAK const PinMap PinMap_OCTOSPI_DATA5[] = {
  {PC_2, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO5
  {PD_5, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO5
  {NC,   NP,       0}
};
#endif

#ifdef HAL_OSPI_MODULE_ENABLED
WEAK const PinMap PinMap_OCTOSPI_DATA6[] = {
  {PC_3, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO6
  {PD_6, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO6
  {NC,   NP,       0}
};
#endif

#ifdef HAL_OSPI_MODULE_ENABLED
WEAK const PinMap PinMap_OCTOSPI_DATA7[] = {
  {PC_0, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_OCTOSPI1)}, // OCTOSPIM_P1_IO7
  {PD_7, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_IO7
  {NC,   NP,       0}
};
#endif

#ifdef HAL_OSPI_MODULE_ENABLED
WEAK const PinMap PinMap_OCTOSPI_SCLK[] = {
  {PA_3,  OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_CLK
  {PB_10, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_CLK
  {PE_10, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_CLK
  {NC,    NP,       0}
};
#endif

#ifdef HAL_OSPI_MODULE_ENABLED
WEAK const PinMap PinMap_OCTOSPI_SSEL[] = {
  {PA_0,  OCTOSPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI2)}, // OCTOSPIM_P2_NCS
  {PA_2,  OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_NCS
  {PA_4,  OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF3_OCTOSPI1)}, // OCTOSPIM_P1_NCS
  {PA_12, OCTOSPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF6_OCTOSPI2)}, // OCTOSPIM_P2_NCS
  {PB_11, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_NCS
  {PC_11, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_OCTOSPI1)}, // OCTOSPIM_P1_NCS
  {PD_3,  OCTOSPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI2)}, // OCTOSPIM_P2_NCS
  {PE_11, OCTOSPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_OCTOSPI1)}, // OCTOSPIM_P1_NCS
  {NC,    NP,       0}
};
#endif

//*** USB ***

#if defined(HAL_PCD_MODULE_ENABLED) || defined(HAL_HCD_MODULE_ENABLED)
WEAK const PinMap PinMap_USB_OTG_FS[] = {
  {PA_8,  USB_OTG_FS, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_USB)}, // USB_OTG_FS_SOF
  {PA_9,  USB_OTG_FS, STM_PIN_DATA(STM_MODE_INPUT, GPIO_NOPULL, GPIO_AF_NONE)}, // USB_OTG_FS_VBUS
  {PA_10, USB_OTG_FS, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_PULLUP, GPIO_AF10_USB)}, // USB_OTG_FS_ID
  {PA_11, USB_OTG_FS, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_USB)}, // USB_OTG_FS_DM
  {PA_12, USB_OTG_FS, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_USB)}, // USB_OTG_FS_DP
  {PA_13, USB_OTG_FS, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_USB)}, // USB_OTG_FS_NOE
  {PA_14, USB_OTG_FS, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_USB)}, // USB_OTG_FS_SOF
  {PC_9,  USB_OTG_FS, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF10_USB)}, // USB_OTG_FS_NOE
  {NC,    NP,         0}
};
#endif

//*** SD ***

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_CMD[] = {
  {PA_0, SDMMC2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF12_SDMMC2)}, // SDMMC2_CMD
  {PD_2, SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF12_SDMMC1)}, // SDMMC1_CMD
  {PD_7, SDMMC2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF11_SDMMC2)}, // SDMMC2_CMD
  {NC,   NP,     0}
};
#endif

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_CK[] = {
  {PC_1,  SDMMC2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF12_SDMMC2)}, // SDMMC2_CK
  {PC_12, SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF12_SDMMC1)}, // SDMMC1_CK
  {PD_6,  SDMMC2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF11_SDMMC2)}, // SDMMC2_CK
  {NC,    NP,     0}
};
#endif

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_DATA0[] = {
  {PB_14, SDMMC2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF12_SDMMC2)}, // SDMMC2_D0
  {PC_8,  SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF12_SDMMC1)}, // SDMMC1_D0
  {NC,    NP,     0}
};
#endif

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_DATA1[] = {
  {PB_15, SDMMC2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF12_SDMMC2)}, // SDMMC2_D1
  {PC_9,  SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF12_SDMMC1)}, // SDMMC1_D1
  {NC,    NP,     0}
};
#endif

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_DATA2[] = {
  {PB_3,  SDMMC2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF12_SDMMC2)}, // SDMMC2_D2
  {PC_10, SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF12_SDMMC1)}, // SDMMC1_D2
  {NC,    NP,     0}
};
#endif

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_DATA3[] = {
  {PB_4,  SDMMC2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF12_SDMMC2)}, // SDMMC2_D3
  {PC_11, SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF12_SDMMC1)}, // SDMMC1_D3
  {NC,    NP,     0}
};
#endif

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_DATA4[] = {
  {PB_8,      SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF12_SDMMC1)}, // SDMMC1_D4
  {PB_8_ALT1, SDMMC2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF11_SDMMC2)}, // SDMMC2_D4
  {NC,        NP,     0}
};
#endif

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_DATA5[] = {
  {PB_9,      SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF12_SDMMC1)}, // SDMMC1_D5
  {PB_9_ALT1, SDMMC2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF11_SDMMC2)}, // SDMMC2_D5
  {PC_0,      SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF12_SDMMC1)}, // SDMMC1_D5
  {NC,        NP,     0}
};
#endif

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_DATA6[] = {
  {PC_6,      SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF12_SDMMC1)}, // SDMMC1_D6
  {PC_6_ALT1, SDMMC2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF11_SDMMC2)}, // SDMMC2_D6
  {NC,        NP,     0}
};
#endif

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_DATA7[] = {
  {PC_7,      SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF12_SDMMC1)}, // SDMMC1_D7
  {PC_7_ALT1, SDMMC2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF11_SDMMC2)}, // SDMMC2_D7
  {NC,        NP,     0}
};
#endif

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_CKIN[] = {
  {PB_8, SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF8_SDMMC1)}, // SDMMC1_CKIN
  {NC,   NP,     0}
};
#endif

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_CDIR[] = {
  {PB_9, SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF8_SDMMC1)}, // SDMMC1_CDIR
  {NC,   NP,     0}
};
#endif

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_D0DIR[] = {
  {PC_6, SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF8_SDMMC1)}, // SDMMC1_D0DIR
  {NC,   NP,     0}
};
#endif

#ifdef HAL_SD_MODULE_ENABLED
WEAK const PinMap PinMap_SD_D123DIR[] = {
  {PC_7, SDMMC1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF8_SDMMC1)}, // SDMMC1_D123DIR
  {NC,   NP,     0}
};
#endif

#endif /* !CUSTOM_PERIPHERAL_PINS */
