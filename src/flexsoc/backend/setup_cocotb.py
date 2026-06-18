# ruff: noqa
#!/usr/bin/env python3
# Copyright 2025
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from __future__ import annotations

import argparse
import re
from pathlib import Path
from textwrap import dedent


def repo_root() -> Path:
    return Path(__file__).resolve().parents[3]


def parse_args() -> argparse.Namespace:
    ap = argparse.ArgumentParser(description="Generate cocotb skeleton + Makefile from RTL sources")
    ap.add_argument("--top", "-top", required=True, help="Top module name (without .sv)")
    ap.add_argument(
        "--itf",
        "-itf",
        required=True,
        choices=["reg_iface", "tlul"],
        help="Register interface: reg_iface or tlul",
    )
    ap.add_argument("--output", "-o", default="tb/cocotb", help="Output folder (default: tb/cocotb)")
    ap.add_argument("--vsv", choices=["sv", "v"], default="sv", help="SV/V flow (default: sv)")
    ap.add_argument("--rtl-dir", default="rtl", help="RTL directory")
    ap.add_argument("--ips-root", default=None, help="IP root (default: <repo>/hw/ips)")
    ap.add_argument(
        "--sim",
        choices=["verilator", "icarus", "questa", "vcs", "xcelium"],
        default="verilator",
        help="Simulator (default: verilator)",
    )
    ap.add_argument("--clk", default="clk_i", help="Clock signal name (default: clk_i)")
    ap.add_argument("--rst", default="rst_ni", help="Reset signal name (default: rst_ni)")
    ap.add_argument("--rst-active", choices=["low", "high"], default="low", help="Reset polarity")
    ap.add_argument("--period-ns", type=float, default=10.0, help="Clock period ns")
    ap.add_argument("--nbit", type=int, default=32, help="Default NBIT")
    ap.add_argument("--n-op", type=int, default=10, help="Loop iterations")
    return ap.parse_args()


def read_flist(path: Path) -> list[Path]:
    out: list[Path] = []
    if not path.exists():
        return out

    base = path.parent
    for raw in path.read_text(encoding="utf-8", errors="ignore").splitlines():
        line = raw.strip()
        if not line or line.startswith("#") or line.startswith("+incdir+"):
            continue
        p = Path(line)
        if not p.is_absolute():
            p = (base / line).resolve()
        else:
            p = p.resolve()
        out.append(p)
    return out


def add_unique(paths: list[Path], seen: set[str], p: Path) -> None:
    rp = p.resolve()
    key = rp.as_posix()
    if rp.exists() and key not in seen:
        seen.add(key)
        paths.append(rp)


def collect_sources(top: str, rtl_dir: Path, ips_root: Path) -> list[Path]:
    """
    Source selection for cocotb:
    1. If <rtl_dir>/rtl_list.f exists, use it as the source of truth.
    2. Otherwise fall back to local rtl/*.sv and rtl/*.v.
    3. Ensure tl_main_pkg.sv, xbar_main.sv, <top>.sv are present at the end if they exist.
    """
    seen: set[str] = set()
    ordered: list[Path] = []

    rtl_list = rtl_dir / "rtl_list.f"
    if rtl_list.exists():
        for p in read_flist(rtl_list):
            add_unique(ordered, seen, p)
    else:
        for p in sorted(rtl_dir.glob("*.sv")):
            add_unique(ordered, seen, p)
        for p in sorted(rtl_dir.glob("*.v")):
            add_unique(ordered, seen, p)

    for tail in (rtl_dir / "tl_main_pkg.sv", rtl_dir / "xbar_main.sv", rtl_dir / f"{top}.sv"):
        add_unique(ordered, seen, tail)

    return ordered


def makefile_block_from_paths(paths: list[Path], *, var_name: str = "VERILOG_SOURCES") -> str:
    if not paths:
        return f"{var_name} :="
    lines = [f"{var_name} := \\"]
    for p in paths[:-1]:
        lines.append(f"  {p.resolve()} \\")
    lines.append(f"  {paths[-1].resolve()}")
    return "\n".join(lines)


def read_top_path(rtl_dir: Path, top: str) -> Path | None:
    cand = rtl_dir / f"{top}.sv"
    if cand.exists():
        return cand
    for p in rtl_dir.rglob("*.sv"):
        if p.stem == top:
            return p
    return None


def parse_top_ports(top_file: Path) -> dict:
    try:
        text = top_file.read_text(encoding="utf-8", errors="ignore")
    except Exception:
        return {"clk": [], "rst": [], "inputs": [], "outputs": []}

    m = re.search(r"module\s+\w+\s*\((.*?)\);\s", text, flags=re.S | re.M)
    header_text = text.split(");", 1)[0] if not m else m.group(1)
    lines = [re.sub(r"//.*", "", ln).strip() for ln in header_text.splitlines()]
    lines = [ln for ln in lines if ln]

    clk, rst = [], []
    inputs, input_w = [], []
    outputs, output_w = [], []

    def parse_decl(prefix: str, line: str):
        body = line[len(prefix):].strip()
        toks = body.split()
        if not toks:
            return None, []
        if toks[0] in ("logic", "wire", "reg"):
            toks = toks[1:]
            if not toks:
                return None, []
        width_tok = None
        if toks and toks[0].startswith("["):
            width_tok = toks[0]
            toks = toks[1:]
        names = [t.rstrip(",") for t in toks if t.rstrip(",")]
        return width_tok if width_tok else 1, names

    for ln in lines:
        if ln.startswith("input "):
            w, names = parse_decl("input ", ln)
            for n in names:
                if "clk" in n:
                    clk.append(n)
                if "rst" in n:
                    rst.append(n)
                inputs.append(n)
                input_w.append(w)
        elif ln.startswith("output "):
            w, names = parse_decl("output ", ln)
            for n in names:
                outputs.append(n)
                output_w.append(w)

    return {
        "clk": clk,
        "rst": rst,
        "inputs": [{"name": n, "width": input_w[i]} for i, n in enumerate(inputs)],
        "outputs": [{"name": n, "width": output_w[i]} for i, n in enumerate(outputs)],
    }


def make_other_port_decls(info: dict) -> tuple[list[str], str]:
    ctrl = set(info.get("clk", [])) | set(info.get("rst", [])) | {"tl_i", "tl_o"}

    def wdecl(w):
        return "logic" if (w == 1 or str(w) == "1") else f"logic {w}"

    names: list[str] = []
    decls: list[str] = []

    for e in info.get("inputs", []):
        n = e.get("name", "")
        if not n or n in ctrl or n.startswith(("clk", "rst")) or "::" in n:
            continue
        names.append(n)
        decls.append(f"  {wdecl(e.get('width', 1))} {n};")

    for e in info.get("outputs", []):
        n = e.get("name", "")
        if not n or n in ctrl or n.startswith(("clk", "rst")) or "::" in n:
            continue
        names.append(n)
        decls.append(f"  {wdecl(e.get('width', 1))} {n};")

    return names, "\n".join(decls)


def emit_makefile(args: argparse.Namespace, out_dir: Path, ordered_sources: list[Path], rtl_dir: Path) -> None:
    repo = repo_root()
    inc_pkgs = repo / "hw/ips/pkgs"
    inc_prim = repo / "hw/ips/prim"
    inc_prim_ot = repo / "hw/ips/prim_opentitan"
    inc_tlul = repo / "hw/ips/tlul"

    verilog_block = makefile_block_from_paths(ordered_sources)

    mk = dedent(
        f"""\
        # Auto-generated Makefile
        SIM               ?= {args.sim}
        TOPLEVEL_LANG     ?= verilog

        PWD               := $(shell pwd)
        TOPLEVEL          = {args.top}_tb
        MODULE            = {args.top}_tb

        ifneq ($(filter clean veryclean distclean,$(MAKECMDGOALS)),)
          SIM := icarus
        endif

        ifeq ($(GATES),yes)
          SIM := icarus
        else
          SIM ?= {args.sim}
        endif

        SIM_BUILD         ?= sim_build/rtl

        ifneq ($(GATES),yes)

        {verilog_block}

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
        VERILOG_SOURCES   += ../../syn/{args.top}_synth.v
        endif

        COMPILE_ARGS += -I{rtl_dir.resolve()} -I{inc_pkgs} -I{inc_prim} -I{inc_prim_ot} -I{inc_tlul}

        export COCOTB_RESULTS_FILE ?= $(abspath results.xml)

        VERILOG_SOURCES += {(out_dir / f"{args.top}_tb.sv").resolve()}

        include $(shell cocotb-config --makefiles)/Makefile.sim
        """
    )
    (out_dir / "Makefile").write_text(mk, encoding="utf-8")


def emit_utils(out_dir: Path) -> None:
    (out_dir / "utils.py").write_text(
        dedent(
            """\
            import random

            def rand_bin_values(nbit: int):
                a = random.randint(0, (1 << nbit) - 1)
                b = random.randint(0, (1 << nbit) - 1)
                return a, b
            """
        ),
        encoding="utf-8",
    )
    (out_dir / "__init__.py").write_text("", encoding="utf-8")


def emit_reg_driver(out_dir: Path) -> None:
    (out_dir / "drivers" / "driver_reg_iface.py").write_text("from cocotb.triggers import RisingEdge\n", encoding="utf-8")


def emit_tlul_driver(out_dir: Path) -> None:
    (out_dir / "drivers" / "driver_tlul.py").write_text("from cocotb.triggers import RisingEdge\n", encoding="utf-8")


def emit_test(args: argparse.Namespace, out_dir: Path) -> None:
    (out_dir / f"{args.top}_tb.py").write_text(
        dedent(
            f"""\
            import cocotb
            from cocotb.clock import Clock
            from cocotb.triggers import RisingEdge

            @cocotb.test()
            async def {args.top}_smoke_test(dut):
                clk = getattr(dut, "{args.clk}")
                cocotb.start_soon(Clock(clk, {args.period_ns}, unit="ns").start())
                for _ in range(5):
                    await RisingEdge(clk)
            """
        ),
        encoding="utf-8",
    )


def emit_tlul_wrapper(args: argparse.Namespace, out_dir: Path, rtl_dir: Path) -> None:
    top_path = read_top_path(rtl_dir, args.top)
    port_info = parse_top_ports(top_path) if top_path else {"clk": [], "rst": [], "inputs": [], "outputs": []}
    _, other_decls = make_other_port_decls(port_info)

    wrap = dedent(
        f"""\
`timescale 1ns/1ps
module {args.top}_tb;
  logic {args.clk};
  logic {args.rst};
  {other_decls}
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
    $dumpfile("{args.top}_tb.vcd");
    $dumpvars(0, {args.top}_tb);
    #1;
  end
  {args.top} u_{args.top} (
    .{args.clk}({args.clk}),
    .{args.rst}({args.rst}),
    .*
  );
endmodule
"""
    )
    (out_dir / f"{args.top}_tb.sv").write_text(wrap, encoding="utf-8")


def main() -> None:
    args = parse_args()

    out_dir = Path(args.output).resolve()
    rtl_dir = Path(args.rtl_dir).resolve()
    ips_root = Path(args.ips_root).resolve() if args.ips_root else (repo_root() / "hw/ips").resolve()

    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "drivers").mkdir(parents=True, exist_ok=True)

    ordered_sources = collect_sources(args.top, rtl_dir, ips_root)

    emit_makefile(args, out_dir, ordered_sources, rtl_dir)
    emit_utils(out_dir)
    emit_reg_driver(out_dir)
    emit_tlul_driver(out_dir)
    emit_test(args, out_dir)
    emit_tlul_wrapper(args, out_dir, rtl_dir)

    print(f"Generated in: {out_dir}")


if __name__ == "__main__":
    main()
