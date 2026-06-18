"""Minimal command line entrypoint for the FlexSoC API layer."""

from __future__ import annotations

import json

import typer

from .api import FlexOC

app = typer.Typer(add_completion=False, help="FlexSoC command line interface.")


@app.callback(invoke_without_command=True)
def main(ctx: typer.Context) -> None:
    """Show a smoke description when no subcommand is selected."""

    if ctx.invoked_subcommand is None:
        typer.echo(json.dumps(FlexOC().describe(), indent=2))


@app.command()
def describe() -> None:
    """Print the current FlexSoC API client description."""

    typer.echo(json.dumps(FlexOC().describe(), indent=2))
