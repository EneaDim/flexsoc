"""Minimal command line entrypoint for the FlexSoC API layer."""

from __future__ import annotations

from datetime import datetime
import json
import subprocess
from pathlib import Path
from typing import Iterable

import typer
from rich.console import Console
from rich.panel import Panel
from rich.table import Table

from .api import FlexSoC, FlowStep, FlowWorkflow

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
                "fx workflow workspace --dry-run --json --set TOP=demo",
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
                "Inspect setup → hjson_gen → reg → doc → rtl_stub → setup_tb → sim → syn → sta → power → pnr → sim_syn → cocotb.",
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
                "fx workflow workspace --set TOP=demo --set RUN_ID=smoke --capture",
                "Create the workspace and run folders through the API layer.",
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
                "1. fx workflow workspace --dry-run --script --set TOP=demo",
                "Start by reading the script preview.",
            ),
            (
                "2. fx workflow workspace --set TOP=demo --capture",
                "Run the safe workspace initialization path.",
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
            ("fx step-info NAME", "Show parameters, defaults, categories, and copy-ready examples for one step."),
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
def workflows(
    json_: bool = typer.Option(False, "--json", help="Print JSON for tools and frontends."),
) -> None:
    """Render high-level workflows exposed by the public API."""

    items = FlexSoC().list_workflows()
    if json_:
        typer.echo(json.dumps([workflow.to_dict() for workflow in items], indent=2))
        return
    _print_workflows(items)

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
def steps(
    group: str | None = typer.Option(None, help="Show only one step group."),
    json_: bool = typer.Option(False, "--json", help="Print JSON for tools and frontends."),
) -> None:
    """Render Make-backed workflow steps known by the API layer."""

    items = FlexSoC().list_steps(group)
    if json_:
        typer.echo(json.dumps([step.to_dict() for step in items], indent=2))
        return
    _print_steps(items, group)

@app.command("smoke")
def smoke(
    top: str = typer.Option("demo", help="Top name used for smoke previews."),
    run_id: str = typer.Option("smoke", help="Run identifier used for smoke previews."),
    project_root: Path | None = typer.Option(None, help="Repository root used as execution cwd."),
    json_: bool = typer.Option(False, "--json", help="Print a JSON payload for tools and frontends."),
    run_workspace: bool = typer.Option(False, "--run-workspace", help="Execute only the safe workspace workflow."),
) -> None:
    """Run safe API/CLI smoke checks without launching EDA tools by default."""

    client = FlexSoC(project_root=project_root)
    payload = _smoke_payload(client, top, run_id, run_workspace)
    if json_:
        typer.echo(json.dumps(payload, indent=2))
    else:
        _print_smoke(payload)
    if not payload["ok"]:
        raise typer.Exit(1)


@app.command("step-info")
def step_info(
    name: str,
    json_: bool = typer.Option(False, "--json", help="Print a JSON payload for tools and frontends."),
    examples: bool = typer.Option(False, "--examples", help="Print only copy-ready command examples."),
) -> None:
    """Show parameters, categories, and examples for one advanced flow step."""

    step = FlexSoC().step_info(name)
    json_enabled = json_ if isinstance(json_, bool) else False
    examples_enabled = examples if isinstance(examples, bool) else False
    if json_enabled:
        typer.echo(json.dumps(step.to_dict(), indent=2))
        return
    _print_step_examples(step) if examples_enabled else _print_step_info(step)


@app.command()
def step(
    targets: list[str] = typer.Argument(..., help="One or more backend steps to run in order."),
    set_: list[str] = typer.Option(None, "--set", help="Override a Make variable as KEY=VALUE."),
    project_root: Path | None = typer.Option(None, help="Repository root used as execution cwd."),
    dry_run: bool = typer.Option(False, help="Print commands without executing them."),
    capture: bool = typer.Option(False, help="Capture and print stdout after execution."),
    script: bool = typer.Option(False, "--script", help="Print a shell script preview during dry-runs."),
    json_: bool = typer.Option(False, "--json", help="Print a JSON payload for tools and frontends."),
) -> None:
    """Run, preview, or serialize one or more advanced backend flow steps."""

    client = FlexSoC(project_root=project_root)
    overrides = _parse_overrides(set_ or [])
    sequence_overrides = _step_sequence_overrides(targets, overrides)
    if dry_run:
        payloads = [client.inspect_step(target, **sequence_overrides) for target in targets]
        if json_:
            payload: object = payloads[0] if len(payloads) == 1 else payloads
            typer.echo(json.dumps(payload, indent=2))
            return
        lines = [item["shell"] for item in payloads]
        typer.echo(_shell_script(lines) if script else "\n".join(lines), nl=not script)
        return

    results = []
    for target in targets:
        try:
            results.append(client.run_step(target, capture=capture, **sequence_overrides))
        except subprocess.CalledProcessError as exc:
            command = " ".join(str(part) for part in exc.cmd)
            typer.secho(f"step failed: {target}", fg=typer.colors.RED, err=True)
            typer.secho(f"command: {command}", err=True)
            raise typer.Exit(exc.returncode) from exc

    if json_:
        payload = results[0].to_dict() if len(results) == 1 else [item.to_dict() for item in results]
        typer.echo(json.dumps(payload, indent=2))
    elif capture:
        for result in results:
            if result.stdout:
                typer.echo(result.stdout, nl=False)



def _step_sequence_overrides(targets: list[str], overrides: dict[str, str]) -> dict[str, str]:
    """Return overrides with one RUN_ID shared by a multi-step call."""

    if len(targets) <= 1 or "RUN_ID" in overrides:
        return overrides
    values = dict(overrides)
    values["RUN_ID"] = datetime.now().strftime("%Y%m%d_%H%M%S")
    return values

def _shell_script(lines: list[str]) -> str:
    """Render dry-run shell lines as a small executable script preview."""

    return "#!/usr/bin/env bash\nset -euo pipefail\n" + "\n".join(lines)


def _smoke_payload(client: FlexSoC, top: str, run_id: str, run_workspace: bool) -> dict[str, object]:
    """Build a safe smoke payload using only public framework workflows."""

    workflows = {
        name: client.inspect_workflow(name, top=top, run_id=run_id).shell_lines()
        for name in ("workspace", "ip_development", "soc_development")
    }
    workspace_results = []
    if run_workspace:
        workspace_results = [item.to_dict() for item in client.run_workflow("workspace", capture=True, top=top, run_id=run_id)]
    workspace_ok = all(item.get("ok", False) for item in workspace_results) if workspace_results else True
    return {
        "ok": workspace_ok,
        "workflows": {name: list(lines) for name, lines in workflows.items()},
        "workspace_results": workspace_results,
    }


def _print_smoke(payload: dict[str, object], console: Console | None = None) -> None:
    """Render the safe smoke summary for humans."""

    console = console or Console()
    ok = bool(payload["ok"])
    style = SUCCESS if ok else WARNING
    workflows = payload["workflows"]
    table = Table(title="Smoke checks", border_style=style)
    table.add_column("Check", style=f"bold {ACCENT}")
    table.add_column("Result", style="white")
    for name, lines in workflows.items():
        table.add_row(name, f"{len(lines)} command(s) previewed")
    if payload["workspace_results"]:
        table.add_row("workspace execution", "ok" if all(item["ok"] for item in payload["workspace_results"]) else "failed")
    console.print(Panel("[bold green]ok[/bold green]" if ok else "[bold yellow]mismatch[/bold yellow]", title="FlexSoC smoke", border_style=style))
    console.print(table)



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
    table.add_column("Category", style="blue")
    table.add_column("Parameter", style=f"bold {ACCENT}")
    table.add_column("Required", style=WARNING)
    table.add_column("Default", style=SECONDARY)
    table.add_column("Description", style="white")
    for param in step.params:
        table.add_row(
            param.category,
            param.name,
            "yes" if param.required else "no",
            param.default or "",
            param.description,
        )
    console.print(Panel(f"[bold {ACCENT}]{step.name}[/bold {ACCENT}]\n{step.description}", border_style=ACCENT))
    console.print(table)
    _print_step_examples(step, console)


def _print_step_examples(step: FlowStep, console: Console | None = None) -> None:
    """Render copy-ready examples for one documented step."""

    console = console or Console()
    table = Table(title=f"{step.name} examples", border_style=SECONDARY)
    table.add_column("Command", style=f"bold {SECONDARY}")
    table.add_column("Purpose", style="white")
    for example in step.examples:
        table.add_row(example.command, example.description)
    console.print(table)


def _print_workflows(workflows: Iterable[FlowWorkflow], console: Console | None = None) -> None:
    """Render public workflows as a compact human catalog."""

    console = console or Console()
    table = Table(title="FlexSoC workflows", border_style="orange3", show_lines=False)
    table.add_column("Workflow", style="bold orange3", no_wrap=True)
    table.add_column("Steps", style="cyan")
    table.add_column("Purpose", style="white")
    table.add_column("Preview", style="dim")
    for workflow in workflows:
        table.add_row(
            workflow.name,
            " → ".join(workflow.steps),
            workflow.description,
            f"fx workflow {workflow.name} --dry-run --script --set TOP=demo",
        )
    console.print(Panel("Use workflows for normal development paths.", title="Discovery", border_style="orange3"))
    console.print(table)


def _print_steps(steps: Iterable[FlowStep], group: str | None = None, console: Console | None = None) -> None:
    """Render advanced steps grouped by development area."""

    console = console or Console()
    items = tuple(sorted(steps, key=lambda step: (step.group, step.name)))
    title = f"FlexSoC steps: {group}" if group else "FlexSoC steps"
    table = Table(title=title, border_style="orange3", show_lines=False)
    table.add_column("Group", style="cyan", no_wrap=True)
    table.add_column("Step", style="bold orange3", no_wrap=True)
    table.add_column("Description", style="white")
    table.add_column("Parameters", style="yellow")
    table.add_column("Details", style="dim")
    for step in items:
        table.add_row(
            step.group,
            step.name,
            step.description,
            _step_param_summary(step),
            f"fx step-info {step.name}",
        )
    console.print(
        Panel(
            "Run `fx step-info NAME` to inspect accepted parameters before running a step.",
            title="Advanced steps",
            border_style="orange3",
        )
    )
    console.print(table)


def _step_param_summary(step: FlowStep) -> str:
    """Return a short parameter summary for the steps table."""

    required = [param.name for param in step.params if param.required]
    optional = [param.name for param in step.params if not param.required]
    names = required + optional[: max(0, 4 - len(required))]
    suffix = " …" if len(required) + len(optional) > len(names) else ""
    return ", ".join(names) + suffix if names else "none"


def _ensure_sequence_run_id(overrides: dict[str, str]) -> dict[str, str]:
    """Return overrides with one RUN_ID shared by a multi-step CLI call."""

    if "RUN_ID" not in overrides:
        overrides = dict(overrides)
        overrides["RUN_ID"] = datetime.now().strftime("%Y%m%d_%H%M%S")
    return overrides

def _parse_overrides(items: list[str]) -> dict[str, str]:
    """Parse KEY=VALUE CLI overrides into Make variable values."""

    values: dict[str, str] = {}
    for item in items:
        key, sep, value = item.partition("=")
        if not sep or not key:
            raise typer.BadParameter(f"expected KEY=VALUE, got {item!r}")
        values[key] = value
    return values
