module multiple_pwm_ramp #(
  parameter int NBITS = 8
)(
  input  logic             clk_i,
  input  logic             rst_ni,
  input  logic             enable_i,
  input  logic [NBITS-1:0] step_i,
  input  logic             lvds_0_i,
  input  logic             lvds_1_i,
  output logic             pwm_0_o,
  output logic             pwm_1_o,
  output logic [NBITS-1:0] adc_value_o,
  output logic             adc_valid_o
);

  // Localparams
  localparam int MAX_CNT = (2**NBITS) - 1;
  localparam int HNBITS = NBITS-1;

  // ADC data and valid
  logic [NBITS-1:0] adc_value_0, adc_value_1;
  logic adc_valid_0, adc_valid_1;

  // LVDS
  logic lvds, lvds_rise;

  pwm_ramp #( .NBITS(NBITS), .ResetValue('d0)) 
  u_pwm_ramp_0 ( .clk_i, .rst_ni,
    .enable_i   (enable_i),
    .reverse_i  (1'b0),
    .step_i     ('d1),
    .lvds_i     (lvds_0_i),
    .pwm_o      (pwm_0_o),
    .adc_value_o(adc_value_0),
    .adc_valid_o(adc_valid_0)
  );

  pwm_ramp #( .NBITS(NBITS), .ResetValue({1'b0, {HNBITS{1'b1}}})) 
  u_pwm_ramp_1 ( .clk_i, .rst_ni,
    .enable_i   (enable_i),
    .reverse_i  (1'b0),
    .step_i     ('d1),
    .lvds_i     (lvds_1_i),
    .pwm_o      (pwm_1_o),
    .adc_value_o(adc_value_1),
    .adc_valid_o(adc_valid_1)
  );

endmodule

