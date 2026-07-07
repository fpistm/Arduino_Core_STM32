/**
  **********************************************************************************************************************
  * @file    stm32_utils_i3c.c
  * @brief   This utility helps calculate the different I3C timing values.
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

/* Includes ----------------------------------------------------------------------------------------------------------*/
#include "stm32_utils_i3c.h"

/** @addtogroup STM32C5xx_UTILS_Driver
  * @{
  */

/** @addtogroup UTILS_I3C
  * @{
  */
/** @defgroup UTILS_I3C_Introduction UTILS I3C Timing Introduction
  * @{

    This module provides utility functions to simplify the configuration of I3C
    peripherals on STM32 devices. It automates the calculation of timing values,
    ensuring compliance with the I3C protocol specification and reliable
    communication.

    \b Important: Note that these C functions are computationally intensive.
    Use STM32CubeMX2 for calculations and store the values rather than calculating at runtime
    to avoid application latency.

    Timing configuration for I3C is performed in one of two modes, depending on
    the role of the peripheral:
    - Controller mode: Use the `stm32_utils_i3c_ctrl_timing_config_t` structure
      and call `STM32_UTILS_I3C_CTRL_ComputeTiming()` to calculate register
      values for I3C_TIMINGR0 and I3C_TIMINGR1.
    - Target mode: Use the `stm32_utils_i3c_tgt_timing_config_t` structure and
      call `STM32_UTILS_I3C_TGT_ComputeTiming()` to calculate the register value
      for I3C_TIMINGR1.

    Select the appropriate mode based on whether the I3C peripheral operates
    as a controller or a target. Only one mode is used per peripheral
    instance.

    The computed values are used directly to fill hardware registers
    (I3C_TIMINGR0 and I3C_TIMINGR1) via the appropriate LL/HAL functions or
    direct register access.

  */
/**
  * @}
  */

/** @defgroup UTILS_I3C_How_To_Use UTILS I3C Timing How To Use
  * @{

# How to use the UTILS I3C Timing module

1. Configure the I3C peripheral:
  - Set up the I3C hardware (clock source, GPIO, NVIC) as required for the STM32 device.

2. Choose the timing configuration mode:
  - **Controller mode:**
    - Fill a `stm32_utils_i3c_ctrl_timing_config_t` structure with the clock source frequency,
    desired I3C push-pull and I2C open-drain bus speeds, duty cycle, activity state,
    and bus type (pure I3C or mixed I3C/I2C).
    - Call `STM32_UTILS_I3C_CTRL_ComputeTiming()` to compute the values for I3C_TIMINGR0 and I3C_TIMINGR1.
  - **Target mode:**
    - Fill a `stm32_utils_i3c_tgt_timing_config_t` structure with the clock source frequency.
    - Call `STM32_UTILS_I3C_TGT_ComputeTiming()` to compute the value for I3C_TIMINGR1.

  - Select the mode based on whether the I3C peripheral operates as a controller or a target.

3. Apply the timing to the I3C peripheral:
  - Use the computed timing values to configure the I3C instance using the HAL or LL driver,
  or by direct register access.
  - For low-level or performance-critical use cases, write the computed values directly
  to the I3C_TIMINGR0 and I3C_TIMINGR1 registers.

  */

/**
  * @}
  */
/* Private constants ---------------------------------------------------------*/
/** @defgroup UTILS_I3C_Private_Constants UTILS I3C Timing private constants
  * @{
  */

#define SEC210PSEC              (uint64_t)100000000000 /*!< 10ps, to take two decimal float of ns calculation */
#define TI3CH_MIN               3200U       /*!< Open drain & push pull SCL high min, 32ns */
#define TI3CH_OD_MAX            4100U       /*!< Open drain SCL high max, 41 ns */
#define TI3CL_OD_MIN            20000U      /*!< Open drain SCL low min, 200 ns */
#define TFMPL_OD_MIN            50000U      /*!< Fast Mode Plus Open drain SCL low min, 500 ns */
#define TFML_OD_MIN             130000U     /*!< Fast Mode Open drain SCL low min, 1300 ns */
#define TFM_MIN                 250000U     /*!< Fast Mode, period min for ti3cclk, 2.5us */
#define TSM_MIN                 1000000U    /*!< Standard Mode, period min for ti3cclk, 10us */
#define TI3C_CAS_MIN            3840U       /*!< Time SCL after START min, 38.4 ns */
#define TCAPA                   35000U      /*!< Capacitor effect Value measure on Nucleo around 350ns */
#define I3C_FREQUENCY_MAX       257000000U  /*!< Maximum I3C frequency */

/**
  * @}
  */

/* Private macros ----------------------------------------------------------------------------------------------------*/
/** @defgroup UTILS_I3C_Private_Macros UTILS I3C Timing private macros
  * @{
  */

/** @brief  Rounds the given number to the nearest multiple of the divisor.
  * @param  x The number to be rounded.
  * @param  d The divisor used for rounding.
  * @return The rounded number.
 */
#define DIV_ROUND_CLOSEST(x, d) (((x) + ((d) / 2U)) / (d))

/**
  * @}
  */

/* Private function prototypes ---------------------------------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------------------------------------------------*/
/** @addtogroup UTILS_I3C_Exported_Functions
  * @{
  */

/**
  * @brief  Calculate the I3C Controller timing according current I3C clock source and required I3C bus clock.
  * @param  p_config Pointer to a @ref stm32_utils_i3c_ctrl_timing_config_t structure that contains
  *         the required parameter for I3C timing computation.
  * @param  p_output_timing_reg0 Pointer to I3C_TIMINGR0 register value calculated by referring to I3C initialization
            section in reference Manual. This value is directly calculated by CubeMx2.
  * @param  p_output_timing_reg1 Pointer to a I3C_TIMINGR1 register value calculated by referring to I3C
            initialization section in reference Manual. This value is directly calculated by CubeMx2.
  * @retval STM32_UTILS_I3C_OK Timing calculation successfully
  * @retval STM32_UTILS_I3C_ERROR Timing calculation error
  * @retval STM32_UTILS_I3C_INVALID_PARAM Invalid Timing parameter
  */
stm32_utils_i3c_status_t STM32_UTILS_I3C_CTRL_ComputeTiming(const stm32_utils_i3c_ctrl_timing_config_t *p_config,
                                                            uint32_t *p_output_timing_reg0,
                                                            uint32_t *p_output_timing_reg1)
{
  stm32_utils_i3c_ctrl_raw_timing_t raw_timing;
  *p_output_timing_reg0 = 0UL;
  *p_output_timing_reg1 = 0UL;

  stm32_utils_i3c_status_t status = STM32_UTILS_I3C_OK;

  /* MIPI Standard constants */
  /* I3C: Open drain & push pull SCL high min, tDIG_H & tDIG_H_MIXED: 32 ns */
  uint32_t ti3ch_min       = TI3CH_MIN;

  /* I3C: Open drain SCL high max, t_HIGH: 41 ns */
  uint32_t ti3ch_od_max   = TI3CH_OD_MAX;

  /* I3C: Open drain SCL high max, tHIGH: 41 ns (Ti3ch_od_max= 410)
      I3C (pure bus): Open drain SCL low min, tLOW_OD: 200 ns */
  uint32_t ti3cl_od_min    = TI3CL_OD_MIN;

  /* I3C (mixed bus): Open drain SCL low min,
     tLOW: 500 ns (FM+ I2C on the bus)
     tLOW: 1300 ns (FM I2C on the bus) */
  uint32_t tfmpl_od_min    = TFMPL_OD_MIN;
  uint32_t tfml_od_min     = TFML_OD_MIN;

  /* I2C: min ti3cclk
          fSCL: 1 MHz (FM+)
          fSCL: 100 kHz (SM) */
  uint32_t tfm_min         = TFM_MIN;
  uint32_t tsm_min         = TSM_MIN;

  /* I3C: time SCL after START min, Tcas: 38,4 ns */
  uint32_t ti3c_cas_min    = TI3C_CAS_MIN;

  /* Period Clock source */
  uint32_t ti3cclk = 0U;

  /* I3C: Push pull period */
  uint32_t ti3c_pp_min = 0U;

  /* I2C: Open drain period */
  uint32_t ti2c_od_min = 0U;

  /* Time for SDA rise to 70% VDD from GND, capacitor effect */
  /* Value measure on Nucleo around 350ns */
  uint32_t tcapa = TCAPA;

  /* Compute variable */
  uint32_t sclhi3c;
  uint32_t scllpp;
  uint32_t scllod;
  uint32_t sclhi2c;
  uint32_t oneus;
  uint32_t free;
  uint32_t sdahold;

  /* Verify Parameters */
  if (p_config->clock_src_freq_hz > I3C_FREQUENCY_MAX)
  {
    /* Above this frequency, some timing register parameters are over than field value */
    status = STM32_UTILS_I3C_INVALID_PARAM;
  }

  if ((p_config->bus_type != STM32_UTILS_I3C_PURE_I3C_BUS) && (p_config->bus_type != STM32_UTILS_I3C_I2C_MIXED_BUS))
  {
    status = STM32_UTILS_I3C_INVALID_PARAM;
  }

  if (((p_config->clock_src_freq_hz == 0U) || (p_config->i3c_pp_freq_hz == 0U))
      && (p_config->bus_type == STM32_UTILS_I3C_PURE_I3C_BUS))
  {
    status = STM32_UTILS_I3C_INVALID_PARAM;
  }

  if (((p_config->clock_src_freq_hz == 0U) || (p_config->i3c_pp_freq_hz == 0U) || (p_config->i2c_od_freq_hz == 0U))
      && (p_config->bus_type == STM32_UTILS_I3C_I2C_MIXED_BUS))
  {
    status = STM32_UTILS_I3C_INVALID_PARAM;
  }

  if (status == STM32_UTILS_I3C_OK)
  {
    /* Period Clock source */
    ti3cclk = (uint32_t)((SEC210PSEC + ((uint64_t)p_config->clock_src_freq_hz / (uint64_t)2))
                         / (uint64_t)p_config->clock_src_freq_hz);

    if ((p_config->duty_cycle_purcent > 50U) || (ti3cclk == 0U))
    {
      status = STM32_UTILS_I3C_ERROR;
    }
  }

  if ((status == STM32_UTILS_I3C_OK) && (ti3cclk != 0U))
  {
    /* I3C: Push pull period */
    ti3c_pp_min = (uint32_t)((SEC210PSEC + ((uint64_t)p_config->i3c_pp_freq_hz / (uint64_t)2))
                             / (uint64_t)p_config->i3c_pp_freq_hz);

    /* I2C: Open drain period */
    ti2c_od_min = (uint32_t)((SEC210PSEC + ((uint64_t)p_config->i2c_od_freq_hz / (uint64_t)2))
                             / (uint64_t)p_config->i2c_od_freq_hz);

    if ((p_config->bus_type != STM32_UTILS_I3C_PURE_I3C_BUS) && (ti2c_od_min > tsm_min))
    {
      status = STM32_UTILS_I3C_ERROR;
    }
  }

  /* SCL Computation */
  if ((status == STM32_UTILS_I3C_OK) && (ti3cclk != 0U))
  {
    /* I3C SCL high level (push-pull & open drain) */
    if (p_config->bus_type == STM32_UTILS_I3C_PURE_I3C_BUS)
    {
      sclhi3c = DIV_ROUND_CLOSEST(DIV_ROUND_CLOSEST(ti3c_pp_min * p_config->duty_cycle_purcent, ti3cclk), 100U) - 1U;

      /* Check if sclhi3c < ti3ch_min, in that case calculate sclhi3c based on ti3ch_min */
      if (((sclhi3c + 1U) * ti3cclk) < ti3ch_min)
      {
        sclhi3c = DIV_ROUND_CLOSEST(ti3ch_min, ti3cclk) - 1U;

        /* Check if sclhi3c < ti3ch_min */
        if (((sclhi3c + 1U) * ti3cclk) < ti3ch_min)
        {
          sclhi3c += 1U;
        }

        scllpp = DIV_ROUND_CLOSEST(ti3c_pp_min, ti3cclk) - (sclhi3c + 1U) - 1U;
      }
      else
      {
        sclhi3c = DIV_ROUND_CLOSEST(DIV_ROUND_CLOSEST(ti3c_pp_min * p_config->duty_cycle_purcent, ti3cclk), 100U) - 1U;

        /* Check if sclhi3c < ti3ch_min */
        if (((sclhi3c + 1U) * ti3cclk) < ti3ch_min)
        {
          sclhi3c += 1U;
        }

        scllpp  = DIV_ROUND_CLOSEST((ti3c_pp_min - ((sclhi3c + 1U) * ti3cclk) + (ti3cclk / 2U)), ti3cclk) - 1U;
      }

    }
    else
    {
      /* Warning: (sclhi3c + 1) * ti3cclk > Ti3ch_od_max expected */
      sclhi3c = DIV_ROUND_CLOSEST(ti3ch_od_max, ti3cclk) - 1U;

      if (((sclhi3c + 1U) * ti3cclk) < ti3ch_min)
      {
        sclhi3c += 1U;
      }
      else if (((sclhi3c + 1U) * ti3cclk) > ti3ch_od_max)
      {
        sclhi3c = (ti3ch_od_max / ti3cclk);
      }
      else
      {
        /* Do nothing, keep sclhi3c as previously calculated */
      }

      /* I3C SCL low level (push-pull) */
      /* tscllpp = (scllpp + 1) x ti3cclk */
      scllpp  = DIV_ROUND_CLOSEST((ti3c_pp_min - ((sclhi3c + 1U) * ti3cclk)), ti3cclk) - 1U;
    }

    /* Check if scllpp is superior at (ti3c_pp_min + 1/2 clock source cycle) */
    /* Goal is to choice the scllpp approach lowest, to have a value frequency highest approach as possible */
    uint32_t ideal_scllpp = (ti3c_pp_min - ((sclhi3c + 1U) * ti3cclk));
    if (((scllpp + 1U) * ti3cclk) >= (ideal_scllpp + (ti3cclk / 2U) + 1U))
    {
      scllpp -= 1U;
    }

    /* Check if scllpp + sclhi3c is inferior at (ti3c_pp_min + 1/2 clock source cycle) */
    /* Goal is to increase the scllpp, to have a value frequency not out of the clock request */
    if (((scllpp + sclhi3c + 1U + 1U) * ti3cclk) < (ideal_scllpp + (ti3cclk / 2U) + 1U))
    {
      scllpp += 1U;
    }

    /* I3C SCL low level (pure I3C bus) */
    if (p_config->bus_type == STM32_UTILS_I3C_PURE_I3C_BUS)
    {
      if (ti3c_pp_min < ti3cl_od_min)
      {
        scllod  = DIV_ROUND_CLOSEST(ti3cl_od_min, ti3cclk) - 1U;

        if (((scllod + 1U) * ti3cclk) < ti3cl_od_min)
        {
          scllod += 1U;
        }
      }
      else
      {
        scllod = scllpp;
      }

      /* Verify that SCL Open drain Low duration is superior as SDA rise time 70% */
      if (((scllod + 1U) * ti3cclk) < tcapa)
      {
        scllod = DIV_ROUND_CLOSEST(tcapa, ti3cclk) + 1U;
      }

      sclhi2c = 0U; /* I2C SCL not used in pure I3C bus */
    }
    /* SCL low level on mixed bus (open-drain) */
    /* I2C SCL high level (mixed bus with I2C) */
    else
    {
      scllod  = DIV_ROUND_CLOSEST(DIV_ROUND_CLOSEST(ti2c_od_min * (100U - p_config->duty_cycle_purcent),
                                                    ti3cclk), 100U) - 1U;

      /* Mix Bus Fast Mode plus */
      if (ti2c_od_min < tfm_min)
      {
        if (((scllod + 1U) * ti3cclk) < tfmpl_od_min)
        {
          scllod  = DIV_ROUND_CLOSEST(tfmpl_od_min, ti3cclk) - 1U;
        }
      }
      /* Mix Bus Fast Mode */
      else
      {
        if (((scllod + 1U) * ti3cclk) < tfml_od_min)
        {
          scllod  = DIV_ROUND_CLOSEST(tfml_od_min, ti3cclk) - 1U;
        }
      }

      sclhi2c = DIV_ROUND_CLOSEST((ti2c_od_min - ((scllod + 1U) * ti3cclk)), ti3cclk) - 1U;
    }

    /* Clock After Start computation */

    /* I3C pure bus: (Tcas + tcapa)/2 */
    if (p_config->bus_type == STM32_UTILS_I3C_PURE_I3C_BUS)
    {
      free = DIV_ROUND_CLOSEST((ti3c_cas_min + tcapa), (2U * ti3cclk)) + 1U;
    }
    /* I3C, I2C mixed: (scllod + tcapa)/2 */
    else
    {
      free = DIV_ROUND_CLOSEST((((scllod + 1U) * ti3cclk) + tcapa), (2U * ti3cclk));
    }

    /* One cycle hold time addition */
    /* By default 1/2 cycle: must be > 3 ns */
    if (ti3cclk > 600U)
    {
      sdahold = 0U;
    }
    else
    {
      sdahold = I3C_TIMINGR1_SDA_HD_0;
    }

    /* 1 microsecond reference */
    oneus = DIV_ROUND_CLOSEST(100000U, ti3cclk) - 2U;

    if ((scllpp > 0xFFU) || (sclhi3c > 0xFFU) || (scllod > 0xFFU) || (sclhi2c > 0xFFU)
        || (free > 0xFFU) || (oneus > 0xFFU))
    {
      /* In case the value exceeds 8 bits, it is possibly because the clock source has a rate that is too high for the
         bus clock request. */
      status = STM32_UTILS_I3C_ERROR;
    }
    else
    {
      /* SCL configuration */
      raw_timing.scl_pp_low_duration = (uint8_t)scllpp;
      raw_timing.scl_i3c_high_duration = (uint8_t)sclhi3c;
      raw_timing.scl_od_low_duration = (uint8_t)scllod;
      raw_timing.scl_i2c_high_duration = (uint8_t)sclhi2c;

      *p_output_timing_reg0 = ((uint32_t)raw_timing.scl_pp_low_duration                                   |
                               ((uint32_t)raw_timing.scl_i3c_high_duration << I3C_TIMINGR0_SCLH_I3C_Pos)  |
                               ((uint32_t)raw_timing.scl_od_low_duration << I3C_TIMINGR0_SCLL_OD_Pos)     |
                               ((uint32_t)raw_timing.scl_i2c_high_duration << I3C_TIMINGR0_SCLH_I2C_Pos));

      /* Free, Idle and SDA hold time configuration */
      raw_timing.bus_free_duration = (uint8_t)free;
      raw_timing.bus_idle_duration = (uint8_t)oneus;
      raw_timing.sda_hold_time = (stm32_utils_i3c_sda_hold_time_t)sdahold;
      raw_timing.wait_time = p_config->wait_time;

      *p_output_timing_reg1 = ((uint32_t)raw_timing.sda_hold_time                                 |
                               (uint32_t)raw_timing.wait_time                                     |
                               ((uint32_t)raw_timing.bus_free_duration <<  I3C_TIMINGR1_FREE_Pos) |
                               (uint32_t)raw_timing.bus_idle_duration);

    }
  }

  return status;
}

/**
  * @brief  Calculate the I3C Controller timing according current I3C clock source and required I3C bus clock.
  * @param  p_config Pointer to a @ref stm32_utils_i3c_tgt_timing_config_t structure that contains
  *         the required parameter for I3C timing computation.
  * @param  p_output_timing Pointer to a I3C_TIMINGR1 register value calculated by referring to I3C
            initialization section in reference Manual. This value is directly calculated by CubeMx2.
  * @retval STM32_UTILS_I3C_OK Timing calculation successfully
  * @retval STM32_UTILS_I3C_ERROR Timing calculation error
  * @retval STM32_UTILS_I3C_INVALID_PARAM Invalid Timing parameter
  */
stm32_utils_i3c_status_t STM32_UTILS_I3C_TGT_ComputeTiming(const stm32_utils_i3c_tgt_timing_config_t *p_config,
                                                           uint32_t *p_output_timing_reg1)
{
  stm32_utils_i3c_status_t status = STM32_UTILS_I3C_OK;
  uint32_t oneus;
  uint32_t ti3cclk = 0U;

  /* Verify Parameters */
  if (p_config->clock_src_freq_hz == 0U)
  {
    status = STM32_UTILS_I3C_INVALID_PARAM;
  }

  if (status == STM32_UTILS_I3C_OK)
  {
    /* Period Clock source */
    ti3cclk = (uint32_t)((SEC210PSEC + ((uint64_t)p_config->clock_src_freq_hz / (uint64_t)2))
                         / (uint64_t)p_config->clock_src_freq_hz);

    /* Verify Parameters */
    if (ti3cclk == 0U)
    {
      status = STM32_UTILS_I3C_ERROR;
    }
  }

  if ((status == STM32_UTILS_I3C_OK) && (ti3cclk != 0U))
  {
    /* 1 microsecond reference */
    oneus =  DIV_ROUND_CLOSEST(100000U, ti3cclk) - 2U;

    /* Bus available time configuration */
    *p_output_timing_reg1 = (oneus << I3C_TIMINGR1_AVAL_Pos);
  }

  return status;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
