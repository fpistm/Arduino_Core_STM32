

# Release Notes for <mark>STM32H5xx CMSIS</mark>
Copyright &copy; 2024 STMicroelectronics\

[![ST logo](_htmresc/st_logo_2020.png)](https://www.st.com)

# Purpose

This driver provides the CMSIS device for the STM32H5xx product. This covers

- STM32H543xx and STM32H553xx, STM32H573xx, STM32H533xx, STM32H523xx, STM32H562xx, STM32H563xx, STM32H503xx, STM32H5E4xx, STM32H5E5xx, STM32H5F4xx and STM32H5F5xx devices.

This driver is composed of the description of the registers under "Include" directory.

Various template files are provided to easily build an application. They can be adapted to fit applications requirements.

- Templates/system_stm32h5xx.c contains the initialization code referred as SystemInit.
- Startup files are provided as example for EWARM&copy;, MDK-ARM&copy;, STM32CubeIDE&copy;.
- Linker files are provided as example for EWARM&copy;, MDK-ARM&copy;, STM32CubeIDE&copy;.


# Update history

<label for="collapse-section8" aria-hidden="true">__V1.7.0 / 03-June-2026__</label>
<div>

## Main Changes

-  Official release of **STM32H543xx and STM32H553xx** devices.
-  CMSIS Device Release version of bits and registers definition aligned with **RM0539 (STM32H543xx / STM32H553xx reference manual)**
   **RM0481** (STM32H523xx, STM32H533xx, STM32H562xx, STM32H563xx and STM32H573xx reference manual), **RM0492** (STM32H503xx reference manual)
   and **RM0517** (STM32H5E4xx, STM32H5E5xx, STM32H5F4xx and STM32H5F5xx reference manual)
-  MISR field is added to I3C_TypeDef for H5 4M
-  The naming of the I3C_MISR_IBIENDMIS bit has been corrected
-  The COMP_CFGR1_WINOUT bit position has been fixed for H5 1M devices
-  Registers and bit definitions have been updated following the latest RNG 4.4 update
-  Linker and startup files have been added for STM32H553xx and STM32H543xx devices for the GCC toolchain
-  The RNG HTCR NIST value has been corrected in the CMSIS headers for H5 devices
-  The reset value of EXTI_IMR2_IM has been corrected

## Known limitations

-	None

</div>

<label for="collapse-section7" aria-hidden="true">__V1.6.0 / 04-February-2026__</label>
<div>

## Main Changes

-  CMSIS Device Release version of bits and registers definition aligned with **RM0481** (STM32H523xx, STM32H533xx, STM32H562xx, STM32H563xx and STM32H573xx reference manual), **RM0492** (STM32H503xx reference manual) and **RM0517** (STM32H5E4xx, STM32H5E5xx, STM32H5F4xx and STM32H5F5xx reference manual)
-  Official release of **STM32H5E4xx, STM32H5E5xx, STM32H5F4xx** and **STM32H5F5xx**
-  Fix `SystemInit()` resetting HSIDIV, which caused wrong Flash latency configuration and potential hard faults
-  Set stack limit (MSPLIM) in CMSIS Device templates for ARMv8-M–based products
-  LTDC: interrupt name aligned with reference manual
-  UCPD: removed bits defined in CMSIS file but unavailable in the reference manual
-  USB: added missing bits definition in the CMSIS file
-  Remove non-present TIM register definition for STM32H5-128K and STM32H5-512K devices

## Known limitations

-	None

</div>

<label for="collapse-section6" aria-hidden="true">__V1.5.0 / 05-February-2025__</label>
<div>

## Main Changes

-   CMSIS Device Maintenance Release version of bits and registers definition aligned with **RM0481** (STM32H523xx, STM32H533xx, STM32H562xx, STM32H563xx and STM32H573xx reference manual) and **RM0492** (STM32H503xx reference manual)
-	Rename ADC_AWD3CR_AWD2CH_19 to ADC_AWD3CR_AWD3CH_19 define
-   Remove HWCFGR, VERR, PIDR and SIDR registers from CRC_TypeDef

## Known limitations

-	None

</div>

<label for="collapse-section5" aria-hidden="true">__V1.4.0 / 30-October-2024__</label>
<div>

## Main Changes

-   CMSIS Device Maintenance Release version of bits and registers definition aligned with **RM0481** (STM32H5 reference manual)
-	Update to use #include \"core_cm33.h\" instead of #include <core_cm33.h> to force the first searches for the core_cm33.h file in the same directory as the file that contains the #include directive (Drivers\\CMSIS\\Core\\Include)
-   Update IS_SPI_LIMITED macro to return an essential boolean

## Known limitations

-	None

</div>


<label for="collapse-section4" aria-hidden="true">__V1.3.0 / 05-June-2024__</label>
<div>

## Main Changes

-   CMSIS Device Maintenance Release version of bits and registers definition aligned with **RM0481** (STM32H5 reference manual)
-	Add RNG_CR_NIST_VALUE, RNG_NSCR_NIST_VALUE and RNG_HTCR_NIST_VALUE defines
-   Add Bits definition for RNG_NSCR register : Add RNG_NSCR_EN_OSC1, RNG_NSCR_EN_OSC2, RNG_NSCR_EN_OSC3, RNG_NSCR_EN_OSC4, RNG_NSCR_EN_OSC5 and RNG_NSCR_EN_OSC6 defines
-	Add USART_DMAREQUESTS_SW_WA define
-	Rename EXTI_RTSR2_TR to EXTI_RTSR2_RT define
-	Rename EXTI_FTSR2_TR to EXTI_FTSR2_FT define
-   Remove unused ADC common status and ADC common group regular data registers for STM32H503xx devices
-   Fix __SAUREGION_PRESENT value to 0 for STM32H503xx devices
-   Fix incorrect character in the definition of OCTOSPI_CR register
-   Correct TIM_CCRx_CCRx constants

## Known limitations

-	None

</div>


<label for="collapse-section3" aria-hidden="true">__V1.2.0 / 09-February-2024__</label>
<div>

## Main Changes

-   First official release of STM32H5xx CMSIS drivers to support **STM32H533xx and STM32H523xx** devices
-	Add bit definition for I3C_BCR register
-	Add IS_DMA_PFREQ_INSTANCE macro
-	Fix Ticket 163445: [FLASH][CMSIS] Wrong EDATA_STRT start sectors mask size
-	Fix Ticket 163090: [FOSS-Audit] Licensing issues: Missing copyright from Arm Limited and original header not retained
-	Update CubeIDE projects to be compliant with GCC12 diagnostics
-	Fix Ticket 165407: [H5][GTZC][CMSIS]: wrong Flash illegal access bit definition
-	Fix Ticket 147880: [STM32H5]|FLASH_HAL] Some option bytes are missing in stm32h5xx_hal_flash_ex.h
-	Set FMC_SDCMR_MODE_2 bit field definition to 0x4
-	Fix Ticket 162902: [GitHub] Wrong declaration of g_pfnVectors size in gcc/startup files
-	Fix: Ticket 167776: [CMSIS] Missing TIM option register related definitions

## Known limitations

-	None

</div>

<label for="collapse-section2" aria-hidden="true">__V1.1.0 / 07-June-2023__</label>
<div>

## Main Changes

-   Add DUA addresses constants definitions for STM32H573xx devices only
-	Fix wrong definition of IS_TIM_CLOCKSOURCE_TIX_INSTANCE & IS_TIM_TISEL_INSTANCE macros
-	Update possible values of the ATCKSEL field of TAMP active tamper control register and update the mask accordingly.

## Known limitations

-	None

</div>

<label for="collapse-section1" aria-hidden="true">__V1.0.0 / 10-February-2023__</label>
<div>

## Main Changes

-	First official release version of bits and registers definition aligned with RM0481 and RM0492 (STM32H5 reference manuals)

## Known limitations

-	None

</div>


For complete documentation on STM32 Microcontrollers </mark> ,
visit: http://www.st.com/stm32
