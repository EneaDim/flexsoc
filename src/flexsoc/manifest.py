from __future__ import annotations

import json
import platform
import subprocess
from dataclasses import asdict, dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, Optional
import re

from .workspace import RunRef


def _cmd_first_line(cmd: list[str]) -> str:
    try:
        p = subprocess.run(cmd, capture_output=True, text=True)
        out = (p.stdout + "\n" + p.stderr).strip()
        return out.splitlines()[0] if out else ""
    except Exception:
        return ""


def _yaml_scalar(value: Any) -> str:
    if value is None:
        return '""'
    if isinstance(value, bool):
        return "true" if value else "false"
    if isinstance(value, (int, float)):
        return str(value)
    text = str(value).replace("\\", "\\\\").replace('"', '\\"')
    return f'"{text}"'


def _list_loaded_ips(run_ref: RunRef) -> list[str]:
    if not run_ref.ips_dir.exists():
        return []
    return sorted(p.name for p in run_ref.ips_dir.iterdir() if p.is_dir())


def _safe_name(value: str) -> str:
    cleaned = re.sub(r"[^A-Za-z0-9_.-]+", "_", value.strip())
    return cleaned.strip("._") or "action"


def _write_run_history_entry(
    run_ref: RunRef,
    *,
    action: str,
    top: Optional[str],
    params: Dict[str, Any],
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
        "params": params,
    }

    out = history_dir / f"{stamp}_{_safe_name(action)}.json"
    out.write_text(json.dumps(entry, indent=2) + "\n", encoding="utf-8")


def _yaml_lines(key: str, value: Any, indent: int = 0) -> list[str]:
    prefix = " " * indent
    if isinstance(value, dict):
        lines = [f"{prefix}{key}:"]
        if not value:
            lines[-1] += " {}"
            return lines
        for subkey, subvalue in value.items():
            lines.extend(_yaml_lines(str(subkey), subvalue, indent + 2))
        return lines

    if isinstance(value, list):
        lines = [f"{prefix}{key}:"]
        if not value:
            lines[-1] += " []"
            return lines
        for item in value:
            if isinstance(item, (dict, list)):
                lines.append(f"{prefix}  -")
                if isinstance(item, dict):
                    for subkey, subvalue in item.items():
                        lines.extend(_yaml_lines(str(subkey), subvalue, indent + 4))
                else:
                    for subitem in item:
                        if isinstance(subitem, (dict, list)):
                            raise TypeError("nested complex lists are not supported in run manifest")
                        lines.append(f"{prefix}    - {_yaml_scalar(subitem)}")
            else:
                lines.append(f"{prefix}  - {_yaml_scalar(item)}")
        return lines

    return [f"{prefix}{key}: {_yaml_scalar(value)}"]


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


def write_run_manifest(
    run_ref: RunRef,
    *,
    action: str,
    params: Dict[str, Any],
    top: Optional[str] = None,
) -> None:
    run_ref.run_dir.mkdir(parents=True, exist_ok=True)
    run_ref.ips_dir.mkdir(parents=True, exist_ok=True)

    loaded_ips = _list_loaded_ips(run_ref)
    now = datetime.now(timezone.utc).isoformat()
    effective_top = top if top is not None else run_ref.top

    lines = [
        f"run_top: {_yaml_scalar(run_ref.run_top)}",
        f"run_id: {_yaml_scalar(run_ref.run_id)}",
        f"top: {_yaml_scalar(effective_top or '')}",
        f"workspace: {_yaml_scalar(str(run_ref.workspace))}",
        f"run_dir: {_yaml_scalar(str(run_ref.run_dir))}",
        f"last_action: {_yaml_scalar(action)}",
        f"updated_at_utc: {_yaml_scalar(now)}",
        "loaded_ips:",
    ]

    if loaded_ips:
        lines.extend(f"  - {_yaml_scalar(name)}" for name in loaded_ips)
    else:
        lines.append("  []")

    lines.extend(_yaml_lines("params", params, 0))
    lines.append("")

    (run_ref.run_dir / "run.yaml").write_text("\n".join(lines), encoding="utf-8")
    _write_run_history_entry(
        run_ref,
        action=action,
        top=effective_top,
        params=params,
    )




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
                }
            )

    return out


def write_flow_manifest(
    flow_run_dir: Path,
    *,
    action: str,
    top: str,
    run_id: str,
    workspace: Path,
    params: Dict[str, Any],
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
        params=params,
    )

    out = flow_run_dir / "manifest.json"
    out.write_text(json.dumps(asdict(mf), indent=2) + "\n", encoding="utf-8")
