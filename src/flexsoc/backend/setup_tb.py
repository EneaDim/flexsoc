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
from typing import Any, Sequence

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
function automatic bit tb_lookup_reg_addr(input string reg_key, output logic [31:0] addr);
  addr = '0;
  return 1'b0;
endfunction

function automatic bit tb_parse_cfg_u32(input string raw, output logic [31:0] value);
  int ok;
  value = '0;
  ok = $sscanf(raw, "%d", value);
  return ok == 1;
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
        "tl_utils_inst.tlul_write(addr[top_pkg::TL_AW-1:0], data, 4'h0, mask[top_pkg::TL_DBW-1:0]);"
        if interface == "tlul"
        else f"reg_utils_inst.write(addr[{top}_reg_pkg::AW-1:0], data, mask[{top}_reg_pkg::DBW-1:0]);"
    )
    read_addr_call = (
        "tl_utils_inst.tlul_read(addr[top_pkg::TL_AW-1:0], data, '0);"
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
            cases.append(f'    "{key}": begin addr = 32\'h{addr:08x}; return 1\'b1; end')

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
{addr_cases}
  endcase

  return tb_parse_cfg_u32(reg_key, addr);
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

    repeat (wait_cycles) @(posedge {clk});
  end

  $fclose(fd);

  if (writes == 0) begin
    $display("[TB] no register config writes from %s; continuing", cfg_path);
  end
endtask
"""

def _sv_output_expr(name: str) -> str:
    """Return the 32-bit SystemVerilog expression used to compare one output."""

    if name.startswith("valid") and name.endswith("_o"):
        return "{31'b0, " + name + "}"
    return name


TOKENIZER = r"""
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
{TOKENIZER}
function automatic logic [31:0] tb_read_output(input string name, output bit known);
  logic [31:0] actual;

  actual = '0;
  known = 1'b0;

{checks_text}
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
  logic [31:0] guard_value;
  bit guard_known;
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

    guard_value = tb_read_output(cycle_raw, guard_known);
    if (guard_known) continue;
    if (!tb_parse_u32(cycle_raw, cycle_value)) continue;

    if (int'(cycle_value) > last_cycle) last_cycle = int'(cycle_value);
  end

  $fclose(fd);
  return last_cycle;
endfunction

function automatic int tb_guarded_output_count(input string out_path);
  int fd;
  int code;
  int count;
  logic [31:0] ignored;
  bit known;
  string line;
  string first;
  string t0;
  string t1;
  string t2;
  string t3;
  string t4;
  string t5;
  string t6;
  string t7;

  count = 0;
  fd = $fopen(out_path, "r");
  if (fd == 0) return 0;

  while (!$feof(fd)) begin
    line = "";
    void'($fgets(line, fd));
    tb_tokenize9(line, code, first, t0, t1, t2, t3, t4, t5, t6, t7);
    if (code < 3) continue;
    if (first.len() > 0 && first.substr(0, 0) == "#") continue;
    ignored = tb_read_output(first, known);
    if (known) count++;
  end

  $fclose(fd);
  return count;
endfunction

task automatic tb_check_outputs(input string out_path, input int cycle);
  int fd;
  int code;
  int expected_cycle;
  int guarded_index;
  logic [31:0] expected_cycle_value;
  logic [31:0] guard_value;
  bit guard_known;
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
  guarded_index = 0;

  while (!$feof(fd)) begin
    line = "";
    void'($fgets(line, fd));
    tb_tokenize9(line, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

    if (code < 3) continue;
    if (cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#") continue;
    if (t0.len() > 0 && t0.substr(0, 0) == "#") continue;

    guard_value = tb_read_output(cycle_raw, guard_known);
    if (guard_known) begin
      if (guarded_index == tb_guarded_output_next && guard_value[0] === 1'b1) begin
        tb_check_signal_one(cycle, t0, t1);
        if (code >= 5) tb_check_signal_one(cycle, t2, t3);
        if (code >= 7) tb_check_signal_one(cycle, t4, t5);
        if (code >= 9) tb_check_signal_one(cycle, t6, t7);
        tb_guarded_output_next++;
      end
      guarded_index++;
      continue;
    end

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
"""

def render_sv_vec_driver(top: str, clk: str, inputs: Sequence[str], outputs: Sequence[str]) -> str:
    """Render generic input-vector drive tasks from data_in.vec.

    Supported rows:
      <cycle> <signal> <value> [<signal> <value> ...]
      <cycle> @write <reg_or_addr> <data> [mask]
      <cycle> @cfg <path>
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

    return f"""// Auto-generated vector driver for {top}.
// data_in.vec supports signal drives, @write register operations, and @cfg.

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

  if (name == "") return;
  if (!tb_parse_u32(raw, value)) return;

  tb_drive_input(name, value);
endtask

task automatic tb_apply_reg_write(input string reg_key, input string data_raw, input string mask_raw);
  logic [31:0] data;
  logic [31:0] mask;
  bit ok;

  if (!tb_parse_u32(data_raw, data)) return;

  if (mask_raw.len() > 0 && tb_parse_u32(mask_raw, mask)) begin
    // parsed explicit mask
  end else begin
    mask = 32'hffff_ffff;
  end

  tb_reg_write_key(reg_key, data, mask, ok);
  if (ok) tb_vector_apply_count++;
endtask

task automatic tb_step(input string data_out_path, inout int now_cycle);
  @(posedge {clk}); #1;
  now_cycle++;
  tb_check_outputs(data_out_path, now_cycle);
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

  now_cycle = -1;
  current_cycle = -1;
  cycle_open = 1'b0;
  apply_start = tb_vector_apply_count;
  tb_guarded_output_next = 0;
  final_cycle = tb_last_output_cycle(data_out_path);
  guarded_total = tb_guarded_output_count(data_out_path);

  fd = $fopen(data_in_path, "r");
  if (fd == 0) begin
    $display("[TB][ERROR] input vector file not found: %s", data_in_path);
    error_count++;
    return;
  end

  $display("[TB] running vectors: in=%s out=%s", data_in_path, data_out_path);

  while (!$feof(fd)) begin
    line = "";
    void'($fgets(line, fd));
    tb_tokenize9(line, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

    if (code < 3) continue;
    if (cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#") continue;
    if (t0.len() > 0 && t0.substr(0, 0) == "#") continue;
    if (!tb_parse_u32(cycle_raw, cycle_value)) continue;

    cycle = int'(cycle_value);

    if (t0 == "@cfg" || t0 == "cfg" || t0 == "@config" || t0 == "config") begin
      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      $display("[TB][CFG] cycle=%0d path=%s", cycle, t1);
      run_reg_config(t1);
      tb_vector_apply_count++;
      continue;
    end

    if (t0 == "@write" || t0 == "write" || t0 == "@reg_write" || t0 == "reg_write") begin
      if (code < 4) begin
        error_count++;
        $display("[TB][ERROR] malformed @write row: %s", line);
        continue;
      end

      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      $display("[TB][VEC-WR] cycle=%0d reg=%s", cycle, t1);
      tb_apply_reg_write(t1, t2, t3);
      continue;
    end

    if ((code - 1) % 2 != 0) begin
      error_count++;
      $display("[TB][ERROR] malformed signal vector row: %s", line);
      continue;
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

  while (now_cycle < final_cycle || tb_guarded_output_next < guarded_total) begin
    if (tb_guarded_output_next < guarded_total && now_cycle >= guarded_deadline) begin
      error_count++;
      $display("[TB][ERROR] timed out waiting for guarded output row %0d/%0d",
               tb_guarded_output_next + 1, guarded_total);
      break;
    end
    tb_step(data_out_path, now_cycle);
  end

  if (tb_vector_apply_count == apply_start) begin
    error_count++;
    $display("[TB][ERROR] no vector inputs or register writes were applied from %s", data_in_path);
  end
endtask
"""

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
        files[stale_vec_files[1]] = render_sv_vec_driver(top, clk, inputs, outputs)
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
        inc.append('  `include "tlul_utils.sv"')
        inc.append('  `include "tlul_if.sv"')

    if flag_reg_pkg and interface == "reg_iface":
        inc.append('  `include "reg_utils.sv"')
        inc.append('  `include "reg_if.sv"')

    # DUT source: assume +incdir+rtldir nel comando
    inc.append(f'  `include "{top}.{"sv" if vsv == "sv" else "v"}"')

    inc.append("`else")

    # prims: includi solo il basename, e metti le loro dir in +incdir
    for p in prims:
        inc.append(f'  `include "{Path(p).name}"')

    # synth netlist: includi solo nome, assume +incdir+syndir nel comando
    inc.append(f'  `include "{top}_synth.v"')

    inc.append("`endif")
    return "\n".join(inc) + "\n"

def render_tlul_interface() -> str:
    """Render the TL-UL SystemVerilog interface used by Verilator tests."""

    return """`timescale 1ns/1ps

interface tlul_if (
  input  logic clk_i,
  input  logic rst_ni
);

  import tlul_pkg::*;

  // Host to Device
  tl_h2d_t h2d /* simulator public*/;

  // Device to Host
  tl_d2h_t d2h /* simulator public*/;

  // Modport for driver (testbench)
  modport drv (
    output h2d,
    input  d2h
  );

  // Modport for DUT
  modport dut (
    input  h2d,
    output d2h
  );

endinterface
"""

def render_tlul_utils() -> str:
    """Render simple TL-UL utility tasks for generated testbenches."""

    return """class tlul_utils;

  virtual tlul_if.drv drv_if;

  function new(virtual tlul_if.drv drv_if);
    this.drv_if = drv_if;
  endfunction

  task automatic cycle();
    @(posedge drv_if.clk_i);
  endtask

  task automatic drive_idle();
    drv_if.h2d.a_valid   <= 1'b0;
    drv_if.h2d.a_opcode  <= tlul_pkg::Get;
    drv_if.h2d.a_param   <= '0;
    drv_if.h2d.a_size    <= '0;
    drv_if.h2d.a_source  <= '0;
    drv_if.h2d.a_address <= '0;
    drv_if.h2d.a_mask    <= '0;
    drv_if.h2d.a_data    <= '0;
    drv_if.h2d.a_user    <= '0;
    drv_if.h2d.d_ready   <= 1'b0;
  endtask

  task automatic init();
    drive_idle();
    cycle();
  endtask

  task automatic tlul_write(input logic [top_pkg::TL_AW-1:0]  addr,
                            input logic [top_pkg::TL_DW-1:0]  data,
                            input logic [top_pkg::TL_AIW-1:0] source,
                            input logic [top_pkg::TL_DBW-1:0] mask = '1);

    $display("[%0t] TLUL WRITE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);

    drive_idle();
    cycle();

    drv_if.h2d.d_ready   <= 1'b1;
    drv_if.h2d.a_valid   <= 1'b1;
    drv_if.h2d.a_opcode  <= tlul_pkg::PutFullData;
    drv_if.h2d.a_param   <= 3'b000;
    drv_if.h2d.a_size    <= 2;
    drv_if.h2d.a_source  <= source;
    drv_if.h2d.a_address <= addr;
    drv_if.h2d.a_mask    <= mask;
    drv_if.h2d.a_data    <= data;
    drv_if.h2d.a_user    <= '0;

    do cycle(); while (!drv_if.d2h.a_ready);
    drv_if.h2d.a_valid <= 1'b0;

    do cycle(); while (!drv_if.d2h.d_valid);

    if (drv_if.d2h.d_error) begin
      $display("[%0t] TLUL WRITE ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    end else begin
      $display("[%0t] TLUL WRITE DONE: Addr = 0x%08x", $time, addr);
    end

    cycle();
    drive_idle();
    cycle();

    #1;
  endtask

  task automatic tlul_read(input  logic [top_pkg::TL_AW-1:0]  addr,
                           output logic [top_pkg::TL_DW-1:0]  data,
                           input  logic [top_pkg::TL_AIW-1:0] source);

    $display("[%0t] TLUL READ: Addr = 0x%08x", $time, addr);
    data = '0;

    drive_idle();
    cycle();

    drv_if.h2d.d_ready   <= 1'b1;
    drv_if.h2d.a_valid   <= 1'b1;
    drv_if.h2d.a_opcode  <= tlul_pkg::Get;
    drv_if.h2d.a_param   <= 3'b000;
    drv_if.h2d.a_size    <= 2;
    drv_if.h2d.a_source  <= source;
    drv_if.h2d.a_address <= addr;
    drv_if.h2d.a_mask    <= 4'b1111;
    drv_if.h2d.a_data    <= '0;
    drv_if.h2d.a_user    <= '0;

    do cycle(); while (!drv_if.d2h.a_ready);
    drv_if.h2d.a_valid <= 1'b0;

    do cycle(); while (!drv_if.d2h.d_valid);
    data = drv_if.d2h.d_data;

    if (drv_if.d2h.d_error) begin
      $display("[%0t] TLUL READ ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    end else begin
      $display("[%0t] TLUL READ DONE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);
    end

    cycle();
    drive_idle();
    cycle();

    #1;
  endtask

endclass
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
    # Optional rdata reg for quick examples
    lines.append(f"  logic [{top}_reg_pkg::DW-1:0] rdata;")

    # Interfaces (Verilator only)
    if compiler == "verilator":
        if interface == "tlul":
            lines.append("  tlul_utils tl_utils_inst;")
            lines.append("  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));")
        if interface == "reg_iface":
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

    # VCD
    lines.append("  // Dump VCD")
    lines.append("  string vcd_path;")
    lines.append("  initial begin")
    lines.append('    if (!$value$plusargs("VCD=%s", vcd_path)) begin')
    lines.append("      `ifndef SYN")
    lines.append('        vcd_path = "";')
    lines.append("      `else")
    lines.append('        vcd_path = "";')
    lines.append("      `endif")
    lines.append("    end")
    lines.append('    $display("[TB] dumpfile = %s", vcd_path);')
    lines.append("    $dumpfile(vcd_path);")
    lines.append(f"    $dumpvars(0, {top}_tb);")
    lines.append("  end\n")

    # SDF annotate (disabled for Verilator)
    lines.append("  // SDF backannotation")
    lines.append("  `ifndef VERILATOR")
    lines.append("    string sdf_path;")
    lines.append("    initial begin")
    lines.append('      if (!$value$plusargs("SDF=%s", sdf_path)) begin')
    lines.append('        sdf_path = "";')
    lines.append("      end")
    lines.append('      $display("[TB] sdf = %s", sdf_path);')
    lines.append(f'      $sdf_annotate(sdf_path, {top}_tb.u_{top}, , , "MAXIMUM");')
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
            lines.append(f"    {nm} = '0;")
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

    if compiler == "verilator":
        if interface == "tlul":
            lines.append("    tl_utils_inst = new(tl_if);")
        if interface == "reg_iface":
            lines.append("    reg_utils_inst = new(regif);")
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

    # VCD
    lines.append("  // Dump VCD")
    lines.append("  string vcd_path;")
    lines.append("  initial begin")
    lines.append('    if (!$value$plusargs("VCD=%s", vcd_path)) begin')
    lines.append("      `ifndef SYN")
    lines.append('        vcd_path = "";')
    lines.append("      `else")
    lines.append('        vcd_path = "";')
    lines.append("      `endif")
    lines.append("    end")
    lines.append('    $display("[TB] dumpfile = %s", vcd_path);')
    lines.append("    $dumpfile(vcd_path);")
    lines.append(f"    $dumpvars(0, {top}_tb);")
    lines.append("  end\n")
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
    """Write optional Verilator bus helper files for full register testbenches."""

    if simple_mode or not reg_pkg or config.compiler != "verilator":
        return []

    outdir = Path(config.output)
    helpers = {
        "tlul": (("tlul_if.sv", render_tlul_interface()), ("tlul_utils.sv", render_tlul_utils())),
        "reg_iface": (("reg_if.sv", render_reg_interface(config.top)), ("reg_utils.sv", render_reg_utils(config.top))),
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
            bus_active=(not simple_mode and config.compiler == "verilator"),
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
  fd = $fopen(cfg_path, "r");
  if (fd == 0) begin
    $display("[TB] register config not found: %s", cfg_path);
    return;
  end
  $display("[TB] no generated register sequence for {top}; ignoring optional config: %s", cfg_path);
  $fclose(fd);
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

    return render_sv_vec_driver(top, "clk_i", [], [])

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


def main(argv=None) -> int:
    """Run testbench generation from the command line."""

    config = config_from_args(parse_args(argv))
    generate_testbench_files(config)
    _normalize_generated_sv_layout(config)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
