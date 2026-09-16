"""ORFS/OpenROAD physical implementation setup and execution."""

from __future__ import annotations

import re
from dataclasses import dataclass
from pathlib import Path

from flexsoc.backend.core.core import BackendContext
from flexsoc.backend.core.target import Target
from flexsoc.backend.core.templates import templates
from flexsoc.backend.core.execution import print_label, print_log, print_path_label, strip_ansi
from flexsoc.backend.core.toolchain import orfs_environment


def render_config(
    top: str,
    platform: str,
    netlist: Path,
    sdc_file: Path,
    hold_slack_margin: float = 0.10,
) -> str:
    """Render a physical-only ORFS config from FlexSoC synthesis artifacts."""

    if hold_slack_margin < 0:
        raise ValueError("PNR hold slack margin must be non-negative")
    return templates.render(
        "impl/orfs/config.mk.j2",
        top=top,
        platform=platform,
        netlist=netlist,
        sdc_file=sdc_file,
        hold_slack_margin=f"{hold_slack_margin:g}",
    )


def write_config(
    top: str,
    outdir: Path,
    platform: str,
    netlist: Path,
    sdc_file: Path,
    hold_slack_margin: float = 0.10,
) -> Path:
    """Write `config.mk` for one physical implementation run."""

    outdir = outdir.expanduser().resolve()
    netlist = netlist.expanduser().resolve()
    sdc_file = sdc_file.expanduser().resolve()
    if not netlist.is_file():
        raise ValueError(f"synthesized netlist not found: {netlist}")
    if not sdc_file.is_file():
        raise ValueError(f"SDC not found: {sdc_file}")
    outdir.mkdir(parents=True, exist_ok=True)
    path = outdir / "config.mk"
    path.write_text(
        render_config(top, platform, netlist, sdc_file, hold_slack_margin), encoding="utf-8"
    )
    return path


_STAGE = re.compile(r"stage\s+([1-6])(?:_|\b)", re.IGNORECASE)
_PHASE = {
    "1": "import",
    "2": "floorplan",
    "3": "placement",
    "4": "CTS",
    "5": "routing",
    "6": "finish",
}


def checkpoint(line: str) -> str | None:
    """Return one stable macro-phase label for an ORFS transcript line."""

    plain = strip_ansi(line)
    lower = plain.lower()
    if "extract_parasitics" in lower or "write_spef" in lower or "openrcx" in lower:
        return "extraction"
    match = _STAGE.search(plain)
    return _PHASE.get(match.group(1)) if match else None


def resolve_orfs_branch(
    workdir: Path, kind: str, top: str, platform: str | None = None
) -> Path | None:
    """Return one canonical ORFS branch, rejecting ambiguous fallbacks."""

    base = workdir.expanduser().resolve() / kind
    if platform:
        direct = base / platform / top / "base"
        if direct.is_dir():
            return direct.resolve()
    matches = sorted({path.resolve() for path in base.glob(f"**/{top}/base") if path.is_dir()})
    if len(matches) > 1:
        raise ValueError(
            f"ambiguous ORFS {kind} branch for {top}: "
            + ", ".join(str(path) for path in matches)
        )
    return matches[0] if matches else None


def resolve_orfs_artifact(
    workdir: Path, kind: str, top: str, filename: str, platform: str | None = None
) -> Path | None:
    """Resolve one final ORFS artifact from the canonical branch."""

    branch = resolve_orfs_branch(workdir, kind, top, platform)
    path = branch / filename if branch else None
    return path.resolve() if path is not None and path.is_file() else None


def _final_artifacts(
    workdir: Path, top: str, platform: str | None = None
) -> tuple[tuple[str, Path], ...]:
    """Return final artifacts only from the canonical ORFS result branch."""

    branch = resolve_orfs_branch(workdir, "results", top, platform)
    if branch is None:
        return ()
    names = (
        ("netlist", "6_final.v"),
        ("sdc", "6_final.sdc"),
        ("spef", "6_final.spef"),
        ("odb", "6_final.odb"),
        ("gds", "6_final.gds"),
    )
    return tuple((kind, path) for kind, name in names if (path := branch / name).is_file())


def _config_value(config: Path, key: str) -> str:
    """Read one generated ORFS config value."""

    pattern = re.compile(rf"\s*export\s+{re.escape(key)}\s*:?=\s*(.+?)\s*$")
    for line in config.read_text(encoding="utf-8").splitlines():
        if match := pattern.match(line):
            return match.group(1)
    raise ValueError(f"{key} missing from OpenROAD config: {config}")


def _config_inputs(config: Path) -> tuple[Path, ...]:
    """Return FlexSoC artifacts referenced by generated config.mk."""

    return tuple(
        Path(_config_value(config, key)).expanduser().resolve()
        for key in ("SYNTH_NETLIST_FILES", "SDC_FILE")
    )



def _config_make_overrides(config: Path) -> tuple[str, ...]:
    """Return generated ORFS assignments as command-line make overrides."""

    if not config.is_file():
        return ()
    overrides: list[str] = []
    pattern = re.compile(r"^\s*export\s+([A-Za-z_][A-Za-z0-9_]*)\s*(\?=|:=|=)\s*(.*?)\s*$")
    for raw in config.read_text(encoding="utf-8").splitlines():
        match = pattern.match(raw)
        if not match:
            continue
        name, operator, value = match.groups()
        if operator == "?=":
            continue
        overrides.append(f"{name}={value}")
    return tuple(overrides)


def orfs_paths(values, workdir: Path) -> tuple[Path, Path]:
    """Return the configured ORFS Makefile and generated design config."""

    raw = str(values.get("ORS", "")).strip()
    root = Path(raw).expanduser() if raw else Path.home() / "OpenROAD-flow-scripts" / "flow"
    return (root / "Makefile").resolve(), workdir.expanduser().resolve() / "config.mk"


def orfs_make_argv(
    *,
    makefile: Path,
    config: Path,
    workdir: Path,
    targets: tuple[str, ...] = (),
) -> tuple[str, ...]:
    """Return the canonical out-of-tree ORFS make invocation."""

    makefile = makefile.expanduser().resolve()
    config = config.expanduser().resolve()
    workdir = workdir.expanduser().resolve()
    return (
        "make",
        "-C",
        str(makefile.parent),
        "--no-print-dir",
        f"DESIGN_CONFIG={config}",
        f"WORK_HOME={workdir}",
        *_config_make_overrides(config),
        *targets,
    )


@dataclass(slots=True)
class ImplementationFlow:
    """Prepare, run and inspect the ORFS/OpenROAD implementation stage."""

    context: BackendContext
    runner: object | None = None

    def __post_init__(self) -> None:
        if self.runner is None:
            from flexsoc.backend.core.execution import ToolRunner
            self.runner = ToolRunner(project_root=self.context.project_root)

    def setup(
        self,
        *,
        top: str,
        output_dir: Path,
        platform: str,
        netlist: Path,
        sdc_file: Path,
        hold_slack_margin: float = 0.10,
    ) -> Path:
        """Generate the physical-only ORFS configuration."""

        return write_config(
            top, output_dir, platform, netlist, sdc_file, hold_slack_margin
        )

    def run(
        self,
        *,
        makefile: Path,
        config: Path,
        workdir: Path,
        log: Path,
        on: str = "local",
    ) -> int:
        """Run ORFS through the shared execution layer."""

        from flexsoc.backend.core.execution import CommandRequest

        makefile = makefile.expanduser().resolve()
        config = config.expanduser().resolve()
        workdir = workdir.expanduser().resolve()
        log = log.expanduser().resolve()
        if not makefile.is_file():
            raise ValueError(f"OpenROAD-flow-scripts Makefile not found: {makefile}")
        if not config.is_file():
            raise ValueError(f"OpenROAD config.mk not found: {config}")
        workdir.mkdir(parents=True, exist_ok=True)
        seen: set[str] = set()

        def on_line(line: str) -> None:
            phase = checkpoint(line)
            if phase and phase not in seen:
                seen.add(phase)
                print_label("pnr", phase)

        print_log(log)
        request = CommandRequest(
            orfs_make_argv(makefile=makefile, config=config, workdir=workdir),
            workdir,
            orfs_environment(),
            log,
            inputs=(makefile, config, *_config_inputs(config)),
            outputs=(workdir / "results", workdir / "reports", workdir / "logs"),
            line_callback=on_line,
        )
        result = self.runner.run(request, on=on)
        if result.returncode == 0:
            top = _config_value(config, "DESIGN_NAME")
            platform = _config_value(config, "PLATFORM")
            for kind, path in _final_artifacts(workdir, top, platform):
                print_path_label("report", path, details={"kind": kind})
        return result.returncode

    def collect(
        self, workdir: Path, *, top: str, platform: str | None = None
    ) -> dict[str, Path]:
        """Return canonical final ORFS artifacts by kind."""

        return dict(_final_artifacts(workdir.expanduser().resolve(), top, platform))

    def view(
        self,
        *,
        makefile: Path,
        config: Path,
        workdir: Path,
        log: Path,
        on: str = "local",
    ) -> int:
        """Open the ORFS GUI target through the selected executor."""

        from flexsoc.backend.core.execution import CommandRequest

        request = CommandRequest(
            orfs_make_argv(
                makefile=makefile, config=config, workdir=workdir, targets=("gui_final",),
            ),
            workdir.resolve(),
            orfs_environment(),
            log.resolve(),
        )
        return self.runner.run(request, on=on).returncode

    def run_target(self, target: Target, *, on: str = "local") -> object:
        """Execute one registered physical-implementation target."""

        paths, values = self.context.paths, self.context.values
        if target.action == "pnr_setup":
            platform = values.get("ORS_TECH", values.get("PDK", "sky130"))
            return self.setup(
                top=paths.top, output_dir=paths.impl, platform=platform,
                netlist=paths.syn / f"{paths.top}_synth.v", sdc_file=paths.sdc,
                hold_slack_margin=float(values.get("PNR_HOLD_SLACK_MARGIN", "0.10")),
            )

        makefile, config = orfs_paths(values, paths.impl)
        layout = self.context.layout
        gui = target.action == "pnr_gui"
        log = layout.pnr_log_dir / f"{paths.top}_{'pnr_gui' if gui else 'pnr'}.log"
        if gui:
            return self.view(
                makefile=makefile, config=config, workdir=paths.impl, log=log, on=on,
            )
        if target.action == "pnr":
            return self.run(
                makefile=makefile, config=config, workdir=paths.impl, log=log, on=on,
            )
        raise ValueError(f"unsupported implementation action: {target.action!r}")

    def flow(self, *, setup: dict, run: dict) -> int:
        """Prepare ORFS and run the canonical implementation target."""

        self.setup(**setup)
        return self.run(**run)

    @staticmethod
    def _show_checkpoints(log: Path) -> None:
        """Render compact phase labels from the completed ORFS log."""

        if not log.is_file():
            return
        seen: set[str] = set()
        for line in log.read_text(encoding="utf-8", errors="replace").splitlines():
            phase = checkpoint(line)
            if phase and phase not in seen:
                seen.add(phase)
                print_label("pnr", phase)
