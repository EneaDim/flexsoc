"""Shared GPIO functional scenarios, independent of CSR layout and bus timing."""
from dataclasses import dataclass

@dataclass(frozen=True)
class IrqLevels:
    previous: int = 0
    current: int = 0x5
    high_mask: int = 0x5
    low_mask: int = 0xA
    expected: int = 0xF

@dataclass(frozen=True)
class InputFilterCase:
    pin_mask: int = 1
    stable_samples: int = 16

IRQ_LEVELS = IrqLevels()
INPUT_FILTER = InputFilterCase()
MODEL_CASES = ("input_filter", "interrupt_levels")
