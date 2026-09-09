// Design-level invariants for the UART Master bridge.
// RTL remains designer-owned.
module uart_master_design_prove (
  input logic        clk_i,
  input logic        rst_ni,
  input logic        req_o,
  input logic        gnt_i,
  input logic [31:0] addr_o,
  input logic        we_o,
  input logic [31:0] wdata_o,
  input logic [3:0]  be_o,
  input logic        cio_tx_en_o
);
  logic past_valid = 1'b0;
  logic reset_seen = 1'b0;

  always_ff @(posedge clk_i) begin
    past_valid <= 1'b1;

    if (!rst_ni) begin
      reset_seen <= 1'b1;

      // The asynchronous reset state is externally idle.
      assert (!req_o);
      assert (!we_o);
      assert (addr_o[1:0] == 2'b00);
    end else if (reset_seen) begin
      // Structural interface guarantees after a real reset has been observed.
      assert (addr_o[1:0] == 2'b00);
      assert (cio_tx_en_o == 1'b1);

      // Make temporal claims only between two consecutive active cycles
      // after reset has been observed.
      if (past_valid && $past(reset_seen && rst_ni)) begin
        // A pending request must remain asserted with stable payload until grant.
        if ($past(req_o && !gnt_i)) begin
          assert (req_o);
          assert (addr_o  == $past(addr_o));
          assert (we_o    == $past(we_o));
          assert (wdata_o == $past(wdata_o));
          assert (be_o    == $past(be_o));
        end

        // A granted request is removed on the following sampled cycle.
        if ($past(req_o && gnt_i)) begin
          assert (!req_o);
        end
      end
    end
  end
endmodule

bind uart_master_core uart_master_design_prove uart_master_design_prove_i (
  .clk_i       (clk_i),
  .rst_ni      (rst_ni),
  .req_o       (req_o),
  .gnt_i       (gnt_i),
  .addr_o      (addr_o),
  .we_o        (we_o),
  .wdata_o     (wdata_o),
  .be_o        (be_o),
  .cio_tx_en_o (cio_tx_en_o)
);
