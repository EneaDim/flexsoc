from __future__ import annotations

import pytest


def pytest_addoption(parser: pytest.Parser) -> None:
    """Register FlexSoC pytest options."""

    parser.addoption(
        "--no-signoff",
        action="store_true",
        default=False,
        help="Skip synthesis/signoff targets in FlexSoC E2E tests.",
    )
    parser.addoption(
        "--e2e-root",
        default=None,
        help="Base directory for isolated FlexSoC E2E workspaces (default: /tmp).",
    )
    parser.addoption(
        "--e2e-pdks",
        dest="e2e_pdks",
        default=None,
        help=(
            "Comma-separated PDK matrix for every FlexSoC E2E flow "
            "(default: sky130,ihp-sg13g2)."
        ),
    )
    parser.addoption(
        "--e2e-gls-modes",
        dest="e2e_gls_modes",
        default=None,
        help=(
            "Comma-separated post-synthesis GLS timing modes "
            "(default: zero,unit,min,typ,max)."
        ),
    )
    parser.addoption(
        "--e2e-gls-backends",
        dest="e2e_gls_backends",
        default=None,
        help="Comma-separated GLS drivers (default: sv,cocotb).",
    )
    parser.addoption(
        "--e2e-gls-tests",
        dest="e2e_gls_tests",
        default=None,
        help=(
            "Comma-separated vector tests used for post-synthesis qualification "
            "(default: smoke,auto_toggle; use all for every generated test)."
        ),
    )
    parser.addoption(
        "--no-post-syn-gls",
        action="store_true",
        default=False,
        help="Skip the post-synthesis SV+cocotb GLS/back-annotation matrix.",
    )
