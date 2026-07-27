"""Generate decomposed multi-clock IP scaffolds for FlexSoC.

The multi-clock flow mirrors the single-clock flow:

* hjson_multi creates one HJSON file per register domain.
* reg_multi/doc_multi run regtool on only the selected or changed regmaps.
* rtl_stub_multi creates an editable core and a wrapper from the core ports.
* top_from_core_multi refreshes only the wrapper after the core signature changes.
* setup_model_multi writes the reference model and generated vector tests.
* setup_tb_multi/setup_cocotb_multi write verification scaffolds that consume vectors.
"""

from __future__ import annotations

import argparse
import re
from dataclasses import dataclass
from pathlib import Path
from textwrap import dedent


# ---------------------------------------------------------------------------
# Defaults and small helpers
# ---------------------------------------------------------------------------

DEFAULT_DOMAINS = ("cfg", "rx", "dsp")
DEFAULT_REGMAPS = ("cfg", "dsp")
REG_PORTS = {"cfg_reg2hw_i", "cfg_hw2reg_o", "dsp_reg2hw_i", "dsp_hw2reg_o"}


@dataclass(frozen=True)
class Port:
    """One parsed SystemVerilog module port declaration."""

    direction: str
    name: str
    declaration: str


def csv(value: str | None, default: tuple[str, ...]) -> tuple[str, ...]:
    """Parse comma-separated values while preserving a sane default."""

    items = tuple(item.strip() for item in (value or "").split(",") if item.strip())
    return items or default


def write_file(path: Path, text: str, force: bool) -> bool:
    """Write one generated file unless it already exists and force is false."""

    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists() and not force:
        print(f"skip {path} (exists; use --force to overwrite)")
        return False
    path.write_text(text.rstrip() + "\n", encoding="utf-8")
    print(path)
    return True


def snake(name: str) -> str:
    """Normalize names to lower-case register/member style."""

    return name.strip().lower()


# ---------------------------------------------------------------------------
# HJSON generation
# ---------------------------------------------------------------------------

def cfg_hjson(top: str) -> str:
    """Render the cfg-domain HJSON regmap."""

    name = f"{top}_cfg"
    return dedent(f"""\
    {{
      name:               "{name}",
      human_name:         "{name}",
      one_line_desc:      "Cfg-domain controls for the generated multi-clock IP.",
      one_paragraph_desc: "Global control and cfg-domain status registers for the generated multi-clock scaffold.",
      cip_id:             "1",
      design_spec:        "",
      dv_doc:             "",
      hw_checklist:       "",
      sw_checklist:       "",
      revisions: [{{
        version:            "1.0.0",
        life_stage:         "L0",
        design_stage:       "D0",
        verification_stage: "V0",
        commit_id:          "",
        notes:              "Generated multi-clock cfg regmap."
      }}],
      clocking: [{{ clock: "clk_i", reset: "rst_ni" }}],
      bus_interfaces: [{{ protocol: "tlul", direction: "device" }}],
      regwidth: "32",
      registers: [
        {{
          name: "CTRL",
          desc: "Global control written from the cfg clock domain.",
          swaccess: "rw",
          hwaccess: "hro",
          fields: [
            {{ bits: "0", name: "ENABLE", desc: "Enable RX input and DSP processing." }},
            {{ bits: "1", name: "SOFT_RESET", desc: "Synchronous datapath clear request." }},
            {{ bits: "2", name: "CLK_GATE_EN", desc: "Allow the DSP clock gate to close when idle." }}
          ]
        }},
        {{
          name: "GAIN",
          desc: "Signed Q1.15 gain added by the DSP pipeline. Update while CTRL.ENABLE is low.",
          swaccess: "rw",
          hwaccess: "hro",
          fields: [{{ bits: "15:0", name: "VALUE", desc: "DSP gain coefficient." }}]
        }},
        {{
          name: "CFG_STATUS",
          desc: "Cfg-domain view of datapath status synchronized back from the DSP domain.",
          swaccess: "ro",
          hwaccess: "hrw",
          hwext: "true",
          fields: [
            {{ bits: "0", name: "BUSY", desc: "The DSP pipeline currently owns an output sample." }},
            {{ bits: "1", name: "OVERFLOW", desc: "The latest result overflowed or saturated." }}
          ]
        }}
      ]
    }}
    """)


def dsp_hjson(top: str) -> str:
    """Render the dsp-domain HJSON regmap."""

    name = f"{top}_dsp"
    return dedent(f"""\
    {{
      name:               "{name}",
      human_name:         "{name}",
      one_line_desc:      "DSP-domain controls and status for the generated multi-clock IP.",
      one_paragraph_desc: "Algorithm selection, threshold, result and live DSP status registers for the generated multi-clock scaffold.",
      cip_id:             "1",
      design_spec:        "",
      dv_doc:             "",
      hw_checklist:       "",
      sw_checklist:       "",
      revisions: [{{
        version:            "1.0.0",
        life_stage:         "L0",
        design_stage:       "D0",
        verification_stage: "V0",
        commit_id:          "",
        notes:              "Generated multi-clock dsp regmap."
      }}],
      clocking: [{{ clock: "clk_i", reset: "rst_ni" }}],
      bus_interfaces: [{{ protocol: "tlul", direction: "device" }}],
      regwidth: "32",
      registers: [
        {{
          name: "DSP_CTRL",
          desc: "DSP-domain algorithm control.",
          swaccess: "rw",
          hwaccess: "hro",
          fields: [
            {{ bits: "1:0", name: "OP", desc: "0=MAC plus gain, 1=absolute difference, 2=energy estimate." }},
            {{ bits: "2", name: "SATURATE", desc: "Clamp overflowing results to signed 32-bit limits." }}
          ]
        }},
        {{
          name: "THRESHOLD",
          desc: "Unsigned threshold compared with the DSP result.",
          swaccess: "rw",
          hwaccess: "hro",
          fields: [{{ bits: "31:0", name: "VALUE", desc: "Result threshold." }}]
        }},
        {{
          name: "RESULT",
          desc: "Latest signed DSP result.",
          swaccess: "ro",
          hwaccess: "hrw",
          hwext: "true",
          fields: [{{ bits: "31:0", name: "VALUE", desc: "Latest output result." }}]
        }},
        {{
          name: "DSP_STATUS",
          desc: "DSP-domain live status.",
          swaccess: "ro",
          hwaccess: "hrw",
          hwext: "true",
          fields: [
            {{ bits: "0", name: "VALID", desc: "RESULT contains a valid sample." }},
            {{ bits: "1", name: "ABOVE_THRESHOLD", desc: "RESULT is greater than THRESHOLD." }},
            {{ bits: "2", name: "FIFO_EMPTY", desc: "RX-to-DSP FIFO has no readable payload." }},
            {{ bits: "3", name: "OVERFLOW", desc: "The latest operation overflowed before saturation." }}
          ]
        }}
      ]
    }}
    """)


def generic_hjson(top: str, regmap: str) -> str:
    """Render a small generic HJSON for an extra domain regmap."""

    name = f"{top}_{regmap}"
    return dedent(f"""\
    {{
      name:               "{name}",
      human_name:         "{name}",
      one_line_desc:      "Generated {regmap}-domain control/status registers.",
      one_paragraph_desc: "Starter control/status map for a generated multi-clock domain.",
      cip_id:             "1",
      design_spec:        "",
      dv_doc:             "",
      hw_checklist:       "",
      sw_checklist:       "",
      revisions: [{{
        version:            "1.0.0",
        life_stage:         "L0",
        design_stage:       "D0",
        verification_stage: "V0",
        commit_id:          "",
        notes:              "Generated multi-clock domain regmap."
      }}],
      clocking: [{{ clock: "clk_i", reset: "rst_ni" }}],
      bus_interfaces: [{{ protocol: "tlul", direction: "device" }}],
      regwidth: "32",
      registers: [
        {{
          name: "CTRL",
          desc: "Domain control.",
          swaccess: "rw",
          hwaccess: "hro",
          fields: [{{ bits: "0", name: "ENABLE", desc: "Enable this domain." }}]
        }},
        {{
          name: "STATUS",
          desc: "Domain status.",
          swaccess: "ro",
          hwaccess: "hrw",
          hwext: "true",
          fields: [{{ bits: "0", name: "BUSY", desc: "Domain busy." }}]
        }}
      ]
    }}
    """)


def hjson_text(top: str, regmap: str) -> str:
    """Render one multi-clock regmap by short name."""

    if regmap == "cfg":
        return cfg_hjson(top)
    if regmap == "dsp":
        return dsp_hjson(top)
    return generic_hjson(top, regmap)


# ---------------------------------------------------------------------------
# RTL generation
# ---------------------------------------------------------------------------

def core_text(top: str) -> str:
    """Render the editable multi-clock core stub."""

    return dedent(f"""\
    // Editable multi-clock RTL core for {top}.
    //
    // User edit point:
    //   Keep this file as the main design surface. After changing ports, run
    //   `fx top_from_core_multi --force` to refresh rtl/{top}.sv.
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

      assign fifo_wdata  = {{rx_sample_i, rx_coeff_i}};
      assign rx_ready_o  = enable_rx & fifo_wready;
      assign fifo_rready = enable_dsp & fifo_rvalid & (!dsp_valid_o | dsp_ready_i);

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
      assign dsp_clk_active = enable_dsp & (!clk_gate_en_dsp | fifo_rvalid | dsp_valid_o);

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
      logic signed [63:0] raw_result;
      logic signed [31:0] clipped_result;
      logic               overflow_d;
      logic               above_threshold_d;

      assign sample_d   = fifo_rdata[31:16];
      assign coeff_d    = fifo_rdata[15:0];
      assign sample_ext = {{{{48{{sample_d[15]}}}}, sample_d}};
      assign coeff_ext  = {{{{48{{coeff_d[15]}}}}, coeff_d}};
      assign gain_ext   = {{{{48{{gain_dsp_q[15]}}}}, gain_dsp_q}};

      always_comb begin
        unique case (dsp_op)
          2'd1: raw_result = (sample_ext >= coeff_ext) ? sample_ext - coeff_ext : coeff_ext - sample_ext;
          2'd2: raw_result = (sample_ext * sample_ext) + (coeff_ext * coeff_ext);
          default: raw_result = (sample_ext * coeff_ext) + gain_ext;
        endcase

        overflow_d = (raw_result > I32_MAX) | (raw_result < I32_MIN);
        if (dsp_saturate && raw_result > I32_MAX) begin
          clipped_result = 32'sh7fff_ffff;
        end else if (dsp_saturate && raw_result < I32_MIN) begin
          clipped_result = -32'sh8000_0000;
        end else begin
          clipped_result = raw_result[31:0];
        end
        above_threshold_d = $unsigned(clipped_result) > dsp_threshold;
      end

      always_ff @(posedge dsp_clk_i or negedge dsp_rst_ni) begin
        if (!dsp_rst_ni) begin
          dsp_valid_o           <= 1'b0;
          dsp_result_o          <= '0;
          dsp_above_threshold_o <= 1'b0;
          dsp_overflow_o        <= 1'b0;
        end else if (soft_reset_dsp) begin
          dsp_valid_o           <= 1'b0;
          dsp_result_o          <= '0;
          dsp_above_threshold_o <= 1'b0;
          dsp_overflow_o        <= 1'b0;
        end else if (fifo_rready) begin
          dsp_valid_o           <= 1'b1;
          dsp_result_o          <= clipped_result;
          dsp_above_threshold_o <= above_threshold_d;
          dsp_overflow_o        <= overflow_d;
        end else if (dsp_ready_i) begin
          dsp_valid_o <= 1'b0;
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


def _remove_sv_comments(text: str) -> str:
    """Remove simple SystemVerilog comments before parsing a module header."""

    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    return re.sub(r"//.*", "", text)


def parse_core_ports(top: str, rtl_dir: Path) -> list[Port]:
    """Parse simple one-line ports from rtl/<top>_core.sv."""

    path = rtl_dir / f"{top}_core.sv"
    if not path.exists():
        raise FileNotFoundError(f"missing core RTL: {path}")
    text = _remove_sv_comments(path.read_text(encoding="utf-8"))
    match = re.search(rf"module\s+{re.escape(top)}_core\b.*?\((.*?)\)\s*;", text, flags=re.S)
    if not match:
        raise ValueError(f"could not parse module header in {path}")
    ports: list[Port] = []
    for raw in match.group(1).splitlines():
        line = raw.strip().rstrip(",")
        if not line or not re.match(r"^(input|output|inout)\b", line):
            continue
        name_match = re.search(r"([A-Za-z_][A-Za-z0-9_]*)\s*$", line)
        if not name_match:
            continue
        direction = line.split(None, 1)[0]
        ports.append(Port(direction=direction, name=name_match.group(1), declaration=line))
    return ports


def _port_block(declarations: list[str]) -> str:
    """Format a comma-terminated SystemVerilog port list."""

    return ",\n".join(f"      {decl}" for decl in declarations)


def wrapper_from_core(top: str, rtl_dir: Path) -> str:
    """Render the SoC-facing wrapper from the editable core port list."""

    ports = parse_core_ports(top, rtl_dir)
    exposed = [p for p in ports if p.name not in REG_PORTS]
    declarations = [p.declaration for p in exposed]
    if "devmode_i" not in {p.name for p in exposed}:
        insert_at = 0
        for idx, port in enumerate(exposed):
            if not ("clk" in port.name or "rst" in port.name or port.name == "test_en_i"):
                insert_at = idx
                break
            insert_at = idx + 1
        declarations.insert(insert_at, "input  logic                     devmode_i")
    declarations.extend([
        "input  tlul_pkg::tl_h2d_t        cfg_tl_i",
        "output tlul_pkg::tl_d2h_t        cfg_tl_o",
        "input  tlul_pkg::tl_h2d_t        dsp_tl_i",
        "output tlul_pkg::tl_d2h_t        dsp_tl_o",
    ])

    core_connections: list[str] = []
    for port in ports:
        if port.name == "cfg_reg2hw_i":
            core_connections.append("        .cfg_reg2hw_i          (cfg_reg2hw)")
        elif port.name == "cfg_hw2reg_o":
            core_connections.append("        .cfg_hw2reg_o          (cfg_hw2reg)")
        elif port.name == "dsp_reg2hw_i":
            core_connections.append("        .dsp_reg2hw_i          (dsp_reg2hw)")
        elif port.name == "dsp_hw2reg_o":
            core_connections.append("        .dsp_hw2reg_o          (dsp_hw2reg)")
        else:
            core_connections.append(f"        .{port.name:<22}({port.name})")

    core_connection_block = ",\n".join(core_connections)

    return dedent(f"""\
    // Auto-generated multi-clock wrapper for {top}.
    //
    // User edit point:
    //   Edit rtl/{top}_core.sv, then run `fx top_from_core_multi --force`.
    //   This wrapper exposes core ports, instantiates one TL-UL register window
    //   per regmap, and wires reg2hw/hw2reg structs into the core.

    module {top}
      import {top}_cfg_reg_pkg::*;
      import {top}_dsp_reg_pkg::*;
    (
    {_port_block(declarations)}
    );

      {top}_cfg_reg2hw_t cfg_reg2hw;
      {top}_cfg_hw2reg_t cfg_hw2reg;
      {top}_dsp_reg2hw_t dsp_reg2hw;
      {top}_dsp_hw2reg_t dsp_hw2reg;

      // Cfg-domain register block. Regtool requires local clk_i/rst_ni names
      // inside the generated block; the wrapper maps them to cfg_clk_i/cfg_rst_ni.
      {top}_cfg_reg_top u_cfg_reg_top (
        .clk_i     (cfg_clk_i),
        .rst_ni    (cfg_rst_ni),
        .tl_i      (cfg_tl_i),
        .tl_o      (cfg_tl_o),
        .reg2hw    (cfg_reg2hw),
        .hw2reg    (cfg_hw2reg),
        .devmode_i (devmode_i)
      );

      // DSP-domain register block mapped to dsp_clk_i/dsp_rst_ni.
      {top}_dsp_reg_top u_dsp_reg_top (
        .clk_i     (dsp_clk_i),
        .rst_ni    (dsp_rst_ni),
        .tl_i      (dsp_tl_i),
        .tl_o      (dsp_tl_o),
        .reg2hw    (dsp_reg2hw),
        .hw2reg    (dsp_hw2reg),
        .devmode_i (devmode_i)
      );

      {top}_core u_core (
    {core_connection_block}
      );

    endmodule
    """)


# ---------------------------------------------------------------------------
# Model and vector generation
# ---------------------------------------------------------------------------

def model_text(top: str) -> str:
    """Render the editable Python model/test generator."""

    return dedent(f'''\
    #!/usr/bin/env python3
    """Reference model and vector generator for the {top} multi-clock scaffold.

    Edit the functions in this file as the RTL changes. Running the file rewrites
    tb/tests/<name>/config.regs, data_in.vec and data_out.vec. Simulation and
    cocotb consume only those generated files.
    """

    from __future__ import annotations

    from pathlib import Path

    ROOT = Path(__file__).resolve().parents[1] / "tb" / "tests"
    TESTS = ("mac_smoke", "absdiff", "energy")


    def i16(value: int) -> int:
        """Convert a value to signed 16-bit."""
        value &= 0xFFFF
        return value - 0x10000 if value & 0x8000 else value


    def u32(value: int) -> int:
        """Convert a value to unsigned 32-bit."""
        return value & 0xFFFFFFFF


    def compute(sample: int, coeff: int, gain: int, op: int, saturate: bool) -> tuple[int, bool]:
        """Mirror the default RTL DSP operation for one transaction."""
        sample = i16(sample)
        coeff = i16(coeff)
        gain = i16(gain)
        if op == 1:
            raw = abs(sample - coeff)
        elif op == 2:
            raw = sample * sample + coeff * coeff
        else:
            raw = sample * coeff + gain
        overflow = raw > 0x7FFFFFFF or raw < -0x80000000
        if saturate and raw > 0x7FFFFFFF:
            raw = 0x7FFFFFFF
        elif saturate and raw < -0x80000000:
            raw = -0x80000000
        return u32(raw), overflow


    def write_lines(path: Path, lines: list[str]) -> None:
        """Write a generated test file."""
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("\\n".join(lines) + "\\n", encoding="utf-8")


    def write_test(name: str, cfg: dict[str, int], rows: list[tuple[int, int]], root: str | Path = ROOT) -> None:
        """Generate one multi-clock vector test directory."""
        out = Path(root) / name
        ctrl = cfg.get("ctrl", 0x1)
        gain = cfg.get("gain", 0)
        dsp_ctrl = cfg.get("dsp_ctrl", 0)
        threshold = cfg.get("threshold", 0)
        write_lines(out / "config.regs", [
            "# format: <regmap>.<REG> <VALUE>",
            "# Multi-clock note: write cfg.GAIN while cfg.CTRL.ENABLE is still low.",
            "# The final cfg.CTRL row enables the RX/DSP domains after config is stable.",
            f"cfg.GAIN 0x{{gain & 0xFFFFFFFF:08x}}",
            f"dsp.DSP_CTRL 0x{{dsp_ctrl:08x}}",
            f"dsp.THRESHOLD 0x{{threshold:08x}}",
            f"cfg.CTRL 0x{{ctrl:08x}}",
        ])

        data_in = [
            "# format: <STEP> <SIGNAL> <VALUE>",
            "# STEP is an input transaction index for this multi-clock scaffold.",
        ]
        data_out = [
            "# format: <STEP> <SIGNAL> <VALUE>",
            "# STEP is an output transaction index; async domains are checked by order.",
        ]
        op = dsp_ctrl & 0x3
        saturate = bool(dsp_ctrl & 0x4)
        for step, (sample, coeff) in enumerate(rows):
            data_in += [
                f"{{step}} rx_sample_i 0x{{sample & 0xFFFF:04x}}",
                f"{{step}} rx_coeff_i 0x{{coeff & 0xFFFF:04x}}",
                f"{{step}} rx_valid_i 0x1",
            ]
            result, overflow = compute(sample, coeff, gain, op, saturate)
            data_out += [
                f"{{step}} dsp_result_o 0x{{result:08x}}",
                f"{{step}} dsp_valid_o 0x1",
                f"{{step}} dsp_overflow_o 0x{{int(overflow)}}",
            ]
        write_lines(out / "data_in.vec", data_in)
        write_lines(out / "data_out.vec", data_out)


    def scenario(name: str) -> tuple[dict[str, int], list[tuple[int, int]]]:
        """Return register config and input rows for one named test.

        Add new tests here. Unknown ad-hoc TEST_NAME values fall back to the
        mac_smoke pattern, which makes it easy to create a new folder first and
        then refine the model behavior.
        """
        if name == "absdiff":
            return {{"ctrl": 0x1, "gain": 0, "dsp_ctrl": 0x1, "threshold": 0x4}}, [(9, 4), (-2, 8)]
        if name == "energy":
            return {{"ctrl": 0x1, "gain": 0, "dsp_ctrl": 0x2, "threshold": 0x20}}, [(3, 4), (5, 12)]
        return {{"ctrl": 0x1, "gain": 1, "dsp_ctrl": 0x0, "threshold": 0x10}}, [(3, 4), (7, 2), (-3, 5)]


    def write_named_test(root: str | Path, name: str) -> None:
        """Generate exactly one TEST_NAME folder from scenario()."""
        cfg, rows = scenario(name)
        write_test(name, cfg, rows, root)


    def write_all_tests(root: str | Path = ROOT, tests: list[str] | tuple[str, ...] | None = None) -> None:
        """Generate requested tests, or the full TESTS catalogue when omitted."""
        for name in (tests or TESTS):
            write_named_test(root, name)


    def main() -> int:
        """Command-line entry point used by tests_gen_multi/test_gen_multi."""
        import argparse
        parser = argparse.ArgumentParser(description="Generate multi-clock vector tests from the editable model.")
        parser.add_argument("--tests-dir", default=str(ROOT))
        parser.add_argument("--test", action="append", default=[], help="Generate only this TEST_NAME. May be repeated.")
        parser.add_argument("--list", action="store_true", help="Print the TESTS catalogue and exit.")
        args = parser.parse_args()
        if args.list:
            for test in TESTS:
                print(test)
            return 0
        write_all_tests(args.tests_dir, args.test or None)
        return 0


    if __name__ == "__main__":
        raise SystemExit(main())
    ''')


# ---------------------------------------------------------------------------
# SystemVerilog verification scaffold
# ---------------------------------------------------------------------------

def sv_include_text(top: str) -> str:
    """Render a small include file matching the single-clock TB layout."""

    guard = f"{top.upper()}_MULTICLOCK_TB_INCLUDE_SV".replace("-", "_")
    return dedent(f"""\
    `ifndef {guard}
    `define {guard}

    // Multi-clock TB include hook.
    // The Makefile compiles rtl_common.f and rtl_ip.f explicitly, so this file
    // is intentionally small. Keep local TB typedefs/macros here if needed.

    `endif
    """)



def sv_driver_text(top: str) -> str:
    """Render top-level TL-UL config-driver tasks."""

    return dedent("""\
      // Reset top-level scalar IO and both TL-UL register ports.
      task automatic apply_defaults();
        cfg_tl_i = tlul_pkg::TL_H2D_DEFAULT;
        dsp_tl_i = tlul_pkg::TL_H2D_DEFAULT;
        cfg_tl_i.a_valid = 1'b0;
        dsp_tl_i.a_valid = 1'b0;
        cfg_tl_i.d_ready = 1'b1;
        dsp_tl_i.d_ready = 1'b1;
        rx_valid_i = 1'b0;
        rx_sample_i = '0;
        rx_coeff_i = '0;
        dsp_ready_i = 1'b1;
        test_en_i = 1'b1;
        devmode_i = 1'b1;
      endtask

      // Perform one cfg-domain TL-UL write into the generated cfg regblock.
      task automatic cfg_write(input logic [31:0] addr, input logic [31:0] data);
        @(negedge cfg_clk_i);
        cfg_tl_i = tlul_pkg::TL_H2D_DEFAULT;
        cfg_tl_i.a_valid   = 1'b1;
        cfg_tl_i.a_opcode  = tlul_pkg::PutFullData;
        cfg_tl_i.a_param   = '0;
        cfg_tl_i.a_size    = 3'd2;
        cfg_tl_i.a_source  = '0;
        cfg_tl_i.a_address = addr;
        cfg_tl_i.a_mask    = 4'hf;
        cfg_tl_i.a_data    = data;
        cfg_tl_i.d_ready   = 1'b1;
        do @(posedge cfg_clk_i); while (!cfg_tl_o.a_ready);
        @(negedge cfg_clk_i);
        cfg_tl_i.a_valid = 1'b0;
        do @(posedge cfg_clk_i); while (!cfg_tl_o.d_valid);
        @(negedge cfg_clk_i);
        cfg_tl_i = tlul_pkg::TL_H2D_DEFAULT;
        cfg_tl_i.d_ready = 1'b1;
      endtask

      // Perform one dsp-domain TL-UL write into the generated dsp regblock.
      task automatic dsp_write(input logic [31:0] addr, input logic [31:0] data);
        @(negedge dsp_clk_i);
        dsp_tl_i = tlul_pkg::TL_H2D_DEFAULT;
        dsp_tl_i.a_valid   = 1'b1;
        dsp_tl_i.a_opcode  = tlul_pkg::PutFullData;
        dsp_tl_i.a_param   = '0;
        dsp_tl_i.a_size    = 3'd2;
        dsp_tl_i.a_source  = '0;
        dsp_tl_i.a_address = addr;
        dsp_tl_i.a_mask    = 4'hf;
        dsp_tl_i.a_data    = data;
        dsp_tl_i.d_ready   = 1'b1;
        do @(posedge dsp_clk_i); while (!dsp_tl_o.a_ready);
        @(negedge dsp_clk_i);
        dsp_tl_i.a_valid = 1'b0;
        do @(posedge dsp_clk_i); while (!dsp_tl_o.d_valid);
        @(negedge dsp_clk_i);
        dsp_tl_i = tlul_pkg::TL_H2D_DEFAULT;
        dsp_tl_i.d_ready = 1'b1;
      endtask

      // Apply one generated config register write through the top-level regblocks.
      task automatic apply_reg(input string reg_name, input logic [31:0] value);
        if (reg_name == "cfg.CTRL") begin
          cfg_write(32'h0000_0000, value);
        end else if (reg_name == "cfg.GAIN") begin
          cfg_write(32'h0000_0004, value);
        end else if (reg_name == "dsp.DSP_CTRL") begin
          dsp_write(32'h0000_0000, value);
        end else if (reg_name == "dsp.THRESHOLD") begin
          dsp_write(32'h0000_0004, value);
        end else begin
          $display("[TB][WARN] unknown config register: %s", reg_name);
        end
      endtask

      // Load config.regs. cfg.CTRL should remain the final enable write.
      task automatic load_config(input string path);
        integer fd;
        integer code;
        string reg_name;
        logic [31:0] value;
        string line;
        fd = $fopen(path, "r");
        if (fd == 0) begin
          $display("[TB][ERROR] config file not found: %s", path);
          errors++;
          return;
        end
        while (!$feof(fd)) begin
          line = "";
          void'($fgets(line, fd));
          if (line.len() == 0 || line.substr(0, 0) == "#") continue;
          code = $sscanf(line, "%s %h", reg_name, value);
          if (code == 2) begin
            if (reg_name.len() > 6 && reg_name.substr(0, 5) == "clk_i.") reg_name = reg_name.substr(6, reg_name.len() - 1);
            apply_reg(reg_name, value);
          end
        end
        $fclose(fd);
      endtask
    """)


def sv_vec_driver_text(top: str) -> str:
    """Render top-level input-vector driver tasks."""

    return dedent("""\
      // Push one sample into the RX clock domain.
      task automatic send_sample(input logic signed [15:0] sample, input logic signed [15:0] coeff);
        integer timeout;
        timeout = 0;
        while (!rx_ready_o && timeout < 64) begin
          @(posedge rx_clk_i);
          timeout++;
        end
        if (!rx_ready_o) begin
          $display("[TB][ERROR] rx_ready_o timeout");
          errors++;
          return;
        end
        @(negedge rx_clk_i);
        rx_sample_i = sample;
        rx_coeff_i  = coeff;
        rx_valid_i  = 1'b1;
        @(negedge rx_clk_i);
        rx_valid_i  = 1'b0;
      endtask

      // Drive input transactions from data_in.vec.
      task automatic run_inputs(input string path);
        integer fd;
        integer code;
        integer step;
        string sig;
        logic [31:0] value;
        string line;
        logic signed [15:0] sample;
        logic signed [15:0] coeff;
        sample = '0;
        coeff = '0;
        fd = $fopen(path, "r");
        if (fd == 0) begin
          $display("[TB][ERROR] input file not found: %s", path);
          errors++;
          return;
        end
        while (!$feof(fd)) begin
          line = "";
          void'($fgets(line, fd));
          if (line.len() == 0 || line.substr(0, 0) == "#") continue;
          code = $sscanf(line, "%d %s %h", step, sig, value);
          if (code != 3) continue;
          if (sig == "rx_sample_i") begin
            sample = value[15:0];
          end else if (sig == "rx_coeff_i") begin
            coeff = value[15:0];
          end else if (sig == "rx_valid_i" && value[0]) begin
            send_sample(sample, coeff);
          end
        end
        $fclose(fd);
      endtask
    """)

def sv_monitor_text(top: str) -> str:
    """Render output-vector monitor/checker tasks."""

    return dedent("""\
      // Load expected output transactions by order, not by absolute cycle.
      task automatic load_expected(input string path);
        integer fd;
        integer code;
        integer step;
        string sig;
        logic [31:0] value;
        string line;
        exp_count = 0;
        fd = $fopen(path, "r");
        if (fd == 0) begin
          $display("[TB][ERROR] expected file not found: %s", path);
          errors++;
          return;
        end
        while (!$feof(fd)) begin
          line = "";
          void'($fgets(line, fd));
          if (line.len() == 0 || line.substr(0, 0) == "#") continue;
          code = $sscanf(line, "%d %s %h", step, sig, value);
          if (code == 3 && sig == "dsp_result_o") begin
            exp_result[exp_count] = value;
            exp_overflow[exp_count] = 1'b0;
            exp_count++;
          end else if (code == 3 && sig == "dsp_overflow_o" && exp_count > 0) begin
            exp_overflow[exp_count - 1] = value[0];
          end
        end
        $fclose(fd);
      endtask

      // Compare each output transaction when the DSP domain produces it.
      task automatic check_outputs();
        integer timeout;
        got_count = 0;
        timeout = 0;
        dsp_ready_i = 1'b1;
        while (got_count < exp_count && timeout < 4096) begin
          @(posedge dsp_clk_i);
          if (dsp_valid_o) begin
            if ($unsigned(dsp_result_o) !== exp_result[got_count]) begin
              $display("[TB][ERROR] result[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned(dsp_result_o), exp_result[got_count]);
              errors++;
            end
            if (dsp_overflow_o !== exp_overflow[got_count]) begin
              $display("[TB][ERROR] overflow[%0d] got=%0d exp=%0d", got_count, dsp_overflow_o, exp_overflow[got_count]);
              errors++;
            end
            got_count++;
          end
          timeout++;
        end
        if (got_count != exp_count) begin
          $display("[TB][ERROR] observed %0d/%0d expected outputs", got_count, exp_count);
          errors++;
        end
      endtask
    """)



def sv_tb_text(top: str, testbench: str) -> str:
    """Render a top-level multi-clock SV vector testbench."""

    return dedent(f"""\
    `timescale 1ns/1ps
    `include "include_{top}_tb.sv"

    module {testbench};

      logic cfg_clk_i;
      logic cfg_rst_ni;
      logic rx_clk_i;
      logic rx_rst_ni;
      logic dsp_clk_i;
      logic dsp_rst_ni;
      logic test_en_i;
      logic devmode_i;

      tlul_pkg::tl_h2d_t cfg_tl_i;
      tlul_pkg::tl_d2h_t cfg_tl_o;
      tlul_pkg::tl_h2d_t dsp_tl_i;
      tlul_pkg::tl_d2h_t dsp_tl_o;

      logic rx_valid_i;
      logic rx_ready_o;
      logic signed [15:0] rx_sample_i;
      logic signed [15:0] rx_coeff_i;
      logic dsp_valid_o;
      logic dsp_ready_i;
      logic signed [31:0] dsp_result_o;
      logic dsp_above_threshold_o;
      logic dsp_overflow_o;

      string cfg_path;
      string data_in_path;
      string data_out_path;
      string vcd_path;
      integer errors;

      logic [31:0] exp_result [0:1023];
      logic        exp_overflow [0:1023];
      integer exp_count;
      integer got_count;

      always #5 cfg_clk_i = ~cfg_clk_i;
      always #4 rx_clk_i  = ~rx_clk_i;
      always #3 dsp_clk_i = ~dsp_clk_i;

      {top} u_dut (
        .cfg_clk_i             (cfg_clk_i),
        .cfg_rst_ni            (cfg_rst_ni),
        .rx_clk_i              (rx_clk_i),
        .rx_rst_ni             (rx_rst_ni),
        .dsp_clk_i             (dsp_clk_i),
        .dsp_rst_ni            (dsp_rst_ni),
        .test_en_i             (test_en_i),
        .devmode_i             (devmode_i),
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

      // Verification helpers are split like the single-clock scaffold.
      `include "drivers/{top}_tlul_driver.svh"
      `include "drivers/{top}_vec_monitor.svh"
      `include "drivers/{top}_vec_driver.svh"

      initial begin
        errors = 0;
        cfg_clk_i = 1'b0;
        rx_clk_i = 1'b0;
        dsp_clk_i = 1'b0;
        cfg_rst_ni = 1'b0;
        rx_rst_ni = 1'b0;
        dsp_rst_ni = 1'b0;
        apply_defaults();

        if (!$value$plusargs("CFG=%s", cfg_path)) cfg_path = "tb/tests/mac_smoke/config.regs";
        if (!$value$plusargs("DATA_IN=%s", data_in_path)) data_in_path = "tb/tests/mac_smoke/data_in.vec";
        if (!$value$plusargs("DATA_OUT=%s", data_out_path)) data_out_path = "tb/tests/mac_smoke/data_out.vec";
        if (!$value$plusargs("VCD=%s", vcd_path)) vcd_path = "{testbench}.vcd";
        if (vcd_path != "") begin
          $display("[TB] dumpfile = %s", vcd_path);
          $dumpfile(vcd_path);
          $dumpvars(0, {testbench});
        end

        repeat (5) @(posedge cfg_clk_i);
        cfg_rst_ni = 1'b1;
        rx_rst_ni = 1'b1;
        dsp_rst_ni = 1'b1;
        repeat (8) @(posedge cfg_clk_i);

        load_config(cfg_path);
        load_expected(data_out_path);
        // Let cfg->rx/dsp synchronizers and gain sampling settle before traffic.
        repeat (8) @(posedge dsp_clk_i);
        fork
          run_inputs(data_in_path);
          check_outputs();
        join

        repeat (10) @(posedge dsp_clk_i);
        if (errors == 0) begin
          $display("[TB] PASS");
          $finish;
        end else begin
          $display("[TB] FAIL errors=%0d", errors);
          $fatal(1);
        end
      end

    endmodule
    """)

# ---------------------------------------------------------------------------
# cocotb scaffold

# ---------------------------------------------------------------------------
# cocotb scaffold
# ---------------------------------------------------------------------------


def cocotb_sv_text(top: str) -> str:
    """Render a cocotb wrapper with scalar TL-UL proxy signals.

    Cocotb/Verilator exposes packed structs as LogicArrayObject values, so Python
    cannot access cfg_tl_i.d_ready directly.  The wrapper keeps the real DUT
    connected to TL-UL structs, but exposes scalar proxy signals for cocotb.
    """

    return dedent(f"""\
    `timescale 1ns/1ps

    module {top}_cocotb_tb;
      logic cfg_clk_i;
      logic cfg_rst_ni;
      logic rx_clk_i;
      logic rx_rst_ni;
      logic dsp_clk_i;
      logic dsp_rst_ni;
      logic test_en_i;
      logic devmode_i;

      tlul_pkg::tl_h2d_t cfg_tl_i;
      tlul_pkg::tl_d2h_t cfg_tl_o;
      tlul_pkg::tl_h2d_t dsp_tl_i;
      tlul_pkg::tl_d2h_t dsp_tl_o;

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

      always_comb begin
        cfg_tl_i = tlul_pkg::TL_H2D_DEFAULT;
        cfg_tl_i.a_valid   = cfg_a_valid;
        cfg_tl_i.a_opcode  = tlul_pkg::tl_a_op_e'(cfg_a_opcode);
        cfg_tl_i.a_param   = cfg_a_param;
        cfg_tl_i.a_size    = cfg_a_size;
        cfg_tl_i.a_source  = cfg_a_source;
        cfg_tl_i.a_address = cfg_a_address;
        cfg_tl_i.a_mask    = cfg_a_mask;
        cfg_tl_i.a_data    = cfg_a_data;
        cfg_tl_i.d_ready   = cfg_d_ready;

        dsp_tl_i = tlul_pkg::TL_H2D_DEFAULT;
        dsp_tl_i.a_valid   = dsp_a_valid;
        dsp_tl_i.a_opcode  = tlul_pkg::tl_a_op_e'(dsp_a_opcode);
        dsp_tl_i.a_param   = dsp_a_param;
        dsp_tl_i.a_size    = dsp_a_size;
        dsp_tl_i.a_source  = dsp_a_source;
        dsp_tl_i.a_address = dsp_a_address;
        dsp_tl_i.a_mask    = dsp_a_mask;
        dsp_tl_i.a_data    = dsp_a_data;
        dsp_tl_i.d_ready   = dsp_d_ready;
      end

      assign cfg_a_ready = cfg_tl_o.a_ready;
      assign cfg_d_valid = cfg_tl_o.d_valid;
      assign cfg_d_data  = cfg_tl_o.d_data;
      assign cfg_d_error = cfg_tl_o.d_error;

      assign dsp_a_ready = dsp_tl_o.a_ready;
      assign dsp_d_valid = dsp_tl_o.d_valid;
      assign dsp_d_data  = dsp_tl_o.d_data;
      assign dsp_d_error = dsp_tl_o.d_error;

      {top} u_dut (
        .cfg_clk_i             (cfg_clk_i),
        .cfg_rst_ni            (cfg_rst_ni),
        .rx_clk_i              (rx_clk_i),
        .rx_rst_ni             (rx_rst_ni),
        .dsp_clk_i             (dsp_clk_i),
        .dsp_rst_ni            (dsp_rst_ni),
        .test_en_i             (test_en_i),
        .devmode_i             (devmode_i),
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
    """Render a cocotb Makefile for the multi-clock wrapper."""

    return dedent(f"""\
    SIM ?= verilator
    TOPLEVEL_LANG ?= verilog
    TOPLEVEL = {top}_cocotb_tb
    MODULE = {top}_multiclock_test
    EXTRA_ARGS += -f $(PWD)/../../rtl/rtl_common.f
    EXTRA_ARGS += -f $(PWD)/../../rtl/rtl_ip.f
    VERILOG_SOURCES += $(PWD)/{top}_cocotb_tb.sv
    EXTRA_ARGS += --top-module $(TOPLEVEL)
    EXTRA_ARGS += -Wno-fatal
    export TEST_NAME ?= mac_smoke
    export CFG ?= ../tests/$(TEST_NAME)/config.regs
    export DATA_IN ?= ../tests/$(TEST_NAME)/data_in.vec
    export DATA_OUT ?= ../tests/$(TEST_NAME)/data_out.vec
    include $(shell cocotb-config --makefiles)/Makefile.sim
    """)



def cocotb_reg_driver_py_text(top: str) -> str:
    """Render cocotb TL-UL register-driver helpers."""

    return dedent("""\
    from __future__ import annotations

    from pathlib import Path

    from cocotb.triggers import FallingEdge, RisingEdge


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
        dut.devmode_i.value = 1


    async def reset(dut):
        "Apply asynchronous resets to all scaffold clocks."
        dut.cfg_rst_ni.value = 0
        dut.rx_rst_ni.value = 0
        dut.dsp_rst_ni.value = 0
        for _ in range(5):
            await RisingEdge(dut.cfg_clk_i)
        dut.cfg_rst_ni.value = 1
        dut.rx_rst_ni.value = 1
        dut.dsp_rst_ni.value = 1
        for _ in range(8):
            await RisingEdge(dut.cfg_clk_i)


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
        while not bool(getattr(dut, f"{domain}_a_ready").value):
            await RisingEdge(clk)
        await FallingEdge(clk)
        getattr(dut, f"{domain}_a_valid").value = 0
        while not bool(getattr(dut, f"{domain}_d_valid").value):
            await RisingEdge(clk)
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
        while not bool(getattr(dut, f"{domain}_a_ready").value):
            await RisingEdge(clk)
        await FallingEdge(clk)
        getattr(dut, f"{domain}_a_valid").value = 0
        while not bool(getattr(dut, f"{domain}_d_valid").value):
            await RisingEdge(clk)
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


    async def apply_reg(dut, name: str, value: int):
        "Apply one config.regs row through the real top-level regblocks."
        domain, addr = _decode_reg(name)
        clk = dut.cfg_clk_i if domain == "cfg" else dut.dsp_clk_i
        await _tlul_write(dut, domain, clk, addr, value)


    async def read_reg(dut, name: str) -> int:
        "Read one register by generated model name, for simple status checks."
        domain, addr = _decode_reg(name)
        clk = dut.cfg_clk_i if domain == "cfg" else dut.dsp_clk_i
        return await _tlul_read(dut, domain, clk, addr)


    async def expect_reg(dut, name: str, expected: int, mask: int = 0xFFFFFFFF):
        "Read one register and assert its masked value."
        got = await read_reg(dut, name)
        if (got & mask) != (expected & mask):
            raise AssertionError(
                f"{name} got=0x{got & mask:08x} exp=0x{expected & mask:08x} mask=0x{mask:08x}"
            )


    async def apply_config(dut, path: str):
        "Apply generated config rows and allow CDC synchronizers to settle."
        for parts in rows(path):
            if len(parts) >= 2:
                await apply_reg(dut, parts[0], int(parts[1], 0))
        for _ in range(8):
            await RisingEdge(dut.dsp_clk_i)
    """)
def cocotb_vec_driver_py_text(top: str) -> str:
    """Render cocotb input-vector driver helpers."""

    return dedent("""\
    from __future__ import annotations

    from cocotb.triggers import FallingEdge, RisingEdge

    from .reg_driver import rows


    async def send_sample(dut, sample: int, coeff: int):
        \"\"\"Send one RX-domain input transaction.\"\"\"
        timeout = 0
        while not bool(dut.rx_ready_o.value) and timeout < 64:
            await RisingEdge(dut.rx_clk_i)
            timeout += 1
        assert bool(dut.rx_ready_o.value), \"rx_ready_o timeout\"
        await FallingEdge(dut.rx_clk_i)
        dut.rx_sample_i.value = sample & 0xFFFF
        dut.rx_coeff_i.value = coeff & 0xFFFF
        dut.rx_valid_i.value = 1
        await FallingEdge(dut.rx_clk_i)
        dut.rx_valid_i.value = 0


    async def drive_inputs(dut, path: str):
        \"\"\"Drive inputs from data_in.vec.\"\"\"
        sample = 0
        coeff = 0
        for parts in rows(path):
            if len(parts) < 3:
                continue
            _, sig, value = parts[:3]
            value = int(value, 0)
            if sig == \"rx_sample_i\":
                sample = value
            elif sig == \"rx_coeff_i\":
                coeff = value
            elif sig == \"rx_valid_i\" and value:
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
                out.append({\"result\": value, \"overflow\": 0})
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
                overflow = int(dut.dsp_overflow_o.value) & 1
                assert result == expected[got][\"result\"], f\"result[{got}] got=0x{result:08x} exp=0x{expected[got]['result']:08x}\"
                assert overflow == expected[got][\"overflow\"], f\"overflow[{got}] got={overflow} exp={expected[got]['overflow']}\"
                got += 1
            timeout += 1
        assert got == len(expected), f\"observed {got}/{len(expected)} expected outputs\"
    """)


def cocotb_py_text(top: str) -> str:
    """Render the small cocotb test entry point."""

    return dedent(f"""\
    \"\"\"cocotb test for the {top} multi-clock scaffold.\"\"\"

    from __future__ import annotations

    import os

    import cocotb
    from cocotb.clock import Clock

    from drivers.reg_driver import apply_config, reset, set_defaults
    from drivers.vec_driver import drive_inputs
    from drivers.vec_monitor import check_outputs, expected_outputs


    @cocotb.test()
    async def vector_test(dut):
        \"\"\"Run one generated vector test selected by TEST_NAME.\"\"\"
        cocotb.start_soon(Clock(dut.cfg_clk_i, 10, units=\"ns\").start())
        cocotb.start_soon(Clock(dut.rx_clk_i, 8, units=\"ns\").start())
        cocotb.start_soon(Clock(dut.dsp_clk_i, 6, units=\"ns\").start())
        set_defaults(dut)
        await reset(dut)

        test_name = os.environ.get(\"TEST_NAME\", \"mac_smoke\")
        cfg = os.environ.get(\"CFG\", f\"../tests/{{test_name}}/config.regs\")
        data_in = os.environ.get(\"DATA_IN\", f\"../tests/{{test_name}}/data_in.vec\")
        data_out = os.environ.get(\"DATA_OUT\", f\"../tests/{{test_name}}/data_out.vec\")
        await apply_config(dut, cfg)
        expected = expected_outputs(data_out)
        checker = cocotb.start_soon(check_outputs(dut, expected))
        await drive_inputs(dut, data_in)
        await checker
    """)

# ---------------------------------------------------------------------------
# SDC and notes

# ---------------------------------------------------------------------------
# SDC and notes
# ---------------------------------------------------------------------------

def sdc_text(top: str, domains: tuple[str, ...]) -> str:
    """Render the canonical IP-level SDC."""

    clocks = "\n".join(
        f"create_clock -name {domain}_clk -period 10.000 [get_ports {domain}_clk_i]"
        for domain in domains
    )
    groups = " ".join(f"-group [get_clocks {domain}_clk]" for domain in domains)
    return dedent(f"""\
    # Canonical IP-level timing constraints for {top}.
    # Review periods, generated clocks, IO delays and CDC exceptions before signoff.

    {clocks}

    # The scaffold assumes independent clock domains until integration proves otherwise.
    set_clock_groups -asynchronous {groups}

    # Gate checks are part of timing review for the DSP clock-gating intent.
    set_clock_gating_check -setup 0.050 -hold 0.050 [get_clocks dsp_clk]

    # The RX-to-DSP FIFO is the intentional multi-bit CDC boundary.
    set_false_path -through [get_cells -hierarchical *u_rx_to_dsp_fifo*]

    # Placeholder IO budgets. Replace with the real integration envelope.
    set_input_delay  1.000 -clock rx_clk  [remove_from_collection [all_inputs] [get_ports *clk_i]]
    set_output_delay 1.000 -clock dsp_clk [all_outputs]
    """)


def notes_text(top: str, domains: tuple[str, ...], regmaps: tuple[str, ...]) -> str:
    """Render the generated scaffold README."""

    return dedent(f"""\
    # {top} multi-clock scaffold

    Generated by the decomposed FlexSoC multi-clock flow.

    ## Generated stages

    ```bash
    fx hjson_multi --force
    fx reg_multi doc_multi --force
    fx rtl_stub_multi --force
    fx top_from_core_multi --force
    fx flist lint --force
    fx setup_model_multi --force
    fx setup_tb_multi setup_cocotb_multi --force
    ```

    ## Domains

    {', '.join(domains)}

    ## Regmaps

    {', '.join(regmaps)}

    ## User edit points

    - Edit `data/{top}_cfg.hjson` and `data/{top}_dsp.hjson` for software-visible registers.
    - Run `fx reg_multi doc_multi --set REGMAP=<name>` after one regmap changes.
    - Run `fx rtl_stub_multi --force` when generated RTL must be recreated from existing reg RTL.
    - Edit `rtl/{top}_core.sv` for the design logic.
    - Run `fx top_from_core_multi --force` after changing core ports.
    - Edit `model/model_{top}_multiclock.py`, then run `fx tests_gen_multi` or `fx test_gen_multi --set TEST_NAME=<name>` to regenerate vectors.
    - Edit `tb/drivers/{top}_tlul_driver.svh` for top-level TL-UL config writes.
    - Edit `tb/drivers/{top}_vec_driver.svh` and `tb/drivers/{top}_vec_monitor.svh` for SV verification behavior.
    - Edit `tb/cocotb/drivers/reg_driver.py`, `vec_driver.py`, and `vec_monitor.py` for cocotb behavior.
    """)


# ---------------------------------------------------------------------------
# Emission actions
# ---------------------------------------------------------------------------

def emit_hjson(args: argparse.Namespace, regmaps: tuple[str, ...]) -> None:
    """Generate selected multi-clock HJSON regmaps."""

    for regmap in regmaps:
        write_file(args.data_dir / f"{args.top}_{regmap}.hjson", hjson_text(args.top, regmap), args.force)


def emit_rtl(args: argparse.Namespace) -> None:
    """Generate the editable core and wrapper from that core."""

    write_file(args.rtl_dir / f"{args.top}_core.sv", core_text(args.top), args.force)
    write_file(args.rtl_dir / f"{args.top}.sv", wrapper_from_core(args.top, args.rtl_dir), args.force)


def emit_top(args: argparse.Namespace) -> None:
    """Refresh only the top wrapper from the edited core."""

    write_file(args.rtl_dir / f"{args.top}.sv", wrapper_from_core(args.top, args.rtl_dir), args.force)


def emit_model(args: argparse.Namespace) -> None:
    """Generate the editable Python model/test generator."""

    path = args.model_dir / f"model_{args.top}_multiclock.py"
    wrote = write_file(path, model_text(args.top), args.force)
    if wrote:
        path.chmod(0o755)



def emit_tb(args: argparse.Namespace) -> None:
    """Generate the split SystemVerilog multi-clock top-level testbench scaffold."""

    drivers = args.tb_dir / "drivers"
    for stale in (
        args.tb_dir / f"{args.top}_vec_driver.svh",
        args.tb_dir / f"{args.top}_vec_monitor.svh",
    ):
        if stale.exists():
            stale.unlink()
            print(f"removed stale {stale}")
    write_file(args.tb_dir / f"include_{args.top}_tb.sv", sv_include_text(args.top), args.force)
    write_file(drivers / f"{args.top}_tlul_driver.svh", sv_driver_text(args.top), args.force)
    write_file(drivers / f"{args.top}_vec_driver.svh", sv_vec_driver_text(args.top), args.force)
    write_file(drivers / f"{args.top}_vec_monitor.svh", sv_monitor_text(args.top), args.force)
    write_file(args.tb_dir / f"{args.testbench}.sv", sv_tb_text(args.top, args.testbench), args.force)


def emit_cocotb(args: argparse.Namespace) -> None:
    """Generate the split cocotb multi-clock top-level scaffold."""

    out = args.tb_dir / "cocotb"
    drivers = out / "drivers"
    for stale in (
        out / "multiclock_driver.py",
        out / "multiclock_monitor.py",
    ):
        if stale.exists():
            stale.unlink()
            print(f"removed stale {stale}")
    write_file(out / "Makefile", cocotb_makefile_text(args.top, args.rtl_dir), args.force)
    write_file(out / f"{args.top}_cocotb_tb.sv", cocotb_sv_text(args.top), args.force)
    write_file(drivers / "__init__.py", "", True)
    write_file(drivers / "reg_driver.py", cocotb_reg_driver_py_text(args.top), args.force)
    write_file(drivers / "vec_driver.py", cocotb_vec_driver_py_text(args.top), args.force)
    write_file(drivers / "vec_monitor.py", cocotb_monitor_py_text(args.top), args.force)
    write_file(out / f"{args.top}_multiclock_test.py", cocotb_py_text(args.top), args.force)

def emit_sdc(args: argparse.Namespace, domains: tuple[str, ...]) -> None:
    """Generate the IP-level multi-clock SDC."""

    write_file(args.constraints_dir / f"{args.top}.sdc", sdc_text(args.top, domains), args.force)


def emit_notes(args: argparse.Namespace, domains: tuple[str, ...], regmaps: tuple[str, ...]) -> None:
    """Generate the local multi-clock README."""

    write_file(args.run_dir / "multiclock_readme.md", notes_text(args.top, domains, regmaps), args.force)


def remove_stale(args: argparse.Namespace) -> None:
    """Remove stale files from older combined multi-clock scaffold versions."""

    if not args.force:
        return
    for old in (
        args.rtl_dir / f"{args.top}_core_multiclock.sv",
        args.signoff_dir / f"{args.top}_multiclock.sdc",
        args.rtl_dir / f"{args.top}_multiclock.sdc",
    ):
        if old.exists():
            old.unlink()
            print(f"removed stale {old}")


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse command-line arguments."""

    parser = argparse.ArgumentParser(description="Generate decomposed multi-clock IP scaffolds")
    parser.add_argument("--top", required=True)
    parser.add_argument("--run-dir", type=Path, required=True)
    parser.add_argument("--rtl-dir", type=Path, required=True)
    parser.add_argument("--data-dir", type=Path, required=True)
    parser.add_argument("--signoff-dir", type=Path, required=True)
    parser.add_argument("--constraints-dir", type=Path, required=True)
    parser.add_argument("--model-dir", type=Path, required=True)
    parser.add_argument("--tb-dir", type=Path, required=True)
    parser.add_argument("--testbench", default="test_tb")
    parser.add_argument("--domains", default=",".join(DEFAULT_DOMAINS))
    parser.add_argument("--regmaps", default=",".join(DEFAULT_REGMAPS))
    parser.add_argument("--emit", action="append", choices=("all", "hjson", "rtl", "top", "model", "tb", "cocotb", "sdc", "notes"), default=[])
    parser.add_argument("--force", action="store_true")
    return parser.parse_args(argv)






def main(argv: list[str] | None = None) -> int:
    """Run the selected multi-clock scaffold emission actions."""

    args = parse_args(argv)
    domains = csv(args.domains, DEFAULT_DOMAINS)
    regmaps = csv(args.regmaps, DEFAULT_REGMAPS)
    emits = set(args.emit or ["all"])
    if "all" in emits:
        emits = {"hjson", "rtl", "model", "tb", "cocotb", "sdc", "notes"}

    remove_stale(args)
    if "hjson" in emits:
        emit_hjson(args, regmaps)
    if "rtl" in emits:
        emit_rtl(args)
    if "top" in emits:
        emit_top(args)
    if "model" in emits:
        emit_model(args)
    if "tb" in emits:
        emit_tb(args)
    if "cocotb" in emits:
        emit_cocotb(args)
    if "sdc" in emits:
        emit_sdc(args, domains)
    if "notes" in emits:
        emit_notes(args, domains, regmaps)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
