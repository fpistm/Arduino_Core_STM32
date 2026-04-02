/* HAL raised several warnings, ignore them */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#ifdef STM32C5xx
  #include "stm32c5xx_hal_crs.c"
#endif
#pragma GCC diagnostic pop
