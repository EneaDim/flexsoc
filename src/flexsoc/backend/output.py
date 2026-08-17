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
_BLUE = "\x1b[94m"
_GREEN = "\x1b[92m"
_YELLOW = "\x1b[93m"
_RED = "\x1b[91m"
_GRAY = "\x1b[90m"
_RESET = "\x1b[0m"
_STRUCTURED = re.compile(r"^\s*\[(log|script|report|technology)\]\s*(.*?)(?:\r?\n)?$")


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
        print(f"{_ORANGE}[{label}]{_RESET} {_BLUE}{text}{_RESET}", file=stream)
    else:
        print(f"[{label}] {text}", file=stream)



def print_target_start(
    target: str,
    description: str,
    *,
    stream: TextIO | None = None,
    color: bool | None = None,
) -> None:
    """Print the uniform header emitted before every CLI target."""

    stream = stream or sys.stdout
    use_color = color_enabled(stream) if color is None else color
    if use_color:
        print(f"{_ORANGE}→ {target}{_RESET}: {_BLUE}{description}{_RESET}", file=stream, flush=True)
    else:
        print(f"→ {target}: {description}", file=stream, flush=True)


def print_target_result(
    target: str,
    returncode: int,
    *,
    stream: TextIO | None = None,
    color: bool | None = None,
) -> None:
    """Print the uniform completion line emitted after every CLI target."""

    stream = stream or sys.stdout
    use_color = color_enabled(stream) if color is None else color
    ok = returncode == 0
    mark = "✓" if ok else "✗"
    suffix = "done" if ok else f"failed ({returncode})"
    if use_color:
        status = _GREEN if ok else _RED
        print(
            f"{status}{mark}{_RESET} {_ORANGE}{target}{_RESET}: {status}{suffix}{_RESET}",
            file=stream,
            flush=True,
        )
    else:
        print(f"{mark} {target}: {suffix}", file=stream, flush=True)


def print_label(
    label: str,
    text: str,
    *,
    stream: TextIO | None = None,
    color: bool | None = None,
) -> None:
    """Print one uniform FlexSoC label/value line."""

    stream = stream or sys.stdout
    use_color = color_enabled(stream) if color is None else color
    if use_color:
        print(f"{_ORANGE}[{label}]{_RESET} {_BLUE}{text}{_RESET}", file=stream, flush=True)
    else:
        print(f"[{label}] {text}", file=stream, flush=True)

def print_status_label(
    label: str,
    status: str,
    text: str = "",
    *,
    stream: TextIO | None = None,
    color: bool | None = None,
) -> None:
    """Print one labeled status using the standard FlexSoC result colors."""

    stream = stream or sys.stdout
    use_color = color_enabled(stream) if color is None else color
    normalized = status.strip().lower()
    status_color = (
        _GREEN if normalized in {"pass", "safe", "done"}
        else _YELLOW if normalized in {"review", "warn", "warning", "partial"}
        else _RED if normalized in {"fail", "error", "failed"}
        else _BLUE
    )
    suffix = f" · {text}" if text else ""
    if use_color:
        print(
            f"{_ORANGE}[{label}]{_RESET} {status_color}{status.upper()}{_RESET}"
            f"{_BLUE}{suffix}{_RESET}",
            file=stream,
            flush=True,
        )
    else:
        print(f"[{label}] {status.upper()}{suffix}", file=stream, flush=True)

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
    structured = _STRUCTURED.match(plain)
    if structured:
        label, text = structured.groups()
        print_label(label, text, stream=stream, color=use_color)
        return
    if use_color:
        stream.write(line if _ANSI.search(line) else f"{_GRAY}{plain}{_RESET}")
    else:
        stream.write(plain)
    stream.flush()
