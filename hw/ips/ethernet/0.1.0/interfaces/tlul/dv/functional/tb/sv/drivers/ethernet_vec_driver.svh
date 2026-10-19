`ifdef VERILATOR
logic [31:0] pending_phy_speed_i = '0;
logic [31:0] pending_tx_data_i = '0;
logic [31:0] pending_tx_last_i = '0;
logic [31:0] pending_tx_error_i = '0;
task automatic send_phy_speed();
  integer timeout;
  begin
  core_drive_cycle();
  phy_speed_i = pending_phy_speed_i;
  phy_speed_valid_i = 1'b1;
  core_sample_cycle();
  core_drive_cycle();
  phy_speed_valid_i = 1'b0;
  end
endtask

task automatic send_tx();
  integer timeout;
  begin
  core_drive_cycle();
  tx_data_i = pending_tx_data_i;
  tx_last_i = pending_tx_last_i;
  tx_error_i = pending_tx_error_i;
  tx_valid_i = 1'b1;
  timeout = 0;
  while (!tx_ready_o && timeout < 64) begin
    core_sample_cycle();
    timeout++;
  end
  if (!tx_ready_o) begin
    $display("[TB][ERROR] timeout waiting for tx_ready_o");
    errors++;
  end
  core_drive_cycle();
  tx_valid_i = 1'b0;
  end
endtask
task automatic wait_output_completion;
  integer timeout;
  begin : wait_output_completion_body
  timeout = 0;
  while (!rx_valid_o && timeout < 64) begin
    core_sample_cycle();
    timeout++;
  end
  if (!rx_valid_o) begin
    $display("[TB][ERROR] @wait_output timeout waiting for rx_valid_o");
    errors++;
  end
  end
endtask

task automatic run_inputs(input string path);
  integer fd;
  integer code;
  integer step;
  integer cycles;
  integer event_cursor;
  bit seen;
  string token;
  string reg_name;
  string reset_selector;
  logic [31:0] value;
  logic [31:0] mask;
  logic [31:0] expected;
  logic [31:0] timeout_cycles;
  string line;
  reg [8*4096-1:0] line_buf;
  begin : run_inputs_body
  event_cursor = 0;
  fd = $fopen(path, "r");
  if (fd == 0) begin
    $display("[TB][ERROR] input file not found: %s", path);
    errors++;
    disable run_inputs_body;
  end
  while (!$feof(fd)) begin : tb_stream_input_line
    line = "";
    line_buf = '0;
    void'($fgets(line_buf, fd));
    line = $sformatf("%0s", line_buf);
    if (line.len() == 0 || line.substr(0, 0) == "#") disable tb_stream_input_line;
    code = $sscanf(line, "%d %s", step, token);
    if (code != 2) disable tb_stream_input_line;

    if (token == "@wait_output" || token == "wait_output") begin
      wait_output_completion();
    end else if (token == "@wait_event" || token == "wait_event") begin
      code = $sscanf(line, "%d %s %s %h %d", step, token, reg_name, expected, timeout_cycles);
      if (code < 4) begin
        errors++;
        $display("[TB][ERROR] @wait_event format: step @wait_event label value [timeout]");
      end else begin
        if (code < 5) timeout_cycles = 1024;
        seen = 1'b0;
        tb_wait_event(reg_name, expected, int'(timeout_cycles), event_cursor, seen);
        if (!seen) begin errors++; $display("[TB][ERROR] event timeout name=%s", reg_name); end
      end

    end else if (token == "@wait_signal" || token == "wait_signal") begin
      code = $sscanf(line, "%d %s %s %h %d", step, token, reg_name, expected, timeout_cycles);
      if (code < 4) begin
        errors++;
        $display("[TB][ERROR] @wait_signal format: step @wait_signal signal value [timeout]");
      end else begin
        if (code < 5) timeout_cycles = 1024;
        seen = 1'b0;
        tb_wait_signal(reg_name, expected, int'(timeout_cycles), seen);
        if (!seen) begin errors++; $display("[TB][ERROR] signal timeout name=%s", reg_name); end
      end

    end else if (token == "@write" || token == "write") begin
      code = $sscanf(line, "%d %s %s %h", step, token, reg_name, value);
      if (code == 4) begin
        mask = 32'hffff_ffff;
        if ($sscanf(line, "%d %s %s %h %h", step, token, reg_name, value, mask) != 5)
          mask = 32'hffff_ffff;
        apply_reg_masked(reg_name, value, mask);
        repeat (8) core_sample_cycle();
      end

    end else if (token == "@read" || token == "read") begin
      code = $sscanf(line, "%d %s %s %h", step, token, reg_name, value);
      if (code == 4) begin
        mask = 32'hffff_ffff;
        if ($sscanf(line, "%d %s %s %h %h", step, token, reg_name, value, mask) != 5)
          mask = 32'hffff_ffff;
        expect_reg(reg_name, value, mask);
      end

    end else if (token == "@reset" || token == "reset") begin
      reset_selector = "all";
      code = $sscanf(line, "%d %s %s %d", step, token, reset_selector, cycles);
      if (code == 3) begin
        code = $sscanf(line, "%d %s %d", step, token, cycles);
        reset_selector = "all";
      end
      if (code == 3 || code >= 4) reset_dut(reset_selector, cycles);
      else begin
        $display("[TB][ERROR] @reset format: cycle @reset [domain|reset] cycles");
        errors++;
      end
    end else begin
      code = $sscanf(line, "%d %s %h", step, token, value);
      if (code != 3) disable tb_stream_input_line;
      if (token == "phy_rst_i") begin core_drive_cycle(); phy_rst_i = value; end
      else if (token == "phy_gtx_clk_i") begin core_drive_cycle(); phy_gtx_clk_i = value; end
      else if (token == "phy_gmii_rx_clk_i") begin core_drive_cycle(); phy_gmii_rx_clk_i = value; end
      else if (token == "phy_gmii_rxd_i") begin core_drive_cycle(); phy_gmii_rxd_i = value; end
      else if (token == "phy_gmii_rx_dv_i") begin core_drive_cycle(); phy_gmii_rx_dv_i = value; end
      else if (token == "phy_gmii_rx_er_i") begin core_drive_cycle(); phy_gmii_rx_er_i = value; end
      else if (token == "phy_mii_tx_clk_i") begin core_drive_cycle(); phy_mii_tx_clk_i = value; end
      else if (token == "phy_mii_select_i") begin core_drive_cycle(); phy_mii_select_i = value; end
      else if (token == "phy_speed_i") begin pending_phy_speed_i = value; end
      else if (token == "phy_speed_valid_i") begin if (value[0]) send_phy_speed(); end
      else if (token == "tx_data_i") begin pending_tx_data_i = value; end
      else if (token == "tx_valid_i") begin if (value[0]) send_tx(); end
      else if (token == "tx_last_i") begin pending_tx_last_i = value; end
      else if (token == "tx_error_i") begin pending_tx_error_i = value; end
      else begin $display("[TB][WARN] unknown input vector signal: %s", token); errors++; end
    end
  end
  $fclose(fd);
  end
endtask

task automatic run_vectors(input string input_path, input string output_path);
  load_expected(output_path);
  fork
    run_inputs(input_path);
    check_outputs();
  join
endtask
`else
logic [31:0] pending_phy_speed_i = '0;
logic [31:0] pending_tx_data_i = '0;
logic [31:0] pending_tx_last_i = '0;
logic [31:0] pending_tx_error_i = '0;
task automatic send_phy_speed();
  integer timeout;
  begin
  core_drive_cycle();
  phy_speed_i = pending_phy_speed_i;
  phy_speed_valid_i = 1'b1;
  core_sample_cycle();
  core_drive_cycle();
  phy_speed_valid_i = 1'b0;
  end
endtask

task automatic send_tx();
  integer timeout;
  begin
  core_drive_cycle();
  tx_data_i = pending_tx_data_i;
  tx_last_i = pending_tx_last_i;
  tx_error_i = pending_tx_error_i;
  tx_valid_i = 1'b1;
  timeout = 0;
  while (!tx_ready_o && timeout < 64) begin
    core_sample_cycle();
    timeout++;
  end
  if (!tx_ready_o) begin
    $display("[TB][ERROR] timeout waiting for tx_ready_o");
    errors++;
  end
  core_drive_cycle();
  tx_valid_i = 1'b0;
  end
endtask
task automatic wait_output_completion;
  integer timeout;
  begin : wait_output_completion_body
  timeout = 0;
  while (!rx_valid_o && timeout < 64) begin
    core_sample_cycle();
    timeout++;
  end
  if (!rx_valid_o) begin
    $display("[TB][ERROR] @wait_output timeout waiting for rx_valid_o");
    errors++;
  end
  end
endtask

task automatic run_inputs(input string path);
  integer fd;
  integer code;
  integer step;
  integer cycles;
  integer event_cursor;
  bit seen;
  tb_token_t step_raw;
  tb_token_t token;
  tb_token_t arg0;
  tb_token_t arg1;
  tb_token_t arg2;
  tb_token_t spare0;
  tb_token_t spare1;
  tb_token_t spare2;
  tb_token_t spare3;
  logic [32:0] parsed;
  string reset_selector;
  logic [31:0] value;
  logic [31:0] mask;
  logic [31:0] expected;
  logic [31:0] timeout_cycles;
  tb_line_t line_buf;
  begin : run_inputs_body
  event_cursor = 0;
  fd = $fopen(path, "r");
  if (fd == 0) begin
    $display("[TB][ERROR] input file not found: %s", path);
    errors++;
    disable run_inputs_body;
  end
  while (!$feof(fd)) begin : tb_stream_input_line
    line_buf = '0;
    code = $fgets(line_buf, fd);
    tb_tokenize9(line_buf, code, step_raw, token, arg0, arg1, arg2, spare0, spare1, spare2, spare3);
    if (code < 2 || tb_token_comment(step_raw) || tb_token_comment(token)) disable tb_stream_input_line;
    parsed = tb_parse_u32(step_raw);
    if (!parsed[32]) disable tb_stream_input_line;
    step = int'(parsed[31:0]);

    if (token == "@wait_output" || token == "wait_output") begin
      wait_output_completion();
    end else if (token == "@wait_event" || token == "wait_event") begin
      if (code >= 4) begin
        parsed = tb_parse_u32(arg1);
        if (!parsed[32]) disable tb_stream_input_line;
        expected = parsed[31:0];
        timeout_cycles = 32'd1024;
        if (code >= 5) begin
          parsed = tb_parse_u32(arg2);
          if (parsed[32]) timeout_cycles = parsed[31:0];
        end
        seen = 1'b0;
        tb_wait_event(arg0, expected, int'(timeout_cycles), event_cursor, seen);
        if (!seen) begin errors++; $display("[TB][ERROR] event timeout name=%s", arg0); end
      end

    end else if (token == "@wait_signal" || token == "wait_signal") begin
      if (code >= 4) begin
        parsed = tb_parse_u32(arg1);
        if (!parsed[32]) disable tb_stream_input_line;
        expected = parsed[31:0];
        timeout_cycles = 32'd1024;
        if (code >= 5) begin
          parsed = tb_parse_u32(arg2);
          if (parsed[32]) timeout_cycles = parsed[31:0];
        end
        seen = 1'b0;
        tb_wait_signal(arg0, expected, int'(timeout_cycles), seen);
        if (!seen) begin errors++; $display("[TB][ERROR] signal timeout name=%s", arg0); end
      end

    end else if (token == "@write" || token == "write") begin
      if (code >= 4) begin
        parsed = tb_parse_u32(arg1);
        if (!parsed[32]) disable tb_stream_input_line;
        value = parsed[31:0];
        mask = 32'hffff_ffff;
        if (code >= 5) begin
          parsed = tb_parse_u32(arg2);
          if (parsed[32]) mask = parsed[31:0];
        end
        apply_reg_masked(arg0, value, mask);
        repeat (8) core_sample_cycle();
      end

    end else if (token == "@read" || token == "read") begin
      if (code >= 4) begin
        parsed = tb_parse_u32(arg1);
        if (!parsed[32]) disable tb_stream_input_line;
        value = parsed[31:0];
        mask = 32'hffff_ffff;
        if (code >= 5) begin
          parsed = tb_parse_u32(arg2);
          if (parsed[32]) mask = parsed[31:0];
        end
        expect_reg(arg0, value, mask);
      end

    end else if (token == "@reset" || token == "reset") begin
      reset_selector = "all";
      if (code == 3) begin
        parsed = tb_parse_u32(arg0);
        if (!parsed[32]) disable tb_stream_input_line;
        cycles = int'(parsed[31:0]);
      end else if (code >= 4) begin
        reset_selector = $sformatf("%0s", arg0);
        parsed = tb_parse_u32(arg1);
        if (!parsed[32]) disable tb_stream_input_line;
        cycles = int'(parsed[31:0]);
      end
      if (code == 3 || code >= 4) reset_dut(reset_selector, cycles);
      else begin
        $display("[TB][ERROR] @reset format: cycle @reset [domain|reset] cycles");
        errors++;
      end
    end else begin
      if (code < 3) disable tb_stream_input_line;
      parsed = tb_parse_u32(arg0);
      if (!parsed[32]) disable tb_stream_input_line;
      value = parsed[31:0];
      if (token == "phy_rst_i") begin core_drive_cycle(); phy_rst_i = value; end
      else if (token == "phy_gtx_clk_i") begin core_drive_cycle(); phy_gtx_clk_i = value; end
      else if (token == "phy_gmii_rx_clk_i") begin core_drive_cycle(); phy_gmii_rx_clk_i = value; end
      else if (token == "phy_gmii_rxd_i") begin core_drive_cycle(); phy_gmii_rxd_i = value; end
      else if (token == "phy_gmii_rx_dv_i") begin core_drive_cycle(); phy_gmii_rx_dv_i = value; end
      else if (token == "phy_gmii_rx_er_i") begin core_drive_cycle(); phy_gmii_rx_er_i = value; end
      else if (token == "phy_mii_tx_clk_i") begin core_drive_cycle(); phy_mii_tx_clk_i = value; end
      else if (token == "phy_mii_select_i") begin core_drive_cycle(); phy_mii_select_i = value; end
      else if (token == "phy_speed_i") begin pending_phy_speed_i = value; end
      else if (token == "phy_speed_valid_i") begin if (value[0]) send_phy_speed(); end
      else if (token == "tx_data_i") begin pending_tx_data_i = value; end
      else if (token == "tx_valid_i") begin if (value[0]) send_tx(); end
      else if (token == "tx_last_i") begin pending_tx_last_i = value; end
      else if (token == "tx_error_i") begin pending_tx_error_i = value; end
      else begin $display("[TB][WARN] unknown input vector signal: %s", token); errors++; end
    end
  end
  $fclose(fd);
  end
endtask

task automatic run_vectors(input string input_path, input string output_path);
  load_expected(output_path);
  fork
    run_inputs(input_path);
    check_outputs();
  join
endtask
`endif
