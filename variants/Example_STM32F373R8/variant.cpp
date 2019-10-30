/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "pins_arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

// Pin number
const PinName digitalPin[] = {
  PC_0,	// I_mirr_1mA
  PC_8,	// Temp_AN_1
  PC_9,	// Temp_AN_2
  PA_8,	// Temp_AN_3
  PA_11,	// Temp_AN_4
  PA_12,	// Temp_intern_AN
  PF_7,	// Temp_kal_3k_AN
  PF_6,	// Temp_kal_30k_AN
  PC_4,	// AI24_AN_2
  PC_5,	// AI24_AN_1
  PC_6,	// AI24_AN_4
  PC_7,	// AI24_AN_3
  PA_7,	// 0_20mA_1
  PC_1,	// 0_20mA_2
  PC_2,	// EN_DA_PWM_1
  PC_3,	// EN_DA_PWM_2
  PB_1,	// AI_1
  PB_2,	// AI_2
  PE_8,	// AI_3
  PE_9,	// AI_4
  PD_8,	// AI_temperatur
  PB_14,	// AI_kal_3k
  PB_15,	// AI_kal_30k
  PB_0,	// AI_curr
  PA_15,	// DI_1
  PD_2,	// DI_2
  PC_12,	// DI_3
  PC_11,	// DI_4, USART3_RX
  PB_9,	// DI_5, USART3_RX
  PC_10,	// USART3_TX
  PA_4,	// DA_PWM_1
  PA_5,	// DA_PWM_2
  PA_2,	// pSwitch_7
  PA_1,	// nSwitch_7
  PA_3,	// pSwitch_8
  PA_6,	// nSwitch_8
  PB_4,	// pSwitch_9
  PB_6,	// nSwitch_9
  PB_5,	// pSwitch_10
  PB_7,	// nSwitch_10
  PA_9,	// A13_SOM_RX = USART1_TX
  PA_10,	// A13_SOM_TX = USART1_RX
  //PA_13,	// SWDIO
  //PA_14,	// SWCLK
  PB_3,	// SWO
  PC_13,	//LED??
  PA_0,
  PB_8
};


// static const uint8_t I_mirr_1mA = PC0;
// static const uint8_t Temp_AN_1 = PC8;
// static const uint8_t Temp_AN_2 = PC9;
// static const uint8_t Temp_AN_3 = PA8;
// static const uint8_t Temp_AN_4 = PA11;
// static const uint8_t Temp_intern_AN = PA12;
// static const uint8_t Temp_kal_3k_AN = PF7;
// static const uint8_t Temp_kal_30k_AN = PF6;
// 
// static const uint8_t AI24_AN_2 = PC4;
// static const uint8_t AI24_AN_1 = PC5;
// static const uint8_t AI24_AN_4 = PC6;
// static const uint8_t AI24_AN_3 = PC7;
// static const uint8_t o_20mA_1 = PA7;
// static const uint8_t o_20mA_2 = PC1;
// 
// static const uint8_t EN_DA_PWM_1 = PC2;
// static const uint8_t EN_DA_PWM_2 = PC3;
// 
// static const uint8_t AI_1 = PB1;
// static const uint8_t AI_2 = PB2;
// static const uint8_t AI_3 = PE8;
// static const uint8_t AI_4 = PE9;
// static const uint8_t AI_temperatur = PD8;
// static const uint8_t AI_kal_3k = PB14;
// static const uint8_t AI_kal_30k = PB15;
// static const uint8_t AI_curr = PB0;
// 
// static const uint8_t DI_1 = PA15;
// static const uint8_t DI_2 = PD2;
// static const uint8_t DI_3 = PC12;
// static const uint8_t DI_4 = PC11;
// static const uint8_t USART3_RX_1 = PC11;
// static const uint8_t DI_5 = PB9;
// static const uint8_t USART3_RX_2 = PB9;
// 
// static const uint8_t USART3_TX = PC10;
// static const uint8_t DA_PWM_1 = PA4;
// static const uint8_t DA_PWM_2 = PA5;
// 
// static const uint8_t pSwitch_7 = PA2;
// static const uint8_t nSwitch_7 = PA1;
// static const uint8_t pSwitch_8 = PA3;
// static const uint8_t nSwitch_8 = PA6;
// static const uint8_t pSwitch_9 = PB4;
// static const uint8_t nSwitch_9 = PB6;
// static const uint8_t pSwitch_10 = PB5;
// static const uint8_t nSwitch_10 = PB7;
// 
// static const uint8_t USART1_TX = PA9;
// static const uint8_t USART1_RX = PA10;
// 
// static const uint8_t SWDIO = PA13;
// static const uint8_t SWCLK = PA14;
// static const uint8_t SWO = PB3;



#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
// void SystemClock_Config(void)
WEAK void SystemClock_Config(void)
{
//   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
//   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
//   RCC_PeriphCLKInitTypeDef PeriphClkInit;
// 
// //   /* Configure the main internal regulator output voltage */
// //   __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
// 
// //   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
// //   RCC_OscInitStruct.HSEState = RCC_HSE_ON;
// //   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
//   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
//   RCC_OscInitStruct.HSEState = RCC_HSI_ON;
//   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
// //   RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
//   //RCC_OscInitStruct.HSICalibrationValue = 16;
// //   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
// //   RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
// //   RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
// //   RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV2;
//   
//   //RCC_OscInitStruct.LSEState = RCC_LSE_ON;
//  
//   HAL_RCC_OscConfig(&RCC_OscInitStruct);
// 
//   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
//                                 | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
// //   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE; //RCC_SYSCLKSOURCE_PLLCLK;
//   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI; //RCC_SYSCLKSOURCE_PLLCLK;
//   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
//   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
//   HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC1;
  PeriphClkInit.Adc1ClockSelection = RCC_ADC1PCLK2_DIV2;

  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

#ifdef __cplusplus
}
#endif
