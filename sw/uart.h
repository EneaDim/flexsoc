#ifndef UART_H
#define UART_H

#include <stdint.h>

#define UART_BASE (0x80000000)

////////////////////
// UART OPENTITAN //
///////////////////
//#define UART_CTRL_REG   (0x10)
//#define UART_STATUS_REG (0x14)
//#define UART_RX_REG     (0x18)
//#define UART_TX_REG     (0x1C)
////////////////////
// MINIMAL UART  //
///////////////////
#define UART_CTRL_REG   (0x0)
#define UART_STATUS_REG (0x4)
#define UART_RX_REG     (0x8)
#define UART_TX_REG     (0xC)

#define UART_STATUS_RX_EMPTY (0x1)
#define UART_STATUS_TX_FULL  (2)

#define UART_EOF (-1)
#define BAUD_RATE (921600)
////////////////////
// UART OPENTITAN //
///////////////////
//#define SYSCLK_FREQ (50000000)
////////////////////
// MINIMAL UART  //
///////////////////
#define SYSCLK_FREQ (100000000)

typedef void* uart_t;

int uart_init(uart_t uart);
int uart_in(uart_t uart);
void uart_out(uart_t uart, char c);
int uart_putchar(int c);
int uart_puts(const char* str);

#endif // UART_H

