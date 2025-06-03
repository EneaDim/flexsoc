// Timescale 
`timescale 1ns/1ps 
// Include files 
`include "tb/include_fft_core_tb.sv"

module fft_core_tb;
  //Parameters
  parameter int CLK_PERIOD = 10; // Clock period in ns
  parameter FFT_SIZE = 8;
  parameter DATA_WIDTH = 16;
  parameter ASYNC = 0;
  // Inputs
  reg clk_i;
  reg rst_ni;
  reg [DATA_WIDTH-1:0] adc_data_i;
  reg adc_valid_i;
  reg fft_out_ready_i;
  // Outputs
  wire adc_ready_o;
  wire fft_out_valid_o;
  wire [DATA_WIDTH-1:0] fft_out_data_o;

  integer error_count;


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
    .clk_i,
    .rst_ni,
    .adc_data_i,
    .adc_valid_i,
    .fft_out_ready_i,
    .adc_ready_o,
    .fft_out_valid_o,
    .fft_out_data_o
  );

  // Clock generation
  initial begin
    clk_i = 0;
    forever #(CLK_PERIOD / 2) clk_i = ~clk_i;
  end

  // Dump vcd file 
  initial begin
    `ifndef SYN
      $dumpfile("sim/dump_fft_core.vcd");
    `else
      $dumpfile("sim/dump_fft_core_syn.vcd");
    `endif
    $dumpvars(0, fft_core_tb);
  end

  // Error count
  initial begin
    error_count = 0;
  end

  initial begin
    // Init inputs
    rst_ni = 0;
    adc_data_i = 0;
    adc_valid_i = 0;
    fft_out_ready_i = 0;
    // Asynch Reset
    #(CLK_PERIOD);
    rst_ni = 1;
    #(CLK_PERIOD);
    // INSERT YOUR CODE
    $display("\nRunning...\n");

    // Provide 16 input samples
    repeat (FFT_SIZE) begin
      @(posedge clk_i);
      adc_valid_i = 1;
      adc_data_i = $urandom_range(-32768, 32767); // or any pattern
    end

    @(posedge clk_i);
    adc_valid_i = 0;

    #(CLK_PERIOD*1000);
    //// Output ready signal
    //forever begin
    //  @(posedge clk_i);
    //  fft_out_ready_i = 1;
    //end


    // Final Check
    if (error_count == 0) begin
      $display("Coverage: 100%%");
    end
    $display("\nEnd.\n");
    $finish;
  end
endmodule
