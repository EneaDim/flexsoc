from __future__ import annotations

import json
import platform
import subprocess
from dataclasses import asdict, dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict


def _cmd_first_line(cmd: list[str]) -> str:
    try:
        p = subprocess.run(cmd, capture_output=True, text=True)
        out = (p.stdout + "\n" + p.stderr).strip()
        return out.splitlines()[0] if out else ""
    except Exception:
        return ""


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
