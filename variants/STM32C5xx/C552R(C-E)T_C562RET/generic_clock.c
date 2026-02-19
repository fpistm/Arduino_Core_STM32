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
#if defined(ARDUINO_GENERIC_C552RCTX) || defined(ARDUINO_GENERIC_C552RETX) ||\
    defined(ARDUINO_GENERIC_C562RETX)
#include "pins_arduino.h"
// #include "stm32yyxx_ll_flash.h"
// #include "stm32yyxx_ll_utils.h"
// #include "stm32yyxx_ll_rcc.h"

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{
  if (HAL_RCC_HSIS_Enable() != HAL_OK) {
    Error_Handler();
  }

  hal_rcc_psi_config_t config_psi;
  config_psi.psi_source = HAL_RCC_PSI_SRC_HSI_8MHz;
  config_psi.psi_ref = HAL_RCC_PSI_REF_8MHZ;
  config_psi.psi_out = HAL_RCC_PSI_OUT_144MHZ;
  if (HAL_RCC_PSI_SetConfig(&config_psi) != HAL_OK) {
    Error_Handler();
  }

  if (HAL_RCC_PSIS_Enable() != HAL_OK) {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB busses clocks */
  hal_rcc_bus_clk_config_t config_bus;
  config_bus.hclk_prescaler  = HAL_RCC_HCLK_PRESCALER1;
  config_bus.pclk1_prescaler = HAL_RCC_PCLK_PRESCALER1;
  config_bus.pclk2_prescaler = HAL_RCC_PCLK_PRESCALER1;
  config_bus.pclk3_prescaler = HAL_RCC_PCLK_PRESCALER1;
  if (HAL_RCC_SetBusClockConfig(&config_bus) != HAL_OK) {
    Error_Handler();
  }

  /** Frequency will be increased */
  HAL_FLASH_ITF_SetLatency(HAL_FLASH, HAL_FLASH_ITF_LATENCY_4);

  if (HAL_RCC_SetSYSCLKSource(HAL_RCC_SYSCLK_SRC_PSIS) != HAL_OK) {
    Error_Handler();
  }

  HAL_FLASH_ITF_SetProgrammingDelay(HAL_FLASH, HAL_FLASH_ITF_PROGRAM_DELAY_2);

  if (HAL_UpdateCoreClock() != HAL_OK) {
    Error_Handler();
  }
  // LL_RCC_HSIS_Enable();
  // while(LL_RCC_HSIS_IsReady() != 1U)
  // {
  // }

  // LL_RCC_ConfigPSI(LL_RCC_PSIFREQ_144MHZ, LL_RCC_PSIREF_8MHZ, LL_RCC_PSISOURCE_HSIDIV18);

  // LL_RCC_PSIS_Enable();
  // while(LL_RCC_PSIS_IsReady() != 1U)
  // {
  // }

  // /** Initializes the CPU, AHB and APB busses clocks */
  // LL_RCC_ConfigBusClock(LL_RCC_HCLK_PRESCALER_1 | LL_RCC_APB1_PRESCALER_1 |
  //                       LL_RCC_APB2_PRESCALER_1 | LL_RCC_APB3_PRESCALER_1);

  // /** Frequency will be increased */
  // LL_FLASH_SetLatency(FLASH, LL_FLASH_LATENCY_4WS);

  // LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PSIS);
  // /* Wait till System clock is ready */
  // while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PSIS)
  // {
  // }

  // LL_FLASH_SetProgrammingDelay(FLASH, LL_FLASH_PROGRAM_DELAY_2);

  // LL_SetSystemCoreClock(144000000U);
  // LL_Init1msTick(SystemCoreClock);

  // /* Peripheral clocks */
  // LL_RCC_HSIK_SetDivider(LL_RCC_HSIK_DIV_8);
  // LL_RCC_HSIK_Enable();
  // while(LL_RCC_HSIK_IsReady() != 1U)
  // {
  // }

  // if (HAL_RCC_LPUART1_SetKernelClkSource(HAL_RCC_LPUART1_CLK_SRC_HSIK) != HAL_OK)
  // {
  //   Error_Handler();
  // }

}

#endif /* ARDUINO_GENERIC_* */
