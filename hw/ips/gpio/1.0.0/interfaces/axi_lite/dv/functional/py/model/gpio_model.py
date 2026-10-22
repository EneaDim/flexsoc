"""Behavioral model for the 4-bit FlexSoC GPIO IP."""

from __future__ import annotations

from dataclasses import dataclass

TOP = "gpio"
WIDTH = 4
MASK = (1 << WIDTH) - 1
FILTER_CYCLES = 16

INPUTS = ("cio_gpio_i",)
OUTPUTS = ("cio_gpio_o", "cio_gpio_en_o", "intr_gpio_o")


def u4(value: int) -> int:
    return int(value) & MASK


@dataclass(frozen=True)
class InterruptConfig:
    rising: int = 0
    falling: int = 0
    high: int = 0
    low: int = 0
    input_filter: int = 0

    def normalized(self) -> "InterruptConfig":
        return InterruptConfig(
            rising=u4(self.rising),
            falling=u4(self.falling),
            high=u4(self.high),
            low=u4(self.low),
            input_filter=u4(self.input_filter),
        )


def interrupt_value(previous: int, current: int, config: InterruptConfig) -> int:
    previous = u4(previous)
    current = u4(current)
    cfg = config.normalized()

    rise = ((~previous) & current) & cfg.rising
    fall = (previous & (~current)) & cfg.falling
    level_high = current & cfg.high
    level_low = (~current) & cfg.low
    return u4(rise | fall | level_high | level_low)


class InputFilter:
    """Cycle model of the 16-sample per-pin input filter."""

    def __init__(self) -> None:
        self.value = 0
        self.counters = [0] * WIDTH

    def reset(self) -> None:
        self.value = 0
        self.counters = [0] * WIDTH

    def step(self, raw: int, enable: int) -> int:
        raw = u4(raw)
        enable = u4(enable)
        next_value = self.value

        for bit in range(WIDTH):
            mask = 1 << bit
            raw_bit = bool(raw & mask)
            stored_bit = bool(self.value & mask)

            if not (enable & mask):
                self.counters[bit] = 0
                if raw_bit:
                    next_value |= mask
                else:
                    next_value &= ~mask
                continue

            if raw_bit == stored_bit:
                self.counters[bit] = 0
                continue

            self.counters[bit] += 1
            if self.counters[bit] >= FILTER_CYCLES:
                if raw_bit:
                    next_value |= mask
                else:
                    next_value &= ~mask
                self.counters[bit] = 0

        self.value = u4(next_value)
        return self.value
