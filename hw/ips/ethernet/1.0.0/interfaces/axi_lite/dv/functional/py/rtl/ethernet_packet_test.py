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

    def assert_valid_frame(self, *, expect_error: bool = False, phy_abort: bool = False) -> None:
        received = bytes(self.observed)
        if phy_abort:
            # The MAC terminates a frame on RX_ER; the remaining wire payload
            # must not appear on the streaming output.
            assert received and len(received) < len(self.expected), (
                f"PHY error did not truncate RX: {received.hex()}"
            )
            assert self.expected.startswith(received), (
                f"PHY error corrupted accepted RX prefix: {received.hex()}"
            )
        else:
            assert received == self.expected, (
                f"RX payload mismatch: observed={received.hex()} expected={self.expected.hex()}"
            )
        assert self.last_count == 1, f"expected one RX end-of-frame, got {self.last_count}"
        if expect_error:
            assert self.error_count > 0, "expected RX error was not observed"
        else:
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
    RX_CASES = frozenset({"gmii_min_1000", "gmii_long", "mii_100", "mii_10",
                          "gmii_bad_fcs", "mii_phy_error", "gmii_no_pad"})
    TX_CASES = frozenset({"gmii_pad_1000", "gmii_ifg_20"})
    SUPPORTED = RX_CASES | TX_CASES

    def __init__(self, dut):
        self.dut = dut

    async def execute(self, name: str) -> None:
        if name not in self.SUPPORTED:
            raise ValueError(f"RX packet runner does not qualify {name!r}")
        case = next(case for case in scenarios.PACKET_SCENARIOS if case.name == name)
        if name in self.TX_CASES:
            await self.execute_tx(case)
            return
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
        scoreboard.assert_valid_frame(expect_error=expected.bad_fcs or expected.phy_error,
                                      phy_abort=expected.phy_error)


    async def execute_tx(self, case) -> None:
        dut = self.dut
        dut.phy_mii_select_i.value = 0
        dut.phy_speed_i.value = 2
        dut.phy_speed_valid_i.value = 1
        await apply_reg(dut, "IFG", case.ifg)
        await apply_reg(dut, "CTRL", 1)
        for _ in range(32):
            await RisingEdge(dut.phy_gtx_clk_i)
        payload = bytes.fromhex(case.payload_hex)
        observer = PhyTxMonitor(dut)
        recorded = cocotb.start_soon(observer.capture())
        await PhyTxDriver(dut).send(payload)
        wire, _ = await recorded
        TxScoreboard.check(wire, payload, padding=case.padding)
        if case.name == "gmii_ifg_20":
            # Observe consecutive frames without restarting the PHY clock.
            watcher = cocotb.start_soon(observer.capture_pair())
            await PhyTxDriver(dut).send(payload)
            await PhyTxDriver(dut).send(payload)
            first, gap, second = await watcher
            TxScoreboard.check(first, payload, padding=case.padding)
            TxScoreboard.check(second, payload, padding=case.padding)
            assert gap >= case.ifg, f"PHY IFG {gap} < programmed {case.ifg}"


class PhyTxMonitor:
    """Capture one GMII wire frame without relying on internal MAC signals."""

    def __init__(self, dut):
        self.dut = dut

    async def capture(self, timeout: int = 4096) -> tuple[bytes, int]:
        data = bytearray()
        idle = 0
        active = False
        for _ in range(timeout):
            await RisingEdge(self.dut.phy_gtx_clk_i)
            await Timer(1, unit="ps")
            en = int(self.dut.phy_gmii_tx_en_o.value)
            if en:
                active = True
                data.append(int(self.dut.phy_gmii_txd_o.value))
                assert not int(self.dut.phy_gmii_tx_er_o.value), "TX asserted GMII error"
            elif active:
                return bytes(data), idle
            else:
                idle += 1
        raise AssertionError("TX frame was not produced")


    async def capture_pair(self, timeout: int = 8192) -> tuple[bytes, int, bytes]:
        frames = [bytearray(), bytearray()]
        frame_idx = 0
        in_frame = False
        gap = 0
        for _ in range(timeout):
            await RisingEdge(self.dut.phy_gtx_clk_i)
            await Timer(1, unit="ps")
            valid = int(self.dut.phy_gmii_tx_en_o.value)
            if valid:
                frames[frame_idx].append(int(self.dut.phy_gmii_txd_o.value))
                assert not int(self.dut.phy_gmii_tx_er_o.value), "TX GMII error"
                in_frame = True
            elif in_frame:
                in_frame = False
                if frame_idx == 1:
                    return bytes(frames[0]), gap, bytes(frames[1])
                frame_idx = 1
                gap = 1
            elif frame_idx == 1:
                gap += 1
        raise AssertionError("two TX frames were not observed")


class PhyTxDriver:
    """AXI-stream producer with valid/ready handshake on the MAC TX clock."""

    def __init__(self, dut):
        self.dut = dut

    async def send(self, body: bytes):
        dut = self.dut
        for i, octet in enumerate(body):
            for _ in range(1024):
                await FallingEdge(dut.tx_clk_o)
                # Sample ready *before* the consuming edge: it is registered by
                # the MAC. Reading it after RisingEdge can see next-cycle ready.
                ready = int(dut.tx_ready_o.value)
                dut.tx_data_i.value = octet
                dut.tx_valid_i.value = 1
                dut.tx_last_i.value = int(i == len(body) - 1)
                dut.tx_error_i.value = 0
                await RisingEdge(dut.tx_clk_o)
                if ready:
                    break
            else:
                raise AssertionError(f"TX ready timeout at byte {i}")
        await FallingEdge(dut.tx_clk_o)
        dut.tx_valid_i.value = 0
        dut.tx_last_i.value = 0


class TxScoreboard:
    @staticmethod
    def check(wire: bytes, payload: bytes, *, padding: bool) -> None:
        import binascii
        assert wire[:8] == bytes([0x55] * 7 + [0xD5]), "wrong TX preamble/SFD"
        body = payload.ljust(60, b"\0") if padding else payload
        fcs = (binascii.crc32(body) & 0xffffffff).to_bytes(4, "little")
        assert wire == bytes([0x55] * 7 + [0xD5]) + body + fcs, (
            f"TX frame mismatch: got {wire.hex()}"
        )


@cocotb.test()
async def packet_test(dut):
    """A true DUT-driven RX test, run with TEST_NAME=<scenario>."""
    name = os.environ["TEST_NAME"]
    speeds = {case.name: case.speed_mbps for case in scenarios.PACKET_SCENARIOS}
    if name not in EthernetPacketTest.SUPPORTED:
        raise AssertionError(f"unsupported packet scenario: {name}")
    rx_period = {1000: 8, 100: 40, 10: 400}[speeds[name]]
    for signal, ns in (("clk_i", 10), ("phy_gtx_clk_i", 8),
                       ("phy_gmii_rx_clk_i", rx_period), ("phy_mii_tx_clk_i", 40)):
        cocotb.start_soon(Clock(getattr(dut, signal), ns, unit="ns").start())
    set_defaults(dut)
    dut.tx_valid_i.value = 0
    dut.tx_last_i.value = 0
    dut.tx_error_i.value = 0
    await reset(dut, "all")
    await EthernetPacketTest(dut).execute(name)
