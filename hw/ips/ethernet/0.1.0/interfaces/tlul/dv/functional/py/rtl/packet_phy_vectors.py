"""Ethernet-specific PHY input fixtures for the nine canonical packet scenarios.

Not an RTL result: fixture generation must be followed by DUT-driven tests.
Each symbol is (rxd, rx_dv, rx_er), sampled on the PHY receive clock.
"""
from __future__ import annotations

from dataclasses import dataclass
import binascii
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import sys
from pathlib import Path
_MODEL = Path(__file__).resolve().parents[1] / "model"
if str(_MODEL) not in sys.path:
    sys.path.insert(0, str(_MODEL))
import scenarios

PREAMBLE = bytes([0x55] * 7 + [0xD5])


@dataclass(frozen=True)
class PhyFixture:
    name: str
    speed_mbps: int
    symbols: tuple[tuple[int, int, int], ...]
    expected_body: bytes
    bad_fcs: bool
    phy_error: bool
    ifg_octets: int


def fixture(case: scenarios.PacketScenario) -> PhyFixture:
    body = bytes.fromhex(case.payload_hex)
    if case.padding:
        body = body.ljust(60, b"\x00")
    fcs = (binascii.crc32(body) & 0xffffffff).to_bytes(4, 'little')
    if case.inject_bad_fcs:
        fcs = bytes([fcs[0] ^ 1]) + fcs[1:]
    wire = PREAMBLE + body + fcs
    if case.speed_mbps == 1000:
        symbols = [(octet, 1, 0) for octet in wire]
        # ER assertion is distinct from corrupted FCS, on the first data symbol.
        if case.phy_error:
            symbols[len(PREAMBLE)] = (symbols[len(PREAMBLE)][0], 1, 1)
        idle_symbols = case.ifg
    elif case.speed_mbps in (10, 100):
        nibbles = [nib for octet in wire for nib in (octet & 15, octet >> 4)]
        symbols = [(nib, 1, 0) for nib in nibbles]
        if case.phy_error:
            symbols[2 * len(PREAMBLE)] = (symbols[2 * len(PREAMBLE)][0], 1, 1)
        idle_symbols = case.ifg * 2
    else:
        raise ValueError(f'unsupported speed: {case.speed_mbps}')
    symbols.extend((0, 0, 0) for _ in range(idle_symbols))
    return PhyFixture(case.name, case.speed_mbps, tuple(symbols), body,
                      case.inject_bad_fcs, case.phy_error, case.ifg)


def all_fixtures() -> tuple[PhyFixture, ...]:
    return tuple(fixture(case) for case in scenarios.PACKET_SCENARIOS)
