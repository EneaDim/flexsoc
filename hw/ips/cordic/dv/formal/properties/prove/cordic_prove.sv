// Design-level invariants for the CORDIC core. RTL remains designer-owned.
module cordic_design_prove (
  input logic clk_i, rst_ni, ctrl_soft_rst,
  input logic state_q, status_busy, status_valid, status_error,
  input logic [31:0] x_out_value, y_out_value, z_out_value,
  input logic [7:0] cfg_data_width, cfg_frac_width, cfg_max_iter, cfg_rsvd,
  input logic [28:0] status_rsvd
);
  logic past_valid = 1'b0;

  always_comb begin
    assert (status_busy == state_q);
    assert (cfg_data_width == 8'd16);
    assert (cfg_frac_width == 8'd14);
    assert (cfg_max_iter == 8'd16);
    assert (cfg_rsvd == '0);
    assert (status_rsvd == '0);
  end

  always_ff @(posedge clk_i) begin
    if (past_valid && (!$past(rst_ni) || $past(ctrl_soft_rst))) begin
      assert (!state_q);
      assert (!status_valid);
      assert (!status_error);
      assert (x_out_value == '0);
      assert (y_out_value == '0);
      assert (z_out_value == '0);
    end
    past_valid <= 1'b1;
  end
endmodule

bind cordic_core cordic_design_prove cordic_design_prove_i (
  .clk_i(clk_i), .rst_ni(rst_ni), .ctrl_soft_rst(ctrl_soft_rst),
  .state_q(state_q), .status_busy(status_busy), .status_valid(status_valid),
  .status_error(status_error), .x_out_value(x_out_value), .y_out_value(y_out_value),
  .z_out_value(z_out_value), .cfg_data_width(cfg_data_width),
  .cfg_frac_width(cfg_frac_width), .cfg_max_iter(cfg_max_iter),
  .cfg_rsvd(cfg_rsvd), .status_rsvd(status_rsvd)
);
