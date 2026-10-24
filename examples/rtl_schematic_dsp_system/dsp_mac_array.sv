// Parallel multiplication: each generated lane binds a *slice of an array*.
module dsp_mac_array #(
  parameter int DATA_W = 16,
  parameter int TAPS = 8,
  parameter int ACC_W = 2*DATA_W + $clog2(TAPS)
)(
  input  logic                            clk_i,
  input  logic                            rst_ni,
  input  logic                            ce_i,
  input  logic                            valid_i,
  input  logic signed [DATA_W-1:0]        sample_i,
  input  wire signed [DATA_W-1:0]         coeff_i [TAPS],
  output logic signed [ACC_W-1:0]         sum_o,
  output logic                            valid_o
);
  wire signed [2*DATA_W-1:0] products [TAPS];
  wire [TAPS-1:0] lane_valid;
  for (genvar lane = 0; lane < TAPS; lane++) begin : g_lanes
    dsp_mul_lane #(.DATA_W(DATA_W)) u_mac (
      .clk_i(clk_i), .rst_ni(rst_ni), .ce_i(ce_i),
      .valid_i(valid_i), .x_i(sample_i), .weight_i(coeff_i[lane]),
      .product_o(products[lane]), .valid_o(lane_valid[lane])
    );
  end
  always_comb begin
    sum_o = '0;
    for (int k = 0; k < TAPS; k++) sum_o = sum_o + ACC_W'(products[k]);
  end
  assign valid_o = lane_valid[0];
endmodule
