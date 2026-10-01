// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// Authored RV timer core.
// The generated rv_timer.sv wrapper owns the register transport and reg block.

module rv_timer_core
  import rv_timer_reg_pkg::*;
(
  input  logic             clk_i,
  input  logic             rst_ni,
  input  rv_timer_reg2hw_t reg2hw,
  output rv_timer_hw2reg_t hw2reg,

  input  logic [1:0]       gpio_intr_i,
  output logic             intr_timer_expired_hart0_timer0_o
);

  logic [N_HARTS-1:0] active;
  logic [11:0] prescaler [N_HARTS];
  logic [7:0]  step      [N_HARTS];

  logic [N_HARTS-1:0] tick;
  logic [31:0] mtime_d  [N_HARTS];
  logic [31:0] mtime    [N_HARTS];
  logic [31:0] mtimecmp [N_HARTS][N_TIMERS];
  logic        mtimecmp_update [N_HARTS][N_TIMERS];

  logic [N_HARTS*N_TIMERS-1:0] intr_timer_set;
  logic [N_HARTS*N_TIMERS-1:0] intr_timer_en;
  logic [N_HARTS*N_TIMERS-1:0] intr_timer_test_q;
  logic [N_HARTS-1:0]          intr_timer_test_qe;
  logic [N_HARTS*N_TIMERS-1:0] intr_timer_state_q;
  logic [N_HARTS-1:0]          intr_timer_state_de;
  logic [N_HARTS*N_TIMERS-1:0] intr_timer_state_d;
  logic [N_HARTS*N_TIMERS-1:0] intr_out;

  logic input_capture_active_d [N_HARTS];
  logic input_capture_active_q [N_HARTS];
  logic sel_gpio_intr_0;
  logic sel_gpio_intr_1;

  assign active[0]  = reg2hw.ctrl[0].active.q || input_capture_active_q[0];
  assign prescaler = '{reg2hw.cfg0.prescale.q};
  assign step      = '{reg2hw.cfg0.step.q};

  assign hw2reg.timer_v0.de = tick[0];
  assign hw2reg.timer_v0.d = mtime_d[0][31:0];
  assign mtime[0] = reg2hw.timer_v0.q;
  assign mtimecmp[0][0] = reg2hw.compare_v0.q;
  assign mtimecmp_update[0][0] = reg2hw.compare_v0.qe;

  assign intr_timer_expired_hart0_timer0_o = intr_out[0];
  assign intr_timer_en            = reg2hw.intr_enable0[0].q;
  assign intr_timer_state_q       = reg2hw.intr_state0[0].q;
  assign intr_timer_test_q        = reg2hw.intr_test0[0].q;
  assign intr_timer_test_qe       = reg2hw.intr_test0[0].qe;
  assign hw2reg.intr_state0[0].de = intr_timer_state_de | mtimecmp_update[0][0];
  assign hw2reg.intr_state0[0].d  = intr_timer_state_d & ~mtimecmp_update[0][0];

  for (genvar h = 0; h < N_HARTS; h++) begin : gen_harts
    prim_intr_hw #(
      .Width(N_TIMERS)
    ) u_intr_hw (
      .clk_i,
      .rst_ni                  (rst_ni),
      .event_intr_i           (intr_timer_set),
      .reg2hw_intr_enable_q_i (intr_timer_en[h*N_TIMERS+:N_TIMERS]),
      .reg2hw_intr_test_q_i   (intr_timer_test_q[h*N_TIMERS+:N_TIMERS]),
      .reg2hw_intr_test_qe_i  (intr_timer_test_qe[h]),
      .reg2hw_intr_state_q_i  (intr_timer_state_q[h*N_TIMERS+:N_TIMERS]),
      .hw2reg_intr_state_de_o (intr_timer_state_de),
      .hw2reg_intr_state_d_o  (intr_timer_state_d[h*N_TIMERS+:N_TIMERS]),
      .intr_o                  (intr_out[h*N_TIMERS+:N_TIMERS])
    );

    rv_timer_counter #(
      .N(N_TIMERS)
    ) u_timer (
      .clk_i,
      .rst_ni    (rst_ni),
      .active    (active[h]),
      .prescaler (prescaler[h]),
      .step      (step[h]),
      .tick      (tick[h]),
      .mtime_d   (mtime_d[h]),
      .mtime     (mtime[h]),
      .mtimecmp  (mtimecmp[h]),
      .intr      (intr_timer_set[h*N_TIMERS+:N_TIMERS])
    );
  end

  assign sel_gpio_intr_0 = !reg2hw.ctrl[0].gpio_intr_1.q &&  reg2hw.ctrl[0].gpio_intr_0.q;
  assign sel_gpio_intr_1 =  reg2hw.ctrl[0].gpio_intr_1.q && !reg2hw.ctrl[0].gpio_intr_0.q;

  assign input_capture_active_d[0] =
      sel_gpio_intr_0 && (input_capture_active_q[0] ^ gpio_intr_i[0]) ||
      sel_gpio_intr_1 && (input_capture_active_q[0] ^ gpio_intr_i[1]);

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      input_capture_active_q[0] <= '0;
    end else begin
      input_capture_active_q[0] <= input_capture_active_d[0];
    end
  end

endmodule


// Parameterized timer datapath kept as an internal authored helper.  Formal
// properties bind here so the counter behavior remains checked independently
// from the generated register transport wrapper.
module rv_timer_counter #(
  parameter int N = 1
) (
  input  logic         clk_i,
  input  logic         rst_ni,
  input  logic         active,
  input  logic [11:0]  prescaler,
  input  logic [7:0]   step,
  output logic         tick,
  output logic [31:0]  mtime_d,
  input  logic [31:0]  mtime,
  input  logic [31:0]  mtimecmp [N],
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

  for (genvar t = 0; t < N; t++) begin : gen_intr
    assign intr[t] = active & (mtime >= mtimecmp[t]);
  end

endmodule
