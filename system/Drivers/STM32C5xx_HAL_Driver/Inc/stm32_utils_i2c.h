/**
  **********************************************************************************************************************
  * @file    stm32_utils_i2c.h
  * @brief   Header file for the STM32 UTILS I2C module.
  **********************************************************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  **********************************************************************************************************************
  */

/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/
#ifndef STM32_UTILS_I2C_H
#define STM32_UTILS_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include <math.h>

/** @addtogroup STM32C5xx_UTILS_Driver
  * @{
  */

/** @defgroup UTILS_I2C UTILS_I2C
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup UTILS_I2C_Exported_Types UTILS I2C Types
  * @{
  */

/**
  * @brief  I2C Utils status structure definition.
  */
typedef enum
{
  STM32_UTILS_I2C_OK            = 0x00000000U, /*!< Utils I2C operation completed successfully */
  STM32_UTILS_I2C_ERROR         = 0xFFFFFFFFU, /*!< Utils I2C operation completed with error   */
  STM32_UTILS_I2C_INVALID_PARAM = 0xAAAAAAAAU, /*!< Utils I2C invalid parameter                */
} stm32_utils_i2c_status_t;

/**
  * @brief  I2C Utils analog filter mode structure definition.
  */
typedef enum
{
  STM32_UTILS_I2C_ANALOG_FILTER_DISABLED = 0U, /*!< Analog filter is not enabled */
  STM32_UTILS_I2C_ANALOG_FILTER_ENABLED  = 1U, /*!< Analog filter is enabled     */
} stm32_utils_i2c_analog_filter_mode_t;

/**
  * @brief  I2C Utils TimeoutA mode structure definition.
  */
typedef enum
{
  STM32_UTILS_I2C_TIMEOUTA_SCL_LOW      = 0U, /*!< TimeoutA is used to detect SCL low level timeout               */
  STM32_UTILS_I2C_TIMEOUTA_SDA_SCL_HIGH = 1U, /*!< TimeoutA is used to detect both SCL and SDA high level timeout */
} stm32_utils_i2c_timeouta_mode_t;

/**
  * @brief  I2C Utils device mode structure definition.
  */
typedef enum
{
  STM32_UTILS_I2C_MASTER_MODE = 1U, /*!< Device in master mode */
  STM32_UTILS_I2C_SLAVE_MODE  = 0U, /*!< Device in slave mode  */
} stm32_utils_i2c_device_mode_t;

/**
  * @brief  I2C Utils timings basic configuration structure definition.
  */
typedef struct
{
  uint32_t clock_src_freq_hz; /*!< Specifies the I2C clock source frequency in Hz.
                                   The user can retrieve the I2Cx clock source frequency by calling
                                   HAL_I2C_GetClockFreq().
                                   Note: This HAL function must only be called after the RCC has been configured.
                                   Therefore, invoke it immediately before calling
                                   HAL_I2C_SetConfig().                                                             */

  uint32_t i2c_freq_hz;       /*!< Required I2C clock in Hz, for instance 4000000 for 400kHz on SCL                 */
} stm32_utils_i2c_timing_basic_config_t;


/**
  * @brief  I2C Utils timings advanced configuration structure definition.
  */
typedef struct
{
  uint32_t                             clock_src_freq_hz; /*!< Clock source frequency in Hz             */

  uint32_t                             i2c_freq_hz;       /*!< Required I2C bus clock in Hz             */

  uint32_t                             trise_ns;          /*!< Rise time max in ns                      */

  uint32_t                             tfall_ns;          /*!< Fall time max in ns                      */

  uint32_t                             dnf;               /*!< Digital noise filter coefficient.
                                                               This parameter must be a number
                                                               between Min_Data = 0 and Max_Data = 0x0F */

  stm32_utils_i2c_analog_filter_mode_t af;                /*!< Analog filter mode                       */
} stm32_utils_i2c_timing_advanced_config_t;

/**
  * @brief  I2C UTILS Timeout A configuration structure definition.
  */
typedef struct
{
  uint32_t                        clock_src_freq_hz; /*!< Source clock frequency of I2C Instance */
  stm32_utils_i2c_timeouta_mode_t timeouta_mode;     /*!< IDLE Timeout mode                      */
  uint32_t                        timeout_ns;        /*!< Timeout to be applied in ns            */
} stm32_utils_i2c_timeouta_config_t;

/**
  * @brief  I2C UTILS Timeout B configuration structure definition.
  */
typedef struct
{
  uint32_t                      clock_src_freq_hz; /*!< Source clock frequency of I2C Instance */
  stm32_utils_i2c_device_mode_t device_mode;       /*!< Device mode                            */
  uint32_t                      timeout_ns;        /*!< Timeout to be applied in ns            */
} stm32_utils_i2c_timeoutb_config_t;

/**
  * @}
  */

/* Exported functions ------------------------------------------------------------------------------------------------*/
/** @defgroup UTILS_I2C_Exported_Functions UTILS I2C Functions
  * @{
  */

stm32_utils_i2c_status_t STM32_UTILS_I2C_ComputeTimingBasic(const stm32_utils_i2c_timing_basic_config_t *p_config,
                                                            uint32_t *p_output_timing_reg);
stm32_utils_i2c_status_t STM32_UTILS_I2C_ComputeTimingAdvanced(const stm32_utils_i2c_timing_advanced_config_t *p_config,
                                                               uint32_t *p_output_timing_reg);
stm32_utils_i2c_status_t STM32_UTILS_I2C_CompTimeoutA(const stm32_utils_i2c_timeouta_config_t *p_config,
                                                      uint32_t *p_output_timeout_reg);
stm32_utils_i2c_status_t STM32_UTILS_I2C_CompTimeoutB(const stm32_utils_i2c_timeoutb_config_t *p_config,
                                                      uint32_t *p_output_timeout_reg);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32_UTILS_I2C_H */
