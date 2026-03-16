from __future__ import annotations

import json
import os
import platform
import shlex
import subprocess
import time
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, Optional


@dataclass(frozen=True)
class RunResult:
    exit_code: int
    run_dir: Path
    stdout_path: Path
    stderr_path: Path
    command: list[str]


@dataclass(frozen=True)
class BackendResult:
    exit_code: int
    run_dir: Path
    stdout_path: Path
    stderr_path: Path
    command: list[str]


def _utc_now() -> datetime:
    return datetime.now(timezone.utc)


def _timestamp_for_dir() -> str:
    return _utc_now().strftime("%Y%m%d_%H%M%S_%f")


def _safe_name(value: str) -> str:
    cleaned = "".join(ch if ch.isalnum() or ch in "._-" else "_" for ch in value.strip())
    cleaned = cleaned.strip("._-")
    return cleaned or "run"


def _sessions_root(workspace_dir: Path) -> Path:
    return workspace_dir / "sessions"


def _build_run_dir(workspace_dir: Path, action_id: str) -> Path:
    name = f"{_timestamp_for_dir()}_{_safe_name(action_id)}"
    return _sessions_root(workspace_dir) / name


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


def _shell_preview(cmd: list[str]) -> str:
    return " ".join(shlex.quote(str(x)) for x in cmd)


def _env_flag(name: str) -> bool:
    value = os.environ.get(name, "").strip().lower()
    return value not in {"", "0", "false", "no", "off"}


def _profiling_payload(*, subprocess_s: float, manifest_write_s: float, total_s: float) -> dict[str, Any]:
    return {
        "enabled": True,
        "t": {
            "subprocess_s": round(subprocess_s, 6),
            "manifest_write_s": round(manifest_write_s, 6),
            "total_s": round(total_s, 6),
        },
    }


def _write_runner_manifest(
    *,
    run_dir: Path,
    action_id: str,
    cmd: list[str],
    params: Dict[str, Any],
    workspace_dir: Path,
    cwd: Optional[Path],
    env: Optional[Dict[str, str]],
    timeout_s: Optional[int],
    started_at_utc: str,
    completed_at_utc: Optional[str],
    exit_code: Optional[int],
    stdout_path: Path,
    stderr_path: Path,
    profiling: Optional[Dict[str, Any]] = None,
) -> None:
    payload = {
        "tool": "flexsoc",
        "kind": "runner_session",
        "action_id": action_id,
        "command": [str(x) for x in cmd],
        "command_shell": _shell_preview(cmd),
        "params": _jsonify(params),
        "workspace_dir": str(workspace_dir),
        "cwd": str(cwd) if cwd else None,
        "timeout_s": timeout_s,
        "env_overrides": _jsonify(env or {}),
        "started_at_utc": started_at_utc,
        "completed_at_utc": completed_at_utc,
        "exit_code": exit_code,
        "stdout_log": str(stdout_path),
        "stderr_log": str(stderr_path),
        "host": {
            "platform": platform.platform(),
            "machine": platform.machine(),
            "processor": platform.processor(),
            "python": platform.python_version(),
        },
    }

    if profiling is not None:
        payload["profiling"] = profiling

    (run_dir / "manifest.json").write_text(
        json.dumps(payload, indent=2) + "\n",
        encoding="utf-8",
    )


def run_command(
    *,
    action_id: str,
    cmd: list[str],
    params: Dict[str, Any],
    workspace_dir: Path,
    cwd: Optional[Path] = None,
    env: Optional[Dict[str, str]] = None,
    timeout_s: Optional[int] = None,
) -> RunResult:
    ws = Path(workspace_dir).expanduser().resolve()
    run_dir = _build_run_dir(ws, action_id)
    run_dir.mkdir(parents=True, exist_ok=True)

    stdout_path = run_dir / "stdout.log"
    stderr_path = run_dir / "stderr.log"

    started_at = _utc_now().isoformat()
    overall_started = time.perf_counter()

    proc_env = os.environ.copy()
    if env:
        proc_env.update({str(k): str(v) for k, v in env.items()})

    exit_code: int
    completed_at: str

    subprocess_started = time.perf_counter()
    with stdout_path.open("w", encoding="utf-8") as stdout_f, stderr_path.open("w", encoding="utf-8") as stderr_f:
        try:
            proc = subprocess.run(
                [str(x) for x in cmd],
                cwd=str(cwd) if cwd else None,
                env=proc_env,
                stdout=stdout_f,
                stderr=stderr_f,
                text=True,
                timeout=timeout_s,
                check=False,
            )
            exit_code = int(proc.returncode)
        except subprocess.TimeoutExpired:
            stderr_f.write(f"\nERROR: command timed out after {timeout_s} seconds\n")
            exit_code = 124
        except FileNotFoundError as e:
            stderr_f.write(f"ERROR: executable not found: {e}\n")
            exit_code = 127
        except Exception as e:
            stderr_f.write(f"ERROR: {type(e).__name__}: {e}\n")
            exit_code = 1
    subprocess_s = time.perf_counter() - subprocess_started

    completed_at = _utc_now().isoformat()

    manifest_started = time.perf_counter()
    profiling = None
    if _env_flag("FLEXSOC_PROFILE"):
        profiling = _profiling_payload(
            subprocess_s=subprocess_s,
            manifest_write_s=0.0,
            total_s=0.0,
        )

    _write_runner_manifest(
        run_dir=run_dir,
        action_id=action_id,
        cmd=cmd,
        params=params,
        workspace_dir=ws,
        cwd=cwd,
        env=env,
        timeout_s=timeout_s,
        started_at_utc=started_at,
        completed_at_utc=completed_at,
        exit_code=exit_code,
        stdout_path=stdout_path,
        stderr_path=stderr_path,
        profiling=profiling,
    )

    manifest_write_s = time.perf_counter() - manifest_started
    if profiling is not None:
        _write_runner_manifest(
            run_dir=run_dir,
            action_id=action_id,
            cmd=cmd,
            params=params,
            workspace_dir=ws,
            cwd=cwd,
            env=env,
            timeout_s=timeout_s,
            started_at_utc=started_at,
            completed_at_utc=completed_at,
            exit_code=exit_code,
            stdout_path=stdout_path,
            stderr_path=stderr_path,
            profiling=_profiling_payload(
                subprocess_s=subprocess_s,
                manifest_write_s=manifest_write_s,
                total_s=time.perf_counter() - overall_started,
            ),
        )

    return RunResult(
        exit_code=exit_code,
        run_dir=run_dir,
        stdout_path=stdout_path,
        stderr_path=stderr_path,
        command=cmd,
    )


class MakeBackend:
    def run(
        self,
        *,
        action_id: str,
        cmd: list[str],
        params: Dict[str, Any],
        workspace_dir: Path,
        cwd: Optional[Path] = None,
        env: Optional[Dict[str, str]] = None,
        timeout_s: Optional[int] = None,
    ) -> BackendResult:
        result = run_command(
            action_id=action_id,
            cmd=cmd,
            params=params,
            workspace_dir=workspace_dir,
            cwd=cwd,
            env=env,
            timeout_s=timeout_s,
        )
        return BackendResult(
            exit_code=result.exit_code,
            run_dir=result.run_dir,
            stdout_path=result.stdout_path,
            stderr_path=result.stderr_path,
            command=result.command,
        )
