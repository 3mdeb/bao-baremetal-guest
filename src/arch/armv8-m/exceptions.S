/**
 * SPDX-License-Identifier: Apache-2.0U
 * Copyright (c) Bao Project and Contributors. All rights reserved.
 */

#include <sysregs.h>
#include <arch/irq.h>

.macro define_handler name
    .thumb
    .thumb_func
    .global \name
    \name:
.endm

.syntax unified
.text

.balign 0x80
.global _exception_vector
_exception_vector:
    .word _stack_top
    .word _start
    .rept 13
    .word _exception_handler
    .endr
    .word _systick_handler
    /* Interrupts */
    .rept IRQ_NUM
    .word _irq_handler
    .endr

/* Handlers */
define_handler _exception_handler
_exception_handler:
    b   .

define_handler _irq_handler
_irq_handler:
    // Get the IRQ number
    mrs r0, IPSR
    lsr r0, r0, #0x2
    // Call the IRQ handler
    b   irq_handle
    b   .

define_handler _systick_handler
_systick_handler:
    // Call the SysTick handler
    mov r0, #TIMER_IRQ_ID
    b   irq_handle
    b   .
