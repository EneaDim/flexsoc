"""Small helpers shared by SystemVerilog and cocotb testbench renderers."""

from __future__ import annotations

from dataclasses import dataclass
from textwrap import dedent

from flexsoc.backend.core import ClockConfig, ClockDomain, templates
from flexsoc.backend.design.ip.regs import RegsFlow


@dataclass(frozen=True, slots=True)
class RegisterTransport:
    """Describe the external CSR transport and discovered register windows."""

    name: str
    windows: tuple[str, ...] = ()

    @classmethod
    def from_name(cls, name: str, windows: tuple[str, ...] = ()) -> "RegisterTransport":
        return cls(RegsFlow.normalize_register_interface(name), windows)

    @property
    def pins(self) -> tuple[str, ...]:
        suffixes = {
            "reg_iface": ("reg_req_i", "reg_rsp_o"),
            "tlul": ("tl_i", "tl_o"),
            "axi_lite": ("axi_lite_i", "axi_lite_o"),
        }[self.name]
        return tuple(f"{window}_{suffix}" for window in self.windows for suffix in suffixes)

    def template_root(self, backend: str) -> str:
        """Return the template root for the direct register bus or one adapter."""

        branch = "reg_iface" if self.name == "reg_iface" else f"adapters/{self.name}"
        return f"dv/{backend}/register/{branch}"


@dataclass(frozen=True, slots=True)
class StreamInterface:
    """One conventional ready/valid stream discovered from top-level ports."""

    name: str
    domain: str
    valid: str
    ready: str | None
    payload: tuple[str, ...]


_SERIAL_IDLE_HIGH_INPUTS = frozenset({"rx_i", "cio_rx_i", "uart_rx_i", "serial_rx_i"})


class TestbenchModel:
    """Shared semantic model used by SystemVerilog and cocotb testbenches."""

    @staticmethod
    def register_windows(interface: str, signature: dict[str, object]) -> tuple[str, ...]:
        """Discover register-window names from the generated top-level bus ports."""
    
        interface = RegsFlow.normalize_register_interface(interface)
        suffixes = {
            "reg_iface": ("_reg_req_i", "_reg_rsp_o"),
            "tlul": ("_tl_i", "_tl_o"),
            "axi_lite": ("_axi_lite_i", "_axi_lite_o"),
        }[interface]
        inputs = [name for name, _ in signature.get("ports_in", [])]
        outputs = {name for name, _ in signature.get("ports_out", [])}
        windows = []
        for name in inputs:
            if not name.endswith(suffixes[0]):
                continue
            window = name[: -len(suffixes[0])]
            if f"{window}{suffixes[1]}" in outputs:
                windows.append(window)
        return tuple(windows)

    @staticmethod
    def render_register_boundary(
        top: str, interface: str, windows: tuple[str, ...], *, cocotb: bool = False
    ) -> tuple[str, str, RegisterTransport]:
        """Render one SV CSR boundary while keeping the transport choice explicit."""
    
        transport = RegisterTransport.from_name(interface, windows)
        mode = "cocotb" if cocotb else "sv"
        root = transport.template_root("sv")
        values = {"top": top, "windows": windows}
        return (
            templates.render(f"{root}/{mode}_declarations.sv.j2", **values),
            templates.render(f"{root}/{mode}_helpers.sv.j2", **values),
            transport,
        )

    @staticmethod
    def signal_domain(name: str, clocks: ClockConfig) -> str:
        """Return explicit prefix-based ownership or the primary clock domain."""
    
        for domain in clocks.domains:
            if name.startswith(f"{domain.name}_"):
                return domain.name
        return clocks.domains[0].name

    @staticmethod
    def stream_interfaces(signature: dict[str, object], clocks: ClockConfig, *, direction: str) -> tuple[StreamInterface, ...]:
        """Discover conventional ready/valid streams without design-specific names."""
    
        inputs = [name for name, _ in signature.get("ports_in", [])]
        outputs = [name for name, _ in signature.get("ports_out", [])]
        if direction == "input":
            valids, peers, payload_ports = inputs, set(outputs), inputs
            valid_suffix, ready_suffix, payload_suffix = "_valid_i", "_ready_o", "_i"
        elif direction == "output":
            valids, peers, payload_ports = outputs, set(inputs), outputs
            valid_suffix, ready_suffix, payload_suffix = "_valid_o", "_ready_i", "_o"
        else:
            raise ValueError(f"unknown stream direction: {direction}")
    
        streams = []
        for valid in valids:
            if not valid.endswith(valid_suffix):
                continue
            prefix = valid[: -len(valid_suffix)]
            ready = f"{prefix}{ready_suffix}"
            payload = tuple(
                name for name in payload_ports
                if name.startswith(f"{prefix}_") and name.endswith(payload_suffix) and name != valid
            )
            streams.append(StreamInterface(
                prefix, TestbenchModel.signal_domain(valid, clocks), valid, ready if ready in peers else None, payload
            ))
        return tuple(streams)

    @staticmethod
    def render_signal_declarations(
        signature: dict[str, object], clocks: ClockConfig, transport: RegisterTransport
    ) -> str:
        """Render non-clock, non-CSR top-level signals for a generated wrapper."""
    
        excluded = {signal for domain in clocks.domains for signal in (domain.signal, domain.reset)}
        excluded.update(transport.pins)
        lines = []
        for name, width in [*signature.get("ports_in", []), *signature.get("ports_out", [])]:
            if name in excluded:
                continue
            if width == 1 or width == "1":
                lines.append(f"  logic {name};")
            elif isinstance(width, str) and width.startswith("["):
                lines.append(f"  logic {width} {name};")
            else:
                lines.append(f"  {width} {name};")
        return "\n".join(lines)

    @staticmethod
    def render_dut_pins(signature: dict[str, object]) -> str:
        """Render deterministic one-to-one DUT connections from the top signature."""
    
        pins = [name for name, _ in [*signature.get("ports_in", []), *signature.get("ports_out", [])]]
        return ",\n".join(f"    .{name:<25}({name})" for name in pins)

    @staticmethod
    def serial_idle_high(name: str) -> bool:
        """Return true for asynchronous serial receive pins that idle high."""
    
        return name.lower() in _SERIAL_IDLE_HIGH_INPUTS

    @staticmethod
    def phases(period_ns: float, io_delay_pct: float) -> tuple[float, float]:
        """Return input-drive and output-sample offsets for one clock period."""
    
        period = float(period_ns)
        pct = float(io_delay_pct)
        if period <= 0.0:
            raise ValueError("testbench clock period must be positive")
        if not 0.0 < pct < 0.5:
            raise ValueError("SDC_IO_DELAY_PCT must be between 0 and 0.5 for testbench phasing")
        return period * pct, period * (1.0 - pct)

    @staticmethod
    def render_packed_tlul_helpers(indent: str = "") -> str:
        """Render package-free TL-UL packing and integrity helpers for GLS wrappers."""
    
        body = templates.render("dv/sv/register/adapters/tlul/packed_helpers.svh.j2").strip("\n")
        return "\n".join(indent + line if line else "" for line in body.splitlines())

    @staticmethod
    def clock_waveform_times(domain: ClockDomain) -> tuple[float, float, float]:
        """Return initial-low, high and nominal-low times for one SDC clock."""
    
        fall = domain.fall_ns if domain.fall_ns is not None else domain.period_ns / 2.0
        initial_low = domain.rise_ns + domain.source_latency_ns
        high = fall - domain.rise_ns
        low = domain.period_ns - high
        if initial_low < 0.0 or high <= 0.0 or low <= 0.0:
            raise ValueError(f"invalid functional clock waveform for {domain.name!r}")
        return initial_low, high, low

    @staticmethod
    def clock_jitter_bound_ps(domain: ClockDomain) -> int:
        """Return the functional jitter bound derived from SDC uncertainty."""
    
        uncertainty = max(domain.setup_uncertainty_ns, domain.hold_uncertainty_ns)
        if domain.setup_uncertainty_ns < 0.0 or domain.hold_uncertainty_ns < 0.0:
            raise ValueError(f"clock uncertainty must be non-negative for {domain.name!r}")
        bound_ps = int(round(uncertainty * 1000.0))
        _, _, low = TestbenchModel.clock_waveform_times(domain)
        low_ps = int(round(low * 1000.0))
        if bound_ps and 2 * bound_ps >= low_ps:
            raise ValueError(
                f"clock uncertainty for {domain.name!r} is too large for functional jitter: "
                f"2*{bound_ps}ps must be smaller than nominal low time {low_ps}ps"
            )
        return bound_ps

    @staticmethod
    def clock_seed_salt(name: str) -> int:
        """Return a stable per-clock FNV-1a salt shared by generated SV and Python."""
    
        value = 0x811C9DC5
        for byte in name.encode("utf-8"):
            value ^= byte
            value = (value * 0x01000193) & 0xFFFFFFFF
        return value or 0x6D2B79F5

    @staticmethod
    def axi_lite_cocotb_proxy(pkg: str, prefix: str = "") -> tuple[str, str, str]:
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
