"""Shared PHY reset must not be declared multiple times in generated testbenches."""
import pytest

from flexsoc.backend.core import ClockConfig, ClockDomain
from flexsoc.backend.dv.tb.common import TestbenchModel
from flexsoc.backend.dv.tb.sv import SystemVerilogTestbench
from flexsoc.backend.dv.tb.cocotb import CocotbTestbench


def ethernet_clocks():
    return ClockConfig(domains=(
        ClockDomain("core", "clk_i", "rst_ni", 10, "low"),
        ClockDomain("gtx", "phy_gtx_clk_i", "phy_rst_i", 8, "high"),
        ClockDomain("gmii_rx", "phy_gmii_rx_clk_i", "phy_rst_i", 8, "high"),
        ClockDomain("mii_tx", "phy_mii_tx_clk_i", "phy_rst_i", 40, "high"),
    ))


def test_shared_reset_declarations_unique():
    decls = TestbenchModel.render_clock_reset_declarations(ethernet_clocks())
    assert decls.count("logic phy_rst_i;") == 1
    assert decls.count("logic rst_ni;") == 1
    assert len([line for line in decls.splitlines() if "logic" in line]) == 6


def test_inconsistent_polarity_rejected():
    clocks = ClockConfig(domains=(
        ClockDomain("a", "a_clk", "rst", 10, "high"),
        ClockDomain("b", "b_clk", "rst", 20, "low"),
    ))
    with pytest.raises(ValueError, match="inconsistent polarities"):
        TestbenchModel.render_clock_reset_declarations(clocks)


def test_clock_reset_collision_rejected():
    clocks = ClockConfig(domains=(
        ClockDomain("a", "a_clk", "rst", 10),
        ClockDomain("b", "rst", "b_rst", 20),
    ))
    with pytest.raises(ValueError, match="both clock and reset"):
        TestbenchModel.render_clock_reset_declarations(clocks)


def test_generator_uses_shared_renderer():
    import inspect
    for generator in (SystemVerilogTestbench.render_top, CocotbTestbench.render_wrapper):
        assert "render_clock_reset_declarations" in inspect.getsource(generator)
