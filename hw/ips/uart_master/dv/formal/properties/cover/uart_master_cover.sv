// Reachability points for the UART Master interface.
module uart_master_design_cover (
  input logic        clk_i,
  input logic        rst_ni,
  input logic        req_o,
  input logic [31:0] addr_o,
  input logic        cio_tx_en_o
);
  logic reset_seen = 1'b0;

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      reset_seen <= 1'b1;
    end else if (reset_seen) begin
      // Reach a live post-reset idle/interface-valid state.
      cover (cio_tx_en_o);
      cover (!req_o && addr_o[1:0] == 2'b00);
    end
  end
endmodule

bind uart_master_core uart_master_design_cover uart_master_design_cover_i (
  .clk_i       (clk_i),
  .rst_ni      (rst_ni),
  .req_o       (req_o),
  .addr_o      (addr_o),
  .cio_tx_en_o (cio_tx_en_o)
);
