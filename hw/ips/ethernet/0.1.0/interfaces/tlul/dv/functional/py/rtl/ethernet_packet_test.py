"""Ethernet RX PHY verification against the actual DUT (cocotb plugin)."""
from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
import sys
import os
import cocotb
from cocotb.clock import Clock
from drivers.reg_driver import reset, set_defaults

from cocotb.triggers import FallingEdge, RisingEdge, Timer
from drivers.reg_driver import apply_reg

_MODEL = Path(__file__).resolve().parents[1] / "model"
if str(_MODEL) not in sys.path:
    sys.path.insert(0, str(_MODEL))
import scenarios
from packet_phy_vectors import fixture


@dataclass(slots=True)
class RxScoreboard:
    expected: bytes
    observed: bytearray
    last_count: int = 0
    error_count: int = 0

    @classmethod
    def for_frame(cls, expected: bytes) -> "RxScoreboard":
        return cls(expected, bytearray())

    def sample(self, dut) -> None:
        if int(dut.rx_valid_o.value):
            self.observed.append(int(dut.rx_data_o.value))
            self.last_count += int(dut.rx_last_o.value)
            self.error_count += int(dut.rx_error_o.value)

    def assert_valid_frame(self) -> None:
        assert bytes(self.observed) == self.expected, (
            f"RX payload mismatch: observed={self.observed.hex()} expected={self.expected.hex()}"
        )
        assert self.last_count == 1, f"expected one RX end-of-frame, got {self.last_count}"
        assert self.error_count == 0, f"unexpected RX errors: {self.error_count}"


class PhyRxDriver:
    def __init__(self, dut):
        self.dut = dut

    async def transmit(self, symbols) -> None:
        dut = self.dut
        for data, valid, error in symbols:
            await FallingEdge(dut.phy_gmii_rx_clk_i)
            dut.phy_gmii_rxd_i.value = data
            dut.phy_gmii_rx_dv_i.value = valid
            dut.phy_gmii_rx_er_i.value = error
        await FallingEdge(dut.phy_gmii_rx_clk_i)
        dut.phy_gmii_rx_dv_i.value = 0
        dut.phy_gmii_rx_er_i.value = 0


class EthernetPacketTest:
    # Only cases whose RX behavior can be conclusively checked belong here.
    SUPPORTED = frozenset({"gmii_min_1000", "gmii_long", "mii_100", "mii_10"})

    def __init__(self, dut):
        self.dut = dut

    async def execute(self, name: str) -> None:
        if name not in self.SUPPORTED:
            raise ValueError(f"RX packet runner does not qualify {name!r}")
        case = next(case for case in scenarios.PACKET_SCENARIOS if case.name == name)
        expected = fixture(case)
        dut = self.dut
        dut.phy_mii_select_i.value = int(case.speed_mbps != 1000)
        dut.phy_speed_i.value = {10: 0, 100: 1, 1000: 2}[case.speed_mbps]
        dut.phy_speed_valid_i.value = 1
        await apply_reg(dut, "CTRL", 2)
        for _ in range(24):
            await RisingEdge(dut.phy_gmii_rx_clk_i)
        scoreboard = RxScoreboard.for_frame(expected.expected_body)

        async def observe():
            for _ in range(len(expected.symbols) + 64):
                await RisingEdge(dut.rx_clk_o)
                await Timer(1, unit="ps")
                scoreboard.sample(dut)

        watcher = cocotb.start_soon(observe())
        await PhyRxDriver(dut).transmit(expected.symbols)
        await watcher
        scoreboard.assert_valid_frame()


@cocotb.test()
async def packet_test(dut):
    """A true DUT-driven RX test, run with TEST_NAME=<scenario>."""
    name = os.environ["TEST_NAME"]
    speeds = {case.name: case.speed_mbps for case in scenarios.PACKET_SCENARIOS}
    if name not in EthernetPacketTest.SUPPORTED:
        raise AssertionError(f"unsupported RX-only scenario: {name}")
    rx_period = {1000: 8, 100: 40, 10: 400}[speeds[name]]
    for signal, ns in (("clk_i", 10), ("phy_gtx_clk_i", 8),
                       ("phy_gmii_rx_clk_i", rx_period), ("phy_mii_tx_clk_i", 40)):
        cocotb.start_soon(Clock(getattr(dut, signal), ns, unit="ns").start())
    set_defaults(dut)
    await reset(dut, "all")
    await EthernetPacketTest(dut).execute(name)
