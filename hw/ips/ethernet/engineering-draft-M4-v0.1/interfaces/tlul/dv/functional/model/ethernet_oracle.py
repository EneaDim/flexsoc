"""Independent Ethernet packet/CSR semantic oracle.

NOT a cycle-accurate implementation of the pinned upstream MAC or CDC.
Bitwise reflected CRC implementation is independent from RTL lfsr.v.
"""
from __future__ import annotations
from dataclasses import dataclass, field

PREAMBLE = b'\x55' * 7 + b'\xd5'
FCS_POLY_REFLECTED = 0xEDB88320
DEFAULT_IFG = 12
MIN_FRAME_WITH_FCS = 64


def crc32_eth(data: bytes) -> int:
    crc = 0xFFFFFFFF
    for octet in data:
        crc ^= octet
        for _ in range(8):
            crc = (crc >> 1) ^ (FCS_POLY_REFLECTED if crc & 1 else 0)
    return crc ^ 0xFFFFFFFF


def fcs_octets(data: bytes) -> bytes:
    return crc32_eth(data).to_bytes(4, 'little')


def pad_frame(body: bytes, minimum_with_fcs: int = MIN_FRAME_WITH_FCS) -> bytes:
    if minimum_with_fcs < 4:
        raise ValueError('minimum length must accommodate FCS')
    return body.ljust(max(len(body), minimum_with_fcs - 4), b'\x00')


@dataclass(frozen=True)
class TxFrame:
    wire: bytes       # From preamble through FCS; excludes idle symbols
    body: bytes       # After optional MAC padding, before FCS
    fcs: bytes
    ifg_octets: int   # Logical idle interval; not an assumed gmii_txd idle value


def encode_tx(body: bytes, *, padding: bool = True, ifg: int = DEFAULT_IFG) -> TxFrame:
    if not 12 <= ifg <= 255:
        raise ValueError('accepted oracle IFG must be between 12 and 255 octet times')
    transmitted = pad_frame(body) if padding else body
    crc = fcs_octets(transmitted)
    return TxFrame(PREAMBLE + transmitted + crc, transmitted, crc, ifg)


@dataclass(frozen=True)
class RxFrame:
    body: bytes
    valid_fcs: bool
    bad_frame: bool
    bad_fcs: bool
    phy_error: bool


def decode_rx(wire: bytes, *, phy_error: bool = False) -> RxFrame:
    if not wire.startswith(PREAMBLE):
        raise ValueError('expected 7-octet preamble + SFD')
    if len(wire) < len(PREAMBLE) + 4:
        raise ValueError('truncated frame/FCS')
    body = wire[len(PREAMBLE):-4]
    good_crc = fcs_octets(body) == wire[-4:]
    return RxFrame(body, good_crc, not good_crc or phy_error, not good_crc, phy_error)


def corrupt_fcs(wire: bytes, bit: int = 0) -> bytes:
    if len(wire) < len(PREAMBLE) + 4 or not 0 <= bit < 32:
        raise ValueError('invalid FCS corruption')
    buf = bytearray(wire)
    buf[-4 + bit // 8] ^= 1 << (bit % 8)
    return bytes(buf)


def mii_low_nibble_first(gmii_octets: bytes) -> tuple[int, ...]:
    return tuple(nibble for x in gmii_octets for nibble in (x & 15, x >> 4))


def mii_to_gmii(nibbles: tuple[int, ...] | list[int]) -> bytes:
    if len(nibbles) % 2 or any(n < 0 or n > 15 for n in nibbles):
        raise ValueError('MII requires an even count of 4-bit nibbles')
    return bytes(nibbles[i] | (nibbles[i + 1] << 4) for i in range(0, len(nibbles), 2))


SPEEDS = {10: (0, 'MII', 2_500_000), 100: (1, 'MII', 25_000_000), 1000: (2, 'GMII', 125_000_000)}


def speed_descriptor(mbps: int) -> tuple[int, str, int]:
    try:
        return SPEEDS[mbps]
    except KeyError as exc:
        raise ValueError(f'unsupported Ethernet speed: {mbps}') from exc


@dataclass
class EthernetCsrOracle:
    """PROPOSED software-level behavior. Real CDC implementation must be proven."""
    request_tx: bool = False
    request_rx: bool = False
    effective_tx: bool = False
    effective_rx: bool = False
    request_ifg: int = DEFAULT_IFG
    effective_ifg: int = DEFAULT_IFG
    speed: int = 0
    speed_valid: bool = False
    intr_enable: int = 0
    intr_state: int = 0
    counters: list[int] = field(default_factory=lambda: [0, 0, 0])

    @property
    def pending(self) -> bool:
        return (self.request_tx != self.effective_tx or
                self.request_rx != self.effective_rx or
                self.request_ifg != self.effective_ifg)

    def write_control(self, value: int) -> None:
        self.request_tx = bool(value & 1)
        self.request_rx = bool(value & 2)

    def write_ifg(self, value: int) -> None:
        if not 12 <= value <= 255:
            raise ValueError('invalid IFG (proposed legal range)')
        self.request_ifg = value

    def acknowledge_tx(self) -> None:
        self.effective_tx, self.effective_ifg = self.request_tx, self.request_ifg

    def acknowledge_rx(self) -> None:
        self.effective_rx = self.request_rx

    def update_speed(self, mbps: int | None) -> None:
        if mbps is None:
            self.speed_valid = False
        else:
            self.speed = speed_descriptor(mbps)[0]
            self.speed_valid = True

    def record_event(self, event: str) -> None:
        index = {'tx_underflow': 0, 'rx_bad_frame': 1, 'rx_bad_fcs': 2}[event]
        self.counters[index] = (self.counters[index] + 1) & 0xFFFFFFFF
        self.intr_state |= 1 << index

    def clear_interrupts(self, mask: int) -> None:
        self.intr_state &= ~(mask & 7)

    @property
    def irq(self) -> int:
        return self.intr_state & self.intr_enable

    def read_status(self) -> int:
        return (self.speed | (int(self.speed_valid) << 2) |
                (int(self.effective_tx) << 3) | (int(self.effective_rx) << 4) |
                (int(self.pending) << 5))

    def reset(self) -> None:
        self.__dict__.update(type(self)().__dict__)
