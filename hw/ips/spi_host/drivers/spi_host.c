#include "spi_host.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(uintptr_t)(addr)) = (uint32_t)(val))
#define DEV_READ(addr) (*((volatile uint32_t *)(uintptr_t)(addr)))

int spi_host_init(spi_host_t base) {
#ifdef SPI_HOST_CTRL_REG_OFFSET
  DEV_WRITE(base + SPI_HOST_CTRL_REG_OFFSET, 0x1u);
#else
  DEV_WRITE(base + 0x0u, 0x1u);
#endif
  return 0;
}

int spi_host_in(spi_host_t base) {
#ifdef SPI_HOST_RDATA_REG_OFFSET
  return (int)DEV_READ(base + SPI_HOST_RDATA_REG_OFFSET);
#else
  return (int)DEV_READ(base + 0x0u);
#endif
}

void spi_host_out(spi_host_t base, char c) {
#ifdef SPI_HOST_WDATA_REG_OFFSET
  DEV_WRITE(base + SPI_HOST_WDATA_REG_OFFSET, (uint32_t)(uint8_t)c);
#else
  DEV_WRITE(base + 0x0u, (uint32_t)(uint8_t)c);
#endif
}

int spi_host_putchar(int c) {
  spi_host_out((spi_host_t)SPI_HOST_BASE, (char)c);
  return c;
}

int spi_host_puts(const char* str) {
  while (*str) {
    spi_host_putchar(*str++);
  }
  return 0;
}
