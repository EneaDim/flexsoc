/**
 * @file
 * @brief Generated register defines for uart_master
 */

// Copyright information found in source file:
// Copyright lowRISC contributors (OpenTitan project).

// Licensing information found in source file:
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#ifndef _UART_MASTER_REG_DEFS_
#define _UART_MASTER_REG_DEFS_


#include <stdint.h>

#define UART_MASTER_BASE 0x0

typedef uintptr_t uart_master_t;
int uart_master_init(uart_master_t base);
int uart_master_in(uart_master_t base);
void uart_master_out(uart_master_t base, char c);
int uart_master_putchar(int c);
int uart_master_puts(const char* str);

#ifdef __cplusplus
extern "C" {
#endif
// Number of bytes in the RX FIFO.
#define UART_MASTER_PARAM_RX_FIFO_DEPTH 16

// Number of bytes in the TX FIFO.
#define UART_MASTER_PARAM_TX_FIFO_DEPTH 8

// Register width
#define UART_MASTER_PARAM_REG_WIDTH 32

// UART control register
#define UART_MASTER_CTRL_REG_OFFSET 0x0
#define UART_MASTER_CTRL_REG_RESVAL 0x4b7f0000u
#define UART_MASTER_CTRL_TX_BIT 0
#define UART_MASTER_CTRL_RX_BIT 1
#define UART_MASTER_CTRL_NF_BIT 2
#define UART_MASTER_CTRL_SLPBK_BIT 4
#define UART_MASTER_CTRL_LLPBK_BIT 5
#define UART_MASTER_CTRL_PARITY_EN_BIT 6
#define UART_MASTER_CTRL_PARITY_ODD_BIT 7
#define UART_MASTER_CTRL_NCO_MASK 0xffffu
#define UART_MASTER_CTRL_NCO_OFFSET 16
#define UART_MASTER_CTRL_NCO_FIELD \
  ((bitfield_field32_t) { .mask = UART_MASTER_CTRL_NCO_MASK, .index = UART_MASTER_CTRL_NCO_OFFSET })

// UART live status register
#define UART_MASTER_STATUS_REG_OFFSET 0x4
#define UART_MASTER_STATUS_REG_RESVAL 0x3cu
#define UART_MASTER_STATUS_TXFULL_BIT 0
#define UART_MASTER_STATUS_RXFULL_BIT 1
#define UART_MASTER_STATUS_TXEMPTY_BIT 2
#define UART_MASTER_STATUS_TXIDLE_BIT 3
#define UART_MASTER_STATUS_RXIDLE_BIT 4
#define UART_MASTER_STATUS_RXEMPTY_BIT 5

// UART read data
#define UART_MASTER_RDATA_REG_OFFSET 0x8
#define UART_MASTER_RDATA_REG_RESVAL 0x0u
#define UART_MASTER_RDATA_RDATA_MASK 0xffu
#define UART_MASTER_RDATA_RDATA_OFFSET 0
#define UART_MASTER_RDATA_RDATA_FIELD \
  ((bitfield_field32_t) { .mask = UART_MASTER_RDATA_RDATA_MASK, .index = UART_MASTER_RDATA_RDATA_OFFSET })

// UART write data
#define UART_MASTER_WDATA_REG_OFFSET 0xc
#define UART_MASTER_WDATA_REG_RESVAL 0x0u
#define UART_MASTER_WDATA_WDATA_MASK 0xffu
#define UART_MASTER_WDATA_WDATA_OFFSET 0
#define UART_MASTER_WDATA_WDATA_FIELD \
  ((bitfield_field32_t) { .mask = UART_MASTER_WDATA_WDATA_MASK, .index = UART_MASTER_WDATA_WDATA_OFFSET })

// UART FIFO control register
#define UART_MASTER_FIFO_CTRL_REG_OFFSET 0x10
#define UART_MASTER_FIFO_CTRL_REG_RESVAL 0x0u
#define UART_MASTER_FIFO_CTRL_RXRST_BIT 0
#define UART_MASTER_FIFO_CTRL_TXRST_BIT 1

// UART FIFO status register
#define UART_MASTER_FIFO_STATUS_REG_OFFSET 0x14
#define UART_MASTER_FIFO_STATUS_REG_RESVAL 0x0u
#define UART_MASTER_FIFO_STATUS_TXLVL_MASK 0xffu
#define UART_MASTER_FIFO_STATUS_TXLVL_OFFSET 0
#define UART_MASTER_FIFO_STATUS_TXLVL_FIELD \
  ((bitfield_field32_t) { .mask = UART_MASTER_FIFO_STATUS_TXLVL_MASK, .index = UART_MASTER_FIFO_STATUS_TXLVL_OFFSET })
#define UART_MASTER_FIFO_STATUS_RXLVL_MASK 0xffu
#define UART_MASTER_FIFO_STATUS_RXLVL_OFFSET 16
#define UART_MASTER_FIFO_STATUS_RXLVL_FIELD \
  ((bitfield_field32_t) { .mask = UART_MASTER_FIFO_STATUS_RXLVL_MASK, .index = UART_MASTER_FIFO_STATUS_RXLVL_OFFSET })

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _UART_MASTER_REG_DEFS_
// End generated register defines for uart_master