"""ORFS/OpenROAD physical implementation setup and execution."""

from __future__ import annotations

import re
from dataclasses import dataclass
from pathlib import Path
from textwrap import dedent

from flexsoc.backend.core.execution import print_label, print_log, print_path_label, strip_ansi
from flexsoc.backend.core.toolchain import orfs_environment


def render_config(
    top: str,
    platform: str,
    netlist: Path,
    sdc_file: Path,
) -> str:
    """Render a physical-only ORFS config from FlexSoC synthesis artifacts."""
    return dedent(
        f"""\
        # OpenROAD-flow-scripts physical implementation (generated)
        export DESIGN_NICKNAME = {top}
        export DESIGN_NAME     = {top}
        export PLATFORM        = {platform}

        # FlexSoC owns synthesis and timing intent.
        export SYNTH_NETLIST_FILES := {netlist}
        export SDC_FILE             := {sdc_file}

        # Platform-owned physical views (LEF/GDS/CDL/LVS decks) stay with ORFS.
        # Physical defaults; synthesis strategy does not alter these.
        export CORE_UTILIZATION ?= 50
        export PLACE_DENSITY ?= 0.58
        export PLACE_DENSITY_LB_ADDON = 0.20
        export TNS_END_PERCENT = 100

        export DETAILED_METRICS := 1
        export REPORT_CLOCK_SKEW := 1
        export GUI_TIMING := 1
        export SETUP_SLACK_MARGIN := 0
        export HOLD_SLACK_MARGIN  := 0
        export CELL_PAD_IN_SITES_GLOBAL_PLACEMENT := 0
        export CELL_PAD_IN_SITES_DETAIL_PLACEMENT := 0
        export DETAILED_ROUTE_END_ITERATION := 64
        export USE_FILL := 0
        export GPL_TIMING_DRIVEN := 1
        export GPL_ROUTABILITY_DRIVEN := 1
        """
    )


def write_config(
    top: str,
    outdir: Path,
    platform: str,
    netlist: Path,
    sdc_file: Path,
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
    path.write_text(render_config(top, platform, netlist, sdc_file), encoding="utf-8")
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


def _final_artifacts(workdir: Path) -> tuple[tuple[str, Path], ...]:
    results = workdir / "results"
    names = (
        ("netlist", "6_final.v"),
        ("sdc", "6_final.sdc"),
        ("spef", "6_final.spef"),
        ("odb", "6_final.odb"),
        ("gds", "6_final.gds"),
    )
    found: list[tuple[str, Path]] = []
    for kind, name in names:
        candidates = sorted(results.glob(f"**/{name}")) if results.is_dir() else []
        if candidates:
            found.append((kind, candidates[-1]))
    return tuple(found)



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
        *targets,
    )


@dataclass(slots=True)
class ImplementationFlow:
    """Prepare, run and inspect the ORFS/OpenROAD implementation stage."""

    runner: object | None = None

    def __post_init__(self) -> None:
        if self.runner is None:
            from flexsoc.backend.core.execution import ToolRunner
            self.runner = ToolRunner()

    def setup(
        self,
        *,
        top: str,
        output_dir: Path,
        platform: str,
        netlist: Path,
        sdc_file: Path,
    ) -> Path:
        """Generate the physical-only ORFS configuration."""

        return write_config(top, output_dir, platform, netlist, sdc_file)

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
            line_callback=on_line,
        )
        result = self.runner.run(request, on=on)
        if result.returncode == 0:
            for kind, path in _final_artifacts(workdir):
                print_path_label("report", path, details={"kind": kind})
        return result.returncode

    def collect(self, workdir: Path) -> dict[str, Path]:
        """Return canonical final ORFS artifacts by kind."""

        return {kind: path for kind, path in _final_artifacts(workdir.expanduser().resolve())}

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
