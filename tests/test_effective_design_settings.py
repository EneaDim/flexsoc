import json
from pathlib import Path

from flexsoc.backend.core.flow.session import DEFAULT_SETTINGS, WorkspaceFlow


def test_effective_settings_overlay_resolved_soc_plan(tmp_path: Path) -> None:
    work = tmp_path / "workspace"
    run = work / "runs" / "demo" / "dev"
    plan = run / "soc" / "plan.json"
    plan.parent.mkdir(parents=True)
    plan.write_text(
        json.dumps({"schema": 1, "host": "ibex", "fabric": "tlul", "devices": []}) + "\n",
        encoding="utf-8",
    )

    stored = {
        **DEFAULT_SETTINGS,
        "TOP": "demo",
        "RUN_TOP": "demo",
        "RUN_ID": "dev",
        "HOST": "uart",
    }

    effective = WorkspaceFlow.effective_settings(tmp_path, work, stored)

    assert effective["DESIGN"] == "soc"
    assert effective["HOST"] == "ibex"
    assert effective["FABRIC"] == "tlul"
    assert stored["HOST"] == "uart"


def test_effective_settings_preserve_ip_context_without_soc_plan(tmp_path: Path) -> None:
    work = tmp_path / "workspace"
    values = {
        **DEFAULT_SETTINGS,
        "TOP": "uart",
        "RUN_TOP": "uart",
        "RUN_ID": "dev",
        "HOST": "uart",
    }

    effective = WorkspaceFlow.effective_settings(tmp_path, work, values)

    assert "DESIGN" not in effective
    assert effective["HOST"] == "uart"


def test_effective_settings_reject_broken_soc_plan(tmp_path: Path) -> None:
    work = tmp_path / "workspace"
    plan = work / "runs" / "demo" / "dev" / "soc" / "plan.json"
    plan.parent.mkdir(parents=True)
    plan.write_text('{"schema": 1, "host": "ibex"}\n', encoding="utf-8")

    values = {
        **DEFAULT_SETTINGS,
        "TOP": "demo",
        "RUN_TOP": "demo",
        "RUN_ID": "dev",
    }

    try:
        WorkspaceFlow.effective_settings(tmp_path, work, values)
    except ValueError as exc:
        assert "host/fabric" in str(exc)
    else:
        raise AssertionError("broken resolved SoC design state must fail")
