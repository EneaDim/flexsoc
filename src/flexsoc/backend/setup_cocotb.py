"""Generate cocotb scaffolding for FlexSoC IP simulation.

The module keeps file discovery, rendering, and writing separate so the API layer
can call the backend directly without duplicating Makefile behavior.
"""

from __future__ import annotations

import argparse
import re
from dataclasses import dataclass
from pathlib import Path
from textwrap import dedent
from typing import Sequence

from .setup_tb import TEST_NAMES, _candidate_hjson_path, _register_entries


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


def repo_root() -> Path:
    """Return the repository root inferred from the installed backend module."""

    return Path(__file__).resolve().parents[3]


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    """Parse command-line options for direct backend execution."""

    parser = argparse.ArgumentParser(description="Generate cocotb scaffolding from RTL sources")
    parser.add_argument("--top", required=True, help="Top module name without extension.")
    parser.add_argument("--itf", required=True, choices=["reg_iface", "tlul"], help="Register interface.")
    parser.add_argument("--output", default="tb/cocotb", help="Output directory.")
    parser.add_argument("--vsv", choices=["sv", "v"], default="sv", help="RTL language mode.")
    parser.add_argument("--rtl-dir", default="rtl", help="RTL source directory.")
    parser.add_argument("--ips-root", default=None, help="IP root used for include discovery.")
    parser.add_argument(
        "--sim",
        choices=["verilator", "icarus", "questa", "vcs", "xcelium"],
        default="verilator",
        help="cocotb simulator backend.",
    )
    parser.add_argument("--clk", default="clk_i", help="Clock signal name.")
    parser.add_argument("--rst", default="rst_ni", help="Reset signal name.")
    parser.add_argument("--rst-active", choices=["low", "high"], default="low", help="Reset polarity.")
    parser.add_argument("--period-ns", type=float, default=10.0, help="Clock period in ns.")
    parser.add_argument("--nbit", type=int, default=32, help="Default random operand width.")
    parser.add_argument("--n-op", type=int, default=10, help="Default smoke loop iterations.")
    return parser.parse_args(argv)


def config_from_args(args: argparse.Namespace) -> CocotbConfig:
    """Convert parsed CLI options into the backend config object."""

    return CocotbConfig(
        top=args.top,
        interface=args.itf,
        output=Path(args.output).resolve(),
        rtl_dir=Path(args.rtl_dir).resolve(),
        ips_root=Path(args.ips_root).resolve() if args.ips_root else None,
        simulator=args.sim,
        clk=args.clk,
        rst=args.rst,
        rst_active=args.rst_active,
        period_ns=args.period_ns,
        nbit=args.nbit,
        n_op=args.n_op,
        vsv=args.vsv,
    )


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

def render_makefile(cfg: CocotbConfig, sources: Sequence[Path]) -> str:
    """Render the cocotb Makefile for RTL or gate-level simulation."""

    repo = repo_root()
    out_dir = cfg.output.resolve()
    rtl_dir = cfg.rtl_dir.resolve()
    include_dirs = [repo / "hw/ips/pkgs", repo / "hw/ips/prim", repo / "hw/ips/prim_opentitan", repo / "hw/ips/tlul"]
    includes = " ".join(f"-I{path}" for path in [rtl_dir, *include_dirs])
    return dedent(
        f"""\
        # Auto-generated Makefile
        SIM               ?= {cfg.simulator}
        TOPLEVEL_LANG     ?= verilog

        PWD               := $(shell pwd)
        TOPLEVEL          = {cfg.top}_tb
        MODULE            = {cfg.top}_tb

        ifneq ($(filter clean veryclean distclean,$(MAKECMDGOALS)),)
          SIM := icarus
        endif

        ifeq ($(GATES),yes)
          SIM := icarus
        else
          SIM ?= {cfg.simulator}
        endif

        SIM_BUILD         ?= sim_build/rtl

        ifneq ($(GATES),yes)

        {render_source_block(sources)}

        COMPILE_ARGS += --sv --timing
        COMPILE_ARGS += --trace --trace-fst --trace-structs
        export WAVES ?= 1
        COMPILE_ARGS += -Wno-WIDTHEXPAND
        COMPILE_ARGS += -Wno-WIDTHTRUNC
        COMPILE_ARGS += -Wno-UNOPTFLAT

        else
        SIM_BUILD         ?= sim_build/gl
        COMPILE_ARGS      += -DFUNCTIONAL -DUSE_POWER_PINS -DSIM -DUNIT_DELAY=#1
        VERILOG_SOURCES   += ../../verilog/primitives.v
        VERILOG_SOURCES   += ../../verilog/sky130_fd_sc_hd.v
        VERILOG_SOURCES   += ../../syn/{cfg.top}_synth.v
        endif

        COMPILE_ARGS += {includes}
        export COCOTB_RESULTS_FILE ?= $(abspath results.xml)
        TEST_NAME ?= smoke

        export TEST_NAME
        export REG_CONFIG ?= $(abspath ../tests/$(TEST_NAME)/config.regs)
        export DATA_IN  ?= $(abspath ../tests/$(TEST_NAME)/data_in.vec)
        export DATA_OUT ?= $(abspath ../tests/$(TEST_NAME)/data_out.vec)
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


def render_reg_driver_py(registers: Sequence[dict[str, object]] = ()) -> str:
    """Render a lightweight cocotb register-sequence driver."""

    entries = "".join(f'    "{reg["key"]}": 0x{int(reg["addr"]):08x},\n' for reg in registers)
    return f"""\
# Auto-generated FlexSoC cocotb register driver.
#
# This file is generated by setup_cocotb. Edit setup_cocotb.py if the generic
# behavior changes; edit the model under model/ to change test content.
#
# Source of truth:
#   - REGISTER_ADDRS is generated from the HJSON regmap.
#   - config files use clock-qualified keys such as clk_i.CTRL.
#
# Config format:
#   <CLOCK.REG_NAME> <DATA> [MASK] [WAIT_CYCLES] [NOTE]

import os

from cocotb.triggers import RisingEdge


REGISTER_ADDRS = {{
{entries}}}


def _resolve_register(key):
    # Map a config.regs register key to its byte address.
    if key in REGISTER_ADDRS:
        return REGISTER_ADDRS[key]
    if "." not in key:
        matches = [addr for name, addr in REGISTER_ADDRS.items() if name.endswith("." + key)]
        if len(matches) == 1:
            return matches[0]
    raise KeyError(f"unknown register key: {{key}}")


def load_register_config(path=None):
    # Load config.regs rows as register write transactions.
    # Notes are optional. Bare register names are accepted only when they
    # uniquely map to one clock-qualified key.
    cfg_path = path or os.environ.get("REG_CONFIG")
    if not cfg_path:
        return []
    rows = []
    try:
        with open(cfg_path, encoding="utf-8") as handle:
            for line in handle:
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                parts = line.split()
                if len(parts) < 2:
                    continue
                key, data_text, *rest = parts
                mask = int(rest[0], 0) if len(rest) >= 1 else 0xFFFFFFFF
                wait_cycles = int(rest[1], 0) if len(rest) >= 2 else 1
                note = " ".join(rest[2:]) if len(rest) >= 3 else ""
                rows.append((key, _resolve_register(key), int(data_text, 0), mask, wait_cycles, note))
    except FileNotFoundError:
        return []
    return rows


async def _tlul_write(dut, clk, addr, data, mask):
    # Issue one simple TL-UL register write.
    dut.tl_i_d_ready.value = 1
    dut.tl_i_a_valid.value = 1
    dut.tl_i_a_opcode.value = 1  # PutFullData
    dut.tl_i_a_param.value = 0
    dut.tl_i_a_size.value = 2
    dut.tl_i_a_source.value = 0
    dut.tl_i_a_address.value = addr
    dut.tl_i_a_mask.value = mask & 0xF
    dut.tl_i_a_data.value = data
    await RisingEdge(clk)
    dut.tl_i_a_valid.value = 0
    await RisingEdge(clk)


async def run_register_config(dut, path=None):
    # Apply one config.regs file before or during vector simulation.
    rows = load_register_config(path)
    clk = getattr(dut, "clk_i", None)
    can_tlul = clk is not None and hasattr(dut, "tl_i_a_valid")
    for key, addr, data, mask, wait_cycles, note in rows:
        dut._log.info("config write %s addr=0x%08x data=0x%08x mask=0x%08x %s", key, addr, data, mask, note)
        if can_tlul:
            await _tlul_write(dut, clk, addr, data, mask)
        for _ in range(wait_cycles):
            if clk is not None:
                await RisingEdge(clk)
"""



def render_vec_monitor_py() -> str:
    """Render a cocotb checker for data_out.vec files."""

    return dedent(
        """\
        # Auto-generated cocotb monitor for data_out.vec files.

        from pathlib import Path


        def _value(text):
            # Parse a vector value using Python integer syntax, including 0x....
            return int(str(text), 0) & 0xFFFFFFFF


        def load_expected(path=None):
            # Load data_out.vec and group expected signals by cycle.
            rows_by_cycle = {}
            if not path:
                return []
            try:
                with open(str(path), encoding="utf-8") as handle:
                    for line in handle:
                        line = line.strip()
                        if not line or line.startswith("#"):
                            continue
                        parts = line.split()
                        if len(parts) < 3:
                            continue
                        cycle = int(parts[0], 0)
                        pairs = [
                            (parts[i], _value(parts[i + 1]))
                            for i in range(1, len(parts) - 1, 2)
                        ]
                        if pairs:
                            rows_by_cycle.setdefault(cycle, []).extend(pairs)
            except FileNotFoundError:
                return []
            return [(cycle, rows_by_cycle[cycle]) for cycle in sorted(rows_by_cycle)]


        class LatencyMonitor:
            # Check generated expected outputs at named vector cycles.
            def __init__(self, dut, expected_rows=None):
                self.dut = dut
                if isinstance(expected_rows, (str, Path)):
                    expected_rows = load_expected(expected_rows)
                self.expected = expected_rows or []

            def check(self, cycle):
                for expected_cycle, pairs in self.expected:
                    if expected_cycle != cycle:
                        continue
                    for name, expected in pairs:
                        if not hasattr(self.dut, name):
                            self.dut._log.info("vector check skipped: missing %s", name)
                            continue
                        actual = int(getattr(self.dut, name).value) & 0xFFFFFFFF
                        assert actual == (expected & 0xFFFFFFFF), (
                            f"cycle={cycle} {name} actual=0x{actual:08x} expected=0x{expected:08x}"
                        )
        """
    )

def render_vec_driver_py() -> str:
    """Render data_in/data_out vector loaders and a named input driver."""

    return dedent(
        'import os\n\nfrom cocotb.triggers import FallingEdge, NextTimeStep, ReadOnly, RisingEdge\n\n\nCONFIG_TOKENS = {"@cfg", "cfg", "@config", "config"}\n\n\ndef load_vectors(path=None):\n    vec_path = path or os.environ.get("DATA_IN")\n    rows = []\n    if not vec_path:\n        return rows\n    try:\n        with open(vec_path, encoding="utf-8") as handle:\n            for line in handle:\n                line = line.strip()\n                if not line or line.startswith("#"):\n                    continue\n                parts = line.split()\n                cycle = int(parts[0], 0)\n                if len(parts) >= 3 and parts[1] in CONFIG_TOKENS:\n                    rows.append((cycle, [(parts[1], parts[2])]))\n                    continue\n                pairs = [(parts[i], int(parts[i + 1], 0)) for i in range(1, len(parts) - 1, 2)]\n                if pairs:\n                    rows.append((cycle, pairs))\n    except FileNotFoundError:\n        return rows\n    return rows\n\n\nasync def _sample_cycle(clk, monitor, state):\n    state["now"] += 1\n    await RisingEdge(clk)\n    await ReadOnly()\n    monitor.check(state["now"])\n    await NextTimeStep()\n\n\nasync def _finish_open_cycle(clk, monitor, state):\n    if state["open"]:\n        await _sample_cycle(clk, monitor, state)\n        state["open"] = False\n\n\nasync def _wait_before_drive(clk, monitor, state, target_cycle):\n    while state["now"] < target_cycle - 1:\n        await _sample_cycle(clk, monitor, state)\n    await FallingEdge(clk)\n\n\nasync def drive_vectors(dut, clk, rows, monitor, config_runner=None):\n    state = {"now": -1, "open": False}\n    current_cycle = None\n    drive_count = 0\n\n    for cycle, pairs in rows:\n        if pairs and pairs[0][0] in CONFIG_TOKENS:\n            await _finish_open_cycle(clk, monitor, state)\n            await _wait_before_drive(clk, monitor, state, cycle)\n            current_cycle = None\n            if config_runner is not None:\n                await config_runner(str(pairs[0][1]))\n            continue\n\n        if not state["open"] or cycle != current_cycle:\n            await _finish_open_cycle(clk, monitor, state)\n            await _wait_before_drive(clk, monitor, state, cycle)\n            current_cycle = cycle\n            state["open"] = True\n            dut._log.info("vector cycle=%d", cycle)\n\n        for name, value in pairs:\n            if hasattr(dut, name):\n                getattr(dut, name).value = value\n                drive_count += 1\n                dut._log.info("drive %s <= 0x%08x", name, value & 0xFFFFFFFF)\n            else:\n                dut._log.warning("unknown input vector signal: %s", name)\n\n    await _finish_open_cycle(clk, monitor, state)\n    for _ in range(8):\n        await _sample_cycle(clk, monitor, state)\n\n    if drive_count == 0:\n        raise AssertionError("no vector inputs were driven")\n'
    )

def render_python_test(cfg: CocotbConfig) -> str:
    """Render a small cocotb test that selects vectors by TEST_NAME."""

    default_test = TEST_NAMES[0]
    return dedent(
        f"""\
        # Auto-generated cocotb test entry point.
        # The model generated by setup_model writes the files. This test only
        # selects a TEST_NAME and consumes config.regs/data_in.vec/data_out.vec.

        import os
        from pathlib import Path

        import cocotb
        from cocotb.clock import Clock
        from cocotb.triggers import RisingEdge

        from drivers.reg_driver import run_register_config
        from drivers.vec_driver import drive_vectors, load_vectors
        from drivers.vec_monitor import LatencyMonitor

        DEFAULT_TEST = {default_test!r}


        def selected_test():
            # Return the TEST_NAME selected by fx --set TEST_NAME=....
            return os.environ.get("TEST_NAME", DEFAULT_TEST).strip() or DEFAULT_TEST


        def test_file(env_name, test_name, filename):
            # Resolve one generated file path with an optional environment override.
            override = os.environ.get(env_name, "").strip()
            if override:
                return override
            return str((Path(__file__).resolve().parent / ".." / "tests" / test_name / filename).resolve())


        @cocotb.test()
        async def {cfg.top}_generated_test(dut):
            test_name = selected_test()
            cocotb.start_soon(Clock(dut.clk_i, 10, unit="ns").start())
            dut.rst_ni.value = 0
            for _ in range(4):
                await RisingEdge(dut.clk_i)
            dut.rst_ni.value = 1

            cfg_path = test_file("REG_CONFIG", test_name, "config.regs")
            data_in = test_file("DATA_IN", test_name, "data_in.vec")
            data_out = test_file("DATA_OUT", test_name, "data_out.vec")
            dut._log.info("TEST_NAME=%s", test_name)
            dut._log.info("REG_CONFIG=%s", cfg_path)
            dut._log.info("DATA_IN=%s", data_in)
            dut._log.info("DATA_OUT=%s", data_out)

            await run_register_config(dut, cfg_path)
            await drive_vectors(
                dut,
                dut.clk_i,
                load_vectors(data_in),
                LatencyMonitor(dut, data_out),
                lambda path: run_register_config(dut, path),
            )
        """
    )

def render_tlul_wrapper(cfg: CocotbConfig) -> str:
    """Render the SystemVerilog wrapper used as the cocotb top-level."""

    port_info = parse_top_ports(find_top_file(cfg.rtl_dir, cfg.top))
    extra_decls = render_extra_port_declarations(port_info)
    return dedent(
        f"""\
        `timescale 1ns/1ps
        module {cfg.top}_tb;
          logic {cfg.clk};
          logic {cfg.rst};
        {extra_decls}
          logic                       tl_i_a_valid;
          tlul_pkg::tl_a_op_e         tl_i_a_opcode;
          logic [2:0]                 tl_i_a_param;
          logic [top_pkg::TL_SZW-1:0] tl_i_a_size;
          logic [top_pkg::TL_AIW-1:0] tl_i_a_source;
          logic [top_pkg::TL_AW-1:0]  tl_i_a_address;
          logic [top_pkg::TL_DBW-1:0] tl_i_a_mask;
          logic [top_pkg::TL_DW-1:0]  tl_i_a_data;
          logic                       tl_i_d_ready;
          logic                       tl_o_d_valid;
          tlul_pkg::tl_d_op_e         tl_o_d_opcode;
          logic [top_pkg::TL_DW-1:0]  tl_o_d_data;
          logic                       tl_o_d_error;
          logic                       tl_o_a_ready;
          tlul_pkg::tl_h2d_t tl_i;
          tlul_pkg::tl_d2h_t tl_o;
          assign tl_i.a_valid   = tl_i_a_valid;
          assign tl_i.a_opcode  = tl_i_a_opcode;
          assign tl_i.a_param   = tl_i_a_param;
          assign tl_i.a_size    = tl_i_a_size;
          assign tl_i.a_source  = tl_i_a_source;
          assign tl_i.a_address = tl_i_a_address;
          assign tl_i.a_mask    = tl_i_a_mask;
          assign tl_i.a_data    = tl_i_a_data;
          assign tl_i.d_ready   = tl_i_d_ready;
          logic [tlul_pkg::H2DCmdIntgWidth-1:0] cmd_intg_calc;
          logic [tlul_pkg::DataIntgWidth-1:0]   data_intg_calc;
          always_comb begin
            /* verilator lint_off IMPLICITSTATIC */
            tlul_pkg::tl_h2d_t t = '0;
            /* verilator lint_on */
            t.a_address         = tl_i_a_address;
            t.a_opcode          = tl_i_a_opcode;
            t.a_mask            = tl_i_a_mask;
            t.a_user.instr_type = prim_mubi_pkg::MuBi4False;
            cmd_intg_calc       = tlul_pkg::get_cmd_intg(t);
            data_intg_calc      = tlul_pkg::get_data_intg(tl_i_a_data);
          end
          assign tl_i.a_user.instr_type = prim_mubi_pkg::MuBi4False;
          assign tl_i.a_user.cmd_intg   = cmd_intg_calc;
          assign tl_i.a_user.data_intg  = data_intg_calc;
          assign tl_o_d_valid  = tl_o.d_valid;
          assign tl_o_d_opcode = tl_o.d_opcode;
          assign tl_o_d_data   = tl_o.d_data;
          assign tl_o_d_error  = tl_o.d_error;
          assign tl_o_a_ready  = tl_o.a_ready;
          initial begin
            $dumpfile("{cfg.top}_tb.vcd");
            $dumpvars(0, {cfg.top}_tb);
            #1;
          end
          {cfg.top} u_{cfg.top} (
            .{cfg.clk}({cfg.clk}),
            .{cfg.rst}({cfg.rst}),
            .*
          );
        endmodule
        """
    )


def _write_cocotb_scaffold_impl(cfg: CocotbConfig) -> list[Path]:
    """Write the cocotb scaffold and return generated paths."""

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
        out_dir / f"{cfg.top}_tb.py": render_python_test(cfg),
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


def _extract_scalar_declarations_from_wrapper(text: str, clk: str, rst: str) -> str:
    """Extract user scalar declarations from a previously generated wrapper."""

    lines = text.splitlines()
    scalars: list[str] = []
    seen_clock_reset = False
    for raw in lines:
        line = raw.strip()
        if not line:
            continue
        if re.fullmatch(rf"logic\s+{re.escape(clk)}\s*;", line) or re.fullmatch(rf"logic\s+{re.escape(rst)}\s*;", line):
            seen_clock_reset = True
            continue
        if "tl_i_a_valid" in line:
            break
        if not seen_clock_reset:
            continue
        if line.startswith("logic ") and not line.startswith("logic                       tl_") and " tl_" not in line:
            scalars.append(line)
    if not scalars:
        return "  // No extra scalar DUT ports detected."
    return "\n".join(f"  {line}" for line in scalars)


def _render_tlul_wrapper(config: CocotbConfig, previous_text: str) -> str:
    """Render a readable TL-UL SystemVerilog wrapper using existing declarations."""

    top = config.top
    clk = config.clk
    rst = config.rst
    scalar_decls = _extract_scalar_declarations_from_wrapper(previous_text, clk, rst)
    return f"""`timescale 1ns/1ps

// Auto-generated Cocotb TL-UL wrapper for {top}.
// Edit setup_cocotb.py instead of this generated file.
module {top}_tb;

  // Clock and reset.
  logic {clk};
  logic {rst};

  // Scalar DUT ports discovered from the RTL header.
{scalar_decls}

  // TL-UL request channel fields driven from Cocotb.
  logic                       tl_i_a_valid;
  tlul_pkg::tl_a_op_e         tl_i_a_opcode;
  logic [2:0]                 tl_i_a_param;
  logic [top_pkg::TL_SZW-1:0] tl_i_a_size;
  logic [top_pkg::TL_AIW-1:0] tl_i_a_source;
  logic [top_pkg::TL_AW-1:0]  tl_i_a_address;
  logic [top_pkg::TL_DBW-1:0] tl_i_a_mask;
  logic [top_pkg::TL_DW-1:0]  tl_i_a_data;
  logic                       tl_i_d_ready;

  // TL-UL response channel fields sampled by Cocotb.
  logic                       tl_o_d_valid;
  tlul_pkg::tl_d_op_e         tl_o_d_opcode;
  logic [top_pkg::TL_DW-1:0]  tl_o_d_data;
  logic                       tl_o_d_error;
  logic                       tl_o_a_ready;

  // Packed TL-UL buses connected to the DUT.
  tlul_pkg::tl_h2d_t          tl_i;
  tlul_pkg::tl_d2h_t          tl_o;

  assign tl_i.a_valid   = tl_i_a_valid;
  assign tl_i.a_opcode  = tl_i_a_opcode;
  assign tl_i.a_param   = tl_i_a_param;
  assign tl_i.a_size    = tl_i_a_size;
  assign tl_i.a_source  = tl_i_a_source;
  assign tl_i.a_address = tl_i_a_address;
  assign tl_i.a_mask    = tl_i_a_mask;
  assign tl_i.a_data    = tl_i_a_data;
  assign tl_i.d_ready   = tl_i_d_ready;

  // Generate TL-UL integrity sideband values from the unpacked fields.
  logic [tlul_pkg::H2DCmdIntgWidth-1:0] cmd_intg_calc;
  logic [tlul_pkg::DataIntgWidth-1:0]   data_intg_calc;

  always_comb begin
    /* verilator lint_off IMPLICITSTATIC */
    tlul_pkg::tl_h2d_t t = '0;
    /* verilator lint_on */

    t.a_address         = tl_i_a_address;
    t.a_opcode          = tl_i_a_opcode;
    t.a_mask            = tl_i_a_mask;
    t.a_user.instr_type = prim_mubi_pkg::MuBi4False;

    cmd_intg_calc       = tlul_pkg::get_cmd_intg(t);
    data_intg_calc      = tlul_pkg::get_data_intg(tl_i_a_data);
  end

  assign tl_i.a_user.instr_type = prim_mubi_pkg::MuBi4False;
  assign tl_i.a_user.cmd_intg   = cmd_intg_calc;
  assign tl_i.a_user.data_intg  = data_intg_calc;

  assign tl_o_d_valid  = tl_o.d_valid;
  assign tl_o_d_opcode = tl_o.d_opcode;
  assign tl_o_d_data   = tl_o.d_data;
  assign tl_o_d_error  = tl_o.d_error;
  assign tl_o_a_ready  = tl_o.a_ready;

  // Wave dump for local debug.
  initial begin
    $dumpfile("{top}_tb.vcd");
    $dumpvars(0, {top}_tb);
    #1;
  end

  // Device under test.
  {top} u_{top} (
    .{clk}({clk}),
    .{rst}({rst}),
    .*
  );

endmodule
"""


def _format_generated_tlul_wrapper(config: CocotbConfig) -> None:
    """Post-format the generated TL-UL wrapper if the scaffold emitted one."""

    path = _generated_tlul_wrapper_path(config)
    if not path.exists():
        return
    text = path.read_text(encoding="utf-8")
    if "tlul_pkg::tl_h2d_t" not in text or f"module {config.top}_tb" not in text:
        return
    path.write_text(_render_tlul_wrapper(config, text), encoding="utf-8")

def write_cocotb_scaffold(config: CocotbConfig) -> list[Path]:
    """Generate Cocotb scaffolding and normalize the generated TL-UL wrapper."""

    written = _write_cocotb_scaffold_impl(config)
    if config.interface == "tlul":
        _format_generated_tlul_wrapper(config)
    if written is None:
        return sorted(path for path in Path(config.output).iterdir() if path.is_file())
    return written

def main() -> None:
    """Run the cocotb scaffold generator from the command line."""

    cfg = config_from_args(parse_args())
    written = write_cocotb_scaffold(cfg)
    print(f"Generated {len(written)} files in: {cfg.output.resolve()}")


if __name__ == "__main__":
    main()
