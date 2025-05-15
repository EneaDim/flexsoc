#ifndef SPI_HOST_H
#define SPI_HOST_H

#include <stdint.h>

#define SPI_HOST_BASE (0x80002000)

#define SPI_HOST_CTRL_REG   (0x0)
#define SPI_HOST_STATUS_REG (0x4)
#define SPI_HOST_RDATA_REG  (0x8)
#define SPI_HOST_WDATA_REG  (0xC)

#define SPI_HOST_STATUS_RX_EMPTY (0x20)
#define SPI_HOST_STATUS_TX_FULL  (2)

#define SPI_HOST_EOF (-1)

typedef void* spi_host_t;

int spi_host_init(spi_host_t spi_host);
int spi_host_in(spi_host_t spi_host);
void spi_host_out(spi_host_t spi_host, char c);
int spi_host_putchar(int c);
int spi_host_puts(const char* str);

#endif // SPI_HOST_H

