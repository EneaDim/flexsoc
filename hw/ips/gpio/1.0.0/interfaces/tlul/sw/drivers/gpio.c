#include "gpio.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(uintptr_t)(addr)) = (uint32_t)(val))
#define DEV_READ(addr) (*((volatile uint32_t *)(uintptr_t)(addr)))

int gpio_init(gpio_t base) {
#ifdef GPIO_CTRL_REG_OFFSET
  DEV_WRITE(base + GPIO_CTRL_REG_OFFSET, 0x1u);
#else
  DEV_WRITE(base + 0x0u, 0x1u);
#endif
  return 0;
}

int gpio_in(gpio_t base) {
#ifdef GPIO_RDATA_REG_OFFSET
  return (int)DEV_READ(base + GPIO_RDATA_REG_OFFSET);
#else
  return (int)DEV_READ(base + 0x0u);
#endif
}

void gpio_out(gpio_t base, char c) {
#ifdef GPIO_WDATA_REG_OFFSET
  DEV_WRITE(base + GPIO_WDATA_REG_OFFSET, (uint32_t)(uint8_t)c);
#else
  DEV_WRITE(base + 0x0u, (uint32_t)(uint8_t)c);
#endif
}

int gpio_putchar(int c) {
  gpio_out((gpio_t)GPIO_BASE, (char)c);
  return c;
}

int gpio_puts(const char* str) {
  while (*str) {
    gpio_putchar(*str++);
  }
  return 0;
}
