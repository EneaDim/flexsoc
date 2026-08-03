"""Shared terminal rendering for generated FlexSoC scripts."""

from __future__ import annotations

import os
import re
import sys
from pathlib import Path
from typing import TextIO

from rich.console import Console
from rich.syntax import Syntax
from rich.text import Text


_ANSI = re.compile(r"\x1b(?:[@-Z\\-_]|\[[0-?]*[ -/]*[@-~])")
_LEXERS = {
    ".eqy": "ini",
    ".mk": "make",
    ".sby": "ini",
    ".tcl": "tcl",
    ".ys": "tcl",
}


def strip_ansi(text: str) -> str:
    """Remove terminal escape sequences before persisting command logs."""

    return _ANSI.sub("", text)


def color_enabled(stream: TextIO | None = None) -> bool:
    """Return whether generated scripts should use terminal color."""

    stream = stream or sys.stdout
    mode = os.environ.get("FLEXSOC_COLOR", "auto").strip().lower()
    if mode in {"always", "1", "true", "yes", "on"}:
        return True
    if mode in {"never", "0", "false", "no", "off"}:
        return False
    if os.environ.get("NO_COLOR") is not None or os.environ.get("TERM") == "dumb":
        return False
    return bool(getattr(stream, "isatty", lambda: False)())


def print_script(
    path: Path,
    *,
    stream: TextIO | None = None,
    color: bool | None = None,
    content: bool | None = None,
) -> None:
    """Print a generated-script label and, in live mode, its highlighted body."""

    stream = stream or sys.stdout
    path = path.expanduser().resolve()
    show_content = (
        os.environ.get("FLEXSOC_LIVE", "0").strip().lower() in {"1", "true", "yes", "on"}
        if content is None
        else content
    )
    use_color = color_enabled(stream) if color is None else color
    if not use_color:
        print(f"[script] {path}", file=stream)
        if show_content:
            text = path.read_text(encoding="utf-8", errors="replace")
            print(text, end="" if text.endswith("\n") else "\n", file=stream)
        return

    console = Console(file=stream, force_terminal=True, color_system="auto")
    console.print(Text.assemble(("[script]", "bold orange1"), " ", (str(path), "bright_cyan")))
    if not show_content:
        return
    text = path.read_text(encoding="utf-8", errors="replace")
    console.print(
        Syntax(
            text,
            _LEXERS.get(path.suffix.lower(), "text"),
            theme="ansi_dark",
            background_color="default",
            word_wrap=False,
        )
    )
