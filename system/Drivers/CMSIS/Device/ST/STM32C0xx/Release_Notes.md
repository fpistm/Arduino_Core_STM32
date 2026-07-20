

# Release Notes for <mark>\ STM32C0xx CMSIS </mark>
Copyright &copy; 2022\ STMicroelectronics\

[![ST logo](_htmresc/st_logo_2020.png)](https://www.st.com)


# __Update History__

<label for="collapse-section6" checked aria-hidden="true">__V1.4.1 / 26-June-2026__</label>
<div>

## Main Changes

- General updates to fix known defects and enhance implementation

## Contents

- Allow redefinition of the macro 'VECT_TAB_OFFSET' externally from the IDE, makefile, or command line.
- Fix RCC_CSR1_LSEDRV_Msk definition to match actual field width
- Fix DMAMUX1/DMA1 shared interrupt handler name
- Add IAR linker configuration file for STM32C071x8

## Supported Devices

- STM32C011xx, STM32C031xx, STM32C051xx, STM32C071xx and STM32C091/92xx devices

</div>

<label for="collapse-section5" aria-hidden="true">__V1.4.0 / 05-February-2025__</label>
<div>

## Main Changes

- No CMSIS-related fixes were included in this release.


</div>


<label for="collapse-section4" checked aria-hidden="true">__V1.3.0 / 30-October-2024__</label>
<div>

## Main Changes

- Official release of STM32C0xx CMSIS drivers to support **STM32C051xx** and **STM32C091/92xx** devices
- General updates to fix known defects and enhance implementation
- Align version of bit and registers definition with the STM32C0 reference manual

## Contents

- **Support of STM32C051xx and STM32C091/92xx devices**:
  - Add “stm32c051xx.h” , “stm32c091xx.h”, and “stm32c092xx.h” files
  - Add startup files “startup_stm32c051xx.s”, “startup_stm32c091xx.s” and “startup_stm32c092xx.s” for EWARM, STM32CubeIDE and MDK-ARM toolchains
  - Add STM32C051xx and STM32C091/92xx devices linker files for EWARM and STM32CubeIDE toolchains

- **Registers and bit field definitions updates** :
	- Add BL_EXIT_SEC_MEM_BASE Bootloader Exit Secure Memory Firmware addresses
	- Remove RCC_CR_SYSDIV bit definition from C031xx and C011xx CMSIS files as undefined

## Supported Devices

- STM32C011xx, STM32C031xx, **STM32C051xx**, STM32C071xx and **STM32C091/92xx** devices

</div>

<label for="collapse-section3" aria-hidden="true">__V1.2.0 / 05-June-2024__</label>
<div>

## Main Changes

- First official release of STM32C0xx CMSIS drivers to support **STM32C071xx** devices
- General updates to fix known defects and enhance implementation
- Align version of bit and registers definition with the STM32C0 reference manual

## Contents

- **Support of STM32C071xx devices**:
  - Add “stm32c071xx.h” file
  - Add startup files “startup_stm32c071xx.s” for EWARM, STM32CubeIDE and MDK-ARM toolchains
  - Add STM32C071xx devices linker files for EWARM and STM32CubeIDE toolchains

- **Registers and bit field definitions updates** :
	- Add DMAMUX1_RequestGenerator3_BASE and DMAMUX1_RequestGenerator3 definitions
	- Remove DMA_IFCR_CGIF4, DMA_IFCR_CTCIF4, DMA_IFCR_CHTIF4 and DMA_IFCR_CTEIF4 definitions
	- Add ADC_AWD2CR_AWD2CH_19, ADC_AWD2CR_AWD2CH_20, ADC_AWD2CR_AWD2CH_21 and ADC_AWD2CR_AWD2CH_22 bits definitions
	- Add ADC_AWD3CR_AWD3CH_19, ADC_AWD3CR_AWD3CH_20, ADC_AWD3CR_AWD3CH_21, ADC_AWD3CR_AWD3CH_22 bits definitions
	- Add FLASH_OPTR_SECURE_MUXING_EN bit definition
	- Correct Flash page number section mask (FLASH_CR_PNB_Msk)
	- Remove extra FLASH_ECCR register bits definitions
	- Correct masks values of FLASH_PCROP1ASR, FLASH_WRP1AR, FLASH_WRP1BR, FLASH_WRP1BR, FLASH_PCROP1BER registers
	- Add FLASH_SIZE macro to compute Flash size value
	- Fix correct FLASH_OPTR_BORF_LEV and FLASH_OPTR_BORR_LEV positions
	- Remove SYSCFG_CFGR1_BOOSTEN bit definition
	- Correct SYSCFG_CFGR3 register bits masks values
	- Change SYSCFG_ITLINE0_SR_EWDG bit definition naming by SYSCFG_ITLINE0_SR_WWDG to be aligned with the reference manual
	- Change SYSCFG_ITLINE4_SR_CLK_CTRL bit definition naming by SYSCFG_ITLINE4_SR_RCC to be aligned with the reference manual
	- Update IS_TIM_REMAP_INSTANCE and IS_TIM_ETRSEL_INSTANCE macros
	- Update TIM Capture/Compare masks values
	- Remove extra EXTI interrupts and events Masks
	- Remove extra PWR_SR2_REGLPF bits definition
	- Update some RCC_CFGR bit definitions
		- Remove RCC_CFGR_MCO2PRE_3 and RCC_CFGR_MCOPRE_3 bits definitions as reserved
		- Update RCC_CFGR_MCO2PRE_Msk and RCC_CFGR_MCOPRE_Msk masks values

## Supported Devices

- STM32C011xx, STM32C031xx and STM32C071xx devices

</div>

<label for="collapse-section2" aria-hidden="true">__V1.1.0 / 07-June-2023__</label>
<div>

## Main Changes

Align flash register address with STM32C0 reference manual

</div>

<label for="collapse-section1" aria-hidden="true">__V1.0.0 / 09-February-2022__</label>
<div>

## Main Changes

First official release version of bits and registers definition aligned with STM32C0 reference manual

</div>



This release note uses up to date web standards and, for this reason, should not be opened with Internet Explorer
but preferably with popular browsers such as Google Chrome, Mozilla Firefox, Opera or Microsoft Edge.