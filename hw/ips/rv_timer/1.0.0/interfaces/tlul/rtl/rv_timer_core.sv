// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//


module rv_timer_core #(
  parameter int N = 1
) (
  input clk_i,
  input rst_ni,

  input        active,
  input [11:0] prescaler,
  input [ 7:0] step,

  output logic        tick,
  output logic [31:0] mtime_d,
  input        [31:0] mtime,
  input        [31:0] mtimecmp [N],

  output logic [N-1:0] intr
);

  logic [11:0] tick_count;
  logic timer_rst_ni;

  prim_flop #(
    .Width      (1),
    .ResetValue (1'b0)
  ) u_timer_reset_branch (
    .clk_i (clk_i),
    .rst_ni(rst_ni),
    .d_i   (1'b1),
    .q_o   (timer_rst_ni)
  );

  always_ff @(posedge clk_i or negedge timer_rst_ni) begin : generate_tick
    if (!timer_rst_ni) begin
      tick_count <= 12'h0;
    end else if (!active) begin
      tick_count <= 12'h0;
    end else if (tick_count == prescaler) begin
      tick_count <= 12'h0;
    end else begin
      tick_count <= tick_count + 1'b1;
    end
  end

  assign tick = active & (tick_count >= prescaler);

  assign mtime_d = mtime + 32'(step);

  // interrupt is generated if mtime is greater than or equal to mtimecmp
  for (genvar t = 0 ; t < N ; t++) begin : gen_intr
    assign intr[t] = active & (mtime >= mtimecmp[t]);
  end

endmodule : rv_timer_core
