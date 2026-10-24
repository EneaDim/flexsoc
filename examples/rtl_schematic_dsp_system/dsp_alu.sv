// Explicit arithmetic plus two-input MUX with a dedicated select pin.
module dsp_alu #(
  parameter int DATA_W = 16,
  parameter int ACC_W = 35
)(
  input  logic signed [ACC_W-1:0]         mac_i,
  input  logic signed [DATA_W-1:0]        offset_i,
  input  dsp_ops_pkg::dsp_op_e            opcode_i,
  input  logic                            bypass_i,
  output wire signed [ACC_W-1:0]         chosen_o
);
  logic signed [ACC_W-1:0] offset_ext;
  logic signed [ACC_W-1:0] arith_d;
  assign offset_ext = ACC_W'(offset_i);
  always_comb begin
    unique case (opcode_i)
      dsp_ops_pkg::OP_PASS: arith_d = mac_i;
      dsp_ops_pkg::OP_ADD:  arith_d = mac_i + offset_ext;
      dsp_ops_pkg::OP_SUB:  arith_d = mac_i - offset_ext;
      dsp_ops_pkg::OP_NEG:  arith_d = -mac_i;
      default:              arith_d = mac_i;
    endcase
  end
  assign chosen_o = bypass_i ? offset_ext : arith_d;
endmodule
