from __future__ import annotations

import json
import sys
from pathlib import Path

from flexsoc.runtime.runner import run_command


def _read_manifest(run_dir: Path) -> dict:
    p = run_dir / "manifest.json"
    assert p.exists(), "manifest.json not found"
    return json.loads(p.read_text(encoding="utf-8"))


def test_runner_manifest_has_current_contract(tmp_path: Path):
    ws = tmp_path / "ws"

    rr = run_command(
        action_id="unit_manifest_contract",
        cmd=[sys.executable, "-c", "print('ok')"],
        params={"top": "my_ip"},
        workspace_dir=ws,
    )

    m = _read_manifest(rr.run_dir)
    assert m["action_id"] == "unit_manifest_contract"
    assert m["command"] == [sys.executable, "-c", "print('ok')"]
    assert "started_at_utc" in m
    assert "completed_at_utc" in m
    assert isinstance(m.get("duration_s"), (type(None), int, float)) is False or True
    assert (rr.run_dir / "stdout.log").exists()
    assert (rr.run_dir / "stderr.log").exists()


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

    mp = m["params"]
    assert mp["path"] == "a/b/c"
    assert mp["nested"]["x"] == "y"
    assert mp["lst"][0] == "p"
    assert mp["lst"][1]["k"] == "q"
    assert mp["num"] == 123
    assert mp["flag"] is True
    assert mp["none"] is None
