from __future__ import annotations

# ui.py
#
# Tutto ciò che stampa “interfaccia umana” (hub/help/tabelle/summary).
#
# Contratti:
# - Hub/help/tabelle: stdout (i test leggono stdout)
# - Summary/run info: stderr (i test vogliono "Runner dir:" in stderr)
# - JSON puro NON deve passare da qui.

import sys
from pathlib import Path
from typing import Iterable, Optional

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

    body = """
[b]Quick actions[/b]
  flexsoc run ip_start --top <name> --run-id <id>
  flexsoc actions
  flexsoc make --list

[b]Common workflow[/b]
  1. Start a new IP
     flexsoc run ip_start --top my_ip --run-id dev

  2. Run simulation
     flexsoc make sim

  3. Run synthesis
     flexsoc make synth

  4. Run signoff
     flexsoc make sta

[b]Shortcuts[/b]
  flexsoc ?        Show this hub
  flexsoc h        Alias for hub
  flexsoc a        List actions
  flexsoc q        Quickstart
  flexsoc t        Tutorial
  flexsoc ip       IP flow guide

[b]Discover[/b]
  flexsoc actions          List available actions
  flexsoc action ip_start  Show action details
  flexsoc make --list      List Make targets
"""
    c.print(Panel(body.strip(), title="flexsoc", expand=False))



def print_help_topics() -> None:
    c = cout()
    t = Table(title="Help topics", show_lines=False)
    t.add_column("Topic", style="bold")
    t.add_column("Description")
    t.add_row("topics", "List help topics")
    t.add_row("action", "Show action details from registry")
    c.print(t)


def print_quickstart() -> None:
    cout().print(Panel("Quickstart\n\n- Start an IP workspace\n- Run sim/syn/signoff\n", title="Quickstart", expand=False))


def print_tutorial() -> None:
    cout().print(Panel("Tutorial\n\n- Use `flexsoc make help`\n- Explore tutorial targets\n", title="Tutorial", expand=False))


def print_ip_guide() -> None:
    cout().print(Panel("IP flow guide\n\n- ip_start generates RTL + TB\n- sim prints Coverage: on stdout\n", title="IP flow guide", expand=False))



def print_actions_table(action_ids: Iterable[str]) -> None:
    c = cout()

    t = Table(title="Available actions", show_lines=False)
    t.add_column("Action", style="bold")
    t.add_column("Description")

    for aid in sorted(action_ids):
        t.add_row(aid, "")

    c.print(t)
    c.print("Use: [bold]flexsoc action <name>[/bold] to see details.")

def print_action_detail(action_id: str, meta: dict) -> None:
    c = cout()

    desc = str(meta.get("description", "") or "")
    c.print(Panel(f"[b]{action_id}[/b]\n\n{desc}", title="Action info", expand=False))

    params = meta.get("params", {}) or {}
    pt = Table(title="Parameters", show_lines=False)
    pt.add_column("Name", style="bold")
    pt.add_column("Type")
    pt.add_column("Default")
    pt.add_column("Help")
    for k, spec in sorted(params.items()):
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

    c.print(Panel("\n".join(map(str, examples)), title="Examples", expand=False))


def print_make_targets(targets: list[str]) -> None:
    # I test vogliono "Target" e "flow" su stdout
    c = cout()
    c.print(Text("Make targets", style="bold"))
    c.print(Text("Discover available Makefile targets under flow/ 🧰", style="dim"))
    c.print()

    t = Table(show_lines=False)
    t.add_column("Target", style="bold")
    for x in targets:
        t.add_row(x)

    c.print(Panel(t, title="flow", expand=False))


def print_runner_summary(*, label: str, exit_code: int, runner_dir: Path, flow_dir: Optional[Path]) -> None:
    # Stderr only
    c = cerr()
    lines = [
        f"[b]{label}[/b]",
        f"Exit code: {exit_code}",
        f"Runner dir: {runner_dir}",
    ]
    if flow_dir is not None:
        lines.append(f"Flow dir: {flow_dir}")

    c.print(Panel("\n".join(lines), title="Summary", expand=False))
