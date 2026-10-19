"""Independent tests of candidate packet and CSR semantics (NOT RTL PASS)."""
from __future__ import annotations
import sys
from pathlib import Path
import binascii
import random
import pytest
sys.path.insert(0, str(Path(__file__).resolve().parent if (Path(__file__).resolve().parent / 'ethernet_oracle.py').is_file() else Path(__file__).resolve().parents[1] / 'model'))
from ethernet_oracle import (crc32_eth, fcs_octets, pad_frame, encode_tx,
                             decode_rx, corrupt_fcs, mii_low_nibble_first,
                             mii_to_gmii, speed_descriptor, EthernetCsrOracle,
                             PREAMBLE)

@pytest.mark.parametrize('raw,crc', [(b'',0), (b'123456789',0xCBF43926),
                                     (b'\x00',0xD202EF8D), (bytes(range(256)),0x29058C73)])
def test_crc_known(raw, crc):
    assert crc32_eth(raw) == crc
    assert crc32_eth(raw) == binascii.crc32(raw)

@pytest.mark.parametrize('n', [0,1,14,59,60,61,100,1500])
def test_roundtrip_pad(n):
    frame = encode_tx(bytes([n % 256]) * n)
    expected = max(n,60)
    assert frame.body == bytes([n % 256])*n + bytes(expected-n)
    assert frame.wire[:8] == PREAMBLE
    assert frame.wire[-4:] == fcs_octets(frame.body)
    result = decode_rx(frame.wire)
    assert result.body == frame.body
    assert result.valid_fcs and not result.bad_frame and not result.bad_fcs

@pytest.mark.parametrize('n', [0,1,59,60,61,1500])
def test_no_padding(n):
    body = bytes((i&255 for i in range(n)))
    assert decode_rx(encode_tx(body,padding=False).wire).body == body

@pytest.mark.parametrize('bit', [0,1,7,8,15,16,31])
def test_bad_fcs_each_octet(bit):
    frame = encode_tx(b'\x40'*100)
    rx = decode_rx(corrupt_fcs(frame.wire,bit))
    assert rx.bad_frame and rx.bad_fcs and not rx.valid_fcs


def test_long_frame_roundtrip():
    # 1514-byte MAC frame, excluding preamble and FCS: independent packet oracle.
    body = bytes((i * 37 + 11) & 0xff for i in range(1514))
    frame = encode_tx(body)
    assert frame.body == body
    assert len(frame.wire) == len(PREAMBLE) + 1514 + 4
    assert frame.wire[-4:] == fcs_octets(body)
    result = decode_rx(frame.wire)
    assert result.body == body
    assert result.valid_fcs and not result.bad_frame and not result.bad_fcs


def test_phy_error_with_good_fcs():
    rx = decode_rx(encode_tx(b'\x01'*100).wire,phy_error=True)
    assert rx.valid_fcs and rx.bad_frame and not rx.bad_fcs and rx.phy_error


def test_short_or_bad_preamble():
    with pytest.raises(ValueError): decode_rx(b'')
    with pytest.raises(ValueError): decode_rx(b'\xff'*9)

@pytest.mark.parametrize('octets', [b'',b'\x12',bytes(range(256))])
def test_mii_roundtrip(octets):
    assert mii_to_gmii(mii_low_nibble_first(octets)) == octets


def test_mii_order():
    assert mii_low_nibble_first(b'\xab\x53') == (11,10,3,5)

@pytest.mark.parametrize('bad', [[16,1],[0],[-1,1]])
def test_reject_bad_mii(bad):
    with pytest.raises(ValueError): mii_to_gmii(bad)

@pytest.mark.parametrize('speed,code,kind,clock', [(10,0,'MII',2500000),(100,1,'MII',25000000),(1000,2,'GMII',125000000)])
def test_speeds(speed,code,kind,clock):
    assert speed_descriptor(speed)==(code,kind,clock)


def test_speed_unknown():
    with pytest.raises(ValueError): speed_descriptor(2500)

@pytest.mark.parametrize('ifg', [0,1,11,256])
def test_ifg_rejected(ifg):
    with pytest.raises(ValueError): encode_tx(b'x'*60,ifg=ifg)


def test_ifg_valid():
    assert encode_tx(b'abcdef'*10,ifg=12).ifg_octets==12
    assert encode_tx(b'abcdef'*10,ifg=255).ifg_octets==255


def test_csr_reset_defaults():
    c = EthernetCsrOracle()
    assert c.read_status()==0 and c.request_ifg==12 and not c.pending
    assert c.counters==[0,0,0]


def test_csr_pending_ack():
    c=EthernetCsrOracle();c.write_control(3);c.write_ifg(24)
    assert c.pending
    c.acknowledge_tx();assert c.pending and c.effective_tx and c.effective_ifg==24
    c.acknowledge_rx();assert not c.pending and c.effective_rx
    assert c.read_status() & 0x18 == 0x18


def test_csr_counter_and_irq():
    c=EthernetCsrOracle();c.intr_enable=0b010
    c.record_event('tx_underflow');assert c.intr_state==1 and c.irq==0
    c.record_event('rx_bad_frame');assert c.intr_state==3 and c.irq==2
    c.clear_interrupts(2); assert c.irq==0 and c.intr_state==1


def test_csr_counter_wrap():
    c=EthernetCsrOracle();c.counters[2]=0xffffffff
    c.record_event('rx_bad_fcs');assert c.counters[2]==0


def test_csr_speed_valid():
    c=EthernetCsrOracle();c.update_speed(1000);assert c.read_status() & 7 == 6
    c.update_speed(None);assert not c.speed_valid


def test_csr_reset_clears_events():
    c=EthernetCsrOracle();c.write_control(3);c.acknowledge_tx();c.record_event('tx_underflow')
    c.reset();assert c.read_status()==0 and c.intr_state==0 and c.request_ifg==12


def test_random_independent_crc_crosscheck():
    rng=random.Random(20261016)
    for _ in range(128):
        length=rng.randrange(1519)
        sample=bytes(rng.randrange(256) for _ in range(length))
        assert crc32_eth(sample)==binascii.crc32(sample)
