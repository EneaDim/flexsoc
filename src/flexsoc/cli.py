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
from click.shell_completion import CompletionItem
from rich.console import Console
from rich.panel import Panel
from rich.table import Table
from rich.text import Text

from .config import default_workspace
from .executor import execute_action
from .doctor import run_doctor
from .context import clear_context, load_context, resolve_context, save_context
from .clean import clean_all, clean_pycache, clean_run, clean_workspace
from .helptext import (
    render_detailed_help,
    render_help_overview,
    render_home_help,
    render_ip_guide,
    render_quickstart,
    render_tutorials,
)
from .manifest import read_run_history
from .orchestration import InvocationSpec, run_orchestrated
from .planning import (
    load_registry,
    naive_intent_to_plan,
    read_plan_json,
    validate_plan,
    write_plan_json,
)
from .workspace import resolve_run_ref
from .ui import (
    print_action_detail,
    print_actions_table,
    print_help_topics,
    print_hub,
    print_make_targets,
    print_runner_summary,
    running_status,
)

log = logging.getLogger(__name__)

app = typer.Typer(add_completion=False, invoke_without_command=True, rich_markup_mode="rich")
help_app = typer.Typer(add_completion=False, rich_markup_mode="rich")
runs_app = typer.Typer(add_completion=False, help="Inspect workspace runs", rich_markup_mode="rich")
app.add_typer(help_app, name="help")
app.add_typer(runs_app, name="runs")


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
        render_quickstart()
        return True
    if argv == ["t"]:
        render_tutorials()
        return True
    if argv == ["ip"]:
        render_ip_guide()
        return True
    return False


@app.callback(invoke_without_command=True)
def main_callback(ctx: typer.Context) -> None:
    if ctx.invoked_subcommand is None:
        _setup_logging()
        render_home_help()
        raise typer.Exit()






@runs_app.command("ls")
def runs_ls(
    workspace: Path = typer.Option(Path("workspace"), "--workspace", "--ws", help="Workspace directory"),
) -> None:
    _setup_logging()
    ws = workspace.expanduser().resolve()
    _print_runs_ls(workspace=ws)


@runs_app.command("show")
def runs_show(
    run_top: str = typer.Option(..., "--run-top", help="Run-top name"),
    run_id: str = typer.Option(..., "--run-id", help="Run identifier"),
    workspace: Path = typer.Option(Path("workspace"), "--workspace", help="Workspace directory"),
    history_limit: int = typer.Option(10, "--history-limit", min=1, help="Number of history entries to show"),
) -> None:
    ws = workspace.expanduser().resolve()
    run_dir = ws / "runs" / run_top / run_id
    _print_run_show(run_dir=run_dir, history_limit=history_limit)




@app.command("hd")
def help_detailed_alias() -> None:
    _setup_logging()
    render_detailed_help()


@help_app.command("detailed")
def help_detailed_cmd() -> None:
    _setup_logging()
    render_detailed_help()


@help_app.command("commands")
def help_commands_cmd() -> None:
    _setup_logging()
    render_detailed_help()


@help_app.command("overview")
def help_overview_cmd() -> None:
    _setup_logging()
    render_help_overview()



@app.command("doctor")
def doctor_cmd() -> None:
    """Check Python deps and external toolchain availability."""
    _setup_logging()
    raise typer.Exit(run_doctor())


@app.command("clean-pycache")
def clean_pycache_cmd(
    root: Path = typer.Option(Path("."), "--root", help="Root directory to clean"),
) -> None:
    _setup_logging()
    removed = clean_pycache(root.expanduser().resolve())
    typer.echo(f"Removed {removed} Python cache entries")


@app.command("clean-run")
def clean_run_cmd(
    run_top: str = typer.Option(..., "--run-top", help="Run-top name"),
    run_id: str = typer.Option(..., "--run-id", help="Run identifier"),
    workspace: Path = typer.Option(Path("workspace"), "--workspace", "--ws", help="Workspace directory"),
) -> None:
    _setup_logging()
    ws = workspace.expanduser().resolve()
    clean_run(ws, run_top, run_id)
    typer.echo(f"Removed run: {ws / 'runs' / run_top / run_id}")


@app.command("clean-workspace")
def clean_workspace_cmd(
    workspace: Path = typer.Option(Path("workspace"), "--workspace", "--ws", help="Workspace directory"),
) -> None:
    _setup_logging()
    ws = workspace.expanduser().resolve()
    clean_workspace(ws)
    typer.echo(f"Cleaned workspace runs under: {ws}")


@app.command("clean-all")
def clean_all_cmd(
    workspace: Path = typer.Option(Path("workspace"), "--workspace", "--ws", help="Workspace directory"),
) -> None:
    _setup_logging()
    ws = workspace.expanduser().resolve()
    clean_all(ws)
    typer.echo(f"Removed workspace: {ws}")


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

    rows: list[tuple[str, str]] = []
    for name in actions_map:
        meta = actions_map.get(name) or {}
        desc = str(meta.get("description", ""))
        rows.append((name, desc))

    print_actions_table(rows)


# ----------------------------------------------------------------------
# Short aliases (real Typer commands)
# ----------------------------------------------------------------------

@app.command("h")
def help_hub() -> None:
    _setup_logging()
    render_home_help()


@app.command("q")
def quickstart_alias() -> None:
    """Show quickstart guide."""
    render_quickstart()


@app.command("t")
def tutorial_alias() -> None:
    """Show tutorial."""
    render_tutorials()

@app.command("ip")
def ip_alias() -> None:
    """Show IP flow guide."""
    render_ip_guide()


@app.command("a")
def actions_alias() -> None:
    """Alias for `flexsoc actions`."""
    actions()


def _read_run_yaml_summary(run_yaml: Path) -> dict[str, str]:
    out: dict[str, str] = {
        "run_top": "",
        "run_id": "",
        "top": "",
        "last_action": "",
        "updated_at_utc": "",
    }

    if not run_yaml.exists():
        return out

    for raw_line in run_yaml.read_text(encoding="utf-8").splitlines():
        line = raw_line.rstrip()
        if not line or line.startswith(" ") or ":" not in line:
            continue

        key, value = line.split(":", 1)
        key = key.strip()
        value = value.strip()

        if key not in out:
            continue

        if value.startswith('"') and value.endswith('"') and len(value) >= 2:
            value = value[1:-1]
            value = value.replace(chr(92) + '"', '"')
            value = value.replace(chr(92) + chr(92), chr(92))

        out[key] = value

    return out


def _count_loaded_ips_from_run_yaml(run_yaml: Path) -> int:
    if not run_yaml.exists():
        return 0

    lines = run_yaml.read_text(encoding="utf-8").splitlines()
    in_loaded_ips = False
    count = 0

    for raw_line in lines:
        line = raw_line.rstrip()

        if not in_loaded_ips:
            if line == "loaded_ips:":
                in_loaded_ips = True
            continue

        if not line.startswith("  "):
            break

        stripped = line.strip()
        if stripped == "[]":
            return 0
        if stripped.startswith("- "):
            count += 1

    return count


def _flow_run_dir_preview(
    *,
    workspace: Path,
    top: Optional[str],
    run_top: Optional[str],
    run_id: Optional[str],
) -> Optional[Path]:
    effective_run_top = run_top or top
    if not effective_run_top or not run_id:
        return None
    return workspace / "runs" / effective_run_top / run_id


_CONSOLE = Console(stderr=True)


def _shell_quote_arg(value: object) -> str:
    text = str(value)
    if not text:
        return '""'
    if any(ch.isspace() for ch in text) or any(ch in text for ch in ['"', "'", "(", ")", "[", "]", "{", "}", "&", ";"]):
        escaped = text.replace("\\", "\\\\").replace('"', '\\\"')
        return f'"{escaped}"'
    return text


def _append_preview_opt(parts: list[str], flag: str, value: Optional[object]) -> None:
    if value is None:
        return
    parts.extend([flag, _shell_quote_arg(value)])


def _append_preview_flag(parts: list[str], flag: str, enabled: bool) -> None:
    if enabled:
        parts.append(flag)

def _build_make_cmd_preview(
    *,
    target: str,
    make_vars: dict[str, str],
    passthrough: list[str],
    workspace: Path,
) -> str:
    parts = ["flexsoc", "make", target]

    top = make_vars.get("TOP")
    run_top = make_vars.get("RUN_TOP")
    run_id = make_vars.get("RUN_ID")

    _append_preview_opt(parts, "--top", top)
    _append_preview_opt(parts, "--run-top", run_top)
    _append_preview_opt(parts, "--run-id", run_id)
    _append_preview_opt(parts, "--workspace", workspace)

    overwrite = make_vars.get("OVERWRITE")
    if overwrite in {"--force", "-f", "1"}:
        _append_preview_flag(parts, "--overwrite", True)

    if passthrough:
        parts.extend(_shell_quote_arg(x) for x in passthrough)

    return " ".join(parts)


def _print_runs_ls(*, workspace: Path) -> None:
    runs_root = workspace / "runs"

    _CONSOLE.print("")
    _CONSOLE.print(
        Panel(
            Text(str(runs_root), style="bold cyan"),
            title="Workspace runs",
            border_style="bright_blue",
        )
    )

    if not runs_root.exists():
        _CONSOLE.print(
            Panel(
                Text("(no runs directory)", style="yellow"),
                border_style="yellow",
            )
        )
        _CONSOLE.print("")
        return

    rows: list[dict[str, str]] = []

    for run_top_dir in sorted(p for p in runs_root.iterdir() if p.is_dir()):
        for run_id_dir in sorted(p for p in run_top_dir.iterdir() if p.is_dir()):
            run_yaml = run_id_dir / "run.yaml"
            if not run_yaml.exists():
                continue

            summary = _read_run_yaml_summary(run_yaml)
            rows.append(
                {
                    "run_top": summary.get("run_top", "") or run_top_dir.name,
                    "run_id": summary.get("run_id", "") or run_id_dir.name,
                    "top": summary.get("top", ""),
                    "ips": str(_count_loaded_ips_from_run_yaml(run_yaml)),
                    "last_action": summary.get("last_action", ""),
                    "updated_at_utc": summary.get("updated_at_utc", ""),
                }
            )

    if not rows:
        _CONSOLE.print(
            Panel(
                Text("(no runs found)", style="yellow"),
                border_style="yellow",
            )
        )
        _CONSOLE.print("")
        return

    table = Table(
        title="Registered runs",
        title_style="bold magenta",
        header_style="bold yellow",
        show_header=True,
    )
    table.add_column("RUN_TOP", style="bold green")
    table.add_column("RUN_ID", style="cyan")
    table.add_column("TOP", style="white")
    table.add_column("IPS", style="bold blue", justify="right")
    table.add_column("LAST_ACTION", style="green")
    table.add_column("UPDATED_AT_UTC", style="white")

    for row in rows:
        table.add_row(
            row["run_top"],
            row["run_id"],
            row["top"],
            row["ips"],
            row["last_action"],
            row["updated_at_utc"],
        )

    _CONSOLE.print(table)
    _CONSOLE.print("")


def _print_run_show(
    *,
    run_dir: Path,
    history_limit: int,
) -> None:
    run_yaml = run_dir / "run.yaml"

    if not run_yaml.exists():
        raise typer.BadParameter(f"run manifest not found: {run_yaml}")

    _CONSOLE.print("")
    _CONSOLE.print(
        Panel(
            Text(str(run_dir), style="bold cyan"),
            title="Run directory",
            border_style="bright_blue",
        )
    )

    _CONSOLE.print(
        Panel(
            run_yaml.read_text(encoding="utf-8").rstrip(),
            title="run.yaml",
            border_style="green",
        )
    )

    entries = read_run_history(run_dir, limit=history_limit)

    table = Table(
        title=f"Recent history ({len(entries)})",
        title_style="bold magenta",
        header_style="bold yellow",
        show_header=True,
    )
    table.add_column("#", style="bold cyan", no_wrap=True)
    table.add_column("Timestamp", style="white", no_wrap=True)
    table.add_column("Action", style="bold green")
    table.add_column("Top", style="cyan")
    table.add_column("Loaded IPs", style="white")

    if not entries:
        table.add_row("-", "-", "(no history entries)", "-", "-")
    else:
        for idx, entry in enumerate(entries, start=1):
            ts = str(entry.get("timestamp_utc", ""))
            act = str(entry.get("action", ""))
            top = "" if entry.get("top") is None else str(entry.get("top", ""))
            loaded = entry.get("loaded_ips", [])
            loaded_text = ", ".join(str(x) for x in loaded) if loaded else "-"
            table.add_row(str(idx), ts, act, top, loaded_text)

    _CONSOLE.print(table)
    _CONSOLE.print("")


def action(action_id: str) -> None:
    _setup_logging()
    reg = _registry()
    actions_map = reg.get("actions") or {}
    meta = actions_map.get(action_id)

    if meta is None:
        raise typer.BadParameter(f"unknown action: {action_id}")

    description = str(meta.get("description", ""))

    command_value = meta.get("command")
    if isinstance(command_value, list):
        command = " ".join(str(x) for x in command_value)
    elif command_value is None:
        command = None
    else:
        command = str(command_value)

    params = meta.get("params") or {}
    required_params = [
        str(name)
        for name, spec in params.items()
        if isinstance(spec, dict) and spec.get("required")
    ]

    notes: list[str] = []

    if meta.get("requires_top"):
        notes.append("Requires --top.")
    if meta.get("requires_run_id"):
        notes.append("Requires --run-id.")
    if meta.get("produces_outroot"):
        notes.append("Produces or updates workspace run artifacts.")

    postprocess = meta.get("postprocess")
    if postprocess:
        notes.append(f"Postprocess: {postprocess}")

    print_action_detail(
        name=action_id,
        description=description,
        command=command,
        required_params=required_params or None,
        notes=notes or None,
    )


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

    with running_status(label=f"exec {plan.action}"):
        res = execute_action(
            action=plan.action,
            params=plan.params,
            workspace=ws,
            run_id=run_id,
        )

    print_runner_summary(
        label=f"exec {plan.action}",
        exit_code=res.exit_code,
        runner_dir=res.runner_run_dir,
        flow_dir=res.flow_run_dir,
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
    workspace, top, run_top, run_id = resolve_context(
        workspace=workspace,
        top=top,
        run_top=run_top,
        run_id=run_id,
    )
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

    with running_status(label=f"run {action_id}"):
        res = execute_action(
            action=action_id,
            params=params,
            workspace=ws,
            run_id=run_id,
        )

    print_runner_summary(
        label=f"run {action_id}",
        exit_code=res.exit_code,
        runner_dir=res.runner_run_dir,
        flow_dir=res.flow_run_dir,
        command=cmd_preview,
    )
    raise typer.Exit(res.exit_code)


def _make_list_targets(flow_dir: Path) -> list[str]:
    """Best-effort user-facing target discovery via `make -qp`."""
    p = subprocess.run(
        ["make", "-C", str(flow_dir), "-qp"],
        capture_output=True,
        text=True,
        check=False,
    )

    raw_targets: set[str] = set()

    for raw_line in p.stdout.splitlines():
        line = raw_line.rstrip()

        if not line:
            continue
        if line.startswith("#"):
            continue
        if line.startswith("."):
            continue
        if line.startswith("	"):
            continue
        if line.startswith(" "):
            continue
        if ":" not in line:
            continue

        name = line.split(":", 1)[0].strip()

        if not name:
            continue
        if name == "Makefile":
            continue
        if "%" in name:
            continue
        if "/" in name:
            continue
        if "$" in name:
            continue
        if "=" in name:
            continue
        if " " in name:
            continue
        if '"' in name or "'" in name:
            continue
        if name.startswith("@"):
            continue
        if name.startswith("("):
            continue

        raw_targets.add(name)

    blacklist = {
        "SUFFIXES",
        "MAKEFILE_LIST",
        "MAKEFLAGS",
        "MAKELEVEL",
        "MAKE_COMMAND",
        "MAKE_VERSION",
        "CURDIR",
        "SHELL",
        "PATH",
        "PWD",
        "HOME",
        "USER",
        "LOGNAME",
        "PYTHONPATH",
        "DISPLAY",
        "TERM",
        "OVERWRITE",
        "REPO_ROOT",
        "FLOW_DIR",
        "FLOWMK_DIR",
        "Q",
        "RED",
        "GREEN",
        "BLUE",
        "YELLOW",
        "ORANGE",
        "RESET",
        "DEVLIST",
        "SOC_CFG_MK",
        "FSMGEN_DIR",
        "THIS_MK_DIR",
        "OR_WORKDIR",
        "OR_LOGDIR",
        "OR_CFG_MK",
        "OR_MAKEFILE",
        "OR_INC_DIRS",
        "_require_var",
    }

    targets = []
    for t in raw_targets:
        if t in blacklist:
            continue
        if t.isupper():
            continue
        targets.append(t)

    preferred_order = [
        "help",
        "ip_start",
        "reg",
        "doc",
        "rtl_stub",
        "setup_tb",
        "sim",
        "view",
        "syn",
        "sdf",
        "sta",
        "power",
        "pnr",
        "ip_save",
        "ip_load",
        "soc_start",
        "xbar",
        "soc",
        "setup_soc_tb",
        "setup_cocotb",
        "cocotb",
        "clean",
    ]

    preferred_rank = {name: i for i, name in enumerate(preferred_order)}

    targets = sorted(
        set(targets),
        key=lambda t: (preferred_rank.get(t, 9999), t),
    )
    return targets


def _complete_make_targets(ctx: typer.Context, param: typer.CallbackParam, incomplete: str):
    try:
        targets = _make_list_targets(_flow_dir())
    except Exception:
        targets = []

    out = []
    for t in targets:
        if not incomplete or t.startswith(incomplete):
            out.append(CompletionItem(t))
    return out


@app.command("make", context_settings={"allow_extra_args": True, "ignore_unknown_options": True})
def make_cmd(
    ctx: typer.Context,
    targets: list[str] = typer.Argument(None, shell_complete=_complete_make_targets),
    list_targets: bool = typer.Option(False, "--list"),
    workspace: Optional[Path] = typer.Option(None, "--workspace", "--ws"),
    top: Optional[str] = typer.Option(None, "--top"),
    run_top: Optional[str] = typer.Option(None, "--run-top"),
    run_id: Optional[str] = typer.Option(None, "--run-id"),
    reg_itf: Optional[str] = typer.Option(None, "--reg-itf"),
    load_as: Optional[str] = typer.Option(None, "--load-as", help="Rename destination folder when loading an IP into a run"),
    overwrite: bool = typer.Option(False, "--overwrite"),
    force: bool = typer.Option(False, "--force", help="Alias for --overwrite"),
) -> None:
    _setup_logging()
    workspace, top, run_top, run_id = resolve_context(
        workspace=workspace,
        top=top,
        run_top=run_top,
        run_id=run_id,
    )
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
    if load_as is not None:
        common_vars["LOAD_AS"] = load_as

    # Extra args after `--` may contain:
    # - additional positional make targets
    # - KEY=VALUE make var overrides
    # - raw passthrough flags
    extra_args = list(ctx.args)
    final_targets, override_vars, passthrough = _split_make_targets_and_passthrough(targets, extra_args)

    if not final_targets:
        discovered = _make_list_targets(flow_make_dir) or ["help"]

        typer.echo("")
        typer.echo("Available make targets:")
        for i, name in enumerate(discovered, start=1):
            typer.echo(f"  {i:>2}. {name}")
        typer.echo("")

        choice = typer.prompt("Select target number (empty to quit)", default="", show_default=False).strip()
        if not choice:
            raise typer.Exit(0)

        if not choice.isdigit():
            raise typer.BadParameter("Please enter a numeric target selection")

        idx = int(choice)
        if idx < 1 or idx > len(discovered):
            raise typer.BadParameter("Target selection out of range")

        final_targets = [discovered[idx - 1]]

    # Backward compatibility rule:
    # raw KEY=VALUE overrides passed after `--` win over typed flags.
    make_vars = {**common_vars, **override_vars}

    for target in final_targets:
        action_exec_id = f"make_{target}"

        cmd = ["make", "-C", str(flow_make_dir), target]
        cmd.extend([f"{k}={v}" for k, v in make_vars.items()])
        cmd.extend(passthrough)

        flow_run_dir_preview = _flow_run_dir_preview(
            workspace=ws,
            top=make_vars.get("TOP"),
            run_top=make_vars.get("RUN_TOP"),
            run_id=make_vars.get("RUN_ID"),
        )

        cmd_preview = " ".join(cmd)
        params = {
            "target": target,
            "targets": final_targets,
            "make_vars": make_vars,
            "passthrough": passthrough,
        }
        run_ref = resolve_run_ref(
            workspace=ws,
            top=make_vars.get("TOP"),
            run_top=make_vars.get("RUN_TOP"),
            run_id=make_vars.get("RUN_ID"),
        )

        with running_status(label=f"make {target}"):
            orchestrated = run_orchestrated(
                InvocationSpec(
                    action_id=action_exec_id,
                    summary_label=f"make {target}",
                    cmd=cmd,
                    params=params,
                    workspace_dir=ws,
                    cwd=repo_root,
                    env=None,
                    run_ref=run_ref,
                    manifest_action=f"make:{target}",
                    manifest_top=(make_vars.get("TOP") or make_vars.get("RUN_TOP")),
                    manifest_run_id=make_vars.get("RUN_ID"),
                )
            )

        print_runner_summary(
            label=f"make {target}",
            exit_code=orchestrated.backend.exit_code,
            runner_dir=orchestrated.backend.run_dir,
            flow_dir=orchestrated.flow_run_dir or flow_run_dir_preview,
            command=cmd_preview,
        )

        if orchestrated.backend.exit_code != 0:
            raise typer.Exit(orchestrated.backend.exit_code)

    raise typer.Exit(0)


@app.command("use")
def use_cmd(
    workspace: Optional[Path] = typer.Option(None, "--workspace", "--ws"),
    top: Optional[str] = typer.Option(None, "--top"),
    run_top: Optional[str] = typer.Option(None, "--run-top"),
    run_id: Optional[str] = typer.Option(None, "--run-id"),
) -> None:
    _setup_logging()
    ws, top_eff, run_top_eff, run_id_eff = resolve_context(
        workspace=workspace,
        top=top,
        run_top=run_top,
        run_id=run_id,
    )
    if ws is None:
        ws = default_workspace().resolve()
    if run_top_eff is None and top_eff is not None:
        run_top_eff = top_eff

    data = save_context(
        workspace=ws,
        top=top_eff,
        run_top=run_top_eff,
        run_id=run_id_eff,
    )

    table = Table(show_header=True, header_style="bold cyan")
    table.add_column("Field")
    table.add_column("Value")
    table.add_row("workspace", str(data.get("workspace", "")))
    table.add_row("top", str(data.get("top", "")))
    table.add_row("run_top", str(data.get("run_top", "")))
    table.add_row("run_id", str(data.get("run_id", "")))

    _CONSOLE.print(Panel(table, title="Current flexsoc context", border_style="blue"))


@app.command("current")
def current_cmd() -> None:
    _setup_logging()
    data = load_context()

    table = Table(show_header=True, header_style="bold cyan")
    table.add_column("Field")
    table.add_column("Value")
    table.add_row("workspace", str(data.get("workspace", "")))
    table.add_row("top", str(data.get("top", "")))
    table.add_row("run_top", str(data.get("run_top", "")))
    table.add_row("run_id", str(data.get("run_id", "")))

    _CONSOLE.print(Panel(table, title="Current flexsoc context", border_style="blue"))


@app.command("clear-current")
def clear_current_cmd() -> None:
    _setup_logging()
    clear_context()
    _CONSOLE.print(Panel("Context cleared.", title="Current flexsoc context", border_style="blue"))

if __name__ == "__main__":
    if _early_shortcuts():
        raise SystemExit(0)
    app()
