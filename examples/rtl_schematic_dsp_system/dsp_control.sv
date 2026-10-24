// Finite state machine plus a frame counter, independent of DSP datapath.
module dsp_control #(parameter int FRAME_LEN = 64)(
  input  logic clk_i,
  input  logic rst_ni,
  input  logic valid_i,
  input  logic valid_o,
  output logic accept_o,
  output logic busy_o,
  output logic [$clog2(FRAME_LEN+1)-1:0] count_o
);
  import dsp_ops_pkg::*;
  ctrl_state_e state_q, state_d;
  logic [$clog2(FRAME_LEN+1)-1:0] count_q;
  always_comb begin
    state_d = state_q;
    unique case (state_q)
      IDLE:   if (valid_i) state_d = FILL;
      FILL:   state_d = ACTIVE;
      ACTIVE: if (count_q == FRAME_LEN-1) state_d = DRAIN;
      DRAIN:  if (valid_o) state_d = IDLE;
      default: state_d = IDLE;
    endcase
  end
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state_q <= IDLE;
      count_q <= '0;
    end else begin
      state_q <= state_d;
      if (state_q == ACTIVE && valid_i) count_q <= count_q + 1'b1;
      else if (state_q == IDLE) count_q <= '0;
    end
  end
  assign accept_o = (state_q != DRAIN);
  assign busy_o = (state_q != IDLE);
  assign count_o = count_q;
endmodule
