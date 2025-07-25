/*
 *******************************************************************************
 * Copyright (c) 2016-2021, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#include "analog.h"
#include "lock_resource.h"
#include "stm32yyxx_ll_adc.h"
#include "PinAF_STM32F1.h"


#ifdef __cplusplus
extern "C" {
#endif


/* Private_Variables */
#if (defined(HAL_ADC_MODULE_ENABLED) && !defined(HAL_ADC_MODULE_ONLY)) ||\
    (defined(HAL_DAC_MODULE_ENABLED) && !defined(HAL_DAC_MODULE_ONLY))
static PinName g_current_pin = NC;
#endif

/* Private_Defines */
#if defined(HAL_ADC_MODULE_ENABLED) && !defined(HAL_ADC_MODULE_ONLY)

#if defined(STM32WB0x)
#ifndef ADC_SAMPLING_RATE
#define ADC_SAMPLING_RATE           ADC_SAMPLE_RATE_16
#endif /* !ADC_SAMPLING_RATE */
#ifndef ADC_SAMPLING_RATE_INTERNAL
#define ADC_SAMPLING_RATE_INTERNAL  ADC_SAMPLE_RATE_16
#endif /* !ADC_SAMPLING_RATE_INTERNAL */
#ifndef ADC_VOLT_RANGE
#define ADC_VOLT_RANGE              ADC_VIN_RANGE_3V6
#endif /* !ADC_VOLT_RANGE */
#else
#ifndef ADC_SAMPLINGTIME
#if defined(ADC_SAMPLETIME_8CYCLES_5)
#define ADC_SAMPLINGTIME        ADC_SAMPLETIME_8CYCLES_5
#elif defined(ADC_SAMPLETIME_11CYCLES_5)
#define ADC_SAMPLINGTIME        ADC_SAMPLETIME_11CYCLES_5
#elif defined(ADC_SAMPLETIME_12CYCLES)
#define ADC_SAMPLINGTIME        ADC_SAMPLETIME_12CYCLES;
#elif defined(ADC_SAMPLETIME_12CYCLES_5)
#define ADC_SAMPLINGTIME        ADC_SAMPLETIME_12CYCLES_5
#elif defined(ADC_SAMPLETIME_13CYCLES_5)
#define ADC_SAMPLINGTIME        ADC_SAMPLETIME_13CYCLES_5
#elif defined(ADC_SAMPLETIME_15CYCLES)
#define ADC_SAMPLINGTIME        ADC_SAMPLETIME_15CYCLES
#elif defined(ADC_SAMPLETIME_16CYCLES)
#define ADC_SAMPLINGTIME        ADC_SAMPLETIME_16CYCLES
#elif defined(ADC_SAMPLETIME_19CYCLES_5)
#define ADC_SAMPLINGTIME        ADC_SAMPLETIME_19CYCLES_5
#endif
#endif /* !ADC_SAMPLINGTIME */

#if defined(ADC_VER_V5_V90) && !defined(ADC3_SAMPLINGTIME)
#define ADC3_SAMPLINGTIME       ADC3_SAMPLETIME_24CYCLES_5
#endif

#if defined(ADC4_SAMPLETIME_19CYCLES_5) && !defined(ADC4_SAMPLINGTIME)
#define ADC4_SAMPLINGTIME       ADC4_SAMPLETIME_19CYCLES_5
#endif

/*
 * Minimum ADC sampling time is required when reading
 * internal channels so set it to max possible value.
 * It can be defined more precisely by defining:
 * ADC_SAMPLINGTIME_INTERNAL
 * to the desired ADC sample time.
 */
#ifndef ADC_SAMPLINGTIME_INTERNAL
#if defined(ADC_SAMPLETIME_480CYCLES)
#define ADC_SAMPLINGTIME_INTERNAL ADC_SAMPLETIME_480CYCLES
#elif defined(ADC_SAMPLETIME_384CYCLES)
#define ADC_SAMPLINGTIME_INTERNAL ADC_SAMPLETIME_384CYCLES
#elif defined(ADC_SAMPLETIME_810CYCLES_5)
#define ADC_SAMPLINGTIME_INTERNAL ADC_SAMPLETIME_810CYCLES_5
#elif defined(ADC_SAMPLETIME_814CYCLES)
#define ADC_SAMPLINGTIME_INTERNAL ADC_SAMPLETIME_814CYCLES
#elif defined(ADC_SAMPLETIME_640CYCLES_5)
#define ADC_SAMPLINGTIME_INTERNAL ADC_SAMPLETIME_640CYCLES_5
#elif defined(ADC_SAMPLETIME_601CYCLES_5)
#define ADC_SAMPLINGTIME_INTERNAL ADC_SAMPLETIME_601CYCLES_5
#elif defined(ADC_SAMPLETIME_247CYCLES_5)
#define ADC_SAMPLINGTIME_INTERNAL ADC_SAMPLETIME_247CYCLES_5
#elif defined(ADC_SAMPLETIME_239CYCLES_5)
#define ADC_SAMPLINGTIME_INTERNAL ADC_SAMPLETIME_239CYCLES_5
#elif defined(ADC_SAMPLETIME_160CYCLES_5)
#define ADC_SAMPLINGTIME_INTERNAL ADC_SAMPLETIME_160CYCLES_5
#elif defined(ADC_SAMPLETIME_814CYCLES_5)
#define ADC_SAMPLINGTIME_INTERNAL ADC_SAMPLETIME_814CYCLES_5
#elif defined(ADC_SAMPLETIME_1499CYCLES_5)
#define ADC_SAMPLINGTIME_INTERNAL ADC_SAMPLETIME_1499CYCLES_5
#else
#error "ADC sampling time could not be defined for internal channels!"
#endif
#endif /* !ADC_SAMPLINGTIME_INTERNAL */

#ifndef ADC_CLOCK_DIV
#ifdef ADC_CLOCK_SYNC_PCLK_DIV4
#define ADC_CLOCK_DIV       ADC_CLOCK_SYNC_PCLK_DIV4
#elif ADC_CLOCK_SYNC_PCLK_DIV2
#define ADC_CLOCK_DIV       ADC_CLOCK_SYNC_PCLK_DIV2
#elif defined(ADC_CLOCK_ASYNC_DIV4)
#define ADC_CLOCK_DIV       ADC_CLOCK_ASYNC_DIV4
#endif
#endif /* !ADC_CLOCK_DIV */

#ifndef ADC_REGULAR_RANK_1
#define ADC_REGULAR_RANK_1  1
#endif
#endif /* STM32WB0x */

/* Exported Functions */
/**
  * @brief  Return ADC HAL channel linked to a PinName
  * @param  pin: PinName
  * @param  bank: pointer to get ADC channel bank if required
  * @retval Valid HAL channel
  */
uint32_t get_adc_channel(PinName pin, uint32_t *bank)
{
  uint32_t function = pinmap_function(pin, PinMap_ADC);
  uint32_t channel = 0;
  switch (STM_PIN_CHANNEL(function)) {
#ifdef ADC_CHANNEL_VINP0
    case 0:
      channel = ADC_CHANNEL_VINP0;
      break;
    case 1:
      channel = ADC_CHANNEL_VINP1;
      break;
    case 2:
      channel = ADC_CHANNEL_VINP2;
      break;
    case 3:
      channel = ADC_CHANNEL_VINP3;
      break;
#else
#ifdef ADC_CHANNEL_0
    case 0:
      channel = ADC_CHANNEL_0;
      break;
#endif
    case 1:
      channel = ADC_CHANNEL_1;
      break;
    case 2:
      channel = ADC_CHANNEL_2;
      break;
    case 3:
      channel = ADC_CHANNEL_3;
      break;
    case 4:
      channel = ADC_CHANNEL_4;
      break;
    case 5:
      channel = ADC_CHANNEL_5;
      break;
    case 6:
      channel = ADC_CHANNEL_6;
      break;
    case 7:
      channel = ADC_CHANNEL_7;
      break;
    case 8:
      channel = ADC_CHANNEL_8;
      break;
    case 9:
      channel = ADC_CHANNEL_9;
      break;
    case 10:
      channel = ADC_CHANNEL_10;
      break;
    case 11:
      channel = ADC_CHANNEL_11;
      break;
    case 12:
      channel = ADC_CHANNEL_12;
      break;
    case 13:
      channel = ADC_CHANNEL_13;
      break;
#ifdef ADC_CHANNEL_14
    case 14:
      channel = ADC_CHANNEL_14;
      break;
    case 15:
      channel = ADC_CHANNEL_15;
      break;
#ifdef ADC_CHANNEL_16
    case 16:
      channel = ADC_CHANNEL_16;
      break;
#endif
    case 17:
      channel = ADC_CHANNEL_17;
      break;
#ifdef ADC_CHANNEL_18
    case 18:
      channel = ADC_CHANNEL_18;
      break;
#endif
#ifdef ADC_CHANNEL_19
    case 19:
      channel = ADC_CHANNEL_19;
      break;
#endif
#ifdef ADC_CHANNEL_20
    case 20:
      channel = ADC_CHANNEL_20;
      break;
    case 21:
      channel = ADC_CHANNEL_21;
      break;
    case 22:
      channel = ADC_CHANNEL_22;
      break;
#ifdef ADC_CHANNEL_23
    case 23:
      channel = ADC_CHANNEL_23;
      break;
#ifdef ADC_CHANNEL_24
    case 24:
      channel = ADC_CHANNEL_24;
      break;
    case 25:
      channel = ADC_CHANNEL_25;
      break;
    case 26:
      channel = ADC_CHANNEL_26;
      break;
#ifdef ADC_CHANNEL_27
    case 27:
      channel = ADC_CHANNEL_27;
      break;
    case 28:
      channel = ADC_CHANNEL_28;
      break;
    case 29:
      channel = ADC_CHANNEL_29;
      break;
    case 30:
      channel = ADC_CHANNEL_30;
      break;
    case 31:
      channel = ADC_CHANNEL_31;
      break;
#endif /* ADC_CHANNEL_27 */
#endif /* ADC_CHANNEL_24 */
#endif /* ADC_CHANNEL_23 */
#endif /* ADC_CHANNEL_20 */
#endif /* ADC_CHANNEL_14 */
#endif /* ADC_CHANNEL_VINP0 */
    default:
      _Error_Handler("ADC: Unknown adc channel", (int)(STM_PIN_CHANNEL(function)));
      break;
  }
#ifdef ADC_CHANNELS_BANK_B
  if (STM_PIN_ANALOG_CHANNEL_BANK_B(function)) {
    *bank = ADC_CHANNELS_BANK_B;
  } else {
    *bank = ADC_CHANNELS_BANK_A;
  }
#else
  UNUSED(bank);
#endif
  return channel;
}

/**
  * @brief  Return ADC HAL internal channel linked to a PinName
  * @param  pin: specific PinName's for ADC internal. Value can be:
  *         PADC_TEMP, PADC_TEMP_ADC5, PADC_VREF, PADC_VBAT
  *         Note that not all of these values ​​may be available for all series.
  * @retval Valid HAL internal channel.
  */
uint32_t get_adc_internal_channel(PinName pin)
{
  uint32_t channel = 0;
  switch (pin) {
#if defined(ADC_CHANNEL_TEMPSENSOR)
    case PADC_TEMP:
      channel = ADC_CHANNEL_TEMPSENSOR;
      break;
#endif
#if defined(ADC_CHANNEL_TEMPSENSOR_ADC1)
    case PADC_TEMP:
      channel = ADC_CHANNEL_TEMPSENSOR_ADC1;
      break;
#endif
#if defined(ADC5) && defined(ADC_CHANNEL_TEMPSENSOR_ADC5)
    case PADC_TEMP_ADC5:
      channel = ADC_CHANNEL_TEMPSENSOR_ADC5;
      break;
#endif
#ifdef ADC_CHANNEL_VREFINT
    case PADC_VREF:
      channel = ADC_CHANNEL_VREFINT;
      break;
#endif
#ifdef ADC_CHANNEL_VBAT
    case PADC_VBAT:
      channel = ADC_CHANNEL_VBAT;
      break;
#endif
    default:
      _Error_Handler("ADC: Unknown adc internal PiName", (int)(pin));
      break;
  }
  return channel;
}
#endif /* HAL_ADC_MODULE_ENABLED && !HAL_ADC_MODULE_ONLY */

#if defined(HAL_DAC_MODULE_ENABLED) && !defined(HAL_DAC_MODULE_ONLY)
/**
  * @brief  Return DAC HAL channel linked to a PinName
  * @param  pin: specific PinName's for ADC internal.
  * @retval Valid HAL channel
  */
uint32_t get_dac_channel(PinName pin)
{
  uint32_t function = pinmap_function(pin, PinMap_DAC);
  uint32_t channel = 0;
  switch (STM_PIN_CHANNEL(function)) {
#ifdef DAC_CHANNEL_0
    case 0:
      channel = DAC_CHANNEL_0;
      break;
#endif
    case 1:
      channel = DAC_CHANNEL_1;
      break;
#ifdef DAC_CHANNEL_2
    case 2:
      channel = DAC_CHANNEL_2;
      break;
#endif
    default:
      _Error_Handler("DAC: Unknown dac channel", (int)(STM_PIN_CHANNEL(function)));
      break;
  }
  return channel;
}

////////////////////////// DAC INTERFACE FUNCTIONS /////////////////////////////

/**
  * @brief DAC MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  * @param hdac: DAC handle pointer
  * @retval None
  */
void HAL_DAC_MspInit(DAC_HandleTypeDef *hdac)
{
  /* DAC Periph clock enable */
  if (hdac->Instance == DAC1) {
#ifdef __HAL_RCC_DAC_CLK_ENABLE
    __HAL_RCC_DAC_CLK_ENABLE();
#endif
#ifdef __HAL_RCC_DAC1_CLK_ENABLE
    __HAL_RCC_DAC1_CLK_ENABLE();
#endif
#ifdef __HAL_RCC_DAC12_CLK_ENABLE
    __HAL_RCC_DAC12_CLK_ENABLE();
#endif
  }
#ifdef DAC2
  else if (hdac->Instance == DAC2) {
#ifdef __HAL_RCC_DAC2_CLK_ENABLE
    __HAL_RCC_DAC2_CLK_ENABLE();
#endif
#ifdef __HAL_RCC_DAC12_CLK_ENABLE
    __HAL_RCC_DAC12_CLK_ENABLE();
#endif
  }
#endif
#ifdef DAC3
  else if (hdac->Instance == DAC3) {
#ifdef __HAL_RCC_DAC3_CLK_ENABLE
    __HAL_RCC_DAC3_CLK_ENABLE();
#endif
  }
#endif
#ifdef DAC4
  else if (hdac->Instance == DAC4) {
#ifdef __HAL_RCC_DAC4_CLK_ENABLE
    __HAL_RCC_DAC4_CLK_ENABLE();
#endif
  }
#endif

  /* Configure DAC GPIO pins */
  pinmap_pinout(g_current_pin, PinMap_DAC);
}


/**
  * @brief  This function will set the DAC to the required value
  * @param  port : the gpio port to use
  * @param  pin : the gpio pin to use
  * @param  value : the value to push on the adc output
  * @param  do_init : if set to 1 the initialization of the adc is done
  * @retval None
  */
void dac_write_value(PinName pin, uint32_t value, uint8_t do_init)
{
  DAC_HandleTypeDef DacHandle = {};
  DAC_ChannelConfTypeDef dacChannelConf = {};
  uint32_t dacChannel;

  DacHandle.Instance = (DAC_TypeDef *)pinmap_peripheral(pin, PinMap_DAC);
  if (DacHandle.Instance == NP) {
    return;
  }
  dacChannel = get_dac_channel(pin);
#if defined(STM32G4xx)
  if (!IS_DAC_CHANNEL(DacHandle.Instance, dacChannel)) {
#else
  if (!IS_DAC_CHANNEL(dacChannel)) {
#endif
    return;
  }
  if (do_init == 1) {
    /*##-1- Configure the DAC peripheral #######################################*/
    g_current_pin = pin;
    if (HAL_DAC_Init(&DacHandle) != HAL_OK) {
      /* Initialization Error */
      return;
    }

    dacChannelConf.DAC_Trigger = DAC_TRIGGER_NONE;
#if defined(DISABLE_DAC_OUTPUTBUFFER)
    dacChannelConf.DAC_OutputBuffer = DAC_OUTPUTBUFFER_DISABLE;
#else
    dacChannelConf.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
#endif
#if defined(DAC_OUTPUTSWITCH_ENABLE)
    dacChannelConf.DAC_OutputSwitch = DAC_OUTPUTSWITCH_ENABLE;
#endif
    /*##-2- Configure DAC channel1 #############################################*/
#if defined(STM32H5xx) && !defined(TIM8) && !defined(HAL_ICACHE_MODULE_DISABLED)
    bool icache_enabled = false;
    if (HAL_ICACHE_IsEnabled() == 1) {
      icache_enabled = true;
      /* Disable instruction cache prior to internal cacheable memory update */
      if (HAL_ICACHE_Disable() != HAL_OK) {
        Error_Handler();
      }
    }
#endif /* STM32H5xx && !defined(TIM8) &&!HAL_ICACHE_MODULE_DISABLED */
    if (HAL_DAC_ConfigChannel(&DacHandle, &dacChannelConf, dacChannel) != HAL_OK) {
      /* Channel configuration Error */
      return;
    }
#if defined(STM32H5xx) && !defined(TIM8) && !defined(HAL_ICACHE_MODULE_DISABLED)
    if (icache_enabled) {
      /* Re-enable instruction cache */
      if (HAL_ICACHE_Enable() != HAL_OK) {
        Error_Handler();
      }
    }
#endif /* STM32H5xx && !defined(TIM8) && !HAL_ICACHE_MODULE_DISABLED */
  }

  /*##-3- Set DAC Channel1 DHR register ######################################*/
  if (HAL_DAC_SetValue(&DacHandle, dacChannel, DAC_ALIGN_12B_R, value) != HAL_OK) {
    /* Setting value Error */
    return;
  }

  /*##-4- Enable DAC Channel1 ################################################*/
  HAL_DAC_Start(&DacHandle, dacChannel);
}

/**
  * @brief  DeInitialize the DAC MSP.
  * @param  hdac: pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @retval None
  */
void HAL_DAC_MspDeInit(DAC_HandleTypeDef *hdac)
{
  /* DAC Periph clock disable */
  if (hdac->Instance == DAC1) {
#ifdef __HAL_RCC_DAC_FORCE_RESET
    __HAL_RCC_DAC_FORCE_RESET();
#endif
#ifdef __HAL_RCC_DAC1_FORCE_RESET
    __HAL_RCC_DAC1_FORCE_RESET();
#endif
#ifdef __HAL_RCC_DAC12_FORCE_RESET
    __HAL_RCC_DAC12_FORCE_RESET();
#endif
#ifdef __HAL_RCC_DAC_RELEASE_RESET
    __HAL_RCC_DAC_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_DAC1_RELEASE_RESET
    __HAL_RCC_DAC1_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_DAC12_RELEASE_RESET
    __HAL_RCC_DAC12_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_DAC_CLK_DISABLE
    __HAL_RCC_DAC_CLK_DISABLE();
#endif
#ifdef __HAL_RCC_DAC1_CLK_DISABLE
    __HAL_RCC_DAC1_CLK_DISABLE();
#endif
#ifdef __HAL_RCC_DAC12_CLK_ENABLE
    __HAL_RCC_DAC12_CLK_ENABLE();
#endif
  }
#ifdef DAC2
  else if (hdac->Instance == DAC2) {
#ifdef __HAL_RCC_DAC2_FORCE_RESET
    __HAL_RCC_DAC2_FORCE_RESET();
#endif
#ifdef __HAL_RCC_DAC12_FORCE_RESET
    __HAL_RCC_DAC12_FORCE_RESET();
#endif
#ifdef __HAL_RCC_DAC2_RELEASE_RESET
    __HAL_RCC_DAC2_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_DAC12_RELEASE_RESET
    __HAL_RCC_DAC12_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_DAC2_CLK_ENABLE
    __HAL_RCC_DAC2_CLK_ENABLE();
#endif
#ifdef __HAL_RCC_DAC12_CLK_ENABLE
    __HAL_RCC_DAC12_CLK_ENABLE();
#endif
  }
#endif
#ifdef DAC3
  else if (hdac->Instance == DAC3) {
#ifdef __HAL_RCC_DAC3_FORCE_RESET
    __HAL_RCC_DAC3_FORCE_RESET();
#endif
#ifdef __HAL_RCC_DAC3_RELEASE_RESET
    __HAL_RCC_DAC3_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_DAC3_CLK_DISABLE
    __HAL_RCC_DAC3_CLK_DISABLE();
#endif
  }
#endif
#ifdef DAC4
  else if (hdac->Instance == DAC4) {
#ifdef __HAL_RCC_DAC4_FORCE_RESET
    __HAL_RCC_DAC4_FORCE_RESET();
#endif
#ifdef __HAL_RCC_DAC4_RELEASE_RESET
    __HAL_RCC_DAC4_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_DAC4_CLK_DISABLE
    __HAL_RCC_DAC4_CLK_DISABLE();
#endif
  }
#endif
}

/**
  * @brief  This function will stop the DAC
  * @param  port : the gpio port to use
  * @param  pin : the gpio pin to use
  * @retval None
  */
void dac_stop(PinName pin)
{
  DAC_HandleTypeDef DacHandle;
  uint32_t dacChannel;

  DacHandle.Instance = (DAC_TypeDef *)pinmap_peripheral(pin, PinMap_DAC);
  if (DacHandle.Instance == NP) {
    return;
  }
  dacChannel = get_dac_channel(pin);
#if defined(STM32G4xx)
  if (!IS_DAC_CHANNEL(DacHandle.Instance, dacChannel)) {
#else
  if (!IS_DAC_CHANNEL(dacChannel)) {
#endif
    return;
  }

  HAL_DAC_Stop(&DacHandle, dacChannel);

  if (HAL_DAC_DeInit(&DacHandle) != HAL_OK) {
    /* DeInitialization Error */
    return;
  }
}
#endif //HAL_DAC_MODULE_ENABLED && !HAL_DAC_MODULE_ONLY


#if defined(HAL_ADC_MODULE_ENABLED) && !defined(HAL_ADC_MODULE_ONLY)
////////////////////////// ADC INTERFACE FUNCTIONS /////////////////////////////

/**
  * @brief ADC MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  * @param hadc: ADC handle pointer
  * @retval None
  */
void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc)
{
  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* ADC Periph clock enable */
#ifdef ADC1
  if (hadc->Instance == ADC1) {
#ifdef __HAL_RCC_ADCDIG_CLK_ENABLE
    __HAL_RCC_ADCDIG_CLK_ENABLE();
#endif
#ifdef __HAL_RCC_ADCANA_CLK_ENABLE
    __HAL_RCC_ADCANA_CLK_ENABLE();
#endif
#ifdef __HAL_RCC_ADC1_CLK_ENABLE
    __HAL_RCC_ADC1_CLK_ENABLE();
#endif
#ifdef __HAL_RCC_ADC12_CLK_ENABLE
    __HAL_RCC_ADC12_CLK_ENABLE();
#endif
  }
#endif
#ifdef ADC2
  if (hadc->Instance == ADC2) {
#ifdef __HAL_RCC_ADC2_CLK_ENABLE
    __HAL_RCC_ADC2_CLK_ENABLE();
#endif
#ifdef __HAL_RCC_ADC12_CLK_ENABLE
    __HAL_RCC_ADC12_CLK_ENABLE();
#endif
  }
#endif
#ifdef ADC3
  if (hadc->Instance == ADC3) {
#ifdef __HAL_RCC_ADC3_CLK_ENABLE
    __HAL_RCC_ADC3_CLK_ENABLE();
#endif
#ifdef __HAL_RCC_ADC34_CLK_ENABLE
    __HAL_RCC_ADC34_CLK_ENABLE();
#endif
#if defined(ADC345_COMMON)
    __HAL_RCC_ADC345_CLK_ENABLE();
#endif
  }
#endif
#ifdef ADC4
  if (hadc->Instance == ADC4) {
#ifdef __HAL_RCC_ADC4_CLK_ENABLE
    __HAL_RCC_ADC4_CLK_ENABLE();
#endif
#ifdef __HAL_RCC_ADC34_CLK_ENABLE
    __HAL_RCC_ADC34_CLK_ENABLE();
#endif
#if defined(ADC345_COMMON)
    __HAL_RCC_ADC345_CLK_ENABLE();
#endif
  }
#endif
#ifdef ADC5
  if (hadc->Instance == ADC5) {
#if defined(ADC345_COMMON)
    __HAL_RCC_ADC345_CLK_ENABLE();
#endif
  }
#endif
#ifdef __HAL_RCC_ADC_CLK_ENABLE
  __HAL_RCC_ADC_CLK_ENABLE();
#endif
  /* For STM32F1xx, STM32H7xx, and STM32MP1xx ADC prescaler is configured in
     SystemClock_Config (variant.cpp) */
#if defined(__HAL_RCC_ADC_CONFIG) && !defined(STM32F1xx) && \
    !defined(STM32H7xx) && !defined(STM32MP1xx)
  hsem_lock(CFG_HW_RCC_CRRCR_CCIPR_SEMID, HSEM_LOCK_DEFAULT_RETRY);
  /* ADC Periph interface clock configuration */
  __HAL_RCC_ADC_CONFIG(RCC_ADCCLKSOURCE_SYSCLK);
  hsem_unlock(CFG_HW_RCC_CRRCR_CCIPR_SEMID);
#endif

  /* Configure ADC GPIO pin */
  if (!(g_current_pin & PADC_BASE)) {
    pinmap_pinout(g_current_pin, PinMap_ADC);
  }
}

/**
  * @brief  DeInitializes the ADC MSP.
  * @param  hadc: ADC handle
  * @retval None
  */
void HAL_ADC_MspDeInit(ADC_HandleTypeDef *hadc)
{
#ifdef __HAL_RCC_ADC_FORCE_RESET
  __HAL_RCC_ADC_FORCE_RESET();
#endif
#ifdef __HAL_RCC_ADC_RELEASE_RESET
  __HAL_RCC_ADC_RELEASE_RESET();
#endif

#ifdef ADC1
  if (hadc->Instance == ADC1) {
#ifdef __HAL_RCC_ADC1_FORCE_RESET
    __HAL_RCC_ADC1_FORCE_RESET();
#endif
#ifdef __HAL_RCC_ADC1_RELEASE_RESET
    __HAL_RCC_ADC1_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_ADC12_FORCE_RESET
    __HAL_RCC_ADC12_FORCE_RESET();
#endif
#ifdef __HAL_RCC_ADC12_RELEASE_RESET
    __HAL_RCC_ADC12_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_ADC1_CLK_DISABLE
    __HAL_RCC_ADC1_CLK_DISABLE();
#endif
#ifdef __HAL_RCC_ADC12_CLK_DISABLE
    __HAL_RCC_ADC12_CLK_DISABLE();
#endif
#ifdef __HAL_RCC_ADCANA_CLK_DISABLE
    __HAL_RCC_ADCANA_CLK_DISABLE();
#endif
#ifdef __HAL_RCC_ADCDIG_CLK_DISABLE
    __HAL_RCC_ADCDIG_CLK_DISABLE();
#endif
  }
#endif
#ifdef ADC2
  if (hadc->Instance == ADC2) {
#ifdef __HAL_RCC_ADC2_FORCE_RESET
    __HAL_RCC_ADC2_FORCE_RESET();
#endif
#ifdef __HAL_RCC_ADC2_RELEASE_RESET
    __HAL_RCC_ADC2_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_ADC12_FORCE_RESET
    __HAL_RCC_ADC12_FORCE_RESET();
#endif
#ifdef __HAL_RCC_ADC12_RELEASE_RESET
    __HAL_RCC_ADC12_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_ADC2_CLK_DISABLE
    __HAL_RCC_ADC2_CLK_DISABLE();
#endif
#ifdef __HAL_RCC_ADC2_CLK_DISABLE
    __HAL_RCC_ADC2_CLK_DISABLE();
#endif
  }
#endif
#ifdef ADC3
  if (hadc->Instance == ADC3) {
#ifdef __HAL_RCC_ADC3_FORCE_RESET
    __HAL_RCC_ADC3_FORCE_RESET();
#endif
#ifdef __HAL_RCC_ADC3_RELEASE_RESET
    __HAL_RCC_ADC3_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_ADC34_FORCE_RESET
    __HAL_RCC_ADC34_FORCE_RESET();
#endif
#ifdef __HAL_RCC_ADC34_RELEASE_RESET
    __HAL_RCC_ADC34_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_ADC3_CLK_DISABLE
    __HAL_RCC_ADC3_CLK_DISABLE();
#endif
#ifdef __HAL_RCC_ADC34_CLK_DISABLE
    __HAL_RCC_ADC34_CLK_DISABLE();
#endif
#if defined(ADC345_COMMON)
    __HAL_RCC_ADC345_FORCE_RESET();
    __HAL_RCC_ADC345_RELEASE_RESET();
    __HAL_RCC_ADC345_CLK_DISABLE();
#endif
  }
#endif
#ifdef ADC4
  if (hadc->Instance == ADC4) {
#ifdef __HAL_RCC_ADC4_FORCE_RESET
    __HAL_RCC_ADC4_FORCE_RESET();
#endif
#ifdef __HAL_RCC_ADC4_RELEASE_RESET
    __HAL_RCC_ADC4_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_ADC4_CLK_DISABLE
    __HAL_RCC_ADC4_CLK_DISABLE();
#endif
#ifdef __HAL_RCC_ADC34_FORCE_RESET
    __HAL_RCC_ADC34_FORCE_RESET();
#endif
#ifdef __HAL_RCC_ADC34_RELEASE_RESET
    __HAL_RCC_ADC34_RELEASE_RESET();
#endif
#ifdef __HAL_RCC_ADC34_CLK_DISABLE
    __HAL_RCC_ADC34_CLK_DISABLE();
#endif
#if defined(ADC345_COMMON)
    __HAL_RCC_ADC345_FORCE_RESET();
    __HAL_RCC_ADC345_RELEASE_RESET();
    __HAL_RCC_ADC345_CLK_DISABLE();
#endif
  }
#endif
#ifdef ADC5
  if (hadc->Instance == ADC5) {
#if defined(ADC345_COMMON)
    __HAL_RCC_ADC345_FORCE_RESET();
    __HAL_RCC_ADC345_RELEASE_RESET();
    __HAL_RCC_ADC345_CLK_DISABLE();
#endif
  }
#endif
#ifdef __HAL_RCC_ADC_CLK_DISABLE
  __HAL_RCC_ADC_FORCE_RESET();
  __HAL_RCC_ADC_RELEASE_RESET();
  __HAL_RCC_ADC_CLK_DISABLE();
#endif
}

/**
  * @brief  This function will set the ADC to the required value
  * @param  pin : the pin to use
  * @param  resolution : resolution for converted data: 6/8/10/12/14/16
  * @retval the value of the adc
  */
uint16_t adc_read_value(PinName pin, uint32_t resolution)
{
  ADC_HandleTypeDef AdcHandle = {};
  ADC_ChannelConfTypeDef  AdcChannelConf = {};
  __IO uint16_t uhADCxConvertedValue = 0;
#if defined(STM32WB0x)
  uint32_t samplingRate = ADC_SAMPLING_RATE;
  uint32_t voltageRange = ADC_VOLT_RANGE;
#else
  uint32_t samplingTime = ADC_SAMPLINGTIME;
#endif /* STM32WB0x */
  uint32_t channel = 0;
  uint32_t bank = 0;

  if ((pin & PADC_BASE) && (pin < ANA_START)) {
#if defined(STM32H7xx) || defined(STM32MP1xx)
#ifdef ADC3
    AdcHandle.Instance = ADC3;
#else
    AdcHandle.Instance = ADC2;
#endif
#elif defined(STM32WBAxx)
    AdcHandle.Instance = ADC4;
#else
    AdcHandle.Instance = ADC1;
#if defined(ADC5) && defined(ADC_CHANNEL_TEMPSENSOR_ADC5)
    if (pin == PADC_TEMP_ADC5) {
      AdcHandle.Instance = ADC5;
    }
#endif
#endif
    channel = get_adc_internal_channel(pin);
#if defined(STM32WB0x)
    samplingRate = ADC_SAMPLING_RATE_INTERNAL;
    if (channel == ADC_CHANNEL_TEMPSENSOR) {
      voltageRange = ADC_VIN_RANGE_1V2;
    } else if (channel == ADC_CHANNEL_VBAT) {
      voltageRange = ADC_VIN_RANGE_3V6;
    }
#else
    samplingTime = ADC_SAMPLINGTIME_INTERNAL;
#endif /* STM32WB0x */
  } else {
    AdcHandle.Instance = (ADC_TypeDef *)pinmap_peripheral(pin, PinMap_ADC);
    channel = get_adc_channel(pin, &bank);
#if defined(STM32WB0x)

#else
#if defined(ADC_VER_V5_V90)
    if (AdcHandle.Instance == ADC3) {
      samplingTime = ADC3_SAMPLINGTIME;
    }
#endif
#if defined(ADC4_SAMPLINGTIME)
    if (AdcHandle.Instance == ADC4) {
      samplingTime = ADC4_SAMPLINGTIME;
    }
#endif
#endif /* STM32WB0x */
  }

  if (AdcHandle.Instance == NP) {
    return 0;
  }
#if defined(STM32WB0x)
  AdcHandle.Init.ConversionType        = ADC_CONVERSION_WITH_DS;
  AdcHandle.Init.ContinuousConvMode    = DISABLE;
  AdcHandle.Init.SequenceLength        = 1;
  AdcHandle.Init.SamplingMode          = ADC_SAMPLING_AT_START;
  AdcHandle.Init.SampleRate            = samplingRate;
  switch (resolution) {
    case 12:
    default:
      AdcHandle.Init.DownSamplerConfig.DataWidth          = ADC_DS_DATA_WIDTH_12_BIT;
      break;
    case 13:
      AdcHandle.Init.DownSamplerConfig.DataWidth          = ADC_DS_DATA_WIDTH_13_BIT;
      break;
    case 14:
      AdcHandle.Init.DownSamplerConfig.DataWidth          = ADC_DS_DATA_WIDTH_14_BIT;
      break;
    case 15:
      AdcHandle.Init.DownSamplerConfig.DataWidth          = ADC_DS_DATA_WIDTH_15_BIT;
      break;
    case 16:
      AdcHandle.Init.DownSamplerConfig.DataWidth          = ADC_DS_DATA_WIDTH_16_BIT;
      break;
  }
  AdcHandle.Init.DownSamplerConfig.DataRatio = ADC_DS_RATIO_8;
  AdcHandle.Init.InvertOutputMode      = ADC_DATA_INVERT_NONE;
  AdcHandle.Init.Overrun               = ADC_NEW_DATA_IS_LOST;
#else
#ifdef ADC_CLOCK_DIV
  AdcHandle.Init.ClockPrescaler        = ADC_CLOCK_DIV;                 /* (A)synchronous clock mode, input ADC clock divided */
#endif
#ifdef ADC_RESOLUTION_12B
  switch (resolution) {
#ifdef ADC_RESOLUTION_6B
    case 6:
      AdcHandle.Init.Resolution          = ADC_RESOLUTION_6B;             /* resolution for converted data */
      break;
#endif
    case 8:
      AdcHandle.Init.Resolution          = ADC_RESOLUTION_8B;             /* resolution for converted data */
      break;
    case 10:
      AdcHandle.Init.Resolution          = ADC_RESOLUTION_10B;            /* resolution for converted data */
      break;
    case 12:
    default:
      AdcHandle.Init.Resolution          = ADC_RESOLUTION_12B;            /* resolution for converted data */
      break;
#ifdef ADC_RESOLUTION_14B
    case 14:
      AdcHandle.Init.Resolution          = ADC_RESOLUTION_14B;            /* resolution for converted data */
      break;
#endif
#ifdef ADC_RESOLUTION_16B
    case 16:
      AdcHandle.Init.Resolution          = ADC_RESOLUTION_16B;            /* resolution for converted data */
      break;
#endif
  }
#else
  UNUSED(resolution);
#endif
#ifdef ADC_DATAALIGN_RIGHT
  AdcHandle.Init.DataAlign             = ADC_DATAALIGN_RIGHT;           /* Right-alignment for converted data */
#endif
#ifdef ADC_SCAN_SEQ_FIXED
  AdcHandle.Init.ScanConvMode          = ADC_SCAN_SEQ_FIXED;            /* Sequencer disabled (ADC conversion on only 1 channel: channel set on rank 1) */
#else
  AdcHandle.Init.ScanConvMode          = DISABLE;                       /* Sequencer disabled (ADC conversion on only 1 channel: channel set on rank 1) */
#endif
#ifdef ADC_EOC_SINGLE_CONV
  AdcHandle.Init.EOCSelection          = ADC_EOC_SINGLE_CONV;           /* EOC flag picked-up to indicate conversion end */
#endif
#if !defined(STM32F1xx) && !defined(STM32F2xx) && !defined(STM32F4xx) && \
    !defined(STM32F7xx) && !defined(ADC1_V2_5)
  AdcHandle.Init.LowPowerAutoWait      = DISABLE;                       /* Auto-delayed conversion feature disabled */
#endif
#if !defined(STM32F1xx) && !defined(STM32F2xx) && !defined(STM32F3xx) && \
    !defined(STM32F4xx) && !defined(STM32F7xx) && !defined(STM32G4xx) && \
    !defined(STM32H5xx) && !defined(STM32H7xx) && !defined(STM32L4xx) &&  \
    !defined(STM32L5xx) && !defined(STM32MP1xx) && !defined(STM32U3xx) && \
    !defined(STM32WBxx) || defined(ADC_SUPPORT_2_5_MSPS)
  AdcHandle.Init.LowPowerAutoPowerOff  = DISABLE;                       /* ADC automatically powers-off after a conversion and automatically wakes-up when a new conversion is triggered */
#endif
#ifdef ADC_CHANNELS_BANK_B
  AdcHandle.Init.ChannelsBank          = bank;
#elif defined(ADC_CHANNELS_BANK_A)
  AdcHandle.Init.ChannelsBank          = ADC_CHANNELS_BANK_A;
#endif
  AdcHandle.Init.ContinuousConvMode    = DISABLE;                       /* Continuous mode disabled to have only 1 conversion at each conversion trig */
#if !defined(STM32F0xx) && !defined(STM32L0xx)
  AdcHandle.Init.NbrOfConversion       = 1;                             /* Specifies the number of ranks that will be converted within the regular group sequencer. */
#endif
  AdcHandle.Init.DiscontinuousConvMode = DISABLE;                       /* Parameter discarded because sequencer is disabled */
#if !defined(STM32C0xx) && !defined(STM32F0xx) && !defined(STM32G0xx) && \
    !defined(STM32L0xx) && !defined(STM32U0xx) && !defined(STM32WBAxx) && \
    !defined(STM32WLxx) && !defined(ADC_SUPPORT_2_5_MSPS)
  AdcHandle.Init.NbrOfDiscConversion   = 0;                             /* Parameter discarded because sequencer is disabled */
#endif
  AdcHandle.Init.ExternalTrigConv      = ADC_SOFTWARE_START;            /* Software start to trig the 1st conversion manually, without external event */
#if !defined(STM32F1xx) && !defined(ADC1_V2_5)
  AdcHandle.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE; /* Parameter discarded because software trigger chosen */
#endif
#if !defined(STM32F1xx) && !defined(STM32H7xx) && !defined(STM32MP1xx) && \
    !defined(STM32U3xx) && !defined(ADC1_V2_5)
  AdcHandle.Init.DMAContinuousRequests = DISABLE;                       /* DMA one-shot mode selected (not applied to this example) */
#endif
#ifdef ADC_CONVERSIONDATA_DR
  AdcHandle.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DR;      /* Regular Conversion data stored in DR register only */
#endif
#ifdef ADC_OVR_DATA_OVERWRITTEN
  AdcHandle.Init.Overrun               = ADC_OVR_DATA_OVERWRITTEN;      /* DR register is overwritten with the last conversion result in case of overrun */
#endif
#ifdef ADC_LEFTBITSHIFT_NONE
  AdcHandle.Init.LeftBitShift          = ADC_LEFTBITSHIFT_NONE;         /* No bit shift left applied on the final ADC conversion data */
#endif

#if defined(STM32F0xx)
  AdcHandle.Init.SamplingTimeCommon    = samplingTime;
#endif
#if defined(STM32C0xx) || defined(STM32G0xx) || defined(STM32U0xx) || defined(STM32U5xx) || \
    defined(STM32WBAxx) || defined(STM32WLxx) || defined(ADC_SUPPORT_2_5_MSPS)
  AdcHandle.Init.SamplingTimeCommon1   = samplingTime;              /* Set sampling time common to a group of channels. */
  AdcHandle.Init.SamplingTimeCommon2   = samplingTime;              /* Set sampling time common to a group of channels, second common setting possible.*/
#endif
#if defined(STM32L0xx)
  AdcHandle.Init.LowPowerFrequencyMode = DISABLE;                       /* To be enabled only if ADC clock < 2.8 MHz */
  AdcHandle.Init.SamplingTime          = samplingTime;
#endif
#if !defined(STM32F0xx) && !defined(STM32F1xx) && !defined(STM32F2xx) && \
    !defined(STM32F3xx) && !defined(STM32F4xx) && !defined(STM32F7xx) && \
    !defined(STM32L1xx) && !defined(ADC_SUPPORT_2_5_MSPS)
  AdcHandle.Init.OversamplingMode      = DISABLE;
  /* AdcHandle.Init.Oversample ignore for STM32L0xx as oversampling disabled */
  /* AdcHandle.Init.Oversampling ignored for other as oversampling disabled */
#endif
#if defined(ADC_CFGR_DFSDMCFG) && defined(DFSDM1_Channel0)
  AdcHandle.Init.DFSDMConfig           = ADC_DFSDM_MODE_DISABLE;        /* ADC conversions are not transferred by DFSDM. */
#endif
#ifdef ADC_TRIGGER_FREQ_HIGH
  AdcHandle.Init.TriggerFrequencyMode  = ADC_TRIGGER_FREQ_HIGH;
#endif
#ifdef ADC_VREF_PPROT_NONE
  AdcHandle.Init.VrefProtection = ADC_VREF_PPROT_NONE;
#endif
#endif /* STM32WB0x*/
  AdcHandle.State = HAL_ADC_STATE_RESET;
  AdcHandle.DMA_Handle = NULL;
  AdcHandle.Lock = HAL_UNLOCKED;
  /* Some other ADC_HandleTypeDef fields exists but not required */

  g_current_pin = pin; /* Needed for HAL_ADC_MspInit*/

  if (HAL_ADC_Init(&AdcHandle) != HAL_OK) {
    return 0;
  }

  AdcChannelConf.Channel      = channel;                          /* Specifies the channel to configure into ADC */

#if defined(STM32G4xx) || defined(STM32H5xx) || defined(STM32L4xx) || \
    defined(STM32L5xx) || defined(STM32U3xx) || defined(STM32WBxx)
  if (!IS_ADC_CHANNEL(&AdcHandle, AdcChannelConf.Channel)) {
#else
  if (!IS_ADC_CHANNEL(AdcChannelConf.Channel)) {
#endif
    return 0;
  }

#if defined(STM32WB0x)
  AdcChannelConf.Rank = ADC_RANK_1;
  AdcChannelConf.VoltRange = voltageRange;
  AdcChannelConf.CalibrationPoint.Number = ADC_CALIB_POINT_1;

  uint32_t uADCxCalibrationPoint_Gain = 0;
  uint32_t uADCxCalibrationPoint_Offset = 0;
  if (channel != ADC_CHANNEL_VBAT && channel != ADC_CHANNEL_TEMPSENSOR) {
    /* Calibration point gain and offset */
    switch (voltageRange) {
      case ADC_VIN_RANGE_3V6:
        uADCxCalibrationPoint_Gain   = LL_ADC_GET_CALIB_GAIN_FOR_VINPX_3V6();
        uADCxCalibrationPoint_Offset = LL_ADC_GET_CALIB_OFFSET_FOR_VINPX_3V6();
        if (uADCxCalibrationPoint_Gain == 0xFFF) {
          uADCxCalibrationPoint_Gain = LL_ADC_DEFAULT_RANGE_VALUE_3V6;
          uADCxCalibrationPoint_Offset = 0UL;
        }
        break;
      case ADC_VIN_RANGE_2V4:
        uADCxCalibrationPoint_Gain   = LL_ADC_GET_CALIB_GAIN_FOR_VINPX_2V4();
        uADCxCalibrationPoint_Offset = LL_ADC_GET_CALIB_OFFSET_FOR_VINPX_2V4();
        if (uADCxCalibrationPoint_Gain == 0xFFF) {
          uADCxCalibrationPoint_Gain = LL_ADC_DEFAULT_RANGE_VALUE_2V4;
          uADCxCalibrationPoint_Offset = 0UL;
        }
        break;
      case ADC_VIN_RANGE_1V2:
        uADCxCalibrationPoint_Gain   = LL_ADC_GET_CALIB_GAIN_FOR_VINPX_1V2();
        uADCxCalibrationPoint_Offset = LL_ADC_GET_CALIB_OFFSET_FOR_VINPX_1V2();
        if (uADCxCalibrationPoint_Gain == 0xFFF) {
          uADCxCalibrationPoint_Gain = LL_ADC_DEFAULT_RANGE_VALUE_1V2;
          uADCxCalibrationPoint_Offset = 0UL;
        }
        break;
      default:
        _Error_Handler("ADC: Unknown ADC_VOLT_RANGE", (int)(ADC_VOLT_RANGE));
        break;
    }
  }
  AdcChannelConf.CalibrationPoint.Gain = uADCxCalibrationPoint_Gain;
  AdcChannelConf.CalibrationPoint.Offset = uADCxCalibrationPoint_Offset;
#else
#if defined(ADC_SCAN_SEQ_FIXED) && defined(ADC_RANK_CHANNEL_NUMBER)
  AdcChannelConf.Rank         = ADC_RANK_CHANNEL_NUMBER;          /* Enable the rank of the selected channels when not fully configurable */
#else
  AdcChannelConf.Rank         = ADC_REGULAR_RANK_1;               /* Specifies the rank in the regular group sequencer */
#endif
#if !defined(STM32L0xx)
#if !defined(STM32G0xx)
  AdcChannelConf.SamplingTime = samplingTime;                     /* Sampling time value to be set for the selected channel */
#else
  AdcChannelConf.SamplingTime = ADC_SAMPLINGTIME_COMMON_1;        /* Sampling time value to be set for the selected channel */
#endif
#endif
#if defined(ADC_DIFFERENTIAL_ENDED) && !defined(ADC1_V2_5)
  AdcChannelConf.SingleDiff   = ADC_SINGLE_ENDED;                 /* Single-ended input channel */
  AdcChannelConf.OffsetNumber = ADC_OFFSET_NONE;                  /* No offset subtraction */
#endif
#if !defined(STM32C0xx) && !defined(STM32F0xx) && !defined(STM32F1xx) && \
    !defined(STM32F2xx) && !defined(STM32G0xx) && !defined(STM32L0xx) && \
    !defined(STM32L1xx) && !defined(STM32U0xx) && !defined(STM32WBAxx) && \
    !defined(STM32WBxx) && !defined(STM32WLxx) && !defined(ADC1_V2_5)
  AdcChannelConf.Offset = 0;                                      /* Parameter discarded because offset correction is disabled */
#endif
#if defined (STM32H7xx) || defined(STM32MP1xx)
  AdcChannelConf.OffsetRightShift = DISABLE;                      /* No Right Offset Shift */
  AdcChannelConf.OffsetSignedSaturation = DISABLE;                /* Signed saturation feature is not used */
#endif
#endif /* STM32WB0x */
  /*##-2- Configure ADC regular channel ######################################*/
  if (HAL_ADC_ConfigChannel(&AdcHandle, &AdcChannelConf) != HAL_OK) {
    /* Channel Configuration Error */
    return 0;
  }

#if defined(ADC_CR_ADCAL) || defined(ADC_CR2_RSTCAL)
  /*##-2.1- Calibrate ADC then Start the conversion process ####################*/
#if defined(ADC_CALIB_OFFSET)
  if (HAL_ADCEx_Calibration_Start(&AdcHandle, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED) != HAL_OK)
#elif defined(ADC_SINGLE_ENDED) && !defined(ADC1_V2_5)
  if (HAL_ADCEx_Calibration_Start(&AdcHandle, ADC_SINGLE_ENDED) !=  HAL_OK)
#else
  if (HAL_ADCEx_Calibration_Start(&AdcHandle) !=  HAL_OK)
#endif
  {
    /* ADC Calibration Error */
    return 0;
  }
#endif

  /*##-3- Start the conversion process ####################*/
  if (HAL_ADC_Start(&AdcHandle) != HAL_OK) {
    /* Start Conversion Error */
    return 0;
  }

  /*##-4- Wait for the end of conversion #####################################*/
  /*  For simplicity reasons, this example is just waiting till the end of the
      conversion, but application may perform other tasks while conversion
      operation is ongoing. */
  if (HAL_ADC_PollForConversion(&AdcHandle, 10) != HAL_OK) {
    /* End Of Conversion flag not set on time */
    return 0;
  }

  /* Check if the continuous conversion of regular channel is finished */
#if defined(HAL_ADC_STATE_DS_EOC)
  if ((HAL_ADC_GetState(&AdcHandle) & HAL_ADC_STATE_DS_EOC) == HAL_ADC_STATE_DS_EOC) {
#else
  if ((HAL_ADC_GetState(&AdcHandle) & HAL_ADC_STATE_REG_EOC) == HAL_ADC_STATE_REG_EOC) {
#endif
    /*##-5- Get the converted value of regular channel  ########################*/
    uhADCxConvertedValue = HAL_ADC_GetValue(&AdcHandle);
  }

  if (HAL_ADC_Stop(&AdcHandle) != HAL_OK) {
    /* Stop Conversation Error */
    return 0;
  }

  if (HAL_ADC_DeInit(&AdcHandle) != HAL_OK) {
    return 0;
  }

#if defined(LL_ADC_PATH_INTERNAL_NONE)
  if (__LL_ADC_COMMON_INSTANCE(AdcHandle.Instance) != 0U) {
    LL_ADC_SetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(AdcHandle.Instance), LL_ADC_PATH_INTERNAL_NONE);
  }
#endif
  return uhADCxConvertedValue;
}
#endif /* HAL_ADC_MODULE_ENABLED && !HAL_ADC_MODULE_ONLY*/

#if defined(HAL_TIM_MODULE_ENABLED) && !defined(HAL_TIM_MODULE_ONLY)
////////////////////////// PWM INTERFACE FUNCTIONS /////////////////////////////

/**
  * @brief  This function will set the PWM to the required value
  * @param  port : the gpio port to use
  * @param  pin : the gpio pin to use
  * @param  clock_freq : frequency of the tim clock
  * @param  value : the value to push on the PWM output
  * @retval None
  */
void pwm_start(PinName pin, uint32_t PWM_freq, uint32_t value, TimerCompareFormat_t resolution)
{
  TIM_TypeDef *Instance = (TIM_TypeDef *)pinmap_peripheral(pin, PinMap_TIM);
  HardwareTimer *HT;
  TimerModes_t previousMode;
  uint32_t index = get_timer_index(Instance);
  if (HardwareTimer_Handle[index] == NULL) {
    HardwareTimer_Handle[index]->__this = new HardwareTimer((TIM_TypeDef *)pinmap_peripheral(pin, PinMap_TIM));
  }

  HT = (HardwareTimer *)(HardwareTimer_Handle[index]->__this);

  uint32_t channel = STM_PIN_CHANNEL(pinmap_function(pin, PinMap_TIM));

  previousMode = HT->getMode(channel);
  if (previousMode != TIMER_OUTPUT_COMPARE_PWM1) {
    HT->setMode(channel, TIMER_OUTPUT_COMPARE_PWM1, pin);
  }
  HT->setOverflow(PWM_freq, HERTZ_FORMAT);
  HT->setCaptureCompare(channel, value, resolution);
  if (previousMode != TIMER_OUTPUT_COMPARE_PWM1) {
    HT->resume();
  }
}
/**
  * @brief  This function will disable the PWM
  * @param  port : the gpio port to use
  * @param  pin : the gpio pin to use
  * @retval None
  */
void pwm_stop(PinName pin)
{
  TIM_TypeDef *Instance = (TIM_TypeDef *)pinmap_peripheral(pin, PinMap_TIM);
  HardwareTimer *HT;
  uint32_t index = get_timer_index(Instance);
  if (HardwareTimer_Handle[index] == NULL) {
    HardwareTimer_Handle[index]->__this = new HardwareTimer((TIM_TypeDef *)pinmap_peripheral(pin, PinMap_TIM));
  }

  HT = (HardwareTimer *)(HardwareTimer_Handle[index]->__this);
  if (HT != NULL) {
    delete (HT);
    HT = NULL;
  }
}
#endif /* HAL_TIM_MODULE_ENABLED && !HAL_TIM_MODULE_ONLY */

#ifdef __cplusplus
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
