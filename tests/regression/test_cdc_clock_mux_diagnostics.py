"""Clock-mux diagnostics must never relax structural CDC/RDC gates."""
from flexsoc.backend.core import ClockConfig, ClockDomain
from flexsoc.backend.dv.lint.cdc import CdcFlow, DesignIR, SequentialElement


def _design(inputs):
    ports = {name: {"direction": "input", "bits": [bit]} for name, bit in inputs}
    ports["mux_select"] = {"direction": "input", "bits": [4]}
    module = {"ports": ports, "netnames": {}, "cells": {
        "mux": {"type": "$mux", "port_directions": {"A": "input", "B": "input", "S": "input", "Y": "output"},
                "connections": {"A": [1], "B": [2], "S": [4], "Y": [33]}}
    }}
    seq = SequentialElement("tx_reg", "$dff", 33, None, (6,), (7,), source="rtl/ethernet_tx.sv:407")
    clocks = (ClockDomain("gtx", "gtx_clk", "rst", 8.0), ClockDomain("mii", "mii_clk", "rst", 40.0))
    return DesignIR(top="demo", clocks=clocks, ports=(), sequential=(seq,), module=module)


def test_mux_clock_candidates_preserved_as_error():
    ir = _design((("gtx_clk", 1), ("mii_clk", 2)))
    from flexsoc.backend.dv.lint.cdc import CrossingAnalysis
    # Use full structural frontend for clock assignment and original gate reporting.
    domain_map = CdcFlow._clock_domain_map(ir.module, ClockConfig(ir.clocks))
    assert 33 not in domain_map
    assert CdcFlow._unassigned_clock_sources(ir, 33) == ("gtx_clk", "mii_clk")


def test_single_clock_path_reports_one_candidate():
    ir = _design((("gtx_clk", 1), ("unrelated_input", 2)))
    assert CdcFlow._unassigned_clock_sources(ir, 33) == ("gtx_clk",)


def test_unrelated_clocks_do_not_create_fake_candidates():
    ir = _design((("other_a", 1), ("other_b", 2)))
    assert CdcFlow._unassigned_clock_sources(ir, 33) == ()


def test_setup_gate_stays_error_with_mux_candidates():
    from unittest.mock import Mock
    ir = _design((("gtx_clk", 1), ("mii_clk", 2)))
    findings = CdcFlow._check_setup(ir, Mock(clock_crossings=(), reset_crossings=(), dependencies=()))
    affected = [item for item in findings if item.classification == "unassigned_clock_domain"]
    assert len(affected) == 1
    assert affected[0].status == "ERROR"
    assert "clock_candidates=gtx_clk,mii_clk" in affected[0].evidence
