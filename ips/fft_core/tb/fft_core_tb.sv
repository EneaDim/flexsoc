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
  parameter real PI = 3.141592653589793;
  parameter int SCALE = 32767; // max Q1.15

  // Inputs
  reg clk_i;
  reg rst_ni;
  reg read_ram_i;
  reg [DATA_WIDTH-1:0] adc_data_i;
  reg adc_valid_i;
  reg fft_out_ready_i;
  // Outputs
  wire adc_ready_o;
  wire fft_out_valid_o;
  wire [DATA_WIDTH-1:0] fft_out_data_o;

  integer error_count;

  // Sine wave generation
  //real    freq      = 6.4; // 1 ciclo su FFT_SIZE campioni
  //real    amplitude = 0.9; // valore tra 0 e 1 (per evitare overflow)
  //int     sample;
  //real    scale     = 32767.0 * amplitude;
    


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
    .read_ram_i,
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
    read_ram_i = 0;
    adc_data_i = 0;
    adc_valid_i = 0;
    fft_out_ready_i = 0;
    // Asynch Reset
    #(CLK_PERIOD);
    rst_ni = 1;
    #(CLK_PERIOD);
    // INSERT YOUR CODE
    $display("\nRunning...\n");

    // Generazione sinusoide Q1.15
    for (int k = 0; k < FFT_SIZE; k++) begin
      real theta = 2.0 * PI * 1.0 * k / FFT_SIZE; // k_bin = 1
      real sine_real = $sin(theta);
      int  sample_q15 = $rtoi(SCALE * sine_real); // Q1.15

      @(negedge clk_i);
      adc_valid_i = 1;
      adc_data_i  = sample_q15;

      // Debug opzionale
      $display("k=%0d, theta=%.4f, sin=%.4f, Q15=%0d (0x%04h)", 
                k, theta, sine_real, sample_q15, sample_q15[15:0]);
    end

    // Fine stimoli
    @(negedge clk_i);
    adc_valid_i = 0;
    adc_data_i  = 16'sd0;
    // 
    // Dopo la scrittura della FFT
    //
    #(CLK_PERIOD * FFT_SIZE * 100);
    read_ram_i = 1;
    
    @(posedge clk_i);
    for (int i = 0; i < FFT_SIZE; i++) begin
      @(posedge clk_i);
      $display("read[%0d]: res_re = %0d (0x%04h), res_im = %0d (0x%04h)",
               i, u_fft_core.res_re, u_fft_core.res_re[15:0],
                  u_fft_core.res_im, u_fft_core.res_im[15:0]);
    end
    
    read_ram_i = 0;

    #(CLK_PERIOD*FFT_SIZE*100);
    read_ram_i = 1;

    #(CLK_PERIOD*(FFT_SIZE-1));
    read_ram_i = 0;
    
    #(CLK_PERIOD*FFT_SIZE*100);
    
    $display("Read ram done");
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
