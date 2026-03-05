from __future__ import annotations

# flexsoc CLI (rewritten, Ruff-clean)
#
# Contracts:
# - `python -m flexsoc.cli` must work.
# - stdout must remain clean for structured outputs (e.g. dump-registry).
# - UI summaries must go to stderr (tests look for "Runner dir:" in stderr).
# - Support shortcuts (?, h, q, t, ip) BEFORE Typer parses argv (because '?' breaks Typer parsing).

import json
import logging
import os
import subprocess
import sys
from pathlib import Path
from typing import Any, Dict, Optional

import typer

from .config import default_workspace
from .executor import execute_action
from .planning import (
    load_registry,
    naive_intent_to_plan,
    read_plan_json,
    validate_plan,
    write_plan_json,
)
from .runner import MakeBackend
from .ui import (
    print_action_detail,
    print_actions_table,
    print_help_topics,
    print_hub,
    print_ip_guide,
    print_make_targets,
    print_quickstart,
    print_runner_summary,
    print_tutorial,
)

log = logging.getLogger(__name__)

app = typer.Typer(add_completion=False, invoke_without_command=True)
help_app = typer.Typer(add_completion=False)
app.add_typer(help_app, name="help")


def _setup_logging() -> None:
    """Always log to stderr so we never pollute stdout contracts."""
    level_s = os.environ.get("FLEXSOC_LOG_LEVEL", "").strip().upper()
    level = getattr(logging, level_s, logging.INFO) if level_s else logging.INFO
    logging.basicConfig(level=level, format="%(levelname)s: %(message)s", stream=sys.stderr)


def _registry_path() -> Path:
    return Path(__file__).parent / "registry.yaml"


def _registry() -> Dict[str, Any]:
    return load_registry(_registry_path())


def _early_shortcuts() -> bool:
    """Handle ?,h,q,t,ip before Typer parsing (required for '?')."""
    argv = sys.argv[1:]
    if not argv:
        return False

    if argv in (["?"], ["h"]):
        print_hub()
        return True
    if argv == ["q"]:
        print_quickstart()
        return True
    if argv == ["t"]:
        print_tutorial()
        return True
    if argv == ["ip"]:
        print_ip_guide()
        return True
    return False


@app.callback(invoke_without_command=True)
def _root(ctx: typer.Context) -> None:
    """Show hub when no subcommand is provided."""
    if ctx.invoked_subcommand is not None:
        return
    if len(sys.argv) == 1:
        print_hub()
        raise typer.Exit(0)


@app.command("dump-registry")
def dump_registry() -> None:
    """Pure JSON to stdout, no UI."""
    _setup_logging()
    sys.stdout.write(json.dumps(_registry(), indent=2))
    sys.stdout.write("\n")


@app.command("actions")
def actions() -> None:
    _setup_logging()
    reg = _registry()
    action_ids = (reg.get("actions") or {}).keys()
    print_actions_table(action_ids)


@app.command("action")
def action(action_id: str) -> None:
    _setup_logging()
    reg = _registry()
    actions_map = reg.get("actions") or {}
    meta = actions_map.get(action_id)
    if meta is None:
        raise typer.Exit(2)
    print_action_detail(action_id, meta)


@help_app.command("topics")
def help_topics() -> None:
    _setup_logging()
    print_help_topics()


@help_app.command("action")
def help_action(action_id: str) -> None:
    """Alias used by tests: flexsoc help action <id>."""
    action(action_id)


@app.command("plan")
def plan_cmd(
    text: str = typer.Argument(..., help="Tests pass: 'create ip'"),
    out: Path = typer.Option(Path("plan.json"), "--out"),
) -> None:
    _setup_logging()
    plan = naive_intent_to_plan(text)
    reg = _registry()
    validate_plan(plan, reg, allow_missing_required=True)
    write_plan_json(plan, out)


@app.command("exec")
def exec_cmd(
    plan_path: Path = typer.Argument(...),
    workspace: Optional[Path] = typer.Option(None, "--workspace", "--ws"),
    top: Optional[str] = typer.Option(None, "--top"),
    run_id: Optional[str] = typer.Option(None, "--run-id"),
    reg_itf: Optional[str] = typer.Option(None, "--reg-itf"),
    overwrite: bool = typer.Option(False, "--overwrite"),
    force: bool = typer.Option(False, "--force", help="Alias for --overwrite"),
    profile: bool = typer.Option(False, "--profile"),
) -> None:
    _setup_logging()
    ws = (workspace or default_workspace()).resolve()
    plan = read_plan_json(plan_path)

    # CLI overrides:
    # - top/reg_itf are registry params (validated)
    # - run_id is NOT a registry param; it must be passed separately to executor/runner
    if top is not None:
        plan.params["top"] = top
    if reg_itf is not None:
        plan.params["reg_itf"] = reg_itf

    # overwrite is a registry param, keep it. force must never reach validation.
    if overwrite or force:
        plan.params["overwrite"] = "1"
    plan.params.pop("force", None)
    plan.params.pop("run_id", None)

    reg = _registry()
    validate_plan(plan, reg, allow_missing_required=False)

    if profile:
        os.environ["FLEXSOC_PROFILE"] = "1"

    res = execute_action(
        action=plan.action,
        params=plan.params,
        workspace=ws,
        run_id=run_id,
    )

    flow_dir = None
    top2 = plan.params.get("top")
    if top2 and run_id:
        flow_dir = ws / "runs" / str(top2) / str(run_id)

    print_runner_summary(
        label=f"exec {plan.action}",
        exit_code=res.exit_code,
        runner_dir=res.runner_run_dir,
        flow_dir=flow_dir,
    )
    raise typer.Exit(res.exit_code)


@app.command("run")
def run_cmd(
    action_id: str = typer.Argument(...),
    workspace: Optional[Path] = typer.Option(None, "--workspace", "--ws"),
    top: Optional[str] = typer.Option(None, "--top"),
    run_id: Optional[str] = typer.Option(None, "--run-id"),
    reg_itf: Optional[str] = typer.Option(None, "--reg-itf"),
    overwrite: bool = typer.Option(False, "--overwrite"),
    force: bool = typer.Option(False, "--force", help="Alias for --overwrite"),
) -> None:
    _setup_logging()
    ws = (workspace or default_workspace()).resolve()

    params: Dict[str, Any] = {}
    if top is not None:
        params["top"] = top
    if reg_itf is not None:
        params["reg_itf"] = reg_itf
    if overwrite or force:
        params["overwrite"] = "1"
    params.pop("force", None)

    res = execute_action(
        action=action_id,
        params=params,
        workspace=ws,
        run_id=run_id,
    )

    flow_dir = None
    if top and run_id:
        flow_dir = ws / "runs" / top / run_id

    print_runner_summary(
        label=f"run {action_id}",
        exit_code=res.exit_code,
        runner_dir=res.runner_run_dir,
        flow_dir=flow_dir,
    )
    raise typer.Exit(res.exit_code)


def _make_list_targets(flow_dir: Path) -> list[str]:
    """Best-effort target discovery via `make -qp`."""
    p = subprocess.run(
        ["make", "-C", str(flow_dir), "-qp"],
        capture_output=True,
        text=True,
        check=False,
    )
    targets: set[str] = set()
    for line in p.stdout.splitlines():
        if not line or line.startswith("#") or line.startswith("."):
            continue
        if ":" not in line:
            continue
        name = line.split(":", 1)[0].strip()
        if not name or "%" in name:
            continue
        if name == "Makefile":
            continue
        targets.add(name)
    return sorted(targets)


@app.command("make", context_settings={"allow_extra_args": True, "ignore_unknown_options": True})
def make_cmd(
    ctx: typer.Context,
    target: Optional[str] = typer.Argument(None),
    list_targets: bool = typer.Option(False, "--list"),
    workspace: Optional[Path] = typer.Option(None, "--workspace", "--ws"),
) -> None:
    _setup_logging()
    ws = (workspace or default_workspace()).resolve()
    repo_root = Path(__file__).resolve().parents[2]
    flow_dir = (repo_root / "flow").resolve()

    if list_targets:
        targets = _make_list_targets(flow_dir) or ["help"]
        print_make_targets(targets)
        raise typer.Exit(0)

    if not target:
        raise typer.BadParameter("Missing target. Use: flexsoc make --list OR flexsoc make <target> [-- ...]")

    extra = list(ctx.args)

    backend = MakeBackend()
    action_exec_id = f"make_{target}"
    cmd = ["make", "-C", str(flow_dir), target] + extra

    res = backend.run(
        action_id=action_exec_id,
        cmd=cmd,
        params={"target": target, "extra": extra},
        workspace_dir=ws,
        cwd=repo_root,
        env=os.environ.copy(),
    )

    print_runner_summary(
        label=f"make {target}",
        exit_code=res.exit_code,
        runner_dir=res.run_dir,
        flow_dir=None,
    )
    raise typer.Exit(res.exit_code)


if __name__ == "__main__":
    if _early_shortcuts():
        raise SystemExit(0)
    app()
