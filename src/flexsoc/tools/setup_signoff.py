# ruff: noqa
from __future__ import annotations

# NOTE:
# This script was moved from flow/scripts into src/flexsoc/scripts.
# It must remain:
# - syntactically valid (ruff must parse it)
# - robust to extra/unexpected CLI args (Make sometimes evolves)
#
# Goal:
# - Generate OpenSTA Tcl scripts into an output directory.
# - Keep it simple, predictable, and "works with many flows".

import argparse
import os
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import List, Sequence


@dataclass
class STAConfig:
    top: str
    output_dir: Path

    # Common directories used by flows
    syndir: Path | None = None
    sdcdir: Path | None = None
    simdir: Path | None = None

    # Liberty / tech inputs
    liberty: List[Path] = None  # type: ignore[assignment]

    # Power options (kept simple)
    activity_pct: float = 10.0


def _p(s: str | None) -> Path | None:
    if s is None or s == "":
        return None
    return Path(s)


def parse_args(argv: Sequence[str]) -> STAConfig:
    """
    Parse known args, accept legacy aliases used by the Makefile, and ignore
    unknown ones.

    Supported forms include both:
      --top / --output-dir / --liberty / --activity-pct
    and legacy flow forms:
      -top / -o / -libs / -activity / -syndir / -sdcdir / -simdir / -rtldir / -clk
    """
    ap = argparse.ArgumentParser(add_help=True)

    # Canonical + legacy aliases
    ap.add_argument("--top", "--design", "--module", "-top", dest="top", default=None)
    ap.add_argument(
        "--output-dir",
        "--outdir",
        "--out",
        "--signoff-dir",
        "-o",
        dest="output_dir",
        default=None,
    )

    ap.add_argument("--syndir", "-syndir", dest="syndir", default=None)
    ap.add_argument("--sdcdir", "-sdcdir", dest="sdcdir", default=None)
    ap.add_argument("--simdir", "-simdir", dest="simdir", default=None)

    # Accepted for compatibility with the flow, even if not used directly below.
    ap.add_argument("--rtldir", "-rtldir", dest="rtldir", default=None)
    ap.add_argument("--clk", "-clk", dest="clk", default=None)

    # Allow multiple --liberty files (or comma-separated), plus legacy -libs
    ap.add_argument("--liberty", "-libs", dest="liberty", action="append", default=[])

    # Activity aliases
    ap.add_argument("--activity-pct", "-activity", dest="activity_pct", type=float, default=10.0)

    ns, _unknown = ap.parse_known_args(list(argv))

    # Environment fallbacks for backward compatibility
    top = ns.top or os.environ.get("TOP")
    output_dir = (
        ns.output_dir
        or os.environ.get("OUTPUT_DIR")
        or os.environ.get("OUTDIR")
        or os.environ.get("SIGNOFFDIR")
    )

    if not top:
        ap.error("missing top name (use --top / -top or set TOP)")
    if not output_dir:
        ap.error("missing output dir (use --output-dir / -o or set OUTPUT_DIR / OUTDIR / SIGNOFFDIR)")

    libs: List[Path] = []
    for item in ns.liberty:
        if not item:
            continue
        for tok in str(item).split(","):
            tok = tok.strip()
            if tok:
                libs.append(Path(tok))

    cfg = STAConfig(
        top=str(top),
        output_dir=Path(output_dir),
        syndir=_p(ns.syndir),
        sdcdir=_p(ns.sdcdir),
        simdir=_p(ns.simdir),
        liberty=libs,
        activity_pct=float(ns.activity_pct),
    )

    # Normalize paths
    cfg.output_dir = cfg.output_dir.resolve()
    if cfg.syndir is not None:
        cfg.syndir = cfg.syndir.resolve()
    if cfg.sdcdir is not None:
        cfg.sdcdir = cfg.sdcdir.resolve()
    if cfg.simdir is not None:
        cfg.simdir = cfg.simdir.resolve()

    return cfg


def _tcl_quote(p: Path) -> str:
    # Basic Tcl-safe quoting
    return "{" + p.as_posix() + "}"


def build_init_opensta(cfg: STAConfig) -> str:
    """
    Minimal OpenSTA setup:
    - read liberty
    - read synthesized netlist (if present)
    - link design
    - read SDC (if present)
    """
    lines: List[str] = []
    lines.append('puts ""')
    lines.append('puts "=== flexsoc OpenSTA init ==="')

    # Liberty
    if cfg.liberty:
        for lib in cfg.liberty:
            lines.append(f'puts "read_liberty {_tcl_quote(lib)}"')
            lines.append(f"read_liberty {_tcl_quote(lib)}")
    else:
        lines.append('puts "WARNING: no --liberty provided"')

    # Netlist
    if cfg.syndir is not None:
        net = (cfg.syndir / f"{cfg.top}_synth.v").resolve()
        lines.append(f'puts "read_verilog {_tcl_quote(net)}"')
        lines.append(f"read_verilog {_tcl_quote(net)}")
    else:
        lines.append('puts "WARNING: no --syndir provided; skipping read_verilog"')

    # link_design always
    lines.append(f'puts "link_design {cfg.top}"')
    lines.append(f"link_design {cfg.top}")

    # SDC
    if cfg.sdcdir is not None:
        sdc = (cfg.sdcdir / f"{cfg.top}.sdc").resolve()
        lines.append(f'puts "read_sdc {_tcl_quote(sdc)}"')
        lines.append(f"read_sdc {_tcl_quote(sdc)}")
    else:
        lines.append('puts "WARNING: no --sdcdir provided; skipping read_sdc"')

    return "\n".join(lines)


def build_sta_tcl(cfg: STAConfig) -> str:
    lines: List[str] = []
    lines.append(build_init_opensta(cfg))
    lines.append("")
    lines.append('puts "=== Timing reports ==="')
    lines.append('report_checks -path_delay max -fields {slew cap input_pins} -digits 3')
    lines.append('report_checks -path_delay min -fields {slew cap input_pins} -digits 3')
    lines.append('report_tns')
    lines.append('report_wns')
    return "\n".join(lines) + "\n"


def build_sta_violators_tcl(cfg: STAConfig) -> str:
    lines: List[str] = []
    lines.append(build_init_opensta(cfg))
    lines.append("")
    lines.append('puts "=== Violators ==="')
    lines.append('report_check_types -max_slew -max_cap -max_fanout -violators')
    lines.append('report_checks -path_delay max -slack_max 0.0')
    lines.append('report_checks -path_delay min -slack_max 0.0')
    return "\n".join(lines) + "\n"


def build_write_sdf_tcl(cfg: STAConfig) -> str:
    """
    Minimal SDF write script.
    Note: corner handling depends on liberty corner setup; we keep simple.
    """
    sdf_dir = (cfg.output_dir / "sdf").resolve()
    sdf_dir.mkdir(parents=True, exist_ok=True)

    sdf_tt = (sdf_dir / f"{cfg.top}_tt.sdf").as_posix()
    sdf_ss = (sdf_dir / f"{cfg.top}_ss.sdf").as_posix()
    sdf_ff = (sdf_dir / f"{cfg.top}_ff.sdf").as_posix()

    lines: List[str] = []
    lines.append(build_init_opensta(cfg))
    lines.append("")
    lines.append('puts "=== Write SDF ==="')

    # If corners exist, users can adjust; we emit generic commands.
    lines.append(f'puts "write_sdf -divider . -include_typ {sdf_tt}"')
    lines.append(f"write_sdf -divider . -include_typ {sdf_tt}")
    lines.append(f'puts "write_sdf -divider . -include_typ {sdf_ss}"')
    lines.append(f"write_sdf -divider . -include_typ {sdf_ss}")
    lines.append(f'puts "write_sdf -divider . -include_typ {sdf_ff}"')
    lines.append(f"write_sdf -divider . -include_typ {sdf_ff}")

    return "\n".join(lines) + "\n"


def build_power_tcl(cfg: STAConfig) -> str:
    """
    Robust power script.

    Some OpenSTA builds do not support power commands such as
    `set_power_activity` and/or `report_power`.

    To avoid failing the whole flow, probe command support first.
    """
    lines: List[str] = []

    # Reuse the common OpenSTA initialization block.
    lines.append(build_init_opensta(cfg))
    lines.append("")
    lines.append('puts "=== Power ==="')
    lines.append(f'puts "set_power_activity -global -activity {cfg.activity_pct}"')
    lines.append(f'set_power_activity -global -activity {cfg.activity_pct}')
    lines.append('puts "report_power"')
    lines.append('report_power')

    return "\n".join(lines) + "\n"

def write_text(path: Path, content: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(content, encoding="utf-8")


def main(argv: Sequence[str]) -> int:
    cfg = parse_args(argv)

    out = cfg.output_dir
    out.mkdir(parents=True, exist_ok=True)

    write_text(out / "sta.tcl", build_sta_tcl(cfg))
    write_text(out / "sta_violators.tcl", build_sta_violators_tcl(cfg))
    write_text(out / "write_sdf.tcl", build_write_sdf_tcl(cfg))
    write_text(out / "power.tcl", build_power_tcl(cfg))

    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
