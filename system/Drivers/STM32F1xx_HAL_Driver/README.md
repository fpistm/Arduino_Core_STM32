# STM32CubeF1 HAL Driver MCU Component

![latest tag](https://img.shields.io/github/v/tag/STMicroelectronics/stm32f1xx_hal_driver.svg?color=brightgreen)

## Overview

**STM32Cube** is an STMicroelectronics original initiative to ease the developers' life by reducing efforts, time and cost.

**STM32Cube** covers the overall STM32 products portfolio. It includes a comprehensive embedded software platform, delivered for each STM32 series.
   * The CMSIS modules (core and device) corresponding to the ARM(tm) core implemented in this STM32 product.
   * The STM32 HAL-LL drivers, an abstraction layer offering a set of APIs ensuring maximized portability across the STM32 portfolio.
   * The BSP drivers of each evaluation, demonstration or nucleo board provided for this STM32 series.
   * A consistent set of middleware libraries such as RTOS, USB, FatFS, graphics, touch sensing library...
   * A full set of software projects (basic examples, applications, and demonstrations) for each board provided for this STM32 series.

Two models of publication are proposed for the STM32Cube embedded software:
   * The monolithic **MCU Package**: all STM32Cube software modules of one STM32 series are present (Drivers, Middleware, Projects, Utilities) in the repository (usual name **STM32Cubexx**, xx corresponding to the STM32 series).
   * The **MCU component**: each STM32Cube software module being part of the STM32Cube MCU Package, is delivered as an individual repository, allowing the user to select and get only the required software functions.

## Description

This **stm32f1xx_hal_driver** MCU component repo is one element of the STM32CubeF1 MCU embedded software package, providing the **HAL-LL Drivers** part.

## Release note

Details about the content of this release are available in the release note [here](https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32f1xx_hal_driver/blob/master/Release_Notes.html).

## Compatibility information

In this table, you can find the successive versions of this HAL-LL Driver component, in line with the corresponding versions of the full MCU package:

It is **crucial** that you use a consistent set of versions for the CMSIS Core - CMSIS Device - HAL, as mentioned in this table.

HAL Driver F1 | CMSIS Device F1 | CMSIS Core | Was delivered in the full MCU package
------------- | --------------- | ---------- | -------------------------------------
Tag v1.1.4 | Tag v4.3.1 | Tag v5.4.0_cm3 | Tag v1.8.0 (and following, if any, till next HAL tag)
Tag v1.1.5 | Tag v4.3.1 | Tag v5.4.0_cm3 | Tag v1.8.1 (and following, if any, till next HAL tag)
Tag v1.1.6 | Tag v4.3.2 | Tag v5.4.0_cm3 | Tag v1.8.2 (and following, if any, till next HAL tag)
Tag v1.1.8 | Tag v4.3.2 | Tag v5.4.0_cm3 | Tag v1.8.3 (and following, if any, till next HAL tag)
Tag v1.1.8 | Tag v4.3.3 | Tag v5.4.0_cm3 | Tag v1.8.4 (and following, if any, till next HAL tag)

The full **STM32CubeF1** MCU package is available [here](https://github.com/STMicroelectronics/STM32CubeF1).

## Troubleshooting

Please refer to the [CONTRIBUTING.md](CONTRIBUTING.md) guide.
