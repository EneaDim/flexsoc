#include "ip1.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(addr)) = (val))
#define DEV_READ(addr) (*((volatile uint32_t *)(addr)))

int ip1_init(ip1_t ip1) {
  DEV_WRITE(ip1 + IP1_CTRL_REG_OFFSET, 0x1);
  return 0;
}

int ip1_in(ip1_t ip1) {
  int res = -1;
  res = DEV_READ(ip1 + IP1_RDATA_REG_OFFSET);
  return res;
}

void ip1_out(ip1_t ip1, char c) {
  DEV_WRITE(ip1 + IP1_WDATA_REG_OFFSET, c);
}

int ip1_putchar(int c) {
  ip1_out((ip1_t) IP1_BASE, c);
  return c;
}

int ip1_puts(const char* str) {
  while (*str) {
    ip1_putchar(*str++);
  }
  return 0;
}