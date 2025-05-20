// Timescale 
`timescale 1ns/1ps 
// Include files 
`include "tb/include_multiple_pwm_ramp_tb.sv"

module multiple_pwm_ramp_tb;
  //Parameters
  parameter int CLK_PERIOD = 10; // Clock period in ns
  parameter NBITS = 6;
  // Inputs
  reg clk_i;
  reg rst_ni;
  reg enable_i;
  reg [NBITS-1:0] step_i;
  reg lvds_0_i;
  reg lvds_1_i;
  // Outputs
  wire pwm_0;
  wire pwm_1;
  wire [NBITS-1:0] adc_value_o;
  wire adc_valid_o;

  integer error_count;

  // Other parameters
  parameter real LSB = 1.0 / ((2**NBITS)-1); // Least Significant Bit value

  // Analog
  real analog_input;
  real adc_value_ana_0;
  real adc_value_ana_1;

  // LVDS
  logic lvds_0, lvds_1;
  
  // RC FILTER
  real filtered_out_0, filtered_out_1;

  // Other signals
  logic [NBITS-1:0] adc_value_0, adc_value_1;
  logic adc_valid_0, adc_valid_1;

  // Device Under Test Instance
  multiple_pwm_ramp
  `ifndef SYN
    #(
      .NBITS(NBITS)
    ) 
  `endif
  u_multiple_pwm_ramp (
    .clk_i,
    .rst_ni,
    .enable_i,
    .step_i      ('d1),
    .lvds_0_i    (lvds_0),
    .lvds_1_i    (lvds_1),
    .pwm_0_o     (pwm_0),
    .pwm_1_o     (pwm_1),
    .adc_value_o (adc_value_0),
    .adc_valid_o (adc_valid_0)
  );
  
  // Instantiate filter with ALPHA = 0.05 (adjust smoothing)
  rc_filter #( .ALPHA(0.007), .VDD(1) ) u_rc_filter_0 (
    .clk_i,
    .rst_ni,
    .in(pwm_0),
    .out(filtered_out_0)
  );
 
  // LVDS
  lvds u_lvds_0(
      .lp(filtered_out_0),
      .ln(analog_input),
      .lvds_o(lvds_0)
  );
  
  // Instantiate filter with ALPHA = 0.05 (adjust smoothing)
  rc_filter #( .ALPHA(0.007), .VDD(1) ) u_rc_filter_1 (
    .clk_i,
    .rst_ni,
    .in(pwm_1),
    .out(filtered_out_1)
  );
 
  // LVDS
  lvds u_lvds_1(
      .lp(filtered_out_1),
      .ln(analog_input),
      .lvds_o(lvds_1)
  );

  assign adc_value_ana_0 = adc_value_0 * LSB;
  assign adc_value_ana_1 = adc_value_1 * LSB;

  // Clock generation
  initial begin
    clk_i = 0;
    forever #(CLK_PERIOD / 2) clk_i = ~clk_i;
  end

  // Dump vcd file 
  initial begin
    `ifndef SYN
      $dumpfile("sim/dump_multiple_pwm_ramp.vcd");
    `else
      $dumpfile("sim/dump_multiple_pwm_ramp_syn.vcd");
    `endif
    $dumpvars(0, multiple_pwm_ramp_tb);
  end

  // Error count
  initial begin
    error_count = 0;
  end

  // Generate a sine wave
  task automatic drive_sine_wave(input real amplitude, input real offset, input real freq_hz, input real duration_us, input real timestep_ns);
    real t_ns;
    real period_ns = 1e9 / freq_hz;
    for (t_ns = 0.0; t_ns < duration_us * 1000; t_ns += timestep_ns) begin
      analog_input = offset + amplitude * $sin(2.0 * 3.141592653589 * t_ns / period_ns);
      #(timestep_ns);
    end
  endtask
  
  // Generate a triangle wave
  task automatic drive_triangle_wave(input real amplitude, input real offset, input real freq_hz, input real duration_us, input real timestep_ns);
    real t_ns;
    real period_ns = 1e9 / freq_hz;
    real phase, frac;
    for (t_ns = 0.0; t_ns < duration_us * 1000; t_ns += timestep_ns) begin
      frac = t_ns - period_ns * $floor(t_ns / period_ns);  // real modulo
      phase = frac / period_ns;
      if (phase < 0.5)
        analog_input = offset + amplitude * (4.0 * phase - 1.0);
      else
        analog_input = offset + amplitude * (3.0 - 4.0 * phase);
      #(timestep_ns);
    end
  endtask
  
  // Generate a sawtooth wave
  task automatic drive_sawtooth_wave(input real amplitude, input real offset, input real freq_hz, input real duration_us, input real timestep_ns);
    real t_ns;
    real period_ns = 1e9 / freq_hz;
    real phase, frac;
    for (t_ns = 0.0; t_ns < duration_us * 1000; t_ns += timestep_ns) begin
      frac = t_ns - period_ns * $floor(t_ns / period_ns);  // real modulo
      phase = frac / period_ns;
      analog_input = offset + amplitude * (2.0 * phase - 1.0);
      #(timestep_ns);
    end
  endtask

  initial begin
    // Init inputs
    rst_ni = 0;
    enable_i = 0;
    step_i = 'd1;
    lvds_0_i = 0;
    lvds_1_i = 0;
    // Asynch Reset
    #(CLK_PERIOD);
    rst_ni = 1;
    #(CLK_PERIOD);
    // Start main test
    $display("\nRunning...\n");
    // INSERT YOUR CODE
    enable_i = 1;

    #(CLK_PERIOD*100);
    // Parameters: amplitude, offset, frequency (Hz), duration (us), timestep (ns)
    //drive_sine_wave(0.5, 0.5, 10_000.0, 1000.0, 10.0);  // 100 kHz sine, 1 ms duration, 10 ns step 
    drive_sine_wave(0.3, 0.5, 1_000.0, 3000.0, 10.0);   // 1 kHz sine, 3 ms duration, 10 ns step 
    #(CLK_PERIOD*100);
    
    // Final Check
    if (error_count == 0) begin
      $display("Coverage: 100%%");
    end
    $display("\nEnd.\n");
    $finish;
  end
endmodule
