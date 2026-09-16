"""Read-only access to canonical machine-readable FlexSoC flow reports."""

from __future__ import annotations

from dataclasses import dataclass
import json
from pathlib import Path
from typing import Any, Mapping

import yaml
from rich.console import Console
from rich.json import JSON
from rich.panel import Panel
from rich.table import Table

from .target import BACKEND_TARGETS


@dataclass(frozen=True)
class ShowSpec:
    """Stable user-facing key for one canonical JSON report or JSON section."""

    key: str
    title: str
    path: Path
    selector: tuple[str, ...] = ()


@dataclass(frozen=True)
class ShowDocument:
    """Loaded JSON plus the canonical source that produced it."""

    key: str
    title: str
    path: Path
    data: Any
    root: Any
    kind: str = "generic"


def spec_root(run: Path) -> Path:
    """Return the live specification root or the frozen loaded-package contract."""

    run = Path(run)
    live = run / "spec"
    if live.is_dir():
        return live
    frozen = run / "contract"
    return frozen if frozen.is_dir() else live


def load_spec(run: Path, key: str) -> ShowDocument:
    """Load requirements.yaml or testplan.yaml from the canonical spec root."""

    normalized = str(key).strip().lower().replace("-", "_")
    names = {
        "requirements": ("Requirements", "requirements.yaml"),
        "testplan": ("Test plan", "testplan.yaml"),
    }
    if normalized not in names:
        raise KeyError(f"unknown spec document {key!r}")
    title, filename = names[normalized]
    path = spec_root(run) / filename
    if not path.is_file():
        raise FileNotFoundError(f"{title} not found: {path}")
    try:
        data = yaml.safe_load(path.read_text(encoding="utf-8"))
    except (OSError, yaml.YAMLError) as exc:
        raise ValueError(f"invalid YAML in {path}: {exc}") from exc
    if not isinstance(data, Mapping):
        raise ValueError(f"{path} must contain a mapping")
    return ShowDocument(normalized, title, path, data, data)


def meta_entries(run: Path) -> tuple[dict[str, object], ...]:
    """Return a deterministic inventory of files below one run's meta directory."""

    root = Path(run) / "meta"
    if not root.is_dir():
        return ()
    rows: list[dict[str, object]] = []
    for path in sorted(item for item in root.rglob("*") if item.is_file()):
        relative = path.relative_to(root).as_posix()
        summary = ""
        if path.suffix.lower() == ".json":
            try:
                data = json.loads(path.read_text(encoding="utf-8"))
            except (OSError, json.JSONDecodeError):
                data = None
            if isinstance(data, Mapping):
                parts: list[str] = []
                for key in ("status", "level_name", "qualification_level", "pdk", "top", "ip", "version"):
                    value = data.get(key)
                    if value not in (None, "", [], {}):
                        parts.append(f"{key}={value}")
                summary = " · ".join(parts[:4])
        rows.append({
            "path": relative,
            "size": path.stat().st_size,
            "summary": summary,
            "source": str(path),
        })
    return tuple(rows)


def meta_documents(run: Path) -> tuple[dict[str, object], ...]:
    """Load canonical design-intent, qualification, and provenance JSON documents."""

    root = Path(run) / "meta"
    if not root.is_dir():
        return ()
    candidates: list[tuple[str, str | None, Path]] = [
        ("design_intent", None, root / "design_intent.json"),
    ]
    for branch in sorted(path for path in root.iterdir() if path.is_dir()):
        candidates.extend((
            ("qualification", branch.name, branch / "qualification.json"),
            ("provenance", branch.name, branch / "provenance.json"),
        ))

    documents: list[dict[str, object]] = []
    for kind, pdk, path in candidates:
        if not path.is_file():
            continue
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError) as exc:
            documents.append({
                "kind": kind, "pdk": pdk, "path": path.relative_to(root).as_posix(),
                "source": str(path), "error": str(exc), "data": None,
            })
            continue
        documents.append({
            "kind": kind, "pdk": pdk, "path": path.relative_to(root).as_posix(),
            "source": str(path), "error": None, "data": data,
        })
    return tuple(documents)



_IMPORTANT_META_NAMES = {
    "contract.json",
    "design_intent.json",
    "interface_migration.json",
    "manifest.json",
    "metrics.json",
    "provenance.json",
    "qualification.json",
    "settings.json",
}


def classify(path: Path, data: Any) -> str:
    """Classify one canonical JSON document by schema/content, not by design name."""

    if not isinstance(data, Mapping):
        return "generic"
    name = path.name.lower()
    keys = set(data)
    if name == "qualification.json" or {"evidence", "freshness", "levels"} <= keys:
        return "qualification"
    if name == "provenance.json" and isinstance(data.get("stages"), Mapping):
        return "provenance"
    if name == "summary.json" and {"qor", "scenarios"} <= keys:
        return "sta"
    if name.startswith("summary") and {"tests", "reports"} <= keys:
        return "matrix"
    if name == "summary.json" and {"order", "tools"} <= keys:
        return "lint"
    if name == "summary.json" and "clock_domains" in data and ("cdc" in data or "rdc" in data):
        return "cdc_rdc"
    if name == "summary.json" and {"scopes", "types"} <= keys:
        return "coverage"
    if data.get("analysis") == "power_estimate" and isinstance(data.get("corners"), Mapping):
        return "power_estimate"
    if isinstance(data.get("reports"), list) and any(key in data for key in ("passed", "failed", "total")):
        return "reports"
    if name == "metrics.json":
        return "metrics"
    if name == "settings.json":
        return "settings"
    if name == "contract.json":
        return "contract"
    if name == "ip.json":
        return "ip"
    if name == "design_intent.json":
        return "design_intent"
    if name == "manifest.json":
        return "manifest"
    if name == "interface_migration.json":
        return "migration"
    if name == "report.json" and "coverage" in data and "action" in data:
        return "formal_report"
    if name.endswith("_synth.json") and "modules" in data:
        return "yosys_netlist"
    return "generic"


def _important_json(run: Path, path: Path, *, top: str) -> bool:
    """Return whether a JSON file is canonical enough to belong to `fx show all`."""

    try:
        relative = path.relative_to(run)
    except ValueError:
        return False
    parts = relative.parts
    name = path.name
    if name.startswith("summary") and name.endswith(".json"):
        return True
    if name == "provenance.json":
        return True
    if relative.as_posix() in {"ip.json", "manifest.json", "report.json"}:
        return True
    if len(parts) >= 2 and parts[0] == "meta" and name in _IMPORTANT_META_NAMES:
        return True
    if len(parts) >= 2 and parts[0] == "dv" and parts[1] == "formal" and name == "report.json":
        return True
    if len(parts) >= 3 and parts[0] == "syn" and name == f"{top}_synth.json":
        return True
    if parts and parts[0] == "signoff" and name == "summary.json":
        return True
    return False


def files(run: Path, *, top: str, pdk: str) -> tuple[dict[str, object], ...]:
    """Inventory every important machine-readable JSON under one run."""

    del pdk  # Discovery intentionally spans every PDK present in the run.
    run = Path(run)
    rows: list[dict[str, object]] = []
    if not run.is_dir():
        return ()
    for path in sorted(item for item in run.rglob("*.json") if item.is_file()):
        if not _important_json(run, path, top=top):
            continue
        relative = path.relative_to(run).as_posix()
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
            kind = classify(path, data)
            error = None
        except (OSError, json.JSONDecodeError) as exc:
            kind = "invalid"
            error = str(exc)
        rows.append({
            "key": relative,
            "path": str(path),
            "kind": kind,
            "size": path.stat().st_size,
            "error": error,
        })
    return tuple(rows)


def load_file(run: Path, key: str) -> ShowDocument:
    """Load one important JSON by run-relative path, rejecting path traversal."""

    run = Path(run).resolve()
    requested = Path(str(key).strip())
    if requested.is_absolute():
        path = requested.resolve()
    else:
        path = (run / requested).resolve()
    if path != run and run not in path.parents:
        raise ValueError(f"show path escapes run root: {key}")
    if not path.is_file():
        raise FileNotFoundError(f"show JSON not found: {path}")
    if path.suffix.lower() != ".json":
        raise ValueError(f"show file must be JSON: {path}")
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except json.JSONDecodeError as exc:
        raise ValueError(f"invalid JSON in {path}: {exc}") from exc
    relative = path.relative_to(run).as_posix()
    return ShowDocument(relative, relative, path, data, data, classify(path, data))


def _select(data: Any, selector: tuple[str, ...]) -> Any:
    current = data
    for token in selector:
        if not isinstance(current, Mapping) or token not in current:
            raise KeyError(".".join(selector))
        current = current[token]
    return current


def catalog(run: Path, *, top: str, pdk: str) -> dict[str, ShowSpec]:
    """Return the stable report-key catalogue for one configured run/PDK."""

    run = Path(run)
    meta = run / "meta" / pdk
    metrics = meta / "metrics.json"
    signoff = run / "signoff" / pdk
    sim = run / "dv" / "functional" / "sim"
    contract = run / "meta" / "contract.json"
    if not contract.is_file():
        contract = run / "contract" / "contract.json"
    specs = (
        ShowSpec("qualification", "Qualification", meta / "qualification.json"),
        ShowSpec("evidence", "Qualification evidence", meta / "qualification.json", ("evidence",)),
        ShowSpec("levels", "Qualification levels", meta / "qualification.json", ("levels",)),
        ShowSpec("metrics", "Collected flow metrics", metrics),
        ShowSpec("manifest", "Run manifest", meta / "manifest.json"),
        ShowSpec("provenance", "Stage provenance", meta / "provenance.json"),
        ShowSpec("settings", "Effective PDK settings", meta / "settings.json"),
        ShowSpec("design_intent", "Common design intent", run / "meta" / "design_intent.json"),
        ShowSpec("contract", "Frozen contract", contract),
        ShowSpec("regression", "RTL regression metrics", metrics, ("regression",)),
        ShowSpec("formal", "Formal metrics", metrics, ("formal",)),
        ShowSpec("eqy", "Equivalence metrics", metrics, ("equivalence",)),
        ShowSpec("synthesis", "Synthesis metrics", metrics, ("synthesis",)),
        ShowSpec("implementation", "Implementation metrics", metrics, ("implementation",)),
        ShowSpec("closure", "Technical closure", metrics, ("closure",)),
        ShowSpec("lint", "Lint summary", run / "dv" / "lint" / "summary.json"),
        ShowSpec("cdc_rdc", "CDC/RDC summary", run / "dv" / "cdc_rdc" / "summary.json"),
        ShowSpec("coverage", "Coverage matrix", run / "dv" / "functional" / "coverage" / "summary.json"),
        ShowSpec("syn", "Synthesis report", run / "syn" / pdk / f"{top}_synth.json"),
        ShowSpec("gls_post_syn", "Post-synthesis GLS matrix", sim / "post_syn" / pdk / "summary_sv.json"),
        ShowSpec("sta", "Post-synthesis STA", signoff / "sta" / "summary.json"),
        ShowSpec("power_estimate", "Post-synthesis vectorless power", signoff / "power" / "estimate" / "summary.json"),
        ShowSpec("power", "Post-synthesis activity power", signoff / "power" / "analysis" / "summary.json"),
        ShowSpec("fusion", "Post-synthesis timing/power fusion", signoff / "fusion" / "summary.json"),
        ShowSpec("physical_signoff", "Physical signoff", signoff / "post_pnr" / "physical" / "summary.json"),
        ShowSpec("gls_post_pnr", "Post-PnR GLS matrix", sim / "post_pnr" / pdk / "summary_sv.json"),
        ShowSpec("sta_post_pnr", "Post-PnR STA", signoff / "post_pnr" / "sta" / "summary.json"),
        ShowSpec("power_estimate_post_pnr", "Post-PnR vectorless power", signoff / "post_pnr" / "power" / "estimate" / "summary.json"),
        ShowSpec("power_post_pnr", "Post-PnR activity power", signoff / "post_pnr" / "power" / "analysis" / "summary.json"),
        ShowSpec("fusion_post_pnr", "Post-PnR timing/power fusion", signoff / "post_pnr" / "fusion" / "summary.json"),
    )
    return {item.key: item for item in specs}


def _available(spec: ShowSpec) -> bool:
    """Return whether both the JSON file and selected section are readable."""

    if not spec.path.is_file():
        return False
    if not spec.selector:
        return True
    try:
        data = json.loads(spec.path.read_text(encoding="utf-8"))
        _select(data, spec.selector)
    except (OSError, json.JSONDecodeError, KeyError):
        return False
    return True


def keys(run: Path, *, top: str, pdk: str) -> tuple[dict[str, object], ...]:
    """Describe report keys and whether their canonical JSON source/section exists."""

    return tuple(
        {
            "key": spec.key,
            "title": spec.title,
            "path": str(spec.path),
            "selector": ".".join(spec.selector) or None,
            "available": _available(spec),
        }
        for spec in catalog(run, top=top, pdk=pdk).values()
    )


def load(run: Path, *, top: str, pdk: str, key: str) -> ShowDocument:
    """Load one canonical report by stable key without modifying the run."""

    normalized = str(key).strip().lower().replace("-", "_")
    registered = BACKEND_TARGETS.get(normalized)
    if registered is not None and registered.show:
        normalized = registered.show
    specs = catalog(run, top=top, pdk=pdk)
    if normalized not in specs:
        choices = ", ".join(specs)
        raise KeyError(f"unknown show key {key!r}; choose one of: {choices}")
    spec = specs[normalized]
    if not spec.path.is_file():
        raise FileNotFoundError(f"{spec.title} JSON not found: {spec.path}")
    try:
        root = json.loads(spec.path.read_text(encoding="utf-8"))
    except json.JSONDecodeError as exc:
        raise ValueError(f"invalid JSON in {spec.path}: {exc}") from exc
    try:
        data = _select(root, spec.selector)
    except KeyError as exc:
        selector = ".".join(spec.selector)
        raise KeyError(f"{spec.path} has no JSON section {selector!r}") from exc
    return ShowDocument(spec.key, spec.title, spec.path, data, root, classify(spec.path, root))


def _status(value: object) -> str | None:
    token = str(value).strip().upper()
    if token in {"PASS", "PASSED", "OK", "SUCCESS"}:
        return "PASS"
    if token in {"FAIL", "FAILED", "ERROR", "FATAL"}:
        return "FAILED"
    if token in {"REVIEW", "PARTIAL", "INCOMPLETE", "UNKNOWN", "UNSUPPORTED", "WARN", "WARNING"}:
        return "REVIEW"
    if token in {"MISSING", "STALE", "INVALID", "MODIFIED", "WAIVED"}:
        return token
    return None


_DIRECT_STAGE_KEYS = {
    "cdc_rdc": "cdc_rdc",
    "syn": "syn",
    "gls_post_syn": "sim_post_syn_all",
    "sta": "sta",
    "power": "power_analysis_all",
    "fusion": "fusion_analysis_all",
    "physical_signoff": "physical_signoff",
    "gls_post_pnr": "sim_post_pnr_all",
    "sta_post_pnr": "sta_post_pnr",
    "power_post_pnr": "power_analysis_post_pnr_all",
    "fusion_post_pnr": "fusion_analysis_post_pnr_all",
}


def issues(run: Path, *, top: str, pdk: str) -> tuple[dict[str, object], ...]:
    """Summarize non-PASS canonical evidence/reports for quick failure diagnosis."""

    run = Path(run)
    rows: list[dict[str, object]] = []
    qualification_path = run / "meta" / pdk / "qualification.json"
    qualified_stages: set[str] = set()
    if qualification_path.is_file():
        try:
            qualification = json.loads(qualification_path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            qualification = {}
        evidence = qualification.get("evidence", {}) if isinstance(qualification, Mapping) else {}
        if isinstance(evidence, Mapping):
            for stage, raw in evidence.items():
                status = _status(raw)
                qualified_stages.add(str(stage))
                if status not in {None, "PASS", "WAIVED"}:
                    rows.append({
                        "key": str(stage),
                        "status": status,
                        "source": str(qualification_path),
                        "detail": "qualification evidence",
                    })

    for key, stage in _DIRECT_STAGE_KEYS.items():
        if stage in qualified_stages:
            continue
        try:
            document = load(run, top=top, pdk=pdk, key=key)
        except (FileNotFoundError, KeyError, ValueError):
            continue
        data = document.data
        status = _status(data.get("status")) if isinstance(data, Mapping) else None
        if status not in {None, "PASS", "WAIVED"}:
            detail = "canonical report"
            if isinstance(data, Mapping):
                passed = data.get("passed")
                failed = data.get("failed")
                total = data.get("total")
                if total is not None:
                    detail = f"pass={passed} fail={failed} total={total}"
            rows.append({
                "key": stage,
                "status": status,
                "source": str(document.path),
                "detail": detail,
            })
    return tuple(rows)


class ShowRenderer:
    """Render one already-loaded show document without reading or changing a run."""

    def __init__(self, console: Console):
        self.console = console

    def status(self, value: object) -> str:
        """Render one report/evidence state with consistent CLI colors."""

        token = str(value).strip().upper()
        color = {
            "PASS": "green",
            "WAIVED": "yellow",
            "REVIEW": "orange1",
            "MISSING": "grey70",
            "FAILED": "red",
            "FAIL": "red",
            "STALE": "red",
            "INVALID": "red",
            "MODIFIED": "red",
        }.get(token, "white")
        return f"[{color}]{token}[/{color}]"

    def _show_evidence_table(self, data: Mapping[str, Any]) -> None:
        """Render qualification evidence including intentionally missing stages."""

        evidence = data.get("evidence", {}) if isinstance(data, Mapping) else {}
        freshness = data.get("freshness", {}) if isinstance(data, Mapping) else {}
        outcomes = data.get("outcomes", {}) if isinstance(data, Mapping) else {}
        levels = data.get("levels", {}) if isinstance(data, Mapping) else {}
        order: list[str] = []
        if isinstance(levels, Mapping):
            for item in levels.values():
                if not isinstance(item, Mapping):
                    continue
                for stage in item.get("required_evidence", ()):
                    name = str(stage)
                    if name not in order:
                        order.append(name)
        if isinstance(evidence, Mapping):
            for stage in evidence:
                name = str(stage)
                if name not in order:
                    order.append(name)
        table = Table(title="Evidence", header_style="bold white", expand=True)
        table.add_column("Stage", style="bright_cyan", no_wrap=True)
        table.add_column("State", no_wrap=True)
        table.add_column("Freshness", no_wrap=True)
        table.add_column("Outcome", no_wrap=True)
        for stage in order:
            state = evidence.get(stage, "MISSING") if isinstance(evidence, Mapping) else "MISSING"
            fresh = freshness.get(stage, "-") if isinstance(freshness, Mapping) else "-"
            outcome = outcomes.get(stage) if isinstance(outcomes, Mapping) else None
            table.add_row(stage, self.status(state), str(fresh), str(outcome or "-"))
        self.console.print(table)

    def _show_qualification(self, document: Any) -> None:
        """Render the compact human view of qualification.json."""

        data = document.root
        req = data.get("requirements", {}) if isinstance(data, Mapping) else {}
        self.console.print(Panel.fit(
            f"IP: [white]{data.get('ip', '-')}[/white]\n"
            f"Interface: [white]{data.get('reg_interface', '-')}[/white]\n"
            f"PDK: [white]{data.get('pdk', '-')}[/white]\n"
            f"Contract: [white]{data.get('contract', 'VALID' if data.get('contract_fingerprint') else '-')}[/white]\n"
            f"Requirements: [white]{req.get('covered', 0)}/{req.get('total', 0)}[/white]\n"
            f"Maximum: [white]L{data.get('maximum_level', 0)} {data.get('maximum_qualification', '-')}[/white] · "
            f"{self.status(data.get('qualification_status', 'MISSING'))}",
            title="Qualification",
            border_style="orange1",
        ))
        self._show_levels(data)
        self._show_evidence_table(data)

    def _show_levels(self, data: Mapping[str, Any]) -> None:
        """Render qualification levels without duplicating the full qualification view."""

        levels = data.get("levels", {}) if isinstance(data, Mapping) else {}
        if not isinstance(levels, Mapping):
            return
        table = Table(title="Levels", header_style="bold white", expand=True)
        table.add_column("Level", style="bright_cyan", no_wrap=True)
        table.add_column("Name")
        table.add_column("Status", no_wrap=True)
        table.add_column("Blocking")
        for level, item in levels.items():
            if not isinstance(item, Mapping):
                continue
            blocking = ", ".join(str(x) for x in item.get("blocking_evidence", ())) or "-"
            table.add_row(
                f"L{level}", str(item.get("name", "-")),
                self.status(item.get("status", "MISSING")), blocking,
            )
        self.console.print(table)

    def _show_gls(self, document: Any) -> None:
        """Render a GLS summary JSON as the test-by-scenario matrix it represents."""

        data = document.data
        tests = [str(item) for item in data.get("tests", ())]
        reports = data.get("reports", ())
        scenarios = [str(item) for item in data.get("scenarios", ())]
        if not scenarios and isinstance(reports, list):
            scenarios = list(dict.fromkeys(str(item.get("scenario", "-")) for item in reports if isinstance(item, Mapping)))
        matrix: dict[tuple[str, str], str] = {}
        if isinstance(reports, list):
            for item in reports:
                if not isinstance(item, Mapping):
                    continue
                test = str(item.get("test_name", item.get("test", "-")))
                scenario = str(item.get("scenario", item.get("timing_mode", "-")))
                matrix[(test, scenario)] = str(item.get("status", "missing")).upper()
        table = Table(title=document.title, header_style="bold white")
        table.add_column("Test", style="bright_cyan")
        for scenario in scenarios:
            table.add_column(scenario, justify="center")
        for test in tests:
            table.add_row(test, *(self.status(matrix.get((test, scenario), "MISSING")) for scenario in scenarios))
        self.console.print(table)
        self.console.print(
            f"[grey70]total[/grey70]=[white]{data.get('total', 0)}[/white] · "
            f"[grey70]pass[/grey70]=[green]{data.get('passed', 0)}[/green] · "
            f"[grey70]fail[/grey70]=[red]{data.get('failed', 0)}[/red]"
        )


    def _show_value(self, value: object) -> str:
        """Compact nested JSON values for human tables without hiding raw --json data."""

        if value is None:
            return "-"
        if isinstance(value, bool):
            return "yes" if value else "no"
        if isinstance(value, float):
            return f"{value:.6g}"
        if isinstance(value, Mapping):
            return f"{{{len(value)} keys}}"
        if isinstance(value, (list, tuple)):
            return f"[{len(value)} items]"
        text = str(value)
        return text if len(text) <= 100 else text[:97] + "..."

    def _show_mapping(self, document: Any) -> None:
        """Render arbitrary canonical mappings as scalars plus one-level semantic sections."""

        data = document.data
        if not isinstance(data, Mapping):
            self.console.print(JSON.from_data(data))
            return
        scalars = [(key, value) for key, value in data.items() if not isinstance(value, (Mapping, list, tuple))]
        if scalars:
            table = Table(title=document.title, header_style="bold white", expand=True)
            table.add_column("Field", style="bright_cyan", no_wrap=True)
            table.add_column("Value")
            for key, value in scalars:
                shown = self.status(value) if str(key).lower() == "status" else self._show_value(value)
                table.add_row(str(key), shown)
            self.console.print(table)
        nested = [(key, value) for key, value in data.items() if isinstance(value, (Mapping, list, tuple))]
        if nested:
            table = Table(title="Sections", header_style="bold white", expand=True)
            table.add_column("Section", style="bright_cyan", no_wrap=True)
            table.add_column("Status", no_wrap=True)
            table.add_column("Content")
            for key, value in nested:
                status = "-"
                detail = self._show_value(value)
                if isinstance(value, Mapping):
                    raw_status = value.get("status")
                    status = self.status(raw_status) if raw_status is not None else "-"
                    parts = [
                        f"{name}={self._show_value(item)}"
                        for name, item in value.items()
                        if name != "status" and not isinstance(item, (Mapping, list, tuple))
                    ]
                    if parts:
                        detail = " · ".join(parts[:6])
                table.add_row(str(key), status, detail)
            self.console.print(table)

    def _show_provenance(self, document: Any) -> None:
        """Render stage lineage, hashes, generated artifacts, inputs, and tool fingerprints."""

        data = document.data
        stages = data.get("stages", {}) if isinstance(data, Mapping) else {}
        table = Table(title="Stage provenance", header_style="bold white", expand=True)
        table.add_column("Stage", style="bright_cyan", no_wrap=True)
        table.add_column("Parents")
        table.add_column("Inputs", justify="right")
        table.add_column("Generated", justify="right")
        table.add_column("Paths", no_wrap=True)
        table.add_column("Tools", justify="right")
        table.add_column("Fingerprint", no_wrap=True)
        for stage, item in stages.items() if isinstance(stages, Mapping) else ():
            if not isinstance(item, Mapping):
                continue
            parents = item.get("parents", {})
            parent_names = ", ".join(str(name) for name in parents) if isinstance(parents, Mapping) else "-"
            fingerprint = str(item.get("fingerprint", "-"))
            table.add_row(
                str(stage), parent_names or "-",
                str(len(item.get("inputs", ()))), str(len(item.get("generated", ()))),
                "yes" if item.get("input_paths_match", True) else "NO",
                str(len(item.get("tools", {}))) if isinstance(item.get("tools", {}), Mapping) else "0",
                fingerprint[:12] if fingerprint != "-" else "-",
            )
        self.console.print(table)

    def _show_sta(self, document: Any) -> None:
        """Render STA QoR and every analyzed corner/mode without detailed text reports."""

        data = document.data
        qor = data.get("qor", {}) if isinstance(data, Mapping) else {}
        self.console.print(Panel.fit(
            f"Status: {self.status(data.get('status', 'MISSING'))}\n"
            f"Stage: [white]{data.get('stage', '-')}[/white] · PDK: [white]{data.get('pdk', '-')}[/white]\n"
            f"Scenarios: [white]{qor.get('scenario_count', 0)}[/white] · "
            f"WNS: [white]{self._show_value(qor.get('worst_wns'))}[/white] · "
            f"TNS: [white]{self._show_value(qor.get('worst_tns'))}[/white] · "
            f"violating: [white]{qor.get('violating_paths', 0)}[/white] · "
            f"unconstrained: [white]{qor.get('unconstrained_paths', 0)}[/white]",
            title=document.title, border_style="orange1",
        ))
        table = Table(title="Scenarios", header_style="bold white", expand=True)
        for name in ("Corner", "Mode", "Status", "WNS", "TNS", "Violating", "Unconstrained", "Clocks"):
            table.add_column(name, no_wrap=name != "Clocks")
        scenarios = data.get("scenarios", ()) if isinstance(data, Mapping) else ()
        for item in scenarios if isinstance(scenarios, list) else ():
            if not isinstance(item, Mapping):
                continue
            clocks = ", ".join(
                f"{clock.get('name', '?')}:{self._show_value(clock.get('fmax_mhz'))}MHz"
                for clock in item.get("clocks", ()) if isinstance(clock, Mapping)
            )
            table.add_row(
                str(item.get("corner", "-")), str(item.get("mode", "-")),
                self.status(item.get("status", "MISSING")), self._show_value(item.get("wns")),
                self._show_value(item.get("tns")), str(item.get("violating_paths", 0)),
                str(item.get("unconstrained_paths", 0)), clocks or "-",
            )
        self.console.print(table)

    def _show_lint(self, document: Any) -> None:
        """Render compact lint QoR by tool."""

        data = document.data
        tools = data.get("tools", {}) if isinstance(data, Mapping) else {}
        table = Table(title="Lint summary", header_style="bold white", expand=True)
        table.add_column("Tool", style="bright_cyan")
        table.add_column("Status", no_wrap=True)
        table.add_column("Errors", justify="right")
        table.add_column("Warnings", justify="right")
        table.add_column("Diagnostics", justify="right")
        for name, item in tools.items() if isinstance(tools, Mapping) else ():
            item = item if isinstance(item, Mapping) else {}
            table.add_row(str(name), self.status(item.get("status", "MISSING")),
                          str(item.get("errors", 0)), str(item.get("warnings", 0)), str(item.get("diagnostics", 0)))
        self.console.print(table)
        self.console.print(f"[grey70]overall[/grey70] {self.status(data.get('status', 'MISSING'))}")

    def _show_cdc_rdc(self, document: Any) -> None:
        """Render structural CDC/RDC counts and obligations."""

        data = document.data
        self.console.print(Panel.fit(
            f"Status: {self.status(data.get('status', 'MISSING'))}\n"
            f"Clock domains: [white]{self._show_value(data.get('clock_domains'))}[/white] · "
            f"Reset domains: [white]{self._show_value(data.get('reset_domains'))}[/white] · "
            f"Sequential elements: [white]{self._show_value(data.get('sequential_elements'))}[/white]",
            title="CDC/RDC summary", border_style="orange1",
        ))
        table = Table(title="Analysis", header_style="bold white", expand=True)
        table.add_column("Section", style="bright_cyan")
        table.add_column("Values")
        for key in ("cdc", "rdc", "setup", "glitch", "obligations", "verification_obligations"):
            value = data.get(key)
            if value in (None, {}, []):
                continue
            if isinstance(value, Mapping):
                detail = " · ".join(
                    f"{name}={self._show_value(item)}" for name, item in value.items()
                    if not isinstance(item, (Mapping, list, tuple))
                ) or self._show_value(value)
            else:
                detail = self._show_value(value)
            table.add_row(key, detail)
        self.console.print(table)

    def _show_coverage(self, document: Any) -> None:
        """Render coverage totals by scope and coverage type."""

        data = document.data
        scopes = data.get("scopes", {}) if isinstance(data, Mapping) else {}
        table = Table(title="Coverage by scope", header_style="bold white", expand=True)
        table.add_column("Scope", style="bright_cyan")
        table.add_column("Hit", justify="right")
        table.add_column("Total", justify="right")
        table.add_column("Percent", justify="right")
        for name, item in scopes.items() if isinstance(scopes, Mapping) else ():
            if not isinstance(item, Mapping):
                continue
            total = item.get("total", item)
            if not isinstance(total, Mapping):
                continue
            table.add_row(str(name), str(total.get("hit", 0)), str(total.get("total", 0)), f"{float(total.get('percent', 0.0)):.2f}%")
        self.console.print(table)
        types = data.get("types", {}) if isinstance(data, Mapping) else {}
        if isinstance(types, Mapping) and types:
            table = Table(title="Coverage by type", header_style="bold white", expand=True)
            table.add_column("Type", style="bright_cyan")
            table.add_column("Hit", justify="right")
            table.add_column("Total", justify="right")
            table.add_column("Percent", justify="right")
            for name, item in types.items():
                if isinstance(item, Mapping):
                    table.add_row(str(name), str(item.get("hit", 0)), str(item.get("total", 0)), f"{float(item.get('percent', 0.0)):.2f}%")
            self.console.print(table)

    def _show_power_estimate(self, document: Any) -> None:
        """Render vectorless power estimate corner QoR."""

        data = document.data
        self.console.print(
            f"[grey70]status[/grey70] {self.status(data.get('status', 'MISSING'))} · "
            f"[grey70]activity[/grey70]=[white]{self._show_value(data.get('activity'))}[/white] · "
            f"[grey70]duty[/grey70]=[white]{self._show_value(data.get('duty'))}[/white]"
        )
        table = Table(title=document.title, header_style="bold white", expand=True)
        for name in ("Corner", "Internal W", "Switching W", "Dynamic W", "Leakage W", "Total W"):
            table.add_column(name, justify="right" if name != "Corner" else "left")
        corners = data.get("corners", {}) if isinstance(data, Mapping) else {}
        for corner, item in corners.items() if isinstance(corners, Mapping) else ():
            item = item if isinstance(item, Mapping) else {}
            table.add_row(str(corner), *(self._show_value(item.get(key)) for key in ("internal_w", "switching_w", "dynamic_w", "leakage_w", "total_w")))
        self.console.print(table)

    def _show_reports(self, document: Any) -> None:
        """Render power/fusion/physical compact summaries as one row per workload."""

        data = document.data
        table = Table(title=document.title, header_style="bold white", expand=True)
        for name in ("Test", "Backend", "Scenario", "Status", "Total W", "Worst WNS"):
            table.add_column(name, no_wrap=name != "Test")
        reports = data.get("reports", ()) if isinstance(data, Mapping) else ()
        for item in reports if isinstance(reports, list) else ():
            if not isinstance(item, Mapping):
                continue
            scenario = item.get("scenario", "-")
            if isinstance(scenario, Mapping):
                scenario = "/".join(str(scenario.get(key)) for key in ("corner", "sdf_mode") if scenario.get(key) is not None) or "-"
            totals: list[float] = []
            wnss: list[float] = []
            corners = item.get("corners", {})
            if isinstance(corners, Mapping):
                for corner in corners.values():
                    if not isinstance(corner, Mapping):
                        continue
                    if isinstance(corner.get("total_w"), (int, float)):
                        totals.append(float(corner["total_w"]))
                    if isinstance(corner.get("wns"), (int, float)):
                        wnss.append(float(corner["wns"]))
            table.add_row(
                str(item.get("test", item.get("test_name", "-"))), str(item.get("backend", "-")), str(scenario),
                self.status(item.get("status", "MISSING")), self._show_value(max(totals) if totals else None),
                self._show_value(min(wnss) if wnss else None),
            )
        self.console.print(table)
        self.console.print(
            f"[grey70]total[/grey70]=[white]{data.get('total', len(reports) if isinstance(reports, list) else 0)}[/white] · "
            f"[grey70]pass[/grey70]=[green]{data.get('passed', 0)}[/green] · "
            f"[grey70]fail[/grey70]=[red]{data.get('failed', 0)}[/red] · "
            f"[grey70]status[/grey70] {self.status(data.get('status', 'MISSING'))}"
        )

    def _show_metrics(self, document: Any) -> None:
        """Render the canonical flow snapshot without re-reading tool logs."""

        data = document.data if isinstance(document.data, Mapping) else {}
        flow = data.get("flow", {}) if isinstance(data.get("flow"), Mapping) else {}
        closure = data.get("closure", {}) if isinstance(data.get("closure"), Mapping) else {}
        table = Table(title=document.title, header_style="bold white", expand=True)
        table.add_column("Section", style="bright_cyan")
        table.add_column("Status")
        for key in ("analysis", "regression", "formal", "synthesis", "equivalence", "signoff", "implementation", "physical_signoff"):
            value = data.get(key)
            if not isinstance(value, Mapping):
                continue
            status = value.get("status")
            if status is None and key == "signoff":
                status = flow.get("signoff")
            table.add_row(key, self.status(status or "MISSING"))
        if closure:
            table.add_row("closure", self.status(closure.get("status", "MISSING")))
        self.console.print(table)

    def _show_manifest(self, document: Any) -> None:
        """Render immutable run identity and toolchain provenance compactly."""

        data = document.data if isinstance(document.data, Mapping) else {}
        run = data.get("run", {}) if isinstance(data.get("run"), Mapping) else {}
        git = data.get("git", {}) if isinstance(data.get("git"), Mapping) else {}
        env = data.get("environment", {}) if isinstance(data.get("environment"), Mapping) else {}
        self.console.print(Panel.fit(
            f"Top: [white]{run.get('top', '-')}[/white] · Run: [white]{run.get('run_id', '-')}[/white] · PDK: [white]{run.get('pdk', '-')}[/white]\n"
            f"FlexSoC: [white]{env.get('flexsoc', '-')}[/white] · Python: [white]{env.get('python', '-')}[/white]\n"
            f"Git: [white]{git.get('commit', '-')}[/white] · dirty=[white]{git.get('dirty', '-')}[/white]",
            title=document.title, border_style="orange1",
        ))
        tools = data.get("tools", {}) if isinstance(data.get("tools"), Mapping) else {}
        if tools:
            table = Table(title="Tools", header_style="bold white", expand=True)
            table.add_column("Tool", style="bright_cyan")
            table.add_column("Version")
            table.add_column("Path")
            for name, item in tools.items():
                item = item if isinstance(item, Mapping) else {}
                table.add_row(str(name), str(item.get("version", "-")), str(item.get("path", "-")))
            self.console.print(table)

    def render(self, document: Any) -> None:
        """Dispatch one canonical document to the smallest matching renderer."""

        key = getattr(document, "key", "")
        if key == "evidence":
            self._show_evidence_table(document.root)
            return
        if key == "levels":
            self._show_levels(document.root)
            return

        kind = getattr(document, "kind", "generic")
        if kind == "qualification":
            self._show_qualification(document)
        elif kind == "provenance":
            self._show_provenance(document)
        elif kind == "sta":
            self._show_sta(document)
        elif kind == "matrix":
            self._show_gls(document)
        elif kind == "lint":
            self._show_lint(document)
        elif kind == "cdc_rdc":
            self._show_cdc_rdc(document)
        elif kind == "coverage":
            self._show_coverage(document)
        elif kind == "power_estimate":
            self._show_power_estimate(document)
        elif kind == "reports":
            self._show_reports(document)
        elif kind == "metrics":
            self._show_metrics(document)
        elif kind == "manifest":
            self._show_manifest(document)
        else:
            self._show_mapping(document)

def render(run: Path, *, top: str, pdk: str, key: str, console: Console | None = None) -> ShowDocument:
    """Load and render one canonical report through the common show path."""

    document = load(run, top=top, pdk=pdk, key=key)
    ShowRenderer(console or Console()).render(document)
    return document

