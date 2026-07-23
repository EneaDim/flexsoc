"""Generate synthesis scripts for ASIC and FPGA FlexSoC runs.

The module exposes pure render helpers plus a small writer function so the API,
CLI, and Makefile can share one backend implementation.
"""

from __future__ import annotations

import argparse
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Sequence


def _repo_root() -> Path:
    """Return the repository root used for generated synthesis paths."""

    for parent in Path(__file__).resolve().parents:
        if (parent / "pyproject.toml").exists():
            return parent
    return Path.cwd()

def _rewrite_hw_ip_include_paths(script: str) -> str:
    """Resolve hw/ips include paths from the current repository root."""

    ip_root = (_repo_root() / "hw" / "ips").as_posix()
    for ip_name in ("pkgs", "prim_opentitan", "prim", "tlul"):
        script = script.replace(f"../hw/ips/{ip_name}", f"{ip_root}/{ip_name}")
    return script

@dataclass(frozen=True, slots=True)
class SynthesisConfig:
    """Describe one synthesis script generation request.

    The config accepts Path objects so Make, CLI, and Python callers converge on
    the same backend contract.
    """

    top: str
    topdir: Path
    target: str
    clk_period_ns: float
    output: Path = Path("syn")
    liberty: Path | None = None
    sdcdir: Path | None = None
    opt: str = "delay"
    filelists: tuple[Path, ...] = (Path("rtl_common.f"), Path("rtl_ip.f"))


def pjoin(*parts: str | Path) -> str:
    """Join path fragments and return a POSIX string for generated scripts."""

    return Path(*parts).as_posix()


def write_text(path: Path, text: str) -> Path:
    """Write UTF-8 text after creating the parent directory."""

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")
    return path


def abc_script_area() -> str:
    """Render the area-oriented ABC recipe."""

    return "\n".join(
        [
            "# AREA-oriented ABC script (portable)",
            "strash",
            "dch",
            "balance",
            "rewrite",
            "refactor",
            "rewrite -z",
            "balance",
            "dch",
            "map -a",
            "topo",
            "dnsize -c",
            "stime -p",
            "print_stats -m",
            "",
        ]
    )


def abc_script_delay(clk_ns: float) -> str:
    """Render the delay-oriented ABC recipe for one clock period."""

    return "\n".join(
        [
            f"# DELAY-oriented ABC script (portable) - target {clk_ns} ns",
            "strash",
            "balance",
            "rewrite",
            "refactor",
            "rewrite -z",
            "balance",
            "dch",
            "# retime -o",
            "map",
            "topo",
            "upsize -c",
            "buffer -c",
            "stime -p",
            "print_stats -m",
            "",
        ]
    )


def render_abc_constraints(driving_cell: str = "sky130_fd_sc_hd__buf_1", load: float = 10.0) -> str:
    """Render ABC constraints shared by area and delay mappings."""

    return "\n".join(
        [
            "# ABC constraint file (edit BUF_X1/load for your tech)",
            f"set_driving_cell {driving_cell}",
            f"set_load {load} [all_outputs]",
            "",
        ]
    )


def _abc_script_name(opt: str) -> str | None:
    """Return the ABC script file name selected by an optimization mode."""

    return {"area": "area.abc", "delay": "delay.abc"}.get(opt)


def _abc_constraint_arg(cfg: SynthesisConfig) -> str:
    """Return the optional ABC constraint argument for ASIC scripts."""

    if cfg.sdcdir is None:
        return ""
    return f"\n    -constr {pjoin(cfg.sdcdir, cfg.top + '.sdc')} \\"


def render_abc_command(cfg: SynthesisConfig, script_name: str | None) -> str:
    """Render the ABC command for one ASIC synthesis script."""

    if cfg.liberty is None:
        raise ValueError("ASIC synthesis requires a Liberty file.")

    if script_name is None:
        delay_ps = int(round(cfg.clk_period_ns * 1000.0))
        return f"abc -D {delay_ps} -liberty {cfg.liberty.as_posix()}"

    base = f"abc -liberty {cfg.liberty.as_posix()}"
    if cfg.opt == "delay":
        delay_ps = int(round(cfg.clk_period_ns * 1000.0))
        base = f"abc -D {delay_ps} -liberty {cfg.liberty.as_posix()}"
    return f"{base} -script {pjoin(cfg.output, script_name)} \\" + _abc_constraint_arg(cfg)

def _asic_tail(cfg: SynthesisConfig, script_name: str | None) -> list[str]:
    """Return shared ASIC mapping, cleanup, and output commands."""

    if cfg.liberty is None:
        raise ValueError("ASIC synthesis requires a Liberty file.")

    return [
        "",
        "# map internal register types to the ones from the cell library",
        f"dfflibmap -liberty {cfg.liberty.as_posix()}",
        "",
        "# map logic to the selected cell library",
        render_abc_command(cfg, script_name),
        "",
        "# Clean",
        "opt_clean -purge",
        "",
        "# Basic stats of std cells and area",
        f"stat -liberty {cfg.liberty.as_posix()}",
        "",
        "# write verilog",
        f"write_verilog {pjoin(cfg.output, cfg.top + '_synth.v')}",
        "# write json",
        f"write_json {pjoin(cfg.output, cfg.top + '_synth.json')}",
        "",
    ]


def yosys_synth_asic_verilog(
    top: str,
    topdir: Path,
    liberty: Path,
    clk_ns: float,
    opt: str,
    sdcdir: Path | None,
    outdir: Path,
) -> str:
    """Render a Verilog-only ASIC Yosys script."""

    cfg = SynthesisConfig(top, topdir, "asic", clk_ns, outdir, liberty, sdcdir, opt)
    script_name = _abc_script_name(opt)
    lines = [
        "# read files",
        f"read_verilog {pjoin(topdir, top + '.v')}",
        "# basic synth",
        f"synth -top {top}" + (" -noabc" if opt in {"area", "delay"} else ""),
        f"show -width -format dot -prefix {pjoin(outdir, 'plots', top + '_postsyn')}",
        *_asic_tail(cfg, script_name),
    ]
    return "\n".join(lines)


def yosys_synth_asic_slang(
    top: str,
    liberty: Path,
    clk_ns: float,
    opt: str,
    sdcdir: Path | None,
    outdir: Path,
    filelists: Sequence[Path] = (Path("rtl_common.f"), Path("rtl_ip.f")),
) -> str:
    """Render a SystemVerilog ASIC Yosys script through slang."""

    cfg = SynthesisConfig(top, Path("rtl"), "asic", clk_ns, outdir, liberty, sdcdir, opt, tuple(filelists))
    script_name = _abc_script_name(opt)
    lines = [
        "# read files (SystemVerilog via slang)",
        f"read_slang -I {(_repo_root() / 'hw' / 'ips' / 'pkgs').as_posix()} \\",
        "           -I ../hw/ips/prim \\",
        "           -I ../hw/ips/prim_opentitan \\",
        "           -I ../hw/ips/tlul \\",
        "           -D SYNTHESIS \\",
        "           --ignore-assertions \\",
        *(f"           -f {Path(filelist).resolve().as_posix()} \\" for filelist in filelists),
        f"           --top {top}",
        "",
        "# basic synth",
        f"synth -top {top}" + (" -noabc" if opt in {"area", "delay"} else ""),
        *_asic_tail(cfg, script_name),
    ]
    return _rewrite_hw_ip_include_paths("\n".join(lines))


def yosys_synth_xilinx(top: str, topdir: Path, outdir: Path) -> str:
    """Render a Xilinx-oriented Yosys script."""

    return "\n".join(
        [
            "# read files",
            f"read_verilog {pjoin(topdir, top + '.v')}",
            "# basic synth",
            f"synth_xilinx -top {top} -flatten -edif {pjoin(outdir, top + '.edif')}",
            "",
        ]
    )


def vivado_tcl_xilinx(top: str) -> str:
    """Render a compact Vivado TCL implementation script."""

    return "\n".join(
        [
            f"read_xdc {top}.xdc",
            f"read_edif {top}.edif",
            f"link_design -part xc7a35tcpg236-1 -top {top}",
            "opt_design",
            "place_design",
            "route_design",
            "report_utilization",
            "report_timing",
            f"write_bitstream -force {top}.bit",
            "",
        ]
    )


def yosys_synth_ice40(top: str, topdir: Path, outdir: Path) -> str:
    """Render an iCE40-oriented Yosys script."""

    return "\n".join(
        [
            "# read files",
            f"read_verilog {pjoin(topdir, top + '.v')}",
            "# basic synth",
            f"synth_ice40 -top {top} -json {pjoin(outdir, top + '.json')}",
            "",
        ]
    )


def generate_synthesis_scripts(cfg: SynthesisConfig) -> tuple[Path, ...]:
    """Generate synthesis scripts and return the written paths."""

    cfg.output.mkdir(parents=True, exist_ok=True)
    (cfg.output / "plots").mkdir(parents=True, exist_ok=True)
    written: list[Path] = []

    if cfg.target == "asic":
        if cfg.liberty is None:
            raise ValueError("For target=asic you must provide a Liberty file.")
        if cfg.opt == "area":
            written.append(write_text(cfg.output / "area.abc", abc_script_area()))
        elif cfg.opt == "delay":
            written.append(write_text(cfg.output / "delay.abc", abc_script_delay(cfg.clk_period_ns)))
        if cfg.opt in {"area", "delay"}:
            written.append(write_text(cfg.output / "abc.constr", render_abc_constraints()))
        written.append(write_text(cfg.output / "synth.ys", yosys_synth_asic_verilog(cfg.top, cfg.topdir, cfg.liberty, cfg.clk_period_ns, cfg.opt, cfg.sdcdir, cfg.output)))
        written.append(write_text(cfg.output / "synth_sv.ys", yosys_synth_asic_slang(cfg.top, cfg.liberty, cfg.clk_period_ns, cfg.opt, cfg.sdcdir, cfg.output, cfg.filelists)))
    elif cfg.target == "xilinx":
        written.append(write_text(cfg.output / "synth.ys", yosys_synth_xilinx(cfg.top, cfg.topdir, cfg.output)))
        written.append(write_text(cfg.output / "xilinx.tcl", vivado_tcl_xilinx(cfg.top)))
    elif cfg.target == "ice40":
        written.append(write_text(cfg.output / "synth.ys", yosys_synth_ice40(cfg.top, cfg.topdir, cfg.output)))
    else:
        raise ValueError(f"Unsupported target: {cfg.target}")

    return tuple(written)


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    """Parse CLI arguments used by the backend Makefile."""

    parser = argparse.ArgumentParser(description="Emit Yosys/ABC/Vivado scripts for ASIC/FPGA.")
    parser.add_argument("-top", "--top", required=True, help="TOP module name without extension.")
    parser.add_argument("-topdir", "--topdir", required=True, type=Path, help="Directory containing TOP RTL.")
    parser.add_argument("-target", "--target", required=True, choices=["asic", "xilinx", "ice40"], help="Target technology.")
    parser.add_argument("-liberty", "--liberty", type=Path, help="Liberty file for ASIC mapping.")
    parser.add_argument("-clk", "--clk", type=float, required=True, help="Clock period in ns for ABC -D.")
    parser.add_argument("-sdcdir", "--sdcdir", type=Path, default=None, help="Directory containing <top>.sdc.")
    parser.add_argument("-opt", "--opt", choices=["area", "delay", "none"], default="delay", help="ASIC optimization mode.")
    parser.add_argument("-o", "--output", type=Path, default=Path("syn"), help="Output folder.")
    parser.add_argument("--filelist", type=Path, action="append", default=None, help="SystemVerilog file list for slang. Repeat for common/IP lists.")
    args = parser.parse_args(argv)

    package_root = Path(__file__).resolve().parent.parent
    repo_root = package_root.parent
    if args.liberty is not None and not args.liberty.is_absolute():
        args.liberty = (repo_root / args.liberty).resolve()
    return args


def config_from_args(args: argparse.Namespace) -> SynthesisConfig:
    """Convert parsed CLI arguments into a synthesis config."""

    return SynthesisConfig(
        top=args.top,
        topdir=args.topdir,
        target=args.target,
        clk_period_ns=args.clk,
        output=args.output,
        liberty=args.liberty,
        sdcdir=args.sdcdir,
        opt=args.opt,
        filelists=tuple(args.filelist or (Path("rtl_common.f"), Path("rtl_ip.f"))),
    )


def main(argv: Sequence[str] | None = None) -> int:
    """Run synthesis script generation from the command line."""

    try:
        generate_synthesis_scripts(config_from_args(parse_args(argv)))
        return 0
    except Exception as err:
        exc_type, _, exc_tb = sys.exc_info()
        line = getattr(exc_tb, "tb_lineno", "?")
        print(
            f"\033[38;5;208mError during CORE CODE:\nError Type: {exc_type}\nLine number: {line}\033[0;0m",
            file=sys.stderr,
        )
        print(err, file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
