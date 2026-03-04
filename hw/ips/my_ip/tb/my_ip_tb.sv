// Timescale
`timescale 1ns/1ps
// Includes
`include "include_my_ip_tb.sv"

module my_ip_tb;
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
  logic [my_ip_reg_pkg::DW-1:0] rdata;
  tlul_utils tl_utils_inst;
  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));

  // DUT
  my_ip u_my_ip (
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
      $dumpfile("/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/sim/my_ip_tb.vcd");
    `else
      $dumpfile("/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/sim/my_ip_syn_tb.vcd");
    `endif
    $dumpvars(0, my_ip_tb);
  end

  // SDF backannotation
  `ifndef VERILATOR
    initial begin
      string sdf = "signoff/sdf/my_ip_ss.sdf";
      $sdf_annotate(sdf, my_ip_tb.u_my_ip, , , "MAXIMUM");
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
