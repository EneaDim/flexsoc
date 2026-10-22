"""IP design target orchestration."""

from __future__ import annotations

import shlex
from dataclasses import dataclass, field
from pathlib import Path

from ...core import BackendContext, Target, ToolRunner
from ...core.render.templates import templates
from .model import ModelFlow
from .regs import RegsFlow
from .rtl import RtlFlow


@dataclass(slots=True)
class IpDesign:
    """Own IP design scaffolds and generated design collateral."""

    context: BackendContext
    runner: ToolRunner | None = None
    regs: RegsFlow = field(init=False)
    rtl: RtlFlow = field(init=False)
    model: ModelFlow = field(init=False)

    def __post_init__(self) -> None:
        self.runner = self.runner or ToolRunner(project_root=self.context.project_root)
        root = self.context.project_root
        self.regs = RegsFlow(root, self.runner)
        self.rtl = RtlFlow(root, self.runner)
        self.model = ModelFlow(root)

    def run_target(self, target: Target, *, on: str = "local"):
        """Execute one registered design target through its owning component."""

        action = target.action or ""
        values, paths = self.context.values, self.context.paths
        top = paths.top
        interface = values.get("REG_ITF", "tlul")
        force = self._bool(values.get("FORCE"))

        if action == "hjson":
            return self.regs.init_hjson(
                top, interface, paths.csr, force=force, clocks=self.context.clocks,
            )
        if action == "reg_rtl":
            return self.regs.setup_rtl(
                top, paths.csr, paths.rtl, regmap=values.get("REGMAP"), on=on,
            )
        if action == "reg_docs":
            return self.regs.setup_docs(
                top, paths.csr, paths.doc, regmap=values.get("REGMAP"), on=on,
            )
        if action == "systemrdl":
            return self.regs.setup_systemrdl(
                top, paths.csr, paths.csr_systemrdl,
                regmap=values.get("REGMAP"), on=on,
            )
        if action == "driver":
            return self.regs.setup_driver(
                paths.csr / f"{top}.hjson", paths.drivers, on=on,
            )
        if action == "regmap_py":
            return self.regs.setup_regmap_py(
                top, paths.csr, paths.py / "rtl", force=force, refresh_tests=True,
                clocks=self.context.clocks,
            )
        if action == "rtl_scaffold":
            hjson = paths.csr / f"{top}.hjson"
            result = self.rtl.init_scaffold(
                hjson if hjson.exists() else None, interface, paths.rtl,
                top=top, force=force, clocks=self.context.clocks,
            )
            self._setup_formal_properties(top)
            return result
        if action == "rtl_top":
            return self.rtl.setup_top(
                top, paths.rtl, interface, force=force, clocks=self.context.clocks,
            )
        if action == "filelists":
            return self._setup_filelists(on=on)
        if action == "fetch":
            vendor = values.get("VENDOR") or values.get("TARGET")
            if not vendor:
                raise ValueError("fetch requires VENDOR=<name>")
            return self.rtl.fetch_vendor(
                self.context.project_root / "vendor" / f"{vendor}.vendor.hjson",
                target_dir=self.context.project_root, force=force, on=on,
            )
        if action == "model_setup":
            return self.model.setup(
                top, paths.csr, paths.py / "model", paths.rtl,
                force=force, clocks=self.context.clocks, regmap_output=paths.py / "rtl",
            )
        raise ValueError(f"unsupported design action: {action!r}")


    def _setup_formal_properties(self, top: str) -> None:
        """Create editable properties aligned with the generated example core."""

        properties = self.context.paths.formal / "properties"
        for mode in ("prove", "cover"):
            templates.write(
                "design/rtl/scaffold_properties.sv.j2",
                properties / mode / f"{top}_{mode}.sv",
                top=top, mode=mode, multiclock=self.context.clocks.multiclock,
            )

    @staticmethod
    def _bool(value: object, default: bool = False) -> bool:
        if value is None:
            return default
        return str(value).strip().lower() in {"1", "true", "yes", "on"}

    def _setup_filelists(self, *, on: str):
        """Generate canonical common/IP filelists for the selected interface."""

        values, paths = self.context.values, self.context.paths
        root = self.context.project_root
        # Loaded IP releases must consume a single frozen dependency tree.
        # Never mix checkout hw/ips with rtl/deps/flexsoc/hw/ips.
        frozen = paths.rtl / "deps" / "flexsoc"
        has_frozen = (frozen / "hw" / "ips").is_dir() or (frozen / "vendor").is_dir()
        library_root = frozen if has_frozen else root
        ips_root = library_root / "hw" / "ips"
        # A loaded package may freeze primitives in either of two legacy
        # layouts: deps/flexsoc/{prim,prim_opentitan} or
        # deps/flexsoc/hw/ips/{prim,prim_opentitan}. Pick ONE per library.
        # Never resolve missing frozen modules against the mutable checkout.
        common_dirs = [ips_root / "pkgs"]
        for name in ("prim", "prim_opentitan"):
            frozen_legacy = frozen / name
            preferred = frozen_legacy if has_frozen and frozen_legacy.is_dir() else ips_root / name
            common_dirs.append(preferred)
        common = tuple(path for path in common_dirs if path.is_dir())
        vendor_roots: tuple[Path, ...] = ()
        extra_args = ""
        interface = values.get("REG_ITF", "tlul")
        vendor = library_root / "vendor"
        if interface == "tlul":
            vendor_roots = (vendor / "lowrisc_ip" / "ip" / "tlul" / "rtl",)
        elif interface == "axi_lite":
            pulp = vendor / "pulp"
            vendor_roots = (
                pulp / "common_cells" / "src",
                pulp / "axi" / "src",
                pulp / "register_interface" / "src",
            )
            extra_args = shlex.join((
                "-I", str(pulp / "axi" / "include"),
                "-I", str(pulp / "register_interface" / "include"),
            ))
        if has_frozen:
            # For a loaded snapshot, do not fall back silently to mutable checkout
            # sources when the frozen library is incomplete.
            for lib in (*common, *vendor_roots):
                if not lib.is_dir():
                    raise FileNotFoundError(f"frozen RTL dependency root missing: {lib}")
        return self.rtl.setup_filelists(
            root=root,
            top_file=paths.rtl / f"{paths.top}.sv",
            common_out=paths.rtl_common,
            ip_out=paths.rtl_ip,
            search_roots=(paths.rtl, *common, *vendor_roots),
            common_roots=(*common, *vendor_roots),
            top=paths.top,
            extra_args=extra_args,
            slang=values.get("SLANG", "slang"),
            on=on,
        )
