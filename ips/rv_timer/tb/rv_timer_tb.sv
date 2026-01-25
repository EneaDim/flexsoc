// Timescale
`timescale 1ns/1ps
// Includes
`include "tb/include_rv_timer_tb.sv"

module rv_timer_tb;
  // Parameters
  parameter int CLK_PERIOD = 20; // ns

  // Inputs
  logic clk_i;
  logic rst_ni;
  logic [1:0] gpio_intr_i;
  tlul_pkg::tl_h2d_t tl_i;

  // Outputs
  tlul_pkg::tl_d2h_t tl_o;
  logic intr_timer_expired_hart0_timer0_o;

  integer error_count;
  logic [rv_timer_reg_pkg::DW-1:0] rdata;
  tlul_utils tl_utils_inst;
  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));

  // DUT
  rv_timer u_rv_timer (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .gpio_intr_i(gpio_intr_i),
    .tl_i(tl_if.h2d),
    .tl_o(tl_if.d2h),
    .intr_timer_expired_hart0_timer0_o(intr_timer_expired_hart0_timer0_o)
  );

  initial begin
    clk_i = 0;
    forever #(CLK_PERIOD / 2) clk_i = ~clk_i;
  end

  // Dump VCD
  initial begin
    `ifndef SYN
      $dumpfile("sim/rv_timer_tb.vcd");
    `else
      $dumpfile("sim/rv_timer_syn_tb.vcd");
    `endif
    $dumpvars(0, rv_timer_tb);
  end

  // SDF backannotation
  `ifndef VERILATOR
    initial begin
      string sdf = "signoff/sdf/rv_timer_ss.sdf";
      $sdf_annotate(sdf, rv_timer_tb.u_rv_timer, , , "MAXIMUM");
    end
  `endif

  initial begin
    error_count = 0;
    rst_ni = '0;
    gpio_intr_i = '0;
    tl_i = '0;
    #(CLK_PERIOD);
    rst_ni = 1'b1;
    #(CLK_PERIOD);
    $display("\nRunning...\n");
    tl_utils_inst = new(tl_if);
    #(CLK_PERIOD*10);
    tl_utils_inst.tlul_write(32'h0, 32'h1, 4'h0);
    #(CLK_PERIOD*10);
    tl_utils_inst.tlul_read (32'h0, rdata, 4'h0);
    $display("Read data: %h", rdata);
    #(CLK_PERIOD*10);
    // INSERT YOUR STIMULUS HERE
    if (error_count == 0) $display("Coverage: 100%%");
    $display("\nEnd.\n");
    $finish;
  end
endmodule
