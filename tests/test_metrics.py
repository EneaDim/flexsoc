"""Focused contracts for machine-readable run metrics."""

from __future__ import annotations

from pathlib import Path

from flexsoc.backend.metrics import collect_formal, formal_stage, status_word


def _write_formal_stage(run: Path, top: str, suite: str, stage: str) -> None:
    formal = run / "dv" / "formal" / "runs"
    logs = run / "logs" / "dv" / "formal"
    if suite == "csr":
        category = "cover" if stage == "cover" else "prove"
        workdir = formal / "csr" / category / f"{top}_csr_{stage}"
        log = logs / "csr" / f"{top}_{stage}.log"
    else:
        category = "cover" if stage == "cover" else "prove"
        workdir = formal / "properties" / category / f"{top}_{stage}"
        log = logs / "properties" / f"{top}_{stage}.log"
    workdir.mkdir(parents=True, exist_ok=True)
    log.parent.mkdir(parents=True, exist_ok=True)
    (workdir / "status").write_text("PASS\n", encoding="utf-8")
    (workdir / "trace0.vcd").write_text("$enddefinitions $end\n", encoding="utf-8")
    log.write_text("DONE (PASS)\nElapsed clock time [00:00:03] (3)\n", encoding="utf-8")


def test_status_word_prefers_persisted_tool_result(tmp_path: Path) -> None:
    status = tmp_path / "status"
    log = tmp_path / "run.log"
    status.write_text("PASS\n", encoding="utf-8")
    log.write_text("informational ERROR counter: 0\n", encoding="utf-8")

    assert status_word(status, log) == "pass"


def test_formal_stage_collects_status_elapsed_and_trace(tmp_path: Path) -> None:
    run = tmp_path / "run"
    workdir = run / "dv/formal/runs/properties/prove/demo_prove"
    log = run / "logs/dv/formal/properties/demo_prove.log"
    workdir.mkdir(parents=True)
    log.parent.mkdir(parents=True)
    (workdir / "status").write_text("PASS\n", encoding="utf-8")
    (workdir / "trace0.vcd").write_text("trace\n", encoding="utf-8")
    log.write_text("Elapsed clock time [00:00:09] (9)\n", encoding="utf-8")

    data = formal_stage(run, workdir, log)

    assert data == {
        "status": "pass",
        "workdir": "dv/formal/runs/properties/prove/demo_prove",
        "log": "logs/dv/formal/properties/demo_prove.log",
        "trace_count": 1,
        "elapsed_s": 9,
        "traces": ["dv/formal/runs/properties/prove/demo_prove/trace0.vcd"],
    }


def test_collect_formal_reports_all_six_stages(tmp_path: Path) -> None:
    run = tmp_path / "run"
    top = "demo"
    for suite in ("csr", "properties"):
        for stage in ("bmc", "prove", "cover"):
            _write_formal_stage(run, top, suite, stage)

    data = collect_formal(top, run)

    assert data is not None
    assert data["status"] == "pass"
    assert data["summary"] == {
        "passed": 6,
        "observed": 6,
        "total": 6,
        "elapsed_s": 18,
        "traces": 6,
        "stages": {
            "bmc": {"passed": 2, "total": 2},
            "prove": {"passed": 2, "total": 2},
            "cover": {"passed": 2, "total": 2},
        },
    }
