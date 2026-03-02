#!/usr/bin/env python3
# Copyright 2025 Enea Dimroci
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

r"""
\file make_synth_scripts.py
\brief Emit synthesis support scripts (ABC/Yosys/TCL) for ASIC or FPGA targets.

Generates (depending on options):
- ASIC:
  - area.abc  (if --opt area)
  - delay.abc (if --opt delay)
  - synth.ys     (Verilog flow: read_verilog <topdir>/<top>.v)
  - synth_sv.ys  (SystemVerilog flow via slang + {cfg.filelist.resolve().as_posix()})
- Xilinx:
  - synth.ys (Yosys synth_xilinx to EDIF)
  - xilinx.tcl (Vivado run script)
- iCE40:
  - synth.ys (Yosys synth_ice40 to JSON)

If --opt none is used (ASIC), no .abc script file is created
and ABC is invoked without -script (default script).
"""

from __future__ import annotations

import sys
import argparse
from pathlib import Path


# ----------------------------
# Utilities
# ----------------------------
def pjoin(*parts: str | Path) -> str:
    """Join parts into POSIX path string."""
    return Path(*parts).as_posix()


def write_text(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")


def abc_script_area() -> str:
    return (
        "# AREA-oriented ABC script (portable)\n"
        "strash\n"
        "dch\n"
        "balance\n"
        "rewrite\n"
        "refactor\n"
        "rewrite -z\n"
        "balance\n"
        "dch\n"
        "map -a\n"
        "topo\n"
        "dnsize -c\n"
        "stime -p\n"
        "print_stats -m\n"
    )


def abc_script_delay(clk_ns: float) -> str:
    return (
        f"# DELAY-oriented ABC script (portable) - target {clk_ns} ns\n"
        "strash\n"
        "balance\n"
        "rewrite\n"
        "refactor\n"
        "rewrite -z\n"
        "balance\n"
        "dch\n"
        "# retime -o\n"
        "map\n"
        "topo\n"
        "upsize -c\n"
        "buffer -c\n"
        "stime -p\n"
        "print_stats -m\n"
    )


def yosys_synth_asic_verilog(
    top: str,
    topdir: Path,
    liberty: Path,
    clk_ns: float,
    opt: str,
    sdcdir: Path | None,
    outdir: Path,
) -> str:
    """
    Verilog (non-SV) ASIC flow using read_verilog.

    \\param opt   "area", "delay" or "none" (controls ABC -script usage).
    """
    abc_D_ps = int(round(clk_ns * 1000.0))  # ABC expects picoseconds

    flag_area_delay = True

    if opt == "area":
        abc_script_name = "area.abc"
    elif opt == "delay":
        abc_script_name = "delay.abc"
    else:
        abc_script_name = None
        flag_area_delay = False

    body = []
    body.append("# read files")
    body.append(f"read_verilog {pjoin(topdir, top + '.v')}")
    body.append("# basic synth")
    if opt == "area":
        body.append(f"synth -top {top} -noabc")
    elif opt == "delay":
        body.append(f"synth -top {top} -noabc")
    else:  # none
        # still do a normal synth, ABC will use default script
        body.append(f"synth -top {top}")

    body.append(f"show -width -format dot -prefix {pjoin(outdir, 'plots', top + '_postsyn')}")
    body.append("# map internal register types to the ones from the cell library")
    body.append(f"dfflibmap -liberty {liberty.as_posix()}")
    body.append("# mapping to internal cell library")

    # Write abc.constr file
    if flag_area_delay:
        with open(pjoin(outdir, 'abc.constr'),'w') as f:
            mystr = '# ABC constraint file (edit BUF_X1/load for your tech)\\n'
            # TODO: change driving cell based on technology
            mystr += 'set_driving_cell sky130_fd_sc_hd__buf_1\\n'
            mystr += 'set_load 10.0 [all_outputs]\\n'
            f.write(mystr)
    # Define constr
    constr = ""
    if sdcdir is not None:
        constr = f"\n    -constr {pjoin(sdcdir, top + '.sdc')} \\"
    # ABC call:
    # - with script and -D (delay) only for opt == "delay"
    # - with script but *no* -D for opt == "area"
    # - without script and without -D for opt == "none"
    if abc_script_name is not None:
        if opt == "delay": # Delay
            body.append(
                "# mapping to internal cell library\n"
                f"abc -D {abc_D_ps}"
                f" -liberty {liberty.as_posix()} "
                f" -script {pjoin(outdir, abc_script_name)} \\"
                f"{constr}"
            )
        else: # Area
            body.append(
                "# mapping to internal cell library\n"
                "abc"
                f" -liberty {liberty.as_posix()}"
                f" -script {pjoin(outdir, abc_script_name)} \\"
                f"{constr}"
            )
    else: # None
        body.append(
            "abc -D " + str(abc_D_ps) + ""
            f" -liberty {liberty.as_posix()}"
        )

    body.append("\n")
    body.append("opt_clean -purge")
    body.append(f"stat -liberty {liberty.as_posix()}")
    body.append("# write verilog")
    body.append(f"write_verilog {pjoin(outdir, top + '_synth.v')}")
    body.append("# write json")
    body.append(f"write_json {pjoin(outdir, top + '_synth.json')}")

    return "\n".join(body) + "\n"


def yosys_synth_asic_slang(
    top: str,
    liberty: Path,
    clk_ns: float,
    opt: str,
    sdcdir: Path | None,
    outdir: Path,
    filelist: Path = Path("rtl_list.f"),
) -> str:
    """
    SystemVerilog ASIC flow via slang using an ordered file list ({cfg.filelist.resolve().as_posix()}).
    Assumes include dirs: ../hw/ips/pkgs, ../hw/ips/prim, ../hw/ips/prim_opentitan, ../hw/ips/tlul.

    \\param opt   "area", "delay" or "none" (controls ABC -script usage).
    """

    abc_D_ps = int(round(clk_ns * 1000.0))

    flag_area_delay = True

    if opt == "area":
        abc_script_name = "area.abc"
    elif opt == "delay":
        abc_script_name = "delay.abc"
    else:
        abc_script_name = None
        flag_area_delay = False

    body = []
    body.append("# read files (SystemVerilog via slang)")
    body.append(
        "read_slang -I ../hw/ips/pkgs \\"
        "\n           -I ../hw/ips/prim \\"
        "\n           -I ../hw/ips/prim_opentitan \\"
        "\n           -I ../hw/ips/tlul \\"
        "\n           -D SYNTHESIS \\"
        "\n           --ignore-assertions \\"
        f"\n           -f {filelist.as_posix()} \\"
        f"\n           --top {top}"
    )
    body.append("")
    body.append("# basic synth")
    if opt == "area":
        body.append(f"synth -top {top} -noabc")
    elif opt == "delay":
        body.append(f"synth -top {top} -noabc")
    else:  # none
        body.append(f"synth -top {top}")

    body.append("")
    body.append("# map internal register types to the ones from the cell library")
    body.append(f"dfflibmap -liberty {liberty.as_posix()}")

    # Write abc.constr file
    body.append("")
    if flag_area_delay:
        with open(pjoin(outdir, 'abc.constr'),'w') as f:
            mystr = '# ABC constraint file (edit BUF_X1/load for your tech)\\n'
            mystr += 'set_driving_cell sky130_fd_sc_hd__buf_1\\n'
            mystr += 'set_load 10.0 [all_outputs]\\n'
            f.write(mystr)
    # Define constr
    constr = ""
    if sdcdir is not None:
        constr = f"\n    -constr {pjoin(sdcdir, top + '.sdc')} \\"
    # ABC call:
    # - with script and -D (delay) only for opt == "delay"
    # - with script but *no* -D for opt == "area"
    # - without script and without -D for opt == "none"
    if abc_script_name is not None:
        if opt == "delay": # Delay
            body.append(
                "# mapping to internal cell library\n"
                f"abc -D {abc_D_ps}"
                f" -liberty {liberty.as_posix()} "
                f" -script {pjoin(outdir, abc_script_name)} \\"
                f"{constr}"
            )
        else: # Area
            body.append(
                "# mapping to internal cell library\n"
                "abc"
                f" -liberty {liberty.as_posix()}"
                f" -script {pjoin(outdir, abc_script_name)} \\"
                f"{constr}"
            )
    else: # None
        body.append(
            "abc -D " + str(abc_D_ps) + ""
            f" -liberty {liberty.as_posix()}"
        )


    body.append("")
    body.append("# Clean")
    body.append("opt_clean -purge")
    body.append("")
    body.append("# Basic stats of std cells and area")
    body.append(f"stat -liberty {liberty.as_posix()}")
    body.append("")
    body.append("# write verilog")
    body.append(f"write_verilog {pjoin(outdir, top + '_synth.v')}")
    body.append("# write json")
    body.append(f"write_json {pjoin(outdir, top + '_synth.json')}")

    return "\n".join(body) + "\n"


def yosys_synth_xilinx(top: str, topdir: Path, outdir: Path) -> str:
    return (
        "# read files\n"
        f"read_verilog {pjoin(topdir, top + '.v')}\n"
        "# basic synth\n"
        f"synth_xilinx -top {top} -flatten -edif {pjoin(outdir, top + '.edif')}\n"
    )


def vivado_tcl_xilinx(top: str) -> str:
    return (
        f"read_xdc {top}.xdc\n"
        f"read_edif {top}.edif\n"
        f"link_design -part xc7a35tcpg236-1 -top {top}\n"
        "opt_design\n"
        "place_design\n"
        "route_design\n"
        "report_utilization\n"
        "report_timing\n"
        f"write_bitstream -force {top}.bit\n"
    )


def yosys_synth_ice40(top: str, topdir: Path, outdir: Path) -> str:
    return (
        "# read files\n"
        f"read_verilog {pjoin(topdir, top + '.v')}\n"
        "# basic synth\n"
        f"synth_ice40 -top {top} -json {pjoin(outdir, top + '.json')}\n"
    )


# ----------------------------
# Argument parsing
# ----------------------------
def parse_args():
    ap = argparse.ArgumentParser(description="Emit Yosys/ABC/Vivado scripts for ASIC/FPGA.")
    ap.add_argument("-top", "--top", required=True, type=str,
                    help="TOP module name (without extension)")
    ap.add_argument("-topdir", "--topdir", required=True, type=Path,
                    help="Directory containing the TOP RTL (e.g., rtl/)")
    ap.add_argument("-target", "--target", required=True,
                    choices=["asic", "xilinx", "ice40"],
                    help="Target technology")
    ap.add_argument("-liberty", "--liberty", type=Path,
                    help="Liberty file for ASIC mapping (required for target=asic)")
    ap.add_argument("-clk", "--clk", type=float, required=True,
                    help="Clock period in ns (used for ABC -D)")
    ap.add_argument("-sdcdir", "--sdcdir", type=Path, default=None,
                    help="Directory containing <top>.sdc (optional)")
    ap.add_argument("-opt", "--opt", choices=["area", "delay", "none"], default="delay",
                    help="Optimization target (ASIC only): area/delay/none",
                    )
    ap.add_argument("-o", "--output", type=Path, default=Path("syn"),
                    help="Output folder (default: syn)")
    ap.add_argument("--filelist", type=Path, default=Path("rtl_list.f"),
                    help="SystemVerilog file list for slang (default: {cfg.filelist.resolve().as_posix()})")
    return ap.parse_args()


# ----------------------------
# Main
# ----------------------------
def main():
    try:
        args = parse_args()

        top: str = args.top
        topdir: Path = args.topdir
        target: str = args.target
        liberty: Path | None = args.liberty
        sdcdir: Path | None = args.sdcdir
        clk_period_ns: float = args.clk
        opt: str = args.opt
        outdir: Path = args.output
        filelist: Path = args.filelist

        outdir.mkdir(parents=True, exist_ok=True)
        (outdir / "plots").mkdir(parents=True, exist_ok=True)

        if target == "asic":
            if liberty is None:
                raise ValueError("For target=asic you must provide --liberty <path/to/xxx.lib>.")

            # ABC recipes: create only what is needed
            if opt == "area":
                write_text(outdir / "area.abc", abc_script_area())
            elif opt == "delay":
                write_text(outdir / "delay.abc", abc_script_delay(clk_period_ns))
            # opt == "none": do not create any .abc script

            # Verilog-only flow (read_verilog)
            synth_v = yosys_synth_asic_verilog(
                top=top,
                topdir=topdir,
                liberty=liberty,
                clk_ns=clk_period_ns,
                opt=opt,
                sdcdir=sdcdir,
                outdir=outdir,
            )
            write_text(outdir / "synth.ys", synth_v)

            # SystemVerilog flow via slang + rtl_list.f
            synth_sv = yosys_synth_asic_slang(
                top=top,
                liberty=liberty,
                clk_ns=clk_period_ns,
                opt=opt,
                sdcdir=sdcdir,
                outdir=outdir,
                filelist=filelist,
            )
            write_text(outdir / "synth_sv.ys", synth_sv)

        elif target == "xilinx":
            write_text(outdir / "synth.ys", yosys_synth_xilinx(top, topdir, outdir))
            write_text(outdir / "xilinx.tcl", vivado_tcl_xilinx(top))

        elif target == "ice40":
            write_text(outdir / "synth.ys", yosys_synth_ice40(top, topdir, outdir))

        else:
            raise ValueError(f"Unsupported target: {target}")

    except Exception as err:
        exc_type, _, exc_tb = sys.exc_info()
        line = getattr(exc_tb, "tb_lineno", "?")
        print(
            f"\033[38;5;208mError during CORE CODE:\n"
            f"Error Type: {exc_type}\n"
            f"Line number: {line}\033[0;0m",
            file=sys.stderr,
        )
        print(err, file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    raise SystemExit(main())

