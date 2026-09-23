"""Shared semantic model for generated functional testbenches."""

from __future__ import annotations

from dataclasses import dataclass

from flexsoc.backend.core import ClockConfig, ClockDomain, templates
from flexsoc.backend.design.ip.regs import RegsFlow


@dataclass(frozen=True, slots=True)
class RegisterWindow:
    """One external CSR window and its owning clock domain."""

    name: str
    domain: str
    request: str
    response: str
    request_type: str | int
    response_type: str | int

    @property
    def package(self) -> str | None:
        value = str(self.request_type)
        return value.split("::", 1)[0] if "::" in value else None

    @property
    def request_decl(self) -> str:
        return self._declaration(self.request, self.request_type)

    @property
    def response_decl(self) -> str:
        return self._declaration(self.response, self.response_type)

    @staticmethod
    def _declaration(name: str, width: str | int) -> str:
        if width in {1, "1"}:
            return f"logic {name}"
        if isinstance(width, str) and width.startswith("["):
            return f"logic {width} {name}"
        return f"{width} {name}"


@dataclass(frozen=True, slots=True)
class RegisterTransport:
    """External CSR protocol plus the register windows using it."""

    name: str
    windows: tuple[RegisterWindow, ...] = ()

    @classmethod
    def from_name(
        cls, name: str, windows: tuple[RegisterWindow, ...] = ()
    ) -> "RegisterTransport":
        return cls(RegsFlow.normalize_register_interface(name), windows)

    @property
    def pins(self) -> tuple[str, ...]:
        return tuple(
            signal
            for window in self.windows
            for signal in (window.request, window.response)
        )

    def template_root(self, backend: str) -> str:
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
    """Semantic model shared by SystemVerilog and cocotb renderers."""

    _REGISTER_SUFFIXES = {
        "reg_iface": ("reg_req_i", "reg_rsp_o"),
        "tlul": ("tl_i", "tl_o"),
        "axi_lite": ("axi_lite_i", "axi_lite_o"),
    }

    @staticmethod
    def register_transport(
        interface: str, signature: dict[str, object], clocks: ClockConfig
    ) -> RegisterTransport:
        """Discover bare or domain-prefixed CSR windows from the top signature."""

        interface = RegsFlow.normalize_register_interface(interface)
        req_suffix, rsp_suffix = TestbenchModel._REGISTER_SUFFIXES[interface]
        inputs = dict(signature.get("ports_in", []))
        outputs = dict(signature.get("ports_out", []))
        windows: list[RegisterWindow] = []

        for request, request_type in inputs.items():
            if request == req_suffix:
                prefix = ""
            elif request.endswith(f"_{req_suffix}"):
                prefix = request[: -(len(req_suffix) + 1)]
            else:
                continue

            response = rsp_suffix if not prefix else f"{prefix}_{rsp_suffix}"
            if response not in outputs:
                continue

            domain = (
                TestbenchModel.signal_domain(request, clocks)
                if prefix
                else clocks.domains[0].name
            )
            name = prefix or domain
            windows.append(
                RegisterWindow(
                    name=name,
                    domain=domain,
                    request=request,
                    response=response,
                    request_type=request_type,
                    response_type=outputs[response],
                )
            )

        return RegisterTransport.from_name(interface, tuple(windows))

    @staticmethod
    def render_register_boundary(
        top: str, transport: RegisterTransport, *, cocotb: bool = False
    ) -> tuple[str, str]:
        """Render protocol-specific bus declarations and optional proxy signals."""

        mode = "cocotb" if cocotb else "sv"
        root = transport.template_root("sv")
        values = {"top": top, "windows": transport.windows, "default_package": f"{top}_reg_pkg"}
        return (
            templates.render(f"{root}/{mode}_declarations.sv.j2", **values),
            templates.render(f"{root}/{mode}_helpers.sv.j2", **values),
        )

    @staticmethod
    def signal_domain(name: str, clocks: ClockConfig) -> str:
        """Return explicit prefix ownership or the primary clock domain."""

        for domain in clocks.domains:
            if name.startswith(f"{domain.name}_"):
                return domain.name
        return clocks.domains[0].name

    @staticmethod
    def stream_interfaces(
        signature: dict[str, object], clocks: ClockConfig, *, direction: str
    ) -> tuple[StreamInterface, ...]:
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

        control = {
            signal
            for domain in clocks.domains
            for signal in (domain.signal, domain.reset)
        }
        streams = []
        for valid in valids:
            if not valid.endswith(valid_suffix):
                continue
            prefix = valid[: -len(valid_suffix)]
            ready = f"{prefix}{ready_suffix}"
            payload = tuple(
                name
                for name in payload_ports
                if name not in control
                and name.startswith(f"{prefix}_")
                and name.endswith(payload_suffix)
                and name != valid
            )
            streams.append(
                StreamInterface(
                    prefix,
                    TestbenchModel.signal_domain(valid, clocks),
                    valid,
                    ready if ready in peers else None,
                    payload,
                )
            )
        return tuple(streams)

    @staticmethod
    def uses_stream_handshake(signature: dict[str, object], clocks: ClockConfig) -> bool:
        """Return whether vector traffic needs ready/valid transaction semantics."""

        return bool(
            TestbenchModel.stream_interfaces(signature, clocks, direction="input")
            or TestbenchModel.stream_interfaces(signature, clocks, direction="output")
        )

    @staticmethod
    def render_signal_declarations(
        signature: dict[str, object], clocks: ClockConfig, transport: RegisterTransport
    ) -> str:
        """Render non-clock, non-CSR top-level signals for a generated wrapper."""

        excluded = {
            signal
            for domain in clocks.domains
            for signal in (domain.signal, domain.reset)
        }
        excluded.update(transport.pins)
        lines = []
        for name, width in [
            *signature.get("ports_in", []),
            *signature.get("ports_out", []),
        ]:
            if name in excluded:
                continue
            lines.append(f"  {RegisterWindow._declaration(name, width)};")
        return "\n".join(lines)

    @staticmethod
    def render_dut_pins(signature: dict[str, object]) -> str:
        pins = [
            name
            for name, _ in [
                *signature.get("ports_in", []),
                *signature.get("ports_out", []),
            ]
        ]
        return ",\n".join(f"    .{name:<25}({name})" for name in pins)

    @staticmethod
    def serial_idle_high(name: str) -> bool:
        return name.lower() in _SERIAL_IDLE_HIGH_INPUTS

    @staticmethod
    def phases(period_ns: float, io_delay_pct: float) -> tuple[float, float]:
        period = float(period_ns)
        pct = float(io_delay_pct)
        if period <= 0.0:
            raise ValueError("testbench clock period must be positive")
        if not 0.0 < pct < 0.5:
            raise ValueError(
                "SDC_IO_DELAY_PCT must be between 0 and 0.5 for testbench phasing"
            )
        return period * pct, period * (1.0 - pct)

    @staticmethod
    def clock_waveform_times(domain: ClockDomain) -> tuple[float, float, float]:
        fall = domain.fall_ns if domain.fall_ns is not None else domain.period_ns / 2.0
        initial_low = domain.rise_ns + domain.source_latency_ns
        high = fall - domain.rise_ns
        low = domain.period_ns - high
        if initial_low < 0.0 or high <= 0.0 or low <= 0.0:
            raise ValueError(f"invalid functional clock waveform for {domain.name!r}")
        return initial_low, high, low

    @staticmethod
    def clock_jitter_bound_ps(domain: ClockDomain) -> int:
        uncertainty = max(domain.setup_uncertainty_ns, domain.hold_uncertainty_ns)
        if domain.setup_uncertainty_ns < 0.0 or domain.hold_uncertainty_ns < 0.0:
            raise ValueError(
                f"clock uncertainty must be non-negative for {domain.name!r}"
            )
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
        value = 0x811C9DC5
        for byte in name.encode("utf-8"):
            value ^= byte
            value = (value * 0x01000193) & 0xFFFFFFFF
        return value or 0x6D2B79F5
