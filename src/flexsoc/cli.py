from __future__ import annotations

import json
from pathlib import Path
from typing import Any, Dict, Optional

import typer
import yaml
from rich import print

from .config import default_workspace
from .runner import run_command
from .reporting import parse_ip_start_flow, write_report_json
from .manifest import write_flow_manifest
from .doctor import run_doctor
from .clean import clean_run, clean_workspace

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
    reg_itf: Optional[str] = typer.Option(None, help="Register interface (e.g. tlul)"),
    overwrite: Optional[str] = typer.Option(None, help="Overwrite flag (e.g. --force)"),
    workspace: Optional[Path] = typer.Option(None, help="Workspace directory"),
    run_id: Optional[str] = typer.Option(None, help="Run identifier (defaults to timestamp)"),
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

    if reg_itf is not None:
        params["reg_itf"] = reg_itf
    if overwrite is not None:
        params["overwrite"] = overwrite

    cmd = list(actions[action]["command"])

    ws = (workspace or default_workspace()).resolve()
    rid = run_id or None

    # Force flow outputs under workspace (Makefile uses WORKSPACE/RUN_ID)
    cmd.append(f"WORKSPACE={ws}")
    if rid:
        cmd.append(f"RUN_ID={rid}")



    # Append Make VAR overrides as "KEY=VALUE" tokens (one-shot overrides)
    # This preserves the "only for this command" behavior.
    for k, v in params.items():
        cmd.append(f"{k.upper()}={v}")

     
    rid = run_id or None

    result = run_command(action_id=action, cmd=cmd, params=params, workspace_dir=ws)

    print(f"[bold]Run dir:[/bold] {result.run_dir}")
    print(f"[bold]Exit code:[/bold] {result.exit_code}")
    raise typer.Exit(code=result.exit_code)


@app.command()
def dump_registry() -> None:
    reg = _load_registry()
    print_json = json.dumps(reg, indent=2)
    print(print_json)


if __name__ == "__main__":
    app()


@app.command("clean-run")
def clean_run_cmd(
    top: str = typer.Option(..., help="Top name"),
    run_id: str = typer.Option(..., help="Run id"),
    workspace: Optional[Path] = typer.Option(None, help="Workspace directory"),
) -> None:
     
    ws = (workspace or default_workspace()).resolve()
    ws = (workspace or default_workspace()).resolve()
    clean_run(ws, top, run_id)


@app.command("clean-workspace")
def clean_workspace_cmd(
    workspace: Optional[Path] = typer.Option(None, help="Workspace directory"),
) -> None:
     
    ws = (workspace or default_workspace()).resolve()
    clean_workspace(ws)
