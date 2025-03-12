#ifndef PLAT_H
#define PLAT_H

#include <sysregs.h>

#define PLAT_NON_UNIFIED_MEM

#define PLAT_CODE_MEM_BASE  0x20000
#define PLAT_CODE_MEM_SIZE  0x10000

#define PLAT_MEM_BASE       0x20010000
#define PLAT_MEM_SIZE       0x8000

#define STACK_SIZE          0x4000

#define PLAT_TIMER_FREQ     12000000ULL

#define PLAT_UART_ADDR      0x40088000UL
#define UART_IRQ_ID         16+EXT_INT_BASE

#define PLAT_MAX_INTERRUPTS 75

#endif
