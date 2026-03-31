#!/usr/bin/env python3
"""
Minimal Streamlit dashboard for CORDIC model analysis.

This dashboard focuses on the most important engineering questions:
- how close is the float CORDIC model to the mathematical reference?
- how much error is introduced by the fixed-point model?
- how do the errors vary across angle / quadrant / vector domain?
- what are the most relevant directed sample values?

The dashboard intentionally stays compact and engineering-oriented.
"""

from __future__ import annotations

import math
import sys
from pathlib import Path

_THIS_DIR = Path(__file__).resolve().parent
if str(_THIS_DIR) not in sys.path:
    sys.path.insert(0, str(_THIS_DIR))

import numpy as np
import pandas as pd
import plotly.graph_objects as go
import streamlit as st

from cordic_common import (
    PI,
    CordicConfig,
    FixedFormat,
    build_atan_lut_fixed,
    build_atan_lut_float,
    cordic_gain,
    cordic_gain_inverse,
    fixed_to_float,
)
from cordic_float_model import (
    atan2_mag_float,
    atan2_math_reference,
    sincos_float,
    sincos_math_reference,
)
from cordic_fixed_model import (
    atan2_mag_fixed,
    generate_directed_rotation_vectors,
    generate_directed_vectoring_vectors,
    sincos_fixed,
)

st.set_page_config(
    page_title="CORDIC Dashboard",
    page_icon="📐",
    layout="wide",
)


# -----------------------------------------------------------------------------
# Helpers
# -----------------------------------------------------------------------------
def line_plot(df: pd.DataFrame, x_col: str, y_cols: list[str], title: str, y_label: str) -> go.Figure:
    fig = go.Figure()
    for col in y_cols:
        fig.add_trace(
            go.Scatter(
                x=df[x_col],
                y=df[col],
                mode="lines",
                name=col,
            )
        )

    fig.update_layout(
        title=title,
        template="plotly_white",
        height=420,
        margin=dict(l=30, r=30, t=60, b=30),
        xaxis_title=x_col,
        yaxis_title=y_label,
    )
    return fig


def histogram_plot(df: pd.DataFrame, col: str, title: str) -> go.Figure:
    fig = go.Figure()
    fig.add_trace(go.Histogram(x=df[col], nbinsx=80, name=col))
    fig.update_layout(
        title=title,
        template="plotly_white",
        height=420,
        margin=dict(l=30, r=30, t=60, b=30),
        xaxis_title=col,
        yaxis_title="Count",
    )
    return fig


# -----------------------------------------------------------------------------
# Cached data builders
# -----------------------------------------------------------------------------
@st.cache_data(show_spinner=False)
def build_rotation_df(
    width: int,
    frac: int,
    angle_width: int,
    angle_frac: int,
    iterations: int,
    guard_bits: int,
    saturate_output: bool,
    num_points: int,
) -> pd.DataFrame:
    cfg = CordicConfig(
        data_format=FixedFormat(width=width, frac=frac, signed=True),
        angle_format=FixedFormat(width=angle_width, frac=angle_frac, signed=True),
        iterations=iterations,
        compensate_gain=True,
        internal_guard_bits=guard_bits,
        saturate_output=saturate_output,
    )

    angles = np.linspace(-PI, PI, num_points)
    rows = []

    for angle in angles:
        cos_math, sin_math = sincos_math_reference(float(angle))
        cos_float, sin_float = sincos_float(float(angle), iterations)
        fixed_res = sincos_fixed(float(angle), cfg)
        cos_fixed = fixed_to_float(fixed_res.x, cfg.data_format)
        sin_fixed = fixed_to_float(fixed_res.y, cfg.data_format)

        rows.append(
            {
                "angle_rad": float(angle),

                "cos_math": cos_math,
                "cos_float": cos_float,
                "cos_fixed": cos_fixed,

                "sin_math": sin_math,
                "sin_float": sin_float,
                "sin_fixed": sin_fixed,

                "cos_err_float_vs_math": abs(cos_float - cos_math),
                "cos_err_fixed_vs_float": abs(cos_fixed - cos_float),
                "cos_err_fixed_vs_math": abs(cos_fixed - cos_math),

                "sin_err_float_vs_math": abs(sin_float - sin_math),
                "sin_err_fixed_vs_float": abs(sin_fixed - sin_float),
                "sin_err_fixed_vs_math": abs(sin_fixed - sin_math),
            }
        )

    return pd.DataFrame(rows)


@st.cache_data(show_spinner=False)
def build_vectoring_df(
    width: int,
    frac: int,
    angle_width: int,
    angle_frac: int,
    iterations: int,
    guard_bits: int,
    saturate_output: bool,
    num_points: int,
    radius: float,
) -> pd.DataFrame:
    cfg = CordicConfig(
        data_format=FixedFormat(width=width, frac=frac, signed=True),
        angle_format=FixedFormat(width=angle_width, frac=angle_frac, signed=True),
        iterations=iterations,
        compensate_gain=True,
        internal_guard_bits=guard_bits,
        saturate_output=saturate_output,
    )

    angles = np.linspace(-PI, PI, num_points)
    rows = []

    for theta in angles:
        x = float(radius * math.cos(theta))
        y = float(radius * math.sin(theta))

        mag_math, ang_math = atan2_math_reference(x, y)
        mag_float, ang_float = atan2_mag_float(x, y, iterations)
        fixed_res = atan2_mag_fixed(x, y, cfg)
        mag_fixed, ang_fixed = fixed_res.x, fixed_res.z

        rows.append(
            {
                "sweep_angle_rad": float(theta),
                "x": x,
                "y": y,

                "mag_math": mag_math,
                "mag_float": mag_float,
                "mag_fixed": mag_fixed,

                "ang_math": ang_math,
                "ang_float": ang_float,
                "ang_fixed": ang_fixed,

                "mag_err_float_vs_math": abs(mag_float - mag_math),
                "mag_err_fixed_vs_float": abs(mag_fixed - mag_float),
                "mag_err_fixed_vs_math": abs(mag_fixed - mag_math),

                "ang_err_float_vs_math": abs(ang_float - ang_math),
                "ang_err_fixed_vs_float": abs(ang_fixed - ang_float),
                "ang_err_fixed_vs_math": abs(ang_fixed - ang_math),
            }
        )

    return pd.DataFrame(rows)


@st.cache_data(show_spinner=False)
def build_lut_df(angle_width: int, angle_frac: int, iterations: int) -> pd.DataFrame:
    angle_fmt = FixedFormat(width=angle_width, frac=angle_frac, signed=True)
    lut_f = build_atan_lut_float(iterations)
    lut_q = build_atan_lut_fixed(iterations, angle_fmt)

    rows = []
    for i, (fval, qval) in enumerate(zip(lut_f, lut_q)):
        rows.append(
            {
                "i": i,
                "atan_float_rad": fval,
                "atan_fixed_raw": qval,
                "atan_fixed_float": fixed_to_float(qval, angle_fmt),
                "lut_quant_error": abs(fixed_to_float(qval, angle_fmt) - fval),
            }
        )

    return pd.DataFrame(rows)


@st.cache_data(show_spinner=False)
def build_directed_tables(
    width: int,
    frac: int,
    angle_width: int,
    angle_frac: int,
    iterations: int,
    guard_bits: int,
    saturate_output: bool,
):
    cfg = CordicConfig(
        data_format=FixedFormat(width=width, frac=frac, signed=True),
        angle_format=FixedFormat(width=angle_width, frac=angle_frac, signed=True),
        iterations=iterations,
        compensate_gain=True,
        internal_guard_bits=guard_bits,
        saturate_output=saturate_output,
    )

    rot_df = pd.DataFrame([vars(v) for v in generate_directed_rotation_vectors(cfg)])
    vec_df = pd.DataFrame([vars(v) for v in generate_directed_vectoring_vectors(cfg)])
    return rot_df, vec_df


# -----------------------------------------------------------------------------
# Sidebar
# -----------------------------------------------------------------------------
st.sidebar.title("⚙️ Configuration")

data_width = st.sidebar.number_input("Data width", min_value=4, max_value=64, value=16, step=1)
data_frac = st.sidebar.number_input("Data fractional bits", min_value=0, max_value=60, value=14, step=1)

angle_width = st.sidebar.number_input("Angle width", min_value=4, max_value=64, value=16, step=1)
angle_frac = st.sidebar.number_input("Angle fractional bits", min_value=0, max_value=60, value=13, step=1)

iterations = st.sidebar.number_input("Iterations", min_value=1, max_value=64, value=16, step=1)
guard_bits = st.sidebar.number_input("Internal guard bits", min_value=0, max_value=16, value=3, step=1)
saturate_output = st.sidebar.toggle("Saturate outputs", value=True)

num_points = st.sidebar.slider("Sweep points", min_value=181, max_value=5001, value=1501, step=20)
vector_radius = st.sidebar.slider("Vector radius", min_value=0.05, max_value=1.50, value=0.80, step=0.05)

show_tables = st.sidebar.toggle("Show raw tables", value=False)

cfg = CordicConfig(
    data_format=FixedFormat(width=int(data_width), frac=int(data_frac), signed=True),
    angle_format=FixedFormat(width=int(angle_width), frac=int(angle_frac), signed=True),
    iterations=int(iterations),
    compensate_gain=True,
    internal_guard_bits=int(guard_bits),
    saturate_output=bool(saturate_output),
)

rotation_df = build_rotation_df(
    width=cfg.data_format.width,
    frac=cfg.data_format.frac,
    angle_width=cfg.angle_format.width,
    angle_frac=cfg.angle_format.frac,
    iterations=cfg.iterations,
    guard_bits=cfg.internal_guard_bits,
    saturate_output=cfg.saturate_output,
    num_points=int(num_points),
)

vectoring_df = build_vectoring_df(
    width=cfg.data_format.width,
    frac=cfg.data_format.frac,
    angle_width=cfg.angle_format.width,
    angle_frac=cfg.angle_format.frac,
    iterations=cfg.iterations,
    guard_bits=cfg.internal_guard_bits,
    saturate_output=cfg.saturate_output,
    num_points=int(num_points),
    radius=float(vector_radius),
)

lut_df = build_lut_df(
    angle_width=cfg.angle_format.width,
    angle_frac=cfg.angle_format.frac,
    iterations=cfg.iterations,
)

rot_directed_df, vec_directed_df = build_directed_tables(
    width=cfg.data_format.width,
    frac=cfg.data_format.frac,
    angle_width=cfg.angle_format.width,
    angle_frac=cfg.angle_format.frac,
    iterations=cfg.iterations,
    guard_bits=cfg.internal_guard_bits,
    saturate_output=cfg.saturate_output,
)

# -----------------------------------------------------------------------------
# Header
# -----------------------------------------------------------------------------
st.title("📐 CORDIC Dashboard")
st.caption("Minimal comparison of math, float CORDIC, and fixed CORDIC")

internal_width = cfg.data_format.width + cfg.internal_guard_bits

k1, k2, k3, k4, k5 = st.columns(5)
k1.metric("Iterations", f"{cfg.iterations}")
k2.metric("Data format", f"Q{cfg.data_format.width - cfg.data_format.frac}.{cfg.data_format.frac}")
k3.metric("Angle format", f"Q{cfg.angle_format.width - cfg.angle_format.frac}.{cfg.angle_format.frac}")
k4.metric("Internal width", f"{internal_width}")
k5.metric("1 / K", f"{cordic_gain_inverse(cfg.iterations):.8f}")

k6, k7, k8, k9 = st.columns(4)
k6.metric("Guard bits", f"{cfg.internal_guard_bits}")
k7.metric("Output policy", "Saturate" if cfg.saturate_output else "Wrap")
k8.metric("Data range", f"[{cfg.data_format.min_val:.4f}, {cfg.data_format.max_val:.4f}]")
k9.metric("Angle range", f"[{cfg.angle_format.min_val:.4f}, {cfg.angle_format.max_val:.4f}]")

# -----------------------------------------------------------------------------
# Summary KPIs
# -----------------------------------------------------------------------------
st.markdown("### Error summary")

s1, s2, s3, s4 = st.columns(4)
s1.metric("Max cos |fixed-math|", f"{rotation_df['cos_err_fixed_vs_math'].max():.3e}")
s2.metric("Max sin |fixed-math|", f"{rotation_df['sin_err_fixed_vs_math'].max():.3e}")
s3.metric("Max mag |fixed-math|", f"{vectoring_df['mag_err_fixed_vs_math'].max():.3e}")
s4.metric("Max ang |fixed-math|", f"{vectoring_df['ang_err_fixed_vs_math'].max():.3e}")

s5, s6, s7, s8 = st.columns(4)
s5.metric("Mean cos |fixed-float|", f"{rotation_df['cos_err_fixed_vs_float'].mean():.3e}")
s6.metric("Mean sin |fixed-float|", f"{rotation_df['sin_err_fixed_vs_float'].mean():.3e}")
s7.metric("Mean mag |fixed-float|", f"{vectoring_df['mag_err_fixed_vs_float'].mean():.3e}")
s8.metric("Mean ang |fixed-float|", f"{vectoring_df['ang_err_fixed_vs_float'].mean():.3e}")

# -----------------------------------------------------------------------------
# Tabs
# -----------------------------------------------------------------------------
tab_rot, tab_vec, tab_lut, tab_samples = st.tabs(
    ["Rotation", "Vectoring", "LUT", "Directed Samples"]
)

with tab_rot:
    st.subheader("Rotation mode")

    c1, c2 = st.columns(2)

    with c1:
        st.plotly_chart(
            line_plot(
                rotation_df,
                "angle_rad",
                ["cos_math", "cos_float", "cos_fixed"],
                "Cosine: math vs float vs fixed",
                "cos",
            ),
            use_container_width=True,
        )

    with c2:
        st.plotly_chart(
            line_plot(
                rotation_df,
                "angle_rad",
                ["sin_math", "sin_float", "sin_fixed"],
                "Sine: math vs float vs fixed",
                "sin",
            ),
            use_container_width=True,
        )

    c3, c4 = st.columns(2)

    with c3:
        st.plotly_chart(
            line_plot(
                rotation_df,
                "angle_rad",
                ["cos_err_float_vs_math", "cos_err_fixed_vs_float", "cos_err_fixed_vs_math"],
                "Cosine errors",
                "absolute error",
            ),
            use_container_width=True,
        )

    with c4:
        st.plotly_chart(
            line_plot(
                rotation_df,
                "angle_rad",
                ["sin_err_float_vs_math", "sin_err_fixed_vs_float", "sin_err_fixed_vs_math"],
                "Sine errors",
                "absolute error",
            ),
            use_container_width=True,
        )

    if show_tables:
        st.dataframe(rotation_df, use_container_width=True, height=420)

with tab_vec:
    st.subheader("Vectoring mode")

    c1, c2 = st.columns(2)

    with c1:
        st.plotly_chart(
            line_plot(
                vectoring_df,
                "sweep_angle_rad",
                ["mag_math", "mag_float", "mag_fixed"],
                "Magnitude: math vs float vs fixed",
                "magnitude",
            ),
            use_container_width=True,
        )

    with c2:
        st.plotly_chart(
            line_plot(
                vectoring_df,
                "sweep_angle_rad",
                ["ang_math", "ang_float", "ang_fixed"],
                "Angle: math vs float vs fixed",
                "angle [rad]",
            ),
            use_container_width=True,
        )

    c3, c4 = st.columns(2)

    with c3:
        st.plotly_chart(
            line_plot(
                vectoring_df,
                "sweep_angle_rad",
                ["mag_err_float_vs_math", "mag_err_fixed_vs_float", "mag_err_fixed_vs_math"],
                "Magnitude errors",
                "absolute error",
            ),
            use_container_width=True,
        )

    with c4:
        st.plotly_chart(
            line_plot(
                vectoring_df,
                "sweep_angle_rad",
                ["ang_err_float_vs_math", "ang_err_fixed_vs_float", "ang_err_fixed_vs_math"],
                "Angle errors",
                "absolute error",
            ),
            use_container_width=True,
        )

    if show_tables:
        st.dataframe(vectoring_df, use_container_width=True, height=420)

with tab_lut:
    st.subheader("Quantized atan LUT")

    c1, c2 = st.columns(2)

    with c1:
        st.plotly_chart(
            line_plot(
                lut_df,
                "i",
                ["atan_float_rad", "atan_fixed_float"],
                "LUT values: float vs quantized",
                "angle [rad]",
            ),
            use_container_width=True,
        )

    with c2:
        st.plotly_chart(
            line_plot(
                lut_df,
                "i",
                ["lut_quant_error"],
                "LUT quantization error",
                "absolute error",
            ),
            use_container_width=True,
        )

    st.dataframe(lut_df, use_container_width=True, height=420)

with tab_samples:
    st.subheader("Directed sample vectors")

    srot, svec = st.tabs(["Rotation directed", "Vectoring directed"])

    with srot:
        st.dataframe(rot_directed_df, use_container_width=True, height=420)

    with svec:
        st.dataframe(vec_directed_df, use_container_width=True, height=420)
