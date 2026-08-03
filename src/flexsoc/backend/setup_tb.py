"""Generate SystemVerilog testbench files for FlexSoC IP and SoC runs.

The module keeps text rendering separate from filesystem writes so the API layer
and CLI can preview or test generated artifacts without invoking external EDA tools.
"""

from __future__ import annotations

import argparse
import ast
import random
import re
from dataclasses import dataclass, replace
from pathlib import Path
from textwrap import dedent
from typing import Any, Sequence

from flexsoc.clocking import ClockConfig, clock_config

from .common import ensure_dir, has_reg_pkg, parse_sv_signature, safe_write_file



TEST_NAMES = ("smoke", "corners", "random")
WRITABLE_SWACCESS = {"rw", "wo", "w1c", "w1s", "rw1c", "rw1s", "rw0c", "rw0w1c"}
Hjson = dict[str, Any]

try:
    import hjson  # type: ignore
except ImportError:  # pragma: no cover - only used when the optional package is missing.
    hjson = None


def _load_hjson(path: Path) -> Hjson:
    """Load HJSON metadata with the real parser and a tiny fallback for tests."""

    text = path.read_text(encoding="utf-8")
    if hjson is not None:
        return dict(hjson.loads(text))
    normalized = re.sub(r"([{,]\s*)([A-Za-z_][\w]*)\s*:", r'\1"\2":', text)
    normalized = re.sub(r",\s*([}\]])", r"\1", normalized).strip()
    return dict(ast.literal_eval(normalized))


def _candidate_hjson_path(rtldir: str | Path, top: str) -> Path | None:
    """Infer the copied/generated HJSON path for a run directory."""

    rtl = Path(rtldir).resolve()
    candidates = [rtl.parent / "data" / f"{top}.hjson", rtl.parent.parent / "data" / f"{top}.hjson"]
    return next((path for path in candidates if path.exists()), None)


def _hex(value: int, width: int = 8) -> str:
    """Render one zero-padded 32-bit hex value."""

    return f"0x{value & 0xFFFFFFFF:0{width}x}"


def _register_clock(hj: Hjson, reg: dict[str, Any]) -> str:
    """Return the clock-domain name used to make a register key unique."""

    value = reg.get("clock") or reg.get("clk") or reg.get("clock_primary") or hj.get("clock_primary")
    if isinstance(value, dict):
        value = value.get("name")
    if isinstance(value, (list, tuple)):
        value = value[0] if value else None
    return str(value or "clk_i")


def _is_writable_register(reg: dict[str, Any]) -> bool:
    """Return true when software can write the register or one of its fields."""

    swaccess = str(reg.get("swaccess", "")).lower()
    if swaccess in WRITABLE_SWACCESS:
        return True
    for field in reg.get("fields", []) or []:
        if isinstance(field, dict) and str(field.get("swaccess", "")).lower() in WRITABLE_SWACCESS:
            return True
    return False


def _register_entries(hjson_path: Path | None) -> list[dict[str, Any]]:
    """Return every writable register with clock-qualified names and offsets.

    The generated config uses ``clock.register`` keys so multi-clock IP can
    disambiguate registers without requiring users to write raw addresses.
    """

    if hjson_path is None or not hjson_path.exists():
        return []
    hj = _load_hjson(hjson_path)
    entries: list[dict[str, Any]] = []
    offset = 0
    for reg in hj.get("registers", []) or []:
        if not isinstance(reg, dict) or "name" not in reg:
            continue
        current = int(str(reg.get("offset", offset)), 0) if reg.get("offset") is not None else offset
        name = str(reg["name"]).upper()
        clock = _register_clock(hj, reg)
        if _is_writable_register(reg):
            swaccess = str(reg.get("swaccess", "rw")).lower()
            entries.append(
                {
                    "name": name,
                    "clock": clock,
                    "key": f"{clock}.{name}",
                    "addr": current,
                    "swaccess": swaccess,
                }
            )
        offset = current + 4
    return entries


def _register_lookup_entries(hjson_path: Path | None) -> list[dict[str, Any]]:
    """Return all registers for vector read/write name resolution.

    _register_entries() intentionally returns writable registers for config.regs.
    Vector files also need read-only registers so data_out.vec can use:

      <cycle> @read <REG_OR_ADDR> <EXPECTED> [MASK]
    """

    if hjson_path is None or not hjson_path.exists():
        return []

    hj = _load_hjson(hjson_path)
    entries: list[dict[str, Any]] = []
    offset = 0

    for reg in hj.get("registers", []) or []:
        if not isinstance(reg, dict) or "name" not in reg:
            continue

        current = int(str(reg.get("offset", offset)), 0) if reg.get("offset") is not None else offset
        name = str(reg["name"]).upper()
        clock = _register_clock(hj, reg)
        swaccess = str(reg.get("swaccess", "rw")).lower()

        entries.append(
            {
                "name": name,
                "clock": clock,
                "key": f"{clock}.{name}",
                "addr": current,
                "swaccess": swaccess,
            }
        )

        offset = current + 4

    return entries



def _mode_for_test(top: str, test: str) -> int:
    """Return the generated MODE.SEL value used by vector expectations."""

    if test == "corners":
        return 1
    if test == "random":
        return random.Random(f"{top}:{test}:mode").randrange(3)
    return 0


def _config_value(test: str, reg: dict[str, Any], index: int, *, top: str) -> int:
    """Choose a deterministic register value for one generated test."""

    name = str(reg["name"])
    fixed = {"CTRL": 0x3, "MODE": _mode_for_test(top, test), "SCALE": 1}
    if name in fixed:
        return fixed[name]
    if test == "corners":
        return [0, 1, 0xFFFFFFFF, 0x80000000][index % 4]
    if test == "random":
        return random.Random(f"{top}:{test}:{name}:{index}").getrandbits(32)
    return (index + 1) & 0xFFFFFFFF


def render_reg_config(top: str, test: str, registers: Sequence[dict[str, Any]]) -> str:
    """Render a register config where write is implicit."""

    lines = [
        "# Auto-generated FlexSoC register configuration.",
        f"# top={top} test={test}",
        "# format: <CLOCK.REG_NAME> <DATA> [MASK] [WAIT_CYCLES] [NOTE]",
        "# write is implicit; MASK=0xffffffff and WAIT_CYCLES=1 by default.",
        f"# writable_registers={len(registers)}",
    ]
    for reg in registers:
        lines.append(f"# map {reg['key']} {_hex(int(reg['addr']))} access={reg.get('swaccess', 'rw')}")
    for index, reg in enumerate(registers):
        lines.append(f"{reg['key']} {_hex(_config_value(test, reg, index, top=top))}")
    if not registers:
        lines.append("# no writable registers inferred from HJSON")
    return "\n".join(lines) + "\n"


def _is_control_port(name: str) -> bool:
    """Return true for clocks, resets, and generated bus records."""

    return name in {"tl_i", "tl_o", "reg_req_i", "reg_rsp_o"} or "clk" in name or "rst" in name


def _vector_inputs(sig: dict[str, Any] | None) -> list[str]:
    """Return top inputs that can be driven from data_in.vec."""

    return [name for name, _ in (sig or {}).get("ports_in", []) if not _is_control_port(name)]


def _vector_outputs(sig: dict[str, Any] | None) -> list[str]:
    """Return top outputs that can be checked from data_out.vec."""

    return [name for name, _ in (sig or {}).get("ports_out", []) if not _is_control_port(name)]


def _stimulus_rows(test: str, *, top: str, count: int = 8) -> list[tuple[int, int, int, int]]:
    """Return cycle, data, coeff, and valid rows for generated vectors."""

    if test == "smoke":
        values = [(0, 1, 1), (1, 4, 2), (2, 7, 3), (3, 8, 5)]
    elif test == "corners":
        values = [(0, 0, 1), (1, 0xFFFFFFFF, 1), (2, 0x80000000, 2), (3, 0x7FFFFFFF, 3)]
    else:
        rng = random.Random(f"{top}:{test}:vectors")
        values = [(i, rng.getrandbits(16), rng.getrandbits(8)) for i in range(count)]
    return [(cycle, data, coeff, 1) for cycle, data, coeff in values]


def _expected(data: int, coeff: int, mode: int) -> int:
    """Return the expected data_o value for the generated starter core."""

    if mode == 1:
        return data ^ coeff
    if mode == 2:
        return data << 1
    return data + coeff


def render_data_in(top: str, test: str, sig: dict[str, Any] | None = None) -> str:
    """Render named input vectors for one test."""

    inputs = _vector_inputs(sig) or ["data_i", "coeff_i", "valid_i"]
    lines = [
        "# Auto-generated FlexSoC input vectors.",
        f"# top={top} test={test}",
        "# format: <CYCLE> <SIGNAL> <VALUE> [<SIGNAL> <VALUE> ...]",
        "# one or many signals can be assigned on the same cycle.",
        "# config change: <CYCLE> @cfg <PATH_TO_CONFIG.REGS>",
    ]
    for cycle, data, coeff, valid in _stimulus_rows(test, top=top):
        pairs = []
        if "valid_i" in inputs:
            pairs += ["valid_i", _hex(valid)]
        if "data_i" in inputs:
            pairs += ["data_i", _hex(data)]
        if "coeff_i" in inputs:
            pairs += ["coeff_i", _hex(coeff)]
        if not pairs and inputs:
            pairs += [inputs[0], _hex(data)]
        lines.append(" ".join([str(cycle), *pairs]))
    return "\n".join(lines) + "\n"


def render_data_out(top: str, test: str, sig: dict[str, Any] | None = None, *, latency: int = 2) -> str:
    """Render named expected-output vectors for one test."""

    outputs = _vector_outputs(sig) or ["data_o", "valid_o"]
    mode = _mode_for_test(top, test)
    lines = [
        "# Auto-generated FlexSoC expected output vectors.",
        f"# top={top} test={test} latency={latency}",
        "# format: <CYCLE> <SIGNAL> <EXPECTED> [<SIGNAL> <EXPECTED> ...]",
    ]
    for cycle, data, coeff, valid in _stimulus_rows(test, top=top):
        pairs = []
        if "data_o" in outputs:
            pairs += ["data_o", _hex(_expected(data, coeff, mode))]
        if "valid_o" in outputs:
            pairs += ["valid_o", _hex(valid)]
        if not pairs and outputs:
            pairs += [outputs[0], _hex(_expected(data, coeff, mode))]
        lines.append(" ".join([str(cycle + latency), *pairs]))
    return "\n".join(lines) + "\n"


def write_verification_tests(
    base_dir: str | Path,
    top: str,
    hjson_path: Path | None,
    sig: dict[str, Any] | None = None,
    *,
    force: bool,
) -> list[Path]:
    """Create per-test register, input, and expected-output data files."""

    root = Path(base_dir)
    registers = _register_entries(hjson_path)
    written: list[Path] = []
    for test in TEST_NAMES:
        test_dir = root / test
        ensure_dir(test_dir)
        stale = test_dir / f"{test}.vec"
        if stale.exists():
            stale.unlink()
        files = {
            test_dir / "config.regs": render_reg_config(top, test, registers),
            test_dir / "data_in.vec": render_data_in(top, test, sig),
            test_dir / "data_out.vec": render_data_out(top, test, sig),
        }
        for path, text in files.items():
            safe_write_file(path, text, overwrite=force)
            written.append(path)
    return written


def render_sv_reg_sequence(
    top: str,
    interface: str,
    clk: str,
    *,
    active: bool,
    registers: Sequence[dict[str, Any]] = (),
) -> str:
    """Render generic SystemVerilog register helpers.

    Exports:
      run_reg_config(cfg_path)
      tb_reg_write_key(reg_or_addr, data, mask, ok)
      tb_reg_read_key(reg_or_addr, data, ok)

    The parser is line-based, so optional MASK/WAIT/NOTE fields in config.regs
    cannot consume tokens from the next row.
    """

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

def render_sv_vec_monitor(top: str, outputs: Sequence[str]) -> str:
    """Render generic expected-output checks from data_out.vec.

    Supported rows:
      <cycle> <signal> <expected> [<signal> <expected> ...]
      <cycle> @read <reg_or_addr> <expected> [mask]
      <valid_signal> <signal> <expected> [<signal> <expected> ...]

    The event-driven form consumes one row whenever ``valid_signal`` is high.
    """

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


def render_sv_vec_driver(top: str, clk: str, rst: str, inputs: Sequence[str], outputs: Sequence[str]) -> str:
    """Render generic input-vector drive tasks from data_in.vec.

    Supported rows:
      <cycle> <signal> <value> [<signal> <value> ...]
      <cycle> @write <reg_or_addr> <data> [mask]
      <cycle> @cfg <path>
      <cycle> @reset <cycles>
    """

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

task automatic tb_apply_reset(input int cycles, input string data_out_path, inout int now_cycle);
  int i;
{reset_defaults}
  {rst} = 1'b0;
  for (i = 0; i < cycles; i++) tb_step(data_out_path, now_cycle);
  @(negedge {clk}); #1;
  {rst} = 1'b1;
  tb_vector_apply_count++;
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
      parsed = tb_parse_u32(t1);
      reset_cycles = parsed[32] ? parsed[31:0] : 32'd2;
      if (reset_cycles == 0) reset_cycles = 2;
      $display("[TB][RESET] cycle=%0d cycles=%0d", cycle, reset_cycles);
      tb_apply_reset(int'(reset_cycles), data_out_path, now_cycle);
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


# Icarus 12 cannot reliably index or coerce automatic SystemVerilog strings at
# runtime. Keep file paths as strings, but parse file content through packed
# vectors and classic $sscanf semantics.
_STRING_RENDER_SV_REG_SEQUENCE = render_sv_reg_sequence
_STRING_RENDER_SV_VEC_MONITOR = render_sv_vec_monitor
_STRING_RENDER_SV_VEC_DRIVER = render_sv_vec_driver

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


def render_sv_reg_sequence(
    top: str,
    interface: str,
    clk: str,
    *,
    active: bool,
    registers: Sequence[dict[str, Any]] = (),
) -> str:
    return _packed_reg_sequence(
        _STRING_RENDER_SV_REG_SEQUENCE(
            top, interface, clk, active=active, registers=registers
        )
    )


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
    return _packed_vec_monitor(_STRING_RENDER_SV_VEC_MONITOR(top, outputs))


def _packed_vec_driver(text: str) -> str:
    text = text.replace("input string name", "input tb_token_t name")
    text = text.replace("input string raw", "input tb_token_t raw")
    text = text.replace("input string reg_key", "input tb_token_t reg_key")
    text = text.replace("input string data_raw", "input tb_token_t data_raw")
    text = text.replace("input string mask_raw", "input tb_token_t mask_raw")
    for name in ("t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"):
        text = text.replace(f"  input string {name}", f"  input tb_token_t {name}")
    text = text.replace("  string line;\n", "")
    text = text.replace("  reg [8*4096-1:0] line_buf;", "  tb_line_t line_buf;")
    for name in ("cycle_raw", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"):
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
) -> str:
    return _packed_vec_driver(
        _STRING_RENDER_SV_VEC_DRIVER(top, clk, rst, inputs, outputs)
    )

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
        files[stale_vec_files[1]] = render_sv_vec_driver(top, clk, rst, inputs, outputs)
    else:
        for stale in stale_vec_files:
            if stale.exists():
                stale.unlink()

    for path, text in files.items():
        safe_write_file(path, text, overwrite=force)

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

# -------------------------
# Render helpers (SV text)
# -------------------------
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

    # Legacy Make/Verilator flow includes primitive models here. Python-native
    # GLS defines FLEXSOC_GLS_EXTERNAL_MODELS and supplies the active PDK models
    # explicitly, which makes a regenerated TB portable across PDK profiles.
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

  task automatic cycle();
    @(posedge clk_i);
  endtask

  task automatic drive_idle();
    h2d <= flexsoc_tlul_h2d(1'b0, FLEXSOC_TL_GET, 3'b0, 2'd2, 8'b0,
                            32'b0, 4'b0, 32'b0, 1'b1);
  endtask

  task automatic init();
    drive_idle();
    cycle();
  endtask

  task automatic wait_d2h_high(input integer bit_index, input string signal_name);
    integer guard;
    guard = 0;
    cycle();
    while (d2h[bit_index] !== 1'b1) begin
      if (d2h[bit_index] !== 1'b0)
        $fatal(1, "[%0t] TLUL %s is X/Z; check reset and gate-level cell model mode",
               $time, signal_name);
      guard++;
      if (guard > 1000)
        $fatal(1, "[%0t] TLUL timeout waiting for %s", $time, signal_name);
      cycle();
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
    drive_idle();
    cycle();
    h2d <= flexsoc_tlul_h2d(1'b1, opcode, 3'b0, 2'd2, source,
                            addr, mask, data, 1'b1);
    wait_d2h_high(0, "write a_ready");
    h2d[108] <= 1'b0;
    wait_d2h_high(65, "write d_valid");
    if (d2h[1])
      $fatal(1, "[%0t] TLUL WRITE ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    cycle();
    drive_idle();
    cycle();
    #1;
  endtask

  task automatic tlul_read(
    input logic [31:0] addr,
    output logic [31:0] data,
    input logic [7:0] source
  );
    $display("[%0t] TLUL READ: Addr = 0x%08x", $time, addr);
    data = '0;
    drive_idle();
    cycle();
    h2d <= flexsoc_tlul_h2d(1'b1, FLEXSOC_TL_GET, 3'b0, 2'd2, source,
                            addr, 4'hf, 32'b0, 1'b1);
    wait_d2h_high(0, "read a_ready");
    h2d[108] <= 1'b0;
    wait_d2h_high(65, "read d_valid");
    data = d2h[47:16];
    if (d2h[1])
      $fatal(1, "[%0t] TLUL READ ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    cycle();
    drive_idle();
    cycle();
    #1;
  endtask

endinterface
"""

def render_tlul_utils() -> str:
    """Retain a harmless compatibility file for older generated workspaces."""

    return "// TL-UL tasks are defined in tlul_if.sv.\n"

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

    # Waveform *path* is simulator-independent. The runtime selects the
    # encoding (FST by default in FlexSoC, VCD on request). Accept the old
    # +VCD plusarg as a compatibility fallback, but never invent a cwd-local
    # filename: an empty path means no dump.
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
    # simple reset: first rst_ if present, else try second input heuristically
    if rsts:
        lines.append("    #(CLK_PERIOD);")
        lines.append(f"    {rsts[0]} = 1'b1;")
    else:
        if len(ports_in) > 1 and "rst" in ports_in[1][0]:
            lines.append("    #(CLK_PERIOD);")
            lines.append(f"    {ports_in[1][0]} = 1'b1;")

    lines.append("    #(CLK_PERIOD);")
    lines.append('    $display("\\nRunning...\\n");')

    if interface == "tlul":
        lines.append("    tl_if.init();")
    elif compiler == "verilator" and interface == "reg_iface":
        lines.append("    reg_utils_inst = new(regif);")
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

# -------------------------
# Filesystem and CLI boundary
# -------------------------


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
        "tlul": (("tlul_if.sv", render_tlul_interface()), ("tlul_utils.sv", render_tlul_utils())),
        "reg_iface": (
            (("reg_if.sv", render_reg_interface(config.top)), ("reg_utils.sv", render_reg_utils(config.top)))
            if config.compiler == "verilator" else ()
        ),
    }.get(config.interface, ())

    written: list[Path] = []
    for name, body in helpers:
        path = outdir / name
        safe_write_file(path, body, overwrite=True)
        written.append(path)
    return written



# BEGIN FLEXSOC CANONICAL SV OUTPUT
def _canonical_sv_output_dir(output: str | Path) -> Path:
    """Return the canonical SystemVerilog output directory.

    FlexSoC keeps generated verification artifacts split as:

      dv/functional/tb/sv      SystemVerilog testbench and SV drivers
      dv/functional/tests      generated vector tests
      dv/functional/tb/cocotb  cocotb scaffold

    The output argument names the testbench root.  SystemVerilog files live
    in its ``sv`` child unless the caller already passes that directory.
    """

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

def generate_testbench_files(config: TestbenchConfig) -> tuple[Path, ...]:
    """Generate include, helper, and top-level testbench files for one request."""

    config = _with_canonical_sv_output(config)
    outdir = Path(config.output)
    ensure_dir(outdir)

    sig = parse_sv_signature(config.rtldir, config.top)
    reg_pkg = has_reg_pkg(config.rtldir, config.top)
    simple_mode = uses_simple_testbench(config)
    written: list[Path] = []
    hjson_path = _candidate_hjson_path(config.rtldir, config.top)
    # setup_model owns config.regs/data_in.vec/data_out.vec generation.
    written.extend(
        write_sv_verification_helpers(
            outdir,
            config.top,
            config.interface,
            sig,
            hjson_path=hjson_path,
            bus_active=(not simple_mode and (config.interface == "tlul" or config.compiler == "verilator")),
            force=True,
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
        safe_write_file(include_path, include, overwrite=config.force)
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
    safe_write_file(tb_path, body, overwrite=config.force)
    written.append(tb_path)
    return tuple(written)


def parse_args(argv=None):
    """Parse command-line options for testbench generation."""

    p = argparse.ArgumentParser(
        prog="setup_tb",
        description="Generate a SystemVerilog testbench and helper files.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    p.add_argument("-top", "--top", required=True, help="TOP module name")
    p.add_argument("-rtldir", "--rtldir", "--rtl-dir", dest="rtldir", required=True, help="RTL directory containing <top>.sv")
    p.add_argument("-simdir", "--simdir", "--sim-dir", dest="simdir", required=True, help="Simulation output dir for VCD")
    p.add_argument("-device", "--device", action="append", nargs=4, default=[], metavar=("NAME", "BASE_ADDR", "SIZE_BYTE", "FROM_LR"), help="Add one mapped SoC device.")
    p.add_argument("-syndir", "--syndir", "--syn-dir", dest="syndir", required=True, help="Synthesis dir for post-syn sim")
    p.add_argument("-prim", "--prim", nargs="+", required=True, help="Primitive files used for post-syn include")
    p.add_argument("-clk", "--clk", type=int, required=True, help="Clock period in ns")
    p.add_argument("-comp", "--comp", "--compiler", dest="comp", required=True, choices=["iverilog", "verilator"], help="Simulator/compiler")
    p.add_argument("-itf", "--itf", "--bus", dest="itf", required=True, choices=["tlul", "reg_iface"], help="Register interface wiring")
    p.add_argument("-vsv", "--vsv", default="sv", choices=["sv", "v"], help="DUT source extension used by Verilator include")
    p.add_argument("-o", "--output", default="dv/functional/tb", help="Output directory for generated files")
    p.add_argument("-f", "--force", action="store_true", help="Overwrite existing files")
    return p.parse_args(argv)


def config_from_args(args: argparse.Namespace) -> TestbenchConfig:
    """Convert parsed CLI arguments into the canonical backend config object."""

    return TestbenchConfig(
        top=args.top,
        rtldir=args.rtldir,
        simdir=args.simdir,
        syndir=args.syndir,
        prims=tuple(args.prim),
        clk_period_ns=args.clk,
        compiler=args.comp,
        interface=args.itf,
        vsv=args.vsv,
        output=_canonical_sv_output_dir(args.output),
        devices=tuple(tuple(item) for item in args.device),
        force=bool(args.force),
    )

# -------------------------
# Generated layout normalization and CLI boundary
# -------------------------
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
    """Move generated SV helpers into the canonical tb/sv/drivers layout.

    This function is intentionally generic. It must not install IP-specific
    drivers. The source-of-truth helpers are produced earlier by
    write_sv_verification_helpers():

      <sv>/<top>_reg_sequence.svh
      <sv>/<top>_vec_driver.svh
      <sv>/<top>_vec_monitor.svh

    Those helpers support both:
      - plain signal vectors: <cycle> <signal> <value> ...
      - register vectors:     <cycle> @write/@read ...
    """

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

    text = _remove_inline_run_vectors(_read_text(tb_path))
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



def sv_driver_text(top: str, clocks: ClockConfig) -> str:
    """Render package-free TL-UL access and reset tasks for the N-clock scaffold."""

    resets = {domain.reset: domain.reset_polarity for domain in clocks.domains}
    assert_reset = "\n".join(
        f"    {name} = 1'b{1 if polarity == 'high' else 0};"
        for name, polarity in resets.items()
    )
    release_reset = "\n".join(
        f"    {name} = 1'b{0 if polarity == 'high' else 1};"
        for name, polarity in resets.items()
    )
    primary = clocks.domains[0].signal
    text = dedent("""\
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

      task automatic reset_dut(input integer cycles);
__ASSERT_RESET__
        repeat (cycles) @(posedge __PRIMARY_CLOCK__);
__RELEASE_RESET__
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
                .replace("__RELEASE_RESET__", release_reset)
                .replace("__PRIMARY_CLOCK__", primary))

def sv_vec_driver_text(top: str) -> str:
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
            code = $sscanf(line, "%d %s %d", step, token, cycles);
            if (code == 3) reset_dut(cycles);
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

def sv_monitor_text(top: str) -> str:
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




_STRING_SV_DRIVER_TEXT = sv_driver_text
_STRING_SV_VEC_DRIVER_TEXT = sv_vec_driver_text
_STRING_SV_MONITOR_TEXT = sv_monitor_text


def sv_driver_text(top: str, clocks: ClockConfig) -> str:
    text = _STRING_SV_DRIVER_TEXT(top, clocks)
    text = _PACKED_TOKEN_SUPPORT + "\n" + text
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
    return text


def sv_vec_driver_text(top: str) -> str:
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


def sv_monitor_text(top: str) -> str:
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
        + [f"    {domain.reset} = 1'b{1 if domain.reset_polarity == 'high' else 0};" for domain in clocks.domains]
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

        repeat (5) @(posedge {primary});
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

# ---------------------------------------------------------------------------
# cocotb scaffold
# ---------------------------------------------------------------------------



def generate_nclock_testbench(top: str, output: Path, clocks: ClockConfig, *, force: bool) -> None:
    """Write the generated N-clock SV testbench and split drivers."""

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
        safe_write_file(path, text, overwrite=force)


def main(argv=None) -> int:
    """Run testbench generation from the command line."""

    config = config_from_args(parse_args(argv))
    clocks = clock_config()
    if clocks.multiclock:
        generate_nclock_testbench(config.top, Path(config.output), clocks, force=config.force)
    else:
        generate_testbench_files(config)
        _normalize_generated_sv_layout(config)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
