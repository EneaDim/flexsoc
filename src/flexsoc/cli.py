from __future__ import annotations

import json
import logging
import os
import subprocess
import sys
from pathlib import Path
from typing import Any, Dict, Optional

import typer
import yaml
from rich import print

from .clean import clean_run, clean_workspace
from .config import default_workspace
from .doctor import run_doctor
from .executor import execute_action
from .planning import (
    Plan,
    load_registry,
    naive_intent_to_plan,
    read_plan_json,
    validate_plan,
    write_plan_json,
)

app = typer.Typer(add_completion=False)


def _setup_logging() -> None:
    """
    Structured logging (opt-in) without breaking CLI output contracts.

    Enable with:
      FLEXSOC_LOG_LEVEL=INFO
      FLEXSOC_LOG_LEVEL=DEBUG
    """
    level_name = os.environ.get("FLEXSOC_LOG_LEVEL", "WARNING").upper()
    level = getattr(logging, level_name, logging.WARNING)

    root = logging.getLogger()
    if root.handlers:
        root.setLevel(level)
        return

    try:
        from rich.logging import RichHandler

        handler = RichHandler(rich_tracebacks=True, show_time=False, show_path=False)
        logging.basicConfig(level=level, handlers=[handler])
    except Exception:
        logging.basicConfig(level=level, format="%(levelname)s %(name)s: %(message)s")


def _load_registry() -> Dict[str, Any]:
    reg_path = Path(__file__).with_name("registry.yaml")
    data = yaml.safe_load(reg_path.read_text(encoding="utf-8"))
    if not isinstance(data, dict) or "actions" not in data:
        raise typer.BadParameter("Invalid registry.yaml: missing 'actions'")
    return data


def _render_env(params: Dict[str, Any]) -> Dict[str, str]:
    # Kept for future use; current execution passes VAR=... via command list (safer than env-only).
    env: Dict[str, str] = {}
    return env


@app.command()
def doctor() -> None:
    _setup_logging()
    rc = run_doctor()
    raise SystemExit(rc)


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
    _setup_logging()
    log = logging.getLogger(__name__)

    # Collect params (map to Makefile vars via executor)
    params: Dict[str, Any] = {}
    if design is not None:
        params["design"] = design
    if top is not None:
        params["top"] = top
    if corner is not None:
        params["corner"] = corner
    if reg_itf is not None:
        params["reg_itf"] = reg_itf
    if overwrite is not None:
        params["overwrite"] = overwrite
    if seed is not None:
        params["seed"] = seed

    ws = (workspace or default_workspace()).resolve()
    log.debug("CLI run: action=%s workspace=%s run_id=%s params=%s", action, ws, run_id, params)

    res = execute_action(
        action=action,
        params=params,
        workspace=ws,
        run_id=run_id,
    )

    # CONTRACT: keep these prints stable (E2E rely on them)
    print(f"Runner dir: {res.runner_run_dir}")
    if res.flow_run_dir:
        print(f"Flow dir: {res.flow_run_dir}")

    raise typer.Exit(code=res.exit_code)

@app.command()
def dump_registry() -> None:
    _setup_logging()
    reg = _load_registry()
    sys.stdout.write(json.dumps(reg, indent=2))
    sys.stdout.write("\n")

@app.command("clean-run")
def clean_run_cmd(
    top: str = typer.Option(..., help="Top name"),
    run_id: str = typer.Option(..., help="Run id"),
    workspace: Optional[Path] = typer.Option(None, help="Workspace directory"),
) -> None:
    _setup_logging()
    ws = (workspace or default_workspace()).resolve()
    clean_run(ws, top, run_id)


@app.command("clean-workspace")
def clean_workspace_cmd(
    workspace: Optional[Path] = typer.Option(None, help="Workspace directory"),
) -> None:
    _setup_logging()
    ws = (workspace or default_workspace()).resolve()
    clean_workspace(ws)


@app.command("plan")
def plan_cmd(
    text: str = typer.Argument(..., help="Natural language request"),
    out: Path = typer.Option(Path("plan.json"), help="Output plan JSON path"),
) -> None:
    _setup_logging()
    registry = load_registry(Path(__file__).parent / "registry.yaml")
    plan = naive_intent_to_plan(text)
    validate_plan(plan, registry, allow_missing_required=True)
    write_plan_json(plan, out)
    print(f"Plan written: {out}")


@app.command("exec")
def exec_cmd(
    plan_path: Path = typer.Argument(..., help="Path to plan JSON"),
    workspace: Optional[Path] = typer.Option(None, help="Workspace directory"),
    run_id: Optional[str] = typer.Option(None, help="Run identifier"),
    overwrite: Optional[str] = typer.Option(None, help="Overwrite flag (e.g. --force)"),
    reg_itf: Optional[str] = typer.Option(None, help="Register interface (e.g. tlul)"),
    top: Optional[str] = typer.Option(None, help="Top name (if plan doesn't contain it)"),
) -> None:
    _setup_logging()
    registry = load_registry(Path(__file__).parent / "registry.yaml")
    plan = read_plan_json(plan_path)

    # Allow CLI overrides
    params = dict(plan.params)
    if top is not None:
        params["top"] = top
    if reg_itf is not None:
        params["reg_itf"] = reg_itf
    if overwrite is not None:
        params["overwrite"] = overwrite

    validate_plan(Plan(action=plan.action, params=params), registry)

    # Execute deterministically via CLI to avoid Typer OptionInfo leaking into runtime defaults
    cmd = [sys.executable, "-m", "flexsoc.cli", "run", plan.action]

    # Apply plan params first (as CLI flags)
    if "top" in params:
        cmd += ["--top", str(params["top"])]
    if "reg_itf" in params:
        cmd += ["--reg-itf", str(params["reg_itf"])]
    if "overwrite" in params:
        # overwrite is expected as a raw flag value, e.g. "--force"
        cmd += ["--overwrite", str(params["overwrite"])]

    # Runtime execution context
    if workspace is not None:
        cmd += ["--workspace", str(workspace)]
    if run_id is not None:
        cmd += ["--run-id", str(run_id)]

    p = subprocess.run(cmd, text=True)
    raise typer.Exit(code=p.returncode)


if __name__ == "__main__":
    app()
