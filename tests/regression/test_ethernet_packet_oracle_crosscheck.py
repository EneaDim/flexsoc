"""Cross-check every Ethernet PHY fixture against the independent semantic oracle.

This is model/fixture verification, NOT an RTL or formal qualification result.
"""
from __future__ import annotations

import json
from pathlib import Path
import sys

import pytest

ROOT = Path(__file__).resolve().parents[2]
IP = ROOT / 'hw/ips/ethernet/0.1.0'
PY = IP / 'interfaces/tlul/dv/functional/py'
MODEL = IP / 'interfaces/tlul/dv/functional/model'
for path in (str(PY), str(MODEL)):
    if path not in sys.path:
        sys.path.insert(0, path)
from packet_phy_vectors import all_fixtures
from ethernet_oracle import PREAMBLE, decode_rx, encode_tx, mii_to_gmii

FIXTURES = all_fixtures()


def _reconstruct_wire(fixture):
    active = [int(data) for data, dv, _er in fixture.symbols if dv]
    if fixture.speed_mbps == 1000:
        return bytes(active)
    return mii_to_gmii(active)


@pytest.mark.parametrize('fixture', FIXTURES, ids=lambda f: f.name)
def test_phy_fixture_matches_independent_packet_oracle(fixture):
    wire = _reconstruct_wire(fixture)
    assert wire.startswith(PREAMBLE)
    assert wire[8:-4] == fixture.expected_body
    rx = decode_rx(wire, phy_error=fixture.phy_error)
    assert rx.body == fixture.expected_body
    assert rx.bad_fcs == fixture.bad_fcs
    assert rx.phy_error == fixture.phy_error
    assert rx.bad_frame == (fixture.bad_fcs or fixture.phy_error)
    assert rx.valid_fcs == (not fixture.bad_fcs)
    if not fixture.bad_fcs:
        # Independent semantic oracle must produce an identical uncorrupted wire.
        assert wire == encode_tx(fixture.expected_body, padding=False, ifg=fixture.ifg_octets).wire
    width = 1 if fixture.speed_mbps == 1000 else 2
    active_count = sum(int(dv) for _data, dv, _er in fixture.symbols)
    assert len(fixture.symbols) - active_count == fixture.ifg_octets * width
    assert all(dv == 0 and er == 0 for _d, dv, er in fixture.symbols[active_count:])
    assert sum(bool(er) for _d, _dv, er in fixture.symbols) == int(fixture.phy_error)


def test_all_declared_packet_scenarios_have_unique_fixtures_and_testplan_mapping():
    from scenarios import PACKET_SCENARIOS
    plan = json.loads((IP / 'spec/testplan.yaml').read_text(encoding='utf-8'))
    names = [case.name for case in PACKET_SCENARIOS]
    assert len(names) == len(set(names)) == 9
    assert {fixture.name for fixture in FIXTURES} == set(names)
    mapped = {}
    for item in plan['items']:
        for test in item.get('tests', []):
            if test in names:
                assert test not in mapped, f'duplicate testplan mapping: {test}'
                mapped[test] = item
    assert set(mapped) == set(names)
    for case in PACKET_SCENARIOS:
        assert set(case.requirement_ids) <= set(mapped[case.name]['requirements'])
