from __future__ import annotations

# ui.py
#
# Solo presentazione.
# - hub/help/tabelle su stdout
# - summary run su stderr
# - niente logica di business qui

import sys
from pathlib import Path
from typing import Iterable, Mapping, Optional

from rich.console import Console
from rich.panel import Panel
from rich.table import Table
from rich.text import Text


def cout() -> Console:
    return Console(file=sys.stdout)


def cerr() -> Console:
    return Console(file=sys.stderr)


def print_hub() -> None:
    c = cout()

    hero = Text()
    hero.append("flexsoc", style="bold cyan")
    hero.append("  ", style="dim")
    hero.append("Workspace-based hardware IP flow runner", style="dim")

    body = """
[bold]Quick actions[/bold]
  [cyan]flexsoc run ip_start --top[/cyan] <name> [cyan]--run-id[/cyan] <id>
  [cyan]flexsoc actions[/cyan]
  [cyan]flexsoc make --list[/cyan]

[bold]Common workflow[/bold]
  1. Start a new IP
     [green]flexsoc run ip_start --top my_ip --run-id dev[/green]

  2. Run simulation
     [green]flexsoc make sim[/green]

  3. Run synthesis
     [green]flexsoc make synth[/green]

  4. Run signoff
     [green]flexsoc make sta[/green]

[bold]Shortcuts[/bold]
  [magenta]flexsoc ?[/magenta]        Show this hub
  [magenta]flexsoc h[/magenta]        Alias for hub
  [magenta]flexsoc a[/magenta]        List actions
  [magenta]flexsoc q[/magenta]        Quickstart
  [magenta]flexsoc t[/magenta]        Tutorial
  [magenta]flexsoc ip[/magenta]       IP flow guide

[bold]Discover[/bold]
  [yellow]flexsoc actions[/yellow]          List available actions
  [yellow]flexsoc action ip_start[/yellow]  Show action details
  [yellow]flexsoc make --list[/yellow]      List Make targets
"""

    c.print()
    c.print(hero)
    c.print()
    c.print(Panel(body.strip(), title="[bold]flexsoc[/bold]", border_style="cyan", expand=False))


def print_help_topics() -> None:
    c = cout()

    t = Table(title="Help topics", show_lines=False, header_style="bold cyan")
    t.add_column("Topic", style="bold")
    t.add_column("Description", style="dim")
    t.add_row("hub", "Main entry hub and shortcuts")
    t.add_row("quickstart", "First steps for starting a new IP flow")
    t.add_row("tutorial", "Guided walkthrough")
    t.add_row("ip", "IP generation and verification flow guide")
    t.add_row("actions", "Registry-backed actions")
    t.add_row("action <name>", "Detailed info for a single action")
    t.add_row("make --list", "Available Make targets")

    c.print(t)


def print_quickstart() -> None:
    body = """
[bold]Quickstart[/bold]

1. Create a workspace-backed run
   [green]flexsoc run ip_start --top my_ip --run-id dev[/green]

2. Explore available actions
   [green]flexsoc actions[/green]

3. Inspect a specific action
   [green]flexsoc action ip_start[/green]

4. Discover Make targets
   [green]flexsoc make --list[/green]
"""
    cout().print(Panel(body.strip(), title="Quickstart", border_style="green", expand=False))


def print_tutorial() -> None:
    body = """
[bold]Tutorial[/bold]

Use the CLI as the main entry point:
  [green]flexsoc run ...[/green]
  [green]flexsoc exec ...[/green]
  [green]flexsoc make ...[/green]

Use [cyan]flexsoc actions[/cyan] to discover workflow steps,
and [cyan]flexsoc action <name>[/cyan] to inspect parameters.
"""
    cout().print(Panel(body.strip(), title="Tutorial", border_style="magenta", expand=False))


def print_ip_guide() -> None:
    body = """
[bold]IP flow guide[/bold]

Typical authoring flow:
  [green]ip_start[/green]  → create HJSON + RTL stub + TB scaffolding
  [green]sim[/green]       → run simulation
  [green]synth[/green]     → run synthesis
  [green]sta[/green]       → timing analysis
  [green]power[/green]     → power estimation

Simulation should print a [bold]Coverage:[/bold] line on stdout.
"""
    cout().print(Panel(body.strip(), title="IP flow guide", border_style="yellow", expand=False))


def print_actions_table(actions: Mapping[str, Mapping[str, object]]) -> None:
    c = cout()

    t = Table(title="Available actions", show_lines=False, header_style="bold cyan")
    t.add_column("Action", style="bold green", no_wrap=True)
    t.add_column("Description", style="dim")

    for action_id in sorted(actions):
        meta = actions[action_id] or {}
        desc = str(meta.get("description", "") or "")
        t.add_row(action_id, desc)

    c.print(t)
    c.print("[dim]Use[/dim] [bold]flexsoc action <name>[/bold] [dim]to see details.[/dim]")


def print_action_detail(action_id: str, meta: Mapping[str, object]) -> None:
    c = cout()

    desc = str(meta.get("description", "") or "")
    c.print(
        Panel(
            f"[bold green]{action_id}[/bold green]\n\n{desc}",
            title="Action info",
            border_style="green",
            expand=False,
        )
    )

    params = meta.get("params", {}) or {}
    pt = Table(title="Parameters", show_lines=False, header_style="bold cyan")
    pt.add_column("Name", style="bold")
    pt.add_column("Type")
    pt.add_column("Default")
    pt.add_column("Help")

    if isinstance(params, dict):
        for k, spec in sorted(params.items()):
            spec = spec or {}
            if not isinstance(spec, dict):
                spec = {}
            pt.add_row(
                str(k),
                str(spec.get("type", "")),
                str(spec.get("default", "")),
                str(spec.get("help", "")),
            )

    c.print(pt)

    examples = meta.get("examples") or meta.get("usage") or []
    if isinstance(examples, str):
        examples = [examples]
    if not examples:
        examples = [f"flexsoc run {action_id} --top <top> --run-id <run_id>"]

    c.print(
        Panel(
            "\n".join(map(str, examples)),
            title="Examples",
            border_style="cyan",
            expand=False,
        )
    )


def print_make_targets(targets: Iterable[str]) -> None:
    c = cout()

    t = Table(title="Make targets", show_lines=False, header_style="bold cyan")
    t.add_column("Target", style="bold yellow")

    for x in targets:
        t.add_row(str(x))

    c.print(Panel(t, title="flow", border_style="yellow", expand=False))


def print_runner_summary(*, label: str, exit_code: int, runner_dir: Path, flow_dir: Optional[Path]) -> None:
    c = cerr()

    ok = exit_code == 0
    color = "green" if ok else "red"
    icon = "✅" if ok else "❌"

    lines = [
        f"[bold]{icon} {label}[/bold]",
        f"Exit code: {exit_code}",
        f"Runner dir: {runner_dir}",
    ]
    if flow_dir is not None:
        lines.append(f"Flow dir: {flow_dir}")

    c.print(Panel("\n".join(lines), title="Summary", border_style=color, expand=False))
