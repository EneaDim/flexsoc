#include "cache_wrapper.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(uintptr_t)(addr)) = (uint32_t)(val))
#define DEV_READ(addr) (*((volatile uint32_t *)(uintptr_t)(addr)))

int cache_wrapper_init(cache_wrapper_t base) {
#ifdef CACHE_WRAPPER_CTRL_REG_OFFSET
  DEV_WRITE(base + CACHE_WRAPPER_CTRL_REG_OFFSET, 0x1u);
#else
  DEV_WRITE(base + 0x0u, 0x1u);
#endif
  return 0;
}

int cache_wrapper_in(cache_wrapper_t base) {
#ifdef CACHE_WRAPPER_RDATA_REG_OFFSET
  return (int)DEV_READ(base + CACHE_WRAPPER_RDATA_REG_OFFSET);
#else
  return (int)DEV_READ(base + 0x0u);
#endif
}

void cache_wrapper_out(cache_wrapper_t base, char c) {
#ifdef CACHE_WRAPPER_WDATA_REG_OFFSET
  DEV_WRITE(base + CACHE_WRAPPER_WDATA_REG_OFFSET, (uint32_t)(uint8_t)c);
#else
  DEV_WRITE(base + 0x0u, (uint32_t)(uint8_t)c);
#endif
}

int cache_wrapper_putchar(int c) {
  cache_wrapper_out((cache_wrapper_t)CACHE_WRAPPER_BASE, (char)c);
  return c;
}

int cache_wrapper_puts(const char* str) {
  while (*str) {
    cache_wrapper_putchar(*str++);
  }
  return 0;
}
