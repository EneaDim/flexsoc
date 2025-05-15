#include "uart.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(addr)) = val)
#define DEV_READ(addr) (*((volatile uint32_t *)(addr)))

int uart_init(uart_t uart) {
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
  while (DEV_READ(uart + UART_STATUS_REG) & UART_STATUS_TX_FULL);
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

