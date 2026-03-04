from __future__ import annotations

import json
import logging
import os
import re
import subprocess
import sys
from pathlib import Path
from typing import Any, Dict, List, Optional

import typer
import yaml
from rich.columns import Columns
from rich.console import Console
from rich.markdown import Markdown
from rich.panel import Panel
from rich.table import Table
from rich.text import Text

from .clean import clean_all, clean_pycache, clean_run, clean_workspace
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
from .runner import MakeBackend

log = logging.getLogger(__name__)

# Root app: show hub if user runs `flexsoc` with no args
app = typer.Typer(add_completion=False, invoke_without_command=True)
help_app = typer.Typer(add_completion=False)
app.add_typer(help_app, name="help")

guide_app = typer.Typer(add_completion=False)
app.add_typer(guide_app, name="guide")

# stdout console: for normal UI that tests expect on stdout
_OUT = Console()
# stderr console: for post-run summary and any non-structured UI noise
_UI = Console(stderr=True)


# ----------------------------
# Logging / registry helpers
# ----------------------------

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


def _load_registry_local() -> Dict[str, Any]:
    reg_path = Path(__file__).with_name("registry.yaml")
    data = yaml.safe_load(reg_path.read_text(encoding="utf-8"))
    if not isinstance(data, dict) or "actions" not in data:
        raise typer.BadParameter("Invalid registry.yaml: missing 'actions'")
    return data


def _actions_from_registry(reg: Dict[str, Any]) -> Dict[str, Any]:
    actions = reg.get("actions", {})
    return actions if isinstance(actions, dict) else {}


# ----------------------------
# Summary (stderr-only)
# ----------------------------

def _read_runner_manifest(run_dir: Path) -> dict:
    p = run_dir / "manifest.json"
    try:
        return json.loads(p.read_text(encoding="utf-8"))
    except Exception:
        return {}


def _maybe_flow_dir(*, workspace: Path, top: Optional[str], run_id: Optional[str]) -> Optional[Path]:
    if not top or not run_id:
        return None
    return workspace / "runs" / top / run_id


def _fmt_duration(dur: object) -> Optional[str]:
    if not isinstance(dur, (int, float)):
        return None
    # Keep it minimal and stable
    if dur < 10:
        return f"{dur:.1f}s"
    return f"{dur:.0f}s"


def _print_run_summary(
    *,
    label: str,
    exit_code: int,
    runner_dir: Path,
    flow_dir: Optional[Path] = None,
) -> None:
    m = _read_runner_manifest(runner_dir)
    dur = _fmt_duration(m.get("duration_s"))
    profiling = m.get("profiling", {}).get("enabled", False)

    ok = (exit_code == 0)
    badge = "✅" if ok else "❌"
    style = "green" if ok else "red"

    head = Text()
    head.append(f"{badge} ", style=style)
    head.append(label, style="bold")
    head.append(f"  ({exit_code})", style="dim")
    if isinstance(dur, str):
        head.append(f" · {dur}", style="dim")
    if profiling:
        head.append(" · prof", style="dim")

    body = Text()
    body.append("\n")
    body.append("Runner dir: ", style="bold")
    body.append(str(runner_dir))
    body.append("\n")
    if flow_dir is not None:
        body.append("Flow dir:   ", style="bold")
        body.append(str(flow_dir))
        body.append("\n")
    body.append("Logs:       ", style="bold")
    body.append("stdout.log, stderr.log")
    body.append("\n")
    body.append("Manifest:   ", style="bold")
    body.append("manifest.json")
    body.append("\n")

    if not ok:
        body.append("\n")
        body.append("Debug:\n", style="bold")
        body.append(f"  cat {runner_dir}/stdout.log\n")
        body.append(f"  cat {runner_dir}/stderr.log\n")

    _UI.print(Panel(body, title=head, border_style=style))


# ----------------------------
# UI helpers (stdout)
# ----------------------------

def _guide_path() -> Path:
    return Path(__file__).resolve().parents[2] / "docs" / "guide.md"


def _read_guide() -> str:
    p = _guide_path()
    if not p.exists():
        raise typer.BadParameter(f"Missing guide file: {p}")
    return p.read_text(encoding="utf-8")


def _extract_guide_section(md_text: str, section: str | None) -> str:
    if section is None:
        return md_text

    marker = f"## GUIDE: {section.upper()}"
    parts = md_text.split(marker)
    if len(parts) < 2:
        raise typer.BadParameter(f"Guide section '{section}' not found")

    tail = parts[1]
    next_marker = "\n## GUIDE:"
    if next_marker in tail:
        tail = tail.split(next_marker)[0]
    return f"## GUIDE: {section.upper()}\n" + tail.strip()


def _render_hub() -> None:
    title = Text("flexsoc", style="bold")
    subtitle = Text("Hardware IP flow runner (workspace-based) ✨", style="dim")

    quick = Text()
    quick.append("\n")
    quick.append("Quick actions\n", style="bold")
    quick.append("  flexsoc run ip_start --top my_ip --run-id dev1 --overwrite\n")
    quick.append("  flexsoc actions\n")
    quick.append("  flexsoc help topics\n")

    nav = Text()
    nav.append("\n")
    nav.append("Navigation shortcuts\n", style="bold")
    nav.append("  flexsoc h | ?         hub\n")
    nav.append("  flexsoc q             quickstart\n")
    nav.append("  flexsoc t             tutorial\n")
    nav.append("  flexsoc a             actions list\n")
    nav.append("  flexsoc ip            IP flow guide\n")
    nav.append("  flexsoc make --list   make targets\n")

    tips = Text()
    tips.append("\n")
    tips.append("Diagnostics\n", style="bold")
    tips.append("  Debug logs:     FLEXSOC_LOG_LEVEL=DEBUG flexsoc ...\n")
    tips.append("  Profiling:      FLEXSOC_PROFILE=1 flexsoc ...\n")
    tips.append("  Soft cache:     FLEXSOC_CACHE=1 flexsoc ...\n")

    panels = [
        Panel(quick, title="🚀 Quick actions", border_style="cyan"),
        Panel(nav, title="🧭 Navigation", border_style="green"),
        Panel(tips, title="🛠️ Tips", border_style="magenta"),
    ]

    _OUT.print(title)
    _OUT.print(subtitle)
    _OUT.print()
    _OUT.print(Columns(panels))


def _render_topics() -> None:
    title = Text("Help", style="bold")
    subtitle = Text("Topics and entry points 🧭", style="dim")

    body = Text()
    body.append("\n")
    body.append("Topics\n", style="bold")
    body.append("  hub            flexsoc h | flexsoc ?\n")
    body.append("  quickstart     flexsoc q\n")
    body.append("  tutorial       flexsoc t\n")
    body.append("  ip             flexsoc ip\n")
    body.append("  actions        flexsoc a | flexsoc actions\n")
    body.append("  action detail  flexsoc action <name>  |  flexsoc help action <name>\n")
    body.append("  make targets   flexsoc make --list\n")
    body.append("\n")
    body.append("Tip\n", style="bold")
    body.append("  Start with: flexsoc q\n")

    _OUT.print(title)
    _OUT.print(subtitle)
    _OUT.print()
    _OUT.print(Columns([Panel(body, title="📚 Help topics", border_style="blue")]))


def _render_quickstart() -> None:
    title = Text("Quickstart", style="bold")
    subtitle = Text("To faster see the features of the framework ✨", style="dim")

    body = Text()
    body.append("\n")
    body.append("1) Bootstrap IP template + smoke flow:\n", style="bold")
    body.append("   flexsoc run ip_start --top my_ip --run-id dev1 --overwrite\n")
    body.append("\n")
    body.append("2) Run any Makefile target (escape hatch):\n", style="bold")
    body.append("   flexsoc make view --top my_ip --run-id dev1\n")
    body.append("\n")
    body.append("3) Where outputs go:\n", style="bold")
    body.append("   - Flow artifacts: workspace/runs/<top>/<run_id>/...\n")
    body.append("   - Runner logs:    workspace/runs/<timestamp>_<action>/stdout.log\n")

    _OUT.print(title)
    _OUT.print(subtitle)
    _OUT.print()
    _OUT.print(Columns([Panel(body, title="🚀 Quick actions", border_style="cyan")]))


def _render_tutorial() -> None:
    title = Text("Tutorial", style="bold")
    subtitle = Text("A guided path through the main flow stages 📘", style="dim")

    body = Text()
    body.append("\n")
    body.append("Suggested path:\n", style="bold")
    body.append("  A) flexsoc doctor\n")
    body.append("  B) flexsoc make full_tutorial --top test --run-id dev1\n")
    body.append("  C) flexsoc make ip_tutorial   --top pwm_ramp --run-id dev1\n")
    body.append("  D) flexsoc make ip_tutorial   --top spi_host --run-id dev1\n")
    body.append("  E) flexsoc make fsm_tutorial  --top fsm_example --run-id dev1 \n")

    _OUT.print(title)
    _OUT.print(subtitle)
    _OUT.print()
    _OUT.print(Columns([Panel(body, title="📘 Tutorial steps", border_style="green")]))


def _render_ip_guide() -> None:
    title = Text("IP flow guide", style="bold")
    subtitle = Text("How to run the IP workflow end-to-end 🧱", style="dim")

    body = Text()
    body.append("\n")
    body.append("Bootstrap:\n", style="bold")
    body.append("  flexsoc run ip_start --top <ip_name> --run-id <id> --reg-itf tlul\n")
    body.append("\n")
    body.append("Then (any Makefile target):\n", style="bold")
    body.append("  flexsoc make sim   --top <ip_name> --run-id <id>\n")
    body.append("  flexsoc make syn   --top <ip_name> --run-id <id>\n")
    body.append("  flexsoc make sta   --top <ip_name> --run-id <id>\n")
    body.append("  flexsoc make power --top <ip_name> --run-id <id>\n")
    body.append("  flexsoc make sdf   --top <ip_name> --run-id <id>\n")
    body.append("\n")
    body.append("Paths:\n", style="bold")
    body.append("  Flow artifacts: workspace/runs/<top>/<run_id>/...\n")
    body.append("  Runner logs:    workspace/runs/<timestamp>_<action>/stdout.log\n")

    _OUT.print(title)
    _OUT.print(subtitle)
    _OUT.print()
    _OUT.print(Columns([Panel(body, title="🧱 IP workflow", border_style="yellow")]))


def _render_actions_list() -> None:
    title = Text("Actions", style="bold")
    subtitle = Text("Discover available registry actions 🧭", style="dim")

    reg = _load_registry_local()
    actions = _actions_from_registry(reg)

    tbl = Table(show_lines=False)
    tbl.add_column("Action", style="bold")
    tbl.add_column("Description")
    tbl.add_column("Run")
    preferred = [
        # Authoring / generation steps
        "hjson",
        "reg",
        "doc",
        "rtl_stub",
        "setup_tb",
        # Bootstrap (composed flow)
        "ip_start",
        # Build / signoff pipeline
        "lint",
        "sim",
        "synth",
        "sta",
        "power",
        "pnr",
        "pnr_gui",
        # SW / integration
        "driver",
        # FuseSoC + bundle workflow
        "fsoc_init",
        # Save and load
        "ip_save",
        "ip_load",
    ]

    ordered: List[str] = []
    seen = set()

    for n in preferred:
        if n in actions and n not in seen:
            ordered.append(n)
            seen.add(n)

    # Anything else goes after, stable alphabetical
    for n in sorted(actions.keys()):
        if n not in seen:
            ordered.append(n)

    for name in ordered:

        entry = actions.get(name, {}) or {}
        desc = str(entry.get("description", "")).strip()
        tbl.add_row(name, desc, f"flexsoc run {name}")

    hint = Text()
    hint.append("\n")
    hint.append("Tip\n", style="bold")
    hint.append("  flexsoc action <name>          for details\n")
    hint.append("  flexsoc help action <name>     same, under help namespace\n")

    _OUT.print(title)
    _OUT.print(subtitle)
    _OUT.print()
    _OUT.print(Columns([
        Panel(tbl, title="📦 Registry actions", border_style="green"),
        Panel(hint, title="💡 Next", border_style="cyan"),
    ]))


def _render_action_detail(name: str) -> None:
    title = Text("Action detail", style="bold")
    subtitle = Text(f"Registry-driven action reference: {name} 🧩", style="dim")

    reg = _load_registry_local()
    actions = _actions_from_registry(reg)
    if name not in actions:
        raise typer.BadParameter(f"Unknown action '{name}'. Try: flexsoc actions")

    entry = actions[name] or {}
    desc = str(entry.get("description", "")).strip()
    cmd = entry.get("command", [])
    params = entry.get("params", {}) or {}

    info = Text()
    info.append("\n")
    info.append("Action\n", style="bold")
    info.append(f"  {name}\n")
    info.append("Description\n", style="bold")
    info.append(f"  {desc or '-'}\n")
    info.append("Command\n", style="bold")
    info.append(f"  {' '.join(str(x) for x in cmd) if isinstance(cmd, list) else str(cmd)}\n")

    meta_keys = ["requires_top", "requires_run_id", "produces_outroot", "postprocess"]
    meta = Text()
    meta.append("\n")
    found = False
    for k in meta_keys:
        if k in entry:
            meta.append(f"{k}: ", style="bold")
            meta.append(f"{entry.get(k)}\n")
            found = True
    if not found:
        meta.append("(no explicit metadata)\n", style="dim")

    pt = Table(show_lines=False)
    pt.add_column("Param", style="bold")
    pt.add_column("Type")
    pt.add_column("Required")

    for pn in sorted(params.keys()):
        spec = params.get(pn, {}) or {}
        pt.add_row(pn, str(spec.get("type", "string")), "yes" if bool(spec.get("required", False)) else "no")

    ex = Text()
    ex.append("\n")
    ex.append("Examples\n", style="bold")
    ex.append(f"  flexsoc run {name}")
    if "top" in params:
        ex.append(" --top my_ip")
    if "reg_itf" in params:
        ex.append(" --reg-itf tlul")
    if "overwrite" in params:
        ex.append(" --overwrite --force")
    ex.append("\n")
    ex.append("  flexsoc make ")
    ex.append(f"{name}", style="bold")
    if "top" in params:
        ex.append(" --top my_ip")
    ex.append(" -- --jobs 8\n")

    _OUT.print(title)
    _OUT.print(subtitle)
    _OUT.print()
    _OUT.print(Columns([
        Panel(info, title="🧾 Action info", border_style="cyan"),
        Panel(meta, title="🧩 Metadata", border_style="magenta"),
        Panel(pt, title="🔧 Parameters", border_style="green"),
        Panel(ex, title="✅ Usage", border_style="yellow"),
    ]))


# ----------------------------
# Make target listing (best effort)
# ----------------------------

def _make_list_targets(flow_dir: Path) -> List[str]:
    p = subprocess.run(["make", "-C", str(flow_dir), "-qp"], capture_output=True, text=True)
    if p.returncode != 0:
        p2 = subprocess.run(["make", "-C", str(flow_dir), "help"], capture_output=True, text=True)
        out = p2.stdout if p2.returncode == 0 else (p.stdout + "\n" + p.stderr)
        return sorted(set(re.findall(r"^[a-zA-Z0-9_.-]+(?=:)", out, flags=re.MULTILINE)))

    out = p.stdout
    targets: set[str] = set()
    for line in out.splitlines():
        if not line or line.startswith("#") or line.startswith("\t") or line.startswith(" "):
            continue
        if ":" not in line:
            continue
        head = line.split(":", 1)[0].strip()
        if not head:
            continue
        if head.startswith("."):
            continue
        if "%" in head or "=" in head:
            continue
        if head in ("Makefile",):
            continue
        targets.add(head)
    return sorted(targets)


# ----------------------------
# Root callback + short aliases
# ----------------------------

@app.callback()
def _root(ctx: typer.Context) -> None:
    _setup_logging()
    if ctx.invoked_subcommand is None:
        _render_hub()


@app.command("h")
@app.command("?")
def hub_cmd() -> None:
    _setup_logging()
    _render_hub()


@app.command("q")
def quickstart_cmd() -> None:
    _setup_logging()
    _render_quickstart()


@app.command("t")
@app.command("tut")
def tutorial_cmd() -> None:
    _setup_logging()
    _render_tutorial()


@app.command("ip")
def ip_guide_cmd() -> None:
    _setup_logging()
    _render_ip_guide()


@app.command("a")
@app.command("actions")
def actions_cmd() -> None:
    _setup_logging()
    _render_actions_list()


@app.command("action")
def action_cmd(name: str = typer.Argument(..., help="Action id from registry")) -> None:
    _setup_logging()
    _render_action_detail(name)


# ----------------------------
# help sub-app (topics + action)
# ----------------------------

@help_app.callback(invoke_without_command=True)
def help_root(ctx: typer.Context) -> None:
    _setup_logging()
    if ctx.invoked_subcommand is None:
        _render_hub()


@help_app.command("topics")
def help_topics_cmd() -> None:
    _setup_logging()
    _render_topics()


@help_app.command("action")
def help_action_cmd(name: str = typer.Argument(..., help="Action id from registry")) -> None:
    _setup_logging()
    _render_action_detail(name)


# ----------------------------
# guide sub-app
# ----------------------------

@guide_app.callback(invoke_without_command=True)
def guide_root(ctx: typer.Context) -> None:
    _setup_logging()
    if ctx.invoked_subcommand is None:
        md = _read_guide()
        _OUT.print(Text("flexsoc Guides", style="bold"))
        _OUT.print(Text("Integrated structured documentation 📚", style="dim"))
        _OUT.print()
        _OUT.print(Panel(Markdown(md), border_style="blue"))


@guide_app.command()
def show(
    section: str = typer.Argument(None, help="Guide section (ip, soc, flow_ip, glossary)"),
    plain: bool = typer.Option(False, "--plain"),
) -> None:
    _setup_logging()
    md = _read_guide()
    content = _extract_guide_section(md, section)

    if plain:
        sys.stdout.write(content + "\n")
        return

    _OUT.print(Text("flexsoc Guide", style="bold"))
    _OUT.print(Text(f"Section: {section or 'full'}", style="dim"))
    _OUT.print()
    _OUT.print(Panel(Markdown(content), border_style="blue"))


# ----------------------------
# Core commands (existing)
# ----------------------------

@app.command()
def doctor() -> None:
    _setup_logging()
    rc = run_doctor()
    raise SystemExit(rc)


@app.command()
def run(
    action: str = typer.Argument(..., help="Action id (from registry)"),
    design: Optional[str] = typer.Option(None, help="Design name"),
    top: Optional[str] = typer.Option(None, help="Top module"),
    corner: Optional[str] = typer.Option(None, help="Corner (e.g. min/max)"),
    seed: Optional[int] = typer.Option(None, help="Simulation seed"),
    reg_itf: Optional[str] = typer.Option(None, help="Register interface (e.g. tlul)"),
    overwrite: bool = typer.Option(False, "--overwrite", help="Overwrite existing outputs"),
    force: bool = typer.Option(False, "--force", help="Alias for --overwrite (deprecated)"),
    workspace: Optional[Path] = typer.Option(None, "--workspace", "--ws", help="Workspace directory"),
    run_id: Optional[str] = typer.Option(None, help="Run identifier"),
) -> None:
    _setup_logging()
    overwrite = bool(overwrite or force)
    params: Dict[str, Any] = {}
    if design is not None:
        params["design"] = design
    if top is not None:
        params["top"] = top
    if corner is not None:
        params["corner"] = corner
    if reg_itf is not None:
        params["reg_itf"] = reg_itf
    if overwrite:
        params["force"] = 1
    if seed is not None:
        params["seed"] = seed

    ws = (workspace or default_workspace())
    log.debug("CLI run: action=%s workspace=%s run_id=%s params=%s", action, ws, run_id, params)

    # Modern progress hint (stderr-only)
    run_msg = f"Running action: {action}"
    if top and run_id:
        run_msg += f"  (top={top}, run_id={run_id})"
    with _UI.status(run_msg, spinner="dots"):
        res = execute_action(
        action=action,
        params=params,
        workspace=ws,
        run_id=run_id,
        )

    flow_dir = res.flow_run_dir or _maybe_flow_dir(workspace=ws, top=top, run_id=run_id)
    _print_run_summary(
        label=f"run {action}",
        exit_code=res.exit_code,
        runner_dir=res.runner_run_dir,
        flow_dir=flow_dir,
    )
    raise typer.Exit(code=res.exit_code)


@app.command("dump-registry")
def dump_registry() -> None:
    _setup_logging()
    reg = _load_registry_local()
    sys.stdout.write(json.dumps(reg, indent=2))
    sys.stdout.write("\n")


@app.command("clean-run")
def clean_run_cmd(
    top: str = typer.Option(..., help="Top name"),
    run_id: str = typer.Option(..., help="Run id"),
    workspace: Optional[Path] = typer.Option(None, "--workspace", "--ws", help="Workspace directory"),
) -> None:
    _setup_logging()
    ws = (workspace or default_workspace())
    clean_run(ws, top, run_id)



@app.command("clean")
def clean_pycache_cmd(
    repo_root: Optional[Path] = typer.Option(None, help="Repo root (default: auto-detected)"),
) -> None:
    """
    Remove Python caches (__pycache__, *.pyc) recursively.
    """
    _setup_logging()
    removed = clean_pycache(repo_root)
    _OUT.print(f"Removed {removed} cache entries")


@app.command("clean-all")
def clean_all_cmd(
    workspace: Optional[Path] = typer.Option(None, "--workspace", "--ws", help="Workspace directory (default: from config)"),
) -> None:
    """
    Delete the entire workspace directory (hard reset).
    """
    _setup_logging()
    ws = (workspace or default_workspace())
    clean_all(ws)
    _OUT.print(f"Deleted workspace: {ws}")

@app.command("clean-workspace")
def clean_workspace_cmd(
    workspace: Optional[Path] = typer.Option(None, "--workspace", "--ws", help="Workspace directory"),
) -> None:
    _setup_logging()
    ws = (workspace or default_workspace())
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
    _OUT.print(f"Plan written: {out}")


@app.command("exec")
def exec_cmd(
    plan_path: Path = typer.Argument(..., help="Path to plan JSON"),
    workspace: Optional[Path] = typer.Option(None, "--workspace", "--ws", help="Workspace directory"),
    run_id: Optional[str] = typer.Option(None, help="Run identifier"),
    overwrite: bool = typer.Option(False, "--overwrite", help="Overwrite existing outputs"),
    reg_itf: Optional[str] = typer.Option(None, help="Register interface (e.g. tlul)"),
    top: Optional[str] = typer.Option(None, help="Top name (if plan doesn't contain it)"),
) -> None:
    _setup_logging()
    overwrite = bool(overwrite or force)
    registry = load_registry(Path(__file__).parent / "registry.yaml")
    plan = read_plan_json(plan_path)

    params = dict(plan.params)
    if top is not None:
        params["top"] = top
    if reg_itf is not None:
        params["reg_itf"] = reg_itf
    if overwrite:
        params["force"] = 1

    validate_plan(Plan(action=plan.action, params=params), registry)

    cmd = ["flexsoc", "run", plan.action]
    if "top" in params:
        cmd += ["--top", str(params["top"])]
    if "reg_itf" in params:
        cmd += ["--reg-itf", str(params["reg_itf"])]
    if params.get("force"):
        cmd += ["--overwrite"]

    if workspace is not None:
        cmd += ["--workspace", str(workspace)]
    if run_id is not None:
        cmd += ["--run-id", str(run_id)]

    try:
        p = subprocess.run(cmd, text=True)
    except FileNotFoundError:
        cmd2 = [sys.executable, "-m", "flexsoc.cli", "run", plan.action]
        if "top" in params:
            cmd2 += ["--top", str(params["top"])]
        if "reg_itf" in params:
            cmd2 += ["--reg-itf", str(params["reg_itf"])]
        if "overwrite" in params:
            cmd2 += ["--overwrite", str(params["overwrite"])]
        if workspace is not None:
            cmd2 += ["--workspace", str(workspace)]
        if run_id is not None:
            cmd2 += ["--run-id", str(run_id)]
        p = subprocess.run(cmd2, text=True)

    raise typer.Exit(code=p.returncode)


@app.command(
    "make",
    context_settings={"allow_extra_args": True, "ignore_unknown_options": True},
)
def make_cmd(
    ctx: typer.Context,
    target: Optional[str] = typer.Argument(None, help="Make target to run inside flow/"),
    list_targets: bool = typer.Option(False, "--list", help="List available Make targets in flow/ (best effort)"),
    verbose: bool = typer.Option(False, "--verbose", "-v", help="Pass VERBOSE=1 V=1 to make"),
    workspace: Optional[Path] = typer.Option(None, "--ws", "--workspace", help="Workspace directory"),
    top: Optional[str] = typer.Option(None, help="Top module"),
    run_id: Optional[str] = typer.Option(None, help="Run identifier"),
    design: Optional[str] = typer.Option(None, help="Design name"),
    corner: Optional[str] = typer.Option(None, help="Corner (e.g. min/max)"),
    seed: Optional[int] = typer.Option(None, help="Simulation seed"),
    reg_itf: Optional[str] = typer.Option(None, help="Register interface (e.g. tlul)"),
    overwrite: bool = typer.Option(False, "--overwrite", help="Overwrite existing outputs (sets FORCE=1)"),
    force: bool = typer.Option(False, "--force", help="Alias for --overwrite (deprecated)"),
) -> None:
    """
    Escape hatch: run ANY Makefile target from flow/ with workspace-based variables and runner logging.

    Examples:
      flexsoc make --list
      flexsoc make sim --top my_ip --run-id dev1 -- --jobs 8
      flexsoc make syn --top my_ip --run-id dev1 -- VERBOSE=1
    """
    _setup_logging()
    overwrite = bool(overwrite or force)

    # --list mode (UI)
    if list_targets:
        title = Text("Make targets", style="bold")
        subtitle = Text("Discover available Makefile targets under flow/ 🧰", style="dim")

        flow_dir = Path("flow").resolve()
        targets = _make_list_targets(flow_dir)

        if not targets:
            msg = Text()
            msg.append("\n")
            msg.append("No targets discovered.\n", style="bold")
            msg.append("\n")
            msg.append("Try:\n", style="bold")
            msg.append("  make -C flow help\n")
            msg.append("  make -C flow -qp | head\n")
            msg.append("\n")
            msg.append("Or run a known target:\n", style="bold")
            msg.append("  flexsoc make help\n")
            _OUT.print(title)
            _OUT.print(subtitle)
            _OUT.print()
            _OUT.print(Columns([Panel(msg, title="⚠️ Target discovery", border_style="red")]))
            return

        tbl = Table(show_lines=False)
        tbl.add_column("Target", style="bold")
        for t in targets:
            tbl.add_row(t)

        hint = Text()
        hint.append("\n")
        hint.append("Usage\n", style="bold")
        hint.append("  flexsoc make <target> [-- <extra make args>]\n")
        hint.append("Examples\n", style="bold")
        hint.append("  flexsoc make help\n")
        hint.append("  flexsoc make sim --top my_ip --run-id dev1 -- --jobs 8\n")

        panels = [
            Panel(tbl, title="🧰 Targets (flow/)", border_style="green"),
            Panel(hint, title="💡 Next", border_style="cyan"),
        ]

        _OUT.print(title)
        _OUT.print(subtitle)
        _OUT.print()
        _OUT.print(Columns(panels))
        return

    if not target:
        raise typer.BadParameter("Missing target. Use: flexsoc make --list OR flexsoc make <target> [-- ...]")

    # Compute workspace for make:
    # - flexsoc UX can show relative "workspace"
    # - but make is invoked with -C flow, so WORKSPACE must be relative to flow/ (or absolute)
    repo_root = Path(__file__).resolve().parents[2]
    flow_dir = (repo_root / "flow").resolve()

    ws_abs = Path(workspace or default_workspace()).expanduser().resolve()
    ws_for_make = os.path.relpath(ws_abs, flow_dir)

    extra_make_args = list(ctx.args)

    cmd = ["make", "-C", "flow", target]
    cmd.append(f"WORKSPACE={ws_for_make}")

    if top is not None:
        cmd.append(f"TOP={top}")
    if run_id is not None:
        cmd.append(f"RUN_ID={run_id}")
    if design is not None:
        cmd.append(f"DESIGN={design}")
    if corner is not None:
        cmd.append(f"CORNER={corner}")
    if seed is not None:
        cmd.append(f"SEED={seed}")

    # Deterministic defaults / knobs
    if reg_itf is None:
        cmd.append("REG_ITF=tlul")
    else:
        cmd.append(f"REG_ITF={reg_itf}")

    cmd.append("FORCE=1" if overwrite else "FORCE=0")

    if verbose:
        cmd.append("VERBOSE=1")
        cmd.append("V=1")

    cmd.extend(extra_make_args)

    backend = MakeBackend()
    # Modern progress hint (stderr-only)
    make_msg = f"Running make target: {target}"
    if top and run_id:
        make_msg += f"  (top={top}, run_id={run_id})"
    with _UI.status(make_msg, spinner="dots"):
        br = backend.run(
        action_id=f"make_{target}",
        cmd=cmd,
        params={
            "target": target,
            "top": top,
            "run_id": run_id,
            "design": design,
            "corner": corner,
            "seed": seed,
            "reg_itf": reg_itf,
            "overwrite": overwrite,
            "make_args": extra_make_args,
        },
        workspace_dir=ws_abs,
        )

    # Print modern summary on stderr (keeps stdout clean)
    flow_run_dir = (Path(workspace or default_workspace()) / "runs" / top / run_id) if (top and run_id) else None
    _print_run_summary(
        label=f"make {target}",
        exit_code=br.exit_code,
        runner_dir=br.run_dir,
        flow_dir=flow_run_dir,
    )
    raise typer.Exit(code=br.exit_code)

if __name__ == "__main__":
    app()
