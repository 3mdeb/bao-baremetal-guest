#ifndef PLAT_H
#define PLAT_H

#define PLAT_NON_UNIFIED_MEM

#define PLAT_CODE_MEM_BASE  0x40000
#define PLAT_CODE_MEM_SIZE  0x10000

#define PLAT_MEM_BASE       0x20030000
#define PLAT_MEM_SIZE       0x8000

#define STACK_SIZE          0x4000

#define PLAT_TIMER_FREQ     216000000UL

#define PLAT_UART_ADDR      0x40087000
#define UART_IRQ_ID         30

#define PLAT_MAX_INTERRUPTS 75

#endif
