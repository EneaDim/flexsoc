`timescale 1ns/1ps
`include "include_ethernet_tb.sv"
`ifdef SYN
  `include "ethernet_synth.v"
`endif

module ethernet_tb;
  logic clk_i;
  logic rst_ni;
  logic phy_gtx_clk_i;
  logic phy_rst_i;
  logic phy_gmii_rx_clk_i;
  logic phy_mii_tx_clk_i;
  ethernet_reg_pkg::reg_req_t reg_req_i;
  ethernet_reg_pkg::reg_rsp_t reg_rsp_o;



  logic [7:0] phy_gmii_rxd_i;
  logic phy_gmii_rx_dv_i;
  logic phy_gmii_rx_er_i;
  logic phy_mii_select_i;
  logic [1:0] phy_speed_i;
  logic phy_speed_valid_i;
  logic [7:0] tx_data_i;
  logic tx_valid_i;
  logic tx_last_i;
  logic tx_error_i;
  logic phy_gmii_tx_clk_o;
  logic [7:0] phy_gmii_txd_o;
  logic phy_gmii_tx_en_o;
  logic phy_gmii_tx_er_o;
  logic tx_clk_o;
  logic tx_rst_o;
  logic tx_ready_o;
  logic rx_clk_o;
  logic rx_rst_o;
  logic [7:0] rx_data_o;
  logic rx_valid_o;
  logic rx_last_o;
  logic rx_error_o;
  logic intr_tx_underflow_o;
  logic intr_rx_bad_frame_o;
  logic intr_rx_bad_fcs_o;

  string test_name;
  string cfg_path;
  string data_in_path;
  string data_out_path;
  string wave_path;
  string sdf_path;
  integer errors;
  localparam integer INITIAL_RESET_CYCLES = 5;


  integer exp_count;
  integer got_count;
  logic [31:0] exp_phy_gmii_tx_clk_o [0:1023];
  logic exp_has_phy_gmii_tx_clk_o [0:1023];
  logic [31:0] exp_phy_gmii_txd_o [0:1023];
  logic exp_has_phy_gmii_txd_o [0:1023];
  logic [31:0] exp_phy_gmii_tx_en_o [0:1023];
  logic exp_has_phy_gmii_tx_en_o [0:1023];
  logic [31:0] exp_phy_gmii_tx_er_o [0:1023];
  logic exp_has_phy_gmii_tx_er_o [0:1023];
  logic [31:0] exp_tx_clk_o [0:1023];
  logic exp_has_tx_clk_o [0:1023];
  logic [31:0] exp_tx_rst_o [0:1023];
  logic exp_has_tx_rst_o [0:1023];
  logic [31:0] exp_tx_ready_o [0:1023];
  logic exp_has_tx_ready_o [0:1023];
  logic [31:0] exp_rx_clk_o [0:1023];
  logic exp_has_rx_clk_o [0:1023];
  logic [31:0] exp_rx_rst_o [0:1023];
  logic exp_has_rx_rst_o [0:1023];
  logic [31:0] exp_rx_data_o [0:1023];
  logic exp_has_rx_data_o [0:1023];
  logic [31:0] exp_rx_valid_o [0:1023];
  logic exp_has_rx_valid_o [0:1023];
  logic [31:0] exp_rx_last_o [0:1023];
  logic exp_has_rx_last_o [0:1023];
  logic [31:0] exp_rx_error_o [0:1023];
  logic exp_has_rx_error_o [0:1023];
  logic [31:0] exp_intr_tx_underflow_o [0:1023];
  logic exp_has_intr_tx_underflow_o [0:1023];
  logic [31:0] exp_intr_rx_bad_frame_o [0:1023];
  logic exp_has_intr_rx_bad_frame_o [0:1023];
  logic [31:0] exp_intr_rx_bad_fcs_o [0:1023];
  logic exp_has_intr_rx_bad_fcs_o [0:1023];
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
  initial begin
    phy_gtx_clk_i = 1'b0;
    #0;
    forever begin
      phy_gtx_clk_i = 1'b1;
      #4;
      phy_gtx_clk_i = 1'b0;
      #4;
    end
  end
  initial begin
    phy_gmii_rx_clk_i = 1'b0;
    #0;
    forever begin
      phy_gmii_rx_clk_i = 1'b1;
      #4;
      phy_gmii_rx_clk_i = 1'b0;
      #4;
    end
  end
  initial begin
    phy_mii_tx_clk_i = 1'b0;
    #0;
    forever begin
      phy_mii_tx_clk_i = 1'b1;
      #20;
      phy_mii_tx_clk_i = 1'b0;
      #20;
    end
  end

  ethernet u_dut (
    .clk_i                    (clk_i),
    .rst_ni                   (rst_ni),
    .phy_rst_i                (phy_rst_i),
    .phy_gtx_clk_i            (phy_gtx_clk_i),
    .phy_gmii_rx_clk_i        (phy_gmii_rx_clk_i),
    .phy_gmii_rxd_i           (phy_gmii_rxd_i),
    .phy_gmii_rx_dv_i         (phy_gmii_rx_dv_i),
    .phy_gmii_rx_er_i         (phy_gmii_rx_er_i),
    .phy_mii_tx_clk_i         (phy_mii_tx_clk_i),
    .phy_mii_select_i         (phy_mii_select_i),
    .phy_speed_i              (phy_speed_i),
    .phy_speed_valid_i        (phy_speed_valid_i),
    .tx_data_i                (tx_data_i),
    .tx_valid_i               (tx_valid_i),
    .tx_last_i                (tx_last_i),
    .tx_error_i               (tx_error_i),
    .reg_req_i                (reg_req_i),
    .phy_gmii_tx_clk_o        (phy_gmii_tx_clk_o),
    .phy_gmii_txd_o           (phy_gmii_txd_o),
    .phy_gmii_tx_en_o         (phy_gmii_tx_en_o),
    .phy_gmii_tx_er_o         (phy_gmii_tx_er_o),
    .tx_clk_o                 (tx_clk_o),
    .tx_rst_o                 (tx_rst_o),
    .tx_ready_o               (tx_ready_o),
    .rx_clk_o                 (rx_clk_o),
    .rx_rst_o                 (rx_rst_o),
    .rx_data_o                (rx_data_o),
    .rx_valid_o               (rx_valid_o),
    .rx_last_o                (rx_last_o),
    .rx_error_o               (rx_error_o),
    .intr_tx_underflow_o      (intr_tx_underflow_o),
    .intr_rx_bad_frame_o      (intr_rx_bad_frame_o),
    .intr_rx_bad_fcs_o        (intr_rx_bad_fcs_o),
    .reg_rsp_o                (reg_rsp_o)
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
    else if (name == "phy_gmii_rxd_i") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(phy_gmii_rxd_i) === expected) seen = 1'b1;
      end
    end
    else if (name == "phy_gmii_rx_dv_i") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(phy_gmii_rx_dv_i) === expected) seen = 1'b1;
      end
    end
    else if (name == "phy_gmii_rx_er_i") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(phy_gmii_rx_er_i) === expected) seen = 1'b1;
      end
    end
    else if (name == "phy_mii_select_i") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(phy_mii_select_i) === expected) seen = 1'b1;
      end
    end
    else if (name == "phy_speed_i") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(phy_speed_i) === expected) seen = 1'b1;
      end
    end
    else if (name == "phy_speed_valid_i") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(phy_speed_valid_i) === expected) seen = 1'b1;
      end
    end
    else if (name == "tx_data_i") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(tx_data_i) === expected) seen = 1'b1;
      end
    end
    else if (name == "tx_valid_i") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(tx_valid_i) === expected) seen = 1'b1;
      end
    end
    else if (name == "tx_last_i") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(tx_last_i) === expected) seen = 1'b1;
      end
    end
    else if (name == "tx_error_i") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(tx_error_i) === expected) seen = 1'b1;
      end
    end
    else if (name == "reg_req_i") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(reg_req_i) === expected) seen = 1'b1;
      end
    end
    else if (name == "phy_gmii_tx_clk_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(phy_gmii_tx_clk_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "phy_gmii_txd_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(phy_gmii_txd_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "phy_gmii_tx_en_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(phy_gmii_tx_en_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "phy_gmii_tx_er_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(phy_gmii_tx_er_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "tx_clk_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(tx_clk_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "tx_rst_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(tx_rst_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "tx_ready_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(tx_ready_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "rx_clk_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(rx_clk_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "rx_rst_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(rx_rst_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "rx_data_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(rx_data_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "rx_valid_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(rx_valid_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "rx_last_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(rx_last_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "rx_error_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(rx_error_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "intr_tx_underflow_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(intr_tx_underflow_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "intr_rx_bad_frame_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(intr_rx_bad_frame_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "intr_rx_bad_fcs_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(intr_rx_bad_fcs_o) === expected) seen = 1'b1;
      end
    end
    else if (name == "reg_rsp_o") begin
      for (i = 0; i < timeout_cycles && !seen; i++) begin
        @(posedge clk_i); #1;
        if ($unsigned(reg_rsp_o) === expected) seen = 1'b1;
      end
    end
    else begin
      $display("[TB][ERROR] unknown wait signal: %s", name);
      errors++;
    end
  endtask
  // Verification helpers share one structure for all clock topologies.
  `include "drivers/ethernet_reg_driver.svh"
  `include "drivers/ethernet_vec_monitor.svh"
  `include "drivers/ethernet_vec_driver.svh"

  initial begin
    errors = 0;
    clk_i = 1'b0;
    phy_gtx_clk_i = 1'b0;
    phy_gmii_rx_clk_i = 1'b0;
    phy_mii_tx_clk_i = 1'b0;
    rst_ni = 1'b1;
    phy_rst_i = 1'b0;
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
      $dumpvars(0, ethernet_tb);
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
    phy_rst_i = 1'b1;
    $display("[TB] initial reset pulse cycles=%0d", INITIAL_RESET_CYCLES);
    repeat (INITIAL_RESET_CYCLES) @(posedge clk_i);
    @(negedge clk_i); #1;
    rst_ni = 1'b1;
    phy_rst_i = 1'b0;
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
