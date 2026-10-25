`ifdef VERILATOR
// Expected rows are grouped by logical vector step and consumed in order.
task automatic load_expected(input string path);
  integer fd;
  integer code;
  integer step;
  integer current_step;
  string sig;
  logic [31:0] value;
  string line;
  reg [8*4096-1:0] line_buf;
  begin : load_expected_body
  exp_count = 0;
  current_step = -1;
  fd = $fopen(path, "r");
  if (fd == 0) begin
    $display("[TB][ERROR] expected file not found: %s", path);
    errors++;
    disable load_expected_body;
  end
  while (!$feof(fd)) begin : tb_stream_expected_line
    line = "";
    line_buf = '0;
    void'($fgets(line_buf, fd));
    line = $sformatf("%0s", line_buf);
    if (line.len() == 0 || line.substr(0, 0) == "#") disable tb_stream_expected_line;
    code = $sscanf(line, "%d %s %h", step, sig, value);
    if (code >= 3) begin
      if (step != current_step) begin
        current_step = step;
        exp_has_phy_gmii_tx_clk_o[exp_count] = 1'b0;
        exp_has_phy_gmii_txd_o[exp_count] = 1'b0;
        exp_has_phy_gmii_tx_en_o[exp_count] = 1'b0;
        exp_has_phy_gmii_tx_er_o[exp_count] = 1'b0;
        exp_has_tx_clk_o[exp_count] = 1'b0;
        exp_has_tx_rst_o[exp_count] = 1'b0;
        exp_has_tx_ready_o[exp_count] = 1'b0;
        exp_has_rx_clk_o[exp_count] = 1'b0;
        exp_has_rx_rst_o[exp_count] = 1'b0;
        exp_has_rx_data_o[exp_count] = 1'b0;
        exp_has_rx_valid_o[exp_count] = 1'b0;
        exp_has_rx_last_o[exp_count] = 1'b0;
        exp_has_rx_error_o[exp_count] = 1'b0;
        exp_has_intr_tx_underflow_o[exp_count] = 1'b0;
        exp_has_intr_rx_bad_frame_o[exp_count] = 1'b0;
        exp_has_intr_rx_bad_fcs_o[exp_count] = 1'b0;
        exp_count++;
      end
      if (sig == "phy_gmii_tx_clk_o") begin exp_phy_gmii_tx_clk_o[exp_count - 1] = value; exp_has_phy_gmii_tx_clk_o[exp_count - 1] = 1'b1; end
      else if (sig == "phy_gmii_txd_o") begin exp_phy_gmii_txd_o[exp_count - 1] = value; exp_has_phy_gmii_txd_o[exp_count - 1] = 1'b1; end
      else if (sig == "phy_gmii_tx_en_o") begin exp_phy_gmii_tx_en_o[exp_count - 1] = value; exp_has_phy_gmii_tx_en_o[exp_count - 1] = 1'b1; end
      else if (sig == "phy_gmii_tx_er_o") begin exp_phy_gmii_tx_er_o[exp_count - 1] = value; exp_has_phy_gmii_tx_er_o[exp_count - 1] = 1'b1; end
      else if (sig == "tx_clk_o") begin exp_tx_clk_o[exp_count - 1] = value; exp_has_tx_clk_o[exp_count - 1] = 1'b1; end
      else if (sig == "tx_rst_o") begin exp_tx_rst_o[exp_count - 1] = value; exp_has_tx_rst_o[exp_count - 1] = 1'b1; end
      else if (sig == "tx_ready_o") begin exp_tx_ready_o[exp_count - 1] = value; exp_has_tx_ready_o[exp_count - 1] = 1'b1; end
      else if (sig == "rx_clk_o") begin exp_rx_clk_o[exp_count - 1] = value; exp_has_rx_clk_o[exp_count - 1] = 1'b1; end
      else if (sig == "rx_rst_o") begin exp_rx_rst_o[exp_count - 1] = value; exp_has_rx_rst_o[exp_count - 1] = 1'b1; end
      else if (sig == "rx_data_o") begin exp_rx_data_o[exp_count - 1] = value; exp_has_rx_data_o[exp_count - 1] = 1'b1; end
      else if (sig == "rx_valid_o") begin exp_rx_valid_o[exp_count - 1] = value; exp_has_rx_valid_o[exp_count - 1] = 1'b1; end
      else if (sig == "rx_last_o") begin exp_rx_last_o[exp_count - 1] = value; exp_has_rx_last_o[exp_count - 1] = 1'b1; end
      else if (sig == "rx_error_o") begin exp_rx_error_o[exp_count - 1] = value; exp_has_rx_error_o[exp_count - 1] = 1'b1; end
      else if (sig == "intr_tx_underflow_o") begin exp_intr_tx_underflow_o[exp_count - 1] = value; exp_has_intr_tx_underflow_o[exp_count - 1] = 1'b1; end
      else if (sig == "intr_rx_bad_frame_o") begin exp_intr_rx_bad_frame_o[exp_count - 1] = value; exp_has_intr_rx_bad_frame_o[exp_count - 1] = 1'b1; end
      else if (sig == "intr_rx_bad_fcs_o") begin exp_intr_rx_bad_fcs_o[exp_count - 1] = value; exp_has_intr_rx_bad_fcs_o[exp_count - 1] = 1'b1; end
      else $display("[TB][WARN] unknown expected-output signal: %s", sig);
    end
  end
  $fclose(fd);
  end
endtask

task automatic check_outputs();
  integer timeout;
  got_count = 0;
  timeout = 0;
  while (got_count < exp_count && timeout < 4096) begin
    core_sample_cycle();
    if (rx_valid_o) begin
      if (exp_has_phy_gmii_tx_clk_o[got_count] && $unsigned(phy_gmii_tx_clk_o) !== exp_phy_gmii_tx_clk_o[got_count]) begin
        $display("[TB][ERROR] phy_gmii_tx_clk_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(phy_gmii_tx_clk_o), exp_phy_gmii_tx_clk_o[got_count]);
        errors++;
      end
      if (exp_has_phy_gmii_txd_o[got_count] && $unsigned(phy_gmii_txd_o) !== exp_phy_gmii_txd_o[got_count]) begin
        $display("[TB][ERROR] phy_gmii_txd_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(phy_gmii_txd_o), exp_phy_gmii_txd_o[got_count]);
        errors++;
      end
      if (exp_has_phy_gmii_tx_en_o[got_count] && $unsigned(phy_gmii_tx_en_o) !== exp_phy_gmii_tx_en_o[got_count]) begin
        $display("[TB][ERROR] phy_gmii_tx_en_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(phy_gmii_tx_en_o), exp_phy_gmii_tx_en_o[got_count]);
        errors++;
      end
      if (exp_has_phy_gmii_tx_er_o[got_count] && $unsigned(phy_gmii_tx_er_o) !== exp_phy_gmii_tx_er_o[got_count]) begin
        $display("[TB][ERROR] phy_gmii_tx_er_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(phy_gmii_tx_er_o), exp_phy_gmii_tx_er_o[got_count]);
        errors++;
      end
      if (exp_has_tx_clk_o[got_count] && $unsigned(tx_clk_o) !== exp_tx_clk_o[got_count]) begin
        $display("[TB][ERROR] tx_clk_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(tx_clk_o), exp_tx_clk_o[got_count]);
        errors++;
      end
      if (exp_has_tx_rst_o[got_count] && $unsigned(tx_rst_o) !== exp_tx_rst_o[got_count]) begin
        $display("[TB][ERROR] tx_rst_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(tx_rst_o), exp_tx_rst_o[got_count]);
        errors++;
      end
      if (exp_has_tx_ready_o[got_count] && $unsigned(tx_ready_o) !== exp_tx_ready_o[got_count]) begin
        $display("[TB][ERROR] tx_ready_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(tx_ready_o), exp_tx_ready_o[got_count]);
        errors++;
      end
      if (exp_has_rx_clk_o[got_count] && $unsigned(rx_clk_o) !== exp_rx_clk_o[got_count]) begin
        $display("[TB][ERROR] rx_clk_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(rx_clk_o), exp_rx_clk_o[got_count]);
        errors++;
      end
      if (exp_has_rx_rst_o[got_count] && $unsigned(rx_rst_o) !== exp_rx_rst_o[got_count]) begin
        $display("[TB][ERROR] rx_rst_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(rx_rst_o), exp_rx_rst_o[got_count]);
        errors++;
      end
      if (exp_has_rx_data_o[got_count] && $unsigned(rx_data_o) !== exp_rx_data_o[got_count]) begin
        $display("[TB][ERROR] rx_data_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(rx_data_o), exp_rx_data_o[got_count]);
        errors++;
      end
      if (exp_has_rx_valid_o[got_count] && $unsigned(rx_valid_o) !== exp_rx_valid_o[got_count]) begin
        $display("[TB][ERROR] rx_valid_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(rx_valid_o), exp_rx_valid_o[got_count]);
        errors++;
      end
      if (exp_has_rx_last_o[got_count] && $unsigned(rx_last_o) !== exp_rx_last_o[got_count]) begin
        $display("[TB][ERROR] rx_last_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(rx_last_o), exp_rx_last_o[got_count]);
        errors++;
      end
      if (exp_has_rx_error_o[got_count] && $unsigned(rx_error_o) !== exp_rx_error_o[got_count]) begin
        $display("[TB][ERROR] rx_error_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(rx_error_o), exp_rx_error_o[got_count]);
        errors++;
      end
      if (exp_has_intr_tx_underflow_o[got_count] && $unsigned(intr_tx_underflow_o) !== exp_intr_tx_underflow_o[got_count]) begin
        $display("[TB][ERROR] intr_tx_underflow_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(intr_tx_underflow_o), exp_intr_tx_underflow_o[got_count]);
        errors++;
      end
      if (exp_has_intr_rx_bad_frame_o[got_count] && $unsigned(intr_rx_bad_frame_o) !== exp_intr_rx_bad_frame_o[got_count]) begin
        $display("[TB][ERROR] intr_rx_bad_frame_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(intr_rx_bad_frame_o), exp_intr_rx_bad_frame_o[got_count]);
        errors++;
      end
      if (exp_has_intr_rx_bad_fcs_o[got_count] && $unsigned(intr_rx_bad_fcs_o) !== exp_intr_rx_bad_fcs_o[got_count]) begin
        $display("[TB][ERROR] intr_rx_bad_fcs_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(intr_rx_bad_fcs_o), exp_intr_rx_bad_fcs_o[got_count]);
        errors++;
      end
      got_count++;
    end
    timeout++;
  end
  if (got_count != exp_count) begin
    $display("[TB][ERROR] observed %0d/%0d expected outputs", got_count, exp_count);
    errors++;
  end
endtask
`else
// Expected rows are grouped by logical vector step and consumed in order.
task automatic load_expected(input string path);
  integer fd;
  integer code;
  integer step;
  integer current_step;
  tb_token_t step_raw;
  tb_token_t sig;
  tb_token_t value_raw;
  tb_token_t spare0;
  tb_token_t spare1;
  tb_token_t spare2;
  tb_token_t spare3;
  tb_token_t spare4;
  tb_token_t spare5;
  logic [32:0] parsed;
  logic [31:0] value;
  tb_line_t line_buf;
  begin : load_expected_body
  exp_count = 0;
  current_step = -1;
  fd = $fopen(path, "r");
  if (fd == 0) begin
    $display("[TB][ERROR] expected file not found: %s", path);
    errors++;
    disable load_expected_body;
  end
  while (!$feof(fd)) begin : tb_stream_expected_line
    line_buf = '0;
    code = $fgets(line_buf, fd);
    tb_tokenize9(line_buf, code, step_raw, sig, value_raw, spare0, spare1, spare2, spare3, spare4, spare5);
    if (code < 3 || tb_token_comment(step_raw) || tb_token_comment(sig)) disable tb_stream_expected_line;
    parsed = tb_parse_u32(step_raw);
    if (!parsed[32]) disable tb_stream_expected_line;
    step = int'(parsed[31:0]);
    parsed = tb_parse_u32(value_raw);
    if (!parsed[32]) disable tb_stream_expected_line;
    value = parsed[31:0];
    if (code >= 3) begin
      if (step != current_step) begin
        current_step = step;
        exp_has_phy_gmii_tx_clk_o[exp_count] = 1'b0;
        exp_has_phy_gmii_txd_o[exp_count] = 1'b0;
        exp_has_phy_gmii_tx_en_o[exp_count] = 1'b0;
        exp_has_phy_gmii_tx_er_o[exp_count] = 1'b0;
        exp_has_tx_clk_o[exp_count] = 1'b0;
        exp_has_tx_rst_o[exp_count] = 1'b0;
        exp_has_tx_ready_o[exp_count] = 1'b0;
        exp_has_rx_clk_o[exp_count] = 1'b0;
        exp_has_rx_rst_o[exp_count] = 1'b0;
        exp_has_rx_data_o[exp_count] = 1'b0;
        exp_has_rx_valid_o[exp_count] = 1'b0;
        exp_has_rx_last_o[exp_count] = 1'b0;
        exp_has_rx_error_o[exp_count] = 1'b0;
        exp_has_intr_tx_underflow_o[exp_count] = 1'b0;
        exp_has_intr_rx_bad_frame_o[exp_count] = 1'b0;
        exp_has_intr_rx_bad_fcs_o[exp_count] = 1'b0;
        exp_count++;
      end
      if (sig == "phy_gmii_tx_clk_o") begin exp_phy_gmii_tx_clk_o[exp_count - 1] = value; exp_has_phy_gmii_tx_clk_o[exp_count - 1] = 1'b1; end
      else if (sig == "phy_gmii_txd_o") begin exp_phy_gmii_txd_o[exp_count - 1] = value; exp_has_phy_gmii_txd_o[exp_count - 1] = 1'b1; end
      else if (sig == "phy_gmii_tx_en_o") begin exp_phy_gmii_tx_en_o[exp_count - 1] = value; exp_has_phy_gmii_tx_en_o[exp_count - 1] = 1'b1; end
      else if (sig == "phy_gmii_tx_er_o") begin exp_phy_gmii_tx_er_o[exp_count - 1] = value; exp_has_phy_gmii_tx_er_o[exp_count - 1] = 1'b1; end
      else if (sig == "tx_clk_o") begin exp_tx_clk_o[exp_count - 1] = value; exp_has_tx_clk_o[exp_count - 1] = 1'b1; end
      else if (sig == "tx_rst_o") begin exp_tx_rst_o[exp_count - 1] = value; exp_has_tx_rst_o[exp_count - 1] = 1'b1; end
      else if (sig == "tx_ready_o") begin exp_tx_ready_o[exp_count - 1] = value; exp_has_tx_ready_o[exp_count - 1] = 1'b1; end
      else if (sig == "rx_clk_o") begin exp_rx_clk_o[exp_count - 1] = value; exp_has_rx_clk_o[exp_count - 1] = 1'b1; end
      else if (sig == "rx_rst_o") begin exp_rx_rst_o[exp_count - 1] = value; exp_has_rx_rst_o[exp_count - 1] = 1'b1; end
      else if (sig == "rx_data_o") begin exp_rx_data_o[exp_count - 1] = value; exp_has_rx_data_o[exp_count - 1] = 1'b1; end
      else if (sig == "rx_valid_o") begin exp_rx_valid_o[exp_count - 1] = value; exp_has_rx_valid_o[exp_count - 1] = 1'b1; end
      else if (sig == "rx_last_o") begin exp_rx_last_o[exp_count - 1] = value; exp_has_rx_last_o[exp_count - 1] = 1'b1; end
      else if (sig == "rx_error_o") begin exp_rx_error_o[exp_count - 1] = value; exp_has_rx_error_o[exp_count - 1] = 1'b1; end
      else if (sig == "intr_tx_underflow_o") begin exp_intr_tx_underflow_o[exp_count - 1] = value; exp_has_intr_tx_underflow_o[exp_count - 1] = 1'b1; end
      else if (sig == "intr_rx_bad_frame_o") begin exp_intr_rx_bad_frame_o[exp_count - 1] = value; exp_has_intr_rx_bad_frame_o[exp_count - 1] = 1'b1; end
      else if (sig == "intr_rx_bad_fcs_o") begin exp_intr_rx_bad_fcs_o[exp_count - 1] = value; exp_has_intr_rx_bad_fcs_o[exp_count - 1] = 1'b1; end
      else $display("[TB][WARN] unknown expected-output signal: %s", sig);
    end
  end
  $fclose(fd);
  end
endtask

task automatic check_outputs();
  integer timeout;
  got_count = 0;
  timeout = 0;
  while (got_count < exp_count && timeout < 4096) begin
    core_sample_cycle();
    if (rx_valid_o) begin
      if (exp_has_phy_gmii_tx_clk_o[got_count] && $unsigned(phy_gmii_tx_clk_o) !== exp_phy_gmii_tx_clk_o[got_count]) begin
        $display("[TB][ERROR] phy_gmii_tx_clk_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(phy_gmii_tx_clk_o), exp_phy_gmii_tx_clk_o[got_count]);
        errors++;
      end
      if (exp_has_phy_gmii_txd_o[got_count] && $unsigned(phy_gmii_txd_o) !== exp_phy_gmii_txd_o[got_count]) begin
        $display("[TB][ERROR] phy_gmii_txd_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(phy_gmii_txd_o), exp_phy_gmii_txd_o[got_count]);
        errors++;
      end
      if (exp_has_phy_gmii_tx_en_o[got_count] && $unsigned(phy_gmii_tx_en_o) !== exp_phy_gmii_tx_en_o[got_count]) begin
        $display("[TB][ERROR] phy_gmii_tx_en_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(phy_gmii_tx_en_o), exp_phy_gmii_tx_en_o[got_count]);
        errors++;
      end
      if (exp_has_phy_gmii_tx_er_o[got_count] && $unsigned(phy_gmii_tx_er_o) !== exp_phy_gmii_tx_er_o[got_count]) begin
        $display("[TB][ERROR] phy_gmii_tx_er_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(phy_gmii_tx_er_o), exp_phy_gmii_tx_er_o[got_count]);
        errors++;
      end
      if (exp_has_tx_clk_o[got_count] && $unsigned(tx_clk_o) !== exp_tx_clk_o[got_count]) begin
        $display("[TB][ERROR] tx_clk_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(tx_clk_o), exp_tx_clk_o[got_count]);
        errors++;
      end
      if (exp_has_tx_rst_o[got_count] && $unsigned(tx_rst_o) !== exp_tx_rst_o[got_count]) begin
        $display("[TB][ERROR] tx_rst_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(tx_rst_o), exp_tx_rst_o[got_count]);
        errors++;
      end
      if (exp_has_tx_ready_o[got_count] && $unsigned(tx_ready_o) !== exp_tx_ready_o[got_count]) begin
        $display("[TB][ERROR] tx_ready_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(tx_ready_o), exp_tx_ready_o[got_count]);
        errors++;
      end
      if (exp_has_rx_clk_o[got_count] && $unsigned(rx_clk_o) !== exp_rx_clk_o[got_count]) begin
        $display("[TB][ERROR] rx_clk_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(rx_clk_o), exp_rx_clk_o[got_count]);
        errors++;
      end
      if (exp_has_rx_rst_o[got_count] && $unsigned(rx_rst_o) !== exp_rx_rst_o[got_count]) begin
        $display("[TB][ERROR] rx_rst_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(rx_rst_o), exp_rx_rst_o[got_count]);
        errors++;
      end
      if (exp_has_rx_data_o[got_count] && $unsigned(rx_data_o) !== exp_rx_data_o[got_count]) begin
        $display("[TB][ERROR] rx_data_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(rx_data_o), exp_rx_data_o[got_count]);
        errors++;
      end
      if (exp_has_rx_valid_o[got_count] && $unsigned(rx_valid_o) !== exp_rx_valid_o[got_count]) begin
        $display("[TB][ERROR] rx_valid_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(rx_valid_o), exp_rx_valid_o[got_count]);
        errors++;
      end
      if (exp_has_rx_last_o[got_count] && $unsigned(rx_last_o) !== exp_rx_last_o[got_count]) begin
        $display("[TB][ERROR] rx_last_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(rx_last_o), exp_rx_last_o[got_count]);
        errors++;
      end
      if (exp_has_rx_error_o[got_count] && $unsigned(rx_error_o) !== exp_rx_error_o[got_count]) begin
        $display("[TB][ERROR] rx_error_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(rx_error_o), exp_rx_error_o[got_count]);
        errors++;
      end
      if (exp_has_intr_tx_underflow_o[got_count] && $unsigned(intr_tx_underflow_o) !== exp_intr_tx_underflow_o[got_count]) begin
        $display("[TB][ERROR] intr_tx_underflow_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(intr_tx_underflow_o), exp_intr_tx_underflow_o[got_count]);
        errors++;
      end
      if (exp_has_intr_rx_bad_frame_o[got_count] && $unsigned(intr_rx_bad_frame_o) !== exp_intr_rx_bad_frame_o[got_count]) begin
        $display("[TB][ERROR] intr_rx_bad_frame_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(intr_rx_bad_frame_o), exp_intr_rx_bad_frame_o[got_count]);
        errors++;
      end
      if (exp_has_intr_rx_bad_fcs_o[got_count] && $unsigned(intr_rx_bad_fcs_o) !== exp_intr_rx_bad_fcs_o[got_count]) begin
        $display("[TB][ERROR] intr_rx_bad_fcs_o[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(intr_rx_bad_fcs_o), exp_intr_rx_bad_fcs_o[got_count]);
        errors++;
      end
      got_count++;
    end
    timeout++;
  end
  if (got_count != exp_count) begin
    $display("[TB][ERROR] observed %0d/%0d expected outputs", got_count, exp_count);
    errors++;
  end
endtask
`endif
