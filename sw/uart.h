#ifndef UART_H
#define UART_H

#include <stdint.h>

#define UART_BASE (0x80000000)

#define UART_CTRL_REG   (0x10)
#define UART_STATUS_REG (0x14)
#define UART_RX_REG     (0x18)
#define UART_TX_REG     (0x1C)

#define UART_STATUS_RX_EMPTY (0x1)
#define UART_STATUS_TX_FULL  (2)

#define UART_EOF (-1)
#define BAUD_RATE (921600)
#define SYSCLK_FREQ (50000000)

typedef void* uart_t;

int uart_init(uart_t uart);
int uart_in(uart_t uart);
void uart_out(uart_t uart, char c);
int uart_putchar(int c);
int uart_puts(const char* str);

#endif // UART_H

