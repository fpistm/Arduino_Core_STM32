/**
  ******************************************************************************
  * @file    stm32l1xx_ll_fsmc.c
  * @author  MCD Application Team
  * @brief   FSMC Low Layer HAL module driver.
  *
  *          This file provides firmware functions to manage the following
  *          functionalities of the Flexible Memory Controller (FSMC) peripheral memories:
  *           + Initialization/de-initialization functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @verbatim
  ==============================================================================
                        ##### FSMC peripheral features #####
  ==============================================================================
  [..] The Flexible memory controller (FSMC) includes following memory controllers:
       (+) The NOR/PSRAM memory controller

  [..] The FSMC functional block makes the interface with synchronous and asynchronous static
       memories. Its main purposes are:
       (+) to translate AHB transactions into the appropriate external device protocol
       (+) to meet the access time requirements of the external memory devices

  [..] All external memories share the addresses, data and control signals with the controller.
       Each external device is accessed by means of a unique Chip Select. The FSMC performs
       only one access at a time to an external device.
       The main features of the FSMC controller are the following:
        (+) Interface with static-memory mapped devices including:
           (++) Static random access memory (SRAM)
           (++) Read-only memory (ROM)
           (++) NOR Flash memory/OneNAND Flash memory
           (++) PSRAM (4 memory banks)
        (+) Independent Chip Select control for each memory bank
        (+) Independent configuration for each memory bank

  @endverbatim
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32l1xx_hal.h"

/** @addtogroup STM32L1xx_HAL_Driver
  * @{
  */
#if defined(HAL_NOR_MODULE_ENABLED) \
    || defined(HAL_SRAM_MODULE_ENABLED)

/** @defgroup FSMC_LL  FSMC Low Layer
  * @brief FSMC driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/** @defgroup FSMC_LL_Private_Constants FSMC Low Layer Private Constants
  * @{
  */

/* ----------------------- FSMC registers bit mask --------------------------- */

#if defined(FSMC_BANK1)
/* --- BCR Register ---*/
/* BCR register clear mask */

/* --- BTR Register ---*/
/* BTR register clear mask */
#define BTR_CLEAR_MASK    ((uint32_t)(FSMC_BTRx_ADDSET | FSMC_BTRx_ADDHLD  |\
                                      FSMC_BTRx_DATAST | FSMC_BTRx_BUSTURN |\
                                      FSMC_BTRx_CLKDIV | FSMC_BTRx_DATLAT  |\
                                      FSMC_BTRx_ACCMOD))

/* --- BWTR Register ---*/
/* BWTR register clear mask */
#define BWTR_CLEAR_MASK   ((uint32_t)(FSMC_BWTRx_ADDSET | FSMC_BWTRx_ADDHLD  |\
                                      FSMC_BWTRx_DATAST | FSMC_BWTRx_BUSTURN |\
                                      FSMC_BWTRx_ACCMOD))
#endif /* FSMC_BANK1 */

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @defgroup FSMC_LL_Exported_Functions FSMC Low Layer Exported Functions
  * @{
  */

#if defined(FSMC_BANK1)

/** @defgroup FSMC_LL_Exported_Functions_NORSRAM FSMC Low Layer NOR SRAM Exported Functions
  * @brief  NORSRAM Controller functions
  *
  @verbatim
  ==============================================================================
                   ##### How to use NORSRAM device driver #####
  ==============================================================================

  [..]
    This driver contains a set of APIs to interface with the FSMC NORSRAM banks in order
    to run the NORSRAM external devices.

    (+) FSMC NORSRAM bank reset using the function FSMC_NORSRAM_DeInit()
    (+) FSMC NORSRAM bank control configuration using the function FSMC_NORSRAM_Init()
    (+) FSMC NORSRAM bank timing configuration using the function FSMC_NORSRAM_Timing_Init()
    (+) FSMC NORSRAM bank extended timing configuration using the function
        FSMC_NORSRAM_Extended_Timing_Init()
    (+) FSMC NORSRAM bank enable/disable write operation using the functions
        FSMC_NORSRAM_WriteOperation_Enable()/FSMC_NORSRAM_WriteOperation_Disable()

@endverbatim
  * @{
  */

/** @defgroup FSMC_LL_NORSRAM_Exported_Functions_Group1 Initialization and de-initialization functions
  * @brief    Initialization and Configuration functions
  *
  @verbatim
  ==============================================================================
              ##### Initialization and de_initialization functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to:
    (+) Initialize and configure the FSMC NORSRAM interface
    (+) De-initialize the FSMC NORSRAM interface
    (+) Configure the FSMC clock and associated GPIOs

@endverbatim
  * @{
  */

/**
  * @brief  Initialize the FSMC_NORSRAM device according to the specified
  *         control parameters in the FSMC_NORSRAM_InitTypeDef
  * @param  Device Pointer to NORSRAM device instance
  * @param  Init Pointer to NORSRAM Initialization structure
  * @retval HAL status
  */
HAL_StatusTypeDef  FSMC_NORSRAM_Init(FSMC_NORSRAM_TypeDef *Device,
                                     const FSMC_NORSRAM_InitTypeDef *Init)
{
  uint32_t flashaccess;
  uint32_t btcr_reg;
  uint32_t mask;

  /* Check the parameters */
  assert_param(IS_FSMC_NORSRAM_DEVICE(Device));
  assert_param(IS_FSMC_NORSRAM_BANK(Init->NSBank));
  assert_param(IS_FSMC_MUX(Init->DataAddressMux));
  assert_param(IS_FSMC_MEMORY(Init->MemoryType));
  assert_param(IS_FSMC_NORSRAM_MEMORY_WIDTH(Init->MemoryDataWidth));
  assert_param(IS_FSMC_BURSTMODE(Init->BurstAccessMode));
  assert_param(IS_FSMC_WAIT_POLARITY(Init->WaitSignalPolarity));
  assert_param(IS_FSMC_WRAP_MODE(Init->WrapMode));
  assert_param(IS_FSMC_WAIT_SIGNAL_ACTIVE(Init->WaitSignalActive));
  assert_param(IS_FSMC_WRITE_OPERATION(Init->WriteOperation));
  assert_param(IS_FSMC_WAITE_SIGNAL(Init->WaitSignal));
  assert_param(IS_FSMC_EXTENDED_MODE(Init->ExtendedMode));
  assert_param(IS_FSMC_ASYNWAIT(Init->AsynchronousWait));
  assert_param(IS_FSMC_WRITE_BURST(Init->WriteBurst));
  assert_param(IS_FSMC_PAGESIZE(Init->PageSize));

  /* Disable NORSRAM Device */
  __FSMC_NORSRAM_DISABLE(Device, Init->NSBank);

  /* Set NORSRAM device control parameters */
  if (Init->MemoryType == FSMC_MEMORY_TYPE_NOR)
  {
    flashaccess = FSMC_NORSRAM_FLASH_ACCESS_ENABLE;
  }
  else
  {
    flashaccess = FSMC_NORSRAM_FLASH_ACCESS_DISABLE;
  }

  btcr_reg = (flashaccess                   | \
              Init->DataAddressMux          | \
              Init->MemoryType              | \
              Init->MemoryDataWidth         | \
              Init->BurstAccessMode         | \
              Init->WaitSignalPolarity      | \
              Init->WaitSignalActive        | \
              Init->WriteOperation          | \
              Init->WaitSignal              | \
              Init->ExtendedMode            | \
              Init->AsynchronousWait        | \
              Init->WriteBurst);

  btcr_reg |= Init->WrapMode;
  btcr_reg |= Init->PageSize;

  mask = (FSMC_BCRx_MBKEN                |
          FSMC_BCRx_MUXEN                |
          FSMC_BCRx_MTYP                 |
          FSMC_BCRx_MWID                 |
          FSMC_BCRx_FACCEN               |
          FSMC_BCRx_BURSTEN              |
          FSMC_BCRx_WAITPOL              |
          FSMC_BCRx_WAITCFG              |
          FSMC_BCRx_WREN                 |
          FSMC_BCRx_WAITEN               |
          FSMC_BCRx_EXTMOD               |
          FSMC_BCRx_ASYNCWAIT            |
          FSMC_BCRx_CBURSTRW);

  mask |= FSMC_BCRx_WRAPMOD;
  mask |= FSMC_BCRx_CPSIZE;

  MODIFY_REG(Device->BTCR[Init->NSBank], mask, btcr_reg);


  return HAL_OK;
}

/**
  * @brief  DeInitialize the FSMC_NORSRAM peripheral
  * @param  Device Pointer to NORSRAM device instance
  * @param  ExDevice Pointer to NORSRAM extended mode device instance
  * @param  Bank NORSRAM bank number
  * @retval HAL status
  */
HAL_StatusTypeDef FSMC_NORSRAM_DeInit(FSMC_NORSRAM_TypeDef *Device,
                                      FSMC_NORSRAM_EXTENDED_TypeDef *ExDevice, uint32_t Bank)
{
  /* Check the parameters */
  assert_param(IS_FSMC_NORSRAM_DEVICE(Device));
  assert_param(IS_FSMC_NORSRAM_EXTENDED_DEVICE(ExDevice));
  assert_param(IS_FSMC_NORSRAM_BANK(Bank));

  /* Disable the FSMC_NORSRAM device */
  __FSMC_NORSRAM_DISABLE(Device, Bank);

  /* De-initialize the FSMC_NORSRAM device */
  /* FSMC_NORSRAM_BANK1 */
  if (Bank == FSMC_NORSRAM_BANK1)
  {
    Device->BTCR[Bank] = 0x000030DBU;
  }
  /* FSMC_NORSRAM_BANK2, FSMC_NORSRAM_BANK3 or FSMC_NORSRAM_BANK4 */
  else
  {
    Device->BTCR[Bank] = 0x000030D2U;
  }

  Device->BTCR[Bank + 1U] = 0x0FFFFFFFU;
  ExDevice->BWTR[Bank]   = 0x0FFFFFFFU;

  return HAL_OK;
}

/**
  * @brief  Initialize the FSMC_NORSRAM Timing according to the specified
  *         parameters in the FSMC_NORSRAM_TimingTypeDef
  * @param  Device Pointer to NORSRAM device instance
  * @param  Timing Pointer to NORSRAM Timing structure
  * @param  Bank NORSRAM bank number
  * @retval HAL status
  */
HAL_StatusTypeDef FSMC_NORSRAM_Timing_Init(FSMC_NORSRAM_TypeDef *Device,
                                           const FSMC_NORSRAM_TimingTypeDef *Timing, uint32_t Bank)
{

  /* Check the parameters */
  assert_param(IS_FSMC_NORSRAM_DEVICE(Device));
  assert_param(IS_FSMC_ADDRESS_SETUP_TIME(Timing->AddressSetupTime));
  assert_param(IS_FSMC_ADDRESS_HOLD_TIME(Timing->AddressHoldTime));
  assert_param(IS_FSMC_DATASETUP_TIME(Timing->DataSetupTime));
  assert_param(IS_FSMC_TURNAROUND_TIME(Timing->BusTurnAroundDuration));
  assert_param(IS_FSMC_CLK_DIV(Timing->CLKDivision));
  assert_param(IS_FSMC_DATA_LATENCY(Timing->DataLatency));
  assert_param(IS_FSMC_ACCESS_MODE(Timing->AccessMode));
  assert_param(IS_FSMC_NORSRAM_BANK(Bank));

  /* Set FSMC_NORSRAM device timing parameters */
  Device->BTCR[Bank + 1U] =
    (Timing->AddressSetupTime << FSMC_BTRx_ADDSET_Pos) |
    (Timing->AddressHoldTime << FSMC_BTRx_ADDHLD_Pos) |
    (Timing->DataSetupTime << FSMC_BTRx_DATAST_Pos) |
    (Timing->BusTurnAroundDuration << FSMC_BTRx_BUSTURN_Pos) |
    ((Timing->CLKDivision - 1U) << FSMC_BTRx_CLKDIV_Pos) |
    ((Timing->DataLatency - 2U) << FSMC_BTRx_DATLAT_Pos) |
    Timing->AccessMode;

  return HAL_OK;
}

/**
  * @brief  Initialize the FSMC_NORSRAM Extended mode Timing according to the specified
  *         parameters in the FSMC_NORSRAM_TimingTypeDef
  * @param  Device Pointer to NORSRAM device instance
  * @param  Timing Pointer to NORSRAM Timing structure
  * @param  Bank NORSRAM bank number
  * @param  ExtendedMode FSMC Extended Mode
  *          This parameter can be one of the following values:
  *            @arg FSMC_EXTENDED_MODE_DISABLE
  *            @arg FSMC_EXTENDED_MODE_ENABLE
  * @retval HAL status
  */
HAL_StatusTypeDef FSMC_NORSRAM_Extended_Timing_Init(FSMC_NORSRAM_EXTENDED_TypeDef *Device,
                                                    const FSMC_NORSRAM_TimingTypeDef *Timing, uint32_t Bank,
                                                    uint32_t ExtendedMode)
{
  /* Check the parameters */
  assert_param(IS_FSMC_EXTENDED_MODE(ExtendedMode));

  /* Set NORSRAM device timing register for write configuration, if extended mode is used */
  if (ExtendedMode == FSMC_EXTENDED_MODE_ENABLE)
  {
    /* Check the parameters */
    assert_param(IS_FSMC_NORSRAM_EXTENDED_DEVICE(Device));
    assert_param(IS_FSMC_ADDRESS_SETUP_TIME(Timing->AddressSetupTime));
    assert_param(IS_FSMC_ADDRESS_HOLD_TIME(Timing->AddressHoldTime));
    assert_param(IS_FSMC_DATASETUP_TIME(Timing->DataSetupTime));
    assert_param(IS_FSMC_TURNAROUND_TIME(Timing->BusTurnAroundDuration));
    assert_param(IS_FSMC_ACCESS_MODE(Timing->AccessMode));
    assert_param(IS_FSMC_NORSRAM_BANK(Bank));

    /* Set NORSRAM device timing register for write configuration, if extended mode is used */
    MODIFY_REG(Device->BWTR[Bank], BWTR_CLEAR_MASK, (Timing->AddressSetupTime                                    |
                                                     ((Timing->AddressHoldTime)        << FSMC_BWTRx_ADDHLD_Pos)  |
                                                     ((Timing->DataSetupTime)          << FSMC_BWTRx_DATAST_Pos)  |
                                                     Timing->AccessMode                                          |
                                                     ((Timing->BusTurnAroundDuration)  << FSMC_BWTRx_BUSTURN_Pos)));
  }
  else
  {
    Device->BWTR[Bank] = 0x0FFFFFFFU;
  }

  return HAL_OK;
}
/**
  * @}
  */

/** @addtogroup FSMC_LL_NORSRAM_Private_Functions_Group2
  *  @brief   management functions
  *
@verbatim
  ==============================================================================
                      ##### FSMC_NORSRAM Control functions #####
  ==============================================================================
  [..]
    This subsection provides a set of functions allowing to control dynamically
    the FSMC NORSRAM interface.

@endverbatim
  * @{
  */

/**
  * @brief  Enables dynamically FSMC_NORSRAM write operation.
  * @param  Device Pointer to NORSRAM device instance
  * @param  Bank NORSRAM bank number
  * @retval HAL status
  */
HAL_StatusTypeDef FSMC_NORSRAM_WriteOperation_Enable(FSMC_NORSRAM_TypeDef *Device, uint32_t Bank)
{
  /* Check the parameters */
  assert_param(IS_FSMC_NORSRAM_DEVICE(Device));
  assert_param(IS_FSMC_NORSRAM_BANK(Bank));

  /* Enable write operation */
  SET_BIT(Device->BTCR[Bank], FSMC_WRITE_OPERATION_ENABLE);

  return HAL_OK;
}

/**
  * @brief  Disables dynamically FSMC_NORSRAM write operation.
  * @param  Device Pointer to NORSRAM device instance
  * @param  Bank NORSRAM bank number
  * @retval HAL status
  */
HAL_StatusTypeDef FSMC_NORSRAM_WriteOperation_Disable(FSMC_NORSRAM_TypeDef *Device, uint32_t Bank)
{
  /* Check the parameters */
  assert_param(IS_FSMC_NORSRAM_DEVICE(Device));
  assert_param(IS_FSMC_NORSRAM_BANK(Bank));

  /* Disable write operation */
  CLEAR_BIT(Device->BTCR[Bank], FSMC_WRITE_OPERATION_ENABLE);

  return HAL_OK;
}

/**
  * @}
  */

/**
  * @}
  */
#endif /* FSMC_BANK1 */


/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_NOR_MODULE_ENABLED */
/**
  * @}
  */
/**
  * @}
  */
