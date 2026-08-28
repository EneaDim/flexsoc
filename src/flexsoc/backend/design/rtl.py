"""RTL scaffold, top regeneration, hierarchy and ordered source views."""

from __future__ import annotations

import ast
import re
import shlex
import shutil
from dataclasses import dataclass
from pathlib import Path
from textwrap import dedent
from typing import Any, Sequence

from flexsoc.backend.core import ClockConfig, ClockDomain, clock_config, ensure_dir, safe_write_file

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
        "// Auto-generated by flexsoc.backend.design.rtl.",
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


@dataclass(frozen=True, slots=True)
class Port:
    """One parsed SystemVerilog port."""

    direction: str
    svtype: str
    name: str


def _strip_comments(text: str) -> str:
    """Remove line and block comments from SystemVerilog text."""

    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    return "\n".join(line.split("//", 1)[0] for line in text.splitlines())


def _port_list(text: str) -> str:
    """Return the first module port list."""

    match = re.search(r"module\s+\w+\s*(?:import\s+[^;]+;\s*)*\((.*?)\);", _strip_comments(text), re.S)
    if not match:
        raise ValueError("could not parse core module header")
    return match.group(1)


def parse_ports(core_path: str | Path) -> list[Port]:
    """Parse direction, type, and name from a compact module header."""

    ports: list[Port] = []
    for raw in _port_list(Path(core_path).read_text(encoding="utf-8")).splitlines():
        line = raw.strip().rstrip(",")
        if not line.startswith(("input", "output")):
            continue
        tokens = line.split()
        direction, name = tokens[0], tokens[-1]
        ports.append(Port(direction, " ".join(tokens[1:-1]), name))
    return ports


def _bus_ports(itf: str) -> list[Port]:
    """Return register-bus wrapper ports for the selected interface."""

    if itf == "tlul":
        return [Port("input", "tlul_pkg::tl_h2d_t", "tl_i"), Port("output", "tlul_pkg::tl_d2h_t", "tl_o")]
    return [Port("input", "reg_req_t", "reg_req_i"), Port("output", "reg_rsp_t", "reg_rsp_o")]


def _bus_pins(itf: str) -> list[str]:
    """Return register-top bus pin connections."""

    return [".tl_i(tl_i)", ".tl_o(tl_o)"] if itf == "tlul" else [".reg_req_i(reg_req_i)", ".reg_rsp_o(reg_rsp_o)"]


def _external_core_ports(ports: list[Port]) -> list[Port]:
    """Return core ports that must stay visible at the wrapper boundary."""

    hidden = {"reg2hw", "hw2reg"}
    return [port for port in ports if port.name not in hidden]


def _format_port(port: Port) -> str:
    """Render one module port declaration."""

    return f"  {port.direction:<6} {port.svtype} {port.name}".replace("  ", " ").rstrip()


def _instance(name: str, module: str, pins: list[str]) -> list[str]:
    """Render a compact SystemVerilog instance."""

    lines = [f"  {module} u_{name} ("]
    lines.extend(f"    {pin}{',' if i + 1 < len(pins) else ''}" for i, pin in enumerate(pins))
    lines.append("  );")
    return lines


def render_top_from_core(top: str, core_path: str | Path, itf: str = "tlul") -> str:
    """Render <top>.sv from <top>_core.sv ports and the register interface."""

    itf = "reg_iface" if itf == "reg" else itf.strip().lower()
    if itf not in {"tlul", "reg_iface"}:
        raise ValueError("--interface must be tlul, reg_iface, or reg")
    ports = parse_ports(core_path)
    top_ports = _external_core_ports(ports) + _bus_ports(itf)
    reg_pins = [".clk_i(clk_i)", ".rst_ni(rst_ni)", *_bus_pins(itf), ".reg2hw(reg2hw)", ".hw2reg(hw2reg)", ".devmode_i(1'b1)"]
    core_pins = [f".{port.name}({port.name})" for port in ports]
    lines = [
        "// Auto-generated by flexsoc.backend.design.rtl.",
        f"module {top}",
        f"  import {top}_reg_pkg::*;",
        "(",
        *[line + ("," if i + 1 < len(top_ports) else "") for i, line in enumerate(_format_port(p) for p in top_ports)],
        ");",
        "",
        f"  {top}_reg2hw_t reg2hw;",
        f"  {top}_hw2reg_t hw2reg;",
        "",
        *_instance(f"{top}_reg", f"{top}_reg_top", reg_pins),
        "",
        *_instance(f"{top}_core", f"{top}_core", core_pins),
        "",
        "endmodule",
    ]
    return "\n".join(lines) + "\n"


_REG_PORT_RE = re.compile(r"^(?P<name>[A-Za-z_][A-Za-z0-9_]*)_(?P<kind>reg2hw_i|hw2reg_o)$")


@dataclass(frozen=True, slots=True)
class RegisterWindow:
    """One discovered regtool interface and its clock domain."""

    name: str
    domain: ClockDomain

    @property
    def reset_ni(self) -> str:
        return self.domain.reset if self.domain.reset_polarity == "low" else f"~{self.domain.reset}"


def _register_windows(ports: list[Port], clocks: ClockConfig) -> tuple[RegisterWindow, ...]:
    """Bind paired register ports to same-named clock domains."""

    kinds: dict[str, set[str]] = {}
    for port in ports:
        match = _REG_PORT_RE.match(port.name)
        if match:
            kinds.setdefault(match["name"], set()).add(match["kind"])
    domains, port_names = {item.name: item for item in clocks.domains}, {port.name for port in ports}
    windows: list[RegisterWindow] = []
    for name, found in kinds.items():
        missing = {"reg2hw_i", "hw2reg_o"} - found
        if missing:
            raise ValueError(f"register window {name!r} is missing core port(s): {', '.join(sorted(missing))}")
        domain = domains.get(name)
        if domain is None:
            raise ValueError(f"register window {name!r} requires a matching CLOCK_DOMAINS entry")
        absent = [signal for signal in (domain.signal, domain.reset) if signal not in port_names]
        if absent:
            raise ValueError(f"register window {name!r} clock/reset port(s) missing from core: {', '.join(absent)}")
        windows.append(RegisterWindow(name, domain))
    return tuple(windows)


def render_nclock_top(top: str, core_path: str | Path, clocks: ClockConfig) -> str:
    """Render a clock-count-neutral wrapper around one editable core."""

    core = Path(core_path)
    core = core / f"{top}_core.sv" if core.is_dir() else core
    ports = parse_ports(core)
    windows = _register_windows(ports, clocks)
    hidden = {f"{window.name}_{kind}" for window in windows for kind in ("reg2hw_i", "hw2reg_o")}
    exposed = [port for port in ports if port.name not in hidden]
    declarations = [_format_port(port) for port in exposed]
    declarations += [item for window in windows for item in (
        f"  input  tlul_pkg::tl_h2d_t        {window.name}_tl_i",
        f"  output tlul_pkg::tl_d2h_t        {window.name}_tl_o",
    )]
    devmode = "devmode_i" if any(port.name == "devmode_i" for port in exposed) else "1'b1"
    lines = [
        "// Auto-generated N-clock wrapper. Edit the core, then rerun fx top_from_core.",
        f"module {top}",
        *(f"  import {top}_{window.name}_reg_pkg::*;" for window in windows),
        "(",
        *[line + ("," if i + 1 < len(declarations) else "") for i, line in enumerate(declarations)],
        ");", "",
    ]
    for window in windows:
        name, domain = window.name, window.domain
        lines += [
            f"  {top}_{name}_reg2hw_t {name}_reg2hw;",
            f"  {top}_{name}_hw2reg_t {name}_hw2reg;", "",
            f"  {top}_{name}_reg_top u_{name}_reg_top (",
            f"    .clk_i     ({domain.signal}),",
            f"    .rst_ni    ({window.reset_ni}),",
            f"    .tl_i      ({name}_tl_i),",
            f"    .tl_o      ({name}_tl_o),",
            f"    .reg2hw    ({name}_reg2hw),",
            f"    .hw2reg    ({name}_hw2reg),",
            f"    .devmode_i ({devmode})",
            "  );", "",
        ]
    pins = []
    for port in ports:
        match = _REG_PORT_RE.match(port.name)
        signal = f"{match['name']}_{match['kind'][:-2]}" if match else port.name
        pins.append(f"    .{port.name:<22}({signal})")
    lines += [f"  {top}_core u_core (", ",\n".join(pins), "  );", "", "endmodule", ""]
    return "\n".join(lines)


def write_top_from_core(top: str, rtl_dir: str | Path, itf: str, *, force: bool = False, clocks: ClockConfig | None = None) -> Path:
    """Write <top>.sv next to <top>_core.sv."""

    rtl = Path(rtl_dir)
    core = rtl / f"{top}_core.sv"
    out = rtl / f"{top}.sv"
    if not core.exists():
        raise FileNotFoundError(core)
    cfg = clocks or clock_config()
    text = render_nclock_top(top, core, cfg) if cfg.multiclock else render_top_from_core(top, core, itf)
    safe_write_file(out, text, overwrite=force)
    return out


MODULE_RE = re.compile(r"\bmodule\s+(?:(?:automatic|static)\s+)?([A-Za-z_][A-Za-z0-9_$]*)")
TIMESCALE_RE = re.compile(r"`timescale\s+([^\s/]+)\s*/\s*([^\s]+)")


def _resolve_tool(name: str) -> str:
    """Resolve one executable or raise a concise error."""

    path = Path(name)
    if path.is_file() and path.stat().st_mode & 0o111:
        return str(path.resolve())
    found = shutil.which(name)
    if found:
        return found
    raise FileNotFoundError(f"tool not found: {name}")


def _source_text(path: Path) -> str:
    """Read source text while removing comments before module-name inference."""

    text = path.read_text(encoding="utf-8", errors="replace")
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    text = re.sub(r"//.*?$", " ", text, flags=re.M)
    return text


def infer_top(top_file: Path) -> str:
    """Infer the intended top module from one SystemVerilog source file."""

    names = MODULE_RE.findall(_source_text(top_file))
    if not names:
        raise ValueError(f"no module declaration found in top file: {top_file}")
    stem = top_file.stem
    if stem in names:
        return stem
    return names[0]


def _ordered_roots(root: Path, top_file: Path, extra_roots: list[Path]) -> list[Path]:
    """Return unique recursive library roots, preferring the top's directory."""

    candidates = [top_file.parent, *extra_roots]
    if not extra_roots:
        candidates.append(root)

    ordered: list[Path] = []
    seen: set[Path] = set()
    for candidate in candidates:
        resolved = candidate.expanduser().resolve()
        if not resolved.is_dir():
            raise FileNotFoundError(f"source root not found: {resolved}")
        if resolved in seen:
            continue
        seen.add(resolved)
        ordered.append(resolved)
    return ordered


def _recursive_search_args(roots: list[Path]) -> list[str]:
    """Return recursive include and library-search arguments for Slang."""

    args: list[str] = []
    for root in roots:
        recursive = str(root / "...")
        args.extend([f"-I{recursive}", "--libdir", recursive])
    return args


def _default_timescale_args(top_file: Path) -> list[str]:
    """Use the top file's ``timescale`` as the default for loaded libraries."""

    match = TIMESCALE_RE.search(_source_text(top_file))
    if not match:
        return []
    return ["--timescale", f"{match.group(1)}/{match.group(2)}"]


def _slang_failure_detail(log: Path, *, context: int = 4, tail: int = 20) -> str:
    """Return a compact actionable excerpt from a failed Slang log."""

    if not log.is_file():
        return ""
    lines = log.read_text(encoding="utf-8", errors="replace").splitlines()
    error_re = re.compile(r"(?i)(?:^|[:\s])(?:fatal|error)(?:[:\s]|$)")
    for index, line in enumerate(lines):
        if error_re.search(line):
            start = max(0, index - context)
            stop = min(len(lines), index + context + 1)
            excerpt = lines[start:stop]
            break
    else:
        excerpt = lines[-tail:]
    if not excerpt:
        return ""
    return "\n--- Slang diagnostic ---\n" + "\n".join(excerpt)


def _run_slang(
    *,
    slang: str,
    root: Path,
    search_roots: list[Path],
    top_file: Path,
    top: str | None,
    extra_args: str,
    action_args: list[str],
    synthesis: bool = True,
    runner=None,
    on: str = "local",
    outputs: tuple[Path, ...] = (),
) -> str:
    """Run Slang through the shared execution layer."""

    from flexsoc.backend.core import CommandRequest, ToolRunner

    root = root.expanduser().resolve()
    top_file = top_file.expanduser().resolve()
    if not top_file.is_file():
        raise FileNotFoundError(f"top source file not found: {top_file}")
    roots = _ordered_roots(root, top_file, search_roots)
    top_name = top or infer_top(top_file)
    executable = _resolve_tool(slang) if on == "local" else slang
    command = (
        executable,
        "--top",
        top_name,
        *(("-DSYNTHESIS",) if synthesis else ()),
        *_default_timescale_args(top_file),
        *_recursive_search_args(roots),
        *shlex.split(extra_args),
        *action_args,
        str(top_file),
    )
    log = (outputs[0] if outputs else top_file).with_suffix(".slang.log")
    runner = runner or ToolRunner(project_root=root)
    request = CommandRequest(
        command,
        root,
        {},
        log,
        inputs=(top_file, *roots),
        outputs=outputs,
    )
    result = runner.run(request, on=on)
    if result.returncode:
        detail = _slang_failure_detail(log)
        raise RuntimeError(
            f"Slang failed ({result.returncode}) while elaborating {top_name} from {top_file}; "
            f"log: {log}{detail}"
        )
    log.unlink(missing_ok=True)
    return top_name


def run_ast(args, *, runner=None, on: str = "local") -> None:
    """Generate elaborated Slang AST JSON."""

    json_path = args.json_out.resolve()
    json_path.parent.mkdir(parents=True, exist_ok=True)
    action = ["--ast-json", str(json_path), "--ast-json-source-info"]
    if args.scope:
        action.extend(["--ast-json-scope", args.scope])
    _run_slang(
        slang=args.slang,
        root=args.root,
        search_roots=args.search_root,
        top_file=args.top_file,
        top=args.top,
        extra_args=args.extra_args,
        action_args=action,
        runner=runner,
        on=on,
        outputs=(json_path,),
    )


def _dep_lines(path: Path) -> list[str]:
    """Read one Slang dependency file, preserving first-seen order."""

    seen: set[str] = set()
    lines: list[str] = []
    for raw in path.read_text(encoding="utf-8").splitlines():
        item = raw.strip()
        if not item or item in seen:
            continue
        seen.add(item)
        lines.append(item)
    return lines


def _resolve_dep(item: str, root: Path) -> Path:
    """Resolve one Slang dependency path against the Slang working root."""

    path = Path(item)
    if not path.is_absolute():
        path = root / path
    return path.resolve()


def _command_path(path: Path, root: Path) -> str:
    """Prefer root-relative paths in portable standalone command files."""

    path = path.resolve()
    try:
        return path.relative_to(root.resolve()).as_posix()
    except ValueError:
        return path.as_posix()


def _portable_extra_args(extra_args: str, root: Path) -> list[str]:
    """Keep portable preprocessor options that affect the discovered closure."""

    tokens = shlex.split(extra_args)
    result: list[str] = []
    index = 0
    while index < len(tokens):
        token = tokens[index]
        if token.startswith("+define+") or token.startswith("+incdir+"):
            result.append(token)
        elif token.startswith("-D") and token != "-D":
            result.append(f"+define+{token[2:]}")
        elif token == "-D" and index + 1 < len(tokens):
            index += 1
            result.append(f"+define+{tokens[index]}")
        elif token.startswith("-I") and token != "-I":
            include_dir = Path(token[2:])
            if not include_dir.is_absolute():
                include_dir = root / include_dir
            result.append(f"+incdir+{_command_path(include_dir, root)}")
        elif token == "-I" and index + 1 < len(tokens):
            index += 1
            include_dir = Path(tokens[index])
            if not include_dir.is_absolute():
                include_dir = root / include_dir
            result.append(f"+incdir+{_command_path(include_dir, root)}")
        index += 1
    return result


def _is_under(path: Path, roots: list[Path]) -> bool:
    """Return whether ``path`` belongs to one of the configured common roots."""

    resolved = path.resolve()
    for root in roots:
        try:
            resolved.relative_to(root.resolve())
            return True
        except ValueError:
            continue
    return False


def _write_lines(path: Path, lines: list[str]) -> None:
    """Write one command file with a trailing newline."""

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def _split_flow_filelists(
    *,
    common_out: Path,
    ip_out: Path,
    modules: list[Path],
    includes: list[Path],
    common_roots: list[Path],
    extra_args: str,
    root: Path,
    synthesis: bool,
) -> None:
    """Write absolute-path FlexSoC common/IP command files from one Slang closure."""

    common_roots = [item.expanduser().resolve() for item in common_roots]
    common_lines = ["# Auto-generated by Slang: shared RTL"]
    if synthesis:
        common_lines.append("+define+SYNTHESIS")
    ip_lines = ["# Auto-generated by Slang: IP/run RTL"]
    seen_common = set(common_lines)
    seen_ip = set(ip_lines)

    def append(lines: list[str], seen: set[str], item: str) -> None:
        if item not in seen:
            seen.add(item)
            lines.append(item)

    for option in _portable_extra_args(extra_args, root):
        if option.startswith("+incdir+"):
            dirs = [part for part in option[len("+incdir+"):].split("+") if part]
            for directory in dirs:
                path = Path(directory)
                if not path.is_absolute():
                    path = (root / path).resolve()
                target_lines, target_seen = (
                    (common_lines, seen_common) if _is_under(path, common_roots) else (ip_lines, seen_ip)
                )
                append(target_lines, target_seen, f"+incdir+{path.as_posix()}")
        else:
            append(common_lines, seen_common, option)

    include_dirs: list[Path] = []
    seen_dirs: set[Path] = set()
    for source in includes:
        directory = source.parent.resolve()
        if directory in seen_dirs:
            continue
        seen_dirs.add(directory)
        include_dirs.append(directory)

    for directory in include_dirs:
        target_lines, target_seen = (
            (common_lines, seen_common) if _is_under(directory, common_roots) else (ip_lines, seen_ip)
        )
        append(target_lines, target_seen, f"+incdir+{directory.as_posix()}")

    for source in modules:
        target_lines, target_seen = (
            (common_lines, seen_common) if _is_under(source, common_roots) else (ip_lines, seen_ip)
        )
        append(target_lines, target_seen, source.resolve().as_posix())

    _write_lines(common_out, common_lines)
    _write_lines(ip_out, ip_lines)


def run_flist(args, *, runner=None, on: str = "local") -> None:
    """Generate a hierarchy-trimmed Slang filelist, optionally split for FlexSoC."""

    root = args.root.expanduser().resolve()
    outputs = [path for path in (args.output, args.common_out, args.ip_out) if path is not None]
    if not outputs:
        raise ValueError("flist requires --output or both --common-out/--ip-out")
    if (args.common_out is None) != (args.ip_out is None):
        raise ValueError("--common-out and --ip-out must be provided together")

    resolved_outputs = [path.expanduser().resolve() for path in outputs]
    for path in resolved_outputs:
        path.parent.mkdir(parents=True, exist_ok=True)
        path.unlink(missing_ok=True)

    anchor = resolved_outputs[0]
    module_deps = anchor.with_suffix(anchor.suffix + ".modules.tmp")
    include_deps = anchor.with_suffix(anchor.suffix + ".includes.tmp")

    try:
        _run_slang(
            slang=args.slang,
            root=root,
            search_roots=args.search_root,
            top_file=args.top_file,
            top=args.top,
            extra_args=args.extra_args,
            action_args=[
                "--Mmodule",
                str(module_deps),
                "--Minclude",
                str(include_deps),
                "--depfile-trim",
                "--depfile-sort",
            ],
            synthesis=args.synthesis,
            runner=runner,
            on=on,
            outputs=(module_deps, include_deps),
        )

        modules = [_resolve_dep(item, root) for item in _dep_lines(module_deps)]
        includes = [_resolve_dep(item, root) for item in _dep_lines(include_deps)]

        if args.output is not None:
            lines: list[str] = []
            seen_lines: set[str] = set()

            def append_unique(item: str) -> None:
                if item not in seen_lines:
                    seen_lines.add(item)
                    lines.append(item)

            if args.synthesis:
                append_unique("+define+SYNTHESIS")
            for option in _portable_extra_args(args.extra_args, root):
                append_unique(option)
            seen_dirs: set[Path] = set()
            for source in includes:
                directory = source.parent.resolve()
                if directory in seen_dirs:
                    continue
                seen_dirs.add(directory)
                append_unique(f"+incdir+{_command_path(directory, root)}")
            for source in modules:
                append_unique(_command_path(source, root))
            _write_lines(args.output.expanduser().resolve(), lines)

        if args.common_out is not None and args.ip_out is not None:
            _split_flow_filelists(
                common_out=args.common_out.expanduser().resolve(),
                ip_out=args.ip_out.expanduser().resolve(),
                modules=modules,
                includes=includes,
                common_roots=args.common_root,
                extra_args=args.extra_args,
                root=root,
                synthesis=args.synthesis,
            )
    finally:
        module_deps.unlink(missing_ok=True)
        include_deps.unlink(missing_ok=True)


def run_hier(args, *, runner=None, on: str = "local") -> None:
    """Write hierarchy through the shared execution layer."""

    from flexsoc.backend.core import CommandRequest, ToolRunner

    root = args.root.expanduser().resolve()
    top_file = args.top_file.expanduser().resolve()
    if not top_file.is_file():
        raise FileNotFoundError(f"top source file not found: {top_file}")
    roots = _ordered_roots(root, top_file, args.search_root)
    top_name = args.top or infer_top(top_file)
    output = args.output.expanduser().resolve()
    output.parent.mkdir(parents=True, exist_ok=True)
    executable = _resolve_tool(args.slang_hier) if on == "local" else args.slang_hier
    command = (
        executable,
        "--top",
        top_name,
        "-DSYNTHESIS",
        *_default_timescale_args(top_file),
        *_recursive_search_args(roots),
        *shlex.split(args.extra_args),
        str(top_file),
    )
    runner = runner or ToolRunner(project_root=root)
    result = runner.run(
        CommandRequest(command, root, {}, output, inputs=(top_file, *roots), outputs=(output,)),
        on=on,
    )
    if result.returncode:
        raise RuntimeError(f"slang-hier failed ({result.returncode}); output: {output}")


class RtlFlow:
    def __init__(self, project_root: Path, runner=None):
        self.project_root = Path(project_root).resolve()
        from ..core import ToolRunner
        self.runner = runner or ToolRunner(project_root=self.project_root)
    """Create RTL scaffold, top wiring and canonical source views."""

    def setup_scaffold(
        self,
        hjson_file: Path | None,
        interface: str,
        output_dir: Path,
        *,
        top: str | None = None,
        force: bool = False,
        clocks: ClockConfig | None = None,
    ) -> tuple[Path, Path]:
        """Create the single- or multi-clock starter RTL."""

        clocks = clocks or clock_config()
        if clocks.multiclock:
            if not top:
                raise ValueError("top is required for a multi-clock RTL scaffold")
            ensure_dir(output_dir)
            core = output_dir / f"{top}_core.sv"
            safe_write_file(core, render_nclock_core(top), overwrite=force)
            wrapper = write_top_from_core(top, output_dir, interface, force=force, clocks=clocks)
            return core, wrapper
        if hjson_file is None:
            raise ValueError("hjson_file is required for a single-clock RTL scaffold")
        return generate_rtl_stubs(hjson_file, interface, output_dir, force=force)

    def generate_top(
        self,
        top: str,
        rtl_dir: Path,
        interface: str,
        *,
        force: bool = False,
        clocks: ClockConfig | None = None,
    ) -> Path:
        """Regenerate the wrapper from the edited core signature."""

        return write_top_from_core(top, rtl_dir, interface, force=force, clocks=clocks)

    def generate_filelists(
        self,
        *,
        root: Path,
        top_file: Path,
        common_out: Path,
        ip_out: Path,
        search_roots: Sequence[Path] = (),
        common_roots: Sequence[Path] = (),
        top: str | None = None,
        extra_args: str = "",
        slang: str = "slang",
        synthesis: bool = False,
        on: str = "local",
    ) -> None:
        """Generate ordered common/IP filelists with Slang."""

        from types import SimpleNamespace

        run_flist(SimpleNamespace(
            root=root,
            search_root=list(search_roots),
            top_file=top_file,
            top=top,
            extra_args=extra_args,
            slang=slang,
            output=None,
            common_out=common_out,
            ip_out=ip_out,
            common_root=list(common_roots),
            synthesis=synthesis,
        ), runner=self.runner, on=on)

    def show_hierarchy(
        self,
        *,
        root: Path,
        top_file: Path,
        output: Path,
        search_roots: Sequence[Path] = (),
        top: str | None = None,
        extra_args: str = "",
        slang_hier: str = "slang-hier",
        on: str = "local",
    ) -> None:
        """Write the elaborated hierarchy for one top."""

        from types import SimpleNamespace

        run_hier(SimpleNamespace(
            root=root,
            search_root=list(search_roots),
            top_file=top_file,
            top=top,
            extra_args=extra_args,
            slang_hier=slang_hier,
            output=output,
        ), runner=self.runner, on=on)

    def show_ast(
        self,
        *,
        root: Path,
        top_file: Path,
        output: Path,
        search_roots: Sequence[Path] = (),
        top: str | None = None,
        extra_args: str = "",
        slang: str = "slang",
        scope: str | None = None,
        on: str = "local",
    ) -> None:
        """Write the Slang AST JSON for one top."""

        from types import SimpleNamespace

        run_ast(SimpleNamespace(
            root=root,
            search_root=list(search_roots),
            top_file=top_file,
            top=top,
            extra_args=extra_args,
            slang=slang,
            json_out=output,
            scope=scope,
        ), runner=self.runner, on=on)

    def fetch_vendor(
        self,
        manifest: Path,
        *,
        target_dir: Path,
        force: bool = False,
        on: str = "local",
    ) -> int:
        """Fetch one vendored RTL dependency through the canonical utility."""

        import sys
        from flexsoc.backend.core import CommandRequest

        tool = self.project_root / "src" / "util" / "vendor.py"
        argv = (sys.executable, str(tool), "--update" if force else "--refresh-patches", str(manifest))
        log = target_dir / ".flexsoc_vendor.log"
        request = CommandRequest(argv, self.project_root, {}, log, inputs=(manifest, tool), outputs=(target_dir,))
        return self.runner.run(request, on=on).returncode

    def flow(
        self,
        hjson_file: Path | None,
        top: str,
        interface: str,
        rtl_dir: Path,
        *,
        force: bool = False,
        clocks: ClockConfig | None = None,
    ) -> tuple[Path, Path]:
        """Run the canonical RTL scaffold/wrapper preparation."""

        paths = self.setup_scaffold(
            hjson_file,
            interface,
            rtl_dir,
            top=top,
            force=force,
            clocks=clocks,
        )
        self.generate_top(top, rtl_dir, interface, force=force, clocks=clocks)
        return paths

