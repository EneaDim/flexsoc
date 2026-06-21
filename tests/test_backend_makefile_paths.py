"""Backend Makefile path contracts for CLI-driven flow steps."""

from __future__ import annotations

from pathlib import Path


def _makefile_text() -> str:
    """Return the backend Makefile text used by the public CLI."""

    return Path("src/flexsoc/backend/Makefile").read_text()


def test_backend_makefile_keeps_run_dir_alias() -> None:
    """RUN_DIR snippets must resolve to the canonical OUTROOT path."""

    text = _makefile_text()

    assert "OUTROOT" in text
    assert "RUN_DIR" in text
    assert "RUN_DIR     ?= $(OUTROOT)" in text or "RUN_DIR ?= $(OUTROOT)" in text


def test_backend_makefile_uses_canonical_output_directories() -> None:
    """Generator step directory prep must never collapse to /rtl or /doc."""

    text = _makefile_text()

    assert "@mkdir -p $(RUN_DIR)/rtl" not in text
    assert "@mkdir -p $(RUN_DIR)/doc" not in text
    assert "@mkdir -p $(RUN_DIR)/data" not in text
    assert "$(RTLDIR)" in text
    assert "$(DOCDIR)" in text
    assert "$(DATADIR)" in text
