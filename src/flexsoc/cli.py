from __future__ import annotations

import json
from pathlib import Path
from typing import Any, Dict, Optional

import typer
import yaml
from rich import print

from .config import default_workspace
from .runner import run_command

app = typer.Typer(add_completion=False)


def _load_registry() -> Dict[str, Any]:
    reg_path = Path(__file__).with_name("registry.yaml")
    data = yaml.safe_load(reg_path.read_text(encoding="utf-8"))
    if not isinstance(data, dict) or "actions" not in data:
        raise typer.BadParameter("Invalid registry.yaml: missing 'actions'")
    return data


def _render_env(params: Dict[str, Any]) -> Dict[str, str]:
    # minimal: pass as MAKE variables (uppercase)
    env: Dict[str, str] = {}
    # We prefer passing via command args as VAR=... but env also works.
    # We'll do VAR=... via command injection-free list for make.
    return env


@app.command()
def doctor() -> None:
    # Minimal placeholder: extend later to check toolchain versions
    print("[bold]flexsoc doctor[/bold] (TODO: toolchain checks)")


@app.command()
def run(
    action: str = typer.Argument(..., help="Action id (e.g. lint, synth, sta, sim, pnr)"),
    design: Optional[str] = typer.Option(None, help="Design name"),
    top: Optional[str] = typer.Option(None, help="Top module"),
    corner: Optional[str] = typer.Option(None, help="Corner (e.g. min/max)"),
    seed: Optional[int] = typer.Option(None, help="Simulation seed"),
    workspace: Optional[Path] = typer.Option(None, help="Workspace directory"),
) -> None:
    reg = _load_registry()
    actions = reg["actions"]
    if action not in actions:
        raise typer.BadParameter(f"Unknown action '{action}'. Available: {', '.join(actions.keys())}")

    params: Dict[str, Any] = {}
    if design is not None:
        params["design"] = design
    if top is not None:
        params["top"] = top
    if corner is not None:
        params["corner"] = corner
    if seed is not None:
        params["seed"] = seed

    cmd = list(actions[action]["command"])

    # Append Make VAR overrides as "KEY=VALUE" tokens (one-shot overrides)
    # This preserves the "only for this command" behavior.
    for k, v in params.items():
        cmd.append(f"{k.upper()}={v}")

    ws = (workspace or default_workspace()).resolve()
    result = run_command(action_id=action, cmd=cmd, params=params, workspace_dir=ws)
    print(f"[bold]Run dir:[/bold] {result.run_dir}")
    print(f"[bold]Exit code:[/bold] {result.exit_code}")
    raise typer.Exit(code=result.exit_code)


@app.command()
def dump_registry() -> None:
    reg = _load_registry()
    print_json = json.dumps(reg, indent=2)
    print(print_json)
