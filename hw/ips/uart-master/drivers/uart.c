#include "uart.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(addr)) = (val))
#define DEV_READ(addr) (*((volatile uint32_t *)(addr)))

int uart_init(uart_t uart) {
  DEV_WRITE(uart + UART_CTRL_REG_OFFSET, 0x1);
  return 0;
}

int uart_in(uart_t uart) {
  int res = -1;
  res = DEV_READ(uart + UART_RDATA_REG_OFFSET);
  return res;
}

void uart_out(uart_t uart, char c) {
  DEV_WRITE(uart + UART_WDATA_REG_OFFSET, c);
}

int uart_putchar(int c) {
  uart_out((uart_t) UART_BASE, c);
  return c;
}

int uart_puts(const char* str) {
  while (*str) {
    uart_putchar(*str++);
  }
  return 0;
}