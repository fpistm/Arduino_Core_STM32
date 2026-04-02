# STM32C5xx HAL Drivers Software Pack

![tag](https://img.shields.io/badge/tag-2.0.0-brightgreen.svg)
[![release note](https://img.shields.io/badge/release_note-view_html-gold.svg)](https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32c5xx-drivers/blob/main/Release_Notes.html)

## Overview

The Portable APIs layer (HAL and Low-Layer drivers) provides a generic, multi-instance, and simple set of APIs to interact with the upper layer (application, libraries, and stacks). It is composed of an API set that is directly built around a generic architecture and allows built-on layers, like the middleware layer, to implement its functions without knowing in depth the underlying STM32 device. This improves library code reusability and guarantees easy portability to other devices and STM32 families.

The HAL drivers must offer a rich set of APIs to interact easily with the application upper layers. Each driver consists of a set of functions covering the full peripheral features. The development of each driver is driven by a common API, which standardizes the driver structure, the functions, and the parameter names.

## Description and Usage

While keeping the same programming model, the new version of HAL (v2.x), named HAL2, brings the following enhancements:

- A lower footprint,
- Enhanced intuitiveness and usability,
- Finer service granularity,
- Improved integration with RTOS environments,
- HAL API built on top of LL API, enabling faster optimization,
- Enhanced quality, with code developed in compliance with MISRA C®:2012 guidelines, elimination of possible runtime errors with Synopsys® Coverity® static analysis tool, and code coverage by running tests on STM32 hardware with the LDRA® dynamic analysis tool.
