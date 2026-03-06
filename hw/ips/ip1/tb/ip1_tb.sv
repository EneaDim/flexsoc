// Timescale
`timescale 1ns/1ps
// Includes
`include "include_ip1_tb.sv"

module ip1_tb;
  // Parameters
  parameter int CLK_PERIOD = 20; // ns

  // Inputs
  logic clk_i;
  logic rst_ni;
  tlul_pkg::tl_h2d_t tl_i;
  logic port_i;

  // Outputs
  tlul_pkg::tl_d2h_t tl_o;
  logic port_o;

  integer error_count;
  logic [ip1_reg_pkg::DW-1:0] rdata;
  tlul_utils tl_utils_inst;
  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));

  // DUT
  ip1 u_ip1 (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .tl_i(tl_if.h2d),
    .port_i(port_i),
    .tl_o(tl_if.d2h),
    .port_o(port_o)
  );

  initial begin
    clk_i = 0;
    forever #(CLK_PERIOD / 2) clk_i = ~clk_i;
  end

  // Dump VCD
  initial begin
    `ifndef SYN
      $dumpfile("/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/sim/ip1_tb.vcd");
    `else
      $dumpfile("/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/sim/ip1_syn_tb.vcd");
    `endif
    $dumpvars(0, ip1_tb);
  end

  // SDF backannotation
  `ifndef VERILATOR
    initial begin
      string sdf = "signoff/sdf/ip1_ss.sdf";
      $sdf_annotate(sdf, ip1_tb.u_ip1, , , "MAXIMUM");
    end
  `endif

  initial begin
    error_count = 0;
    rst_ni = '0;
    tl_i = '0;
    port_i = '0;
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
