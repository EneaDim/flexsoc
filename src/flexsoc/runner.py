from __future__ import annotations

import hashlib
import json
import logging
import os
import subprocess
import time
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, List, Optional

log = logging.getLogger(__name__)


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


def _profile_enabled() -> bool:
    v = os.environ.get("FLEXSOC_PROFILE", "").strip()
    return v not in ("", "0", "false", "False", "no", "NO")


def _cache_enabled() -> bool:
    v = os.environ.get("FLEXSOC_CACHE", "").strip()
    return v not in ("", "0", "false", "False", "no", "NO")


def _repo_git_head(repo_root: Optional[Path]) -> Optional[str]:
    if repo_root is None:
        return None
    try:
        git_dir = repo_root / ".git"
        head = (git_dir / "HEAD").read_text(encoding="utf-8").strip()
        if head.startswith("ref:"):
            ref = head.split(" ", 1)[1].strip()
            ref_path = git_dir / ref
            if ref_path.exists():
                return ref_path.read_text(encoding="utf-8").strip()
            packed = git_dir / "packed-refs"
            if packed.exists():
                for line in packed.read_text(encoding="utf-8").splitlines():
                    if line.startswith("#") or line.startswith("^") or not line.strip():
                        continue
                    sha, name = line.split(" ", 1)
                    if name.strip() == ref:
                        return sha.strip()
        if len(head) >= 7:
            return head
    except Exception:
        return None
    return None


def _compute_signature(
    *,
    action_id: str,
    cmd: List[str],
    params: Dict[str, Any],
    cwd: Optional[Path],
    env: Optional[Dict[str, str]],
    repo_root: Optional[Path],
) -> str:
    payload: Dict[str, Any] = {
        "action_id": action_id,
        "cmd": [str(x) for x in cmd],
        "params": _jsonify(params),
        "cwd": str(cwd) if cwd else None,
        "env": _jsonify(env or {}),
        "git_head": _repo_git_head(repo_root),
    }
    blob = json.dumps(payload, sort_keys=True, separators=(",", ":")).encode("utf-8")
    return hashlib.sha256(blob).hexdigest()


def _find_cached_run_dir(workspace_dir: Path, signature: str) -> Optional[Path]:
    runs_root = workspace_dir / "sessions"
    if not runs_root.exists():
        return None

    candidates = sorted([p for p in runs_root.iterdir() if p.is_dir()], reverse=True)

    for d in candidates:
        mpath = d / "manifest.json"
        if not mpath.exists():
            continue
        try:
            m = json.loads(mpath.read_text(encoding="utf-8"))
        except Exception:
            continue
        if m.get("signature") != signature:
            continue
        if m.get("exit_code") != 0:
            continue
        return d

    return None


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

    repo_root: Optional[Path] = None
    try:
        if cwd:
            repo_root = cwd
        else:
            repo_root = workspace_dir.parent if (workspace_dir / "..").exists() else None
            if repo_root and not (repo_root / ".git").exists():
                repo_root = None
    except Exception:
        repo_root = None

    signature = _compute_signature(
        action_id=action_id,
        cmd=cmd,
        params=params,
        cwd=cwd,
        env=env,
        repo_root=repo_root,
    )

    if _cache_enabled():
        cached_dir = _find_cached_run_dir(workspace_dir, signature)
        if cached_dir is not None:
            log.info("cache_hit: action=%s signature=%s dir=%s", action_id, signature[:12], cached_dir)
            return RunResult(run_dir=cached_dir, exit_code=0)

    run_dir = workspace_dir / "sessions" / f"{_now_id()}_{action_id}"
    run_dir.mkdir(parents=True, exist_ok=True)

    stdout_path = run_dir / "stdout.log"
    stderr_path = run_dir / "stderr.log"
    manifest_path = run_dir / "manifest.json"

    prof = _profile_enabled()
    t0 = time.time()

    proc_env = os.environ.copy()
    if env:
        proc_env.update(env)

    t_sub_start = time.time()
    exit_code = 0
    timed_out = False
    exception_text: Optional[str] = None

    with stdout_path.open("w", encoding="utf-8") as out, stderr_path.open("w", encoding="utf-8") as err:
        try:
            p = subprocess.run(
                cmd,
                cwd=str(cwd) if cwd else None,
                env=proc_env,
                stdout=out,
                stderr=err,
                timeout=timeout_s,
                text=True,
            )
            exit_code = p.returncode
        except subprocess.TimeoutExpired as e:
            timed_out = True
            exit_code = 124
            exception_text = f"TimeoutExpired: command exceeded timeout_s={timeout_s}"
            err.write(exception_text + "\n")
            if e.stdout:
                out.write(str(e.stdout))
            if e.stderr:
                err.write(str(e.stderr))
        except Exception as e:
            exit_code = 1
            exception_text = f"{type(e).__name__}: {e}"
            err.write(exception_text + "\n")

    t_sub_end = time.time()

    manifest: Dict[str, Any] = {
        "kind": "runner_session",
        "action_id": action_id,
        "signature": signature,
        "session_dir": str(run_dir),
        "started_at_utc": datetime.fromtimestamp(t_sub_start, tz=timezone.utc).isoformat(),
        "finished_at_utc": datetime.fromtimestamp(t_sub_end, tz=timezone.utc).isoformat(),
        "cmd": [str(x) for x in cmd],
        "params": _jsonify(params),
        "cwd": str(cwd) if cwd else None,
        "exit_code": exit_code,
        "timed_out": timed_out,
        "exception": exception_text,
        "duration_s": round(t_sub_end - t_sub_start, 3),
        "stdout": str(stdout_path),
        "stderr": str(stderr_path),
    }

    if prof:
        t_manifest_start = time.time()
        payload = json.dumps(manifest, indent=2)
        manifest_path.write_text(payload, encoding="utf-8")
        t_manifest_end = time.time()

        manifest["profiling"] = {
            "enabled": True,
            "t": {
                "start_epoch_s": round(t0, 6),
                "subprocess_s": round(t_sub_end - t_sub_start, 6),
                "manifest_write_s": round(t_manifest_end - t_manifest_start, 6),
                "total_s": round(t_manifest_end - t0, 6),
            },
        }
        manifest_path.write_text(json.dumps(manifest, indent=2), encoding="utf-8")
    else:
        manifest_path.write_text(json.dumps(manifest, indent=2), encoding="utf-8")

    return RunResult(run_dir=run_dir, exit_code=exit_code)


@dataclass(frozen=True)
class BackendResult:
    exit_code: int
    run_dir: Path
    stdout_log: Path
    stderr_log: Path


@dataclass(frozen=True)
class MakeBackend:
    def run(
        self,
        *,
        action_id: str,
        cmd: List[str],
        params: Dict[str, Any],
        workspace_dir: Path,
        cwd: Optional[Path] = None,
        env: Optional[Dict[str, str]] = None,
        timeout_s: Optional[int] = None,
    ) -> BackendResult:
        rr = run_command(
            action_id=action_id,
            cmd=cmd,
            params=params,
            workspace_dir=workspace_dir,
            cwd=cwd,
            env=env,
            timeout_s=timeout_s,
        )

        stdout_log = rr.run_dir / "stdout.log"
        stderr_log = rr.run_dir / "stderr.log"

        return BackendResult(
            exit_code=rr.exit_code,
            run_dir=rr.run_dir,
            stdout_log=stdout_log,
            stderr_log=stderr_log,
        )
