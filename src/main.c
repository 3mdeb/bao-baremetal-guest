/**
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) Bao Project and Contributors. All rights reserved.
 */

#include <core.h>
#include <util.h>
#include <stdlib.h>
#include <stdio.h>
#include <cpu.h>
#include <wfi.h>
#include <spinlock.h>
#include <plat.h>
#include <irq.h>
#ifdef ENABLE_UART
#include <uart.h>
#endif
#include <timer.h>
#include <string.h>

#define VM "VM0"
#define IPC_IRQ_ID 78

#define TIMER_INTERVAL      (TIME_MS(1000))

#define BAO_IMAGE_START     0x10000000UL
#define BAO_HC_OFF          0x41UL
#define BAO_HC_ADDR         BAO_IMAGE_START+BAO_HC_OFF
#define BAO_HC_IPC_ID       0x1
#define VMS_IPC_BASE        0x20027000UL
#define VMS_IPC_SIZE        0x1000

void (*bao_hypercall)(unsigned int, unsigned int, unsigned int) =
    (void (*)(unsigned int, unsigned int, unsigned int))BAO_HC_ADDR;

char* const message1 = (char*)VMS_IPC_BASE;
char* const message2 = (char*)VMS_IPC_BASE+VMS_IPC_SIZE/2;
const size_t shmem_channel_size = VMS_IPC_SIZE/2;

void print_message (char * string)
{
#ifdef ENABLE_UART
    while (*string)
        uart_putc(*string++);
#endif
}

void shmem_init(void)
{
    memset(message1, 0, shmem_channel_size);
    memset(message2, 0, shmem_channel_size);
}

void ipc_notify(int ipc_id, int event_id)
{
    bao_hypercall(BAO_HC_IPC_ID, ipc_id, event_id);
}

void ipc_irq_handler(void)
{
    static uint32_t counter = 0;

    printf(VM": IPC Handler\n");
    print_message(message1);
}

#ifdef ENABLE_UART
void uart_rx_handler(void)
{
    printf(VM": UART RX Handler\n");
    uart_clear_rxirq();
}
#endif

void timer_handler(void)
{
    printf(VM": Timer Handler\n");
    ipc_notify(0,0);
}

void ipc_init(void)
{
    irq_enable(IPC_IRQ_ID);
    irq_set_handler(IPC_IRQ_ID, ipc_irq_handler);
}

void main(void)
{
    printf(VM": Bao bare-metal test guest\n");

    shmem_init();

    ipc_init();

#ifdef ENABLE_UART
    irq_set_handler(UART_IRQ_ID, uart_rx_handler);
    uart_enable_rxirq();
    irq_enable(UART_IRQ_ID);
    irq_set_prio(UART_IRQ_ID, IRQ_MAX_PRIO);
#endif
    irq_set_handler(TIMER_IRQ_ID, timer_handler);


    timer_set(TIMER_INTERVAL);
    irq_enable(TIMER_IRQ_ID);
    irq_set_prio(TIMER_IRQ_ID, IRQ_MAX_PRIO);


    while(1) wfi();
}
