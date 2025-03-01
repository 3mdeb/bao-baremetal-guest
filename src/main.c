/** 
 * Bao, a Lightweight Static Partitioning Hypervisor 
 *
 * Copyright (c) Bao Project (www.bao-project.org), 2019-
 *
 * Authors:
 *      Jose Martins <jose.martins@bao-project.org>
 *      Sandro Pinto <sandro.pinto@bao-project.org>
 *
 * Bao is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License version 2 as published by the Free
 * Software Foundation, with a special exception exempting guest code from such
 * license. See the COPYING file in the top-level directory for details. 
 *
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
#include <uart.h>
#include <timer.h>

#define TIMER_INTERVAL (TIME_S(1))

void uart_rx_handler(){
    printf("cpu0: \n");
    uart_clear_rxirq();
}

void timer_handler(){
    printf("cpu0: \n");
}

void main(void)
{
    printf("Bao bare-metal test guest\n");

    irq_set_handler(UART_IRQ_ID, uart_rx_handler);
    irq_set_handler(TIMER_IRQ_ID, timer_handler);

    uart_enable_rxirq();

    timer_set(TIMER_INTERVAL);
    irq_enable(TIMER_IRQ_ID);
    irq_set_prio(TIMER_IRQ_ID, IRQ_MAX_PRIO);

    irq_enable(UART_IRQ_ID);
    irq_set_prio(UART_IRQ_ID, IRQ_MAX_PRIO);

    printf("cpu 0 up\n");

    while(1) wfi();
    while(1);
}
