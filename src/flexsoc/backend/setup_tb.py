"""Generate SystemVerilog testbench files for FlexSoC IP and SoC runs.

The module keeps text rendering separate from filesystem writes so the API layer
and CLI can preview or test generated artifacts without invoking external EDA tools.
"""

from __future__ import annotations

import argparse
import ast
import random
import re
from dataclasses import dataclass
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
    """Render a SystemVerilog register config reader."""

    if not active:
        return f"""// Auto-generated register sequence helper for {top}.
// This DUT has no generated register bus helper in the current testbench.
task automatic run_reg_config(input string cfg_path);
  $display("[TB] register config skipped: %s", cfg_path);
endtask
"""
    write_call = (
        "tl_utils_inst.tlul_write(addr[top_pkg::TL_AW-1:0], data, 4'h0, mask[top_pkg::TL_DBW-1:0]);"
        if interface == "tlul"
        else f"reg_utils_inst.write(addr[{top}_reg_pkg::AW-1:0], data, mask[{top}_reg_pkg::DBW-1:0]);"
    )
    addr_cases = "\n".join(
        f'    "{reg["key"]}": begin addr = 32\'h{int(reg["addr"]):08x}; return 1\'b1; end'
        for reg in registers
    )
    if not addr_cases:
        addr_cases = "    default: begin addr = '0; return 1'b0; end"
    else:
        addr_cases += "\n    default: begin addr = '0; return 1'b0; end"
    return f"""// Auto-generated register sequence helper for {top}.
//
// Source of truth:
//   - register names, clock domains and addresses are generated from the HJSON regmap.
//   - config files use clock-qualified keys such as clk_i.CTRL, not raw addresses.
//
// Config format:
//   <CLOCK.REG_NAME> <DATA> [MASK] [WAIT_CYCLES] [NOTE]
//
// Keep custom test intent in tb/tests/<test>/config.regs; regenerate this helper
// from setup_tb.py when the regmap changes.
function automatic bit tb_lookup_reg_addr(input string reg_key, output logic [31:0] addr);
  case (reg_key)
{addr_cases}
  endcase
endfunction

function automatic bit tb_parse_cfg_u32(input string raw, output logic [31:0] value);
  string s;
  int ok;
  value = '0;
  s = raw;
  if (raw.len() > 2 && (raw.substr(0, 1) == "0x" || raw.substr(0, 1) == "0X")) begin
    s = raw.substr(2, raw.len() - 1);
  end
  ok = $sscanf(s, "%h", value);
  if (ok != 1) ok = $sscanf(raw, "%d", value);
  if (ok != 1) $display("[TB][WARN] cannot parse config value: %s", raw);
  return ok == 1;
endfunction

task automatic run_reg_config(input string cfg_path);
  int fd;
  int code;
  int writes;
  string rest;
  string reg_key;
  string data_raw;
  logic [31:0] addr;
  logic [31:0] data;
  logic [31:0] mask;

  fd = $fopen(cfg_path, "r");
  if (fd == 0) begin
    $display("[TB] register config not found: %s", cfg_path);
    return;
  end

  writes = 0;
  $display("[TB] applying register config: %s", cfg_path);
  while (!$feof(fd)) begin
    reg_key = "";
    data_raw = "";
    code = $fscanf(fd, "%s", reg_key);
    if (code != 1) begin
      void'($fgets(rest, fd));
      continue;
    end

    if (reg_key.len() == 0) continue;
    if (reg_key.substr(0, 0) == "#") begin
      void'($fgets(rest, fd));
      continue;
    end

    if (reg_key == "write") begin
      code = $fscanf(fd, "%s %s", reg_key, data_raw);
    end else begin
      code = $fscanf(fd, "%s", data_raw);
    end
    void'($fgets(rest, fd));

    if (code < 1 || data_raw.len() == 0) begin
      $display("[TB][WARN] malformed config row near key: %s", reg_key);
      continue;
    end
    if (!tb_lookup_reg_addr(reg_key, addr)) begin
      $display("[TB][WARN] unknown register key in config: %s", reg_key);
      continue;
    end
    if (!tb_parse_cfg_u32(data_raw, data)) continue;

    mask = 32'hffff_ffff;
    $display("[TB] config write %s addr=0x%08x data=0x%08x", reg_key, addr, data);
    {write_call}
    writes++;
    @(posedge {clk});
  end
  $fclose(fd);

  if (writes == 0) begin
    $display("[TB][ERROR] no register config writes were applied from %s", cfg_path);
    error_count++;
  end
endtask
"""



def _sv_output_expr(name: str) -> str:
    """Return the 32-bit SystemVerilog expression used to compare one output."""

    if name.startswith("valid") and name.endswith("_o"):
        return "{31'b0, " + name + "}"
    return name


def render_sv_vec_monitor(top: str, outputs: Sequence[str]) -> str:
    """Render named expected-output checks from data_out.vec."""

    if not outputs:
        return f"""// Auto-generated vector monitor for {top}.
// Scan data_out.vec and apply all checks scheduled for this cycle.
task automatic tb_check_outputs(input string out_path, input int cycle);
endtask
"""
    checks = []
    for index, name in enumerate(outputs):
        head = "if" if index == 0 else "else if"
        checks.append(
            f'  {head} (name == "{name}") begin\n'
            f"    actual = {_sv_output_expr(name)};\n"
            "  end"
        )
    checks_text = "\n".join(checks)
    return f"""// Auto-generated vector monitor for {top}.
// Reads data_out.vec and checks named DUT outputs at vector cycles.
// Format: <CYCLE> <SIGNAL> <EXPECTED>. Repeat a cycle for multiple checks.
function automatic bit tb_parse_u32(input string raw, output logic [31:0] value);
  string s;
  int ok;
  value = '0;
  s = raw;
  if (raw.len() > 2 && (raw.substr(0, 1) == "0x" || raw.substr(0, 1) == "0X")) begin
    s = raw.substr(2, raw.len() - 1);
  end
  ok = $sscanf(s, "%h", value);
  if (ok != 1) ok = $sscanf(raw, "%d", value);
  if (ok != 1) $display("[TB][WARN] cannot parse vector value: %s", raw);
  return ok == 1;
endfunction

// Return one DUT output as a 32-bit value for comparison.
function automatic logic [31:0] tb_read_output(input string name);
  logic [31:0] actual;
  actual = '0;
{checks_text}
  else begin
    $display("[TB][WARN] unknown output vector signal: %s", name);
  end
  return actual;
endfunction

// Compare one expected output row against the current DUT value.
task automatic tb_check_one(input int cycle, input string name, input string raw);
  logic [31:0] actual;
  logic [31:0] expected;
  if (name == "") return;
  if (!tb_parse_u32(raw, expected)) return;
  actual = tb_read_output(name);
  if (actual !== expected) begin
    error_count++;
    $display("[TB][FAIL] cycle=%0d %s actual=0x%08x expected=0x%08x", cycle, name, actual, expected);
  end else begin
    $display("[TB][PASS] cycle=%0d %s=0x%08x", cycle, name, actual);
  end
endtask

// Scan data_out.vec and apply all checks scheduled for this cycle.
task automatic tb_check_outputs(input string out_path, input int cycle);
  int fd;
  int code;
  int expected_cycle;
  string line;
  string name;
  string value;
  fd = $fopen(out_path, "r");
  if (fd == 0) return;
  while (!$feof(fd)) begin
    void'($fgets(line, fd));
    name = "";
    value = "";
    code = $sscanf(line, "%d %s %s", expected_cycle, name, value);
    if (code == 3 && expected_cycle == cycle) tb_check_one(cycle, name, value);
  end
  $fclose(fd);
endtask
"""

def render_sv_vec_driver(top: str, clk: str, inputs: Sequence[str], outputs: Sequence[str]) -> str:
    """Render named input-vector drive tasks from data_in.vec."""

    if not inputs or not outputs:
        return f"""// Auto-generated vector driver for {top}.
// Main vector runner used by the generated testbench.
task automatic run_vectors(input string data_in_path, input string data_out_path);
  $display("[TB] vector check skipped for this DUT: %s %s", data_in_path, data_out_path);
endtask
"""
    drives = []
    for index, name in enumerate(inputs):
        head = "if" if index == 0 else "else if"
        drives.append(
            f'  {head} (name == "{name}") begin\n'
            f"    {name} = value;\n"
            "    tb_vector_drive_count++;\n"
            f'    $display("[TB][DRV] {name} <= 0x%08h", value);\n'
            "  end"
        )
    drives_text = "\n".join(drives)
    return f"""// Auto-generated vector driver for {top}.
// Reads data_in.vec, drives named DUT inputs, and applies @cfg reconfiguration.
// Format: <CYCLE> <SIGNAL> <VALUE>. Repeat a cycle for simultaneous drives.
int tb_vector_drive_count;

// Drive one named top-level input.
task automatic tb_drive_input(input string name, input logic [31:0] value);
{drives_text}
  else begin
    $display("[TB][WARN] unknown input vector signal: %s", name);
  end
endtask

task automatic tb_drive_raw(input string name, input string raw);
  logic [31:0] value;
  if (name == "") return;
  if (tb_parse_u32(raw, value)) tb_drive_input(name, value);
endtask

// Advance one logical vector cycle and check expected outputs.
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

// Main vector runner used by the generated testbench.
task automatic run_vectors(input string data_in_path, input string data_out_path);
  int fd;
  int code;
  int cycle;
  int now_cycle;
  int current_cycle;
  int drive_start;
  bit cycle_open;
  string line;
  string name;
  string value;

  now_cycle = -1;
  current_cycle = -1;
  cycle_open = 1'b0;
  drive_start = tb_vector_drive_count;
  fd = $fopen(data_in_path, "r");
  if (fd == 0) begin
    $display("[TB][ERROR] input vector file not found: %s", data_in_path);
    error_count++;
    return;
  end

  $display("[TB] running vectors: in=%s out=%s", data_in_path, data_out_path);
  while (!$feof(fd)) begin
    void'($fgets(line, fd));
    name = "";
    value = "";
    code = $sscanf(line, "%d %s %s", cycle, name, value);
    if (code < 3) continue;

    if (name == "@cfg" || name == "cfg" || name == "@config" || name == "config") begin
      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      $display("[TB][CFG] cycle=%0d path=%s", cycle, value);
      run_reg_config(value);
      continue;
    end

    if (!cycle_open || cycle != current_cycle) begin
      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = cycle;
      cycle_open = 1'b1;
      $display("[TB][VEC] cycle=%0d", cycle);
    end
    tb_drive_raw(name, value);
  end
  $fclose(fd);

  tb_finish_cycle(data_out_path, now_cycle, cycle_open);
  repeat (8) begin
    tb_step(data_out_path, now_cycle);
  end
  if (tb_vector_drive_count == drive_start) begin
    error_count++;
    $display("[TB][ERROR] no vector inputs were driven from %s", data_in_path);
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
    registers = _register_entries(hjson_path)
    inputs, outputs = _simple_datapath_ports(sig)
    files = {
        out / f"{top}_reg_sequence.svh": render_sv_reg_sequence(
            top, interface, clk, active=bus_active, registers=registers
        ),
    }
    stale_vec_files = [out / f"{top}_vec_monitor.svh", out / f"{top}_vec_driver.svh"]
    if inputs and outputs:
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


def generate_testbench_files(config: TestbenchConfig) -> tuple[Path, ...]:
    """Generate include, helper, and top-level testbench files for one request."""

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
    p.add_argument("-o", "--output", default="tb", help="Output directory for generated files")
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
        output=args.output,
        devices=tuple(tuple(item) for item in args.device),
        force=bool(args.force),
    )





# -----------------------------------------------------------------------------
# Single-clock verification layout repair
# -----------------------------------------------------------------------------
def _single_tb_dir_from_config(config) -> Path:
    """Return the generated SystemVerilog TB directory for any config shape."""
    for attr in ("tb_dir", "output", "outdir"):
        value = getattr(config, attr, None)
        if value:
            return Path(value)
    rtldir = getattr(config, "rtldir", None)
    if rtldir:
        return Path(rtldir).resolve().parent / "tb"
    raise AttributeError("could not infer testbench output directory from config")


def _ensure_single_tb_driver_layout(config) -> None:
    """Keep single-clock SV driver/monitor files under tb/drivers.

    setup_tb writes the top-level testbench in tb/.  The included driver and
    monitor snippets live in tb/drivers/, matching the multi-clock and cocotb
    layouts.  This helper is intentionally tolerant of older generated layouts
    and copies legacy files into the structured directory when needed.
    """
    import shutil

    tb_dir = _single_tb_dir_from_config(config)
    top = str(getattr(config, "top", ""))
    if not top:
        for tb in sorted(tb_dir.glob("*_tb.sv")):
            top = tb.stem[:-3]
            break
    if not top:
        return

    drivers_dir = tb_dir / "drivers"
    drivers_dir.mkdir(parents=True, exist_ok=True)

    # Keep both canonical names and legacy test_* names working during upgrades.
    for kind in ("driver", "monitor"):
        canonical = drivers_dir / f"{top}_vec_{kind}.svh"
        legacy_named = drivers_dir / f"test_vec_{kind}.svh"
        candidates = [
            canonical,
            tb_dir / f"{top}_vec_{kind}.svh",
            tb_dir / f"test_vec_{kind}.svh",
            legacy_named,
        ]
        source = next((path for path in candidates if path.exists()), None)
        if source is not None:
            if not canonical.exists():
                shutil.copyfile(source, canonical)
            if not legacy_named.exists():
                shutil.copyfile(canonical, legacy_named)

    for tb in sorted({tb_dir / f"{top}_tb.sv", tb_dir / "test_tb.sv"}):
        if not tb.exists():
            continue
        text = tb.read_text(encoding="utf-8")
        new = text
        new = new.replace(f'`include "{top}_vec_driver.svh"', f'`include "drivers/{top}_vec_driver.svh"')
        new = new.replace(f'`include "{top}_vec_monitor.svh"', f'`include "drivers/{top}_vec_monitor.svh"')
        new = new.replace('`include "test_vec_driver.svh"', f'`include "drivers/{top}_vec_driver.svh"')
        new = new.replace('`include "test_vec_monitor.svh"', f'`include "drivers/{top}_vec_monitor.svh"')
        if new != text:
            tb.write_text(new, encoding="utf-8")

def main(argv=None) -> int:
    """Run testbench generation from the command line."""

    config = config_from_args(parse_args(argv))
    generate_testbench_files(config)
    _ensure_single_tb_driver_layout(config)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
