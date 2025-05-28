`timescale 1ns/1ps 
`include "tb/include_fft_core_tb.sv"

module fft_core_tb;
  // Parameters
  parameter int CLK_PERIOD = 10; // Clock period in ns
  parameter FFT_SIZE = 1024;
  parameter DATA_WIDTH = 16;
  parameter ASYNC = 0;

  // Inputs
  reg clk_i;
  reg rst_ni;
  reg signed [DATA_WIDTH-1:0] adc_data_i;
  reg adc_valid_i;
  reg fft_out_ready_i;

  // Outputs
  wire adc_ready_o;
  wire fft_out_valid_o;
  wire signed [2*DATA_WIDTH-1:0] fft_out_data_o;

  reg signed [DATA_WIDTH-1:0] real_part;
  reg signed [DATA_WIDTH-1:0] imag_part;

  integer error_count;
   
  int timeout = 0;

  // Device Under Test Instance
  fft_core
  `ifndef SYN
    #(
      .FFT_SIZE(FFT_SIZE),
      .DATA_WIDTH(DATA_WIDTH),
      .ASYNC(ASYNC)
    ) 
  `endif
  u_fft_core (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .adc_data_i(adc_data_i),
    .adc_valid_i(adc_valid_i),
    .fft_out_ready_i(fft_out_ready_i),
    .adc_ready_o(adc_ready_o),
    .fft_out_valid_o(fft_out_valid_o),
    .fft_out_data_o(fft_out_data_o)
  );

  // Clock generation
  initial begin
    clk_i = 0;
    forever #(CLK_PERIOD / 2) clk_i = ~clk_i;
  end

  // Dump VCD file
  initial begin
    `ifndef SYN
      $dumpfile("sim/dump_fft_core.vcd");
    `else
      $dumpfile("sim/dump_fft_core_syn.vcd");
    `endif
    $dumpvars(0, fft_core_tb);
    for (int i = 0; i < FFT_SIZE; i++) begin
      $dumpvars(0, u_fft_core.stage_buffer[i]);
    end
  end

  // Error count
  initial error_count = 0;

  // Test variables
  integer i;
  real pi = 3.14159265358979323846;
  real sine_val, magnitude;
  real real_val, imag_val;
  reg signed [DATA_WIDTH-1:0] test_input [0:FFT_SIZE-1];

  // Generate test input (sine wave)
  initial begin
    for (i = 0; i < FFT_SIZE; i++) begin
      sine_val = $sin(2.0 * pi * i / FFT_SIZE*10);
      // Convert to Q1.15 format (scaled by 2^15)
      test_input[i] = $rtoi(sine_val * 32767.0);
    end
  end

  // File handling
  integer fd;
  initial fd = $fopen("fft_output.txt", "w");
    
  // Stimulus process
  initial begin
    // Init inputs
    rst_ni = 0;
    adc_data_i = 0;
    adc_valid_i = 0;
    fft_out_ready_i = 0;

    // Reset pulse
    #(CLK_PERIOD * 2);
    rst_ni = 1;

    // Wait a cycle
    @(negedge clk_i);

    // Feed samples
    i = 0;
    while (i < FFT_SIZE && timeout < 10000) begin
      if (adc_ready_o) begin
        adc_data_i <= test_input[i];
        adc_valid_i <= 1;
        i++;
        timeout = 0;
      end else begin
        adc_valid_i <= 0;
        timeout++;
      end
      @(negedge clk_i);
    end
    if (timeout >= 10000) begin
      $error("Timeout while waiting for adc_ready_o");
      $finish;
    end
    adc_valid_i <= 0;

    // Start reading outputs
    fft_out_ready_i <= 1;
    i = 0;
    timeout = 0;
    while (i < FFT_SIZE*15 && timeout < 100000) begin
      @(negedge clk_i);
      if (fft_out_valid_o) begin
        real_val = fft_out_data_o[2*DATA_WIDTH-1:DATA_WIDTH];
        imag_val = fft_out_data_o[DATA_WIDTH-1:0];
        magnitude = $sqrt(real_val*real_val + imag_val*imag_val);
        $display("FFT Magnitude[%0d] = %f", i, magnitude);
        $fwrite(fd, "%0f\n", magnitude);
        i++;
        timeout = 0;
      end else begin
        timeout++;
      end
    end
    if (timeout >= 100000) begin
      $fclose(fd);
      $finish;
    end
    fft_out_ready_i <= 0;

    $finish;
  end

endmodule

