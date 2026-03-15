from __future__ import annotations

import os
import shutil
from pathlib import Path
from typing import Optional


def _repo_root() -> Path:
    # src/flexsoc/clean.py -> repo root is parents[2]
    return Path(__file__).resolve().parents[3]


def _safe_rmtree(p: Path) -> None:
    """
    Defensive delete: refuse to delete root/home, and refuse empty/suspicious paths.
    """
    p = p.resolve()
    if str(p) in ("/", str(Path.home().resolve())):
        raise ValueError(f"Refusing to delete dangerous path: {p}")
    if len(str(p)) < 5:
        raise ValueError(f"Refusing to delete suspiciously short path: {p}")
    if p.exists():
        shutil.rmtree(p)


def _looks_like_workspace(ws: Path) -> bool:
    """
    Best-effort workspace detection.
    Accept if:
      - directory name is literally 'workspace', or
      - contains known workspace subdirs/files
    """
    ws = ws.resolve()
    if ws.name == "workspace":
        return True

    known_markers = [
        ws / "runs",
        ws / "sessions",
        ws / ".flexsoc_context.json",
    ]
    return any(marker.exists() for marker in known_markers)


def clean_pycache(root: Optional[Path] = None) -> int:
    """
    Remove Python bytecode caches recursively:
      - __pycache__ directories
      - *.pyc / *.pyo files

    Returns number of removed entries (best effort).
    """
    root = (root or _repo_root()).resolve()
    removed = 0

    for dirpath, dirnames, filenames in os.walk(root):
        dp = Path(dirpath)

        if "__pycache__" in dirnames:
            pyc_dir = dp / "__pycache__"
            try:
                _safe_rmtree(pyc_dir)
                removed += 1
            except Exception:
                pass
            dirnames[:] = [d for d in dirnames if d != "__pycache__"]

        for fn in filenames:
            if fn.endswith((".pyc", ".pyo")):
                fp = dp / fn
                try:
                    fp.unlink(missing_ok=True)
                    removed += 1
                except Exception:
                    pass

    return removed


def clean_run(workspace: Path, top: str, run_id: str) -> None:
    """
    Remove one flow run directory: workspace/runs/<top>/<run_id>
    """
    ws = Path(workspace).resolve()
    run_dir = ws / "runs" / top / run_id
    _safe_rmtree(run_dir)

    top_dir = ws / "runs" / top
    try:
        if top_dir.exists() and not any(top_dir.iterdir()):
            top_dir.rmdir()
    except Exception:
        pass


def clean_workspace(workspace: Path) -> None:
    """
    Remove runs artifacts inside workspace, but keep the workspace root directory.
    """
    ws = Path(workspace).resolve()
    runs = ws / "runs"
    if runs.exists():
        _safe_rmtree(runs)
    (ws / "runs").mkdir(parents=True, exist_ok=True)


def clean_all(workspace: Path) -> None:
    """
    Remove the entire workspace directory (hard reset), but only if it really
    looks like a FlexSoC workspace.
    """
    ws = Path(workspace).resolve()

    if not _looks_like_workspace(ws):
        raise ValueError(
            f"Refusing to remove non-workspace path: {ws}. "
            "Expected a FlexSoC workspace directory."
        )

    _safe_rmtree(ws)
