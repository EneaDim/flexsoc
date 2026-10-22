"""UART master host request tests using shared semantic stimuli."""
import pytest
from uart_master_model import HostRequest, HostResponse
import scenarios


@pytest.mark.parametrize("case_id", scenarios.MODEL_CASES)
def test_model_case(case_id):
    if case_id == "read_response_format":
        data, error, expected = scenarios.READ_RESPONSE
        assert HostResponse(data=data, error=error).encode() == list(expected)
        return
    cfg = scenarios.REQUESTS[case_id]
    req = HostRequest(address=cfg.address, write=cfg.write,
                      data=cfg.data, byte_enable=cfg.byte_enable)
    expected_addr = cfg.address & ~3
    assert req.bus_outputs() == {
        "addr_o": expected_addr, "we_o": int(cfg.write),
        "wdata_o": cfg.data if cfg.write else 0,
        "be_o": cfg.byte_enable & 0xF,
    }
    encoded = req.encode()
    assert encoded[0] == 0xA5
    assert encoded[1] == int(cfg.write)
    assert encoded[2] == (cfg.byte_enable & 0xF)
    assert encoded[3:7] == [(cfg.address >> shift) & 0xFF for shift in (0, 8, 16, 24)]
    if cfg.write:
        assert encoded[7:] == [(cfg.data >> shift) & 0xFF for shift in (0, 8, 16, 24)]
    else:
        assert len(encoded) == 7
