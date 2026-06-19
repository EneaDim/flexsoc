"""Minimal command line entrypoint for the FlexSoC API layer."""

from __future__ import annotations

import json
from pathlib import Path
from typing import Iterable

import typer
from rich.console import Console
from rich.panel import Panel
from rich.table import Table

from .api import FlexSoC, FlowStep

ACCENT = "orange3"
SECONDARY = "cyan"
SUCCESS = "green"
WARNING = "yellow"

HELP_INTRO = """Thin command line interface over the public FlexSoC API layer.
Use workflows for normal development and steps for advanced flow control."""

HELP_SECTIONS = (
    (
        "Quickstart",
        ACCENT,
        (
            ("fx help", "Open this guide."),
            ("python -m flexsoc help", "Open the same guide through the package module."),
            ("fx workflows", "List high-level workflows for normal use."),
            ("fx steps", "List advanced Make-backed steps exposed through the API."),
            ("fx step-info hjson_gen", "Show accepted parameters for one step."),
            ("fx describe", "Show project root, workspace, and client options."),
        ),
    ),
    (
        "Safe previews",
        SECONDARY,
        (
            (
                "fx workflow ip_development --dry-run --script --set TOP=demo --set RUN_ID=smoke",
                "Preview the full IP flow as an ordered shell script.",
            ),
            (
                "fx workflow prepare --dry-run --json --set TOP=demo",
                "Return a structured workflow plan for frontends or services.",
            ),
            ("fx step setup --dry-run --set TOP=demo", "Preview one advanced backend step."),
        ),
    ),
    (
        "IP development",
        SUCCESS,
        (
            (
                "fx workflow ip_development --dry-run --script --set TOP=my_ip",
                "Inspect setup, HJSON, reg, docs, RTL stubs, TB, sim, syn, STA, power, PnR, and Cocotb.",
            ),
            (
                "fx step-info rtl_stub",
                "Show parameters accepted by the RTL stub generation step.",
            ),
            (
                "fx step fsm_gen --dry-run --set FSM=my_fsm",
                "Preview the bundled FSM generator step directly.",
            ),
        ),
    ),
    (
        "SoC development",
        WARNING,
        (
            (
                "fx workflow prepare --set TOP=demo --set RUN_ID=smoke --capture",
                "Create the workspace through the API layer.",
            ),
            (
                "fx workflow soc_development --dry-run --script --set TOP=soc",
                "Preview setup, IP loading, SoC generation, software build, simulation, and run.",
            ),
            (
                "fx step-info soc",
                "Show SoC generation parameters such as HOST and workspace values.",
            ),
        ),
    ),
    (
        "Tutorials",
        "magenta",
        (
            (
                "1. fx workflow prepare --dry-run --script --set TOP=demo",
                "Start by reading the script preview.",
            ),
            (
                "2. fx workflow prepare --set TOP=demo --capture",
                "Run the safe workspace preparation path.",
            ),
            (
                "3. fx step-info syn",
                "Check parameters before running a tool-dependent implementation step.",
            ),
        ),
    ),
    (
        "Common options",
        "blue",
        (
            ("--set KEY=VALUE", "Override one Make variable for one call. Repeat as needed."),
            (
                "--project-root PATH",
                "Execute from a repository root different from the current directory.",
            ),
            (
                "--dry-run / --json / --script / --capture",
                "Inspect, serialize, preview, or capture execution.",
            ),
        ),
    ),
)

app = typer.Typer(
    add_completion=False,
    help="Thin FlexSoC CLI over the public API layer. Use `fx help` for examples.",
)


@app.callback(invoke_without_command=True)
def main(ctx: typer.Context) -> None:
    """Show the extended help guide when no subcommand is selected."""

    if ctx.invoked_subcommand is None:
        _print_help()


@app.command()
def help() -> None:
    """Print an extended CLI guide with workflows, tutorials, and options."""

    _print_help()


@app.command()
def describe() -> None:
    """Print the current FlexSoC API client description as JSON."""

    typer.echo(json.dumps(FlexSoC().describe(), indent=2))


@app.command("workflows")
def workflows() -> None:
    """Print high-level workflows exposed by the public API."""

    payload = [workflow.to_dict() for workflow in FlexSoC().list_workflows()]
    typer.echo(json.dumps(payload, indent=2))


@app.command("workflow")
def workflow(
    name: str,
    set_: list[str] = typer.Option(None, "--set", help="Override a Make variable as KEY=VALUE."),
    project_root: Path | None = typer.Option(None, help="Repository root used as execution cwd."),
    dry_run: bool = typer.Option(False, help="Print commands without executing them."),
    capture: bool = typer.Option(False, help="Capture and print stdout after execution."),
    script: bool = typer.Option(False, "--script", help="Print a shell script preview during dry-runs."),
    json_: bool = typer.Option(False, "--json", help="Print a JSON payload for tools and frontends."),
) -> None:
    """Run, preview, or serialize one high-level workflow through FlexSoC."""

    client = FlexSoC(project_root=project_root)
    overrides = _parse_overrides(set_ or [])
    if dry_run and (json_ or script):
        plan = client.inspect_workflow(name, **overrides)
        typer.echo(json.dumps(plan.to_dict(), indent=2) if json_ else plan.shell_script(), nl=not script)
        return
    results = client.run_workflow(name, dry_run=dry_run, capture=capture, **overrides)
    if json_:
        payload = [item.to_dict() for item in results]
        typer.echo(json.dumps(payload, indent=2))
        return
    for item in results:
        if dry_run:
            typer.echo(item.shell_line())
        elif capture and item.stdout:
            typer.echo(item.stdout, nl=False)


@app.command("steps")
def steps(group: str | None = typer.Option(None, help="Show only one step group.")) -> None:
    """Print Make-backed workflow steps known by the API layer."""

    payload = [step.to_dict() for step in FlexSoC().list_steps(group)]
    typer.echo(json.dumps(payload, indent=2))


@app.command("step-info")
def step_info(
    name: str,
    json_: bool = typer.Option(False, "--json", help="Print a JSON payload for tools and frontends."),
) -> None:
    """Show parameters and usage notes for one advanced flow step."""

    step = FlexSoC().step_info(name)
    if json_:
        typer.echo(json.dumps(step.to_dict(), indent=2))
        return
    _print_step_info(step)


@app.command()
def step(
    target: str,
    set_: list[str] = typer.Option(None, "--set", help="Override a Make variable as KEY=VALUE."),
    project_root: Path | None = typer.Option(None, help="Repository root used as execution cwd."),
    dry_run: bool = typer.Option(False, help="Print the command without executing it."),
    capture: bool = typer.Option(False, help="Capture and print stdout after execution."),
    script: bool = typer.Option(False, "--script", help="Print a shell script preview during dry-runs."),
    json_: bool = typer.Option(False, "--json", help="Print a JSON payload for tools and frontends."),
) -> None:
    """Run, preview, or serialize one advanced backend flow step through FlexSoC."""

    client = FlexSoC(project_root=project_root)
    overrides = _parse_overrides(set_ or [])
    if dry_run:
        payload = client.inspect_step(target, **overrides)
        typer.echo(json.dumps(payload, indent=2) if json_ else payload["shell"])
        return
    result = client.run_step(target, capture=capture, **overrides)
    if json_:
        typer.echo(json.dumps(result.to_dict(), indent=2))
    elif capture and result.stdout:
        typer.echo(result.stdout, nl=False)


def _print_help(console: Console | None = None) -> None:
    """Render the project help guide with a small Rich color palette."""

    console = console or Console()
    console.print(
        Panel(
            f"[bold {ACCENT}]FlexSoC CLI[/bold {ACCENT}]\n{HELP_INTRO}",
            border_style=ACCENT,
        )
    )
    for title, color, rows in HELP_SECTIONS:
        console.print(_help_section(title, color, rows))
    console.print(
        f"[dim]Design rule:[/dim] CLI commands call [bold {ACCENT}]FlexSoC[/bold {ACCENT}], "
        "never backend modules directly."
    )


def _help_section(title: str, color: str, rows: Iterable[tuple[str, str]]) -> Panel:
    """Build one colored help section for the extended CLI guide."""

    table = Table.grid(padding=(0, 2))
    table.add_column(style=f"bold {color}", no_wrap=True)
    table.add_column(style="white")
    for command, description in rows:
        table.add_row(command, description)
    return Panel(table, title=f"[bold {color}]{title}[/bold {color}]", border_style=color)


def _print_step_info(step: FlowStep, console: Console | None = None) -> None:
    """Render one documented step and its accepted Make variables."""

    console = console or Console()
    table = Table(title=f"{step.name} parameters", border_style=ACCENT)
    table.add_column("Parameter", style=f"bold {ACCENT}")
    table.add_column("Required", style=WARNING)
    table.add_column("Default", style=SECONDARY)
    table.add_column("Description", style="white")
    for param in step.params:
        table.add_row(param.name, "yes" if param.required else "no", param.default or "", param.description)
    console.print(Panel(f"[bold {ACCENT}]{step.name}[/bold {ACCENT}]\n{step.description}", border_style=ACCENT))
    console.print(table)
    console.print(f"[dim]Preview:[/dim] fx step {step.name} --dry-run --set TOP=demo")


def _parse_overrides(items: list[str]) -> dict[str, str]:
    """Parse KEY=VALUE CLI overrides into Make variable values."""

    values: dict[str, str] = {}
    for item in items:
        key, sep, value = item.partition("=")
        if not sep or not key:
            raise typer.BadParameter(f"expected KEY=VALUE, got {item!r}")
        values[key] = value
    return values
