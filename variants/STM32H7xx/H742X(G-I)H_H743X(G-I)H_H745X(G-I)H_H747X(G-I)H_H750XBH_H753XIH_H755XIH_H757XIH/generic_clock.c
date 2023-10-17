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
#if defined(ARDUINO_GENERIC_H742XGHX) || defined(ARDUINO_GENERIC_H742XIHX) ||\
    defined(ARDUINO_GENERIC_H743XGHX) || defined(ARDUINO_GENERIC_H743XIHX) ||\
    defined(ARDUINO_GENERIC_H745XGHX) || defined(ARDUINO_GENERIC_H745XIHX) ||\
    defined(ARDUINO_GENERIC_H747XGHX) || defined(ARDUINO_GENERIC_H747XIHX) ||\
    defined(ARDUINO_GENERIC_H750XBHX) || defined(ARDUINO_GENERIC_H753XIHX) ||\
    defined(ARDUINO_GENERIC_H755XIHX) || defined(ARDUINO_GENERIC_H757XIHX)
#include "pins_arduino.h"

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {};

  /** Supply configuration update enable
  */
#if defined(SMPS)
  /** If SMPS is available on this MCU, assume that the MCU's board is
   *  built to power the MCU using the SMPS since it's more efficient.
   *  In this case, we must configure the MCU to use DIRECT_SMPS_SUPPLY.
   * 
   *  N.B.: if the hardware configuration does not match the argument to
   *  HAL_PWREx_ConfigSupply(), the board will deadlock at this function call.
   *  This can manifest immediatly or after a RESET/power cycle.
   * 
   *  Trying to flash the board at this point will result in errors such as
   *  "No STM32 target found". To overcome this problem, erase the MCU's flash.
   * 
   *  The following settings in STM32CubeProgrammer appear to work for this purpose:
   *   - Mode: Power down
   *   - Reset mode: Hardware reset
   */
  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);
#else
  /** No SMPS available: use the internal volatage regulator (LDO).
   */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
#endif

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48|RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 9;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOMEDIUM;
  RCC_OscInitStruct.PLL.PLLFRACN = 3072;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

#endif /* ARDUINO_GENERIC_* */
