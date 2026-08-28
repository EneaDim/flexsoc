// SPDX-License-Identifier: Apache-2.0
//
// Authored 4-bit GPIO core.
// Keep the module header compact: `fx top_from_core` parses this port list.

module gpio_core
  import gpio_reg_pkg::*;
(
  input  logic         clk_i,
  input  logic         rst_ni,
  input  gpio_reg2hw_t reg2hw,
  output gpio_hw2reg_t hw2reg,

  input  logic [3:0]   cio_gpio_i,
  output logic [3:0]   cio_gpio_o,
  output logic [3:0]   cio_gpio_en_o,
  output logic [3:0]   intr_gpio_o
);

  // GPIO is intentionally fixed to four pins in this reference IP.
  // Synchronizers remain enabled for asynchronous pad inputs.
  localparam bit GpioAsyncOn = 1'b1;
  localparam int unsigned FilterCntWidth = 4;

  logic [3:0] data_in_d;
  logic [3:0] data_in_q;
  logic [3:0] gpio_o_q;
  logic [3:0] gpio_oe_q;

  logic [3:0] event_rise;
  logic [3:0] event_fall;
  logic [3:0] event_high;
  logic [3:0] event_low;

  for (genvar i = 0; i < 4; i++) begin : gen_input_filter
    prim_filter_ctr #(
      .AsyncOn  (GpioAsyncOn),
      .CntWidth (FilterCntWidth)
    ) u_filter (
      .clk_i    (clk_i),
      .rst_ni   (rst_ni),
      .enable_i (reg2hw.intr_ctrl.en_input_filter.q[i]),
      .filter_i (cio_gpio_i[i]),
      .thresh_i ({FilterCntWidth{1'b1}}),
      .filter_o (data_in_d[i])
    );
  end

  // Software-visible filtered input readback.
  assign hw2reg.data_in.de = 1'b1;
  assign hw2reg.data_in.d  = data_in_d;

  // Direct GPIO outputs are stored in the authored core. The generated
  // register block supplies q/qe and receives the live state through hw2reg.
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      gpio_o_q <= '0;
    end else if (reg2hw.direct.gpio_o.qe) begin
      gpio_o_q <= reg2hw.direct.gpio_o.q;
    end
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      gpio_oe_q <= '0;
    end else if (reg2hw.direct.gpio_oe.qe) begin
      gpio_oe_q <= reg2hw.direct.gpio_oe.q;
    end
  end

  assign cio_gpio_o    = gpio_o_q;
  assign cio_gpio_en_o = gpio_oe_q;

  assign hw2reg.direct.gpio_o.d  = gpio_o_q;
  assign hw2reg.direct.gpio_oe.d = gpio_oe_q;

  // Keep one previous filtered sample for edge detection.
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      data_in_q <= '0;
    end else begin
      data_in_q <= data_in_d;
    end
  end

  assign event_rise = (~data_in_q &  data_in_d) & reg2hw.intr_ctrl.en_rising.q;
  assign event_fall = ( data_in_q & ~data_in_d) & reg2hw.intr_ctrl.en_falling.q;
  assign event_high =                  data_in_d  & reg2hw.intr_ctrl.en_lvlhigh.q;
  assign event_low  =                 ~data_in_d  & reg2hw.intr_ctrl.en_lvllow.q;

  assign intr_gpio_o = event_rise | event_fall | event_high | event_low;

endmodule
