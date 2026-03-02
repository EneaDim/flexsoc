from __future__ import annotations

import json

def _json_default(o):
    # Make manifests resilient to typer OptionInfo / Path / other non-JSON types.
    try:
        from pathlib import Path as _Path
        if isinstance(o, _Path):
            return str(o)
    except Exception:
        pass

    try:
        from typer.models import OptionInfo
        if isinstance(o, OptionInfo):
            # If a Typer option default leaked into runtime, serialize it safely.
            return None
    except Exception:
        pass

    # Last resort: string representation
    return str(o)

import os
import subprocess
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Dict, List, Optional


@dataclass
class RunResult:
    run_dir: Path
    exit_code: int


def _now_id() -> str:
    return time.strftime("%Y%m%d_%H%M%S")


def run_command(
    *,
    action_id: str,
    cmd: List[str],
    params: Dict[str, Any],
    workspace_dir: Path,
    cwd: Optional[Path] = None,
    env: Optional[Dict[str, str]] = None,
    timeout_s: Optional[int] = None,
) -> RunResult:
    workspace_dir.mkdir(parents=True, exist_ok=True)
    run_dir = workspace_dir / "runs" / f"{_now_id()}_{action_id}"
    run_dir.mkdir(parents=True, exist_ok=True)

    stdout_path = run_dir / "stdout.log"
    stderr_path = run_dir / "stderr.log"
    manifest_path = run_dir / "manifest.json"

    start = time.time()
    proc_env = os.environ.copy()
    if env:
        proc_env.update(env)

    with stdout_path.open("w", encoding="utf-8") as out, stderr_path.open("w", encoding="utf-8") as err:
        p = subprocess.run(
            cmd,
            cwd=str(cwd) if cwd else None,
            env=proc_env,
            stdout=out,
            stderr=err,
            timeout=timeout_s,
            text=True,
        )

    duration_s = round(time.time() - start, 3)

    manifest = {
        "action_id": action_id,
        "cmd": cmd,
        "params": params,
        "cwd": str(cwd) if cwd else None,
        "exit_code": p.returncode,
        "duration_s": duration_s,
        "stdout": str(stdout_path),
        "stderr": str(stderr_path),
    }
    manifest_path.write_text(json.dumps(manifest, indent=2, default=_json_default), encoding="utf-8")

    return RunResult(run_dir=run_dir, exit_code=p.returncode)
