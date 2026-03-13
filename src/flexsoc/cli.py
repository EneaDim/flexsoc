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
from typing import Any, Optional

import typer
from click.shell_completion import CompletionItem
from rich.console import Console
from rich.panel import Panel
from rich.table import Table
from rich.text import Text
from typer.core import TyperGroup

from .clean import clean_all, clean_pycache, clean_run, clean_workspace
from .config import default_workspace
from .context import clear_context, load_context, resolve_context, save_context
from .doctor import run_doctor
from .executor import execute_action
from .helptext import (
    render_detailed_help,
    render_fsm_development_guide,
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
from .ui import (
    print_actions_table,
    print_help_topics,
    print_hub,
    print_make_targets,
    print_runner_summary,
    running_status,
)
from .workspace import resolve_run_ref

log = logging.getLogger(__name__)

HELP_COMMAND_ORDER = [
    "run",
    "make",
    "plan",
    "exec",
    "actions",
    "action",
    "help",
    "runs",
    "use",
    "current",
    "clear-current",
    "doctor",
    "clean-pycache",
    "clean-run",
    "clean-workspace",
    "clean-all",
    "dump-registry",
    "hd",
    "h",
    "q",
    "t",
    "ip",
    "a",
]

HELP_SUBCOMMAND_ORDER = [
    "overview",
    "topics",
    "action",
    "detailed",
    "commands",
]

RUNS_SUBCOMMAND_ORDER = [
    "ls",
    "show",
]


class FlexSocHelpGroup(TyperGroup):
    def list_commands(self, ctx):
        names = list(self.commands.keys())
        rank = {name: idx for idx, name in enumerate(HELP_COMMAND_ORDER)}
        return sorted(names, key=lambda name: (rank.get(name, 9999), name))


class FlexSocHelpTopicsGroup(TyperGroup):
    def list_commands(self, ctx):
        names = list(self.commands.keys())
        rank = {name: idx for idx, name in enumerate(HELP_SUBCOMMAND_ORDER)}
        return sorted(names, key=lambda name: (rank.get(name, 9999), name))


class FlexSocRunsGroup(TyperGroup):
    def list_commands(self, ctx):
        names = list(self.commands.keys())
        rank = {name: idx for idx, name in enumerate(RUNS_SUBCOMMAND_ORDER)}
        return sorted(names, key=lambda name: (rank.get(name, 9999), name))


app = typer.Typer(
    cls=FlexSocHelpGroup,
    add_completion=False,
    invoke_without_command=True,
    rich_markup_mode="rich",
    help="FlexSoC CLI for flow execution, registry actions, workspace management, and diagnostics.",
)
help_app = typer.Typer(
    cls=FlexSocHelpTopicsGroup,
    add_completion=False,
    rich_markup_mode="rich",
    help="Guides, topics, and action-specific help.",
)
runs_app = typer.Typer(
    cls=FlexSocRunsGroup,
    add_completion=False,
    help="Inspect workspace runs and history.",
    rich_markup_mode="rich",
)
app.add_typer(help_app, name="help", help="Browse guides, topics, and action help.", rich_help_panel="Discovery / introspection")
app.add_typer(runs_app, name="runs", help="Inspect workspace runs and history.", rich_help_panel="Discovery / introspection")

_CONSOLE = Console(stderr=True)


def _emit_json_stdout(payload: object) -> None:
    sys.stdout.write(json.dumps(payload, indent=2, sort_keys=True))
    sys.stdout.write("\n")


def _emit_text_stdout(text: str) -> None:
    sys.stdout.write(text)
    if not text.endswith("\n"):
        sys.stdout.write("\n")


def _emit_text_stderr(text: str) -> None:
    sys.stderr.write(text)
    if not text.endswith("\n"):
        sys.stderr.write("\n")


def _fail(message: str, exit_code: int = 2) -> None:
    _emit_text_stderr(f"ERROR: {message}")
    raise typer.Exit(exit_code)


def _safe_registry() -> dict[str, Any]:
    try:
        return _registry()
    except Exception as e:
        _fail(str(e))
        raise

def _setup_logging() -> None:
    """Always log to stderr so stdout remains clean for machine-readable outputs."""
    level_s = os.environ.get("FLEXSOC_LOG_LEVEL", "").strip().upper()
    level = getattr(logging, level_s, logging.INFO) if level_s else logging.INFO
    logging.basicConfig(level=level, format="%(levelname)s: %(message)s", stream=sys.stderr)


def _registry_path() -> Path:
    return Path(__file__).resolve().parent / "registry.yaml"


def _registry() -> dict[str, Any]:
    return load_registry(_registry_path())


def _repo_root() -> Path:
    # src/flexsoc/cli.py -> repo root = parents[2]
    return Path(__file__).resolve().parents[2]


def _flow_dir() -> Path:
    return (_repo_root() / "flow").resolve()


def _resolved_workspace(workspace: Optional[Path]) -> Path:
    ws = (workspace or default_workspace()).expanduser().resolve()
    if not str(ws).strip():
        _fail(f"Invalid workspace path: {ws}")
    return ws


def _validate_run_lookup_inputs(run_top: Optional[str], run_id: Optional[str]) -> None:
    if run_top is not None and not str(run_top).strip():
        _fail("run_top cannot be empty")
    if run_id is not None and not str(run_id).strip():
        _fail("run_id cannot be empty")


def _early_shortcuts() -> bool:
    """Handle ?,h,q,t,ip before Typer parsing (required because '?' breaks parsing)."""
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
    if argv == ["fsm"]:
        render_fsm_development_guide()
        return True
    return False


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
            value = value.replace('\\"', '"').replace("\\\\", "\\")

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


def _print_run_show(*, run_dir: Path, history_limit: int) -> None:
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


def _shell_quote_arg(value: object) -> str:
    text = str(value)
    if not text:
        return '""'
    special = ['"', "'", "(", ")", "[", "]", "{", "}", "&", ";"]
    if any(ch.isspace() for ch in text) or any(ch in text for ch in special):
        escaped = text.replace("\\", "\\\\").replace('"', '\\"')
        return f'"{escaped}"'
    return text


def _append_preview_opt(parts: list[str], flag: str, value: Optional[object]) -> None:
    if value is not None:
        parts.extend([flag, _shell_quote_arg(value)])


def _append_preview_flag(parts: list[str], flag: str, enabled: bool) -> None:
    if enabled:
        parts.append(flag)


def _common_make_vars(
    *,
    workspace: Path,
    top: Optional[str],
    run_top: Optional[str],
    run_id: Optional[str],
    reg_itf: Optional[str],
    overwrite: bool,
    force: bool,
) -> dict[str, str]:
    """Build canonical Make variables shared by `run` and `make`."""
    make_vars: dict[str, str] = {
        "WORKSPACE": str(workspace.resolve()),
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
) -> tuple[list[str], dict[str, str], list[str]]:
    """
    Split user input for `flexsoc make` into:
    - ordered make targets
    - KEY=VALUE make variable overrides
    - passthrough option-like args

    KEY=VALUE tokens must never become targets.
    """
    targets: list[str] = []
    override_vars: dict[str, str] = {}
    passthrough: list[str] = []

    def consume(arg: str) -> None:
        if "=" in arg and not arg.startswith("-"):
            key, value = arg.split("=", 1)
            key = key.strip()
            if key:
                override_vars[key] = value
                return

        if not arg.startswith("-"):
            targets.append(arg)
            return

        passthrough.append(arg)

    for arg in list(initial_targets or []):
        consume(arg)

    for arg in list(extra_args or []):
        consume(arg)

    return targets, override_vars, passthrough

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


def _build_make_cmd_preview(
    *,
    target: str,
    make_vars: dict[str, str],
    passthrough: list[str],
    workspace: Path,
) -> str:
    parts = ["flexsoc", "make", target]

    _append_preview_opt(parts, "--top", make_vars.get("TOP"))
    _append_preview_opt(parts, "--run-top", make_vars.get("RUN_TOP"))
    _append_preview_opt(parts, "--run-id", make_vars.get("RUN_ID"))
    _append_preview_opt(parts, "--workspace", workspace)

    overwrite = make_vars.get("OVERWRITE")
    _append_preview_flag(parts, "--overwrite", overwrite in {"--force", "-f", "1"})

    if "REG_ITF" in make_vars:
        _append_preview_opt(parts, "--reg-itf", make_vars["REG_ITF"])
    if "LOAD_AS" in make_vars:
        _append_preview_opt(parts, "--load-as", make_vars["LOAD_AS"])

    if passthrough:
        parts.extend(_shell_quote_arg(x) for x in passthrough)

    return " ".join(parts)


def _make_list_targets(flow_dir: Path) -> list[str]:
    """Best-effort user-facing target discovery via `make -qp`."""
    proc = subprocess.run(
        ["make", "-C", str(flow_dir), "-qp"],
        capture_output=True,
        text=True,
        check=False,
    )

    raw_targets: set[str] = set()
    for raw_line in proc.stdout.splitlines():
        line = raw_line.rstrip()
        if not line or line.startswith(("#", ".", "\t", " ")):
            continue
        if ":" not in line:
            continue

        name = line.split(":", 1)[0].strip()
        if (
            not name
            or name == "Makefile"
            or "%" in name
            or "/" in name
            or "$" in name
            or "=" in name
            or " " in name
            or '"' in name
            or "'" in name
            or name.startswith("@")
            or name.startswith("(")
        ):
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

    targets = [
        t
        for t in raw_targets
        if t not in blacklist and not t.isupper()
    ]
    return sorted(set(targets), key=lambda t: (preferred_rank.get(t, 9999), t))


def _complete_make_targets(
    ctx: typer.Context,
    param: typer.CallbackParam,
    incomplete: str,
) -> list[CompletionItem]:
    del ctx, param
    try:
        targets = _make_list_targets(_flow_dir())
    except Exception:
        targets = []

    return [CompletionItem(t) for t in targets if not incomplete or t.startswith(incomplete)]


def _action_rows() -> list[tuple[str, str]]:
    reg = _safe_registry()
    actions_map = reg.get("actions") or {}
    rows: list[tuple[str, str]] = []

    for name, meta in actions_map.items():
        if not isinstance(meta, dict):
            continue
        rows.append((str(name), str(meta.get("description", ""))))

    rows.sort(key=lambda row: row[0])
    return rows


def _action_meta(action_id: str) -> tuple[dict[str, Any] | None, list[str]]:
    reg = _safe_registry()
    actions_map = reg.get("actions") or {}
    names = sorted(str(k) for k in actions_map.keys())
    meta = actions_map.get(action_id)
    if not isinstance(meta, dict):
        return None, names
    return meta, names


def _render_action_detail(action_id: str) -> None:
    _setup_logging()
    meta, available = _action_meta(action_id)

    if meta is None:
        _emit_text_stderr(f"Unknown action: {action_id}")
        _emit_text_stderr(
            f"Available actions: {', '.join(available) if available else '(none)'}"
        )
        return

    description_text = str(meta.get("description", "")).strip()

    command_value = meta.get("command")
    if isinstance(command_value, list):
        command = " ".join(str(x) for x in command_value)
    elif command_value is None:
        command = "(none)"
    else:
        command = str(command_value)

    params = meta.get("params") or {}
    required_params = [
        str(name)
        for name, spec in params.items()
        if isinstance(spec, dict) and spec.get("required")
    ]

    lines = [
        f"Action: {action_id}",
        f"Description: {description_text or '(none)'}",
        f"Command: {command}",
        f"Requires top: {bool(meta.get('requires_top', False))}",
        f"Requires run_id: {bool(meta.get('requires_run_id', False))}",
        f"Produces outroot: {bool(meta.get('produces_outroot', False))}",
    ]

    if required_params:
        lines.append(f"Required params: {', '.join(required_params)}")

    if meta.get("postprocess"):
        lines.append(f"Postprocess: {meta['postprocess']}")

    _emit_text_stdout("\n".join(lines))


@app.callback(invoke_without_command=True)
def main_callback(ctx: typer.Context) -> None:
    try:
        if ctx.invoked_subcommand is None:
            _setup_logging()
            render_home_help()
            raise typer.Exit(0)
    except typer.Exit:
        raise
    except Exception as e:
        _fail(str(e))
        _setup_logging()
        render_home_help()
        raise typer.Exit(0)


@runs_app.command("ls", help="List available runs in the workspace.", rich_help_panel="Workspace inspection")
def runs_ls(
    workspace: Path = typer.Option(Path("workspace"), "--workspace", "--ws", help="Workspace directory"),
) -> None:
    _setup_logging()
    _print_runs_ls(workspace=_resolved_workspace(workspace))


@runs_app.command("show", help="Show one run manifest and recent history.", rich_help_panel="Workspace inspection")
def runs_show(
    run_top: str = typer.Option(..., "--run-top", help="Run-top name"),
    run_id: str = typer.Option(..., "--run-id", help="Run identifier"),
    workspace: Path = typer.Option(Path("workspace"), "--workspace", help="Workspace directory"),
    history_limit: int = typer.Option(10, "--history-limit", min=1, help="Number of history entries to show"),
) -> None:
    _setup_logging()
    _validate_run_lookup_inputs(run_top, run_id)
    ws = _resolved_workspace(workspace)
    _print_run_show(run_dir=ws / "runs" / run_top / run_id, history_limit=history_limit)


@app.command("fsm", help="Show FSM development guide.", rich_help_panel="Advanced / docs")
def help_fs_guide_alias() -> None:
    _setup_logging()
    render_fsm_development_guide()

@app.command("hd", help="Show the detailed help page.", rich_help_panel="Advanced / docs")
def help_detailed_alias() -> None:
    _setup_logging()
    render_detailed_help()


@help_app.command("detailed", help="Show detailed command documentation.", rich_help_panel="Reference")
def help_detailed_cmd() -> None:
    _setup_logging()
    render_detailed_help()


@help_app.command("commands", help="Show command reference.", rich_help_panel="Reference")
def help_commands_cmd() -> None:
    _setup_logging()
    render_detailed_help()


@help_app.command("overview", help="Show a high-level overview of FlexSoC.", rich_help_panel="Start here")
def help_overview_cmd() -> None:
    _setup_logging()
    render_help_overview()


@help_app.command("topics", help="List available help topics.", rich_help_panel="Start here")
def help_topics_cmd() -> None:
    _setup_logging()
    print_help_topics()


@help_app.command("action", help="Show detailed help for one action.", rich_help_panel="Action help")
def help_action_cmd(action_id: str) -> None:
    _render_action_detail(action_id)


@app.command("doctor", help="Check Python deps and external tool availability.", rich_help_panel="Diagnostics / maintenance")
def doctor_cmd(
    json_output: bool = typer.Option(False, "--json", help="Emit structured JSON output."),
) -> None:
    _setup_logging()
    raise typer.Exit(run_doctor(json_mode=json_output))


@app.command("clean-pycache", help="Remove Python cache files.", rich_help_panel="Diagnostics / maintenance")
def clean_pycache_cmd(
    root: Path = typer.Option(Path("."), "--root", help="Root directory to clean"),
) -> None:
    _setup_logging()
    removed = clean_pycache(root.expanduser().resolve())
    typer.echo(f"Removed {removed} Python cache entries")


@app.command("clean-run", help="Remove one run directory.", rich_help_panel="Diagnostics / maintenance")
def clean_run_cmd(
    run_top: str = typer.Option(..., "--run-top", help="Run-top name"),
    run_id: str = typer.Option(..., "--run-id", help="Run identifier"),
    workspace: Path = typer.Option(Path("workspace"), "--workspace", "--ws", help="Workspace directory"),
) -> None:
    _setup_logging()
    _validate_run_lookup_inputs(run_top, run_id)
    ws = _resolved_workspace(workspace)
    clean_run(ws, run_top, run_id)
    typer.echo(f"Removed run: {ws / 'runs' / run_top / run_id}")


@app.command("clean-workspace", help="Clean workspace run artifacts.", rich_help_panel="Diagnostics / maintenance")
def clean_workspace_cmd(
    workspace: Path = typer.Option(Path("workspace"), "--workspace", "--ws", help="Workspace directory"),
) -> None:
    _setup_logging()
    ws = _resolved_workspace(workspace)
    clean_workspace(ws)
    typer.echo(f"Cleaned workspace runs under: {ws}")


@app.command("clean-all", help="Remove the entire workspace directory.", rich_help_panel="Diagnostics / maintenance")
def clean_all_cmd(
    workspace: Path = typer.Option(Path("workspace"), "--workspace", "--ws", help="Workspace directory"),
) -> None:
    _setup_logging()
    ws = _resolved_workspace(workspace)
    clean_all(ws)
    typer.echo(f"Removed workspace: {ws}")


@app.command("dump-registry", help="Emit the action registry as JSON.", rich_help_panel="Advanced / machine-readable")
def dump_registry_cmd() -> None:
    """Pure JSON to stdout, no UI."""
    _setup_logging()
    try:
        _emit_json_stdout(_safe_registry())
    except typer.Exit:
        raise
    except Exception as e:
        _fail(str(e))

@app.command("actions", help="List available registry actions.", rich_help_panel="Discovery / introspection")
def actions_cmd() -> None:
    _setup_logging()
    try:
        print_actions_table(_action_rows())
    except typer.Exit:
        raise
    except Exception as e:
        _fail(str(e))


@app.command("action", help="Show details for one registry action.", rich_help_panel="Discovery / introspection")
def action_cmd(action_id: str) -> None:
    try:
        _render_action_detail(action_id)
    except typer.Exit:
        raise
    except Exception as e:
        _fail(str(e))


@app.command("h", hidden=True)
def help_hub_cmd() -> None:
    _setup_logging()
    render_home_help()


@app.command("q", hidden=True)
def quickstart_alias() -> None:
    render_quickstart()


@app.command("t", hidden=True)
def tutorial_alias() -> None:
    render_tutorials()


@app.command("ip", hidden=True)
def ip_alias() -> None:
    render_ip_guide()


@app.command("a", hidden=True)
def actions_alias() -> None:
    actions_cmd()


@app.command("plan", help="Generate a plan JSON from a natural-language intent.", rich_help_panel="Core workflow")
def plan_cmd(
    text: str = typer.Argument(..., help="Natural-language intent, e.g. 'create ip'"),
    out: Path = typer.Option(Path("plan.json"), "--out"),
) -> None:
    _setup_logging()
    try:
        plan = naive_intent_to_plan(text)
        validate_plan(plan, _safe_registry(), allow_missing_required=True)
        write_plan_json(plan, out)
    except typer.Exit:
        raise
    except Exception as e:
        _fail(str(e))


@app.command("exec", help="Execute a previously generated plan.", rich_help_panel="Core workflow")
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
    try:
        ws = _resolved_workspace(workspace)
        plan = read_plan_json(plan_path)

        if top is not None:
            plan.params["top"] = top
        if run_top is not None:
            plan.params["run_top"] = run_top
        if reg_itf is not None:
            plan.params["reg_itf"] = reg_itf
        if overwrite or force:
            plan.params["overwrite"] = "1"

        plan.params.pop("force", None)
        plan.params.pop("run_id", None)

        validate_plan(plan, _safe_registry(), allow_missing_required=False)

        if profile:
            os.environ["FLEXSOC_PROFILE"] = "1"

        cmd_preview_parts = ["flexsoc", "exec", str(plan_path)]
        _append_preview_opt(cmd_preview_parts, "--top", top)
        _append_preview_opt(cmd_preview_parts, "--run-top", run_top)
        _append_preview_opt(cmd_preview_parts, "--run-id", run_id)
        _append_preview_opt(cmd_preview_parts, "--reg-itf", reg_itf)
        _append_preview_opt(cmd_preview_parts, "--workspace", ws)
        _append_preview_flag(cmd_preview_parts, "--overwrite", overwrite or force)

        with running_status(label=f"exec {plan.action}"):
            result = execute_action(
                action=plan.action,
                params=plan.params,
                workspace=ws,
                run_id=run_id,
            )

        print_runner_summary(
            label=f"exec {plan.action}",
            exit_code=result.exit_code,
            runner_dir=result.runner_run_dir,
            flow_dir=result.flow_run_dir,
            command=" ".join(cmd_preview_parts),
        )
        raise typer.Exit(result.exit_code)
    except typer.Exit:
        raise
    except Exception as e:
        _fail(str(e))


@app.command("run", help="Execute one registry action.", rich_help_panel="Core workflow")
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
    try:
        workspace, top, run_top, run_id = resolve_context(
            workspace=workspace,
            top=top,
            run_top=run_top,
            run_id=run_id,
        )
        ws = _resolved_workspace(workspace)

        params: dict[str, Any] = {}
        if top is not None:
            params["top"] = top
        if run_top is not None:
            params["run_top"] = run_top
        if reg_itf is not None:
            params["reg_itf"] = reg_itf
        if overwrite or force:
            params["overwrite"] = "1"

        cmd_preview_parts = ["flexsoc", "run", action_id]
        _append_preview_opt(cmd_preview_parts, "--top", top)
        _append_preview_opt(cmd_preview_parts, "--run-top", run_top)
        _append_preview_opt(cmd_preview_parts, "--run-id", run_id)
        _append_preview_opt(cmd_preview_parts, "--reg-itf", reg_itf)
        _append_preview_opt(cmd_preview_parts, "--workspace", ws)
        _append_preview_flag(cmd_preview_parts, "--overwrite", overwrite or force)

        with running_status(label=f"run {action_id}"):
            result = execute_action(
                action=action_id,
                params=params,
                workspace=ws,
                run_id=run_id,
            )

        print_runner_summary(
            label=f"run {action_id}",
            exit_code=result.exit_code,
            runner_dir=result.runner_run_dir,
            flow_dir=result.flow_run_dir,
            command=" ".join(cmd_preview_parts),
        )
        raise typer.Exit(result.exit_code)
    except typer.Exit:
        raise
    except Exception as e:
        _fail(str(e))


@app.command("make", help="Run one or more raw flow Make targets.", rich_help_panel="Core workflow", context_settings={"allow_extra_args": True, "ignore_unknown_options": True})
def make_cmd(
    ctx: typer.Context,
    targets: list[str] = typer.Argument(None, shell_complete=_complete_make_targets),
    list_targets: bool = typer.Option(False, "--list"),
    workspace: Optional[Path] = typer.Option(None, "--workspace", "--ws"),
    top: Optional[str] = typer.Option(None, "--top"),
    run_top: Optional[str] = typer.Option(None, "--run-top"),
    run_id: Optional[str] = typer.Option(None, "--run-id"),
    reg_itf: Optional[str] = typer.Option(None, "--reg-itf"),
    load_as: Optional[str] = typer.Option(
        None,
        "--load-as",
        help="Rename destination folder when loading an IP into a run",
    ),
    overwrite: bool = typer.Option(False, "--overwrite"),
    force: bool = typer.Option(False, "--force", help="Alias for --overwrite"),
) -> None:
    _setup_logging()
    try:
        workspace, top, run_top, run_id = resolve_context(
            workspace=workspace,
            top=top,
            run_top=run_top,
            run_id=run_id,
        )
        ws = _resolved_workspace(workspace)
        repo_root = _repo_root()
        flow_make_dir = _flow_dir()

        if list_targets:
            targets_to_show = _make_list_targets(flow_make_dir) or ["help"]
            print_make_targets(targets_to_show)
            raise typer.Exit(0)

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

        final_targets, override_vars, passthrough = _split_make_targets_and_passthrough(
            list(targets or []),
            list(ctx.args),
        )

        if not final_targets:
            discovered = _make_list_targets(flow_make_dir) or ["help"]
            typer.echo("")
            typer.echo("Available make targets:")
            for idx, name in enumerate(discovered, start=1):
                typer.echo(f"  {idx:>2}. {name}")
            typer.echo("")

            choice = typer.prompt(
                "Select target number (empty to quit)",
                default="",
                show_default=False,
            ).strip()
            if not choice:
                raise typer.Exit(0)
            if not choice.isdigit():
                raise typer.BadParameter("Please enter a numeric target selection")

            selected = int(choice)
            if selected < 1 or selected > len(discovered):
                raise typer.BadParameter("Target selection out of range")

            final_targets = [discovered[selected - 1]]

        make_vars = {**common_vars, **override_vars}

        for target in final_targets:
            cmd = ["make", "-C", str(flow_make_dir), target]
            cmd.extend([f"{k}={v}" for k, v in make_vars.items()])
            cmd.extend(passthrough)

            run_ref = resolve_run_ref(
                workspace=ws,
                top=make_vars.get("TOP"),
                run_top=make_vars.get("RUN_TOP"),
                run_id=make_vars.get("RUN_ID"),
            )

            with running_status(label=f"make {target}"):
                orchestrated = run_orchestrated(
                    InvocationSpec(
                        action_id=f"make_{target}",
                        summary_label=f"make {target}",
                        cmd=cmd,
                        params={
                            "target": target,
                            "targets": final_targets,
                            "make_vars": make_vars,
                            "passthrough": passthrough,
                        },
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
                flow_dir=orchestrated.flow_run_dir
                or _flow_run_dir_preview(
                    workspace=ws,
                    top=make_vars.get("TOP"),
                    run_top=make_vars.get("RUN_TOP"),
                    run_id=make_vars.get("RUN_ID"),
                ),
                command=_build_make_cmd_preview(
                    target=target,
                    make_vars=make_vars,
                    passthrough=passthrough,
                    workspace=ws,
                ),
            )

            if orchestrated.backend.exit_code != 0:
                raise typer.Exit(orchestrated.backend.exit_code)

        raise typer.Exit(0)
    except typer.Exit:
        raise
    except Exception as e:
        _fail(str(e))


@app.command("use", help="Save the current workspace/top/run context.", rich_help_panel="Context / workspace")
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


@app.command("current", help="Show the saved context.", rich_help_panel="Context / workspace")
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


@app.command("clear-current", help="Clear the saved context.", rich_help_panel="Context / workspace")
def clear_current_cmd() -> None:
    _setup_logging()
    clear_context()
    _CONSOLE.print(Panel("Context cleared.", title="Current flexsoc context", border_style="blue"))


if __name__ == "__main__":
    if _early_shortcuts():
        raise SystemExit(0)
    app()
