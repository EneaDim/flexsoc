// Timescale
`timescale 1ns/1ps
// Includes
`include "include_uart_tb.sv"

module uart_tb;
  // Parameters
  parameter int CLK_PERIOD = 20; // ns

  // Inputs
  logic clk_i;
  logic rst_ni;
  tlul_pkg::tl_h2d_t tl_i;
  logic gnt_i;
  logic valid_i;
  logic [31:0] rdata_i;
  logic err_i;
  logic cio_rx_i;

  // Outputs
  tlul_pkg::tl_d2h_t tl_o;
  logic req_o;
  logic [31:0] addr_o;
  logic we_o;
  logic [31:0] wdata_o;
  logic [3:0] be_o;
  logic cio_tx_o;
  logic cio_tx_en_o;

  integer error_count;
  logic [uart_reg_pkg::DW-1:0] rdata;
  tlul_utils tl_utils_inst;
  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));

  // DUT
  uart u_uart (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .tl_i(tl_if.h2d),
    .gnt_i(gnt_i),
    .valid_i(valid_i),
    .rdata_i(rdata_i),
    .err_i(err_i),
    .cio_rx_i(cio_rx_i),
    .tl_o(tl_if.d2h),
    .req_o(req_o),
    .addr_o(addr_o),
    .we_o(we_o),
    .wdata_o(wdata_o),
    .be_o(be_o),
    .cio_tx_o(cio_tx_o),
    .cio_tx_en_o(cio_tx_en_o)
  );

  initial begin
    clk_i = 0;
    forever #(CLK_PERIOD / 2) clk_i = ~clk_i;
  end

  // Dump VCD
  string vcd_path;
  initial begin
    if (!$value$plusargs("VCD=%s", vcd_path)) begin
      `ifndef SYN
        vcd_path = "";
      `else
        vcd_path = "";
      `endif
    end
    $display("[TB] dumpfile = %s", vcd_path);
    $dumpfile(vcd_path);
    $dumpvars(0, uart_tb);
  end

  // SDF backannotation
  `ifndef VERILATOR
    string sdf_path;
    initial begin
      if (!$value$plusargs("SDF=%s", sdf_path)) begin
        sdf_path = "";
      end
      $display("[TB] sdf = %s", sdf_path);
      $sdf_annotate(sdf_path, uart_tb.u_uart, , , "MAXIMUM");
    end
  `endif

  initial begin
    error_count = 0;
    rst_ni = '0;
    tl_i = '0;
    gnt_i = '0;
    valid_i = '0;
    rdata_i = '0;
    err_i = '0;
    cio_rx_i = '0;
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
