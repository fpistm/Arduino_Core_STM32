/**
  **********************************************************************************************************************
  * @file    stm32_utils_i2c.c
  * @brief   This utility helps to compute I2C and SMBUS timings and timeouts.
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
#include "stm32_utils_i2c.h"

/** @addtogroup STM32C5xx_UTILS_Driver
  * @{
  */

/** @addtogroup UTILS_I2C
  * @{
  */

/** @defgroup UTILS_I2C_Introduction UTILS I2C Timing Introduction
  * @{

    This module provides utility functions to simplify the configuration of I2C
    and SMBUS peripherals. It automates the calculation of timing and timeout values,
    ensuring compliance with protocol specifications and reliable communication.

    \b Important: Calculate timing and timeout values using STM32CubeMX2.
    It isrecommendedto use STM32CubeMX2 for these calculations, as the C functions provided here
 are computationally    intensive.

    There are two approaches for I2C timing configuration:
    - Basic mode: Bus frequencies are predefined (100 kHz for normal mode,
      400 kHz for fast mode, 1 MHz for fast mode plus). Provide the clock source frequency and desired
      I2C speed. The module calculates the timing value to meet the I2C standard.
    - Advanced mode: Allows full customization:
      - Frequency ranges:
        - 1 Hz to 100 kHz for normal mode
        - 101 kHz to 400 kHz for fast mode
        - 401 kHz to 1 MHz for fast mode plus
      - Parameters to fine-tune:
        - Rising time
        - Falling time
        - Digital noise filter coefficient
        - Analog filter mode

    This distinction allows for quick setup using standard values (basic) or full customization (advanced)
    for specific requirements.

    The computed values are used directly to fill hardware registers (I2C_TIMINGR for timings,
    I2C_TIMEOUTR for SMBUS timeouts) via the appropriate LL/HAL functions or direct register access.

  */
/**
  * @}
  */

/** @defgroup UTILS_I2C_How_To_Use UTILS I2C Timing How To Use
  * @{

# How to use the utils_i2c module

1. Configure your I2C peripheral:
  - Set up the I2C hardware (clock, GPIO, NVIC) as required for your STM32 device.

2. Choose your timing configuration approach:
  - **Basic mode:** Use the `stm32_utils_i2c_timing_basic_config_t` structure for quick setup.
  This mode supports only standard bus frequencies:
      - 100 kHz (Standard mode)
      - 400 kHz (Fast mode)
      - 1 MHz (Fast mode plus)
    Provide your clock source frequency and desired I2C speed (must match one of the above).
    The timing calculation will use protocol-compliant defaults.

  - **Advanced mode:** Use the `stm32_utils_i2c_timing_advanced_config_t` structure for full customization.
  This mode allows:
      - Any I2C speed in the supported range (1 Hz to 100 kHz for standard, 101 kHz to 400 kHz for fast,
      401 kHz to 1 MHz for fast plus)
      - Fine-tuning of rising time, falling time, digital noise filter coefficient, analog filter mode.
    Specify all timing parameters explicitly for precise control.

3. Calculate timing values:
  - For basic timing, call `STM32_UTILS_I2C_ComputeTimingBasic()` with your basic config.
  - For advanced timing, call `STM32_UTILS_I2C_ComputeAdvanced()` with your advanced config.
  - On success, use the timing register value to configure your I2C peripheral.
  If the function returns an error, check your input parameters.

4. Apply the timing to your I2C peripheral:
  - Use the computed timing value to configure your I2C instance using the HAL or LL driver,
  or by direct register access.
  - The function `LL_I2C_SetTiming` writes the value to the I2C_TIMINGR register.
  - Alternatively, write the computed value directly to the I2C_TIMINGR register for low-level
  or performance-critical use cases.

5. SMBUS timeout calculation (if needed):
  - For SMBUS TIMEOUTA, fill a `stm32_utils_i2c_smbus_timeouta_config_t` structure
  and call `STM32_UTILS_I2C_CompTimeoutA()`.
  - For SMBUS TIMEOUTB, fill a `stm32_utils_i2c_smbus_timeoutb_config_t` structure
  and call `STM32_UTILS_I2C_CompTimeoutB()`.
  - On success, use the returned value to configure the SMBUS TIMEOUT registers:
    - Recommended: Use `LL_I2C_ConfigSMBusTimeout()` to set the timeout value,
    then enable it with `LL_I2C_EnableSMBusTimeout()`
      and the appropriate parameter (`LL_I2C_SMBUS_TIMEOUTA`, `LL_I2C_SMBUS_TIMEOUTB`,
      or `LL_I2C_SMBUS_ALL_TIMEOUT`).
    - Alternatively, for direct register access, write the computed value to the TIMEOUTA
    and TIMEOUTB fields of the I2C_TIMEOUTR register.

6. Integrate with your application:
  - Use the computed timing and timeout values to ensure robust and specification-compliant I2C/SMBUS communication.

Note:
- The calculation and application workflow is identical for both basic and advanced modes,
and for TIMEOUTA and TIMEOUTB.

  */
/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/** @defgroup I2C_Private_Constants I2C Private Constants
  * @{
  */

#define I2C_SPEED_FREQ_STANDARD                (0U)         /* 100 kHz */
#define I2C_SPEED_FREQ_FAST                    (1U)         /* 400 kHz */
#define I2C_SPEED_FREQ_FAST_PLUS               (2U)         /* 1 MHz   */

#define I2C_VALID_TIMING_NBR_MAX               (128U)

#define I2C_ANALOG_FILTER_DELAY_MIN            (50.0)       /* ns */
#define I2C_ANALOG_FILTER_DELAY_MAX            (260.0)      /* ns */

#define I2C_DIGITAL_FILTER_COEF                (0U)

#define I2C_PRESC_MAX                          (16U)
#define I2C_SCLDEL_MAX                         (16U)
#define I2C_SDADEL_MAX                         (16U)
#define I2C_SCLH_MAX                           (256U)
#define I2C_SCLL_MAX                           (256U)

#define SMBUS_IDLE_TIMEOUT_MIN                 (25000000UL) /* ns */
#define SMBUS_IDLE_TIMEOUT_MAX                 (35000000UL) /* ns */
#define SMBUS_SLAVE_EXT_LOW_TIMEOUT_MAX        (25000000UL) /* ns */
#define SMBUS_MASTER_EXT_LOW_TIMEOUT_MAX       (10000000UL) /* ns */

#define SEC2NSEC                               (1000000000UL)

/**
  * @}
  */

/* Private macros -------------------------------------------------------------*/
/** @defgroup I2C_Private_Macros I2C Private Macros
  * @{
  */

/** @brief  Rounds the given number to the nearest multiple of the divisor.
  * @param  x The number to be rounded.
  * @param  d The divisor used for rounding.
  * @return The rounded number.
  */
#define DIV_ROUND_CLOSEST(x, d)   (((x) + ((d) / 2.0)) / (d))

/**
  * @}
  */

/* Private types ------------------------------------------------------------*/
/** @defgroup I2C_Private_Types I2C Private Types
  * @{
  */
typedef struct
{
  uint32_t freq;      /*!< Frequency in Hz                           */
  uint32_t freq_min;  /*!< Minimum frequency in Hz                   */
  uint32_t freq_max;  /*!< Maximum frequency in Hz                   */
  uint32_t hddat_min; /*!< Minimum data hold time in ns              */
  uint32_t vddat_max; /*!< Maximum data valid time in ns             */
  uint32_t sudat_min; /*!< Minimum data setup time in ns             */
  uint32_t lscl_min;  /*!< Minimum low period of the SCL clock in ns */
  uint32_t hscl_min;  /*!< Minimum high period of SCL clock in ns    */
  uint32_t trise_max; /*!< Rise time max in ns                       */
  uint32_t trise_min; /*!< Rise time min in ns                       */
  uint32_t tfall_max; /*!< Fall time in ns                           */
  uint32_t tfall_min; /*!< Fall time in ns                           */
  uint32_t dnf;       /*!< Digital noise filter coefficient          */
} i2c_charac_t;

typedef struct
{
  uint32_t presc;     /*!< Timing prescaler */
  uint32_t tscldel;   /*!< SCL delay        */
  uint32_t tsdadel;   /*!< SDA delay        */
  uint32_t sclh;      /*!< SCL high period  */
  uint32_t scll;      /*!< SCL low period   */
} i2c_timings_t;

/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/** @defgroup I2C_Private_Variables I2C Private variables
  * @{
  */

static i2c_timings_t i2c_valid_timing[I2C_VALID_TIMING_NBR_MAX];
static uint32_t      i2c_valid_timing_nbr;

static const i2c_charac_t i2c_charac[] =
{
  [I2C_SPEED_FREQ_STANDARD] =
  {
    .freq      = 100000U,
    .freq_min  = 80000U,
    .freq_max  = 120000U,
    .hddat_min = 0U,
    .vddat_max = 3450U,
    .sudat_min = 250U,
    .lscl_min  = 4700U,
    .hscl_min  = 4000U,
    .trise_min = 0U,
    .trise_max = 1000U,
    .tfall_min = 0U,
    .tfall_max = 300U,
    .dnf       = I2C_DIGITAL_FILTER_COEF,
  },
  [I2C_SPEED_FREQ_FAST] =
  {
    .freq      = 400000U,
    .freq_min  = 320000U,
    .freq_max  = 480000U,
    .hddat_min = 0U,
    .vddat_max = 900U,
    .sudat_min = 100U,
    .lscl_min  = 1300U,
    .hscl_min  = 600U,
    .trise_min = 20U,   /* 20 + 0.1Cb; cb ignored */
    .trise_max = 300U,
    .tfall_min = 20U,   /* 20 + 0.1Cb; cb ignored */
    .tfall_max = 300U,
    .dnf       = I2C_DIGITAL_FILTER_COEF,
  },
  [I2C_SPEED_FREQ_FAST_PLUS] =
  {
    .freq      = 1000000U,
    .freq_min  = 800000U,
    .freq_max  = 1200000U,
    .hddat_min = 0U,
    .vddat_max = 450U,
    .sudat_min = 50U,
    .lscl_min  = 500U,
    .hscl_min  = 260U,
    .trise_min = 0U,
    .trise_max = 120U,
    .tfall_min = 0U,
    .tfall_max = 120U,
    .dnf       = I2C_DIGITAL_FILTER_COEF,
  },
};

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup I2C_Private_function I2C Private function
  * @{
  */
static uint32_t I2C_Compute_SCLL_SCLH(const stm32_utils_i2c_timing_advanced_config_t *p_config, uint32_t i2c_speed);
static stm32_utils_i2c_status_t I2C_Compute_PRESC_SCLDEL_SDADEL(const stm32_utils_i2c_timing_advanced_config_t
                                                                *p_config,
                                                                uint32_t i2c_speed);
/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */
/** @addtogroup UTILS_I2C_Exported_Functions UTILS I2C Functions
  * @{
  */

/**
  * @brief  Compute I2C timing according to the current I2C clock source and required I2C clock.
  * @param  p_config Pointer to a @ref stm32_utils_i2c_timing_basic_config_t structure that contains
  *         the required parameters for I2C timing computation.
  * @param  p_output_timing_reg Pointer to an I2C_TIMINGR register value computed by referring to the I2C
            initialization section in the Reference Manual. This value is directly computed by STM32CubeMX2.
  * @retval STM32_UTILS_I2C_OK    Timing calculation successful.
  * @retval STM32_UTILS_I2C_ERROR Timing calculation error.
  */
stm32_utils_i2c_status_t STM32_UTILS_I2C_ComputeTimingBasic(const stm32_utils_i2c_timing_basic_config_t *p_config,
                                                            uint32_t *p_output_timing_reg)
{
  stm32_utils_i2c_status_t status = STM32_UTILS_I2C_ERROR;
  stm32_utils_i2c_timing_advanced_config_t p_advanced_config;
  uint32_t idx;

  i2c_valid_timing_nbr = 0U;

  if ((p_config->clock_src_freq_hz != 0U) && (p_config->i2c_freq_hz != 0U))
  {
    for (uint32_t speed = 0U; speed <= I2C_SPEED_FREQ_FAST_PLUS; speed++)
    {
      if ((p_config->i2c_freq_hz >= i2c_charac[speed].freq_min) \
          && (p_config->i2c_freq_hz <= i2c_charac[speed].freq_max))
      {
        p_advanced_config.clock_src_freq_hz = p_config->clock_src_freq_hz;
        p_advanced_config.i2c_freq_hz       = p_config->i2c_freq_hz;
        p_advanced_config.trise_ns          = i2c_charac[speed].trise_max / 2U;
        p_advanced_config.tfall_ns          = i2c_charac[speed].tfall_max / 2U;
        p_advanced_config.dnf               = i2c_charac[speed].dnf;
        p_advanced_config.af                = STM32_UTILS_I2C_ANALOG_FILTER_ENABLED;

        if (I2C_Compute_PRESC_SCLDEL_SDADEL(&p_advanced_config, speed) != STM32_UTILS_I2C_OK)
        {
          return STM32_UTILS_I2C_ERROR;
        }

        idx = I2C_Compute_SCLL_SCLH(&p_advanced_config, speed);

        if (idx < I2C_VALID_TIMING_NBR_MAX)
        {
          *p_output_timing_reg = ((i2c_valid_timing[idx].presc   & 0x0FUL) << 28U) | \
                                 ((i2c_valid_timing[idx].tscldel & 0x0FUL) << 20U) | \
                                 ((i2c_valid_timing[idx].tsdadel & 0x0FUL) << 16U) | \
                                 ((i2c_valid_timing[idx].sclh    & 0xFFUL) << 8U)  | \
                                 (i2c_valid_timing[idx].scll     & 0xFFUL);

          status = STM32_UTILS_I2C_OK;
        }
        break;
      }
    }
  }

  return status;
}


/**
  * @brief  Compute I2C timing according to the current I2C clock source and required I2C clock.
  * @param  p_config Pointer to a @ref stm32_utils_i2c_timing_advanced_config_t structure that contains
  *         the required parameters for I2C timing computation.
  * @param  p_output_timing_reg Pointer to an I2C_TIMINGR register value computed by referring to the I2C
            initialization section in the Reference Manual. This value is directly computed by STM32CubeMX2.
  * @retval STM32_UTILS_I2C_OK    Timing calculation successful.
  * @retval STM32_UTILS_I2C_ERROR Timing calculation error.
  */
stm32_utils_i2c_status_t STM32_UTILS_I2C_ComputeTimingAdvanced(const stm32_utils_i2c_timing_advanced_config_t *p_config,
                                                               uint32_t *p_output_timing_reg)
{
  stm32_utils_i2c_status_t status = STM32_UTILS_I2C_ERROR;
  uint32_t idx;

  i2c_valid_timing_nbr = 0U;

  if ((p_config->clock_src_freq_hz != 0U) && (p_config->i2c_freq_hz != 0U))
  {
    for (uint32_t speed = 0U; speed <= (uint32_t)I2C_SPEED_FREQ_FAST_PLUS; speed++)
    {
      if ((p_config->i2c_freq_hz >= i2c_charac[speed].freq_min) \
          && (p_config->i2c_freq_hz <= i2c_charac[speed].freq_max))
      {
        if (I2C_Compute_PRESC_SCLDEL_SDADEL(p_config, speed) != STM32_UTILS_I2C_OK)
        {
          return STM32_UTILS_I2C_ERROR;
        }

        idx = I2C_Compute_SCLL_SCLH(p_config, speed);

        if (idx < I2C_VALID_TIMING_NBR_MAX)
        {
          *p_output_timing_reg = ((i2c_valid_timing[idx].presc   & 0x0FUL) << 28U) | \
                                 ((i2c_valid_timing[idx].tscldel & 0x0FUL) << 20U) | \
                                 ((i2c_valid_timing[idx].tsdadel & 0x0FUL) << 16U) | \
                                 ((i2c_valid_timing[idx].sclh    & 0xFFUL) << 8U)  | \
                                 (i2c_valid_timing[idx].scll     & 0xFFUL);

          status = STM32_UTILS_I2C_OK;
        }
        break;
      }
    }
  }

  return status;
}

/**
  * @brief  Compute timeout A using the current I2C clock source, IDLE mode, and timeout requested in ns.
  * @param  p_config Pointer to a @ref stm32_utils_i2c_timeouta_config_t structure containing the desired
  *         timeout parameters.
  * @param  p_output_timeout_reg Pointer to an I2C_TIMEOUTR register value computed.
  *         This value is directly computed by STM32CubeMX2.
  * @note   When IDLE mode is disabled, the timeout value must be between 25000000 ns and 35000000 ns per the SMBUS
  *         specification.
  * @note   When IDLE mode is enabled, the timeout value must be under tIDLE= (0xFFF + 1) x 4 x tI2CCLK.
  * @retval STM32_UTILS_I2C_OK            Timing calculation successful.
  * @retval STM32_UTILS_I2C_INVALID_PARAM Invalid parameter.
  */
stm32_utils_i2c_status_t STM32_UTILS_I2C_CompTimeoutA(const stm32_utils_i2c_timeouta_config_t *p_config,
                                                      uint32_t *p_output_timeout_reg)
{
  double_t ti2cclk;
  double_t timeout_reg;
  stm32_utils_i2c_status_t status = STM32_UTILS_I2C_INVALID_PARAM;

  if (p_config != NULL)
  {
    if (p_config->clock_src_freq_hz != 0U)
    {
      uint32_t timeout_ns = p_config->timeout_ns;
      ti2cclk = (double_t)SEC2NSEC / (double_t)p_config->clock_src_freq_hz;
      if (ti2cclk > 0.0)
      {
        if (p_config->timeouta_mode == STM32_UTILS_I2C_TIMEOUTA_SDA_SCL_HIGH)
        {
          /* Compute the p_output_timeout_reg value based on Reference manual formula:
             tIDLE= (TIMEOUTA + 1) x 4 x tI2CCLK */
          timeout_reg = DIV_ROUND_CLOSEST((double_t)timeout_ns, (ti2cclk * 4.0)) - 1.0;
          *p_output_timeout_reg = (uint32_t)timeout_reg;
          if (*p_output_timeout_reg <= 0xFFFU)
          {
            status = STM32_UTILS_I2C_OK;
          }
        }
        else
        {
          if ((timeout_ns <= SMBUS_IDLE_TIMEOUT_MAX) && (timeout_ns >= SMBUS_IDLE_TIMEOUT_MIN))
          {
            /* Compute the p_output_timeout_reg value based on Reference manual formula:
               tTIMEOUT= (TIMEOUTA + 1) x 2048 x tI2CCLK */
            timeout_reg = DIV_ROUND_CLOSEST((double_t)timeout_ns, (ti2cclk * 2048.0)) - 1.0;
            *p_output_timeout_reg = (uint32_t)timeout_reg;

            status = STM32_UTILS_I2C_OK;
          }
        }
      }
    }
  }
  return status;
}

/**
  * @brief  Compute timeout B using the current I2C clock source, device mode, and timeout requested in ns.
  * @param  p_config Pointer to a @ref stm32_utils_i2c_timeoutb_config_t structure containing the desired
  *         timeout parameters.
  * @param  p_output_timeout_reg Pointer to an I2C_TIMEOUTR register value computed.
  *         This value is directly computed by STM32CubeMX2.
  * @retval STM32_UTILS_I2C_OK            Timing calculation successful.
  * @retval STM32_UTILS_I2C_INVALID_PARAM Invalid parameter.
  */
stm32_utils_i2c_status_t STM32_UTILS_I2C_CompTimeoutB(const stm32_utils_i2c_timeoutb_config_t *p_config,
                                                      uint32_t *p_output_timeout_reg)
{
  double_t ti2cclk;
  double_t timeout_reg;
  stm32_utils_i2c_status_t status = STM32_UTILS_I2C_INVALID_PARAM;
  if (p_config != NULL)
  {
    if (p_config->clock_src_freq_hz != 0U)
    {
      uint32_t timeout_ns = p_config->timeout_ns;
      ti2cclk = (double_t)SEC2NSEC / (double_t)p_config->clock_src_freq_hz;
      if (ti2cclk > 0.0)
      {
        if (p_config->device_mode == STM32_UTILS_I2C_SLAVE_MODE)
        {
          if (timeout_ns <= SMBUS_SLAVE_EXT_LOW_TIMEOUT_MAX)
          {
            /* Compute the p_output_timeout_reg value based on Reference manual formula:
               tLOW:SEXT= (TIMEOUTB + 1) x 2048 x tI2CCLK */
            timeout_reg = DIV_ROUND_CLOSEST((double_t)timeout_ns, (ti2cclk * 2048.0)) - 1.0;
            *p_output_timeout_reg = (uint32_t)timeout_reg;

            status = STM32_UTILS_I2C_OK;
          }
        }
        else
        {
          if (timeout_ns <= SMBUS_MASTER_EXT_LOW_TIMEOUT_MAX)
          {
            /* Compute the p_output_timeout_reg value based on Reference manual formula:
               tLOW:MEXT= (TIMEOUTB + 1) x 2048 x tI2CCLK */
            timeout_reg = DIV_ROUND_CLOSEST((double_t)timeout_ns, (ti2cclk * 2048.0)) - 1.0;
            *p_output_timeout_reg = (uint32_t)timeout_reg;

            status = STM32_UTILS_I2C_OK;
          }
        }
      }
    }
  }
  return status;
}

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Compute PRESC, SCLDEL, and SDADEL.
  * @param  p_config Pointer to a @ref stm32_utils_i2c_timing_advanced_config_t structure containing the timing
  *         configuration parameters.
  * @param  i2c_speed I2C frequency (index).
  * @retval STM32_UTILS_I2C_OK    Timing calculation successful.
  * @retval STM32_UTILS_I2C_ERROR Timing calculation error.
  */
static stm32_utils_i2c_status_t I2C_Compute_PRESC_SCLDEL_SDADEL(const stm32_utils_i2c_timing_advanced_config_t
                                                                *p_config,
                                                                uint32_t i2c_speed)
{
  stm32_utils_i2c_status_t status = STM32_UTILS_I2C_ERROR;
  uint32_t prev_presc = I2C_PRESC_MAX;
  double_t ti2cclk;
  double_t tsdadel_min;
  double_t tsdadel_max;
  double_t tscldel_min;
  double_t tafdel_min;
  double_t tafdel_max;

  ti2cclk = (double_t)SEC2NSEC / (double_t)p_config->clock_src_freq_hz;

  tafdel_min = (p_config->af == STM32_UTILS_I2C_ANALOG_FILTER_ENABLED) ? I2C_ANALOG_FILTER_DELAY_MIN : 0.0;
  tafdel_max = (p_config->af == STM32_UTILS_I2C_ANALOG_FILTER_ENABLED) ? I2C_ANALOG_FILTER_DELAY_MAX : 0.0;

  /**
    * tDNF = DNF x tI2CCLK
    * tPRESC = (PRESC+1) x tI2CCLK
    * SDADEL >= {tf +tHD;DAT(min) - tAF(min) - tDNF - [3 x tI2CCLK]} / {tPRESC}
    * SDADEL <= {tVD;DAT(max) - tr - tAF(max) - tDNF- [4 x tI2CCLK]} / {tPRESC}.
    */

  tsdadel_min = (double_t)p_config->tfall_ns + (double_t)i2c_charac[i2c_speed].hddat_min -
                tafdel_min - (((double_t)p_config->dnf + 3.0) * ti2cclk);

  tsdadel_max = (double_t)i2c_charac[i2c_speed].vddat_max - (double_t)p_config->trise_ns -
                tafdel_max - (((double_t)p_config->dnf + 4.0) * ti2cclk);


  /* {[tr+ tSU;DAT(min)] / [tPRESC]} - 1 <= SCLDEL */
  tscldel_min = (double_t)p_config->trise_ns + (double_t)i2c_charac[i2c_speed].sudat_min;

  if (tsdadel_min <= 0.0)
  {
    tsdadel_min = 0.0;
  }

  if (tsdadel_max <= 0.0)
  {
    tsdadel_max = 0.0;
  }

  for (uint32_t presc = 0U; presc < I2C_PRESC_MAX; presc++)
  {
    for (uint32_t scldel = 0U; scldel < I2C_SCLDEL_MAX; scldel++)
    {
      /* TSCLDEL = (SCLDEL+1) * (PRESC + 1) * TI2CCLK */
      double_t tscldel = ((double_t)scldel + 1.0) * ((double_t)presc + 1.0) * ti2cclk;

      if (tscldel >= tscldel_min)
      {
        for (uint32_t sdadel = 0U; sdadel < I2C_SDADEL_MAX; sdadel++)
        {
          /* TSDADEL = SDADEL * (PRESC + 1) * TI2CCLK */
          double_t tsdadel = ((double_t)sdadel * ((double_t)presc + 1.0)) * ti2cclk;

          if ((tsdadel >= tsdadel_min) && (tsdadel <= tsdadel_max))
          {
            if (presc != prev_presc)
            {
              i2c_valid_timing[i2c_valid_timing_nbr].presc   = presc;
              i2c_valid_timing[i2c_valid_timing_nbr].tscldel = scldel;
              i2c_valid_timing[i2c_valid_timing_nbr].tsdadel = sdadel;
              prev_presc                                     = presc;

              i2c_valid_timing_nbr ++;

              if (i2c_valid_timing_nbr >= I2C_VALID_TIMING_NBR_MAX)
              {
                return STM32_UTILS_I2C_ERROR;
              }
              else
              {
                status = STM32_UTILS_I2C_OK;
              }
            }
          }
        }
      }
    }
  }

  return status;
}

/**
  * @brief  Calculate SCLL and SCLH and find the best configuration.
  * @param  p_config Pointer to a @ref stm32_utils_i2c_timing_advanced_config_t structure containing the timing
  *         configuration parameters.
  * @param  i2c_speed I2C frequency (index).
  * @retval Configuration index (0 to I2C_VALID_TIMING_NBR_MAX), 0xAAAAAAAAU for no valid configuration.
  */
static uint32_t I2C_Compute_SCLL_SCLH(const stm32_utils_i2c_timing_advanced_config_t *p_config, uint32_t i2c_speed)
{
  uint32_t ret = 0xAAAAAAAAU;
  double_t ti2cclk;
  double_t ti2cspeed;
  double_t prev_error;
  double_t dnf_delay;
  double_t clk_min;
  double_t clk_max;
  double_t tafdel_min;
  uint32_t tmp;

  tmp = SEC2NSEC / p_config->clock_src_freq_hz;
  ti2cclk = (double_t)tmp;
  tmp = SEC2NSEC / p_config->i2c_freq_hz;
  ti2cspeed = (double_t)tmp;

  tafdel_min = (p_config->af == STM32_UTILS_I2C_ANALOG_FILTER_ENABLED) ? I2C_ANALOG_FILTER_DELAY_MIN : 0.0;

  /* tDNF = DNF x tI2CCLK */
  dnf_delay = (double_t)p_config->dnf * ti2cclk;

  tmp = SEC2NSEC / i2c_charac[i2c_speed].freq_min;
  clk_max = (double_t)tmp;
  tmp = SEC2NSEC / i2c_charac[i2c_speed].freq_max;
  clk_min = (double_t)tmp;

  prev_error = ti2cspeed;

  for (uint32_t count = 0U; count < i2c_valid_timing_nbr; count++)
  {
    /* tPRESC = (PRESC+1) x tI2CCLK*/
    double_t tpresc = ((double_t)i2c_valid_timing[count].presc + 1.0) * ti2cclk;

    for (uint32_t scll = 0U; scll < I2C_SCLL_MAX; scll++)
    {
      /* tLOW(min) <= tAF(min) + tDNF + 2 x tI2CCLK + [(SCLL + 1) x tPRESC ] */
      double_t tscl_l = tafdel_min + dnf_delay + (2.0 * ti2cclk) + (((double_t)scll + 1.0) * tpresc);

      /* The I2CCLK period tI2CCLK must respect the following conditions:
      tI2CCLK < (tLOW - tfilters) / 4 and tI2CCLK < tHIGH */
      if ((tscl_l > (double_t)i2c_charac[i2c_speed].lscl_min) && (ti2cclk < ((tscl_l - tafdel_min - dnf_delay) / 4.0)))
      {
        for (uint32_t sclh = 0U; sclh < I2C_SCLH_MAX; sclh++)
        {
          /* tHIGH(min) <= tAF(min) + tDNF + 2 x tI2CCLK + [(SCLH + 1) x tPRESC] */
          double_t tscl_h = tafdel_min + dnf_delay + (2.0 * ti2cclk) + (((double_t)sclh + 1.0) * tpresc);

          /* tSCL = tf + tLOW + tr + tHIGH */
          double_t tscl = tscl_l + tscl_h + (double_t)p_config->trise_ns + (double_t)p_config->tfall_ns;

          if ((tscl >= clk_min) && (tscl <= clk_max) && (tscl_h >= (double_t)i2c_charac[i2c_speed].hscl_min)
              && (ti2cclk < tscl_h))
          {
            double_t error = tscl - ti2cspeed;

            if (error < 0.0)
            {
              error = -error;
            }

            /* look for the timings with the lowest clock error */
            if (error < prev_error)
            {
              prev_error                   = error;
              i2c_valid_timing[count].scll = scll;
              i2c_valid_timing[count].sclh = sclh;
              ret                          = count;
            }
          }
        }
      }
    }
  }

  return ret;
}

/**
  * @}
  */

/**
  * @}
  */
