// Auto-generated register helper for cordic.
//
// Config format:
//   <REG_OR_ADDR> <DATA> [MASK] [WAIT_CYCLES] [NOTE]
//
// Vector register operations:
//   data_in.vec:  <CYCLE> @write <REG_OR_ADDR> <DATA> [MASK]
//   data_out.vec: <CYCLE> @read  <REG_OR_ADDR> <EXPECTED> [MASK]

function automatic bit tb_cfg_is_dec_char(input byte ch);
  return ch >= 8'h30 && ch <= 8'h39;
endfunction

function automatic bit tb_cfg_is_hex_alpha(input byte ch);
  return (ch >= 8'h41 && ch <= 8'h46) || (ch >= 8'h61 && ch <= 8'h66);
endfunction

function automatic bit tb_cfg_is_all_dec(input string raw);
  int i;
  byte ch;

  if (raw.len() == 0) return 1'b0;

  for (i = 0; i < raw.len(); i++) begin
    ch = raw.getc(i);
    if (!tb_cfg_is_dec_char(ch)) return 1'b0;
  end

  return 1'b1;
endfunction

function automatic bit tb_cfg_is_bare_hex(input string raw);
  int i;
  byte ch;
  bit has_hex_alpha;

  if (raw.len() == 0) return 1'b0;
  has_hex_alpha = 1'b0;

  for (i = 0; i < raw.len(); i++) begin
    ch = raw.getc(i);

    if (tb_cfg_is_dec_char(ch)) begin
      // decimal digit is also legal in hex
    end else if (tb_cfg_is_hex_alpha(ch)) begin
      has_hex_alpha = 1'b1;
    end else begin
      return 1'b0;
    end
  end

  return has_hex_alpha;
endfunction

function automatic bit tb_parse_cfg_u32(input string raw, output logic [31:0] value);
  string s;
  int ok;

  value = '0;
  s = raw;
  ok = 0;

  if (raw.len() > 2 && (raw.substr(0, 1) == "0x" || raw.substr(0, 1) == "0X")) begin
    s = raw.substr(2, raw.len() - 1);
    ok = $sscanf(s, "%h", value);
  end else if (tb_cfg_is_all_dec(raw)) begin
    ok = $sscanf(raw, "%d", value);
  end else if (tb_cfg_is_bare_hex(raw)) begin
    ok = $sscanf(raw, "%h", value);
  end

  if (ok != 1) begin
    $display("[TB][WARN] cannot parse u32 value: %s", raw);
  end

  return ok == 1;
endfunction

function automatic void tb_cfg_tokenize9(
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

    if (tok.len() > 0 && tok.substr(0, 0) == "#") return;
    if (count >= 9) return;
  end
endfunction

function automatic bit tb_lookup_reg_addr(input string reg_key, output logic [31:0] addr);
  case (reg_key)
    "clk_i.CTRL": begin addr = 32'h00000000; return 1'b1; end
    "CTRL": begin addr = 32'h00000000; return 1'b1; end
    "clk_i.STATUS": begin addr = 32'h00000004; return 1'b1; end
    "STATUS": begin addr = 32'h00000004; return 1'b1; end
    "clk_i.X_IN": begin addr = 32'h00000008; return 1'b1; end
    "X_IN": begin addr = 32'h00000008; return 1'b1; end
    "clk_i.Y_IN": begin addr = 32'h0000000c; return 1'b1; end
    "Y_IN": begin addr = 32'h0000000c; return 1'b1; end
    "clk_i.Z_IN": begin addr = 32'h00000010; return 1'b1; end
    "Z_IN": begin addr = 32'h00000010; return 1'b1; end
    "clk_i.X_OUT": begin addr = 32'h00000014; return 1'b1; end
    "X_OUT": begin addr = 32'h00000014; return 1'b1; end
    "clk_i.Y_OUT": begin addr = 32'h00000018; return 1'b1; end
    "Y_OUT": begin addr = 32'h00000018; return 1'b1; end
    "clk_i.Z_OUT": begin addr = 32'h0000001c; return 1'b1; end
    "Z_OUT": begin addr = 32'h0000001c; return 1'b1; end
    "clk_i.CFG": begin addr = 32'h00000020; return 1'b1; end
    "CFG": begin addr = 32'h00000020; return 1'b1; end
    default: begin end
  endcase

  return tb_parse_cfg_u32(reg_key, addr);
endfunction

task automatic tb_reg_write_addr(
  input logic [31:0] addr,
  input logic [31:0] data,
  input logic [31:0] mask
);
  tl_if.tlul_write(addr[31:0], data, 8'h00, mask[3:0]);
  @(posedge clk_i);
endtask

task automatic tb_reg_read_addr(
  input logic [31:0] addr,
  output logic [31:0] data
);
  tl_if.tlul_read(addr[31:0], data, 8'h00);
  @(posedge clk_i);
endtask

task automatic tb_reg_write_key(
  input string reg_key,
  input logic [31:0] data,
  input logic [31:0] mask,
  output bit ok
);
  logic [31:0] addr;

  ok = 1'b0;

  if (!tb_lookup_reg_addr(reg_key, addr)) begin
    $display("[TB][ERROR] unknown register key/address: %s", reg_key);
    error_count++;
    return;
  end

  $display("[TB][REG-WR] %s addr=0x%08x data=0x%08x mask=0x%08x", reg_key, addr, data, mask);
  tb_reg_write_addr(addr, data, mask);
  ok = 1'b1;
endtask

task automatic tb_reg_read_key(
  input string reg_key,
  output logic [31:0] data,
  output bit ok
);
  logic [31:0] addr;

  data = '0;
  ok = 1'b0;

  if (!tb_lookup_reg_addr(reg_key, addr)) begin
    $display("[TB][ERROR] unknown register key/address: %s", reg_key);
    error_count++;
    return;
  end

  tb_reg_read_addr(addr, data);
  $display("[TB][REG-RD] %s addr=0x%08x data=0x%08x", reg_key, addr, data);
  ok = 1'b1;
endtask

task automatic run_reg_config(input string cfg_path);
  int fd;
  int code;
  int writes;
  int wait_cycles;
  logic [31:0] wait_value;
  string line;
  string t0;
  string t1;
  string t2;
  string t3;
  string t4;
  string t5;
  string t6;
  string t7;
  string t8;
  string reg_key;
  string data_raw;
  string mask_raw;
  string wait_raw;
  logic [31:0] data;
  logic [31:0] mask;
  bit ok;

  fd = $fopen(cfg_path, "r");
  if (fd == 0) begin
    $display("[TB] register config not found: %s", cfg_path);
    return;
  end

  writes = 0;
  $display("[TB] applying register config: %s", cfg_path);

  while (!$feof(fd)) begin
    line = "";
    tb_cfg_tokenize9(line, code, t0, t1, t2, t3, t4, t5, t6, t7, t8);

    void'($fgets(line, fd));
    tb_cfg_tokenize9(line, code, t0, t1, t2, t3, t4, t5, t6, t7, t8);

    if (code < 1) continue;
    if (t0.len() > 0 && t0.substr(0, 0) == "#") continue;

    reg_key = "";
    data_raw = "";
    mask_raw = "";
    wait_raw = "";

    if (t0 == "write" || t0 == "@write" || t0 == "reg_write" || t0 == "@reg_write") begin
      if (code < 3) begin
        $display("[TB][WARN] malformed config write row: %s", line);
        continue;
      end

      reg_key = t1;
      data_raw = t2;
      mask_raw = t3;
      wait_raw = t4;
    end else begin
      if (code < 2) begin
        $display("[TB][WARN] malformed config row: %s", line);
        continue;
      end

      reg_key = t0;
      data_raw = t1;
      mask_raw = t2;
      wait_raw = t3;
    end

    if (data_raw.len() > 0 && data_raw.substr(0, 0) == "#") begin
      $display("[TB][WARN] malformed config row: %s", line);
      continue;
    end

    if (!tb_parse_cfg_u32(data_raw, data)) continue;

    if (mask_raw.len() > 0 && mask_raw.substr(0, 0) != "#" && tb_parse_cfg_u32(mask_raw, mask)) begin
      // explicit mask parsed
    end else begin
      mask = 32'hffff_ffff;
    end

    wait_cycles = 1;
    if (wait_raw.len() > 0 && wait_raw.substr(0, 0) != "#" && tb_parse_cfg_u32(wait_raw, wait_value)) begin
      wait_cycles = int'(wait_value);
    end

    tb_reg_write_key(reg_key, data, mask, ok);
    if (ok) writes++;

    repeat (wait_cycles) @(posedge clk_i);
  end

  $fclose(fd);

  if (writes == 0) begin
    $display("[TB] no register config writes from %s; continuing", cfg_path);
  end
endtask
