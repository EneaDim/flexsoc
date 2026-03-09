// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: PWM Core Module
module pwm_core #(
  parameter int NOutputs   = 6,
  parameter int PhaseCntDw = 16,
  parameter int BeatCntDw  = 27
) (
  input  logic                      clk_core_i,
  input  logic                      rst_core_ni,
  input  pwm_reg_pkg::pwm_reg2hw_t  reg2hw,
  output logic [NOutputs-1:0]       pwm_o
);

  // --------------------------------------------------------------------------
  // Helper functions
  // --------------------------------------------------------------------------

  function automatic logic sanitize_bit(input logic val, input logic default_val);
    if ((val === 1'b0) || (val === 1'b1)) begin
      sanitize_bit = val;
    end else begin
      sanitize_bit = default_val;
    end
  endfunction

  function automatic logic [3:0] sanitize_u4(input logic [3:0] val,
                                              input logic [3:0] default_val);
    if ((^val) === 1'bX) begin
      sanitize_u4 = default_val;
    end else begin
      sanitize_u4 = val;
    end
  endfunction

  function automatic logic [15:0] sanitize_u16(input logic [15:0] val,
                                               input logic [15:0] default_val);
    if ((^val) === 1'bX) begin
      sanitize_u16 = default_val;
    end else begin
      sanitize_u16 = val;
    end
  endfunction

  function automatic logic [BeatCntDw-1:0] sanitize_clkdiv(
      input logic [BeatCntDw-1:0] val,
      input logic [BeatCntDw-1:0] default_val
  );
    if ((^val) === 1'bX) begin
      sanitize_clkdiv = default_val;
    end else begin
      sanitize_clkdiv = val;
    end
  endfunction

  // --------------------------------------------------------------------------
  // Sanitized configuration
  // --------------------------------------------------------------------------

  logic                 clr_phase_cntr;
  logic                 cntr_en;
  logic [BeatCntDw-1:0] clk_div;
  logic [3:0]           dc_resn;
  logic [3:0]           lshift;

  // These are qe bits from the register block. Treat anything not exactly 1 as 0.
  logic clk_div_qe;
  logic dc_resn_qe;
  logic cntr_en_qe;

  always_comb begin
    clk_div_qe = sanitize_bit(reg2hw.cfg.clk_div.qe, 1'b0);
    dc_resn_qe = sanitize_bit(reg2hw.cfg.dc_resn.qe, 1'b0);
    cntr_en_qe = sanitize_bit(reg2hw.cfg.cntr_en.qe, 1'b0);

    clr_phase_cntr = clk_div_qe | dc_resn_qe | cntr_en_qe;

    // Safe defaults while config may still be unstable
    cntr_en = sanitize_bit(reg2hw.cfg.cntr_en.q, 1'b0);
    dc_resn = sanitize_u4(reg2hw.cfg.dc_resn.q, 4'd0);
    clk_div = sanitize_clkdiv(reg2hw.cfg.clk_div.q, '0);

    // dc_resn is 4-bit, so range is already 0..15
    lshift = 4'd15 - dc_resn;
  end

  // --------------------------------------------------------------------------
  // Beat and phase counters
  // --------------------------------------------------------------------------

  logic [BeatCntDw-1:0]  beat_ctr_q;
  logic [BeatCntDw-1:0]  beat_ctr_d;
  logic                  beat_ctr_en;
  logic                  beat_end;

  logic [PhaseCntDw-1:0] phase_ctr_q;
  logic [PhaseCntDw-1:0] phase_ctr_d;
  logic [PhaseCntDw-1:0] phase_ctr_incr;
  logic [PhaseCntDw-1:0] phase_ctr_next;
  logic                  phase_ctr_overflow;
  logic                  phase_ctr_en;
  logic                  cycle_end;

  always_comb begin
    beat_end    = (beat_ctr_q == clk_div);
    beat_ctr_en = clr_phase_cntr | cntr_en;

    if (clr_phase_cntr) begin
      beat_ctr_d = '0;
    end else if (beat_end) begin
      beat_ctr_d = '0;
    end else begin
      beat_ctr_d = beat_ctr_q + {{(BeatCntDw-1){1'b0}}, 1'b1};
    end
  end

  always_ff @(posedge clk_core_i or negedge rst_core_ni) begin
    if (!rst_core_ni) begin
      beat_ctr_q <= '0;
    end else if (beat_ctr_en) begin
      beat_ctr_q <= beat_ctr_d;
    end
  end

  // Update phase counter only at the end of each beat.
  // If configuration changes, force a clear to a known value.
  always_comb begin
    phase_ctr_en   = beat_end & (clr_phase_cntr | cntr_en);

    phase_ctr_incr = '0;
    phase_ctr_incr[0] = 1'b1;
    phase_ctr_incr = phase_ctr_incr << lshift;

    {phase_ctr_overflow, phase_ctr_next} = phase_ctr_q + phase_ctr_incr;

    if (clr_phase_cntr) begin
      phase_ctr_d = '0;
    end else begin
      phase_ctr_d = phase_ctr_next;
    end

    cycle_end = beat_end & phase_ctr_overflow;
  end

  always_ff @(posedge clk_core_i or negedge rst_core_ni) begin
    if (!rst_core_ni) begin
      phase_ctr_q <= '0;
    end else if (phase_ctr_en) begin
      phase_ctr_q <= phase_ctr_d;
    end
  end

  // --------------------------------------------------------------------------
  // Per-channel sanitized inputs
  // --------------------------------------------------------------------------

  logic [NOutputs-1:0] pwm_en_s;
  logic [15:0]         phase_delay_s [NOutputs];
  logic [15:0]         duty_cycle_s  [NOutputs];

  for (genvar ii = 0; ii < NOutputs; ii++) begin : gen_chan_cfg_sanitize
    always_comb begin
      pwm_en_s[ii]       = sanitize_bit(reg2hw.pwm_en[ii].q, 1'b0);
      phase_delay_s[ii]  = sanitize_u16(reg2hw.pwm_param[ii].phase_delay.q, '0);
      duty_cycle_s[ii]   = sanitize_u16(reg2hw.pwm_param[ii].duty_cycle.q, '0);
    end
  end

  // --------------------------------------------------------------------------
  // PWM channels
  // --------------------------------------------------------------------------

  for (genvar ii = 0; ii < NOutputs; ii++) begin : gen_chan_insts
    pwm_chan #(
      .CntDw(PhaseCntDw)
    ) u_chan (
      .clk_i          (clk_core_i),
      .rst_ni         (rst_core_ni),
      .pwm_en_i       (pwm_en_s[ii]),
      .phase_delay_i  (phase_delay_s[ii]),
      .duty_cycle_a_i (duty_cycle_s[ii]),
      .phase_ctr_i    (phase_ctr_q),
      .cycle_end_i    (cycle_end),
      .dc_resn_i      (dc_resn),
      .pwm_o          (pwm_o[ii])
    );
  end

endmodule : pwm_core
