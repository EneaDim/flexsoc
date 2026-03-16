from __future__ import annotations

import json
import sys
from pathlib import Path

from flexsoc.runtime.runner import run_command


def _manifest(run_dir: Path) -> dict:
    p = run_dir / "manifest.json"
    assert p.exists()
    return json.loads(p.read_text(encoding="utf-8"))


def test_runner_creates_distinct_session_dirs_for_distinct_invocations(tmp_path: Path):
    ws = tmp_path / "workspace"
    ws.mkdir(parents=True, exist_ok=True)

    r1 = run_command(
        action_id="unit_runner_sessions",
        cmd=[sys.executable, "-c", "print('hello')"],
        params={"k": "v"},
        workspace_dir=ws,
    )
    r2 = run_command(
        action_id="unit_runner_sessions",
        cmd=[sys.executable, "-c", "print('hello')"],
        params={"k": "v"},
        workspace_dir=ws,
    )

    assert r1.exit_code == 0
    assert r2.exit_code == 0
    assert r1.run_dir != r2.run_dir

    m1 = _manifest(r1.run_dir)
    m2 = _manifest(r2.run_dir)

    assert m1["command"] == [sys.executable, "-c", "print('hello')"]
    assert m2["command"] == [sys.executable, "-c", "print('hello')"]

    runs_root = ws / "sessions"
    dirs = [p for p in runs_root.iterdir() if p.is_dir()]
    assert len(dirs) == 2
