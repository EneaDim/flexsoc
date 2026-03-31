#!/usr/bin/env python3
"""
Fixed-point CORDIC model.

This file is the external-behavior golden model used to compare against the RTL.
It models:
- fixed-point quantization
- quantized angle LUT
- observable quadrant mapping behavior
- output saturation policy
- deterministic corner-case policy (for example the zero vector)

It does NOT try to mirror every internal RTL implementation detail beyond what
is necessary to preserve the externally observable input/output behavior.
"""

from __future__ import annotations

import random
from typing import List

from cordic_common import (
    HALF_PI,
    PI,
    CordicConfig,
    CordicMode,
    CordicResultFixed,
    CordicResultFloat,
    TestVector,
    arithmetic_shift_right,
    build_atan_lut_fixed,
    cordic_gain,
    cordic_gain_inverse,
    fixed_to_float,
    float_to_fixed,
    get_internal_data_format,
    normalize_angle_pm_pi,
    quantize_output_data,
    wrap_to_width,
)
from cordic_float_model import atan2_math_reference, sincos_math_reference


# -----------------------------------------------------------------------------
# Fixed-point pre-rotation helpers
# -----------------------------------------------------------------------------
def _rotation_prerotate_fixed(x_in: int, y_in: int, z_in: int, cfg: CordicConfig) -> CordicResultFixed:
    """
    Fixed-point rotation pre-rotation helper.
    """
    internal_fmt = get_internal_data_format(cfg)

    x = wrap_to_width(x_in, internal_fmt.width)
    y = wrap_to_width(y_in, internal_fmt.width)
    z = wrap_to_width(z_in, cfg.angle_format.width)

    half_pi_q = float_to_fixed(HALF_PI, cfg.angle_format)
    pi_q = float_to_fixed(PI, cfg.angle_format)

    if z > half_pi_q:
        x = wrap_to_width(-x, internal_fmt.width)
        y = wrap_to_width(-y, internal_fmt.width)
        z = wrap_to_width(z - pi_q, cfg.angle_format.width)
    elif z < -half_pi_q:
        x = wrap_to_width(-x, internal_fmt.width)
        y = wrap_to_width(-y, internal_fmt.width)
        z = wrap_to_width(z + pi_q, cfg.angle_format.width)

    return CordicResultFixed(x=x, y=y, z=z)


def _vectoring_prerotate_fixed(x_in: int, y_in: int, z_in: int, cfg: CordicConfig) -> CordicResultFixed:
    """
    Fixed-point vectoring pre-rotation helper.

    The null vector uses the deterministic policy:
        x = 0, y = 0, z = 0
    """
    internal_fmt = get_internal_data_format(cfg)

    x = wrap_to_width(x_in, internal_fmt.width)
    y = wrap_to_width(y_in, internal_fmt.width)
    z = wrap_to_width(z_in, cfg.angle_format.width)

    pi_q = float_to_fixed(PI, cfg.angle_format)

    if x == 0 and y == 0:
        return CordicResultFixed(x=0, y=0, z=0)

    if x < 0:
        if y >= 0:
            z = wrap_to_width(z + pi_q, cfg.angle_format.width)
        else:
            z = wrap_to_width(z - pi_q, cfg.angle_format.width)

        x = wrap_to_width(-x, internal_fmt.width)
        y = wrap_to_width(-y, internal_fmt.width)

    return CordicResultFixed(x=x, y=y, z=z)


# -----------------------------------------------------------------------------
# Fixed-point core kernels
# -----------------------------------------------------------------------------
def cordic_rotate_fixed(
    x_in: int,
    y_in: int,
    z_in: int,
    cfg: CordicConfig,
) -> CordicResultFixed:
    """
    Fixed-point rotation kernel.
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
    Fixed-point vectoring kernel.
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


# -----------------------------------------------------------------------------
# Public fixed-point API
# -----------------------------------------------------------------------------
def sincos_fixed(angle_rad: float, cfg: CordicConfig) -> CordicResultFixed:
    """
    Return cosine and sine in raw fixed-point representation.
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


def atan2_mag_fixed(x_in: float, y_in: float, cfg: CordicConfig) -> CordicResultFloat:
    """
    Return magnitude and angle after fixed-point processing.

    The returned values are converted back to float because that is the most
    convenient format for plotting and error analysis.
    """
    x_raw = float_to_fixed(x_in, cfg.data_format)
    y_raw = float_to_fixed(y_in, cfg.data_format)
    z_raw = float_to_fixed(0.0, cfg.angle_format)

    pre = _vectoring_prerotate_fixed(x_raw, y_raw, z_raw, cfg)
    result_raw = cordic_vector_fixed(pre.x, pre.y, pre.z, cfg)

    x_float = fixed_to_float(result_raw.x, cfg.data_format) / cordic_gain(cfg.iterations)
    y_float = fixed_to_float(result_raw.y, cfg.data_format)
    z_float = normalize_angle_pm_pi(fixed_to_float(result_raw.z, cfg.angle_format))

    return CordicResultFloat(x=x_float, y=y_float, z=z_float)


# -----------------------------------------------------------------------------
# Test-vector generation
# -----------------------------------------------------------------------------
def create_rotation_test_vector(angle_rad: float, cfg: CordicConfig) -> TestVector:
    """
    Build one rotation-mode test vector.
    """
    angle_rad = normalize_angle_pm_pi(angle_rad)

    x0_f = cordic_gain_inverse(cfg.iterations) if cfg.compensate_gain else 1.0
    y0_f = 0.0
    z0_f = angle_rad

    x0_q = float_to_fixed(x0_f, cfg.data_format)
    y0_q = float_to_fixed(y0_f, cfg.data_format)
    z0_q = float_to_fixed(z0_f, cfg.angle_format)

    out_q = sincos_fixed(angle_rad, cfg)

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
    Build one vectoring-mode test vector.
    """
    x_q = float_to_fixed(x_in, cfg.data_format)
    y_q = float_to_fixed(y_in, cfg.data_format)
    z_q = float_to_fixed(0.0, cfg.angle_format)

    pre = _vectoring_prerotate_fixed(x_q, y_q, z_q, cfg)
    out_q = cordic_vector_fixed(pre.x, pre.y, pre.z, cfg)

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

    for _ in range(8):
        angles.append(rng.uniform(-PI, PI))

    unique = list(dict.fromkeys(round(normalize_angle_pm_pi(a), 15) for a in angles))
    return [create_rotation_test_vector(a, cfg) for a in unique]


def generate_directed_vectoring_vectors(cfg: CordicConfig) -> List[TestVector]:
    """
    Generate a rich directed set of vectoring-mode vectors.
    """
    min_v = cfg.data_format.min_val
    max_v = cfg.data_format.max_val
    lsb = 1.0 / cfg.data_format.scale
    rng = random.Random(2026)

    points = [
        (0.0, 0.0),

        (min_v, 0.0),
        (max_v, 0.0),
        (0.0, min_v),
        (0.0, max_v),

        (lsb, 0.0),
        (-lsb, 0.0),
        (0.0, lsb),
        (0.0, -lsb),

        (0.5, 0.0),
        (-0.5, 0.0),
        (0.0, 0.5),
        (0.0, -0.5),

        (0.5, 0.5),
        (0.5, -0.5),
        (-0.5, 0.5),
        (-0.5, -0.5),

        (max_v, max_v),
        (max_v, min_v),
        (min_v, max_v),
        (min_v, min_v),

        (max_v, lsb),
        (max_v, -lsb),
        (lsb, max_v),
        (lsb, min_v),
        (-max_v, lsb),
        (-max_v, -lsb),
        (-lsb, max_v),
        (-lsb, min_v),
    ]

    for _ in range(12):
        points.append((rng.uniform(min_v, max_v), rng.uniform(min_v, max_v)))

    unique = list(dict.fromkeys((round(x, 15), round(y, 15)) for x, y in points))
    return [create_vectoring_test_vector(x, y, cfg) for x, y in unique]


def generate_random_rotation_vectors(cfg: CordicConfig, count: int, seed: int = 1234) -> List[TestVector]:
    """Generate random rotation-mode vectors over [-pi, pi)."""
    rng = random.Random(seed)
    return [create_rotation_test_vector(rng.uniform(-PI, PI), cfg) for _ in range(count)]


def generate_random_vectoring_vectors(cfg: CordicConfig, count: int, seed: int = 1234) -> List[TestVector]:
    """Generate random vectoring-mode vectors across the visible input range."""
    rng = random.Random(seed)
    lo = cfg.data_format.min_val
    hi = cfg.data_format.max_val
    return [create_vectoring_test_vector(rng.uniform(lo, hi), rng.uniform(lo, hi), cfg) for _ in range(count)]


# -----------------------------------------------------------------------------
# Numerical self-check
# -----------------------------------------------------------------------------
def run_selfcheck(cfg: CordicConfig, count: int = 100) -> None:
    """
    Run a lightweight self-check.

    The report is intentionally split into:
    - trigonometric errors: exact reference vs fixed-point CORDIC
    - vectoring errors    : exact reference vs fixed-point CORDIC
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
        dut = sincos_fixed(angle, cfg)

        cos_dut = fixed_to_float(dut.x, cfg.data_format)
        sin_dut = fixed_to_float(dut.y, cfg.data_format)

        cos_err = abs(cos_ref - cos_dut)
        sin_err = abs(sin_ref - sin_dut)

        if cos_err > max_cos_err:
            max_cos_err = cos_err
            worst_cos = {"angle": angle, "ref": cos_ref, "dut": cos_dut, "err": cos_err}

        if sin_err > max_sin_err:
            max_sin_err = sin_err
            worst_sin = {"angle": angle, "ref": sin_ref, "dut": sin_dut, "err": sin_err}

    safe_bound = min(0.5, 0.5 * cfg.data_format.max_val)

    for _ in range(count):
        x = rng.uniform(-safe_bound, safe_bound)
        y = rng.uniform(-safe_bound, safe_bound)

        mag_ref, ang_ref = atan2_math_reference(x, y)
        dut = atan2_mag_fixed(x, y, cfg)

        mag_err = abs(mag_ref - dut.x)
        ang_err = abs(normalize_angle_pm_pi(ang_ref - dut.z))

        if mag_err > max_mag_err:
            max_mag_err = mag_err
            worst_mag = {"x": x, "y": y, "mag_ref": mag_ref, "mag_dut": dut.x, "err": mag_err}

        if ang_err > max_ang_err:
            max_ang_err = ang_err
            worst_ang = {"x": x, "y": y, "ang_ref": ang_ref, "ang_dut": dut.z, "err": ang_err}

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
