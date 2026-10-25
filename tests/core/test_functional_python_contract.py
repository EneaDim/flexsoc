"""Four-IP functional Python layout, executable model tests and vector stability."""

from __future__ import annotations

import json
import shutil
from pathlib import Path

import pytest

from flexsoc.backend.design.ip.model import ModelFlow
from flexsoc.backend.dv.func.functional import FunctionalFlow


REPO = Path(__file__).resolve().parents[2]
IP_VARIANTS = [
    (name, interface)
    for name in ("gpio", "uart", "rv_timer", "uart_master")
    for interface in (("tlul",) if name == "uart_master" else ("tlul", "reg_iface", "axi_lite"))
]


def _package(name: str, interface: str) -> Path:
    return REPO / "hw" / "ips" / name / "1.0.0" / "interfaces" / interface / "dv" / "functional"


@pytest.mark.parametrize("name,interface", IP_VARIANTS)
def test_ip_python_and_vectors(name: str, interface: str, tmp_path: Path) -> None:
    """Every generator consumes its Python package and regenerates identical RTL collateral."""

    source = _package(name, interface)
    assert not tuple((source / "model").glob("*.py"))
    py = source / "py"
    model, rtl = py / "model", py / "rtl"
    assert (model / "scenarios.py").is_file()
    assert (model / f"{name}_model.py").is_file()
    assert (model / f"{name}_model_tests.py").is_file()
    assert (rtl / f"{name}_tests.py").is_file()
    assert (rtl / f"{name}_regmap_tests.py").is_file()
    assert (rtl / f"{name}_regmap.py").is_file()
    functional = tmp_path / "dv" / "functional"
    shutil.copytree(py, functional / "py", ignore=shutil.ignore_patterns("__pycache__", "*.pyc"))
    flow = FunctionalFlow()
    generated = functional / "tests"
    flow.setup_tests(generated, name)
    assert flow.check_tests(generated, name)["ok"]
    for produced in generated.glob("*/*"):
        baseline = source / "tests" / produced.relative_to(generated)
        assert baseline.is_file(), f"missing baseline for {name}/{interface}: {produced.name}"
        assert produced.read_bytes() == baseline.read_bytes(), str(produced)


@pytest.mark.parametrize("name,interface", IP_VARIANTS)
def test_model_evidence_and_index(name: str, interface: str, tmp_path: Path) -> None:
    """Test outcomes come from pytest, and the functional index cannot pretend RTL ran."""

    source = _package(name, interface)
    functional = tmp_path / "dv" / "functional"
    output = functional / "model_tests"
    result = FunctionalFlow().run_model_tests(
        model_dir=source / "py" / "model", top=name, output_dir=output,
        log_dir=tmp_path / "logs" / "dv" / "functional" / "model_tests",
    )
    assert result["status"] == "PASS"
    assert result["cases"] and set(result["cases"].values()) == {"PASS"}
    assert (output / "junit.xml").is_file()
    assert (tmp_path / "logs/dv/functional/model_tests/model_tests.log").is_file()
    index = json.loads((functional / "summary.json").read_text())
    assert index["status"] == "PARTIAL"
    assert index["stages"]["model_tests"]["status"] == "PASS"
    assert index["stages"]["regression"]["status"] == "NOT_RUN"
    assert index["stages"]["coverage"]["status"] == "NOT_RUN"
    assert (output / "summary.json").is_file()


def test_new_ip_scaffold_is_explicitly_unqualified(tmp_path: Path) -> None:
    """Generic template provides IDs but no fabricated known-answer model PASS."""

    directory = tmp_path / "py"
    directory.mkdir()
    (directory / "scenarios.py").write_text(ModelFlow._scenarios_text("demo"))
    (directory / "demo_model_tests.py").write_text(ModelFlow._model_tests_text("demo"))
    (directory / "demo_model.py").write_text('"""Test model scaffold."""\n')
    result = FunctionalFlow().run_model_tests(model_dir=directory, top="demo", output_dir=tmp_path / "dv/functional/model_tests")
    assert result["status"] == "NOT_RUN"
    assert result["cases"] == {"smoke": "NOT_RUN", "corners": "NOT_RUN", "random_seed_1": "NOT_RUN", "random_seed_2": "NOT_RUN", "reconfig": "NOT_RUN"}


def test_aggregated_stage_pass_never_implies_qualification(tmp_path: Path) -> None:
    """The functional index cannot validate cross-stage provenance on its own."""
    functional = tmp_path / "dv" / "functional"
    for stage in ("model_tests", "regression", "coverage"):
        directory = functional / stage
        directory.mkdir(parents=True)
        (directory / "summary.json").write_text('{"status":"PASS"}\n')
    result = FunctionalFlow.refresh_summary(functional)
    assert result["status"] == "REVIEW_REQUIRED"
    assert all(s["status"] == "PASS" for s in result["stages"].values())
