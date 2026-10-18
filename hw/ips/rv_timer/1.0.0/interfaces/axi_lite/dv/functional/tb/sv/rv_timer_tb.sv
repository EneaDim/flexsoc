`timescale 1ns/1ps
`include "include_rv_timer_tb.sv"
`ifdef SYN
  `include "rv_timer_synth.v"
`endif

module rv_timer_tb;
  logic clk_i;
  logic rst_ni;
  rv_timer_reg_pkg::axi_lite_req_t axi_lite_i;
  rv_timer_reg_pkg::axi_lite_rsp_t axi_lite_o;



  logic [1:0] gpio_intr_i;
  logic intr_timer_expired_hart0_timer0_o;

  string test_name;
  string cfg_path;
  string data_in_path;
  string data_out_path;
  string wave_path;
  string sdf_path;
  integer errors;
  localparam integer INITIAL_RESET_CYCLES = 5;



  logic flexsoc_event_valid = 1'b0;
  logic [31:0] flexsoc_event_value = 32'b0;
  integer flexsoc_event_sequence = 0;
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

  rv_timer u_dut (
    .clk_i                    (clk_i),
    .rst_ni                   (rst_ni),
    .gpio_intr_i              (gpio_intr_i),
    .axi_lite_i               (axi_lite_i),
    .intr_timer_expired_hart0_timer0_o(intr_timer_expired_hart0_timer0_o),
    .axi_lite_o               (axi_lite_o)
  );


  task automatic tb_wait_event(
    input string label,
    input logic [31:0] expected,
    input integer timeout_cycles,
    inout integer cursor,
    output bit seen
  );
    integer i;
    seen = 1'b0;
    for (i = 0; i < timeout_cycles && !seen; i++) begin
      @(posedge clk_i); #1;
      if (flexsoc_event_sequence != cursor) begin
        cursor = flexsoc_event_sequence;
        if (flexsoc_event_value === expected) seen = 1'b1;
      end
    end
    if (seen)
      $display("[TB][EVENT] observed name=%s value=0x%08x", label, expected);
  endtask

  task automatic tb_wait_signal(
    input string name,
    input logic [31:0] expected,
    input integer timeout_cycles,
    output bit seen
  );
    integer i;
    seen = 1'b0;
    if (1'b0) begin
      seen = 1'b0;
    end
    else if (name == "gpio_intr_i") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(gpio_intr_i) === expected) seen = 1'b1;
      end
    end
    else if (name == "axi_lite_i") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(axi_lite_i) === expected) seen = 1'b1;
      end
    end
    else if (name == "intr_timer_expired_hart0_timer0_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(intr_timer_expired_hart0_timer0_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "axi_lite_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(axi_lite_o) === expected) seen = 1'b1;
      end
    end
    else begin
      $display("[TB][ERROR] unknown wait signal: %s", name);
      errors++;
    end
  endtask
  // Verification helpers share one structure for all clock topologies.
  `include "drivers/rv_timer_reg_driver.svh"
  `include "drivers/rv_timer_vec_monitor.svh"
  `include "drivers/rv_timer_vec_driver.svh"

  initial begin
    errors = 0;
    clk_i = 1'b0;
    rst_ni = 1'b1;
    apply_defaults();

    if (!$value$plusargs("TEST_NAME=%s", test_name)) test_name = "smoke";
    $display("[TB] test = %s", test_name);
    if (!$value$plusargs("CFG=%s", cfg_path)) cfg_path = "dv/functional/tests/smoke/config.regs";
    if (!$value$plusargs("DATA_IN=%s", data_in_path)) data_in_path = "dv/functional/tests/smoke/data_in.vec";
    if (!$value$plusargs("DATA_OUT=%s", data_out_path)) data_out_path = "dv/functional/tests/smoke/data_out.vec";
    if (!$value$plusargs("WAVE=%s", wave_path)) begin
      if (!$value$plusargs("VCD=%s", wave_path)) wave_path = "";
    end
    if (wave_path != "") begin
      $display("[TB] dumpfile = %s", wave_path);
      $dumpfile(wave_path);
      $dumpvars(0, rv_timer_tb);
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
      $display("[TB] PASS test=%s", test_name);
      $finish;
    end else begin
      $display("[TB] FAIL test=%s errors=%0d", test_name, errors);
      $fatal(1);
    end
  end

endmodule
