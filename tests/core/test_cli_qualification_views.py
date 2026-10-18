"""Qualification CLI views must read stored PDK reports, not signoff post_syn."""

from __future__ import annotations

import json
from pathlib import Path

from flexsoc.cli import app


def _args(tmp_path: Path) -> tuple[list[str], Path]:
    work = tmp_path / "workspace"
    path = work / "runs/rv_timer/l2/meta/sky130/qualification.json"
    return [
        "--project-root", str(tmp_path), "--workdir", str(work),
        "--set", "TOP=rv_timer", "--set", "RUN_TOP=rv_timer",
        "--set", "RUN_ID=l2", "--set", "PDK=sky130",
    ], path


def _report() -> dict:
    return {
        "ip": "rv_timer", "reg_interface": "reg_iface", "pdk": "sky130",
        "maximum_level": 2, "maximum_qualification": "RTL Qualified",
        "qualification_status": "PASS",
        "requirements": {"covered": 11, "total": 11, "status": "PASS"},
        "levels": {
            "1": {"name": "Contract Valid", "status": "PASS", "blocking_evidence": []},
            "2": {"name": "RTL Qualified", "status": "PASS", "blocking_evidence": []},
            "3": {"name": "Netlist Qualified", "status": "BLOCKED", "blocking_evidence": ["syn", "sta"]},
        },
        "evidence": {"regression": "PASS", "syn": "MISSING"},
    }


def test_qualification_summary_show_and_json_use_recorded_report(tmp_path: Path, capsys) -> None:
    args, path = _args(tmp_path)
    path.parent.mkdir(parents=True)
    path.write_text(json.dumps(_report()), encoding="utf-8")
    before = path.read_bytes()

    assert app(["qualify", "--summary", *args]) == 0
    output = capsys.readouterr().out
    assert "L2 RTL Qualified" in output and "L2=PASS" in output
    assert "L3=BLOCKED" in output and "post_syn" not in output

    assert app(["qualify", "--show", *args]) == 0
    output = capsys.readouterr().out
    assert "Qualification" in output and "regression" in output

    assert app(["qualify", "--summary", "--json", *args]) == 0
    result = json.loads(capsys.readouterr().out)
    assert result["maximum_level"] == 2 and result["levels"]["2"] == "PASS"
    assert result["levels"]["3"] == "BLOCKED"
    assert result["pdk"] == "sky130" and result["source"] == str(path)

    assert app(["qualify", "--show", "--json", *args]) == 0
    assert json.loads(capsys.readouterr().out) == _report()
    assert path.read_bytes() == before  # No writes, no EDA.


def test_qualification_summary_missing_and_invalid_artifacts(tmp_path: Path, capsys) -> None:
    args, path = _args(tmp_path)
    assert app(["qualify", "--summary", *args]) == 2
    assert "qualification.json" in capsys.readouterr().err

    path.parent.mkdir(parents=True)
    for bad in (
        {**_report(), "pdk": "ihp-sg13g2"},
        {**_report(), "maximum_level": 4},
        {**_report(), "levels": {}},
        {**_report(), "maximum_level": "garbage"},
    ):
        path.write_text(json.dumps(bad), encoding="utf-8")
        assert app(["qualify", "--summary", *args]) == 2
        capsys.readouterr()
