// One real multiplier stage, independent of instance name.
module dsp_mul_lane #(parameter int DATA_W = 16)(
  input  logic                            clk_i,
  input  logic                            rst_ni,
  input  logic                            ce_i,
  input  logic                            valid_i,
  input  logic signed [DATA_W-1:0]        x_i,
  input  logic signed [DATA_W-1:0]        weight_i,
  output logic signed [2*DATA_W-1:0]      product_o,
  output logic                            valid_o
);
  logic signed [2*DATA_W-1:0] product_d;
  assign product_d = x_i * weight_i;
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      product_o <= '0;
      valid_o   <= 1'b0;
    end else if (ce_i) begin
      product_o <= product_d;
      valid_o   <= valid_i;
    end
  end
endmodule
