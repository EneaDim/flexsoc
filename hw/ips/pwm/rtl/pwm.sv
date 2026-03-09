// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
`include "prim_assert.sv"

module pwm
  import pwm_reg_pkg::*;
#(
  parameter int PhaseCntDw = 16,
  parameter int BeatCntDw  = 27
) (
  input  logic              clk_i,
  input  logic              rst_ni,

  input  tlul_pkg::tl_h2d_t tl_i,
  output tlul_pkg::tl_d2h_t tl_o,

  output logic              cio_pwm_o,
  output logic              cio_pwm_en_o
);

  localparam int unsigned NOutputs = 1;

  pwm_reg2hw_t       reg2hw;
  tlul_pkg::tl_d2h_t tl_o_int;

  pwm_reg_top u_reg (
    .clk_i     (clk_i),
    .rst_ni    (rst_ni),
    .tl_i      (tl_i),
    .tl_o      (tl_o_int),
    .reg2hw    (reg2hw),
    .devmode_i (1'b1)
  );

  assign tl_o         = tl_o_int;
  assign cio_pwm_en_o = 1'b1;

  pwm_core #(
    .NOutputs   (NOutputs),
    .PhaseCntDw (PhaseCntDw),
    .BeatCntDw  (BeatCntDw)
  ) u_pwm_core (
    .clk_core_i  (clk_i),
    .rst_core_ni (rst_ni),
    .reg2hw      (reg2hw),
    .pwm_o       (cio_pwm_o)
  );

endmodule : pwm
