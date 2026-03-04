// Timescale
`timescale 1ns/1ps

import fsm_example_pkg::*;

module fsm_example_tb;

  parameter real CLK_PERIOD = 31.25;

  logic clk_i;
  logic rst_ni;
  logic clear_error_i;
  logic cmd_pending_i;
  logic cmd_valid_i;
  logic error_i;
  logic exec_done_i;
  logic fatal_error_i;
  logic flush_done_i;
  logic flush_req_i;
  logic prefetch_done_i;
  logic reset_done_i;
  logic restart_i;
  logic sleep_req_i;
  logic wake_i;
  logic writeback_done_i;
  logic busy_o;
  logic valid_o;
  logic error_o;
  logic low_power_o;
  logic dbg_o;
  state_fsm state_o;

  fsm_example u_fsm_example (
    .clk_i,
    .rst_ni,
    .clear_error_i,
    .cmd_pending_i,
    .cmd_valid_i,
    .error_i,
    .exec_done_i,
    .fatal_error_i,
    .flush_done_i,
    .flush_req_i,
    .prefetch_done_i,
    .reset_done_i,
    .restart_i,
    .sleep_req_i,
    .wake_i,
    .writeback_done_i,
    .busy_o,
    .valid_o,
    .error_o,
    .low_power_o,
    .dbg_o,
    .state_o
  );

  // Dump VCD
  initial begin
    `ifndef SYN
      $dumpfile("sim/fsm_example_tb.vcd");
    `else
      $dumpfile("sim/fsm_example_syn_tb.vcd");
    `endif
    $dumpvars(0, fsm_example_tb);
  end

  // Clock generation
  initial begin
    forever #(CLK_PERIOD/2) clk_i = ~clk_i;
  end

  initial begin
    clk_i = 1'b0;
    rst_ni = 1'b0;
    clear_error_i = 1'b0;
    cmd_pending_i = 1'b0;
    cmd_valid_i = 1'b0;
    error_i = 1'b0;
    exec_done_i = 1'b0;
    fatal_error_i = 1'b0;
    flush_done_i = 1'b0;
    flush_req_i = 1'b0;
    prefetch_done_i = 1'b0;
    reset_done_i = 1'b0;
    restart_i = 1'b0;
    sleep_req_i = 1'b0;
    wake_i = 1'b0;
    writeback_done_i = 1'b0;

    // Apply reset and basic stimulus here as needed.
    #(CLK_PERIOD*8);
    rst_ni = 1'b1;
    #(CLK_PERIOD*1.5);

    // RESET -> IDLE : "reset_done_i"
    reset_done_i = 1'b1;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == IDLE)
      else $fatal(1, "RESET -> IDLE failed: state_o=%0d", u_fsm_example.state_o);

    // IDLE -> LOW_POWER : "sleep_req_i"
    sleep_req_i = 1'b1;
    cmd_pending_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == LOW_POWER)
      else $fatal(1, "IDLE -> LOW_POWER failed: state_o=%0d", u_fsm_example.state_o);

    // LOW_POWER -> IDLE : "wake_i"
    wake_i = 1'b1;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == IDLE)
      else $fatal(1, "LOW_POWER -> IDLE failed: state_o=%0d", u_fsm_example.state_o);

    // IDLE -> WAIT_CMD : "cmd_pending_i"
    cmd_pending_i = 1'b1;
    sleep_req_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == WAIT_CMD)
      else $fatal(1, "IDLE -> WAIT_CMD failed: state_o=%0d", u_fsm_example.state_o);

    // WAIT_CMD -> FLUSH : "flush_req_i"
    flush_req_i = 1'b1;
    cmd_valid_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == FLUSH)
      else $fatal(1, "WAIT_CMD -> FLUSH failed: state_o=%0d", u_fsm_example.state_o);

    // FLUSH -> IDLE : "flush_done_i & ~cmd_pending_i"
    cmd_pending_i = 1'b0;
    flush_done_i = 1'b1;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == IDLE)
      else $fatal(1, "FLUSH -> IDLE failed: state_o=%0d", u_fsm_example.state_o);

    // IDLE -> WAIT_CMD : "cmd_pending_i"
    cmd_pending_i = 1'b1;
    sleep_req_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == WAIT_CMD)
      else $fatal(1, "IDLE -> WAIT_CMD failed: state_o=%0d", u_fsm_example.state_o);

    // WAIT_CMD -> FLUSH : "flush_req_i"
    flush_req_i = 1'b1;
    cmd_valid_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == FLUSH)
      else $fatal(1, "WAIT_CMD -> FLUSH failed: state_o=%0d", u_fsm_example.state_o);

    // FLUSH -> WAIT_CMD : "flush_done_i & cmd_pending_i"
    cmd_pending_i = 1'b1;
    flush_done_i = 1'b1;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == WAIT_CMD)
      else $fatal(1, "FLUSH -> WAIT_CMD failed: state_o=%0d", u_fsm_example.state_o);

    // WAIT_CMD -> PREFETCH : "cmd_valid_i & ~flush_req_i"
    cmd_valid_i = 1'b1;
    flush_req_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == PREFETCH)
      else $fatal(1, "WAIT_CMD -> PREFETCH failed: state_o=%0d", u_fsm_example.state_o);

    // PREFETCH -> EXECUTE : "prefetch_done_i"
    prefetch_done_i = 1'b1;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == EXECUTE)
      else $fatal(1, "PREFETCH -> EXECUTE failed: state_o=%0d", u_fsm_example.state_o);

    // EXECUTE -> ERROR : "error_i"
    error_i = 1'b1;
    exec_done_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == ERROR)
      else $fatal(1, "EXECUTE -> ERROR failed: state_o=%0d", u_fsm_example.state_o);

    // ERROR -> IDLE : "clear_error_i & ~fatal_error_i"
    clear_error_i = 1'b1;
    fatal_error_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == IDLE)
      else $fatal(1, "ERROR -> IDLE failed: state_o=%0d", u_fsm_example.state_o);

    // IDLE -> WAIT_CMD : "cmd_pending_i"
    cmd_pending_i = 1'b1;
    sleep_req_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == WAIT_CMD)
      else $fatal(1, "IDLE -> WAIT_CMD failed: state_o=%0d", u_fsm_example.state_o);

    // WAIT_CMD -> PREFETCH : "cmd_valid_i & ~flush_req_i"
    cmd_valid_i = 1'b1;
    flush_req_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == PREFETCH)
      else $fatal(1, "WAIT_CMD -> PREFETCH failed: state_o=%0d", u_fsm_example.state_o);

    // PREFETCH -> EXECUTE : "prefetch_done_i"
    prefetch_done_i = 1'b1;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == EXECUTE)
      else $fatal(1, "PREFETCH -> EXECUTE failed: state_o=%0d", u_fsm_example.state_o);

    // EXECUTE -> WRITEBACK : "exec_done_i & ~error_i"
    error_i = 1'b0;
    exec_done_i = 1'b1;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == WRITEBACK)
      else $fatal(1, "EXECUTE -> WRITEBACK failed: state_o=%0d", u_fsm_example.state_o);

    // WRITEBACK -> IDLE : "writeback_done_i & ~cmd_pending_i"
    cmd_pending_i = 1'b0;
    writeback_done_i = 1'b1;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == IDLE)
      else $fatal(1, "WRITEBACK -> IDLE failed: state_o=%0d", u_fsm_example.state_o);

    // IDLE -> WAIT_CMD : "cmd_pending_i"
    cmd_pending_i = 1'b1;
    sleep_req_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == WAIT_CMD)
      else $fatal(1, "IDLE -> WAIT_CMD failed: state_o=%0d", u_fsm_example.state_o);

    // WAIT_CMD -> PREFETCH : "cmd_valid_i & ~flush_req_i"
    cmd_valid_i = 1'b1;
    flush_req_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == PREFETCH)
      else $fatal(1, "WAIT_CMD -> PREFETCH failed: state_o=%0d", u_fsm_example.state_o);

    // PREFETCH -> EXECUTE : "prefetch_done_i"
    prefetch_done_i = 1'b1;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == EXECUTE)
      else $fatal(1, "PREFETCH -> EXECUTE failed: state_o=%0d", u_fsm_example.state_o);

    // EXECUTE -> WRITEBACK : "exec_done_i & ~error_i"
    error_i = 1'b0;
    exec_done_i = 1'b1;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == WRITEBACK)
      else $fatal(1, "EXECUTE -> WRITEBACK failed: state_o=%0d", u_fsm_example.state_o);

    // WRITEBACK -> WAIT_CMD : "writeback_done_i & cmd_pending_i"
    cmd_pending_i = 1'b1;
    writeback_done_i = 1'b1;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == WAIT_CMD)
      else $fatal(1, "WRITEBACK -> WAIT_CMD failed: state_o=%0d", u_fsm_example.state_o);

    // WAIT_CMD -> PREFETCH : "cmd_valid_i & ~flush_req_i"
    cmd_valid_i = 1'b1;
    flush_req_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == PREFETCH)
      else $fatal(1, "WAIT_CMD -> PREFETCH failed: state_o=%0d", u_fsm_example.state_o);

    // PREFETCH -> EXECUTE : "prefetch_done_i"
    prefetch_done_i = 1'b1;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == EXECUTE)
      else $fatal(1, "PREFETCH -> EXECUTE failed: state_o=%0d", u_fsm_example.state_o);

    // EXECUTE -> ERROR : "error_i"
    error_i = 1'b1;
    exec_done_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == ERROR)
      else $fatal(1, "EXECUTE -> ERROR failed: state_o=%0d", u_fsm_example.state_o);

    // ERROR -> SHUTDOWN : "fatal_error_i"
    fatal_error_i = 1'b1;
    clear_error_i = 1'b0;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == SHUTDOWN)
      else $fatal(1, "ERROR -> SHUTDOWN failed: state_o=%0d", u_fsm_example.state_o);

    // SHUTDOWN -> RESET : "restart_i"
    restart_i = 1'b1;
    #(CLK_PERIOD);
    assert (u_fsm_example.state_o == RESET)
      else $fatal(1, "SHUTDOWN -> RESET failed: state_o=%0d", u_fsm_example.state_o);

    #(CLK_PERIOD) $finish;

  end

endmodule
