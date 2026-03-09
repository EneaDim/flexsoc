// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
module pwm_chan #(
  parameter int CntDw = 16
) (
  input  logic        clk_i,
  input  logic        rst_ni,

  input  logic        pwm_en_i,
  input  logic [15:0] phase_delay_i,
  input  logic [15:0] duty_cycle_a_i,

  input  logic [15:0] phase_ctr_i,
  input  logic        cycle_end_i,
  input  logic [3:0]  dc_resn_i,

  output logic        pwm_o
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

  // --------------------------------------------------------------------------
  // Sanitized inputs
  // --------------------------------------------------------------------------

  logic        pwm_en_s;
  logic        cycle_end_s;
  logic [3:0]  dc_resn_s;
  logic [15:0] phase_delay_s;
  logic [15:0] duty_cycle_a_s;
  logic [15:0] phase_ctr_s;

  always_comb begin
    pwm_en_s      = sanitize_bit(pwm_en_i, 1'b0);
    cycle_end_s   = sanitize_bit(cycle_end_i, 1'b0);
    dc_resn_s     = sanitize_u4(dc_resn_i, 4'd0);
    phase_delay_s = sanitize_u16(phase_delay_i, 16'd0);
    duty_cycle_a_s= sanitize_u16(duty_cycle_a_i, 16'd0);
    phase_ctr_s   = sanitize_u16(phase_ctr_i, 16'd0);
  end

  // --------------------------------------------------------------------------
  // Masking and phase computation
  // --------------------------------------------------------------------------

  logic [15:0] dc_mask;
  logic [15:0] phase_delay_masked;
  logic [15:0] duty_cycle_masked;
  logic [15:0] on_phase;
  logic [15:0] off_phase;
  logic        phase_wrap;

  always_comb begin
    // Safe because dc_resn_s is guaranteed known.
    dc_mask = 16'hffff >> (dc_resn_s + 4'd1);

    // Explicitly round down phase_delay and duty cycle according to dc_resn.
    phase_delay_masked = phase_delay_s & ~dc_mask;
    duty_cycle_masked  = duty_cycle_a_s & ~dc_mask;

    on_phase = phase_delay_masked;
    {phase_wrap, off_phase} = {1'b0, phase_delay_masked} +
                              {1'b0, duty_cycle_masked};
  end

  // --------------------------------------------------------------------------
  // Comparators
  // --------------------------------------------------------------------------

  logic on_phase_exceeded;
  logic off_phase_exceeded;

  always_comb begin
    on_phase_exceeded  = (phase_ctr_s >= on_phase);
    off_phase_exceeded = (phase_ctr_s >= off_phase);
  end

  // --------------------------------------------------------------------------
  // PWM enable latch
  // --------------------------------------------------------------------------

  logic pwm_en_q;
  logic pwm_en_d;
  logic pwm_d;
  logic pwm_q;

  always_comb begin
    // Hold previous latched enable by default.
    pwm_en_d = pwm_en_q;

    // Sample a new enable only when output is currently inactive.
    // This preserves original intent while avoiding X-driven behavior.
    if (!pwm_d) begin
      pwm_en_d = pwm_en_s;
    end
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      pwm_en_q <= 1'b0;
    end else begin
      pwm_en_q <= pwm_en_d;
    end
  end

  // --------------------------------------------------------------------------
  // PWM combinational decision
  // --------------------------------------------------------------------------

  always_comb begin
    pwm_d = 1'b0;

    if (pwm_en_q) begin
      if (phase_wrap) begin
        pwm_d = on_phase_exceeded | ~off_phase_exceeded;
      end else begin
        pwm_d = on_phase_exceeded & ~off_phase_exceeded;
      end
    end
  end

  // --------------------------------------------------------------------------
  // Registered output
  // --------------------------------------------------------------------------

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      pwm_q <= 1'b0;
    end else begin
      pwm_q <= pwm_d;
    end
  end

  assign pwm_o = pwm_q;

endmodule : pwm_chan
