"""General clock/reset generation and simplified clock settings."""
from flexsoc.backend.core import ClockConfig
from flexsoc.backend.dv.tb.common import TestbenchModel
from flexsoc.backend.dv.tb.sv import SystemVerilogTestbench
import pytest


def cfg(spec):
    return ClockConfig.from_values({"N_CLOCKS": str(len(spec.split(","))), "CLOCK_DOMAINS": spec})


@pytest.mark.parametrize("spec,expected", [
    ("core:clk_i:rst_ni:10:low", 1),
    ("a:clk_a:rst_ni:10:low,b:clk_b:rst_ni:12:low", 1),
    ("a:clk_a:rst_a:10:low,b:clk_b:rst_b:12:high", 2),
    ("a:clk_a:rst_a:10:low,b:clk_b:rst_a:12:low,c:clk_c:rst_c:8:high", 2),
])
def test_unique_resets(spec,expected):
    clocks=cfg(spec)
    reps=TestbenchModel.unique_resets(clocks)
    assert len(reps)==expected
    declarations=TestbenchModel.render_clock_reset_declarations(clocks)
    for d in reps:
        assert declarations.count(f"logic {d.reset};")==1
    tasks=SystemVerilogTestbench._reset_tasks(clocks)
    # global assert/release must contain each physical reset only once
    assert f"{reps[0].reset} =" in tasks


def test_reject_polarity_conflict():
    clocks=cfg("a:clk_a:rst_shared:10:low,b:clk_b:rst_shared:12:high")
    with pytest.raises(ValueError,match="inconsistent polarities"):
        TestbenchModel.unique_resets(clocks)


def test_reject_clock_reset_collision():
    clocks=cfg("a:clk_a:clk_b:10:low,b:clk_b:rst_b:12:low")
    with pytest.raises(ValueError,match="both clock and reset"):
        TestbenchModel.unique_resets(clocks)
