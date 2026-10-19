"""A multi-source TX clock must remain a blocking glitch until proven safe."""
from dataclasses import replace
from flexsoc.backend.core import ClockDomain
from flexsoc.backend.dv.lint.cdc import CdcFlow, DesignIR, SequentialElement


def _ir(kind="$mux", second=2):
    ports = {
        "gtx_clk": {"direction": "input", "bits": [1]},
        "mii_clk": {"direction": "input", "bits": [2]},
        "mode": {"direction": "input", "bits": [4]},
    }
    cells = {"tx_mux": {
        "type": kind,
        "port_directions": {"A": "input", "B": "input", "S": "input", "Y": "output"},
        "connections": {"A": [1], "B": [second], "S": [4], "Y": [33]},
    }}
    return DesignIR("ethernet", (
        ClockDomain("gtx", "gtx_clk", "rst", 8.0),
        ClockDomain("mii", "mii_clk", "rst", 40.0),
    ), (), (SequentialElement("tx", "$dff", 33, None, (41,), (42,)),),
        {"ports": ports, "cells": cells, "netnames": {}})


def test_mux_evidence_uses_both_clock_sources():
    evidence = CdcFlow._clock_mux_evidence(_ir(), 33)
    assert "clock_mux=tx_mux" in evidence
    assert "clock_mux_inputs=gtx_clk,mii_clk" in evidence
    assert "clock_mux_select=mode" in evidence
    assert "clock_mux_switch_safety=unproven" in evidence


def test_mux_remains_error_and_demands_proof():
    findings = CdcFlow._check_glitches(_ir())
    assert len(findings) == 1
    assert findings[0].status == "ERROR"
    assert findings[0].classification == "combinational_clock_path"
    assert "prove_clock_switch_glitch_free_or_use_qualified_clock_mux" in findings[0].obligations


def test_non_mux_logic_never_claims_clock_mux_proof():
    ir = _ir(kind="$and")
    assert CdcFlow._clock_mux_evidence(ir, 33) == ()
    findings = CdcFlow._check_glitches(ir)
    assert len(findings) == 1 and findings[0].status == "ERROR"
    assert not findings[0].obligations


def test_same_clock_mux_not_misclassified_as_two_clock_mux():
    ir = _ir(second=1)
    assert CdcFlow._clock_mux_evidence(ir, 33) == ()
    assert CdcFlow._check_glitches(ir)[0].status == "ERROR"


def test_internal_selection_still_requires_proof():
    ir = _ir()
    module = dict(ir.module)
    cells = {name: dict(cell) for name, cell in module["cells"].items()}
    cells["tx_mux"]["connections"] = dict(cells["tx_mux"]["connections"], S=[54])
    module["cells"] = cells
    changed = replace(ir, module=module)
    evidence = CdcFlow._clock_mux_evidence(changed, 33)
    assert "clock_mux_select=internal" in evidence
    assert CdcFlow._check_glitches(changed)[0].status == "ERROR"
