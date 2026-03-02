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
from .planning import Plan, load_registry, validate_plan, write_plan_json, naive_intent_to_plan
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


    # Resolve workspace/run-id once (used for flow outputs)
    ws = (workspace or default_workspace()).resolve()
    rid = run_id

    # Ensure deterministic flow output location for make-based actions
    # (critical for e2e tests + agents)
    if action == "ip_start":
        if not rid:
            raise typer.BadParameter("--run-id is required for ip_start (deterministic workspace runs)")
        cmd.append(f"WORKSPACE={ws}")
        cmd.append(f"RUN_ID={rid}")


    ws = (workspace or default_workspace()).resolve()
    rid = run_id or None



    # Append Make VAR overrides as "KEY=VALUE" tokens (one-shot overrides)
    # This preserves the "only for this command" behavior.
    for k, v in params.items():
        cmd.append(f"{k.upper()}={v}")

     
    rid = run_id or None

    result = run_command(action_id=action, cmd=cmd, params=params, workspace_dir=ws)


    if action == "ip_start":
        top_name = params.get("top")
        flow_run_dir = ws / "runs" / str(top_name) / str(rid)
        if not flow_run_dir.exists():
            # Fail loudly with debugging info
            candidates = sorted((ws / "runs" / str(top_name)).glob("*")) if (ws / "runs" / str(top_name)).exists() else []
            raise RuntimeError(f"Expected flow run dir missing: {flow_run_dir}. Existing: {[c.name for c in candidates]}")
        write_flow_manifest(
            flow_run_dir,
            action=action,
            top=str(top_name),
            run_id=str(rid),
            workspace=ws,
            params=params,
        )
        report = parse_ip_start_flow(flow_run_dir)
        write_report_json(report, flow_run_dir / "report.json")


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


@app.command("plan")
def plan_cmd(
    text: str = typer.Argument(..., help="Natural language request"),
    out: Path = typer.Option(Path("plan.json"), help="Output plan JSON path"),
) -> None:
    registry = load_registry(Path(__file__).parent / "registry.yaml")
    plan = naive_intent_to_plan(text)
    validate_plan(plan, registry)
    write_plan_json(plan, out)
    print(f"Plan written: {out}")
