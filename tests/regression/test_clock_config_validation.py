"""Generic clock/reset settings validation, independent of DUT or interface."""

import pytest

from flexsoc.backend.core import ClockConfig


@pytest.mark.parametrize("domains", [
    "a:clk_a:rst:10:low",
    "a:clk_a:rst:10:low,b:clk_b:rst:20:low",
    "a:clk_a:rst_a:10:low,b:clk_b:rst_b:20:high",
    "a:clk_a:rst_a:10:low,b:clk_b:rst_a:20:low,c:clk_c:rst_c:8:high",
])
def test_valid_topologies(domains):
    count = len(domains.split(","))
    cfg = ClockConfig.from_values({"CLOCK_DOMAINS": domains, "N_CLOCKS": str(count)})
    assert cfg.n_clocks == count
    assert len(cfg.to_settings()["CLOCK_DOMAINS"].split(",")) == count


def test_conflicting_shared_reset_polarity_rejected_early():
    with pytest.raises(ValueError, match="inconsistent polarities"):
        ClockConfig.from_values({
            "N_CLOCKS": "2",
            "CLOCK_DOMAINS": "a:clk_a:rst:10:low,b:clk_b:rst:20:high",
        })


def test_clock_reset_name_collision_rejected_early():
    with pytest.raises(ValueError, match="both clock and reset"):
        ClockConfig.from_values({
            "N_CLOCKS": "2",
            "CLOCK_DOMAINS": "a:clk_a:clk_b:10:low,b:clk_b:rst_b:20:low",
        })


def test_valid_shared_reset_not_rejected():
    cfg = ClockConfig.from_values({
        "N_CLOCKS": "3",
        "CLOCK_DOMAINS": "a:clk_a:rst:10:low,b:clk_b:rst:20:low,c:clk_c:rst:30:low",
    })
    assert cfg.n_clocks == 3
