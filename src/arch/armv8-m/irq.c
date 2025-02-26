/**
 * SPDX-License-Identifier: Apache-2.0U
 * Copyright (c) Bao Project and Contributors. All rights reserved.
 */

#include <irq.h>
#include <cpu.h>
#include <nvic.h>

void irq_enable(unsigned id)
{
    nvic_set_enable(id, true);
}

void irq_set_prio(unsigned id, unsigned prio)
{
    nvic_set_prio(id, (uint8_t) prio);
}

void irq_send_ipi(unsigned long target_cpu_mask)
{
    (void)(target_cpu_mask);
}
