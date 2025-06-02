// Timescale 
`timescale 1ns/1ps 
// Include files 
`include "tb/include_fft_fsm_tb.sv"

module fft_fsm_tb;
  //Parameters
  parameter int CLK_PERIOD = 10; // Clock period in ns
  // Inputs
  reg clk_i;
  reg rst_ni;
  reg start_i;
  reg end_samples_i;
  reg end_compute_i;
  reg end_algo_i;
  // Outputs
  wire en_cnt_samples_o;
  wire wr_mem_o;
  wire en_cnt_rd_o;
  wire done_o;

  integer error_count;


  // Device Under Test Instance
  fft_fsm
  u_fft_fsm (
    .clk_i,
    .rst_ni,
    .start_i,
    .end_samples_i,
    .end_compute_i,
    .end_algo_i,
    .en_cnt_samples_o,
    .wr_mem_o,
    .en_cnt_rd_o,
    .done_o
  );

  // Clock generation
  initial begin
    clk_i = 0;
    forever #(CLK_PERIOD / 2) clk_i = ~clk_i;
  end

  // Dump vcd file 
  initial begin
    `ifndef SYN
      $dumpfile("sim/dump_fft_fsm.vcd");
    `else
      $dumpfile("sim/dump_fft_fsm_syn.vcd");
    `endif
    $dumpvars(0, fft_fsm_tb);
  end

  // Error count
  initial begin
    error_count = 0;
  end

  initial begin
    // Init inputs
    rst_ni = 0;
    start_i = 0;
    end_samples_i = 0;
    end_compute_i = 0;
    end_algo_i = 0;
    // Asynch Reset
    #(CLK_PERIOD);
    rst_ni = 1;
    #(CLK_PERIOD);
    // Start main test
    $display("\nRunning...\n");
    // INSERT YOUR CODE


    // Final Check
    if (error_count == 0) begin
      $display("Coverage: 100%%");
    end
    $display("\nEnd.\n");
    $finish;
  end
endmodule
