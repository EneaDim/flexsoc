from __future__ import annotations

import json
from pathlib import Path

from flexsoc.runtime.reporting import parse_action_flow, postprocess_action


def test_parse_action_flow_reads_stage_logs(tmp_path: Path):
    flow_dir = tmp_path / "workspace" / "runs" / "demo" / "dev1"
    logs_dir = flow_dir / "logs"
    logs_dir.mkdir(parents=True, exist_ok=True)

    (logs_dir / "demo_sta_opt_fast.log").write_text(
        "OpenSTA report\nWarning: minor thing\nERROR: timing failed\n",
        encoding="utf-8",
    )

    rep = parse_action_flow(
        flow_run_dir=flow_dir,
        action="make:sta",
        runner_dir=None,
    )

    assert rep.action == "make:sta"
    assert rep.ok is False
    assert rep.errors >= 1
    assert rep.warnings >= 1
    assert rep.summary["matched_file_count"] == 1
    assert rep.summary["has_opensta"] is True


def test_postprocess_action_falls_back_to_runner_logs(tmp_path: Path):
    flow_dir = tmp_path / "workspace" / "runs" / "demo" / "dev2"
    runner_dir = tmp_path / "workspace" / "sessions" / "123_make_sim"

    flow_dir.mkdir(parents=True, exist_ok=True)
    runner_dir.mkdir(parents=True, exist_ok=True)

    (runner_dir / "stdout.log").write_text("Compiling...\n", encoding="utf-8")
    (runner_dir / "stderr.log").write_text("ERROR: compile failed\n", encoding="utf-8")

    postprocess_action(
        action="make:sim",
        flow_run_dir=flow_dir,
        runner_dir=runner_dir,
    )

    report = json.loads((flow_dir / "report.json").read_text(encoding="utf-8"))
    assert report["action"] == "make:sim"
    assert report["ok"] is False
    assert report["errors"] >= 1
    assert report["summary"]["matched_file_count"] >= 1
