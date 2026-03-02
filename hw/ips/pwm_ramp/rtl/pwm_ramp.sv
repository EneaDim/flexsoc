module pwm_ramp #(
  parameter int NBITS = 8,
  parameter logic [NBITS-1:0] ResetValue = 0
)(
  input  logic             clk_i,
  input  logic             rst_ni,
  input  logic             enable_i,
  input  logic             reverse_i,
  input  logic [NBITS-1:0] step_i,
  input  logic             lvds_i,
  output logic             pwm_o,
  output logic [NBITS-1:0] adc_value_o,
  output logic             adc_valid_o
);

  // Localparams
  localparam int MAX_CNT = (2**NBITS) - 1;

  // Counter and duty cycle
  logic [NBITS-1:0] duty_cycle;
  logic [NBITS-1:0] counter;

  logic clear;
  logic pwm_drive_w;

  // LVDS
  logic lvds, lvds_rise, lvds_fall;

  // Sync and filter 
  prim_deglitch #( .AsyncOn(1), .SIZE(3)) 
  u_prim_deglitch (
    .clk_i,
    .rst_ni,
    .en_i(enable_i),
    .d_i(lvds_i),
    .q_o(lvds)
  );

  // Rise detection
  prim_edge_detect
  u_prim_edge_detect (
    .clk_i,
    .rst_ni,
    .en_i(enable_i),
    .serial_i(lvds),
    .r_edge_o(lvds_rise),
    .f_edge_o(lvds_fall)
  );

  // ADC value latching and clearing
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      clear       <= 1'b0;
      adc_valid_o <= 1'b0;
      adc_value_o <= 'd0;
    end else if (lvds_rise) begin
      clear       <= 1'b1;
      adc_valid_o <= 1'b1;
      if (reverse_i) begin
        adc_value_o <= {NBITS{1'b1}} - duty_cycle;
      end else begin
        adc_value_o <= duty_cycle;
      end
    end else if (clear) begin
      clear       <= 1'b0;
      adc_valid_o <= 1'b0;
    end
  end
  
  // Counter track
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin            // Asynch Reset
      counter <= '0;
      duty_cycle <= ResetValue;
    end else if (clear) begin     // Clear when analog signal reached 
        counter <= '0;
        duty_cycle <= ResetValue;
    end else if (enable_i) begin
      // Increment duty cycle by step_i and wrap counter when MAX_CNT
      if (counter == MAX_CNT[NBITS-1:0]) begin
        duty_cycle <= duty_cycle + step_i;
        counter <= '0;
      end else begin
        counter <= counter + 1;
      end
    end
  end

  assign pwm_drive_w = (reverse_i) ? (counter > duty_cycle) : (counter < duty_cycle);
  assign pwm_o       = (pwm_drive_w) ? 1'b1 : 1'b0;

endmodule

