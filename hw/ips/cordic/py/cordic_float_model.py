#!/usr/bin/env python3
"""
Floating-point CORDIC model.

This file represents the algorithmic / mathematical CORDIC behavior without
fixed-point quantization effects. It is useful for:
- validating the algorithm itself
- validating quadrant mapping
- comparing against Python's math library
- estimating the intrinsic CORDIC approximation error before quantization
"""

from __future__ import annotations

import math
from typing import Tuple

from cordic_common import (
    HALF_PI,
    PI,
    CordicResultFloat,
    cordic_gain,
    cordic_gain_inverse,
    normalize_angle_pm_pi,
    build_atan_lut_float,
)


# -----------------------------------------------------------------------------
# Internal float-domain helpers
# -----------------------------------------------------------------------------
def _rotation_prerotate_float(x_in: float, y_in: float, z_in: float) -> Tuple[float, float, float]:
    """
    Pre-rotate the vector so that the residual angle falls inside the main
    circular CORDIC convergence region around zero.
    """
    x = x_in
    y = y_in
    z = normalize_angle_pm_pi(z_in)

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


def _vectoring_prerotate_float(x_in: float, y_in: float, z_in: float = 0.0) -> Tuple[float, float, float]:
    """
    Pre-rotate the vector into the right half-plane so that the vectoring kernel
    yields a full-quadrant atan2 result in the interval [-pi, pi).
    """
    x = x_in
    y = y_in
    z = z_in

    # Explicit zero-vector policy.
    # The angle of the null vector is mathematically undefined, but the model
    # chooses a deterministic hardware-friendly convention: z = 0.
    if x == 0.0 and y == 0.0:
        return 0.0, 0.0, 0.0

    if x < 0.0:
        if y >= 0.0:
            z += PI
        else:
            z -= PI

        x = -x
        y = -y

    z = normalize_angle_pm_pi(z)
    return x, y, z


# -----------------------------------------------------------------------------
# Core float kernels
# -----------------------------------------------------------------------------
def cordic_rotate_float(
    x_in: float,
    y_in: float,
    z_in: float,
    iterations: int,
) -> CordicResultFloat:
    """
    Floating-point CORDIC rotation kernel over the main convergence interval.
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
    Floating-point CORDIC vectoring kernel over the right half-plane.
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


# -----------------------------------------------------------------------------
# Public float reference API
# -----------------------------------------------------------------------------
def sincos_float(angle_rad: float, iterations: int) -> Tuple[float, float]:
    """
    Return cosine and sine using the floating-point CORDIC algorithm.

    The initial vector is pre-scaled by 1/K so that the outputs directly
    approximate cos(angle) and sin(angle).
    """
    x0 = cordic_gain_inverse(iterations)
    y0 = 0.0
    z0 = normalize_angle_pm_pi(angle_rad)

    x1, y1, z1 = _rotation_prerotate_float(x0, y0, z0)
    result = cordic_rotate_float(x1, y1, z1, iterations)
    return result.x, result.y


def atan2_mag_float(x_in: float, y_in: float, iterations: int) -> Tuple[float, float]:
    """
    Return magnitude and angle using the floating-point CORDIC vectoring mode.

    The x output of the vectoring kernel contains the magnitude multiplied by
    the CORDIC gain, so it is de-scaled here before returning.
    """
    x1, y1, z1 = _vectoring_prerotate_float(x_in, y_in, 0.0)
    result = cordic_vector_float(x1, y1, z1, iterations)

    magnitude = result.x / cordic_gain(iterations)
    angle = normalize_angle_pm_pi(result.z)
    return magnitude, angle


def sincos_math_reference(angle_rad: float) -> Tuple[float, float]:
    """Exact math-library reference for cosine and sine."""
    return math.cos(angle_rad), math.sin(angle_rad)


def atan2_math_reference(x_in: float, y_in: float) -> Tuple[float, float]:
    """Exact math-library reference for magnitude and angle."""
    return math.hypot(x_in, y_in), math.atan2(y_in, x_in)
