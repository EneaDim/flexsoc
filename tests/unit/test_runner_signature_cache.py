from __future__ import annotations

import json
import sys
from pathlib import Path

from flexsoc.runner import run_command


def _manifest(run_dir: Path) -> dict:
    p = run_dir / "manifest.json"
    assert p.exists()
    return json.loads(p.read_text(encoding="utf-8"))


def test_signature_is_present_and_cache_hit(tmp_path: Path, monkeypatch):
    ws = tmp_path / "workspace"
    ws.mkdir(parents=True, exist_ok=True)

    # Ensure profiling doesn't affect semantics
    monkeypatch.delenv("FLEXSOC_PROFILE", raising=False)

    # First run: cache disabled -> creates a new run dir
    monkeypatch.delenv("FLEXSOC_CACHE", raising=False)
    r1 = run_command(
        action_id="unit_cache",
        cmd=[sys.executable, "-c", "print('hello')"],
        params={"k": "v"},
        workspace_dir=ws,
    )
    m1 = _manifest(r1.run_dir)
    assert "signature" in m1
    assert isinstance(m1["signature"], str)
    assert len(m1["signature"]) >= 32  # sha256 hex is 64

    # Second run: same inputs, cache enabled -> must reuse the previous run_dir
    monkeypatch.setenv("FLEXSOC_CACHE", "1")
    r2 = run_command(
        action_id="unit_cache",
        cmd=[sys.executable, "-c", "print('hello')"],
        params={"k": "v"},
        workspace_dir=ws,
    )

    assert r2.exit_code == 0
    assert r2.run_dir == r1.run_dir, "expected cache hit to reuse previous run_dir"

    # Also ensure it didn't create additional runner dirs
    runs_root = ws / "runs"
    dirs = [p for p in runs_root.iterdir() if p.is_dir()]
    assert len(dirs) == 1, f"expected 1 run dir, got {len(dirs)}: {[d.name for d in dirs]}"
