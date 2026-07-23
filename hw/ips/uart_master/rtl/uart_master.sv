// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: UART top level wrapper file

`include "prim_assert.sv"

module uart_master import uart_reg_pkg::*; (
  input           clk_i,
  input           rst_ni,

  // Bus Interface
  input  tlul_pkg::tl_h2d_t tl_i,
  output tlul_pkg::tl_d2h_t tl_o,

  // ===== Verso tlul_adapter_host 
  output logic        req_o,
  input  logic        gnt_i,
  output logic [31:0] addr_o,
  output logic        we_o,
  output logic [31:0] wdata_o,
  output logic [3:0]  be_o,
  input  logic        valid_i,
  input  logic [31:0] rdata_i,
  input  logic        err_i,

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

  logic       rx_valid;
  logic [7:0] rx_data;
  logic       rx_pop;

  logic       tx_valid;
  logic [7:0] tx_data;
  logic       tx_ready;

  uart_core u_uart_core (
    .clk_i,
    .rst_ni,
    .reg2hw,
    .hw2reg,
    .rx (cio_rx_i),
    .tx (cio_tx_o),
    .rx_valid_o (rx_valid),
    .rx_data_o  (rx_data),
    .rx_pop_i   (rx_pop),
    .tx_valid_i (tx_valid),
    .tx_data_i  (tx_data),
    .tx_ready_o (tx_ready)
  );

  assign cio_tx_en_o = 1'b1;

  // Bridge UART↔host
  uart_host_bridge u_bridge (
    .clk_i, .rst_ni,

    .rx_valid_i (rx_valid),
    .rx_data_i  (rx_data),
    .rx_pop_o   (rx_pop),

    .tx_valid_o (tx_valid),
    .tx_data_o  (tx_data),
    .tx_ready_i (tx_ready),

    // → tlul_adapter_host nel top
    .req_o,
    .gnt_i,
    .addr_o,
    .we_o,
    .wdata_o,
    .be_o,

    // ← risposta dall'adapter
    .valid_i,
    .rdata_i,
    .err_i
  );

endmodule
