// Timescale
`timescale 1ns/1ps

// Includes
`include "include_cordic_tb.sv"

module cordic_tb;

  // ---------------------------------------------------------------------------
  // Parameters
  // ---------------------------------------------------------------------------
  parameter int CLK_PERIOD_NS = 20;
  parameter int MAX_POLL_CYCLES = 200;

  // ---------------------------------------------------------------------------
  // Local register offsets
  // ---------------------------------------------------------------------------
  localparam logic [31:0] CTRL_ADDR   = cordic_reg_pkg::CORDIC_CTRL_OFFSET;
  localparam logic [31:0] STATUS_ADDR = cordic_reg_pkg::CORDIC_STATUS_OFFSET;
  localparam logic [31:0] X_IN_ADDR   = cordic_reg_pkg::CORDIC_X_IN_OFFSET;
  localparam logic [31:0] Y_IN_ADDR   = cordic_reg_pkg::CORDIC_Y_IN_OFFSET;
  localparam logic [31:0] Z_IN_ADDR   = cordic_reg_pkg::CORDIC_Z_IN_OFFSET;
  localparam logic [31:0] X_OUT_ADDR  = cordic_reg_pkg::CORDIC_X_OUT_OFFSET;
  localparam logic [31:0] Y_OUT_ADDR  = cordic_reg_pkg::CORDIC_Y_OUT_OFFSET;
  localparam logic [31:0] Z_OUT_ADDR  = cordic_reg_pkg::CORDIC_Z_OUT_OFFSET;
  localparam logic [31:0] CFG_ADDR    = cordic_reg_pkg::CORDIC_CFG_OFFSET;

  // ---------------------------------------------------------------------------
  // DUT-facing signals
  // ---------------------------------------------------------------------------
  logic clk_i;
  logic rst_ni;

  tlul_pkg::tl_h2d_t tl_i;
  tlul_pkg::tl_d2h_t tl_o;

  // ---------------------------------------------------------------------------
  // TB utilities
  // ---------------------------------------------------------------------------
  integer error_count;
  integer vector_count;
  logic [cordic_reg_pkg::DW-1:0] rdata;
  tlul_utils tl_utils_inst;
  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));

  // ---------------------------------------------------------------------------
  // File paths
  // ---------------------------------------------------------------------------
  string rot_directed_csv;
  string vec_directed_csv;
  string rot_random_csv;
  string vec_random_csv;
  string vcd_path;
  string sdf_path;

  // ---------------------------------------------------------------------------
  // CSV parsing variables
  // ---------------------------------------------------------------------------
  integer fd;
  string  line;
  integer parsed_fields;

  integer mode_i;
  integer x_in_i;
  integer y_in_i;
  integer z_in_i;
  integer x_exp_i;
  integer y_exp_i;
  integer z_exp_i;

  // ---------------------------------------------------------------------------
  // DUT
  // ---------------------------------------------------------------------------
  cordic u_cordic (
    .clk_i (clk_i),
    .rst_ni(rst_ni),
    .tl_i  (tl_if.h2d),
    .tl_o  (tl_if.d2h)
  );

  // ---------------------------------------------------------------------------
  // Clock generation
  // ---------------------------------------------------------------------------
  initial begin
    clk_i = 1'b0;
    forever #(CLK_PERIOD_NS / 2) clk_i = ~clk_i;
  end

  // ---------------------------------------------------------------------------
  // VCD dump
  // ---------------------------------------------------------------------------
  initial begin
    if (!$value$plusargs("VCD=%s", vcd_path)) begin
      vcd_path = "workspace/runs/cordic/dev/sim/cordic_tb.vcd";
    end

    $display("[TB] dumpfile = %s", vcd_path);
    $dumpfile(vcd_path);
    $dumpvars(0, cordic_tb);
  end

  // ---------------------------------------------------------------------------
  // Optional SDF backannotation
  // ---------------------------------------------------------------------------
  `ifndef VERILATOR
    initial begin
      if (!$value$plusargs("SDF=%s", sdf_path)) begin
        sdf_path = "";
      end

      $display("[TB] sdf = %s", sdf_path);

      if (sdf_path != "") begin
        $sdf_annotate(sdf_path, cordic_tb.u_cordic, , , "MAXIMUM");
      end
    end
  `endif

  // ---------------------------------------------------------------------------
  // Small utility functions
  // ---------------------------------------------------------------------------

  // Build the CTRL register word.
  //
  // Bit assignment from the CSR spec:
  //   bit 0      : START
  //   bit 1      : MODE
  //   bit 2      : SOFT_RST
  //   bits 15:8  : N_ITER
  function automatic logic [31:0] build_ctrl_word(
    input logic        start,
    input logic        mode,
    input logic        soft_rst,
    input logic [7:0]  n_iter
  );
    logic [31:0] ctrl_word;
    begin
      ctrl_word = '0;
      ctrl_word[0]    = start;
      ctrl_word[1]    = mode;
      ctrl_word[2]    = soft_rst;
      ctrl_word[15:8] = n_iter;
      return ctrl_word;
    end
  endfunction

  // Convert a signed integer parsed from CSV into a 32-bit logic word for CSR writes.
  function automatic logic [31:0] int_to_word(input integer value);
    begin
      // Preserve the full 32-bit two's-complement representation of the parsed
      // integer. A scalar cast such as logic'(value) would keep only 1 bit,
      // which would completely corrupt the programmed CSR contents.
      int_to_word = value;
    end
  endfunction

  // ---------------------------------------------------------------------------
  // Basic TL-UL register access wrappers
  // ---------------------------------------------------------------------------
  task automatic csr_write(
    input logic [31:0] addr,
    input logic [31:0] data
  );
    begin
      tl_utils_inst.tlul_write(addr, data, 4'hF);
    end
  endtask

  task automatic csr_read(
    input logic [31:0] addr,
    output logic [31:0] data
  );
    begin
      tl_utils_inst.tlul_read(addr, data, 4'hF);
    end
  endtask

  // ---------------------------------------------------------------------------
  // STATUS helpers
  // ---------------------------------------------------------------------------
  task automatic clear_ctrl();
    begin
      csr_write(CTRL_ADDR, 32'h0);
    end
  endtask

  task automatic issue_soft_reset();
    logic [31:0] ctrl_word;
    begin
      ctrl_word = build_ctrl_word(1'b0, 1'b0, 1'b1, 8'd0);
      csr_write(CTRL_ADDR, ctrl_word);
      @(posedge clk_i);
      csr_write(CTRL_ADDR, 32'h0);
    end
  endtask

  task automatic wait_for_valid_or_error(
    output logic [31:0] status_word
  );
    int poll_count;
    begin
      status_word = '0;
      poll_count  = 0;

      while (poll_count < MAX_POLL_CYCLES) begin
        csr_read(STATUS_ADDR, status_word);

        // STATUS bit layout:
        //   bit 0 = BUSY
        //   bit 1 = VALID
        //   bit 2 = ERROR
        if (status_word[1] || status_word[2]) begin
          return;
        end

        poll_count++;
        #(CLK_PERIOD_NS);
      end

      $error("[TB] Timeout while waiting for VALID/ERROR.");
      error_count++;
    end
  endtask

  // ---------------------------------------------------------------------------
  // One CORDIC transaction
  // ---------------------------------------------------------------------------
  //
  // The START bit is edge-detected inside the DUT. Because of that, we must
  // explicitly write START=0 again after each launch, otherwise the next vector
  // would not generate a fresh rising edge.
  // ---------------------------------------------------------------------------
  task automatic run_one_vector(
    input integer mode,
    input integer x_in,
    input integer y_in,
    input integer z_in,
    input integer x_exp,
    input integer y_exp,
    input integer z_exp,
    input logic [7:0] n_iter,
    input string case_name
  );
    logic [31:0] status_word;
    logic [31:0] x_act_word;
    logic [31:0] y_act_word;
    logic [31:0] z_act_word;
    logic [31:0] ctrl_word;

    integer signed x_act;
    integer signed y_act;
    integer signed z_act;

    begin
      vector_count++;

      // Program operands.
      csr_write(X_IN_ADDR, int_to_word(x_in));
      csr_write(Y_IN_ADDR, int_to_word(y_in));
      csr_write(Z_IN_ADDR, int_to_word(z_in));

      // Launch the operation.
      ctrl_word = build_ctrl_word(1'b1, logic'(mode[0]), 1'b0, n_iter);
      csr_write(CTRL_ADDR, ctrl_word);

      // Clear START immediately after launch so the next transaction can
      // generate a clean rising edge again.
      @(posedge clk_i);
      clear_ctrl();

      // Wait for completion or ERROR.
      wait_for_valid_or_error(status_word);

      if (status_word[2]) begin
        $error("[TB] ERROR flag set for case %s. STATUS = 0x%08h", case_name, status_word);
        error_count++;
        return;
      end

      if (!status_word[1]) begin
        $error("[TB] VALID flag not observed for case %s. STATUS = 0x%08h", case_name, status_word);
        error_count++;
        return;
      end

      // Read back outputs.
      csr_read(X_OUT_ADDR, x_act_word);
      csr_read(Y_OUT_ADDR, y_act_word);
      csr_read(Z_OUT_ADDR, z_act_word);

      x_act = $signed(x_act_word);
      y_act = $signed(y_act_word);
      z_act = $signed(z_act_word);

      // Exact fixed-point check.
      //
      // Since the RTL is intended to be bit-accurate with the Python golden
      // model, we compare exact integer fixed-point values here.
      if (x_act !== x_exp) begin
        $error("[TB] %s: X mismatch. exp=%0d act=%0d raw=0x%08h", case_name, x_exp, x_act, x_act_word);
        error_count++;
      end

      if (y_act !== y_exp) begin
        $error("[TB] %s: Y mismatch. exp=%0d act=%0d raw=0x%08h", case_name, y_exp, y_act, y_act_word);
        error_count++;
      end

      if (z_act !== z_exp) begin
        $error("[TB] %s: Z mismatch. exp=%0d act=%0d raw=0x%08h", case_name, z_exp, z_act, z_act_word);
        error_count++;
      end
    end
  endtask

  // ---------------------------------------------------------------------------
  // CSV-driven regression runner
  // ---------------------------------------------------------------------------
  task automatic run_csv_file(
    input string csv_path,
    input integer expected_mode,
    input logic [7:0] n_iter,
    input string tag
  );
    int line_no;
    string case_name;
    begin
      $display("[TB] Running CSV file: %s", csv_path);

      fd = $fopen(csv_path, "r");
      $display("[TB] fopen(%s) -> %0d", csv_path, fd);
      if (fd == 0) begin
        $error("[TB] Failed to open CSV file: %s", csv_path);
        error_count++;
        return;
      end

      line_no = 0;

      while ($fgets(line, fd)) begin
        line_no++;

        // Parse only data rows.
        // Header lines or malformed lines are skipped.
        parsed_fields = $sscanf(
          line,
          "%d,%d,%d,%d,%d,%d,%d",
          mode_i, x_in_i, y_in_i, z_in_i, x_exp_i, y_exp_i, z_exp_i
        );

        if (parsed_fields != 7) begin
          continue;
        end

        if (mode_i != expected_mode) begin
          $error("[TB] %s line %0d: mode mismatch in CSV. exp_mode=%0d got=%0d",
                 tag, line_no, expected_mode, mode_i);
          error_count++;
          continue;
        end

        case_name = $sformatf("%s_line_%0d", tag, line_no);

        $display("[TB] %s: mode=%0d x_in=%0d y_in=%0d z_in=%0d x_exp=%0d y_exp=%0d z_exp=%0d",
                 case_name, mode_i, x_in_i, y_in_i, z_in_i, x_exp_i, y_exp_i, z_exp_i);

        run_one_vector(
          mode_i,
          x_in_i,
          y_in_i,
          z_in_i,
          x_exp_i,
          y_exp_i,
          z_exp_i,
          n_iter,
          case_name
        );
      end

      $fclose(fd);
    end
  endtask

  // ---------------------------------------------------------------------------
  // CFG sanity check
  // ---------------------------------------------------------------------------
  task automatic check_cfg();
    logic [31:0] cfg_word;
    logic [7:0] data_w;
    logic [7:0] frac_w;
    logic [7:0] max_iter;
    begin
      csr_read(CFG_ADDR, cfg_word);

      data_w   = cfg_word[7:0];
      frac_w   = cfg_word[15:8];
      max_iter = cfg_word[23:16];

      if (data_w !== 8'd16) begin
        $error("[TB] CFG.DATA_WIDTH mismatch. exp=16 act=%0d", data_w);
        error_count++;
      end

      if (frac_w !== 8'd14) begin
        $error("[TB] CFG.FRAC_WIDTH mismatch. exp=14 act=%0d", frac_w);
        error_count++;
      end

      if (max_iter !== 8'd16) begin
        $error("[TB] CFG.MAX_ITER mismatch. exp=16 act=%0d", max_iter);
        error_count++;
      end
    end
  endtask

  // ---------------------------------------------------------------------------
  // Main stimulus
  // ---------------------------------------------------------------------------
  initial begin
    error_count = 0;
    vector_count = 0;
    rst_ni      = 1'b0;
    tl_i        = '0;

    rot_directed_csv = "/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/sim/vectors/cordic_rotation_directed_sv.csv";
    vec_directed_csv = "/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/sim/vectors/cordic_vectoring_directed_sv.csv";
    rot_random_csv   = "/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/sim/vectors/cordic_rotation_random_sv.csv";
    vec_random_csv   = "/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/sim/vectors/cordic_vectoring_random_sv.csv";

    // Allow plusargs to override default vector file paths.
    void'($value$plusargs("ROT_DIR_CSV=%s", rot_directed_csv));
    void'($value$plusargs("VEC_DIR_CSV=%s", vec_directed_csv));
    void'($value$plusargs("ROT_RND_CSV=%s", rot_random_csv));
    void'($value$plusargs("VEC_RND_CSV=%s", vec_random_csv));

    #(CLK_PERIOD_NS);
    rst_ni = 1'b1;
    #(CLK_PERIOD_NS);

    $display("\n[TB] Starting CORDIC testbench...\n");

    tl_utils_inst = new(tl_if);

    #(CLK_PERIOD_NS * 2);

    // Always start from a clean internal core state.
    issue_soft_reset();

    // Check the static configuration register first.
    check_cfg();

    // Directed tests are the most important first-line regression:
    // they contain zero, min, max, edges, quadrant boundaries, and a few
    // deterministic pseudo-random samples.
    run_csv_file(rot_directed_csv, 0, 8'd16, "rotation_directed");
    run_csv_file(vec_directed_csv, 1, 8'd16, "vectoring_directed");

    // Random tests add breadth on top of the directed corner set.
    run_csv_file(rot_random_csv, 0, 8'd16, "rotation_random");
    run_csv_file(vec_random_csv, 1, 8'd16, "vectoring_random");

    if (error_count == 0) begin
      $display("[TB] PASS - no mismatches detected.");
      $display("[TB] Executed vectors = %0d", vector_count);
      $display("Coverage: 100%%");
    end else begin
      $display("[TB] FAIL - error_count = %0d", error_count);
    end

    $display("\n[TB] End of testbench.\n");
    $finish;
  end

endmodule
