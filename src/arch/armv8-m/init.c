
#include <core.h>
#include <cpu.h>
#include <timer.h>
#include <sysregs.h>

void _start();

__attribute__((weak))
void arch_init() { }
