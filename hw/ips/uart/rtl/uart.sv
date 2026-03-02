// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: UART top level wrapper file

`include "prim_assert.sv"

module uart import uart_reg_pkg::*; (
  input           clk_i,
  input           rst_ni,

  // Bus Interface
  input  tlul_pkg::tl_h2d_t tl_i,
  output tlul_pkg::tl_d2h_t tl_o,

  // Generic IO
  input           cio_rx_i,
  output logic    cio_tx_o,
  output logic    cio_tx_en_o
);

  uart_reg2hw_t reg2hw;
  uart_hw2reg_t hw2reg;

  uart_reg_top u_reg (
    .clk_i,
    .rst_ni,
    .tl_i,
    .tl_o,
    .reg2hw,
    .hw2reg,
    .devmode_i(1'b1)
  );

  uart_core u_uart_core (
    .clk_i,
    .rst_ni,
    .reg2hw,
    .hw2reg,
    .rx (cio_rx_i),
    .tx (cio_tx_o)
  );

  assign cio_tx_en_o = 1'b1;

endmodule
