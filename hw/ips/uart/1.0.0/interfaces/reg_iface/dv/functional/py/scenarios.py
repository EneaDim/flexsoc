"""UART functional stimuli and independently specified known-answer frames."""
from dataclasses import dataclass

@dataclass(frozen=True)
class Frame:
    data: int
    bits: tuple[int, ...]

CORNER_FRAMES = (
    Frame(0x00, (0, 0, 0, 0, 0, 0, 0, 0, 0, 1)),
    Frame(0xFF, (0, 1, 1, 1, 1, 1, 1, 1, 1, 1)),
    Frame(0x55, (0, 1, 0, 1, 0, 1, 0, 1, 0, 1)),
    Frame(0xAA, (0, 0, 1, 0, 1, 0, 1, 0, 1, 1)),
)
RECONFIG_FIRST_BYTE = 0x5A
RECONFIG_PARITY_BYTE = 0xC3
PARITY_ERROR_BYTE = 0x5A
PARITY_RECOVERY_BYTE = 0xC3
MODEL_CASES = ("corners", "parity_reconfig", "parity_error")
