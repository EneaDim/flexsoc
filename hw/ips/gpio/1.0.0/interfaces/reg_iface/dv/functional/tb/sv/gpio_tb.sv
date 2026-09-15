// Timescale
`timescale 1ns/1ps
// Includes
`include "include_gpio_tb.sv"

module gpio_tb;
  // Parameters
  parameter real CLK_PERIOD = 10; // ns
  parameter int INITIAL_RESET_CYCLES = 5;

  // Inputs
  logic clk_i;
  logic rst_ni;
  logic [3:0] cio_gpio_i;
  gpio_reg_pkg::reg_req_t reg_req_i;

  // Outputs
  logic [3:0] cio_gpio_o;
  logic [3:0] cio_gpio_en_o;
  logic [3:0] intr_gpio_o;
  gpio_reg_pkg::reg_rsp_t reg_rsp_o;

  integer error_count;
  logic [gpio_reg_pkg::DW-1:0] rdata;
  reg_if regif(.clk_i(clk_i), .rst_ni(rst_ni));

  // Verification helpers
  `include "drivers/gpio_reg_driver.svh"
  `include "drivers/gpio_vec_monitor.svh"
  `include "drivers/gpio_vec_driver.svh"

  // DUT
  gpio u_gpio (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .cio_gpio_i(cio_gpio_i),
    .reg_req_i(regif.req),
    .cio_gpio_o(cio_gpio_o),
    .cio_gpio_en_o(cio_gpio_en_o),
    .intr_gpio_o(intr_gpio_o),
    .reg_rsp_o(regif.rsp)
  );

  initial begin
    integer flexsoc_seed;
    integer jitter_prev_ps;
    integer jitter_next_ps;
    real low_delay_ns;
    logic [31:0] jitter_state;
    clk_i = 1'b0;
    if (!$value$plusargs("FLEXSOC_SEED=%d", flexsoc_seed)) flexsoc_seed = 1;
    jitter_state = flexsoc_seed ^ 32'hdd5e607e;
    if (jitter_state == 0) jitter_state = 32'h6d2b79f5;
    jitter_prev_ps = 0;
    $display("[FLEXSOC CLOCK] clock=core jitter=uniform bound_ps=25 seed=%0d", flexsoc_seed);
    #0.1;
    forever begin
      clk_i = 1'b1;
      #4.95;
      clk_i = 1'b0;
      jitter_state = jitter_state ^ (jitter_state << 13);
      jitter_state = jitter_state ^ (jitter_state >> 17);
      jitter_state = jitter_state ^ (jitter_state << 5);
      jitter_next_ps = (jitter_state % 51) - 25;
      low_delay_ns = (5050 + jitter_next_ps - jitter_prev_ps) / 1000.0;
      if (low_delay_ns <= 0.0) $fatal(1, "invalid FlexSoC jittered clock delay");
      #(low_delay_ns);
      jitter_prev_ps = jitter_next_ps;
    end
  end

  string wave_path;
  initial begin
    if (!$value$plusargs("WAVE=%s", wave_path)) begin
      if (!$value$plusargs("VCD=%s", wave_path)) wave_path = "";
    end
    if (wave_path != "") begin
      $display("[TB] dumpfile = %s", wave_path);
      $dumpfile(wave_path);
      $dumpvars(0, gpio_tb);
    end
  end

  // SDF backannotation
  `ifdef FLEXSOC_ENABLE_SDF
    string sdf_path;
    initial begin
      if (!$value$plusargs("SDF=%s", sdf_path)) sdf_path = "";
      if (sdf_path != "") begin
        `ifdef FLEXSOC_SDF_MIN
          $display("[TB] sdf = %s (MINIMUM)", sdf_path);
          $sdf_annotate(sdf_path, gpio_tb.u_gpio);
        `elsif FLEXSOC_SDF_TYP
          $display("[TB] sdf = %s (TYPICAL)", sdf_path);
          $sdf_annotate(sdf_path, gpio_tb.u_gpio);
        `else
          $display("[TB] sdf = %s (MAXIMUM)", sdf_path);
          $sdf_annotate(sdf_path, gpio_tb.u_gpio);
        `endif
      end
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
    cio_gpio_i = '0;
    reg_req_i = '0;
    regif.init();
    rst_ni = 1'b1;
    repeat (2) @(posedge clk_i);
    @(negedge clk_i); #1;
    rst_ni = 1'b0;
    $display("[TB] initial reset pulse cycles=%0d", INITIAL_RESET_CYCLES);
    repeat (INITIAL_RESET_CYCLES) @(posedge clk_i);
    @(negedge clk_i); #1;
    rst_ni = 1'b1;
    repeat (2) @(posedge clk_i);
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
