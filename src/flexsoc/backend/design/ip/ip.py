"""IP design target orchestration."""

from __future__ import annotations

import shlex
from dataclasses import dataclass, field
from pathlib import Path

from ...core import BackendContext, Target, ToolRunner
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
                paths.csr / f"{top}.hjson", paths.drivers,
                base_address=values.get("BASE_ADDRESS", "0x0"), on=on,
            )
        if action == "regmap_py":
            return self.regs.setup_regmap_py(
                top, paths.csr, paths.model, force=force, refresh_tests=True,
                clocks=self.context.clocks,
            )
        if action == "rtl_scaffold":
            hjson = paths.csr / f"{top}.hjson"
            return self.rtl.init_scaffold(
                hjson if hjson.exists() else None, interface, paths.rtl,
                top=top, force=force, clocks=self.context.clocks,
            )
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
                top, paths.csr, paths.model, paths.rtl,
                force=force, clocks=self.context.clocks,
            )
        raise ValueError(f"unsupported design action: {action!r}")

    @staticmethod
    def _bool(value: object, default: bool = False) -> bool:
        if value is None:
            return default
        return str(value).strip().lower() in {"1", "true", "yes", "on"}

    def _setup_filelists(self, *, on: str):
        """Generate canonical common/IP filelists for the selected interface."""

        values, paths = self.context.values, self.context.paths
        root = self.context.project_root
        ips_root = root / "hw" / "ips"
        common = tuple(
            ips_root / name
            for name in ("pkgs", "prim", "prim_opentitan")
            if (ips_root / name).is_dir()
        )
        vendor_roots: tuple[Path, ...] = ()
        extra_args = ""
        interface = values.get("REG_ITF", "tlul")
        vendor = root / "vendor"
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
