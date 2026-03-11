from __future__ import annotations

import json
import sys
from pathlib import Path

from flexsoc.manifest import read_run_manifest
from flexsoc.orchestration import InvocationSpec, run_orchestrated
from flexsoc.workspace import resolve_run_ref


def test_run_orchestrated_writes_runner_and_flow_artifacts(tmp_path: Path):
    ws = tmp_path / "workspace"
    ws.mkdir(parents=True, exist_ok=True)

    run_ref = resolve_run_ref(
        workspace=ws,
        top="demo_ip",
        run_top="demo_ip",
        run_id="dev",
    )
    assert run_ref is not None

    result = run_orchestrated(
        InvocationSpec(
            action_id="unit_orchestrated",
            summary_label="unit orchestrated",
            cmd=[sys.executable, "-c", "print('hello from orchestrated path')"],
            params={"top": "demo_ip", "overwrite": "1"},
            workspace_dir=ws,
            run_ref=run_ref,
            manifest_action="unit:test",
            manifest_top="demo_ip",
            manifest_run_id="dev",
        )
    )

    assert result.backend.exit_code == 0
    assert result.backend.run_dir.exists()
    assert result.flow_run_dir == ws / "runs" / "demo_ip" / "dev"

    runner_manifest = result.backend.run_dir / "manifest.json"
    flow_manifest = result.flow_run_dir / "manifest.json"
    run_manifest = result.flow_run_dir / "run.yaml"

    assert runner_manifest.exists()
    assert flow_manifest.exists()
    assert run_manifest.exists()

    runner_data = json.loads(runner_manifest.read_text(encoding="utf-8"))
    flow_data = json.loads(flow_manifest.read_text(encoding="utf-8"))
    run_data = read_run_manifest(result.flow_run_dir)

    assert runner_data["action_id"] == "unit_orchestrated"
    assert runner_data["flow_run_dir"] == str(result.flow_run_dir)
    assert flow_data["action"] == "unit:test"
    assert flow_data["top"] == "demo_ip"
    assert flow_data["run_id"] == "dev"
    assert flow_data["runner_session_dir"] == str(result.backend.run_dir)
    assert run_data["last_session_dir"] == str(result.backend.run_dir)
