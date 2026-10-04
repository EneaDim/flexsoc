"""SoC composition, TL-UL fabric generation, and software scaffold flow."""

from __future__ import annotations

import json
import re
import shutil
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Any

from ...core import BackendContext, CommandRequest, ToolRunner

SUPPORTED_HOSTS = {"ibex", "uart"}
SUPPORTED_FABRICS = {"tlul"}
HOST_IPS = {"ibex", "ibex_top_tracing"}
KNOWN_BASES = {
    "uart": 0x80000000,
    "uart_master": 0x80000000,
    "gpio": 0x80040000,
    "rv_timer": 0x80060000,
    "spi_host": 0x80080000,
}
SRAM_BASE = 0x00100000
SRAM_SIZE = 128 * 1024


@dataclass(frozen=True, slots=True)
class SoCDevice:
    """One memory-mapped endpoint in the resolved SoC plan."""

    name: str
    base: int
    size: int = 0x1000
    builtin: bool = False

    @property
    def base_hex(self) -> str:
        return f"0x{self.base:08X}"

    @property
    def size_hex(self) -> str:
        return f"0x{self.size:08X}"

    def to_dict(self) -> dict[str, object]:
        return {
            "name": self.name,
            "base": self.base_hex,
            "size": self.size_hex,
            "builtin": self.builtin,
        }


@dataclass(frozen=True, slots=True)
class SoCPlan:
    """Single source of truth for one resolved SoC composition."""

    host: str
    fabric: str
    devices: tuple[SoCDevice, ...]

    @property
    def external_devices(self) -> tuple[SoCDevice, ...]:
        return tuple(device for device in self.devices if not device.builtin)

    def to_dict(self) -> dict[str, object]:
        return {
            "schema": 1,
            "host": self.host,
            "fabric": self.fabric,
            "devices": [device.to_dict() for device in self.devices],
        }


@dataclass(slots=True)
class TlulFabric:
    """Generate the concrete TL-UL fabric with the vendored OpenTitan tlgen."""

    project_root: Path
    runner: ToolRunner

    @staticmethod
    def host_name(host: str) -> str:
        return "uart_host" if host == "uart" else "ibex"

    @staticmethod
    def host_node(name: str) -> dict[str, Any]:
        return {
            "name": name,
            "type": "host",
            "clock": "clk_i",
            "reset": "rst_ni",
            "xbar": False,
            "pipeline": False,
        }

    @staticmethod
    def device_node(device: SoCDevice) -> dict[str, Any]:
        return {
            "name": device.name,
            "type": "device",
            "clock": "clk_i",
            "reset": "rst_ni",
            "xbar": False,
            "addr_range": [{"base_addr": device.base_hex, "size_byte": device.size_hex}],
        }

    def payload(self, plan: SoCPlan) -> dict[str, Any]:
        host = self.host_name(plan.host)
        return {
            "name": "main",
            "type": "xbar",
            "clock": "clk_i",
            "clock_connections": {"clk_i": "main"},
            "reset": "rst_ni",
            "reset_connections": {"rst_ni": "main"},
            "nodes": [self.host_node(host), *(self.device_node(device) for device in plan.devices)],
            "connections": {host: [device.name for device in plan.devices]},
        }

    def generate(self, plan: SoCPlan, run_dir: Path, log: Path, *, on: str = "local") -> object:
        config = run_dir / "soc" / "xbar.hjson"
        SocFlow.write_json(config, self.payload(plan))
        outputs = (
            run_dir / "rtl" / "autogen" / "tl_main_pkg.sv",
            run_dir / "rtl" / "autogen" / "xbar_main.sv",
        )
        argv = (
            sys.executable,
            str(self.project_root / "src" / "util" / "tlgen.py"),
            "-t", str(config),
            "-o", str(run_dir),
        )
        return self.runner.run(
            CommandRequest(argv, self.project_root, {}, log, (config,), outputs), on=on
        )


class SocFlow:
    """Resolve and generate one SoC composition for the current backend context."""

    def __init__(self, context: BackendContext, runner: ToolRunner | None = None):
        self.context = context
        self.runner = runner or ToolRunner(project_root=context.project_root)
        self.fabric = TlulFabric(context.project_root, self.runner)

    @property
    def paths(self):
        return self.context.paths

    @property
    def values(self):
        return self.context.values

    def run_target(self, target, *, on: str = "local"):
        """Execute the single public SoC target."""

        if target.action != "soc":
            raise ValueError(f"unsupported SoC action: {target.action!r}")
        action = str(self.values.get("SOC_ACTION", "generate")).strip().lower()
        if action == "show":
            return self.show()
        if action != "generate":
            raise ValueError(f"unsupported SoC option {action!r}; expected generate or show")
        return self.generate(on=on)

    def prepare_run(self) -> tuple[Path, ...]:
        """Create canonical SoC run directories and merge staged IP RTL filelists."""

        run = self.paths.run
        for dirname in ("ips", "rtl", "tb", "sim", "logs", "doc", "tests", "model", "soc"):
            (run / dirname).mkdir(parents=True, exist_ok=True)
        ips = self.loaded_ip_dirs()
        (run / "ips" / "loaded_ips.txt").write_text(
            "".join(f"{ip.name}\n" for ip in ips), encoding="utf-8"
        )
        sources = self.merged_rtl_sources(ips) if ips else ()
        (run / "rtl" / "rtl_ip.f").write_text(
            "\n".join(sources) + ("\n" if sources else ""), encoding="utf-8"
        )
        (run / "rtl" / "rtl_list.f").unlink(missing_ok=True)
        self.stage_ip_verification_assets(ips)
        return ips

    def loaded_ip_dirs(self) -> tuple[Path, ...]:
        ips = self.paths.run / "ips"
        if not ips.is_dir():
            return ()
        return tuple(sorted(path for path in ips.iterdir() if path.is_dir()))

    def resolve_plan(self) -> SoCPlan:
        """Resolve host infrastructure plus explicitly staged reusable IPs."""

        host = self.normalize_host(str(self.values.get("HOST", "ibex")))
        fabric = self.normalize_fabric(str(self.values.get("FABRIC", "tlul")))
        loaded = tuple(path.name for path in self.loaded_ip_dirs())

        devices = list(self.builtin_devices(host))
        used_names = {device.name for device in devices}
        used_bases = {device.base for device in devices}
        next_base = 0x800A0000

        for name in loaded:
            if name in HOST_IPS or name in used_names:
                continue
            base = KNOWN_BASES.get(name)
            if base is None:
                while next_base in used_bases:
                    next_base += 0x00020000
                base = next_base
                next_base += 0x00020000
            if base in used_bases:
                raise ValueError(f"duplicate SoC base address 0x{base:08X} for {name}")
            devices.append(SoCDevice(name, base))
            used_names.add(name)
            used_bases.add(base)

        return SoCPlan(host, fabric, tuple(devices))

    @staticmethod
    def normalize_host(host: str) -> str:
        host = host.strip().lower()
        if host not in SUPPORTED_HOSTS:
            raise ValueError(f"unsupported SoC host {host!r}; expected one of: {', '.join(sorted(SUPPORTED_HOSTS))}")
        return host

    @staticmethod
    def normalize_fabric(fabric: str) -> str:
        fabric = fabric.strip().lower()
        if fabric not in SUPPORTED_FABRICS:
            raise ValueError("unsupported SoC fabric {!r}; currently supported: tlul".format(fabric))
        return fabric

    @staticmethod
    def builtin_devices(host: str) -> tuple[SoCDevice, ...]:
        """Return only infrastructure intrinsically required by a host."""

        if host == "ibex":
            return (SoCDevice("sram", SRAM_BASE, SRAM_SIZE, True),)
        if host == "uart":
            return ()
        raise ValueError(f"unsupported SoC host {host!r}")

    def write_plan(self, plan: SoCPlan) -> Path:
        return self.write_json(self.paths.run / "soc" / "plan.json", plan.to_dict())

    def show(self) -> Path:
        """Print the stored plan, or the currently resolved plan when not generated yet."""

        path = self.paths.run / "soc" / "plan.json"
        payload = json.loads(path.read_text(encoding="utf-8")) if path.is_file() else self.resolve_plan().to_dict()
        print(json.dumps(payload, indent=2, sort_keys=True))
        return path

    def generate(self, *, on: str = "local") -> object:
        """Generate the complete hardware composition for the current SoC plan."""

        self.prepare_run()
        plan = self.resolve_plan()
        self.write_plan(plan)
        result = self.fabric.generate(plan, self.paths.run, self.paths.logs / "soc" / "tlgen.log", on=on)
        if getattr(result, "returncode", 0):
            return result
        self.generate_top(plan)
        return self.paths.run / "soc" / "plan.json"

    @staticmethod
    def write_json(path: Path, payload: dict[str, Any]) -> Path:
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return path.resolve()

    @staticmethod
    def _copy_tree(src: Path, dst: Path) -> bool:
        if not src.exists():
            return False
        if dst.exists():
            shutil.rmtree(dst)
        shutil.copytree(src, dst)
        return True

    def stage_ip_verification_assets(self, ips: tuple[Path, ...]) -> Path:
        manifest = self.paths.run / "tests" / "loaded_tests.txt"
        lines: list[str] = []
        for ip in ips:
            functional = ip / "dv" / "functional"
            copied_tests = self._copy_tree(functional / "tests", self.paths.run / "tests" / ip.name)
            copied_model = self._copy_tree(functional / "model", self.paths.run / "model" / ip.name)
            if copied_tests or copied_model:
                lines.append(f"{ip.name}: tests={int(copied_tests)} model={int(copied_model)}")
        manifest.write_text("\n".join(lines) + ("\n" if lines else ""), encoding="utf-8")
        return manifest

    @staticmethod
    def read_filelists(ip_dir: Path) -> tuple[str, ...]:
        files = (ip_dir / "rtl" / "rtl_common.f", ip_dir / "rtl" / "rtl_ip.f")
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
    def merged_rtl_sources(ips: tuple[Path, ...]) -> tuple[str, ...]:
        merged: list[str] = []
        seen: set[str] = set()
        for ip in ips:
            for source in SocFlow.read_filelists(ip):
                if source not in seen:
                    seen.add(source)
                    merged.append(source)
        return tuple(merged)

    def find_sv_file(self, module_name: str) -> Path | None:
        """Resolve a loaded device only from its frozen staged release."""

        rtl = self.paths.run / "ips" / module_name / "rtl"
        if not rtl.is_dir():
            return None
        exact = rtl / f"{module_name}.sv"
        if exact.is_file():
            return exact
        matches = sorted(rtl.rglob(f"{module_name}.sv"))
        return matches[0] if len(matches) == 1 else None

    @staticmethod
    def parse_ports(sv_file: Path) -> list[tuple[str, str | None, str]]:
        content = sv_file.read_text(encoding="utf-8")
        content = re.sub(r"//.*?$|/\*.*?\*/", "", content, flags=re.DOTALL | re.MULTILINE)
        content = re.sub(r"\s+", " ", content)
        match = re.search(r"\bmodule\b.*?\((?P<plist>.*?)\)\s*;", content)
        if not match:
            return []
        ports = []
        for declaration in (part.strip() for part in match.group("plist").split(",")):
            parsed = re.match(r"^\s*(input|output)\b\s+(.*)$", declaration)
            if not parsed:
                continue
            direction, rest = parsed.group(1), parsed.group(2).strip()
            name_match = re.search(r"([A-Za-z_]\w*)\s*$", rest)
            if not name_match:
                continue
            ports.append((direction, rest[:name_match.start(1)].strip() or None, name_match.group(1)))
        return ports

    @staticmethod
    def collect_soc_ports(modules_ports: dict[str, list[tuple[str, str | None, str]]]) -> dict[str, str]:
        all_ports: dict[str, str] = {}
        for ports in modules_ports.values():
            for direction, dtype, name in ports:
                all_ports.setdefault(name, direction + " " + (dtype or ""))
        return all_ports

    @staticmethod
    def add_host_ports(host: str, all_ports: dict[str, str]) -> dict[str, str]:
        if host == "uart":
            all_ports.setdefault("cio_rx_i", "input logic")
            all_ports.setdefault("cio_tx_o", "output logic")
            all_ports.setdefault("cio_tx_en_o", "output logic")
        return all_ports

    @staticmethod
    def generate_port_decls(all_ports: dict[str, str]) -> list[str]:
        lines = []
        for name, direction in all_ports.items():
            if "tl_" in name or name in {"clk_i", "rst_ni"} or "intr" in name:
                continue
            lines.append(f"  {direction} {name},")
        return lines

    @staticmethod
    def generate_module_inst(module: str, ports: list[tuple[str, str | None, str]]) -> str:
        from flexsoc.backend.core.render.templates import templates
        connections = [".clk_i", ".rst_ni", f".tl_i(tl_{module}_h2d)", f".tl_o(tl_{module}_d2h)"]
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
        return templates.render("design/soc/module_instance.sv.j2", module=module, connections=connections)

    @staticmethod
    def defaults(host: str) -> str:
        from flexsoc.backend.core.render.templates import templates
        return templates.render(f"design/soc/defaults_{host}.sv.j2")

    @staticmethod
    def render_xbar_connections(plan: SoCPlan) -> str:
        from flexsoc.backend.core.render.templates import templates
        connections: list[str] = []
        if plan.host == "ibex":
            connections.extend((
                ".tl_ibex_i (tl_ibex_h2d)", ".tl_ibex_o (tl_ibex_d2h)",
                ".tl_sram_o (tl_sram_h2d)", ".tl_sram_i (tl_sram_d2h)",
            ))
        elif plan.host == "uart":
            connections.extend((
                ".tl_uart_host_i (tl_uart_host_h2d)", ".tl_uart_host_o (tl_uart_host_d2h)",
            ))
        for device in plan.external_devices:
            connections.extend((
                f".tl_{device.name}_o (tl_{device.name}_h2d)",
                f".tl_{device.name}_i (tl_{device.name}_d2h)",
            ))
        return templates.render("design/soc/xbar.sv.j2", connections=connections)

    def module_ports(self, plan: SoCPlan) -> dict[str, list[tuple[str, str | None, str]]]:
        parsed = {}
        for device in plan.external_devices:
            source = self.find_sv_file(device.name)
            if source is None:
                raise FileNotFoundError(
                    f"loaded SoC device {device.name!r} has no unique rtl/{device.name}.sv"
                )
            parsed[device.name] = self.parse_ports(source)
        return parsed

    def render_soc_sv(self, plan: SoCPlan, modules_ports: dict[str, list[tuple[str, str | None, str]]]) -> str:
        from flexsoc.backend.core.render.templates import templates
        all_ports = self.add_host_ports(plan.host, self.collect_soc_ports(modules_ports))
        port_declarations = "\n".join(self.generate_port_decls(all_ports)) + "\n"
        tl_signals = "\n".join(
            line
            for module in modules_ports
            for line in (
                f"  tlul_pkg::tl_h2d_t tl_{module}_h2d;",
                f"  tlul_pkg::tl_d2h_t tl_{module}_d2h;",
            )
        )
        if tl_signals:
            tl_signals += "\n"
        instances = "\n".join(
            self.generate_module_inst(module, ports) for module, ports in modules_ports.items()
        )
        return templates.render(
            "design/soc/soc.sv.j2",
            port_declarations=port_declarations,
            defaults=self.defaults(plan.host),
            tl_signals=tl_signals,
            xbar=self.render_xbar_connections(plan),
            module_instances=instances,
        )

    def write_top_verilator_sv(self, path: Path, plan: SoCPlan, all_ports: dict[str, str]) -> Path:
        from flexsoc.backend.core.render.templates import templates
        ports = [
            (name, direction)
            for name, direction in all_ports.items()
            if name not in {"clk_i", "rst_ni"} and "tl_" not in name and "intr" not in name
        ]
        declarations = [
            f"{' '.join(direction.split()[1:]).strip() or 'logic'} {name}" for name, direction in ports
        ]
        return templates.write(
            "design/soc/top_verilator.sv.j2", path, force=True,
            host=plan.host, declarations=declarations, ports=[name for name, _ in ports],
            has_uart=all(name in all_ports for name in ("cio_rx_i", "cio_tx_o")),
        )

    @staticmethod
    def write_top_verilator_cc(path: Path, plan: SoCPlan) -> Path:
        from flexsoc.backend.core.render.templates import templates
        return templates.write("design/soc/top_verilator.cc.j2", path, force=True, host=plan.host)

    @staticmethod
    def write_soc_core(path: Path, plan: SoCPlan) -> Path:
        from flexsoc.backend.core.render.templates import templates
        return templates.write(
            "design/soc/soc.core.j2", path, force=True,
            host=plan.host, modules=[device.name for device in plan.external_devices],
            merge_key="<<: *default_target",
        )

    def generate_top(self, plan: SoCPlan) -> Path:
        modules_ports = self.module_ports(plan)
        all_ports = self.add_host_ports(plan.host, self.collect_soc_ports(modules_ports))
        output = self.paths.rtl / "soc.sv"
        output.write_text(self.render_soc_sv(plan, modules_ports), encoding="utf-8")
        self.paths.tb.mkdir(parents=True, exist_ok=True)
        self.write_top_verilator_sv(self.paths.tb / "top_verilator.sv", plan, all_ports)
        self.write_top_verilator_cc(self.paths.tb / "top_verilator.cc", plan)
        self.write_soc_core(self.paths.run / "soc.core", plan)
        return output

    @staticmethod
    def copy_driver_files(ips_dir: Path, sw_dir: Path) -> list[str]:
        if not ips_dir.exists():
            return []
        modules: list[str] = []
        for ip_dir in sorted((path for path in ips_dir.iterdir() if path.is_dir()), key=lambda path: path.name):
            driver_dir = ip_dir / "sw" / "drivers"
            files = sorted(driver_dir.glob("*.h")) + sorted(driver_dir.glob("*.c"))
            if not files:
                continue
            for source in files:
                shutil.copy2(source, sw_dir / source.name)
            modules.append(ip_dir.name)
        return modules

    @staticmethod
    def render_main_c(modules: list[str], host: str) -> str:
        from flexsoc.backend.core.render.templates import templates
        return templates.render("design/soc/main.c.j2", modules=modules, uses_uart=host == "uart" and "uart" in modules)

    @staticmethod
    def render_makefile(modules: list[str]) -> str:
        from flexsoc.backend.core.render.templates import templates
        objects = " ".join(f"$(BUILD_DIR)/{module}.o" for module in ("main", *modules))
        return templates.render("design/soc/Makefile.j2", obj_list=f"{objects} $(BUILD_DIR)/boot.o")

    def generate_software(self, plan: SoCPlan) -> tuple[Path, list[str]]:
        """Internal software scaffold generation; public CLI wiring follows after M0 boot."""

        from flexsoc.backend.core.render.templates import templates
        sw = self.paths.sw
        sw.mkdir(parents=True, exist_ok=True)
        modules = self.copy_driver_files(self.paths.run / "ips", sw)
        templates.write("design/soc/boot.S.j2", sw / "boot.S", force=True)
        templates.write("design/soc/link.ld.j2", sw / "link.ld", force=True)
        (sw / "main.c").write_text(self.render_main_c(modules, plan.host), encoding="utf-8")
        (sw / "Makefile").write_text(self.render_makefile(modules), encoding="utf-8")
        return sw, modules
