#include "cordic.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(uintptr_t)(addr)) = (uint32_t)(val))
#define DEV_READ(addr) (*((volatile uint32_t *)(uintptr_t)(addr)))

int cordic_init(cordic_t base) {
#ifdef CORDIC_CTRL_REG_OFFSET
  DEV_WRITE(base + CORDIC_CTRL_REG_OFFSET, 0x1u);
#else
  DEV_WRITE(base + 0x0u, 0x1u);
#endif
  return 0;
}

int cordic_in(cordic_t base) {
#ifdef CORDIC_RDATA_REG_OFFSET
  return (int)DEV_READ(base + CORDIC_RDATA_REG_OFFSET);
#else
  return (int)DEV_READ(base + 0x0u);
#endif
}

void cordic_out(cordic_t base, char c) {
#ifdef CORDIC_WDATA_REG_OFFSET
  DEV_WRITE(base + CORDIC_WDATA_REG_OFFSET, (uint32_t)(uint8_t)c);
#else
  DEV_WRITE(base + 0x0u, (uint32_t)(uint8_t)c);
#endif
}

int cordic_putchar(int c) {
  cordic_out((cordic_t)CORDIC_BASE, (char)c);
  return c;
}

int cordic_puts(const char* str) {
  while (*str) {
    cordic_putchar(*str++);
  }
  return 0;
}
