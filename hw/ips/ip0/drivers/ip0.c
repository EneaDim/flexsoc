#include "ip0.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(addr)) = (val))
#define DEV_READ(addr) (*((volatile uint32_t *)(addr)))

int ip0_init(ip0_t ip0) {
  DEV_WRITE(ip0 + IP0_CTRL_REG_OFFSET, 0x1);
  return 0;
}

int ip0_in(ip0_t ip0) {
  int res = -1;
  res = DEV_READ(ip0 + IP0_RDATA_REG_OFFSET);
  return res;
}

void ip0_out(ip0_t ip0, char c) {
  DEV_WRITE(ip0 + IP0_WDATA_REG_OFFSET, c);
}

int ip0_putchar(int c) {
  ip0_out((ip0_t) IP0_BASE, c);
  return c;
}

int ip0_puts(const char* str) {
  while (*str) {
    ip0_putchar(*str++);
  }
  return 0;
}