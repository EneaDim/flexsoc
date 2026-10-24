// Signed saturation before a registered output; no implicit truncation.
module dsp_round_sat #(
  parameter int DATA_W = 16,
  parameter int ACC_W  = 35
)(
  input  logic                        clk_i,
  input  logic                        rst_ni,
  input  logic                        ce_i,
  input  logic                        valid_i,
  input  logic signed [ACC_W-1:0]     data_i,
  output logic signed [DATA_W-1:0]    data_o,
  output logic                        valid_o
);
  localparam logic signed [ACC_W-1:0] MAX_VAL = (ACC_W'(1) <<< (DATA_W-1)) - 1;
  localparam logic signed [ACC_W-1:0] MIN_VAL = -(ACC_W'(1) <<< (DATA_W-1));
  logic signed [DATA_W-1:0] clipped_d;
  always_comb begin
    if (data_i > MAX_VAL)      clipped_d = DATA_W'(MAX_VAL);
    else if (data_i < MIN_VAL) clipped_d = DATA_W'(MIN_VAL);
    else                       clipped_d = DATA_W'(data_i);
  end
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      data_o  <= '0;
      valid_o <= 1'b0;
    end else if (ce_i) begin
      data_o  <= clipped_d;
      valid_o <= valid_i;
    end
  end
endmodule
