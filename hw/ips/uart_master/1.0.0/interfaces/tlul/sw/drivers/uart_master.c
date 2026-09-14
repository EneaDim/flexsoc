#include "uart_master.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(uintptr_t)(addr)) = (uint32_t)(val))
#define DEV_READ(addr) (*((volatile uint32_t *)(uintptr_t)(addr)))

#ifndef BAUD_RATE
#define BAUD_RATE 115200u
#endif

#ifndef SYSCLK_FREQ
#define SYSCLK_FREQ 50000000u
#endif

#ifndef UART_EOF
#define UART_EOF (-1)
#endif

int uart_master_init(uart_master_t base) {
  uint32_t nco = (uint32_t)(((uint64_t)BAUD_RATE << 20) / SYSCLK_FREQ);
  DEV_WRITE(base + UART_MASTER_CTRL_REG_OFFSET, (nco << 16) | 0x3U);
  return 0;
}

int uart_master_in(uart_master_t base) {
  int res = UART_EOF;
#ifdef UART_MASTER_STATUS_REG_OFFSET
#ifdef UART_MASTER_STATUS_RXEMPTY_BIT
  if (!(DEV_READ(base + UART_MASTER_STATUS_REG_OFFSET) & (1u << UART_MASTER_STATUS_RXEMPTY_BIT))) {
    res = (int)DEV_READ(base + UART_MASTER_RDATA_REG_OFFSET);
  }
#else
  res = (int)DEV_READ(base + UART_MASTER_RDATA_REG_OFFSET);
#endif
#else
  res = (int)DEV_READ(base + UART_MASTER_RDATA_REG_OFFSET);
#endif
  return res;
}

void uart_master_out(uart_master_t base, char c) {
#ifdef UART_MASTER_STATUS_REG_OFFSET
#ifdef UART_MASTER_STATUS_TXFULL_BIT
  while (DEV_READ(base + UART_MASTER_STATUS_REG_OFFSET) & (1u << UART_MASTER_STATUS_TXFULL_BIT)) {
  }
#endif
#endif
  DEV_WRITE(base + UART_MASTER_WDATA_REG_OFFSET, (uint32_t)(uint8_t)c);
}

int uart_master_putchar(int c) {
  if (c == '\n') {
    uart_master_out((uart_master_t)UART_MASTER_BASE, '\r');
  }
  uart_master_out((uart_master_t)UART_MASTER_BASE, (char)c);
  return c;
}

int uart_master_puts(const char* str) {
  while (*str) {
    uart_master_putchar(*str++);
  }
  return 0;
}
