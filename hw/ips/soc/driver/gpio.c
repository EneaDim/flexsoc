#include "gpio.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(addr)) = (val))
#define DEV_READ(addr) (*((volatile uint32_t *)(addr)))

int gpio_init(gpio_t gpio) {
  DEV_WRITE(gpio + GPIO_CTRL_REG_OFFSET, 0x1);
  return 0;
}

int gpio_in(gpio_t gpio) {
  int res = -1;
  res = DEV_READ(gpio + GPIO_RDATA_REG_OFFSET);
  return res;
}

void gpio_out(gpio_t gpio, char c) {
  DEV_WRITE(gpio + GPIO_WDATA_REG_OFFSET, c);
}

int gpio_putchar(int c) {
  gpio_out((gpio_t) GPIO_BASE, c);
  return c;
}

int gpio_puts(const char* str) {
  while (*str) {
    gpio_putchar(*str++);
  }
  return 0;
}