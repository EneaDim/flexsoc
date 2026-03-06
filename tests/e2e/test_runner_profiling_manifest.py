from __future__ import annotations

import json
import os
import subprocess
import sys
from pathlib import Path


def _list_dirs(p: Path) -> set[Path]:
    if not p.exists():
        return set()
    return {x for x in p.iterdir() if x.is_dir()}


def _pick_new_runner_run_dir(before: set[Path], after: set[Path], action_id: str) -> Path:
    new_dirs = sorted(after - before)
    assert new_dirs, "no new run dirs created"

    # Runner dirs are named like: YYYYmmdd_HHMMSS_<action_id>
    # Flow dirs are: <top>/...
    candidates = [d for d in new_dirs if d.name.endswith(f"_{action_id}")]
    assert candidates, f"no runner run dir found for action '{action_id}' in: {[d.name for d in new_dirs]}"
    # If multiple, pick latest lexicographically (timestamp prefix)
    return sorted(candidates)[-1]


def _read_manifest(run_dir: Path) -> dict:
    mpath = run_dir / "manifest.json"
    assert mpath.exists(), f"manifest.json missing in {run_dir}"
    return json.loads(mpath.read_text(encoding="utf-8"))


def _run_ip_start(*, ws: Path, run_id: str, env: dict) -> int:
    cmd = [
        sys.executable, "-m", "flexsoc.cli",
        "run", "ip_start",
        "--top", "my_ip",
        "--reg-itf", "tlul",
        "--workspace", str(ws),
        "--run-id", run_id,
        "--overwrite", "--force",
    ]
    p = subprocess.run(cmd, capture_output=True, text=True, env=env)
    if p.returncode != 0:
        print("STDOUT:\n", p.stdout)
        print("STDERR:\n", p.stderr)
    return p.returncode


def test_runner_manifest_profiling_on_and_off(tmp_path: Path):
    ws = tmp_path / "workspace"
    ws.mkdir(parents=True, exist_ok=True)

    runs_root = ws / "sessions"

    # ----------------
    # Profiling ON
    # ----------------
    env_on = os.environ.copy()
    env_on["FLEXSOC_PROFILE"] = "1"

    before = _list_dirs(runs_root)
    rc = _run_ip_start(ws=ws, run_id="e2e_prof_on", env=env_on)
    assert rc == 0
    after = _list_dirs(runs_root)

    runner_dir_on = _pick_new_runner_run_dir(before, after, "ip_start")
    m_on = _read_manifest(runner_dir_on)

    assert "profiling" in m_on, "profiling should be present when FLEXSOC_PROFILE=1"
    assert m_on["profiling"]["enabled"] is True
    t = m_on["profiling"]["t"]
    assert "subprocess_s" in t
    assert "manifest_write_s" in t
    assert "total_s" in t

    # ----------------
    # Profiling OFF
    # ----------------
    env_off = os.environ.copy()
    env_off["FLEXSOC_PROFILE"] = "0"

    before2 = _list_dirs(runs_root)
    rc2 = _run_ip_start(ws=ws, run_id="e2e_prof_off", env=env_off)
    assert rc2 == 0
    after2 = _list_dirs(runs_root)

    runner_dir_off = _pick_new_runner_run_dir(before2, after2, "ip_start")
    m_off = _read_manifest(runner_dir_off)

    assert "profiling" not in m_off, "profiling should NOT be present when FLEXSOC_PROFILE=0"
