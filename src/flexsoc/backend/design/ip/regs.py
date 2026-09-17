"""Register-description scaffold and generated CSR collateral."""

from __future__ import annotations

import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Any


REGISTER_INTERFACES = ("tlul", "reg_iface", "axi_lite")


# RTL generation


READABLE_SWACCESS = frozenset({"ro", "rc", "rw", "rw1s", "rw1c", "rw0c"})
WRITABLE_SWACCESS = frozenset({"rw", "wo", "r0w1c", "rw1s", "rw1c", "rw0c"})


@dataclass(frozen=True)
class FieldSpec:
    """Normalized field metadata consumed by the Python emitter."""

    name: str
    lsb: int
    msb: int
    swaccess: str
    hwaccess: str
    reset: int | None

    @property
    def mask(self) -> int:
        return ((1 << (self.msb - self.lsb + 1)) - 1) << self.lsb

    @property
    def readable(self) -> bool:
        return self.swaccess in READABLE_SWACCESS

    @property
    def writable(self) -> bool:
        return self.swaccess in WRITABLE_SWACCESS


@dataclass(frozen=True)
class RegisterSpec:
    """Normalized register metadata consumed by the Python emitter."""

    domain: str
    name: str
    offset: int
    reset: int
    reset_mask: int
    fields: tuple[FieldSpec, ...]

    @property
    def path(self) -> str:
        return f"{self.domain}.{self.name}"

    @property
    def readable(self) -> bool:
        return any(field.readable for field in self.fields)

    @property
    def writable(self) -> bool:
        return any(field.writable for field in self.fields)


class RegsFlow:
    """Generate register source and each derived collateral independently."""

    def __init__(self, project_root: Path | None = None, runner=None):
        from flexsoc.backend.core.runtime.execution import ToolRunner

        self.project_root = Path(project_root or Path.cwd()).resolve()
        self.runner = runner or ToolRunner()

    def init_hjson(
        self,
        top: str,
        interface: str,
        output_dir: Path,
        *,
        force: bool = False,
        clocks=None,
    ) -> Path | tuple[Path, ...]:
        """Create the HJSON source of truth for one IP."""

        if clocks is not None and clocks.multiclock:
            from flexsoc.backend.core.render.templates import templates

            protocol = RegsFlow.reggen_interface(interface)
            specs = (
                ("cfg", "design/registers/nclock_cfg.hjson.j2"),
                ("dsp", "design/registers/nclock_dsp.hjson.j2"),
            )
            return tuple(
                templates.write(
                    template, Path(output_dir) / f"{top}_{name}.hjson",
                    force=force, top=top, protocol=protocol,
                )
                for name, template in specs
            )
        return RegsFlow.write_hjson(top, interface, output_dir, force=force)

    def _maps(self, top: str, data_dir: Path, regmap: str | None = None) -> tuple[Path, ...]:
        named = sorted(data_dir.glob(f"{top}_*.hjson"))
        paths = named or [data_dir / f"{top}.hjson"]
        if regmap:
            paths = [path for path in paths if path.stem == f"{top}_{regmap}"]
        selected = tuple(path for path in paths if path.is_file())
        if not selected:
            raise FileNotFoundError(f"no HJSON register maps for {top} under {data_dir}")
        return selected

    def _regtool(self) -> Path:
        """Return the pinned OpenTitan regtool used for generated collateral."""

        tool = self.project_root / "vendor" / "opentitan_reggen" / "util" / "regtool.py"
        if not tool.is_file():
            raise FileNotFoundError(
                "missing vendored regtool; run `fx fetch --set VENDOR=opentitan_reggen`"
            )
        return tool

    @staticmethod
    def _regtool_failure(action: str, source: Path, log: Path) -> RuntimeError:
        lines = (
            log.read_text(encoding="utf-8", errors="replace").splitlines()
            if log.is_file()
            else []
        )
        detail = lines[-1] if lines else "no regtool log output"
        return RuntimeError(
            f"regtool {action} failed: {source} · {detail} · log: {log.resolve()}"
        )

    def _run_regtool(
        self,
        argv: list[str],
        *,
        cwd: Path,
        log: Path,
        on: str = "local",
    ) -> int:
        from flexsoc.backend.core.runtime.execution import CommandRequest

        request = CommandRequest(
            (sys.executable, str(self._regtool()), *argv),
            cwd,
            {},
            log,
        )
        return self.runner.run(request, on=on).returncode

    def setup_rtl(
        self,
        top: str,
        data_dir: Path,
        rtl_dir: Path,
        *,
        regmap: str | None = None,
        on: str = "local",
    ) -> tuple[Path, ...]:
        """Generate CSR RTL for one or all register maps."""

        rtl_dir.mkdir(parents=True, exist_ok=True)
        outputs: list[Path] = []
        for source in self._maps(top, data_dir, regmap):
            RegsFlow.validate_reggen_transport(source)
            log = rtl_dir / f".{source.stem}_regtool.log"
            argv = ["-r", "-t", str(rtl_dir), str(source)]
            if self._run_regtool(argv, cwd=self.project_root, log=log, on=on):
                raise self._regtool_failure("RTL generation", source, log)
            RegsFlow.add_axi_lite_types(rtl_dir / f"{source.stem}_reg_pkg.sv")
            outputs.append(source)
        return tuple(outputs)

    def setup_docs(
        self,
        top: str,
        data_dir: Path,
        doc_dir: Path,
        *,
        regmap: str | None = None,
        on: str = "local",
    ) -> tuple[Path, ...]:
        """Generate register and interface documentation."""

        doc_dir.mkdir(parents=True, exist_ok=True)
        outputs: list[Path] = []
        for source in self._maps(top, data_dir, regmap):
            doc = doc_dir / f"{source.stem}.md"
            interfaces = doc_dir / f"{source.stem}_interfaces.md"
            log = doc_dir / f".{source.stem}_regtool.log"
            commands = (
                ["-d", "-o", str(doc), str(source)],
                ["--interfaces", "-o", str(interfaces), str(source)],
            )
            for argv in commands:
                if self._run_regtool(argv, cwd=self.project_root, log=log, on=on):
                    raise self._regtool_failure("documentation", source, log)
            outputs.extend((doc, interfaces))
        return tuple(outputs)

    def setup_systemrdl(
        self,
        top: str,
        data_dir: Path,
        output_dir: Path,
        *,
        regmap: str | None = None,
        on: str = "local",
    ) -> tuple[Path, ...]:
        """Export one SystemRDL view for every authored HJSON register map."""

        output_dir.mkdir(parents=True, exist_ok=True)
        outputs = []
        for source in self._maps(top, data_dir, regmap):
            output = output_dir / f"{source.stem}.rdl"
            log = output_dir / f".{source.stem}_regtool.log"
            argv = ["--systemrdl", "-o", str(output), str(source)]
            if self._run_regtool(argv, cwd=self.project_root, log=log, on=on):
                raise self._regtool_failure("SystemRDL export", source, log)
            outputs.append(output)
        return tuple(outputs)

    def setup_driver(
        self,
        hjson_file: Path,
        output_dir: Path,
        *,
        base_address: str = "0x0",
        on: str = "local",
    ) -> tuple[Path, Path]:
        """Generate the C register header and FlexSoC driver source."""

        module_name = str(RegsFlow.load_hjson(hjson_file)["name"])
        output_dir.mkdir(parents=True, exist_ok=True)
        header = output_dir / f"{module_name}.h"
        log = output_dir / f".{module_name}_regtool.log"
        argv = ["--cdefines", "-o", str(header), str(hjson_file)]
        if self._run_regtool(argv, cwd=self.project_root, log=log, on=on):
            raise self._regtool_failure("C header generation", hjson_file, log)
        return RegsFlow._generate_driver(hjson_file, output_dir, base_address)

    def setup_regmap_py(
        self,
        top: str,
        data_dir: Path,
        model_dir: Path,
        *,
        force: bool = False,
        refresh_tests: bool = True,
        clocks=None,
    ) -> Path:
        """Generate the Python CSR API and optional machine-owned tests."""

        path = RegsFlow.generate(top, data_dir, model_dir, force=force)
        if refresh_tests:
            from .model import ModelFlow
            from flexsoc.backend.core import ClockConfig

            resolved = clocks or ClockConfig.from_values()
            ModelFlow.write_regmap_tests(top, model_dir, safe_controls=resolved.multiclock)
        return path

    @staticmethod
    def normalize_register_interface(value: str) -> str:
        """Return one canonical external register-interface intent."""

        interface = value.strip().lower()
        if interface not in REGISTER_INTERFACES:
            choices = ", ".join(REGISTER_INTERFACES)
            raise ValueError(f"REG_ITF must be one of: {choices}")
        return interface

    @staticmethod
    def reggen_interface(value: str) -> str:
        """Return the canonical internal register-file transport."""

        RegsFlow.normalize_register_interface(value)
        return "reg_iface"

    @staticmethod
    def reggen_device_protocols(path: str | Path) -> tuple[str, ...]:
        """Return device-side protocols declared by one register HJSON source."""

        data = RegsFlow.load_hjson(path)
        interfaces = data.get("bus_interfaces")
        if isinstance(interfaces, list):
            protocols = tuple(
                str(item.get("protocol", "")).strip().lower()
                for item in interfaces
                if hasattr(item, "get") and str(item.get("direction", "")).strip().lower() == "device"
            )
            if protocols:
                return protocols

        # Keep the lightweight no-hjson fallback useful for static/unit checks.
        import re

        text = Path(path).read_text(encoding="utf-8")
        protocols: list[str] = []
        for body in re.findall(r"\{([^{}]*)\}", text, re.S):
            direction = re.search(r"\bdirection\s*:\s*[\"']?([A-Za-z0-9_]+)", body)
            protocol = re.search(r"\bprotocol\s*:\s*[\"']?([A-Za-z0-9_]+)", body)
            if direction and protocol and direction.group(1).lower() == "device":
                protocols.append(protocol.group(1).lower())
        return tuple(protocols)

    @staticmethod
    def validate_reggen_transport(path: str | Path) -> None:
        """Require the one canonical reggen device transport used by FlexSoC."""

        protocols = RegsFlow.reggen_device_protocols(path)
        if protocols != ("reg_iface",):
            raise ValueError(
                f"{Path(path)}: canonical register RTL requires exactly one device "
                f"bus_interface with protocol='reg_iface'; found {list(protocols)!r}. "
                "REG_ITF selects the external FlexSoC wrapper, not reggen transport."
            )

    @staticmethod
    def render_hjson(top: str, itf: str) -> str:
        """Render the editable single-clock register scaffold."""

        from flexsoc.backend.core.render.templates import templates

        return templates.render(
            "design/registers/ip.hjson.j2",
            top=top, protocol=RegsFlow.reggen_interface(itf),
        )

    @staticmethod
    def write_hjson(top: str, itf: str, output: str | Path = ".", *, force: bool = False) -> Path:
        """Write or preserve the editable HJSON source of truth."""

        from flexsoc.backend.core.render.templates import templates

        return templates.write(
            "design/registers/ip.hjson.j2",
            Path(output or ".") / f"{top}.hjson",
            force=force, top=top, protocol=RegsFlow.reggen_interface(itf),
        )

    @staticmethod
    def cfg_hjson(top: str, itf: str = "tlul") -> str:
        """Render the cfg-domain HJSON scaffold."""

        from flexsoc.backend.core.render.templates import templates

        return templates.render(
            "design/registers/nclock_cfg.hjson.j2",
            top=top, protocol=RegsFlow.reggen_interface(itf),
        )

    @staticmethod
    def dsp_hjson(top: str, itf: str = "tlul") -> str:
        """Render the dsp-domain HJSON scaffold."""

        from flexsoc.backend.core.render.templates import templates

        return templates.render(
            "design/registers/nclock_dsp.hjson.j2",
            top=top, protocol=RegsFlow.reggen_interface(itf),
        )

    @staticmethod
    def generic_hjson(top: str, regmap: str, itf: str = "tlul") -> str:
        """Render a generic extra-domain HJSON scaffold."""

        from flexsoc.backend.core.render.templates import templates

        return templates.render(
            "design/registers/nclock_domain.hjson.j2",
            top=top, regmap=regmap, protocol=RegsFlow.reggen_interface(itf),
        )

    @staticmethod
    def render_nclock_hjson(top: str, regmap: str, itf: str = "tlul") -> str:
        """Render one N-clock regmap by short name."""

        if regmap == "cfg":
            return RegsFlow.cfg_hjson(top, itf)
        if regmap == "dsp":
            return RegsFlow.dsp_hjson(top, itf)
        return RegsFlow.generic_hjson(top, regmap, itf)

    @staticmethod
    def load_hjson(path: str | Path) -> dict[str, Any]:
        """Load one HJSON file with hjson, falling back to a tiny name parser."""

        text = Path(path).read_text(encoding="utf-8")
        try:
            import hjson  # type: ignore

            return hjson.loads(text)
        except ImportError:
            import re

            match = re.search(r"\bname\s*:\s*[\"']?([A-Za-z_][A-Za-z0-9_]*)", text)
            if match:
                return {"name": match.group(1)}
            raise

    @staticmethod
    def render_header_declarations(module_name: str, base_address: str) -> str:
        """Render the C declarations injected into the generated header."""

        from flexsoc.backend.core.render.templates import templates

        return templates.render(
            "design/registers/driver_header.h.j2",
            module_name=module_name, upper=module_name.upper(), base_address=base_address,
        ) + "\n"

    @staticmethod
    def insert_function_declarations(header_path: str | Path, base_address: str, module_name: str) -> Path:
        """Inject the common driver declarations before the C++ guard when present."""

        path = Path(header_path)
        lines = path.read_text(encoding="utf-8").splitlines(keepends=True)
        decls = RegsFlow.render_header_declarations(module_name, base_address)
        index = next((i for i, line in enumerate(lines) if line.strip().startswith("#ifdef __cplusplus")), len(lines))
        path.write_text("".join(lines[:index]) + decls + "".join(lines[index:]), encoding="utf-8")
        return path

    @staticmethod
    def render_uart_source(module_name: str) -> str:
        """Render the UART-specialized C driver body."""

        from flexsoc.backend.core.render.templates import templates

        return templates.render(
            "design/registers/driver_uart.c.j2",
            module_name=module_name, upper=module_name.upper(),
        )

    @staticmethod
    def render_generic_source(module_name: str) -> str:
        """Render the generic memory-mapped C driver body."""

        from flexsoc.backend.core.render.templates import templates

        return templates.render(
            "design/registers/driver_generic.c.j2",
            module_name=module_name, upper=module_name.upper(),
        )

    @staticmethod
    def write_source(module_name: str, output_dir: str | Path) -> Path:
        """Write the selected C driver body and return the generated path."""

        path = Path(output_dir) / f"{module_name}.c"
        renderer = RegsFlow.render_uart_source if module_name in {"uart", "uart_master"} else RegsFlow.render_generic_source
        path.write_text(renderer(module_name), encoding="utf-8")
        return path

    @staticmethod
    def _generate_driver(hjson_file: str | Path, output_dir: str | Path, base_address: str) -> tuple[Path, Path]:
        """Generate header declarations and C source for one decoded IP block."""

        module_name = str(RegsFlow.load_hjson(hjson_file)["name"])
        outdir = Path(output_dir)
        outdir.mkdir(parents=True, exist_ok=True)
        header = RegsFlow.insert_function_declarations(outdir / f"{module_name}.h", base_address, module_name)
        source = RegsFlow.write_source(module_name, outdir)
        return header, source

    @staticmethod
    def _reggen_ip_block() -> Any:
        """Return ``IpBlock`` from the pinned OpenTitan reggen vendor."""

        util_dir = Path(__file__).resolve().parents[4] / "vendor" / "opentitan_reggen" / "util"
        if not (util_dir / "reggen").is_dir():
            raise SystemExit(
                "missing vendored reggen; run `fx fetch --set VENDOR=opentitan_reggen`"
            )
        if str(util_dir) not in sys.path:
            sys.path.insert(0, str(util_dir))
        try:
            from reggen.ip_block import IpBlock  # type: ignore
        except ModuleNotFoundError as exc:
            missing = exc.name or "reggen dependency"
            raise SystemExit(
                f"cannot load vendored reggen ({missing!r} missing); run `uv sync` first"
            ) from exc
        return IpBlock

    @staticmethod
    def _source_files(top: str, data_dir: Path) -> list[tuple[str, Path]]:
        """Discover one flat map or any number of named domain maps."""

        named = sorted(data_dir.glob(f"{top}_*.hjson"))
        if named:
            return [(path.stem[len(top) + 1 :], path) for path in named]
        path = data_dir / f"{top}.hjson"
        if path.exists():
            return [("core", path)]
        raise SystemExit(f"no HJSON register maps found for {top} under {data_dir}")

    @staticmethod
    def _field_spec(field: Any) -> FieldSpec:
        reset = field.resval if isinstance(field.resval, int) else None
        return FieldSpec(
            name=str(field.name).upper(),
            lsb=int(field.bits.lsb),
            msb=int(field.bits.msb),
            swaccess=str(field.swaccess.key).lower(),
            hwaccess=str(field.hwaccess.key).lower(),
            reset=reset,
        )

    @staticmethod
    def _collect(top: str, data_dir: Path) -> tuple[list[Path], list[RegisterSpec]]:
        """Load HJSON through reggen and return flattened software-visible CSRs."""

        IpBlock = RegsFlow._reggen_ip_block()
        sources: list[Path] = []
        registers: list[RegisterSpec] = []
        seen_paths: set[str] = set()

        for fallback_domain, source in RegsFlow._source_files(top, data_dir):
            try:
                block = IpBlock.from_path(str(source), [])
            except (RuntimeError, ValueError) as exc:
                raise SystemExit(f"invalid HJSON regmap {source}: {exc}") from exc

            sources.append(source)
            primary_clock = getattr(getattr(block.clocking, "primary", None), "clock", None)
            domain = fallback_domain if source.stem != top else str(primary_clock or fallback_domain)

            for reg_block in block.reg_blocks.values():
                for register in reg_block.flat_regs:
                    spec = RegisterSpec(
                        domain=domain,
                        name=str(register.name).upper(),
                        offset=int(register.offset),
                        reset=int(register.resval),
                        reset_mask=int(register.resmask),
                        fields=tuple(RegsFlow._field_spec(field) for field in register.fields),
                    )
                    if spec.path in seen_paths:
                        raise SystemExit(
                            f"duplicate model register path {spec.path!r} while reading {source}"
                        )
                    seen_paths.add(spec.path)
                    registers.append(spec)

        if not registers:
            joined = ", ".join(str(path) for path in sources)
            raise SystemExit(f"no registers found in HJSON source(s): {joined}")
        return sources, registers

    @staticmethod
    def _field_expr(field: FieldSpec) -> str:
        return (
            "Field("
            f"name={field.name!r}, lsb={field.lsb}, msb={field.msb}, "
            f"swaccess={field.swaccess!r}, hwaccess={field.hwaccess!r}, "
            f"reset={field.reset!r})"
        )

    @staticmethod
    def _domain_literal(registers: list[RegisterSpec]) -> str:
        by_domain: dict[str, list[RegisterSpec]] = {}
        for register in registers:
            by_domain.setdefault(register.domain, []).append(register)

        rows: list[str] = []
        for domain, domain_registers in by_domain.items():
            rows.extend(
                [
                    f"    {domain!r}: RegisterDomain(",
                    f"        name={domain!r},",
                    "        registers=(",
                ]
            )
            for register in domain_registers:
                rows.extend(
                    [
                        "            Register(",
                        f"                domain={register.domain!r},",
                        f"                name={register.name!r},",
                        f"                offset=0x{register.offset:08x},",
                        f"                reset=0x{register.reset:08x},",
                        f"                mask=0x{register.reset_mask:08x},",
                        "                fields=(",
                        *(
                            f"                    {RegsFlow._field_expr(field)},"
                            for field in register.fields
                        ),
                        "                ),",
                        "            ),",
                    ]
                )
            rows.extend(["        ),", "    ),"])
        return "\n".join(rows)

    @staticmethod
    def _emit_python(top: str, sources: list[Path], registers: list[RegisterSpec]) -> str:
        """Render the dependency-free ``<top>_regmap.py`` helper."""

        from flexsoc.backend.core.render.templates import templates

        return templates.render(
            "design/registers/regmap.py.j2",
            top=top,
            top_repr=repr(top),
            source_names=", ".join(path.name for path in sources),
            primary_domain_repr=repr(registers[0].domain),
            readable_repr=repr(tuple(sorted(READABLE_SWACCESS))),
            writable_repr=repr(tuple(sorted(WRITABLE_SWACCESS))),
            domain_literal=RegsFlow._domain_literal(registers),
        )

    @staticmethod
    def generate(
        top: str,
        data_dir: Path,
        model_dir: Path,
        *,
        force: bool = False,
    ) -> Path:
        """Generate only ``<top>_regmap.py`` from HJSON."""

        model_dir.mkdir(parents=True, exist_ok=True)
        out_path = model_dir / f"{top}_regmap.py"
        if out_path.exists() and not force:
            return out_path

        sources, registers = RegsFlow._collect(top, data_dir)
        out_path.write_text(RegsFlow._emit_python(top, sources, registers), encoding="utf-8")
        return out_path

    @staticmethod
    def add_axi_lite_types(path: str | Path) -> Path:
        """Add the canonical packed AXI4-Lite view to one generated register package."""

        pkg = Path(path)
        text = pkg.read_text(encoding="utf-8")
        if "} axi_lite_req_t;" in text and "} axi_lite_rsp_t;" in text:
            return pkg
        marker = "\nendpackage"
        if marker not in text:
            raise RuntimeError(f"generated register package has no endpackage: {pkg}")
        from flexsoc.backend.core.render.templates import templates

        types = templates.render("design/registers/axi_lite_types.svh.j2")
        pkg.write_text(text.replace(marker, f"\n{types}{marker}", 1), encoding="utf-8")
        return pkg
