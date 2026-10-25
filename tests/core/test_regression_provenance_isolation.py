"""RTL regression must not depend on model-only outputs or aggregate indexes."""

from pathlib import Path
from types import SimpleNamespace

from flexsoc.backend.core.flow.lifecycle import STAGE_CONTRACTS
from flexsoc.backend.core.flow.provenance import Provenance
from flexsoc.backend.core.flow.session import TargetSession


def test_model_execution_does_not_invalidate_rtl_regression(tmp_path: Path) -> None:
    rtl = tmp_path / "rtl" / "uart.sv"
    sdc = tmp_path / "constraints" / "uart.sdc"
    tests = tmp_path / "dv" / "functional" / "tests"
    py = tmp_path / "dv" / "functional" / "py"
    model_results = py / "model" / "results" / "summary.json"
    aggregate = tmp_path / "dv" / "functional" / "summary.json"
    generator = py / "rtl" / "uart_tests.py"
    regression = tmp_path / "dv" / "functional" / "regression" / "summary.json"
    for path in (rtl, sdc, tests / "smoke" / "vectors.txt", generator, regression):
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("initial\n")

    session = TargetSession.__new__(TargetSession)
    session.paths = SimpleNamespace(sdc=sdc, tests=tests, py=py)
    session.context = SimpleNamespace(rtl_contract=SimpleNamespace(filelists=(rtl,), sources=lambda: (rtl,)))
    session._execution_inputs = lambda stage: ()

    inputs = session._provenance_inputs("regression")
    store = Provenance(tmp_path / "meta" / "provenance.json", tmp_path)
    store.record("regression", inputs=inputs, generated=(regression,), config={})
    assert store.state("regression", inputs=inputs, config={}) == "CLEAN"

    model_results.parent.mkdir(parents=True, exist_ok=True)
    model_results.write_text('{"status": "PASS"}\n')
    aggregate.write_text('{"stages": {"model_tests": "PASS"}}\n')
    assert store.state("regression", inputs=session._provenance_inputs("regression"), config={}) == "CLEAN"
    assert "dv/functional/summary.json" not in STAGE_CONTRACTS["regression"].owned_outputs

    generator.write_text("modified generator\n")
    assert store.state("regression", inputs=session._provenance_inputs("regression"), config={}) == "STALE"
