from __future__ import annotations

import json
import platform
import re
import subprocess
from dataclasses import asdict, dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, Optional

import yaml

from .workspace import RunRef


def _cmd_first_line(cmd: list[str]) -> str:
    try:
        p = subprocess.run(cmd, capture_output=True, text=True)
        out = (p.stdout + "\n" + p.stderr).strip()
        return out.splitlines()[0] if out else ""
    except Exception:
        return ""


def _safe_name(value: str) -> str:
    cleaned = re.sub(r"[^A-Za-z0-9_.-]+", "_", value.strip())
    return cleaned.strip("._") or "action"


def _list_loaded_ips(run_ref: RunRef) -> list[str]:
    if not run_ref.ips_dir.exists():
        return []
    return sorted(p.name for p in run_ref.ips_dir.iterdir() if p.is_dir())


def _jsonify(x: Any) -> Any:
    if x is None:
        return None
    if isinstance(x, (str, int, float, bool)):
        return x
    if isinstance(x, Path):
        return str(x)
    if isinstance(x, dict):
        return {str(k): _jsonify(v) for k, v in x.items()}
    if isinstance(x, (list, tuple)):
        return [_jsonify(v) for v in x]
    return str(x)


@dataclass
class RunManifest:
    run_top: str
    run_id: str
    top: str
    workspace: str
    run_dir: str
    last_action: str
    updated_at_utc: str
    loaded_ips: list[str]
    params: Dict[str, Any]
    last_session_dir: Optional[str] = None
    last_session_action: Optional[str] = None


@dataclass
class FlowManifest:
    tool: str
    action: str
    top: str
    run_id: str
    workspace: str
    flow_run_dir: str
    started_at_utc: str
    host: Dict[str, Any]
    tool_versions: Dict[str, str]
    params: Dict[str, Any]
    runner_session_dir: Optional[str] = None
    runner_action_id: Optional[str] = None


def _write_run_history_entry(
    run_ref: RunRef,
    *,
    action: str,
    top: Optional[str],
    params: Dict[str, Any],
    session_dir: Optional[Path],
) -> None:
    history_dir = run_ref.run_dir / "history"
    history_dir.mkdir(parents=True, exist_ok=True)

    now = datetime.now(timezone.utc)
    stamp = now.strftime("%Y%m%d_%H%M%S_%f")
    entry = {
        "timestamp_utc": now.isoformat(),
        "action": action,
        "run_top": run_ref.run_top,
        "run_id": run_ref.run_id,
        "top": top,
        "workspace": str(run_ref.workspace),
        "run_dir": str(run_ref.run_dir),
        "loaded_ips": _list_loaded_ips(run_ref),
        "params": _jsonify(params),
        "session_dir": str(session_dir) if session_dir else None,
    }

    out = history_dir / f"{stamp}_{_safe_name(action)}.json"
    out.write_text(json.dumps(entry, indent=2) + "\n", encoding="utf-8")


def read_run_manifest(path: Path) -> Dict[str, Any]:
    manifest_path = path if path.name == "run.yaml" else (path / "run.yaml")
    if not manifest_path.exists():
        return {}

    data = yaml.safe_load(manifest_path.read_text(encoding="utf-8")) or {}
    if not isinstance(data, dict):
        return {}

    data.setdefault("run_top", "")
    data.setdefault("run_id", "")
    data.setdefault("top", "")
    data.setdefault("workspace", "")
    data.setdefault("run_dir", "")
    data.setdefault("last_action", "")
    data.setdefault("updated_at_utc", "")
    data.setdefault("loaded_ips", [])
    data.setdefault("params", {})
    data.setdefault("last_session_dir", None)
    data.setdefault("last_session_action", None)
    return data


def read_run_history(run_dir: Path, limit: int = 10) -> list[Dict[str, Any]]:
    history_dir = run_dir / "history"
    if not history_dir.exists():
        return []

    files = sorted(history_dir.glob("*.json"), reverse=True)
    out: list[Dict[str, Any]] = []

    for file in files[:limit]:
        try:
            out.append(json.loads(file.read_text(encoding="utf-8")))
        except Exception:
            out.append(
                {
                    "timestamp_utc": "",
                    "action": "invalid_history_entry",
                    "top": None,
                    "loaded_ips": [],
                    "params": {"file": str(file)},
                    "session_dir": None,
                }
            )

    return out


def write_run_manifest(
    run_ref: RunRef,
    *,
    action: str,
    params: Dict[str, Any],
    top: Optional[str] = None,
    session_dir: Optional[Path] = None,
) -> None:
    run_ref.run_dir.mkdir(parents=True, exist_ok=True)
    run_ref.ips_dir.mkdir(parents=True, exist_ok=True)

    loaded_ips = _list_loaded_ips(run_ref)
    now = datetime.now(timezone.utc).isoformat()
    effective_top = top if top is not None else run_ref.top

    mf = RunManifest(
        run_top=run_ref.run_top,
        run_id=run_ref.run_id,
        top=effective_top or "",
        workspace=str(run_ref.workspace),
        run_dir=str(run_ref.run_dir),
        last_action=action,
        updated_at_utc=now,
        loaded_ips=loaded_ips,
        params=_jsonify(params),
        last_session_dir=str(session_dir) if session_dir else None,
        last_session_action=action,
    )

    out = run_ref.run_dir / "run.yaml"
    out.write_text(
        yaml.safe_dump(asdict(mf), sort_keys=False, allow_unicode=True),
        encoding="utf-8",
    )

    _write_run_history_entry(
        run_ref,
        action=action,
        top=effective_top,
        params=params,
        session_dir=session_dir,
    )


def read_flow_manifest(path: Path) -> Dict[str, Any]:
    manifest_path = path if path.name == "manifest.json" else (path / "manifest.json")
    if not manifest_path.exists():
        return {}
    try:
        data = json.loads(manifest_path.read_text(encoding="utf-8"))
    except Exception:
        return {}
    return data if isinstance(data, dict) else {}


def write_flow_manifest(
    flow_run_dir: Path,
    *,
    action: str,
    top: str,
    run_id: str,
    workspace: Path,
    params: Dict[str, Any],
    runner_session_dir: Optional[Path] = None,
    runner_action_id: Optional[str] = None,
) -> None:
    flow_run_dir.mkdir(parents=True, exist_ok=True)

    versions = {
        "python": platform.python_version(),
        "verilator": _cmd_first_line(["verilator", "--version"]),
        "yosys": _cmd_first_line(["yosys", "-V"]),
        "openroad": _cmd_first_line(["openroad", "-version"]),
        "sv2v": _cmd_first_line(["sv2v", "--version"]),
    }

    mf = FlowManifest(
        tool="flexsoc",
        action=action,
        top=top,
        run_id=run_id,
        workspace=str(workspace),
        flow_run_dir=str(flow_run_dir),
        started_at_utc=datetime.now(timezone.utc).isoformat(),
        host={
            "platform": platform.platform(),
            "machine": platform.machine(),
            "processor": platform.processor(),
        },
        tool_versions=versions,
        params=_jsonify(params),
        runner_session_dir=str(runner_session_dir) if runner_session_dir else None,
        runner_action_id=runner_action_id,
    )

    out = flow_run_dir / "manifest.json"
    out.write_text(json.dumps(asdict(mf), indent=2) + "\n", encoding="utf-8")


def update_runner_manifest(runner_dir: Path, patch: Dict[str, Any]) -> None:
    manifest_path = runner_dir / "manifest.json"
    if manifest_path.exists():
        try:
            data = json.loads(manifest_path.read_text(encoding="utf-8"))
        except Exception:
            data = {}
    else:
        data = {}

    if not isinstance(data, dict):
        data = {}

    data.update(_jsonify(patch))
    manifest_path.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")
