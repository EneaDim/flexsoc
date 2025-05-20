// Timescale 
`timescale 1ns/1ps 
// Include files 
`include "tb/include_pwm_ramp_tb.sv"

module pwm_ramp_tb;
  //Parameters
  parameter int CLK_PERIOD = 10; // Clock period in ns
  parameter NBITS = 6;
  parameter SAR_SEARCH = 0;
  // Inputs
  reg clk_i;
  reg rst_ni;
  reg enable_i;
  reg [NBITS-1:0] step_i;
  // Outputs
  wire [NBITS-1:0] dc;
  wire pwm_o;

  integer error_count;

  // LVDS
  real analog_input;
  logic lvds_out;
  
  // RC FILTER
  real filtered_out;

  // Controller outputs
  logic [NBITS-1:0] adc_value;
  logic clear_pwm_count;

  // Device Under Test Instance
  pwm_ramp
  `ifndef SYN
    #(
      .NBITS(NBITS),
      .SAR_SEARCH(SAR_SEARCH)
    ) 
  `endif
  u_pwm_ramp (
    .clk_i,
    .rst_ni,
    .clear_i(clear_pwm_count),
    .enable_i,
    .step_i,
    .dc_o(dc),
    .pwm_o
  );

  // Instantiate filter with ALPHA = 0.05 (adjust smoothing)
  rc_filter #( .ALPHA(0.05), .VDD(1) ) u_rc_filter (
    .clk_i,
    .rst_ni,
    .in(pwm_o),
    .out(filtered_out)
  );
 
  // LVDS
  lvds lvds_inst(
      .lp(filtered_out),
      .ln(analog_input),
      .data_out(lvds_out)
  );

  // Controller to measure timing of LVDS edges and handle errors
  controller #(
      .NBITS(NBITS)
  ) u_controller (
    .clk_i,
    .rst_ni,
    .lvds_i(lvds_out),
    .pwm_dc_i(dc),
    .adc_value_o(adc_value),
    .clear_pwm_count_o(clear_pwm_count)
  );

  // Clock generation
  initial begin
    clk_i = 0;
    forever #(CLK_PERIOD / 2) clk_i = ~clk_i;
  end

  // Dump vcd file 
  initial begin
    `ifndef SYN
      $dumpfile("sim/dump_pwm_ramp.vcd");
    `else
      $dumpfile("sim/dump_pwm_ramp_syn.vcd");
    `endif
    $dumpvars(0, pwm_ramp_tb);
  end

  // Error count
  initial begin
    error_count = 0;
  end

  initial begin
    // Init inputs
    rst_ni = 0;
    enable_i = 0;
    step_i = 'd1;
    analog_input = 0.0;
    // Asynch Reset
    #(CLK_PERIOD);
    rst_ni = 1;
    #(CLK_PERIOD);
    // Start main test
    $display("\nRunning...\n");
    // INSERT YOUR CODE
    enable_i = 1;

    #(CLK_PERIOD*10000);
    
    for (int i=0; i<100; i++)  begin
      analog_input = analog_input + 0.01;
      #(CLK_PERIOD*1000);
    end

    for (int i=0; i<100; i++)  begin
      analog_input = analog_input - 0.01;
      #(CLK_PERIOD*1000);
    end

    #(CLK_PERIOD*10000);
    //
    //forever begin
    //  #10 analog_input = analog_input + 0.1;
    //  if (analog_input > 1.0)
    //    analog_input = 0.0;
    //end

    // Final Check
    if (error_count == 0) begin
      $display("Coverage: 100%%");
    end
    $display("\nEnd.\n");
    $finish;
  end
endmodule
