"""Canonical Ethernet scenarios: semantic intent, independent of CSR bus encoding.

Packet cases intentionally do NOT project to FlexSoC data_in.vec until the actual
packet ports and multi-clock top testbench support are complete.
"""
from __future__ import annotations
from dataclasses import dataclass

@dataclass(frozen=True)
class Operation:
    cycle: int
    kind: str  # write | read
    register: str
    value: int
    mask: int | None = None

@dataclass(frozen=True)
class CsrScenario:
    name: str
    requirement_ids: tuple[str, ...]
    operations: tuple[Operation, ...]

CSR_SCENARIOS = (
    CsrScenario('reset_defaults', ('REQ-CSR-01',), (
        Operation(16, 'read','CTRL',0,0x3),
        Operation(18, 'read','IFG',12,0xff),
        Operation(20, 'read','INTR_ENABLE',0,0x7),
    )),
    CsrScenario('control_rw', ('REQ-CSR-01','REQ-CSR-02'), (
        Operation(8,'write','CTRL',3),
        Operation(20,'read','CTRL',3,0x3),
        Operation(30,'write','CTRL',0),
        Operation(42,'read','CTRL',0,0x3),
    )),
    CsrScenario('ifg_rw', ('REQ-CSR-03',), (
        Operation(8,'write','IFG',16),
        Operation(20,'read','IFG',16,0xff),
        Operation(30,'write','IFG',12),
        Operation(42,'read','IFG',12,0xff),
    )),
    CsrScenario('irq_enable_rw', ('REQ-CSR-04',), (
        Operation(8,'write','INTR_ENABLE',7),
        Operation(20,'read','INTR_ENABLE',7,0x7),
        Operation(30,'write','INTR_ENABLE',0),
        Operation(42,'read','INTR_ENABLE',0,0x7),
    )),
)

@dataclass(frozen=True)
class PacketScenario:
    name: str
    requirement_ids: tuple[str, ...]
    speed_mbps: int
    payload_hex: str
    padding: bool = True
    ifg: int = 12
    inject_bad_fcs: bool = False
    phy_error: bool = False


def _frame(n: int) -> str:
    # Distinct patterns including DA/SA/type-like fields; body is MAC frame
    # without preamble/FCS; not Ethernet II header validation.
    return bytes((j * 37 + 11) & 255 for j in range(n)).hex()

PACKET_SCENARIOS = (
    PacketScenario('gmii_min_1000', ('REQ-TX-01','REQ-RX-01'), 1000, _frame(60)),
    PacketScenario('gmii_pad_1000', ('REQ-TX-02','REQ-RX-01'), 1000, _frame(42)),
    PacketScenario('mii_100', ('REQ-TX-01','REQ-PHY-01'), 100, _frame(100)),
    PacketScenario('mii_10', ('REQ-TX-01','REQ-PHY-01'), 10, _frame(100)),
    PacketScenario('gmii_bad_fcs', ('REQ-RX-02',), 1000, _frame(74), inject_bad_fcs=True),
    PacketScenario('mii_phy_error', ('REQ-RX-03',), 100, _frame(60), phy_error=True),
    PacketScenario('gmii_no_pad', ('REQ-TX-02',), 1000, _frame(59), padding=False),
    PacketScenario('gmii_long', ('REQ-TX-01','REQ-RX-01'), 1000, _frame(1514)),
    PacketScenario('gmii_ifg_20', ('REQ-TX-03',), 1000, _frame(100), ifg=20),
)
