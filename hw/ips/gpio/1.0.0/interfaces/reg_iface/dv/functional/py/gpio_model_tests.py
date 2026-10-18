"""Independent GPIO model checks against IP-owned semantic scenarios."""
import pytest
from gpio_model import InputFilter, InterruptConfig, interrupt_value, u4
import scenarios


def test_width_mask():
    assert u4(0x1F) == 0xF
    assert u4(0x10) == 0


@pytest.mark.parametrize("case_id", scenarios.MODEL_CASES)
def test_model_case(case_id):
    if case_id == "input_filter":
        filt = InputFilter()
        cfg = scenarios.INPUT_FILTER
        assert filt.step(cfg.pin_mask, cfg.pin_mask) == 0
        assert filt.step(0, cfg.pin_mask) == 0
        for _ in range(cfg.stable_samples - 1):
            assert filt.step(cfg.pin_mask, cfg.pin_mask) == 0
        assert filt.step(cfg.pin_mask, cfg.pin_mask) == cfg.pin_mask
        filt.reset()
        assert filt.value == 0
    elif case_id == "interrupt_levels":
        case = scenarios.IRQ_LEVELS
        config = InterruptConfig(high=case.high_mask, low=case.low_mask)
        assert interrupt_value(case.previous, case.current, config) == case.expected
        assert interrupt_value(0, 1, InterruptConfig(rising=1)) == 1
        assert interrupt_value(1, 0, InterruptConfig(falling=1)) == 1
    else:
        raise AssertionError(case_id)
