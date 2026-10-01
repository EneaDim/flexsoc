"""ORFS/OpenROAD physical implementation setup and execution."""

from __future__ import annotations

import json
import re
from dataclasses import dataclass, replace
from io import StringIO
from pathlib import Path
from typing import Mapping

from rich.console import Console

from flexsoc.backend.core.core import BackendContext
from flexsoc.backend.core.flow.target import Target
from flexsoc.backend.core.render.show import ShowRenderer
from flexsoc.backend.core.render.templates import templates
from flexsoc.backend.core.runtime.execution import Terminal
from flexsoc.backend.core.runtime.toolchain import Toolchain


_STAGE = re.compile(r"stage\s+([1-6])(?:_|\b)", re.IGNORECASE)
_PHASE = {
    "1": "import",
    "2": "floorplan",
    "3": "placement",
    "4": "CTS",
    "5": "routing",
    "6": "finish",
}
_FINAL_ARTIFACTS = (
    ("netlist", "6_final.v"),
    ("sdc", "6_final.sdc"),
    ("spef", "6_final.spef"),
    ("odb", "6_final.odb"),
    ("gds", "6_final.gds"),
)


@dataclass(slots=True)
class ImplementationFlow:
    """Prepare, run and inspect the ORFS/OpenROAD implementation stage."""

    context: BackendContext
    runner: object | None = None

    def __post_init__(self) -> None:
        if self.runner is None:
            from flexsoc.backend.core.runtime.execution import ToolRunner
            self.runner = ToolRunner(project_root=self.context.project_root)

    def setup(
        self,
        *,
        top: str,
        output_dir: Path,
        platform: str,
        netlist: Path,
        sdc_file: Path,
        corner_liberties: Mapping[str, Path] | None = None,
        hold_slack_margin: float = 0.05,
        slew_margin: float = 30.0,
        cap_margin: float = 30.0,
    ) -> Path:
        """Generate the physical-only ORFS configuration."""

        return ImplementationFlow.write_config(
            top, output_dir, platform, netlist, sdc_file, corner_liberties,
            hold_slack_margin, slew_margin, cap_margin,
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
        """Run ORFS and publish canonical implementation evidence."""

        from flexsoc.backend.core.runtime.execution import CommandRequest

        makefile = makefile.expanduser().resolve()
        config = config.expanduser().resolve()
        workdir = workdir.expanduser().resolve()
        log = log.expanduser().resolve()
        if not makefile.is_file():
            raise ValueError(f"OpenROAD-flow-scripts Makefile not found: {makefile}")
        if not config.is_file():
            raise ValueError(f"OpenROAD config.mk not found: {config}")
        workdir.mkdir(parents=True, exist_ok=True)
        seen: list[str] = []

        def on_line(line: str) -> None:
            phase = ImplementationFlow.checkpoint(line)
            if phase and phase not in seen:
                seen.append(phase)
                Terminal.print_label("pnr", phase)

        Terminal.print_log(log)
        request = CommandRequest(
            ImplementationFlow.orfs_make_argv(makefile=makefile, config=config, workdir=workdir),
            workdir,
            Toolchain.orfs_environment(),
            log,
            inputs=(makefile, config, *ImplementationFlow._config_inputs(config)),
            outputs=(workdir / "results", workdir / "reports", workdir / "logs"),
            line_callback=on_line,
        )
        result = self.runner.run(request, on=on)
        top = ImplementationFlow._config_value(config, "DESIGN_NAME")
        platform = ImplementationFlow._config_value(config, "PLATFORM")
        artifacts = ImplementationFlow._final_artifacts(workdir, top, platform)
        returncode = result.returncode
        if returncode == 0 and len(artifacts) != len(_FINAL_ARTIFACTS):
            returncode = 1
        self._write_summary(
            workdir=workdir,
            top=top,
            platform=platform,
            returncode=returncode,
            tool_returncode=result.returncode,
            phases=tuple(seen),
            artifacts=artifacts,
            command=request.argv,
            log=log,
        )
        if returncode == 0:
            for kind, path in artifacts:
                Terminal.print_path_label("report", path, details={"kind": kind})
        return returncode

    def debug(
        self, *, output: str | None = None, as_json: bool = False,
    ) -> int:
        """Show implementation evidence plus existing runtime artifact paths."""

        return self.show(debug=True, output=output, as_json=as_json)

    def show(
        self, *, summary: bool = False, debug: bool = False,
        output: str | None = None, as_json: bool = False,
    ) -> int:
        """Render canonical implementation evidence without rediscovering ORFS outputs."""

        path = self.context.paths.impl / "summary.json"
        if not path.is_file():
            raise FileNotFoundError(f"implementation summary not found: {path}; run `fx pnr` first")
        relative = path.relative_to(self.context.paths.run).as_posix()
        document = ShowRenderer.load_file(self.context.paths.run, relative)
        if summary:
            data = dict(document.data)
            data["summary_only"] = True
            document = replace(document, data=data)

        capture = StringIO() if output else None
        console = Console(file=capture, force_terminal=False) if capture else Console()
        if as_json:
            print(json.dumps(document.data, indent=2, sort_keys=True), file=capture or None)
        else:
            ShowRenderer(console).render(document)
            if debug:
                self._show_debug(console, document.data)

        if output and capture is not None:
            destination = Path(output).expanduser()
            if not destination.is_absolute():
                destination = self.context.project_root / destination
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_text(capture.getvalue(), encoding="utf-8")
        return 0

    def collect(
        self, workdir: Path, *, top: str, platform: str | None = None
    ) -> dict[str, Path]:
        """Return canonical final ORFS artifacts by kind."""

        return dict(ImplementationFlow._final_artifacts(workdir.expanduser().resolve(), top, platform))

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

        from flexsoc.backend.core.runtime.execution import CommandRequest

        request = CommandRequest(
            ImplementationFlow.orfs_make_argv(
                makefile=makefile, config=config, workdir=workdir, targets=("gui_final",),
            ),
            workdir.resolve(),
            Toolchain.orfs_environment(),
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
                corner_liberties=ImplementationFlow._corner_liberties(values),
                hold_slack_margin=float(values.get("PNR_HOLD_SLACK_MARGIN", "0.05")),
                slew_margin=float(values.get("PNR_SLEW_MARGIN", "30")),
                cap_margin=float(values.get("PNR_CAP_MARGIN", "30")),
            )

        makefile, config = ImplementationFlow.orfs_paths(values, paths.impl)
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

    def _write_summary(
        self,
        *,
        workdir: Path,
        top: str,
        platform: str,
        returncode: int,
        tool_returncode: int,
        phases: tuple[str, ...],
        artifacts: tuple[tuple[str, Path], ...],
        command: tuple[str, ...],
        log: Path,
    ) -> Path:
        """Write one compact implementation summary from the completed ORFS run."""

        payload = {
            "schema": "flexsoc.implementation.v1",
            "top": top,
            "pdk": self.context.paths.pdk,
            "platform": platform,
            "status": "PASS" if returncode == 0 else "FAILED",
            "returncode": returncode,
            "tool_returncode": tool_returncode,
            "phases": list(phases),
            "artifacts": {
                kind: self._relative(path)
                for kind, path in artifacts
            },
            "command": list(command),
            "log": self._relative(log),
        }
        output = workdir / "summary.json"
        output.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return output

    def _show_debug(self, console: Console, data: object) -> None:
        """Render runtime paths already recorded in the implementation summary."""

        if not isinstance(data, dict):
            return
        console.print("[bold orange1]Diagnostics[/bold orange1]")
        command = data.get("command")
        if isinstance(command, list):
            console.print(f"[grey70]command[/grey70] {' '.join(str(item) for item in command)}")
        if data.get("log"):
            console.print(f"[grey70]log[/grey70] {data['log']}")
        artifacts = data.get("artifacts")
        if isinstance(artifacts, dict):
            for kind, path in artifacts.items():
                console.print(f"[grey70]{kind}[/grey70] {path}")

    def _relative(self, path: Path) -> str:
        """Return one run-relative artifact path when possible."""

        path = path.expanduser().resolve()
        try:
            return path.relative_to(self.context.paths.run.resolve()).as_posix()
        except ValueError:
            return str(path)

    @staticmethod
    def render_config(
        top: str,
        platform: str,
        netlist: Path,
        sdc_file: Path,
        corner_liberties: Mapping[str, Path] | None = None,
        hold_slack_margin: float = 0.05,
        slew_margin: float = 30.0,
        cap_margin: float = 30.0,
    ) -> str:
        """Render a physical-only ORFS config from FlexSoC synthesis artifacts."""

        if hold_slack_margin < 0:
            raise ValueError("PNR hold slack margin must be non-negative")
        if not 0 <= slew_margin < 100 or not 0 <= cap_margin < 100:
            raise ValueError("PNR slew/cap margins must be percentages in [0, 100)")
        corners = dict(corner_liberties or {})
        unknown = set(corners) - {"ss", "tt", "ff"}
        if unknown:
            raise ValueError(f"unsupported PNR corners: {', '.join(sorted(unknown))}")
        return templates.render(
            "impl/orfs/config.mk.j2",
            top=top,
            platform=platform,
            netlist=netlist,
            sdc_file=sdc_file,
            corners=tuple(
                (corner, corners[corner])
                for corner in ("ss", "tt", "ff")
                if corner in corners
            ),
            corner_names=" ".join(corner for corner in ("ss", "tt", "ff") if corner in corners),
            hold_slack_margin=f"{hold_slack_margin:g}",
            slew_margin=f"{slew_margin:g}",
            cap_margin=f"{cap_margin:g}",
        )

    @staticmethod
    def write_config(
        top: str,
        outdir: Path,
        platform: str,
        netlist: Path,
        sdc_file: Path,
        corner_liberties: Mapping[str, Path] | None = None,
        hold_slack_margin: float = 0.05,
        slew_margin: float = 30.0,
        cap_margin: float = 30.0,
    ) -> Path:
        """Write `config.mk` for one physical implementation run."""

        outdir = outdir.expanduser().resolve()
        netlist = netlist.expanduser().resolve()
        sdc_file = sdc_file.expanduser().resolve()
        corners = {
            name: path.expanduser().resolve()
            for name, path in (corner_liberties or {}).items()
        }
        if not netlist.is_file():
            raise ValueError(f"synthesized netlist not found: {netlist}")
        if not sdc_file.is_file():
            raise ValueError(f"SDC not found: {sdc_file}")
        for corner, liberty in corners.items():
            if not liberty.is_file():
                raise ValueError(f"{corner} Liberty not found: {liberty}")
        outdir.mkdir(parents=True, exist_ok=True)
        path = outdir / "config.mk"
        path.write_text(
            ImplementationFlow.render_config(
                top, platform, netlist, sdc_file, corners,
                hold_slack_margin, slew_margin, cap_margin,
            ), encoding="utf-8"
        )
        return path

    @staticmethod
    def checkpoint(line: str) -> str | None:
        """Return one stable macro-phase label for an ORFS transcript line."""

        plain = Terminal.strip_ansi(line)
        lower = plain.lower()
        if "extract_parasitics" in lower or "write_spef" in lower or "openrcx" in lower:
            return "extraction"
        match = _STAGE.search(plain)
        return _PHASE.get(match.group(1)) if match else None

    @staticmethod
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

    @staticmethod
    def resolve_orfs_artifact(
        workdir: Path, kind: str, top: str, filename: str, platform: str | None = None
    ) -> Path | None:
        """Resolve one final ORFS artifact from the canonical branch."""

        branch = ImplementationFlow.resolve_orfs_branch(workdir, kind, top, platform)
        path = branch / filename if branch else None
        return path.resolve() if path is not None and path.is_file() else None

    @staticmethod
    def _final_artifacts(
        workdir: Path, top: str, platform: str | None = None
    ) -> tuple[tuple[str, Path], ...]:
        """Return final artifacts only from the canonical ORFS result branch."""

        branch = ImplementationFlow.resolve_orfs_branch(workdir, "results", top, platform)
        if branch is None:
            return ()
        return tuple(
            (kind, path)
            for kind, name in _FINAL_ARTIFACTS
            if (path := branch / name).is_file()
        )

    @staticmethod
    def _corner_liberties(values: Mapping[str, str]) -> dict[str, Path]:
        """Return PDK-discovered sign-off views using ORFS corner names."""

        keys = {"ss": "LIB_SLOW", "tt": "LIB_TYP", "ff": "LIB_FAST"}
        return {corner: Path(values[key]) for corner, key in keys.items() if values.get(key)}

    @staticmethod
    def _config_value(config: Path, key: str) -> str:
        """Read one generated ORFS config value."""

        pattern = re.compile(rf"\s*export\s+{re.escape(key)}\s*:?=\s*(.+?)\s*$")
        for line in config.read_text(encoding="utf-8").splitlines():
            if match := pattern.match(line):
                return match.group(1)
        raise ValueError(f"{key} missing from OpenROAD config: {config}")

    @staticmethod
    def _config_inputs(config: Path) -> tuple[Path, ...]:
        """Return FlexSoC artifacts referenced by generated config.mk."""

        paths = [
            Path(ImplementationFlow._config_value(config, key)).expanduser().resolve()
            for key in ("SYNTH_NETLIST_FILES", "SDC_FILE")
        ]
        try:
            corners = ImplementationFlow._config_value(config, "CORNERS").split()
        except ValueError:
            corners = []
        paths.extend(
            Path(
                ImplementationFlow._config_value(config, f"{corner.upper()}_LIB_FILES")
            ).expanduser().resolve()
            for corner in corners
        )
        return tuple(paths)

    @staticmethod
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

    @staticmethod
    def orfs_paths(values, workdir: Path) -> tuple[Path, Path]:
        """Return the configured ORFS Makefile and generated design config."""

        raw = str(values.get("ORS", "")).strip()
        root = Path(raw).expanduser() if raw else Path.home() / "OpenROAD-flow-scripts" / "flow"
        return (root / "Makefile").resolve(), workdir.expanduser().resolve() / "config.mk"

    @staticmethod
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
            *ImplementationFlow._config_make_overrides(config),
            *targets,
        )
