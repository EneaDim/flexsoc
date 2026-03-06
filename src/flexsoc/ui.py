from __future__ import annotations

# ui.py
#
# Presentation only:
# - hub/help/tables on stdout
# - running/summary on stderr

import sys
from contextlib import contextmanager
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
    hero.append("✨ flexsoc", style="bold cyan")
    hero.append("  ", style="dim")
    hero.append("Framework for ", style="dim")
    hero.append("IP development", style="bold green")
    hero.append(" and ", style="dim")
    hero.append("SoC integration", style="bold magenta")

    body = """
[bold]What you can do[/bold]
  [cyan]flexsoc run ip_start --top my_ip --run-id dev --overwrite[/cyan]
      Start a new IP workspace and generate the initial scaffolding

  [cyan]flexsoc actions[/cyan]
      Explore registry-backed actions and their descriptions

  [cyan]flexsoc make --list[/cyan]
      Discover raw Make targets for the flow backend

[bold]Shortcuts[/bold]
  [magenta]flexsoc ?[/magenta]        Show this hub
  [magenta]flexsoc h[/magenta]        Alias for hub
  [magenta]flexsoc a[/magenta]        List actions
  [magenta]flexsoc q[/magenta]        Quickstart
  [magenta]flexsoc t[/magenta]        Tutorials
  [magenta]flexsoc ip[/magenta]       IP development guide

[bold]Useful next commands[/bold]
  [yellow]flexsoc action ip_start[/yellow]
  [yellow]flexsoc action setup_tb[/yellow]
  [yellow]flexsoc action ip_save[/yellow]
"""
    c.print()
    c.print(hero)
    c.print()
    c.print(
        Panel(
            body.strip(),
            title="[bold]flexsoc[/bold]",
            border_style="cyan",
            expand=False,
        )
    )

def print_help_topics() -> None:
    c = cout()

    t = Table(title="Help topics", show_lines=False, header_style="bold cyan")
    t.add_column("Topic", style="bold")
    t.add_column("Description", style="dim")
    t.add_row("hub", "Main entry hub and shortcuts")
    t.add_row("quickstart", "Practical first steps for a new IP")
    t.add_row("tutorial", "Tutorial commands for shipped examples")
    t.add_row("ip", "Full IP development guide")
    t.add_row("actions", "Registry-backed actions")
    t.add_row("action <name>", "Detailed info for a single action")
    t.add_row("make --list", "Available Make targets")

    c.print(t)



def print_quickstart() -> None:
    body = """
[bold]Quickstart[/bold]

Recommended first flow for a new IP:
  1. [green]flexsoc run ip_start --top my_ip --run-id dev --workspace workspace --overwrite[/green]
  2. [green]flexsoc make view --top my_ip --run-id dev --workspace workspace --overwrite[/green]
  3. [green]flexsoc make syn --top my_ip --run-id dev --workspace workspace --overwrite[/green]
  4. [green]flexsoc make sta --top my_ip --run-id dev --workspace workspace --overwrite[/green]
  5. [green]flexsoc make power --top my_ip --run-id dev --workspace workspace --overwrite[/green]
  6. [green]flexsoc make pnr --top my_ip --run-id dev --workspace workspace --overwrite[/green]
  7. [green]flexsoc make pnr_gui --top my_ip --run-id dev --workspace workspace --overwrite[/green]

Tip:
  Use [bold]--overwrite[/bold] from the beginning while iterating quickly on the same run.

Useful discovery commands:
  [cyan]flexsoc actions[/cyan]
  [cyan]flexsoc make --list[/cyan]
"""
    cout().print(
        Panel(
            body.strip(),
            title="Quickstart",
            border_style="green",
            expand=False,
        )
    )

def print_tutorial() -> None:
    body = """
[bold]Tutorials[/bold]

Full IP workflow tutorials:
  [green]flexsoc make full_tutorial[/green]

IP tutorials:
  [green]flexsoc make ip_tutorial --top spi_host[/green]
  [green]flexsoc make ip_tutorial --top pwm_ramp[/green]

FSM tutorial:
  [green]flexsoc make fsm_tutorial --top fsm_example[/green]

SoC tutorial:
  [green]flexsoc make soc_pless[/green]

Use tutorials to inspect the generated workspace structure,
then reuse the same flow style for your own IPs.
"""
    cout().print(
        Panel(
            body.strip(),
            title="Tutorials",
            border_style="magenta",
            expand=False,
        )
    )


def print_ip_guide() -> None:
    body = """
[bold]IP development guide[/bold]

[bold]1. Start the workspace[/bold]
  [green]ip_start[/green]
  Creates the run folder and initial collateral under the workspace.

[bold]2. HJSON authoring[/bold]
  [green]hjson[/green]
  A starter HJSON template is generated for the IP.
  This is where you describe registers and metadata.
  After generation, edit the template with the real register map.

[bold]3. Register collateral and docs[/bold]
  [green]reg[/green] and [green]doc[/green]
  Generate the reg package / reg top and the documentation from HJSON.

[bold]4. Stub generation and RTL authoring[/bold]
  [green]rtl_stub[/green]
  Generate the initial RTL stub, then write the actual core logic.
  This is where the IP implementation really starts.

[bold]5. Testbench setup and verification authoring[/bold]
  [green]setup_tb[/green]
  Generate the TB scaffold, then write / extend the testbench.

[bold]6. Pre-silicon quality loop[/bold]
  [green]lint[/green]
      Structural / style checking
  [green]sim[/green]
      Functional simulation; stdout should include a [bold]Coverage:[/bold] line

[bold]7. Implementation and signoff[/bold]
  [green]synth[/green]
      Synthesis
  [green]sta[/green]
      Static timing analysis
  [green]power[/green]
      Power estimation
  [green]pnr[/green]
      Place and route
  [green]pnr_gui[/green]
      Interactive GUI flow for PnR/debug

[bold]8. Software / integration helpers[/bold]
  [green]driver[/green]
      Generate software-facing collateral / helpers
  [green]fsoc_init[/green]
      Initialize FlexSoC-related integration material
  [green]ip_save[/green]
      Save or package the resulting IP state

[bold]Suggested command sequence[/bold]
  [green]flexsoc run ip_start --top my_ip --run-id dev[/green]
  [green]flexsoc make hjson reg doc --top my_ip --run-id dev[/green]
  [green]flexsoc make rtl_stub setup_tb --top my_ip --run-id dev[/green]
  [green]flexsoc make lint sim --top my_ip --run-id dev[/green]
  [green]flexsoc make synth sta power --top my_ip --run-id dev[/green]
  [green]flexsoc make pnr --top my_ip --run-id dev[/green]
  [green]flexsoc make driver ip_save --top my_ip --run-id dev[/green]
"""
    cout().print(
        Panel(
            body.strip(),
            title="IP development guide",
            border_style="yellow",
            expand=False,
        )
    )


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


@contextmanager
def running_status(*, label: str):
    """
    Dynamic running indicator shown on stderr while a command is executing.
    Keep it intentionally minimal: the detailed information is shown later
    in the final summary.
    """
    c = cerr()
    with c.status(f"[bold cyan]▶ Running[/bold cyan] {label}", spinner="dots") as status:
        yield status


def print_runner_summary(
    *,
    label: str,
    exit_code: int,
    runner_dir: Path,
    flow_dir: Optional[Path],
    command: Optional[str] = None,
) -> None:
    """
    Modern unified summary for run / exec / make.
    Keep legacy label strings stable because tests search for them literally.
    """
    c = cerr()

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

    c.print(
        Panel(
            "\n".join(lines),
            border_style=status_color,
            title=f"[bold]{label}[/bold]",
            expand=False,
        )
    )
