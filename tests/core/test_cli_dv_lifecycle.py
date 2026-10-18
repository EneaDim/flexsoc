"""Short CLI model-test/trace lifecycle: views never execute pytest implicitly."""

from __future__ import annotations

import json
import shutil
from pathlib import Path

from flexsoc.cli import app


REPO = Path(__file__).resolve().parents[2]


def _gpio_package(destination: Path) -> Path:
    source = REPO / "hw/ips/gpio/1.0.0"
    shutil.copytree(source / "spec", destination / "spec")
    shutil.copytree(source / "interfaces/tlul/dv/functional/py", destination / "interfaces/tlul/dv/functional/py")
    return destination


def test_short_model_test_execution_views_and_stale_check(tmp_path: Path, capsys) -> None:
    source = _gpio_package(tmp_path / "gpio")
    workdir = tmp_path / "workspace"
    args = [str(source), "--set", "REG_ITF=tlul", "--workdir", str(workdir)]
    assert app(["trace", *args, "--summary"]) == 0
    assert app(["traceability", *args, "--summary"]) == 0  # Existing scripts.
    assert app(["model_tests", *args, "--summary"]) == 0
    assert app(["mtest", *args, "--summary"]) == 0
    assert app(["mtest", *args, "--check"]) == 1  # Never ran.
    assert app(["mtest", *args]) == 0
    report = workdir / "model_tests/gpio/tlul/summary.json"
    before = report.read_bytes()
    assert json.loads(before)["status"] == "PASS"
    assert app(["mtest", *args, "--check"]) == 0
    assert app(["mtest", *args, "--summary"]) == 0
    assert app(["mtest", *args, "--show"]) == 0
    assert app(["trace", *args, "--show"]) == 0
    assert report.read_bytes() == before  # Read-only view and freshness check.
    scenario = source / "interfaces/tlul/dv/functional/py/scenarios.py"
    scenario.write_text(scenario.read_text(encoding="utf-8") + "\n# deliberate changed input\n", encoding="utf-8")
    assert app(["mtest", *args, "--check"]) == 1
    assert "STALE" in capsys.readouterr().out
    assert report.read_bytes() == before  # A stale check never rewrites evidence.
    assert app(["mtest", *args]) == 0
    assert app(["mtest", *args, "--check"]) == 0


def test_setup_preserves_authored_tests_and_rejects_package_edits(tmp_path: Path) -> None:
    workdir = tmp_path / "workspace"
    run = workdir / "runs/gpio/dev"
    _gpio_package(run)
    src = run / "interfaces/tlul/dv/functional/py"
    dest = run / "dv/functional/py"
    shutil.copytree(src, dest)
    shutil.rmtree(run / "interfaces")
    (dest / "gpio_model_tests.py").unlink()
    (dest / "scenarios.py").unlink()
    args = ["--set", "TOP=gpio", "--set", "RUN_TOP=gpio", "--set", "RUN_ID=dev", "--workdir", str(workdir)]
    assert app(["mtest", "--setup", *args]) == 0
    tests = dest / "gpio_model_tests.py"
    assert tests.is_file() and (dest / "scenarios.py").is_file()
    tests.write_text("# authored\n", encoding="utf-8")
    assert app(["mtest", "--setup", *args]) == 0
    assert tests.read_text() == "# authored\n"
    assert app(["mtest", "--setup", "--force", *args]) == 2
    package = _gpio_package(tmp_path / "package")
    assert app(["mtest", "--setup", str(package), "--workdir", str(workdir)]) == 2


def test_short_command_help_and_listing(capsys) -> None:
    for name in ("mtest", "trace", "validate"):
        assert app(["help", name]) == 0
    assert app(["commands", "--json"]) == 0
    out = capsys.readouterr().out
    for value in ('"name": "trace"', '"name": "mtest"', '"name": "validate"'):
        assert value in out
