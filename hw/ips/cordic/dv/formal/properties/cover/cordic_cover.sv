// Reachability points for the CORDIC control path.
module cordic_design_cover (
  input logic clk_i, rst_ni, ctrl_soft_rst, start_rise, status_busy, status_valid
);
  always_ff @(posedge clk_i) if (rst_ni) begin
    cover (ctrl_soft_rst);
    cover (start_rise);
    cover (status_busy);
    cover (status_valid);
  end
endmodule

bind cordic_core cordic_design_cover cordic_design_cover_i (
  .clk_i(clk_i), .rst_ni(rst_ni), .ctrl_soft_rst(ctrl_soft_rst),
  .start_rise(start_rise), .status_busy(status_busy), .status_valid(status_valid)
);
