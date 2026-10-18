"""Independent UART known-answer scenarios for serial frame generation."""
import pytest
from uart_model import parity_bit, uart_frame
import scenarios


@pytest.mark.parametrize("case_id", scenarios.MODEL_CASES)
def test_model_case(case_id):
    if case_id == "corners":
        for frame in scenarios.CORNER_FRAMES:
            assert uart_frame(frame.data) == list(frame.bits)
    elif case_id == "parity_reconfig":
        data = scenarios.RECONFIG_PARITY_BYTE
        assert parity_bit(data, odd=False) == 0
        assert parity_bit(data, odd=True) == 1
        assert uart_frame(data, parity=True, odd=False)[-2:] == [0, 1]
        assert uart_frame(data, parity=True, odd=True)[-2:] == [1, 1]
    elif case_id == "parity_error":
        data = scenarios.PARITY_ERROR_BYTE
        valid = uart_frame(data, parity=True, odd=True)
        bad = uart_frame(data, parity=True, odd=True, bad_parity=True)
        assert len(valid) == len(bad) == 11
        assert valid[:-2] == bad[:-2]
        assert valid[-2] != bad[-2]
    else:
        raise AssertionError(case_id)
