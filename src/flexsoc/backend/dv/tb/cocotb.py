"""Cocotb functional testbench generation."""

from __future__ import annotations

from dataclasses import dataclass, replace
from pathlib import Path
from typing import Sequence

from flexsoc.backend.core import ClockConfig, Files, RtlSources, templates
from flexsoc.backend.design.ip.regs import RegsFlow
from ..func.functional import FunctionalFlow
from .common import RegisterTransport, TestbenchModel


@dataclass(frozen=True, slots=True)
class CocotbConfig:
    """Configuration for one generated cocotb functional testbench."""

    top: str
    interface: str
    output: Path
    rtl_dir: Path = Path("rtl")
    ips_root: Path | None = None
    simulator: str = "verilator"
    clk: str = "clk_i"
    rst: str = "rst_ni"
    rst_active: str = "low"
    period_ns: float = 10.0
    io_delay_pct: float = 0.2
    nbit: int = 32
    n_op: int = 10
    vsv: str = "sv"
    force: bool = False


@dataclass(slots=True)
class CocotbTestbench:
    """Generate one clock-topology-independent cocotb testbench scaffold."""

    def setup(
        self, config: CocotbConfig, *, clocks: ClockConfig | None = None
    ) -> list[Path]:
        clocks = clocks or ClockConfig.from_values()
        config = replace(
            config, interface=RegsFlow.normalize_register_interface(config.interface)
        )
        with Files.replace_generated_tree(config.output):
            return self._write(config, clocks)

    @staticmethod
    def repo_root() -> Path:
        return Path(__file__).resolve().parents[5]

    @staticmethod
    def render_wrapper(
        top: str,
        clocks: ClockConfig,
        signature: dict[str, object],
        interface: str,
    ) -> str:
        """Render the common SV wrapper and protocol-specific bus proxies."""

        transport = TestbenchModel.register_transport(interface, signature, clocks)
        CocotbTestbench._validate_windows(transport, clocks)
        bus_decls, bus_helpers = TestbenchModel.render_register_boundary(
            top, transport, cocotb=True
        )
        clock_decls = "\n".join(
            f"  logic {domain.signal};\n  logic {domain.reset};"
            for domain in clocks.domains
        )
        return templates.render(
            "dv/cocotb/testbench/wrapper.sv.j2",
            top=top,
            clock_decls=clock_decls,
            bus_decls=bus_decls,
            signal_decls=TestbenchModel.render_signal_declarations(
                signature, clocks, transport
            ),
            bus_helpers=bus_helpers,
            dut_pins=TestbenchModel.render_dut_pins(signature),
        )

    @staticmethod
    def render_reg_driver(
        top: str,
        clocks: ClockConfig,
        signature: dict[str, object],
        registers: Sequence[dict[str, object]],
        interface: str,
        io_delay_pct: float = 0.2,
    ) -> str:
        """Render one register driver for bare or domain-prefixed windows."""

        del top
        transport = TestbenchModel.register_transport(interface, signature, clocks)
        CocotbTestbench._validate_windows(transport, clocks)
        addr_map = {window.name: {} for window in transport.windows}
        by_name = {window.name: window for window in transport.windows}
        by_domain = {window.domain: window for window in transport.windows}
        only = transport.windows[0] if len(transport.windows) == 1 else None
        for register in registers:
            key = str(register.get("key") or register.get("name") or "")
            prefix = key.split(".", 1)[0] if "." in key else ""
            window = (
                by_name.get(prefix)
                or by_domain.get(str(register.get("clock") or ""))
                or only
            )
            if window is None or not key:
                continue
            reg_name = key.split(".", 1)[-1]
            addr_map[window.name][reg_name.upper()] = int(register["addr"])

        domain_by_name = {domain.name: domain for domain in clocks.domains}
        clock_map = {
            window.name: domain_by_name[window.domain].signal
            for window in transport.windows
        }
        reset_map = {
            domain.name: (domain.signal, domain.reset, domain.reset_polarity)
            for domain in clocks.domains
        }
        period_ps = {
            domain.signal: int(round(domain.period_ns * 1000))
            for domain in clocks.domains
        }
        drive_ps = {}
        sample_ps = {}
        for domain in clocks.domains:
            drive_ns, sample_ns = TestbenchModel.phases(
                domain.period_ns, io_delay_pct
            )
            drive_ps[domain.signal] = int(round(drive_ns * 1000))
            sample_ps[domain.signal] = int(round(sample_ns * 1000))

        root = transport.template_root("cocotb")
        bus_defaults, bus_write, bus_read = (
            templates.render(f"{root}/{name}.py.j2")
            for name in ("defaults", "write", "read")
        )
        return templates.render(
            "dv/cocotb/drivers/reg_driver.py.j2",
            clock_map=repr(clock_map),
            period_ps=repr(period_ps),
            drive_ps=repr(drive_ps),
            sample_ps=repr(sample_ps),
            reset_map=repr(reset_map),
            primary=repr(clocks.domains[0].signal),
            settle=repr(clocks.domains[0].signal),
            windows=repr(tuple(window.name for window in transport.windows)),
            addr_map=repr(addr_map),
            default_domain=repr(only.name if only else None),
            input_defaults=CocotbTestbench._input_defaults(
                signature, clocks, transport
            ),
            bus_defaults=bus_defaults.rstrip(),
            bus_write=bus_write.rstrip(),
            bus_read=bus_read.rstrip(),
        )

    @staticmethod
    def render_vec_driver(
        clocks: ClockConfig, signature: dict[str, object]
    ) -> str:
        """Render cycle or stream vector semantics from the DUT contract."""

        if not TestbenchModel.uses_stream_handshake(signature, clocks):
            return templates.render("dv/cocotb/drivers/vec_driver_cycle.py.j2")
        inputs = TestbenchModel.stream_interfaces(
            signature, clocks, direction="input"
        )
        outputs = TestbenchModel.stream_interfaces(
            signature, clocks, direction="output"
        )
        domains = {domain.name: domain.signal for domain in clocks.domains}
        input_streams = {
            stream.name: {
                "clock": domains[stream.domain],
                "valid": stream.valid,
                "ready": stream.ready,
                "payload": stream.payload,
            }
            for stream in inputs
        }
        output_valid = (
            (outputs[0].valid, domains[outputs[0].domain])
            if len(outputs) == 1
            else None
        )
        return templates.render(
            "dv/cocotb/drivers/vec_driver_stream.py.j2",
            signal_clocks=repr(CocotbTestbench._signal_clocks(signature, clocks)),
            input_streams=repr(input_streams),
            output_valid=repr(output_valid),
        )

    @staticmethod
    def render_vec_monitor(
        clocks: ClockConfig, signature: dict[str, object]
    ) -> str:
        """Render the matching cycle or stream monitor."""

        if not TestbenchModel.uses_stream_handshake(signature, clocks):
            return templates.render("dv/cocotb/drivers/vec_monitor_cycle.py.j2")
        outputs = TestbenchModel.stream_interfaces(
            signature, clocks, direction="output"
        )
        domains = {domain.name: domain.signal for domain in clocks.domains}
        output_valid = (
            (outputs[0].valid, domains[outputs[0].domain])
            if len(outputs) == 1
            else None
        )
        return templates.render(
            "dv/cocotb/drivers/vec_monitor_stream.py.j2",
            signal_clocks=repr(CocotbTestbench._signal_clocks(signature, clocks)),
            output_valid=repr(output_valid),
        )

    @staticmethod
    def render_test(top: str, clocks: ClockConfig) -> str:
        """Render the common functional-vector test lifecycle."""

        starts = "\n".join(
            f"    cocotb.start_soon(_flexsoc_clock(getattr(dut, {domain.signal!r}), "
            f"{domain.period_ns:g}, {domain.rise_ns:g}, "
            f"{(domain.fall_ns if domain.fall_ns is not None else domain.period_ns / 2.0):g}, "
            f"{domain.source_latency_ns:g}, {TestbenchModel.clock_jitter_bound_ps(domain)}, "
            f"{TestbenchModel.clock_seed_salt(domain.name)}))"
            for domain in clocks.domains
        )
        return templates.render(
            "dv/cocotb/testbench/test.py.j2",
            top=top,
            clock_starts=starts,
            vector_body=templates.render("dv/cocotb/testbench/vector_body.py.j2").rstrip(),
        )

    @staticmethod
    def _write(config: CocotbConfig, clocks: ClockConfig) -> list[Path]:
        out = config.output.resolve()
        drivers = out / "drivers"
        drivers.mkdir(parents=True, exist_ok=True)
        signature = RtlSources.parse_sv_signature(config.rtl_dir, config.top)
        registers = FunctionalFlow.register_entries_for_top(
            config.rtl_dir, config.top
        )
        sources = CocotbTestbench.collect_sources(
            config.top, config.rtl_dir.resolve(), config.ips_root
        )
        files = {
            out / "Makefile": CocotbTestbench.render_makefile(config, sources),
            out / f"{config.top}_tb.sv": CocotbTestbench.render_wrapper(
                config.top, clocks, signature, config.interface
            ),
            out / f"{config.top}_tb.py": CocotbTestbench.render_test(config.top, clocks),
            drivers / "__init__.py": "",
            drivers / "reg_driver.py": CocotbTestbench.render_reg_driver(
                config.top,
                clocks,
                signature,
                registers,
                config.interface,
                config.io_delay_pct,
            ),
            drivers / "vec_driver.py": CocotbTestbench.render_vec_driver(
                clocks, signature
            ),
            drivers / "vec_monitor.py": CocotbTestbench.render_vec_monitor(
                clocks, signature
            ),
        }
        for path, body in files.items():
            path.write_text(body.rstrip() + "\n", encoding="utf-8")
        return list(files)

    @staticmethod
    def _validate_windows(transport: RegisterTransport, clocks: ClockConfig) -> None:
        domains = {domain.name for domain in clocks.domains}
        missing = sorted(
            {window.domain for window in transport.windows if window.domain not in domains}
        )
        if missing:
            raise ValueError(
                "register window(s) require matching CLOCK_DOMAINS entries: "
                + ", ".join(missing)
            )

    @staticmethod
    def _input_defaults(
        signature: dict[str, object],
        clocks: ClockConfig,
        transport: RegisterTransport,
    ) -> str:
        control = {
            signal
            for domain in clocks.domains
            for signal in (domain.signal, domain.reset)
        }
        control.update(transport.pins)
        ready = {
            stream.ready
            for stream in TestbenchModel.stream_interfaces(
                signature, clocks, direction="output"
            )
            if stream.ready
        }
        lines = []
        for name, _ in signature.get("ports_in", []):
            if name in control:
                continue
            value = 1 if name in ready or TestbenchModel.serial_idle_high(name) else 0
            lines.append(f"    dut.{name}.value = {value}")
        return "\n".join(lines)

    @staticmethod
    def _signal_clocks(
        signature: dict[str, object], clocks: ClockConfig
    ) -> dict[str, str]:
        clock_names = {domain.signal for domain in clocks.domains}
        reset_names = {domain.reset for domain in clocks.domains}
        domains = {domain.name: domain.signal for domain in clocks.domains}
        mapping = {}
        for name, _ in [
            *signature.get("ports_in", []),
            *signature.get("ports_out", []),
        ]:
            if name in clock_names or name in reset_names:
                continue
            mapping[name] = domains[TestbenchModel.signal_domain(name, clocks)]
        return mapping

    @staticmethod
    def read_filelist(path: Path) -> list[Path]:
        if not path.exists():
            return []
        base = path.parent
        sources = []
        for raw in path.read_text(encoding="utf-8", errors="ignore").splitlines():
            line = raw.strip()
            if not line or line.startswith("#"):
                continue
            if line.startswith(("+incdir+", "-I", "+define+", "-D", "-f")):
                continue
            source = Path(line)
            sources.append(
                (base / source).resolve() if not source.is_absolute() else source.resolve()
            )
        return sources

    @staticmethod
    def collect_sources(
        top: str, rtl_dir: Path, _ips_root: Path | None = None
    ) -> list[Path]:
        rtl_dir = Path(rtl_dir)
        candidates = [
            source
            for filelist in (rtl_dir / "rtl_common.f", rtl_dir / "rtl_ip.f")
            for source in CocotbTestbench.read_filelist(filelist)
        ]
        if not candidates and (rtl_dir / "rtl_list.f").exists():
            candidates = CocotbTestbench.read_filelist(rtl_dir / "rtl_list.f")
        if not candidates:
            candidates = sorted(rtl_dir.glob("*.sv")) + sorted(rtl_dir.glob("*.v"))
        ordered = []
        seen = set()
        for source in [*candidates, rtl_dir / f"{top}.sv"]:
            resolved = source.resolve()
            key = resolved.as_posix()
            if resolved.exists() and key not in seen:
                seen.add(key)
                ordered.append(resolved)
        return ordered

    @staticmethod
    def render_source_block(paths: Sequence[Path]) -> str:
        if not paths:
            return "# No RTL sources found; run the flist step first.\nVERILOG_SOURCES :="
        lines = ["# RTL sources expanded from rtl_common.f and rtl_ip.f", "VERILOG_SOURCES := \\"]
        lines.extend(f"  {path.resolve()} \\" for path in paths[:-1])
        lines.append(f"  {paths[-1].resolve()}")
        return "\n".join(lines)

    @staticmethod
    def render_makefile(config: CocotbConfig, sources: Sequence[Path]) -> str:
        repo = CocotbTestbench.repo_root()
        rtl_dir = config.rtl_dir.resolve()
        ips_root = (config.ips_root or repo / "hw" / "ips").resolve()
        include_dirs = [
            rtl_dir,
            ips_root / "pkgs",
            ips_root / "prim",
            ips_root / "prim_opentitan",
        ]
        if config.interface == "tlul":
            include_dirs.append(ips_root / "tlul")
        elif config.interface == "axi_lite":
            pulp = repo / "vendor" / "pulp"
            include_dirs.extend(
                (pulp / "axi" / "include", pulp / "register_interface" / "include")
            )
        return templates.render(
            "dv/cocotb/common/Makefile.j2",
            simulator=config.simulator,
            top=config.top,
            gls_block=CocotbTestbench.render_gls_make_block(
                f"../../../../syn/$(PDK)/{config.top}_synth.v"
            ),
            rtl_sources="\n".join(
                f"  {line}" if line else ""
                for line in CocotbTestbench.render_source_block(sources).splitlines()
            ),
            includes=" ".join(f"-I{path}" for path in include_dirs),
            tb_source=(config.output.resolve() / f"{config.top}_tb.sv").resolve(),
        )

    @staticmethod
    def render_gls_make_block(default_netlist: str) -> str:
        return "\n".join(
            (
                "  SIM := icarus",
                "  SIM_BUILD ?= sim_build/gls",
                "  TIMING_MODE ?= zero",
                "  GLS_UNIT_DELAY_DEFINE ?= 1",
                "  GLS_INTERCONNECT ?= 0",
                "  SDF_FILE ?=",
                "  GLS_PACKAGES ?=",
                "  GLS_MODELS ?=",
                f"  GLS_NETLIST ?= {default_netlist}",
                "",
                "  VERILOG_SOURCES += $(GLS_PACKAGES)",
                "  VERILOG_SOURCES += $(GLS_MODELS)",
                "  VERILOG_SOURCES += $(GLS_NETLIST)",
                "  COMPILE_ARGS += -g2012 -DSIM -DSYN -DFLEXSOC_GLS_EXTERNAL_MODELS -DFLEXSOC_COCOTB_WAVE_OWNER",
                "",
                "  ifeq ($(TIMING_MODE),zero)",
                "    COMPILE_ARGS += -DFUNCTIONAL -DUNIT_DELAY=\\#0 -gno-specify",
                "  else ifeq ($(TIMING_MODE),unit)",
                "    COMPILE_ARGS += -DFUNCTIONAL -gno-specify -DUNIT_DELAY=\\#$(GLS_UNIT_DELAY_DEFINE)",
                "  else ifneq ($(filter $(TIMING_MODE),min typ max),)",
                "    ifeq ($(strip $(SDF_FILE)),)",
                "      $(error SDF_FILE is required when TIMING_MODE=$(TIMING_MODE))",
                "    endif",
                "    COMPILE_ARGS += -gspecify -T$(TIMING_MODE) -DFLEXSOC_ENABLE_SDF",
                "    ifeq ($(GLS_INTERCONNECT),1)",
                "      COMPILE_ARGS += -ginterconnect",
                "    endif",
                "    ifeq ($(TIMING_MODE),min)",
                "      COMPILE_ARGS += -DFLEXSOC_SDF_MIN",
                "    else ifeq ($(TIMING_MODE),typ)",
                "      COMPILE_ARGS += -DFLEXSOC_SDF_TYP",
                "    else",
                "      COMPILE_ARGS += -DFLEXSOC_SDF_MAX",
                "    endif",
                "    COCOTB_PLUSARGS += +SDF=$(abspath $(SDF_FILE))",
                "  else",
                "    $(error TIMING_MODE must be zero, unit, min, typ, or max)",
                "  endif",
            )
        )
