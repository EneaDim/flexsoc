`timescale 1ns/1ps
`include "include_uart_master_tb.sv"
`ifdef SYN
  `include "uart_master_synth.v"
`endif

module uart_master_tb;
  logic clk_i;
  logic rst_ni;
  logic [108:0] tl_i;
  logic [65:0]  tl_o;



  logic gnt_i;
  logic valid_i;
  logic [31:0] rdata_i;
  logic err_i;
  logic cio_rx_i;
  logic req_o;
  logic [31:0] addr_o;
  logic we_o;
  logic [31:0] wdata_o;
  logic [3:0] be_o;
  logic cio_tx_o;
  logic cio_tx_en_o;

  string cfg_path;
  string data_in_path;
  string data_out_path;
  string wave_path;
  string sdf_path;
  integer errors;
  localparam integer INITIAL_RESET_CYCLES = 5;
  localparam logic [2:0] FLEXSOC_TL_PUT_FULL    = 3'h0;
  localparam logic [2:0] FLEXSOC_TL_PUT_PARTIAL = 3'h1;
  localparam logic [2:0] FLEXSOC_TL_GET         = 3'h4;

  function automatic logic [6:0] flexsoc_tlul_data_intg(input logic [31:0] data_i);
    logic [38:0] data_o;
    begin
      data_o = {7'b0, data_i};
      data_o[32] = ^(data_o & 39'h002606BD25);
      data_o[33] = ^(data_o & 39'h00DEBA8050);
      data_o[34] = ^(data_o & 39'h00413D89AA);
      data_o[35] = ^(data_o & 39'h0031234ED1);
      data_o[36] = ^(data_o & 39'h00C2C1323B);
      data_o[37] = ^(data_o & 39'h002DCC624C);
      data_o[38] = ^(data_o & 39'h0098505586);
      data_o = data_o ^ 39'h2A00000000;
      flexsoc_tlul_data_intg = data_o[38:32];
    end
  endfunction

  function automatic logic [6:0] flexsoc_tlul_cmd_intg(
    input logic [2:0] opcode,
    input logic [31:0] address,
    input logic [3:0] mask
  );
    logic [56:0] payload;
    logic [63:0] data_o;
    begin
      payload = {14'b0, 4'h9, address, opcode, mask};
      data_o = {7'b0, payload};
      data_o[57] = ^(data_o & 64'h0103FFF800007FFF);
      data_o[58] = ^(data_o & 64'h017C1FF801FF801F);
      data_o[59] = ^(data_o & 64'h01BDE1F87E0781E1);
      data_o[60] = ^(data_o & 64'h01DEEE3B8E388E22);
      data_o[61] = ^(data_o & 64'h01EF76CDB2C93244);
      data_o[62] = ^(data_o & 64'h01F7BB56D5525488);
      data_o[63] = ^(data_o & 64'h01FBDDA769A46910);
      data_o = data_o ^ 64'h5400000000000000;
      flexsoc_tlul_cmd_intg = data_o[63:57];
    end
  endfunction

  function automatic logic [108:0] flexsoc_tlul_h2d(
    input logic valid,
    input logic [2:0] opcode,
    input logic [2:0] param,
    input logic [1:0] size,
    input logic [7:0] source,
    input logic [31:0] address,
    input logic [3:0] mask,
    input logic [31:0] data,
    input logic ready
  );
    logic [108:0] value;
    begin
      value = '0;
      value[108]     = valid;
      value[107:105] = opcode;
      value[104:102] = param;
      value[101:100] = size;
      value[99:92]   = source;
      value[91:60]   = address;
      value[59:56]   = mask;
      value[55:24]   = data;
      value[23:19]   = 5'b0;
      value[18:15]   = 4'h9;
      value[14:8]    = flexsoc_tlul_cmd_intg(opcode, address, mask);
      value[7:1]     = flexsoc_tlul_data_intg(data);
      value[0]       = ready;
      flexsoc_tlul_h2d = value;
    end
  endfunction


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

  uart_master u_dut (
    .clk_i                    (clk_i),
    .rst_ni                   (rst_ni),
    .gnt_i                    (gnt_i),
    .valid_i                  (valid_i),
    .rdata_i                  (rdata_i),
    .err_i                    (err_i),
    .cio_rx_i                 (cio_rx_i),
    .tl_i                     (tl_i),
    .req_o                    (req_o),
    .addr_o                   (addr_o),
    .we_o                     (we_o),
    .wdata_o                  (wdata_o),
    .be_o                     (be_o),
    .cio_tx_o                 (cio_tx_o),
    .cio_tx_en_o              (cio_tx_en_o),
    .tl_o                     (tl_o)
  );

  // Verification helpers share one structure for all clock topologies.
  `include "drivers/uart_master_reg_driver.svh"
  `include "drivers/uart_master_vec_monitor.svh"
  `include "drivers/uart_master_vec_driver.svh"

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
      $dumpvars(0, uart_master_tb);
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
