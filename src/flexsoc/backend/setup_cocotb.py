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

from .setup_tb import _candidate_hjson_path, _register_entries


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
        COCOTB_TOPLEVEL   = {cfg.top}_tb
        COCOTB_TEST_MODULES = {cfg.top}_tb

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
        COMPILE_ARGS += --trace-fst --trace-structs
        export WAVES ?= 1
        COMPILE_ARGS += -Wno-WIDTHEXPAND
        COMPILE_ARGS += -Wno-WIDTHTRUNC
        COMPILE_ARGS += -Wno-UNOPTFLAT

        else
        SIM_BUILD         ?= sim_build/gl
        COMPILE_ARGS      += -DFUNCTIONAL -DUSE_POWER_PINS -DSIM -DUNIT_DELAY=#1
        VERILOG_SOURCES   += ../../verilog/primitives.v
        VERILOG_SOURCES   += ../../verilog/sky130_fd_sc_hd.v
        VERILOG_SOURCES   += ../../../../syn/{cfg.top}_synth.v
        endif

        COMPILE_ARGS += {includes}
        export COCOTB_RESULTS_FILE ?= $(abspath results.xml)
        TEST_NAME ?= smoke
        SEED ?= 1
        HDL_COVERAGE ?= 0
        COVERAGE_FILE ?= $(abspath ../../coverage/cocotb/$(TEST_NAME).dat)
        WAVE_EXT ?= $(if $(filter verilator,$(SIM)),fst,vcd)
        WAVE_FILE ?= $(abspath ../../sim/rtl/{cfg.top}_tb_cocotb_$(TEST_NAME).$(WAVE_EXT))
        COCOTB_PLUSARGS += +WAVE=$(WAVE_FILE)

        # FlexSoC reserves COVERAGE for HDL coverage. Cocotb 2.x also treats
        # COVERAGE as deprecated Python user-code coverage, so clear the legacy
        # cocotb variable while HDL_COVERAGE carries the Verilator setting.
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
        export REG_CONFIG ?= $(abspath ../../tests/$(TEST_NAME)/config.regs)
        export DATA_IN  ?= $(abspath ../../tests/$(TEST_NAME)/data_in.vec)
        export DATA_OUT ?= $(abspath ../../tests/$(TEST_NAME)/data_out.vec)
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

    dut._log.info("reg write addr=0x%08x data=0x%08x mask=0x%x", addr, data, mask)

    _drive_idle(dut)
    await _cycle(clk)

    _get(dut, "tl_i_d_ready").value = 1
    _get(dut, "tl_i_a_valid").value = 1
    _get(dut, "tl_i_a_opcode").value = 0  # PutFullData
    _get(dut, "tl_i_a_param").value = 0
    _get(dut, "tl_i_a_size").value = 2
    _get(dut, "tl_i_a_source").value = 0
    _get(dut, "tl_i_a_address").value = addr
    _get(dut, "tl_i_a_mask").value = mask
    _get(dut, "tl_i_a_data").value = data

    guard = 0
    while int(_get(dut, "tl_o_a_ready").value) == 0:
        await _cycle(clk)
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting a_ready on write addr=0x{addr:08x}")

    await _cycle(clk)
    _get(dut, "tl_i_a_valid").value = 0

    guard = 0
    while int(_get(dut, "tl_o_d_valid").value) == 0:
        await _cycle(clk)
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting d_valid on write addr=0x{addr:08x}")

    if int(_get(dut, "tl_o_d_error").value):
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
    while int(_get(dut, "tl_o_a_ready").value) == 0:
        await _cycle(clk)
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting a_ready on read addr=0x{addr:08x}")

    await _cycle(clk)
    _get(dut, "tl_i_a_valid").value = 0

    guard = 0
    while int(_get(dut, "tl_o_d_valid").value) == 0:
        await _cycle(clk)
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting d_valid on read addr=0x{addr:08x}")

    if int(_get(dut, "tl_o_d_error").value):
        raise AssertionError(f"TL-UL read error at addr=0x{addr:08x}")

    data = int(_get(dut, "tl_o_d_data").value) & 0xFFFFFFFF
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
          string wave_path;
          initial begin
            if (!$value$plusargs("WAVE=%s", wave_path)) wave_path = "{cfg.top}_tb.fst";
            $display("[TB] dumpfile = %s", wave_path);
            $dumpfile(wave_path);
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
  string wave_path;
  initial begin
    if (!$value$plusargs("WAVE=%s", wave_path)) wave_path = "{top}_tb.fst";
    $display("[TB] dumpfile = %s", wave_path);
    $dumpfile(wave_path);
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
    write_cocotb_scaffold(cfg)


if __name__ == "__main__":
    main()
