module controller #(
  parameter NBITS = 8
) (
  input  logic             clk_i,
  input  logic             rst_ni,
  input  logic             lvds_i,
  input  logic [NBITS-1:0] pwm_dc_i,
  output logic [NBITS-1:0] adc_value_o,
  output logic             clear_pwm_count_o
);

  logic lvds_q;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      lvds_q <= 0;
      adc_value_o <= 0;
      clear_pwm_count_o <= 0;
    end else begin
      lvds_q <= lvds_i;
      clear_pwm_count_o <= 0;

      if (lvds_i && !lvds_q) begin
        adc_value_o <= pwm_dc_i;
        clear_pwm_count_o <= 1;  // trigger PWM reset
      end
    end
  end

endmodule

