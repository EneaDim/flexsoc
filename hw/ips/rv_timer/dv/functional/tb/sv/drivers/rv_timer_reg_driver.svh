`ifdef VERILATOR
// Auto-generated register helper for rv_timer.
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
    ch = raw[i];
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
    ch = raw[i];

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

function automatic logic [32:0] tb_parse_cfg_u32(input string raw);
  string s;
  logic [31:0] value;
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

  return {ok == 1, value};
endfunction

task automatic tb_cfg_tokenize9(
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

  begin : tb_cfg_tokenize_done
    while (i < n) begin
      begin : tb_cfg_skip_ws
        while (i < n) begin
          ch = line[i];
          if (!(ch == 8'h20 || ch == 8'h09 || ch == 8'h0a || ch == 8'h0d))
            disable tb_cfg_skip_ws;
          i++;
        end
      end

      if (i >= n) disable tb_cfg_tokenize_done;

      j = i;

      begin : tb_cfg_scan_token
        while (i < n) begin
          ch = line[i];
          if (ch == 8'h20 || ch == 8'h09 || ch == 8'h0a || ch == 8'h0d)
            disable tb_cfg_scan_token;
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

    if (tok.len() > 0 && tok.substr(0, 0) == "#") disable tb_cfg_tokenize_done;
    if (count >= 9) disable tb_cfg_tokenize_done;
    end
  end
endtask

function automatic logic [32:0] tb_lookup_reg_addr(input string reg_key);
  logic [31:0] addr;
  logic [32:0] parsed;
  bit found;

  addr = '0;
  found = 1'b0;
  case (reg_key)
    "clk_i.CTRL": begin addr = 32'h00000000; found = 1'b1; end
    "CTRL": begin addr = 32'h00000000; found = 1'b1; end
    "clk_i.INTR_ENABLE0": begin addr = 32'h00000004; found = 1'b1; end
    "INTR_ENABLE0": begin addr = 32'h00000004; found = 1'b1; end
    "clk_i.INTR_STATE0": begin addr = 32'h00000008; found = 1'b1; end
    "INTR_STATE0": begin addr = 32'h00000008; found = 1'b1; end
    "clk_i.INTR_TEST0": begin addr = 32'h0000000c; found = 1'b1; end
    "INTR_TEST0": begin addr = 32'h0000000c; found = 1'b1; end
    "clk_i.CFG0": begin addr = 32'h00000010; found = 1'b1; end
    "CFG0": begin addr = 32'h00000010; found = 1'b1; end
    "clk_i.TIMER_V0": begin addr = 32'h00000014; found = 1'b1; end
    "TIMER_V0": begin addr = 32'h00000014; found = 1'b1; end
    "clk_i.COMPARE_V0": begin addr = 32'h00000018; found = 1'b1; end
    "COMPARE_V0": begin addr = 32'h00000018; found = 1'b1; end
    default: begin end
  endcase

  if (!found) begin
    parsed = tb_parse_cfg_u32(reg_key);
    found = parsed[32];
    addr = parsed[31:0];
  end

  return {found, addr};
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
  logic [32:0] lookup;

  begin : tb_reg_write_key_body
    ok = 1'b0;
    lookup = tb_lookup_reg_addr(reg_key);

    if (!lookup[32]) begin
      $display("[TB][ERROR] unknown register key/address: %s", reg_key);
      error_count++;
      disable tb_reg_write_key_body;
    end

    addr = lookup[31:0];
    $display("[TB][REG-WR] %s addr=0x%08x data=0x%08x mask=0x%08x", reg_key, addr, data, mask);
    tb_reg_write_addr(addr, data, mask);
    ok = 1'b1;
  end
endtask

task automatic tb_reg_read_key(
  input string reg_key,
  output logic [31:0] data,
  output bit ok
);
  logic [31:0] addr;
  logic [32:0] lookup;

  begin : tb_reg_read_key_body
    data = '0;
    ok = 1'b0;
    lookup = tb_lookup_reg_addr(reg_key);

    if (!lookup[32]) begin
      $display("[TB][ERROR] unknown register key/address: %s", reg_key);
      error_count++;
      disable tb_reg_read_key_body;
    end

    addr = lookup[31:0];
    tb_reg_read_addr(addr, data);
    $display("[TB][REG-RD] %s addr=0x%08x data=0x%08x", reg_key, addr, data);
    ok = 1'b1;
  end
endtask

task automatic run_reg_config(input string cfg_path);
  int fd;
  int code;
  int writes;
  int wait_cycles;
  logic [31:0] wait_value;
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
  string t8;
  string reg_key;
  string data_raw;
  string mask_raw;
  string wait_raw;
  logic [31:0] data;
  logic [31:0] mask;
  logic [32:0] parsed;
  bit ok;

  begin : run_reg_config_body
  fd = $fopen(cfg_path, "r");
  if (fd == 0) begin
    $display("[TB] register config not found: %s", cfg_path);
    disable run_reg_config_body;
  end

  writes = 0;
  $display("[TB] applying register config: %s", cfg_path);

  while (!$feof(fd)) begin : tb_cfg_line_1
    line = "";
    tb_cfg_tokenize9(line, code, t0, t1, t2, t3, t4, t5, t6, t7, t8);

    line_buf = '0;
    void'($fgets(line_buf, fd));
    line = $sformatf("%0s", line_buf);
    tb_cfg_tokenize9(line, code, t0, t1, t2, t3, t4, t5, t6, t7, t8);

    if (code < 1) disable tb_cfg_line_1;
    if (t0.len() > 0 && t0.substr(0, 0) == "#") disable tb_cfg_line_1;

    reg_key = "";
    data_raw = "";
    mask_raw = "";
    wait_raw = "";

    if (t0 == "write" || t0 == "@write" || t0 == "reg_write" || t0 == "@reg_write") begin
      if (code < 3) begin
        $display("[TB][WARN] malformed config write row: %s", line);
        disable tb_cfg_line_1;
      end

      reg_key = t1;
      data_raw = t2;
      mask_raw = t3;
      wait_raw = t4;
    end else begin
      if (code < 2) begin
        $display("[TB][WARN] malformed config row: %s", line);
        disable tb_cfg_line_1;
      end

      reg_key = t0;
      data_raw = t1;
      mask_raw = t2;
      wait_raw = t3;
    end

    if (data_raw.len() > 0 && data_raw.substr(0, 0) == "#") begin
      $display("[TB][WARN] malformed config row: %s", line);
      disable tb_cfg_line_1;
    end

    parsed = tb_parse_cfg_u32(data_raw);
    if (!parsed[32]) disable tb_cfg_line_1;
    data = parsed[31:0];

    parsed = tb_parse_cfg_u32(mask_raw);
    if (mask_raw.len() > 0 && mask_raw.substr(0, 0) != "#" && parsed[32]) begin
      mask = parsed[31:0];
    end else begin
      mask = 32'hffff_ffff;
    end

    wait_cycles = 1;
    parsed = tb_parse_cfg_u32(wait_raw);
    if (wait_raw.len() > 0 && wait_raw.substr(0, 0) != "#" && parsed[32]) begin
      wait_value = parsed[31:0];
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
  end
endtask
`else

localparam integer FLEXSOC_TB_LINE_BYTES = 4096;
localparam integer FLEXSOC_TB_TOKEN_BYTES = 256;
typedef reg [8*FLEXSOC_TB_LINE_BYTES-1:0] tb_line_t;
typedef reg [8*FLEXSOC_TB_TOKEN_BYTES-1:0] tb_token_t;

function automatic bit tb_token_empty(input tb_token_t token);
  return token == '0;
endfunction

function automatic bit tb_token_comment(input tb_token_t token);
  tb_token_t ignored;
  integer matched;
  ignored = '0;
  matched = $sscanf(token, "#%s", ignored);
  return token == "#" || matched == 1;
endfunction

function automatic logic [32:0] tb_parse_u32(input tb_token_t raw);
  logic [31:0] value;
  integer ok;

  value = '0;
  ok = 0;
  if (!tb_token_empty(raw) && !tb_token_comment(raw)) begin
    ok = $sscanf(raw, "0x%h", value);
    if (ok != 1) ok = $sscanf(raw, "0X%h", value);
    if (ok != 1) ok = $sscanf(raw, "%d", value);
    if (ok != 1) ok = $sscanf(raw, "%h", value);
  end
  return {ok == 1, value};
endfunction

task automatic tb_tokenize9(
  input tb_line_t line,
  output integer count,
  output tb_token_t w0,
  output tb_token_t w1,
  output tb_token_t w2,
  output tb_token_t w3,
  output tb_token_t w4,
  output tb_token_t w5,
  output tb_token_t w6,
  output tb_token_t w7,
  output tb_token_t w8
);
  w0 = '0; w1 = '0; w2 = '0; w3 = '0; w4 = '0;
  w5 = '0; w6 = '0; w7 = '0; w8 = '0;
  count = $sscanf(line, "%s %s %s %s %s %s %s %s %s",
                  w0, w1, w2, w3, w4, w5, w6, w7, w8);
  if (count < 0) count = 0;
endtask

// Auto-generated register helper for rv_timer.
//
// Config format:
//   <REG_OR_ADDR> <DATA> [MASK] [WAIT_CYCLES] [NOTE]
//
// Vector register operations:
//   data_in.vec:  <CYCLE> @write <REG_OR_ADDR> <DATA> [MASK]
//   data_out.vec: <CYCLE> @read  <REG_OR_ADDR> <EXPECTED> [MASK]

function automatic logic [32:0] tb_parse_cfg_u32(input tb_token_t raw);
  return tb_parse_u32(raw);
endfunction

function automatic logic [32:0] tb_lookup_reg_addr(input tb_token_t reg_key);
  logic [31:0] addr;
  logic [32:0] parsed;
  bit found;

  addr = '0;
  found = 1'b0;
  case (reg_key)
    "clk_i.CTRL": begin addr = 32'h00000000; found = 1'b1; end
    "CTRL": begin addr = 32'h00000000; found = 1'b1; end
    "clk_i.INTR_ENABLE0": begin addr = 32'h00000004; found = 1'b1; end
    "INTR_ENABLE0": begin addr = 32'h00000004; found = 1'b1; end
    "clk_i.INTR_STATE0": begin addr = 32'h00000008; found = 1'b1; end
    "INTR_STATE0": begin addr = 32'h00000008; found = 1'b1; end
    "clk_i.INTR_TEST0": begin addr = 32'h0000000c; found = 1'b1; end
    "INTR_TEST0": begin addr = 32'h0000000c; found = 1'b1; end
    "clk_i.CFG0": begin addr = 32'h00000010; found = 1'b1; end
    "CFG0": begin addr = 32'h00000010; found = 1'b1; end
    "clk_i.TIMER_V0": begin addr = 32'h00000014; found = 1'b1; end
    "TIMER_V0": begin addr = 32'h00000014; found = 1'b1; end
    "clk_i.COMPARE_V0": begin addr = 32'h00000018; found = 1'b1; end
    "COMPARE_V0": begin addr = 32'h00000018; found = 1'b1; end
    default: begin end
  endcase

  if (!found) begin
    parsed = tb_parse_cfg_u32(reg_key);
    found = parsed[32];
    addr = parsed[31:0];
  end

  return {found, addr};
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
  input tb_token_t reg_key,
  input logic [31:0] data,
  input logic [31:0] mask,
  output bit ok
);
  logic [31:0] addr;
  logic [32:0] lookup;

  begin : tb_reg_write_key_body
    ok = 1'b0;
    lookup = tb_lookup_reg_addr(reg_key);

    if (!lookup[32]) begin
      $display("[TB][ERROR] unknown register key/address: %s", reg_key);
      error_count++;
      disable tb_reg_write_key_body;
    end

    addr = lookup[31:0];
    $display("[TB][REG-WR] %s addr=0x%08x data=0x%08x mask=0x%08x", reg_key, addr, data, mask);
    tb_reg_write_addr(addr, data, mask);
    ok = 1'b1;
  end
endtask

task automatic tb_reg_read_key(
  input tb_token_t reg_key,
  output logic [31:0] data,
  output bit ok
);
  logic [31:0] addr;
  logic [32:0] lookup;

  begin : tb_reg_read_key_body
    data = '0;
    ok = 1'b0;
    lookup = tb_lookup_reg_addr(reg_key);

    if (!lookup[32]) begin
      $display("[TB][ERROR] unknown register key/address: %s", reg_key);
      error_count++;
      disable tb_reg_read_key_body;
    end

    addr = lookup[31:0];
    tb_reg_read_addr(addr, data);
    $display("[TB][REG-RD] %s addr=0x%08x data=0x%08x", reg_key, addr, data);
    ok = 1'b1;
  end
endtask

task automatic run_reg_config(input string cfg_path);
  int fd;
  int code;
  int writes;
  int wait_cycles;
  logic [31:0] wait_value;
  tb_line_t line_buf;
  tb_token_t t0;
  tb_token_t t1;
  tb_token_t t2;
  tb_token_t t3;
  tb_token_t t4;
  tb_token_t t5;
  tb_token_t t6;
  tb_token_t t7;
  tb_token_t t8;
  tb_token_t reg_key;
  tb_token_t data_raw;
  tb_token_t mask_raw;
  tb_token_t wait_raw;
  logic [31:0] data;
  logic [31:0] mask;
  logic [32:0] parsed;
  bit ok;

  begin : run_reg_config_body
  fd = $fopen(cfg_path, "r");
  if (fd == 0) begin
    $display("[TB] register config not found: %s", cfg_path);
    disable run_reg_config_body;
  end

  writes = 0;
  $display("[TB] applying register config: %s", cfg_path);

  while (!$feof(fd)) begin : tb_cfg_line_1
    line_buf = '0;
    code = $fgets(line_buf, fd);
    tb_tokenize9(line_buf, code, t0, t1, t2, t3, t4, t5, t6, t7, t8);

    if (code < 1) disable tb_cfg_line_1;
    if (tb_token_comment(t0)) disable tb_cfg_line_1;

    reg_key = "";
    data_raw = "";
    mask_raw = "";
    wait_raw = "";

    if (t0 == "write" || t0 == "@write" || t0 == "reg_write" || t0 == "@reg_write") begin
      if (code < 3) begin
        $display("[TB][WARN] malformed config write row: %0s", line_buf);
        disable tb_cfg_line_1;
      end

      reg_key = t1;
      data_raw = t2;
      mask_raw = t3;
      wait_raw = t4;
    end else begin
      if (code < 2) begin
        $display("[TB][WARN] malformed config row: %0s", line_buf);
        disable tb_cfg_line_1;
      end

      reg_key = t0;
      data_raw = t1;
      mask_raw = t2;
      wait_raw = t3;
    end

    if (tb_token_comment(data_raw)) begin
      $display("[TB][WARN] malformed config row: %0s", line_buf);
      disable tb_cfg_line_1;
    end

    parsed = tb_parse_cfg_u32(data_raw);
    if (!parsed[32]) disable tb_cfg_line_1;
    data = parsed[31:0];

    parsed = tb_parse_cfg_u32(mask_raw);
    if (!tb_token_empty(mask_raw) && !tb_token_comment(mask_raw) && parsed[32]) begin
      mask = parsed[31:0];
    end else begin
      mask = 32'hffff_ffff;
    end

    wait_cycles = 1;
    parsed = tb_parse_cfg_u32(wait_raw);
    if (!tb_token_empty(wait_raw) && !tb_token_comment(wait_raw) && parsed[32]) begin
      wait_value = parsed[31:0];
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
  end
endtask
`endif
