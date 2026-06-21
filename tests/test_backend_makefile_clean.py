"""Regression tests for backend Makefile cleanup targets."""

from pathlib import Path


def test_clean_vendor_removes_vendor_directory_recursively() -> None:
    """The clean_vendor target removes directory checkouts, not only files."""

    makefile = Path("src/flexsoc/backend/Makefile").read_text()

    assert "clean_vendor:" in makefile
    assert "$(RM) -r vendor/lowrisc_ip" in makefile or "rm -rf vendor/lowrisc_ip" in makefile
    assert "$(RM) vendor/lowrisc_ip\n" not in makefile
