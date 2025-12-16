// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: UART core module
//

`include "prim_assert.sv"

module uart_core (
  input                  clk_i,
  input                  rst_ni,

  input  uart_reg_pkg::uart_reg2hw_t reg2hw,
  output uart_reg_pkg::uart_hw2reg_t hw2reg,

  // pin fisici
  input  logic           rx,
  output logic           tx
);

  import uart_reg_pkg::*;

  localparam int NcoWidth = $bits(reg2hw.ctrl.nco.q);
  localparam int TxFifoDepthW = $clog2(TxFifoDepth)+1;
  localparam int RxFifoDepthW = $clog2(RxFifoDepth)+1;

  // The design does not support FIFOs deeper than 255 elements with the current CSR layout.
  `ASSERT_INIT(TxFifoDepth_A, TxFifoDepth < 256)
  `ASSERT_INIT(RxFifoDepth_A, RxFifoDepth < 256)

  logic   [15:0]  rx_val_q;
  logic   [7:0]   uart_rdata;
  logic           tick_baud_x16, rx_tick_baud;

  logic   [TxFifoDepthW-1:0] tx_fifo_depth;
  logic   [RxFifoDepthW-1:0] rx_fifo_depth;
  logic   [RxFifoDepthW-1:0] rx_fifo_depth_prev_q;

  logic   [23:0]  rx_timeout_count_d, rx_timeout_count_q, uart_rxto_val;
  logic           rx_fifo_depth_changed, uart_rxto_en;
  logic           tx_enable, rx_enable;
  logic           sys_loopback, line_loopback, rxnf_enable;
  logic           uart_fifo_rxrst, uart_fifo_txrst;
  logic   [7:0]   tx_fifo_data;
  logic           tx_fifo_rready, tx_fifo_rvalid;
  logic           tx_fifo_wready, tx_uart_idle;
  logic           tx_out;
  logic           tx_out_q;
  logic   [7:0]   rx_fifo_data;
  logic           rx_valid, rx_fifo_wvalid, rx_fifo_rvalid;
  logic           rx_fifo_wready, rx_uart_idle;
  logic           rx_sync;
  logic           rx_in;
  logic           break_err;
  logic   [4:0]   allzero_cnt_d, allzero_cnt_q;
  logic           allzero_err, not_allzero_char;
  logic           event_tx_watermark, event_tx_empty, event_rx_watermark, event_tx_done;
  logic           event_rx_overflow, event_rx_frame_err, event_rx_break_err, event_rx_timeout;
  logic           event_rx_parity_err;
  logic           tx_uart_idle_q;

  logic           rx_fifo_pop;
  logic   [7:0]   tx_fifo_wdata;
  logic           tx_fifo_wvalid;

  assign tx_enable        = reg2hw.ctrl.tx.q;
  //assign rx_enable        = reg2hw.ctrl.rx.q;
  assign rx_enable        = 1'b1;
  assign rxnf_enable      = reg2hw.ctrl.nf.q;
  assign sys_loopback     = reg2hw.ctrl.slpbk.q;
  assign line_loopback    = reg2hw.ctrl.llpbk.q;

  assign uart_fifo_rxrst  = reg2hw.fifo_ctrl.rxrst.q & reg2hw.fifo_ctrl.rxrst.qe;
  assign uart_fifo_txrst  = reg2hw.fifo_ctrl.txrst.q & reg2hw.fifo_ctrl.txrst.qe;
  assign hw2reg.rdata.d   = uart_rdata;

  assign hw2reg.status.rxempty.d     = ~rx_fifo_rvalid;
  assign hw2reg.status.rxidle.d      = rx_uart_idle;
  assign hw2reg.status.txidle.d      = tx_uart_idle & ~tx_fifo_rvalid;
  assign hw2reg.status.txempty.d     = ~tx_fifo_rvalid;
  assign hw2reg.status.rxfull.d      = ~rx_fifo_wready;
  assign hw2reg.status.txfull.d      = ~tx_fifo_wready;

  assign hw2reg.fifo_status.txlvl.d  = 8'(tx_fifo_depth);
  assign hw2reg.fifo_status.rxlvl.d  = 8'(rx_fifo_depth);

  //              NCO 16x Baud Generator
  logic   [NcoWidth:0]     nco_sum_q; // extra bit to get the carry

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      nco_sum_q <= '0;
    end else if (tx_enable || rx_enable) begin
      nco_sum_q <= {1'b0,nco_sum_q[NcoWidth-1:0]} + {1'b0,reg2hw.ctrl.nco.q[NcoWidth-1:0]};
    end
  end

  assign tick_baud_x16 = nco_sum_q[NcoWidth]; // bit di carry

  //////////////
  // TX Logic //
  //////////////

  assign tx_fifo_rready  = tx_uart_idle & tx_fifo_rvalid & tx_enable;

  assign tx_fifo_wdata   = reg2hw.wdata.q;
  assign tx_fifo_wvalid  = reg2hw.wdata.qe;

  prim_fifo_sync #(
    .Width   (8),
    .Pass    (1'b0),
    .Depth   (TxFifoDepth)
  ) u_uart_txfifo (
    .clk_i,
    .rst_ni,
    .clr_i   (uart_fifo_txrst),
    .wvalid_i(tx_fifo_wvalid),
    .wready_o(tx_fifo_wready),
    .wdata_i (tx_fifo_wdata),
    .depth_o (tx_fifo_depth),
    .full_o  (),
    .rvalid_o(tx_fifo_rvalid),
    .rready_i(tx_fifo_rready),
    .rdata_o (tx_fifo_data),
    .err_o   ()
  );

  uart_tx uart_tx (
    .clk_i,
    .rst_ni,
    .tx_enable,
    .tick_baud_x16,
    .parity_enable  (reg2hw.ctrl.parity_en.q),
    .wr             (tx_fifo_rready),
    .wr_parity      ((^tx_fifo_data) ^ reg2hw.ctrl.parity_odd.q),
    .wr_data        (tx_fifo_data),
    .idle           (tx_uart_idle),
    .tx             (tx_out)
  );

  assign tx = line_loopback ? rx : tx_out_q ;
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      tx_out_q <= 1'b1;
    end else if (sys_loopback) begin
      tx_out_q <= 1'b1;
    end else begin
      tx_out_q <= tx_out;
    end
  end

  //////////////
  // RX Logic //
  //////////////

  //      sync the incoming data
  prim_flop_2sync #(
    .Width(1),
    .ResetValue(1'b1)
  ) sync_rx (
    .clk_i,
    .rst_ni,
    .d_i(rx),
    .q_o(rx_sync)
  );

  // majority filter (NF)
  logic   rx_sync_q1, rx_sync_q2, rx_in_mx, rx_in_maj;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      rx_sync_q1 <= 1'b1;
      rx_sync_q2 <= 1'b1;
    end else begin
      rx_sync_q1 <= rx_sync;
      rx_sync_q2 <= rx_sync_q1;
    end
  end

  assign rx_in_maj = (rx_sync    & rx_sync_q1) |
                     (rx_sync    & rx_sync_q2) |
                     (rx_sync_q1 & rx_sync_q2);
  assign rx_in_mx  = rxnf_enable ? rx_in_maj : rx_sync;

  assign rx_in =  sys_loopback ? tx_out   :
                  line_loopback ? 1'b1 :
                  rx_in_mx;

  uart_rx uart_rx (
    .clk_i,
    .rst_ni,
    .rx_enable,
    .tick_baud_x16,
    .parity_enable  (reg2hw.ctrl.parity_en.q),
    .parity_odd     (reg2hw.ctrl.parity_odd.q),
    .tick_baud      (rx_tick_baud),
    .rx_valid,
    .rx_data        (rx_fifo_data),
    .idle           (rx_uart_idle),
    .frame_err      (event_rx_frame_err),
    .rx             (rx_in),
    .rx_parity_err  (event_rx_parity_err)
  );

  assign rx_fifo_wvalid = rx_valid & ~event_rx_frame_err & ~event_rx_parity_err;

  assign rx_fifo_pop = reg2hw.rdata.re;

  prim_fifo_sync #(
    .Width   (8),
    .Pass    (1'b0),
    .Depth   (RxFifoDepth)
  ) u_uart_rxfifo (
    .clk_i,
    .rst_ni,
    .clr_i   (uart_fifo_rxrst),
    .wvalid_i(rx_fifo_wvalid),
    .wready_o(rx_fifo_wready),
    .wdata_i (rx_fifo_data),
    .depth_o (rx_fifo_depth),
    .full_o  (),
    .rvalid_o(rx_fifo_rvalid),
    .rready_i(rx_fifo_pop),
    .rdata_o (uart_rdata),
    .err_o   ()
  );

endmodule

