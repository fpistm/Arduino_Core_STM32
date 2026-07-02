

# Release Notes for
# <mark>STM32WL3xx CMSIS</mark>
Copyright &copy; 2024-2026 STMicroelectronics\

[![ST logo](_htmresc/st_logo_2020.png)](https://www.st.com)

# Purpose

This driver provides the CMSIS device for the STM32WL3xx products. This covers

- STM32WL33x devices
- STM32WL3Rx devices

This driver is composed of the description of the registers under "Include" directory.

Various template files are provided to easily build an application. They can be adapted to fit applications requirements.

- Templates/system_stm32wl3x.c contains the initialization code referred as SystemInit.
- Startup files are provided as example for EWARM&copy;, MDK-ARM&copy; and STM32CubeIDE.
- Linker files are provided as example for EWARM&copy;, MDK-ARM&copy; and STM32CubeIDE.


# Update history

<label for="collapse-section8" aria-hidden="true"> __V1.5.0 / 05-June-2026__ </label>
<div>

## Main Changes
- ENGTRIM2 register removed.
- DBGSMPS register exposed.
- System initialization template file updated, adding a macro to skip CPU context restore.
- Added linker file templates for WL30xx and WL31xx devices.

## Known Limitations
- None

## Development Toolchains and Compilers
- IAR Embedded Workbench for ARM (EWARM) toolchain V9.30.1

## Supported Devices and boards
- STM32WL3xx devices
</div>

<label for="collapse-section7" aria-hidden="true"> __V1.4.0 / 04-February-2026__ </label>
<div>

## Main Changes
- AGC_ANA_ENG register exposed.
- typo fixed on a register bit macro ("nAND" replaced by "NAND")

## Known Limitations
- None

## Development Toolchains and Compilers
- IAR Embedded Workbench for ARM (EWARM) toolchain V9.30.1

## Supported Devices and boards
- STM32WL3xx devices
</div>

<label for="collapse-section6" aria-hidden="true"> __V1.3.1 / 20-November-2025__ </label>
<div>

## Main Changes
- Added missing I2S support on WL3Rx devices (stm32wl3rx.h)

## Known Limitations
- None

## Development Toolchains and Compilers
- IAR Embedded Workbench for ARM (EWARM) toolchain V9.30.1

## Supported Devices and boards
- STM32WL3xx devices

</div>

<label for="collapse-section5" aria-hidden="true"> __V1.3.0 / 29-October-2025__ </label>
<div>

## Main Changes
- Added support to STM32WL3Rx product line.
- [LCSC] LCSC_VER register removed from the accessible register list, as it is Non-User.
- [LCSC] Fixed a typo on an LCSC register name (COMP_CTN  -> COMP_CNT)
- [MRSUBG] RSSI_FLT bit #3 renamed to <code>FREEZE_SYNC_ON_SYNC_OOK_PEAK_DECAY</code>

## Known Limitations
- None

## Development Toolchains and Compilers
- IAR Embedded Workbench for ARM (EWARM) toolchain V9.30.1

## Supported Devices and boards
- STM32WL3xx devices

</div>

<label for="collapse-section3" aria-hidden="true"> __V1.2.0 / 04-June-2025__ </label>
<div>

## Main Changes
- Documentation based on jQuery 1.7.1 removed

## Contents

- Add PULSETRIM bits definition in CMSIS header files
- Renamed some interrupt to improve clarity and consistency
- Added FQCY_BAND_ID bits definition for RF_INFO_OUT register

## Known Limitations

- CMSIS devices files are delivered "as is" and have not been fully validated

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V9.30.1

## Supported Devices and boards

- STM32WL3xx devices

</div>

<label for="collapse-section2" aria-hidden="true"> __V1.1.0 / 05-February-2025__ </label>
<div>

## Main Changes

### Release

- Release of CMSIS for STM32WL3xx devices

## Contents

- CMSIS devices files for STM32WL3xx

## Known Limitations

- CMSIS devices files are delivered "as is" and have not been fully validated

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V9.30.1

## Supported Devices and boards

- STM32WL3xx devices

</div>

<label for="collapse-section1" aria-hidden="true"> __V1.0.0 / 30-October-2024__ </label>
<div>

## Main Changes

### First  Release

- First Official Release of CMSIS for STM32WL33x devices

## Contents

- CMSIS devices files for STM32WL33x

## Known Limitations

- CMSIS devices files are delivered "as is" and have not been fully validated

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V9.30.1

## Supported Devices and boards

- STM32WL33x devices

</div>


For complete documentation on STM32 Microcontrollers </mark>, visit: http://www.st.com/stm32

*This release note uses up to date web standards and, for this reason, should not be opened with Internet Explorer but preferably with popular browsers such as Google Chrome, Mozilla Firefox, Opera or Microsoft Edge.*
<abbr title="Based on template cx566953 version 2.0">Info</abbr>