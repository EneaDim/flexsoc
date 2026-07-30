"""Float reference model for CORDIC verification.

This module is intentionally small and readable. It is the mathematical golden
reference; the fixed-point model is responsible for matching the RTL-visible
CSR formats and iterative CORDIC behavior.
"""

from __future__ import annotations

import math
from dataclasses import dataclass


@dataclass(frozen=True)
class CordicFloatInput:
    """One high-level CORDIC operation in real-valued units."""

    x: float
    y: float
    z_rad: float
    mode: int = 0


@dataclass(frozen=True)
class CordicFloatOutput:
    """Expected high-level CORDIC output in real-valued units."""

    x: float
    y: float
    z_rad: float


def rotate(sample: CordicFloatInput) -> CordicFloatOutput:
    """Rotate vector ``(x, y)`` by ``z_rad`` using Python math."""

    c = math.cos(sample.z_rad)
    s = math.sin(sample.z_rad)
    return CordicFloatOutput(
        x=sample.x * c - sample.y * s,
        y=sample.x * s + sample.y * c,
        z_rad=0.0,
    )


def vector(sample: CordicFloatInput) -> CordicFloatOutput:
    """Return magnitude-like x, near-zero y, and atan2 angle for vectoring mode."""

    return CordicFloatOutput(
        x=math.hypot(sample.x, sample.y),
        y=0.0,
        z_rad=math.atan2(sample.y, sample.x),
    )


def run(sample: CordicFloatInput) -> CordicFloatOutput:
    """Run the selected high-level operation."""

    if sample.mode == 0:
        return rotate(sample)
    if sample.mode == 1:
        return vector(sample)
    raise ValueError(f"unsupported CORDIC mode: {sample.mode}")
