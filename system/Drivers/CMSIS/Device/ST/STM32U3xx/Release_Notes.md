

# Release Notes for <mark>STM32U3xx CMSIS</mark>
Copyright &copy; 2024 - 2026 STMicroelectronics\

[![ST logo](_htmresc/st_logo_2020.png)](https://www.st.com)

# Purpose

This driver provides the CMSIS device for the STM32U3xx product. This covers

- STM32U375xx devices
- STM32U385xx devices

This driver is composed of the description of the registers under "Include" directory.

Various template files are provided to easily build an application. They can be adapted to fit applications requirements.

- Templates/system_stm32u3xx.c contains the initialization code referred as SystemInit.
- Startup files are provided as example for EWARM&copy;, MDK-ARM&copy;, STM32CubeIDE&copy;.
- Linker files are provided as example for EWARM&copy;, MDK-ARM&copy;, STM32CubeIDE&copy;.



# Update history

<label for="collapse-section5" aria-hidden="true"> __V1.4.0 / 03-June-2026__ </label>
<div>

## Official Release

- Official release of CMSIS for **STM32U3xx** firmware package supporting **STM32U335xx/STM32U345xx/STM32U356xx/STM32U366xx/STM32U375xx/STM32U385xx/STM32U3B5xx/STM32U3C5xx** devices
- CMSIS Device Release version of bits and registers definition aligned with **RM0487**

## Contents
- First official release of STM32U335xx/STM32U345xx/STM32U356xx/STM32U366xx
- Update registers and bit definition for all derivatives after last update of RNG4.4.
- Created startup and Linker files of STM32U3 256K for CubeIDE
- Add ADC1 security bit for U3 256K variants
- Enable CCB HW sanity check on more U3 variants

## Known Limitations

- None

</div>

<label for="collapse-section4" aria-hidden="true"> __V1.3.0 / 04-February-2026__ </label>
<div>

## Official Release

- Official release of CMSIS for **STM32U3xx** firmware package supporting **STM32U385xx/STM32U375xx/STM32U3B5xx/STM32U3C5xx** devices
- CMSIS Device Release version of bits and registers definition aligned with **RM0487**

## Contents
- First official release of STM32U3B5xx/STM32U3C5xx
- Add COMP2 output-blanking PWM assignment
- Fix Missing OR operator in IS_TIM_CCXN_INSTANCE definition
- Set stack limit (MSPLIM) in CMSIS Device templates
- Remove "__section_static_hsp_data_bram_start__" & "__section_static_hsp_data_bram_end__" useless symbols
- Fix wrong memory region for HSP_DATA_BRAM
- Add missing bit fields in flash
- Update scatter file with correct flash size
- Add Begin/End symbols for HSP_DATA_BRAM memory region
- Add clock defaults to system file
- Add/Update TSC registers for U3 derivatives
- Add/Update DBGMCU registers
- Add SYSCFG_CFGR1_TSC_G2_IO3 and SYSCFG_CFGR1_TSC_G2_IO1 bit definitions in SYSCFG_CFGR1
- Fix wrong macro value for VREFBUF_CSR_VRS_2
- Update TIM8 IRQ Handler name and remove unused AES IRQ handler
- Add I2C4 macros for STM32U3 2M
- Rename "HSP_BKO0CFGR_xxxx" constants by "HSP_BKOCFGR_xxxx"
- Fix wrong macro HSPI1 to HSP1 in DBGMCU_AHB1FZR_DBG_HSP1
- CMSIS update removing ADC DIFSEL register
- Fix MPCBB registers for SRAM3
- CMSIS correction for TIM8_S Definition
- Add SPI4 instance for STM32U3 2M
- Update FLASH linker files with correct flash size

## Known Limitations

- None

</div>

<label for="collapse-section3" aria-hidden="true"> __V1.2.0 / 04-June-2025__ </label>
<div>

## Maintenance Release

- Maintenance release of CMSIS for **STM32U3xx** firmware package supporting **STM32U385xx/STM32U375xx** devices

## Contents
- Add PKA on STM32U375xx
- Add CCB sanity check feature on STM32U385xx
- Swap bit position FLASH MEM and FLASH REG in GTZC1 TZIC registers

## Known Limitations

- None

</div>

<label for="collapse-section2" aria-hidden="true"> __V1.1.0 / 05-February-2025__ </label>
<div>

## Maintenance Release

- Maintenance release of CMSIS for **STM32U3xx** firmware package supporting **STM32U385xx/STM32U375xx** devices

## Contents
- Fix PWR_I3CPUCR2_PG14_I3CPU_Pos value
- Suppress unused bit
- Minor fix on comments

## Known Limitations

- None

</div>

<label for="collapse-section1" aria-hidden="true"> __V1.0.0 / 30-October-2024__ </label>
<div>

## First Release

- First official release of CMSIS for **STM32U3xx** firmware package supporting **STM32U385xx/STM32U375xx** devices

## Contents

- First official release of CMSIS devices drivers
  - Support of STM32U385xx/STM32U375xx devices

## Known Limitations

- None

</div>


<abbr title="Based on template cx566953 version 2.1">Info</abbr>