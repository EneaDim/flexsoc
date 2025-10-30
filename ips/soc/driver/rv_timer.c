#include "rv_timer.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(addr)) = (val))
#define DEV_READ(addr) (*((volatile uint32_t *)(addr)))

int rv_timer_init(rv_timer_t rv_timer) {
  DEV_WRITE(rv_timer + RV_TIMER_CTRL_REG_OFFSET, 0x1);
  return 0;
}

int rv_timer_in(rv_timer_t rv_timer) {
  int res = -1;
  res = DEV_READ(rv_timer + RV_TIMER_RDATA_REG_OFFSET);
  return res;
}

void rv_timer_out(rv_timer_t rv_timer, char c) {
  DEV_WRITE(rv_timer + RV_TIMER_WDATA_REG_OFFSET, c);
}

int rv_timer_putchar(int c) {
  rv_timer_out((rv_timer_t) RV_TIMER_BASE, c);
  return c;
}

int rv_timer_puts(const char* str) {
  while (*str) {
    rv_timer_putchar(*str++);
  }
  return 0;
}