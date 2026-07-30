// Design-level invariants for the UART core. RTL remains designer-owned.
module uart_design_prove (
  input logic clk_i, rst_ni,
  input logic rx, tx, tx_enable, rx_enable, sys_loopback, line_loopback,
  input logic tx_out_q, tx_fifo_rvalid, rx_fifo_rvalid, tx_fifo_wready, rx_fifo_wready,
  input logic [16:0] nco_sum_q,
  input logic rx_sync_q1, rx_sync_q2,
  input logic status_rxempty, status_txempty, status_rxfull, status_txfull
);
  logic past_valid = 1'b0;

  always_comb begin
    assert (rx_enable);
    assert (tx == (line_loopback ? rx : tx_out_q));
    assert (status_rxempty == !rx_fifo_rvalid);
    assert (status_txempty == !tx_fifo_rvalid);
    assert (status_rxfull == !rx_fifo_wready);
    assert (status_txfull == !tx_fifo_wready);
  end

  always_ff @(posedge clk_i) begin
    if (past_valid && !$past(rst_ni)) begin
      assert (nco_sum_q == '0);
      assert (tx_out_q);
      assert (rx_sync_q1);
      assert (rx_sync_q2);
    end
    if (past_valid && $past(sys_loopback)) assert (tx_out_q);
    past_valid <= 1'b1;
  end
endmodule

bind uart_core uart_design_prove uart_design_prove_i (
  .clk_i(clk_i), .rst_ni(rst_ni), .rx(rx), .tx(tx),
  .tx_enable(tx_enable), .rx_enable(rx_enable), .sys_loopback(sys_loopback),
  .line_loopback(line_loopback), .tx_out_q(tx_out_q),
  .tx_fifo_rvalid(tx_fifo_rvalid), .rx_fifo_rvalid(rx_fifo_rvalid),
  .tx_fifo_wready(tx_fifo_wready), .rx_fifo_wready(rx_fifo_wready),
  .nco_sum_q(nco_sum_q), .rx_sync_q1(rx_sync_q1), .rx_sync_q2(rx_sync_q2),
  .status_rxempty(hw2reg.status.rxempty.d), .status_txempty(hw2reg.status.txempty.d),
  .status_rxfull(hw2reg.status.rxfull.d), .status_txfull(hw2reg.status.txfull.d)
);
