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
        "--e2e-gls-modes",
        dest="e2e_gls_modes",
        default=None,
        help=(
            "Single post-synthesis GLS timing mode for one linear E2E run "
            "(default: typ). Use the CI matrix for additional modes."
        ),
    )
    parser.addoption(
        "--e2e-gls-backends",
        dest="e2e_gls_backends",
        default=None,
        help=(
            "Single GLS backend for one linear E2E run (default: sv). "
            "Use the CI matrix for cocotb."
        ),
    )
    parser.addoption(
        "--no-post-syn-gls",
        action="store_true",
        default=False,
        help="Skip the explicit post-synthesis GLS/back-annotation command sequence.",
    )
