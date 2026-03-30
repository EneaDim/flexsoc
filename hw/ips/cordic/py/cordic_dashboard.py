#!/usr/bin/env python3
"""
Interactive Streamlit dashboard for the CORDIC reference model.

This dashboard is designed to help with:
- algorithm bring-up
- fixed-point format exploration
- iteration count tradeoff analysis
- visual comparison between Python math reference and CORDIC results
- quick inspection of LUT values and representative samples

Main design goals:
- keep the UX clean and engineering-oriented
- show useful metrics first
- keep plots interactive through Plotly
- reuse the same numerical backend already implemented in cordic_model.py

How to run:
    streamlit run workspace/runs/cordic/dev/py/cordic_dashboard.py
"""

from __future__ import annotations

import math
from dataclasses import dataclass

import numpy as np
import pandas as pd
import plotly.express as px
import plotly.graph_objects as go
import streamlit as st

from cordic_model import (
    PI,
    CordicConfig,
    FixedFormat,
    atan2_mag_fixed,
    atan2_math_reference,
    build_atan_lut_fixed,
    build_atan_lut_float,
    cordic_gain,
    cordic_gain_inverse,
    fixed_to_float,
    generate_directed_rotation_vectors,
    generate_directed_vectoring_vectors,
    normalize_angle_pm_pi,
    sincos_fixed,
    sincos_math_reference,
)


# =============================================================================
# Page configuration
# =============================================================================

st.set_page_config(
    page_title="CORDIC Dashboard",
    page_icon="📐",
    layout="wide",
)


# =============================================================================
# Dataclasses used to keep sweep data organized
# =============================================================================

@dataclass
class RotationSweep:
    """
    Container for rotation-mode sweep data.
    """
    df: pd.DataFrame
    max_cos_err: float
    mean_cos_err: float
    max_sin_err: float
    mean_sin_err: float


@dataclass
class VectoringSweep:
    """
    Container for vectoring-mode sweep data.
    """
    df: pd.DataFrame
    max_mag_err: float
    mean_mag_err: float
    max_ang_err: float
    mean_ang_err: float


# =============================================================================
# Cached data builders
# =============================================================================

@st.cache_data(show_spinner=False)
def build_rotation_dataframe(
    width: int,
    frac: int,
    angle_width: int,
    angle_frac: int,
    iterations: int,
    num_points: int,
) -> RotationSweep:
    """
    Generate a full sweep for rotation mode.

    This function compares:
    - Python's exact math.cos / math.sin
    - the fixed-point CORDIC model converted back to float

    The result is returned as a Pandas DataFrame so it can be reused in:
    - Plotly charts
    - Streamlit dataframes
    - metric summaries
    """
    cfg = CordicConfig(
        data_format=FixedFormat(width=width, frac=frac, signed=True),
        angle_format=FixedFormat(width=angle_width, frac=angle_frac, signed=True),
        iterations=iterations,
        compensate_gain=True,
    )

    angles = np.linspace(-PI, PI, num_points)

    rows = []

    for angle in angles:
        cos_ref, sin_ref = sincos_math_reference(float(angle))
        dut = sincos_fixed(float(angle), cfg)

        cos_dut = fixed_to_float(dut.x, cfg.data_format)
        sin_dut = fixed_to_float(dut.y, cfg.data_format)
        z_residual = fixed_to_float(dut.z, cfg.angle_format)

        rows.append(
            {
                "angle_rad": float(angle),
                "cos_ref": cos_ref,
                "sin_ref": sin_ref,
                "cos_cordic": cos_dut,
                "sin_cordic": sin_dut,
                "z_residual": z_residual,
                "cos_abs_err": abs(cos_ref - cos_dut),
                "sin_abs_err": abs(sin_ref - sin_dut),
            }
        )

    df = pd.DataFrame(rows)

    return RotationSweep(
        df=df,
        max_cos_err=float(df["cos_abs_err"].max()),
        mean_cos_err=float(df["cos_abs_err"].mean()),
        max_sin_err=float(df["sin_abs_err"].max()),
        mean_sin_err=float(df["sin_abs_err"].mean()),
    )


@st.cache_data(show_spinner=False)
def build_vectoring_dataframe(
    width: int,
    frac: int,
    angle_width: int,
    angle_frac: int,
    iterations: int,
    num_points: int,
    radius: float,
) -> VectoringSweep:
    """
    Generate a circular sweep for vectoring mode.

    The sweep traces points on a circle:
        x = r * cos(theta)
        y = r * sin(theta)

    This is a very effective way to inspect:
    - magnitude accuracy
    - angle accuracy
    - quadrant-related behavior
    - discontinuities near +/- pi
    """
    cfg = CordicConfig(
        data_format=FixedFormat(width=width, frac=frac, signed=True),
        angle_format=FixedFormat(width=angle_width, frac=angle_frac, signed=True),
        iterations=iterations,
        compensate_gain=True,
    )

    angles = np.linspace(-PI, PI, num_points)

    rows = []

    for theta in angles:
        x = float(radius * math.cos(theta))
        y = float(radius * math.sin(theta))

        mag_ref, ang_ref = atan2_math_reference(x, y)
        dut = atan2_mag_fixed(x, y, cfg)

        mag_dut = dut.x
        ang_dut = dut.z
        ang_err = abs(normalize_angle_pm_pi(ang_ref - ang_dut))

        rows.append(
            {
                "sweep_angle_rad": float(theta),
                "x": x,
                "y": y,
                "mag_ref": mag_ref,
                "ang_ref": ang_ref,
                "mag_cordic": mag_dut,
                "ang_cordic": ang_dut,
                "mag_abs_err": abs(mag_ref - mag_dut),
                "ang_abs_err": ang_err,
            }
        )

    df = pd.DataFrame(rows)

    return VectoringSweep(
        df=df,
        max_mag_err=float(df["mag_abs_err"].max()),
        mean_mag_err=float(df["mag_abs_err"].mean()),
        max_ang_err=float(df["ang_abs_err"].max()),
        mean_ang_err=float(df["ang_abs_err"].mean()),
    )


@st.cache_data(show_spinner=False)
def build_lut_dataframe(angle_width: int, angle_frac: int, iterations: int) -> pd.DataFrame:
    """
    Build a DataFrame for the CORDIC atan LUT.

    Both floating-point and fixed-point forms are exposed because the LUT is one
    of the first things engineers usually inspect when aligning model and RTL.
    """
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
) -> tuple[pd.DataFrame, pd.DataFrame]:
    """
    Build directed sample tables for quick human inspection.

    These tables are useful because they expose exact sample values instead of
    only aggregate curves and metrics.
    """
    cfg = CordicConfig(
        data_format=FixedFormat(width=width, frac=frac, signed=True),
        angle_format=FixedFormat(width=angle_width, frac=angle_frac, signed=True),
        iterations=iterations,
        compensate_gain=True,
    )

    rot = pd.DataFrame([vars(v) for v in generate_directed_rotation_vectors(cfg)])
    vec = pd.DataFrame([vars(v) for v in generate_directed_vectoring_vectors(cfg)])

    return rot, vec


# =============================================================================
# Plot builders
# =============================================================================

def line_plot(
    df: pd.DataFrame,
    x: str,
    y_cols: list[str],
    title: str,
    x_label: str,
    y_label: str,
) -> go.Figure:
    """
    Build a generic multi-line Plotly figure from selected DataFrame columns.
    """
    fig = go.Figure()

    for col in y_cols:
        fig.add_trace(
            go.Scatter(
                x=df[x],
                y=df[col],
                mode="lines",
                name=col,
            )
        )

    fig.update_layout(
        title=title,
        xaxis_title=x_label,
        yaxis_title=y_label,
        legend_title="Series",
        template="plotly_white",
        height=430,
        margin=dict(l=30, r=30, t=60, b=30),
    )
    return fig


def histogram_plot(df: pd.DataFrame, column: str, title: str, x_label: str) -> go.Figure:
    """
    Build an interactive histogram for an error distribution.
    """
    fig = px.histogram(
        df,
        x=column,
        nbins=80,
        title=title,
        template="plotly_white",
    )
    fig.update_layout(
        xaxis_title=x_label,
        yaxis_title="Count",
        height=430,
        margin=dict(l=30, r=30, t=60, b=30),
    )
    return fig


def scatter_xy_plot(df: pd.DataFrame, title: str) -> go.Figure:
    """
    Plot the Cartesian input domain used in vectoring mode.
    """
    fig = px.line(
        df,
        x="x",
        y="y",
        title=title,
        template="plotly_white",
    )
    fig.update_layout(
        xaxis_title="x",
        yaxis_title="y",
        height=500,
        margin=dict(l=30, r=30, t=60, b=30),
    )
    fig.update_yaxes(scaleanchor="x", scaleratio=1.0)
    return fig


# =============================================================================
# Sidebar configuration
# =============================================================================

st.sidebar.title("⚙️ Configuration")

st.sidebar.markdown("Set the numerical format and sweep parameters.")

data_width = st.sidebar.number_input("Data width", min_value=4, max_value=64, value=16, step=1)
data_frac = st.sidebar.number_input("Data fractional bits", min_value=0, max_value=60, value=13, step=1)

angle_width = st.sidebar.number_input("Angle width", min_value=4, max_value=64, value=16, step=1)
angle_frac = st.sidebar.number_input("Angle fractional bits", min_value=0, max_value=60, value=13, step=1)

iterations = st.sidebar.number_input("Iterations", min_value=1, max_value=64, value=16, step=1)
guard_bits = st.sidebar.number_input("Internal guard bits", min_value=0, max_value=16, value=3, step=1)
saturate_output = st.sidebar.toggle("Saturate outputs", value=True)

num_points = st.sidebar.slider("Sweep points", min_value=181, max_value=5001, value=2001, step=20)
vector_radius = st.sidebar.slider("Vectoring sweep radius", min_value=0.05, max_value=1.50, value=0.80, step=0.05)

show_raw_tables = st.sidebar.toggle("Show full sample tables", value=False)

cfg = CordicConfig(
    data_format=FixedFormat(width=int(data_width), frac=int(data_frac), signed=True),
    angle_format=FixedFormat(width=int(angle_width), frac=int(angle_frac), signed=True),
    iterations=int(iterations),
    compensate_gain=True,
    internal_guard_bits=int(guard_bits),
    saturate_output=bool(saturate_output),
)


# =============================================================================
# Data preparation
# =============================================================================

rotation = build_rotation_dataframe(
    width=cfg.data_format.width,
    frac=cfg.data_format.frac,
    angle_width=cfg.angle_format.width,
    angle_frac=cfg.angle_format.frac,
    iterations=cfg.iterations,
    num_points=int(num_points),
)

vectoring = build_vectoring_dataframe(
    width=cfg.data_format.width,
    frac=cfg.data_format.frac,
    angle_width=cfg.angle_format.width,
    angle_frac=cfg.angle_format.frac,
    iterations=cfg.iterations,
    num_points=int(num_points),
    radius=float(vector_radius),
)

lut_df = build_lut_dataframe(
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
)


# =============================================================================
# Page header
# =============================================================================

st.title("📐 CORDIC Dashboard")
st.caption("Interactive analysis dashboard for the Python golden model.")

st.markdown(
    """
This dashboard compares the fixed-point CORDIC model against Python math
reference functions and helps inspect convergence, quantization error, LUT
content, and representative vectors.
"""
)

k_col1, k_col2, k_col3, k_col4 = st.columns(4)

k_col1.metric("Iterations", f"{cfg.iterations}")
k_col2.metric("Data format", f"Q{cfg.data_format.width - cfg.data_format.frac}.{cfg.data_format.frac}")
k_col3.metric("Angle format", f"Q{cfg.angle_format.width - cfg.angle_format.frac}.{cfg.angle_format.frac}")
k_col4.metric("CORDIC gain K", f"{cordic_gain(cfg.iterations):.8f}")

internal_width = cfg.data_format.width + cfg.internal_guard_bits

k2_col1, k2_col2, k2_col3, k2_col4 = st.columns(4)
k2_col1.metric("1 / K", f"{cordic_gain_inverse(cfg.iterations):.8f}")
k2_col2.metric("Data range", f"[{cfg.data_format.min_val:.4f}, {cfg.data_format.max_val:.4f}]")
k2_col3.metric("Angle range", f"[{cfg.angle_format.min_val:.4f}, {cfg.angle_format.max_val:.4f}]")
k2_col4.metric("Internal width", f"{internal_width} bits")

k3_col1, k3_col2 = st.columns(2)
k3_col1.metric("Guard bits", f"{cfg.internal_guard_bits}")
k3_col2.metric("Output policy", "Saturate" if cfg.saturate_output else "Wrap")


# =============================================================================
# Tabs
# =============================================================================

tab_overview, tab_rotation, tab_vectoring, tab_lut, tab_samples = st.tabs(
    ["Overview", "Rotation Mode", "Vectoring Mode", "LUT", "Sample Tables"]
)


# =============================================================================
# Overview tab
# =============================================================================

with tab_overview:
    st.subheader("Overall quality summary")

    m1, m2, m3, m4 = st.columns(4)
    m1.metric("Max |cos error|", f"{rotation.max_cos_err:.6e}")
    m2.metric("Mean |cos error|", f"{rotation.mean_cos_err:.6e}")
    m3.metric("Max |sin error|", f"{rotation.max_sin_err:.6e}")
    m4.metric("Mean |sin error|", f"{rotation.mean_sin_err:.6e}")

    m5, m6, m7, m8 = st.columns(4)
    m5.metric("Max |mag error|", f"{vectoring.max_mag_err:.6e}")
    m6.metric("Mean |mag error|", f"{vectoring.mean_mag_err:.6e}")
    m7.metric("Max |angle error|", f"{vectoring.max_ang_err:.6e}")
    m8.metric("Mean |angle error|", f"{vectoring.mean_ang_err:.6e}")

    st.markdown("### Rotation error overview")
    ov_col1, ov_col2 = st.columns(2)

    with ov_col1:
        fig = line_plot(
            rotation.df,
            x="angle_rad",
            y_cols=["cos_abs_err", "sin_abs_err"],
            title="Absolute trigonometric error over angle",
            x_label="Angle [rad]",
            y_label="Absolute error",
        )
        st.plotly_chart(fig, use_container_width=True)

    with ov_col2:
        fig = histogram_plot(
            rotation.df,
            column="cos_abs_err",
            title="Cosine error distribution",
            x_label="Absolute cosine error",
        )
        st.plotly_chart(fig, use_container_width=True)

    st.markdown("### Vectoring error overview")
    ov2_col1, ov2_col2 = st.columns(2)

    with ov2_col1:
        fig = line_plot(
            vectoring.df,
            x="sweep_angle_rad",
            y_cols=["mag_abs_err", "ang_abs_err"],
            title="Magnitude and angle error over circular sweep",
            x_label="Sweep angle [rad]",
            y_label="Absolute error",
        )
        st.plotly_chart(fig, use_container_width=True)

    with ov2_col2:
        fig = histogram_plot(
            vectoring.df,
            column="ang_abs_err",
            title="Angle error distribution",
            x_label="Absolute wrapped angle error [rad]",
        )
        st.plotly_chart(fig, use_container_width=True)


# =============================================================================
# Rotation tab
# =============================================================================

with tab_rotation:
    st.subheader("Rotation mode analysis")

    r1, r2, r3, r4 = st.columns(4)
    r1.metric("Max |cos error|", f"{rotation.max_cos_err:.6e}")
    r2.metric("Mean |cos error|", f"{rotation.mean_cos_err:.6e}")
    r3.metric("Max |sin error|", f"{rotation.max_sin_err:.6e}")
    r4.metric("Mean |sin error|", f"{rotation.mean_sin_err:.6e}")

    fig_cos = line_plot(
        rotation.df,
        x="angle_rad",
        y_cols=["cos_ref", "cos_cordic"],
        title="Cosine: reference vs CORDIC",
        x_label="Angle [rad]",
        y_label="Cosine",
    )
    st.plotly_chart(fig_cos, use_container_width=True)

    fig_sin = line_plot(
        rotation.df,
        x="angle_rad",
        y_cols=["sin_ref", "sin_cordic"],
        title="Sine: reference vs CORDIC",
        x_label="Angle [rad]",
        y_label="Sine",
    )
    st.plotly_chart(fig_sin, use_container_width=True)

    rot_col1, rot_col2 = st.columns(2)

    with rot_col1:
        fig = line_plot(
            rotation.df,
            x="angle_rad",
            y_cols=["cos_abs_err"],
            title="Absolute cosine error",
            x_label="Angle [rad]",
            y_label="Absolute error",
        )
        st.plotly_chart(fig, use_container_width=True)

    with rot_col2:
        fig = line_plot(
            rotation.df,
            x="angle_rad",
            y_cols=["sin_abs_err"],
            title="Absolute sine error",
            x_label="Angle [rad]",
            y_label="Absolute error",
        )
        st.plotly_chart(fig, use_container_width=True)

    rot_col3, rot_col4 = st.columns(2)

    with rot_col3:
        fig = histogram_plot(
            rotation.df,
            column="cos_abs_err",
            title="Cosine error histogram",
            x_label="Absolute cosine error",
        )
        st.plotly_chart(fig, use_container_width=True)

    with rot_col4:
        fig = histogram_plot(
            rotation.df,
            column="sin_abs_err",
            title="Sine error histogram",
            x_label="Absolute sine error",
        )
        st.plotly_chart(fig, use_container_width=True)

    with st.expander("Show rotation sweep table"):
        st.dataframe(rotation.df, use_container_width=True, height=420)


# =============================================================================
# Vectoring tab
# =============================================================================

with tab_vectoring:
    st.subheader("Vectoring mode analysis")

    v1, v2, v3, v4 = st.columns(4)
    v1.metric("Max |mag error|", f"{vectoring.max_mag_err:.6e}")
    v2.metric("Mean |mag error|", f"{vectoring.mean_mag_err:.6e}")
    v3.metric("Max |angle error|", f"{vectoring.max_ang_err:.6e}")
    v4.metric("Mean |angle error|", f"{vectoring.mean_ang_err:.6e}")

    fig_xy = scatter_xy_plot(vectoring.df, "Circular input domain used for vectoring sweep")
    st.plotly_chart(fig_xy, use_container_width=True)

    fig_mag = line_plot(
        vectoring.df,
        x="sweep_angle_rad",
        y_cols=["mag_ref", "mag_cordic"],
        title="Magnitude: reference vs CORDIC",
        x_label="Sweep angle [rad]",
        y_label="Magnitude",
    )
    st.plotly_chart(fig_mag, use_container_width=True)

    fig_ang = line_plot(
        vectoring.df,
        x="sweep_angle_rad",
        y_cols=["ang_ref", "ang_cordic"],
        title="Angle: reference vs CORDIC",
        x_label="Sweep angle [rad]",
        y_label="Angle [rad]",
    )
    st.plotly_chart(fig_ang, use_container_width=True)

    vec_col1, vec_col2 = st.columns(2)

    with vec_col1:
        fig = line_plot(
            vectoring.df,
            x="sweep_angle_rad",
            y_cols=["mag_abs_err"],
            title="Magnitude absolute error",
            x_label="Sweep angle [rad]",
            y_label="Absolute error",
        )
        st.plotly_chart(fig, use_container_width=True)

    with vec_col2:
        fig = line_plot(
            vectoring.df,
            x="sweep_angle_rad",
            y_cols=["ang_abs_err"],
            title="Angle absolute error",
            x_label="Sweep angle [rad]",
            y_label="Absolute wrapped angle error [rad]",
        )
        st.plotly_chart(fig, use_container_width=True)

    vec_col3, vec_col4 = st.columns(2)

    with vec_col3:
        fig = histogram_plot(
            vectoring.df,
            column="mag_abs_err",
            title="Magnitude error histogram",
            x_label="Absolute magnitude error",
        )
        st.plotly_chart(fig, use_container_width=True)

    with vec_col4:
        fig = histogram_plot(
            vectoring.df,
            column="ang_abs_err",
            title="Angle error histogram",
            x_label="Absolute wrapped angle error [rad]",
        )
        st.plotly_chart(fig, use_container_width=True)

    with st.expander("Show vectoring sweep table"):
        st.dataframe(vectoring.df, use_container_width=True, height=420)


# =============================================================================
# LUT tab
# =============================================================================

with tab_lut:
    st.subheader("atan(2^-i) lookup table")

    st.markdown(
        """
This table is one of the most important inspection points when aligning the
Python model with the RTL implementation.
"""
    )

    lut_col1, lut_col2 = st.columns([1, 2])

    with lut_col1:
        st.metric("LUT entries", f"{len(lut_df)}")
        st.metric("Angle width", f"{cfg.angle_format.width}")
        st.metric("Angle fractional bits", f"{cfg.angle_format.frac}")

    with lut_col2:
        fig = line_plot(
            lut_df,
            x="i",
            y_cols=["atan_float_rad", "atan_fixed_float"],
            title="atan LUT: float vs quantized fixed-point",
            x_label="Iteration index i",
            y_label="Angle [rad]",
        )
        st.plotly_chart(fig, use_container_width=True)

    st.dataframe(lut_df, use_container_width=True, height=420)


# =============================================================================
# Sample tables tab
# =============================================================================

with tab_samples:
    st.subheader("Directed sample vectors")

    st.markdown(
        """
These tables are useful for debugging because they show representative
hand-checkable vectors rather than only aggregate sweeps.
"""
    )

    samp_tab1, samp_tab2 = st.tabs(["Directed rotation vectors", "Directed vectoring vectors"])

    with samp_tab1:
        st.dataframe(rot_directed_df, use_container_width=True, height=420)

    with samp_tab2:
        st.dataframe(vec_directed_df, use_container_width=True, height=420)

    if show_raw_tables:
        st.markdown("### Full raw sweep tables")
        raw1, raw2 = st.tabs(["Rotation raw sweep", "Vectoring raw sweep"])

        with raw1:
            st.dataframe(rotation.df, use_container_width=True, height=420)

        with raw2:
            st.dataframe(vectoring.df, use_container_width=True, height=420)
