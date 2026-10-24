// Configuration register bank: unpacked coefficient words, one per tap.
module dsp_coeff_bank #(
  parameter int DATA_W = 16,
  parameter int TAPS = 8,
  parameter int ADDR_W = (TAPS > 1) ? $clog2(TAPS) : 1
)(
  input  logic                         clk_i,
  input  logic                         rst_ni,
  input  logic                         write_i,
  input  logic [ADDR_W-1:0]            write_addr_i,
  input  logic signed [DATA_W-1:0]     write_data_i,
  output wire signed [DATA_W-1:0]      coeff_o [TAPS]
);
  logic signed [DATA_W-1:0] bank_q [TAPS];

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      for (int t = 0; t < TAPS; t++) bank_q[t] <= DATA_W'(t + 1);
    end else if (write_i && (int'(write_addr_i) < TAPS)) begin
      bank_q[write_addr_i] <= write_data_i;
    end
  end
  for (genvar t = 0; t < TAPS; t++) begin : g_read
    assign coeff_o[t] = bank_q[t];
  end
endmodule
