/* HAL raised several warnings, ignore them */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#ifdef STM32H5xx
  #include "stm32h5xx_hal_ccb.c"
#elif STM32U3xx
  #include "stm32u3xx_hal_ccb.c"
#endif
#pragma GCC diagnostic pop
