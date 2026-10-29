"""Cycle-vector epoch is shared across CSR protocols without touching stream TBs.

These are generator-contract tests. Simulator-level signoff remains external.
"""
from __future__ import annotations

import pytest

from flexsoc.backend.core import ClockConfig
from flexsoc.backend.dv.tb.common import TestbenchModel
from flexsoc.backend.dv.tb.cocotb import CocotbTestbench
from flexsoc.backend.dv.tb.sv import SystemVerilogTestbench


@pytest.fixture(params=("tlul", "reg_iface", "axi_lite"))
def interface(request):
    return request.param


@pytest.fixture(params=("single", "multi"))
def topology(request):
    if request.param == "single":
        return ClockConfig.from_values({
            "N_CLOCKS": "1", "CLOCK_DOMAINS": "core:clk_i:rst_ni:10:low",
        })
    return ClockConfig.from_values({
        "N_CLOCKS": "3", "CLOCK_DOMAINS": (
            "cfg:cfg_clk_i:cfg_rst_ni:20:low,"
            "rx:rx_clk_i:rx_rst_ni:16:low,"
            "dsp:dsp_clk_i:dsp_rst_ni:30:low"
        ),
        "CLOCK_RELATIONSHIPS": "async:cfg:rx,async:cfg:dsp,async:rx:dsp",
    })


def _signature(interface, clocks, *, stream=False):
    buses = {
        "tlul": (("tl_i", "[108:0]"), ("tl_o", "[65:0]")),
        "reg_iface": (("reg_req_i", "demo_reg_pkg::reg_req_t"),
                      ("reg_rsp_o", "demo_reg_pkg::reg_rsp_t")),
        "axi_lite": (("axi_lite_i", "demo_reg_pkg::axi_lite_req_t"),
                     ("axi_lite_o", "demo_reg_pkg::axi_lite_rsp_t")),
    }
    inputs = [(clock.signal, 1) for clock in clocks.domains]
    inputs += [(clock.reset, 1) for clock in clocks.domains]
    outputs = []
    for domain in (clocks.domains if len(clocks.domains) > 1 else clocks.domains[:1]):
        request, response = buses[interface]
        prefix = "" if len(clocks.domains) == 1 else f"{domain.name}_"
        # Register windows are discovered by suffix, not by protocol selection in the vector engine.
        inputs.append((prefix + request[0], request[1]))
        outputs.append((prefix + response[0], response[1]))
    if stream:
        inputs += [("feed_valid_i", 1), ("feed_payload_i", "[31:0]")]
        outputs += [("feed_ready_o", 1)]
    else:
        inputs += [("data_i", "[31:0]"), ("valid_i", 1)]
        outputs += [("data_o", "[31:0]"), ("valid_o", 1)]
    return {"ports_in": inputs, "ports_out": outputs}


def test_cycle_phase_barrier_shared_for_all_register_interfaces(interface, topology):
    signature = _signature(interface, topology)
    transport = TestbenchModel.register_transport(interface, signature, topology)
    assert transport.name == interface
    assert len(transport.windows) == len(topology.domains)
    assert not TestbenchModel.uses_stream_handshake(signature, topology)

    driver = SystemVerilogTestbench.render_vec_driver("demo", topology, signature, interface)
    monitor = SystemVerilogTestbench.render_vec_monitor("demo", topology, signature, interface)
    tb_top = SystemVerilogTestbench.render_top("demo", topology, signature, interface)
    reg_driver = SystemVerilogTestbench.render_reg_driver(
        "demo", topology, signature, (), interface
    )
    py_driver = CocotbTestbench.render_vec_driver(topology, signature)
    py_monitor = CocotbTestbench.render_vec_monitor(topology, signature)
    py_reg_driver = CocotbTestbench.render_reg_driver(
        "demo", topology, signature, (), interface
    )
    py_wrapper = CocotbTestbench.render_wrapper(
        "demo", topology, signature, interface
    )
    py_test = CocotbTestbench.render_test("demo", topology)
    # Two SV parser variants are included in the generated file.
    barrier = "  tb_wait_sample_phase();\n  fork\n    run_input_vectors(input_path);"
    assert driver.count(barrier) == 2
    assert "task automatic run_output_vectors" in monitor
    assert "run_vectors(data_in_path, data_out_path);" in tb_top
    assert "module demo_tb" in py_wrapper
    assert "async def vector_test" in py_test
    assert "run_vectors(dut, cfg, data_in, data_out)" in py_test
    assert "task automatic apply_reg_masked" in reg_driver or "apply_reg_masked" in reg_driver
    assert "async def run_vectors" in py_driver
    compile(py_driver, "<cycle-driver>", "exec")
    compile(py_monitor, "<cycle-monitor>", "exec")
    compile(py_reg_driver, "<register-driver>", "exec")


def test_stream_handshake_remains_separate_for_all_register_interfaces(interface, topology):
    signature = _signature(interface, topology, stream=True)
    assert TestbenchModel.uses_stream_handshake(signature, topology)
    driver = SystemVerilogTestbench.render_vec_driver("demo", topology, signature, interface)
    assert "task automatic run_inputs" in driver
    assert "tb_wait_sample_phase();\n  fork\n    run_input_vectors" not in driver
    assert "task automatic run_input_vectors" not in driver
    py_driver = CocotbTestbench.render_vec_driver(topology, signature)
    assert "INPUT_STREAMS" in py_driver
    compile(py_driver, "<stream-driver>", "exec")
