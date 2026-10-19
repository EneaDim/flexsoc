"""Fixture-level checks only; do not count as RTL execution."""
from __future__ import annotations
import importlib.util
from pathlib import Path
import sys
import binascii

ROOT = Path(__file__).resolve().parents[2]
SRC = ROOT / 'hw/ips/ethernet/0.1.0/interfaces/tlul/dv/functional/py/rtl'
sys.path.insert(0, str(SRC))
from packet_phy_vectors import PREAMBLE, all_fixtures


def test_every_packet_scenario_produces_phy_input():
    fixtures = all_fixtures()
    assert len(fixtures) == 9
    assert len({f.name for f in fixtures}) == 9
    for f in fixtures:
        width = 8 if f.speed_mbps == 1000 else 4
        assert all(0 <= data < (1 << width) and dv in (0, 1) and er in (0, 1)
                   for data, dv, er in f.symbols)
        assert f.symbols[-1] == (0, 0, 0)


def test_gmii_wire_crc_and_ifg():
    f = next(x for x in all_fixtures() if x.name == 'gmii_long')
    wire = bytes(data for data, dv, _ in f.symbols if dv)
    assert wire.startswith(PREAMBLE)
    assert wire[8:-4] == f.expected_body
    assert wire[-4:] == binascii.crc32(f.expected_body).to_bytes(4, 'little')
    assert len(wire) == 8 + 1514 + 4
    assert len(f.symbols) - len(wire) == 12


def test_bad_fcs_and_phy_error_are_independent():
    fs = {x.name: x for x in all_fixtures()}
    bad = fs['gmii_bad_fcs']
    wire = bytes(d for d, valid, _ in bad.symbols if valid)
    assert wire[-4:] != binascii.crc32(bad.expected_body).to_bytes(4, 'little')
    assert not any(er for _, _, er in bad.symbols)
    phy = fs['mii_phy_error']
    assert any(er for _, _, er in phy.symbols)
    assert not phy.bad_fcs


def test_mii_lsb_nibble_first_and_idle():
    f = next(x for x in all_fixtures() if x.name == 'mii_100')
    active = [d for d, dv, _ in f.symbols if dv]
    octets = bytes(active[i] | (active[i + 1] << 4) for i in range(0, len(active), 2))
    assert octets[:8] == PREAMBLE
    assert octets[8:-4] == f.expected_body
    assert octets[-4:] == binascii.crc32(f.expected_body).to_bytes(4, 'little')
    assert len(f.symbols) - len(active) == 2 * f.ifg_octets
