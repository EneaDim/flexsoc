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
    running_status,
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


def _common_make_vars(
    *,
    workspace: Path,
    top: Optional[str],
    run_top: Optional[str],
    run_id: Optional[str],
    reg_itf: Optional[str],
    overwrite: bool,
    force: bool,
) -> Dict[str, str]:
    """
    Build the common Make variable mapping shared by `run` and `make`.

    Rules:
    - WORKSPACE is always passed as an absolute path
    - TOP / RUN_ID / REG_ITF are included only when provided
    - --force is only a CLI alias for overwrite
    - OVERWRITE is normalized to the Make contract expected by the flow
    """
    make_vars: Dict[str, str] = {
        "WORKSPACE": str(Path(workspace).resolve()),
    }

    if top is not None:
        make_vars["TOP"] = top
    if run_top is not None:
        make_vars["RUN_TOP"] = run_top
    if run_id is not None:
        make_vars["RUN_ID"] = run_id
    if reg_itf is not None:
        make_vars["REG_ITF"] = reg_itf
    if overwrite or force:
        make_vars["OVERWRITE"] = "--force"

    return make_vars



def _split_make_targets_and_passthrough(
    initial_targets: list[str],
    extra_args: list[str],
) -> tuple[list[str], Dict[str, str], list[str]]:
    """
    Build the final ordered target list for `flexsoc make`.

    Why this exists:
    - Typer may parse only the first positional target and leave the rest in ctx.args
      because this command also accepts raw passthrough args.
    - We want:
        flexsoc make ip_start syn sta power --top my_ip --run-id dev
      to mean four sequential make invocations, not one invocation with extra goals.

    Return:
    - targets: full ordered target list
    - override_vars: KEY=VALUE overrides from raw passthrough
    - passthrough: remaining raw args (flags etc.)
    """
    targets = list(initial_targets or [])
    override_vars: Dict[str, str] = {}
    passthrough: list[str] = []

    for arg in extra_args:
        if "=" in arg and not arg.startswith("-"):
            key, value = arg.split("=", 1)
            if key:
                override_vars[key] = value
                continue

        # Bare non-option words are interpreted as additional make targets.
        if not arg.startswith("-"):
            targets.append(arg)
            continue

        passthrough.append(arg)

    return targets, override_vars, passthrough

def _parse_make_var_overrides(extra_args: list[str]) -> tuple[Dict[str, str], list[str]]:
    """
    Split `make` extra args into:
    - KEY=VALUE overrides
    - passthrough positional/flag args

    This keeps backward compatibility with:
      flexsoc make ip_start -- TOP=... RUN_ID=...

    while allowing common CLI flags to generate the same variables.
    """
    overrides: Dict[str, str] = {}
    passthrough: list[str] = []

    for arg in extra_args:
        if "=" in arg and not arg.startswith("-"):
            key, value = arg.split("=", 1)
            if key:
                overrides[key] = value
                continue
        passthrough.append(arg)

    return overrides, passthrough


def _repo_root() -> Path:
    # src/flexsoc/cli.py -> repo root = parents[2]
    return Path(__file__).resolve().parents[2]


def _flow_dir() -> Path:
    return (_repo_root() / "flow").resolve()



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
    actions_map = reg.get("actions") or {}
    print_actions_table(actions_map)


# ----------------------------------------------------------------------
# Short aliases (real Typer commands)
# ----------------------------------------------------------------------

@app.command("h")
def hub_alias() -> None:
    """Alias for hub."""
    print_hub()


@app.command("q")
def quickstart_alias() -> None:
    """Show quickstart guide."""
    print_quickstart()


@app.command("t")
def tutorial_alias() -> None:
    """Show tutorial."""
    print_tutorial()


@app.command("ip")
def ip_alias() -> None:
    """Show IP flow guide."""
    print_ip_guide()


@app.command("a")
def actions_alias() -> None:
    """Alias for `flexsoc actions`."""
    actions()


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
    run_top: Optional[str] = typer.Option(None, "--run-top"),
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
    if run_top is not None:
        plan.params["run_top"] = run_top
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

    cmd_preview = "flexsoc exec " + str(plan_path)
    if top is not None:
        cmd_preview += f" --top {top}"
    if run_top is not None:
        cmd_preview += f" --run-top {run_top}"
    if run_id is not None:
        cmd_preview += f" --run-id {run_id}"
    if reg_itf is not None:
        cmd_preview += f" --reg-itf {reg_itf}"
    cmd_preview += f" --workspace {ws}"
    if overwrite or force:
        cmd_preview += " --overwrite"

    run_top_preview = plan.params.get("run_top") or plan.params.get("top")
    flow_dir_preview = None
    if run_top_preview and run_id:
        flow_dir_preview = ws / "runs" / str(run_top_preview) / str(run_id)

    with running_status(label=f"exec {plan.action}"):
        res = execute_action(
            action=plan.action,
            params=plan.params,
            workspace=ws,
            run_id=run_id,
        )

    flow_dir = None
    run_top2 = plan.params.get("run_top") or plan.params.get("top")
    if run_top2 and run_id:
        flow_dir = ws / "runs" / str(run_top2) / str(run_id)

    print_runner_summary(
        label=f"exec {plan.action}",
        exit_code=res.exit_code,
        runner_dir=res.runner_run_dir,
        flow_dir=flow_dir,
        command=cmd_preview,
    )
    raise typer.Exit(res.exit_code)


@app.command("run")
def run_cmd(
    action_id: str = typer.Argument(...),
    workspace: Optional[Path] = typer.Option(None, "--workspace", "--ws"),
    top: Optional[str] = typer.Option(None, "--top"),
    run_top: Optional[str] = typer.Option(None, "--run-top"),
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
    if run_top is not None:
        params["run_top"] = run_top
    if reg_itf is not None:
        params["reg_itf"] = reg_itf
    if overwrite or force:
        params["overwrite"] = "1"
    params.pop("force", None)

    cmd_preview = f"flexsoc run {action_id}"
    if top is not None:
        cmd_preview += f" --top {top}"
    if run_top is not None:
        cmd_preview += f" --run-top {run_top}"
    if run_id is not None:
        cmd_preview += f" --run-id {run_id}"
    if reg_itf is not None:
        cmd_preview += f" --reg-itf {reg_itf}"
    cmd_preview += f" --workspace {ws}"
    if overwrite or force:
        cmd_preview += " --overwrite"

    flow_dir_preview = None
    run_top_preview = run_top or top
    if run_top_preview and run_id:
        flow_dir_preview = ws / "runs" / run_top_preview / run_id

    with running_status(label=f"run {action_id}"):
        res = execute_action(
            action=action_id,
            params=params,
            workspace=ws,
            run_id=run_id,
        )

    flow_dir = None
    run_top2 = run_top or top
    if run_top2 and run_id:
        flow_dir = ws / "runs" / run_top2 / run_id

    print_runner_summary(
        label=f"run {action_id}",
        exit_code=res.exit_code,
        runner_dir=res.runner_run_dir,
        flow_dir=flow_dir,
        command=cmd_preview,
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
    targets: list[str] = typer.Argument(None),
    list_targets: bool = typer.Option(False, "--list"),
    workspace: Optional[Path] = typer.Option(None, "--workspace", "--ws"),
    top: Optional[str] = typer.Option(None, "--top"),
    run_top: Optional[str] = typer.Option(None, "--run-top"),
    run_id: Optional[str] = typer.Option(None, "--run-id"),
    reg_itf: Optional[str] = typer.Option(None, "--reg-itf"),
    overwrite: bool = typer.Option(False, "--overwrite"),
    force: bool = typer.Option(False, "--force", help="Alias for --overwrite"),
) -> None:
    _setup_logging()
    ws = (workspace or default_workspace()).resolve()
    repo_root = _repo_root()
    flow_make_dir = _flow_dir()

    if list_targets:
        targets = _make_list_targets(flow_make_dir) or ["help"]
        print_make_targets(targets)
        raise typer.Exit(0)

    # Common typed CLI flags -> canonical Make variables
    common_vars = _common_make_vars(
        workspace=ws,
        top=top,
        run_top=run_top,
        run_id=run_id,
        reg_itf=reg_itf,
        overwrite=overwrite,
        force=force,
    )

    # Extra args after `--` may contain:
    # - additional positional make targets
    # - KEY=VALUE make var overrides
    # - raw passthrough flags
    extra_args = list(ctx.args)
    final_targets, override_vars, passthrough = _split_make_targets_and_passthrough(targets, extra_args)

    if not final_targets:
        raise typer.BadParameter(
            "Missing target. Use: flexsoc make --list OR flexsoc make <target> [<target> ...] [-- ...]"
        )

    # Backward compatibility rule:
    # raw KEY=VALUE overrides passed after `--` win over typed flags.
    make_vars = {**common_vars, **override_vars}

    backend = MakeBackend()

    for target in final_targets:
        action_exec_id = f"make_{target}"

        cmd = ["make", "-C", str(flow_make_dir), target]
        cmd.extend([f"{k}={v}" for k, v in make_vars.items()])
        cmd.extend(passthrough)

        flow_run_dir_preview = None
        run_top2 = make_vars.get("RUN_TOP") or make_vars.get("TOP")
        run_id2 = make_vars.get("RUN_ID")
        if run_top2 and run_id2:
            flow_run_dir_preview = ws / "runs" / str(run_top2) / str(run_id2)

        cmd_preview = " ".join(cmd)

        with running_status(label=f"make {target}"):
            res = backend.run(
                action_id=action_exec_id,
                cmd=cmd,
                params={
                    "target": target,
                    "targets": final_targets,
                    "make_vars": make_vars,
                    "passthrough": passthrough,
                },
                workspace_dir=ws,
                cwd=repo_root,
                env=os.environ.copy(),
            )

        print_runner_summary(
            label=f"make {target}",
            exit_code=res.exit_code,
            runner_dir=res.run_dir,
            flow_dir=flow_run_dir_preview,
            command=cmd_preview,
        )

        if res.exit_code != 0:
            raise typer.Exit(res.exit_code)

    raise typer.Exit(0)


if __name__ == "__main__":
    if _early_shortcuts():
        raise SystemExit(0)
    app()
