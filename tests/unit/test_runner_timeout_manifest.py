from __future__ import annotations

import json
import sys
from pathlib import Path

from flexsoc.runtime.runner import run_command


def test_runner_manifest_records_timeout(tmp_path: Path):
    ws = tmp_path / "ws"

    rr = run_command(
        action_id="unit_timeout",
        cmd=[sys.executable, "-c", "import time; time.sleep(2)"],
        params={"top": "demo"},
        workspace_dir=ws,
        timeout_s=1,
    )

    assert rr.exit_code == 124

    manifest = json.loads((rr.run_dir / "manifest.json").read_text(encoding="utf-8"))
    assert manifest["action_id"] == "unit_timeout"
    assert manifest["exit_code"] == 124
    assert manifest["timeout_s"] == 1
    assert "started_at_utc" in manifest
    assert "completed_at_utc" in manifest

    stderr_text = (rr.run_dir / "stderr.log").read_text(encoding="utf-8")
    assert "timed out" in stderr_text.lower()
