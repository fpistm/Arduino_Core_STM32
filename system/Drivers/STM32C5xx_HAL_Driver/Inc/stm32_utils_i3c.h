/**
  **********************************************************************************************************************
  * @file    stm32_utils_i3c.h
  * @brief   Header file of UTILS I3C module.
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
#ifndef STM32_UTILS_I3C_H
#define STM32_UTILS_I3C_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ----------------------------------------------------------------------------------------------------------*/
#include "stm32c5xx.h"

/** @addtogroup STM32C5xx_UTILS_Driver
  * @{
  */

/** @defgroup UTILS_I3C UTILS_I3C
  * @{
  */

/* Exported types ----------------------------------------------------------------------------------------------------*/
/** @defgroup  UTILS_I3C_Exported_Types UTILS I3C Timing Types
  * @{
  */

/**
  * @brief  I3C utils status structure definition
  */
typedef enum
{
  STM32_UTILS_I3C_OK            = 0x00000000U, /*!< Utils I3C operation completed successfully */
  STM32_UTILS_I3C_ERROR         = 0xFFFFFFFFU, /*!< Utils I3C operation completed with error   */
  STM32_UTILS_I3C_INVALID_PARAM = 0xAAAAAAAAU, /*!< Utils I3C invalid parameter                */
} stm32_utils_i3c_status_t;

/**
  * @brief  Bus type defines that can be used with STM32_UTILS_I3C_CTRL_CalculateTiming function
  */
typedef enum
{
  STM32_UTILS_I3C_PURE_I3C_BUS  = 0U,  /*!< Pure I3C bus, no I2C */
  STM32_UTILS_I3C_I2C_MIXED_BUS = 1U,  /*!< Mixed bus I3C and I2C */
} stm32_utils_i3c_bus_type_t;

/**
  * @brief  Activity state, own activity state
  */
typedef enum
{
  STM32_UTILS_I3C_ACTIVITY_STATE_0 = 0x00000000U,                                   /*!< Own ctrl activity state 0 */
  STM32_UTILS_I3C_ACTIVITY_STATE_1 = I3C_TIMINGR1_ASNCR_0,                          /*!< Own ctrl activity state 1 */
  STM32_UTILS_I3C_ACTIVITY_STATE_2 = I3C_TIMINGR1_ASNCR_1,                          /*!< Own ctrl activity state 2 */
  STM32_UTILS_I3C_ACTIVITY_STATE_3 = (I3C_TIMINGR1_ASNCR_1 | I3C_TIMINGR1_ASNCR_0), /*!< Own ctrl activity state 3 */
} stm32_utils_i3c_activity_state_t;

/**
  * @brief  SDA_hold_time SDA hold time
  */
typedef enum
{
  STM32_UTILS_I3C_SDA_HOLD_TIME_0_5 = 0x00000000U,                                     /*!< SDA hold time is 0.5 x ti3cclk */
  STM32_UTILS_I3C_SDA_HOLD_TIME_1_5 = I3C_TIMINGR1_SDA_HD_0,                           /*!< SDA hold time is 1.5 x ti3cclk */
  STM32_UTILS_I3C_SDA_HOLD_TIME_2_5 = I3C_TIMINGR1_SDA_HD_1,                           /*!< SDA hold time is 2.5 x ti3cclk */
  STM32_UTILS_I3C_SDA_HOLD_TIME_3_5 = (I3C_TIMINGR1_SDA_HD_1 | I3C_TIMINGR1_SDA_HD_0), /*!< SDA hold time is 3.5 x ti3cclk */
} stm32_utils_i3c_sda_hold_time_t;

/**
  * @brief  I3C utils controller timing structure definition
  */
typedef struct
{
  uint32_t clock_src_freq_hz;                  /*!< I3C clock source in Hz */

  uint32_t i3c_pp_freq_hz;                     /*!< I3C required bus clock for push-pull phase in Hz */

  uint32_t i2c_od_freq_hz;                     /*!< I2C required bus clock for Open-Drain phase in Hz */

  uint32_t duty_cycle_purcent;                 /*!< I3C duty cycle for pure I3C bus or I2C duty cycle
                                                    for mixed bus in percent.
                                                    This parameter must be a value less than or equal to 50 percent */

  stm32_utils_i3c_activity_state_t wait_time;  /*!< Time that the main and the new controllers must wait
                                                    before issuing a start. This parameter must be
                                                    a value of @ref stm32_utils_i3c_activity_state_t */

  stm32_utils_i3c_bus_type_t bus_type;         /*!< Bus configuration type. This parameter must be
                                                    a value of @ref stm32_utils_i3c_bus_type_t */
} stm32_utils_i3c_ctrl_timing_config_t;

/**
  * @brief  I3C utils controller bus configuration structure definition
  */
typedef struct
{
  stm32_utils_i3c_sda_hold_time_t sda_hold_time;  /*!< I3C SDA hold time. This parameter must be a value of
                                                       @ref stm32_utils_i3c_sda_hold_time_t */

  stm32_utils_i3c_activity_state_t wait_time;  /*!< Time that the main and the new controllers must wait
                                                    before issuing a start.
                                                    This parameter must be a value of
                                                    @ref stm32_utils_i3c_activity_state_t */

  uint8_t scl_pp_low_duration;   /*!< I3C SCL low duration in number of kernel clock cycles in I3C push-pull phases.
                                      This parameter must be a number between Min_Data=0 and Max_Data=0xFF. */

  uint8_t scl_i3c_high_duration; /*!< I3C SCL high duration in number of kernel clock cycles,
                                      used for I3C messages for I3C open-drain and push pull phases.
                                      This parameter must be a number between Min_Data=0 and Max_Data=0xFF. */

  uint8_t scl_od_low_duration;   /*!< I3C SCL low duration in number of kernel clock cycles in
                                      open-drain phases, used for legacy I2C commands and for I3C open-drain phases.
                                      This parameter must be a number between Min_Data=0 and Max_Data=0xFF. */

  uint8_t scl_i2c_high_duration; /*!< I3C SCL high duration in number of kernel clock cycles, used for legacy I2C
                                      commands. This parameter must be a number between Min_Data=0 and Max_Data=0xFF. */

  uint8_t bus_free_duration;    /*!< I3C controller duration in number of kernel clock cycles, after a stop and before
                                     a start. This parameter must be a number between Min_Data=0 and Max_Data=0xFF. */

  uint8_t bus_idle_duration;    /*!< I3C controller duration in number of kernel clock cycles to be elapsed, after that
                                     both SDA and SCL are continuously high and stable before issuing a hot-join event.
                                     This parameter must be a number between Min_Data=0 and Max_Data=0xFF. */
} stm32_utils_i3c_ctrl_raw_timing_t;

/**
  * @brief  I3C utils Target Timing structure definition
  */
typedef struct
{
  uint32_t clock_src_freq_hz;  /*!< I3C clock source (in Hz). */
} stm32_utils_i3c_tgt_timing_config_t;
/**
  * @}
  */

/* Exported functions ------------------------------------------------------------------------------------------------*/
/** @defgroup UTILS_I3C_Exported_Functions UTILS I3C Timing Functions
  * @{
  */
stm32_utils_i3c_status_t STM32_UTILS_I3C_CTRL_ComputeTiming(const stm32_utils_i3c_ctrl_timing_config_t *p_config,
                                                            uint32_t *p_output_timing_reg0,
                                                            uint32_t *p_output_timing_reg1);

stm32_utils_i3c_status_t STM32_UTILS_I3C_TGT_ComputeTiming(const stm32_utils_i3c_tgt_timing_config_t *p_config,
                                                           uint32_t *p_output_timing_reg1);
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
#endif /* __cplusplus */

#endif /* STM32_UTILS_I3C_H */
