"""SystemVerilog and cocotb testbench scaffold generation."""

from __future__ import annotations

import re
from dataclasses import dataclass, replace
from pathlib import Path
from textwrap import dedent
from typing import Any, Sequence

from flexsoc.backend.core import ClockConfig, clock_config
from .functional import (
    TEST_NAMES, _candidate_hjson_path, _register_entries, _register_lookup_entries,
    _vector_inputs, _vector_outputs,
)

from flexsoc.backend.core import (
    ensure_dir,
    has_reg_pkg,
    parse_sv_signature,
    replace_generated_tree,
    safe_write_file,
)


def _render_sv_reg_sequence_string(
    top: str,
    interface: str,
    clk: str,
    *,
    active: bool,
    registers: Sequence[dict[str, Any]] = (),
) -> str:
    """Render generic SystemVerilog register helpers."""

    if not active:
        return f"""// Auto-generated register helper for {top}.
// This DUT has no generated register bus helper in the current testbench.
function automatic logic [32:0] tb_lookup_reg_addr(input string reg_key);
  return 33'b0;
endfunction

function automatic logic [32:0] tb_parse_cfg_u32(input string raw);
  logic [31:0] value;
  int ok;
  value = '0;
  ok = $sscanf(raw, "%d", value);
  return {{ok == 1, value}};
endfunction

task automatic tb_reg_write_key(
  input string reg_key,
  input logic [31:0] data,
  input logic [31:0] mask,
  output bit ok
);
  ok = 1'b0;
  $display("[TB][ERROR] register write requested but no register bus is active: %s", reg_key);
  error_count++;
endtask

task automatic tb_reg_read_key(
  input string reg_key,
  output logic [31:0] data,
  output bit ok
);
  data = '0;
  ok = 1'b0;
  $display("[TB][ERROR] register read requested but no register bus is active: %s", reg_key);
  error_count++;
endtask

task automatic run_reg_config(input string cfg_path);
  $display("[TB] register config skipped: %s", cfg_path);
endtask
"""

    write_addr_call = (
        "tl_if.tlul_write(addr[31:0], data, 8'h00, mask[3:0]);"
        if interface == "tlul"
        else f"reg_utils_inst.write(addr[{top}_reg_pkg::AW-1:0], data, mask[{top}_reg_pkg::DBW-1:0]);"
    )
    read_addr_call = (
        "tl_if.tlul_read(addr[31:0], data, 8'h00);"
        if interface == "tlul"
        else f"reg_utils_inst.read(addr[{top}_reg_pkg::AW-1:0], data);"
    )

    cases: list[str] = []
    seen: set[str] = set()
    for reg in registers:
        addr = int(reg["addr"]) & 0xFFFFFFFF
        names = [
            str(reg.get("key", "")),
            str(reg.get("name", "")),
            str(reg.get("name", "")).upper(),
        ]
        for key in names:
            if not key or key in seen:
                continue
            seen.add(key)
            cases.append(f'    "{key}": begin addr = 32\'h{addr:08x}; found = 1\'b1; end')

    cases.append("    default: begin end")
    addr_cases = "\n".join(cases)

    return f"""// Auto-generated register helper for {top}.
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

  return {{ok == 1, value}};
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
{addr_cases}
  endcase

  if (!found) begin
    parsed = tb_parse_cfg_u32(reg_key);
    found = parsed[32];
    addr = parsed[31:0];
  end

  return {{found, addr}};
endfunction

task automatic tb_reg_write_addr(
  input logic [31:0] addr,
  input logic [31:0] data,
  input logic [31:0] mask
);
  {write_addr_call}
  @(posedge {clk});
endtask

task automatic tb_reg_read_addr(
  input logic [31:0] addr,
  output logic [31:0] data
);
  {read_addr_call}
  @(posedge {clk});
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

    repeat (wait_cycles) @(posedge {clk});
  end

  $fclose(fd);

  if (writes == 0) begin
    $display("[TB] no register config writes from %s; continuing", cfg_path);
  end
  end
endtask
"""

def _sv_output_expr(name: str) -> str:
    """Return the 32-bit SystemVerilog expression used to compare one output."""

    if name.startswith("valid") and name.endswith("_o"):
        return "{31'b0, " + name + "}"
    return name


TOKENIZER = r"""
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
"""

def _render_sv_vec_monitor_string(top: str, outputs: Sequence[str]) -> str:
    """Render generic expected-output checks from data_out.vec."""

    checks = ["  if (1'b0) begin\n    known = 1'b0;\n  end"]
    for name in outputs:
        checks.append(
            f'  else if (name == "{name}") begin\n'
            f"    actual = {_sv_output_expr(name)};\n"
            "    known = 1'b1;\n"
            "  end"
        )
    checks_text = "\n".join(checks)

    return f"""// Auto-generated vector monitor for {top}.
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

  return {{ok == 1, value}};
endfunction
{TOKENIZER}
function automatic logic [32:0] tb_read_output(input string name);
  logic [31:0] actual;
  bit known;

  actual = '0;
  known = 1'b0;

{checks_text}
  else begin
    known = 1'b0;
  end

  return {{known, actual}};
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
      error_count++;
      $display("[TB][ERROR] unknown expected-output vector signal: %s", name);
      disable tb_check_signal_one_body;
    end
    actual = sampled[31:0];

    if (actual !== expected) begin
      error_count++;
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
  bit ok;

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

    tb_reg_read_key(reg_key, actual, ok);
    if (!ok) disable tb_check_read_one_body;

    if ((actual & mask) !== (expected & mask)) begin
      error_count++;
      $display("[TB][FAIL] cycle=%0d read %s actual=0x%08x expected=0x%08x mask=0x%08x",
               cycle, reg_key, actual, expected, mask);
    end else begin
      $display("[TB][PASS] cycle=%0d read %s=0x%08x mask=0x%08x",
               cycle, reg_key, actual, mask);
    end
  end
endtask

task automatic tb_last_output_cycle(input string out_path, output int last_cycle);
  int fd;
  int code;
  logic [31:0] cycle_value;
  logic [32:0] parsed;
  logic [32:0] sampled;
  string line;
  reg [8*4096-1:0] line_buf;
  string cycle_raw;
  string t0;
  string t1;
  string t2;
  string t3;
  string t4;
  string t5;
  string t6;
  string t7;

  begin : tb_last_output_cycle_body
  last_cycle = -1;
  fd = $fopen(out_path, "r");
  if (fd == 0) disable tb_last_output_cycle_body;

  while (!$feof(fd)) begin : tb_last_cycle_line
    line = "";
    tb_tokenize9(line, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

    line_buf = '0;
    void'($fgets(line_buf, fd));
    line = $sformatf("%0s", line_buf);
    tb_tokenize9(line, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

    if (code < 3) disable tb_last_cycle_line;
    if (cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#") disable tb_last_cycle_line;

    sampled = tb_read_output(cycle_raw);
    if (sampled[32]) disable tb_last_cycle_line;
    parsed = tb_parse_u32(cycle_raw);
    if (!parsed[32]) disable tb_last_cycle_line;
    cycle_value = parsed[31:0];

    if (int'(cycle_value) > last_cycle) last_cycle = int'(cycle_value);
  end

  $fclose(fd);
  end
endtask

task automatic tb_guarded_output_count(input string out_path, output int count);
  int fd;
  int code;
  logic [32:0] sampled;
  string line;
  reg [8*4096-1:0] line_buf;
  string first;
  string t0;
  string t1;
  string t2;
  string t3;
  string t4;
  string t5;
  string t6;
  string t7;

  begin : tb_guarded_output_count_body
  count = 0;
  fd = $fopen(out_path, "r");
  if (fd == 0) disable tb_guarded_output_count_body;

  while (!$feof(fd)) begin : tb_guard_count_line
    line = "";
    line_buf = '0;
    void'($fgets(line_buf, fd));
    line = $sformatf("%0s", line_buf);
    tb_tokenize9(line, code, first, t0, t1, t2, t3, t4, t5, t6, t7);
    if (code < 3) disable tb_guard_count_line;
    if (first.len() > 0 && first.substr(0, 0) == "#") disable tb_guard_count_line;
    sampled = tb_read_output(first);
    if (sampled[32]) count++;
  end

  $fclose(fd);
  end
endtask

task automatic tb_check_outputs(input string out_path, input int cycle);
  int fd;
  int code;
  int expected_cycle;
  int guarded_index;
  logic [31:0] expected_cycle_value;
  logic [32:0] parsed;
  logic [32:0] sampled;
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

  begin : tb_check_outputs_body
  fd = $fopen(out_path, "r");
  if (fd == 0) disable tb_check_outputs_body;
  guarded_index = 0;

  while (!$feof(fd)) begin : tb_check_output_line
    line = "";
    line_buf = '0;
    void'($fgets(line_buf, fd));
    line = $sformatf("%0s", line_buf);
    tb_tokenize9(line, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

    if (code < 3) disable tb_check_output_line;
    if (cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#") disable tb_check_output_line;
    if (t0.len() > 0 && t0.substr(0, 0) == "#") disable tb_check_output_line;

    sampled = tb_read_output(cycle_raw);
    if (sampled[32]) begin
      if (guarded_index == tb_guarded_output_next && sampled[0] === 1'b1) begin
        tb_check_signal_one(cycle, t0, t1);
        if (code >= 5) tb_check_signal_one(cycle, t2, t3);
        if (code >= 7) tb_check_signal_one(cycle, t4, t5);
        if (code >= 9) tb_check_signal_one(cycle, t6, t7);
        tb_guarded_output_next++;
      end
      guarded_index++;
      disable tb_check_output_line;
    end

    parsed = tb_parse_u32(cycle_raw);
    if (!parsed[32]) disable tb_check_output_line;
    expected_cycle_value = parsed[31:0];

    expected_cycle = int'(expected_cycle_value);
    if (expected_cycle != cycle) disable tb_check_output_line;

    if (t0 == "@read" || t0 == "read" || t0 == "@reg_read" || t0 == "reg_read") begin
      if (code < 4) begin
        error_count++;
        $display("[TB][ERROR] malformed @read row: %s", line);
      end else begin
        tb_check_read_one(cycle, t1, t2, t3);
      end
      disable tb_check_output_line;
    end

    tb_check_signal_one(cycle, t0, t1);
    if (code >= 5) tb_check_signal_one(cycle, t2, t3);
    if (code >= 7) tb_check_signal_one(cycle, t4, t5);
    if (code >= 9) tb_check_signal_one(cycle, t6, t7);
  end

  $fclose(fd);
  end
endtask
"""

def _sv_input_default(name: str) -> str:
    """Return the reset-time default for a generated top-level input."""

    return "'1" if name.lower() in {"cio_rx_i", "uart_rx_i", "serial_rx_i"} else "'0"


def _render_sv_vec_driver_string(
    top: str,
    clk: str,
    rst: str,
    inputs: Sequence[str],
    outputs: Sequence[str],
    reset_polarity: str = "low",
    reset_domain: str = "core",
) -> str:
    """Render generic input-vector drive tasks from data_in.vec."""

    drives = ["  if (1'b0) begin\n    tb_vector_apply_count = tb_vector_apply_count;\n  end"]
    for name in inputs:
        drives.append(
            f'  else if (name == "{name}") begin\n'
            f"    {name} = value;\n"
            "    tb_vector_apply_count++;\n"
            f'    $display("[TB][DRV] {name} <= 0x%08h", value);\n'
            "  end"
        )
    drives_text = "\n".join(drives)
    reset_defaults = "\n".join(f"  {name} = {_sv_input_default(name)};" for name in inputs)
    reset_asserted = "1'b1" if reset_polarity == "high" else "1'b0"
    reset_released = "1'b0" if reset_polarity == "high" else "1'b1"

    return f"""// Auto-generated vector driver for {top}.
// data_in.vec supports signal drives, @write, @cfg, and @reset.

int tb_vector_apply_count;

task automatic tb_drive_input(input string name, input logic [31:0] value);
{drives_text}
  else begin
    error_count++;
    $display("[TB][ERROR] unknown input vector signal: %s", name);
  end
endtask

task automatic tb_drive_raw(input string name, input string raw);
  logic [31:0] value;
  logic [32:0] parsed;

  begin : tb_drive_raw_body
    if (name == "") disable tb_drive_raw_body;
    parsed = tb_parse_u32(raw);
    if (!parsed[32]) disable tb_drive_raw_body;
    value = parsed[31:0];
    tb_drive_input(name, value);
  end
endtask

task automatic tb_apply_reg_write(input string reg_key, input string data_raw, input string mask_raw);
  logic [31:0] data;
  logic [31:0] mask;
  logic [32:0] parsed;
  bit ok;

  begin : tb_apply_reg_write_body
    parsed = tb_parse_u32(data_raw);
    if (!parsed[32]) disable tb_apply_reg_write_body;
    data = parsed[31:0];

    parsed = tb_parse_u32(mask_raw);
    if (mask_raw.len() > 0 && parsed[32]) begin
      mask = parsed[31:0];
    end else begin
      mask = 32'hffff_ffff;
    end

    tb_reg_write_key(reg_key, data, mask, ok);
    if (ok) tb_vector_apply_count++;
  end
endtask

task automatic tb_step(input string data_out_path, inout int now_cycle);
  @(posedge {clk}); #1;
  now_cycle++;
  tb_check_outputs(data_out_path, now_cycle);
endtask

task automatic tb_apply_reset(
  input string selector,
  input int cycles,
  input string data_out_path,
  inout int now_cycle
);
  int i;
  bit selected;
{reset_defaults}
  selected = (selector == "" || selector == "all" || selector == "*" ||
              selector == "{reset_domain}" || selector == "{rst}");
  if (!selected) begin
    error_count++;
    $display("[TB][ERROR] unknown reset selector: %s", selector);
  end else begin
    {rst} = {reset_asserted};
    for (i = 0; i < cycles; i++) tb_step(data_out_path, now_cycle);
    @(negedge {clk}); #1;
    {rst} = {reset_released};
    tb_vector_apply_count++;
  end
endtask

task automatic tb_finish_cycle(input string data_out_path, inout int now_cycle, inout bit cycle_open);
  if (cycle_open) begin
    tb_step(data_out_path, now_cycle);
    cycle_open = 1'b0;
  end
endtask

task automatic tb_wait_before_drive(input int target_cycle, input string data_out_path, inout int now_cycle);
  while (now_cycle < target_cycle - 1) begin
    tb_step(data_out_path, now_cycle);
  end
  @(negedge {clk}); #1;
endtask

task automatic tb_drive_signal_pairs(
  input int code,
  input string t0,
  input string t1,
  input string t2,
  input string t3,
  input string t4,
  input string t5,
  input string t6,
  input string t7
);
  tb_drive_raw(t0, t1);
  if (code >= 5) tb_drive_raw(t2, t3);
  if (code >= 7) tb_drive_raw(t4, t5);
  if (code >= 9) tb_drive_raw(t6, t7);
endtask

task automatic run_vectors(input string data_in_path, input string data_out_path);
  int fd;
  int code;
  int cycle;
  int final_cycle;
  int now_cycle;
  int current_cycle;
  int apply_start;
  int guarded_total;
  int guarded_deadline;
  bit cycle_open;
  logic [31:0] cycle_value;
  logic [31:0] reset_cycles;
  logic [32:0] parsed;
  string cycle_raw;
  string reset_selector;
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

  now_cycle = -1;
  current_cycle = -1;
  cycle_open = 1'b0;
  apply_start = tb_vector_apply_count;
  tb_guarded_output_next = 0;
  tb_last_output_cycle(data_out_path, final_cycle);
  tb_guarded_output_count(data_out_path, guarded_total);

  begin : run_vectors_body
  fd = $fopen(data_in_path, "r");
  if (fd == 0) begin
    $display("[TB][ERROR] input vector file not found: %s", data_in_path);
    error_count++;
    disable run_vectors_body;
  end

  $display("[TB] running vectors: in=%s out=%s", data_in_path, data_out_path);

  while (!$feof(fd)) begin : tb_input_line
    line = "";
    line_buf = '0;
    void'($fgets(line_buf, fd));
    line = $sformatf("%0s", line_buf);
    tb_tokenize9(line, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

    if (code < 3) disable tb_input_line;
    if (cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#") disable tb_input_line;
    if (t0.len() > 0 && t0.substr(0, 0) == "#") disable tb_input_line;
    parsed = tb_parse_u32(cycle_raw);
    if (!parsed[32]) disable tb_input_line;
    cycle_value = parsed[31:0];

    cycle = int'(cycle_value);

    if (t0 == "@cfg" || t0 == "cfg" || t0 == "@config" || t0 == "config") begin
      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      $display("[TB][CFG] cycle=%0d path=%s", cycle, t1);
      run_reg_config(t1);
      tb_vector_apply_count++;
      disable tb_input_line;
    end

    if (t0 == "@reset" || t0 == "reset") begin
      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      if (code >= 4) begin
        parsed = tb_parse_u32(t2);
      end else begin
        parsed = tb_parse_u32(t1);
      end
      reset_cycles = parsed[32] ? parsed[31:0] : 32'd2;
      if (reset_cycles == 0) reset_cycles = 2;
      reset_selector = code >= 4 ? t1 : "all";
      $display(
        "[TB][RESET] cycle=%0d selector=%s cycles=%0d",
        cycle, reset_selector, reset_cycles
      );
      tb_apply_reset(reset_selector, int'(reset_cycles), data_out_path, now_cycle);
      disable tb_input_line;
    end

    if (t0 == "@write" || t0 == "write" || t0 == "@reg_write" || t0 == "reg_write") begin
      if (code < 4) begin
        error_count++;
        $display("[TB][ERROR] malformed @write row: %s", line);
        disable tb_input_line;
      end

      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      $display("[TB][VEC-WR] cycle=%0d reg=%s", cycle, t1);
      tb_apply_reg_write(t1, t2, t3);
      disable tb_input_line;
    end

    if ((code - 1) % 2 != 0) begin
      error_count++;
      $display("[TB][ERROR] malformed signal vector row: %s", line);
      disable tb_input_line;
    end

    if (!cycle_open || cycle != current_cycle) begin
      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = cycle;
      cycle_open = 1'b1;
      $display("[TB][VEC] cycle=%0d", cycle);
    end

    tb_drive_signal_pairs(code, t0, t1, t2, t3, t4, t5, t6, t7);
  end

  $fclose(fd);

  tb_finish_cycle(data_out_path, now_cycle, cycle_open);

  if (final_cycle < now_cycle + 8) begin
    final_cycle = now_cycle + 8;
  end
  guarded_deadline = now_cycle + 4096;

  while ((now_cycle < final_cycle || tb_guarded_output_next < guarded_total) &&
         now_cycle < guarded_deadline) begin
    tb_step(data_out_path, now_cycle);
  end
  if (tb_guarded_output_next < guarded_total) begin
    error_count++;
    $display("[TB][ERROR] timed out waiting for guarded output row %0d/%0d",
             tb_guarded_output_next + 1, guarded_total);
  end

  if (tb_vector_apply_count == apply_start) begin
    error_count++;
    $display("[TB][ERROR] no vector inputs or register writes were applied from %s", data_in_path);
  end
  end
endtask
"""


# Keep paths as strings, but parse file contents through packed vectors.
# This avoids unreliable automatic-string coercion in older Icarus builds.
_STRING_RENDER_SV_REG_SEQUENCE = _render_sv_reg_sequence_string
_STRING_RENDER_SV_VEC_MONITOR = _render_sv_vec_monitor_string
_STRING_RENDER_SV_VEC_DRIVER = _render_sv_vec_driver_string

_PACKED_TOKEN_SUPPORT = r"""
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
"""


def _drop_sv_span(text: str, start: str, end: str) -> str:
    """Drop one generated SV span, retaining the end marker."""

    begin = text.find(start)
    if begin < 0:
        return text
    finish = text.find(end, begin)
    if finish < 0:
        raise RuntimeError(f"cannot locate generated SV marker: {end}")
    return text[:begin] + text[finish:]


def _packed_reg_sequence(text: str) -> str:
    text = _drop_sv_span(
        text,
        "function automatic bit tb_cfg_is_dec_char",
        "function automatic logic [32:0] tb_lookup_reg_addr",
    )
    text = _PACKED_TOKEN_SUPPORT + "\n" + text
    text = text.replace(
        "function automatic logic [32:0] tb_parse_cfg_u32(input string raw);",
        "function automatic logic [32:0] tb_parse_cfg_u32(input tb_token_t raw);",
    )
    # The active implementation was removed with the legacy string parser.
    if "function automatic logic [32:0] tb_parse_cfg_u32" not in text:
        anchor = "function automatic logic [32:0] tb_lookup_reg_addr"
        text = text.replace(
            anchor,
            "function automatic logic [32:0] tb_parse_cfg_u32(input tb_token_t raw);\n"
            "  return tb_parse_u32(raw);\n"
            "endfunction\n\n" + anchor,
            1,
        )
    else:
        start = text.find("function automatic logic [32:0] tb_parse_cfg_u32")
        end = text.find("endfunction", start) + len("endfunction")
        text = text[:start] + (
            "function automatic logic [32:0] tb_parse_cfg_u32(input tb_token_t raw);\n"
            "  return tb_parse_u32(raw);\n"
            "endfunction"
        ) + text[end:]

    text = text.replace("input string reg_key", "input tb_token_t reg_key")
    text = text.replace("  string line;\n", "")
    text = text.replace("  reg [8*4096-1:0] line_buf;", "  tb_line_t line_buf;")
    for name in ("t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "t8",
                 "reg_key", "data_raw", "mask_raw", "wait_raw"):
        text = text.replace(f"  string {name};", f"  tb_token_t {name};")
    text = text.replace("tb_cfg_tokenize9", "tb_tokenize9")
    text = text.replace(
        "    line = \"\";\n    tb_tokenize9(line, code, t0, t1, t2, t3, t4, t5, t6, t7, t8);\n\n",
        "",
    )
    text = text.replace("    void'($fgets(line_buf, fd));\n    line = $sformatf(\"%0s\", line_buf);",
                        "    code = $fgets(line_buf, fd);")
    text = text.replace("tb_tokenize9(line,", "tb_tokenize9(line_buf,")
    text = text.replace('t0.len() > 0 && t0.substr(0, 0) == "#"', "tb_token_comment(t0)")
    text = text.replace('data_raw.len() > 0 && data_raw.substr(0, 0) == "#"', "tb_token_comment(data_raw)")
    text = text.replace('mask_raw.len() > 0 && mask_raw.substr(0, 0) != "#"',
                        "!tb_token_empty(mask_raw) && !tb_token_comment(mask_raw)")
    text = text.replace('wait_raw.len() > 0 && wait_raw.substr(0, 0) != "#"',
                        "!tb_token_empty(wait_raw) && !tb_token_comment(wait_raw)")
    text = text.replace("malformed config write row: %s\", line", "malformed config write row: %0s\", line_buf")
    text = text.replace("malformed config row: %s\", line", "malformed config row: %0s\", line_buf")
    return text


def _sv_parser_variants(verilator: str, icarus: str) -> str:
    """Select the native string parser for Verilator and packed tokens for Icarus."""

    return (
        "`ifdef VERILATOR\n"
        + verilator.rstrip()
        + "\n`else\n"
        + icarus.rstrip()
        + "\n`endif\n"
    )


def render_sv_reg_sequence(
    top: str,
    interface: str,
    clk: str,
    *,
    active: bool,
    registers: Sequence[dict[str, Any]] = (),
) -> str:
    string_parser = _STRING_RENDER_SV_REG_SEQUENCE(
        top, interface, clk, active=active, registers=registers
    )
    return _sv_parser_variants(string_parser, _packed_reg_sequence(string_parser))


def _packed_vec_monitor(text: str) -> str:
    text = _drop_sv_span(
        text,
        "function automatic bit tb_vec_is_dec_char",
        "function automatic logic [32:0] tb_read_output",
    )
    text = text.replace("input string name", "input tb_token_t name")
    text = text.replace("input string raw", "input tb_token_t raw")
    text = text.replace("input string reg_key", "input tb_token_t reg_key")
    text = text.replace("input string expected_raw", "input tb_token_t expected_raw")
    text = text.replace("input string mask_raw", "input tb_token_t mask_raw")
    text = text.replace("  string line;\n", "")
    text = text.replace("  reg [8*4096-1:0] line_buf;", "  tb_line_t line_buf;")
    for name in ("cycle_raw", "first", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"):
        text = text.replace(f"  string {name};", f"  tb_token_t {name};")
    text = text.replace("    line = \"\";\n", "")
    text = text.replace("    void'($fgets(line_buf, fd));\n    line = $sformatf(\"%0s\", line_buf);",
                        "    code = $fgets(line_buf, fd);")
    text = text.replace("tb_tokenize9(line,", "tb_tokenize9(line_buf,")
    text = text.replace(
        "    tb_tokenize9(line_buf, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);\n\n"
        "    line_buf = '0;",
        "    line_buf = '0;",
    )
    text = text.replace('name == ""', "tb_token_empty(name)")
    text = text.replace('mask_raw.len() > 0', "!tb_token_empty(mask_raw)")
    text = text.replace('cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#"',
                        "tb_token_comment(cycle_raw)")
    text = text.replace('first.len() > 0 && first.substr(0, 0) == "#"',
                        "tb_token_comment(first)")
    text = text.replace('t0.len() > 0 && t0.substr(0, 0) == "#"', "tb_token_comment(t0)")
    text = text.replace("malformed @read row: %s\", line", "malformed @read row: %0s\", line_buf")
    return text


def render_sv_vec_monitor(top: str, outputs: Sequence[str]) -> str:
    string_parser = _STRING_RENDER_SV_VEC_MONITOR(top, outputs)
    return _sv_parser_variants(string_parser, _packed_vec_monitor(string_parser))


def _packed_vec_driver(text: str) -> str:
    text = text.replace("input string name", "input tb_token_t name")
    text = text.replace("input string raw", "input tb_token_t raw")
    text = text.replace("input string reg_key", "input tb_token_t reg_key")
    text = text.replace("input string data_raw", "input tb_token_t data_raw")
    text = text.replace("input string mask_raw", "input tb_token_t mask_raw")
    text = text.replace("input string selector", "input tb_token_t selector")
    for name in ("t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"):
        text = text.replace(f"  input string {name}", f"  input tb_token_t {name}")
    text = text.replace("  string line;\n", "")
    text = text.replace("  reg [8*4096-1:0] line_buf;", "  tb_line_t line_buf;")
    for name in (
        "cycle_raw", "reset_selector", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"
    ):
        text = text.replace(f"  string {name};", f"  tb_token_t {name};")
    text = text.replace("    line = \"\";\n", "")
    text = text.replace("    void'($fgets(line_buf, fd));\n    line = $sformatf(\"%0s\", line_buf);",
                        "    code = $fgets(line_buf, fd);")
    text = text.replace("tb_tokenize9(line,", "tb_tokenize9(line_buf,")
    text = text.replace('name == ""', "tb_token_empty(name)")
    text = text.replace('mask_raw.len() > 0', "!tb_token_empty(mask_raw)")
    text = text.replace('cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#"',
                        "tb_token_comment(cycle_raw)")
    text = text.replace('t0.len() > 0 && t0.substr(0, 0) == "#"', "tb_token_comment(t0)")
    text = text.replace("malformed @write row: %s\", line", "malformed @write row: %0s\", line_buf")
    text = text.replace("malformed signal vector row: %s\", line", "malformed signal vector row: %0s\", line_buf")
    return text


def render_sv_vec_driver(
    top: str,
    clk: str,
    rst: str,
    inputs: Sequence[str],
    outputs: Sequence[str],
    reset_polarity: str = "low",
    reset_domain: str = "core",
) -> str:
    string_parser = _STRING_RENDER_SV_VEC_DRIVER(
        top, clk, rst, inputs, outputs, reset_polarity, reset_domain
    )
    return _sv_parser_variants(string_parser, _packed_vec_driver(string_parser))

def _simple_datapath_ports(sig: dict[str, Any]) -> tuple[list[str], list[str]]:
    """Return generic data ports detected on the DUT."""

    return _vector_inputs(sig), _vector_outputs(sig)


def _has_simple_datapath(sig: dict[str, Any]) -> bool:
    """Return true when generated vector drive/check helpers are meaningful."""

    inputs, outputs = _simple_datapath_ports(sig)
    return bool(inputs and outputs)


def _render_no_vector_task(top: str) -> str:
    """Render the inline no-op used when no generic datapath exists."""

    return f'''  // No generic data input/output ports were detected for {top}.
  // Register config still runs; add an IP-specific checker for datapath checks.
  // Main vector runner used by the generated testbench.
task automatic run_vectors(input string data_in_path, input string data_out_path);
    $display("[TB] vector check skipped for this DUT: %s %s", data_in_path, data_out_path);
  endtask
'''


def write_sv_verification_helpers(
    outdir: str | Path,
    top: str,
    interface: str,
    sig: dict[str, Any],
    *,
    hjson_path: Path | None = None,
    bus_active: bool,
    force: bool,
    reset_polarity: str = "low",
    reset_domain: str = "core",
) -> list[Path]:
    """Write SystemVerilog driver/monitor/config helper include files."""

    out = Path(outdir)
    ensure_dir(out)

    clk = (sig.get("clks") or ["clk_i"])[0]
    rst = (sig.get("rsts") or ["rst_ni"])[0]
    config_registers = _register_entries(hjson_path)
    lookup_registers = _register_lookup_entries(hjson_path)
    inputs, outputs = _simple_datapath_ports(sig)

    files = {
        out / f"{top}_reg_sequence.svh": render_sv_reg_sequence(
            top,
            interface,
            clk,
            active=bus_active,
            registers=lookup_registers or config_registers,
        ),
    }

    stale_vec_files = [out / f"{top}_vec_monitor.svh", out / f"{top}_vec_driver.svh"]

    if bus_active or (inputs and outputs):
        files[stale_vec_files[0]] = render_sv_vec_monitor(top, outputs)
        files[stale_vec_files[1]] = render_sv_vec_driver(
            top, clk, rst, inputs, outputs, reset_polarity, reset_domain
        )
    else:
        for stale in stale_vec_files:
            if stale.exists():
                stale.unlink()

    for path, text in files.items():
        # Verification helpers belong to the fully generated SV scaffold.
        safe_write_file(path, text, overwrite=True)

    return list(files)

@dataclass(frozen=True, slots=True)
class TestbenchConfig:
    """Describe one testbench generation request.

    Paths are accepted as strings or Path objects to keep Make and Python callers simple.
    """

    top: str
    rtldir: str | Path
    simdir: str | Path
    syndir: str | Path
    prims: tuple[str, ...]
    clk_period_ns: int
    compiler: str
    interface: str
    vsv: str = "sv"
    output: str | Path = "tb"
    devices: tuple[tuple[str, str, str, str], ...] = ()
    force: bool = False


def _logic_decl(name: str, width: Any, *, default_type: str = "logic") -> str:
    """Render a SystemVerilog declaration for a parsed port width."""

    packed_tlul = {
        "tlul_pkg::tl_h2d_t": "[108:0]",
        "tlul_pkg::tl_d2h_t": "[65:0]",
    }
    if width in packed_tlul:
        return f"  logic {packed_tlul[width]} {name};"
    if width == 1 or width == "1":
        return f"  logic {name};"
    if isinstance(width, str) and width.startswith("["):
        return f"  logic {width} {name};"
    return f"  {default_type} {name};"


def _connect_ports(ports_in: Sequence[tuple[str, Any]], ports_out: Sequence[tuple[str, Any]], top: str, interface: str) -> list[str]:
    """Return DUT instance pin mappings for generic, TL-UL, or reg-interface wiring."""

    pins: list[str] = []
    for name, _ in ports_in:
        if interface == "tlul" and name == "tl_i":
            pins.append(f"    .{name}(tl_if.h2d)")
        elif interface == "reg_iface" and name == "reg_req_i":
            pins.append(f"    .{name}(regif.req)")
        else:
            pins.append(f"    .{name}({name})")
    for name, _ in ports_out:
        if interface == "tlul" and name == "tl_o":
            pins.append(f"    .{name}(tl_if.d2h)")
        elif interface == "reg_iface" and name == "reg_rsp_o":
            pins.append(f"    .{name}(regif.rsp)")
        else:
            pins.append(f"    .{name}({name})")
    return [line + ("," if index != len(pins) - 1 else "") for index, line in enumerate(pins)]

# SystemVerilog render helpers
def render_verilator_include(top: str, rtldir: str | Path, syndir: str | Path,
                              prims: Sequence[str], flag_reg_pkg: bool,
                              interface: str, vsv: str) -> str:
    """Render the include shim used by Verilator pre/post-synthesis runs."""

    inc: list[str] = []
    inc.append("`ifndef SYN")

    # pkgs: assume +incdir+<ips_root>/pkgs nel comando
    inc.append('  `include "top_pkg.sv"')
    inc.append('  `include "prim_util_pkg.sv"')
    inc.append('  `include "prim_mubi_pkg.sv"')
    inc.append('  `include "prim_secded_pkg.sv"')

    # local rtl: assume +incdir+rtldir nel comando
    if flag_reg_pkg:
        inc.append(f'  `include "{top}_reg_pkg.sv"')

    # TLUL: assume +incdir+<ips_root>/pkgs e +incdir+<ips_root>/tlul
    if flag_reg_pkg and interface == "tlul":
        inc.append('  `include "tlul_pkg.sv"')
        inc.append('  `include "tlul_if.sv"')

    if flag_reg_pkg and interface == "reg_iface":
        inc.append('  `include "reg_utils.sv"')
        inc.append('  `include "reg_if.sv"')

    # DUT source: assume +incdir+rtldir nel comando
    inc.append(f'  `include "{top}.{"sv" if vsv == "sv" else "v"}"')

    inc.append("`else")

    # Native GLS supplies active-PDK models through FLEXSOC_GLS_EXTERNAL_MODELS.
    # Keep generated testbenches portable across PDK profiles.
    inc.append("  `ifndef FLEXSOC_GLS_EXTERNAL_MODELS")
    for p in prims:
        inc.append(f'    `include "{Path(p).name}"')
    inc.append("  `endif")

    # synth netlist: includi solo nome, assume +incdir+syndir nel comando
    inc.append(f'  `include "{top}_synth.v"')

    inc.append("`endif")
    return "\n".join(inc) + "\n"

def render_packed_tlul_helpers(indent: str = "") -> str:
    """Render package-free TL-UL packing and integrity helpers for GLS wrappers."""

    body = r"""
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
""".strip("\n")
    return "\n".join(indent + line if line else "" for line in body.splitlines())


def render_tlul_interface() -> str:
    """Render a package-free, simulator-neutral TL-UL interface and driver."""

    helpers = render_packed_tlul_helpers("  ")
    return f"""`timescale 1ns/1ps

interface tlul_if (
  input logic clk_i,
  input logic rst_ni
);

  logic [108:0] h2d /* simulator public*/;
  logic [65:0]  d2h /* simulator public*/;

{helpers}

  modport drv (output h2d, input d2h);
  modport dut (input h2d, output d2h);

  // TB timing contract: drive DUT inputs on negedge, sample DUT outputs on posedge.
  task automatic sample_cycle();
    @(posedge clk_i);
  endtask

  task automatic drive_cycle();
    @(negedge clk_i);
  endtask

  task automatic drive_idle();
    h2d <= flexsoc_tlul_h2d(1'b0, FLEXSOC_TL_GET, 3'b0, 2'd2, 8'b0,
                            32'b0, 4'b0, 32'b0, 1'b1);
  endtask

  task automatic init();
    drive_idle();
    sample_cycle();
  endtask

  task automatic wait_d2h_high(input integer bit_index, input string signal_name);
    integer guard;
    guard = 0;
    sample_cycle();
    while (d2h[bit_index] !== 1'b1) begin
      if (d2h[bit_index] !== 1'b0)
        $fatal(1, "[%0t] TLUL %s is X/Z; check reset and gate-level cell model mode",
               $time, signal_name);
      guard++;
      if (guard > 1000)
        $fatal(1, "[%0t] TLUL timeout waiting for %s", $time, signal_name);
      sample_cycle();
    end
  endtask

  task automatic tlul_write(
    input logic [31:0] addr,
    input logic [31:0] data,
    input logic [7:0] source,
    input logic [3:0] mask = 4'hf
  );
    logic [2:0] opcode;
    $display("[%0t] TLUL WRITE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);
    opcode = (mask == 4'hf) ? FLEXSOC_TL_PUT_FULL : FLEXSOC_TL_PUT_PARTIAL;
    drive_cycle();
    h2d <= flexsoc_tlul_h2d(1'b1, opcode, 3'b0, 2'd2, source,
                            addr, mask, data, 1'b1);
    wait_d2h_high(0, "write a_ready");
    drive_cycle();
    h2d[108] <= 1'b0;
    wait_d2h_high(65, "write d_valid");
    if (d2h[1])
      $fatal(1, "[%0t] TLUL WRITE ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    drive_cycle();
    drive_idle();
    sample_cycle();
    #1;
  endtask

  task automatic tlul_read(
    input logic [31:0] addr,
    output logic [31:0] data,
    input logic [7:0] source
  );
    $display("[%0t] TLUL READ: Addr = 0x%08x", $time, addr);
    data = '0;
    drive_cycle();
    h2d <= flexsoc_tlul_h2d(1'b1, FLEXSOC_TL_GET, 3'b0, 2'd2, source,
                            addr, 4'hf, 32'b0, 1'b1);
    wait_d2h_high(0, "read a_ready");
    drive_cycle();
    h2d[108] <= 1'b0;
    wait_d2h_high(65, "read d_valid");
    data = d2h[47:16];
    if (d2h[1])
      $fatal(1, "[%0t] TLUL READ ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    drive_cycle();
    drive_idle();
    sample_cycle();
    #1;
  endtask

endinterface
"""

def render_reg_interface(top: str) -> str:
    """Render a generic register request/response SystemVerilog interface."""

    return f"""`timescale 1ns/1ps

interface reg_if (
  input  logic clk_i,
  input  logic rst_ni
);
  import {top}_reg_pkg::*;

  // Toward DUT (registered request)
  reg_req_t req /* simulator public*/;
  // From DUT (response)
  reg_rsp_t rsp /* simulator public*/;

  // Staging avoids combinational loops from TB into DUT
  reg_req_t req_q;

  // Register the staged request (visible to DUT as 'req')
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) req <= '0;
    else         req <= req_q;
  end

  // Driver modport (TB)
  modport drv (
    input  clk_i,
    output req_q,
    input  rsp
  );

  // DUT modport (sees registered request)
  modport dut (
    input  clk_i,
    input  rst_ni,
    input  req,
    output rsp
  );

endinterface
"""


def render_reg_utils(top: str) -> str:
    """Render simple register read/write tasks for generated testbenches."""

    return f"""class reg_utils;

  // Use the driver modport for clean directions & clock access
  virtual reg_if.drv drv_if;

  function new(virtual reg_if.drv drv_if);
    this.drv_if = drv_if;
  endfunction

  task automatic cycle();
    @(posedge drv_if.clk_i);
  endtask

  task automatic write(
      input  logic [{top}_reg_pkg::AW-1:0]  addr,
      input  logic [{top}_reg_pkg::DW-1:0]  data,
      input  logic [{top}_reg_pkg::DBW-1:0] strb = {{{top}_reg_pkg::DBW{{1'b1}}}});
    $display("[%0t] REG WRITE: Addr = 0x%0h Data = 0x%0h WSTRB = 0x%0h", $time, addr, data, strb);

    drv_if.req_q.valid <= 1'b1;
    drv_if.req_q.write <= 1'b1;
    drv_if.req_q.addr  <= addr;
    drv_if.req_q.wdata <= data;
    drv_if.req_q.wstrb <= strb;

    cycle();

    while (!drv_if.rsp.ready) cycle();

    drv_if.req_q.valid <= 1'b0;
    cycle();

    if (drv_if.rsp.error) begin
      $display("[%0t] REG WRITE ERROR: Addr = 0x%0h", $time, addr);
    end else begin
      $display("[%0t] REG WRITE DONE: Addr = 0x%0h", $time, addr);
    end
    #1;
  endtask

  task automatic read(
      input  logic [{top}_reg_pkg::AW-1:0]  addr,
      output logic [{top}_reg_pkg::DW-1:0]  data);
    $display("[%0t] REG READ: Addr = 0x%0h", $time, addr);

    drv_if.req_q.valid <= 1'b1;
    drv_if.req_q.write <= 1'b0;
    drv_if.req_q.addr  <= addr;
    drv_if.req_q.wdata <= '0;
    drv_if.req_q.wstrb <= '0;

    cycle();

    while (!drv_if.rsp.ready) cycle();

    data = drv_if.rsp.rdata;

    drv_if.req_q.valid <= 1'b0;
    cycle();

    if (drv_if.rsp.error) begin
      $display("[%0t] REG READ ERROR: Addr = 0x%0h", $time, addr);
    end else begin
      $display("[%0t] REG READ DONE: Addr = 0x%0h Data = 0x%0h", $time, addr, data);
    end
    #1;
  endtask

endclass
"""


def render_sv_test_selector(tests: Sequence[str] = TEST_NAMES) -> str:
    """Render plusarg-based test selection by name or explicit files."""

    names = ", ".join(tests)
    return f"""  // Test selection
  // Use +TEST_NAME=<name> or explicit CFG/DATA_IN/DATA_OUT file paths.
  // Use +TEST_ROOT=<dir> to relocate generated tests.
  // Available generated tests from the default model: {names}
  task automatic tb_select_test(output string cfg_path, output string data_in_path, output string data_out_path);
    string test_name;
    string test_root;

    test_name = "{tests[0]}";
    test_root = "tests";
    void'($value$plusargs("TEST_ROOT=%s", test_root));
    void'($value$plusargs("TEST_NAME=%s", test_name));

    cfg_path      = {{test_root, "/", test_name, "/config.regs"}};
    data_in_path  = {{test_root, "/", test_name, "/data_in.vec"}};
    data_out_path = {{test_root, "/", test_name, "/data_out.vec"}};

    void'($value$plusargs("CFG=%s", cfg_path));
    void'($value$plusargs("DATA_IN=%s", data_in_path));
    void'($value$plusargs("DATA_OUT=%s", data_out_path));

    $display("[TB] test=%s", test_name);
    $display("[TB] test_root=%s", test_root);
    $display("[TB] cfg=%s", cfg_path);
    $display("[TB] data_in=%s", data_in_path);
    $display("[TB] data_out=%s", data_out_path);
  endtask
"""

def render_testbench(top: str,
                     clk_period_ns: int,
                     simdir: str | Path,
                     syndir: str | Path,
                     interface: str,
                     compiler: str,
                     vsv: str,
                     sig: dict[str, Any]) -> str:
    """Compose the <top>_tb.sv body using parsed signature info."""
    params: list[tuple[str, str]] = sig["parameters"]
    lparams: list[tuple[str, str]] = sig["localparams"]
    ports_in: list[tuple[str, Any]] = sig["ports_in"]
    ports_out: list[tuple[str, Any]] = sig["ports_out"]
    clks: list[str] = sig["clks"]
    rsts: list[str] = sig["rsts"]

    lines: list[str] = []
    lines.append("// Timescale")
    lines.append("`timescale 1ns/1ps")
    lines.append("// Includes")
    if compiler == "verilator":
        lines.append(f'`include "include_{top}_tb.sv"')
    else:
        # Fallback includes for non-Verilator
        lines.append("`ifndef SYN")
        lines.append(f'  `include "{top}.v"')
        lines.append("`else")
        lines.append(f'  `include "{top}_synth.v"')
        lines.append("`endif")
    lines.append("")
    lines.append(f"module {top}_tb;")
    lines.append("  // Parameters")
    lines.append(f"  parameter int CLK_PERIOD = {clk_period_ns}; // ns")
    lines.append("  parameter int INITIAL_RESET_CYCLES = 5;")
    for name, val in params:
        lines.append(f"  parameter {name} = {val};")
    for name, val in lparams:
        lines.append(f"  localparam {name} = {val};")

    # Inputs
    lines.append("\n  // Inputs")
    for name, width in ports_in:
        default = str(width) if interface == "tlul" else f"{top}_reg_pkg::{width}"
        lines.append(_logic_decl(name, width, default_type=default))

    # Outputs
    lines.append("\n  // Outputs")
    for name, width in ports_out:
        default = str(width) if interface == "tlul" else f"{top}_reg_pkg::{width}"
        lines.append(_logic_decl(name, width, default_type=default))

    lines.append("\n  integer error_count;")
    # TL-UL is fixed at 32 data bits; reg-interface mode keeps the generated package width.
    lines.append("  logic [31:0] rdata;" if interface == "tlul" else f"  logic [{top}_reg_pkg::DW-1:0] rdata;")

    # TL-UL uses procedural interface tasks in both RTL and gate simulation.
    if interface == "tlul":
        lines.append("  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));")
    elif compiler == "verilator" and interface == "reg_iface":
        lines.append("  reg_utils reg_utils_inst;")
        lines.append("  reg_if regif(.clk_i(clk_i), .rst_ni(rst_ni));")

    lines.append("\n  // Verification helpers")
    lines.append(f'  `include "{top}_reg_sequence.svh"')
    if _has_simple_datapath(sig):
        lines.append(f'  `include "drivers/{top}_vec_monitor.svh"')
        lines.append(f'  `include "drivers/{top}_vec_driver.svh"')
    else:
        lines.append(_render_no_vector_task(top).rstrip())

    # DUT instance
    lines.append("\n  // DUT")
    lines.append(f"  {top} u_{top} (")
    lines.extend(_connect_ports(ports_in, ports_out, top, interface))
    lines.append("  );\n")

    # Clock gens
    for c in clks:
        lines.append("  initial begin")
        lines.append(f"    {c} = 0;")
        lines.append("    forever #(CLK_PERIOD / 2) " + f"{c} = ~{c};")
        lines.append("  end\n")

    # Wave path is simulator-independent; runtime selects FST or VCD encoding.
    # An empty path means no dump, so never invent a cwd-local filename.
    lines.append("  string wave_path;")
    lines.append("  initial begin")
    lines.append('    if (!$value$plusargs("WAVE=%s", wave_path)) begin')
    lines.append('      if (!$value$plusargs("VCD=%s", wave_path)) wave_path = "";')
    lines.append("    end")
    lines.append('    if (wave_path != "") begin')
    lines.append('      $display("[TB] dumpfile = %s", wave_path);')
    lines.append("      $dumpfile(wave_path);")
    lines.append(f"      $dumpvars(0, {top}_tb);")
    lines.append("    end")
    lines.append("  end\n")

    # SDF exists only in gate-level builds; RTL simulators never parse it.
    lines.append("  // SDF backannotation")
    lines.append("  `ifdef FLEXSOC_ENABLE_SDF")
    lines.append("    string sdf_path;")
    lines.append("    initial begin")
    lines.append('      if (!$value$plusargs("SDF=%s", sdf_path)) sdf_path = "";')
    lines.append('      if (sdf_path != "") begin')
    lines.append('        `ifdef FLEXSOC_SDF_MIN')
    lines.append('          $display("[TB] sdf = %s (MINIMUM)", sdf_path);')
    lines.append(f'          $sdf_annotate(sdf_path, {top}_tb.u_{top});')
    lines.append('        `elsif FLEXSOC_SDF_TYP')
    lines.append('          $display("[TB] sdf = %s (TYPICAL)", sdf_path);')
    lines.append(f'          $sdf_annotate(sdf_path, {top}_tb.u_{top});')
    lines.append('        `else')
    lines.append('          $display("[TB] sdf = %s (MAXIMUM)", sdf_path);')
    lines.append(f'          $sdf_annotate(sdf_path, {top}_tb.u_{top});')
    lines.append('        `endif')
    lines.append("      end")
    lines.append("    end")
    lines.append("  `endif\n")

    # Stimulus
    lines.append("  string cfg_path;")
    lines.append("  string data_in_path;")
    lines.append("  string data_out_path;")
    lines.append("")
    lines.append(render_sv_test_selector().rstrip())
    lines.append("")
    lines.append("  initial begin")
    lines.append("    error_count = 0;")
    lines.append("    tb_select_test(cfg_path, data_in_path, data_out_path);")
    if ports_in:
        # init inputs (skip the first, often a clock)
        for nm, _ in ports_in[1:]:
            lines.append(f"    {nm} = {_sv_input_default(nm)};")
    if interface == "tlul":
        lines.append("    tl_if.init();")
    elif compiler == "verilator" and interface == "reg_iface":
        lines.append("    reg_utils_inst = new(regif);")

    # Every generated test starts from an initialized, race-free reset boundary.
    reset_name = rsts[0] if rsts else (ports_in[1][0] if len(ports_in) > 1 and "rst" in ports_in[1][0] else "")
    if reset_name:
        lines.append(f"    {reset_name} = 1'b1;")
        lines.append(f"    repeat (2) @(posedge {clks[0]});")
        lines.append(f"    @(negedge {clks[0]}); #1;")
        lines.append(f"    {reset_name} = 1'b0;")
        lines.append('    $display("[TB] initial reset pulse cycles=%0d", INITIAL_RESET_CYCLES);')
        lines.append(f"    repeat (INITIAL_RESET_CYCLES) @(posedge {clks[0]});")
        lines.append(f"    @(negedge {clks[0]}); #1;")
        lines.append(f"    {reset_name} = 1'b1;")
        lines.append(f"    repeat (2) @(posedge {clks[0]});")
    else:
        lines.append("    #(CLK_PERIOD*2);")

    lines.append('    $display("\\nRunning...\\n");')

    if interface == "tlul" or compiler == "verilator":
        lines.append("    #(CLK_PERIOD*10);")
        lines.append("    run_reg_config(cfg_path);")
        lines.append("    run_vectors(data_in_path, data_out_path);")
        lines.append("    #(CLK_PERIOD*10);")

    lines.append("    // INSERT ADDITIONAL TEST-SPECIFIC STIMULUS HERE")
    lines.append("    if (error_count == 0) $display(\"Coverage: 100%%\");")
    lines.append('    $display("\\nEnd.\\n");')
    lines.append('    if (error_count != 0) $fatal(1, "[TB] %0d vector check(s) failed", error_count);')
    lines.append("    $finish;")
    lines.append("  end")
    lines.append("endmodule")
    return "\n".join(lines) + "\n"


def render_simple_testbench(top: str,
                            clk_period_ns: int,
                            devices: Sequence[Sequence[str]],
                            simdir: str | Path,
                            syndir: str | Path,
                            compiler: str,
                            sig: dict[str, Any]) -> str:
    """Minimal TB: only clock(s) and reset(s). No TLUL/Reg IF."""
    params = sig["parameters"]
    lparams = sig["localparams"]
    ports_in = sig["ports_in"]
    ports_out = sig["ports_out"]
    clks = sig["clks"]
    rsts = sig["rsts"]

    lines = []
    lines.append("`timescale 1ns/1ps")
    if compiler == "verilator":
        lines.append(f'`include "include_{top}_tb.sv"')
    else:
        lines.append("`ifndef SYN")
        lines.append(f'  `include "{top}.v"')
        lines.append("`else")
        lines.append(f'  `include "{top}_synth.v"')
        lines.append("`endif")
    lines.append("")
    lines.append(f"module {top}_tb;")
    lines.append(f"  parameter int CLK_PERIOD = {clk_period_ns}; // ns")

    for name, val in params:
        lines.append(f"  parameter {name} = {val};")
    for name, val in lparams:
        lines.append(f"  localparam {name} = {val};")

    # Declare ports directly in the testbench scope.
    lines.append("\n  // Inputs")
    for name, width in ports_in:
        lines.append(_logic_decl(name, width))

    lines.append("\n  // Outputs")
    for name, width in ports_out:
        lines.append(_logic_decl(name, width))

    lines.append("\n  integer error_count;")

    # DUT
    lines.append("\n  // DUT")
    lines.append(f"  {top} u_{top} (")
    lines.extend(_connect_ports(ports_in, ports_out, top, "direct"))
    lines.append("  );\n")

    lines.append("  // Verification helpers")
    lines.append(f'  `include "{top}_reg_sequence.svh"')
    if _has_simple_datapath(sig):
        lines.append(f'  `include "drivers/{top}_vec_monitor.svh"')
        lines.append(f'  `include "drivers/{top}_vec_driver.svh"')
    else:
        lines.append(_render_no_vector_task(top).rstrip())
    lines.append("")

    # Clocks
    for c in clks:
        lines.append("  initial begin")
        lines.append(f"    {c} = 1'b0;")
        lines.append(f"    forever #(CLK_PERIOD/2) {c} = ~{c};")
        lines.append("  end\n")

    # Runtime-selected FST/VCD path; never fall back to a cwd-local dump.
    lines.append("  string wave_path;")
    lines.append("  initial begin")
    lines.append('    if (!$value$plusargs("WAVE=%s", wave_path)) begin')
    lines.append('      if (!$value$plusargs("VCD=%s", wave_path)) wave_path = "";')
    lines.append("    end")
    lines.append('    if (wave_path != "") begin')
    lines.append('      $display("[TB] dumpfile = %s", wave_path);')
    lines.append("      $dumpfile(wave_path);")
    lines.append(f"      $dumpvars(0, {top}_tb);")
    lines.append("    end")
    lines.append("  end\n")
    lines.append("  // Optional SDF backannotation for post-synthesis/post-PnR GLS")
    lines.append("  `ifdef FLEXSOC_ENABLE_SDF")
    lines.append("    string sdf_path;")
    lines.append("    initial begin")
    lines.append('      if (!$value$plusargs("SDF=%s", sdf_path)) sdf_path = "";')
    lines.append('      if (sdf_path != "") begin')
    lines.append('        `ifdef FLEXSOC_SDF_MIN')
    lines.append('          $display("[TB] sdf = %s (MINIMUM)", sdf_path);')
    lines.append(f'          $sdf_annotate(sdf_path, {top}_tb.u_{top});')
    lines.append('        `elsif FLEXSOC_SDF_TYP')
    lines.append('          $display("[TB] sdf = %s (TYPICAL)", sdf_path);')
    lines.append(f'          $sdf_annotate(sdf_path, {top}_tb.u_{top});')
    lines.append('        `else')
    lines.append('          $display("[TB] sdf = %s (MAXIMUM)", sdf_path);')
    lines.append(f'          $sdf_annotate(sdf_path, {top}_tb.u_{top});')
    lines.append('        `endif')
    lines.append("      end")
    lines.append("    end")
    lines.append("  `endif\n")
    # UART HOST TASK
    if top == 'soc':
        lines.append("  // UART HOST TASKS")
        lines.append("  task automatic uart_send_byte(input logic [7:0] b);")
        lines.append("    begin")
        lines.append("      // Start bit")
        lines.append("      cio_rx_i = 1'b0; ")
        lines.append("      #1085; // Wait for half a bit period")
        lines.append("      // Send each bit of the pattern")
        lines.append("      for (int i = 0; i < 8; i++) begin")
        lines.append("        cio_rx_i = b[i]; // Send each bit of the pattern")
        lines.append("        #1085; // Wait for half a bit period")
        lines.append("      end")
        lines.append("      // Stop bit")
        lines.append("      cio_rx_i = 1'b1; ")
        lines.append("      #1085; // Wait for half a bit period")
        lines.append("    end")
        lines.append("  endtask")
        lines.append("  ")
        lines.append("  // Frame helper: manda un 32b LSB-first")
        lines.append("  task automatic uart_send_word32(input logic [31:0] w);")
        lines.append("    uart_send_byte(w[7:0]);")
        lines.append("    uart_send_byte(w[15:8]);")
        lines.append("    uart_send_byte(w[23:16]);")
        lines.append("    uart_send_byte(w[31:24]);")
        lines.append("  endtask")
        lines.append("  ")
        lines.append("  // WRITE: A5 | 01 | 01 | {0000,BE} | 00 | ADDR(4) | DATA(4)")
        lines.append("  task automatic uart_write32(input logic [31:0] addr, input logic [31:0] data, input logic [3:0] be = 4'hF);")
        lines.append("    begin")
        lines.append("      uart_send_byte(8'hA5);      // SOF")
        lines.append("      uart_send_byte(8'h01);      // OP=WRITE")
        lines.append("      uart_send_byte({4'h0,be});  // BE")
        lines.append("      uart_send_word32(addr);     // ADDR (LSB-first)")
        lines.append("      uart_send_word32(data);     // DATA (LSB-first)")
        lines.append("    end")
        lines.append("  endtask")
        lines.append("  ")
        lines.append("  // READ: A5 | 01 | 00 | {0000,1111} | 00 | ADDR(4)")
        lines.append("  task automatic uart_read32(input logic [31:0] addr);")
        lines.append("    begin")
        lines.append("      uart_send_byte(8'hA5);       // SOF")
        lines.append("      uart_send_byte(8'h00);       // OP=READ")
        lines.append("      uart_send_byte({4'h0,4'hF}); // BE")
        lines.append("      uart_send_word32(addr);      // ADDR (LSB-first)")
        lines.append("    end")
        lines.append("  endtask")
        lines.append("  ")
        lines.append("  // =========")
        lines.append("  // Addresses")
        lines.append("  // =========")
        for d in devices:
            lines.append(f"  localparam logic [31:0] {d[0].upper()}_BASE   = 32'h{d[1][2:]};")
        lines.append("")
        lines.append("  // Offsets")
        for d in devices:
            lines.append(f"  localparam logic [31:0] {d[0].upper()}_CTRL_OFF = 32'h00000000;")
            lines.append("  /////////////////////////////////////////////////////////////////")

    lines.append("  string cfg_path;")
    lines.append("  string data_in_path;")
    lines.append("  string data_out_path;")
    lines.append("")
    lines.append(render_sv_test_selector().rstrip())
    lines.append("")

    # Simple reset pulse(s)
    lines.append("  initial begin")
    lines.append("    error_count = 0;")
    lines.append("    tb_select_test(cfg_path, data_in_path, data_out_path);")
    # Init inputs to 0
    for nm, _ in ports_in:
        if nm not in clks and nm not in rsts:
            lines.append(f"    {nm} = '0;")
    if rsts:
        for r in rsts:
            lines.append(f"    {r} = 1'b0;")
        lines.append("    #(CLK_PERIOD*2);")
        for r in rsts:
            lines.append(f"    {r} = 1'b1;")
    else:
        lines.append("    #(CLK_PERIOD*2);")
    if top == 'soc':
        lines.append("    uart_write32(UART_BASE + UART_CTRL_OFF, 32'h4B7F_0001); // For 100MHz fclk")
        lines.append("    #(CLK_PERIOD*2000);")
        lines.append("    uart_read32(UART_BASE + UART_CTRL_OFF);")
        lines.append("    #(CLK_PERIOD*2000);    ")
    lines.append("    run_reg_config(cfg_path);")
    lines.append("    run_vectors(data_in_path, data_out_path);")
    lines.append("    #(CLK_PERIOD*10);")
    lines.append('    if (error_count != 0) $fatal(1, "[TB] %0d vector check(s) failed", error_count);')
    lines.append("    $finish;")
    lines.append("  end")
    lines.append("endmodule")
    return "\n".join(lines) + "\n"

# Filesystem boundary


def uses_simple_testbench(config: TestbenchConfig) -> bool:
    """Return whether the top should use direct port wiring instead of bus helpers."""

    reg_pkg = has_reg_pkg(config.rtldir, config.top)
    reg_top = (Path(config.rtldir) / f"{config.top}_reg_top.sv").exists()
    return not (reg_pkg and reg_top)


def write_bus_helpers(config: TestbenchConfig, *, reg_pkg: bool, simple_mode: bool) -> list[Path]:
    """Write bus helpers required by generated RTL and gate testbenches."""

    if simple_mode or not reg_pkg:
        return []

    outdir = Path(config.output)
    helpers = {
        "tlul": (("tlul_if.sv", render_tlul_interface()),),
        "reg_iface": (
            (("reg_if.sv", render_reg_interface(config.top)), ("reg_utils.sv", render_reg_utils(config.top)))
            if config.compiler == "verilator" else ()
        ),
    }.get(config.interface, ())

    written: list[Path] = []
    for name, body in helpers:
        path = outdir / name
        # Machine-owned bus interfaces must stay in lockstep with generated drivers.
        # Regenerate them together so driver tasks always match the interface.
        safe_write_file(path, body, overwrite=True)
        written.append(path)
    return written


# BEGIN FLEXSOC CANONICAL SV OUTPUT
def _canonical_sv_output_dir(output: str | Path) -> Path:
    """Return the canonical SystemVerilog output directory."""

    out = Path(output)
    if out.name == "sv":
        return out
    return out / "sv"


def _with_canonical_sv_output(config: TestbenchConfig) -> TestbenchConfig:
    """Return a config whose output points at the canonical tb/sv directory."""

    sv_output = _canonical_sv_output_dir(config.output)
    if Path(config.output) == sv_output:
        return config
    return replace(config, output=sv_output)
# END FLEXSOC CANONICAL SV OUTPUT

def _generate_testbench_files(
    config: TestbenchConfig, clocks: ClockConfig | None = None
) -> tuple[Path, ...]:
    """Generate include, helper, and top-level testbench files for one request."""

    config = _with_canonical_sv_output(config)
    clocks = clocks or clock_config()
    outdir = Path(config.output)
    ensure_dir(outdir)

    sig = parse_sv_signature(config.rtldir, config.top)
    reg_pkg = has_reg_pkg(config.rtldir, config.top)
    simple_mode = uses_simple_testbench(config)
    written: list[Path] = []
    hjson_path = _candidate_hjson_path(config.rtldir, config.top)
    # setup_model owns config.regs/data_in.vec/data_out.vec generation.
    primary_reset = (sig.get("rsts") or ["rst_ni"])[0]
    reset_domain = next(
        (domain for domain in clocks.domains if domain.reset == primary_reset),
        clocks.domains[0],
    )
    written.extend(
        write_sv_verification_helpers(
            outdir,
            config.top,
            config.interface,
            sig,
            hjson_path=hjson_path,
            bus_active=(not simple_mode and (config.interface == "tlul" or config.compiler == "verilator")),
            force=True,
            reset_polarity=reset_domain.reset_polarity,
            reset_domain=reset_domain.name,
        )
    )

    if config.compiler == "verilator":
        include = render_verilator_include(
            config.top,
            config.rtldir,
            config.syndir,
            config.prims,
            reg_pkg,
            config.interface,
            config.vsv,
        )
        include_path = outdir / f"include_{config.top}_tb.sv"
        safe_write_file(include_path, include, overwrite=True)
        written.append(include_path)

    written.extend(write_bus_helpers(config, reg_pkg=reg_pkg, simple_mode=simple_mode))

    body = (
        render_simple_testbench(
            config.top,
            config.clk_period_ns,
            config.devices,
            config.simdir,
            config.syndir,
            config.compiler,
            sig,
        )
        if simple_mode
        else render_testbench(
            config.top,
            config.clk_period_ns,
            config.simdir,
            config.syndir,
            config.interface,
            config.compiler,
            config.vsv,
            sig,
        )
    )
    tb_path = outdir / f"{config.top}_tb.sv"
    safe_write_file(tb_path, body, overwrite=True)
    written.append(tb_path)
    return tuple(written)


def generate_testbench_files(
    config: TestbenchConfig, clocks: ClockConfig | None = None
) -> tuple[Path, ...]:
    """Recreate the complete machine-owned SystemVerilog scaffold."""

    canonical = _with_canonical_sv_output(config)
    with replace_generated_tree(canonical.output):
        written = _generate_testbench_files(canonical, clocks)
        _normalize_generated_sv_layout(canonical)
        return written


# Generated layout normalization
def _read_text(path: Path) -> str:
    """Return file text or an empty string when the file is absent."""

    return path.read_text(encoding="utf-8") if path.exists() else ""


def _write_text(path: Path, text: str) -> None:
    """Write text after creating the parent directory."""

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")


def _patch_empty_config_ok(text: str) -> str:
    """Allow comment-only config.regs files to be valid generated tests."""

    old = """  if (writes == 0) begin
    $display("[TB][ERROR] no register config writes were applied from %s", cfg_path);
    error_count++;
  end"""
    new = """  if (writes == 0) begin
    $display("[TB] no register config writes from %s; continuing", cfg_path);
  end"""
    return text.replace(old, new)


def _find_task_block(text: str, task_name: str) -> tuple[int, int] | None:
    """Return the span of one simple SystemVerilog task block."""

    start = text.find(f"task automatic {task_name}")
    if start < 0:
        return None
    end = text.find("endtask", start)
    if end < 0:
        return None
    return start, end + len("endtask")


def _reg_driver_fallback(top: str) -> str:
    """Render a register-config no-op for DUTs without generated register metadata."""

    return f"""// Auto-generated {top} register driver fallback.
// Empty or comment-only config.regs files are valid.

task automatic run_reg_config(input string cfg_path);
  int fd;
  begin : run_reg_config_fallback_body
    fd = $fopen(cfg_path, "r");
    if (fd == 0) begin
      $display("[TB] register config not found: %s", cfg_path);
      disable run_reg_config_fallback_body;
    end
    $display("[TB] no generated register sequence for {top}; ignoring optional config: %s", cfg_path);
    $fclose(fd);
  end
endtask
"""


def _cordic_reg_driver_prefix(top: str, clk: str) -> str:
    """Render low-level CORDIC CSR read/write helpers."""

    return f"""// Auto-generated {top} CSR/TL-UL register access helpers.

task automatic {top}_reg_write(input logic [31:0] addr, input logic [31:0] data);
  logic [31:0] mask;
  mask = 32'hffff_ffff;
  tl_utils_inst.tlul_write(addr[top_pkg::TL_AW-1:0], data, 4'h0, mask[top_pkg::TL_DBW-1:0]);
  @(posedge {clk});
endtask

task automatic {top}_reg_read(input logic [31:0] addr, output logic [31:0] data);
  tl_utils_inst.tlul_read(addr[top_pkg::TL_AW-1:0], data, '0);
  @(posedge {clk});
endtask

"""


def _cordic_vec_monitor(top: str) -> str:
    """Compatibility wrapper: use the generic signal/register vector monitor."""

    return render_sv_vec_monitor(top, [])

def _cordic_vec_driver(top: str) -> str:
    """Compatibility wrapper: use the generic signal/register vector driver."""

    return render_sv_vec_driver(top, "clk_i", "rst_ni", [], [])

def _noop_vec_monitor(top: str) -> str:
    """Render a no-op monitor that satisfies the generic driver contract."""

    return f"""// Auto-generated {top} vector monitor fallback.

task automatic tb_check_outputs(input string out_path, input int cycle);
endtask
"""


def _noop_vec_driver(top: str) -> str:
    """Render a no-op vector runner for DUTs without generic datapath ports."""

    return f"""// Auto-generated {top} vector driver fallback.

task automatic run_vectors(input string data_in_path, input string data_out_path);
  $display("[TB] vector check skipped for this DUT: %s %s", data_in_path, data_out_path);
endtask
"""


def _driver_text_is_placeholder(text: str) -> bool:
    """Return true for stale placeholder driver content."""

    lowered = text.lower()
    return "may keep its inline run_vectors" in lowered or "placeholder" in lowered or not text.strip()


def _install_canonical_sv_drivers(config) -> None:
    """Move generated SV helpers into the canonical tb/sv/drivers layout."""

    top = getattr(config, "top")
    out = Path(getattr(config, "output"))
    sv_dir = out if out.name == "sv" else out / "sv"
    drivers = sv_dir / "drivers"
    drivers.mkdir(parents=True, exist_ok=True)

    src_reg = sv_dir / f"{top}_reg_sequence.svh"
    src_vec_driver = sv_dir / f"{top}_vec_driver.svh"
    src_vec_monitor = sv_dir / f"{top}_vec_monitor.svh"

    dst_reg = drivers / f"{top}_reg_driver.svh"
    dst_vec_driver = drivers / f"{top}_vec_driver.svh"
    dst_vec_monitor = drivers / f"{top}_vec_monitor.svh"

    if src_reg.exists():
        dst_reg.write_text(src_reg.read_text(encoding="utf-8"), encoding="utf-8")
    elif not dst_reg.exists():
        dst_reg.write_text(_reg_driver_fallback(top), encoding="utf-8")

    if src_vec_driver.exists():
        dst_vec_driver.write_text(src_vec_driver.read_text(encoding="utf-8"), encoding="utf-8")
    elif not dst_vec_driver.exists():
        dst_vec_driver.write_text(_noop_vec_driver(top), encoding="utf-8")

    if src_vec_monitor.exists():
        dst_vec_monitor.write_text(src_vec_monitor.read_text(encoding="utf-8"), encoding="utf-8")
    elif not dst_vec_monitor.exists():
        dst_vec_monitor.write_text(_noop_vec_monitor(top), encoding="utf-8")

    # Remove stale root-level helper copies after canonical installation.
    for stale in (src_reg, src_vec_driver, src_vec_monitor):
        if stale.exists():
            stale.unlink()

    # Hard guard: the canonical vec driver must define run_vectors.
    vec_text = dst_vec_driver.read_text(encoding="utf-8")
    if "task automatic run_vectors" not in vec_text:
        raise RuntimeError(f"{dst_vec_driver} does not define run_vectors")

def _remove_inline_run_vectors(text: str) -> str:
    """Remove any inline fallback run_vectors task from a generated TB body."""

    block = _find_task_block(text, "run_vectors")
    if block is None:
        return text
    start, end = block
    before = text[:start].rstrip()
    after = text[end:].lstrip("\n")
    return before + "\n" + after


def _patch_tb_driver_includes(config: TestbenchConfig) -> None:
    """Make <top>_tb.sv include only canonical driver files."""

    out = Path(config.output)
    top = config.top
    tb_path = out / f"{top}_tb.sv"
    if not tb_path.exists():
        return

    original = _read_text(tb_path)
    text = _remove_inline_run_vectors(original)
    driver_lines = [
        f'  `include "drivers/{top}_reg_driver.svh"',
        f'  `include "drivers/{top}_vec_monitor.svh"',
        f'  `include "drivers/{top}_vec_driver.svh"',
    ]

    cleaned: list[str] = []
    for line in text.splitlines():
        if f'`include "{top}_reg_sequence.svh"' in line:
            continue
        if f'`include "{top}_reg_driver.svh"' in line:
            continue
        if f'`include "{top}_vec_monitor.svh"' in line:
            continue
        if f'`include "{top}_vec_driver.svh"' in line:
            continue
        if f'`include "drivers/{top}_reg_driver.svh"' in line:
            continue
        if f'`include "drivers/{top}_vec_monitor.svh"' in line:
            continue
        if f'`include "drivers/{top}_vec_driver.svh"' in line:
            continue
        cleaned.append(line)

    text = "\n".join(cleaned) + "\n"
    include_block = "\n".join(driver_lines)
    marker = "  // Verification helpers"
    if marker in text:
        text = text.replace(marker, marker + "\n" + include_block, 1)
    else:
        text = text.replace("\n  // DUT", "\n  // Verification helpers\n" + include_block + "\n\n  // DUT", 1)
    if text != original:
        _write_text(tb_path, text)


def _validate_sv_driver_layout(config: TestbenchConfig) -> None:
    """Fail early if the generated layout is internally inconsistent."""

    out = Path(config.output)
    top = config.top
    required = [
        out / "drivers" / f"{top}_reg_driver.svh",
        out / "drivers" / f"{top}_vec_monitor.svh",
        out / "drivers" / f"{top}_vec_driver.svh",
    ]
    missing = [path for path in required if not path.exists()]
    if missing:
        names = ", ".join(path.as_posix() for path in missing)
        raise FileNotFoundError(f"missing generated SV helper(s): {names}")

    vec_driver = out / "drivers" / f"{top}_vec_driver.svh"
    if "task automatic run_vectors" not in _read_text(vec_driver):
        raise RuntimeError(f"{vec_driver} must define task automatic run_vectors(...)")

    legacy = out / f"{top}_vec_driver.svh"
    if legacy.exists():
        raise RuntimeError(f"legacy duplicate should not exist: {legacy}")


def _normalize_generated_sv_layout(config: TestbenchConfig) -> None:
    """Normalize generated files to the native tb/sv layout."""

    _install_canonical_sv_drivers(config)
    _patch_tb_driver_includes(config)
    _validate_sv_driver_layout(config)

def sv_include_text(top: str) -> str:
    """Render a small include file matching the single-clock TB layout."""

    guard = f"{top.upper()}_NCLOCK_TB_INCLUDE_SV".replace("-", "_")
    return dedent(f"""\
    `ifndef {guard}
    `define {guard}

    // N-clock TB include hook.
    // The Makefile compiles rtl_common.f and rtl_ip.f explicitly, so this file
    // is intentionally small. Keep local TB typedefs/macros here if needed.

    `endif
    """)


def _sv_driver_text_string(top: str, clocks: ClockConfig) -> str:
    """Render package-free TL-UL access and reset tasks for the N-clock scaffold."""

    resets = {domain.reset: domain.reset_polarity for domain in clocks.domains}
    assert_reset = "\n".join(
        f"        {name} = 1'b{1 if polarity == 'high' else 0};"
        for name, polarity in resets.items()
    )
    release_reset = "\n".join(
        f"        {name} = 1'b{0 if polarity == 'high' else 1};"
        for name, polarity in resets.items()
    )
    wait_all = "\n".join(
        f"          begin repeat (cycles) @(posedge {domain.signal}); @(negedge {domain.signal}); end"
        for domain in clocks.domains
    )
    named_reset = "\n".join(
        dedent(
            f"""\
            else if (selector == "{domain.name}" || selector == "{domain.reset}") begin
              {domain.reset} = 1'b{1 if domain.reset_polarity == 'high' else 0};
              repeat (cycles) @(posedge {domain.signal});
              @(negedge {domain.signal});
              {domain.reset} = 1'b{0 if domain.reset_polarity == 'high' else 1};
              matched = 1'b1;
            end
            """
        ).rstrip()
        for domain in clocks.domains
    )
    primary = clocks.domains[0].signal
    text = dedent("""\
      // TB timing contract: drive DUT inputs on negedge, sample DUT outputs on posedge.
      task automatic apply_defaults();
        cfg_tl_i = flexsoc_tlul_h2d(1'b0, FLEXSOC_TL_GET, 3'b0, 2'd2, 8'b0,
                                    32'b0, 4'b0, 32'b0, 1'b1);
        dsp_tl_i = flexsoc_tlul_h2d(1'b0, FLEXSOC_TL_GET, 3'b0, 2'd2, 8'b0,
                                    32'b0, 4'b0, 32'b0, 1'b1);
        rx_valid_i = 1'b0;
        rx_sample_i = '0;
        rx_coeff_i = '0;
        dsp_ready_i = 1'b1;
        test_en_i = 1'b1;
      endtask

      task automatic reset_dut(input string selector, input integer cycles);
        bit matched;
        matched = 1'b0;
        if (selector == "" || selector == "all" || selector == "*") begin
__ASSERT_RESET__
          fork
__WAIT_ALL_RESETS__
          join
__RELEASE_RESET__
          matched = 1'b1;
        end
__NAMED_RESET_BRANCHES__
        if (!matched) begin
          $display("[TB][ERROR] unknown reset selector: %s", selector);
          errors++;
        end
        apply_defaults();
        repeat (8) @(posedge __PRIMARY_CLOCK__);
      endtask

      task automatic cfg_write(input logic [31:0] addr, input logic [31:0] data);
        @(negedge cfg_clk_i);
        cfg_tl_i = flexsoc_tlul_h2d(1'b1, FLEXSOC_TL_PUT_FULL, 3'b0, 2'd2, 8'b0,
                                    addr, 4'hf, data, 1'b1);
        do @(posedge cfg_clk_i); while (!cfg_tl_o[0]);
        @(negedge cfg_clk_i);
        cfg_tl_i[108] = 1'b0;
        do @(posedge cfg_clk_i); while (!cfg_tl_o[65]);
        if (cfg_tl_o[1]) errors++;
        @(negedge cfg_clk_i);
        cfg_tl_i = flexsoc_tlul_h2d(1'b0, FLEXSOC_TL_GET, 3'b0, 2'd2, 8'b0,
                                    32'b0, 4'b0, 32'b0, 1'b1);
      endtask

      task automatic dsp_write(input logic [31:0] addr, input logic [31:0] data);
        @(negedge dsp_clk_i);
        dsp_tl_i = flexsoc_tlul_h2d(1'b1, FLEXSOC_TL_PUT_FULL, 3'b0, 2'd2, 8'b0,
                                    addr, 4'hf, data, 1'b1);
        do @(posedge dsp_clk_i); while (!dsp_tl_o[0]);
        @(negedge dsp_clk_i);
        dsp_tl_i[108] = 1'b0;
        do @(posedge dsp_clk_i); while (!dsp_tl_o[65]);
        if (dsp_tl_o[1]) errors++;
        @(negedge dsp_clk_i);
        dsp_tl_i = flexsoc_tlul_h2d(1'b0, FLEXSOC_TL_GET, 3'b0, 2'd2, 8'b0,
                                    32'b0, 4'b0, 32'b0, 1'b1);
      endtask

      task automatic cfg_read(input logic [31:0] addr, output logic [31:0] data);
        @(negedge cfg_clk_i);
        cfg_tl_i = flexsoc_tlul_h2d(1'b1, FLEXSOC_TL_GET, 3'b0, 2'd2, 8'b0,
                                    addr, 4'hf, 32'b0, 1'b1);
        do @(posedge cfg_clk_i); while (!cfg_tl_o[0]);
        @(negedge cfg_clk_i);
        cfg_tl_i[108] = 1'b0;
        do @(posedge cfg_clk_i); while (!cfg_tl_o[65]);
        data = cfg_tl_o[47:16];
        if (cfg_tl_o[1]) errors++;
        @(negedge cfg_clk_i);
        cfg_tl_i = flexsoc_tlul_h2d(1'b0, FLEXSOC_TL_GET, 3'b0, 2'd2, 8'b0,
                                    32'b0, 4'b0, 32'b0, 1'b1);
      endtask

      task automatic dsp_read(input logic [31:0] addr, output logic [31:0] data);
        @(negedge dsp_clk_i);
        dsp_tl_i = flexsoc_tlul_h2d(1'b1, FLEXSOC_TL_GET, 3'b0, 2'd2, 8'b0,
                                    addr, 4'hf, 32'b0, 1'b1);
        do @(posedge dsp_clk_i); while (!dsp_tl_o[0]);
        @(negedge dsp_clk_i);
        dsp_tl_i[108] = 1'b0;
        do @(posedge dsp_clk_i); while (!dsp_tl_o[65]);
        data = dsp_tl_o[47:16];
        if (dsp_tl_o[1]) errors++;
        @(negedge dsp_clk_i);
        dsp_tl_i = flexsoc_tlul_h2d(1'b0, FLEXSOC_TL_GET, 3'b0, 2'd2, 8'b0,
                                    32'b0, 4'b0, 32'b0, 1'b1);
      endtask

      task automatic apply_reg(input string reg_name, input logic [31:0] value);
        if (reg_name == "cfg.CTRL") cfg_write(32'h0, value);
        else if (reg_name == "cfg.GAIN") cfg_write(32'h4, value);
        else if (reg_name == "dsp.DSP_CTRL") dsp_write(32'h0, value);
        else if (reg_name == "dsp.THRESHOLD") dsp_write(32'h4, value);
        else $display("[TB][WARN] unknown config register: %s", reg_name);
      endtask

      task automatic read_reg(input string reg_name, output logic [31:0] value);
        value = '0;
        if (reg_name == "cfg.CTRL") cfg_read(32'h0, value);
        else if (reg_name == "cfg.GAIN") cfg_read(32'h4, value);
        else if (reg_name == "dsp.DSP_CTRL") dsp_read(32'h0, value);
        else if (reg_name == "dsp.THRESHOLD") dsp_read(32'h4, value);
        else begin
          $display("[TB][WARN] unknown read register: %s", reg_name);
          errors++;
        end
      endtask

      task automatic apply_reg_masked(
        input string reg_name,
        input logic [31:0] value,
        input logic [31:0] mask
      );
        logic [31:0] current;
        logic [31:0] merged;
        merged = value;
        if (mask != 32'hffff_ffff) begin
          read_reg(reg_name, current);
          merged = (current & ~mask) | (value & mask);
        end
        apply_reg(reg_name, merged);
      endtask

      task automatic expect_reg(
        input string reg_name,
        input logic [31:0] expected,
        input logic [31:0] mask
      );
        logic [31:0] got;
        read_reg(reg_name, got);
        if ((got & mask) !== (expected & mask)) begin
          $display("[TB][ERROR] %s got=0x%08x exp=0x%08x mask=0x%08x", reg_name, got, expected, mask);
          errors++;
        end
      endtask

      task automatic load_config(input string path);
        integer fd;
        integer code;
        string reg_name;
        logic [31:0] value;
        logic [31:0] mask;
        string line;
        reg [8*4096-1:0] line_buf;
        begin : load_config_body
        fd = $fopen(path, "r");
        if (fd == 0) begin
          $display("[TB][ERROR] config file not found: %s", path);
          errors++;
          disable load_config_body;
        end
        while (!$feof(fd)) begin : tb_nclk_cfg_line
          line = "";
          line_buf = '0;
          void'($fgets(line_buf, fd));
          line = $sformatf("%0s", line_buf);
          if (line.len() == 0 || line.substr(0, 0) == "#") disable tb_nclk_cfg_line;
          code = $sscanf(line, "%s %h", reg_name, value);
          if (code == 2) begin
            mask = 32'hffff_ffff;
            if ($sscanf(line, "%s %h %h", reg_name, value, mask) != 3)
              mask = 32'hffff_ffff;
            if (reg_name.len() > 6 && reg_name.substr(0, 5) == "clk_i.") reg_name = reg_name.substr(6, reg_name.len() - 1);
            apply_reg_masked(reg_name, value, mask);
          end
        end
        $fclose(fd);
        end
      endtask
    """)
    return (text.replace("__ASSERT_RESET__", assert_reset)
                .replace("__WAIT_ALL_RESETS__", wait_all)
                .replace("__RELEASE_RESET__", release_reset)
                .replace("__NAMED_RESET_BRANCHES__", named_reset)
                .replace("__PRIMARY_CLOCK__", primary))

def _sv_vec_driver_text_string(top: str) -> str:
    """Render N-clock vector commands, including CSR and reset actions."""

    return dedent("""\
      task automatic send_sample(input logic signed [15:0] sample, input logic signed [15:0] coeff);
        integer timeout;
        begin : send_sample_body
        timeout = 0;
        while (!rx_ready_o && timeout < 64) begin
          @(posedge rx_clk_i);
          timeout++;
        end
        if (!rx_ready_o) begin
          $display("[TB][ERROR] rx_ready_o timeout");
          errors++;
          disable send_sample_body;
        end
        @(negedge rx_clk_i);
        rx_sample_i = sample;
        rx_coeff_i = coeff;
        rx_valid_i = 1'b1;
        @(negedge rx_clk_i);
        rx_valid_i = 1'b0;
        end
      endtask

      task automatic run_inputs(input string path);
        integer fd;
        integer code;
        integer step;
        integer cycles;
        string token;
        string reg_name;
        string reset_selector;
        logic [31:0] value;
        logic [31:0] mask;
        string line;
        reg [8*4096-1:0] line_buf;
        logic signed [15:0] sample;
        logic signed [15:0] coeff;
        begin : run_inputs_body
        sample = '0;
        coeff = '0;
        fd = $fopen(path, "r");
        if (fd == 0) begin
          $display("[TB][ERROR] input file not found: %s", path);
          errors++;
          disable run_inputs_body;
        end
        while (!$feof(fd)) begin : tb_nclk_input_line
          line = "";
          line_buf = '0;
          void'($fgets(line_buf, fd));
          line = $sformatf("%0s", line_buf);
          if (line.len() == 0 || line.substr(0, 0) == "#") disable tb_nclk_input_line;
          code = $sscanf(line, "%d %s", step, token);
          if (code != 2) disable tb_nclk_input_line;
          if (token == "@write" || token == "write") begin
            code = $sscanf(line, "%d %s %s %h", step, token, reg_name, value);
            if (code == 4) begin
              mask = 32'hffff_ffff;
              if ($sscanf(line, "%d %s %s %h %h", step, token, reg_name, value, mask) != 5)
                mask = 32'hffff_ffff;
              apply_reg_masked(reg_name, value, mask);
              repeat (8) @(posedge dsp_clk_i);
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
            if (code == 3 || code == 4) begin
              $display(
                "[TB][RESET] cycle=%0d selector=%s cycles=%0d",
                step, reset_selector, cycles
              );
              reset_dut(reset_selector, cycles);
            end else begin
              $display("[TB][ERROR] @reset format: cycle @reset [domain|reset] cycles");
              errors++;
            end
          end else begin
            code = $sscanf(line, "%d %s %h", step, token, value);
            if (code != 3) disable tb_nclk_input_line;
            if (token == "rx_sample_i") sample = value[15:0];
            else if (token == "rx_coeff_i") coeff = value[15:0];
            else if (token == "rx_valid_i" && value[0]) send_sample(sample, coeff);
          end
        end
        $fclose(fd);
        end
      endtask
    """)

def _sv_monitor_text_string(top: str) -> str:
    """Render output-vector monitor/checker tasks."""

    return dedent("""\
      // Load expected output transactions by order, not by absolute cycle.
      task automatic load_expected(input string path);
        integer fd;
        integer code;
        integer step;
        string sig;
        logic [31:0] value;
        string line;
        reg [8*4096-1:0] line_buf;
        begin : load_expected_body
        exp_count = 0;
        fd = $fopen(path, "r");
        if (fd == 0) begin
          $display("[TB][ERROR] expected file not found: %s", path);
          errors++;
          disable load_expected_body;
        end
        while (!$feof(fd)) begin : tb_nclk_expected_line
          line = "";
          line_buf = '0;
          void'($fgets(line_buf, fd));
          line = $sformatf("%0s", line_buf);
          if (line.len() == 0 || line.substr(0, 0) == "#") disable tb_nclk_expected_line;
          code = $sscanf(line, "%d %s %h", step, sig, value);
          if (code == 3 && sig == "dsp_result_o") begin
            exp_result[exp_count] = value;
            exp_above_threshold[exp_count] = 1'b0;
            exp_overflow[exp_count] = 1'b0;
            exp_count++;
          end else if (code == 3 && sig == "dsp_above_threshold_o" && exp_count > 0) begin
            exp_above_threshold[exp_count - 1] = value[0];
          end else if (code == 3 && sig == "dsp_overflow_o" && exp_count > 0) begin
            exp_overflow[exp_count - 1] = value[0];
          end
        end
        $fclose(fd);
        end
      endtask

      // Compare each output transaction when the DSP domain produces it.
      task automatic check_outputs();
        integer timeout;
        got_count = 0;
        timeout = 0;
        dsp_ready_i = 1'b1;
        while (got_count < exp_count && timeout < 4096) begin
          // Sample halfway through the DSP cycle, after sequential updates.
          @(negedge dsp_clk_i);
          if (dsp_valid_o) begin
            if ($unsigned(dsp_result_o) !== exp_result[got_count]) begin
              $display("[TB][ERROR] result[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(dsp_result_o), exp_result[got_count]);
              errors++;
            end
            if (dsp_above_threshold_o !== exp_above_threshold[got_count]) begin
              $display("[TB][ERROR] above_threshold[%0d] got=%0d exp=%0d", got_count, dsp_above_threshold_o, exp_above_threshold[got_count]);
              errors++;
            end
            if (dsp_overflow_o !== exp_overflow[got_count]) begin
              $display("[TB][ERROR] overflow[%0d] got=%0d exp=%0d", got_count, dsp_overflow_o, exp_overflow[got_count]);
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
    """)


_STRING_SV_DRIVER_TEXT = _sv_driver_text_string
_STRING_SV_VEC_DRIVER_TEXT = _sv_vec_driver_text_string
_STRING_SV_MONITOR_TEXT = _sv_monitor_text_string


def _packed_sv_driver_text(top: str, clocks: ClockConfig) -> str:
    text = _STRING_SV_DRIVER_TEXT(top, clocks)
    text = text.replace("input string reg_name", "input tb_token_t reg_name")
    text = text.replace("  string reg_name;", "  tb_token_t reg_name;")
    text = text.replace("  string line;\n", "")
    text = text.replace("  reg [8*4096-1:0] line_buf;", "  tb_line_t line_buf;")
    text = text.replace("    line = \"\";\n", "")
    text = text.replace(
        "          void'($fgets(line_buf, fd));\n          line = $sformatf(\"%0s\", line_buf);\n"
        "          if (line.len() == 0 || line.substr(0, 0) == \"#\") disable tb_nclk_cfg_line;\n"
        "          code = $sscanf(line, \"%s %h\", reg_name, value);",
        "          code = $fgets(line_buf, fd);\n"
        "          code = $sscanf(line_buf, \"%s %h\", reg_name, value);",
    )
    text = text.replace("$sscanf(line,", "$sscanf(line_buf,")
    text = text.replace(
        '            if (reg_name.len() > 6 && reg_name.substr(0, 5) == "clk_i.") reg_name = reg_name.substr(6, reg_name.len() - 1);',
        '            begin\n'
        '              tb_token_t short_name;\n'
        "              short_name = '0;\n"
        '              if ($sscanf(reg_name, "clk_i.%s", short_name) == 1) reg_name = short_name;\n'
        '            end',
    )
    # Add the packed parser after rewriting generated task bodies.
    # Earlier insertion lets broad replacements corrupt the parser argument.
    return _PACKED_TOKEN_SUPPORT + "\n" + text


def _packed_sv_vec_driver_text(top: str) -> str:
    text = _STRING_SV_VEC_DRIVER_TEXT(top)
    text = text.replace("  string token;", "  tb_token_t token;")
    text = text.replace("  string reg_name;", "  tb_token_t reg_name;")
    text = text.replace("  string line;\n", "")
    text = text.replace("  reg [8*4096-1:0] line_buf;", "  tb_line_t line_buf;")
    text = text.replace("    line = \"\";\n", "")
    text = text.replace(
        "    void'($fgets(line_buf, fd));\n    line = $sformatf(\"%0s\", line_buf);\n"
        "    if (line.len() == 0 || line.substr(0, 0) == \"#\") disable tb_nclk_input_line;\n"
        "    code = $sscanf(line, \"%d %s\", step, token);",
        "    code = $fgets(line_buf, fd);\n"
        "    code = $sscanf(line_buf, \"%d %s\", step, token);",
    )
    text = text.replace("$sscanf(line,", "$sscanf(line_buf,")
    return text


def _packed_sv_monitor_text(top: str) -> str:
    text = _STRING_SV_MONITOR_TEXT(top)
    text = text.replace("  string sig;", "  tb_token_t sig;")
    text = text.replace("  string line;\n", "")
    text = text.replace("  reg [8*4096-1:0] line_buf;", "  tb_line_t line_buf;")
    text = text.replace("    line = \"\";\n", "")
    text = text.replace(
        "    void'($fgets(line_buf, fd));\n    line = $sformatf(\"%0s\", line_buf);\n"
        "    if (line.len() == 0 || line.substr(0, 0) == \"#\") disable tb_nclk_expected_line;\n"
        "    code = $sscanf(line, \"%d %s %h\", step, sig, value);",
        "    code = $fgets(line_buf, fd);\n"
        "    code = $sscanf(line_buf, \"%d %s %h\", step, sig, value);",
    )
    text = text.replace("$sscanf(line,", "$sscanf(line_buf,")
    return text


def sv_driver_text(top: str, clocks: ClockConfig) -> str:
    """Render an N-clock driver with simulator-specific file parsing."""

    return _sv_parser_variants(
        _STRING_SV_DRIVER_TEXT(top, clocks),
        _packed_sv_driver_text(top, clocks),
    )


def sv_vec_driver_text(top: str) -> str:
    """Render N-clock vector input parsing for Verilator and Icarus."""

    return _sv_parser_variants(
        _STRING_SV_VEC_DRIVER_TEXT(top),
        _packed_sv_vec_driver_text(top),
    )


def sv_monitor_text(top: str) -> str:
    """Render N-clock expected-output parsing for Verilator and Icarus."""

    return _sv_parser_variants(
        _STRING_SV_MONITOR_TEXT(top),
        _packed_sv_monitor_text(top),
    )


def sv_tb_text(top: str, testbench: str, clocks: ClockConfig) -> str:
    """Render the starter N-clock SV testbench from ``ClockConfig``."""

    clock_decls = "\n".join(
        f"  logic {domain.signal};\n  logic {domain.reset};" for domain in clocks.domains
    )
    clock_drivers = "\n".join(
        f"  always #{domain.period_ns / 2:g} {domain.signal} = ~{domain.signal};"
        for domain in clocks.domains
    )
    clock_pins = ",\n".join(
        f"    .{signal:<25}({signal})"
        for domain in clocks.domains
        for signal in (domain.signal, domain.reset)
    )
    clock_init = "\n".join(
        [f"    {domain.signal} = 1'b0;" for domain in clocks.domains]
        + [f"    {domain.reset} = 1'b{0 if domain.reset_polarity == 'high' else 1};" for domain in clocks.domains]
    )
    reset_assert = "\n".join(
        f"    {domain.reset} = 1'b{1 if domain.reset_polarity == 'high' else 0};"
        for domain in clocks.domains
    )
    reset_release = "\n".join(
        f"    {domain.reset} = 1'b{0 if domain.reset_polarity == 'high' else 1};"
        for domain in clocks.domains
    )
    primary = clocks.domains[0].signal
    tlul_helpers = render_packed_tlul_helpers("  ")
    return dedent(f"""\
    `timescale 1ns/1ps
    `include "include_{top}_tb.sv"
    `ifdef SYN
      `include "{top}_synth.v"
    `endif

    module {testbench};

      {clock_decls}
      logic test_en_i;

      logic [108:0] cfg_tl_i;
      logic [65:0]  cfg_tl_o;
      logic [108:0] dsp_tl_i;
      logic [65:0]  dsp_tl_o;

      logic rx_valid_i;
      logic rx_ready_o;
      logic signed [15:0] rx_sample_i;
      logic signed [15:0] rx_coeff_i;
      logic dsp_valid_o;
      logic dsp_ready_i;
      logic signed [31:0] dsp_result_o;
      logic dsp_above_threshold_o;
      logic dsp_overflow_o;

      string cfg_path;
      string data_in_path;
      string data_out_path;
      string wave_path;
      string sdf_path;
      integer errors;
      localparam integer INITIAL_RESET_CYCLES = 5;

{tlul_helpers}

      logic [31:0] exp_result [0:1023];
      logic        exp_above_threshold [0:1023];
      logic        exp_overflow [0:1023];
      integer exp_count;
      integer got_count;

      {clock_drivers}

      {top} u_dut (
        {clock_pins},
        .test_en_i             (test_en_i),
        .cfg_tl_i              (cfg_tl_i),
        .cfg_tl_o              (cfg_tl_o),
        .dsp_tl_i              (dsp_tl_i),
        .dsp_tl_o              (dsp_tl_o),
        .rx_valid_i            (rx_valid_i),
        .rx_ready_o            (rx_ready_o),
        .rx_sample_i           (rx_sample_i),
        .rx_coeff_i            (rx_coeff_i),
        .dsp_valid_o           (dsp_valid_o),
        .dsp_ready_i           (dsp_ready_i),
        .dsp_result_o          (dsp_result_o),
        .dsp_above_threshold_o (dsp_above_threshold_o),
        .dsp_overflow_o        (dsp_overflow_o)
      );

      // Verification helpers are split like the single-clock scaffold.
      `include "drivers/{top}_tlul_driver.svh"
      `include "drivers/{top}_vec_monitor.svh"
      `include "drivers/{top}_vec_driver.svh"

      initial begin
        errors = 0;
        {clock_init}
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
          $dumpvars(0, {testbench});
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

        repeat (2) @(posedge {primary});
        @(negedge {primary}); #1;
        {reset_assert}
        $display("[TB] initial reset pulse cycles=%0d", INITIAL_RESET_CYCLES);
        repeat (INITIAL_RESET_CYCLES) @(posedge {primary});
        @(negedge {primary}); #1;
        {reset_release}
        repeat (8) @(posedge {primary});

        load_config(cfg_path);
        load_expected(data_out_path);
        // Let cfg->rx/dsp synchronizers and gain sampling settle before traffic.
        repeat (8) @(posedge dsp_clk_i);
        fork
          run_inputs(data_in_path);
          check_outputs();
        join

        repeat (10) @(posedge dsp_clk_i);
        if (errors == 0) begin
          $display("[TB] PASS");
          $finish;
        end else begin
          $display("[TB] FAIL errors=%0d", errors);
          $fatal(1);
        end
      end

    endmodule
    """)

# ---------------------------------------------------------------------------
# cocotb scaffold

# cocotb scaffold


def _generate_nclock_testbench(top: str, output: Path, clocks: ClockConfig, *, force: bool) -> None:
    """Write the generated N-clock SV testbench and split drivers."""

    del force
    drivers = output / "drivers"
    drivers.mkdir(parents=True, exist_ok=True)
    files = {
        output / f"include_{top}_tb.sv": sv_include_text(top),
        drivers / f"{top}_tlul_driver.svh": sv_driver_text(top, clocks),
        drivers / f"{top}_vec_driver.svh": sv_vec_driver_text(top),
        drivers / f"{top}_vec_monitor.svh": sv_monitor_text(top),
        output / f"{top}_tb.sv": sv_tb_text(top, f"{top}_tb", clocks),
    }
    for path, text in files.items():
        safe_write_file(path, text, overwrite=True)


def generate_nclock_testbench(
    top: str, output: Path, clocks: ClockConfig, *, force: bool
) -> tuple[Path, ...]:
    """Recreate the complete machine-owned N-clock SystemVerilog scaffold."""

    with replace_generated_tree(output):
        _generate_nclock_testbench(top, output, clocks, force=force)
    return (
        output / f"include_{top}_tb.sv",
        output / "drivers" / f"{top}_tlul_driver.svh",
        output / "drivers" / f"{top}_vec_monitor.svh",
        output / "drivers" / f"{top}_vec_driver.svh",
        output / f"{top}_tb.sv",
    )


@dataclass(frozen=True, slots=True)
class CocotbConfig:
    """Configuration used to generate one cocotb testbench directory."""

    top: str
    interface: str
    output: Path
    rtl_dir: Path = Path("rtl")
    ips_root: Path | None = None
    simulator: str = "verilator"
    clk: str = "clk_i"
    rst: str = "rst_ni"
    rst_active: str = "low"
    period_ns: float = 10.0
    nbit: int = 32
    n_op: int = 10
    vsv: str = "sv"
    force: bool = False


def repo_root() -> Path:
    """Return the checkout root inferred from ``src/flexsoc/backend/dv``."""

    return Path(__file__).resolve().parents[4]


def find_top_file(rtl_dir: Path, top: str) -> Path | None:
    """Find the SystemVerilog file that defines the selected top module."""

    direct = rtl_dir / f"{top}.sv"
    if direct.exists():
        return direct
    return next((path for path in rtl_dir.rglob("*.sv") if path.stem == top), None)


def parse_decl(prefix: str, line: str) -> tuple[str | int, list[str]]:
    """Parse one compact Verilog port declaration into width and names."""

    tokens = line[len(prefix) :].strip().split()
    if tokens and tokens[0] in {"logic", "wire", "reg"}:
        tokens = tokens[1:]
    width: str | int = 1
    if tokens and tokens[0].startswith("["):
        width = tokens[0]
        tokens = tokens[1:]
    return width, [token.rstrip(",") for token in tokens if token.rstrip(",")]


def parse_top_ports(top_file: Path | None) -> dict[str, list]:
    """Parse simple top-level ports used by the generated wrapper."""

    empty = {"clk": [], "rst": [], "inputs": [], "outputs": []}
    if top_file is None:
        return empty
    try:
        text = top_file.read_text(encoding="utf-8", errors="ignore")
    except OSError:
        return empty
    match = re.search(r"module\s+\w+\s*\((.*?)\);\s", text, flags=re.S | re.M)
    header = text.split(");", 1)[0] if not match else match.group(1)
    lines = [re.sub(r"//.*", "", line).strip() for line in header.splitlines()]
    info: dict[str, list] = {"clk": [], "rst": [], "inputs": [], "outputs": []}
    for line in filter(None, lines):
        if line.startswith("input "):
            width, names = parse_decl("input ", line)
            for name in names:
                if "clk" in name:
                    info["clk"].append(name)
                if "rst" in name:
                    info["rst"].append(name)
                info["inputs"].append({"name": name, "width": width})
        elif line.startswith("output "):
            width, names = parse_decl("output ", line)
            info["outputs"].extend({"name": name, "width": width} for name in names)
    return info


def render_width(width: str | int) -> str:
    """Render a SystemVerilog logic declaration prefix from a parsed width."""

    return "logic" if width in {1, "1"} else f"logic {width}"


def render_extra_port_declarations(info: dict[str, list]) -> str:
    """Render non-control DUT ports needed by the cocotb wrapper."""

    control = set(info.get("clk", [])) | set(info.get("rst", [])) | {"tl_i", "tl_o"}
    decls: list[str] = []
    for entry in [*info.get("inputs", []), *info.get("outputs", [])]:
        name = entry.get("name", "")
        if not name or name in control or name.startswith(("clk", "rst")) or "::" in name:
            continue
        decls.append(f"  {render_width(entry.get('width', 1))} {name};")
    return "\n".join(decls)

def _serial_idle_high(name: str) -> bool:
    """Return true for asynchronous serial receive pins that idle high."""

    return name.lower() in {"cio_rx_i", "uart_rx_i", "serial_rx_i"}


def render_extra_input_initializers(info: dict[str, list]) -> str:
    """Initialize non-control DUT inputs before reset and configuration."""

    control = set(info.get("clk", [])) | set(info.get("rst", [])) | {"tl_i", "tl_o"}
    lines: list[str] = []
    for entry in info.get("inputs", []):
        name = entry.get("name", "")
        if not name or name in control or name.startswith(("clk", "rst")) or "::" in name:
            continue
        value = "'1" if _serial_idle_high(name) else "'0"
        lines.append(f"    {name} = {value};")
    return "\n".join(lines)


def read_filelist(path: Path) -> list[Path]:
    """Read an RTL filelist and return ordered source paths."""

    if not path.exists():
        return []
    base = path.parent
    sources: list[Path] = []
    for raw in path.read_text(encoding="utf-8", errors="ignore").splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        if line.startswith(("+incdir+", "-I", "+define+", "-D", "-f")):
            continue
        source = Path(line)
        sources.append((base / source).resolve() if not source.is_absolute() else source.resolve())
    return sources


def append_existing(paths: list[Path], seen: set[str], path: Path) -> None:
    """Append an existing source only once while preserving filelist order."""

    resolved = path.resolve()
    key = resolved.as_posix()
    if resolved.exists() and key not in seen:
        seen.add(key)
        paths.append(resolved)


def collect_sources(top: str, rtl_dir: Path, _ips_root: Path | None = None) -> list[Path]:
    """Collect Cocotb RTL sources from clean common/IP filelists."""

    rtl_dir = Path(rtl_dir)
    lists = [rtl_dir / "rtl_common.f", rtl_dir / "rtl_ip.f"]
    candidates = [src for flist in lists for src in read_filelist(flist)]
    if not candidates and (rtl_dir / "rtl_list.f").exists():
        candidates = read_filelist(rtl_dir / "rtl_list.f")
    if not candidates:
        candidates = sorted(rtl_dir.glob("*.sv")) + sorted(rtl_dir.glob("*.v"))
    seen: set[str] = set()
    ordered: list[Path] = []
    for source in candidates:
        append_existing(ordered, seen, source)
    for tail in (rtl_dir / "tl_main_pkg.sv", rtl_dir / "xbar_main.sv", rtl_dir / f"{top}.sv"):
        append_existing(ordered, seen, tail)
    return ordered


def render_source_block(paths: Sequence[Path], var_name: str = "VERILOG_SOURCES") -> str:
    """Render Cocotb VERILOG_SOURCES from the resolved RTL filelist."""

    if not paths:
        return f"# No RTL sources found; run the flist step first.\n{var_name} :="
    lines = ["# RTL sources expanded from rtl_common.f and rtl_ip.f", f"{var_name} := \\"]
    lines.extend(f"  {path.resolve()} \\" for path in paths[:-1])
    lines.append(f"  {paths[-1].resolve()}")
    return "\n".join(lines)

def render_gls_make_block(default_netlist: str) -> str:
    """Render one gate-level cocotb configuration shared by 1/N-clock TBs."""

    return dedent(f"""\
        SIM := icarus
        SIM_BUILD ?= sim_build/gls
        TIMING_MODE ?= zero
        GLS_UNIT_DELAY_DEFINE ?= 1
        GLS_INTERCONNECT ?= 0
        SDF_FILE ?=
        GLS_MODELS ?=
        GLS_NETLIST ?= {default_netlist}

        VERILOG_SOURCES += $(GLS_MODELS)
        VERILOG_SOURCES += $(GLS_NETLIST)
        COMPILE_ARGS += -g2012 -DSIM -DSYN -DFLEXSOC_GLS_EXTERNAL_MODELS -DFLEXSOC_COCOTB_WAVE_OWNER

        ifeq ($(TIMING_MODE),zero)
        COMPILE_ARGS += -DFUNCTIONAL -DUNIT_DELAY=\\#0 -gno-specify
        else ifeq ($(TIMING_MODE),unit)
        COMPILE_ARGS += -DFUNCTIONAL -gno-specify -DUNIT_DELAY=\\#$(GLS_UNIT_DELAY_DEFINE)
        else ifneq ($(filter $(TIMING_MODE),min typ max),)
        ifeq ($(strip $(SDF_FILE)),)
        $(error SDF_FILE is required when TIMING_MODE=$(TIMING_MODE))
        endif
        COMPILE_ARGS += -gspecify -T$(TIMING_MODE) -DFLEXSOC_ENABLE_SDF
        ifeq ($(GLS_INTERCONNECT),1)
        COMPILE_ARGS += -ginterconnect
        endif
        ifeq ($(TIMING_MODE),min)
        COMPILE_ARGS += -DFLEXSOC_SDF_MIN
        else ifeq ($(TIMING_MODE),typ)
        COMPILE_ARGS += -DFLEXSOC_SDF_TYP
        else
        COMPILE_ARGS += -DFLEXSOC_SDF_MAX
        endif
        COCOTB_PLUSARGS += +SDF=$(abspath $(SDF_FILE))
        else
        $(error TIMING_MODE must be zero, unit, min, typ, or max)
        endif
        """)


def render_makefile(cfg: CocotbConfig, sources: Sequence[Path]) -> str:
    """Render the cocotb Makefile for RTL or gate-level simulation."""

    repo = repo_root()
    out_dir = cfg.output.resolve()
    rtl_dir = cfg.rtl_dir.resolve()
    ips_root = (cfg.ips_root or repo / "hw" / "ips").resolve()
    include_dirs = [
        ips_root / "pkgs",
        ips_root / "prim",
        ips_root / "prim_opentitan",
        ips_root / "tlul",
    ]
    includes = " ".join(f"-I{path}" for path in [rtl_dir, *include_dirs])
    gate = render_gls_make_block(f"../../../../syn/$(PDK)/{cfg.top}_synth.v")
    return dedent(
        f"""\
        # Auto-generated Makefile
        SIM               ?= {cfg.simulator}
        TOPLEVEL_LANG     ?= verilog

        PWD               := $(shell pwd)
        COCOTB_TOPLEVEL   = {cfg.top}_tb
        COCOTB_TEST_MODULES = {cfg.top}_tb

        ifneq ($(filter clean veryclean distclean,$(MAKECMDGOALS)),)
          SIM := icarus
        endif

        ifeq ($(GATES),yes)
        {gate}
        else
        SIM_BUILD ?= sim_build/rtl

        {render_source_block(sources)}

        COMPILE_ARGS += --sv --timing
        WAVE_FORMAT ?= fst
        ifeq ($(WAVE_FORMAT),vcd)
        COMPILE_ARGS += --trace-vcd --trace-structs
        else
        COMPILE_ARGS += --trace-fst --trace-structs
        export IVERILOG_DUMPER := fst
        endif
        export WAVES ?= 1
        COMPILE_ARGS += -Wno-WIDTHEXPAND
        COMPILE_ARGS += -Wno-WIDTHTRUNC
        COMPILE_ARGS += -Wno-UNOPTFLAT
        endif

        COMPILE_ARGS += {includes}
        export COCOTB_RESULTS_FILE ?= $(abspath results.xml)
        TEST_NAME ?= smoke
        SEED ?= 1
        HDL_COVERAGE ?= 0
        COVERAGE_FILE ?= $(abspath ../../coverage/cocotb/$(TEST_NAME).dat)
        WAVE_FORMAT ?= fst
        WAVE_EXT ?= $(WAVE_FORMAT)
        WAVE_FILE ?= $(abspath ../../sim/rtl/{cfg.top}_tb_cocotb_$(TEST_NAME).$(WAVE_EXT))
        COCOTB_PLUSARGS += +WAVE=$(WAVE_FILE)
        ifeq ($(GATES),yes)
        COCOTB_PLUSARGS += +dumpfile_path=$(WAVE_FILE)
        endif

        override COVERAGE :=
        unexport COVERAGE

        ifeq ($(SIM),verilator)
        COCOTB_PLUSARGS += +verilator+seed+$(SEED)
        ifeq ($(HDL_COVERAGE),1)
        COMPILE_ARGS += --coverage-line --coverage-toggle --coverage-expr --coverage-fsm --coverage-user
        COCOTB_PLUSARGS += +verilator+coverage+file+$(COVERAGE_FILE)
        endif
        endif

        export TEST_NAME
        export FLEXSOC_SEED := $(SEED)
        export COCOTB_RANDOM_SEED := $(SEED)
        export TEST_ROOT ?= $(abspath ../../tests)
        export REG_CONFIG ?= $(TEST_ROOT)/$(TEST_NAME)/config.regs
        export CFG ?= $(REG_CONFIG)
        export DATA_IN  ?= $(TEST_ROOT)/$(TEST_NAME)/data_in.vec
        export DATA_OUT ?= $(TEST_ROOT)/$(TEST_NAME)/data_out.vec
        export PYTHONPATH := $(PWD):$(PYTHONPATH)
        VERILOG_SOURCES += {(out_dir / f"{cfg.top}_tb.sv").resolve()}

        COCOTB_MAKEFILES := $(shell cocotb-config --makefiles 2>/dev/null)
        ifeq ($(strip $(COCOTB_MAKEFILES)),)
        $(error cocotb is not installed in this environment; run: uv sync)
        endif
        include $(COCOTB_MAKEFILES)/Makefile.sim
        """
    )


def render_pipeline_model_py(top: str) -> str:
    """Render the reference model used by generated cocotb tests."""

    return dedent(
        f'''\
        """Auto-generated reference model for {top}."""

        def expected(data: int, coeff: int, mode: int = 0) -> int:
            if mode == 1:
                return (data ^ coeff) & 0xFFFFFFFF
            if mode == 2:
                return (data << 1) & 0xFFFFFFFF
            return (data + coeff) & 0xFFFFFFFF
        '''
    )


def _normalise_register_entries(registers) -> dict[str, int]:
    """Best-effort conversion of HJSON register metadata into a name/address map."""

    regmap: dict[str, int] = {}

    for entry in registers or []:
        name = None
        addr = None

        if isinstance(entry, dict):
            name = entry.get("name") or entry.get("reg") or entry.get("key")
            addr = (
                entry.get("offset")
                or entry.get("addr")
                or entry.get("address")
                or entry.get("byte_offset")
            )
        else:
            name = getattr(entry, "name", None)
            addr = (
                getattr(entry, "offset", None)
                or getattr(entry, "addr", None)
                or getattr(entry, "address", None)
                or getattr(entry, "byte_offset", None)
            )

        if not name or addr is None:
            continue

        try:
            value = int(str(addr), 0) & 0xFFFFFFFF
        except ValueError:
            continue

        key = str(name)
        regmap[key] = value
        regmap[key.upper()] = value
        regmap[key.split(".")[-1].upper()] = value

    return regmap


def render_reg_driver_py(registers=None) -> str:
    """Render generic cocotb register read/write helpers."""

    register_addrs = _normalise_register_entries(registers)

    body = r'''
from __future__ import annotations

from pathlib import Path

from cocotb.triggers import FallingEdge, RisingEdge, Timer

WRITE_TOKENS = {"@write", "write", "@reg_write", "reg_write"}
READ_TOKENS = {"@read", "read", "@reg_read", "reg_read"}

REGISTER_ADDRS = __REGISTER_ADDRS__


def parse_u32(text):
    """Parse one vector/config integer token.

    Keep this intentionally aligned with the SystemVerilog parser:
      - 0x/0b/0o prefixes select the base explicitly;
      - all-decimal digits are decimal, even with leading zeroes;
      - bare hex is accepted only when A-F/a-f is present.

    This avoids silently parsing vector cycles such as 40 as hex while still
    allowing values like ffffcdbc in legacy generated files.
    """

    raw = str(text).strip().replace("_", "")
    if not raw:
        return 0

    low = raw.lower()
    if low.startswith(("0x", "0b", "0o")):
        return int(raw, 0) & 0xFFFFFFFF

    if any(ch in "abcdefABCDEF" for ch in raw):
        return int(raw, 16) & 0xFFFFFFFF

    return int(raw, 10) & 0xFFFFFFFF


def load_register_map(*paths):
    """Load register aliases from generated metadata and optional comments."""

    regmap = dict(REGISTER_ADDRS)

    for item in paths:
        if item is None:
            continue

        path = Path(item)
        if not path.exists():
            continue

        for raw in path.read_text(encoding="utf-8").splitlines():
            line = raw.strip()
            if not line.startswith("#"):
                continue

            parts = line[1:].strip().split()
            if len(parts) < 3 or parts[0] != "map":
                continue

            value = parse_u32(parts[2])
            key = parts[1]
            regmap[key] = value
            regmap[key.upper()] = value
            regmap[key.split(".")[-1].upper()] = value

    return regmap


def resolve_register(reg_or_addr, regmap=None):
    token = str(reg_or_addr).strip()
    regmap = regmap or {}

    try:
        return parse_u32(token)
    except ValueError:
        pass

    for key in (token, token.upper(), token.split(".")[-1].upper()):
        if key in regmap:
            return int(regmap[key]) & 0xFFFFFFFF

    raise KeyError(f"unknown register/address token: {token}")


def _get(dut, name):
    if not hasattr(dut, name):
        raise AttributeError(f"generated cocotb wrapper does not expose {name}")
    return getattr(dut, name)


def has_tlul_proxy(dut):
    required = [
        "tl_i_a_valid",
        "tl_i_a_opcode",
        "tl_i_a_param",
        "tl_i_a_size",
        "tl_i_a_source",
        "tl_i_a_address",
        "tl_i_a_mask",
        "tl_i_a_data",
        "tl_i_d_ready",
        "tl_o_a_ready",
        "tl_o_d_valid",
        "tl_o_d_error",
        "tl_o_d_data",
    ]
    return all(hasattr(dut, name) for name in required)


def _clock(dut, clk=None):
    if clk is not None:
        return clk
    if hasattr(dut, "clk_i"):
        return dut.clk_i
    raise AttributeError("cannot infer cocotb clock; expected clk_i")


async def _sample_cycle(clk):
    """Sample DUT outputs on the rising edge, after delta-cycle settling."""

    await RisingEdge(clk)
    await Timer(1, unit="ps")


async def _drive_cycle(clk):
    """Drive DUT inputs on the falling edge, away from the active edge."""

    await FallingEdge(clk)
    await Timer(1, unit="ps")


def _known_int(dut, name, context):
    value = _get(dut, name).value
    try:
        return int(value)
    except ValueError as exc:
        raise AssertionError(
            f"{name} is X/Z while {context}; check reset and gate-level cell model mode"
        ) from exc


def _drive_idle(dut):
    _get(dut, "tl_i_a_valid").value = 0
    _get(dut, "tl_i_a_opcode").value = 4
    _get(dut, "tl_i_a_param").value = 0
    _get(dut, "tl_i_a_size").value = 2
    _get(dut, "tl_i_a_source").value = 0
    _get(dut, "tl_i_a_address").value = 0
    _get(dut, "tl_i_a_mask").value = 0
    _get(dut, "tl_i_a_data").value = 0
    _get(dut, "tl_i_d_ready").value = 1


async def init_register_bus(dut, clk=None):
    if not has_tlul_proxy(dut):
        return

    clk = _clock(dut, clk)
    _drive_idle(dut)
    await _sample_cycle(clk)


async def write_register(dut, reg_or_addr, data, mask=0xFFFFFFFF, *, regmap=None, clk=None):
    if not has_tlul_proxy(dut):
        raise RuntimeError("register write requested, but this cocotb wrapper has no TL-UL proxy signals")

    clk = _clock(dut, clk)
    addr = resolve_register(reg_or_addr, regmap)
    data = parse_u32(data)
    mask = parse_u32(mask) & 0xF
    if not mask:
        raise ValueError(f"TL-UL write mask is zero at addr=0x{addr:08x}")

    dut._log.info("reg write addr=0x%08x data=0x%08x mask=0x%x", addr, data, mask)

    await _drive_cycle(clk)
    _get(dut, "tl_i_d_ready").value = 1
    _get(dut, "tl_i_a_valid").value = 1
    _get(dut, "tl_i_a_opcode").value = 0 if mask == 0xF else 1  # PutFullData / PutPartialData
    _get(dut, "tl_i_a_param").value = 0
    _get(dut, "tl_i_a_size").value = 2
    _get(dut, "tl_i_a_source").value = 0
    _get(dut, "tl_i_a_address").value = addr
    _get(dut, "tl_i_a_mask").value = mask
    _get(dut, "tl_i_a_data").value = data

    guard = 0
    while True:
        await _sample_cycle(clk)
        if _known_int(dut, "tl_o_a_ready", f"waiting write a_ready addr=0x{addr:08x}"):
            break
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting a_ready on write addr=0x{addr:08x}")

    await _drive_cycle(clk)
    _get(dut, "tl_i_a_valid").value = 0

    guard = 0
    while True:
        await _sample_cycle(clk)
        if _known_int(dut, "tl_o_d_valid", f"waiting write d_valid addr=0x{addr:08x}"):
            break
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting d_valid on write addr=0x{addr:08x}")

    if _known_int(dut, "tl_o_d_error", f"checking write response addr=0x{addr:08x}"):
        raise AssertionError(f"TL-UL write error at addr=0x{addr:08x}")

    await _drive_cycle(clk)
    _drive_idle(dut)
    await _sample_cycle(clk)


async def read_register(dut, reg_or_addr, *, regmap=None, clk=None):
    if not has_tlul_proxy(dut):
        raise RuntimeError("register read requested, but this cocotb wrapper has no TL-UL proxy signals")

    clk = _clock(dut, clk)
    addr = resolve_register(reg_or_addr, regmap)

    dut._log.info("reg read addr=0x%08x", addr)

    await _drive_cycle(clk)
    _get(dut, "tl_i_d_ready").value = 1
    _get(dut, "tl_i_a_valid").value = 1
    _get(dut, "tl_i_a_opcode").value = 4  # Get
    _get(dut, "tl_i_a_param").value = 0
    _get(dut, "tl_i_a_size").value = 2
    _get(dut, "tl_i_a_source").value = 0
    _get(dut, "tl_i_a_address").value = addr
    _get(dut, "tl_i_a_mask").value = 0xF
    _get(dut, "tl_i_a_data").value = 0

    guard = 0
    while True:
        await _sample_cycle(clk)
        if _known_int(dut, "tl_o_a_ready", f"waiting read a_ready addr=0x{addr:08x}"):
            break
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting a_ready on read addr=0x{addr:08x}")

    await _drive_cycle(clk)
    _get(dut, "tl_i_a_valid").value = 0

    guard = 0
    while True:
        await _sample_cycle(clk)
        if _known_int(dut, "tl_o_d_valid", f"waiting read d_valid addr=0x{addr:08x}"):
            break
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting d_valid on read addr=0x{addr:08x}")

    if _known_int(dut, "tl_o_d_error", f"checking read response addr=0x{addr:08x}"):
        raise AssertionError(f"TL-UL read error at addr=0x{addr:08x}")

    data = _known_int(dut, "tl_o_d_data", f"reading response data addr=0x{addr:08x}") & 0xFFFFFFFF
    dut._log.info("reg read addr=0x%08x data=0x%08x", addr, data)

    await _drive_cycle(clk)
    _drive_idle(dut)
    await _sample_cycle(clk)

    return data


async def run_register_config(dut, cfg_path, *, regmap=None, clk=None):
    path = Path(cfg_path)
    if not path.exists():
        dut._log.info("register config not found: %s", path)
        return

    merged_map = dict(regmap or {})
    merged_map.update(load_register_map(path))

    writes = 0

    for raw_line in path.read_text(encoding="utf-8").splitlines():
        line = raw_line.split("#", 1)[0].strip()
        if not line:
            continue

        parts = line.split()
        if parts and parts[0] in WRITE_TOKENS:
            parts = parts[1:]

        if len(parts) < 2:
            dut._log.warning("malformed config row: %s", raw_line)
            continue

        reg = parts[0]
        data = parts[1]
        mask = parts[2] if len(parts) >= 3 else "0xffffffff"
        wait_cycles = int(parts[3], 0) if len(parts) >= 4 else 1

        await write_register(dut, reg, data, mask, regmap=merged_map, clk=clk)
        writes += 1

        for _ in range(max(0, wait_cycles)):
            await _cycle(_clock(dut, clk))

    if writes == 0:
        dut._log.info("no register config writes from %s; continuing", path)
'''

    return body.lstrip().replace("__REGISTER_ADDRS__", repr(register_addrs))

def render_vec_monitor_py() -> str:
    """Render a generic cocotb expected-output monitor."""

    return r"""from __future__ import annotations

import re
from collections import defaultdict
from pathlib import Path

from drivers.reg_driver import READ_TOKENS, parse_u32

_SIGNAL_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_./:-]*$")


def _looks_like_signal(token):
    return bool(_SIGNAL_RE.match(str(token)))


class LatencyMonitor:
    def __init__(self, dut, expected_path=None, *, register_reader=None):
        self.dut = dut
        self.expected = defaultdict(list)
        self.guarded = []
        self.last_cycle = -1
        self.register_reader = register_reader
        self._load(expected_path)

    def _load(self, path):
        if path is None:
            return

        path = Path(path)
        if not path.exists():
            return

        for lineno, raw_line in enumerate(path.read_text(encoding="utf-8").splitlines(), start=1):
            line = raw_line.split("#", 1)[0].strip()
            if not line:
                continue

            parts = line.split()
            if len(parts) < 3:
                raise ValueError(
                    f"{path}:{lineno}: expected cycle/valid signal and command/pairs"
                )

            first = parts[0]
            try:
                cycle = parse_u32(first)
            except ValueError:
                if not _looks_like_signal(first):
                    raise ValueError(f"{path}:{lineno}: invalid cycle/valid token: {first}")
                if (len(parts) - 1) % 2 != 0:
                    raise ValueError(
                        f"{path}:{lineno}: valid-guarded row must be "
                        "<valid_signal> <signal> <expected> [<signal> <expected> ...]"
                    )
                checks = []
                for idx in range(1, len(parts), 2):
                    name = parts[idx]
                    if not _looks_like_signal(name):
                        raise ValueError(f"{path}:{lineno}: invalid signal name: {name}")
                    checks.append((name, parse_u32(parts[idx + 1])))
                self.guarded.append((first, checks))
                continue

            self.last_cycle = max(self.last_cycle, cycle)
            command = parts[1]

            if command in READ_TOKENS:
                if len(parts) not in (4, 5):
                    raise ValueError(f"{path}:{lineno}: @read format is: cycle @read reg expected [mask]")
                mask = parts[4] if len(parts) == 5 else "0xffffffff"
                self.expected[cycle].append(("@read", parts[2], parse_u32(parts[3]), parse_u32(mask)))
                continue

            if (len(parts) - 1) % 2 != 0:
                raise ValueError(f"{path}:{lineno}: expected cycle followed by signal/value pairs")

            for idx in range(1, len(parts), 2):
                name = parts[idx]
                if not _looks_like_signal(name):
                    raise ValueError(f"{path}:{lineno}: invalid signal name: {name}")
                self.expected[cycle].append((name, parse_u32(parts[idx + 1])))

    def has_pending_guarded(self):
        return bool(self.guarded)

    def _read_signal(self, name):
        if not hasattr(self.dut, name):
            raise AssertionError(f"unknown expected-output vector signal: {name}")
        return int(getattr(self.dut, name).value) & 0xFFFFFFFF

    def _check_signal(self, cycle, name, expected):
        got = self._read_signal(name)
        if got != expected:
            raise AssertionError(
                f"cycle={cycle} {name}: got 0x{got:08x}, expected 0x{expected:08x}"
            )
        self.dut._log.info("check %s == 0x%08x", name, expected)

    async def check(self, cycle):
        for item in self.expected.pop(cycle, []):
            name = item[0]

            if name in READ_TOKENS:
                if self.register_reader is None:
                    raise AssertionError("@read row requested but no register_reader was provided")

                _, reg, expected, mask = item
                got = await self.register_reader(reg)
                if (got & mask) != (expected & mask):
                    raise AssertionError(
                        f"cycle={cycle} read {reg}: got 0x{got:08x}, "
                        f"expected 0x{expected:08x}, mask 0x{mask:08x}"
                    )

                self.dut._log.info("read check %s == 0x%08x mask=0x%08x", reg, expected, mask)
                continue

            self._check_signal(cycle, name, item[1])

        if self.guarded:
            valid_signal, checks = self.guarded[0]
            if self._read_signal(valid_signal) & 0x1:
                for name, expected in checks:
                    self._check_signal(cycle, name, expected)
                self.dut._log.info("guarded output row consumed on %s", valid_signal)
                self.guarded.pop(0)
"""

def render_vec_driver_py() -> str:
    """Render a generic cocotb input-vector driver."""

    return r"""from __future__ import annotations

import os
import re
from pathlib import Path

from cocotb.triggers import Combine, FallingEdge, RisingEdge, Timer

from drivers.reg_driver import WRITE_TOKENS, parse_u32

CONFIG_TOKENS = {"@cfg", "cfg", "@config", "config"}
RESET_TOKENS = {"@reset", "reset"}
_SIGNAL_RE = re.compile(r"^[@A-Za-z_][A-Za-z0-9_./:-]*$")


def _looks_like_signal(token):
    return bool(_SIGNAL_RE.match(str(token)))


def load_vectors(path=None):
    rows = []

    if path is None:
        return rows

    path = Path(path)
    if not path.exists():
        return rows

    for lineno, raw_line in enumerate(path.read_text(encoding="utf-8").splitlines(), start=1):
        line = raw_line.split("#", 1)[0].strip()
        if not line:
            continue

        parts = line.split()
        if len(parts) < 3:
            raise ValueError(f"{path}:{lineno}: expected cycle and command/pairs")

        cycle = parse_u32(parts[0])
        command = parts[1]

        if command in CONFIG_TOKENS:
            if len(parts) != 3:
                raise ValueError(f"{path}:{lineno}: @cfg format is: cycle @cfg path")
            rows.append((cycle, [("@cfg", parts[2])]))
            continue

        if command in WRITE_TOKENS:
            if len(parts) not in (4, 5):
                raise ValueError(f"{path}:{lineno}: @write format is: cycle @write reg data [mask]")
            mask = parts[4] if len(parts) == 5 else "0xffffffff"
            rows.append((cycle, [("@write", parts[2], parse_u32(parts[3]), parse_u32(mask))]))
            continue

        if command in RESET_TOKENS:
            if len(parts) == 3:
                selector, cycles = "all", parts[2]
            elif len(parts) == 4:
                selector, cycles = parts[2], parts[3]
            else:
                raise ValueError(
                    f"{path}:{lineno}: @reset format is: "
                    "cycle @reset [domain|reset] cycles"
                )
            rows.append((cycle, [("@reset", selector, parse_u32(cycles))]))
            continue

        if (len(parts) - 1) % 2 != 0:
            raise ValueError(f"{path}:{lineno}: expected cycle followed by signal/value pairs")

        pairs = []
        for idx in range(1, len(parts), 2):
            name = parts[idx]
            if not _looks_like_signal(name):
                raise ValueError(f"{path}:{lineno}: invalid signal name: {name}")
            pairs.append((name, parse_u32(parts[idx + 1])))

        rows.append((cycle, pairs))

    return rows


def _coalesce_rows(rows):
    # Return deterministic atomic vector batches grouped by logical cycle.
    # Multiple signal rows with the same cycle are one transaction and are
    # driven together. Commands consume simulator time and therefore cannot be
    # mixed with signal drives or another command on the same logical cycle.

    ordered = sorted(enumerate(rows), key=lambda item: (item[1][0], item[0]))
    grouped = []
    for _, (cycle, pairs) in ordered:
        if grouped and grouped[-1][0] == cycle:
            grouped[-1][1].extend(pairs)
        else:
            grouped.append([cycle, list(pairs)])

    special_tokens = CONFIG_TOKENS | WRITE_TOKENS | RESET_TOKENS
    result = []
    for cycle, pairs in grouped:
        special = [item for item in pairs if item and item[0] in special_tokens]
        if special and (len(special) != 1 or len(pairs) != 1):
            raise ValueError(
                f"cycle {cycle}: commands cannot share a cycle with another command or signal drive"
            )
        result.append((cycle, pairs))
    return result


async def _advance(clk, count=1):
    for _ in range(max(0, int(count))):
        await RisingEdge(clk)


def _configured_reset_domains():
    raw = os.environ.get("CLOCK_DOMAINS", "").strip()
    domains = []
    for item in raw.replace(";", ",").split(","):
        parts = [part.strip() for part in item.split(":") if part.strip()]
        if len(parts) in {4, 5}:
            domain, clock, reset = parts[:3]
            polarity = parts[4].lower() if len(parts) == 5 else "low"
            domains.append((domain, clock, reset, polarity))
    return tuple(domains or (("core", "clk_i", "rst_ni", "low"),))


def _selected_reset_domains(selector):
    clean = str(selector or "all")
    domains = _configured_reset_domains()
    if clean in {"all", "*"}:
        return domains
    selected = tuple(item for item in domains if clean in {item[0], item[2]})
    if not selected:
        raise AssertionError(f"unknown reset selector: {clean}")
    return selected


async def _default_reset_runner(dut, selector, cycles):
    selected = _selected_reset_domains(selector)
    for name in ("cio_rx_i", "uart_rx_i", "serial_rx_i"):
        if hasattr(dut, name):
            getattr(dut, name).value = 1
    for _, _, reset, polarity in selected:
        if not hasattr(dut, reset):
            raise AssertionError(f"reset signal not found on DUT: {reset}")
        getattr(dut, reset).value = int(polarity == "high")
    for _ in range(max(1, int(cycles))):
        await Combine(*(RisingEdge(getattr(dut, clock)) for _, clock, _, _ in selected))
    await Combine(*(FallingEdge(getattr(dut, clock)) for _, clock, _, _ in selected))
    for _, _, reset, polarity in selected:
        getattr(dut, reset).value = int(polarity == "low")


async def _drive_one(dut, name, value):
    if not hasattr(dut, name):
        raise AssertionError(f"unknown input vector signal: {name}")

    signal = getattr(dut, name)
    width = len(signal)
    value = int(value) & ((1 << width) - 1)
    signal.value = value
    dut._log.info("drive %s <= 0x%x", name, value)
    return True


async def drive_vectors(
    dut,
    clk,
    rows,
    monitor=None,
    config_runner=None,
    register_writer=None,
    reset_runner=None,
):
    now = -1
    applied = 0

    for cycle, pairs in _coalesce_rows(rows):
        if not pairs:
            continue

        while now < cycle - 1:
            await _advance(clk)
            now += 1
            if monitor is not None:
                await monitor.check(now)

        await FallingEdge(clk)
        await Timer(1, unit="ps")

        dut._log.info("vector cycle=%d", cycle)

        if pairs[0][0] in RESET_TOKENS:
            _, selector, cycles = pairs[0]
            cycles = max(1, int(cycles))
            dut._log.info(
                "[TB][RESET] cycle=%d selector=%s cycles=%d",
                cycle, selector, cycles,
            )
            if reset_runner is None:
                await _default_reset_runner(dut, selector, cycles)
            else:
                await reset_runner(selector, cycles)
            applied += 1
            now = cycle + cycles - 1
            continue

        for item in pairs:
            name = item[0]

            if name in CONFIG_TOKENS:
                if config_runner is None:
                    raise AssertionError("@cfg row requested but no config_runner was provided")
                await config_runner(item[1])
                applied += 1
                continue

            if name in WRITE_TOKENS:
                if register_writer is None:
                    raise AssertionError("@write row requested but no register_writer was provided")
                _, reg, data, mask = item
                await register_writer(reg, data, mask)
                applied += 1
                continue

            if await _drive_one(dut, name, item[1]):
                applied += 1

        await RisingEdge(clk)
        await Timer(1, unit="ns")
        now = cycle

        if monitor is not None:
            await monitor.check(now)

    final_cycle = now + 8
    if monitor is not None:
        final_cycle = max(final_cycle, monitor.last_cycle)
    guarded_deadline = now + 4096

    while now < final_cycle or (monitor is not None and monitor.has_pending_guarded()):
        if (
            monitor is not None
            and monitor.has_pending_guarded()
            and now >= guarded_deadline
        ):
            raise AssertionError("timed out waiting for valid-guarded output checks")
        await _advance(clk)
        now += 1
        if monitor is not None:
            await monitor.check(now)

    if applied == 0:
        raise AssertionError("no vector inputs or register writes were applied")
"""

def render_python_test(
    top: str,
    clk: str,
    rst: str,
    rst_active: str,
    period_ns: float,
    reset_domain: str = "core",
) -> str:
    """Render the generated single-clock cocotb test module."""

    reset_domains = {reset_domain: (clk, rst, rst_active)}
    return f"""from __future__ import annotations

import os
from pathlib import Path

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import Combine, FallingEdge, RisingEdge, Timer

from drivers.reg_driver import (
    init_register_bus,
    load_register_map,
    read_register,
    run_register_config,
    write_register,
)
from drivers.vec_driver import drive_vectors, load_vectors
from drivers.vec_monitor import LatencyMonitor


RESET_DOMAINS = {reset_domains!r}


def _selected_resets(selector):
    clean = str(selector or "all")
    if clean in {{"all", "*"}}:
        return tuple(RESET_DOMAINS.values())
    for domain, item in RESET_DOMAINS.items():
        if clean in {{domain, item[1]}}:
            return (item,)
    raise AssertionError(f"unknown reset selector: {{clean}}")


async def apply_reset(dut, selector="all", cycles=5):
    selected = _selected_resets(selector)
    for name in ("cio_rx_i", "uart_rx_i", "serial_rx_i"):
        if hasattr(dut, name):
            getattr(dut, name).value = 1
    for _, reset, polarity in selected:
        getattr(dut, reset).value = int(polarity == "high")
    for _ in range(max(1, int(cycles))):
        await Combine(*(RisingEdge(getattr(dut, clock)) for clock, _, _ in selected))
    await Combine(*(FallingEdge(getattr(dut, clock)) for clock, _, _ in selected))
    for _, reset, polarity in selected:
        getattr(dut, reset).value = int(polarity == "low")
    await Timer(1, unit="ns")


@cocotb.test()
async def {top}_generated_test(dut):
    cocotb.start_soon(Clock(dut.{clk}, {period_ns:g}, unit="ns").start())
    for _, reset, polarity in RESET_DOMAINS.values():
        getattr(dut, reset).value = int(polarity == "low")
    await init_register_bus(dut, dut.{clk})
    reset_cycles = max(1, int(os.environ.get("INITIAL_RESET_CYCLES", "5")))
    dut._log.info("initial reset cycles=%d", reset_cycles)
    await apply_reset(dut, "all", reset_cycles)
    for _ in range(2):
        await RisingEdge(dut.{clk})

    test_name = os.environ.get("TEST_NAME", "smoke")
    test_root = Path(os.environ.get("TEST_ROOT", "tests"))
    test_dir = test_root / test_name

    cfg_path = Path(os.environ.get("REG_CONFIG", test_dir / "config.regs"))
    data_in = Path(os.environ.get("DATA_IN", test_dir / "data_in.vec"))
    data_out = Path(os.environ.get("DATA_OUT", test_dir / "data_out.vec"))

    dut._log.info("TEST_NAME=%s", test_name)
    dut._log.info("REG_CONFIG=%s", cfg_path)
    dut._log.info("DATA_IN=%s", data_in)
    dut._log.info("DATA_OUT=%s", data_out)

    regmap = load_register_map(cfg_path, data_in, data_out)

    async def apply_config(path):
        await run_register_config(dut, path, regmap=regmap, clk=dut.{clk})

    async def do_write(reg, data, mask):
        await write_register(dut, reg, data, mask, regmap=regmap, clk=dut.{clk})

    async def do_read(reg):
        return await read_register(dut, reg, regmap=regmap, clk=dut.{clk})

    async def do_reset(selector, cycles):
        await apply_reset(dut, selector, cycles)

    await apply_config(cfg_path)

    await drive_vectors(
        dut,
        dut.{clk},
        load_vectors(data_in),
        LatencyMonitor(dut, data_out, register_reader=do_read),
        config_runner=apply_config,
        register_writer=do_write,
        reset_runner=do_reset,
    )
"""

def render_tlul_wrapper(cfg: CocotbConfig) -> str:
    """Render a package-free TL-UL wrapper used by RTL and gate cocotb runs."""

    port_info = parse_top_ports(find_top_file(cfg.rtl_dir, cfg.top))
    extra_decls = render_extra_port_declarations(port_info)
    extra_init = render_extra_input_initializers(port_info)
    helpers = render_packed_tlul_helpers("  ")
    return dedent(
        f"""\
        `timescale 1ns/1ps
        module {cfg.top}_tb;
          logic {cfg.clk};
          logic {cfg.rst};
        {extra_decls}
          logic         tl_i_a_valid;
          logic [2:0]   tl_i_a_opcode;
          logic [2:0]   tl_i_a_param;
          logic [1:0]   tl_i_a_size;
          logic [7:0]   tl_i_a_source;
          logic [31:0]  tl_i_a_address;
          logic [3:0]   tl_i_a_mask;
          logic [31:0]  tl_i_a_data;
          logic         tl_i_d_ready;
          logic         tl_o_d_valid;
          logic [2:0]   tl_o_d_opcode;
          logic [31:0]  tl_o_d_data;
          logic         tl_o_d_error;
          logic         tl_o_a_ready;
          logic [108:0] tl_i;
          logic [65:0]  tl_o;

        {helpers}

          initial begin
        {extra_init}
          end

          assign tl_i = flexsoc_tlul_h2d(
            tl_i_a_valid, tl_i_a_opcode, tl_i_a_param, tl_i_a_size,
            tl_i_a_source, tl_i_a_address, tl_i_a_mask, tl_i_a_data, tl_i_d_ready
          );
          assign tl_o_d_valid  = tl_o[65];
          assign tl_o_d_opcode = tl_o[64:62];
          assign tl_o_d_data   = tl_o[47:16];
          assign tl_o_d_error  = tl_o[1];
          assign tl_o_a_ready  = tl_o[0];

          string wave_path;
          initial begin
            if (!$value$plusargs("WAVE=%s", wave_path)) begin
              if (!$value$plusargs("VCD=%s", wave_path)) wave_path = "";
            end
            if (wave_path != "") begin
              `ifdef FLEXSOC_COCOTB_WAVE_OWNER
                $display("[TB] dumpfile = %s owner=cocotb", wave_path);
              `else
                $display("[TB] dumpfile = %s owner=wrapper", wave_path);
                $dumpfile(wave_path);
                $dumpvars(0, {cfg.top}_tb);
              `endif
            end
            #1;
          end
          `ifdef FLEXSOC_ENABLE_SDF
            string sdf_path;
            initial begin
              if (!$value$plusargs("SDF=%s", sdf_path)) sdf_path = "";
              if (sdf_path != "") begin
                `ifdef FLEXSOC_SDF_MIN
                  $display("[TB] sdf = %s scope=u_{cfg.top} mode=MINIMUM", sdf_path);
                  $sdf_annotate(sdf_path, u_{cfg.top});
                `elsif FLEXSOC_SDF_TYP
                  $display("[TB] sdf = %s scope=u_{cfg.top} mode=TYPICAL", sdf_path);
                  $sdf_annotate(sdf_path, u_{cfg.top});
                `else
                  $display("[TB] sdf = %s scope=u_{cfg.top} mode=MAXIMUM", sdf_path);
                  $sdf_annotate(sdf_path, u_{cfg.top});
                `endif
              end
            end
          `endif
          {cfg.top} u_{cfg.top} (
            .{cfg.clk}({cfg.clk}),
            .{cfg.rst}({cfg.rst}),
            .*
          );
        endmodule
        """
    )

def _write_cocotb_scaffold_impl(
    cfg: CocotbConfig, clocks: ClockConfig | None = None
) -> list[Path]:
    """Write the cocotb scaffold and return generated paths."""

    clocks = clocks or clock_config()
    out_dir = cfg.output.resolve()
    drivers = out_dir / "drivers"
    drivers.mkdir(parents=True, exist_ok=True)
    sources = collect_sources(cfg.top, cfg.rtl_dir.resolve(), cfg.ips_root)
    hjson_path = _candidate_hjson_path(cfg.rtl_dir, cfg.top)
    registers = _register_entries(hjson_path)
    files = {
        out_dir / "Makefile": render_makefile(cfg, sources),
        drivers / "reg_driver.py": render_reg_driver_py(registers),
        drivers / "vec_driver.py": render_vec_driver_py(),
        drivers / "vec_monitor.py": render_vec_monitor_py(),
        out_dir / f"{cfg.top}_tb.py": render_python_test(
            cfg.top, cfg.clk, cfg.rst, cfg.rst_active, cfg.period_ns,
            next(
                (domain.name for domain in clocks.domains if domain.reset == cfg.rst),
                clocks.domains[0].name,
            ),
        ),
        out_dir / f"{cfg.top}_tb.sv": render_tlul_wrapper(cfg),
    }
    for stale in (
        out_dir / "utils.py",
        out_dir / "__init__.py",
        drivers / "__init__.py",
        drivers / "driver_reg_iface.py",
        drivers / "driver_tlul.py",
    ):
        if stale.exists():
            stale.unlink()
    for path, text in files.items():
        path.write_text(text, encoding="utf-8")
    return list(files)

def _generated_tlul_wrapper_path(config: CocotbConfig) -> Path:
    """Return the generated TL-UL wrapper path for a Cocotb scaffold."""

    return Path(config.output) / f"{config.top}_tb.sv"


def _render_tlul_wrapper(config: CocotbConfig, previous_text: str) -> str:
    """Regenerate the canonical package-free TL-UL wrapper."""

    del previous_text
    return render_tlul_wrapper(config)

def _format_generated_tlul_wrapper(config: CocotbConfig) -> None:
    """Post-format the generated TL-UL wrapper if the scaffold emitted one."""

    path = _generated_tlul_wrapper_path(config)
    if not path.exists():
        return
    text = path.read_text(encoding="utf-8")
    if "tl_i_a_valid" not in text or f"module {config.top}_tb" not in text:
        return
    path.write_text(_render_tlul_wrapper(config, text), encoding="utf-8")

def write_cocotb_scaffold(
    config: CocotbConfig, clocks: ClockConfig | None = None
) -> list[Path]:
    """Recreate the complete machine-owned cocotb scaffold."""

    clocks = clocks or clock_config()
    if clocks.multiclock:
        return write_nclock_cocotb(config, clocks)
    with replace_generated_tree(config.output):
        written = _write_cocotb_scaffold_impl(config, clocks)
        if config.interface == "tlul":
            _format_generated_tlul_wrapper(config)
        if written is None:
            return sorted(path for path in Path(config.output).iterdir() if path.is_file())
        return written
def cocotb_sv_text(top: str, clocks: ClockConfig) -> str:
    """Render the package-free N-clock cocotb wrapper with two TL-UL proxies."""

    clock_decls = "\n".join(
        f"  logic {domain.signal};\n  logic {domain.reset};" for domain in clocks.domains
    )
    clock_pins = ",\n".join(
        f"    .{signal:<25}({signal})"
        for domain in clocks.domains
        for signal in (domain.signal, domain.reset)
    )
    helpers = render_packed_tlul_helpers("  ")
    return dedent(f"""\
    `timescale 1ns/1ps

    module {top}_tb;
      {clock_decls}
      logic test_en_i;

      logic [108:0] cfg_tl_i;
      logic [65:0]  cfg_tl_o;
      logic [108:0] dsp_tl_i;
      logic [65:0]  dsp_tl_o;

      logic        cfg_a_valid;
      logic [2:0]  cfg_a_opcode;
      logic [2:0]  cfg_a_param;
      logic [1:0]  cfg_a_size;
      logic [7:0]  cfg_a_source;
      logic [31:0] cfg_a_address;
      logic [3:0]  cfg_a_mask;
      logic [31:0] cfg_a_data;
      logic        cfg_d_ready;
      logic        cfg_a_ready;
      logic        cfg_d_valid;
      logic [31:0] cfg_d_data;
      logic        cfg_d_error;

      logic        dsp_a_valid;
      logic [2:0]  dsp_a_opcode;
      logic [2:0]  dsp_a_param;
      logic [1:0]  dsp_a_size;
      logic [7:0]  dsp_a_source;
      logic [31:0] dsp_a_address;
      logic [3:0]  dsp_a_mask;
      logic [31:0] dsp_a_data;
      logic        dsp_d_ready;
      logic        dsp_a_ready;
      logic        dsp_d_valid;
      logic [31:0] dsp_d_data;
      logic        dsp_d_error;

      logic rx_valid_i;
      logic rx_ready_o;
      logic signed [15:0] rx_sample_i;
      logic signed [15:0] rx_coeff_i;
      logic dsp_valid_o;
      logic dsp_ready_i;
      logic signed [31:0] dsp_result_o;
      logic dsp_above_threshold_o;
      logic dsp_overflow_o;

{helpers}

      assign cfg_tl_i = flexsoc_tlul_h2d(
        cfg_a_valid, cfg_a_opcode, cfg_a_param, cfg_a_size, cfg_a_source,
        cfg_a_address, cfg_a_mask, cfg_a_data, cfg_d_ready
      );
      assign dsp_tl_i = flexsoc_tlul_h2d(
        dsp_a_valid, dsp_a_opcode, dsp_a_param, dsp_a_size, dsp_a_source,
        dsp_a_address, dsp_a_mask, dsp_a_data, dsp_d_ready
      );

      assign cfg_a_ready = cfg_tl_o[0];
      assign cfg_d_valid = cfg_tl_o[65];
      assign cfg_d_data  = cfg_tl_o[47:16];
      assign cfg_d_error = cfg_tl_o[1];
      assign dsp_a_ready = dsp_tl_o[0];
      assign dsp_d_valid = dsp_tl_o[65];
      assign dsp_d_data  = dsp_tl_o[47:16];
      assign dsp_d_error = dsp_tl_o[1];

      `ifdef FLEXSOC_ENABLE_SDF
        string sdf_path;
        initial begin
          if (!$value$plusargs("SDF=%s", sdf_path)) sdf_path = "";
          if (sdf_path != "") begin
            `ifdef FLEXSOC_SDF_MIN
              $display("[TB] sdf = %s scope=u_dut mode=MINIMUM", sdf_path);
              $sdf_annotate(sdf_path, u_dut);
            `elsif FLEXSOC_SDF_TYP
              $display("[TB] sdf = %s scope=u_dut mode=TYPICAL", sdf_path);
              $sdf_annotate(sdf_path, u_dut);
            `else
              $display("[TB] sdf = %s scope=u_dut mode=MAXIMUM", sdf_path);
              $sdf_annotate(sdf_path, u_dut);
            `endif
          end
        end
      `endif

      {top} u_dut (
{clock_pins},
        .test_en_i             (test_en_i),
        .cfg_tl_i              (cfg_tl_i),
        .cfg_tl_o              (cfg_tl_o),
        .dsp_tl_i              (dsp_tl_i),
        .dsp_tl_o              (dsp_tl_o),
        .rx_valid_i            (rx_valid_i),
        .rx_ready_o            (rx_ready_o),
        .rx_sample_i           (rx_sample_i),
        .rx_coeff_i            (rx_coeff_i),
        .dsp_valid_o           (dsp_valid_o),
        .dsp_ready_i           (dsp_ready_i),
        .dsp_result_o          (dsp_result_o),
        .dsp_above_threshold_o (dsp_above_threshold_o),
        .dsp_overflow_o        (dsp_overflow_o)
      );
    endmodule
    """)

def cocotb_makefile_text(
    top: str,
    rtl_dir: Path,
    *,
    ips_root: Path | None = None,
    simulator: str = "verilator",
) -> str:
    """Render a cocotb Makefile bound to the current run and checkout paths."""

    rtl_dir = rtl_dir.resolve()
    ips_root = (ips_root or repo_root() / "hw" / "ips").resolve()
    include_args = " ".join(
        f"-I{path}"
        for path in (
            rtl_dir,
            ips_root / "pkgs",
            ips_root / "prim",
            ips_root / "prim_opentitan",
            ips_root / "tlul",
        )
    )
    common_filelist = rtl_dir / "rtl_common.f"
    ip_filelist = rtl_dir / "rtl_ip.f"
    gate = render_gls_make_block(f"../../../../syn/$(PDK)/{top}_synth.v")
    return dedent(f"""\
    SIM ?= {simulator}
    TOPLEVEL_LANG ?= verilog
    COCOTB_TOPLEVEL = {top}_tb
    COCOTB_TEST_MODULES = {top}_tb

    ifeq ($(GATES),yes)
    {gate}
    else
    SIM_BUILD ?= sim_build/rtl
    EXTRA_ARGS += -f {common_filelist}
    EXTRA_ARGS += -f {ip_filelist}
    EXTRA_ARGS += {include_args}
    EXTRA_ARGS += -Wno-fatal
    endif

    VERILOG_SOURCES += $(PWD)/{top}_tb.sv
    export TEST_NAME ?= smoke
    export TEST_ROOT ?= $(abspath ../../tests)
    SEED ?= 1
    HDL_COVERAGE ?= 0
    COVERAGE_FILE ?= $(abspath ../../coverage/cocotb/$(TEST_NAME).dat)
    WAVE_FORMAT ?= fst
    WAVE_EXT ?= $(WAVE_FORMAT)
    WAVE_FILE ?= $(abspath ../../sim/rtl/{top}_tb_cocotb_$(TEST_NAME).$(WAVE_EXT))
    COCOTB_PLUSARGS += +WAVE=$(WAVE_FILE)

    override COVERAGE :=
    unexport COVERAGE

    ifeq ($(SIM),verilator)
      COCOTB_PLUSARGS += +verilator+seed+$(SEED)
      ifeq ($(HDL_COVERAGE),1)
        EXTRA_ARGS += --coverage-line --coverage-toggle --coverage-expr --coverage-fsm --coverage-user
        COCOTB_PLUSARGS += +verilator+coverage+file+$(COVERAGE_FILE)
      endif
    endif
    export FLEXSOC_SEED := $(SEED)
    export COCOTB_RANDOM_SEED := $(SEED)
    export CFG ?= $(TEST_ROOT)/$(TEST_NAME)/config.regs
    export REG_CONFIG ?= $(CFG)
    export DATA_IN ?= $(TEST_ROOT)/$(TEST_NAME)/data_in.vec
    export DATA_OUT ?= $(TEST_ROOT)/$(TEST_NAME)/data_out.vec
    include $(shell cocotb-config --makefiles)/Makefile.sim
    """)


def cocotb_reg_driver_py_text(top: str, clocks: ClockConfig) -> str:
    """Render TL-UL helpers bound to the canonical clock/reset domains."""

    clock_map = {domain.name: domain.signal for domain in clocks.domains}
    reset_map = {
        domain.name: (domain.signal, domain.reset, domain.reset_polarity)
        for domain in clocks.domains
    }
    primary = clocks.domains[0].signal
    settle = clocks.domains[-1].signal
    text = dedent("""\
    from __future__ import annotations

    from pathlib import Path

    from cocotb.triggers import Combine, FallingEdge, RisingEdge


    CLOCKS = __CLOCK_MAP__
    RESET_DOMAINS = __RESET_MAP__
    PRIMARY_CLOCK = __PRIMARY_CLOCK__
    SETTLE_CLOCK = __SETTLE_CLOCK__

    ADDR = {
        "cfg": {
            "CTRL": 0x0,
            "GAIN": 0x4,
            "STATUS": 0x8,
            "CFG_STATUS": 0x8,
        },
        "dsp": {
            "DSP_CTRL": 0x0,
            "THRESHOLD": 0x4,
            "DSP_STATUS": 0x8,
            "STATUS": 0x8,
            "RESULT": 0xC,
        },
    }


    def rows(path: str):
        "Read non-comment config/vector rows."
        for raw in Path(path).read_text(encoding="utf-8").splitlines():
            line = raw.strip()
            if not line or line.startswith("#"):
                continue
            yield line.split()


    def _set_domain_defaults(dut, domain: str):
        "Initialize scalar TL-UL proxy signals for one domain."
        for name in ("a_valid", "a_opcode", "a_param", "a_size", "a_source", "a_address", "a_mask", "a_data"):
            getattr(dut, f"{domain}_{name}").value = 0
        getattr(dut, f"{domain}_d_ready").value = 1


    def set_defaults(dut):
        "Initialize top-level scalar IO and TL-UL proxy signals."
        _set_domain_defaults(dut, "cfg")
        _set_domain_defaults(dut, "dsp")
        dut.rx_valid_i.value = 0
        dut.rx_sample_i.value = 0
        dut.rx_coeff_i.value = 0
        dut.dsp_ready_i.value = 1
        dut.test_en_i.value = 1


    def _selected_resets(selector: str):
        "Resolve all, a domain name, or a reset signal name."
        clean = str(selector or "all")
        if clean in {"all", "*"}:
            return tuple(RESET_DOMAINS.values())
        for domain, item in RESET_DOMAINS.items():
            if clean in {domain, item[1]}:
                return (item,)
        raise AssertionError(f"unknown reset selector: {clean}")


    async def _wait_reset_cycles(dut, selected, cycles: int):
        "Wait the requested number of edges in every selected reset domain."
        for _ in range(max(1, int(cycles))):
            await Combine(*(RisingEdge(getattr(dut, clock)) for clock, _, _ in selected))


    async def reset(dut, selector: str = "all", cycles: int = 5):
        "Apply the same named reset pulse semantics used by the SV backend."
        selected = _selected_resets(selector)
        set_defaults(dut)
        for _, signal, polarity in selected:
            getattr(dut, signal).value = int(polarity == "high")
        await _wait_reset_cycles(dut, selected, cycles)
        await Combine(*(FallingEdge(getattr(dut, clock)) for clock, _, _ in selected))
        for _, signal, polarity in selected:
            getattr(dut, signal).value = int(polarity == "low")
        set_defaults(dut)
        for _ in range(8):
            await RisingEdge(getattr(dut, PRIMARY_CLOCK))


    async def _wait_high(dut, signal: str, clk, limit: int = 256):
        "Wait for one TL-UL handshake without missing an already-high response."
        for _ in range(limit):
            if bool(getattr(dut, signal).value):
                return
            await RisingEdge(clk)
        if bool(getattr(dut, signal).value):
            return
        raise TimeoutError(f"timeout waiting for {signal}")


    async def _tlul_write(dut, domain: str, clk, addr: int, data: int):
        "Issue one simple PutFullData write through scalar TL-UL proxies."
        await FallingEdge(clk)
        _set_domain_defaults(dut, domain)
        getattr(dut, f"{domain}_a_valid").value = 1
        getattr(dut, f"{domain}_a_opcode").value = 0
        getattr(dut, f"{domain}_a_param").value = 0
        getattr(dut, f"{domain}_a_size").value = 2
        getattr(dut, f"{domain}_a_source").value = 0
        getattr(dut, f"{domain}_a_address").value = addr & 0xFFFFFFFF
        getattr(dut, f"{domain}_a_mask").value = 0xF
        getattr(dut, f"{domain}_a_data").value = data & 0xFFFFFFFF
        await _wait_high(dut, f"{domain}_a_ready", clk)
        await FallingEdge(clk)
        getattr(dut, f"{domain}_a_valid").value = 0
        await _wait_high(dut, f"{domain}_d_valid", clk)
        await FallingEdge(clk)
        _set_domain_defaults(dut, domain)


    async def _tlul_read(dut, domain: str, clk, addr: int) -> int:
        "Issue one simple Get read through scalar TL-UL proxies."
        await FallingEdge(clk)
        _set_domain_defaults(dut, domain)
        getattr(dut, f"{domain}_a_valid").value = 1
        getattr(dut, f"{domain}_a_opcode").value = 4
        getattr(dut, f"{domain}_a_param").value = 0
        getattr(dut, f"{domain}_a_size").value = 2
        getattr(dut, f"{domain}_a_source").value = 0
        getattr(dut, f"{domain}_a_address").value = addr & 0xFFFFFFFF
        getattr(dut, f"{domain}_a_mask").value = 0xF
        await _wait_high(dut, f"{domain}_a_ready", clk)
        await FallingEdge(clk)
        getattr(dut, f"{domain}_a_valid").value = 0
        await _wait_high(dut, f"{domain}_d_valid", clk)
        await FallingEdge(clk)
        data = int(getattr(dut, f"{domain}_d_data").value) & 0xFFFFFFFF
        error = int(getattr(dut, f"{domain}_d_error").value)
        _set_domain_defaults(dut, domain)
        if error:
            raise AssertionError(f"TL-UL read error on {domain} addr=0x{addr:08x}")
        return data


    def _decode_reg(name: str) -> tuple[str, int]:
        "Resolve a generated config/check register name to domain and address."
        clean = name[6:] if name.startswith("clk_i.") else name
        if "." in clean:
            domain, reg = clean.split(".", 1)
        else:
            domain, reg = "cfg", clean
        reg = reg.upper()
        try:
            return domain, ADDR[domain][reg]
        except KeyError as exc:
            raise KeyError(f"unknown register {name!r}; update drivers/reg_driver.py") from exc


    async def apply_reg(dut, name: str, value: int, mask: int = 0xFFFFFFFF):
        "Apply one config/vector register write, including a bit mask."
        domain, addr = _decode_reg(name)
        clk = getattr(dut, CLOCKS[domain])
        if mask != 0xFFFFFFFF:
            current = await _tlul_read(dut, domain, clk, addr)
            value = (current & ~mask) | (value & mask)
        await _tlul_write(dut, domain, clk, addr, value)


    async def read_reg(dut, name: str) -> int:
        "Read one register by generated model name, for simple status checks."
        domain, addr = _decode_reg(name)
        clk = getattr(dut, CLOCKS[domain])
        return await _tlul_read(dut, domain, clk, addr)


    async def expect_reg(dut, name: str, expected: int, mask: int = 0xFFFFFFFF):
        "Read one register and assert its masked value."
        got = await read_reg(dut, name)
        if (got & mask) != (expected & mask):
            raise AssertionError(
                f"{name} got=0x{got & mask:08x} exp=0x{expected & mask:08x} mask=0x{mask:08x}"
            )


    async def settle(dut, cycles: int = 8):
        "Allow synchronized controls to propagate into the datapath."
        for _ in range(cycles):
            await RisingEdge(getattr(dut, SETTLE_CLOCK))


    async def apply_config(dut, path: str):
        "Apply generated config rows and allow CDC synchronizers to settle."
        for parts in rows(path):
            if len(parts) >= 2:
                mask = int(parts[2], 0) if len(parts) >= 3 else 0xFFFFFFFF
                await apply_reg(dut, parts[0], int(parts[1], 0), mask)
        await settle(dut)
    """)
    return (text.replace("__CLOCK_MAP__", repr(clock_map))
                .replace("__RESET_MAP__", repr(reset_map))
                .replace("__PRIMARY_CLOCK__", repr(primary))
                .replace("__SETTLE_CLOCK__", repr(settle)))
def cocotb_vec_driver_py_text(top: str) -> str:
    """Render N-clock vector commands, including CSR and reset actions."""

    return dedent("""\
    from __future__ import annotations

    from cocotb.triggers import FallingEdge, RisingEdge

    from .reg_driver import apply_reg, expect_reg, reset, rows, settle


    async def send_sample(dut, sample: int, coeff: int):
        "Send one RX-domain input transaction."
        timeout = 0
        while not bool(dut.rx_ready_o.value) and timeout < 64:
            await RisingEdge(dut.rx_clk_i)
            timeout += 1
        assert bool(dut.rx_ready_o.value), "rx_ready_o timeout"
        await FallingEdge(dut.rx_clk_i)
        dut.rx_sample_i.value = sample & 0xFFFF
        dut.rx_coeff_i.value = coeff & 0xFFFF
        dut.rx_valid_i.value = 1
        await FallingEdge(dut.rx_clk_i)
        dut.rx_valid_i.value = 0


    async def drive_inputs(dut, path: str):
        "Execute signal, CSR and reset commands from data_in.vec."
        sample = 0
        coeff = 0
        for parts in rows(path):
            if len(parts) < 2:
                continue
            token = parts[1]
            if token in {"@write", "write"} and len(parts) >= 4:
                mask = int(parts[4], 0) if len(parts) >= 5 else 0xFFFFFFFF
                await apply_reg(dut, parts[2], int(parts[3], 0), mask)
                await settle(dut)
                continue
            if token in {"@read", "read"} and len(parts) >= 4:
                mask = int(parts[4], 0) if len(parts) >= 5 else 0xFFFFFFFF
                await expect_reg(dut, parts[2], int(parts[3], 0), mask)
                continue
            if token in {"@reset", "reset"}:
                if len(parts) == 3:
                    selector, cycles = "all", parts[2]
                elif len(parts) == 4:
                    selector, cycles = parts[2], parts[3]
                else:
                    raise AssertionError(
                        "@reset format: cycle @reset [domain|reset] cycles"
                    )
                dut._log.info(
                    "[TB][RESET] cycle=%s selector=%s cycles=%s",
                    parts[0], selector, cycles,
                )
                await reset(dut, selector, int(cycles, 0))
                continue
            if len(parts) < 3:
                continue
            value = int(parts[2], 0)
            if token == "rx_sample_i":
                sample = value
            elif token == "rx_coeff_i":
                coeff = value
            elif token == "rx_valid_i" and value:
                await send_sample(dut, sample, coeff)
    """)


def cocotb_monitor_py_text(top: str) -> str:
    """Render cocotb output-vector monitor helpers."""

    return dedent("""\
    from __future__ import annotations

    from cocotb.triggers import ReadOnly, RisingEdge

    from .reg_driver import rows


    def expected_outputs(path: str):
        \"\"\"Load expected output transactions by order.\"\"\"
        out = []
        for parts in rows(path):
            if len(parts) < 3:
                continue
            _, sig, value = parts[:3]
            value = int(value, 0)
            if sig == \"dsp_result_o\":
                out.append({\"result\": value, \"above_threshold\": 0, \"overflow\": 0})
            elif sig == \"dsp_above_threshold_o\" and out:
                out[-1][\"above_threshold\"] = value & 1
            elif sig == \"dsp_overflow_o\" and out:
                out[-1][\"overflow\"] = value & 1
        return out


    async def check_outputs(dut, expected):
        \"\"\"Check DSP outputs in transaction order.\"\"\"
        got = 0
        timeout = 0
        while got < len(expected) and timeout < 4096:
            await RisingEdge(dut.dsp_clk_i)
            await ReadOnly()
            if bool(dut.dsp_valid_o.value):
                result = int(dut.dsp_result_o.value) & 0xFFFFFFFF
                above_threshold = int(dut.dsp_above_threshold_o.value) & 1
                overflow = int(dut.dsp_overflow_o.value) & 1
                assert result == expected[got][\"result\"], f\"result[{got}] got=0x{result:08x} exp=0x{expected[got]['result']:08x}\"
                assert above_threshold == expected[got][\"above_threshold\"], f\"above_threshold[{got}] got={above_threshold} exp={expected[got]['above_threshold']}\"
                assert overflow == expected[got][\"overflow\"], f\"overflow[{got}] got={overflow} exp={expected[got]['overflow']}\"
                got += 1
            timeout += 1
        assert got == len(expected), f\"observed {got}/{len(expected)} expected outputs\"
    """)


def cocotb_py_text(top: str, clocks: ClockConfig) -> str:
    """Render the N-clock cocotb test entry point."""

    starts = "\n".join(
        f'    cocotb.start_soon(Clock(getattr(dut, {domain.signal!r}), {domain.period_ns:g}, units="ns").start())'
        for domain in clocks.domains
    )
    template = dedent(f'''\
    """cocotb test for the {top} N-clock scaffold."""

    from __future__ import annotations

    import os

    import cocotb
    from cocotb.clock import Clock

    from drivers.reg_driver import apply_config, reset, set_defaults
    from drivers.vec_driver import drive_inputs
    from drivers.vec_monitor import check_outputs, expected_outputs


    @cocotb.test()
    async def vector_test(dut):
        """Run one generated vector test selected by TEST_NAME."""
    __CLOCK_STARTS__
        set_defaults(dut)
        await reset(dut, "all")

        test_name = os.environ.get("TEST_NAME", "smoke")
        cfg = os.environ.get("CFG", f"../tests/{{test_name}}/config.regs")
        data_in = os.environ.get("DATA_IN", f"../tests/{{test_name}}/data_in.vec")
        data_out = os.environ.get("DATA_OUT", f"../tests/{{test_name}}/data_out.vec")
        await apply_config(dut, cfg)
        expected = expected_outputs(data_out)
        checker = cocotb.start_soon(check_outputs(dut, expected))
        await drive_inputs(dut, data_in)
        await checker
    ''')
    return template.replace("__CLOCK_STARTS__", starts)


# N-clock scaffold writer


def _write_nclock_cocotb_tree(cfg: CocotbConfig, clocks: ClockConfig) -> list[Path]:
    """Write the generated N-clock cocotb scaffold into an empty tree."""

    out, drivers = cfg.output, cfg.output / "drivers"
    files = {
        out / "Makefile": cocotb_makefile_text(
            cfg.top,
            cfg.rtl_dir,
            ips_root=cfg.ips_root,
            simulator=cfg.simulator,
        ),
        out / f"{cfg.top}_tb.sv": cocotb_sv_text(cfg.top, clocks),
        drivers / "__init__.py": "",
        drivers / "reg_driver.py": cocotb_reg_driver_py_text(cfg.top, clocks),
        drivers / "vec_driver.py": cocotb_vec_driver_py_text(cfg.top),
        drivers / "vec_monitor.py": cocotb_monitor_py_text(cfg.top),
        out / f"{cfg.top}_tb.py": cocotb_py_text(cfg.top, clocks),
    }
    for path, text in files.items():
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text.rstrip() + "\n", encoding="utf-8")
    return list(files)


def write_nclock_cocotb(cfg: CocotbConfig, clocks: ClockConfig) -> list[Path]:
    """Recreate the complete machine-owned N-clock cocotb scaffold."""

    with replace_generated_tree(cfg.output):
        return _write_nclock_cocotb_tree(cfg, clocks)

@dataclass(slots=True)
class TestbenchFlow:
    """Create SystemVerilog and cocotb testbench scaffolds independently."""

    def setup_systemverilog(self, config: TestbenchConfig, *, clocks: ClockConfig | None = None) -> tuple[Path, ...]:
        """Generate the SystemVerilog testbench and canonical drivers."""

        clocks = clocks or clock_config()
        if clocks.multiclock:
            canonical = _with_canonical_sv_output(config)
            return generate_nclock_testbench(
                canonical.top,
                Path(canonical.output),
                clocks,
                force=canonical.force,
            )
        return generate_testbench_files(config, clocks=clocks)

    def setup_cocotb(self, config: CocotbConfig, *, clocks: ClockConfig | None = None) -> list[Path]:
        """Generate the cocotb wrapper, drivers and Makefile."""

        return write_cocotb_scaffold(config, clocks=clocks)

    def flow(self, sv_config: TestbenchConfig, cocotb_config: CocotbConfig, *, clocks: ClockConfig | None = None):
        """Generate both canonical functional-DV testbench backends."""

        return (
            self.setup_systemverilog(sv_config, clocks=clocks),
            self.setup_cocotb(cocotb_config, clocks=clocks),
        )

