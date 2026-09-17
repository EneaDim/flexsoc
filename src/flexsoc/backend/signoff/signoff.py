"""Reusable pre/post implementation sign-off package API."""

from __future__ import annotations

from dataclasses import dataclass, field
from enum import Enum
import json
from pathlib import Path
import re
import shlex
import sys
from typing import Mapping

from rich.console import Console
from rich.table import Table

from flexsoc.backend.core import BackendContext, PDKRunLayout
from flexsoc.backend.core.runtime.execution import CommandRequest, ToolRunner, Terminal
from flexsoc.backend.core.flow.target import Target
from flexsoc.backend.core.runtime.toolchain import Toolchain
from flexsoc.backend.impl import ImplementationFlow

from .fusion import FusionAnalysis
from .gls import GateLevelSimulation
from .power import ActivitySpec, PowerAnalysis
from .sdc import Sdc
from .sta import SignoffContext, StaAnalysis


class SignoffStage(str, Enum):
    """Select post-synthesis or post-implementation sign-off."""

    POST_SYN = "post_syn"
    POST_IMPL = "post_route"


_ANT = re.compile(r"Found\s+(\d+)\s+(net|pin) violations", re.IGNORECASE)
_BAD_LVS = re.compile(
    r"(?:\bno equivalence\b|\bnot equivalent\b|\bmismatch(?:es)?\b|"
    r"netlists do not match|\[ERROR|^ERROR:)",
    re.IGNORECASE | re.MULTILINE,
)
_BAD_IR = re.compile(r"(?:\[ERROR|^ERROR:|\bfailed\b)", re.IGNORECASE | re.MULTILINE)
_WORST_IR = re.compile(r"Worstcase IR drop:\s*([0-9.eE+-]+)\s*V", re.IGNORECASE)
_ANT_TOTAL = re.compile(r"FLEXSOC_ANTENNA_VIOLATIONS\s*=\s*(\d+)", re.IGNORECASE)


_DEBUG_BAD = re.compile(r"(?:\b(?:warning|error|fatal)\b|\(VIOLATED\)|unconstrained)", re.IGNORECASE)
_DEBUG_FLOAT = r"[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?"
_DEBUG_POWER = re.compile(
    r"^(?:analysis|workload|corner|activity_model|activity|duty|annotated_percent|"
    r"internal_power|switching_power|dynamic_power|leakage_power|total_power|wns|tns)=",
    re.IGNORECASE,
)


@dataclass(slots=True)
class SignoffFlow:
    """Compose independent sign-off engines for one lifecycle stage."""

    project_root: Path
    values: Mapping[str, str]
    stage: SignoffStage
    runner: object | None = None
    sta: StaAnalysis = field(init=False)
    gls: GateLevelSimulation = field(init=False)
    power: PowerAnalysis = field(init=False)
    fusion: FusionAnalysis = field(init=False)

    def __post_init__(self) -> None:
        self.values = {**self.values, "SIGNOFF_STAGE": self.stage.value}
        self.sta = StaAnalysis(self.project_root, self.values, self.runner)
        gls_stage = "post_impl" if self.stage is SignoffStage.POST_IMPL else "post_syn"
        self.gls = GateLevelSimulation(self.project_root, self.values, gls_stage, self.runner)
        self.power = PowerAnalysis(self.project_root, self.values, self.runner)
        self.fusion = FusionAnalysis(self.project_root, self.values, self.runner)

    def setup(self, target: Target, *, on: str = "local") -> object:
        """Materialize authored/generated collateral for one sign-off target."""

        del on
        if target.action == "sdc_setup":
            return self.setup_sdc()
        if target.action == "setup":
            return self.setup_sta(), self.setup_sdf(), self.setup_power(), self.setup_fusion()
        raise ValueError(f"setup is not supported for sign-off target {target.name!r}")

    def run(self, target: Target, *, on: str = "local") -> object:
        """Execute one registered sign-off target through this stage view."""

        action = target.action
        if action == "path_view":
            layout = PDKRunLayout.from_values(self.project_root, self.values)
            path = Path(self.values.get("PATH_VIEW_FILE", layout.path_view_dir / "paths.json")).expanduser().resolve()
            script = self.project_root / "src" / "util" / "plot_path.py"
            request = CommandRequest(
                (sys.executable, str(script), str(path)), self.project_root, {},
                layout.command_log_dir / "path_view.log", inputs=(path,),
            )
            return self.runner.run(request, on=on)
        if action == "sta":
            return self.run_sta(on=on)
        if action == "sdf":
            return self.run_sdf(on=on)
        if action == "power_estimate":
            return self.run_power_estimate(on=on)
        if action in {"power_activity", "power_activity_all"}:
            return self.run_power_activity(all_workloads=action.endswith("_all"), on=on)
        if action in {"fusion", "fusion_all"}:
            return self.run_fusion(all_workloads=action.endswith("_all"), on=on)

        test = self.values.get("TEST_NAME", "smoke")
        timing = self.values.get("TIMING_MODE", "zero")
        backend = self.values.get("GLS_BACKEND", "sv")
        if action == "gls_compile":
            return self.gls.compile(test=test, timing=timing, backend=backend, on=on)
        if action == "gls":
            return self.run_gls(test=test, timing=timing, backend=backend, on=on)
        if action == "gls_all":
            return self.gls.run_all(on=on)
        if action == "physical":
            layout = PDKRunLayout.from_values(self.project_root, self.values)
            makefile, config = ImplementationFlow.orfs_paths(self.values, layout.pnr_dir)
            return self.run_physical(
                makefile=makefile, config=config, workdir=layout.pnr_dir, top=layout.top,
                output=layout.signoff_stage_root("post_impl") / "physical" / "summary.json",
                log=layout.signoff_stage_log_root("post_impl") / "physical" / "physical_signoff.log",
                on=on,
            )
        raise ValueError(f"run is not supported for sign-off target {target.name!r}")

    def debug(self, target: Target, *, output: str | None = None) -> int:
        """Diagnose existing artifacts without rerunning the target."""

        if target.debug == "sta":
            return self.debug_sta(output=output)
        if target.debug == "power_estimate":
            return self.debug_power(activity=False, output=output)
        if target.debug == "power_activity":
            return self.debug_power(activity=True, output=output)
        if target.debug == "fusion":
            return self.debug_fusion(output=output)
        if target.debug == "gls":
            return self.debug_gls(output=output)
        raise ValueError(f"--debug is not supported for target {target.name!r}")

    def show(self, target: Target) -> tuple[Path, ...]:
        """Return canonical machine-readable evidence paths for one target."""

        layout = PDKRunLayout.from_values(self.project_root, self.values)
        root = layout.signoff_stage_root(self.stage.value)
        action = target.action
        if action == "sta":
            return (root / "sta" / "summary.json",)
        if action == "power_estimate":
            return (root / "power" / "estimate" / "summary.json",)
        if action in {"power_activity", "power_activity_all"}:
            return (root / "power" / "analysis" / "summary.json",)
        if action in {"fusion", "fusion_all"}:
            return (root / "fusion" / "summary.json",)
        if action == "physical":
            return (root / "physical" / "summary.json",)
        if action in {"gls", "gls_all"}:
            sim = layout.post_impl_sim_dir if self.stage is SignoffStage.POST_IMPL else layout.post_syn_sim_dir
            return (sim / "summary_sv.json",)
        return ()


    def setup_sdc(self) -> Path:
        """Initialize the single authored design SDC."""

        from flexsoc.backend.core import ClockConfig, FlowPaths

        workspace = Path(self.values.get("WORKSPACE", self.project_root / "workspace"))
        paths = FlowPaths.from_values(self.project_root, workspace, self.values)
        top = self.values.get("TOP", "test")
        return Sdc.init_sdc(
            paths.sdc,
            top=top,
            clocks=ClockConfig.from_values(self.values),
            top_file=paths.rtl / f"{top}.sv",
            io_delay_pct=float(self.values.get("SDC_IO_DELAY_PCT", "0.2")),
            force=str(self.values.get("FORCE", "0")).lower() in {"1", "true", "yes", "on"},
        )

    def setup_sta(self) -> Path:
        return self.sta.setup_sta()

    def setup_sdf(self) -> Path:
        return self.sta.setup_sdf()

    def setup_power(self) -> tuple[Path, Path]:
        return self.power.setup_estimate(), self.power.setup_activity()

    def setup_fusion(self) -> Path:
        return self.fusion.setup()

    def run_sta(self, *, on: str = "local") -> int:
        return self.sta.run_sta(on=on)

    def run_sdf(self, *, on: str = "local") -> int:
        return self.sta.write_sdf(on=on)

    def run_gls(self, *, test: str | None = None, timing: str = "zero", backend: str = "sv", on: str = "local") -> int:
        if test is None:
            return self.gls.run_all(on=on)
        return self.gls.run(test=test, timing=timing, backend=backend, on=on)

    def run_power_estimate(self, *, on: str = "local") -> int:
        return self.power.estimate(on=on)

    def run_power_activity(self, *, all_workloads: bool = False, on: str = "local") -> int:
        return self.power.activity(all_workloads=all_workloads, on=on)

    def run_fusion(self, *, all_workloads: bool = False, on: str = "local") -> int:
        return self.fusion.run(all_workloads=all_workloads, on=on)

    def debug_sta(self, *, output: str | None = None) -> int:
        layout = PDKRunLayout.from_values(self.project_root, self.values)
        root = layout.signoff_stage_root(self.stage.value)
        return SignoffFlow._debug_emit(self.project_root, "sta", SignoffFlow._debug_sta(root), output)

    def debug_power(self, *, activity: bool = False, output: str | None = None) -> int:
        layout = PDKRunLayout.from_values(self.project_root, self.values)
        root = layout.signoff_stage_root(self.stage.value) / "power"
        branch = root / ("analysis" if activity else "estimate")
        return SignoffFlow._debug_emit(self.project_root, "power", SignoffFlow._debug_reports(branch, "power"), output)

    def debug_fusion(self, *, output: str | None = None) -> int:
        layout = PDKRunLayout.from_values(self.project_root, self.values)
        root = layout.signoff_stage_root(self.stage.value) / "fusion"
        return SignoffFlow._debug_emit(self.project_root, "fusion", SignoffFlow._debug_reports(root, "fusion"), output)

    def debug_gls(self, *, output: str | None = None) -> int:
        layout = PDKRunLayout.from_values(self.project_root, self.values)
        return SignoffFlow._debug_emit(self.project_root, "gls", SignoffFlow._debug_gls(layout, self.stage.value), output)

    def _physical(
        self,
        *,
        makefile: Path,
        config: Path,
        workdir: Path,
        top: str,
        output: Path,
        log: Path,
        targets: tuple[str, ...],
        on: str,
    ) -> int:
        if self.stage is not SignoffStage.POST_IMPL:
            raise ValueError("physical sign-off is only valid post implementation")
        return SignoffFlow._run_physical(
            makefile=makefile,
            config=config,
            workdir=workdir,
            top=top,
            output=output,
            log=log,
            platform=self.values.get("ORS_TECH", self.values.get("PDK")),
            targets=targets,
            runner=self.runner,
            on=on,
        )

    def run_gds_drc(
        self, *, makefile: Path, config: Path, workdir: Path, top: str,
        output: Path, log: Path, on: str = "local",
    ) -> int:
        """Run only the final ORFS GDS DRC target."""

        return self._physical(
            makefile=makefile, config=config, workdir=workdir, top=top,
            output=output, log=log,
            targets=("drc",), on=on,
        )

    def run_lvs(
        self, *, makefile: Path, config: Path, workdir: Path, top: str,
        output: Path, log: Path, on: str = "local",
    ) -> int:
        """Run only the final ORFS LVS target."""

        return self._physical(
            makefile=makefile, config=config, workdir=workdir, top=top,
            output=output, log=log,
            targets=("lvs",), on=on,
        )

    def run_physical(
        self, *, makefile: Path, config: Path, workdir: Path, top: str,
        output: Path, log: Path, on: str = "local",
    ) -> int:
        """Run the canonical final DRC+LVS physical closure."""

        return self._physical(
            makefile=makefile, config=config, workdir=workdir, top=top,
            output=output, log=log,
            targets=("drc", "lvs"), on=on,
        )

    def collect_physical(self, *, workdir: Path, top: str) -> dict[str, object]:
        if self.stage is not SignoffStage.POST_IMPL:
            raise ValueError("physical sign-off is only valid post implementation")
        return SignoffFlow.collect(
            workdir=workdir, top=top,
            platform=self.values.get("ORS_TECH", self.values.get("PDK")),
        )

    @staticmethod
    def _branch(root: Path, kind: str, top: str, platform: str | None = None) -> Path | None:
        return ImplementationFlow.resolve_orfs_branch(root, kind, top, platform)

    @staticmethod
    def _route_drc(path: Path | None) -> dict[str, object]:
        if path is None or not path.is_file():
            return {"status": "missing", "entries": None, "report": None}
        text = path.read_text(encoding="utf-8", errors="replace")
        entries = sum(bool(line.strip()) for line in text.splitlines())
        return {"status": "pass" if entries == 0 else "fail", "entries": entries, "report": str(path)}

    @staticmethod
    def _antenna(path: Path | None) -> dict[str, object]:
        if path is None or not path.is_file():
            return {"status": "missing", "net_violations": None, "pin_violations": None, "report": None}
        text = path.read_text(encoding="utf-8", errors="replace")
        values = {kind.lower(): int(count) for count, kind in _ANT.findall(text)}
        if not values:
            total = _ANT_TOTAL.search(text)
            if total:
                violations = int(total.group(1))
                return {
                    "status": "pass" if violations == 0 else "fail",
                    "net_violations": violations,
                    "pin_violations": None,
                    "report": str(path),
                }
            return {"status": "review", "net_violations": None, "pin_violations": None, "report": str(path)}
        nets, pins = values.get("net", 0), values.get("pin", 0)
        return {
            "status": "pass" if nets == 0 and pins == 0 else "fail",
            "net_violations": nets,
            "pin_violations": pins,
            "report": str(path),
        }

    @staticmethod
    def _gds_drc(report_dir: Path | None) -> dict[str, object]:
        if report_dir is None:
            return {"status": "missing", "violations": None, "report": None}
        db = report_dir / "6_drc.lyrdb"
        count = report_dir / "6_drc_count.rpt"
        if db.is_file() and "DRC not supported" in db.read_text(encoding="utf-8", errors="replace"):
            return {"status": "unsupported", "violations": None, "report": str(db)}
        if not count.is_file():
            return {"status": "missing", "violations": None, "report": str(db) if db.is_file() else None}
        try:
            violations = int(count.read_text(encoding="utf-8").strip() or "0")
        except ValueError:
            return {"status": "unknown", "violations": None, "report": str(count)}
        return {"status": "pass" if violations == 0 else "fail", "violations": violations, "report": str(db)}

    @staticmethod
    def _lvs(results_dir: Path | None, logs_dir: Path | None) -> dict[str, object]:
        if results_dir is None:
            return {"status": "missing", "report": None, "log": None}
        db = results_dir / "6_lvs.lvsdb"
        log = logs_dir / "6_lvs.log" if logs_dir else None
        if db.is_file() and "LVS not supported" in db.read_text(encoding="utf-8", errors="replace"):
            return {"status": "unsupported", "report": str(db), "log": str(log) if log and log.is_file() else None}
        if not db.is_file():
            return {"status": "missing", "report": None, "log": str(log) if log and log.is_file() else None}
        text = log.read_text(encoding="utf-8", errors="replace") if log and log.is_file() else ""
        return {
            "status": "fail" if _BAD_LVS.search(text) else "pass",
            "report": str(db),
            "log": str(log) if log and log.is_file() else None,
        }

    @staticmethod
    def _ir_drop(report_dir: Path | None) -> dict[str, object]:
        if report_dir is None:
            return {"status": "missing", "reports": [], "worst_drop_v": {}}
        reports = [path for name in ("VDD.rpt", "VSS.rpt") if (path := report_dir / name).is_file()]
        if not reports:
            return {"status": "unsupported", "reports": [], "worst_drop_v": {}}
        worst: dict[str, float] = {}
        failed = False
        for path in reports:
            text = path.read_text(encoding="utf-8", errors="replace")
            failed |= bool(_BAD_IR.search(text))
            if match := _WORST_IR.search(text):
                worst[path.stem] = float(match.group(1))
        return {
            "status": "fail" if failed else "pass",
            "reports": [str(path) for path in reports],
            "worst_drop_v": worst,
        }

    @staticmethod
    def _overall(checks: dict[str, dict[str, object]]) -> str:
        statuses = [str(check.get("status", "missing")) for check in checks.values()]
        if "fail" in statuses:
            return "fail"
        if any(status in {"missing", "unknown", "unsupported", "review"} for status in statuses):
            return "review"
        return "pass"

    @staticmethod
    def collect(
        *, workdir: Path, top: str, platform: str | None = None, antenna_report: Path | None = None
    ) -> dict[str, object]:
        reports = SignoffFlow._branch(workdir, "reports", top, platform)
        results = SignoffFlow._branch(workdir, "results", top, platform)
        logs = SignoffFlow._branch(workdir, "logs", top, platform)
        antenna = antenna_report if antenna_report is not None else (reports / "antenna.log" if reports else None)
        checks = {
            "route_drc": SignoffFlow._route_drc(reports / "5_route_drc.rpt" if reports else None),
            "antenna": SignoffFlow._antenna(antenna),
            "gds_drc": SignoffFlow._gds_drc(reports),
            "lvs": SignoffFlow._lvs(results, logs),
            "ir_drop": SignoffFlow._ir_drop(reports),
        }
        return {"status": SignoffFlow._overall(checks), "checks": checks}

    @staticmethod
    def _run_antenna(
        *, workdir: Path, top: str, platform: str | None, output_dir: Path, runner, on: str
    ) -> Path | None:
        """Run a deterministic antenna check from the final ODB when ORFS has no report."""

        reports = SignoffFlow._branch(workdir, "reports", top, platform)
        native = reports / "antenna.log" if reports else None
        if native is not None and native.is_file():
            return native
        results = SignoffFlow._branch(workdir, "results", top, platform)
        odb = results / "6_final.odb" if results else None
        if odb is None or not odb.is_file():
            return None
        output_dir.mkdir(parents=True, exist_ok=True)
        script = output_dir / "antenna.tcl"
        log = output_dir / "antenna.log"
        script.write_text(
            f"read_db {{{odb}}}\n"
            "check_antennas -verbose\n"
            'puts "FLEXSOC_ANTENNA_VIOLATIONS=[ant::antenna_violation_count]"\n',
            encoding="utf-8",
        )
        env = Toolchain.orfs_environment()
        executable = env.get("OPENROAD_EXE", "openroad")
        request = CommandRequest(
            (executable, "-exit", "-no_init", str(script)),
            workdir, env, log, inputs=(odb, script), outputs=(log,),
        )
        result = runner.run(request, on=on)
        return log if result.returncode == 0 and log.is_file() else None

    @staticmethod
    def _run_physical(
        *, makefile: Path, config: Path, workdir: Path, top: str, output: Path, log: Path,
        platform: str | None = None, targets: tuple[str, ...] = ("drc", "lvs"), runner=None,
        on: str = "local",
    ) -> int:
        makefile = makefile.expanduser().resolve()
        config = config.expanduser().resolve()
        workdir = workdir.expanduser().resolve()
        output = output.expanduser().resolve()
        log = log.expanduser().resolve()
        for path, label in ((makefile, "OpenROAD-flow-scripts Makefile"), (config, "OpenROAD config.mk")):
            if not path.is_file():
                raise ValueError(f"{label} not found: {path}")
        output.parent.mkdir(parents=True, exist_ok=True)
        log.parent.mkdir(parents=True, exist_ok=True)
        Terminal.print_log(log)
        env = Toolchain.orfs_environment()
        try:
            current_klayout, required_klayout = Toolchain.validate_orfs_klayout(
                makefile, env, runner=runner, on=on
            )
        except ValueError as exc:
            log.write_text(f"ERROR: {exc}\n", encoding="utf-8")
            Terminal.print_label("post-signoff", f"klayout=fail · {exc}")
            raise
        if current_klayout and required_klayout:
            Terminal.print_label(
                "post-signoff",
                f"klayout={current_klayout} · required>={required_klayout}",
            )
        command = ImplementationFlow.orfs_make_argv(
            makefile=makefile, config=config, workdir=workdir, targets=targets,
        )
        runner = runner or ToolRunner()
        request = CommandRequest(
            command, workdir, env, log,
            inputs=(makefile, config), outputs=(workdir,),
        )
        returncode = runner.run(request, on=on).returncode
        antenna_report = SignoffFlow._run_antenna(
            workdir=workdir, top=top, platform=platform, output_dir=output.parent, runner=runner, on=on,
        )
        summary = SignoffFlow.collect(
            workdir=workdir, top=top, platform=platform, antenna_report=antenna_report
        )
        summary.update({"orfs_returncode": returncode, "log": str(log)})
        output.write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
        Terminal.print_path_label("report", output, details={"kind": "post-signoff-physical"})
        for name, values in summary["checks"].items():
            Terminal.print_label("post-signoff", f"{name}={values['status']}")
        return 2 if returncode != 0 or summary["status"] != "pass" else 0

    @staticmethod
    def _debug_path_rows(text: str, start: str, end: str, limit: int = 5) -> list[str]:
        """Return compact start/end/group/slack summaries from a timing-report section."""

        section = StaAnalysis._report_section(text, start, end)
        rows: list[str] = []
        for block in re.split(r"(?=^Startpoint:)", section, flags=re.MULTILINE):
            if not block.startswith("Startpoint:"):
                continue
            keep = [
                line.strip() for line in block.splitlines()
                if line.startswith(("Startpoint:", "Endpoint:", "Path Group:", "Path Type:"))
                or " slack (" in line
            ]
            if keep:
                rows.append(" · ".join(keep))
            if len(rows) >= limit:
                break
        return rows

    @staticmethod
    def _debug_focus(text: str, limit: int = 20) -> list[str]:
        """Keep only actionable warning/error/violation lines plus short context."""

        lines = text.splitlines()
        selected: list[str] = []
        for index, line in enumerate(lines):
            if not _DEBUG_BAD.search(line):
                continue
            selected.append(line.strip())
            if "unconstrained" in line.lower():
                selected.extend(item.strip() for item in lines[index + 1:index + 6] if item.strip())
            if len(selected) >= limit:
                break
        return list(dict.fromkeys(selected))[:limit]

    @staticmethod
    def _debug_field(item: str, name: str) -> str:
        match = re.search(rf"(?:^| · ){name}: (.*?)(?= · [A-Za-z ]+:| · [-+0-9.]|$)", item)
        return match.group(1) if match else "?"

    @staticmethod
    def _debug_number(value: str) -> str:
        if value == "—":
            return "[grey70]—[/grey70]"
        return f"[{'red' if value.startswith('-') else 'green'}]{value}[/]"

    @staticmethod
    def _debug_compact_path(item: str) -> str:
        """Render one path summary without report field labels."""

        slack = re.search(rf"({_DEBUG_FLOAT})\s+slack\s+\((?:MET|VIOLATED)\)", item, re.IGNORECASE)
        suffix = f" · slack={float(slack.group(1)):+.6f} ns" if slack else ""
        return (
            f"{SignoffFlow._debug_field(item, 'Startpoint')} → {SignoffFlow._debug_field(item, 'Endpoint')} · "
            f"group={SignoffFlow._debug_field(item, 'Path Group')} · type={SignoffFlow._debug_field(item, 'Path Type')}{suffix}"
        )

    @staticmethod
    def _debug_emit(
        project_root: Path, target: str, rows: list[tuple[str, str]], output: str | None
    ) -> int:
        """Render filtered diagnostics as compact Rich tables and optionally save plain text."""

        missing = len(rows) == 1
        if missing:
            rows.append(("error", f"{target}: no matching artifacts found"))

        console = Console()
        title = {"sta": "STA", "power": "Power", "fusion": "Timing / power fusion", "gls": "GLS"}.get(
            target, target
        )
        console.print(f"[bold orange1]{title} debug[/bold orange1]")
        for label, text in rows:
            if label == "debug":
                console.print(f"[grey70]{text}[/grey70]")

        qor = [text for label, text in rows if label == "qor"]
        if target == "sta" and len(qor) > 1:
            table = Table(box=None, pad_edge=False, header_style="bold grey70")
            for column in ("Corner", "Mode", "Status", "WNS (ns)", "TNS (ns)", "Viol", "Unconstr"):
                table.add_column(column, justify="right" if column in {"WNS (ns)", "TNS (ns)", "Viol", "Unconstr"} else "left")
            for line in qor[1:]:
                fields = line.split()
                if len(fields) != 7:
                    continue
                corner, mode, status, wns, tns, violations, unconstrained = fields
                style = "bold green" if status == "PASS" else "bold red" if status == "FAIL" else "bold orange1"
                table.add_row(
                    corner, mode, f"[{style}]{status}[/{style}]",
                    SignoffFlow._debug_number(wns), SignoffFlow._debug_number(tns),
                    f"[{'red' if int(violations) else 'green'}]{violations}[/]",
                    f"[{'red' if int(unconstrained) else 'green'}]{unconstrained}[/]",
                )
            console.print(table)

        detail_rows = [(label, text) for label, text in rows if label not in {"debug", "qor", "artifact"}]
        if detail_rows:
            table = Table(box=None, pad_edge=False, header_style="bold grey70")
            table.add_column("Kind", no_wrap=True)
            table.add_column("Scope", style="grey70", no_wrap=True)
            table.add_column("Detail", style="white")
            colors = {
                "error": "bold red", "timing": "red", "reset": "orange1", "electrical": "red",
                "constraint": "orange1", "near": "green", "case": "bright_cyan", "sdf": "orange1",
                "power": "bright_cyan", "fusion": "bright_cyan", "summary": "bright_cyan",
                "path": "white", "report": "#87d7ff", "wave": "#87d7ff", "view": "#87d7ff",
            }
            for label, text in detail_rows:
                scope, detail = "", text
                if " · " in text:
                    candidate, remainder = text.split(" · ", 1)
                    if "/" in candidate or candidate in {"ss", "tt", "ff"} or candidate.startswith("test="):
                        scope, detail = candidate, remainder
                style = colors.get(label, "white")
                table.add_row(f"[{style}]{label}[/{style}]", scope or "-", detail)
            console.print(table)

        artifacts = [text for label, text in rows if label == "artifact"]
        if artifacts:
            console.print("[bold bright_cyan]Artifacts[/bold bright_cyan]")
            for path in dict.fromkeys(artifacts):
                console.print(f"[#87d7ff]{path}[/#87d7ff]")

        if output:
            path = Path(output).expanduser()
            if not path.is_absolute():
                path = project_root / path
            if not path.suffix:
                path = path / f"{target}_debug.txt"
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text("\n".join(f"[{label}] {text}" for label, text in rows) + "\n", encoding="utf-8")
            Terminal.print_path_label("debug-report", path)
        return 2 if missing else 0

    @staticmethod
    def _debug_sta(root: Path) -> list[tuple[str, str]]:
        sta_root = root / "sta"
        rows: list[tuple[str, str]] = [("debug", f"STA artifacts={sta_root}")]
        summary = {}
        summary_path = sta_root / "summary.json"
        if summary_path.is_file():
            try:
                payload = json.loads(summary_path.read_text(encoding="utf-8"))
                summary = {
                    (item.get("corner"), item.get("mode")): item
                    for item in payload.get("scenarios", [])
                    if isinstance(item, dict)
                }
            except (OSError, json.JSONDecodeError):
                pass

        report_paths = sorted(
            sta_root.glob("*/*/timing.rpt"),
            key=lambda path: (
                {"ss": 0, "tt": 1, "ff": 2}.get(path.parent.parent.name, 99),
                {"setup": 0, "hold": 1}.get(path.parent.name, 99),
                str(path),
            ),
        )
        if not report_paths:
            return rows
        reports = []
        nearest: tuple[float, str] | None = None
        electrical: set[tuple[str, str]] = set()
        rows.append(("qor", "corner  mode   status      WNS(ns)      TNS(ns)    violations  unconstrained"))
        for report in report_paths:
            text = report.read_text(encoding="utf-8", errors="replace")
            rel = report.relative_to(sta_root)
            corner, mode = rel.parts[:2]
            timing = StaAnalysis._timing_values(text)
            violators = SignoffFlow._debug_path_rows(text, "=== Violating paths ===", "=== Near-critical paths ===", limit=100000)
            unconstrained = StaAnalysis._unconstrained_endpoint_count(text)
            scenario = summary.get((corner, mode), {})
            status = str(scenario.get("status") or ("fail" if violators or unconstrained else "pass")).upper()
            wns = scenario.get("wns", timing.get("wns"))
            tns = scenario.get("tns", timing.get("tns"))
            wns_text = "—" if wns is None else f"{float(wns):+.6f}"
            tns_text = "—" if tns is None else f"{float(tns):+.6f}"
            rows.append((
                "qor",
                f"{corner:<7} {mode:<6} {status:<8} {wns_text:>11} {tns_text:>12} "
                f"{len(violators):>13} {unconstrained:>14}",
            ))
            reports.append((corner, mode, report, text, violators, unconstrained))
            if not violators:
                for item in SignoffFlow._debug_path_rows(text, "=== Near-critical paths ===", "", limit=1):
                    match = re.search(rf"({_DEBUG_FLOAT})\s+slack\s+\(MET\)", item, re.IGNORECASE)
                    if match:
                        candidate = (float(match.group(1)), f"{corner}/{mode} · {SignoffFlow._debug_compact_path(item)}")
                        if nearest is None or candidate[0] < nearest[0]:
                            nearest = candidate
            constraint = StaAnalysis._report_section(text, "=== Constraint validation ===", "=== Violating paths ===")
            for line in constraint.splitlines():
                stripped = line.strip()
                if "(VIOLATED)" in stripped:
                    electrical.add((corner, stripped))

        for corner, mode, report, text, violators, unconstrained in reports:
            if unconstrained:
                rows.append(("constraint", f"{corner}/{mode} · unconstrained_endpoints={unconstrained}"))
            if violators:
                kinds: dict[str, list[str]] = {}
                for item in violators:
                    lowered = item.lower()
                    kind = "removal" if "removal check" in lowered else "recovery" if "recovery check" in lowered else "data"
                    kinds.setdefault(kind, []).append(item)
                for kind, items in kinds.items():
                    slacks = [
                        float(match.group(1))
                        for item in items
                        if (match := re.search(rf"({_DEBUG_FLOAT})\s+slack\s+\(VIOLATED\)", item, re.IGNORECASE))
                    ]
                    label = "reset" if kind in {"removal", "recovery"} else "timing"
                    worst = f"{min(slacks):+.6f} ns" if slacks else "n/a"
                    rows.append((label, f"{corner}/{mode} · {kind} checks={len(items)} · worst={worst}"))
                    rows.append(("path", f"{corner}/{mode} · {SignoffFlow._debug_compact_path(items[0])}"))
                rows.append(("report", f"{corner}/{mode} · {report}"))

        for corner, line in sorted(electrical):
            rows.append(("electrical", f"{corner} · {line}"))
        if nearest is not None:
            rows.append(("near", f"closest passing path · {nearest[1]}"))
        if summary_path.is_file():
            rows.append(("artifact", str(summary_path)))
        return rows

    @staticmethod
    def _debug_reports(branch: Path, kind: str) -> list[tuple[str, str]]:
        rows: list[tuple[str, str]] = [("debug", f"{kind} artifacts={branch}")]
        for summary in sorted(branch.rglob("summary.json")):
            try:
                data = json.loads(summary.read_text(encoding="utf-8"))
            except (OSError, json.JSONDecodeError):
                continue
            rows.append((
                "summary",
                f"{summary.parent.relative_to(branch)} · status={data.get('status')} "
                f"· pass={data.get('passed', 'n/a')} · fail={data.get('failed', 'n/a')} "
                f"· total={data.get('total', 'n/a')}",
            ))
            rows.append(("artifact", str(summary)))
        name = "power.rpt" if kind == "power" else "fusion.rpt"
        for report in sorted(branch.rglob(name)):
            text = report.read_text(encoding="utf-8", errors="replace")
            rel = report.relative_to(branch)
            focused = [line.strip() for line in text.splitlines() if _DEBUG_POWER.search(line.strip())]
            focused += SignoffFlow._debug_focus(text, 12)
            for line in list(dict.fromkeys(focused))[:20]:
                rows.append((kind, f"{rel.parent} · {line}"))
            if kind == "fusion":
                for item in SignoffFlow._debug_path_rows(text, "=== Worst timing paths (violated or met) ===", "", limit=5):
                    rows.append(("path", f"{rel.parent} · {item}"))
            rows.append(("artifact", str(report)))
        return rows

    @staticmethod
    def _debug_gls(layout, stage: str) -> list[tuple[str, str]]:
        root = layout.post_impl_sim_dir if stage == "post_route" else layout.post_syn_sim_dir
        rows: list[tuple[str, str]] = [("debug", f"GLS artifacts={root}")]
        reports = []
        for path in sorted(root.rglob("*.json")) if root.is_dir() else ():
            if path.name.startswith("summary_") or path.name == "manifest.json":
                continue
            try:
                data = json.loads(path.read_text(encoding="utf-8"))
            except (OSError, json.JSONDecodeError):
                continue
            if "test_name" in data and "timing_mode" in data:
                reports.append((path, data))
        reports.sort(key=lambda item: (item[1].get("status") == "pass", str(item[0])))
        for path, data in reports[:20]:
            rows.append((
                "case",
                f"test={data.get('test_name')} · backend={data.get('backend')} · timing={data.get('timing_mode')} "
                f"· status={data.get('status')} · model={data.get('timing_model')}",
            ))
            annotation = data.get("annotation") or {}
            for level in ("errors", "warnings", "markers"):
                for line in annotation.get(level, [])[:5] if isinstance(annotation, dict) else ():
                    rows.append(("sdf", f"{level[:-1]} · {line}"))
            wave = Path(str(data.get("wave", "")))
            if wave.is_file():
                rows.append(("wave", str(wave)))
                rows.append(("view", f"surfer {shlex.quote(str(wave))}"))
                rows.append(("view", f"gtkwave {shlex.quote(str(wave))}"))
            log = Path(str(data.get("log", "")))
            if data.get("status") != "pass" and log.is_file():
                for line in SignoffFlow._debug_focus(log.read_text(encoding="utf-8", errors="replace"), 12):
                    rows.append(("log", line))
            rows.append(("artifact", str(path)))
        return rows


@dataclass(slots=True)
class Signoff:
    """Expose reusable pre/post lifecycle views over one backend context."""

    context: BackendContext
    runner: object | None = None

    def _flow(self, stage: SignoffStage) -> SignoffFlow:
        values = {**self.context.values, "WORKSPACE": str(self.context.workspace)}
        return SignoffFlow(self.context.project_root, values, stage, self.runner)

    @property
    def post_syn(self) -> SignoffFlow:
        """Return post-synthesis sign-off."""

        return self._flow(SignoffStage.POST_SYN)

    @property
    def post_impl(self) -> SignoffFlow:
        """Return post-implementation sign-off."""

        return self._flow(SignoffStage.POST_IMPL)


__all__ = [
    "Signoff", "SignoffFlow", "SignoffStage", "SignoffContext",
    "StaAnalysis", "GateLevelSimulation", "ActivitySpec", "PowerAnalysis",
    "FusionAnalysis",
]
