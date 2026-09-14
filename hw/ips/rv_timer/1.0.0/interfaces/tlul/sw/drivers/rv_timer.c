#include "rv_timer.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(uintptr_t)(addr)) = (uint32_t)(val))
#define DEV_READ(addr) (*((volatile uint32_t *)(uintptr_t)(addr)))

int rv_timer_init(rv_timer_t base) {
#ifdef RV_TIMER_CTRL_REG_OFFSET
  DEV_WRITE(base + RV_TIMER_CTRL_REG_OFFSET, 0x1u);
#else
  DEV_WRITE(base + 0x0u, 0x1u);
#endif
  return 0;
}

int rv_timer_in(rv_timer_t base) {
#ifdef RV_TIMER_RDATA_REG_OFFSET
  return (int)DEV_READ(base + RV_TIMER_RDATA_REG_OFFSET);
#else
  return (int)DEV_READ(base + 0x0u);
#endif
}

void rv_timer_out(rv_timer_t base, char c) {
#ifdef RV_TIMER_WDATA_REG_OFFSET
  DEV_WRITE(base + RV_TIMER_WDATA_REG_OFFSET, (uint32_t)(uint8_t)c);
#else
  DEV_WRITE(base + 0x0u, (uint32_t)(uint8_t)c);
#endif
}

int rv_timer_putchar(int c) {
  rv_timer_out((rv_timer_t)RV_TIMER_BASE, (char)c);
  return c;
}

int rv_timer_puts(const char* str) {
  while (*str) {
    rv_timer_putchar(*str++);
  }
  return 0;
}
