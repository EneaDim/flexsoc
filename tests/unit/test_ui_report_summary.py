from __future__ import annotations

from pathlib import Path

from flexsoc.presentation.ui import print_runner_summary


def test_print_runner_summary_includes_report_when_present(tmp_path: Path, capsys):
    runner_dir = tmp_path / "sessions" / "s1"
    flow_dir = tmp_path / "runs" / "demo" / "dev1"

    runner_dir.mkdir(parents=True, exist_ok=True)
    flow_dir.mkdir(parents=True, exist_ok=True)

    (runner_dir / "stdout.log").write_text("", encoding="utf-8")
    (runner_dir / "stderr.log").write_text("", encoding="utf-8")
    (flow_dir / "report.json").write_text('{"ok": true}\n', encoding="utf-8")

    print_runner_summary(
        label="make sim",
        exit_code=0,
        runner_dir=runner_dir,
        flow_dir=flow_dir,
        command="flexsoc make sim --top demo --run-id dev1",
    )

    captured = capsys.readouterr()
    stderr = captured.err
    assert "Runner dir:" in stderr
    assert "Flow dir:" in stderr
    assert "Report:" in stderr
