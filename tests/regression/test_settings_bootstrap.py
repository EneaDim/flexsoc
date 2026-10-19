"""A populated workspace can still be configured explicitly and safely."""
import json
from pathlib import Path
import pytest
from flexsoc.cli import app
from flexsoc.backend.core.flow.session import WorkspaceFlow


def test_populated_workspace_bootstrap(tmp_path: Path, capsys):
    work = tmp_path / "ethernet_l2_07"
    (work / "runs" / "scaffold_single_clock" / "single_tlul").mkdir(parents=True)
    assert app(["settings", "--project-root", str(tmp_path), "--workdir", str(work),
                "TOP=ethernet", "RUN_TOP=ethernet", "RUN_ID=ethernet_l2_07",
                "IP_NAME=ethernet", "IP_VERSION=0.1.0", "REG_ITF=tlul",
                "CLOCK_DOMAINS=core:clk_i:rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low",
                "--json"]) == 0
    values = json.loads((work / ".flexsoc" / "settings.json").read_text())
    assert values["IP_VERSION"] == "0.1.0"
    assert values["N_CLOCKS"] == "2"
    assert values["RUN_ID"] == "ethernet_l2_07"
    assert json.loads(capsys.readouterr().out)["RUN_ROOT"].endswith("runs/ethernet/ethernet_l2_07")


def test_missing_settings_still_fail_closed(tmp_path: Path):
    work = tmp_path / "old"
    (work / "runs" / "old").mkdir(parents=True)
    with pytest.raises(FileNotFoundError, match="workspace settings missing"):
        WorkspaceFlow.read_settings(tmp_path, work)
