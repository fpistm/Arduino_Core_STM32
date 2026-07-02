

# Release Notes for
# <mark>STM32WBAxx CMSIS</mark>
Copyright &copy; 2022-2025 STMicroelectronics\

[![ST logo](_htmresc/st_logo_2020.png)](https://www.st.com)

# Purpose

This driver provides the CMSIS device for the STM32WBAxx products. This covers

- STM32WBA20xx devices
- STM32WBA23xx devices
- STM32WBA25xx devices
- STM32WBA50xx devices
- STM32WBA52xx devices
- STM32WBA54xx devices
- STM32WBA55xx devices
- STM32WBA5Mxx devices
- STM32WBA62xx devices
- STM32WBA63xx devices
- STM32WBA64xx devices
- STM32WBA65xx devices
- STM32WBA6Mxx devices

This driver is composed of the description of the registers under "Include" directory.

Various template file are provided to easily build an application. They can be adapted to fit applications requirements.

- Templates/system_stm32wbaxx.c contains the initialization code referred as SystemInit.
- Startup files are provided as example for EWARM&copy;, MDK-ARM&copy;, STM32CubeIDE&copy;.
- Linker files are provided as example for EWARM&copy;, MDK-ARM&copy;, STM32CubeIDE&copy;.

# Update History

<label for="collapse-section14" aria-hidden="true">V1.10.0 / 03-June-2026</label>
<div>

## Main Changes

### Official Release of **STM32CubeWBA** Firmware package supporting **STM32WBA2x**, **STM32WBA5x** and **STM32WBA6x** devices

## Contents

### Official Release of **CMSIS devices** drivers supporting **STM32WBA2x**, **STM32WBA5x** and **STM32WBA6x** devices

- Fixed Error in USB_OTG_GCCFG_FSVMINUS_Msk definition
- Updated registers and bit definition after update to RNG4.4


## Known Limitations

- None

## Dependencies

- None

## Notes

- None

</div>

<label for="collapse-section13" aria-hidden="true">__V1.9.0 / 20-January-2026__</label>
<div>

## Main Changes

### Official Release of **STM32CubeWBA** Firmware package supporting **STM32WBA2x**, **STM32WBA5x** and **STM32WBA6x** devices

## Contents

### Official Release of **CMSIS devices** drivers supporting **STM32WBA2x**, **STM32WBA5x** and **STM32WBA6x** devices

- Add support of STM32WBA2xx devices
- Update CMSIS devices drivers to include latest corrections
  - Set stack limit (MSPLIM) in CMSIS Device templates
  - Add missing NSCR feature
  - Update IS_USART_<feature>_INSTANCE() macros with USART3 if available


## Known Limitations

- None

## Dependencies

- None

## Notes

- None

</div>

<label for="collapse-section12" aria-hidden="true">__V1.8.0 / 7-October-2025__</label>
<div>

## Main Changes

### Official Release of **STM32CubeWBA** Firmware package supporting **STM32WBA5x** and **STM32WBA6x** devices

## Contents

### Official Release of **CMSIS devices** drivers supporting **STM32WBA5x** and **STM32WBA6x** devices

- Update CMSIS devices drivers to include latest corrections
  - Update DMA request field to cover all possible requests
  - For WBA50, map only heap and stack in SRAM1, remaining data in SRAM2


## Known Limitations

- None

## Dependencies

- None

## Notes

- None

</div>

<label for="collapse-section11" aria-hidden="true">__V1.7.0 / 23-May-2025__</label>
<div>

## Main Changes

### Official Release of **STM32CubeWBA** Firmware package supporting **STM32WBA5x** and **STM32WBA6x** devices

## Contents

###  Official Release of **CMSIS devices** drivers supporting **STM32WBA5x** and **STM32WBA6x** devices

- Update CMSIS devices drivers to add STM32WBA6M
- Update CMSIS devices drivers to include latest corrections
  - New VTOR management based on information from the linker files
  - MISRA-C 2012 warnings correction due to IAR version change
  - Activate LSI2 feature on WBA50/52
  - Add missing RNG busy bit define for WBA6 devices
  - Update linker files to split RAM area between SRAM1 and SRAM2
  - Add missing SPI2 in macro SPI for WBA6 devices


## Known Limitations

- None

## Dependencies

- None

## Notes

- None

</div>

<label for="collapse-section10" aria-hidden="true">__V1.6.0 / 07-February-2025__</label>
<div>

## Main Changes

### Official Release of **STM32CubeWBA** Firmware package supporting **STM32WBA5x** and **STM32WBA6x** devices

## Contents

###  Official Release of **CMSIS devices** drivers supporting **STM32WBA5x** and **STM32WBA6x** devices

- Update CMSIS devices drivers to add STM32WBA6x
- Update CMSIS devices drivers to include latest corrections
  - Workaround for VREF_BUF issue : VREF_BUFF cannot be trimmed by EngiBit (refer to Errata Sheet)


## Known Limitations

- None

## Dependencies

- None

## Notes

- None

</div>

<label for="collapse-section9" aria-hidden="true">__V1.5.0 / 22-October-2024__</label>
<div>

## Main Changes

### Official Release of **STM32CubeWBA** Firmware package supporting **STM32WBA50xx**, **STM32WBA52xx**, **STM32WBA54xx**, **STM32WBA55xx** and **STM32WBA5Mxx** devices

## Contents

###  Official Release of **CMSIS devices** drivers supporting **STM32WBA50xx**, **STM32WBA52xx**, **STM32WBA54xx**, **STM32WBA55xx** and **STM32WBA5Mxx** devices

- Update CMSIS device to add STM32WBA5Mxx devices
- Update CMSIS device to include latest corrections
  - Additional TAMP register bit ATCKSEL[3] inside TAMP_ATCR1
  - Update to use #include \"core_cm33.h\" instead of #include <core_cm33.h> to force the first searches for the core_cm33.h file in the same directory as the file that contains the #include directive (Drivers\\CMSIS\\Core\\Include)



## Known Limitations

- None

## Dependencies

- None

## Notes

- None

</div>

<label for="collapse-section8" aria-hidden="true">__V1.4.0 / 05-June-2024__</label>
<div>

## Main Changes

### Official Release of **STM32CubeWBA** Firmware package supporting **STM32WBA50xx**, **STM32WBA52xx**, **STM32WBA54xx** and **STM32WBA55xx** devices

## Contents

###  Official Release of **CMSIS devices** drivers supporting **STM32WBA50xx**, **STM32WBA52xx**, **STM32WBA54xx** and **STM32WBA55xx** devices

- Update CMSIS devices to include latest corrections
  - Properly mark sections readonly for GCC
  - Add RNG (CR, HTCR) Nist Compliance Values
  - Update IS_TIM_OCXREF_CLEAR_INSTANCE macro to support of TIM16/TIM17


## Known Limitations

- None

## Dependencies

- None

## Notes

- None

</div>

<label for="collapse-section7" aria-hidden="true">__V1.3.0 / 07-February-2024__</label>
<div>

## Main Changes

### Official Release of **STM32CubeWBA** Firmware package supporting **STM32WBA52xx** and **STM32WBA55xx** devices

## Contents

###  Official Release of **CMSIS devices** drivers supporting **STM32WBA52xx** and **STM32WBA55xx** devices

- Update CMSIS devices to include latest corrections
  - Update IS_TIM_32B_COUNTER_INSTANCE macro to remove 16-bit counter TIM3
  - Update IS_TIM_OCXREF_CLEAR_INSTANCE macro as feature is supported by  TIM16 and TIM17
  - Add IS_TIM_OCCS_INSTANCE macro for Secure context


## Known Limitations

- None

## Dependencies

- None

## Notes

- None

</div>

<label for="collapse-section6" aria-hidden="true">__V1.2.0 / 02-November-2023__</label>
<div>

## Main Changes

### Official Release of **STM32CubeWBA** Firmware package supporting **STM32WBA52xx** and **STM32WBA55xx** devices

## Contents

###  Official Release of **CMSIS devices** drivers supporting **STM32WBA52xx** and **STM32WBA55xx** devices

- Update CMSIS devices to include latest corrections
  - Add support of WKUP_S_IRQn and RCC_AUDIOSYNC_IRQn interrupts in CMSIS devices, startup_stm32wba5xxx.s and partition_stmwba5xxx.h files
  - Update Licensing header in partition_stm325xxx.h files based on partition_ARMCM33.h
  - Update declaration of g_pfnVectors size in gcc/startup_stm32wba5xxx.s files


## Known Limitations

- None

## Dependencies

- None

## Notes

- None

</div>

<label for="collapse-section5" aria-hidden="true">__V1.1.0 / 06-June-2023__</label>
<div>

## Main Changes

###  Official Release of **STM32CubeWBA** Firmware package supporting **STM32WBA52xx** devices

## Contents

###  Official Release of **CMSIS devices** drivers supporting **STM32WBA52xx** devices

- Update CMSIS devices to include latest corrections
  - Align SAU region end address on Flash end address


## Known Limitations

- None

## Dependencies

- None

## Notes

- None

</div>

<label for="collapse-section4" aria-hidden="true">__V1.0.0 / 08-February-2023__</label>
<div>

## Main Changes

###  First Official Release of **STM32CubeWBA** Firmware package supporting **STM32WBA52xx** devices

## Contents

- First official release of CMSIS devices drivers
  - Support of STM32WBA52xx devices

## Known Limitations

- None

## Dependencies

- None

## Notes

- None

</div>


For complete documentation on STM32WBAxx,
visit: [www.st.com/stm32wba](http://www.st.com/stm32wba)

*This release note uses up to date web standards and, for this reason, should not be opened with Internet Explorer but preferably with popular browsers such as Google Chrome, Mozilla Firefox, Opera or Microsoft Edge.*
<abbr title="Based on template cx566953 version 2.0">Info</abbr>