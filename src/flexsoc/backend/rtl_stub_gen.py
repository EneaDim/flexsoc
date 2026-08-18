"""Generate starter RTL core logic and a wrapper aligned from the core ports."""

from __future__ import annotations

import argparse
import ast
import re
import sys
from pathlib import Path
from textwrap import dedent
from typing import Any

from flexsoc.clocking import clock_config

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

def render_nclock_core(top: str) -> str:
    """Render the editable N-clock core stub."""

    return dedent(f"""\
    // Editable N-clock RTL core for {top}.
    //
    // User edit point:
    //   Keep this file as the main design surface. After changing ports, run
    //   `fx top_from_core --force` to refresh rtl/{top}.sv.
    //
    // Register path rule from reggen:
    //   - multi-field registers use .<field>.q/.d, e.g. ctrl.enable.q.
    //   - single-field registers are flat, e.g. gain.q and result.d.

    module {top}_core
      import {top}_cfg_reg_pkg::*;
      import {top}_dsp_reg_pkg::*;
    (
      input  logic                     cfg_clk_i,
      input  logic                     cfg_rst_ni,
      input  logic                     rx_clk_i,
      input  logic                     rx_rst_ni,
      input  logic                     dsp_clk_i,
      input  logic                     dsp_rst_ni,
      input  logic                     test_en_i,

      input  {top}_cfg_reg2hw_t        cfg_reg2hw_i,
      output {top}_cfg_hw2reg_t        cfg_hw2reg_o,
      input  {top}_dsp_reg2hw_t        dsp_reg2hw_i,
      output {top}_dsp_hw2reg_t        dsp_hw2reg_o,

      input  logic                     rx_valid_i,
      output logic                     rx_ready_o,
      input  logic signed [15:0]       rx_sample_i,
      input  logic signed [15:0]       rx_coeff_i,

      output logic                     dsp_valid_o,
      input  logic                     dsp_ready_i,
      output logic signed [31:0]       dsp_result_o,
      output logic                     dsp_above_threshold_o,
      output logic                     dsp_overflow_o
    );

      localparam logic signed [63:0] I32_MAX = 64'sd2147483647;
      localparam logic signed [63:0] I32_MIN = -64'sd2147483648;

      // --------------------------------------------------------------------
      // Register extraction
      // --------------------------------------------------------------------
      logic               cfg_enable;
      logic               cfg_soft_reset;
      logic               cfg_clk_gate_en;
      logic signed [15:0] cfg_gain;
      logic [1:0]         dsp_op;
      logic               dsp_saturate;
      logic [31:0]        dsp_threshold;

      assign cfg_enable      = cfg_reg2hw_i.ctrl.enable.q;
      assign cfg_soft_reset  = cfg_reg2hw_i.ctrl.soft_reset.q;
      assign cfg_clk_gate_en = cfg_reg2hw_i.ctrl.clk_gate_en.q;
      assign cfg_gain        = cfg_reg2hw_i.gain.q[15:0];
      assign dsp_op          = dsp_reg2hw_i.dsp_ctrl.op.q;
      assign dsp_saturate    = dsp_reg2hw_i.dsp_ctrl.saturate.q;
      assign dsp_threshold   = dsp_reg2hw_i.threshold.q;

      // --------------------------------------------------------------------
      // Single-bit CDC controls
      // --------------------------------------------------------------------
      logic enable_rx;
      logic enable_dsp;
      logic soft_reset_dsp;
      logic clk_gate_en_dsp;
      logic signed [15:0] gain_dsp_q;

      prim_flop_2sync #(.Width(1), .ResetValue(1'b0)) u_enable_rx_sync (
        .clk_i  (rx_clk_i),
        .rst_ni (rx_rst_ni),
        .d_i    (cfg_enable),
        .q_o    (enable_rx)
      );

      prim_flop_2sync #(.Width(1), .ResetValue(1'b0)) u_enable_dsp_sync (
        .clk_i  (dsp_clk_i),
        .rst_ni (dsp_rst_ni),
        .d_i    (cfg_enable),
        .q_o    (enable_dsp)
      );

      prim_flop_2sync #(.Width(1), .ResetValue(1'b0)) u_soft_reset_dsp_sync (
        .clk_i  (dsp_clk_i),
        .rst_ni (dsp_rst_ni),
        .d_i    (cfg_soft_reset),
        .q_o    (soft_reset_dsp)
      );

      prim_flop_2sync #(.Width(1), .ResetValue(1'b0)) u_clk_gate_en_dsp_sync (
        .clk_i  (dsp_clk_i),
        .rst_ni (dsp_rst_ni),
        .d_i    (cfg_clk_gate_en),
        .q_o    (clk_gate_en_dsp)
      );

      always_ff @(posedge dsp_clk_i or negedge dsp_rst_ni) begin
        if (!dsp_rst_ni) begin
          gain_dsp_q <= '0;
        end else if (!enable_dsp) begin
          // Safe scaffold policy: update multi-bit cfg while disabled.
          gain_dsp_q <= cfg_gain;
        end
      end

      // --------------------------------------------------------------------
      // RX -> DSP async FIFO
      // --------------------------------------------------------------------
      logic        fifo_wready;
      logic        fifo_rvalid;
      logic        fifo_rready;
      logic [31:0] fifo_wdata;
      logic [31:0] fifo_rdata;
      logic [3:0]  fifo_wdepth;
      logic [3:0]  fifo_rdepth;
      logic        dsp_pipe_valid_q;
      logic        dsp_pipe_ready;
      logic        dsp_out_ready;

      assign fifo_wdata  = {{rx_sample_i, rx_coeff_i}};
      assign rx_ready_o  = enable_rx & fifo_wready;
      assign fifo_rready = enable_dsp & fifo_rvalid & dsp_pipe_ready;

      prim_fifo_async #(
        .Width(32),
        .Depth(8),
        .OutputZeroIfEmpty(1'b1),
        .OutputZeroIfInvalid(1'b1)
      ) u_rx_to_dsp_fifo (
        .clk_wr_i  (rx_clk_i),
        .rst_wr_ni (rx_rst_ni),
        .wvalid_i  (rx_valid_i & rx_ready_o),
        .wready_o  (fifo_wready),
        .wdata_i   (fifo_wdata),
        .wdepth_o  (fifo_wdepth),
        .clk_rd_i  (dsp_clk_i),
        .rst_rd_ni (dsp_rst_ni),
        .rvalid_o  (fifo_rvalid),
        .rready_i  (fifo_rready),
        .rdata_o   (fifo_rdata),
        .rdepth_o  (fifo_rdepth)
      );

      // --------------------------------------------------------------------
      // DSP clock gate intent
      // --------------------------------------------------------------------
      // The scaffold keeps computation on dsp_clk_i for broad tool support and
      // still instantiates prim_clk_gate so the intended enable is visible to
      // lint/timing review. Replace this with a gated-clock implementation only
      // after your constraints and gate-level checks are ready.
      logic dsp_clk_gated;
      logic dsp_clk_active;
      assign dsp_clk_active = enable_dsp & (!clk_gate_en_dsp | fifo_rvalid | dsp_pipe_valid_q | dsp_valid_o);

      prim_clk_gate u_dsp_clk_gate (
        .clk_i     (dsp_clk_i),
        .en_i      (dsp_clk_active),
        .test_en_i (test_en_i),
        .clk_o     (dsp_clk_gated)
      );

      // --------------------------------------------------------------------
      // Small DSP algorithm
      // --------------------------------------------------------------------
      logic signed [15:0] sample_d;
      logic signed [15:0] coeff_d;
      logic signed [63:0] sample_ext;
      logic signed [63:0] coeff_ext;
      logic signed [63:0] gain_ext;
      logic signed [63:0] raw_result_d;
      logic signed [63:0] raw_result_q;
      logic signed [31:0] clipped_result_d;
      logic               overflow_d;
      logic               above_threshold_d;
      logic               dsp_saturate_q;
      logic [31:0]        dsp_threshold_q;

      assign sample_d   = fifo_rdata[31:16];
      assign coeff_d    = fifo_rdata[15:0];
      assign sample_ext = {{{{48{{sample_d[15]}}}}, sample_d}};
      assign coeff_ext  = {{{{48{{coeff_d[15]}}}}, coeff_d}};
      assign gain_ext   = {{{{48{{gain_dsp_q[15]}}}}, gain_dsp_q}};

      assign dsp_out_ready  = !dsp_valid_o | dsp_ready_i;
      assign dsp_pipe_ready = !dsp_pipe_valid_q | dsp_out_ready;

      always_comb begin
        unique case (dsp_op)
          2'd1: raw_result_d = (sample_ext >= coeff_ext) ? sample_ext - coeff_ext : coeff_ext - sample_ext;
          2'd2: raw_result_d = (sample_ext * sample_ext) + (coeff_ext * coeff_ext);
          default: raw_result_d = (sample_ext * coeff_ext) + gain_ext;
        endcase

        overflow_d = (raw_result_q > I32_MAX) | (raw_result_q < I32_MIN);
        if (dsp_saturate_q && raw_result_q > I32_MAX) begin
          clipped_result_d = 32'sh7fff_ffff;
        end else if (dsp_saturate_q && raw_result_q < I32_MIN) begin
          clipped_result_d = -32'sh8000_0000;
        end else begin
          clipped_result_d = raw_result_q[31:0];
        end
        above_threshold_d = $unsigned(clipped_result_d) > dsp_threshold_q;
      end

      always_ff @(posedge dsp_clk_i or negedge dsp_rst_ni) begin
        if (!dsp_rst_ni) begin
          raw_result_q         <= '0;
          dsp_saturate_q       <= 1'b0;
          dsp_threshold_q      <= '0;
          dsp_pipe_valid_q     <= 1'b0;
          dsp_valid_o          <= 1'b0;
          dsp_result_o         <= '0;
          dsp_above_threshold_o <= 1'b0;
          dsp_overflow_o       <= 1'b0;
        end else if (soft_reset_dsp) begin
          raw_result_q         <= '0;
          dsp_saturate_q       <= 1'b0;
          dsp_threshold_q      <= '0;
          dsp_pipe_valid_q     <= 1'b0;
          dsp_valid_o          <= 1'b0;
          dsp_result_o         <= '0;
          dsp_above_threshold_o <= 1'b0;
          dsp_overflow_o       <= 1'b0;
        end else begin
          if (dsp_out_ready) begin
            dsp_valid_o <= dsp_pipe_valid_q;
            if (dsp_pipe_valid_q) begin
              dsp_result_o          <= clipped_result_d;
              dsp_above_threshold_o <= above_threshold_d;
              dsp_overflow_o        <= overflow_d;
            end
          end

          if (dsp_pipe_ready) begin
            dsp_pipe_valid_q <= fifo_rready;
            if (fifo_rready) begin
              raw_result_q    <= raw_result_d;
              dsp_saturate_q  <= dsp_saturate;
              dsp_threshold_q <= dsp_threshold;
            end
          end
        end
      end

      // --------------------------------------------------------------------
      // HW -> register status/result
      // --------------------------------------------------------------------
      logic cfg_busy;
      logic cfg_overflow;

      prim_flop_2sync #(.Width(1), .ResetValue(1'b0)) u_busy_cfg_sync (
        .clk_i  (cfg_clk_i),
        .rst_ni (cfg_rst_ni),
        .d_i    (dsp_valid_o),
        .q_o    (cfg_busy)
      );

      prim_flop_2sync #(.Width(1), .ResetValue(1'b0)) u_overflow_cfg_sync (
        .clk_i  (cfg_clk_i),
        .rst_ni (cfg_rst_ni),
        .d_i    (dsp_overflow_o),
        .q_o    (cfg_overflow)
      );

      assign cfg_hw2reg_o.cfg_status.busy.d     = cfg_busy;
      assign cfg_hw2reg_o.cfg_status.overflow.d = cfg_overflow;

      assign dsp_hw2reg_o.result.d                     = dsp_result_o;
      assign dsp_hw2reg_o.dsp_status.valid.d           = dsp_valid_o;
      assign dsp_hw2reg_o.dsp_status.above_threshold.d = dsp_above_threshold_o;
      assign dsp_hw2reg_o.dsp_status.fifo_empty.d      = ~fifo_rvalid;
      assign dsp_hw2reg_o.dsp_status.overflow.d        = dsp_overflow_o;

      // Debug visibility and lint quieting for intentionally unused scaffold nets.
      logic unused_debug;
      assign unused_debug = ^{{fifo_wdepth, fifo_rdepth, dsp_clk_gated}};

    endmodule
    """)




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
    parser.add_argument("--top", help="Top name for N-clock scaffold generation.")
    parser.add_argument("--hjson-file", dest="hjson_path")
    parser.add_argument("--interface", dest="itf", required=True)
    parser.add_argument("--output-dir", dest="outdir", default=".")
    parser.add_argument("-f", "--force", action="store_true", help="overwrite existing files")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Run the RTL stub generator."""

    try:
        args = parse_args(argv)
        clocks = clock_config()
        if clocks.multiclock:
            top, out = (args.top or "").strip(), Path(args.outdir)
            if not top:
                raise ValueError("--top is required when N_CLOCKS > 1")
            ensure_dir(out)
            safe_write_file(out / f"{top}_core.sv", render_nclock_core(top), overwrite=args.force)
            from .top_from_core import write_top_from_core
            write_top_from_core(top, out, args.itf, force=args.force, clocks=clocks)
        else:
            if not args.hjson_path:
                raise ValueError("--hjson-file is required when N_CLOCKS = 1")
            generate_rtl_stubs(args.hjson_path, args.itf, args.outdir, force=args.force)
        return 0
    except Exception as err:
        print(colorize(f"Error: {err}"), file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
