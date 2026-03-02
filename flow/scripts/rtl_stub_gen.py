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
\file rtl_stub_gen.py
\brief Generate RTL stub files (<top>_core.sv and <top>.sv) from a Comportable HJSON.
\details
  This script reads an OpenTitan-style Comportable IP HJSON and emits:
    - `<top>_core.sv`: a minimal "core" that exposes typed reg2hw/hw2reg signals and placeholder logic.
    - `<top>.sv`     : a top wrapper that instantiates the generated register block and the core,
                       and wires up the chosen bus interface (currently TL-UL device or a generic reg_if).

  ## CLI (legacy-compatible)
    - -i / --input / --hjson / --hjson-file : path to input HJSON (required)
    - -itf / -iT / --itf / --bus            : bus interface (e.g., "tlul") (required)
    - -o / --output / --output-dir          : output directory (default: ".")
    - -f / --force                          : overwrite existing files if present

  ## Behavior
    - Creates the output directory, if missing.
    - Refuses to overwrite existing outputs unless --force is provided.
    - Emits simple, readable SystemVerilog with clear comment banners to guide further edits.

  ## Example
    python3 scripts/rtl_stub_gen.py -i data/my_ip.hjson -itf tlul -o rtl
"""

from __future__ import annotations

import argparse
import sys
import os
from pathlib import Path
from typing import List, Tuple, Dict, Any

# --- shared helpers (optional dependency on scripts/common.py) ----------------
try:
    from common import colorize, ensure_dir, safe_write_file  # type: ignore
except Exception:
    def colorize(s: str) -> str: return s
    def ensure_dir(path: str | os.PathLike[str]) -> None: os.makedirs(path, exist_ok=True)
    def safe_write_file(path: str | os.PathLike[str], content: str, *, overwrite: bool = False) -> None:
        p = Path(path)
        if p.exists() and not overwrite:
            raise FileExistsError(str(p))
        p.write_text(content, encoding="utf-8")

# --- external deps ------------------------------------------------------------
# We keep import local to show a clear error if hjson is missing.
try:
    import hjson
except ImportError as e:
    print(colorize("Error: Missing dependency 'hjson'. Try: pip install hjson"), file=sys.stderr)
    raise

# --- types --------------------------------------------------------------------
Hjson = Dict[str, Any]


# === small utilities ==========================================================

def _sv_logic_decl(name: str, width: int) -> str:
    r""" \brief Emit a SystemVerilog logic declaration 'logic [N-1:0] name;' or 'logic name;' """
    return f"  logic [{width - 1}:0] {name};" if width > 1 else f"  logic {name};"


def _bit_width(bits: str) -> int:
    r""" \brief Compute width from a bit-range like '31:16' or a single bit '7' / '0'. """
    if ":" in bits:
        msb, lsb = map(int, bits.split(":"))
        return abs(msb - lsb) + 1
    return 1


def _sanitize_id(s: str) -> str:
    r""" \brief Make a conservative SV identifier: lowercase, non-alnum -> '_' """
    out = []
    for ch in s.lower():
        out.append(ch if (ch.isalnum() or ch == "_") else "_")
    # Disallow leading digit
    if out and out[0].isdigit():
        out.insert(0, "_")
    return "".join(out)

# === code generation ==========================================================

def render_core(hj: Hjson) -> str:
    r"""
    \brief Render the `<top>_core.sv` module.
    \details
      - Declares simple internal signals for each CSR field.
      - Wires reg2hw -> internal (for RW/WO) and internal -> hw2reg (for RO with HW drives).
      - Adds a tiny example synchronizer (prim_ff_2sync) as placeholder logic.
    """
    module = _sanitize_id(str(hj["name"]))
    reg_pkg = f"{module}_reg_pkg"
    reg2hw_struct = f"{module}_reg2hw_t"
    hw2reg_struct = f"{module}_hw2reg_t"

    signal_defs: List[str] = []
    ctrl2reg_assign: List[str] = []
    reg2ctrl_assign: List[str] = []

    for reg in hj.get("registers", []) or []:
        reg_name = _sanitize_id(reg["name"])
        swaccess = str(reg.get("swaccess", "")).lower()
        hwaccess = str(reg.get("hwaccess", "")).lower()
        hwqe = bool(reg.get("hwqe", False))
        hwre = bool(reg.get("hwre", False))
        fields = reg.get("fields", []) or []

        # If no fields present, skip defensively
        if not fields:
            continue

        # Single anonymous field -> treat as full register width
        if len(fields) == 1 and not fields[0].get("name"):
            bits = str(fields[0]["bits"])
            width = _bit_width(bits)
            base = reg_name
            signal_defs.append(_sv_logic_decl(base, width))

            if swaccess in ("rw", "wo"):
                ctrl2reg_assign.append(f"  assign {base} = reg2hw.{reg_name}.q;")
            if (swaccess == "ro") and (hwaccess in ("hrw", "hwo")):
                reg2ctrl_assign.append(f"  assign hw2reg.{reg_name}.d = {base};")

            if hwqe:
                v = f"{base}_valid"
                signal_defs.append(_sv_logic_decl(v, 1))
                ctrl2reg_assign.append(f"  assign {v} = reg2hw.{reg_name}.qe;")
            if hwre:
                r = f"{base}_ready"
                signal_defs.append(_sv_logic_decl(r, 1))
                ctrl2reg_assign.append(f"  assign {r} = reg2hw.{reg_name}.re;")

        else:
            # Named fields
            for fld in fields:
                fld_name = _sanitize_id(str(fld.get("name", reg_name)))
                bits = str(fld["bits"])
                width = _bit_width(bits)
                wire = f"{reg_name}_{fld_name}"
                signal_defs.append(_sv_logic_decl(wire, width))

                if swaccess in ("rw", "wo"):
                    ctrl2reg_assign.append(f"  assign {wire} = reg2hw.{reg_name}.{fld_name}.q;")
                    if hwqe:
                        v = f"{wire}_valid"
                        signal_defs.append(_sv_logic_decl(v, 1))
                        ctrl2reg_assign.append(f"  assign {v} = reg2hw.{reg_name}.{fld_name}.qe;")
                    if hwre:
                        r = f"{wire}_ready"
                        signal_defs.append(_sv_logic_decl(r, 1))
                        ctrl2reg_assign.append(f"  assign {r} = reg2hw.{reg_name}.{fld_name}.re;")

                if (swaccess == "ro") and (hwaccess in ("hrw", "hwo")):
                    reg2ctrl_assign.append(f"  assign hw2reg.{reg_name}.{fld_name}.d = {wire};")

    lines: List[str] = []
    lines.append(f"// -----------------------------------------------------------------------------")
    lines.append(f"// THIS FILE IS AUTO-GENERATED. Edit the logic below the placeholders as needed.")
    lines.append(f"// -----------------------------------------------------------------------------")
    lines.append(f"module {module}_core")
    lines.append(f"  import {reg_pkg}::*;")
    lines.append(f"(")
    lines.append(f"  input        clk_i,")
    lines.append(f"  input        rst_ni,")
    lines.append(f"  input  {reg2hw_struct} reg2hw,")
    lines.append(f"  output {hw2reg_struct} hw2reg,")
    lines.append(f"")
    lines.append(f"  // TODO: add real IP I/Os")
    lines.append(f"  input  logic port_i,")
    lines.append(f"  output logic port_o")
    lines.append(f");")
    lines.append("")
    lines.append(f"  //////////////")
    lines.append(f"  // Signals  //")
    lines.append(f"  //////////////")
    if signal_defs:
        lines.extend(signal_defs)
    else:
        lines.append(f"  // (no CSR-driven signals inferred yet)")
    lines.append("")
    lines.append(f"  //////////////")
    lines.append(f"  // CTRL2REG //")
    lines.append(f"  //////////////")
    lines.extend(ctrl2reg_assign if ctrl2reg_assign else ["  // (no assignments)"])
    lines.append("")
    lines.append(f"  //////////////")
    lines.append(f"  // REG2CTRL //")
    lines.append(f"  //////////////")
    lines.extend(reg2ctrl_assign if reg2ctrl_assign else ["  // (no assignments)"])
    lines.append("")
    lines.append(f"  // ---------------------------------------------------------------------------")
    lines.append(f"  // Example placeholder logic: 2-flop synchronizer")
    lines.append(f"  // Replace with your real core functionality.")
    lines.append(f"  // ---------------------------------------------------------------------------")
    lines.append(f"  prim_ff_2sync #(")
    lines.append(f"    .Width(1),")
    lines.append(f"    .ResetValue('0)")
    lines.append(f"  ) u_sync_name (")
    lines.append(f"    .clk_i (clk_i),")
    lines.append(f"    .rst_ni(rst_ni),")
    lines.append(f"    .d_i   (port_i),")
    lines.append(f"    .q_o   (port_o)")
    lines.append(f"  );")
    lines.append("")
    lines.append(f"endmodule")
    return "\n".join(lines)


def render_wrapper(hj: Hjson, itf: str) -> str:
    r"""
    \brief Render the `<top>.sv` wrapper.
    \param itf Bus interface. Currently supported: "tlul" (device).
    """
    module = _sanitize_id(str(hj["name"]))
    reg_pkg = f"{module}_reg_pkg"

    if itf.lower() not in ("tlul", "reg_iface"):
        raise ValueError(f"Unsupported --itf '{itf}'. Supported: tlul, reg")

    # Interface ports
    if itf.lower() == "tlul":
        bus_decl_in  = "input  tlul_pkg::tl_h2d_t tl_i"
        bus_decl_out = "output tlul_pkg::tl_d2h_t tl_o"
        bus_conn_in  = ".tl_i(tl_i),"
        bus_conn_out = ".tl_o(tl_o),"
        aw_param = ""  # TL-UL device uses TLUL structs; no AW here
    else:
        # Generic reg_if style (placeholder)
        bus_decl_in  = "input  reg_req_t reg_req_i"
        bus_decl_out = "output reg_rsp_t reg_rsp_o"
        bus_conn_in  = ".reg_req_i(reg_req_i),"
        bus_conn_out = ".reg_rsp_o(reg_rsp_o),"
        aw_param = "  parameter int AW = 4,\n"

    lines: List[str] = []
    lines.append(f"// -----------------------------------------------------------------------------")
    lines.append(f"// THIS FILE IS AUTO-GENERATED. It wires the register block with the core.")
    lines.append(f"// -----------------------------------------------------------------------------")
    lines.append(f"module {module}")
    lines.append(f"  import {reg_pkg}::*;")
    lines.append(f"(")
    lines.append(f"  // Clocks & Reset")
    lines.append(f"  input  clk_i,")
    lines.append(f"  input  rst_ni,")
    lines.append(f"")
    lines.append(f"  // Bus interface")
    lines.append(f"  {bus_decl_in},")
    lines.append(f"  {bus_decl_out},")
    lines.append(f"")
    lines.append(f"  // User I/O")
    lines.append(f"  input  logic port_i,")
    lines.append(f"  output logic port_o")
    lines.append(f");")
    lines.append("")
    lines.append(f"  {module}_reg2hw_t reg2hw;")
    lines.append(f"  {module}_hw2reg_t hw2reg;")
    lines.append("")
    lines.append(f"  // Register block")
    lines.append(f"  {module}_reg_top u_{module}_reg (")
    lines.append(f"    .clk_i(clk_i),")
    lines.append(f"    .rst_ni(rst_ni),")
    lines.append(f"    {bus_conn_in}")
    lines.append(f"    {bus_conn_out}")
    lines.append(f"    .reg2hw(reg2hw),")
    lines.append(f"    .hw2reg(hw2reg),")
    lines.append(f"    .devmode_i(1'b1)")
    lines.append(f"  );")
    lines.append("")
    lines.append(f"  // Core")
    lines.append(f"  {module}_core u_{module}_core (")
    lines.append(f"    .clk_i(clk_i),")
    lines.append(f"    .rst_ni(rst_ni),")
    lines.append(f"    .reg2hw(reg2hw),")
    lines.append(f"    .hw2reg(hw2reg),")
    lines.append(f"    .port_i(port_i),")
    lines.append(f"    .port_o(port_o)")
    lines.append(f"  );")
    lines.append("")
    lines.append(f"endmodule")
    return "\n".join(lines)


# === CLI ======================================================================

def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    r"""
    \brief Parse command-line arguments (supports legacy flags).
    \details
      Returns an argparse.Namespace with:
        - hjson_path: Path to input HJSON
        - itf:       Bus interface
        - outdir:    Output directory
        - force:     Overwrite existing files
    """
    p = argparse.ArgumentParser(
        prog="rtl_stub_gen",
        description="Generate <top>_core.sv and <top>.sv from a Comportable HJSON.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    p.add_argument("-i", "--input", "--hjson", "--hjson-file",
                   dest="hjson_path", required=True,
                   help="Input HJSON file path.")
    p.add_argument("-itf", "-iT", "--itf", "--bus",
                   dest="itf", required=True,
                   help='Register/bus interface (e.g., "tlul").')
    p.add_argument("-o", "--output", "--output-dir",
                   dest="outdir", default=".",
                   help="Output directory for generated .sv files.")
    p.add_argument("-f", "--force", dest="force", action="store_true",
                   help="Overwrite existing files if they already exist.")
    return p.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    r""" \brief Entry point. """
    try:
        args = parse_args(argv)

        hjson_path = Path(args.hjson_path).resolve()
        outdir = Path(args.outdir)
        itf = str(args.itf).strip().lower()
        force = bool(args.force)

        if not hjson_path.exists():
            print(colorize(f"Error: HJSON file not found: {hjson_path}"), file=sys.stderr)
            return 2

        # Load HJSON
        with hjson_path.open("r", encoding="utf-8") as f:
            hj: Hjson = hjson.load(f)

        # Basic validations
        name = _sanitize_id(str(hj.get("name", "")).strip())
        if not name:
            print(colorize("Error: missing or empty 'name' in HJSON."), file=sys.stderr)
            return 2

        # Render
        core_sv = render_core(hj)
        wrap_sv = render_wrapper(hj, itf)

        # Write
        ensure_dir(outdir)
        core_path = outdir / f"{name}_core.sv"
        wrap_path = outdir / f"{name}.sv"

        try:
            safe_write_file(core_path, core_sv, overwrite=force)
            safe_write_file(wrap_path, wrap_sv, overwrite=force)
        except FileExistsError as e:
            print(colorize(f"Refusing to overwrite existing file: {e}. Use --force."), file=sys.stderr)
            return 1

        #print(colorize(f"Generated: {core_path}"))
        #print(colorize(f"Generated: {wrap_path}"))
        return 0

    except KeyboardInterrupt:
        print(colorize("Aborted by user."), file=sys.stderr)
        return 130
    except Exception as err:
        tb = sys.exc_info()[2]
        line = getattr(tb, "tb_lineno", "?") if tb else "?"
        print(colorize(f"Error at line {line}: {err!s}"), file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
