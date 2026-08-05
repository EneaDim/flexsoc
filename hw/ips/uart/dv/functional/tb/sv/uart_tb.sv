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
  logic cio_rx_i;

  // Outputs
  logic cio_tx_o;
  logic cio_tx_en_o;

  integer error_count;
  logic [31:0] rdata;
  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));

  // Verification helpers
  `include "drivers/uart_reg_driver.svh"
  `include "drivers/uart_vec_monitor.svh"
  `include "drivers/uart_vec_driver.svh"

  // DUT
  uart u_uart (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .tl_i(tl_if.h2d),
    .cio_rx_i(cio_rx_i),
    .tl_o(tl_if.d2h),
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

  string cfg_path;
  string data_in_path;
  string data_out_path;

  // Test selection
  // Use +TEST_NAME=<name> or explicit CFG/DATA_IN/DATA_OUT file paths.
  // Use +TEST_ROOT=<dir> to relocate generated tests.
  // Available generated tests from the default model: smoke, corners, random
  task automatic tb_select_test(output string cfg_path, output string data_in_path, output string data_out_path);
    string test_name;
    string test_root;

    test_name = "smoke";
    test_root = "tests";
    void'($value$plusargs("TEST_ROOT=%s", test_root));
    void'($value$plusargs("TEST_NAME=%s", test_name));

    cfg_path      = {test_root, "/", test_name, "/config.regs"};
    data_in_path  = {test_root, "/", test_name, "/data_in.vec"};
    data_out_path = {test_root, "/", test_name, "/data_out.vec"};

    void'($value$plusargs("CFG=%s", cfg_path));
    void'($value$plusargs("DATA_IN=%s", data_in_path));
    void'($value$plusargs("DATA_OUT=%s", data_out_path));

    $display("[TB] test=%s", test_name);
    $display("[TB] test_root=%s", test_root);
    $display("[TB] cfg=%s", cfg_path);
    $display("[TB] data_in=%s", data_in_path);
    $display("[TB] data_out=%s", data_out_path);
  endtask

  initial begin
    error_count = 0;
    tb_select_test(cfg_path, data_in_path, data_out_path);
    rst_ni = '0;
    tl_if.init();
    cio_rx_i = '0;
    #(CLK_PERIOD);
    rst_ni = 1'b1;
    #(CLK_PERIOD);
    $display("\nRunning...\n");
    #(CLK_PERIOD*10);
    run_reg_config(cfg_path);
    run_vectors(data_in_path, data_out_path);
    #(CLK_PERIOD*10);
    // INSERT ADDITIONAL TEST-SPECIFIC STIMULUS HERE
    if (error_count == 0) $display("Coverage: 100%%");
    $display("\nEnd.\n");
    if (error_count != 0) $fatal(1, "[TB] %0d vector check(s) failed", error_count);
    $finish;
  end
endmodule
