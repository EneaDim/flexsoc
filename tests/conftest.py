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
