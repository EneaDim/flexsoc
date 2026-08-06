"""Shared terminal rendering for generated scripts and live command logs."""

from __future__ import annotations

import os
import re
import sys
from pathlib import Path
from typing import Mapping, TextIO

from rich.console import Console
from rich.syntax import Syntax


_ANSI = re.compile(r"\x1b(?:[@-Z\\-_]|\[[0-?]*[ -/]*[@-~])")
_ORANGE = "\x1b[38;5;208m"
_GRAY = "\x1b[90m"
_RESET = "\x1b[0m"


def strip_ansi(text: str) -> str:
    """Remove terminal escape sequences before persisting command logs."""

    return _ANSI.sub("", text)


def color_enabled(stream: TextIO | None = None) -> bool:
    """Return whether FlexSoC terminal blocks should use color."""

    stream = stream or sys.stdout
    mode = os.environ.get("FLEXSOC_COLOR", "auto").strip().lower()
    if mode in {"always", "1", "true", "yes", "on"}:
        return True
    if mode in {"never", "0", "false", "no", "off"}:
        return False
    if os.environ.get("NO_COLOR") is not None or os.environ.get("TERM") == "dumb":
        return False
    return bool(getattr(stream, "isatty", lambda: False)())


def print_path_label(
    label: str,
    path: Path,
    *,
    details: Mapping[str, object] | None = None,
    stream: TextIO | None = None,
    color: bool | None = None,
) -> None:
    """Print one labeled absolute path followed by deterministic key/value context."""

    stream = stream or sys.stdout
    resolved = path.expanduser().resolve()
    suffix = " · ".join(
        f"{key}={value}"
        for key, value in (details or {}).items()
        if value is not None and value != ""
    )
    text = f"{resolved}" + (f" · {suffix}" if suffix else "")
    use_color = color_enabled(stream) if color is None else color
    if use_color:
        print(f"{_ORANGE}[{label}]{_RESET} {_GRAY}{text}{_RESET}", file=stream)
    else:
        print(f"[{label}] {text}", file=stream)


def print_script(
    path: Path,
    *,
    details: Mapping[str, object] | None = None,
    stream: TextIO | None = None,
    color: bool | None = None,
    content: bool | None = None,
) -> None:
    """Print a generated script header and, in live mode, highlighted Tcl content."""

    stream = stream or sys.stdout
    resolved = path.expanduser().resolve()
    show_content = (
        os.environ.get("FLEXSOC_LIVE", "0").strip().lower() in {"1", "true", "yes", "on"}
        if content is None
        else content
    )
    use_color = color_enabled(stream) if color is None else color
    print_path_label("script", resolved, details=details, stream=stream, color=use_color)
    if not show_content:
        return
    text = resolved.read_text(encoding="utf-8", errors="replace")
    if use_color:
        Console(file=stream, force_terminal=True, color_system="256", soft_wrap=True).print(
            Syntax(text.rstrip("\n"), "tcl", theme="ansi_dark", word_wrap=False)
        )
    else:
        stream.write(text)
        if not text.endswith("\n"):
            stream.write("\n")
    stream.flush()


def print_log(path: Path, *, stream: TextIO | None = None, color: bool | None = None) -> None:
    """Print the header used before a live command transcript."""

    print_path_label("log", path, stream=stream, color=color)


def print_live_line(
    line: str,
    *,
    stream: TextIO | None = None,
    color: bool | None = None,
) -> None:
    """Write one live line, preserving intentional child-process ANSI styling."""

    stream = stream or sys.stdout
    use_color = color_enabled(stream) if color is None else color
    plain = strip_ansi(line)
    if use_color:
        stream.write(line if _ANSI.search(line) else f"{_GRAY}{plain}{_RESET}")
    else:
        stream.write(plain)
    stream.flush()
