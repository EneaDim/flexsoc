"""Smoke tests for the public FlexSoC API layer."""

from __future__ import annotations

from flexsoc import FlexOC, FlexOCConfig


def test_public_api_describes_client() -> None:
    """The package exposes a thin client with a stable smoke contract."""

    client = FlexOC(FlexOCConfig(), target="demo")

    assert client.describe()["package"] == "flexsoc"
    assert client.describe()["api"] == "FlexOC"
    assert client.describe()["options"]["target"] == "demo"
