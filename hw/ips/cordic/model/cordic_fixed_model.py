"""Fixed-point CORDIC model matching the CSR-visible RTL contract.

The RTL exposes a TL-UL peripheral with these visible formats:

* x/y data: signed 16-bit, 14 fractional bits
* z angle: signed 16-bit, 13 fractional bits, radians
* CTRL fields: START bit 0, MODE bit 1, N_ITER bits [15:8]

This model intentionally mirrors the simple iterative CORDIC datapath instead
of hiding the behavior behind Python's floating-point trig functions.
"""

from __future__ import annotations

import math
from dataclasses import dataclass


@dataclass(frozen=True)
class CordicFormat:
    """RTL-visible CORDIC fixed-point formats."""

    data_width: int = 16
    data_frac_bits: int = 14
    angle_width: int = 16
    angle_frac_bits: int = 13
    max_iter: int = 16
    guard_bits: int = 3

    @property
    def data_scale(self) -> int:
        return 1 << self.data_frac_bits

    @property
    def angle_scale(self) -> int:
        return 1 << self.angle_frac_bits

    @property
    def int_width(self) -> int:
        return self.data_width + self.guard_bits


@dataclass(frozen=True)
class CordicInput:
    """One CSR-level CORDIC operation."""

    x: int
    y: int
    z: int
    mode: int = 0
    n_iter: int = 16


@dataclass(frozen=True)
class CordicOutput:
    """One CSR-level expected CORDIC result."""

    x: int
    y: int
    z: int


def signed_min(width: int) -> int:
    return -(1 << (width - 1))


def signed_max(width: int) -> int:
    return (1 << (width - 1)) - 1


def clamp_signed(value: int, width: int) -> int:
    """Clamp an integer to a signed ``width``-bit range."""

    return max(signed_min(width), min(signed_max(width), value))


def wrap_signed(value: int, width: int) -> int:
    """Wrap an integer to a signed ``width``-bit value."""

    mask = (1 << width) - 1
    value &= mask
    if value & (1 << (width - 1)):
        value -= 1 << width
    return value


def sign_extend_to_32(value: int, width: int) -> int:
    """Sign-extend a visible signed value to a 32-bit CSR word."""

    signed = wrap_signed(value, width)
    return signed & 0xFFFFFFFF


def hex32(value: int) -> str:
    """Format a 32-bit CSR word as eight lowercase hex digits."""

    return f"{value & 0xFFFFFFFF:08x}"


def float_to_data(value: float, fmt: CordicFormat) -> int:
    """Convert a real x/y value to signed visible data format."""

    return clamp_signed(round(value * fmt.data_scale), fmt.data_width)


def float_to_angle(rad: float, fmt: CordicFormat) -> int:
    """Convert a radian angle to signed visible angle format."""

    return clamp_signed(round(rad * fmt.angle_scale), fmt.angle_width)


def data_to_float(value: int, fmt: CordicFormat) -> float:
    return wrap_signed(value, fmt.data_width) / fmt.data_scale


def angle_to_float(value: int, fmt: CordicFormat) -> float:
    return wrap_signed(value, fmt.angle_width) / fmt.angle_scale


def _atan_table(fmt: CordicFormat) -> list[int]:
    return [float_to_angle(math.atan(2.0 ** -idx), fmt) for idx in range(fmt.max_iter)]


def _data_to_internal(value: int, fmt: CordicFormat) -> int:
    return wrap_signed(value, fmt.data_width)


def _angle_to_internal(value: int, fmt: CordicFormat) -> int:
    return wrap_signed(value, fmt.angle_width)


def _data_to_csr(value: int, fmt: CordicFormat) -> int:
    visible = clamp_signed(value, fmt.data_width)
    return sign_extend_to_32(visible, fmt.data_width)


def _angle_to_csr(value: int, fmt: CordicFormat) -> int:
    visible = wrap_signed(value, fmt.angle_width)
    return sign_extend_to_32(visible, fmt.angle_width)


def make_input(
    x: float,
    y: float,
    z_rad: float,
    fmt: CordicFormat,
    *,
    mode: int = 0,
    n_iter: int | None = None,
) -> CordicInput:
    """Build one CSR-level input operation from real-valued numbers."""

    return CordicInput(
        x=sign_extend_to_32(float_to_data(x, fmt), fmt.data_width),
        y=sign_extend_to_32(float_to_data(y, fmt), fmt.data_width),
        z=sign_extend_to_32(float_to_angle(z_rad, fmt), fmt.angle_width),
        mode=mode,
        n_iter=fmt.max_iter if n_iter is None else n_iter,
    )


def rotate_fixed(sample: CordicInput, fmt: CordicFormat) -> CordicOutput:
    """Run an RTL-like fixed-point CORDIC operation."""

    atan_table = _atan_table(fmt)
    n_iter = sample.n_iter
    if n_iter <= 0 or n_iter > fmt.max_iter:
        n_iter = fmt.max_iter

    x = _data_to_internal(sample.x, fmt)
    y = _data_to_internal(sample.y, fmt)
    z = _angle_to_internal(sample.z, fmt)

    pi_q = float_to_angle(math.pi, fmt)
    half_pi_q = float_to_angle(math.pi / 2.0, fmt)

    if sample.mode == 0:
        # Match the RTL full-range pre-rotation policy for rotation mode.
        if z > half_pi_q:
            x = -x
            y = -y
            z = wrap_signed(z - pi_q, fmt.angle_width)
        elif z < -half_pi_q:
            x = -x
            y = -y
            z = wrap_signed(z + pi_q, fmt.angle_width)

    for idx in range(n_iter):
        x_shift = x >> idx
        y_shift = y >> idx

        if sample.mode == 0:
            if z >= 0:
                x_next = x - y_shift
                y_next = y + x_shift
                z_next = z - atan_table[idx]
            else:
                x_next = x + y_shift
                y_next = y - x_shift
                z_next = z + atan_table[idx]
        elif sample.mode == 1:
            if y >= 0:
                x_next = x + y_shift
                y_next = y - x_shift
                z_next = z + atan_table[idx]
            else:
                x_next = x - y_shift
                y_next = y + x_shift
                z_next = z - atan_table[idx]
        else:
            raise ValueError(f"unsupported CORDIC mode: {sample.mode}")

        x = clamp_signed(x_next, fmt.int_width)
        y = clamp_signed(y_next, fmt.int_width)
        z = wrap_signed(z_next, fmt.angle_width)

    return CordicOutput(
        x=_data_to_csr(x, fmt),
        y=_data_to_csr(y, fmt),
        z=_angle_to_csr(z, fmt),
    )
