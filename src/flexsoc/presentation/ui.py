from __future__ import annotations

from contextlib import contextmanager
from pathlib import Path
from typing import Iterable, Optional

from rich.console import Console
from rich.panel import Panel
from rich.table import Table

_CONSOLE = Console(stderr=True)


def _emit_panel(
    lines: Iterable[str],
    *,
    border_style: str = "blue",
    title: Optional[str] = None,
) -> None:
    text = "\n".join(lines).rstrip()
    _CONSOLE.print(
        Panel(
            text,
            border_style=border_style,
            title=title,
            title_align="left",
            padding=(0, 1),
        )
    )


def print_runner_summary(
    *,
    label: str,
    exit_code: int,
    runner_dir: Path,
    flow_dir: Optional[Path],
    command: Optional[str] = None,
) -> None:
    ok = exit_code == 0
    border = "green" if ok else "red"
    title = "Success" if ok else "Error"

    stdout_log = Path(runner_dir) / "stdout.log"
    stderr_log = Path(runner_dir) / "stderr.log"

    lines: list[str] = [
        f"[bold]{label}[/bold]",
        f"Exit code: {exit_code}",
        f"Runner dir: {runner_dir}",
        f"stdout: {stdout_log}",
        f"stderr: {stderr_log}",
    ]

    if flow_dir is not None:
        lines.append(f"Flow dir: {flow_dir}")

    report_path = (Path(flow_dir) / "report.json") if flow_dir is not None else None
    if report_path is not None and report_path.exists():
        lines.append(f"Report: {report_path}")

    if command:
        lines.append(f"Command: {command}")

    if not ok:
        lines.append("")
        lines.append("[bold yellow]Quick inspect[/bold yellow]")
        lines.append(f"cat {stderr_log}")
        lines.append(f"cat {stdout_log}")
        if report_path is not None and report_path.exists():
            lines.append(f"cat {report_path}")

    _emit_panel(lines, border_style=border, title=title)


@contextmanager
def running_status(*, label: str):
    # "arc" gives a circular moving-light feel in Rich.
    with _CONSOLE.status(f"[bold cyan] Running :[/bold cyan] {label}", spinner="arc"):
        yield


def print_actions_table(rows: list[tuple[str, str]]) -> None:
    table = Table(
        title="Available actions",
        title_style="bold magenta",
        header_style="bold yellow",
        show_header=True,
    )
    table.add_column("Action", style="bold green", no_wrap=True)
    table.add_column("Description", style="white")

    for name, desc in rows:
        table.add_row(name, desc)

    _CONSOLE.print(table)


def print_action_detail(
    *,
    name: str,
    description: str,
    command: Optional[str] = None,
    required_params: Optional[list[str]] = None,
    notes: Optional[list[str]] = None,
) -> None:
    lines = [f"[bold bright_cyan]{name}[/bold bright_cyan]"]

    if description:
        lines.append(description)
    if command:
        lines.append("")
        lines.append(f"[bold]Command:[/bold] {command}")
    if required_params:
        lines.append("")
        lines.append(f"[bold]Required params:[/bold] {', '.join(required_params)}")
    if notes:
        lines.append("")
        lines.append("[bold]Notes:[/bold]")
        for note in notes:
            lines.append(f"  • {note}")

    _emit_panel(lines, border_style="bright_blue", title="Action")


def print_help_topics() -> None:
    lines = [
        "[bold]Help topics[/bold]",
        "",
        "overview",
        "commands",
        "detailed",
        "action <id>",
    ]
    _emit_panel(lines, border_style="cyan", title="Help")


def print_hub() -> None:
    lines = [
        "[bold bright_cyan]flexsoc[/bold bright_cyan]",
        "",
        "Use one of:",
        "  flexsoc help overview",
        "  flexsoc help topics",
        "  flexsoc actions",
        "  flexsoc make --list",
    ]
    _emit_panel(lines, border_style="bright_blue", title="Home")


def print_quickstart() -> None:
    lines = [
        "[bold]Quickstart[/bold]",
        "",
        "flexsoc doctor",
        "flexsoc actions",
        "flexsoc run ip_start --top my_ip --run-id dev",
        "flexsoc make setup_tb --top my_ip --run-id dev",
        "flexsoc make sim --top my_ip --run-id dev",
    ]
    _emit_panel(lines, border_style="green", title="Quickstart")


def print_tutorial() -> None:
    lines = [
        "[bold]Tutorial[/bold]",
        "",
        "1. Create a run with flexsoc run ...",
        "2. Generate collateral with flexsoc make ...",
        "3. Inspect artifacts under workspace/runs/...",
        "4. Inspect runner sessions under workspace/sessions/...",
    ]
    _emit_panel(lines, border_style="magenta", title="Tutorial")


def print_ip_guide() -> None:
    lines = [
        "[bold]IP flow guide[/bold]",
        "",
        "flexsoc use --ws workspace --run-id dev --run-top my_ip --top my_ip",
        "flexsoc run ip_start",
        "flexsoc make sim view",
        "flexsoc make syn sdf sta power",
        "flexsoc make fsoc_init driver",
        "flexsoc make ip_save",
    ]
    _emit_panel(lines, border_style="blue", title="IP Guide")


def print_make_targets(targets: list[str]) -> None:
    table = Table(
        title="Make targets",
        title_style="bold magenta",
        header_style="bold yellow",
        show_header=True,
    )
    table.add_column("Target", style="bold green")

    for target in targets:
        table.add_row(target)

    _CONSOLE.print(table)
