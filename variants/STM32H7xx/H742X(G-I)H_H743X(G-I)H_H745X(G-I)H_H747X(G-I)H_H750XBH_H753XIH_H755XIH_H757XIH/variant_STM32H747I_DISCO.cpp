/*
 *******************************************************************************
 * Copyright (c) 2023, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#if defined(ARDUINO_STM32H747I_DISCO)
#include "pins_arduino.h"

//Digital pin number mapping array
const PinName digitalPin[] = {
  PJ_9,
  PJ_8,
  PJ_3,
  PF_8,
  PJ_4,
  PA_6,
  PJ_7,
  PJ_0,
  PJ_5,
  PJ_6,
  PK_1,
  PJ_10,
  PJ_11,
  PK_0,
  PD_13,
  PD_12,
  PA_4,
  PF_10,
  PA_0_C,
  PA_1_C,
  PC_2_C,
  PC_3_C,
  PI_12,
  PI_13,
  PI_14,
  PI_15,
  PA_10,
  PA_9,
  PA_11,
  PA_12,
  PC_2,
  PC_3,
  PK_2,
  PK_3,
  PK_4,
  PK_5,
  PK_6,
  PC_13,
  PB_2,
  PG_6,
  PD_11,
  PF_9,
  PF_7,
  PF_6,
  PH_2,
  PH_3,
  PG_9,
  PG_14,
  PC_8,
  PC_9,
  PC_10,
  PC_11,
  PC_12,
  PD_2,
  PI_8,
  PG_10,
  PB_7,
  PJ_14,
  PA_5,
  PA_3,
  PB_0,
  PB_1,
  PB_10,
  PB_11,
  PB_12,
  PB_13,
  PB_5,
  PC_0,
  PH_4,
  PI_11,
  PJ_1,
  PD_7,
  PE_3,
  PE_4,
  PE_5,
  PE_6,
  PG_7,
  PC_1,
  PE_2,
  PJ_15,
  PA_0,
  PD_5,
  PD_6,
  PD_4,
  PB_15,
  PB_14,
  PC_6,
  PJ_13,
  PC_7,
  PD_3,
  PB_9,
  PB_8,
  PH_0,
  PH_1,
  PC_14,
  PC_15,
  PA_8,
  PJ_12,
  PG_3,
  PJ_2,
  PB_6,
  PK_7,
  PE_0,
  PE_1,
  PI_4,
  PI_5,
  PG_8,
  PH_5,
  PH_6,
  PH_7,
  PF_11,
  PG_15,
  PD_14,
  PD_15,
  PD_0,
  PD_1,
  PE_7,
  PE_8,
  PE_9,
  PE_10,
  PE_11,
  PE_12,
  PE_13,
  PE_14,
  PE_15,
  PD_8,
  PD_9,
  PD_10,
  PH_8,
  PH_9,
  PH_10,
  PH_11,
  PH_12,
  PH_13,
  PH_14,
  PH_15,
  PI_0,
  PI_1,
  PI_2,
  PI_3,
  PI_6,
  PI_7,
  PI_9,
  PI_10,
  PF_0,
  PF_1,
  PF_2,
  PF_3,
  PF_4,
  PF_5,
  PF_12,
  PF_13,
  PF_14,
  PF_15,
  PG_0,
  PG_1,
  PG_2,
  PG_4,
  PG_5,
  PA_13,
  PA_14,
  PA_15,
  PB_3,
  PB_4,
  PA_1,
  PA_2,
  PA_7,
  PC_4,
  PC_5,
  PG_11,
  PG_12,
  PG_13
};

// Analog (Ax) pin number mapping array
const uint32_t analogInputPin[] = {
  16, //A0
  17, //A1
  18, //A2
  19, //A3
  20, //A4
  21  //A5
};

#ifdef __cplusplus
extern "C" {
#endif

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
  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_CSI|RCC_OSCILLATORTYPE_HSI
                              |RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.CSIState = RCC_CSI_ON;
  RCC_OscInitStruct.CSICalibrationValue = RCC_CSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 48;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 5;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSI, RCC_MCODIV_1);

  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {};

  /** Initializes the peripherals clock
  */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_CEC | RCC_PERIPHCLK_SAI1
                                           | RCC_PERIPHCLK_SPDIFRX | RCC_PERIPHCLK_DSI | RCC_PERIPHCLK_FMC
                                           | RCC_PERIPHCLK_LTDC | RCC_PERIPHCLK_QSPI | RCC_PERIPHCLK_RTC
                                           | RCC_PERIPHCLK_SDMMC | RCC_PERIPHCLK_LPUART1 | RCC_PERIPHCLK_UART8
                                           | RCC_PERIPHCLK_FDCAN | RCC_PERIPHCLK_SPI2 | RCC_PERIPHCLK_SPI5
                                           | RCC_PERIPHCLK_I2C123 | RCC_PERIPHCLK_I2C4 | RCC_PERIPHCLK_USB;
  PeriphClkInitStruct.PLL2.PLL2M = 2;
  PeriphClkInitStruct.PLL2.PLL2N = 12;
  PeriphClkInitStruct.PLL2.PLL2P = 2;
  PeriphClkInitStruct.PLL2.PLL2Q = 2;
  PeriphClkInitStruct.PLL2.PLL2R = 2;
  PeriphClkInitStruct.PLL2.PLL2RGE = RCC_PLL2VCIRANGE_3;
  PeriphClkInitStruct.PLL2.PLL2VCOSEL = RCC_PLL2VCOMEDIUM;
  PeriphClkInitStruct.PLL2.PLL2FRACN = 0;
  PeriphClkInitStruct.PLL3.PLL3M = 32;
  PeriphClkInitStruct.PLL3.PLL3N = 192;
  PeriphClkInitStruct.PLL3.PLL3P = 2;
  PeriphClkInitStruct.PLL3.PLL3Q = 2;
  PeriphClkInitStruct.PLL3.PLL3R = 2;
  PeriphClkInitStruct.PLL3.PLL3RGE = RCC_PLL3VCIRANGE_3;
  PeriphClkInitStruct.PLL3.PLL3VCOSEL = RCC_PLL3VCOMEDIUM;
  PeriphClkInitStruct.PLL3.PLL3FRACN = 0;
  PeriphClkInitStruct.AdcClockSelection = RCC_ADCCLKSOURCE_PLL2;
  PeriphClkInitStruct.CecClockSelection = RCC_CECCLKSOURCE_LSI;
  PeriphClkInitStruct.DsiClockSelection = RCC_DSICLKSOURCE_PHY;
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  PeriphClkInitStruct.UsbClockSelection = RCC_USBCLKSOURCE_PLL;
  PeriphClkInitStruct.Sai1ClockSelection = RCC_SAI1CLKSOURCE_PLL;
  PeriphClkInitStruct.SpdifrxClockSelection = RCC_SPDIFRXCLKSOURCE_PLL;
  PeriphClkInitStruct.FmcClockSelection = RCC_FMCCLKSOURCE_D1HCLK;
  PeriphClkInitStruct.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL;
  PeriphClkInitStruct.SdmmcClockSelection = RCC_SDMMCCLKSOURCE_PLL;
  PeriphClkInitStruct.QspiClockSelection = RCC_QSPICLKSOURCE_D1HCLK;
  PeriphClkInitStruct.Spi123ClockSelection = RCC_SPI123CLKSOURCE_PLL;
  PeriphClkInitStruct.Spi45ClockSelection = RCC_SPI45CLKSOURCE_D2PCLK1;
  PeriphClkInitStruct.Lpuart1ClockSelection = RCC_LPUART1CLKSOURCE_CSI;
  PeriphClkInitStruct.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_D2PCLK1;
  PeriphClkInitStruct.I2c123ClockSelection = RCC_I2C123CLKSOURCE_D2PCLK1;
  PeriphClkInitStruct.I2c4ClockSelection = RCC_I2C4CLKSOURCE_D3PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  //TODO: do we need the PLLInit of HAL_DSI_Init? do we ignore it because DSI isn't supported?
}

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_STM32H747I_DISCO */
