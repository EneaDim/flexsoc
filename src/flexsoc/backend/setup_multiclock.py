"""Generate a coherent multi-clock IP scaffold.

The scaffold follows the same idea as the normal ``hjson`` + ``rtl_stub`` flow,
but it is explicit about clock domains, multiple regmaps, clock gating and CDC.
It creates editable starter RTL, reggen inputs, an IP-level SDC and notes for SoC
integration. It does not pretend to close CDC or timing automatically: the intent
is visible in the generated files and must be reviewed by the designer.
"""

from __future__ import annotations

import argparse
from pathlib import Path
from textwrap import dedent


DEFAULT_DOMAINS = ("cfg", "rx", "dsp")
DEFAULT_REGMAPS = ("cfg", "dsp")


def csv(value: str | None, default: tuple[str, ...]) -> tuple[str, ...]:
    """Parse a comma-separated option, falling back to a default tuple."""

    items = tuple(item.strip() for item in (value or "").split(",") if item.strip())
    return items or default


def clk(domain: str) -> str:
    """Return the clock port name for one domain."""

    return f"{domain}_clk_i"


def rst(domain: str) -> str:
    """Return the active-low reset port name for one domain."""

    return f"{domain}_rst_ni"


def write_file(path: Path, text: str, force: bool) -> bool:
    """Write one generated file, respecting --force."""

    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists() and not force:
        return False
    path.write_text(text.rstrip() + "\n", encoding="utf-8")
    return True


def cfg_hjson(top: str) -> str:
    """Render the cfg-domain regmap used by the generated RTL stub."""

    name = f"{top}_cfg"
    return dedent(f"""\
    {{
      name: "{name}"
      clock_primary: "cfg_clk_i"
      reset_primary: "cfg_rst_ni"
      bus_interfaces: [ {{ protocol: "tlul", direction: "device" }} ]
      registers: [
        {{ name: CTRL
          desc: "Global control written from the cfg clock domain."
          swaccess: "rw"
          hwaccess: "hro"
          fields: [
            {{ bits: "0", name: enable, desc: "Enable RX input and DSP processing." }}
            {{ bits: "1", name: soft_reset, desc: "Synchronous datapath clear request." }}
            {{ bits: "2", name: clk_gate_en, desc: "Allow the DSP clock gate to close when idle." }}
          ]
        }}
        {{ name: GAIN
          desc: "Signed Q1.15 gain added by the DSP pipeline. Update while CTRL.enable is low."
          swaccess: "rw"
          hwaccess: "hro"
          fields: [ {{ bits: "15:0", name: value, desc: "DSP gain coefficient." }} ]
        }}
        {{ name: CFG_STATUS
          desc: "Cfg-domain view of status synchronized back from the datapath."
          swaccess: "ro"
          hwaccess: "hrw"
          hwext: "true"
          fields: [
            {{ bits: "0", name: busy, desc: "The DSP pipeline currently owns an output sample." }}
            {{ bits: "1", name: overflow, desc: "The latest result overflowed or saturated." }}
          ]
        }}
      ]
    }}
    """)


def dsp_hjson(top: str) -> str:
    """Render the dsp-domain regmap used by the generated RTL stub."""

    name = f"{top}_dsp"
    return dedent(f"""\
    {{
      name: "{name}"
      clock_primary: "dsp_clk_i"
      reset_primary: "dsp_rst_ni"
      bus_interfaces: [ {{ protocol: "tlul", direction: "device" }} ]
      registers: [
        {{ name: DSP_CTRL
          desc: "DSP-domain algorithm control."
          swaccess: "rw"
          hwaccess: "hro"
          fields: [
            {{ bits: "1:0", name: op, desc: "0=MAC plus gain, 1=absolute difference, 2=energy estimate." }}
            {{ bits: "2", name: saturate, desc: "Clamp overflowing results to signed 32-bit limits." }}
          ]
        }}
        {{ name: THRESHOLD
          desc: "Unsigned threshold compared with the DSP result."
          swaccess: "rw"
          hwaccess: "hro"
          fields: [ {{ bits: "31:0", name: value, desc: "Result threshold." }} ]
        }}
        {{ name: RESULT
          desc: "Latest signed DSP result."
          swaccess: "ro"
          hwaccess: "hrw"
          hwext: "true"
          fields: [ {{ bits: "31:0", name: value, desc: "Latest output result." }} ]
        }}
        {{ name: DSP_STATUS
          desc: "DSP-domain live status."
          swaccess: "ro"
          hwaccess: "hrw"
          hwext: "true"
          fields: [
            {{ bits: "0", name: valid, desc: "RESULT contains a valid sample." }}
            {{ bits: "1", name: above_threshold, desc: "RESULT is greater than THRESHOLD." }}
            {{ bits: "2", name: fifo_empty, desc: "RX-to-DSP FIFO has no readable payload." }}
            {{ bits: "3", name: overflow, desc: "The latest operation overflowed before saturation." }}
          ]
        }}
      ]
    }}
    """)


def hjson_text(top: str, regmap: str) -> str:
    """Render one supported multi-clock regmap."""

    if regmap == "cfg":
        return cfg_hjson(top)
    if regmap == "dsp":
        return dsp_hjson(top)
    return dedent(f"""\
    {{
      name: "{top}_{regmap}"
      clock_primary: "{clk(regmap)}"
      reset_primary: "{rst(regmap)}"
      bus_interfaces: [ {{ protocol: "tlul", direction: "device" }} ]
      registers: [
        {{ name: CTRL desc: "Domain control." swaccess: "rw" hwaccess: "hro"
          fields: [ {{ bits: "0", name: enable, desc: "Enable this domain." }} ] }}
        {{ name: STATUS desc: "Domain status." swaccess: "ro" hwaccess: "hrw" hwext: "true"
          fields: [ {{ bits: "0", name: busy, desc: "Domain busy." }} ] }}
      ]
    }}
    """)


def wrapper_text(top: str) -> str:
    """Render the SoC-facing top wrapper with two TL-UL regmap ports."""

    return dedent(f"""\
    // Auto-generated multi-clock top-level stub for {top}.
    //
    // SoC integration model:
    //   - cfg_tl_* is one TL-UL device window for global configuration.
    //   - dsp_tl_* is one TL-UL device window for datapath-local control/status.
    //   - both windows must be address-mapped by the SoC top/xbar.
    //   - each clock/reset is explicit so the SoC can connect real clock domains.

    module {top}
      import {top}_cfg_reg_pkg::*;
      import {top}_dsp_reg_pkg::*;
    (
      input  logic                cfg_clk_i,
      input  logic                cfg_rst_ni,
      input  logic                rx_clk_i,
      input  logic                rx_rst_ni,
      input  logic                dsp_clk_i,
      input  logic                dsp_rst_ni,
      input  logic                test_en_i,
      input  logic                devmode_i,

      // Cfg-domain TL-UL register window.
      input  tlul_pkg::tl_h2d_t   cfg_tl_i,
      output tlul_pkg::tl_d2h_t   cfg_tl_o,

      // DSP-domain TL-UL register window.
      input  tlul_pkg::tl_h2d_t   dsp_tl_i,
      output tlul_pkg::tl_d2h_t   dsp_tl_o,

      // RX-domain input stream.
      input  logic                rx_valid_i,
      output logic                rx_ready_o,
      input  logic signed [15:0]  rx_sample_i,
      input  logic signed [15:0]  rx_coeff_i,

      // DSP-domain output stream.
      output logic                dsp_valid_o,
      input  logic                dsp_ready_i,
      output logic signed [31:0]  dsp_result_o,
      output logic                dsp_above_threshold_o,
      output logic                dsp_overflow_o
    );

      {top}_cfg_reg2hw_t cfg_reg2hw;
      {top}_cfg_hw2reg_t cfg_hw2reg;
      {top}_dsp_reg2hw_t dsp_reg2hw;
      {top}_dsp_hw2reg_t dsp_hw2reg;

      // Cfg register block. It lives in cfg_clk_i and owns global controls.
      {top}_cfg_reg_top u_cfg_reg_top (
        .clk_i     (cfg_clk_i),
        .rst_ni    (cfg_rst_ni),
        .tl_i      (cfg_tl_i),
        .tl_o      (cfg_tl_o),
        .reg2hw    (cfg_reg2hw),
        .hw2reg    (cfg_hw2reg),
        .devmode_i (devmode_i)
      );

      // DSP register block. It lives in dsp_clk_i and owns datapath controls.
      {top}_dsp_reg_top u_dsp_reg_top (
        .clk_i     (dsp_clk_i),
        .rst_ni    (dsp_rst_ni),
        .tl_i      (dsp_tl_i),
        .tl_o      (dsp_tl_o),
        .reg2hw    (dsp_reg2hw),
        .hw2reg    (dsp_hw2reg),
        .devmode_i (devmode_i)
      );

      // The core consumes reg2hw controls and drives hw2reg status/result fields.
      {top}_core u_core (
        .cfg_clk_i              (cfg_clk_i),
        .cfg_rst_ni             (cfg_rst_ni),
        .rx_clk_i               (rx_clk_i),
        .rx_rst_ni              (rx_rst_ni),
        .dsp_clk_i              (dsp_clk_i),
        .dsp_rst_ni             (dsp_rst_ni),
        .test_en_i              (test_en_i),
        .cfg_reg2hw_i           (cfg_reg2hw),
        .cfg_hw2reg_o           (cfg_hw2reg),
        .dsp_reg2hw_i           (dsp_reg2hw),
        .dsp_hw2reg_o           (dsp_hw2reg),
        .rx_valid_i             (rx_valid_i),
        .rx_ready_o             (rx_ready_o),
        .rx_sample_i            (rx_sample_i),
        .rx_coeff_i             (rx_coeff_i),
        .dsp_valid_o            (dsp_valid_o),
        .dsp_ready_i            (dsp_ready_i),
        .dsp_result_o           (dsp_result_o),
        .dsp_above_threshold_o  (dsp_above_threshold_o),
        .dsp_overflow_o         (dsp_overflow_o)
      );

    endmodule
    """)


def core_text(top: str) -> str:
    """Render the editable multi-clock RTL stub."""

    return dedent(f"""\
    // Editable multi-clock RTL stub for {top}.
    //
    // This file is intentionally more complete than a placeholder:
    //   - cfg_reg2hw_i controls the block.
    //   - dsp_reg2hw_i selects the DSP algorithm.
    //   - RX samples cross into the DSP domain through prim_fifo_async.
    //   - the DSP clock is gated with prim_clk_gate.
    //   - hw2reg status/result fields are driven by the core.
    //
    // Design rule:
    //   Multi-bit data must cross clock domains through an explicit CDC structure.
    //   This scaffold uses prim_fifo_async for data and prim_flop_2sync for
    //   single-bit status/control examples. Review and replace with stronger
    //   handshakes where runtime updates can occur while the datapath is active.

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
      // Register map extraction
      // --------------------------------------------------------------------
      // Multi-field registers use .<field>.q. Single-field registers are flat
      // in reggen, so GAIN, THRESHOLD and RESULT use .q/.d directly.
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
      // cfg_enable and cfg_soft_reset are synchronized into RX/DSP domains.
      // cfg_gain is sampled in the DSP domain for this scaffold; in production,
      // update multi-bit configuration while disabled or add a config handshake.
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
          // Safe default policy: multi-bit cfg is sampled only while disabled.
          gain_dsp_q <= cfg_gain;
        end
      end

      // --------------------------------------------------------------------
      // DSP clock gating
      // --------------------------------------------------------------------
      // test_en_i keeps the gated clock open for scan/debug/gate-level checks.
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
      // RX -> DSP asynchronous FIFO
      // --------------------------------------------------------------------
      // RX writes {{sample, coeff}}. DSP reads the packed payload with dsp_clk_i.
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
      // Small DSP algorithm
      // --------------------------------------------------------------------
      // op=0: sample * coeff + gain
      // op=1: abs(sample - coeff)
      // op=2: sample^2 + coeff^2
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
      assign sample_ext = {{48{{sample_d[15]}}, sample_d}};
      assign coeff_ext  = {{48{{coeff_d[15]}}, coeff_d}};
      assign gain_ext   = {{48{{gain_dsp_q[15]}}, gain_dsp_q}};

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

      always_ff @(posedge dsp_clk_gated or negedge dsp_rst_ni) begin
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
      // DSP-domain regmap gets live status. cfg-domain regmap gets a synchronized
      // summary for software that only polls the cfg window.
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

      // Keep FIFO depth wires visible for debug and quiet for lint.
      logic unused_fifo_depth;
      assign unused_fifo_depth = ^{{fifo_wdepth, fifo_rdepth}};

    endmodule
    """)


def model_text(top: str) -> str:
    """Render a small Python reference model for the scaffolded DSP algorithm."""

    return dedent(f'''\
    #!/usr/bin/env python3
    """Reference model template for the {top} multi-clock scaffold.

    Edit this file to describe the algorithm, then run it to regenerate vector
    tests. SV and cocotb simulations only consume the generated files; they do
    not call this model during simulation.
    """

    from __future__ import annotations

    from pathlib import Path

    ROOT = Path(__file__).resolve().parents[1] / "tb" / "tests"


    def i16(value: int) -> int:
        """Convert an integer to signed 16-bit."""
        value &= 0xFFFF
        return value - 0x10000 if value & 0x8000 else value


    def i32(value: int) -> int:
        """Convert an integer to signed 32-bit."""
        value &= 0xFFFFFFFF
        return value - 0x100000000 if value & 0x80000000 else value


    def compute(sample: int, coeff: int, gain: int, op: int, saturate: bool) -> tuple[int, bool]:
        """Mirror the RTL DSP operation and return result plus overflow flag."""
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
        if saturate and raw < -0x80000000:
            raw = -0x80000000
        return i32(raw) & 0xFFFFFFFF, overflow


    def write_lines(path: Path, lines: list[str]) -> None:
        """Create one generated vector/config file."""
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("\\n".join(lines) + "\\n", encoding="utf-8")


    def write_test(name: str, cfg: dict[str, int], rows: list[tuple[int, int, int]]) -> None:
        """Generate config.regs, data_in.vec and data_out.vec for one test."""
        out = ROOT / name
        write_lines(out / "config.regs", [
            f"cfg.CTRL 0x{{cfg['ctrl']:08x}}",
            f"cfg.GAIN 0x{{cfg['gain'] & 0xFFFFFFFF:08x}}",
            f"dsp.DSP_CTRL 0x{{cfg['dsp_ctrl']:08x}}",
            f"dsp.THRESHOLD 0x{{cfg['threshold']:08x}}",
        ])
        data_in = [
            "# format: <CYCLE> <SIGNAL> <VALUE>",
            "# repeat the same cycle to drive multiple signals together",
        ]
        data_out = ["# format: <CYCLE> <SIGNAL> <VALUE>"]
        op = cfg["dsp_ctrl"] & 0x3
        saturate = bool(cfg["dsp_ctrl"] & 0x4)
        gain = cfg["gain"]
        for cycle, sample, coeff in rows:
            data_in += [
                f"{{cycle}} rx_sample_i 0x{{sample & 0xFFFF:04x}}",
                f"{{cycle}} rx_coeff_i 0x{{coeff & 0xFFFF:04x}}",
                f"{{cycle}} rx_valid_i 0x1",
            ]
            result, overflow = compute(sample, coeff, gain, op, saturate)
            data_out += [
                f"{{cycle + 1}} dsp_result_o 0x{{result:08x}}",
                f"{{cycle + 1}} dsp_valid_o 0x1",
                f"{{cycle + 1}} dsp_overflow_o 0x{{int(overflow)}}",
            ]
        write_lines(out / "data_in.vec", data_in)
        write_lines(out / "data_out.vec", data_out)


    def write_all_tests() -> None:
        """Generate a small regression; add more entries as the IP grows."""
        write_test(
            "mac_smoke",
            cfg={{"ctrl": 0x7, "gain": 1, "dsp_ctrl": 0x0, "threshold": 0x10}},
            rows=[(0, 3, 4), (1, 7, 2), (2, -3, 5)],
        )
        write_test(
            "absdiff",
            cfg={{"ctrl": 0x7, "gain": 0, "dsp_ctrl": 0x1, "threshold": 0x4}},
            rows=[(0, 9, 4), (1, -2, 8)],
        )
        write_test(
            "energy",
            cfg={{"ctrl": 0x7, "gain": 0, "dsp_ctrl": 0x2, "threshold": 0x20}},
            rows=[(0, 3, 4), (1, 5, 12)],
        )


    if __name__ == "__main__":
        write_all_tests()
    ''')


def sdc_text(top: str, domains: tuple[str, ...]) -> str:
    """Render the canonical IP-level SDC in pnr_openroad/<top>.sdc."""

    clocks = "\n".join(
        f"create_clock -name {domain}_clk -period 10.000 [get_ports {domain}_clk_i]"
        for domain in domains
    )
    groups = " ".join(f"-group [get_clocks {domain}_clk]" for domain in domains)
    return dedent(f"""\
    # Canonical IP-level timing constraints for {top}.
    # This file is generated in pnr_openroad/{top}.sdc, matching the normal IP flow.
    # Review periods, clock relationships, IO delays and CDC exceptions before signoff.

    {clocks}

    # The scaffold assumes independent clock domains until the SoC proves otherwise.
    set_clock_groups -asynchronous {groups}

    # Gate checks are part of timing review for gated DSP logic.
    set_clock_gating_check -setup 0.050 -hold 0.050 [get_clocks dsp_clk]

    # The RX-to-DSP FIFO is the intentional multi-bit CDC boundary.
    # Narrow this exception to exact implementation paths after hierarchy is stable.
    set_false_path -through [get_cells -hierarchical *u_rx_to_dsp_fifo*]

    # Placeholder IO budgets. Replace these with the real IP integration envelope.
    set_input_delay  1.000 -clock rx_clk  [remove_from_collection [all_inputs] [get_ports *clk_i]]
    set_output_delay 1.000 -clock dsp_clk [all_outputs]
    """)


def notes_text(top: str, domains: tuple[str, ...], regmaps: tuple[str, ...]) -> str:
    """Render a README for the generated multi-clock scaffold."""

    return dedent(f"""\
    # {top} multi-clock scaffold

    Generated by `fx multiclock_scaffold`.

    ## What was generated

    - `data/{top}_cfg.hjson`: cfg-domain global control/status regmap.
    - `data/{top}_dsp.hjson`: dsp-domain algorithm/result regmap.
    - `rtl/{top}.sv`: SoC-facing wrapper with two TL-UL windows.
    - `rtl/{top}_core.sv`: editable multi-clock RTL stub.
    - `model/model_{top}_multiclock.py`: reference model/test generator template.
    - `pnr_openroad/{top}.sdc`: canonical IP-level SDC used by synth/signoff.

    ## Clock domains

    {', '.join(domains)}

    ## Regmaps

    {', '.join(regmaps)}

    ## Suggested flow

    ```bash
    fx reg_multi doc_multi --force
    fx flist lint --force
    python3 model/model_{top}_multiclock.py
    fx setup_tb setup_cocotb --force
    fx tests
    fx sim --set TEST_NAME=mac_smoke
    fx cocotb --set TEST_NAME=mac_smoke
    fx syn sdf sta_corners power_corners
    ```

    ## SoC compliance notes

    A SoC must connect both TL-UL register windows and provide all clocks/resets:

    - cfg window: `{top}_cfg`
    - dsp window: `{top}_dsp`
    - data stream: `rx_*` input and `dsp_*` output

    Do not blindly reuse this IP SDC as the top-level SoC SDC. The SoC must own
    its top-level clock definitions, generated clocks, clock groups and IO delays.
    The IP SDC is the IP authoring contract that informs the SoC constraints.
    """)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse command-line arguments."""

    parser = argparse.ArgumentParser(description="Generate a coherent multi-clock IP scaffold")
    parser.add_argument("--top", required=True)
    parser.add_argument("--run-dir", type=Path, required=True)
    parser.add_argument("--rtl-dir", type=Path, required=True)
    parser.add_argument("--data-dir", type=Path, required=True)
    parser.add_argument("--signoff-dir", type=Path, required=True)
    parser.add_argument("--constraints-dir", type=Path, required=True)
    parser.add_argument("--model-dir", type=Path, required=True)
    parser.add_argument("--domains", default=",".join(DEFAULT_DOMAINS))
    parser.add_argument("--regmaps", default=",".join(DEFAULT_REGMAPS))
    parser.add_argument("--force", action="store_true")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Generate regmaps, RTL, model and constraints for a multi-clock IP."""

    args = parse_args(argv)
    domains = csv(args.domains, DEFAULT_DOMAINS)
    regmaps = csv(args.regmaps, DEFAULT_REGMAPS)
    written: list[Path] = []

    for regmap in regmaps:
        hjson_path = args.data_dir / f"{args.top}_{regmap}.hjson"
        if write_file(hjson_path, hjson_text(args.top, regmap), args.force):
            written.append(hjson_path)

    files = {
        args.rtl_dir / f"{args.top}.sv": wrapper_text(args.top),
        args.rtl_dir / f"{args.top}_core.sv": core_text(args.top),
        args.model_dir / f"model_{args.top}_multiclock.py": model_text(args.top),
        args.constraints_dir / f"{args.top}.sdc": sdc_text(args.top, domains),
        args.run_dir / "multiclock_readme.md": notes_text(args.top, domains, regmaps),
    }
    for output, text in files.items():
        if write_file(output, text, args.force):
            written.append(output)

    stale = [
        args.rtl_dir / f"{args.top}_core_multiclock.sv",
        args.signoff_dir / f"{args.top}_multiclock.sdc",
        args.rtl_dir / f"{args.top}_multiclock.sdc",
    ]
    if args.force:
        for old in stale:
            if old.exists():
                old.unlink()
                print(f"removed stale {old}")

    if written:
        for output in written:
            print(output)
    else:
        print("No files written. Use --force to overwrite existing scaffold files.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
