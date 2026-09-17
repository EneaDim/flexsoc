"""Cocotb testbench scaffold rendering and generation."""

from __future__ import annotations

import re
from dataclasses import dataclass, replace
from pathlib import Path
from typing import Sequence

from flexsoc.backend.core import ClockConfig, ClockDomain, Files, RtlSources, templates
from flexsoc.backend.design.ip.regs import RegsFlow
from ..func.functional import FunctionalFlow
from .common import RegisterTransport, TestbenchModel

@dataclass(frozen=True, slots=True)
class CocotbConfig:
    """Configuration used to generate one cocotb testbench directory."""

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


# Multiclock rendering uses the same generated scaffold layout.


@dataclass(slots=True)
class CocotbTestbench:
    """Generate the canonical cocotb functional testbench scaffold."""

    def setup(
        self, config: CocotbConfig, *, clocks: ClockConfig | None = None
    ) -> list[Path]:
        return CocotbTestbench.write_cocotb_scaffold(config, clocks=clocks)

    @staticmethod
    def repo_root() -> Path:
        """Return the checkout root inferred from ``src/flexsoc/backend/dv``."""
    
        return Path(__file__).resolve().parents[4]

    @staticmethod
    def find_top_file(rtl_dir: Path, top: str) -> Path | None:
        """Find the SystemVerilog file that defines the selected top module."""
    
        direct = rtl_dir / f"{top}.sv"
        if direct.exists():
            return direct
        return next((path for path in rtl_dir.rglob("*.sv") if path.stem == top), None)

    @staticmethod
    def parse_decl(prefix: str, line: str) -> tuple[str | int, list[str]]:
        """Parse one compact Verilog port declaration into width and names."""
    
        tokens = line[len(prefix) :].strip().split()
        if tokens and tokens[0] in {"logic", "wire", "reg"}:
            tokens = tokens[1:]
        width: str | int = 1
        if tokens and tokens[0].startswith("["):
            width = tokens.pop(0)
        elif len(tokens) > 1 and ("::" in tokens[0] or tokens[0].endswith("_t")):
            width = tokens.pop(0)
        return width, [token.rstrip(",") for token in tokens if token.rstrip(",")]

    @staticmethod
    def parse_top_ports(top_file: Path | None) -> dict[str, list]:
        """Parse simple top-level ports used by the generated wrapper."""
    
        empty = {"clk": [], "rst": [], "inputs": [], "outputs": []}
        if top_file is None:
            return empty
        try:
            text = top_file.read_text(encoding="utf-8", errors="ignore")
        except OSError:
            return empty
        match = re.search(r"module\s+\w+\s*\((.*?)\);\s", text, flags=re.S | re.M)
        header = text.split(");", 1)[0] if not match else match.group(1)
        lines = [re.sub(r"//.*", "", line).strip() for line in header.splitlines()]
        info: dict[str, list] = {"clk": [], "rst": [], "inputs": [], "outputs": []}
        for line in filter(None, lines):
            if line.startswith("input "):
                width, names = CocotbTestbench.parse_decl("input ", line)
                for name in names:
                    if "clk" in name:
                        info["clk"].append(name)
                    if "rst" in name:
                        info["rst"].append(name)
                    info["inputs"].append({"name": name, "width": width})
            elif line.startswith("output "):
                width, names = CocotbTestbench.parse_decl("output ", line)
                info["outputs"].extend({"name": name, "width": width} for name in names)
        return info

    @staticmethod
    def render_width(width: str | int) -> str:
        """Render a SystemVerilog logic declaration prefix from a parsed width."""
    
        return "logic" if width in {1, "1"} else f"logic {width}"

    @staticmethod
    def render_extra_port_declarations(info: dict[str, list]) -> str:
        """Render non-control DUT ports needed by the cocotb wrapper."""
    
        control = set(info.get("clk", [])) | set(info.get("rst", [])) | {"tl_i", "tl_o"}
        decls: list[str] = []
        for entry in [*info.get("inputs", []), *info.get("outputs", [])]:
            name = entry.get("name", "")
            if not name or name in control or name.startswith(("clk", "rst")) or "::" in name:
                continue
            decls.append(f"  {CocotbTestbench.render_width(entry.get('width', 1))} {name};")
        return "\n".join(decls)

    @staticmethod
    def render_extra_input_initializers(info: dict[str, list]) -> str:
        """Initialize non-control DUT inputs before reset and configuration."""
    
        control = set(info.get("clk", [])) | set(info.get("rst", [])) | {"tl_i", "tl_o"}
        lines: list[str] = []
        for entry in info.get("inputs", []):
            name = entry.get("name", "")
            if not name or name in control or name.startswith(("clk", "rst")) or "::" in name:
                continue
            value = "'1" if TestbenchModel.serial_idle_high(name) else "'0"
            lines.append(f"    {name} = {value};")
        return "\n".join(lines)

    @staticmethod
    def read_filelist(path: Path) -> list[Path]:
        """Read an RTL filelist and return ordered source paths."""
    
        if not path.exists():
            return []
        base = path.parent
        sources: list[Path] = []
        for raw in path.read_text(encoding="utf-8", errors="ignore").splitlines():
            line = raw.strip()
            if not line or line.startswith("#"):
                continue
            if line.startswith(("+incdir+", "-I", "+define+", "-D", "-f")):
                continue
            source = Path(line)
            sources.append((base / source).resolve() if not source.is_absolute() else source.resolve())
        return sources

    @staticmethod
    def append_existing(paths: list[Path], seen: set[str], path: Path) -> None:
        """Append an existing source only once while preserving filelist order."""
    
        resolved = path.resolve()
        key = resolved.as_posix()
        if resolved.exists() and key not in seen:
            seen.add(key)
            paths.append(resolved)

    @staticmethod
    def collect_sources(top: str, rtl_dir: Path, _ips_root: Path | None = None) -> list[Path]:
        """Collect Cocotb RTL sources from clean common/IP filelists."""
    
        rtl_dir = Path(rtl_dir)
        lists = [rtl_dir / "rtl_common.f", rtl_dir / "rtl_ip.f"]
        candidates = [src for flist in lists for src in CocotbTestbench.read_filelist(flist)]
        if not candidates and (rtl_dir / "rtl_list.f").exists():
            candidates = CocotbTestbench.read_filelist(rtl_dir / "rtl_list.f")
        if not candidates:
            candidates = sorted(rtl_dir.glob("*.sv")) + sorted(rtl_dir.glob("*.v"))
        seen: set[str] = set()
        ordered: list[Path] = []
        for source in candidates:
            CocotbTestbench.append_existing(ordered, seen, source)
        for tail in (rtl_dir / "tl_main_pkg.sv", rtl_dir / "xbar_main.sv", rtl_dir / f"{top}.sv"):
            CocotbTestbench.append_existing(ordered, seen, tail)
        return ordered

    @staticmethod
    def render_source_block(paths: Sequence[Path], var_name: str = "VERILOG_SOURCES") -> str:
        """Render Cocotb VERILOG_SOURCES from the resolved RTL filelist."""
    
        if not paths:
            return f"# No RTL sources found; run the flist step first.\n{var_name} :="
        lines = ["# RTL sources expanded from rtl_common.f and rtl_ip.f", f"{var_name} := \\"]
        lines.extend(f"  {path.resolve()} \\" for path in paths[:-1])
        lines.append(f"  {paths[-1].resolve()}")
        return "\n".join(lines)

    @staticmethod
    def render_gls_make_block(default_netlist: str) -> str:
        """Render the gate-level branch nested under ``ifeq ($(GATES),yes)``."""
    
        return "\n".join((
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
        ))

    @staticmethod
    def render_makefile(cfg: CocotbConfig, sources: Sequence[Path]) -> str:
        """Render the cocotb Makefile for RTL or gate-level simulation."""
    
        interface = RegsFlow.normalize_register_interface(cfg.interface)
        repo = CocotbTestbench.repo_root()
        out_dir = cfg.output.resolve()
        rtl_dir = cfg.rtl_dir.resolve()
        ips_root = (cfg.ips_root or repo / "hw" / "ips").resolve()
        include_dirs = [ips_root / "pkgs", ips_root / "prim", ips_root / "prim_opentitan"]
        if interface == "tlul":
            include_dirs.append(ips_root / "tlul")
        elif interface == "axi_lite":
            pulp_root = repo / "vendor" / "pulp"
            include_dirs += [pulp_root / "axi" / "include", pulp_root / "register_interface" / "include"]
    
        return templates.render(
            "dv/cocotb/common/Makefile.j2",
            simulator=cfg.simulator,
            top=cfg.top,
            gls_block=CocotbTestbench.render_gls_make_block(f"../../../../syn/$(PDK)/{cfg.top}_synth.v"),
            rtl_sources="\n".join(
                f"  {line}" if line else ""
                for line in CocotbTestbench.render_source_block(sources).splitlines()
            ),
            includes=" ".join(f"-I{path}" for path in [rtl_dir, *include_dirs]),
            tb_source=(out_dir / f"{cfg.top}_tb.sv").resolve(),
        )

    @staticmethod
    def render_pipeline_model_py(top: str) -> str:
        """Render the reference model used by generated cocotb tests."""
    
        return templates.render("dv/cocotb/model/pipeline_model.py.j2", top=top)

    @staticmethod
    def _normalise_register_entries(registers) -> dict[str, int]:
        """Best-effort conversion of HJSON register metadata into a name/address map."""
    
        regmap: dict[str, int] = {}
    
        for entry in registers or []:
            name = None
            addr = None
    
            if isinstance(entry, dict):
                name = entry.get("name") or entry.get("reg") or entry.get("key")
                addr = (
                    entry.get("offset")
                    or entry.get("addr")
                    or entry.get("address")
                    or entry.get("byte_offset")
                )
            else:
                name = getattr(entry, "name", None)
                addr = (
                    getattr(entry, "offset", None)
                    or getattr(entry, "addr", None)
                    or getattr(entry, "address", None)
                    or getattr(entry, "byte_offset", None)
                )
    
            if not name or addr is None:
                continue
    
            try:
                value = int(str(addr), 0) & 0xFFFFFFFF
            except ValueError:
                continue
    
            key = str(name)
            regmap[key] = value
            regmap[key.upper()] = value
            regmap[key.split(".")[-1].upper()] = value
    
        return regmap

    @staticmethod
    def render_reg_driver_py(
        registers=None, period_ns: float = 10.0, io_delay_pct: float = 0.2, interface: str = "tlul"
    ) -> str:
        """Render generic cocotb register helpers using the shared IO timing intent."""
    
        register_addrs = CocotbTestbench._normalise_register_entries(registers)
        drive_ns, sample_ns = TestbenchModel.phases(period_ns, io_delay_pct)
        transport = RegisterTransport.from_name(interface)
        transport_helpers = templates.render(f"{transport.template_root('cocotb')}/single.py.j2")
        return templates.render(
            "dv/cocotb/drivers/reg_driver.py.j2",
            multiclock=False, register_addrs=repr(register_addrs),
            tb_period_ps=int(round(period_ns * 1000)),
            tb_drive_ps=int(round(drive_ns * 1000)),
            tb_sample_ps=int(round(sample_ns * 1000)),
            transport_helpers=transport_helpers.rstrip(),
        )

    @staticmethod
    def render_vec_monitor_py() -> str:
        """Render a generic cocotb expected-output monitor."""
    
        return templates.render("dv/cocotb/drivers/vec_monitor.py.j2", multiclock=False)

    @staticmethod
    def render_vec_driver_py() -> str:
        """Render a generic cocotb input-vector driver."""
    
        return templates.render("dv/cocotb/drivers/vec_driver.py.j2", multiclock=False)

    @staticmethod
    def render_python_test(
        top: str,
        clk: str,
        rst: str,
        rst_active: str,
        period_ns: float,
        rise_ns: float = 0.0,
        fall_ns: float | None = None,
        source_latency_ns: float = 0.0,
        reset_domain: str = "core",
        setup_uncertainty_ns: float = 0.0,
        hold_uncertainty_ns: float = 0.0,
    ) -> str:
        """Render the generated single-clock cocotb test module."""
    
        fall_ns = period_ns / 2.0 if fall_ns is None else fall_ns
        clock = ClockDomain(
            reset_domain, clk, rst, period_ns, rst_active,
            rise_ns=rise_ns, fall_ns=fall_ns, source_latency_ns=source_latency_ns,
            setup_uncertainty_ns=setup_uncertainty_ns,
            hold_uncertainty_ns=hold_uncertainty_ns,
        )
        initial_low, high_ns, low_ns = TestbenchModel.clock_waveform_times(clock)
        jitter_bound_ps = TestbenchModel.clock_jitter_bound_ps(clock)
        return templates.render(
            "dv/cocotb/testbench/test.py.j2",
            multiclock=False, top=top,
            clk=clk,
            reset_domain=reset_domain,
            reset_domains=repr({reset_domain: (clk, rst, rst_active)}),
            clock_salt=TestbenchModel.clock_seed_salt(clock.name),
            jitter_bound_ps=jitter_bound_ps,
            jitter_span=2 * jitter_bound_ps + 1,
            initial_low=f"{initial_low:g}",
            high_ns=f"{high_ns:g}",
            low_ps=int(round(low_ns * 1000.0)),
        )

    @staticmethod
    def render_reg_iface_wrapper(cfg: CocotbConfig) -> str:
        """Render a flat cocotb proxy for the canonical reg_req/reg_rsp transport."""
    
        port_info = CocotbTestbench.parse_top_ports(CocotbTestbench.find_top_file(cfg.rtl_dir, cfg.top))
        bus_tokens = {"reg_req_t", "reg_req_i", "reg_rsp_t", "reg_rsp_o"}
        clean_info = {
            key: ([entry for entry in value if entry.get("name") not in bus_tokens]
                  if key in {"inputs", "outputs"} else value)
            for key, value in port_info.items()
        }
        return templates.render(
            "dv/cocotb/register/reg_iface/wrapper.sv.j2",
            top=cfg.top, clk=cfg.clk, rst=cfg.rst,
            extra_decls=CocotbTestbench.render_extra_port_declarations(clean_info),
            extra_init=CocotbTestbench.render_extra_input_initializers(clean_info),
        )

    @staticmethod
    def render_tlul_wrapper(cfg: CocotbConfig) -> str:
        """Render a package-free TL-UL wrapper used by RTL and gate cocotb runs."""
    
        port_info = CocotbTestbench.parse_top_ports(CocotbTestbench.find_top_file(cfg.rtl_dir, cfg.top))
        return templates.render(
            "dv/cocotb/register/adapters/tlul/wrapper.sv.j2",
            top=cfg.top, clk=cfg.clk, rst=cfg.rst,
            extra_decls=CocotbTestbench.render_extra_port_declarations(port_info),
            extra_init=CocotbTestbench.render_extra_input_initializers(port_info),
            tlul_helpers=TestbenchModel.render_packed_tlul_helpers("  "),
        )

    @staticmethod
    def render_axi_lite_wrapper(cfg: CocotbConfig) -> str:
        """Render scalar cocotb proxies around the packed AXI4-Lite DUT boundary."""
    
        port_info = CocotbTestbench.parse_top_ports(CocotbTestbench.find_top_file(cfg.rtl_dir, cfg.top))
        clean_info = {
            key: ([entry for entry in value if entry.get("name") not in {"axi_lite_i", "axi_lite_o"}]
                  if key in {"inputs", "outputs"} else value)
            for key, value in port_info.items()
        }
        proxy_decls, proxy_assigns, proxy_init = TestbenchModel.axi_lite_cocotb_proxy(f"{cfg.top}_reg_pkg")
        return templates.render(
            "dv/cocotb/register/adapters/axi_lite/wrapper.sv.j2",
            top=cfg.top, clk=cfg.clk, rst=cfg.rst,
            extra_decls=CocotbTestbench.render_extra_port_declarations(clean_info),
            extra_init=CocotbTestbench.render_extra_input_initializers(clean_info),
            proxy_decls=proxy_decls, proxy_assigns=proxy_assigns, proxy_init=proxy_init,
        )

    @staticmethod
    def cocotb_sv_text(
        top: str, clocks: ClockConfig, interface: str = "tlul", *, signature: dict[str, object]
    ) -> str:
        """Render the multiclock cocotb wrapper from the top-level contract."""
    
        interface = RegsFlow.normalize_register_interface(interface)
        windows = TestbenchModel.register_windows(interface, signature)
        clock_decls = "\n".join(
            f"  logic {domain.signal};\n  logic {domain.reset};" for domain in clocks.domains
        )
        bus_decls, bus_helpers, transport = TestbenchModel.render_register_boundary(
            top, interface, windows, cocotb=True
        )
        root = transport.template_root("cocotb")
        return templates.render(
            f"{root}/wrapper_multiclock.sv.j2",
            top=top,
            clock_decls=clock_decls,
            bus_decls=bus_decls,
            signal_decls=TestbenchModel.render_signal_declarations(signature, clocks, transport),
            bus_helpers=bus_helpers,
            dut_pins=TestbenchModel.render_dut_pins(signature),
        )

    @staticmethod
    def _nclock_cocotb_bus_py(interface: str) -> tuple[str, str, str]:
        """Render defaults/write/read snippets for one multiclock CSR transport."""
    
        interface = RegsFlow.normalize_register_interface(interface)
        root = RegisterTransport.from_name(interface).template_root("cocotb")
        return tuple(
            templates.render(f"{root}/{name}.py.j2")
            for name in ("defaults", "write", "read")
        )

    @staticmethod
    def _multiclock_input_defaults(
        signature: dict[str, object], clocks: ClockConfig, interface: str
    ) -> str:
        """Initialize generic non-control DUT inputs deterministically."""
    
        transport = RegisterTransport.from_name(interface, TestbenchModel.register_windows(interface, signature))
        control = {domain.signal for domain in clocks.domains} | {domain.reset for domain in clocks.domains}
        control.update(transport.pins)
        ready = {stream.ready for stream in TestbenchModel.stream_interfaces(signature, clocks, direction="output") if stream.ready}
        lines = []
        for name, _ in signature.get("ports_in", []):
            if name in control:
                continue
            value = 1 if name in ready or TestbenchModel.serial_idle_high(name) else 0
            lines.append(f"    dut.{name}.value = {value}")
        return "\n".join(lines)

    @staticmethod
    def cocotb_reg_driver_py_text(
        top: str,
        clocks: ClockConfig,
        io_delay_pct: float = 0.2,
        interface: str = "tlul",
        *,
        signature: dict[str, object],
        registers: Sequence[dict[str, object]] = (),
    ) -> str:
        """Render multiclock register helpers from discovered windows and regmap."""
    
        del top
        interface = RegsFlow.normalize_register_interface(interface)
        windows = TestbenchModel.register_windows(interface, signature)
        domains = {domain.name for domain in clocks.domains}
        missing = [window for window in windows if window not in domains]
        if missing:
            raise ValueError(
                "register window(s) require matching CLOCK_DOMAINS entries: " + ", ".join(missing)
            )
        addr_map = {window: {} for window in windows}
        for reg in registers:
            domain = str(reg.get("clock", ""))
            if domain in addr_map:
                addr_map[domain][str(reg["name"]).upper()] = int(reg["addr"])
    
        clock_map = {domain.name: domain.signal for domain in clocks.domains}
        reset_map = {
            domain.name: (domain.signal, domain.reset, domain.reset_polarity)
            for domain in clocks.domains
        }
        period_ps = {domain.signal: int(round(domain.period_ns * 1000)) for domain in clocks.domains}
        drive_ps: dict[str, int] = {}
        sample_ps: dict[str, int] = {}
        for domain in clocks.domains:
            drive_ns, sample_ns = TestbenchModel.phases(domain.period_ns, io_delay_pct)
            drive_ps[domain.signal] = int(round(drive_ns * 1000))
            sample_ps[domain.signal] = int(round(sample_ns * 1000))
        defaults, write, read = CocotbTestbench._nclock_cocotb_bus_py(interface)
        return templates.render(
            "dv/cocotb/drivers/reg_driver.py.j2",
            multiclock=True, clock_map=repr(clock_map),
            period_ps=repr(period_ps), drive_ps=repr(drive_ps), sample_ps=repr(sample_ps),
            reset_map=repr(reset_map), primary=repr(clocks.domains[0].signal),
            settle=repr(clocks.domains[0].signal), windows=repr(windows),
            addr_map=repr(addr_map), default_domain=repr(windows[0] if len(windows) == 1 else None),
            input_defaults=CocotbTestbench._multiclock_input_defaults(signature, clocks, interface),
            bus_defaults=defaults.rstrip(), bus_write=write.rstrip(), bus_read=read.rstrip(),
        )

    @staticmethod
    def _cocotb_signal_clocks(signature: dict[str, object], clocks: ClockConfig) -> dict[str, str]:
        """Map each non-clock top-level signal to its inferred driving/sample clock."""
    
        clock_names = {domain.signal for domain in clocks.domains}
        reset_names = {domain.reset for domain in clocks.domains}
        mapping = {}
        for name, _ in [*signature.get("ports_in", []), *signature.get("ports_out", [])]:
            if name in clock_names or name in reset_names:
                continue
            domain = TestbenchModel.signal_domain(name, clocks)
            mapping[name] = next(item.signal for item in clocks.domains if item.name == domain)
        return mapping

    @staticmethod
    def cocotb_vec_driver_py_text(
        top: str, clocks: ClockConfig, *, signature: dict[str, object]
    ) -> str:
        """Render generic multiclock vector commands from top-level streams/signals."""
    
        del top
        inputs = TestbenchModel.stream_interfaces(signature, clocks, direction="input")
        outputs = TestbenchModel.stream_interfaces(signature, clocks, direction="output")
        domains = {domain.name: domain.signal for domain in clocks.domains}
        input_streams = {
            stream.name: {
                "clock": domains[stream.domain], "valid": stream.valid, "ready": stream.ready,
                "payload": stream.payload,
            }
            for stream in inputs
        }
        output_valid = (outputs[0].valid, domains[outputs[0].domain]) if len(outputs) == 1 else None
        return templates.render(
            "dv/cocotb/drivers/vec_driver.py.j2", multiclock=True,
            signal_clocks=repr(CocotbTestbench._cocotb_signal_clocks(signature, clocks)),
            input_streams=repr(input_streams), output_valid=repr(output_valid),
        )

    @staticmethod
    def cocotb_monitor_py_text(
        top: str, clocks: ClockConfig, *, signature: dict[str, object]
    ) -> str:
        """Render generic multiclock expected-output monitoring."""
    
        del top
        outputs = TestbenchModel.stream_interfaces(signature, clocks, direction="output")
        domains = {domain.name: domain.signal for domain in clocks.domains}
        output_valid = (outputs[0].valid, domains[outputs[0].domain]) if len(outputs) == 1 else None
        return templates.render(
            "dv/cocotb/drivers/vec_monitor.py.j2", multiclock=True,
            signal_clocks=repr(CocotbTestbench._cocotb_signal_clocks(signature, clocks)),
            output_valid=repr(output_valid),
        )

    @staticmethod
    def cocotb_py_text(top: str, clocks: ClockConfig) -> str:
        """Render the multiclock cocotb test entry point."""
    
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
            multiclock=True, top=top, clock_starts=starts,
        )

    @staticmethod
    def _write_cocotb_scaffold_impl(
        cfg: CocotbConfig, clocks: ClockConfig | None = None
    ) -> list[Path]:
        """Write the cocotb scaffold and return generated paths."""
    
        clocks = clocks or ClockConfig.from_values()
        cfg = replace(cfg, interface=RegsFlow.normalize_register_interface(cfg.interface))
        out_dir = cfg.output.resolve()
        drivers = out_dir / "drivers"
        drivers.mkdir(parents=True, exist_ok=True)
        sources = CocotbTestbench.collect_sources(cfg.top, cfg.rtl_dir.resolve(), cfg.ips_root)
        files = {
            out_dir / "Makefile": CocotbTestbench.render_makefile(cfg, sources),
            drivers / "__init__.py": "",
        }
    
        if clocks.multiclock:
            signature = RtlSources.parse_sv_signature(cfg.rtl_dir, cfg.top)
            registers = FunctionalFlow.register_entries_for_top(cfg.rtl_dir, cfg.top)
            files.update({
                out_dir / f"{cfg.top}_tb.sv": CocotbTestbench.cocotb_sv_text(
                    cfg.top, clocks, cfg.interface, signature=signature
                ),
                drivers / "reg_driver.py": CocotbTestbench.cocotb_reg_driver_py_text(
                    cfg.top, clocks, cfg.io_delay_pct, cfg.interface,
                    signature=signature, registers=registers,
                ),
                drivers / "vec_driver.py": CocotbTestbench.cocotb_vec_driver_py_text(
                    cfg.top, clocks, signature=signature
                ),
                drivers / "vec_monitor.py": CocotbTestbench.cocotb_monitor_py_text(
                    cfg.top, clocks, signature=signature
                ),
                out_dir / f"{cfg.top}_tb.py": CocotbTestbench.cocotb_py_text(cfg.top, clocks),
            })
        else:
            hjson_path = FunctionalFlow.hjson_path(cfg.rtl_dir, cfg.top)
            registers = FunctionalFlow.register_entries(hjson_path)
            clock_domain = next(
                (domain for domain in clocks.domains if domain.signal == cfg.clk or domain.reset == cfg.rst),
                clocks.domains[0],
            )
            files.update({
                drivers / "reg_driver.py": CocotbTestbench.render_reg_driver_py(
                    registers, clock_domain.period_ns, cfg.io_delay_pct, cfg.interface
                ),
                drivers / "vec_driver.py": CocotbTestbench.render_vec_driver_py(),
                drivers / "vec_monitor.py": CocotbTestbench.render_vec_monitor_py(),
                out_dir / f"{cfg.top}_tb.py": CocotbTestbench.render_python_test(
                    cfg.top, cfg.clk, cfg.rst, cfg.rst_active, clock_domain.period_ns,
                    clock_domain.rise_ns, clock_domain.fall_ns, clock_domain.source_latency_ns,
                    clock_domain.name,
                    setup_uncertainty_ns=clock_domain.setup_uncertainty_ns,
                    hold_uncertainty_ns=clock_domain.hold_uncertainty_ns,
                ),
                out_dir / f"{cfg.top}_tb.sv": {
                    "tlul": CocotbTestbench.render_tlul_wrapper,
                    "reg_iface": CocotbTestbench.render_reg_iface_wrapper,
                    "axi_lite": CocotbTestbench.render_axi_lite_wrapper,
                }[cfg.interface](cfg),
            })
    
        for path, text in files.items():
            path.write_text(text.rstrip() + "\n", encoding="utf-8")
        return list(files)

    @staticmethod
    def write_cocotb_scaffold(
        config: CocotbConfig, clocks: ClockConfig | None = None
    ) -> list[Path]:
        """Recreate the complete machine-owned cocotb scaffold."""
    
        clocks = clocks or ClockConfig.from_values()
        config = replace(config, interface=RegsFlow.normalize_register_interface(config.interface))
        with Files.replace_generated_tree(config.output):
            return CocotbTestbench._write_cocotb_scaffold_impl(config, clocks)

