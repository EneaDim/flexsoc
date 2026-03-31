#!/usr/bin/env python3
"""
Common utilities shared by the CORDIC floating-point and fixed-point models.

This file intentionally contains:
- shared dataclasses
- shared enums
- fixed-point conversion helpers
- angle normalization helpers
- LUT generation
- generic numerical utilities

The goal is to keep the modeling stack layered and easy to understand:
    math / algorithmic model
        ->
    fixed-point visible-behavior model
        ->
    RTL
"""

from __future__ import annotations

import math
from dataclasses import asdict, dataclass, field
from enum import Enum
from typing import List


# -----------------------------------------------------------------------------
# Global constants
# -----------------------------------------------------------------------------
TWO_PI = 2.0 * math.pi
PI = math.pi
HALF_PI = math.pi / 2.0


# -----------------------------------------------------------------------------
# Enumerations
# -----------------------------------------------------------------------------
class CordicMode(str, Enum):
    """Supported CORDIC operating modes."""
    ROTATION = "rotation"
    VECTORING = "vectoring"


# -----------------------------------------------------------------------------
# Shared dataclasses
# -----------------------------------------------------------------------------
@dataclass
class FixedFormat:
    """
    Fixed-point format description.

    Example:
        width = 16, frac = 14, signed = True
    corresponds to a signed Q2.14 interpretation.
    """
    width: int = 16
    frac: int = 14
    signed: bool = True

    @property
    def scale(self) -> int:
        return 1 << self.frac

    @property
    def min_int(self) -> int:
        if self.signed:
            return -(1 << (self.width - 1))
        return 0

    @property
    def max_int(self) -> int:
        if self.signed:
            return (1 << (self.width - 1)) - 1
        return (1 << self.width) - 1

    @property
    def min_val(self) -> float:
        return self.min_int / self.scale

    @property
    def max_val(self) -> float:
        return self.max_int / self.scale


@dataclass
class CordicConfig:
    """
    High-level CORDIC numerical configuration.

    Notes
    -----
    - data_format describes the externally visible x/y format.
    - angle_format describes the externally visible z/angle format.
    - internal_guard_bits is kept here because it influences observable results
      through saturation and intermediate arithmetic, even though it is not part
      of the software-visible register map.
    """
    data_format: FixedFormat = field(
        default_factory=lambda: FixedFormat(width=16, frac=14, signed=True)
    )
    angle_format: FixedFormat = field(
        default_factory=lambda: FixedFormat(width=16, frac=13, signed=True)
    )
    iterations: int = 16
    compensate_gain: bool = True
    internal_guard_bits: int = 3
    saturate_output: bool = True


@dataclass
class CordicResultFloat:
    """Floating-point CORDIC result."""
    x: float
    y: float
    z: float


@dataclass
class CordicResultFixed:
    """Fixed-point CORDIC result using raw signed integers."""
    x: int
    y: int
    z: int


@dataclass
class TestVector:
    """
    Generic test vector format.

    Both float and fixed-point representations are kept so the same vector can
    be reused in Python analysis, CSV export, cocotb, or SystemVerilog TBs.
    """
    mode: str

    x_in_float: float
    y_in_float: float
    z_in_float: float

    x_in_fixed: int
    y_in_fixed: int
    z_in_fixed: int

    x_out_float: float
    y_out_float: float
    z_out_float: float

    x_out_fixed: int
    y_out_fixed: int
    z_out_fixed: int


# -----------------------------------------------------------------------------
# Generic math helpers
# -----------------------------------------------------------------------------
def normalize_angle_pm_pi(angle_rad: float) -> float:
    """Normalize an angle into the interval [-pi, pi)."""
    return (angle_rad + PI) % TWO_PI - PI


def cordic_gain(iterations: int) -> float:
    """Return the circular CORDIC gain after a given number of iterations."""
    gain = 1.0
    for i in range(iterations):
        gain *= math.sqrt(1.0 + 2.0 ** (-2 * i))
    return gain


def cordic_gain_inverse(iterations: int) -> float:
    """Return the inverse of the circular CORDIC gain."""
    return 1.0 / cordic_gain(iterations)


# -----------------------------------------------------------------------------
# Fixed-point conversion helpers
# -----------------------------------------------------------------------------
def saturate_int(value: int, fmt: FixedFormat) -> int:
    """Clamp a raw integer to the representable range of a fixed-point format."""
    if value < fmt.min_int:
        return fmt.min_int
    if value > fmt.max_int:
        return fmt.max_int
    return value


def wrap_to_width(value: int, width: int) -> int:
    """
    Wrap an integer to a given bit width and interpret it as signed two's
    complement.
    """
    mask = (1 << width) - 1
    value &= mask
    sign_bit = 1 << (width - 1)
    if value & sign_bit:
        value -= (1 << width)
    return value


def float_to_fixed(value: float, fmt: FixedFormat, *, rounding: str = "nearest") -> int:
    """
    Convert a Python float into a raw fixed-point integer.
    """
    scaled = value * fmt.scale

    if rounding == "nearest":
        raw = int(round(scaled))
    elif rounding == "trunc":
        raw = int(scaled)
    elif rounding == "floor":
        raw = math.floor(scaled)
    elif rounding == "ceil":
        raw = math.ceil(scaled)
    else:
        raise ValueError(f"Unsupported rounding mode: {rounding}")

    return saturate_int(raw, fmt)


def fixed_to_float(raw: int, fmt: FixedFormat) -> float:
    """Convert a raw fixed-point integer into a Python float."""
    return raw / fmt.scale


def arithmetic_shift_right(value: int, amount: int, width: int) -> int:
    """
    Perform an arithmetic right shift and re-wrap the result to a signed width.
    """
    shifted = value >> amount
    return wrap_to_width(shifted, width)


def get_internal_data_format(cfg: CordicConfig) -> FixedFormat:
    """
    Build the internal x/y datapath format.

    The binary point is unchanged. Only the width is increased by the configured
    number of guard bits.
    """
    return FixedFormat(
        width=cfg.data_format.width + cfg.internal_guard_bits,
        frac=cfg.data_format.frac,
        signed=cfg.data_format.signed,
    )


def saturate_to_width(value: int, width: int) -> int:
    """Saturate a signed integer to the representable range of a given width."""
    min_int = -(1 << (width - 1))
    max_int = (1 << (width - 1)) - 1
    if value < min_int:
        return min_int
    if value > max_int:
        return max_int
    return value


def quantize_output_data(value: int, cfg: CordicConfig) -> int:
    """
    Convert an internal x/y datapath value back to the externally visible width.
    """
    if cfg.saturate_output:
        return saturate_to_width(value, cfg.data_format.width)
    return wrap_to_width(value, cfg.data_format.width)


# -----------------------------------------------------------------------------
# LUT generation
# -----------------------------------------------------------------------------
def build_atan_lut_float(iterations: int) -> List[float]:
    """Generate atan(2^-i) LUT values in radians."""
    return [math.atan(2.0 ** (-i)) for i in range(iterations)]


def build_atan_lut_fixed(iterations: int, angle_fmt: FixedFormat) -> List[int]:
    """Generate atan(2^-i) LUT values in raw fixed-point representation."""
    return [float_to_fixed(math.atan(2.0 ** (-i)), angle_fmt) for i in range(iterations)]


__all__ = [
    "TWO_PI",
    "PI",
    "HALF_PI",
    "CordicMode",
    "FixedFormat",
    "CordicConfig",
    "CordicResultFloat",
    "CordicResultFixed",
    "TestVector",
    "normalize_angle_pm_pi",
    "cordic_gain",
    "cordic_gain_inverse",
    "saturate_int",
    "wrap_to_width",
    "float_to_fixed",
    "fixed_to_float",
    "arithmetic_shift_right",
    "get_internal_data_format",
    "saturate_to_width",
    "quantize_output_data",
    "build_atan_lut_float",
    "build_atan_lut_fixed",
    "asdict",
]
