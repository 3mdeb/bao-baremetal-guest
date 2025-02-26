#ifndef ARCH_CPU_H
#define ARCH_CPU_H

#include <core.h>
#include <sysregs.h>

static inline unsigned long get_cpuid(){
    return scb->cpuid;
}

static bool cpu_is_master() {
    return true;
}

#endif
