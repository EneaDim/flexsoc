from __future__ import annotations

from pathlib import Path
from typing import Iterable, Optional

from rich.console import Console
from rich.panel import Panel
from rich.table import Table
from rich.text import Text

_CONSOLE = Console(stderr=True)


def _emit_lines(lines: Iterable[str]) -> None:
    text = "\n".join(lines).rstrip()
    _CONSOLE.print(Panel(text, border_style="blue"))


def print_runner_summary(
    *,
    label: str,
    exit_code: int,
    runner_dir: Path,
    flow_dir: Optional[Path],
    command: Optional[str] = None,
) -> None:
    ok = exit_code == 0

    stdout_log = Path(runner_dir) / "stdout.log"
    stderr_log = Path(runner_dir) / "stderr.log"
    report_path = (Path(flow_dir) / "report.json") if flow_dir is not None else None

    lines: list[str] = []
    lines.append(f"[bold]{label}[/bold]")
    lines.append(f"Exit code: {exit_code}")
    lines.append(f"Runner dir: {runner_dir}")
    lines.append(f"stdout: {stdout_log}")
    lines.append(f"stderr: {stderr_log}")

    if flow_dir is not None:
        lines.append(f"Flow dir: {flow_dir}")
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

    _emit_lines(lines)


def running_status(*, label: str):
    class _StatusCtx:
        def __enter__(self):
            _CONSOLE.print(f"[cyan]Running:[/cyan] {label}")
            return self

        def __exit__(self, exc_type, exc, tb):
            return False

    return _StatusCtx()


def print_actions_table(rows: list[tuple[str, str]]) -> None:
    table = Table(title="Available actions", header_style="bold cyan")
    table.add_column("Action", style="green", no_wrap=True)
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
    lines = [f"[bold]{name}[/bold]"]
    if description:
        lines.append(description)
    if command:
        lines.append(f"Command: {command}")
    if required_params:
        lines.append(f"Required params: {', '.join(required_params)}")
    if notes:
        lines.append("Notes:")
        for note in notes:
            lines.append(f"  - {note}")

    _emit_lines(lines)


def print_help_topics() -> None:
    lines = [
        "[bold]Help topics[/bold]",
        "overview",
        "commands",
        "detailed",
        "action <id>",
    ]
    _emit_lines(lines)


def print_hub() -> None:
    lines = [
        "[bold]flexsoc[/bold]",
        "Use one of:",
        "  flexsoc help overview",
        "  flexsoc help topics",
        "  flexsoc actions",
        "  flexsoc make --list",
    ]
    _emit_lines(lines)


def print_quickstart() -> None:
    lines = [
        "[bold]Quickstart[/bold]",
        "flexsoc doctor",
        "flexsoc actions",
        "flexsoc run ip_start --top my_ip --run-id dev",
        "flexsoc make setup_tb --top my_ip --run-id dev",
        "flexsoc make sim --top my_ip --run-id dev",
    ]
    _emit_lines(lines)


def print_tutorial() -> None:
    lines = [
        "[bold]Tutorial[/bold]",
        "1. Create a run with flexsoc run ...",
        "2. Generate collateral with flexsoc make ...",
        "3. Inspect artifacts under workspace/runs/...",
        "4. Inspect runner sessions under workspace/sessions/...",
    ]
    _emit_lines(lines)


def print_ip_guide() -> None:
    lines = [
        "[bold]IP flow guide[/bold]",
        "Typical flow:",
        "  flexsoc run ip_start --top my_ip --run-id dev",
        "  flexsoc make reg --top my_ip --run-id dev",
        "  flexsoc make setup_tb --top my_ip --run-id dev",
        "  flexsoc make sim --top my_ip --run-id dev",
        "  flexsoc make syn --top my_ip --run-id dev",
    ]
    _emit_lines(lines)


def print_make_targets(targets: list[str]) -> None:
    table = Table(title="Make targets", header_style="bold cyan")
    table.add_column("Target", style="green")

    for target in targets:
        table.add_row(target)

    _CONSOLE.print(table)
