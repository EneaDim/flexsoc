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
        if action in {"slang_hier", "slang_ast"}:
            return self._run_slang(action, on=on)
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

    def _slang_inputs(self) -> tuple[Path, Path, tuple[Path, ...], str]:
        """Resolve hierarchy/AST inputs from settings and canonical filelists."""

        values, paths = self.context.values, self.context.paths
        root = Path(values.get("SLANG_ROOT", paths.rtl)).expanduser().resolve()
        top_file = Path(values.get("SLANG_TOP_FILE", root / f"{paths.top}.sv")).expanduser().resolve()
        tokens = iter(shlex.split(values.get("SLANG_SEARCH_ARGS", "")))
        roots: list[Path] = []
        extra: list[str] = []
        for token in tokens:
            if token == "--search-root":
                try:
                    roots.append(Path(next(tokens)).expanduser().resolve())
                except StopIteration as exc:
                    raise ValueError("SLANG_SEARCH_ARGS: --search-root requires a path") from exc
            elif token.startswith("--search-root="):
                roots.append(Path(token.split("=", 1)[1]).expanduser().resolve())
            else:
                extra.append(token)
        if not roots:
            for filelist in (paths.rtl_common, paths.rtl_ip):
                if not filelist.is_file():
                    continue
                for raw in filelist.read_text(encoding="utf-8").splitlines():
                    item = raw.strip()
                    if not item or item.startswith(("#", "+define+")):
                        continue
                    items = (
                        item.removeprefix("+incdir+").split("+")
                        if item.startswith("+incdir+")
                        else [str(Path(item).parent)]
                    )
                    roots.extend(
                        (root / path if not path.is_absolute() else path).resolve()
                        for path in map(Path, items) if str(path)
                    )
            roots = list(dict.fromkeys(roots)) or [
                paths.rtl, self.context.project_root / "hw" / "ips",
                self.context.project_root / "vendor",
            ]
        args = [*shlex.split(values.get("SLANG_ARGS", "")), *extra]
        return root, top_file, tuple(roots), shlex.join(args)

    def _run_slang(self, action: str, *, on: str):
        """Write hierarchy or AST through the shared execution abstraction."""

        values, paths = self.context.values, self.context.paths
        root, top_file, search_roots, extra_args = self._slang_inputs()
        top = values.get("SLANG_TOP", paths.top)
        if action == "slang_hier":
            return self.rtl.show_hierarchy(
                root=root, top_file=top_file,
                output=paths.slang / f"{paths.top}_hier.txt",
                search_roots=search_roots, top=top, extra_args=extra_args,
                slang_hier=values.get("SLANG_HIER", "slang-hier"), on=on,
            )
        return self.rtl.show_ast(
            root=root, top_file=top_file,
            output=paths.slang / f"{paths.top}_ast.json",
            search_roots=search_roots, top=top, extra_args=extra_args,
            slang=values.get("SLANG", "slang"),
            scope=values.get("SLANG_AST_SCOPE"), on=on,
        )

