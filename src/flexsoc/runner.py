from __future__ import annotations

import hashlib
import json
import logging
import os
import subprocess
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Dict, List, Optional

log = logging.getLogger(__name__)


def _jsonify(x: Any) -> Any:
    """
    Make a value JSON-serializable without using json.dumps(default=...).

    Rules:
    - Path -> str(path)
    - dict/list/tuple -> recurse
    - primitives -> keep
    - everything else -> str(x)
    """
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
    """
    Best-effort git HEAD sha without calling git.
    Returns None if not in git repo or cannot read.
    """
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
            # Fallback: packed-refs
            packed = git_dir / "packed-refs"
            if packed.exists():
                for line in packed.read_text(encoding="utf-8").splitlines():
                    if line.startswith("#") or line.startswith("^") or not line.strip():
                        continue
                    sha, name = line.split(" ", 1)
                    if name.strip() == ref:
                        return sha.strip()
        # Detached HEAD contains sha directly
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
    """
    Compute a stable signature for the run.

    Design goals:
    - Deterministic
    - Does not include timestamps
    - Includes inputs that affect behavior
    - Lightweight (no tool invocations)

    Note: we intentionally do NOT include full os.environ to avoid noise.
    """
    payload: Dict[str, Any] = {
        "action_id": action_id,
        "cmd": [str(x) for x in cmd],
        "params": _jsonify(params),
        "cwd": str(cwd) if cwd else None,
        "env": _jsonify(env or {}),  # only explicit env overrides
        "git_head": _repo_git_head(repo_root),
    }
    blob = json.dumps(payload, sort_keys=True, separators=(",", ":")).encode("utf-8")
    return hashlib.sha256(blob).hexdigest()


def _find_cached_run_dir(workspace_dir: Path, signature: str) -> Optional[Path]:
    """
    Look for a previous runner run dir under <workspace>/runs whose manifest.json
    has the same signature and exit_code==0.

    Conservative: only reuses successful runs.
    """
    runs_root = workspace_dir / "runs"
    if not runs_root.exists():
        return None

    # Scan newest-first (lexicographic works due to timestamp prefix)
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
    """
    Low-level command runner.

    Contract (do not break):
    - Creates runner run dir at: <workspace>/runs/<timestamp>_<action_id>/
    - Writes stdout.log, stderr.log
    - Writes manifest.json (runner-level)
    """
    workspace_dir.mkdir(parents=True, exist_ok=True)

    # repo_root: best effort (assume package lives in repo; try cwd or workspace parent)
    repo_root: Optional[Path] = None
    try:
        if cwd:
            repo_root = cwd
        else:
            # heuristic: workspace is usually <repo>/workspace
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

    # Soft caching (opt-in)
    if _cache_enabled():
        cached_dir = _find_cached_run_dir(workspace_dir, signature)
        if cached_dir is not None:
            log.info("cache_hit: action=%s signature=%s dir=%s", action_id, signature[:12], cached_dir)
            # Return cached result without creating a new run dir
            # (non-breaking: caller expects run_dir and exit_code)
            exit_code = 0
            return RunResult(run_dir=cached_dir, exit_code=exit_code)

    run_dir = workspace_dir / "runs" / f"{_now_id()}_{action_id}"
    run_dir.mkdir(parents=True, exist_ok=True)

    stdout_path = run_dir / "stdout.log"
    stderr_path = run_dir / "stderr.log"
    manifest_path = run_dir / "manifest.json"

    prof = _profile_enabled()
    t0 = time.time()

    proc_env = os.environ.copy()
    if env:
        proc_env.update(env)

    # Measure subprocess wall time
    t_sub_start = time.time()
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
    t_sub_end = time.time()

    # Build manifest payload
    manifest: Dict[str, Any] = {
        "action_id": action_id,
        "signature": signature,
        "cmd": [str(x) for x in cmd],
        "params": _jsonify(params),
        "cwd": str(cwd) if cwd else None,
        "exit_code": p.returncode,
        "duration_s": round(t_sub_end - t_sub_start, 3),
        "stdout": str(stdout_path),
        "stderr": str(stderr_path),
    }

    if prof:
        # Measure manifest serialization/write separately
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
        # Re-write including profiling block
        manifest_path.write_text(json.dumps(manifest, indent=2), encoding="utf-8")
    else:
        # Normal path: write once
        manifest_path.write_text(json.dumps(manifest, indent=2), encoding="utf-8")

    return RunResult(run_dir=run_dir, exit_code=p.returncode)


# --------------------------------------------------------------------------------------
# Backend layer (incremental, non-breaking)
# --------------------------------------------------------------------------------------


@dataclass(frozen=True)
class BackendResult:
    """
    Normalized result returned by backend implementations.

    Note: stdout/stderr paths follow the existing runner contract:
    they are always <run_dir>/stdout.log and <run_dir>/stderr.log.
    """
    exit_code: int
    run_dir: Path
    stdout_log: Path
    stderr_log: Path


class MakeBackend:
    """
    Minimal backend that delegates to run_command().

    Why this exists:
    - executor/usecases decide WHAT to run and how to interpret artifacts
    - backend decides HOW to run (local subprocess today; docker/remote later)

    Non-breaking: it uses the exact same runner run_dir + logs + manifest.json.
    """

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
