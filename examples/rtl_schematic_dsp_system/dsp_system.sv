// Integrated multi-file DSP: every module port is intentionally connected.
// Parent nets use different names from child ports to exercise AST bindings.
module dsp_system #(
  parameter int DATA_W = 16,
  parameter int TAPS = 8,
  parameter int FRAME_LEN = 64,
  parameter int ACC_W = 2*DATA_W + $clog2(TAPS),
  parameter int ADDR_W = (TAPS > 1) ? $clog2(TAPS) : 1
)(
  input  logic                            clk_i,
  input  logic                            rst_ni,
  input  logic                            ce_i,
  input  logic                            in_valid_i,
  input  logic signed [DATA_W-1:0]        sample_i,
  input  logic signed [DATA_W-1:0]        offset_i,
  input  dsp_ops_pkg::dsp_op_e            opcode_i,
  input  logic                            bypass_i,
  input  logic                            cfg_write_i,
  input  logic [ADDR_W-1:0]              cfg_addr_i,
  input  logic signed [DATA_W-1:0]        cfg_coeff_i,
  output logic                            ready_o,
  output logic                            out_valid_o,
  output logic signed [DATA_W-1:0]        data_o,
  output logic                            busy_o,
  output logic [$clog2(FRAME_LEN+1)-1:0]  frame_count_o
);
  wire signed [DATA_W-1:0] coeff_words [TAPS];
  wire signed [ACC_W-1:0] parallel_sum;
  wire signed [ACC_W-1:0] alu_result;
  wire                      sum_valid;
  wire                      accepted;

  dsp_coeff_bank #(.DATA_W(DATA_W), .TAPS(TAPS)) u_coefficients (
    .clk_i(clk_i), .rst_ni(rst_ni),
    .write_i(cfg_write_i), .write_addr_i(cfg_addr_i),
    .write_data_i(cfg_coeff_i), .coeff_o(coeff_words)
  );
  dsp_mac_array #(.DATA_W(DATA_W), .TAPS(TAPS), .ACC_W(ACC_W)) u_parallel (
    .clk_i(clk_i), .rst_ni(rst_ni), .ce_i(ce_i),
    .valid_i(accepted), .sample_i(sample_i), .coeff_i(coeff_words),
    .sum_o(parallel_sum), .valid_o(sum_valid)
  );
  dsp_alu #(.DATA_W(DATA_W), .ACC_W(ACC_W)) u_arithmetic (
    .mac_i(parallel_sum), .offset_i(offset_i),
    .opcode_i(opcode_i), .bypass_i(bypass_i), .chosen_o(alu_result)
  );
  dsp_round_sat #(.DATA_W(DATA_W), .ACC_W(ACC_W)) u_output (
    .clk_i(clk_i), .rst_ni(rst_ni), .ce_i(ce_i),
    .valid_i(sum_valid), .data_i(alu_result),
    .data_o(data_o), .valid_o(out_valid_o)
  );
  dsp_control #(.FRAME_LEN(FRAME_LEN)) u_controller (
    .clk_i(clk_i), .rst_ni(rst_ni), .valid_i(in_valid_i),
    .valid_o(out_valid_o), .accept_o(ready_o),
    .busy_o(busy_o), .count_o(frame_count_o)
  );
  assign accepted = ready_o && in_valid_i;
endmodule
