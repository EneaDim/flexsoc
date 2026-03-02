from __future__ import annotations

import json
import sys
from pathlib import Path

from flexsoc.runner import run_command


def _read_manifest(run_dir: Path) -> dict:
    p = run_dir / "manifest.json"
    assert p.exists(), "manifest.json not found"
    return json.loads(p.read_text(encoding="utf-8"))


def test_runner_manifest_no_profile(tmp_path: Path, monkeypatch):
    ws = tmp_path / "ws"
    monkeypatch.delenv("FLEXSOC_PROFILE", raising=False)

    rr = run_command(
        action_id="unit_no_profile",
        cmd=[sys.executable, "-c", "print('ok')"],
        params={"top": "my_ip"},
        workspace_dir=ws,
    )

    m = _read_manifest(rr.run_dir)
    assert m["action_id"] == "unit_no_profile"
    assert "profiling" not in m, "profiling should NOT be present when FLEXSOC_PROFILE is unset"
    assert (rr.run_dir / "stdout.log").exists()
    assert (rr.run_dir / "stderr.log").exists()
    assert isinstance(m.get("duration_s"), (int, float))


def test_runner_manifest_with_profile(tmp_path: Path, monkeypatch):
    ws = tmp_path / "ws"
    monkeypatch.setenv("FLEXSOC_PROFILE", "1")

    rr = run_command(
        action_id="unit_profile",
        cmd=[sys.executable, "-c", "print('ok')"],
        params={"top": "my_ip"},
        workspace_dir=ws,
    )

    m = _read_manifest(rr.run_dir)
    assert m["action_id"] == "unit_profile"
    assert "profiling" in m, "profiling should be present when FLEXSOC_PROFILE=1"
    assert m["profiling"]["enabled"] is True
    t = m["profiling"]["t"]
    assert "subprocess_s" in t
    assert "manifest_write_s" in t
    assert "total_s" in t
    assert t["total_s"] >= 0


def test_runner_manifest_params_are_json_safe(tmp_path: Path):
    ws = tmp_path / "ws"

    params = {
        "path": Path("a/b/c"),
        "nested": {"x": Path("y")},
        "lst": [Path("p"), {"k": Path("q")}],
        "num": 123,
        "flag": True,
        "none": None,
    }

    rr = run_command(
        action_id="unit_params_json",
        cmd=[sys.executable, "-c", "print('ok')"],
        params=params,
        workspace_dir=ws,
    )

    m = _read_manifest(rr.run_dir)

    # Ensure params survived JSON serialization and paths became strings
    mp = m["params"]
    assert mp["path"] == "a/b/c"
    assert mp["nested"]["x"] == "y"
    assert mp["lst"][0] == "p"
    assert mp["lst"][1]["k"] == "q"
    assert mp["num"] == 123
    assert mp["flag"] is True
    assert mp["none"] is None
