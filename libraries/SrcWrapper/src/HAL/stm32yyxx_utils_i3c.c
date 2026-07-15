/* HAL raised several warnings, ignore them */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#ifdef STM32C5xx
  #include "stm32_utils_i3c.c"
#endif
#pragma GCC diagnostic pop
