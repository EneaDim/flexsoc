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


def read_filelist(path: Path) -> list[Path]:
    """Read a Verilog filelist while ignoring comments and include markers."""

    if not path.exists():
        return []
    base = path.parent
    sources: list[Path] = []
    for raw in path.read_text(encoding="utf-8", errors="ignore").splitlines():
        line = raw.strip()
        if not line or line.startswith("#") or line.startswith("+incdir+"):
            continue
        source = Path(line)
        sources.append((base / source).resolve() if not source.is_absolute() else source.resolve())
    return sources


def append_existing(paths: list[Path], seen: set[str], path: Path) -> None:
    """Append one existing path once while preserving source order."""

    resolved = path.resolve()
    key = resolved.as_posix()
    if resolved.exists() and key not in seen:
        seen.add(key)
        paths.append(resolved)


def collect_sources(top: str, rtl_dir: Path, _ips_root: Path | None = None) -> list[Path]:
    """Collect RTL sources for cocotb with the top wrapper kept last."""

    seen: set[str] = set()
    ordered: list[Path] = []
    rtl_list = rtl_dir / "rtl_list.f"
    if rtl_list.exists():
        candidates = read_filelist(rtl_list)
    else:
        candidates = sorted(rtl_dir.glob("*.sv")) + sorted(rtl_dir.glob("*.v"))
    for source in candidates:
        append_existing(ordered, seen, source)
    for tail in (rtl_dir / "tl_main_pkg.sv", rtl_dir / "xbar_main.sv", rtl_dir / f"{top}.sv"):
        append_existing(ordered, seen, tail)
    return ordered


def render_source_block(paths: Sequence[Path], var_name: str = "VERILOG_SOURCES") -> str:
    """Render one Make variable containing ordered Verilog sources."""

    if not paths:
        return f"{var_name} :="
    lines = [f"{var_name} := \\"]
    lines.extend(f"  {path.resolve()} \\" for path in paths[:-1])
    lines.append(f"  {paths[-1].resolve()}")
    return "\n".join(lines)


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
        VERILOG_SOURCES += {(out_dir / f"{cfg.top}_tb.sv").resolve()}

        include $(shell cocotb-config --makefiles)/Makefile.sim
        """
    )


def render_utils() -> str:
    """Render small Python helpers imported by generated cocotb tests."""

    return dedent(
        """\
        import random

        def rand_bin_values(nbit: int):
            a = random.randint(0, (1 << nbit) - 1)
            b = random.randint(0, (1 << nbit) - 1)
            return a, b
        """
    )


def render_driver_import() -> str:
    """Render the minimal placeholder driver module used by generated tests."""

    return "from cocotb.triggers import RisingEdge\n"


def render_python_test(cfg: CocotbConfig) -> str:
    """Render a small cocotb smoke test for the generated wrapper."""

    return dedent(
        f"""\
        import cocotb
        from cocotb.clock import Clock
        from cocotb.triggers import RisingEdge

        @cocotb.test()
        async def {cfg.top}_smoke_test(dut):
            clk = getattr(dut, "{cfg.clk}")
            cocotb.start_soon(Clock(clk, {cfg.period_ns}, unit="ns").start())
            for _ in range(5):
                await RisingEdge(clk)
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


def write_cocotb_scaffold(cfg: CocotbConfig) -> list[Path]:
    """Write the cocotb scaffold and return generated paths."""

    out_dir = cfg.output.resolve()
    drivers = out_dir / "drivers"
    drivers.mkdir(parents=True, exist_ok=True)
    sources = collect_sources(cfg.top, cfg.rtl_dir.resolve(), cfg.ips_root)
    files = {
        out_dir / "Makefile": render_makefile(cfg, sources),
        out_dir / "utils.py": render_utils(),
        out_dir / "__init__.py": "",
        drivers / "driver_reg_iface.py": render_driver_import(),
        drivers / "driver_tlul.py": render_driver_import(),
        out_dir / f"{cfg.top}_tb.py": render_python_test(cfg),
        out_dir / f"{cfg.top}_tb.sv": render_tlul_wrapper(cfg),
    }
    for path, text in files.items():
        path.write_text(text, encoding="utf-8")
    return list(files)


def main() -> None:
    """Run the cocotb scaffold generator from the command line."""

    cfg = config_from_args(parse_args())
    written = write_cocotb_scaffold(cfg)
    print(f"Generated {len(written)} files in: {cfg.output.resolve()}")


if __name__ == "__main__":
    main()
