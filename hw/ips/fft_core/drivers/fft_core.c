#include "fft_core.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(uintptr_t)(addr)) = (uint32_t)(val))
#define DEV_READ(addr) (*((volatile uint32_t *)(uintptr_t)(addr)))

int fft_core_init(fft_core_t base) {
#ifdef FFT_CORE_CTRL_REG_OFFSET
  DEV_WRITE(base + FFT_CORE_CTRL_REG_OFFSET, 0x1u);
#else
  DEV_WRITE(base + 0x0u, 0x1u);
#endif
  return 0;
}

int fft_core_in(fft_core_t base) {
#ifdef FFT_CORE_RDATA_REG_OFFSET
  return (int)DEV_READ(base + FFT_CORE_RDATA_REG_OFFSET);
#else
  return (int)DEV_READ(base + 0x0u);
#endif
}

void fft_core_out(fft_core_t base, char c) {
#ifdef FFT_CORE_WDATA_REG_OFFSET
  DEV_WRITE(base + FFT_CORE_WDATA_REG_OFFSET, (uint32_t)(uint8_t)c);
#else
  DEV_WRITE(base + 0x0u, (uint32_t)(uint8_t)c);
#endif
}

int fft_core_putchar(int c) {
  fft_core_out((fft_core_t)FFT_CORE_BASE, (char)c);
  return c;
}

int fft_core_puts(const char* str) {
  while (*str) {
    fft_core_putchar(*str++);
  }
  return 0;
}
