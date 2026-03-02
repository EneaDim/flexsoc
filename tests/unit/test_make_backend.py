from __future__ import annotations

import json
import sys
from pathlib import Path

from flexsoc.runner import MakeBackend


def test_make_backend_creates_logs_and_manifest(tmp_path: Path):
    ws = tmp_path / "ws"
    backend = MakeBackend()

    br = backend.run(
        action_id="unit_backend",
        cmd=[sys.executable, "-c", "print('hello')"],
        params={"k": "v"},
        workspace_dir=ws,
    )

    assert br.run_dir.exists()
    assert br.stdout_log.exists()
    assert br.stderr_log.exists()

    manifest_path = br.run_dir / "manifest.json"
    assert manifest_path.exists()

    m = json.loads(manifest_path.read_text(encoding="utf-8"))
    assert m["action_id"] == "unit_backend"
    assert m["exit_code"] == 0
