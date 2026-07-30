// Auto-generated vector monitor for cordic.
// data_out.vec supports both signal checks and register reads.

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
    ch = raw.getc(i);
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
    ch = raw.getc(i);

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

function automatic bit tb_parse_u32(input string raw, output logic [31:0] value);
  string s;
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

  return ok == 1;
endfunction

function automatic void tb_tokenize9(
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

  while (i < n) begin
    while (i < n) begin
      ch = line.getc(i);
      if (!(ch == 8'h20 || ch == 8'h09 || ch == 8'h0a || ch == 8'h0d)) break;
      i++;
    end

    if (i >= n) break;

    j = i;

    while (i < n) begin
      ch = line.getc(i);
      if (ch == 8'h20 || ch == 8'h09 || ch == 8'h0a || ch == 8'h0d) break;
      i++;
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
      return;
    end

    if (count >= 9) begin
      return;
    end
  end
endfunction

function automatic logic [31:0] tb_read_output(input string name, output bit known);
  logic [31:0] actual;

  actual = '0;
  known = 1'b0;

  if (1'b0) begin
    known = 1'b0;
  end
  else begin
    known = 1'b0;
  end

  return actual;
endfunction

task automatic tb_check_signal_one(input int cycle, input string name, input string raw);
  logic [31:0] actual;
  logic [31:0] expected;
  bit known;

  if (name == "") return;
  if (!tb_parse_u32(raw, expected)) return;

  actual = tb_read_output(name, known);

  if (!known) begin
    error_count++;
    $display("[TB][ERROR] unknown expected-output vector signal: %s", name);
    return;
  end

  if (actual !== expected) begin
    error_count++;
    $display("[TB][FAIL] cycle=%0d %s actual=0x%08x expected=0x%08x", cycle, name, actual, expected);
  end else begin
    $display("[TB][PASS] cycle=%0d %s=0x%08x", cycle, name, actual);
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
  bit ok;

  if (!tb_parse_u32(expected_raw, expected)) return;

  if (mask_raw.len() > 0 && tb_parse_u32(mask_raw, mask)) begin
    // parsed explicit mask
  end else begin
    mask = 32'hffff_ffff;
  end

  tb_reg_read_key(reg_key, actual, ok);
  if (!ok) return;

  if ((actual & mask) !== (expected & mask)) begin
    error_count++;
    $display("[TB][FAIL] cycle=%0d read %s actual=0x%08x expected=0x%08x mask=0x%08x",
             cycle, reg_key, actual, expected, mask);
  end else begin
    $display("[TB][PASS] cycle=%0d read %s=0x%08x mask=0x%08x",
             cycle, reg_key, actual, mask);
  end
endtask

function automatic int tb_last_output_cycle(input string out_path);
  int fd;
  int code;
  int last_cycle;
  logic [31:0] cycle_value;
  string line;
  string cycle_raw;
  string t0;
  string t1;
  string t2;
  string t3;
  string t4;
  string t5;
  string t6;
  string t7;

  last_cycle = -1;
  fd = $fopen(out_path, "r");
  if (fd == 0) return -1;

  while (!$feof(fd)) begin
    line = "";
    tb_tokenize9(line, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

    void'($fgets(line, fd));
    tb_tokenize9(line, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

    if (code < 3) continue;
    if (cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#") continue;
    if (!tb_parse_u32(cycle_raw, cycle_value)) continue;

    if (int'(cycle_value) > last_cycle) last_cycle = int'(cycle_value);
  end

  $fclose(fd);
  return last_cycle;
endfunction

task automatic tb_check_outputs(input string out_path, input int cycle);
  int fd;
  int code;
  int expected_cycle;
  logic [31:0] expected_cycle_value;
  string cycle_raw;
  string line;
  string t0;
  string t1;
  string t2;
  string t3;
  string t4;
  string t5;
  string t6;
  string t7;

  fd = $fopen(out_path, "r");
  if (fd == 0) return;

  while (!$feof(fd)) begin
    line = "";
    void'($fgets(line, fd));
    tb_tokenize9(line, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

    if (code < 3) continue;
    if (cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#") continue;
    if (t0.len() > 0 && t0.substr(0, 0) == "#") continue;
    if (!tb_parse_u32(cycle_raw, expected_cycle_value)) continue;

    expected_cycle = int'(expected_cycle_value);
    if (expected_cycle != cycle) continue;

    if (t0 == "@read" || t0 == "read" || t0 == "@reg_read" || t0 == "reg_read") begin
      if (code < 4) begin
        error_count++;
        $display("[TB][ERROR] malformed @read row: %s", line);
      end else begin
        tb_check_read_one(cycle, t1, t2, t3);
      end
      continue;
    end

    tb_check_signal_one(cycle, t0, t1);
    if (code >= 5) tb_check_signal_one(cycle, t2, t3);
    if (code >= 7) tb_check_signal_one(cycle, t4, t5);
    if (code >= 9) tb_check_signal_one(cycle, t6, t7);
  end

  $fclose(fd);
endtask
