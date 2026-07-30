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
