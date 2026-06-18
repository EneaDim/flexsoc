"""Minimal command line entrypoint for the FlexSoC API layer."""

from __future__ import annotations

import json
from pathlib import Path

import typer

from .api import FlexSoC

HELP_GUIDE = """FlexSoC CLI guide.

Environment:
  uv run fx help
      Run the CLI from the project .venv managed by uv.

Discovery:
  uv run fx workflows
      List public high-level workflows intended for normal users.
  uv run fx steps
      List advanced Make-backed steps exposed by the API layer.
  uv run fx describe
      Show the configured project root, workspace, and client options.

Safe previews:
  uv run fx workflow prepare --dry-run --script --set TOP=demo --set RUN_ID=smoke
      Print a copyable shell script without running external tools.
  uv run fx workflow prepare --dry-run --json --set TOP=demo
      Print a JSON workflow plan for frontends or web services.
  uv run fx step setup --dry-run --set TOP=demo
      Preview one advanced backend step.

Execution:
  uv run fx workflow prepare --set TOP=demo --set RUN_ID=smoke --capture
      Run the safe workspace preparation workflow and capture stdout.
  uv run fx step setup --set TOP=demo --capture
      Run one advanced backend step through the same API layer.

Common options:
  --set KEY=VALUE
      Override a Make variable for one call. Repeat it for multiple values.
  --project-root PATH
      Execute from a repository root different from the current directory.
  --dry-run, --json, --script, --capture
      Inspect, serialize, preview, or capture command execution.

Design rule:
  CLI commands call FlexSoC, never backend modules directly.
"""

app = typer.Typer(
    add_completion=False,
    help="Thin FlexSoC CLI over the public API layer. Use `fx help` for examples.",
)


@app.callback(invoke_without_command=True)
def main(ctx: typer.Context) -> None:
    """Show the compact help guide when no subcommand is selected."""

    if ctx.invoked_subcommand is None:
        typer.echo(HELP_GUIDE.strip())


@app.command()
def help() -> None:
    """Print an extended CLI guide with common commands and API boundaries."""

    typer.echo(HELP_GUIDE.strip())


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


def _parse_overrides(items: list[str]) -> dict[str, str]:
    """Parse KEY=VALUE CLI overrides into Make variable values."""

    values: dict[str, str] = {}
    for item in items:
        key, sep, value = item.partition("=")
        if not sep or not key:
            raise typer.BadParameter(f"expected KEY=VALUE, got {item!r}")
        values[key] = value
    return values
