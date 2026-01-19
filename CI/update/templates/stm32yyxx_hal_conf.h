#ifndef __STM32{{series}}{{nx}}_HAL_CONF_H
#define __STM32{{series}}{{nx}}_HAL_CONF_H

#include "variant.h"

/* STM32{{series}}{{nx}} specific HAL configuration options. */
#if __has_include("hal_conf_custom.h")
#include "hal_conf_custom.h"
#else
#if __has_include("hal_conf_extra.h")
#include "hal_conf_extra.h"
#endif
#include "stm32{{series.lower()}}{{nx}}_hal_conf_default.h"
#endif

#endif /* __STM32{{series}}{{nx}}_HAL_CONF_H */
