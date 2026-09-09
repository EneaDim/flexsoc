"""Read-only access to canonical machine-readable FlexSoC flow reports."""

from __future__ import annotations

from dataclasses import dataclass
import json
from pathlib import Path
from typing import Any, Mapping


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
    specs = (
        ShowSpec("qualification", "Qualification", meta / "qualification.json"),
        ShowSpec("evidence", "Qualification evidence", meta / "qualification.json", ("evidence",)),
        ShowSpec("levels", "Qualification levels", meta / "qualification.json", ("levels",)),
        ShowSpec("metrics", "Collected flow metrics", metrics),
        ShowSpec("manifest", "Run manifest", meta / "manifest.json"),
        ShowSpec("provenance", "Stage provenance", meta / "provenance.json"),
        ShowSpec("settings", "Effective PDK settings", meta / "settings.json"),
        ShowSpec("design_intent", "Common design intent", run / "meta" / "design_intent.json"),
        ShowSpec("contract", "Frozen contract", run / "contract" / "contract.json"),
        ShowSpec("regression", "RTL regression metrics", metrics, ("regression",)),
        ShowSpec("formal", "Formal metrics", metrics, ("formal",)),
        ShowSpec("eqy", "Equivalence metrics", metrics, ("equivalence",)),
        ShowSpec("synthesis", "Synthesis metrics", metrics, ("synthesis",)),
        ShowSpec("implementation", "Implementation metrics", metrics, ("implementation",)),
        ShowSpec("closure", "Technical closure", metrics, ("closure",)),
        ShowSpec("cdc_rdc", "CDC/RDC summary", run / "analysis" / "cdc_rdc" / "summary.json"),
        ShowSpec("coverage", "Coverage matrix", run / "dv" / "functional" / "coverage" / "summary.json"),
        ShowSpec("syn", "Synthesis report", run / "syn" / pdk / f"{top}_synth.json"),
        ShowSpec("gls_post_syn", "Post-synthesis GLS matrix", sim / "post_syn" / pdk / "summary_sv.json"),
        ShowSpec("sta", "Post-synthesis STA", signoff / "sta" / "sta.json"),
        ShowSpec("power", "Post-synthesis activity power", signoff / "power" / "analysis" / "summary.json"),
        ShowSpec("fusion", "Post-synthesis timing/power fusion", signoff / "fusion" / "summary.json"),
        ShowSpec("physical_signoff", "Physical signoff", signoff / "post_pnr" / "physical" / "summary.json"),
        ShowSpec("gls_post_pnr", "Post-PnR GLS matrix", sim / "post_pnr" / pdk / "summary_sv.json"),
        ShowSpec("sta_post_pnr", "Post-PnR STA", signoff / "post_pnr" / "sta" / "sta.json"),
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
    return ShowDocument(spec.key, spec.title, spec.path, data, root)


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
