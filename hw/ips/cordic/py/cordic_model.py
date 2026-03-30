#!/usr/bin/env python3
"""
CORDIC reference model for RTL development and verification.

This module provides:
- floating-point helpers
- fixed-point conversion helpers
- angle normalization utilities
- CORDIC LUT generation
- iterative CORDIC model for:
  * rotation mode
  * vectoring mode
- convenience wrappers for:
  * sin/cos
  * atan2/magnitude
- simple directed and random test vector generation

The main goal of this file is to serve as the golden reference for the
SystemVerilog RTL implementation and for cocotb-based verification.

The code is intentionally heavily commented and explicit, so that it is easy
to review together with the RTL and easy to reuse in future arithmetic IPs.
"""

from __future__ import annotations

import argparse
import csv
import json
import math
import random
from dataclasses import asdict, dataclass, field
from enum import Enum
from typing import List, Sequence, Tuple


# =============================================================================
# Constants
# =============================================================================

# Full turn in radians.
TWO_PI = 2.0 * math.pi

# Half turn in radians.
PI = math.pi

# Quarter turn in radians.
HALF_PI = math.pi / 2.0


# =============================================================================
# Enumerations
# =============================================================================

class CordicMode(str, Enum):
    """
    Supported CORDIC modes.

    ROTATION:
        Rotates an input vector (x, y) by an angle z.

    VECTORING:
        Drives y toward zero while accumulating the angle in z.
        This mode is commonly used to estimate magnitude and atan2.
    """
    ROTATION = "rotation"
    VECTORING = "vectoring"


# =============================================================================
# Dataclasses for configuration and results
# =============================================================================

@dataclass
class FixedFormat:
    """
    Fixed-point format description.

    Attributes
    ----------
    width:
        Total number of bits.
    frac:
        Number of fractional bits.
    signed:
        Whether the representation is signed two's complement.

    Notes
    -----
    For example:
        width = 16, frac = 14, signed = True
    corresponds to a signed Q2.14 interpretation.

    The numerical range for signed fixed-point is:
        min = -2^(width-1) / 2^frac
        max = (2^(width-1)-1) / 2^frac
    """
    width: int = 16
    frac: int = 14
    signed: bool = True

    @property
    def scale(self) -> int:
        """Return the scaling factor equal to 2^frac."""
        return 1 << self.frac

    @property
    def min_int(self) -> int:
        """Minimum representable raw integer value."""
        if self.signed:
            return -(1 << (self.width - 1))
        return 0

    @property
    def max_int(self) -> int:
        """Maximum representable raw integer value."""
        if self.signed:
            return (1 << (self.width - 1)) - 1
        return (1 << self.width) - 1

    @property
    def min_val(self) -> float:
        """Minimum representable real value."""
        return self.min_int / self.scale

    @property
    def max_val(self) -> float:
        """Maximum representable real value."""
        return self.max_int / self.scale


@dataclass
class CordicConfig:
    """
    High-level CORDIC configuration.

    Attributes
    ----------
    data_format:
        Fixed-point format for externally visible x and y data paths.
    angle_format:
        Fixed-point format for externally visible z / angle path.

        Important:
        To support a full angular domain in [-pi, pi), the angle path must be
        able to represent pi. Therefore the default angle format is Q3.13
        (width=16, frac=13), not Q2.14.
    iterations:
        Number of CORDIC iterations.
    compensate_gain:
        Whether convenience wrappers should compensate the CORDIC gain.
    internal_guard_bits:
        Number of extra guard bits used on the internal x/y datapath to reduce
        intermediate overflow during the iterative updates.
    saturate_output:
        If True, the final externally visible x/y outputs are saturated to the
        configured output width. If False, they are wrapped.
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
    """
    Floating-point result from the reference model.

    x, y, z are real-valued quantities in Python float representation.
    """
    x: float
    y: float
    z: float


@dataclass
class CordicResultFixed:
    """
    Fixed-point result from the reference model.

    x, y, z are raw signed integers corresponding to the chosen fixed format.
    """
    x: int
    y: int
    z: int


@dataclass
class TestVector:
    """
    Generic test vector representation.

    Both float and fixed-point values are stored so that the same vector can
    be used by:
    - Python-only regression
    - cocotb
    - SystemVerilog file-driven testbenches
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


# =============================================================================
# Generic math helpers
# =============================================================================

def normalize_angle_pm_pi(angle_rad: float) -> float:
    """
    Normalize an angle into the interval [-pi, pi).

    This helper is useful because CORDIC angle handling becomes much easier
    when inputs are constrained to a canonical range.

    Parameters
    ----------
    angle_rad:
        Input angle in radians.

    Returns
    -------
    float
        Equivalent angle in the range [-pi, pi).
    """
    wrapped = (angle_rad + PI) % TWO_PI - PI
    return wrapped


def cordic_gain(iterations: int) -> float:
    """
    Compute the CORDIC gain after a given number of iterations.

    The standard circular CORDIC gain is:

        K_n = product over i=0..n-1 of sqrt(1 + 2^(-2i))

    Many textbook references use:
        1 / K_n
    as the pre-scaling factor for sin/cos generation.

    Parameters
    ----------
    iterations:
        Number of CORDIC iterations.

    Returns
    -------
    float
        Gain K_n.
    """
    gain = 1.0
    for i in range(iterations):
        gain *= math.sqrt(1.0 + 2.0 ** (-2 * i))
    return gain


def cordic_gain_inverse(iterations: int) -> float:
    """
    Return the inverse CORDIC gain.

    This is commonly used to pre-scale the initial x input when using rotation
    mode to generate sine and cosine directly.
    """
    return 1.0 / cordic_gain(iterations)


# =============================================================================
# Fixed-point conversion helpers
# =============================================================================

def saturate_int(value: int, fmt: FixedFormat) -> int:
    """
    Saturate an integer to the representable range of a fixed-point format.

    Parameters
    ----------
    value:
        Raw integer value to clamp.
    fmt:
        Fixed-point format.

    Returns
    -------
    int
        Clamped integer.
    """
    if value < fmt.min_int:
        return fmt.min_int
    if value > fmt.max_int:
        return fmt.max_int
    return value


def wrap_to_width(value: int, width: int) -> int:
    """
    Wrap an integer to a given bit width.

    This helper emulates hardware-style truncation to 'width' bits and then
    interprets the result as signed two's complement.

    Parameters
    ----------
    value:
        Arbitrary Python integer.
    width:
        Number of bits to keep.

    Returns
    -------
    int
        Signed integer after width truncation.
    """
    mask = (1 << width) - 1
    value &= mask
    sign_bit = 1 << (width - 1)
    if value & sign_bit:
        value -= (1 << width)
    return value


def float_to_fixed(value: float, fmt: FixedFormat, *, rounding: str = "nearest") -> int:
    """
    Convert a Python float to fixed-point raw integer.

    Parameters
    ----------
    value:
        Real value to convert.
    fmt:
        Fixed-point format.
    rounding:
        Rounding policy:
            - "nearest": round to nearest integer
            - "trunc": truncate toward zero
            - "floor": mathematical floor
            - "ceil": mathematical ceil

    Returns
    -------
    int
        Saturated raw integer representation.

    Notes
    -----
    The return value is the raw fixed-point integer, not the scaled float.
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
    """
    Convert a raw fixed-point integer into a Python float.

    Parameters
    ----------
    raw:
        Raw integer value.
    fmt:
        Fixed-point format.

    Returns
    -------
    float
        Real-valued interpretation.
    """
    return raw / fmt.scale


def arithmetic_shift_right(value: int, amount: int, width: int) -> int:
    """
    Perform an arithmetic right shift with signed width-limited behavior.

    Python's right shift on negative integers is already arithmetic, but this
    helper makes the hardware intent explicit and re-wraps the result to the
    target width.

    Parameters
    ----------
    value:
        Signed integer.
    amount:
        Shift amount.
    width:
        Datapath width.

    Returns
    -------
    int
        Shifted and width-limited signed integer.
    """
    shifted = value >> amount
    return wrap_to_width(shifted, width)


def get_internal_data_format(cfg: CordicConfig) -> FixedFormat:
    """
    Build the internal x/y datapath format.

    The internal datapath keeps the same number of fractional bits as the
    external format, but increases the total width with extra guard bits.
    """
    return FixedFormat(
        width=cfg.data_format.width + cfg.internal_guard_bits,
        frac=cfg.data_format.frac,
        signed=cfg.data_format.signed,
    )


def saturate_to_width(value: int, width: int) -> int:
    """
    Saturate a signed integer to the representable range of a given width.
    """
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

    The internal and external x/y paths share the same fractional bit count, so
    no binary-point shift is needed. Only width reduction is required.
    """
    if cfg.saturate_output:
        return saturate_to_width(value, cfg.data_format.width)
    return wrap_to_width(value, cfg.data_format.width)


# =============================================================================
# LUT generation
# =============================================================================

def build_atan_lut_float(iterations: int) -> List[float]:
    """
    Generate the floating-point atan LUT.

    Entry i is:
        atan(2^-i)

    Parameters
    ----------
    iterations:
        Number of entries to generate.

    Returns
    -------
    list[float]
        LUT in radians.
    """
    return [math.atan(2.0 ** (-i)) for i in range(iterations)]


def build_atan_lut_fixed(iterations: int, angle_fmt: FixedFormat) -> List[int]:
    """
    Generate the fixed-point atan LUT.

    Parameters
    ----------
    iterations:
        Number of entries to generate.
    angle_fmt:
        Fixed-point format used for the z/angle path.

    Returns
    -------
    list[int]
        Fixed-point LUT entries.
    """
    return [float_to_fixed(math.atan(2.0 ** (-i)), angle_fmt) for i in range(iterations)]


# =============================================================================
# Floating-point CORDIC model
# =============================================================================

def cordic_rotate_float(
    x_in: float,
    y_in: float,
    z_in: float,
    iterations: int,
) -> CordicResultFloat:
    """
    Floating-point CORDIC in rotation mode.

    Rotation mode attempts to rotate the vector (x, y) by angle z.
    The iterative update is:

        if z >= 0:
            x' = x - y * 2^-i
            y' = y + x * 2^-i
            z' = z - atan(2^-i)
        else:
            x' = x + y * 2^-i
            y' = y - x * 2^-i
            z' = z + atan(2^-i)

    Parameters
    ----------
    x_in, y_in, z_in:
        Input vector and angle.
    iterations:
        Number of CORDIC iterations.

    Returns
    -------
    CordicResultFloat
        Final x, y, z values.
    """
    x = x_in
    y = y_in
    z = z_in

    lut = build_atan_lut_float(iterations)

    for i in range(iterations):
        step = 2.0 ** (-i)

        if z >= 0.0:
            x_next = x - y * step
            y_next = y + x * step
            z_next = z - lut[i]
        else:
            x_next = x + y * step
            y_next = y - x * step
            z_next = z + lut[i]

        x, y, z = x_next, y_next, z_next

    return CordicResultFloat(x=x, y=y, z=z)


def cordic_vector_float(
    x_in: float,
    y_in: float,
    z_in: float,
    iterations: int,
) -> CordicResultFloat:
    """
    Floating-point CORDIC in vectoring mode.

    Vectoring mode attempts to drive y toward zero while accumulating the
    angle into z.

    A common textbook update is:

        if y >= 0:
            x' = x + y * 2^-i
            y' = y - x * 2^-i
            z' = z + atan(2^-i)
        else:
            x' = x - y * 2^-i
            y' = y + x * 2^-i
            z' = z - atan(2^-i)

    Parameters
    ----------
    x_in, y_in, z_in:
        Input vector and initial angle accumulator.
    iterations:
        Number of CORDIC iterations.

    Returns
    -------
    CordicResultFloat
        Final x, y, z values.
    """
    x = x_in
    y = y_in
    z = z_in

    lut = build_atan_lut_float(iterations)

    for i in range(iterations):
        step = 2.0 ** (-i)

        if y >= 0.0:
            x_next = x + y * step
            y_next = y - x * step
            z_next = z + lut[i]
        else:
            x_next = x - y * step
            y_next = y + x * step
            z_next = z - lut[i]

        x, y, z = x_next, y_next, z_next

    return CordicResultFloat(x=x, y=y, z=z)


# =============================================================================
# Fixed-point CORDIC model
# =============================================================================

def cordic_rotate_fixed(
    x_in: int,
    y_in: int,
    z_in: int,
    cfg: CordicConfig,
) -> CordicResultFixed:
    """
    Fixed-point CORDIC in rotation mode.

    This implementation uses an internal x/y datapath with guard bits to reduce
    intermediate overflow and better match a production RTL implementation.

    Notes
    -----
    - The binary point is unchanged between external and internal x/y paths.
    - The z/angle path keeps the external angle width.
    - Final x/y results are quantized back to the externally visible width.
    """
    internal_fmt = get_internal_data_format(cfg)
    data_width_int = internal_fmt.width
    angle_width = cfg.angle_format.width

    # Sign-extend into the internal datapath by re-wrapping to the wider width.
    x = wrap_to_width(x_in, data_width_int)
    y = wrap_to_width(y_in, data_width_int)
    z = wrap_to_width(z_in, angle_width)

    lut = build_atan_lut_fixed(cfg.iterations, cfg.angle_format)

    for i in range(cfg.iterations):
        x_shift = arithmetic_shift_right(x, i, data_width_int)
        y_shift = arithmetic_shift_right(y, i, data_width_int)

        if z >= 0:
            x_next = x - y_shift
            y_next = y + x_shift
            z_next = z - lut[i]
        else:
            x_next = x + y_shift
            y_next = y - x_shift
            z_next = z + lut[i]

        x = wrap_to_width(x_next, data_width_int)
        y = wrap_to_width(y_next, data_width_int)
        z = wrap_to_width(z_next, angle_width)

    x_out = quantize_output_data(x, cfg)
    y_out = quantize_output_data(y, cfg)

    return CordicResultFixed(x=x_out, y=y_out, z=z)


def cordic_vector_fixed(
    x_in: int,
    y_in: int,
    z_in: int,
    cfg: CordicConfig,
) -> CordicResultFixed:
    """
    Fixed-point CORDIC in vectoring mode.

    This implementation uses an internal x/y datapath with guard bits to reduce
    intermediate overflow and better match a production RTL implementation.
    """
    internal_fmt = get_internal_data_format(cfg)
    data_width_int = internal_fmt.width
    angle_width = cfg.angle_format.width

    x = wrap_to_width(x_in, data_width_int)
    y = wrap_to_width(y_in, data_width_int)
    z = wrap_to_width(z_in, angle_width)

    lut = build_atan_lut_fixed(cfg.iterations, cfg.angle_format)

    for i in range(cfg.iterations):
        x_shift = arithmetic_shift_right(x, i, data_width_int)
        y_shift = arithmetic_shift_right(y, i, data_width_int)

        if y >= 0:
            x_next = x + y_shift
            y_next = y - x_shift
            z_next = z + lut[i]
        else:
            x_next = x - y_shift
            y_next = y + x_shift
            z_next = z - lut[i]

        x = wrap_to_width(x_next, data_width_int)
        y = wrap_to_width(y_next, data_width_int)
        z = wrap_to_width(z_next, angle_width)

    x_out = quantize_output_data(x, cfg)
    y_out = quantize_output_data(y, cfg)

    return CordicResultFixed(x=x_out, y=y_out, z=z)


# =============================================================================
# High-level convenience wrappers
# =============================================================================

def _rotation_prerotate_float(x_in: float, y_in: float, z_in: float) -> Tuple[float, float, float]:
    """
    Pre-rotate the rotation-mode input so that the residual angle falls inside
    the main CORDIC convergence interval.

    The basic circular CORDIC rotation converges well when the residual angle is
    roughly inside [-pi/2, pi/2]. To support the full domain [-pi, pi), we
    perform a simple pre-rotation by +/- pi when needed.

    Mapping strategy
    ----------------
    If z is outside [-pi/2, pi/2], rotating the input vector by pi is
    equivalent to negating both x and y, while subtracting or adding pi from z.

    This keeps the final mathematical rotation identical while ensuring the
    iterative core only sees angles in the main convergence region.
    """
    z = normalize_angle_pm_pi(z_in)
    x = x_in
    y = y_in

    if z > HALF_PI:
        x = -x
        y = -y
        z = z - PI
    elif z < -HALF_PI:
        x = -x
        y = -y
        z = z + PI

    z = normalize_angle_pm_pi(z)
    return x, y, z


def _rotation_prerotate_fixed(x_in: int, y_in: int, z_in: int, cfg: CordicConfig) -> CordicResultFixed:
    """
    Fixed-point equivalent of the rotation-mode pre-rotation helper.

    This function is intentionally written in a very RTL-friendly way:
    - compare against fixed-point +/- pi/2 thresholds
    - negate x and y when a pre-rotation by pi is required
    - adjust z by +/- pi
    - wrap all results to their target width
    """
    x = wrap_to_width(x_in, cfg.data_format.width)
    y = wrap_to_width(y_in, cfg.data_format.width)
    z = wrap_to_width(z_in, cfg.angle_format.width)

    half_pi_q = float_to_fixed(HALF_PI, cfg.angle_format)
    pi_q = float_to_fixed(PI, cfg.angle_format)

    if z > half_pi_q:
        x = wrap_to_width(-x, cfg.data_format.width)
        y = wrap_to_width(-y, cfg.data_format.width)
        z = wrap_to_width(z - pi_q, cfg.angle_format.width)
    elif z < -half_pi_q:
        x = wrap_to_width(-x, cfg.data_format.width)
        y = wrap_to_width(-y, cfg.data_format.width)
        z = wrap_to_width(z + pi_q, cfg.angle_format.width)

    return CordicResultFixed(x=x, y=y, z=z)


def _vectoring_prerotate_float(x_in: float, y_in: float, z_in: float = 0.0) -> Tuple[float, float, float]:
    """
    Pre-rotate the vectoring-mode input so that the internal vectoring step sees
    x >= 0, while the final output angle still represents the full atan2
    domain in [-pi, pi).

    Mapping strategy
    ----------------
    If x < 0, we rotate the vector by pi:
        (x, y) -> (-x, -y)

    This brings the x component to the right half-plane, which is favorable for
    the base vectoring iteration.

    The corresponding angular correction is:
    - +pi if the original vector was in quadrant II
    - -pi if the original vector was in quadrant III or on the negative x axis
      with negative y

    For the exact negative x axis with y == 0, we intentionally choose the
    canonical normalized result -pi rather than +pi, because the project uses
    the interval [-pi, pi).
    """
    x = x_in
    y = y_in
    z = z_in

    if x < 0.0:
        if y >= 0.0:
            z += PI
        else:
            z -= PI
        x = -x
        y = -y

    z = normalize_angle_pm_pi(z)
    return x, y, z


def _vectoring_prerotate_fixed(x_in: int, y_in: int, z_in: int, cfg: CordicConfig) -> CordicResultFixed:
    """
    Fixed-point equivalent of the vectoring-mode pre-rotation helper.

    Important
    ---------
    This helper must use the *internal* x/y datapath width, not the externally
    visible width. Otherwise corner cases such as the minimum two's-complement
    value would wrap incorrectly before the guard-bit datapath has a chance to
    absorb the negation.

    This is one of the key details required to keep the Python model bit-aligned
    with the RTL implementation.
    """
    internal_width = cfg.data_format.width + cfg.internal_guard_bits

    x = wrap_to_width(x_in, internal_width)
    y = wrap_to_width(y_in, internal_width)
    z = wrap_to_width(z_in, cfg.angle_format.width)

    pi_q = float_to_fixed(PI, cfg.angle_format)

    # Explicit zero-vector handling.
    # The angle of the null vector is undefined mathematically, but for a
    # hardware-friendly deterministic behavior we choose to return z = 0.
    if x == 0 and y == 0:
        return CordicResultFixed(x=0, y=0, z=0)

    if x < 0:
        if y >= 0:
            z = wrap_to_width(z + pi_q, cfg.angle_format.width)
        else:
            z = wrap_to_width(z - pi_q, cfg.angle_format.width)

        x = wrap_to_width(-x, internal_width)
        y = wrap_to_width(-y, internal_width)

    return CordicResultFixed(x=x, y=y, z=z)


def _sincos_fixed_full_range(angle_rad: float, cfg: CordicConfig) -> CordicResultFixed:
    """
    Full-range fixed-point sine/cosine wrapper.

    This helper:
    - normalizes the requested angle to [-pi, pi)
    - builds the standard pre-scaled initial vector
    - applies quadrant-aware pre-rotation
    - runs the base fixed-point CORDIC rotation kernel
    """
    angle_rad = normalize_angle_pm_pi(angle_rad)

    x0_f = cordic_gain_inverse(cfg.iterations) if cfg.compensate_gain else 1.0
    y0_f = 0.0
    z0_f = angle_rad

    x0_q = float_to_fixed(x0_f, cfg.data_format)
    y0_q = float_to_fixed(y0_f, cfg.data_format)
    z0_q = float_to_fixed(z0_f, cfg.angle_format)

    pre = _rotation_prerotate_fixed(x0_q, y0_q, z0_q, cfg)
    return cordic_rotate_fixed(pre.x, pre.y, pre.z, cfg)


def _vectoring_fixed_full_range(x_in_raw: int, y_in_raw: int, cfg: CordicConfig) -> CordicResultFixed:
    """
    Full-range fixed-point vectoring wrapper.

    This helper:
    - applies quadrant-aware pre-rotation based on the sign of x
    - runs the base fixed-point vectoring kernel
    - returns the raw fixed-point magnitude*gain and angle estimate
    """
    z0_q = float_to_fixed(0.0, cfg.angle_format)
    pre = _vectoring_prerotate_fixed(x_in_raw, y_in_raw, z0_q, cfg)
    result = cordic_vector_fixed(pre.x, pre.y, pre.z, cfg)
    return CordicResultFixed(
        x=result.x,
        y=result.y,
        z=wrap_to_width(result.z, cfg.angle_format.width),
    )


def sincos_float(angle_rad: float, iterations: int) -> Tuple[float, float]:
    """
    Compute cosine and sine using floating-point CORDIC rotation mode with
    full-range angle support.

    The initial vector is pre-scaled by 1/K so that the final output directly
    approximates cos(angle) and sin(angle).
    """
    x0 = cordic_gain_inverse(iterations)
    y0 = 0.0
    z0 = normalize_angle_pm_pi(angle_rad)

    x1, y1, z1 = _rotation_prerotate_float(x0, y0, z0)
    result = cordic_rotate_float(x1, y1, z1, iterations)
    return result.x, result.y


def sincos_fixed(angle_rad: float, cfg: CordicConfig) -> CordicResultFixed:
    """
    Compute cosine and sine using the fixed-point CORDIC model with full-range
    support on [-pi, pi).
    """
    return _sincos_fixed_full_range(angle_rad, cfg)


def atan2_mag_float(x_in: float, y_in: float, iterations: int) -> Tuple[float, float]:
    """
    Compute magnitude and angle using floating-point CORDIC vectoring mode with
    full-quadrant atan2 support.
    """
    x1, y1, z1 = _vectoring_prerotate_float(x_in, y_in, 0.0)
    result = cordic_vector_float(x1, y1, z1, iterations)

    magnitude = result.x / cordic_gain(iterations)
    angle = normalize_angle_pm_pi(result.z)
    return magnitude, angle


def atan2_mag_fixed(x_in: float, y_in: float, cfg: CordicConfig) -> CordicResultFloat:
    """
    Compute magnitude and angle using the fixed-point CORDIC model with
    full-quadrant atan2 support.

    The output is converted back to float for user-friendly inspection.
    """
    x_raw = float_to_fixed(x_in, cfg.data_format)
    y_raw = float_to_fixed(y_in, cfg.data_format)

    result_raw = _vectoring_fixed_full_range(x_raw, y_raw, cfg)

    x_float = fixed_to_float(result_raw.x, cfg.data_format)
    y_float = fixed_to_float(result_raw.y, cfg.data_format)
    z_float = fixed_to_float(result_raw.z, cfg.angle_format)

    # The x output of vectoring mode still includes the CORDIC gain.
    x_float /= cordic_gain(cfg.iterations)
    z_float = normalize_angle_pm_pi(z_float)

    return CordicResultFloat(x=x_float, y=y_float, z=z_float)


# =============================================================================
# Quadrant-aware helpers
# =============================================================================
# =============================================================================
# Quadrant-aware helpers
# =============================================================================

def sincos_math_reference(angle_rad: float) -> Tuple[float, float]:
    """
    Exact Python math-library reference for cosine and sine.
    """
    return math.cos(angle_rad), math.sin(angle_rad)


def atan2_math_reference(x_in: float, y_in: float) -> Tuple[float, float]:
    """
    Exact Python math-library reference for magnitude and angle.

    Returns
    -------
    (magnitude, angle)
    """
    magnitude = math.hypot(x_in, y_in)
    angle = math.atan2(y_in, x_in)
    return magnitude, angle


# =============================================================================
# Test vector generation
# =============================================================================

def create_rotation_test_vector(angle_rad: float, cfg: CordicConfig) -> TestVector:
    """
    Build a single rotation-mode test vector for sin/cos use.

    The externally visible input vector is the standard sin/cos setup:
        x0 = 1 / K
        y0 = 0
        z0 = angle

    Internally, the full-range wrapper may apply a quadrant-aware pre-rotation,
    but that is intentionally hidden from the test vector because the vector
    should represent the programmer-visible CSR input.
    """
    angle_rad = normalize_angle_pm_pi(angle_rad)

    x0_f = cordic_gain_inverse(cfg.iterations) if cfg.compensate_gain else 1.0
    y0_f = 0.0
    z0_f = angle_rad

    x0_q = float_to_fixed(x0_f, cfg.data_format)
    y0_q = float_to_fixed(y0_f, cfg.data_format)
    z0_q = float_to_fixed(z0_f, cfg.angle_format)

    out_q = _sincos_fixed_full_range(angle_rad, cfg)

    return TestVector(
        mode=CordicMode.ROTATION.value,
        x_in_float=x0_f,
        y_in_float=y0_f,
        z_in_float=z0_f,
        x_in_fixed=x0_q,
        y_in_fixed=y0_q,
        z_in_fixed=z0_q,
        x_out_float=fixed_to_float(out_q.x, cfg.data_format),
        y_out_float=fixed_to_float(out_q.y, cfg.data_format),
        z_out_float=fixed_to_float(out_q.z, cfg.angle_format),
        x_out_fixed=out_q.x,
        y_out_fixed=out_q.y,
        z_out_fixed=out_q.z,
    )


def create_vectoring_test_vector(x_in: float, y_in: float, cfg: CordicConfig) -> TestVector:
    """
    Build a single vectoring-mode test vector.

    The externally visible interface is:
        x_in, y_in, z_in = 0

    Internally, the full-range vectoring wrapper may apply a pre-rotation to
    ensure robust full-quadrant atan2 behavior.
    """
    x_q = float_to_fixed(x_in, cfg.data_format)
    y_q = float_to_fixed(y_in, cfg.data_format)
    z_q = float_to_fixed(0.0, cfg.angle_format)

    out_q = _vectoring_fixed_full_range(x_q, y_q, cfg)

    x_out_f = fixed_to_float(out_q.x, cfg.data_format) / cordic_gain(cfg.iterations)
    y_out_f = fixed_to_float(out_q.y, cfg.data_format)
    z_out_f = normalize_angle_pm_pi(fixed_to_float(out_q.z, cfg.angle_format))

    return TestVector(
        mode=CordicMode.VECTORING.value,
        x_in_float=x_in,
        y_in_float=y_in,
        z_in_float=0.0,
        x_in_fixed=x_q,
        y_in_fixed=y_q,
        z_in_fixed=z_q,
        x_out_float=x_out_f,
        y_out_float=y_out_f,
        z_out_float=z_out_f,
        x_out_fixed=out_q.x,
        y_out_fixed=out_q.y,
        z_out_fixed=out_q.z,
    )


def generate_directed_rotation_vectors(cfg: CordicConfig) -> List[TestVector]:
    """
    Generate a rich directed set of rotation-mode vectors.

    This set intentionally includes:
    - zero
    - minimum / maximum representable angle values
    - canonical trigonometric angles
    - boundary-adjacent values near +/- pi/2 and +/- pi
    - a few seeded random samples for quick coverage expansion
    """
    angle_lsb = 1.0 / cfg.angle_format.scale
    rng = random.Random(2026)

    angles = [
        0.0,
        cfg.angle_format.min_val,
        cfg.angle_format.max_val,
        -PI,
        -PI + angle_lsb,
        -3.0 * PI / 4.0,
        -HALF_PI - angle_lsb,
        -HALF_PI,
        -HALF_PI + angle_lsb,
        -PI / 3.0,
        -PI / 4.0,
        -PI / 6.0,
        -angle_lsb,
        angle_lsb,
        PI / 6.0,
        PI / 4.0,
        PI / 3.0,
        HALF_PI - angle_lsb,
        HALF_PI,
        HALF_PI + angle_lsb,
        3.0 * PI / 4.0,
        PI - angle_lsb,
    ]

    # Add a few deterministic random angles to the directed pool.
    for _ in range(8):
        angles.append(rng.uniform(-PI, PI))

    # Normalize and de-duplicate while preserving determinism.
    normalized = [normalize_angle_pm_pi(a) for a in angles]
    unique = list(dict.fromkeys(round(a, 15) for a in normalized))

    return [create_rotation_test_vector(a, cfg) for a in unique]


def generate_directed_vectoring_vectors(cfg: CordicConfig) -> List[TestVector]:
    """
    Generate a rich directed set of vectoring-mode vectors.

    This set intentionally includes:
    - exact zero
    - min / max representable values
    - axis-aligned points
    - all Cartesian corners
    - near-axis and near-boundary points
    - a few seeded random samples
    """
    min_v = cfg.data_format.min_val
    max_v = cfg.data_format.max_val
    lsb = 1.0 / cfg.data_format.scale
    rng = random.Random(2026)

    points = [
        (0.0, 0.0),

        # Pure min / max stress points.
        (min_v, 0.0),
        (max_v, 0.0),
        (0.0, min_v),
        (0.0, max_v),

        # Small values near zero.
        (lsb, 0.0),
        (-lsb, 0.0),
        (0.0, lsb),
        (0.0, -lsb),

        # Moderate axis-aligned values.
        (0.5, 0.0),
        (-0.5, 0.0),
        (0.0, 0.5),
        (0.0, -0.5),

        # Moderate quadrant coverage.
        (0.5, 0.5),
        (0.5, -0.5),
        (-0.5, 0.5),
        (-0.5, -0.5),

        # Full dynamic-range corners.
        (max_v, max_v),
        (max_v, min_v),
        (min_v, max_v),
        (min_v, min_v),

        # Near-axis / near-boundary cases.
        (max_v, lsb),
        (max_v, -lsb),
        (lsb, max_v),
        (lsb, min_v),
        (-max_v, lsb),
        (-max_v, -lsb),
        (-lsb, max_v),
        (-lsb, min_v),
    ]

    # Add a few deterministic random samples across the full representable range.
    for _ in range(12):
        points.append(
            (
                rng.uniform(min_v, max_v),
                rng.uniform(min_v, max_v),
            )
        )

    unique = list(dict.fromkeys((round(x, 15), round(y, 15)) for x, y in points))
    return [create_vectoring_test_vector(x, y, cfg) for x, y in unique]


def generate_random_rotation_vectors(cfg: CordicConfig, count: int, seed: int = 1234) -> List[TestVector]:
    """
    Generate random rotation-mode vectors over the full angular domain [-pi, pi).
    """
    rng = random.Random(seed)
    vectors = []
    for _ in range(count):
        angle = rng.uniform(-PI, PI)
        vectors.append(create_rotation_test_vector(angle, cfg))
    return vectors


def generate_random_vectoring_vectors(cfg: CordicConfig, count: int, seed: int = 1234) -> List[TestVector]:
    """
    Generate random vectoring-mode vectors over the full representable input
    range of the configured data format.

    Important
    ---------
    These random vectors are intentionally broad because they are meant to
    expose difficult corner behavior, including possible intermediate overflow.
    """
    rng = random.Random(seed)
    lo = cfg.data_format.min_val
    hi = cfg.data_format.max_val

    vectors = []
    for _ in range(count):
        x = rng.uniform(lo, hi)
        y = rng.uniform(lo, hi)
        vectors.append(create_vectoring_test_vector(x, y, cfg))
    return vectors


# =============================================================================
# Serialization helpers
# =============================================================================
# =============================================================================
# Serialization helpers
# =============================================================================

def save_vectors_json(vectors: Sequence[TestVector], path: str) -> None:
    """
    Save a vector list to JSON.

    This is often the easiest format for cocotb or Python-side inspection.
    """
    with open(path, "w", encoding="utf-8") as fh:
        json.dump([asdict(v) for v in vectors], fh, indent=2)


def save_vectors_csv(vectors: Sequence[TestVector], path: str) -> None:
    """
    Save a vector list to CSV.

    This is often the easiest format for simple SystemVerilog file-driven TBs.
    """
    if not vectors:
        raise ValueError("Cannot save an empty vector list to CSV")

    fieldnames = list(asdict(vectors[0]).keys())

    with open(path, "w", encoding="utf-8", newline="") as fh:
        writer = csv.DictWriter(fh, fieldnames=fieldnames)
        writer.writeheader()
        for vector in vectors:
            writer.writerow(asdict(vector))


# =============================================================================
# Human-readable reporting helpers
# =============================================================================

def print_config_summary(cfg: CordicConfig) -> None:
    """
    Print a human-readable summary of the current configuration.
    """
    internal_fmt = get_internal_data_format(cfg)

    print("CORDIC configuration")
    print("--------------------")
    print(f"Data format         : width={cfg.data_format.width}, frac={cfg.data_format.frac}")
    print(f"Angle format        : width={cfg.angle_format.width}, frac={cfg.angle_format.frac}")
    print(f"Internal data width : width={internal_fmt.width}, frac={internal_fmt.frac}")
    print(f"Iterations          : {cfg.iterations}")
    print(f"Guard bits          : {cfg.internal_guard_bits}")
    print(f"Saturate output     : {cfg.saturate_output}")
    print(f"Gain K              : {cordic_gain(cfg.iterations):.12f}")
    print(f"Gain 1/K            : {cordic_gain_inverse(cfg.iterations):.12f}")
    print()


def print_lut(cfg: CordicConfig) -> None:
    """
    Print the atan LUT in both float and fixed-point form.
    """
    lut_f = build_atan_lut_float(cfg.iterations)
    lut_q = build_atan_lut_fixed(cfg.iterations, cfg.angle_format)

    print("CORDIC atan LUT")
    print("----------------")
    for i, (angle_f, angle_q) in enumerate(zip(lut_f, lut_q)):
        print(
            f"i={i:2d}  "
            f"atan(2^-i)={angle_f: .12f} rad  "
            f"fixed={angle_q:8d}  "
            f"float_from_fixed={fixed_to_float(angle_q, cfg.angle_format): .12f}"
        )
    print()


def run_selfcheck(cfg: CordicConfig, count: int = 100) -> None:
    """
    Run a lightweight self-check against Python's math library.

    This is not a replacement for a real regression environment, but it is very
    useful as a quick smoke test while bringing up the reference model.

    In addition to reporting the worst observed error, this function also prints
    the input sample that triggered each worst case. This is extremely useful
    when debugging quadrant mapping, overflow, or boundary handling issues.
    """
    rng = random.Random(2026)

    max_cos_err = -1.0
    max_sin_err = -1.0
    max_mag_err = -1.0
    max_ang_err = -1.0

    worst_cos = None
    worst_sin = None
    worst_mag = None
    worst_ang = None

    for _ in range(count):
        angle = rng.uniform(-PI, PI)

        cos_ref, sin_ref = sincos_math_reference(angle)
        sincos_q = sincos_fixed(angle, cfg)

        cos_dut = fixed_to_float(sincos_q.x, cfg.data_format)
        sin_dut = fixed_to_float(sincos_q.y, cfg.data_format)

        cos_err = abs(cos_ref - cos_dut)
        sin_err = abs(sin_ref - sin_dut)

        if cos_err > max_cos_err:
            max_cos_err = cos_err
            worst_cos = {
                "angle": angle,
                "ref": cos_ref,
                "dut": cos_dut,
                "err": cos_err,
            }

        if sin_err > max_sin_err:
            max_sin_err = sin_err
            worst_sin = {
                "angle": angle,
                "ref": sin_ref,
                "dut": sin_dut,
                "err": sin_err,
            }

    for _ in range(count):
        # Use a conservative functional-validation range for vectoring mode.
        # Full-range random inputs are still useful as overflow stress tests,
        # but they are not appropriate for measuring numerical accuracy because
        # intermediate CORDIC states can overflow the configured datapath.
        safe_bound = min(0.5, 0.5 * cfg.data_format.max_val)
        x = rng.uniform(-safe_bound, safe_bound)
        y = rng.uniform(-safe_bound, safe_bound)

        mag_ref, ang_ref = atan2_math_reference(x, y)
        vec_dut = atan2_mag_fixed(x, y, cfg)

        mag_err = abs(mag_ref - vec_dut.x)
        ang_err = abs(normalize_angle_pm_pi(ang_ref - vec_dut.z))

        if mag_err > max_mag_err:
            max_mag_err = mag_err
            worst_mag = {
                "x": x,
                "y": y,
                "mag_ref": mag_ref,
                "mag_dut": vec_dut.x,
                "err": mag_err,
            }

        if ang_err > max_ang_err:
            max_ang_err = ang_err
            worst_ang = {
                "x": x,
                "y": y,
                "ang_ref": ang_ref,
                "ang_dut": vec_dut.z,
                "err": ang_err,
            }

    print("Self-check summary")
    print("------------------")
    print(f"Vectoring functional safe bound : {safe_bound:.12e}")
    print(f"Max cos error : {max_cos_err:.12e}")
    print(f"Max sin error : {max_sin_err:.12e}")
    print(f"Max mag error : {max_mag_err:.12e}")
    print(f"Max ang error : {max_ang_err:.12e}")
    print()

    print("Worst cosine case")
    print("-----------------")
    print(worst_cos)
    print()

    print("Worst sine case")
    print("---------------")
    print(worst_sin)
    print()

    print("Worst magnitude case")
    print("--------------------")
    print(worst_mag)
    print()

    print("Worst angle case")
    print("----------------")
    print(worst_ang)
    print()


def run_vectoring_stress_check(cfg: CordicConfig, count: int = 100) -> None:
    """
    Run a full-range vectoring stress test.

    This check intentionally explores the full representable input range and is
    meant to expose overflow or wrap-around behavior. It is not an accuracy
    metric and should not be interpreted as such.
    """
    rng = random.Random(3030)

    max_mag_err = -1.0
    max_ang_err = -1.0
    worst_mag = None
    worst_ang = None

    for _ in range(count):
        x = rng.uniform(cfg.data_format.min_val, cfg.data_format.max_val)
        y = rng.uniform(cfg.data_format.min_val, cfg.data_format.max_val)

        mag_ref, ang_ref = atan2_math_reference(x, y)
        vec_dut = atan2_mag_fixed(x, y, cfg)

        mag_err = abs(mag_ref - vec_dut.x)
        ang_err = abs(normalize_angle_pm_pi(ang_ref - vec_dut.z))

        if mag_err > max_mag_err:
            max_mag_err = mag_err
            worst_mag = {
                "x": x,
                "y": y,
                "mag_ref": mag_ref,
                "mag_dut": vec_dut.x,
                "err": mag_err,
            }

        if ang_err > max_ang_err:
            max_ang_err = ang_err
            worst_ang = {
                "x": x,
                "y": y,
                "ang_ref": ang_ref,
                "ang_dut": vec_dut.z,
                "err": ang_err,
            }

    print("Vectoring stress-check summary")
    print("------------------------------")
    print(f"Max mag error : {max_mag_err:.12e}")
    print(f"Max ang error : {max_ang_err:.12e}")
    print()
    print("Worst magnitude stress case")
    print("---------------------------")
    print(worst_mag)
    print()
    print("Worst angle stress case")
    print("-----------------------")
    print(worst_ang)
    print()


# =============================================================================
# CLI
# =============================================================================

def build_argparser() -> argparse.ArgumentParser:
    """
    Build the command-line interface for the model.

    This is intentionally simple but already useful for:
    - inspecting the gain and LUT
    - generating vectors
    - running a small self-check
    """
    parser = argparse.ArgumentParser(description="CORDIC Python reference model")

    parser.add_argument("--width", type=int, default=16, help="Data path width")
    parser.add_argument("--frac", type=int, default=14, help="Data path fractional bits")
    parser.add_argument("--angle-width", type=int, default=16, help="Angle path width")
    parser.add_argument("--angle-frac", type=int, default=13, help="Angle path fractional bits")
    parser.add_argument("--iterations", type=int, default=16, help="Number of CORDIC iterations")
    parser.add_argument("--guard-bits", type=int, default=3, help="Internal x/y guard bits")
    parser.add_argument(
        "--wrap-output",
        action="store_true",
        help="Wrap x/y outputs instead of saturating them",
    )

    parser.add_argument("--print-config", action="store_true", help="Print configuration summary")
    parser.add_argument("--print-lut", action="store_true", help="Print the atan LUT")
    parser.add_argument("--selfcheck", action="store_true", help="Run internal self-check")
    parser.add_argument("--stresscheck", action="store_true", help="Run vectoring full-range stress check")

    parser.add_argument(
        "--gen-directed-rotation-json",
        type=str,
        default=None,
        help="Write directed rotation-mode vectors to JSON",
    )
    parser.add_argument(
        "--gen-directed-vectoring-json",
        type=str,
        default=None,
        help="Write directed vectoring-mode vectors to JSON",
    )
    parser.add_argument(
        "--gen-random-rotation-json",
        type=str,
        default=None,
        help="Write random rotation-mode vectors to JSON",
    )
    parser.add_argument(
        "--gen-random-vectoring-json",
        type=str,
        default=None,
        help="Write random vectoring-mode vectors to JSON",
    )

    parser.add_argument(
        "--gen-directed-rotation-csv",
        type=str,
        default=None,
        help="Write directed rotation-mode vectors to CSV",
    )
    parser.add_argument(
        "--gen-directed-vectoring-csv",
        type=str,
        default=None,
        help="Write directed vectoring-mode vectors to CSV",
    )
    parser.add_argument(
        "--gen-random-rotation-csv",
        type=str,
        default=None,
        help="Write random rotation-mode vectors to CSV",
    )
    parser.add_argument(
        "--gen-random-vectoring-csv",
        type=str,
        default=None,
        help="Write random vectoring-mode vectors to CSV",
    )

    parser.add_argument("--count", type=int, default=100, help="Number of random vectors")
    parser.add_argument("--seed", type=int, default=1234, help="Random seed")

    return parser


def main() -> None:
    """
    Command-line entry point.
    """
    args = build_argparser().parse_args()

    cfg = CordicConfig(
        data_format=FixedFormat(width=args.width, frac=args.frac, signed=True),
        angle_format=FixedFormat(width=args.angle_width, frac=args.angle_frac, signed=True),
        iterations=args.iterations,
        compensate_gain=True,
        internal_guard_bits=args.guard_bits,
        saturate_output=not args.wrap_output,
    )

    if args.print_config:
        print_config_summary(cfg)

    if args.print_lut:
        print_lut(cfg)

    if args.selfcheck:
        run_selfcheck(cfg, count=args.count)

    if args.stresscheck:
        run_vectoring_stress_check(cfg, count=args.count)

    if args.gen_directed_rotation_json:
        save_vectors_json(
            generate_directed_rotation_vectors(cfg),
            args.gen_directed_rotation_json,
        )

    if args.gen_directed_vectoring_json:
        save_vectors_json(
            generate_directed_vectoring_vectors(cfg),
            args.gen_directed_vectoring_json,
        )

    if args.gen_random_rotation_json:
        save_vectors_json(
            generate_random_rotation_vectors(cfg, args.count, args.seed),
            args.gen_random_rotation_json,
        )

    if args.gen_random_vectoring_json:
        save_vectors_json(
            generate_random_vectoring_vectors(cfg, args.count, args.seed),
            args.gen_random_vectoring_json,
        )

    if args.gen_directed_rotation_csv:
        save_vectors_csv(
            generate_directed_rotation_vectors(cfg),
            args.gen_directed_rotation_csv,
        )

    if args.gen_directed_vectoring_csv:
        save_vectors_csv(
            generate_directed_vectoring_vectors(cfg),
            args.gen_directed_vectoring_csv,
        )

    if args.gen_random_rotation_csv:
        save_vectors_csv(
            generate_random_rotation_vectors(cfg, args.count, args.seed),
            args.gen_random_rotation_csv,
        )

    if args.gen_random_vectoring_csv:
        save_vectors_csv(
            generate_random_vectoring_vectors(cfg, args.count, args.seed),
            args.gen_random_vectoring_csv,
        )


if __name__ == "__main__":
    main()
