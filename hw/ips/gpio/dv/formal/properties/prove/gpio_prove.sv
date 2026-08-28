// Authored design-level formal properties for the 4-bit GPIO core.

module gpio_design_prove
  import gpio_reg_pkg::*;
(
  input logic          clk_i,
  input logic          rst_ni,
  input gpio_reg2hw_t  reg2hw,
  input gpio_hw2reg_t  hw2reg,
  input logic [3:0]    data_in_d,
  input logic [3:0]    data_in_q,
  input logic [3:0]    cio_gpio_o,
  input logic [3:0]    cio_gpio_en_o,
  input logic [3:0]    intr_gpio_o
);

  logic past_valid = 1'b0;
  logic reset_seen = 1'b0;
  logic [3:0] expected_intr;

  always_comb begin
    expected_intr =
        ((~data_in_q &  data_in_d) & reg2hw.intr_ctrl.en_rising.q)
      | (( data_in_q & ~data_in_d) & reg2hw.intr_ctrl.en_falling.q)
      | (                   data_in_d  & reg2hw.intr_ctrl.en_lvlhigh.q)
      | (                  ~data_in_d  & reg2hw.intr_ctrl.en_lvllow.q);
  end

  always_ff @(posedge clk_i) begin
    past_valid <= 1'b1;

    if (!rst_ni) begin
      reset_seen <= 1'b1;
      assert (cio_gpio_o == 4'h0);
      assert (cio_gpio_en_o == 4'h0);
    end else if (reset_seen) begin
      assert (hw2reg.data_in.de);
      assert (hw2reg.data_in.d == data_in_d);
      assert (hw2reg.direct.gpio_o.d == cio_gpio_o);
      assert (hw2reg.direct.gpio_oe.d == cio_gpio_en_o);
      assert (intr_gpio_o == expected_intr);

      if (past_valid && $past(reset_seen && rst_ni)) begin
        if ($past(reg2hw.direct.gpio_o.qe)) begin
          assert (cio_gpio_o == $past(reg2hw.direct.gpio_o.q));
        end else begin
          assert (cio_gpio_o == $past(cio_gpio_o));
        end

        if ($past(reg2hw.direct.gpio_oe.qe)) begin
          assert (cio_gpio_en_o == $past(reg2hw.direct.gpio_oe.q));
        end else begin
          assert (cio_gpio_en_o == $past(cio_gpio_en_o));
        end
      end
    end
  end

endmodule

bind gpio_core gpio_design_prove gpio_design_prove_i (
  .clk_i         (clk_i),
  .rst_ni        (rst_ni),
  .reg2hw        (reg2hw),
  .hw2reg        (hw2reg),
  .data_in_d     (data_in_d),
  .data_in_q     (data_in_q),
  .cio_gpio_o    (cio_gpio_o),
  .cio_gpio_en_o (cio_gpio_en_o),
  .intr_gpio_o   (intr_gpio_o)
);
