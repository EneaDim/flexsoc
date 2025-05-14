#define SPI_HOST_BASE (0x80002000)

#define SPI_HOST_CTRL_REG   (0x0)
#define SPI_HOST_STATUS_REG (0x4)
#define SPI_HOST_RDATA_REG  (0x8)
#define SPI_HOST_WDATA_REG  (0xC)
#define SPI_HOST_STATUS_RX_EMPTY (0x20)
#define SPI_HOST_STATUS_TX_FULL (2)

#define SPI_HOST_EOF (-1)

#define UART_BASE (0x80000000)

#define UART_CTRL_REG (0x10)
#define UART_STATUS_REG (0x14)
#define UART_RX_REG (0x18)
#define UART_TX_REG (0x1C)

#define UART_STATUS_RX_EMPTY (0x1)
#define UART_STATUS_TX_FULL (2)

#define UART_EOF (-1)

#define BAUD_RATE (921600)
#define SYSCLK_FREQ (50000000)

#include <stdint.h>

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(addr)) = val)
#define DEV_READ(addr) (*((volatile uint32_t *)(addr)))

typedef void* spi_host_t;

int spi_host_init(spi_host_t spi_host) {
  // Enable
  DEV_WRITE(spi_host + SPI_HOST_CTRL_REG, 0x1);

  return 0;
}

int spi_host_in(spi_host_t spi_host) {
  int res = SPI_HOST_EOF;

  //if (!(DEV_READ(spi_host + SPI_HOST_STATUS_REG) & SPI_HOST_STATUS_RXEMPTY)) {
    res = DEV_READ(spi_host + SPI_HOST_RDATA_REG);
  //}

  return res;
}

void spi_host_out(spi_host_t spi_host, char c) {
  //while (DEV_READ(spi_host + SPI_HOST_STATUS_REG) & SPI_HOST_STATUS_TXFULL) {
  //}

  DEV_WRITE(spi_host + SPI_HOST_WDATA_REG, c);
}

int spi_host_putchar(int c) {
  //if (c == '\n') {
  //  spi_host_out((spi_host_t) SPI_HOST_BASE, '\r');
  //}

  spi_host_out((spi_host_t) SPI_HOST_BASE, c);
  return c;
}

int spi_host_puts(const char* str) {
  while (*str) {
    spi_host_putchar(*str++);
  }
  return 0;
}

typedef void* uart_t;

int uart_init(uart_t uart) {
  // NCO = 2^20 * baud rate / cpu frequency
  uint32_t nco = (uint32_t)(((uint64_t)BAUD_RATE << 20) / SYSCLK_FREQ);

  DEV_WRITE(uart + UART_CTRL_REG, (nco << 16) | 0x3U);

  return 0;
}

int uart_in(uart_t uart) {
  int res = UART_EOF;

  if (!(DEV_READ(uart + UART_STATUS_REG) & UART_STATUS_RX_EMPTY)) {
    res = DEV_READ(uart + UART_RX_REG);
  }

  return res;
}

void uart_out(uart_t uart, char c) {
  while (DEV_READ(uart + UART_STATUS_REG) & UART_STATUS_TX_FULL) {
  }

  DEV_WRITE(uart + UART_TX_REG, c);
}

int uart_putchar(int c) {
  if (c == '\n') {
    uart_out((uart_t) UART_BASE, '\r');
  }

  uart_out((uart_t) UART_BASE, c);
  return c;
}

int uart_puts(const char* str) {
  while (*str) {
    uart_putchar(*str++);
  }
  return 0;
}

int main(void) {
  spi_host_init((spi_host_t) SPI_HOST_BASE);
  uart_init((uart_t) UART_BASE);

  spi_host_puts("a5a");
  spi_host_puts("5a5");
  uart_puts("Hello World!\n");

  while(1) {
  }

  return 0;
}
