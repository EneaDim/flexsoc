`timescale 1ns/1ps
`include "include_gpio_tb.sv"
`ifdef SYN
  `include "gpio_synth.v"
`endif

module gpio_tb;
  logic clk_i;
  logic rst_ni;
  gpio_reg_pkg::axi_lite_req_t axi_lite_i;
  gpio_reg_pkg::axi_lite_rsp_t axi_lite_o;



  logic [3:0] cio_gpio_i;
  logic [3:0] cio_gpio_o;
  logic [3:0] cio_gpio_en_o;
  logic [3:0] intr_gpio_o;

  string cfg_path;
  string data_in_path;
  string data_out_path;
  string wave_path;
  string sdf_path;
  integer errors;
  localparam integer INITIAL_RESET_CYCLES = 5;



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

  gpio u_dut (
    .clk_i                    (clk_i),
    .rst_ni                   (rst_ni),
    .cio_gpio_i               (cio_gpio_i),
    .axi_lite_i               (axi_lite_i),
    .cio_gpio_o               (cio_gpio_o),
    .cio_gpio_en_o            (cio_gpio_en_o),
    .intr_gpio_o              (intr_gpio_o),
    .axi_lite_o               (axi_lite_o)
  );

  // Verification helpers share one structure for all clock topologies.
  `include "drivers/gpio_reg_driver.svh"
  `include "drivers/gpio_vec_monitor.svh"
  `include "drivers/gpio_vec_driver.svh"

  initial begin
    errors = 0;
    clk_i = 1'b0;
    rst_ni = 1'b1;
    apply_defaults();

    if (!$value$plusargs("CFG=%s", cfg_path)) cfg_path = "dv/functional/tests/smoke/config.regs";
    if (!$value$plusargs("DATA_IN=%s", data_in_path)) data_in_path = "dv/functional/tests/smoke/data_in.vec";
    if (!$value$plusargs("DATA_OUT=%s", data_out_path)) data_out_path = "dv/functional/tests/smoke/data_out.vec";
    if (!$value$plusargs("WAVE=%s", wave_path)) begin
      if (!$value$plusargs("VCD=%s", wave_path)) wave_path = "";
    end
    if (wave_path != "") begin
      $display("[TB] dumpfile = %s", wave_path);
      $dumpfile(wave_path);
      $dumpvars(0, gpio_tb);
    end

    `ifdef FLEXSOC_ENABLE_SDF
      if (!$value$plusargs("SDF=%s", sdf_path)) sdf_path = "";
      if (sdf_path != "") begin
        `ifdef FLEXSOC_SDF_MIN
          $display("[TB] sdf = %s (MINIMUM)", sdf_path);
          $sdf_annotate(sdf_path, u_dut);
        `elsif FLEXSOC_SDF_TYP
          $display("[TB] sdf = %s (TYPICAL)", sdf_path);
          $sdf_annotate(sdf_path, u_dut);
        `else
          $display("[TB] sdf = %s (MAXIMUM)", sdf_path);
          $sdf_annotate(sdf_path, u_dut);
        `endif
      end
    `endif

    repeat (2) @(posedge clk_i);
    @(negedge clk_i); #1;
    rst_ni = 1'b0;
    $display("[TB] initial reset pulse cycles=%0d", INITIAL_RESET_CYCLES);
    repeat (INITIAL_RESET_CYCLES) @(posedge clk_i);
    @(negedge clk_i); #1;
    rst_ni = 1'b1;
    repeat (8) @(posedge clk_i);

    load_config(cfg_path);
    run_vectors(data_in_path, data_out_path);
    repeat (10) core_sample_cycle();
    if (errors == 0) begin
      $display("[TB] PASS");
      $finish;
    end else begin
      $display("[TB] FAIL errors=%0d", errors);
      $fatal(1);
    end
  end

endmodule
