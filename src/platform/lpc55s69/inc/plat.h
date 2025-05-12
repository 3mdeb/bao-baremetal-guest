#ifndef PLAT_H
#define PLAT_H

#include <sysregs.h>
#include <iocon.h>
#include <syscon.h>

#define PLAT_NON_UNIFIED_MEM

#define PLAT_CODE_MEM_BASE  0x20000
#define PLAT_CODE_MEM_SIZE  0x10000

#define PLAT_MEM_BASE       0x20010000
#define PLAT_MEM_SIZE       0x7000

// Select USART2 or USART3 ot be used as console
#define SELECTED_UART       3

#define FLEXCOMM2_ADDR      0x40088000UL
#define FLEXCOMM2_NVIC_IRQ  16
#define FLEXCOMM2_RX_PORT   port1
#define FLEXCOMM2_RX_PIN    pin24
#define FLEXCOMM2_TX_PORT   port0
#define FLEXCOMM2_TX_PIN    pin27

#define FLEXCOMM3_ADDR      0x40089000UL
#define FLEXCOMM3_NVIC_IRQ  17
#define FLEXCOMM3_RX_PORT   port0
#define FLEXCOMM3_RX_PIN    pin03
#define FLEXCOMM3_TX_PORT   port0
#define FLEXCOMM3_TX_PIN    pin02

#if SELECTED_UART == 2
  #define PLAT_UART_ADDR    FLEXCOMM2_ADDR
  #define UART_NVIC_IRQ_ID  FLEXCOMM2_NVIC_IRQ
  #define UART_RX_PORT      FLEXCOMM2_RX_PORT
  #define UART_RX_PIN       FLEXCOMM2_RX_PIN
  #define UART_TX_PORT      FLEXCOMM2_TX_PORT
  #define UART_TX_PIN       FLEXCOMM2_TX_PIN
  #define FCRST             FC2_RST
  #define FCCLKSEL          FCCLKSEL2
  #define SYSCON_AHBCLKTRL1 SYSCON_AHBCLKTRL1_FC2
#elif SELECTED_UART == 3
  #define PLAT_UART_ADDR    FLEXCOMM3_ADDR
  #define UART_NVIC_IRQ_ID  FLEXCOMM3_NVIC_IRQ
  #define UART_RX_PORT      FLEXCOMM3_RX_PORT
  #define UART_RX_PIN       FLEXCOMM3_RX_PIN
  #define UART_TX_PORT      FLEXCOMM3_TX_PORT
  #define UART_TX_PIN       FLEXCOMM3_TX_PIN
  #define FCRST             FC3_RST
  #define FCCLKSEL          FCCLKSEL3
  #define SYSCON_AHBCLKTRL1 SYSCON_AHBCLKTRL1_FC3
#else
  #error "Invalid SELECTED_UART value"
#endif

#define UART_IRQ_ID         (EXT_INT_BASE + UART_NVIC_IRQ_ID)


#define STACK_SIZE          0x4000

#define PLAT_TIMER_FREQ     12000000ULL

#define PLAT_MAX_INTERRUPTS 75

#endif
