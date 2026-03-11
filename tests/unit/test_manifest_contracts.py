from __future__ import annotations

import json
from pathlib import Path

from flexsoc.manifest import read_run_manifest, update_runner_manifest, write_flow_manifest, write_run_manifest
from flexsoc.workspace import resolve_run_ref


def test_run_manifest_roundtrip_and_linkage(tmp_path: Path):
    ws = tmp_path / "workspace"
    ws.mkdir(parents=True, exist_ok=True)

    run_ref = resolve_run_ref(
        workspace=ws,
        top="demo_top",
        run_top="demo_top",
        run_id="dev",
    )
    assert run_ref is not None

    session_dir = ws / "sessions" / "20260310_120000_demo"
    session_dir.mkdir(parents=True, exist_ok=True)

    write_run_manifest(
        run_ref,
        action="make:sim",
        params={"target": "sim"},
        top="demo_top",
        session_dir=session_dir,
    )

    data = read_run_manifest(run_ref.run_dir)
    assert data["run_top"] == "demo_top"
    assert data["run_id"] == "dev"
    assert data["top"] == "demo_top"
    assert data["last_action"] == "make:sim"
    assert data["last_session_dir"] == str(session_dir)
    assert data["last_session_action"] == "make:sim"
    assert isinstance(data["loaded_ips"], list)
    assert isinstance(data["params"], dict)


def test_update_runner_manifest_and_flow_manifest_link(tmp_path: Path):
    ws = tmp_path / "workspace"
    session_dir = ws / "sessions" / "20260310_120001_make_sim"
    flow_dir = ws / "runs" / "demo_top" / "dev"

    session_dir.mkdir(parents=True, exist_ok=True)
    (session_dir / "manifest.json").write_text(json.dumps({"action_id": "make_sim"}) + "\n", encoding="utf-8")

    update_runner_manifest(
        session_dir,
        {
            "flow_run_dir": str(flow_dir),
            "run_top": "demo_top",
            "run_id": "dev",
        },
    )

    runner_data = json.loads((session_dir / "manifest.json").read_text(encoding="utf-8"))
    assert runner_data["flow_run_dir"] == str(flow_dir)
    assert runner_data["run_top"] == "demo_top"
    assert runner_data["run_id"] == "dev"

    write_flow_manifest(
        flow_dir,
        action="make:sim",
        top="demo_top",
        run_id="dev",
        workspace=ws,
        params={"target": "sim"},
        runner_session_dir=session_dir,
        runner_action_id="make_sim",
    )

    flow_data = json.loads((flow_dir / "manifest.json").read_text(encoding="utf-8"))
    assert flow_data["runner_session_dir"] == str(session_dir)
    assert flow_data["runner_action_id"] == "make_sim"
