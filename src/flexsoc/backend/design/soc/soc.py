"""SoC configuration, generation, FuseSoC and software scaffold flow."""

from __future__ import annotations

import json
import re
import shutil
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Any

_cfg_SUPPORTED_HOSTS = {"ibex", "uart"}
KNOWN_BASES = {
    "uart": 0x80000000,
    "uart_master": 0x80000000,
    "pwm": 0x80020000,
    "gpio": 0x80040000,
    "rv_timer": 0x80060000,
    "spi_host": 0x80080000,
}
HOST_IPS = {"ibex", "ibex_top_tracing"}


@dataclass(frozen=True, slots=True)
class SoCDevice:
    """Describe one memory-mapped device used by generated SoC flows."""

    name: str
    base: str
    size: str = "0x00001000"
    from_lr: str = "False"

    def make_call(self) -> str:
        """Render this device as one Make `add_device` evaluation."""

        return f"$(eval $(call add_device,{self.name},{self.base},{self.size},{self.from_lr}))"

    def args(self) -> tuple[str, str, str, str]:
        """Return CLI argument fields consumed by SoC backend generators."""

        return self.name, self.base, self.size, self.from_lr


@dataclass(frozen=True, slots=True)
class SoCConfig:
    """Resolved host and memory map emitted for one SoC run."""

    host: str
    devices: tuple[SoCDevice, ...]

    def args(self) -> tuple[str, ...]:
        """Return flat generator arguments for host and devices."""

        parts = ["--host", self.host]
        for device in self.devices:
            parts.extend(("--device", *device.args()))
        return tuple(parts)


@dataclass(frozen=True, slots=True)
class SoCStartConfig:
    """Configuration required to initialize a SoC run."""

    workspace: Path
    run_top: str
    run_id: str

    @property
    def run_dir(self) -> Path:
        """Return the canonical run directory for this SoC build."""

        return self.workspace.expanduser().resolve() / "runs" / self.run_top / self.run_id

    @property
    def ips_dir(self) -> Path:
        """Return the directory containing staged IP bundles."""

        return self.run_dir / "ips"


@dataclass(frozen=True, slots=True)
class XbarDevice:
    """Describe one device node attached to the generated crossbar."""

    name: str
    base_addr: str
    size_byte: str
    from_lr: str = "False"


@dataclass(frozen=True, slots=True)
class XbarConfig:
    """Group all inputs needed to render one crossbar configuration."""

    host: str
    devices: tuple[XbarDevice, ...]


_gen_SUPPORTED_HOSTS = {"ibex", "uart"}


@dataclass(frozen=True, slots=True)
class SoCModule:
    """Describe one generated SoC device and where its RTL should be resolved."""

    name: str
    base_addr: str
    size_bytes: str
    from_lowrisc: bool = False


@dataclass(frozen=True, slots=True)
class SoCGenerationConfig:
    """Collect the inputs needed to generate SoC RTL and simulator files."""

    host: str
    devices: tuple[SoCModule, ...]
    root: Path = Path(".")
    output: Path = Path("soc.sv")

    @property
    def run_dir(self) -> Path:
        """Return the run directory inferred from the RTL output path."""

        return self.output.resolve().parent.parent

    @property
    def tb_dir(self) -> Path:
        """Return the generated SoC testbench directory."""

        return self.run_dir / "tb"


@dataclass(frozen=True, slots=True)
class SoCSoftwareConfig:
    """Collect paths and options used to build the SoC software scaffold."""

    workspace: Path
    run_top: str
    run_id: str
    host: str

    @property
    def _software_run_dir(self) -> Path:
        """Return the canonical run directory for this software scaffold."""

        return SocFlow._software_run_dir(self.workspace, self.run_top, self.run_id)


class SocFlow:
    """Generate SoC integration, FuseSoC metadata and software collateral."""

    def __init__(self, project_root: Path, runner=None):
        from ...core import ToolRunner
        self.project_root = Path(project_root).resolve()
        self.runner = runner or ToolRunner(project_root=self.project_root)

    def resolve_config(self, **kwargs) -> SoCConfig:
        """Resolve host and device configuration from loaded IP metadata."""
        return SocFlow.resolve_soc_config(**kwargs)

    def start(self, config: SoCStartConfig) -> Path:
        """Initialize a SoC run from packaged IPs."""
        return SocFlow.initialize_soc_run(config)

    def init_xbar(self, config: XbarConfig, output: Path) -> Path:
        """Write the tlgen crossbar input configuration."""
        return SocFlow.write_json(output, SocFlow.build_xbar_config(config))

    def generate(self, config: SoCGenerationConfig) -> Path:
        """Generate the SoC top and simulation wrappers."""
        return SocFlow.generate_soc(config)

    def generate_fusesoc(self, project: str, top: str, rtl_dir: Path, output_dir: Path) -> Path:
        """Generate the CAPI2 FuseSoC core metadata."""
        return SocFlow.write_core(project, top, rtl_dir, output_dir)

    def generate_software(self, config: SoCSoftwareConfig):
        """Generate the SoC software workspace from staged IP drivers."""
        return SocFlow.write_soc_software(config)


    def run_target(self, target, context, *, on: str = "local"):
        """Execute one atomic SoC target from the current backend context."""

        paths, values = context.paths, context.values
        host = values.get("HOST", "uart")
        action = target.action or ""

        if action == "start":
            return self.start(SoCStartConfig(context.workspace, paths.run_top, paths.run_id))
        if action == "config":
            config = self.resolve_config(
                workspace=context.workspace, run_top=paths.run_top, run_id=paths.run_id,
                default_host=host, mode=values.get("SOC_CFG_MODE", "builtin"),
            )
            print(config)
            return config
        if action == "software":
            return self.generate_software(SoCSoftwareConfig(context.workspace, paths.run_top, paths.run_id, host))
        if action == "fusesoc_init":
            return self.generate_fusesoc(
                values.get("PRJ", "flexsoc"), paths.top, paths.rtl,
                paths.run / "fusesoc" / host / "cores",
            )
        if action == "xbar_init":
            config = self.resolve_config(
                workspace=context.workspace, run_top=paths.run_top, run_id=paths.run_id,
                default_host=host, mode=values.get("SOC_CFG_MODE", "builtin"),
            )
            devices = tuple(SocFlow.parse_device_rows([list(device.args()) for device in config.devices]))
            return self.init_xbar(XbarConfig(host, devices), paths.run / "soc" / "xbar.hjson")
        if action == "xbar_build":
            config = paths.run / "soc" / "xbar.hjson"
            output = paths.rtl / "xbar"
            output.mkdir(parents=True, exist_ok=True)
            return self.run_tool(
                (sys.executable, str(context.project_root / "src" / "util" / "tlgen.py"), "-t", str(output), str(config)),
                cwd=context.project_root, log=paths.logs / "soc" / "xbar.log",
                inputs=(config,), outputs=(output,), on=on,
            ).returncode
        if action in {"generate", "generate_uart", "generate_ibex"}:
            selected_host = "ibex" if action == "generate_ibex" else "uart" if action == "generate_uart" else host
            config = self.resolve_config(
                workspace=context.workspace, run_top=paths.run_top, run_id=paths.run_id,
                default_host=selected_host, mode=values.get("SOC_CFG_MODE", "builtin"),
            )
            devices = tuple(
                SoCModule(device.name, device.base, device.size, device.from_lr.strip().lower() in {"1", "true", "yes", "on"})
                for device in config.devices
            )
            return self.generate(SoCGenerationConfig(config.host, devices, paths.run, paths.rtl / "soc.sv"))
        if action in {"fusesoc_build", "prepare", "sim_build"}:
            root = paths.run / "fusesoc" / host
            selected = values.get("TARGET", "default" if action == "fusesoc_build" else "sim")
            argv = (
                values.get("FUSESOC", "fusesoc"),
                f"--cores-root={context.project_root}", f"--cores-root={root / 'cores'}",
                "run", "--setup", "--build", "--target", selected,
                "--build-root", str(root / "build"), values.get("SOC_CORE_VLNV", "enea:soc:main"),
            )
            return self.run_tool(argv, cwd=root, log=paths.logs / "soc" / f"{target.name}.log", on=on).returncode
        if action == "build_sw":
            sw = paths.run / "sw"
            if not (sw / "Makefile").is_file():
                raise FileNotFoundError(f"missing SoC software scaffold: {sw / 'Makefile'}; run `fx sw_soc` first")
            return self.run_tool(("make", "-C", str(sw)), cwd=paths.run, log=paths.logs / "soc" / "build_sw.log", inputs=(sw / "Makefile",), on=on).returncode
        if action == "sim_run":
            exe = paths.run / "fusesoc" / host / "build" / "sim-verilator" / "Vtop_verilator"
            return self.run_tool((str(exe),), cwd=exe.parent, log=paths.logs / "soc" / "run.log", inputs=(exe,), on=on).returncode
        if action == "view":
            from ...core.flow.session import WorkspaceFlow
            return WorkspaceFlow(context, self.runner).view("view", on=on)
        raise ValueError(f"unsupported SoC action: {action!r}")

    def run_tool(self, argv, *, cwd: Path, log: Path, inputs=(), outputs=(), on: str = "local"):
        """Run one external SoC tool through the shared execution layer."""
        from ...core import CommandRequest
        return self.runner.run(CommandRequest(tuple(argv), cwd, {}, log, tuple(inputs), tuple(outputs)), on=on)

    @staticmethod
    def _cfg_run_dir(workspace: str | Path, run_top: str, run_id: str) -> Path:
        """Return the canonical run directory for a workspace/run identity."""

        return Path(workspace).expanduser().resolve() / "runs" / run_top / run_id

    @staticmethod
    def _cfg_loaded_ips(workspace: str | Path, run_top: str, run_id: str) -> tuple[str, ...]:
        """List IP directories staged under a run workspace."""

        ips_dir = SocFlow._cfg_run_dir(workspace, run_top, run_id) / "ips"
        if not ips_dir.exists():
            return ()
        return tuple(sorted(path.name for path in ips_dir.iterdir() if path.is_dir()))

    @staticmethod
    def builtin_devices(host: str) -> tuple[SoCDevice, ...]:
        """Return the built-in memory map for a supported host profile."""

        if host == "ibex":
            return (
                SoCDevice("sram", "0x00100000", "0x00100000", "True"),
                SoCDevice("uart", "0x80000000"),
                SoCDevice("pwm", "0x80020000"),
                SoCDevice("gpio", "0x80040000"),
                SoCDevice("rv_timer", "0x80060000"),
                SoCDevice("spi_host", "0x80080000"),
            )
        if host == "uart":
            return (
                SoCDevice("uart", "0x80000000"),
                SoCDevice("pwm", "0x80020000"),
                SoCDevice("gpio", "0x80040000"),
                SoCDevice("rv_timer", "0x80060000"),
            )
        raise SystemExit(f"ERROR: Unknown HOST '{host}'. Supported builtin hosts: ibex, uart")

    @staticmethod
    def _cfg_normalize_host(host: str | None) -> str | None:
        """Normalize and validate an optional host override."""

        if not host:
            return None
        normalized = host.strip().lower()
        if normalized not in _cfg_SUPPORTED_HOSTS:
            raise SystemExit(f"ERROR: unsupported host '{host}'. Use ibex or uart.")
        return normalized

    @staticmethod
    def resolve_host(ip_names: tuple[str, ...], default_host: str | None = None) -> str:
        """Resolve the host profile from an explicit hint or staged IP names."""

        if default_host:
            return default_host
        names = set(ip_names)
        if names & HOST_IPS:
            return "ibex"
        if names & {"uart", "uart_master"}:
            return "uart"
        raise SystemExit("ERROR: no loaded IPs found under workspace/runs/<run_top>/<run_id>/ips")

    @staticmethod
    def workspace_devices(ip_names: tuple[str, ...], host: str) -> tuple[SoCDevice, ...]:
        """Build a deterministic memory map from staged workspace IP names."""

        devices = [SoCDevice("sram", "0x00100000", "0x00100000", "True")] if host == "ibex" else []
        next_base = 0x800A0000
        used_bases = set(KNOWN_BASES.values())

        for ip in dict.fromkeys(ip_names):
            if ip in HOST_IPS:
                continue
            base = KNOWN_BASES.get(ip)
            if base is None:
                while next_base in used_bases:
                    next_base += 0x00020000
                base = next_base
                used_bases.add(base)
                next_base += 0x00020000
            devices.append(SoCDevice(ip, f"0x{base:08X}"))
        return tuple(devices)

    @staticmethod
    def resolve_soc_config(
        workspace: str | Path,
        run_top: str,
        run_id: str,
        *,
        default_host: str | None = None,
        mode: str = "auto",
    ) -> SoCConfig:
        """Resolve a SoC config from builtin profiles, workspace IPs, or both."""

        host_hint = SocFlow._cfg_normalize_host(default_host)
        if mode not in {"workspace", "builtin", "auto"}:
            raise SystemExit("ERROR: --mode must be workspace, builtin, or auto")

        if mode == "builtin":
            if not host_hint:
                raise SystemExit("ERROR: --mode builtin requires --default-host <ibex|uart>")
            return SoCConfig(host_hint, SocFlow.builtin_devices(host_hint))

        ips = SocFlow._cfg_loaded_ips(workspace, run_top, run_id)
        if mode == "workspace" or ips:
            host = SocFlow.resolve_host(ips, host_hint)
            return SoCConfig(host, SocFlow.workspace_devices(ips, host))

        if host_hint:
            return SoCConfig(host_hint, SocFlow.builtin_devices(host_hint))
        raise SystemExit(
            "ERROR: no loaded IPs found under workspace/runs/<run_top>/<run_id>/ips "
            "and no supported builtin host selected. Use HOST=ibex or HOST=uart, or load IPs into the run."
        )

    @staticmethod
    def render_make_config(config: SoCConfig) -> str:
        """Render a Make fragment containing host and device memory map data."""

        lines = [
            f"HOST ?= {config.host}",
            "DEVLIST :=",
            "define add_device",
            "DEVLIST += $(1)",
            "BASE_$(1) := $(2)",
            "SIZE_$(1) := $(3)",
            "FROM_LR_$(1) := $(4)",
            "endef",
            *(device.make_call() for device in config.devices),
            "SOC_MEMORY_MAP ?= $(foreach d,$(DEVLIST),--device $(d) $(BASE_$(d)) $(SIZE_$(d)) $(FROM_LR_$(d)))",
        ]
        return "\n".join(lines) + "\n"

    @staticmethod
    def render_args(config: SoCConfig) -> str:
        """Render flat command-line arguments for SoC generators."""

        return " ".join(config.args()) + "\n"

    @staticmethod
    def _start_loaded_ips(ips_dir: Path) -> tuple[Path, ...]:
        """Return staged IP bundle directories sorted by name."""

        return tuple(sorted(path for path in ips_dir.iterdir() if path.is_dir()))

    @staticmethod
    def _copy_tree(src: Path, dst: Path) -> bool:
        """Copy one optional verification asset tree."""

        if not src.exists():
            return False
        if dst.exists():
            shutil.rmtree(dst)
        shutil.copytree(src, dst)
        return True

    @staticmethod
    def stage_ip_verification_assets(config: SoCStartConfig, ips: tuple[Path, ...]) -> Path:
        """Stage per-IP tests/models into the SoC run root."""

        manifest = config.run_dir / "tests" / "loaded_tests.txt"
        lines: list[str] = []
        for ip in ips:
            copied_tests = SocFlow._copy_tree(ip / "tb" / "tests", config.run_dir / "tests" / ip.name)
            copied_model = SocFlow._copy_tree(ip / "model", config.run_dir / "model" / ip.name)
            if copied_tests or copied_model:
                lines.append(f"{ip.name}: tests={int(copied_tests)} model={int(copied_model)}")
        manifest.parent.mkdir(parents=True, exist_ok=True)
        manifest.write_text("\n".join(lines) + ("\n" if lines else ""), encoding="utf-8")
        return manifest

    @staticmethod
    def read_filelists(ip_dir: Path) -> tuple[str, ...]:
        """Read the canonical staged IP common/IP filelists."""

        files = (ip_dir / "rtl/rtl_common.f", ip_dir / "rtl/rtl_ip.f")
        missing = [path for path in files if not path.is_file()]
        if missing:
            raise FileNotFoundError("missing canonical IP filelist(s): " + ", ".join(map(str, missing)))
        return tuple(
            line
            for flist in files
            for raw in flist.read_text(encoding="utf-8").splitlines()
            if (line := raw.strip()) and not line.startswith("#")
        )

    @staticmethod
    def fallback_rtl_sources(ip_dir: Path) -> tuple[str, ...]:
        """Discover RTL files when an IP bundle has no explicit filelist."""

        rtl_dir = ip_dir / "rtl"
        if not rtl_dir.exists():
            return ()
        files = sorted(rtl_dir.glob("*.sv")) + sorted(rtl_dir.glob("*.v"))
        return tuple(path.resolve().as_posix() for path in files if path.is_file())

    @staticmethod
    def merged_rtl_sources(ips: tuple[Path, ...]) -> tuple[str, ...]:
        """Merge IP RTL sources while preserving first-seen ordering."""

        merged: list[str] = []
        seen: set[str] = set()
        for ip_dir in ips:
            for source in SocFlow.read_filelists(ip_dir) or SocFlow.fallback_rtl_sources(ip_dir):
                if source not in seen:
                    seen.add(source)
                    merged.append(source)
        return tuple(merged)

    @staticmethod
    def write_soc_start_summary(config: SoCStartConfig, ips: tuple[Path, ...], rtl_ip: Path) -> Path:
        """Write a compact summary for the initialized SoC run."""

        doc_dir = config.run_dir / "doc"
        doc_dir.mkdir(parents=True, exist_ok=True)
        path = doc_dir / "soc_start.txt"
        path.write_text(
            "\n".join(
                (
                    f"run_top={config.run_top}",
                    f"run_id={config.run_id}",
                    f"run_dir={config.run_dir}",
                    f"loaded_ips={len(ips)}",
                    f"rtl_ip={rtl_ip}",
                )
            )
            + "\n",
            encoding="utf-8",
        )
        return path

    @staticmethod
    def initialize_soc_run(config: SoCStartConfig) -> Path:
        """Create SoC run folders and write the merged RTL filelist."""

        if not config.ips_dir.exists():
            raise FileNotFoundError(f"missing ips directory: {config.ips_dir}")

        ips = SocFlow._start_loaded_ips(config.ips_dir)
        if not ips:
            raise ValueError(f"no loaded IPs under: {config.ips_dir}")

        for dirname in ("rtl", "tb", "sim", "logs", "doc", "tests", "model"):
            (config.run_dir / dirname).mkdir(parents=True, exist_ok=True)

        (config.ips_dir / "loaded_ips.txt").write_text("".join(f"{ip.name}\n" for ip in ips), encoding="utf-8")
        sources = SocFlow.merged_rtl_sources(ips)
        if not sources:
            raise ValueError(f"no RTL sources found under loaded IPs in: {config.ips_dir}")

        rtl_ip = config.run_dir / "rtl" / "rtl_ip.f"
        rtl_ip.write_text("\n".join(sources) + "\n", encoding="utf-8")
        (config.run_dir / "rtl" / "rtl_list.f").unlink(missing_ok=True)
        SocFlow.stage_ip_verification_assets(config, ips)
        SocFlow.write_soc_start_summary(config, ips, rtl_ip)
        return rtl_ip

    @staticmethod
    def _xbar_normalize_host(host: str) -> str:
        """Map user-facing host names to generated crossbar node names."""

        return "uart_host" if host.strip().lower() == "uart" else "ibex"

    @staticmethod
    def device_node(device: XbarDevice) -> dict[str, Any]:
        """Render one device as a JSON-ready crossbar node."""

        return {
            "name": device.name,
            "type": "device",
            "clock": "clk_i",
            "reset": "rst_ni",
            "xbar": False,
            "addr_range": [{"base_addr": device.base_addr, "size_byte": device.size_byte}],
        }

    @staticmethod
    def host_node(name: str) -> dict[str, Any]:
        """Render the host node shared by all generated configurations."""

        return {
            "name": name,
            "type": "host",
            "clock": "clk_i",
            "reset": "rst_ni",
            "xbar": False,
            "pipeline": False,
        }

    @staticmethod
    def build_xbar_config(config: XbarConfig) -> dict[str, Any]:
        """Build a JSON-ready crossbar configuration from normalized inputs."""

        host_name = SocFlow._xbar_normalize_host(config.host)
        nodes = [SocFlow.host_node(host_name), *(SocFlow.device_node(device) for device in config.devices)]
        return {
            "name": "main",
            "type": "xbar",
            "clock": "clk_i",
            "clock_connections": {"clk_i": "main"},
            "reset": "rst_ni",
            "reset_connections": {"rst_ni": "main"},
            "nodes": nodes,
            "connections": {host_name: [device.name for device in config.devices]},
        }

    @staticmethod
    def write_json(path: Path, payload: dict[str, Any]) -> Path:
        """Write a JSON payload to disk and return the resolved path."""

        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
        return path.resolve()

    @staticmethod
    def parse_device_rows(rows: list[list[str]]) -> tuple[XbarDevice, ...]:
        """Convert argparse device rows into typed crossbar devices."""

        return tuple(XbarDevice(name, base_addr, size_byte, from_lr) for name, base_addr, size_byte, from_lr in rows)

    @staticmethod
    def _gen_normalize_host(host: str) -> str:
        """Normalize and validate the host selected for SoC generation."""

        host = host.strip().lower()
        if host not in _gen_SUPPORTED_HOSTS:
            expected = ", ".join(sorted(_gen_SUPPORTED_HOSTS))
            raise ValueError(f"unsupported host {host!r}; expected one of: {expected}")
        return host

    @staticmethod
    def normalize_device(raw: tuple[str, str, str, str] | list[str]) -> SoCModule:
        """Convert one CLI device tuple into the canonical SoC module model."""

        name, base_addr, size_bytes, from_lowrisc = raw
        return SoCModule(name, base_addr, size_bytes, from_lowrisc == "True")

    @staticmethod
    def normalize_devices(devices: list[list[str]] | tuple[SoCModule, ...]) -> tuple[SoCModule, ...]:
        """Normalize CLI or API device entries into immutable module objects."""

        if all(isinstance(device, SoCModule) for device in devices):
            return tuple(devices)
        return tuple(SocFlow.normalize_device(device) for device in devices)

    @staticmethod
    def find_sv_file(module_name, root_dir=".", from_vendor=False):
        """Find the SystemVerilog source for one module below canonical roots."""

        root = Path(root_dir)
        search_roots = [root / "vendor"] if from_vendor else [
            root / "hw" / "ips" / module_name,
            root / "rtl",
            root,
        ]
        for search_root in search_roots:
            if not search_root.exists():
                continue
            for path in search_root.rglob(f"{module_name}.sv"):
                return path
        return None

    @staticmethod
    def parse_ports(sv_file):
        """Parse simple input/output port declarations from a SystemVerilog module."""

        with open(sv_file, "r", encoding="utf-8") as f:
            content = f.read()

        content = re.sub(r"//.*?$|/\*.*?\*/", "", content, flags=re.DOTALL | re.MULTILINE)
        content = re.sub(r"\s+", " ", content)

        m = re.search(r"\bmodule\b.*?\((?P<plist>.*?)\)\s*;", content)
        if not m:
            return []

        plist = m.group("plist")
        port_decls = [p.strip() for p in plist.split(",") if p.strip()]

        ports = []
        for decl in port_decls:
            dm = re.match(r"^\s*(input|output)\b\s+(.*)$", decl)
            if not dm:
                continue
            dir_ = dm.group(1)
            rest = dm.group(2).strip()
            nm = re.search(r"([A-Za-z_]\w*)\s*$", rest)
            if not nm:
                continue
            name = nm.group(1)
            dtype = rest[: nm.start(1)].strip() or None
            ports.append((dir_, dtype, name))
        return ports

    @staticmethod
    def generate_port_decls(all_ports):
        """Render top-level SoC ports while hiding clocks, TL-UL, and interrupts."""

        lines = []
        for name, direction in all_ports.items():
            if "tl_" in name:
                continue
            if name in {"clk_i", "rst_ni"}:
                continue
            if "intr" in name:
                continue
            lines.append(f"  {direction} {name},")
        return lines

    @staticmethod
    def generate_module_inst(mod: str, ports) -> str:
        """Render one peripheral instance from semantic port metadata."""

        from flexsoc.backend.core.render.templates import templates

        connections = [".clk_i", ".rst_ni", f".tl_i(tl_{mod}_h2d)", f".tl_o(tl_{mod}_d2h)"]
        connections.extend(
            f".{name}"
            for _direction, _dtype, name in ports
            if name not in {"tl_i", "tl_o", "clk_i", "rst_ni"}
            and not any(token in name for token in ("intr", "alert_rx", "alert_tx"))
        )
        connections.extend(
            f".{name}()"
            for _direction, _dtype, name in ports
            if any(token in name for token in ("intr", "alert_rx", "alert_tx"))
        )
        return templates.render(
            "design/soc/module_instance.sv.j2", module=mod, connections=connections
        )

    @staticmethod
    def defaults(host: str) -> str:
        """Render host-specific default logic and TileLink adapters."""

        from flexsoc.backend.core.render.templates import templates

        host = SocFlow._gen_normalize_host(host)
        return templates.render(f"design/soc/defaults_{host}.sv.j2")

    @staticmethod
    def write_top_verilator_sv(tb_file: Path, host: str, all_ports: dict[str, str]) -> Path:
        """Write the generated Verilator SystemVerilog wrapper."""

        from flexsoc.backend.core.render.templates import templates

        ports = [
            (name, direction)
            for name, direction in all_ports.items()
            if name not in {"clk_i", "rst_ni"} and "tl_" not in name and "intr" not in name
        ]
        declarations = [
            f"{' '.join(direction.split()[1:]).strip() or 'logic'} {name}"
            for name, direction in ports
        ]
        return templates.write(
            "design/soc/top_verilator.sv.j2", Path(tb_file), force=True,
            host=host,
            declarations=declarations,
            ports=[name for name, _ in ports],
            has_uart=all(name in all_ports for name in ("cio_rx_i", "cio_tx_o")),
        )

    @staticmethod
    def write_top_verilator_cc(tb_file: Path, host: str) -> Path:
        """Write the generated Verilator C++ harness."""

        from flexsoc.backend.core.render.templates import templates

        return templates.write(
            "design/soc/top_verilator.cc.j2", Path(tb_file), force=True, host=host
        )

    @staticmethod
    def write_soc_core(core_file: Path, host: str, modules: list[str]) -> Path:
        """Write the FuseSoC core file for the generated SoC."""

        from flexsoc.backend.core.render.templates import templates

        return templates.write(
            "design/soc/soc.core.j2", Path(core_file), force=True,
            host=host, modules=modules, merge_key="<<: *default_target",
        )

    @staticmethod
    def split_devices(devices: tuple[SoCModule, ...]) -> tuple[list[str], list[str]]:
        """Split normalized devices into local IPs and lowRISC dependencies."""

        local = [device.name for device in devices if not device.from_lowrisc]
        lowrisc = [device.name for device in devices if device.from_lowrisc]
        return local, lowrisc

    @staticmethod
    def soc_modules(devices: tuple[SoCModule, ...]) -> tuple[list[str], list[str], list[str]]:
        """Return local, lowRISC, and renderable module lists for SoC generation."""

        local, lowrisc = SocFlow.split_devices(devices)
        return local, lowrisc, lowrisc[1:] + local

    @staticmethod
    def collect_module_ports(config: SoCGenerationConfig) -> tuple[dict[str, list[tuple[str, str | None, str]]], list[str]]:
        """Resolve every renderable module and parse its external ports."""

        local_modules, lowrisc_modules, modules = SocFlow.soc_modules(config.devices)
        parsed = {}
        for module in modules:
            if module == "uart" and config.host == "uart":
                continue
            sv_path = SocFlow.find_sv_file(module, config.root, module in lowrisc_modules)
            if not sv_path:
                raise FileNotFoundError(f"SystemVerilog file for module {module!r} not found.")
            parsed[module] = SocFlow.parse_ports(sv_path)
        return parsed, local_modules

    @staticmethod
    def collect_soc_ports(modules_ports):
        """Merge parsed module ports into the generated SoC top-level port map."""

        all_ports = {}
        for mod_ports in modules_ports.values():
            for direction, dtype, name in mod_ports:
                all_ports.setdefault(name, direction + " " + ("" if dtype is None else dtype))
        return all_ports

    @staticmethod
    def add_host_ports(host: str, all_ports: dict[str, str]) -> dict[str, str]:
        """Add host-facing external pins that are not discovered from IP wrappers."""

        if host == "uart":
            all_ports.setdefault("cio_rx_i", "input logic")
            all_ports.setdefault("cio_tx_o", "output logic")
            all_ports.setdefault("cio_tx_en_o", "output logic")
        return all_ports

    @staticmethod
    def render_xbar_connections(host: str, modules: list[str]) -> str:
        """Render xbar connections from the resolved host/device topology."""

        from flexsoc.backend.core.render.templates import templates

        connections: list[str] = []
        if host == "ibex":
            connections.extend((
                ".tl_ibex_i (tl_ibex_h2d)", ".tl_ibex_o (tl_ibex_d2h)",
                ".tl_sram_o (tl_sram_h2d)", ".tl_sram_i (tl_sram_d2h)",
            ))
        elif host == "uart":
            connections.extend((
                ".tl_uart_host_i (tl_uart_host_h2d)", ".tl_uart_host_o (tl_uart_host_d2h)",
                ".tl_uart_o (tl_uart_h2d)", ".tl_uart_i (tl_uart_d2h)",
            ))
        for module in modules:
            if module == "uart" and host == "uart":
                continue
            connections.extend((
                f".tl_{module}_o (tl_{module}_h2d)",
                f".tl_{module}_i (tl_{module}_d2h)",
            ))
        return templates.render("design/soc/xbar.sv.j2", connections=connections)

    @staticmethod
    def render_soc_sv(host: str, modules_ports, local_modules: list[str]) -> str:
        """Render the generated ``soc.sv`` source from semantic port/module data."""

        from flexsoc.backend.core.render.templates import templates

        modules = list(modules_ports)
        all_ports = SocFlow.add_host_ports(host, SocFlow.collect_soc_ports(modules_ports))
        port_declarations = "\n".join(SocFlow.generate_port_decls(all_ports)) + "\n"
        tl_signals = "\n".join(
            line
            for module in modules
            if not (module == "uart" and host == "uart")
            for line in (
                f"  tlul_pkg::tl_h2d_t tl_{module}_h2d;",
                f"  tlul_pkg::tl_d2h_t tl_{module}_d2h;",
            )
        )
        if tl_signals:
            tl_signals += "\n"
        instances = "\n".join(
            SocFlow.generate_module_inst(module, ports)
            for module, ports in modules_ports.items()
        )
        return templates.render(
            "design/soc/soc.sv.j2",
            port_declarations=port_declarations,
            defaults=SocFlow.defaults(host),
            tl_signals=tl_signals,
            xbar=SocFlow.render_xbar_connections(host, local_modules),
            module_instances=instances,
        )

    @staticmethod
    def generate_soc(config: SoCGenerationConfig) -> Path:
        """Generate SoC RTL, Verilator wrappers, and FuseSoC metadata."""

        modules_ports, local_modules = SocFlow.collect_module_ports(config)
        all_ports = SocFlow.add_host_ports(config.host, SocFlow.collect_soc_ports(modules_ports))
        config.output.parent.mkdir(parents=True, exist_ok=True)
        config.tb_dir.mkdir(parents=True, exist_ok=True)
        config.output.write_text(SocFlow.render_soc_sv(config.host, modules_ports, local_modules), encoding="utf-8")
        SocFlow.write_top_verilator_sv(config.tb_dir / "top_verilator.sv", config.host, all_ports)
        SocFlow.write_top_verilator_cc(config.tb_dir / "top_verilator.cc", config.host)
        SocFlow.write_soc_core(config.run_dir / "soc.core", config.host, local_modules)
        return config.output

    @staticmethod
    def generate_soc_sv(host, device, root_dir, output_file):
        """Generate SoC files from CLI-style arguments."""

        return SocFlow.generate_soc(
            SoCGenerationConfig(
                host=SocFlow._gen_normalize_host(host),
                devices=SocFlow.normalize_devices(device),
                root=Path(root_dir),
                output=Path(output_file),
            )
        )

    @staticmethod
    def rtl_sort_key(filename: str, top: str) -> tuple[int, str]:
        """Return a stable RTL order with packages first and the top module last."""

        if filename.endswith("_pkg.sv") and filename != f"{top}_reg_pkg.sv":
            return (0, filename)
        if filename == f"{top}_reg_pkg.sv":
            return (1, filename)
        if filename == f"{top}_reg_core.sv":
            return (2, filename)
        if filename == f"{top}_reg_top.sv":
            return (3, filename)
        if filename.endswith("_core.sv") or filename == "timer_core.sv":
            return (4, filename)
        if filename == f"{top}.sv":
            return (5, filename)
        return (6, filename)

    @staticmethod
    def list_rtl_sources(rtl_dir: Path, top: str) -> list[str]:
        """List visible SystemVerilog files in FuseSoC-friendly order."""

        files = [p.name for p in rtl_dir.iterdir() if p.is_file() and not p.name.startswith(".")]
        return sorted((name for name in files if name.endswith(".sv")), key=lambda name: SocFlow.rtl_sort_key(name, top))

    @staticmethod
    def render_core(prj: str, top: str, rtl_files: list[str], rtl_ref_dir: str = "rtl") -> str:
        """Render the CAPI2 core description used by FuseSoC."""

        file_lines = "\n".join(f"      - {rtl_ref_dir}/{name}" for name in rtl_files)
        if file_lines:
            file_lines += "\n"
        return (
            "CAPI=2:\n"
            f"name: \"{prj}:ip:{top}:0.1\"\n"
            f"description: \"{top}\"\n"
            "filesets:\n"
            "  files_rtl:\n"
            "    depend:\n"
            "      - ips:dependecies:all\n"
            "    files:\n"
            f"{file_lines}"
            "    file_type: systemVerilogSource\n\n"
            "targets:\n"
            "  default: &default_target\n"
            "    filesets:\n"
            "      - files_rtl\n"
            f"    toplevel: {top}\n\n"
            "  lint:\n"
            "    <<: *default_target\n"
            "    default_tool: verilator\n"
            "    tools:\n"
            "      verilator:\n"
            "        mode: lint-only\n"
            "        verilator_options:\n"
            "          - \"-Wall\"\n"
            "          - \"-Wno-fatal\"\n"
        )

    @staticmethod
    def write_core(prj: str, top: str, rtl_dir: Path, output: Path | None = None) -> Path:
        """Write `<top>.core` and return the generated path."""

        out_dir = output or Path.cwd()
        out_dir.mkdir(parents=True, exist_ok=True)
        core_path = out_dir / f"{top}.core"
        core_path.write_text(SocFlow.render_core(prj, top, SocFlow.list_rtl_sources(rtl_dir, top)), encoding="utf-8")
        return core_path

    @staticmethod
    def _software_run_dir(workspace: Path, run_top: str, run_id: str) -> Path:
        """Build the canonical workspace run directory path."""

        return workspace / "runs" / run_top / run_id

    @staticmethod
    def copy_driver_files(ips_dir: Path, sw_dir: Path) -> list[str]:
        """Copy staged IP C drivers into the software directory."""

        if not ips_dir.exists():
            raise SystemExit(f"ERROR: missing loaded IP directory: {ips_dir}")

        modules: list[str] = []
        for ip_dir in sorted((p for p in ips_dir.iterdir() if p.is_dir()), key=lambda p: p.name):
            driver_files = sorted((ip_dir / "sw" / "drivers").glob("*.h")) + sorted((ip_dir / "sw" / "drivers").glob("*.c"))
            if not driver_files:
                continue
            for src in driver_files:
                shutil.copy2(src, sw_dir / src.name)
            modules.append(ip_dir.name)
        return modules

    @staticmethod
    def render_main_c(modules: list[str], host: str) -> str:
        """Render the generated SoC C entrypoint."""

        from flexsoc.backend.core.render.templates import templates

        return templates.render(
            "design/soc/main.c.j2",
            modules=modules,
            uses_uart=host == "uart" and "uart" in modules,
        )

    @staticmethod
    def render_makefile(modules: list[str]) -> str:
        """Render the generated RISC-V software Makefile."""

        from flexsoc.backend.core.render.templates import templates

        objects = " ".join(f"$(BUILD_DIR)/{module}.o" for module in ("main", *modules))
        return templates.render(
            "design/soc/Makefile.j2",
            obj_list=f"{objects} $(BUILD_DIR)/boot.o",
        )

    @staticmethod
    def write_soc_software(config: SoCSoftwareConfig) -> tuple[Path, list[str]]:
        """Generate the SoC software directory and return its copied modules."""

        sw_dir = config._software_run_dir / "sw"
        sw_dir.mkdir(parents=True, exist_ok=True)

        modules = SocFlow.copy_driver_files(config._software_run_dir / "ips", sw_dir)
        if not modules:
            raise SystemExit(f"ERROR: no driver files found under loaded IPs: {config._software_run_dir / 'ips'}")

        from flexsoc.backend.core.render.templates import templates

        templates.write("design/soc/boot.S.j2", sw_dir / "boot.S", force=True)
        templates.write("design/soc/link.ld.j2", sw_dir / "link.ld", force=True)
        (sw_dir / "main.c").write_text(SocFlow.render_main_c(modules, config.host), encoding="utf-8")
        (sw_dir / "Makefile").write_text(SocFlow.render_makefile(modules), encoding="utf-8")
        return sw_dir, modules
