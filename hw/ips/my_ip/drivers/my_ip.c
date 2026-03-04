#include "my_ip.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(addr)) = (val))
#define DEV_READ(addr) (*((volatile uint32_t *)(addr)))

int my_ip_init(my_ip_t my_ip) {
  DEV_WRITE(my_ip + MY_IP_CTRL_REG_OFFSET, 0x1);
  return 0;
}

int my_ip_in(my_ip_t my_ip) {
  int res = -1;
  res = DEV_READ(my_ip + MY_IP_RDATA_REG_OFFSET);
  return res;
}

void my_ip_out(my_ip_t my_ip, char c) {
  DEV_WRITE(my_ip + MY_IP_WDATA_REG_OFFSET, c);
}

int my_ip_putchar(int c) {
  my_ip_out((my_ip_t) MY_IP_BASE, c);
  return c;
}

int my_ip_puts(const char* str) {
  while (*str) {
    my_ip_putchar(*str++);
  }
  return 0;
}