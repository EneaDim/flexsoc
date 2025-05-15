#include "spi_host.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(addr)) = val)
#define DEV_READ(addr) (*((volatile uint32_t *)(addr)))

int spi_host_init(spi_host_t spi_host) {
  DEV_WRITE(spi_host + SPI_HOST_CTRL_REG, 0x1);
  return 0;
}

int spi_host_in(spi_host_t spi_host) {
  int res = SPI_HOST_EOF;
  res = DEV_READ(spi_host + SPI_HOST_RDATA_REG);
  return res;
}

void spi_host_out(spi_host_t spi_host, char c) {
  DEV_WRITE(spi_host + SPI_HOST_WDATA_REG, c);
}

int spi_host_putchar(int c) {
  spi_host_out((spi_host_t) SPI_HOST_BASE, c);
  return c;
}

int spi_host_puts(const char* str) {
  while (*str) {
    spi_host_putchar(*str++);
  }
  return 0;
}

