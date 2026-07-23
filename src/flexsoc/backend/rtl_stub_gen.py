"""Generate starter RTL core logic and a wrapper aligned from the core ports."""

from __future__ import annotations

import argparse
import ast
import re
import sys
from pathlib import Path
from typing import Any

from .common import colorize, ensure_dir, safe_write_file
from .top_from_core import render_top_from_core

try:
    import hjson  # type: ignore
except ImportError:  # pragma: no cover - import fallback for tiny tests.
    hjson = None

Hjson = dict[str, Any]


def _load_hjson(path: Path) -> Hjson:
    """Load HJSON metadata with hjson or a tiny literal fallback."""

    text = path.read_text(encoding="utf-8")
    if hjson is not None:
        return dict(hjson.loads(text))
    text = re.sub(r"([{,]\s*)([A-Za-z_]\w*)\s*:", r'\1"\2":', text)
    text = re.sub(r",\s*([}\]])", r"\1", text)
    return dict(ast.literal_eval(text))


def _id(value: str) -> str:
    """Return a conservative lowercase SystemVerilog identifier."""

    name = re.sub(r"\W+", "_", value.strip().lower()).strip("_")
    return f"_{name}" if name[:1].isdigit() else name


def _width(bits: str) -> int:
    """Return the width encoded by one bit or msb:lsb range."""

    if ":" not in bits:
        return 1
    msb, lsb = (int(part) for part in bits.split(":", 1))
    return abs(msb - lsb) + 1


def _logic(name: str, width: int) -> str:
    """Render a scalar/vector logic declaration."""

    return f"  logic [{width - 1}:0] {name};" if width > 1 else f"  logic {name};"


def _field_signal(reg_name: str, field: Hjson, *, flat: bool) -> tuple[str, int, str]:
    """Return local name, width, and reggen CSR path for one HJSON field."""

    field_name = _id(str(field.get("name") or reg_name))
    signal = reg_name if flat else f"{reg_name}_{field_name}"
    path = reg_name if flat else f"{reg_name}.{field_name}"
    return signal, _width(str(field["bits"])), path


def _register_signals(hj: Hjson) -> tuple[list[str], list[str], list[str], set[str]]:
    """Map HJSON registers to reggen's reg2hw/hw2reg structs."""

    decls, reg2core, core2reg, names = [], [], [], set()
    for reg in hj.get("registers", []) or []:
        if not isinstance(reg, dict) or "name" not in reg:
            continue
        reg_name = _id(str(reg["name"]))
        fields = [f for f in reg.get("fields", []) or [] if isinstance(f, dict) and "bits" in f]
        flat = len(fields) == 1
        for field in fields:
            signal, width, path = _field_signal(reg_name, field, flat=flat)
            swaccess = str(field.get("swaccess", reg.get("swaccess", ""))).lower()
            hwaccess = str(field.get("hwaccess", reg.get("hwaccess", ""))).lower()
            if signal not in names:
                decls.append(_logic(signal, width))
                names.add(signal)
            if swaccess in {"rw", "wo", "w1c", "w1s", "rw1c", "rw1s", "rw0c", "rw0w1c"}:
                reg2core.append(f"  assign {signal} = reg2hw.{path}.q;")
            if swaccess == "ro" and hwaccess in {"hrw", "hwo"}:
                core2reg.append(f"  assign hw2reg.{path}.d = {signal};")
    return decls, reg2core, core2reg, names


def _assign_if(name: str, expr: str, names: set[str]) -> list[str]:
    """Assign a generated CSR signal only when it exists."""

    return [f"  assign {name} = {expr};"] if name in names else []


def _sig(names: set[str], name: str, default: str) -> str:
    """Return a CSR signal expression or a safe default."""

    return name if name in names else default


def render_core(hj: Hjson) -> str:
    """Render a small but useful pipelined <top>_core.sv."""

    top = _id(str(hj["name"]))
    decls, reg2core, core2reg, names = _register_signals(hj)
    ctrl_en = _sig(names, "ctrl_en", "1'b1")
    ctrl_clr = _sig(names, "ctrl_clr", "1'b0")
    mode_sel = _sig(names, "mode_sel", "2'd0")
    scale = _sig(names, "scale", "8'd0")
    core_logic = [
        "  logic [31:0] add_result;",
        "  logic [31:0] xor_result;",
        "  logic [31:0] selected_d;",
        "  logic [31:0] pipe_q0;",
        "  logic [31:0] pipe_q1;",
        "  logic        valid_q0;",
        "  logic        valid_q1;",
        "",
        "  assign add_result = data_i + coeff_i;",
        "  assign xor_result = data_i ^ coeff_i;",
        "",
        "  always_comb begin",
        f"    unique case ({mode_sel}[1:0])",
        "      2'd0: selected_d = add_result;",
        "      2'd1: selected_d = xor_result;",
        f"      2'd2: selected_d = data_i << {scale}[4:0];",
        "      default: selected_d = data_i;",
        "    endcase",
        f"    if (!{ctrl_en}) selected_d = '0;",
        "  end",
        "",
        "  always_ff @(posedge clk_i or negedge rst_ni) begin",
        "    if (!rst_ni) begin",
        "      pipe_q0  <= '0;",
        "      pipe_q1  <= '0;",
        "      valid_q0 <= 1'b0;",
        "      valid_q1 <= 1'b0;",
        f"    end else if ({ctrl_clr}) begin",
        "      pipe_q0  <= '0;",
        "      pipe_q1  <= '0;",
        "      valid_q0 <= 1'b0;",
        "      valid_q1 <= 1'b0;",
        "    end else begin",
        "      pipe_q0  <= selected_d;",
        "      pipe_q1  <= pipe_q0;",
        f"      valid_q0 <= valid_i & {ctrl_en};",
        "      valid_q1 <= valid_q0;",
        "    end",
        "  end",
        "",
        "  assign data_o  = pipe_q1;",
        "  assign valid_o = valid_q1;",
        *_assign_if("status_busy", "valid_q0", names),
        *_assign_if("status_done", "valid_q1", names),
        *_assign_if("status_error", "1'b0", names),
        *_assign_if("result", "pipe_q1", names),
    ]
    lines = [
        "// Auto-generated by flexsoc.backend.rtl_stub_gen.",
        f"module {top}_core",
        f"  import {top}_reg_pkg::*;",
        "(",
        "  input        clk_i,",
        "  input        rst_ni,",
        f"  input  {top}_reg2hw_t reg2hw,",
        f"  output {top}_hw2reg_t hw2reg,",
        "",
        "  input  logic [31:0] data_i,",
        "  input  logic [31:0] coeff_i,",
        "  input  logic        valid_i,",
        "  output logic [31:0] data_o,",
        "  output logic        valid_o",
        ");",
        "",
        "  // CSR signals",
        *(decls or ["  // no CSR signals inferred"]),
        "",
        "  // CSR to core",
        *(reg2core or ["  // no writable CSR fields inferred"]),
        "",
        "  // Core datapath",
        *core_logic,
        "",
        "  // Core to CSR",
        *(core2reg or ["  // no readable HW CSR fields inferred"]),
        "",
        "endmodule",
    ]
    return "\n".join(lines) + "\n"


def generate_rtl_stubs(hjson_path: str | Path, itf: str, outdir: str | Path, *, force: bool = False) -> tuple[Path, Path]:
    """Generate <top>_core.sv and an aligned <top>.sv wrapper."""

    hj = _load_hjson(Path(hjson_path).resolve())
    top = _id(str(hj.get("name", "")))
    if not top:
        raise ValueError("missing or empty 'name' in HJSON")
    ensure_dir(outdir)
    rtl = Path(outdir)
    core_path, top_path = rtl / f"{top}_core.sv", rtl / f"{top}.sv"
    safe_write_file(core_path, render_core(hj), overwrite=force)
    safe_write_file(top_path, render_top_from_core(top, core_path, itf), overwrite=force)
    return core_path, top_path


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse command-line arguments."""

    parser = argparse.ArgumentParser(description="Generate starter RTL core and top wrapper.")
    parser.add_argument("--hjson-file", dest="hjson_path", required=True)
    parser.add_argument("--interface", dest="itf", required=True)
    parser.add_argument("--output-dir", dest="outdir", default=".")
    parser.add_argument("-f", "--force", action="store_true", help="overwrite existing files")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Run the RTL stub generator."""

    try:
        args = parse_args(argv)
        generate_rtl_stubs(args.hjson_path, args.itf, args.outdir, force=args.force)
        return 0
    except Exception as err:
        print(colorize(f"Error: {err}"), file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
