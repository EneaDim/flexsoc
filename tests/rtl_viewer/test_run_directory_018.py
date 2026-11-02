"""A run path is enough to select existing RTL View artifacts and fx identity."""
from __future__ import annotations

import json
from pathlib import Path
import subprocess
import sys

import pytest

from flexsoc.cli import app
from flexsoc.backend.core.flow.session import WorkspaceFlow
from flexsoc.run_select import select_run


ROOT = Path(__file__).resolve().parents[2]


def sample_run(tmp_path):
    run = tmp_path / "workspace" / "runs" / "ethernet" / "rtlviewer_axi_lite"
    (run / "rtl").mkdir(parents=True)
    ast = run / "dv" / "slang_hier" / "ast.json"
    ast.parent.mkdir(parents=True)
    ast.write_text(json.dumps({"design": {"kind": "Root", "members": [{
        "kind": "Instance", "name": "ethernet",
        "body": {"kind": "InstanceBody", "name": "ethernet", "members": []},
    }]}}), encoding="utf-8")
    return run


def test_select_run_is_anchored_to_runs_directory(tmp_path):
    run = sample_run(tmp_path)
    workspace, settings = select_run(run)
    assert workspace == tmp_path / "workspace"
    assert settings == {"TOP": "ethernet", "RUN_TOP": "ethernet",
                        "RUN_ID": "rtlviewer_axi_lite", "WORKSPACE": str(workspace)}
    with pytest.raises(ValueError, match="expected a directory"):
        select_run(run / "rtl")
    unexpected = tmp_path / "arbitrary" / "runs" / "ghost" / "missing"
    unexpected.mkdir(parents=True)
    with pytest.raises(ValueError, match="no FlexSoC run artifacts"):
        select_run(unexpected)


def test_fx_settings_selects_run_and_preserves_other_settings(tmp_path, capsys):
    run = sample_run(tmp_path)
    workspace = run.parent.parent.parent
    WorkspaceFlow.write_settings(tmp_path, {"PDK": "ihp-sg13g2", "REG_ITF": "axi_lite",
                                                "N_CLOCKS": "2", "TOP": "old_ip"}, workspace)
    assert app(["settings", str(run), "--json", "--project-root", str(tmp_path)]) == 0
    displayed = json.loads(capsys.readouterr().out)
    assert displayed["RUN_ROOT"] == str(run)
    saved = json.loads(WorkspaceFlow.settings_path(tmp_path, workspace).read_text())
    assert (saved["TOP"], saved["RUN_TOP"], saved["RUN_ID"]) == (
        "ethernet", "ethernet", "rtlviewer_axi_lite")
    assert saved["PDK"] == "ihp-sg13g2"
    assert saved["REG_ITF"] == "axi_lite"
    assert saved["N_CLOCKS"] == "2"
    assert app(["settings", str(run), "--json", "--project-root", str(tmp_path)]) == 0
    capsys.readouterr()


def test_viewer_run_dir_uses_existing_ast_without_slang(tmp_path):
    run = sample_run(tmp_path)
    p = subprocess.run([sys.executable, str(ROOT / "scripts" / "rtl_viewer.py"),
                        "--run-dir", str(run), "--check"], text=True,
                       capture_output=True, timeout=25)
    assert p.returncode == 0, p.stdout + p.stderr
    report = json.loads(p.stdout)
    assert report["top"] == "ethernet"
    assert report["scopes"] == 1
    assert report["elaboration_verified"] is False


def test_viewer_run_dir_rejects_conflicting_options(tmp_path):
    run = sample_run(tmp_path)
    p = subprocess.run([sys.executable, str(ROOT / "scripts" / "rtl_viewer.py"),
                        "--run-dir", str(run), "--top", "wrong", "--check"],
                       text=True, capture_output=True, timeout=25)
    assert p.returncode != 0
    assert "conflicts" in p.stderr


def test_checkout_run_recovers_shared_compiler_source(tmp_path):
    """Only in-checkout runs automatically authorize the checkout as a source root."""
    import tempfile
    with tempfile.TemporaryDirectory(prefix='fsrtl019-', dir=ROOT) as base:
        run = Path(base) / 'workspace/runs/ethernet/shared_source'
        ast = run / 'dv/slang_hier/ast.json'
        ast.parent.mkdir(parents=True)
        shared = (ROOT / 'examples/rtl_schematic_dsp/DSP.sv').resolve()
        assert shared.is_file()
        ast.write_text(json.dumps({'design': {'members': [{
            'kind':'Instance', 'name':'ethernet',
            'body': {'kind':'InstanceBody', 'members': [{
                'kind':'Port', 'name':'clk_i', 'direction':'In',
                'source_file': str(shared), 'source_line': 1
            }]}
        }]}}))
        p = subprocess.run([sys.executable, str(ROOT / 'scripts/rtl_viewer.py'),
                            '--run-dir', str(run), '--check'], text=True,
                           capture_output=True, timeout=25)
        assert p.returncode == 0, p.stderr
        result = json.loads(p.stdout)
        assert result['totals']['missing_sources'] == 0
