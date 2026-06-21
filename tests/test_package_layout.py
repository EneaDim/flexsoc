"""Framework tests for the FlexSoC package layout."""

from __future__ import annotations

from pathlib import Path


def test_tiny_config_module_is_inlined() -> None:
    """The package keeps tiny defaults near the code that uses them."""

    assert not Path("src/flexsoc/config.py").exists()
    for path in Path("src/flexsoc").rglob("*.py"):
        assert "flexsoc.config" not in path.read_text(encoding="utf-8")
        assert "from .config" not in path.read_text(encoding="utf-8")
