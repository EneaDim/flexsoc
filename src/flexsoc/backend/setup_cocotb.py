"""Generate cocotb scaffolding for FlexSoC IP simulation.

The module keeps file discovery, rendering, and writing separate so the API layer
can call the backend directly without duplicating Makefile behavior.
"""

from __future__ import annotations

import argparse
import re
from dataclasses import dataclass, replace
from pathlib import Path
from textwrap import dedent
from typing import Sequence

from flexsoc.clocking import ClockConfig, clock_config

from .setup_tb import _candidate_hjson_path, _register_entries, render_packed_tlul_helpers


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
    """Return the repository root inferred from the installed backend module."""

    return Path(__file__).resolve().parents[3]


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    """Parse command-line options for direct backend execution."""

    parser = argparse.ArgumentParser(description="Generate cocotb scaffolding from RTL sources")
    parser.add_argument("--top", required=True, help="Top module name without extension.")
    parser.add_argument("--itf", required=True, choices=["reg_iface", "tlul"], help="Register interface.")
    parser.add_argument("--output", default="dv/functional/tb/cocotb", help="Output directory.")
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
    parser.add_argument("-f", "--force", action="store_true", help="Overwrite generated files.")
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
        force=args.force,
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
        SDF_FILE ?=
        GLS_MODELS ?=
        GLS_NETLIST ?= {default_netlist}

        VERILOG_SOURCES += $(GLS_MODELS)
        VERILOG_SOURCES += $(GLS_NETLIST)
        COMPILE_ARGS += -g2012 -DSIM -DSYN -DFLEXSOC_GLS_EXTERNAL_MODELS -DFLEXSOC_COCOTB_WAVE_OWNER

        ifeq ($(TIMING_MODE),zero)
        COMPILE_ARGS += -DFUNCTIONAL -DUNIT_DELAY=\\#0 -gno-specify
        else ifeq ($(TIMING_MODE),unit)
        COMPILE_ARGS += -DFUNCTIONAL -gno-specify -DUNIT_DELAY=\\#1
        else ifneq ($(filter $(TIMING_MODE),min typ max),)
        ifeq ($(strip $(SDF_FILE)),)
        $(error SDF_FILE is required when TIMING_MODE=$(TIMING_MODE))
        endif
        COMPILE_ARGS += -gspecify -T$(TIMING_MODE) -DFLEXSOC_ENABLE_SDF
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
    include_dirs = [repo / "hw/ips/pkgs", repo / "hw/ips/prim", repo / "hw/ips/prim_opentitan", repo / "hw/ips/tlul"]
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

from cocotb.triggers import RisingEdge, Timer

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


async def _cycle(clk):
    await RisingEdge(clk)
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
    await _cycle(clk)


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

    _drive_idle(dut)
    await _cycle(clk)

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
    while _known_int(dut, "tl_o_a_ready", f"waiting write a_ready addr=0x{addr:08x}") == 0:
        await _cycle(clk)
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting a_ready on write addr=0x{addr:08x}")

    await _cycle(clk)
    _get(dut, "tl_i_a_valid").value = 0

    guard = 0
    while _known_int(dut, "tl_o_d_valid", f"waiting write d_valid addr=0x{addr:08x}") == 0:
        await _cycle(clk)
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting d_valid on write addr=0x{addr:08x}")

    if _known_int(dut, "tl_o_d_error", f"checking write response addr=0x{addr:08x}"):
        raise AssertionError(f"TL-UL write error at addr=0x{addr:08x}")

    _drive_idle(dut)
    await _cycle(clk)


async def read_register(dut, reg_or_addr, *, regmap=None, clk=None):
    if not has_tlul_proxy(dut):
        raise RuntimeError("register read requested, but this cocotb wrapper has no TL-UL proxy signals")

    clk = _clock(dut, clk)
    addr = resolve_register(reg_or_addr, regmap)

    dut._log.info("reg read addr=0x%08x", addr)

    _drive_idle(dut)
    await _cycle(clk)

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
    while _known_int(dut, "tl_o_a_ready", f"waiting read a_ready addr=0x{addr:08x}") == 0:
        await _cycle(clk)
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting a_ready on read addr=0x{addr:08x}")

    await _cycle(clk)
    _get(dut, "tl_i_a_valid").value = 0

    guard = 0
    while _known_int(dut, "tl_o_d_valid", f"waiting read d_valid addr=0x{addr:08x}") == 0:
        await _cycle(clk)
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting d_valid on read addr=0x{addr:08x}")

    if _known_int(dut, "tl_o_d_error", f"checking read response addr=0x{addr:08x}"):
        raise AssertionError(f"TL-UL read error at addr=0x{addr:08x}")

    data = _known_int(dut, "tl_o_d_data", f"reading response data addr=0x{addr:08x}") & 0xFFFFFFFF
    dut._log.info("reg read addr=0x%08x data=0x%08x", addr, data)

    _drive_idle(dut)
    await _cycle(clk)

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

import re
from pathlib import Path

from cocotb.triggers import FallingEdge, RisingEdge, Timer

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
            if len(parts) != 3:
                raise ValueError(f"{path}:{lineno}: @reset format is: cycle @reset cycles")
            rows.append((cycle, [("@reset", parse_u32(parts[2]))]))
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


async def _advance(clk, count=1):
    for _ in range(max(0, int(count))):
        await RisingEdge(clk)


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

    for cycle, pairs in sorted(rows, key=lambda item: item[0]):
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
            if reset_runner is None:
                raise AssertionError("@reset row requested but no reset_runner was provided")
            cycles = max(1, int(pairs[0][1]))
            await reset_runner(cycles)
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
        await Timer(1, unit="ps")
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

def render_python_test(top: str) -> str:
    """Render the generated cocotb test module."""

    return f"""from __future__ import annotations

import os
from pathlib import Path

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer

from drivers.reg_driver import (
    init_register_bus,
    load_register_map,
    read_register,
    run_register_config,
    write_register,
)
from drivers.vec_driver import drive_vectors, load_vectors
from drivers.vec_monitor import LatencyMonitor


async def apply_reset(dut, cycles=2):
    for name in ("cio_rx_i", "uart_rx_i", "serial_rx_i"):
        if hasattr(dut, name):
            getattr(dut, name).value = 1
    if hasattr(dut, "rst_ni"):
        dut.rst_ni.value = 0
    for _ in range(max(1, int(cycles))):
        await RisingEdge(dut.clk_i)
    if hasattr(dut, "rst_ni"):
        dut.rst_ni.value = 1
    await Timer(1, unit="ns")


@cocotb.test()
async def {top}_generated_test(dut):
    cocotb.start_soon(Clock(dut.clk_i, 10, unit="ns").start())
    await apply_reset(dut)
    await RisingEdge(dut.clk_i)
    await init_register_bus(dut, dut.clk_i)

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
        await run_register_config(dut, path, regmap=regmap, clk=dut.clk_i)

    async def do_write(reg, data, mask):
        await write_register(dut, reg, data, mask, regmap=regmap, clk=dut.clk_i)

    async def do_read(reg):
        return await read_register(dut, reg, regmap=regmap, clk=dut.clk_i)

    async def do_reset(cycles):
        await apply_reset(dut, cycles)

    await apply_config(cfg_path)

    await drive_vectors(
        dut,
        dut.clk_i,
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
        out_dir / f"{cfg.top}_tb.py": render_python_test(cfg.top),
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

def write_cocotb_scaffold(config: CocotbConfig) -> list[Path]:
    """Generate Cocotb scaffolding and normalize the generated TL-UL wrapper."""

    written = _write_cocotb_scaffold_impl(config)
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

    module {top}_cocotb_tb;
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

def cocotb_makefile_text(top: str, rtl_dir: Path) -> str:
    """Render a cocotb Makefile for the N-clock wrapper."""

    gate = render_gls_make_block(f"../../../../syn/$(PDK)/{top}_synth.v")
    return dedent(f"""\
    SIM ?= verilator
    TOPLEVEL_LANG ?= verilog
    COCOTB_TOPLEVEL = {top}_cocotb_tb
    COCOTB_TEST_MODULES = {top}_tb

    ifeq ($(GATES),yes)
    {gate}
    else
    SIM_BUILD ?= sim_build/rtl
    EXTRA_ARGS += -f $(PWD)/../../../../rtl/rtl_common.f
    EXTRA_ARGS += -f $(PWD)/../../../../rtl/rtl_ip.f
    EXTRA_ARGS += -Wno-fatal
    endif

    VERILOG_SOURCES += $(PWD)/{top}_cocotb_tb.sv
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
    reset_map = {domain.reset: domain.reset_polarity for domain in clocks.domains}
    primary = clocks.domains[0].signal
    settle = clocks.domains[-1].signal
    text = dedent("""\
    from __future__ import annotations

    from pathlib import Path

    from cocotb.triggers import FallingEdge, RisingEdge


    CLOCKS = __CLOCK_MAP__
    RESETS = __RESET_MAP__
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


    async def reset(dut, cycles: int = 5):
        "Apply every configured reset with its declared polarity."
        set_defaults(dut)
        for signal, polarity in RESETS.items():
            getattr(dut, signal).value = int(polarity == "high")
        for _ in range(cycles):
            await RisingEdge(getattr(dut, PRIMARY_CLOCK))
        for signal, polarity in RESETS.items():
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
        data = int(getattr(dut, f"{domain}_d_data").value) & 0xFFFFFFFF
        error = int(getattr(dut, f"{domain}_d_error").value)
        await FallingEdge(clk)
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
            if token in {"@reset", "reset"} and len(parts) >= 3:
                await reset(dut, int(parts[2], 0))
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
        await reset(dut)

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


# ---------------------------------------------------------------------------
# N-clock scaffold writer
# ---------------------------------------------------------------------------


def write_nclock_cocotb(cfg: CocotbConfig, clocks: ClockConfig) -> list[Path]:
    """Write the generated N-clock cocotb scaffold."""

    out, drivers = cfg.output, cfg.output / "drivers"
    files = {
        out / "Makefile": cocotb_makefile_text(cfg.top, cfg.rtl_dir),
        out / f"{cfg.top}_cocotb_tb.sv": cocotb_sv_text(cfg.top, clocks),
        drivers / "__init__.py": "",
        drivers / "reg_driver.py": cocotb_reg_driver_py_text(cfg.top, clocks),
        drivers / "vec_driver.py": cocotb_vec_driver_py_text(cfg.top),
        drivers / "vec_monitor.py": cocotb_monitor_py_text(cfg.top),
        out / f"{cfg.top}_tb.py": cocotb_py_text(cfg.top, clocks),
    }
    for path, text in files.items():
        path.parent.mkdir(parents=True, exist_ok=True)
        if cfg.force or not path.exists() or path.name == "__init__.py":
            path.write_text(text.rstrip() + "\n", encoding="utf-8")
    return list(files)


def main() -> None:
    """Run the cocotb scaffold generator from the command line."""

    clocks = clock_config()
    primary = clocks.domains[0]
    cfg = replace(
        config_from_args(parse_args()),
        clk=primary.signal,
        rst=primary.reset,
        rst_active=primary.reset_polarity,
        period_ns=primary.period_ns,
    )
    if clocks.multiclock:
        write_nclock_cocotb(cfg, clocks)
    else:
        write_cocotb_scaffold(cfg)


if __name__ == "__main__":
    main()
