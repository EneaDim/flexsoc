`ifdef VERILATOR
// Auto-generated vector monitor for uart.
// data_out.vec supports fixed-cycle checks, guarded-valid checks and register reads.

int tb_guarded_output_next;

function automatic bit tb_vec_is_dec_char(input byte ch);
  return ch >= 8'h30 && ch <= 8'h39;
endfunction

function automatic bit tb_vec_is_hex_alpha(input byte ch);
  return (ch >= 8'h41 && ch <= 8'h46) || (ch >= 8'h61 && ch <= 8'h66);
endfunction

function automatic bit tb_vec_is_all_dec(input string raw);
  int i;
  byte ch;

  if (raw.len() == 0) return 1'b0;

  for (i = 0; i < raw.len(); i++) begin
    ch = raw[i];
    if (!tb_vec_is_dec_char(ch)) return 1'b0;
  end

  return 1'b1;
endfunction

function automatic bit tb_vec_is_bare_hex(input string raw);
  int i;
  byte ch;
  bit has_hex_alpha;

  if (raw.len() == 0) return 1'b0;
  has_hex_alpha = 1'b0;

  for (i = 0; i < raw.len(); i++) begin
    ch = raw[i];

    if (tb_vec_is_dec_char(ch)) begin
      // decimal digit is also legal in hex
    end else if (tb_vec_is_hex_alpha(ch)) begin
      has_hex_alpha = 1'b1;
    end else begin
      return 1'b0;
    end
  end

  return has_hex_alpha;
endfunction

function automatic logic [32:0] tb_parse_u32(input string raw);
  string s;
  logic [31:0] value;
  int ok;

  value = '0;
  s = raw;
  ok = 0;

  if (raw.len() > 2 && (raw.substr(0, 1) == "0x" || raw.substr(0, 1) == "0X")) begin
    s = raw.substr(2, raw.len() - 1);
    ok = $sscanf(s, "%h", value);
  end else if (tb_vec_is_all_dec(raw)) begin
    ok = $sscanf(raw, "%d", value);
  end else if (tb_vec_is_bare_hex(raw)) begin
    ok = $sscanf(raw, "%h", value);
  end

  if (ok != 1) begin
    $display("[TB][WARN] cannot parse vector value: %s", raw);
  end

  return {ok == 1, value};
endfunction

task automatic tb_tokenize9(
  input string line,
  output int count,
  output string w0,
  output string w1,
  output string w2,
  output string w3,
  output string w4,
  output string w5,
  output string w6,
  output string w7,
  output string w8
);
  int i;
  int j;
  int n;
  byte ch;
  string tok;

  count = 0;
  w0 = ""; w1 = ""; w2 = ""; w3 = ""; w4 = "";
  w5 = ""; w6 = ""; w7 = ""; w8 = "";

  n = line.len();
  i = 0;

  begin : tb_tokenize_done
    while (i < n) begin
      begin : tb_skip_ws
        while (i < n) begin
          ch = line[i];
          if (!(ch == 8'h20 || ch == 8'h09 || ch == 8'h0a || ch == 8'h0d))
            disable tb_skip_ws;
          i++;
        end
      end

      if (i >= n) disable tb_tokenize_done;

      j = i;

      begin : tb_scan_token
        while (i < n) begin
          ch = line[i];
          if (ch == 8'h20 || ch == 8'h09 || ch == 8'h0a || ch == 8'h0d)
            disable tb_scan_token;
          i++;
        end
      end

      tok = line.substr(j, i - 1);

    if (count == 0) w0 = tok;
    else if (count == 1) w1 = tok;
    else if (count == 2) w2 = tok;
    else if (count == 3) w3 = tok;
    else if (count == 4) w4 = tok;
    else if (count == 5) w5 = tok;
    else if (count == 6) w6 = tok;
    else if (count == 7) w7 = tok;
    else if (count == 8) w8 = tok;

    count++;

    if (tok.len() > 0 && tok.substr(0, 0) == "#") begin
      disable tb_tokenize_done;
    end

    if (count >= 9) begin
      disable tb_tokenize_done;
    end
    end
  end
endtask

function automatic logic [32:0] tb_read_output(input string name);
  logic [31:0] actual;
  bit known;

  actual = '0;
  known = 1'b0;

  if (1'b0) begin
    known = 1'b0;
  end
  else if (name == "tx_o") begin
    actual = tx_o;
    known = 1'b1;
  end
  else begin
    known = 1'b0;
  end

  return {known, actual};
endfunction

task automatic tb_check_signal_one(input int cycle, input string name, input string raw);
  logic [31:0] actual;
  logic [31:0] expected;
  logic [32:0] parsed;
  logic [32:0] sampled;

  begin : tb_check_signal_one_body
    if (name == "") disable tb_check_signal_one_body;
    parsed = tb_parse_u32(raw);
    if (!parsed[32]) disable tb_check_signal_one_body;
    expected = parsed[31:0];

    sampled = tb_read_output(name);
    if (!sampled[32]) begin
      errors++;
      $display("[TB][ERROR] unknown expected-output vector signal: %s", name);
      disable tb_check_signal_one_body;
    end
    actual = sampled[31:0];

    if (actual !== expected) begin
      errors++;
      $display("[TB][FAIL] cycle=%0d %s actual=0x%08x expected=0x%08x", cycle, name, actual, expected);
    end else begin
      $display("[TB][PASS] cycle=%0d %s=0x%08x", cycle, name, actual);
    end
  end
endtask

task automatic tb_check_read_one(
  input int cycle,
  input string reg_key,
  input string expected_raw,
  input string mask_raw
);
  logic [31:0] actual;
  logic [31:0] expected;
  logic [31:0] mask;
  logic [32:0] parsed;

  begin : tb_check_read_one_body
    parsed = tb_parse_u32(expected_raw);
    if (!parsed[32]) disable tb_check_read_one_body;
    expected = parsed[31:0];

    parsed = tb_parse_u32(mask_raw);
    if (mask_raw.len() > 0 && parsed[32]) begin
      mask = parsed[31:0];
    end else begin
      mask = 32'hffff_ffff;
    end

    read_reg(reg_key, actual);

    if ((actual & mask) !== (expected & mask)) begin
      errors++;
      $display("[TB][FAIL] cycle=%0d read %s actual=0x%08x expected=0x%08x mask=0x%08x",
               cycle, reg_key, actual, expected, mask);
    end else begin
      $display("[TB][PASS] cycle=%0d read %s=0x%08x mask=0x%08x",
               cycle, reg_key, actual, mask);
    end
  end
endtask


task automatic run_output_vectors(input string out_path);
  int fd;
  int code;
  int now_cycle;
  int cycle;
  int event_cursor;
  logic [31:0] cycle_value;
  logic [31:0] expected;
  logic [31:0] timeout;
  logic [32:0] parsed;
  logic [32:0] sampled;
  bit seen;
  string cycle_raw;
  string line;
  reg [8*4096-1:0] line_buf;
  string t0;
  string t1;
  string t2;
  string t3;
  string t4;
  string t5;
  string t6;
  string t7;


  begin : run_output_vectors_body
    now_cycle = -1;
    event_cursor = 0;
    fd = $fopen(out_path, "r");
    if (fd == 0) begin
      $display("[TB][ERROR] expected file not found: %s", out_path);
      errors++;
      disable run_output_vectors_body;
    end

    while (!$feof(fd)) begin : tb_output_line
      line = "";
      line_buf = '0;
      void'($fgets(line_buf, fd));
      line = $sformatf("%0s", line_buf);
      tb_tokenize9(line, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

      if (code < 2) disable tb_output_line;
      if (cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#") disable tb_output_line;
      if (t0.len() > 0 && t0.substr(0, 0) == "#") disable tb_output_line;


      parsed = tb_parse_u32(cycle_raw);
      if (!parsed[32]) begin
        sampled = tb_read_output(cycle_raw);
        if (!sampled[32]) begin
          errors++;
          $display("[TB][ERROR] invalid output cycle/guard token: %s", cycle_raw);
          disable tb_output_line;
        end
        seen = 1'b0;
        tb_wait_signal(cycle_raw, 32'd1, 4096, seen);
        if (!seen) begin
          errors++;
          $display("[TB][ERROR] guarded output timeout signal=%s", cycle_raw);
          disable tb_output_line;
        end
        tb_check_signal_one(now_cycle, t0, t1);
        if (code >= 5) tb_check_signal_one(now_cycle, t2, t3);
        if (code >= 7) tb_check_signal_one(now_cycle, t4, t5);
        if (code >= 9) tb_check_signal_one(now_cycle, t6, t7);
        disable tb_output_line;
      end

      cycle_value = parsed[31:0];
      cycle = int'(cycle_value);
      while (now_cycle < cycle) begin
        core_sample_cycle();
        now_cycle++;
      end

      if (t0 == "@wait_event" || t0 == "wait_event") begin
        if (code < 4) begin
          errors++;
          $display("[TB][ERROR] malformed @wait_event row");
          disable tb_output_line;
        end
        parsed = tb_parse_u32(t2);
        if (!parsed[32]) disable tb_output_line;
        expected = parsed[31:0];
        parsed = tb_parse_u32(t3);
        timeout = parsed[32] ? parsed[31:0] : 32'd1024;
        seen = 1'b0;
        tb_wait_event(t1, expected, int'(timeout), event_cursor, seen);
        if (!seen) begin
          errors++;
          $display("[TB][ERROR] event timeout name=%s value=0x%08x", t1, expected);
        end
        now_cycle = -1;
        disable tb_output_line;
      end

      if (t0 == "@wait_signal" || t0 == "wait_signal") begin
        if (code < 4) begin
          errors++;
          $display("[TB][ERROR] malformed @wait_signal row");
          disable tb_output_line;
        end
        parsed = tb_parse_u32(t2);
        if (!parsed[32]) disable tb_output_line;
        expected = parsed[31:0];
        parsed = tb_parse_u32(t3);
        timeout = parsed[32] ? parsed[31:0] : 32'd1024;
        seen = 1'b0;
        tb_wait_signal(t1, expected, int'(timeout), seen);
        if (!seen) begin
          errors++;
          $display("[TB][ERROR] signal timeout name=%s value=0x%08x", t1, expected);
        end
        now_cycle = -1;
        disable tb_output_line;
      end

      if (t0 == "@read" || t0 == "read" || t0 == "@reg_read" || t0 == "reg_read") begin
        if (code < 4) begin
          errors++;
          $display("[TB][ERROR] malformed @read row");
        end else begin
          tb_check_read_one(cycle, t1, t2, t3);
        end
        disable tb_output_line;
      end

      tb_check_signal_one(cycle, t0, t1);
      if (code >= 5) tb_check_signal_one(cycle, t2, t3);
      if (code >= 7) tb_check_signal_one(cycle, t4, t5);
      if (code >= 9) tb_check_signal_one(cycle, t6, t7);
    end
    $fclose(fd);
  end
endtask
`else
// Auto-generated vector monitor for uart.
// data_out.vec supports fixed-cycle checks, guarded-valid checks and register reads.

int tb_guarded_output_next;

function automatic logic [32:0] tb_read_output(input tb_token_t name);
  logic [31:0] actual;
  bit known;

  actual = '0;
  known = 1'b0;

  if (1'b0) begin
    known = 1'b0;
  end
  else if (name == "tx_o") begin
    actual = tx_o;
    known = 1'b1;
  end
  else begin
    known = 1'b0;
  end

  return {known, actual};
endfunction

task automatic tb_check_signal_one(input int cycle, input tb_token_t name, input tb_token_t raw);
  logic [31:0] actual;
  logic [31:0] expected;
  logic [32:0] parsed;
  logic [32:0] sampled;

  begin : tb_check_signal_one_body
    if (tb_token_empty(name)) disable tb_check_signal_one_body;
    parsed = tb_parse_u32(raw);
    if (!parsed[32]) disable tb_check_signal_one_body;
    expected = parsed[31:0];

    sampled = tb_read_output(name);
    if (!sampled[32]) begin
      errors++;
      $display("[TB][ERROR] unknown expected-output vector signal: %s", name);
      disable tb_check_signal_one_body;
    end
    actual = sampled[31:0];

    if (actual !== expected) begin
      errors++;
      $display("[TB][FAIL] cycle=%0d %s actual=0x%08x expected=0x%08x", cycle, name, actual, expected);
    end else begin
      $display("[TB][PASS] cycle=%0d %s=0x%08x", cycle, name, actual);
    end
  end
endtask

task automatic tb_check_read_one(
  input int cycle,
  input tb_token_t reg_key,
  input tb_token_t expected_raw,
  input tb_token_t mask_raw
);
  logic [31:0] actual;
  logic [31:0] expected;
  logic [31:0] mask;
  logic [32:0] parsed;

  begin : tb_check_read_one_body
    parsed = tb_parse_u32(expected_raw);
    if (!parsed[32]) disable tb_check_read_one_body;
    expected = parsed[31:0];

    parsed = tb_parse_u32(mask_raw);
    if (!tb_token_empty(mask_raw) && parsed[32]) begin
      mask = parsed[31:0];
    end else begin
      mask = 32'hffff_ffff;
    end

    read_reg(reg_key, actual);

    if ((actual & mask) !== (expected & mask)) begin
      errors++;
      $display("[TB][FAIL] cycle=%0d read %s actual=0x%08x expected=0x%08x mask=0x%08x",
               cycle, reg_key, actual, expected, mask);
    end else begin
      $display("[TB][PASS] cycle=%0d read %s=0x%08x mask=0x%08x",
               cycle, reg_key, actual, mask);
    end
  end
endtask


task automatic run_output_vectors(input string out_path);
  int fd;
  int code;
  int now_cycle;
  int cycle;
  int event_cursor;
  logic [31:0] cycle_value;
  logic [31:0] expected;
  logic [31:0] timeout;
  logic [32:0] parsed;
  logic [32:0] sampled;
  bit seen;
  tb_token_t cycle_raw;
  tb_line_t line_buf;
  tb_token_t t0;
  tb_token_t t1;
  tb_token_t t2;
  tb_token_t t3;
  tb_token_t t4;
  tb_token_t t5;
  tb_token_t t6;
  tb_token_t t7;


  begin : run_output_vectors_body
    now_cycle = -1;
    event_cursor = 0;
    fd = $fopen(out_path, "r");
    if (fd == 0) begin
      $display("[TB][ERROR] expected file not found: %s", out_path);
      errors++;
      disable run_output_vectors_body;
    end

    while (!$feof(fd)) begin : tb_output_line
      line_buf = '0;
      code = $fgets(line_buf, fd);
      tb_tokenize9(line_buf, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

      if (code < 2) disable tb_output_line;
      if (tb_token_comment(cycle_raw) || tb_token_comment(t0)) disable tb_output_line;


      parsed = tb_parse_u32(cycle_raw);
      if (!parsed[32]) begin
        sampled = tb_read_output(cycle_raw);
        if (!sampled[32]) begin
          errors++;
          $display("[TB][ERROR] invalid output cycle/guard token: %s", cycle_raw);
          disable tb_output_line;
        end
        seen = 1'b0;
        tb_wait_signal(cycle_raw, 32'd1, 4096, seen);
        if (!seen) begin
          errors++;
          $display("[TB][ERROR] guarded output timeout signal=%s", cycle_raw);
          disable tb_output_line;
        end
        tb_check_signal_one(now_cycle, t0, t1);
        if (code >= 5) tb_check_signal_one(now_cycle, t2, t3);
        if (code >= 7) tb_check_signal_one(now_cycle, t4, t5);
        if (code >= 9) tb_check_signal_one(now_cycle, t6, t7);
        disable tb_output_line;
      end

      cycle_value = parsed[31:0];
      cycle = int'(cycle_value);
      while (now_cycle < cycle) begin
        core_sample_cycle();
        now_cycle++;
      end

      if (t0 == "@wait_event" || t0 == "wait_event") begin
        if (code < 4) begin
          errors++;
          $display("[TB][ERROR] malformed @wait_event row");
          disable tb_output_line;
        end
        parsed = tb_parse_u32(t2);
        if (!parsed[32]) disable tb_output_line;
        expected = parsed[31:0];
        parsed = tb_parse_u32(t3);
        timeout = parsed[32] ? parsed[31:0] : 32'd1024;
        seen = 1'b0;
        tb_wait_event(t1, expected, int'(timeout), event_cursor, seen);
        if (!seen) begin
          errors++;
          $display("[TB][ERROR] event timeout name=%s value=0x%08x", t1, expected);
        end
        now_cycle = -1;
        disable tb_output_line;
      end

      if (t0 == "@wait_signal" || t0 == "wait_signal") begin
        if (code < 4) begin
          errors++;
          $display("[TB][ERROR] malformed @wait_signal row");
          disable tb_output_line;
        end
        parsed = tb_parse_u32(t2);
        if (!parsed[32]) disable tb_output_line;
        expected = parsed[31:0];
        parsed = tb_parse_u32(t3);
        timeout = parsed[32] ? parsed[31:0] : 32'd1024;
        seen = 1'b0;
        tb_wait_signal(t1, expected, int'(timeout), seen);
        if (!seen) begin
          errors++;
          $display("[TB][ERROR] signal timeout name=%s value=0x%08x", t1, expected);
        end
        now_cycle = -1;
        disable tb_output_line;
      end

      if (t0 == "@read" || t0 == "read" || t0 == "@reg_read" || t0 == "reg_read") begin
        if (code < 4) begin
          errors++;
          $display("[TB][ERROR] malformed @read row");
        end else begin
          tb_check_read_one(cycle, t1, t2, t3);
        end
        disable tb_output_line;
      end

      tb_check_signal_one(cycle, t0, t1);
      if (code >= 5) tb_check_signal_one(cycle, t2, t3);
      if (code >= 7) tb_check_signal_one(cycle, t4, t5);
      if (code >= 9) tb_check_signal_one(cycle, t6, t7);
    end
    $fclose(fd);
  end
endtask
`endif
