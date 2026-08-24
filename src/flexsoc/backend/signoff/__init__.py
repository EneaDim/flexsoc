"""Reusable pre/post implementation sign-off package API."""

from __future__ import annotations

from dataclasses import dataclass, field
from enum import Enum
import json
from pathlib import Path
import re
from typing import Mapping

from flexsoc.backend.core.execution import CommandRequest, ToolRunner, print_label, print_log, print_path_label
from flexsoc.backend.core.toolchain import orfs_environment

from .fusion import FusionAnalysis
from .gls import GateLevelSimulation
from .power import ActivitySpec, PowerAnalysis
from .sta import SignoffContext, StaAnalysis


class SignoffStage(str, Enum):
    """Select the pre- or post-implementation timing model."""

    PRE_IMPL = "post_syn"
    POST_IMPL = "post_route"


_ANT = re.compile(r"Found\s+(\d+)\s+(net|pin) violations", re.IGNORECASE)
_BAD_LVS = re.compile(
    r"(?:\bno equivalence\b|\bnot equivalent\b|\bmismatch(?:es)?\b|"
    r"netlists do not match|\[ERROR|^ERROR:)",
    re.IGNORECASE | re.MULTILINE,
)
_BAD_IR = re.compile(r"(?:\[ERROR|^ERROR:|\bfailed\b)", re.IGNORECASE | re.MULTILINE)
_WORST_IR = re.compile(r"Worstcase IR drop:\s*([0-9.eE+-]+)\s*V", re.IGNORECASE)


def _branch(root: Path, kind: str, top: str) -> Path | None:
    base = root / kind
    matches = sorted(base.glob(f"*/{top}/base")) if base.is_dir() else []
    return matches[0] if matches else None


def _route_drc(path: Path | None) -> dict[str, object]:
    if path is None or not path.is_file():
        return {"status": "missing", "entries": None, "report": None}
    text = path.read_text(encoding="utf-8", errors="replace")
    entries = sum(bool(line.strip()) for line in text.splitlines())
    return {"status": "pass" if entries == 0 else "fail", "entries": entries, "report": str(path)}


def _antenna(path: Path | None) -> dict[str, object]:
    if path is None or not path.is_file():
        return {"status": "missing", "net_violations": None, "pin_violations": None, "report": None}
    text = path.read_text(encoding="utf-8", errors="replace")
    values = {kind.lower(): int(count) for count, kind in _ANT.findall(text)}
    if not values:
        return {"status": "unknown", "net_violations": None, "pin_violations": None, "report": str(path)}
    nets, pins = values.get("net", 0), values.get("pin", 0)
    return {
        "status": "pass" if nets == 0 and pins == 0 else "fail",
        "net_violations": nets,
        "pin_violations": pins,
        "report": str(path),
    }


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


def _overall(checks: dict[str, dict[str, object]]) -> str:
    statuses = [str(check.get("status", "missing")) for check in checks.values()]
    if "fail" in statuses:
        return "fail"
    if any(status in {"missing", "unknown", "unsupported"} for status in statuses):
        return "review"
    return "pass"


def collect(*, workdir: Path, top: str) -> dict[str, object]:
    reports = _branch(workdir, "reports", top)
    results = _branch(workdir, "results", top)
    logs = _branch(workdir, "logs", top)
    checks = {
        "route_drc": _route_drc(reports / "5_route_drc.rpt" if reports else None),
        "antenna": _antenna(reports / "antenna.log" if reports else None),
        "gds_drc": _gds_drc(reports),
        "lvs": _lvs(results, logs),
        "ir_drop": _ir_drop(reports),
    }
    return {"status": _overall(checks), "checks": checks}


def _run_physical(*, makefile: Path, config: Path, workdir: Path, top: str, output: Path, log: Path, targets: tuple[str, ...] = ("drc", "lvs"), runner=None, on: str = "local") -> int:
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
    print_log(log)
    command = ("make", f"--file={makefile}", "--no-print-dir", f"DESIGN_CONFIG={config}", *targets)
    runner = runner or ToolRunner()
    request = CommandRequest(
        command, workdir, orfs_environment(), log,
        inputs=(makefile, config), outputs=(workdir,),
    )
    returncode = runner.run(request, on=on).returncode
    summary = collect(workdir=workdir, top=top)
    summary.update({"orfs_returncode": returncode, "log": str(log)})
    output.write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
    print_path_label("report", output, details={"kind": "physical-signoff"})
    for name, values in summary["checks"].items():
        print_label("physical", f"{name}={values['status']}")
    return 2 if returncode != 0 or summary["status"] == "fail" else 0





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
        self.gls = GateLevelSimulation(self.project_root, self.values, self.stage.value, self.runner)
        self.power = PowerAnalysis(self.project_root, self.values, self.runner)
        self.fusion = FusionAnalysis(self.project_root, self.values, self.runner)

    def setup_sdc(self) -> Path:
        return self.sta.setup_sdc()

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

    def write_sdf(self, *, on: str = "local") -> int:
        return self.sta.write_sdf(on=on)

    def run_gls(self, *, test: str | None = None, timing: str = "zero", backend: str = "sv", on: str = "local") -> int:
        if test is None:
            return self.gls.flow(on=on)
        return self.gls.run(test=test, timing=timing, backend=backend, on=on)

    def run_power_estimate(self, *, on: str = "local") -> int:
        return self.power.estimate(on=on)

    def run_power_activity(self, *, all_workloads: bool = False, on: str = "local") -> int:
        return self.power.activity(all_workloads=all_workloads, on=on)

    def run_fusion(self, *, all_workloads: bool = False, on: str = "local") -> int:
        return self.fusion.run(all_workloads=all_workloads, on=on)

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
        return _run_physical(
            makefile=makefile,
            config=config,
            workdir=workdir,
            top=top,
            output=output,
            log=log,
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
            output=output, log=log, targets=("drc",), on=on,
        )

    def run_lvs(
        self, *, makefile: Path, config: Path, workdir: Path, top: str,
        output: Path, log: Path, on: str = "local",
    ) -> int:
        """Run only the final ORFS LVS target."""

        return self._physical(
            makefile=makefile, config=config, workdir=workdir, top=top,
            output=output, log=log, targets=("lvs",), on=on,
        )

    def run_physical(
        self, *, makefile: Path, config: Path, workdir: Path, top: str,
        output: Path, log: Path, on: str = "local",
    ) -> int:
        """Run the canonical final DRC+LVS physical closure."""

        return self._physical(
            makefile=makefile, config=config, workdir=workdir, top=top,
            output=output, log=log, targets=("drc", "lvs"), on=on,
        )

    def collect_physical(self, *, workdir: Path, top: str) -> dict[str, object]:
        if self.stage is not SignoffStage.POST_IMPL:
            raise ValueError("physical sign-off is only valid post implementation")
        return collect(workdir=workdir, top=top)

    def flow(self, *, physical: dict | None = None, on: str = "local") -> int:
        """Run the canonical pre/post sign-off sequence."""

        if self.stage is SignoffStage.PRE_IMPL:
            self.setup_sdc()
        self.setup_sta()
        self.setup_sdf()
        self.setup_power()
        self.setup_fusion()
        for action in (
            lambda: self.run_sta(on=on),
            lambda: self.write_sdf(on=on),
            lambda: self.gls.flow(on=on),
            lambda: self.run_power_estimate(on=on),
            lambda: self.run_power_activity(all_workloads=True, on=on),
            lambda: self.run_fusion(all_workloads=True, on=on),
        ):
            rc = action()
            if rc:
                return rc
        if self.stage is SignoffStage.POST_IMPL and physical:
            return self.run_physical(**physical, on=on)
        return 0


@dataclass(slots=True)
class Signoff:
    """Expose reusable pre/post lifecycle views over the same engines."""

    project_root: Path
    values: Mapping[str, str]
    runner: object | None = None

    @property
    def pre(self) -> SignoffFlow:
        return SignoffFlow(self.project_root, self.values, SignoffStage.PRE_IMPL, self.runner)

    @property
    def post(self) -> SignoffFlow:
        return SignoffFlow(self.project_root, self.values, SignoffStage.POST_IMPL, self.runner)


__all__ = [
    "Signoff", "SignoffFlow", "SignoffStage", "SignoffContext",
    "StaAnalysis", "GateLevelSimulation", "ActivitySpec", "PowerAnalysis",
    "FusionAnalysis",
]
