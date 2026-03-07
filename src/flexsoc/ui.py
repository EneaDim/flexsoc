from __future__ import annotations

from contextlib import contextmanager
from pathlib import Path
from typing import Iterable, Sequence

from rich import box
from rich.console import Console
from rich.panel import Panel
from rich.table import Table
from rich.text import Text


_CONSOLE = Console(stderr=True)


def get_console() -> Console:
    return _CONSOLE


@contextmanager
def running_status(label: str):
    with _CONSOLE.status(f"[bold cyan]Running :[/bold cyan] [bold white]{label}[/bold white]"):
        yield


def render_simple_table(
    *,
    title: str,
    columns: Sequence[str],
    rows: Iterable[Sequence[str]],
    column_styles: Sequence[str] | None = None,
) -> Table:
    table = Table(
        title=title,
        title_style="bold magenta",
        header_style="bold yellow",
        box=box.ROUNDED,
        show_header=True,
        expand=True,
        pad_edge=False,
    )

    for idx, name in enumerate(columns):
        style = column_styles[idx] if column_styles and idx < len(column_styles) else "white"
        no_wrap = idx == 0
        table.add_column(name, style=style, no_wrap=no_wrap)

    for row in rows:
        table.add_row(*[str(x) for x in row])

    return table


def render_key_value_panel(
    *,
    title: str,
    items: Sequence[tuple[str, str]],
    border_style: str = "bright_blue",
) -> Panel:
    body = Text()
    for idx, (key, value) in enumerate(items):
        body.append(f"{key}: ", style="bold cyan")
        body.append(value, style="white")
        if idx != len(items) - 1:
            body.append("\n")
    return Panel(body, title=title, title_align="left", border_style=border_style, padding=(0, 1))


def print_runner_summary(
    *,
    label: str,
    exit_code: int,
    runner_dir: Path,
    flow_dir: Path | None,
    command: str | None = None,
) -> None:
    """
    Unified runtime summary for run / exec / make.
    Keeps the useful failure hints from the original implementation.
    """
    ok = exit_code == 0
    status_text = "SUCCESS" if ok else "FAILED"
    status_color = "green" if ok else "red"
    icon = "●"

    stdout_log = Path(runner_dir) / "stdout.log"
    stderr_log = Path(runner_dir) / "stderr.log"

    lines: list[str] = []
    lines.append(f"[bold {status_color}]{icon} {status_text}[/bold {status_color}]  [bold]{label}[/bold]")

    lines.append("")
    lines.append(f"Exit code: {exit_code}")
    lines.append(f"Runner dir: {runner_dir}")
    if flow_dir is not None:
        lines.append(f"Flow dir: {flow_dir}")

    if command:
        lines.append("")
        lines.append("[bold cyan]Command[/bold cyan]")
        lines.append(command)

    lines.append("")
    lines.append("[bold cyan]Logs[/bold cyan]")
    lines.append(f"stdout.log: {stdout_log}")
    lines.append(f"stderr.log: {stderr_log}")

    if not ok:
        lines.append("")
        lines.append("[bold yellow]Quick inspect[/bold yellow]")
        lines.append(f"cat {stderr_log}")
        lines.append(f"cat {stdout_log}")

    _CONSOLE.print(
        Panel(
            "\n".join(lines),
            border_style=status_color,
            title=f"[bold]{label}[/bold]",
            expand=False,
        )
    )
def render_action_table(rows: Sequence[tuple[str, str]]) -> None:
    table = render_simple_table(
        title="Available actions",
        columns=("Action", "Description"),
        rows=rows,
        column_styles=("bold green", "white"),
    )
    _CONSOLE.print(table)
    _CONSOLE.print("[dim]Use flexsoc action <name> to inspect one action.[/dim]")


def render_action_detail(
    *,
    name: str,
    description: str,
    command: str | None = None,
    required_params: Sequence[str] | None = None,
    notes: Sequence[str] | None = None,
) -> None:
    header = Text()
    header.append("Action: ", style="bold cyan")
    header.append(name, style="bold green")
    _CONSOLE.print(header)
    _CONSOLE.print()

    _CONSOLE.print(
        Panel(
            description,
            title="Description",
            title_align="left",
            border_style="green",
            padding=(0, 1),
        )
    )

    if command:
        _CONSOLE.print(
            Panel(
                command,
                title="Backend command",
                title_align="left",
                border_style="yellow",
                padding=(0, 1),
            )
        )

    if required_params:
        items = [(str(i + 1), p) for i, p in enumerate(required_params)]
        _CONSOLE.print(
            render_key_value_panel(
                title="Required parameters",
                items=items,
                border_style="magenta",
            )
        )

    if notes:
        body = "\n".join(f"- {note}" for note in notes)
        _CONSOLE.print(
            Panel(
                body,
                title="Notes",
                title_align="left",
                border_style="cyan",
                padding=(0, 1),
            )
        )


# Compatibility wrappers: keep old call sites working while help prose lives in helptext.py.

def render_home_help() -> None:
    from .helptext import render_home_help as _impl
    _impl()


def render_help_overview() -> None:
    from .helptext import render_help_overview as _impl
    _impl()


def render_detailed_help() -> None:
    from .helptext import render_detailed_help as _impl
    _impl()


def render_quickstart() -> None:
    from .helptext import render_quickstart as _impl
    _impl()


def render_tutorials() -> None:
    from .helptext import render_tutorials as _impl
    _impl()


def render_ip_guide() -> None:
    from .helptext import render_ip_guide as _impl
    _impl()


def print_action_detail(
    *,
    name: str,
    description: str,
    command: str | None = None,
    required_params: Sequence[str] | None = None,
    notes: Sequence[str] | None = None,
) -> None:
    render_action_detail(
        name=name,
        description=description,
        command=command,
        required_params=required_params,
        notes=notes,
    )


def print_action_table(rows: Sequence[tuple[str, str]]) -> None:
    render_action_table(rows)


def print_actions_table(rows: Sequence[tuple[str, str]]) -> None:
    render_action_table(rows)


def print_hub() -> None:
    render_home_help()


def print_help_topics() -> None:
    render_help_overview()


def print_quickstart() -> None:
    render_quickstart()


def print_tutorial() -> None:
    render_tutorials()


def print_ip_guide() -> None:
    render_ip_guide()


def print_make_targets(targets: Sequence[tuple[str, str]] | Sequence[str]) -> None:
    rows: list[tuple[str, str]] = []

    for item in targets:
        if isinstance(item, tuple) and len(item) == 2:
            rows.append((str(item[0]), str(item[1])))
        else:
            rows.append((str(item), ""))

    table = render_simple_table(
        title="Available Make targets",
        columns=("Target", "Description"),
        rows=rows,
        column_styles=("bold green", "white"),
    )
    _CONSOLE.print(table)
