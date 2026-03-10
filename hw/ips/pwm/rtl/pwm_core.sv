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
  input  logic                     clk_core_i,
  input  logic                     rst_core_ni,
  input  pwm_reg_pkg::pwm_reg2hw_t reg2hw,
  output logic [NOutputs-1:0]      pwm_o
);

  // --------------------------------------------------------------------------
  // Registered configuration
  // --------------------------------------------------------------------------

  logic                 cntr_en_q;
  logic [BeatCntDw-1:0] clk_div_q;
  logic [3:0]           dc_resn_q;

  logic                 clk_div_qe_q;
  logic                 dc_resn_qe_q;
  logic                 cntr_en_qe_q;

  logic [NOutputs-1:0] pwm_en_q;
  logic [15:0]         phase_delay_q [NOutputs];
  logic [15:0]         duty_cycle_q  [NOutputs];

  always_ff @(posedge clk_core_i or negedge rst_core_ni) begin
    if (!rst_core_ni) begin
      cntr_en_q    <= 1'b0;
      clk_div_q    <= '0;
      dc_resn_q    <= '0;

      clk_div_qe_q <= 1'b0;
      dc_resn_qe_q <= 1'b0;
      cntr_en_qe_q <= 1'b0;

      for (int i = 0; i < NOutputs; i++) begin
        pwm_en_q[i]       <= 1'b0;
        phase_delay_q[i]  <= '0;
        duty_cycle_q[i]   <= '0;
      end
    end else begin
      cntr_en_q    <= reg2hw.cfg.cntr_en.q;
      clk_div_q    <= reg2hw.cfg.clk_div.q;
      dc_resn_q    <= reg2hw.cfg.dc_resn.q;

      clk_div_qe_q <= reg2hw.cfg.clk_div.qe;
      dc_resn_qe_q <= reg2hw.cfg.dc_resn.qe;
      cntr_en_qe_q <= reg2hw.cfg.cntr_en.qe;

      for (int i = 0; i < NOutputs; i++) begin
        pwm_en_q[i]      <= reg2hw.pwm_en[i].q;
        phase_delay_q[i] <= reg2hw.pwm_param[i].phase_delay.q;
        duty_cycle_q[i]  <= reg2hw.pwm_param[i].duty_cycle.q;
      end
    end
  end

  // --------------------------------------------------------------------------
  // Counter control
  // --------------------------------------------------------------------------

  logic                clr_phase_cntr;
  logic [3:0]          lshift;

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

  assign clr_phase_cntr = clk_div_qe_q | dc_resn_qe_q | cntr_en_qe_q;
  assign lshift         = 4'd15 - dc_resn_q;

  // --------------------------------------------------------------------------
  // Beat counter
  // --------------------------------------------------------------------------

  always_comb begin
    beat_end    = (beat_ctr_q == clk_div_q);
    beat_ctr_en = clr_phase_cntr | cntr_en_q;

    if (clr_phase_cntr) begin
      beat_ctr_d = '0;
    end else if (beat_end) begin
      beat_ctr_d = '0;
    end else begin
      beat_ctr_d = beat_ctr_q + 1'b1;
    end
  end

  always_ff @(posedge clk_core_i or negedge rst_core_ni) begin
    if (!rst_core_ni) begin
      beat_ctr_q <= '0;
    end else if (beat_ctr_en) begin
      beat_ctr_q <= beat_ctr_d;
    end
  end

  // --------------------------------------------------------------------------
  // Phase counter
  // --------------------------------------------------------------------------

  always_comb begin
    phase_ctr_en      = beat_end & (clr_phase_cntr | cntr_en_q);
    phase_ctr_incr    = '0;
    phase_ctr_incr[0] = 1'b1;
    phase_ctr_incr    = phase_ctr_incr << lshift;

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
  // PWM channels
  // --------------------------------------------------------------------------

  for (genvar ii = 0; ii < NOutputs; ii++) begin : gen_chan_insts
    pwm_chan #(
      .CntDw(PhaseCntDw)
    ) u_chan (
      .clk_i          (clk_core_i),
      .rst_ni         (rst_core_ni),
      .pwm_en_i       (pwm_en_q[ii]),
      .phase_delay_i  (phase_delay_q[ii]),
      .duty_cycle_a_i (duty_cycle_q[ii]),
      .phase_ctr_i    (phase_ctr_q),
      .cycle_end_i    (cycle_end),
      .dc_resn_i      (dc_resn_q),
      .pwm_o          (pwm_o[ii])
    );
  end

endmodule : pwm_core
