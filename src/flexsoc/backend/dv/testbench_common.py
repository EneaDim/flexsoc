"""Small helpers shared by SystemVerilog and cocotb testbench renderers."""

from __future__ import annotations

from dataclasses import dataclass
from textwrap import dedent

from flexsoc.backend.core import ClockConfig, ClockDomain, templates
from flexsoc.backend.design.regs import normalize_register_interface


@dataclass(frozen=True, slots=True)
class RegisterTransport:
    """Describe one external CSR transport over the common register contract."""

    name: str
    pins: tuple[str, ...]

    @classmethod
    def from_name(cls, name: str) -> "RegisterTransport":
        name = normalize_register_interface(name)
        pins = {
            "reg_iface": (
                "cfg_reg_req_i", "cfg_reg_rsp_o", "dsp_reg_req_i", "dsp_reg_rsp_o",
            ),
            "tlul": ("cfg_tl_i", "cfg_tl_o", "dsp_tl_i", "dsp_tl_o"),
            "axi_lite": (
                "cfg_axi_lite_i", "cfg_axi_lite_o", "dsp_axi_lite_i", "dsp_axi_lite_o",
            ),
        }[name]
        return cls(name, pins)

    def template_root(self, backend: str) -> str:
        """Return the template root for the direct register bus or one adapter."""

        branch = "reg_iface" if self.name == "reg_iface" else f"adapters/{self.name}"
        return f"dv/{backend}/register/{branch}"


def render_register_boundary(
    top: str, interface: str, *, cocotb: bool = False
) -> tuple[str, str, RegisterTransport]:
    """Render one SV CSR boundary while keeping the transport choice explicit."""

    transport = RegisterTransport.from_name(interface)
    mode = "cocotb" if cocotb else "sv"
    root = transport.template_root("sv")
    return (
        templates.render(f"{root}/{mode}_declarations.sv.j2", top=top),
        templates.render(f"{root}/{mode}_helpers.sv.j2", top=top),
        transport,
    )


def render_dut_pins(clocks: ClockConfig, transport: RegisterTransport) -> str:
    """Render deterministic DUT connections for the shared multiclock wrapper."""

    pins = [signal for domain in clocks.domains for signal in (domain.signal, domain.reset)]
    pins += [
        *transport.pins,
        "rx_valid_i", "rx_ready_o", "rx_sample_i", "rx_coeff_i",
        "dsp_valid_o", "dsp_ready_i", "dsp_result_o",
        "dsp_above_threshold_o", "dsp_overflow_o",
    ]
    return ",\n".join(f"    .{name:<25}({name})" for name in pins)


_SERIAL_IDLE_HIGH_INPUTS = frozenset({"rx_i", "cio_rx_i", "uart_rx_i", "serial_rx_i"})


def _serial_idle_high(name: str) -> bool:
    """Return true for asynchronous serial receive pins that idle high."""

    return name.lower() in _SERIAL_IDLE_HIGH_INPUTS


def _tb_phases(period_ns: float, io_delay_pct: float) -> tuple[float, float]:
    """Return input-drive and output-sample offsets for one clock period."""

    period = float(period_ns)
    pct = float(io_delay_pct)
    if period <= 0.0:
        raise ValueError("testbench clock period must be positive")
    if not 0.0 < pct < 0.5:
        raise ValueError("SDC_IO_DELAY_PCT must be between 0 and 0.5 for testbench phasing")
    return period * pct, period * (1.0 - pct)


def render_packed_tlul_helpers(indent: str = "") -> str:
    """Render package-free TL-UL packing and integrity helpers for GLS wrappers."""

    body = templates.render("dv/sv/register/adapters/tlul/packed_helpers.svh.j2").strip("\n")
    return "\n".join(indent + line if line else "" for line in body.splitlines())


def _clock_waveform_times(domain: ClockDomain) -> tuple[float, float, float]:
    """Return initial-low, high and nominal-low times for one SDC clock."""

    fall = domain.fall_ns if domain.fall_ns is not None else domain.period_ns / 2.0
    initial_low = domain.rise_ns + domain.source_latency_ns
    high = fall - domain.rise_ns
    low = domain.period_ns - high
    if initial_low < 0.0 or high <= 0.0 or low <= 0.0:
        raise ValueError(f"invalid functional clock waveform for {domain.name!r}")
    return initial_low, high, low


def _clock_jitter_bound_ps(domain: ClockDomain) -> int:
    """Return the functional jitter bound derived from SDC uncertainty."""

    uncertainty = max(domain.setup_uncertainty_ns, domain.hold_uncertainty_ns)
    if domain.setup_uncertainty_ns < 0.0 or domain.hold_uncertainty_ns < 0.0:
        raise ValueError(f"clock uncertainty must be non-negative for {domain.name!r}")
    bound_ps = int(round(uncertainty * 1000.0))
    _, _, low = _clock_waveform_times(domain)
    low_ps = int(round(low * 1000.0))
    if bound_ps and 2 * bound_ps >= low_ps:
        raise ValueError(
            f"clock uncertainty for {domain.name!r} is too large for functional jitter: "
            f"2*{bound_ps}ps must be smaller than nominal low time {low_ps}ps"
        )
    return bound_ps


def _clock_seed_salt(name: str) -> int:
    """Return a stable per-clock FNV-1a salt shared by generated SV and Python."""

    value = 0x811C9DC5
    for byte in name.encode("utf-8"):
        value ^= byte
        value = (value * 0x01000193) & 0xFFFFFFFF
    return value or 0x6D2B79F5


def _axi_lite_cocotb_proxy(pkg: str, prefix: str = "") -> tuple[str, str, str]:
    """Expose one packed AXI4-Lite port pair as scalar cocotb handles."""

    stem = f"{prefix}_" if prefix else ""
    fields = (
        ("AW", "aw_addr_i"), ("logic [2:0]", "aw_prot_i"), ("logic", "aw_valid_i"),
        ("logic", "aw_ready_o"), ("DW", "w_data_i"), ("DBW", "w_strb_i"),
        ("logic", "w_valid_i"), ("logic", "w_ready_o"), ("logic [1:0]", "b_resp_o"),
        ("logic", "b_valid_o"), ("logic", "b_ready_i"), ("AW", "ar_addr_i"),
        ("logic [2:0]", "ar_prot_i"), ("logic", "ar_valid_i"), ("logic", "ar_ready_o"),
        ("DW", "r_data_o"), ("logic [1:0]", "r_resp_o"), ("logic", "r_valid_o"),
        ("logic", "r_ready_i"),
    )
    decls = []
    for width, suffix in fields:
        kind = f"logic [{pkg}::{width}-1:0]" if width in {"AW", "DW", "DBW"} else width
        decls.append(f"  {kind} {stem}axi_{suffix};")
    assigns = dedent(f"""\
      assign {stem}axi_lite_i = '{{
        aw: '{{addr: {stem}axi_aw_addr_i, prot: {stem}axi_aw_prot_i}},
        aw_valid: {stem}axi_aw_valid_i,
        w: '{{data: {stem}axi_w_data_i, strb: {stem}axi_w_strb_i}},
        w_valid: {stem}axi_w_valid_i, b_ready: {stem}axi_b_ready_i,
        ar: '{{addr: {stem}axi_ar_addr_i, prot: {stem}axi_ar_prot_i}},
        ar_valid: {stem}axi_ar_valid_i, r_ready: {stem}axi_r_ready_i
      }};
      assign {stem}axi_aw_ready_o = {stem}axi_lite_o.aw_ready;
      assign {stem}axi_w_ready_o = {stem}axi_lite_o.w_ready;
      assign {stem}axi_b_resp_o = {stem}axi_lite_o.b.resp;
      assign {stem}axi_b_valid_o = {stem}axi_lite_o.b_valid;
      assign {stem}axi_ar_ready_o = {stem}axi_lite_o.ar_ready;
      assign {stem}axi_r_data_o = {stem}axi_lite_o.r.data;
      assign {stem}axi_r_resp_o = {stem}axi_lite_o.r.resp;
      assign {stem}axi_r_valid_o = {stem}axi_lite_o.r_valid;""")
    assigns = "\n".join(f"  {line}" if line else "" for line in assigns.splitlines())
    init = "\n".join(
        f"    {stem}axi_{suffix} = '0;"
        for suffix in ("aw_addr_i", "aw_prot_i", "aw_valid_i", "w_data_i", "w_strb_i", "w_valid_i",
                       "b_ready_i", "ar_addr_i", "ar_prot_i", "ar_valid_i", "r_ready_i")
    )
    return "\n".join(decls), assigns, init
