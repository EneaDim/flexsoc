// Reachability points for the UART control and TX paths.
module uart_design_cover (
  input logic clk_i, rst_ni, tx_enable, sys_loopback, line_loopback, tx_fifo_wvalid
);
  always_ff @(posedge clk_i) if (rst_ni) begin
    cover (tx_enable);
    cover (sys_loopback);
    cover (line_loopback);
    cover (tx_fifo_wvalid);
  end
endmodule

bind uart_core uart_design_cover uart_design_cover_i (
  .clk_i(clk_i), .rst_ni(rst_ni), .tx_enable(tx_enable),
  .sys_loopback(sys_loopback), .line_loopback(line_loopback),
  .tx_fifo_wvalid(tx_fifo_wvalid)
);
