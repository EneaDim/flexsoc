"""Regression guard: blocking CSR operations must advance the SV vector cursor."""

from __future__ import annotations

import pytest

from flexsoc.backend.core import ClockConfig
from flexsoc.backend.dv.tb.sv import SystemVerilogTestbench


@pytest.mark.parametrize("clock_spec", (
    {"N_CLOCKS": "1", "CLOCK_DOMAINS": "core:clk_i:rst_ni:10:low"},
    {"N_CLOCKS": "3", "CLOCK_DOMAINS": (
        "core:clk_i:rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:16:low,"
        "dsp:dsp_clk_i:dsp_rst_ni:20:low"
    )},
))
def test_cycle_vectors_account_for_blocking_register_operations(clock_spec):
    clocks = ClockConfig.from_values(clock_spec)
    signature = {
        "ports_in": [("clk_i", "1"), ("rst_ni", "1"), ("data_i", "32"), ("valid_i", "1")],
        "ports_out": [("data_o", "32"), ("valid_o", "1")],
    }
    driver = SystemVerilogTestbench.render_vec_driver("demo", clocks, signature, "axi_lite")
    monitor = SystemVerilogTestbench.render_vec_monitor("demo", clocks, signature, "axi_lite")
    assert "always @(posedge clk_i) tb_vector_clock_edges++" in driver
    assert "now_cycle += tb_vector_clock_edges - bus_start_edges;" in driver
    assert "now_cycle += tb_vector_clock_edges - bus_start_edges;" in monitor
    assert driver.count("now_cycle += tb_vector_clock_edges - bus_start_edges;") == 4  # 2 parser variants x cfg/write
    assert monitor.count("now_cycle += tb_vector_clock_edges - bus_start_edges;") == 2  # 2 parser variants
    assert 'if (t0 == "@reset"' in driver


def test_stream_vector_templates_unchanged():
    # Stream-handshake IPs take a separate template path; do not touch their semantics.
    from pathlib import Path
    root = Path(__file__).resolve().parents[2]
    templates = root / "src/flexsoc/templates/dv/sv/drivers"
    assert "tb_vector_clock_edges" not in (templates / "vec_driver_stream.svh.j2").read_text()
    assert "tb_vector_clock_edges" not in (templates / "vec_monitor_stream.svh.j2").read_text()
