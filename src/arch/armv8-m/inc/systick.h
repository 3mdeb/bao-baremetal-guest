#ifndef SYSTICK_ARCH_H
#define SYSTICK_ARCH_H

#include <sysregs.h>

static inline void systick_set_rvr(uint32_t val)
{
    systick->rvr = val & (0xFFFFFFUL);
}

static inline uint32_t systick_get_rvr(void)
{
    return systick->rvr;
}

static inline uint32_t systick_get_cvr(void)
{
    return systick->cvr;
}

static inline void systick_set_csr(uint32_t val)
{
    systick->csr = val;
}

static inline uint32_t systick_get_csr(void)
{
    return systick->csr;
}

#endif /* SYSTICK_ARCH_H */
