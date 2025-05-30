/**
  ******************************************************************************
  * @file    uart.h
  * @author  WI6LABS, fpistm
  * @brief   Header for uart module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __UART_H
#define __UART_H

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include "stm32_def.h"
#include "PinNames.h"

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(HAL_UART_MODULE_ENABLED) || defined(HAL_UART_MODULE_ONLY)
#define serial_t void*
#else

#ifndef UART_IRQ_PRIO
#define UART_IRQ_PRIO       1
#endif
#ifndef UART_IRQ_SUBPRIO
#define UART_IRQ_SUBPRIO    0
#endif

/* Exported types ------------------------------------------------------------*/
typedef struct serial_s serial_t;

struct serial_s {
  /*  The 1st 2 members USART_TypeDef *uart
   *  and UART_HandleTypeDef handle should
   *  be kept as the first members of this struct
   *  to have get_serial_obj() function work as expected
   */
  USART_TypeDef *uart;
  UART_HandleTypeDef handle;
  void (*rx_callback)(serial_t *);
  int (*tx_callback)(serial_t *);
  PinName pin_tx;
  PinName pin_rx;
  PinName pin_rts;
  PinName pin_cts;
  IRQn_Type irq;
  uint8_t index;
  uint8_t recv;
  uint8_t *rx_buff;
  uint8_t *tx_buff;
  uint16_t rx_tail;
  uint16_t tx_head;
  volatile uint16_t rx_head;
  volatile uint16_t tx_tail;
  size_t tx_size;
};

/* Exported constants --------------------------------------------------------*/
#ifndef TX_TIMEOUT
#define TX_TIMEOUT  1000
#endif

#if !defined(RCC_USART1CLKSOURCE_HSI)
/* Some series like C0 have 2 derivated clock from HSI: HSIKER (for peripherals)
 * and HSISYS (for system clock). But each have a dedicated prescaler.
 * To avoid changing Arduino implementation,
 * remap RCC_USART1CLKSOURCE_HSI to RCC_USART1CLKSOURCE_HSIKER
 */
#define RCC_USART1CLKSOURCE_HSI RCC_USART1CLKSOURCE_HSIKER
#endif

#if defined(USART2_BASE) && !defined(USART2_IRQn)
#if defined(STM32G0xx) || defined(STM32U0xx)
#if defined(LPUART2_BASE)
#define USART2_IRQn USART2_LPUART2_IRQn
#define USART2_IRQHandler USART2_LPUART2_IRQHandler
#endif
#endif /* STM32G0xx */
#endif

#if defined(USART3_BASE) && !defined(USART3_IRQn)
#if defined(STM32F0xx)
#if defined(STM32F091xC) || defined (STM32F098xx)
#define USART3_IRQn USART3_8_IRQn
#define USART3_IRQHandler USART3_8_IRQHandler
#elif defined(STM32F030xC)
#define USART3_IRQn USART3_6_IRQn
#define USART3_IRQHandler USART3_6_IRQHandler
#else
#define USART3_IRQn USART3_4_IRQn
#define USART3_IRQHandler USART3_4_IRQHandler
#endif /* STM32F091xC || STM32F098xx */
#elif defined(STM32G0xx) || defined(STM32C0xx)
#if defined(LPUART2_BASE)
#define USART3_IRQn USART3_4_5_6_LPUART1_IRQn
#define USART3_IRQHandler USART3_4_5_6_LPUART1_IRQHandler
#elif defined(LPUART1_BASE)
#define USART3_IRQn USART3_4_LPUART1_IRQn
#define USART3_IRQHandler USART3_4_LPUART1_IRQHandler
#elif defined(USART5_BASE)
#define USART3_IRQn USART3_4_5_6_IRQn
#define USART3_IRQHandler USART3_4_5_6_IRQHandler
#else
#define USART3_IRQn USART3_4_IRQn
#define USART3_IRQHandler USART3_4_IRQHandler
#endif
#elif defined(STM32U0xx)
#define USART3_IRQn USART3_LPUART1_IRQn
#define USART3_IRQHandler USART3_LPUART1_IRQHandler
#endif /* STM32F0xx */
#endif

#if defined(USART4_BASE) && !defined(USART4_IRQn)
#if defined(STM32F0xx)
/* IRQHandler is mapped on USART3_IRQHandler for STM32F0xx */
#if defined(STM32F091xC) || defined (STM32F098xx)
#define USART4_IRQn USART3_8_IRQn
#elif defined(STM32F030xC)
#define USART4_IRQn USART3_6_IRQn
#else
#define USART4_IRQn USART3_4_IRQn
#endif /* STM32F091xC || STM32F098xx */
#elif defined(STM32L0xx)
#define USART4_IRQn USART4_5_IRQn
#elif defined(STM32G0xx) || defined(STM32C0xx)
#if defined(LPUART2_BASE)
#define USART4_IRQn USART3_4_5_6_LPUART1_IRQn
#elif defined(LPUART1_BASE)
#define USART4_IRQn USART3_4_LPUART1_IRQn
#elif defined(USART5_BASE)
#define USART4_IRQn USART3_4_5_6_IRQn
#else
#define USART4_IRQn USART3_4_IRQn
#endif
#elif defined(STM32U0xx)
#if defined(LPUART3_BASE)
#define USART4_IRQn USART4_LPUART3_IRQn
#define USART4_IRQHandler USART4_LPUART3_IRQHandler
#endif /* LPUART3_BASE */
#endif /* STM32G0xx */
#endif

#if defined(USART5_BASE) && !defined(USART5_IRQn)
#if defined(STM32F0xx)
/* IRQHandler is mapped on USART3_IRQHandler for STM32F0xx */
#if defined(STM32F091xC) || defined (STM32F098xx)
#define USART5_IRQn USART3_8_IRQn
#elif defined(STM32F030xC)
#define USART5_IRQn USART3_6_IRQn
#endif /* STM32F091xC || STM32F098xx */
#elif defined(STM32G0xx)
#if defined(LPUART2_BASE)
#define USART5_IRQn USART3_4_5_6_LPUART1_IRQn
#elif defined(USART5_BASE)
#define USART5_IRQn USART3_4_5_6_IRQn
#endif
#elif defined(STM32L0xx)
#define USART5_IRQn USART4_5_IRQn
#endif /* STM32F0xx */
#endif

/* IRQHandler is mapped on USART3_IRQHandler for STM32F0xx */
#if defined(USART6_BASE) && !defined(USART6_IRQn)
#if defined (STM32F0xx)
#if defined(STM32F091xC) || defined (STM32F098xx)
#define USART6_IRQn USART3_8_IRQn
#elif defined(STM32F030xC)
#define USART6_IRQn USART3_6_IRQn
#endif /* STM32F091xC || STM32F098xx */
#elif defined(STM32G0xx)
#if defined(LPUART2_BASE)
#define USART6_IRQn USART3_4_5_6_LPUART1_IRQn
#elif defined(USART5_BASE)
#define USART6_IRQn USART3_4_5_6_IRQn
#endif
#endif /* STM32F0xx */
#endif

#if defined(USART7_BASE) && !defined(USART7_IRQn)
#if defined (STM32F0xx)
#if defined(STM32F091xC) || defined (STM32F098xx)
#define USART7_IRQn USART3_8_IRQn
#endif /* STM32F091xC || STM32F098xx */
#endif /* STM32F0xx */
#endif

#if defined(USART8_BASE) && !defined(USART8_IRQn)
#if defined (STM32F0xx)
#if defined(STM32F091xC) || defined (STM32F098xx)
#define USART8_IRQn USART3_8_IRQn
#endif /* STM32F091xC || STM32F098xx */
#endif /* STM32F0xx */
#endif

#if defined(LPUART1_BASE) && !defined(LPUART1_IRQn)
#if defined(STM32G0xx)
#if defined(LPUART2_BASE)
#define LPUART1_IRQn USART3_4_5_6_LPUART1_IRQn
#elif defined(USART3_BASE)
#define LPUART1_IRQn USART3_4_LPUART1_IRQn
#endif
#endif /* STM32G0xx */
#if defined(STM32U0xx)
#define LPUART1_IRQn USART3_LPUART1_IRQn
#endif /* STM32U0xx */
#endif

#if defined(LPUART2_BASE) && !defined(LPUART2_IRQn)
#if defined(STM32G0xx)
#if defined(LPUART2_BASE)
#define LPUART2_IRQn USART2_LPUART2_IRQn
#endif
#endif /* STM32G0xx */
#if defined(STM32U0xx)
#define LPUART2_IRQn USART2_LPUART2_IRQn
#endif /* STM32U0xx */
#endif

#if defined(LPUART3_BASE) && !defined(LPUART3_IRQn)
#if defined(STM32U0xx)
#define LPUART3_IRQn USART4_LPUART3_IRQn
#endif /* STM32U0xx */
#endif

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
bool uart_init(serial_t *obj, uint32_t baudrate, uint32_t databits, uint32_t parity, uint32_t stopbits, bool rx_invert, bool tx_invert, bool data_invert);
void uart_deinit(serial_t *obj);
#if defined(HAL_PWR_MODULE_ENABLED) && (defined(UART_IT_WUF) || defined(LPUART1_BASE))
void uart_config_lowpower(serial_t *obj);
#endif
int uart_getc(serial_t *obj, unsigned char *c);
void uart_attach_rx_callback(serial_t *obj, void (*callback)(serial_t *));
void uart_attach_tx_callback(serial_t *obj, int (*callback)(serial_t *), size_t size);

uint8_t serial_tx_active(serial_t *obj);
uint8_t serial_rx_active(serial_t *obj);

void uart_enable_tx(serial_t *obj);
void uart_enable_rx(serial_t *obj);

size_t uart_debug_write(uint8_t *data, uint32_t size);

#endif /* HAL_UART_MODULE_ENABLED  && !HAL_UART_MODULE_ONLY */
#ifdef __cplusplus
}
#endif

#endif /* __UART_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
