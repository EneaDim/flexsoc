"""Minimal command line entrypoint for the FlexSoC API layer."""

from __future__ import annotations

from datetime import datetime
import json
import subprocess
from pathlib import Path
from typing import Iterable

import typer
from rich.console import Console
from rich.panel import Panel
from rich.table import Table

from .api import FlexSoC, FlowStep, FlowWorkflow

ACCENT = "orange3"
SECONDARY = "cyan"
SUCCESS = "green"
WARNING = "yellow"

SETTINGS_DIRNAME = ".flexsoc"
SETTINGS_FILENAME = "settings.json"
DEFAULT_SETTINGS = {"TOP": "test", "HOST": "uart", "FORCE": "0", "RUN_ID": "default"}

def _resolve_run_id(project_root: Path | None, values: dict[str, str]) -> dict[str, str]:
    """Keep RUN_ID static unless the user provided one explicitly."""

    resolved = dict(values)
    if not resolved.get("RUN_ID"):
        resolved["RUN_ID"] = DEFAULT_SETTINGS["RUN_ID"]
    return resolved
HELP_INTRO = """Thin command line interface over the public FlexSoC API layer.
Use workflows for normal development and steps for advanced flow control."""

HELP_SECTIONS = (
    (
        "0. Shell discovery",
        ACCENT,
        (
            ("fx --install-completion", "Enable shell completion, then restart the shell or source the profile."),
            ("fx <TAB>", "Discover top-level commands from your shell."),
            ("fx commands", "Render the command catalog with short descriptions."),
            ("fx help", "Open this chronological guide."),
        ),
    ),
    (
        "1. Project settings",
        SECONDARY,
        (
            ("fx settings", "Show defaults, saved settings, and the active workspace."),
            ("fx settings --set TOP=my_ip --set HOST=uart --set FORCE=1", "Save project defaults in .flexsoc/settings.json."),
            ("fx describe", "Show project root, workspace, and API client options."),
        ),
    ),
    (
        "2. Flow discovery",
        SUCCESS,
        (
            ("fx steps", "List all advanced backend steps."),
            ("fx steps --group ip", "List only IP-development steps."),
            ("fx step-info hjson_gen", "Inspect parameters and examples for one step."),
            ("fx workflows", "List high-level development flows."),
        ),
    ),
    (
        "3. Workspace setup",
        WARNING,
        (
            ("fx workflow workspace --dry-run --script --set TOP=demo", "Preview workspace/run-folder initialization."),
            ("fx workflow workspace --set TOP=demo --capture", "Create the workspace and run folders."),
            ("fx step setup --set TOP=demo --capture", "Run only the setup step."),
        ),
    ),
    (
        "4. IP development flow",
        "magenta",
        (
            (
                "fx workflow ip_development --dry-run --script --set TOP=my_ip",
                "Preview setup → hjson_gen → reg → doc → rtl_stub → setup_tb → sim → syn → sta → power → pnr → sim_syn → cocotb.",
            ),
            (
                "fx step setup hjson_gen reg doc rtl_stub setup_tb sim --set TOP=my_ip",
                "Run a selected IP sequence, sharing one RUN_ID across the call.",
            ),
            ("fx step-info syn", "Inspect synthesis-specific parameters before launching tool-dependent steps."),
        ),
    ),
    (
        "5. SoC development flow",
        "blue",
        (
            (
                "fx workflow soc_development --dry-run --script --set TOP=soc",
                "Preview setup → soc_start → soc_flow → soc_prepare → soc_build_sw → soc_sim → soc_run.",
            ),
            ("fx step-info soc", "Inspect SoC generation parameters."),
            ("fx step-info sw_soc", "Inspect software generation parameters."),
        ),
    ),
    (
        "6. Smoke and debug",
        "cyan",
        (
            ("fx smoke", "Run safe catalog and workflow preview checks."),
            ("fx smoke --run-workspace --top demo --run-id smoke", "Execute only the safe workspace path."),
            ("fx step reg doc --dry-run --script", "Debug a short ordered step sequence before execution."),
            ("--json", "Return structured output for tools and frontends."),
        ),
    ),
    (
        "Common options",
        "white",
        (
            ("--set KEY=VALUE", "Override one Make variable for one call. Repeat as needed."),
            ("--project-root PATH", "Execute from a repository root different from the current directory."),
            ("--dry-run / --script / --capture", "Inspect, preview, or capture execution."),
        ),
    ),
)

app = typer.Typer(
    context_settings={"help_option_names": ["-h", "--help"]},

    add_completion=True,
    help="Thin FlexSoC CLI over the public API layer. Use `fx help` for examples.",
)
console = Console()

_HELP_COMMAND_ROWS = [{'command': 'fx settings', 'purpose': 'Show or edit defaults such as TOP, HOST, RUN_ID, FORCE.'},
 {'command': 'fx steps', 'purpose': 'List backend steps that can be launched with fx step.'},
 {'command': 'fx step ...', 'purpose': 'Run one or more explicit backend steps in order.'},
 {'command': 'fx step-info NAME', 'purpose': 'Explain one step, its parameters, and examples.'},
 {'command': 'fx workflows',
  'purpose': 'Show practical tutorial recipes built from real step commands.'},
 {'command': 'fx smoke', 'purpose': 'Run safe package/backend smoke checks.'},
 {'command': 'fx help', 'purpose': 'Show this concise getting-started guide.'}]
_HELP_WORKFLOW_ROWS = [{'name': 'ip-from-scratch',
  'goal': 'Create a minimal IP from metadata, generate RTL/testbench, and run simulation.',
  'command': 'fx step hjson reg doc rtl_stub setup_tb sim --force'},
 {'name': 'existing-ip-testbench',
  'goal': 'Prepare an already-present IP/run and execute the generated testbench.',
  'command': 'fx step ip_load setup_tb sim'},
 {'name': 'cocotb-smoke',
  'goal': 'Generate the Cocotb scaffold from the RTL filelist and run the Cocotb test.',
  'command': 'fx step setup_cocotb cocotb --force'},
 {'name': 'edit-and-regress',
  'goal': 'After changing metadata or RTL, refresh generated collateral and rerun simulation.',
  'command': 'fx step reg doc rtl_stub setup_tb sim --force'},
 {'name': 'synthesis-smoke',
  'goal': 'Run the synthesis/timing/power path for the current IP run.',
  'command': 'fx step setup_syn syn sta power pnr'}]


def _commands_table() -> Table:
    """Render public CLI commands as a compact table."""
    table = Table(title="Commands", show_lines=False)
    table.add_column("Command", style="bold orange3", no_wrap=True)
    table.add_column("Purpose")
    for row in _HELP_COMMAND_ROWS:
        table.add_row(_row_command(row), _row_purpose(row))
    return table


def _workflow_table() -> Table:
    """Render practical workflow recipes as tutorials."""
    table = Table(title="Workflow tutorials", show_lines=True)
    table.add_column("Recipe", style="bold orange3", no_wrap=True)
    table.add_column("Goal")
    table.add_column("Command", style="cyan")
    for row in _HELP_WORKFLOW_ROWS:
        table.add_row(row["name"], row["goal"], _row_command(row))
    return table



def _step_error_hint(target: str, message: object = "") -> str:
    """Return a short recovery hint for common backend step failures."""

    text = str(message).lower()
    if "refusing to overwrite" in text or "use --force" in text:
        return (
            f"hint: {target} found an existing generated file. "
            "Re-run with --force or --overwrite, or choose another run with "
            "--set RUN_ID=<name>."
        )
    if target in {"hjson", "hjson_gen"}:
        return (
            "hint: hjson writes data/<TOP>.hjson. If that file already exists, "
            "use --force/--overwrite or change RUN_ID."
        )
    if target in {"reg", "doc", "rtl_stub"}:
        return (
            f"hint: {target} expects a generated HJSON file in the current run. "
            "Run hjson first, or check TOP/RUN_ID with fx settings."
        )
    if target in {"setup_tb", "setup_cocotb", "sim", "cocotb"}:
        return (
            f"hint: {target} depends on generated RTL and rtl/rtl_list.f. "
            "Run hjson reg doc rtl_stub setup_tb first, then retry with --capture."
        )
    if target in {"syn", "sta", "power", "pnr", "pnr_gui"}:
        return (
            f"hint: {target} expects synthesis inputs from the same RUN_ID. "
            "Check rtl/rtl_list.f, syn scripts, and rerun with --capture for logs."
        )
    return "hint: re-run with --capture and inspect the run directory under workspace/runs/<TOP>/<RUN_ID>."


@app.callback(invoke_without_command=True)
def main(ctx: typer.Context) -> None:
    """Show the concise CLI guide when fx has no subcommand."""

    if ctx.invoked_subcommand is None:
        help()

def _workflow_name_completion(incomplete: str):
    """Return workflow names matching the shell completion prefix."""

    return [name for name in FlexSoC().workflow_names() if name.startswith(incomplete)]


def _step_name_completion(incomplete: str):
    """Return step names matching the shell completion prefix."""

    return [name for name in FlexSoC().step_names() if name.startswith(incomplete)]



def _command_rows() -> list[dict[str, str]]:
    """Return the public command catalog shown by help and commands."""

    return [
        {"command": "fx setting", "purpose": "Show or edit TOP, HOST, RUN_ID, FORCE, and viewer defaults."},
        {"command": "fx commands", "purpose": "Show this concise command catalog."},
        {"command": "fx steps", "purpose": "List all backend steps available through fx step."},
        {"command": "fx step NAME...", "purpose": "Run one or more backend steps in order."},
        {"command": "fx <step>", "purpose": "Run a single step directly, for example fx hjson or fx setup_tb."},
        {"command": "fx <step> --info", "purpose": "Explain one step before launching it."},
        {"command": "fx view", "purpose": "Open the latest waveform using the configured viewer."},
        {"command": "fx help", "purpose": "Show the concise guide and practical tutorials."},
    ]


def _print_command_table() -> None:
    """Render the concise command catalog as a Rich table."""

    table = Table(title="Commands", show_lines=False)
    table.add_column("Command", style="bold orange3", no_wrap=True)
    table.add_column("Purpose")
    for row in _command_rows():
        table.add_row(_row_command(row), _row_purpose(row))
    console.print(table)

def _row_field(row, index: int, key: str) -> str:
    """Read one field from tuple-style or dict-style help rows."""
    if isinstance(row, dict):
        return str(row.get(key, ""))
    try:
        return str(row[index])
    except (IndexError, TypeError):
        return ""


def _row_command(row) -> str:
    """Return the command column from a help row."""
    return _row_field(row, 0, "command")


def _row_purpose(row) -> str:
    """Return the purpose column from a help row."""
    return _row_field(row, 1, "purpose")


def _recipe_name(row) -> str:
    """Return the tutorial recipe name from tuple or dict rows."""
    return _row_field(row, 0, "name")


def _recipe_title(row) -> str:
    """Return the tutorial recipe title from tuple or dict rows."""
    return _row_field(row, 1, "title")


def _recipe_command(row) -> str:
    """Return the tutorial command from tuple or dict rows."""
    return _row_field(row, 2, "command")


def _recipe_note(row) -> str:
    """Return the tutorial note from tuple or dict rows."""
    return _row_field(row, 3, "note")


@app.command()
def help() -> None:
    """Show a concise CLI guide with commands and practical IP recipes."""

    console.print(Panel(
        "A Python API and CLI facade over the backend hardware flow.\n"
        "Set project defaults once, then launch explicit backend steps.",
        title="FlexSoC CLI",
        border_style="orange3",
    ))
    console.print("[bold orange3]Quickstart[/bold orange3]")
    console.print("  fx setting")
    console.print("  fx setting --set TOP=test --set HOST=uart --set RUN_ID=default")
    console.print("  fx setup --dry-run --script")
    console.print("  fx hjson --force")
    console.print("  fx reg")
    console.print("  fx doc")
    console.print("  fx rtl_stub")
    console.print("  fx setup_tb")
    console.print("  fx sim")
    console.print("  python -m flexsoc help")

    _print_command_table()

    console.print("\n[bold orange3]Tutorials[/bold orange3]")
    console.print("  [bold]IP development[/bold]")
    console.print("    1. fx setting --set TOP=my_ip --set HOST=uart --set RUN_ID=default")
    console.print("    2. fx setup")
    console.print("    3. fx hjson --force")
    console.print("    4. fx reg && fx doc")
    console.print("    5. fx rtl_stub && fx setup_tb")
    console.print("    6. fx sim")
    console.print("  [bold]Existing IP[/bold]")
    console.print("    1. fx setting --set TOP=cordic --set HOST=uart --set RUN_ID=default")
    console.print("    2. fx ip_load --force")
    console.print("    3. fx setup_tb")
    console.print("    4. fx sim")
    console.print("  [bold]Waveform debug[/bold]")
    console.print("    1. fx sim")
    console.print("    2. fx view")

    console.print("\n[bold orange3]Useful options[/bold orange3]")
    console.print("  --set KEY=VALUE      Override one project setting for one command.")
    console.print("  --force/--overwrite  Refresh generated files when outputs already exist.")
    console.print("  --dry-run --script   Print backend Make commands without executing them.")
    console.print("  --capture            Capture backend output and show step hints on failure.")
    console.print("\nDesign rule: CLI commands call FlexSoC, never backend modules directly.")
@app.command()
def commands(json_output: bool = typer.Option(False, "--json", help="Print commands as JSON.")) -> None:
    """List the concise command surface."""

    rows = _command_rows()
    if json_output:
        typer.echo(json.dumps(rows, indent=2))
        return
    _print_command_table()
@app.command()
def describe() -> None:
    """Print the current FlexSoC API client description as JSON."""

    typer.echo(json.dumps(FlexSoC().describe(), indent=2))


@app.command("settings")
def settings(
    set_: list[str] = typer.Option(None, "--set", help="Persist one project setting as KEY=VALUE."),
    unset: list[str] = typer.Option(None, "--unset", help="Remove one persisted setting by name."),
    reset: bool = typer.Option(False, "--reset", help="Remove all persisted project settings."),
    project_root: Path | None = typer.Option(None, help="Repository root that owns the settings file."),
    json_: bool = typer.Option(False, "--json", help="Print a JSON payload for tools and frontends."),
) -> None:
    """Show, save, or reset project-level FlexSoC CLI settings."""

    root = _project_root(project_root)
    path = _settings_path(root)
    values = _read_settings(root)
    changed = False

    if reset:
        path.unlink(missing_ok=True)
        values = {}
        changed = True

    for key in unset or []:
        removed = values.pop(key.upper(), None)
        changed = changed or removed is not None

    if set_:
        values.update(_parse_overrides(set_))
        changed = True

    if changed:
        _write_settings(root, values)

    payload = _settings_payload(root)
    if json_:
        typer.echo(json.dumps(payload, indent=2))
        return
    _print_settings(payload)


@app.command("workflow")
def workflow(
    name: str = typer.Argument(..., help="Workflow name. Use TAB to discover available workflows.", autocompletion=_workflow_name_completion),
    set_: list[str] = typer.Option(None, "--set", help="Override a Make variable as KEY=VALUE."),
    project_root: Path | None = typer.Option(None, help="Repository root used as execution cwd."),
    dry_run: bool = typer.Option(False, help="Print commands without executing them."),
    capture: bool = typer.Option(False, help="Capture and print stdout after execution."),
    script: bool = typer.Option(False, "--script", help="Print a shell script preview during dry-runs."),
    json_: bool = typer.Option(False, "--json", help="Print a JSON payload for tools and frontends."),
) -> None:
    """Run, preview, or serialize one high-level workflow through FlexSoC."""

    client = FlexSoC(project_root=project_root)
    overrides = _merged_settings(project_root, set_ or [])
    if dry_run and (json_ or script):
        plan = client.inspect_workflow(name, **overrides)
        typer.echo(json.dumps(plan.to_dict(), indent=2) if json_ else plan.shell_script(), nl=not script)
        return
    results = client.run_workflow(name, dry_run=dry_run, capture=capture, **overrides)
    if json_:
        payload = [item.to_dict() for item in results]
        typer.echo(json.dumps(payload, indent=2))
        return
    for item in results:
        if dry_run:
            typer.echo(item.shell_line())
        elif capture and item.stdout:
            typer.echo(item.stdout, nl=False)


@app.command("steps")
def steps(
    group: str | None = typer.Option(None, help="Show only one step group."),
    json_: bool = typer.Option(False, "--json", help="Print JSON for tools and frontends."),
) -> None:
    """Render Make-backed workflow steps known by the API layer."""

    items = FlexSoC().list_steps(group)
    if json_:
        typer.echo(json.dumps([step.to_dict() for step in items], indent=2))
        return
    _print_steps(items, group)

@app.command("smoke")
def smoke(
    top: str = typer.Option("demo", help="Top name used for smoke previews."),
    run_id: str = typer.Option("smoke", help="Run identifier used for smoke previews."),
    project_root: Path | None = typer.Option(None, help="Repository root used as execution cwd."),
    json_: bool = typer.Option(False, "--json", help="Print a JSON payload for tools and frontends."),
    run_workspace: bool = typer.Option(False, "--run-workspace", help="Execute only the safe workspace workflow."),
) -> None:
    """Run safe API/CLI smoke checks without launching EDA tools by default."""

    client = FlexSoC(project_root=project_root)
    payload = _smoke_payload(client, top, run_id, run_workspace)
    if json_:
        typer.echo(json.dumps(payload, indent=2))
    else:
        _print_smoke(payload)
    if not payload["ok"]:
        raise typer.Exit(1)


@app.command("step-info")
def step_info(
    name: str = typer.Argument(..., help="Step name. Use TAB to discover available steps.", autocompletion=_step_name_completion),
    json_: bool = typer.Option(False, "--json", help="Print a JSON payload for tools and frontends."),
    examples: bool = typer.Option(False, "--examples", help="Print only copy-ready command examples."),
) -> None:
    """Show parameters, categories, and examples for one advanced flow step."""

    step = FlexSoC().step_info(name)
    json_enabled = json_ if isinstance(json_, bool) else False
    examples_enabled = examples if isinstance(examples, bool) else False
    if json_enabled:
        typer.echo(json.dumps(step.to_dict(), indent=2))
        return
    _print_step_examples(step) if examples_enabled else _print_step_info(step)


def _step_error_hint(step: str) -> str:
    """Return a concise human hint for common backend step failures."""

    hints = {
        "hjson": "The HJSON file already exists. Re-run with --force/--overwrite or choose another RUN_ID.",
        "reg": "Register generation needs data/<TOP>.hjson. Run hjson first, or re-run the flow with --force.",
        "doc": "Documentation generation needs data/<TOP>.hjson. Run hjson first.",
        "rtl_stub": "RTL stub generation needs data/<TOP>.hjson. Run hjson/reg first and keep the same RUN_ID.",
        "setup_tb": "Testbench setup needs generated RTL/filelist inputs. Run rtl_stub and flist first, or use the full IP flow.",
        "setup_cocotb": "Cocotb setup needs rtl/rtl_list.f. Run flist first, or use setup_cocotb after rtl_stub.",
        "sim": "Simulation failed during lint/compile/run. Re-run with --capture and inspect logs under workspace/runs/<TOP>/<RUN_ID>/sim.",
        "syn": "Synthesis needs rtl/rtl_list.f and valid vendor/IP include paths. Run rtl_stub/setup_syn first and inspect syn logs.",
        "sta": "STA depends on synthesis outputs. Run syn first and inspect workspace/runs/<TOP>/<RUN_ID>/syn.",
        "power": "Power analysis depends on synthesis/timing outputs. Run syn and sta first.",
        "pnr": "PnR depends on synthesis and floorplan inputs. Run syn/setup_pnr first and inspect pnr_openroad logs.",
        "pnr_gui": "PnR GUI depends on an existing PnR run. Run pnr first.",
    }
    return hints.get(step, "Re-run with --capture and inspect the generated workspace logs for this step.")

@app.command()
def step(
    targets: list[str] = typer.Argument(..., help="One or more backend steps to run in order. Use TAB to discover steps.", autocompletion=_step_name_completion),
    set_: list[str] = typer.Option(None, "--set", help="Override a Make variable as KEY=VALUE."),
    project_root: Path | None = typer.Option(None, help="Repository root used as execution cwd."),
    dry_run: bool = typer.Option(False, help="Print commands without executing them."),
    capture: bool = typer.Option(False, help="Capture and print stdout after execution."),
    script: bool = typer.Option(False, "--script", help="Print a shell script preview during dry-runs."),
    json_: bool = typer.Option(False, "--json", help="Print a JSON payload for tools and frontends."),
    force: bool = typer.Option(False, "--force", help="Overwrite generated files where supported."),
    overwrite: bool = typer.Option(False, "--overwrite", help="Alias for --force."),
) -> None:
    """Run, preview, or serialize one or more advanced backend flow steps."""

    client = FlexSoC(project_root=project_root)
    overrides = _merged_settings(None, set_ or [])
    # CLI aliases map to the backend FORCE override. Without these flags,
    # the backend receives FORCE=0 and reports overwrite conflicts itself.
    if force or overwrite:
        overrides = dict(overrides)
        overrides["FORCE"] = "1"
    sequence_overrides = _step_sequence_overrides(targets, overrides)
    if dry_run:
        payloads = [client.inspect_step(target, **sequence_overrides) for target in targets]
        if json_:
            payload: object = payloads[0] if len(payloads) == 1 else payloads
            typer.echo(json.dumps(payload, indent=2))
            return
        lines = [item["shell"] for item in payloads]
        typer.echo(_shell_script(lines) if script else "\n".join(lines), nl=not script)
        return

    results = []
    for target in targets:
        try:
            results.append(client.run_step(target, capture=capture, **sequence_overrides))
        except subprocess.CalledProcessError as exc:
            command = " ".join(str(part) for part in exc.cmd)
            typer.secho(f"step failed: {target}", fg=typer.colors.RED, err=True)
            typer.secho(f"command: {command}", err=True)
            raise typer.Exit(exc.returncode) from exc

    if json_:
        payload = results[0].to_dict() if len(results) == 1 else [item.to_dict() for item in results]
        typer.echo(json.dumps(payload, indent=2))
    elif capture:
        for result in results:
            if result.stdout:
                typer.echo(result.stdout, nl=False)


def _step_sequence_overrides(targets: list[str], overrides: dict[str, str]) -> dict[str, str]:
    """Return step overrides without creating timestamp run identifiers."""

    values = dict(overrides)
    if not values.get("RUN_ID"):
        values["RUN_ID"] = DEFAULT_SETTINGS["RUN_ID"]
    return values

def _shell_script(lines: list[str]) -> str:
    """Render dry-run shell lines as a small executable script preview."""

    return "#!/usr/bin/env bash\nset -euo pipefail\n" + "\n".join(lines)


def _smoke_payload(client: FlexSoC, top: str, run_id: str, run_workspace: bool) -> dict[str, object]:
    """Build a safe smoke payload using only public framework workflows."""

    workflows = {
        name: client.inspect_workflow(name, top=top, run_id=run_id).shell_lines()
        for name in ("workspace", "ip_development", "soc_development")
    }
    workspace_results = []
    if run_workspace:
        workspace_results = [item.to_dict() for item in client.run_workflow("workspace", capture=True, top=top, run_id=run_id)]
    workspace_ok = all(item.get("ok", False) for item in workspace_results) if workspace_results else True
    return {
        "ok": workspace_ok,
        "workflows": {name: list(lines) for name, lines in workflows.items()},
        "workspace_results": workspace_results,
    }


def _print_smoke(payload: dict[str, object], console: Console | None = None) -> None:
    """Render the safe smoke summary for humans."""

    console = console or Console()
    ok = bool(payload["ok"])
    style = SUCCESS if ok else WARNING
    workflows = payload["workflows"]
    table = Table(title="Smoke checks", border_style=style)
    table.add_column("Check", style=f"bold {ACCENT}")
    table.add_column("Result", style="white")
    for name, lines in workflows.items():
        table.add_row(name, f"{len(lines)} command(s) previewed")
    if payload["workspace_results"]:
        table.add_row("workspace execution", "ok" if all(item["ok"] for item in payload["workspace_results"]) else "failed")
    console.print(Panel("[bold green]ok[/bold green]" if ok else "[bold yellow]mismatch[/bold yellow]", title="FlexSoC smoke", border_style=style))
    console.print(table)

def _command_rows() -> tuple[tuple[str, str, str], ...]:
    """Return top-level commands ordered like a normal development session."""

    return (
        ("help", "Guide", "Show the chronological CLI guide."),
        ("commands", "Guide", "Show this compact command catalog."),
        ("settings", "Setup", "Show or persist project defaults."),
        ("describe", "Setup", "Show API client context."),
        ("workflows", "Discovery", "List high-level workflows."),
        ("steps", "Discovery", "List advanced backend steps."),
        ("step-info", "Discovery", "Show parameters and examples for one step."),
        ("workflow", "Execution", "Run or preview a high-level workflow."),
        ("step", "Execution", "Run or preview one or more backend steps."),
        ("smoke", "Validation", "Run safe catalog and workspace smoke checks."),
    )


def _print_commands(console: Console | None = None) -> None:
    """Render the public command catalog as a Rich table."""

    console = console or Console()
    table = Table(title="FlexSoC commands", border_style=ACCENT, show_lines=False)
    table.add_column("Phase", style=SECONDARY, no_wrap=True)
    table.add_column("Command", style=f"bold {ACCENT}", no_wrap=True)
    table.add_column("Purpose", style="white")
    for command, phase, purpose in _command_rows():
        table.add_row(phase, f"fx {command}", purpose)
    console.print(Panel("Use shell completion with `fx --install-completion`.", title="Command discovery", border_style=ACCENT))
    console.print(table)

def _print_help(console: Console | None = None) -> None:
    """Render the project help guide with a small Rich color palette."""

    console = console or Console()
    console.print(
        Panel(
            f"[bold {ACCENT}]FlexSoC CLI[/bold {ACCENT}]\n{HELP_INTRO}",
            border_style=ACCENT,
        )
    )
    for title, color, rows in HELP_SECTIONS:
        console.print(_help_section(title, color, rows))
    console.print(
        f"[dim]Design rule:[/dim] CLI commands call [bold {ACCENT}]FlexSoC[/bold {ACCENT}], "
        "never backend modules directly."
    )


def _help_section(title: str, color: str, rows: Iterable[tuple[str, str]]) -> Panel:
    """Build one colored help section for the extended CLI guide."""

    table = Table.grid(padding=(0, 2))
    table.add_column(style=f"bold {color}", no_wrap=True)
    table.add_column(style="white")
    for command, description in rows:
        table.add_row(command, description)
    return Panel(table, title=f"[bold {color}]{title}[/bold {color}]", border_style=color)


def _print_step_info(step: FlowStep, console: Console | None = None) -> None:
    """Render one documented step and its accepted Make variables."""

    console = console or Console()
    table = Table(title=f"{step.name} parameters", border_style=ACCENT)
    table.add_column("Category", style="blue")
    table.add_column("Parameter", style=f"bold {ACCENT}")
    table.add_column("Required", style=WARNING)
    table.add_column("Default", style=SECONDARY)
    table.add_column("Description", style="white")
    for param in step.params:
        table.add_row(
            param.category,
            param.name,
            "yes" if param.required else "no",
            param.default or "",
            param.description,
        )
    console.print(Panel(f"[bold {ACCENT}]{step.name}[/bold {ACCENT}]\n{step.description}", border_style=ACCENT))
    console.print(table)
    _print_step_examples(step, console)


def _print_step_examples(step: FlowStep, console: Console | None = None) -> None:
    """Render copy-ready examples for one documented step."""

    console = console or Console()
    table = Table(title=f"{step.name} examples", border_style=SECONDARY)
    table.add_column("Command", style=f"bold {SECONDARY}")
    table.add_column("Purpose", style="white")
    for example in step.examples:
        table.add_row(example.command, example.description)
    console.print(table)


def _print_workflows(workflows: Iterable[FlowWorkflow], console: Console | None = None) -> None:
    """Render public workflows as a compact human catalog."""

    console = console or Console()
    table = Table(title="FlexSoC workflows", border_style="orange3", show_lines=False)
    table.add_column("Workflow", style="bold orange3", no_wrap=True)
    table.add_column("Steps", style="cyan")
    table.add_column("Purpose", style="white")
    table.add_column("Preview", style="dim")
    for workflow in workflows:
        table.add_row(
            workflow.name,
            " → ".join(workflow.steps),
            workflow.description,
            f"fx workflow {workflow.name} --dry-run --script --set TOP=demo",
        )
    console.print(Panel("Use workflows for normal development paths.", title="Discovery", border_style="orange3"))
    console.print(table)


def _print_steps(steps: Iterable[FlowStep], group: str | None = None, console: Console | None = None) -> None:
    """Render advanced steps grouped by development area."""

    console = console or Console()
    items = tuple(sorted(steps, key=lambda step: (step.group, step.name)))
    title = f"FlexSoC steps: {group}" if group else "FlexSoC steps"
    table = Table(title=title, border_style="orange3", show_lines=False)
    table.add_column("Group", style="cyan", no_wrap=True)
    table.add_column("Step", style="bold orange3", no_wrap=True)
    table.add_column("Description", style="white")
    table.add_column("Parameters", style="yellow")
    table.add_column("Details", style="dim")
    for step in items:
        table.add_row(
            step.group,
            step.name,
            step.description,
            _step_param_summary(step),
            f"fx step-info {step.name}",
        )
    console.print(
        Panel(
            "Run `fx step-info NAME` to inspect accepted parameters before running a step.",
            title="Advanced steps",
            border_style="orange3",
        )
    )
    console.print(table)


def _step_param_summary(step: FlowStep) -> str:
    """Return a short parameter summary for the steps table."""

    required = [param.name for param in step.params if param.required]
    optional = [param.name for param in step.params if not param.required]
    names = required + optional[: max(0, 4 - len(required))]
    suffix = " …" if len(required) + len(optional) > len(names) else ""
    return ", ".join(names) + suffix if names else "none"


def _ensure_sequence_run_id(overrides: dict[str, str]) -> dict[str, str]:
    """Return overrides with one RUN_ID shared by a multi-step CLI call."""

    if "RUN_ID" not in overrides:
        overrides = dict(overrides)
        overrides["RUN_ID"] = DEFAULT_SETTINGS["RUN_ID"]
    return overrides


def _project_root(project_root: Path | None = None) -> Path:
    """Return the repository root used for CLI settings and execution."""

    return (project_root or Path.cwd()).resolve()


def _settings_path(project_root: Path | None = None) -> Path:
    """Return the project-local settings file path."""

    return _project_root(project_root) / SETTINGS_DIRNAME / SETTINGS_FILENAME


def _read_settings(project_root: Path | None = None) -> dict[str, str]:
    """Read saved project settings, falling back to an empty mapping."""

    path = _settings_path(project_root)
    if not path.exists():
        return {}
    data = json.loads(path.read_text())
    return {str(key).upper(): str(value) for key, value in data.items()}


def _write_settings(project_root: Path | None, values: dict[str, str]) -> None:
    """Write project settings in a compact JSON file."""

    path = _settings_path(project_root)
    path.parent.mkdir(parents=True, exist_ok=True)
    if values:
        path.write_text(json.dumps(dict(sorted(values.items())), indent=2) + "\n")
    else:
        path.unlink(missing_ok=True)


def _settings_payload(project_root: Path | None = None) -> dict[str, object]:
    """Return defaults, saved settings, and resolved values for display."""

    root = _project_root(project_root)
    defaults = dict(DEFAULT_SETTINGS)
    saved = _read_settings(root)
    resolved = {**defaults, **saved}
    return {
        "path": str(_settings_path(root)),
        "defaults": defaults,
        "saved": saved,
        "resolved": resolved,
        "workspace": str(FlexSoC(project_root=root).workdir),
    }


def _merged_settings(project_root: Path | None, overrides: list[str]) -> dict[str, str]:
    """Merge static defaults, saved project settings, and one-call overrides."""

    values = dict(DEFAULT_SETTINGS)
    values.update(_read_settings(project_root))
    values.update(_parse_overrides(overrides))
    if not values.get("RUN_ID"):
        values["RUN_ID"] = DEFAULT_SETTINGS["RUN_ID"]
    return values


def _generated_run_id() -> str:
    """Return the static default run id for old internal callers."""

    return DEFAULT_SETTINGS["RUN_ID"]


def _print_settings(payload: dict[str, object], console: Console | None = None) -> None:
    """Render project settings as a compact human table."""

    console = console or Console()
    table = Table(title="FlexSoC settings", border_style=ACCENT)
    table.add_column("Name", style=f"bold {ACCENT}")
    table.add_column("Value", style="white")
    table.add_column("Source", style=SECONDARY)
    defaults = payload["defaults"]
    saved = payload["saved"]
    resolved = payload["resolved"]
    for key, value in resolved.items():
        table.add_row(key, str(value), "saved" if key in saved else "default")
    table.add_row("WORKSPACE", str(payload["workspace"]), "computed")
    console.print(Panel(str(payload["path"]), title="Settings file", border_style=ACCENT))
    console.print(table)

def _parse_overrides(items: list[str]) -> dict[str, str]:
    """Parse KEY=VALUE CLI overrides into Make variable values."""

    values: dict[str, str] = {}
    for item in items:
        key, sep, value = item.partition("=")
        if not sep or not key:
            raise typer.BadParameter(f"expected KEY=VALUE, got {item!r}")
        values[key.upper()] = value
    return values

# BEGIN FLEXSOC_CONCISE_CLI
import inspect as _fx_inspect
import json as _fx_json
from rich.console import Console as _FxConsole
from rich.panel import Panel as _FxPanel
from rich.table import Table as _FxTable
import inspect

_FX_CONSOLE = _FxConsole()

_FX_DIRECT_STEPS = {
    "setup": "setup",
    "hjson": "hjson",
    "reg": "reg",
    "doc": "doc",
    "rtl_stub": "rtl_stub",
    "rtl-stub": "rtl_stub",
    "flist": "flist",
    "setup_tb": "setup_tb",
    "setup-tb": "setup_tb",
    "setup_cocotb": "setup_cocotb",
    "setup-cocotb": "setup_cocotb",
    "sim": "sim",
    "view": "view",
    "cocotb": "cocotb",
    "syn": "syn",
    "sta": "sta",
    "power": "power",
    "pnr": "pnr",
    "pnr_gui": "pnr_gui",
    "pnr-gui": "pnr_gui",
    "ip_load": "ip_load",
    "ip-load": "ip_load",
}

_FX_COMMAND_ROWS = [
    ("fx setting", "Show or edit TOP, HOST, RUN_ID, FORCE, WAVE_VIEWER."),
    ("fx steps", "List available backend steps."),
    ("fx <step>", "Run one backend step directly, for example fx hjson --force."),
    ("fx step ...", "Run multiple backend steps in order."),
    ("fx step-info NAME", "Show detailed metadata for one backend step."),
    ("fx smoke", "Run safe package/backend smoke checks."),
]

_FX_TUTORIAL_ROWS = [
    ("IP from scratch", "setup → hjson → reg → doc → rtl_stub → setup_tb → sim", "fx step setup hjson reg doc rtl_stub setup_tb sim --force"),
    ("Reload existing IP", "ip_load copies hw/ips/<TOP> into the current run, then rebuilds filelist/testbench/sim.", "fx step ip_load setup_tb sim --set TOP=cordic --force"),
    ("Cocotb smoke", "Generate cocotb scaffold from the current RTL filelist, then run cocotb.", "fx step setup_cocotb cocotb --force"),
    ("Synthesis smoke", "Use the generated RTL filelist and run the open synthesis checks.", "fx step setup_syn syn sta power"),
    ("Open waveform", "Open the current run waveform with the configured viewer.", "fx view"),
]


def _fx_command_name(command_info: object) -> str:
    """Return the visible Typer command name."""
    name = getattr(command_info, "name", None)
    callback = getattr(command_info, "callback", None)
    if name:
        return str(name)
    if callback is None:
        return ""
    return callback.__name__.replace("_", "-")


def _fx_drop_commands(names: set[str]) -> None:
    """Remove commands registered by earlier CLI versions."""
    app.registered_commands[:] = [cmd for cmd in app.registered_commands if _fx_command_name(cmd) not in names]


def _fx_commands_table() -> _FxTable:
    """Build the concise command table."""
    table = _FxTable(title="Commands", show_lines=False)
    table.add_column("command", style="orange3", no_wrap=True)
    table.add_column("purpose")
    for command, purpose in _FX_COMMAND_ROWS:
        table.add_row(command, purpose)
    return table


def _fx_tutorial_table() -> _FxTable:
    """Build the practical tutorial table."""
    table = _FxTable(title="Tutorials", show_lines=True)
    table.add_column("goal", style="orange3", no_wrap=True)
    table.add_column("flow")
    table.add_column("command", style="green")
    for goal, flow, command in _FX_TUTORIAL_ROWS:
        table.add_row(goal, flow, command)
    return table


def _fx_print_help() -> None:
    """Print the concise FlexSoC guide."""
    _FX_CONSOLE.print(_FxPanel(
        "A compact Python CLI over the backend hardware flow.\n"
        "Set project defaults once, then launch explicit steps directly.",
        title="FlexSoC CLI",
        border_style="orange3",
    ))
    _FX_CONSOLE.print("[bold orange3]Quickstart[/bold orange3]")
    _FX_CONSOLE.print("  fx setting --set TOP=test --set HOST=uart --set RUN_ID=default")
    _FX_CONSOLE.print("  fx hjson --force")
    _FX_CONSOLE.print("  fx reg")
    _FX_CONSOLE.print("  fx doc")
    _FX_CONSOLE.print("  fx rtl_stub")
    _FX_CONSOLE.print("  fx setup_tb")
    _FX_CONSOLE.print("  fx sim")
    _FX_CONSOLE.print()
    _FX_CONSOLE.print(_fx_commands_table())
    _FX_CONSOLE.print()
    _FX_CONSOLE.print(_fx_tutorial_table())
    _FX_CONSOLE.print()
    _FX_CONSOLE.print("[bold]Common options[/bold]")
    _FX_CONSOLE.print("  --info/-h          Show step metadata for a direct step command.")
    _FX_CONSOLE.print("  --set KEY=VALUE    Override a project setting for one command.")
    _FX_CONSOLE.print("  --force            Refresh generated files when they already exist.")
    _FX_CONSOLE.print("  --dry-run --script Print backend commands without executing them.")
    _FX_CONSOLE.print("  --capture          Capture backend output and print failure hints.")


def _fx_step_parameter_default(name: str):
    """Return safe Python defaults when calling a Typer command directly."""

    if name == "targets":
        return []
    if name in {"set", "set_"}:
        return []
    if name in {"force", "overwrite", "dry_run", "script", "capture", "json", "json_output"}:
        return False
    if name in {"project_root", "workspace", "settings_path", "settings_file", "config"}:
        return None
    return None


def _fx_call_step(
    target: str,
    set_: list[str] | None,
    force: bool,
    overwrite: bool,
    dry_run: bool,
    script: bool,
    capture: bool,
) -> None:
    """Run one direct step alias without leaking Typer OptionInfo defaults."""

    explicit = {
        "targets": [target],
        "set_": set_ or [],
        "set": set_ or [],
        "force": force,
        "overwrite": overwrite,
        "dry_run": dry_run,
        "script": script,
        "capture": capture,
        "project_root": None,
    }
    signature = inspect.signature(step)
    kwargs = {}
    for name, parameter in signature.parameters.items():
        if name in explicit:
            kwargs[name] = explicit[name]
        elif parameter.default.__class__.__name__.endswith("Info"):
            kwargs[name] = _fx_step_parameter_default(name)
    step(**kwargs)


def _fx_make_step_command(command_name: str, target: str):
    """Create a direct Typer command for one backend target."""
    def command(
        info: bool = typer.Option(False, "--info", "-h", help="Show step info and exit."),
        force: bool = typer.Option(False, "--force", help="Refresh generated files."),
        overwrite: bool = typer.Option(False, "--overwrite", help="Alias for --force."),
        dry_run: bool = typer.Option(False, "--dry-run", help="Preview backend command."),
        script: bool = typer.Option(False, "--script", help="Print dry-run as shell script."),
        capture: bool = typer.Option(False, "--capture", help="Capture backend output."),
        set_: list[str] | None = typer.Option(None, "--set", help="Override KEY=VALUE."),
    ) -> None:
        """Run one backend step directly."""
        if info:
            step_info(target)
            return
        _fx_call_step(target, set_, force, overwrite, dry_run, script, capture)
    command.__name__ = f"fx_{command_name.replace('-', '_')}"
    command.__doc__ = f"Run the {target} backend step."
    return command


def _fx_setting_alias(*args, **kwargs) -> None:
    """Alias fx setting to the existing settings command."""
    return settings(*args, **kwargs)


def _fx_register_concise_cli() -> None:
    """Register the concise public CLI surface."""
    _fx_drop_commands(set(_FX_DIRECT_STEPS) | {"help", "commands", "workflow", "workflows", "tutorial", "tutorials", "setting"})
    app.command(name="help")(_fx_help_command)
    app.command(name="commands")(_fx_commands_command)
    if "settings" in globals():
        app.command(name="setting")(settings)
    for command_name, target in _FX_DIRECT_STEPS.items():
        app.command(name=command_name)(_fx_make_step_command(command_name, target))


def _fx_help_command() -> None:
    """Show the concise FlexSoC CLI guide."""
    _fx_print_help()


def _fx_commands_command(
    json_: bool = typer.Option(False, "--json", help="Print commands as JSON."),
) -> None:
    """List the concise command surface."""
    if json_:
        typer.echo(_fx_json.dumps([{"command": c, "purpose": p} for c, p in _FX_COMMAND_ROWS], indent=2))
        return
    _FX_CONSOLE.print(_fx_commands_table())


_fx_register_concise_cli()
# END FLEXSOC_CONCISE_CLI
# --- compact public CLI surface ---
PUBLIC_TARGETS = (
    ("setup", "setup", "Create the run directory layout."),
    ("hjson", "hjson", "Generate or refresh the IP HJSON description."),
    ("reg", "reg", "Generate register RTL and software collateral."),
    ("doc", "doc", "Generate register documentation."),
    ("rtl_stub", "rtl_stub", "Generate the RTL top stub."),
    ("rtl-stub", "rtl_stub", "Generate the RTL top stub."),
    ("flist", "flist", "Generate the RTL file list."),
    ("setup_tb", "setup_tb", "Generate the SystemVerilog testbench."),
    ("setup-tb", "setup_tb", "Generate the SystemVerilog testbench."),
    ("setup_cocotb", "setup_cocotb", "Generate the Cocotb scaffold."),
    ("setup-cocotb", "setup_cocotb", "Generate the Cocotb scaffold."),
    ("sim", "sim", "Run lint, compile, and simulation."),
    ("view", "view", "Open the latest waveform."),
    ("cocotb", "cocotb", "Run Cocotb tests."),
    ("setup_syn", "setup_syn", "Generate synthesis scripts."),
    ("setup-syn", "setup_syn", "Generate synthesis scripts."),
    ("syn", "syn", "Run synthesis."),
    ("sta", "sta", "Run static timing analysis."),
    ("power", "power", "Run power analysis."),
    ("pnr", "pnr", "Run place and route."),
    ("pnr_gui", "pnr_gui", "Open the PnR GUI."),
    ("pnr-gui", "pnr_gui", "Open the PnR GUI."),
    ("ip_load", "ip_load", "Load an existing IP into the current run."),
    ("ip-load", "ip_load", "Load an existing IP into the current run."),
)

COMMAND_ROWS = (
    ("fx", "Show this concise guide."),
    ("fx setting", "Show or edit TOP, HOST, RUN_ID, FORCE, WAVE_VIEWER."),
    ("fx commands", "List public commands."),
    ("fx run ...", "Run several backend targets in order."),
    ("fx <target>", "Run one target directly, for example fx hjson --force."),
    ("fx <target> --info", "Show short help for one target."),
    ("fx smoke", "Run safe package/backend checks."),
)


def _fx_table(title: str, columns: tuple[str, str], rows: tuple[tuple[str, str], ...]):
    """Build a compact two-column Rich table."""

    table = Table(title=title)
    table.add_column(columns[0], style="bold orange3")
    table.add_column(columns[1])
    for left, right in rows:
        table.add_row(left, right)
    return table


def _fx_target_rows() -> tuple[tuple[str, str], ...]:
    """Return unique public target command rows for help rendering."""

    seen: set[str] = set()
    rows: list[tuple[str, str]] = []
    for command, _target, purpose in PUBLIC_TARGETS:
        if command in seen or "-" in command:
            continue
        seen.add(command)
        rows.append((f"fx {command}", purpose))
    return tuple(rows)


def _fx_call_targets(
    targets: list[str],
    set_: list[str] | None = None,
    force: bool = False,
    overwrite: bool = False,
    dry_run: bool = False,
    script: bool = False,
    capture: bool = False,
) -> None:
    """Run one or more backend targets through the existing API boundary."""

    kwargs = {
        "targets": targets,
        "project_root": None,
        "set_": set_ or [],
        "force": force,
        "overwrite": overwrite,
        "dry_run": dry_run,
        "script": script,
        "capture": capture,
    }
    signature = inspect.signature(step)
    step(**{key: value for key, value in kwargs.items() if key in signature.parameters})


def _fx_target_command(command_name: str, target: str):
    """Create one concise direct command for a backend target."""

    @app.command(command_name)
    def command(
        info: bool = typer.Option(False, "--info", "-h", help="Show target information and exit."),
        set_: list[str] | None = typer.Option(None, "--set", help="Override one project setting for this command."),
        force: bool = typer.Option(False, "--force", help="Refresh generated files when they already exist."),
        overwrite: bool = typer.Option(False, "--overwrite", help="Alias for --force."),
        dry_run: bool = typer.Option(False, "--dry-run", help="Preview the backend Make command."),
        script: bool = typer.Option(False, "--script", help="Print dry-run output as a shell script."),
        capture: bool = typer.Option(False, "--capture", help="Capture backend output and print failure hints."),
    ) -> None:
        """Run one backend target directly."""

        if info:
            step_info(target)
            return
        _fx_call_targets([target], set_, force, overwrite, dry_run, script, capture)

    command.__name__ = f"fx_{command_name.replace('-', '_')}"
    command.__doc__ = f"Run the {target} backend target."
    return command


@app.callback(invoke_without_command=True, context_settings={"help_option_names": ["-h", "--help"]})
def main(ctx: typer.Context) -> None:
    """Show concise help when fx is launched without a subcommand."""

    if ctx.invoked_subcommand is None:
        help()


@app.command("help")
def help() -> None:
    """Show the concise FlexSoC command guide."""

    console.print(Panel(
        "A compact Python CLI over the backend hardware flow.\n"
        "Set project defaults once, then launch explicit backend targets.",
        title="FlexSoC CLI",
        border_style="orange3",
    ))
    console.print("[bold orange3]Quickstart[/bold orange3]")
    for line in (
        "fx setting --set TOP=test --set HOST=uart --set RUN_ID=default",
        "fx hjson --force",
        "fx reg",
        "fx doc",
        "fx rtl_stub",
        "fx setup_tb",
        "fx sim",
        "fx view",
    ):
        console.print(f"  {line}")
    console.print()
    console.print(_fx_table("Commands", ("command", "purpose"), COMMAND_ROWS))
    console.print()
    console.print("[bold orange3]IP development[/bold orange3]")
    for line in (
        "1. fx setting --set TOP=my_ip --set HOST=uart --set RUN_ID=default",
        "2. fx setup",
        "3. fx hjson --force",
        "4. fx reg && fx doc",
        "5. fx rtl_stub && fx setup_tb",
        "6. fx sim && fx view",
    ):
        console.print(f"  {line}")
    console.print()
    console.print("[bold orange3]Existing IP[/bold orange3]")
    for line in (
        "1. fx setting --set TOP=cordic --set HOST=uart --set RUN_ID=default",
        "2. fx ip_load --force",
        "3. fx setup_tb",
        "4. fx sim && fx view",
    ):
        console.print(f"  {line}")
    console.print()
    console.print("[bold orange3]Useful options[/bold orange3]")
    for line in (
        "--info/-h          Show information for a direct target command.",
        "--set KEY=VALUE    Override one project setting for one command.",
        "--force            Refresh generated files when they already exist.",
        "--dry-run --script Print backend Make commands without executing them.",
        "--capture          Capture backend output and print failure hints.",
    ):
        console.print(f"  {line}")
    console.print()
    console.print("Design rule: CLI commands call FlexSoC, never backend modules directly.")


@app.command("commands")
def commands(json_: bool = typer.Option(False, "--json", help="Print command metadata as JSON.")) -> None:
    """List the compact public command surface."""

    rows = tuple({"command": command, "purpose": purpose} for command, purpose in COMMAND_ROWS)
    if json_:
        typer.echo(json.dumps(rows, indent=2))
        return
    console.print(_fx_table("Commands", ("command", "purpose"), COMMAND_ROWS))
    console.print(_fx_table("Targets", ("command", "purpose"), _fx_target_rows()))


@app.command("run")
def run(
    targets: list[str] = typer.Argument(..., help="Backend targets to run in order."),
    set_: list[str] | None = typer.Option(None, "--set", help="Override one project setting for this command."),
    force: bool = typer.Option(False, "--force", help="Refresh generated files when they already exist."),
    overwrite: bool = typer.Option(False, "--overwrite", help="Alias for --force."),
    dry_run: bool = typer.Option(False, "--dry-run", help="Preview backend Make commands."),
    script: bool = typer.Option(False, "--script", help="Print dry-run output as a shell script."),
    capture: bool = typer.Option(False, "--capture", help="Capture backend output and print failure hints."),
) -> None:
    """Run several backend targets in order."""

    _fx_call_targets(targets, set_, force, overwrite, dry_run, script, capture)


for _command_name, _target, _purpose in PUBLIC_TARGETS:
    _fx_target_command(_command_name, _target)


def _fx_command_name(command_info) -> str:
    """Return the public Typer command name for filtering."""

    name = command_info.name
    if name:
        return name
    callback = getattr(command_info, "callback", None)
    return callback.__name__.replace("_", "-") if callback else ""


def _fx_prune_registered_commands() -> None:
    """Drop old workflow/step commands and keep the newest duplicate commands."""

    banned = {"workflow", "workflows", "tutorials", "step", "steps", "step-info"}
    latest: dict[str, object] = {}
    for info in app.registered_commands:
        latest[_fx_command_name(info)] = info
    app.registered_commands[:] = [
        info
        for info in app.registered_commands
        if _fx_command_name(info) not in banned and latest.get(_fx_command_name(info)) is info
    ]


_fx_prune_registered_commands()
# --- end compact public CLI surface ---

# Focused RTL lint direct commands.
def _fx_lint_command(target: str, set_: list[str] | None, tool: str, force: bool, overwrite: bool, dry_run: bool, script: bool, capture: bool) -> None:
    """Run one lint backend target with an optional tool selection."""
    values = list(set_ or [])
    if tool != "auto":
        values.append(f"LINT_TOOL={tool}")
    _fx_call_step(target, values, force, overwrite, dry_run, script, capture)


def _fx_register_lint_command(name: str, target: str, title: str) -> None:
    """Register one concise lint command."""
    @app.command(name)
    def command(
        tool: str = typer.Option("auto", "--tool", help="Lint backend: auto, verilator, or slang."),
        set_: list[str] | None = typer.Option(None, "--set", help="Override one project setting for this command."),
        force: bool = typer.Option(False, "--force", help="Forward FORCE=1 to backend steps."),
        overwrite: bool = typer.Option(False, "--overwrite", help="Alias for --force."),
        dry_run: bool = typer.Option(False, "--dry-run", help="Print the backend command without running it."),
        script: bool = typer.Option(False, "--script", help="Render dry-run output as a shell script."),
        capture: bool = typer.Option(False, "--capture", help="Capture backend output and print hints on failure."),
    ) -> None:
        """Run one focused RTL lint command."""
        _fx_lint_command(target, set_, tool, force, overwrite, dry_run, script, capture)
    command.__name__ = f"fx_{name.replace('-', '_')}"
    command.__doc__ = title


for _lint_name, _lint_target, _lint_title in (
    ("lint", "lint", "Run all configured RTL lint checks."),
    ("lint-latch", "lint_latch", "Check inferred latch diagnostics."),
    ("lint-undriven", "lint_undriven", "Check undriven signal diagnostics."),
    ("lint-width", "lint_width", "Check width mismatch diagnostics."),
    ("lint-unconnected", "lint_unconnected", "Check unconnected port diagnostics."),
    ("lint-unused", "lint_unused", "Check unused signal diagnostics."),
):
    _fx_register_lint_command(_lint_name, _lint_target, _lint_title)
