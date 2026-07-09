"""Compact command line entrypoint for the FlexSoC API layer."""

from __future__ import annotations

import json
import subprocess
from pathlib import Path
from typing import Any, Iterable

import typer
from rich.console import Console
from rich.panel import Panel
from rich.table import Table

from .api import FlexSoC

ACCENT = "orange3"
SECONDARY = "cyan"
SUCCESS = "green"
WARNING = "yellow"

SETTINGS_DIRNAME = ".flexsoc"
SETTINGS_FILENAME = "settings.json"
DEFAULT_SETTINGS = {"TOP": "test", "HOST": "uart", "FORCE": "0", "RUN_ID": "default"}

def _target_aliases_for_step(name: str) -> tuple[str, ...]:
    """Return ergonomic aliases for one backend target."""

    aliases = [name]
    dashed = name.replace("_", "-")
    if dashed != name:
        aliases.append(dashed)
    return tuple(aliases)


def _public_targets() -> tuple[tuple[str, str, str], ...]:
    """Expose every documented backend step as a compact `fx TARGET` command."""

    rows: list[tuple[str, str, str]] = []
    for step in FlexSoC().list_steps():
        if step.group == "help" or step.name == "help":
            continue
        for command in _target_aliases_for_step(step.name):
            rows.append((command, step.name, step.description))
    return tuple(rows)


PUBLIC_TARGETS: tuple[tuple[str, str, str], ...] = _public_targets()

TARGET_ALIASES = {target: target for _, target, _ in PUBLIC_TARGETS} | {
    command: target for command, target, _ in PUBLIC_TARGETS
}

COMMAND_ROWS: tuple[tuple[str, str], ...] = (
    ("fx", "Show this concise guide."),
    ("fx help", "Show this concise guide."),
    ("fx settings", "Show or edit TOP, HOST, RUN_ID, FORCE, and WAVE_VIEWER."),
    ("fx commands", "List the compact command catalog."),
    ("fx TARGET [TARGET...]", "Run backend targets in the exact order provided."),
    ("fx TARGET --info", "Show target metadata and examples."),
    ("fx smoke", "Run safe package/backend smoke checks."),
)

app = typer.Typer(
    add_completion=True,
    context_settings={"help_option_names": ["-h", "--help"]},
    help="Compact FlexSoC CLI over the public API layer. Use `fx help` for examples.",
)
console = Console()


def _as_bool(value: object) -> bool:
    """Return True only for real boolean CLI flags, not Typer OptionInfo defaults."""

    return value is True


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
    return {str(key).upper(): str(value) for key, value in json.loads(path.read_text()).items()}


def _write_settings(project_root: Path | None, values: dict[str, str]) -> None:
    """Write project settings in a compact JSON file."""

    path = _settings_path(project_root)
    path.parent.mkdir(parents=True, exist_ok=True)
    if values:
        path.write_text(json.dumps(dict(sorted(values.items())), indent=2) + "\n")
    else:
        path.unlink(missing_ok=True)


def _parse_overrides(items: Iterable[str] | None) -> dict[str, str]:
    """Parse KEY=VALUE CLI overrides into Make variable values."""

    values: dict[str, str] = {}
    for item in items or ():
        key, sep, value = str(item).partition("=")
        if not sep or not key:
            raise typer.BadParameter(f"expected KEY=VALUE, got {item!r}")
        values[key.upper()] = value
    return values


def _merged_settings(project_root: Path | None, overrides: Iterable[str] | None) -> dict[str, str]:
    """Merge static defaults, saved project settings, and one-call overrides."""

    values = dict(DEFAULT_SETTINGS)
    values.update(_read_settings(project_root))
    values.update(_parse_overrides(overrides))
    if not values.get("RUN_ID"):
        values["RUN_ID"] = DEFAULT_SETTINGS["RUN_ID"]
    return values


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


def _print_settings(payload: dict[str, object], output: Console | None = None) -> None:
    """Render project settings as a compact human table."""

    output = output or console
    saved = payload["saved"]
    resolved = payload["resolved"]
    table = Table(title="FlexSoC settings", border_style=ACCENT)
    table.add_column("Name", style=f"bold {ACCENT}")
    table.add_column("Value")
    table.add_column("Source", style=SECONDARY)
    for key, value in resolved.items():
        table.add_row(str(key), str(value), "saved" if key in saved else "default")
    table.add_row("WORKSPACE", str(payload["workspace"]), "computed")
    output.print(Panel(str(payload["path"]), title="Settings file", border_style=ACCENT))
    output.print(table)


def _table(title: str, columns: tuple[str, str], rows: Iterable[tuple[str, str]]) -> Table:
    """Build a compact two-column Rich table."""

    table = Table(title=title)
    table.add_column(columns[0], style=f"bold {ACCENT}")
    table.add_column(columns[1])
    for left, right in rows:
        table.add_row(left, right)
    return table


def _target_rows() -> tuple[tuple[str, str], ...]:
    """Return unique public target command rows for help rendering."""

    seen: set[str] = set()
    rows: list[tuple[str, str]] = []
    for command, target, purpose in PUBLIC_TARGETS:
        if target in seen:
            continue
        seen.add(target)
        rows.append((f"fx {command}", purpose))
    return tuple(rows)


def _print_help(output: Console | None = None) -> None:
    """Render the canonical compact command guide."""

    output = output or console
    output.print(
        Panel(
            "A compact Python CLI over the backend hardware flow.\n"
            "Set project defaults once, then launch explicit backend targets.",
            title="FlexSoC CLI",
            border_style=ACCENT,
        )
    )
    output.print(f"[bold {ACCENT}]Quickstart[/bold {ACCENT}]")
    for line in (
        "fx settings --set TOP=test --set HOST=uart --set RUN_ID=default",
        "fx hjson --force",
        "fx reg",
        "fx doc",
        "fx rtl_stub",
        "fx setup_tb",
        "fx sim",
        "fx view",
    ):
        output.print(f"  {line}")
    output.print()
    output.print(_table("Commands", ("command", "purpose"), COMMAND_ROWS))
    output.print()
    output.print(f"[bold {ACCENT}]IP development[/bold {ACCENT}]")
    for line in (
        "1. fx settings --set TOP=my_ip --set HOST=uart --set RUN_ID=default",
        "2. fx setup",
        "3. fx hjson --force",
        "4. fx reg doc",
        "5. fx rtl_stub setup_tb",
        "6. fx sim view",
    ):
        output.print(f"  {line}")
    output.print()
    output.print(f"[bold {ACCENT}]Existing IP[/bold {ACCENT}]")
    for line in (
        "1. fx settings --set TOP=cordic --set HOST=uart --set RUN_ID=default",
        "2. fx ip_load --force",
        "3. fx setup_tb",
        "4. fx sim view",
    ):
        output.print(f"  {line}")
    output.print()
    output.print(f"[bold {ACCENT}]Useful options[/bold {ACCENT}]")
    for line in (
        "--info/-h          Show information for a direct target command.",
        "--set KEY=VALUE    Override one project setting for one command.",
        "--force            Refresh generated files when they already exist.",
        "--dry-run --script Print backend Make commands without executing them.",
        "--capture          Capture backend output and print failure hints.",
    ):
        output.print(f"  {line}")
    output.print()
    output.print(
        f"[dim]Design rule:[/dim] CLI commands call [bold {ACCENT}]FlexSoC[/bold {ACCENT}], "
        "never backend modules directly."
    )


def _print_step_examples(step: Any, output: Console | None = None) -> None:
    """Render copy-ready examples for one documented step."""

    output = output or console
    table = Table(title=f"{step.name} examples", border_style=SECONDARY)
    table.add_column("Command", style=f"bold {SECONDARY}")
    table.add_column("Purpose")
    for example in step.examples:
        table.add_row(example.command, example.description)
    output.print(table)


def _print_step_info(step: Any, output: Console | None = None) -> None:
    """Render one documented step and its accepted Make variables."""

    output = output or console
    table = Table(title=f"{step.name} parameters", border_style=ACCENT)
    table.add_column("Category", style="blue")
    table.add_column("Parameter", style=f"bold {ACCENT}")
    table.add_column("Required", style=WARNING)
    table.add_column("Default", style=SECONDARY)
    table.add_column("Description")
    for param in step.params:
        table.add_row(
            param.category,
            param.name,
            "yes" if param.required else "no",
            param.default or "",
            param.description,
        )
    output.print(Panel(f"[bold {ACCENT}]{step.name}[/bold {ACCENT}]\n{step.description}", border_style=ACCENT))
    output.print(table)
    _print_step_examples(step, output)


def _shell_script(lines: Iterable[str]) -> str:
    """Render dry-run shell lines as a small executable script preview."""

    return "#!/usr/bin/env bash\nset -euo pipefail\n" + "\n".join(lines) + "\n"


def _error_hint(target: str, message: object = "") -> str:
    """Return a short recovery hint for common backend target failures."""

    text = str(message).lower()
    if "refusing to overwrite" in text or "use --force" in text:
        return (
            f"hint: {target} found an existing generated file. "
            "Re-run with --force or choose another RUN_ID."
        )
    hints = {
        "hjson": "hint: hjson writes data/<TOP>.hjson; use --force/--overwrite when refreshing it.",
        "hjson_gen": "hint: hjson_gen writes data/<TOP>.hjson; use --force/--overwrite when refreshing it.",
        "reg": "hint: reg expects data/<TOP>.hjson. Run hjson first and keep the same TOP/RUN_ID.",
        "doc": "hint: doc expects data/<TOP>.hjson. Run hjson first and keep the same TOP/RUN_ID.",
        "rtl_stub": "hint: rtl_stub expects generated metadata. Run hjson/reg first.",
        "setup_tb": "hint: setup_tb expects generated RTL/filelist inputs. Run rtl_stub/flist first.",
        "setup_cocotb": "hint: setup_cocotb expects rtl/rtl_list.f. Run flist first.",
        "sim": "hint: sim depends on generated RTL/testbench inputs; rerun with --capture for logs.",
        "syn": "hint: syn needs synthesis inputs from the same RUN_ID; inspect syn logs with --capture.",
        "sta": "hint: sta depends on synthesis outputs. Run syn first.",
        "power": "hint: power depends on synthesis/timing outputs. Run syn and sta first.",
        "pnr": "hint: pnr depends on synthesis and floorplan inputs. Run syn/setup_pnr first.",
        "pnr_gui": "hint: pnr_gui depends on an existing PnR run. Run pnr first.",
    }
    return hints.get(target, "hint: re-run with --capture and inspect workspace/runs/<TOP>/<RUN_ID> logs.")


def _normalize_targets(targets: Iterable[str]) -> list[str]:
    """Resolve CLI command aliases into backend Make target names."""

    resolved: list[str] = []
    for item in targets:
        key = str(item)
        target = TARGET_ALIASES.get(key)
        if target is None:
            known = ", ".join(sorted(TARGET_ALIASES))
            raise typer.BadParameter(f"unknown target {key!r}; expected one of: {known}")
        resolved.append(target)
    return resolved


def _target_payloads(
    client: FlexSoC,
    targets: Iterable[str],
    values: dict[str, str],
) -> list[dict[str, Any]]:
    """Return JSON-ready dry-run previews for targets."""

    return [client.inspect_step(target, **values) for target in targets]


def _run_targets(
    targets: Iterable[str],
    *,
    set_: Iterable[str] | None = None,
    project_root: Path | None = None,
    force: bool = False,
    overwrite: bool = False,
    dry_run: bool = False,
    script: bool = False,
    capture: bool = False,
    json_: bool = False,
) -> None:
    """Run, preview, or serialize one or more backend targets through FlexSoC."""

    target_list = _normalize_targets(targets)
    client = FlexSoC(project_root=project_root)
    values = _merged_settings(project_root, set_)
    if force or overwrite:
        values["FORCE"] = "1"
    if dry_run:
        payloads = _target_payloads(client, target_list, values)
        if json_:
            payload: object = payloads[0] if len(payloads) == 1 else payloads
            typer.echo(json.dumps(payload, indent=2))
            return
        lines = [str(item["shell"]) for item in payloads]
        typer.echo(_shell_script(lines) if script else "\n".join(lines), nl=not script)
        return

    results = []
    for target in target_list:
        try:
            results.append(client.run_step(target, capture=capture, **values))
        except subprocess.CalledProcessError as exc:
            command = " ".join(str(part) for part in exc.cmd)
            typer.secho(f"target failed: {target}", fg=typer.colors.RED, err=True)
            typer.secho(f"command: {command}", err=True)
            typer.secho(_error_hint(target, exc.stderr or exc.stdout or exc), err=True)
            raise typer.Exit(exc.returncode) from exc

    if json_:
        payload = results[0].to_dict() if len(results) == 1 else [item.to_dict() for item in results]
        typer.echo(json.dumps(payload, indent=2))
    elif capture:
        for result in results:
            if result.stdout:
                typer.echo(result.stdout, nl=False)


def _smoke_payload(client: FlexSoC, top: str, run_id: str, run_workspace: bool) -> dict[str, object]:
    """Build a safe smoke payload using public framework workflows."""

    workflows = {
        name: client.inspect_workflow(name, top=top, run_id=run_id).shell_lines()
        for name in ("workspace", "ip_development", "soc_development")
    }
    workspace_results = []
    if run_workspace:
        workspace_results = [
            item.to_dict()
            for item in client.run_workflow("workspace", capture=True, top=top, run_id=run_id)
        ]
    workspace_ok = all(item.get("ok", False) for item in workspace_results) if workspace_results else True
    return {
        "ok": workspace_ok,
        "workflows": {name: list(lines) for name, lines in workflows.items()},
        "workspace_results": workspace_results,
    }


def _print_smoke(payload: dict[str, object], output: Console | None = None) -> None:
    """Render the safe smoke summary for humans."""

    output = output or console
    ok = bool(payload["ok"])
    style = SUCCESS if ok else WARNING
    workflows = payload["workflows"]
    table = Table(title="Smoke checks", border_style=style)
    table.add_column("Check", style=f"bold {ACCENT}")
    table.add_column("Result")
    for name, lines in workflows.items():
        table.add_row(str(name), f"{len(lines)} command(s) previewed")
    if payload["workspace_results"]:
        table.add_row(
            "workspace execution",
            "ok" if all(item["ok"] for item in payload["workspace_results"]) else "failed",
        )
    output.print(
        Panel(
            "[bold green]ok[/bold green]" if ok else "[bold yellow]mismatch[/bold yellow]",
            title="FlexSoC smoke",
            border_style=style,
        )
    )
    output.print(table)


def _show_target_info(target: str, *, json_: bool = False) -> None:
    """Show parameters, categories, and examples for one backend target."""

    step = FlexSoC().step_info(target)
    if _as_bool(json_):
        typer.echo(json.dumps(step.to_dict(), indent=2))
    else:
        _print_step_info(step)


@app.callback(invoke_without_command=True)
def main(ctx: typer.Context) -> None:
    """Show concise help when fx is launched without a subcommand."""

    if ctx.invoked_subcommand is None:
        help()


@app.command("help")
def help() -> None:
    """Show the concise FlexSoC command guide."""

    _print_help()


@app.command("commands")
def commands(json_: bool = typer.Option(False, "--json", help="Print command metadata as JSON.")) -> None:
    """List the compact public command surface."""

    rows = tuple({"command": command, "purpose": purpose} for command, purpose in COMMAND_ROWS)
    if _as_bool(json_):
        typer.echo(json.dumps(rows, indent=2))
        return
    console.print(_table("Commands", ("command", "purpose"), COMMAND_ROWS))
    console.print(_table("Targets", ("command", "purpose"), _target_rows()))



@app.command("settings")
def settings(
    set_: list[str] | None = typer.Option(None, "--set", help="Persist one project setting as KEY=VALUE."),
    unset: list[str] | None = typer.Option(None, "--unset", help="Remove one persisted setting by name."),
    reset: bool = typer.Option(False, "--reset", help="Remove all persisted project settings."),
    project_root: Path | None = typer.Option(None, help="Repository root that owns the settings file."),
    json_: bool = typer.Option(False, "--json", help="Print a JSON payload for tools and frontends."),
) -> None:
    """Show, save, or reset project-level FlexSoC CLI settings."""

    root = _project_root(project_root)
    path = _settings_path(root)
    values = _read_settings(root)
    changed = False
    if _as_bool(reset):
        path.unlink(missing_ok=True)
        values = {}
        changed = True
    for key in unset or []:
        changed = values.pop(str(key).upper(), None) is not None or changed
    if set_:
        values.update(_parse_overrides(set_))
        changed = True
    if changed:
        _write_settings(root, values)
    payload = _settings_payload(root)
    if _as_bool(json_):
        typer.echo(json.dumps(payload, indent=2))
    else:
        _print_settings(payload)



@app.command("smoke")
def smoke(
    top: str = typer.Option("demo", help="Top name used for smoke previews."),
    run_id: str = typer.Option("smoke", help="Run identifier used for smoke previews."),
    project_root: Path | None = typer.Option(None, help="Repository root used as execution cwd."),
    json_: bool = typer.Option(False, "--json", help="Print a JSON payload for tools and frontends."),
    run_workspace: bool = typer.Option(False, "--run-workspace", help="Execute only the safe workspace workflow."),
) -> None:
    """Run safe API/CLI smoke checks without launching EDA tools by default."""

    payload = _smoke_payload(FlexSoC(project_root=project_root), top, run_id, run_workspace)
    if _as_bool(json_):
        typer.echo(json.dumps(payload, indent=2))
    else:
        _print_smoke(payload)
    if not payload["ok"]:
        raise typer.Exit(1)


def _target_command(command_name: str, target: str):
    """Create one concise direct command for a backend target."""

    def command(
        extra_targets: list[str] | None = typer.Argument(
            None, help="Additional backend targets to run after this one."
        ),
        info: bool = typer.Option(False, "--info", "-h", help="Show target information and exit."),
        set_: list[str] | None = typer.Option(None, "--set", help="Override one project setting for this command."),
        force: bool = typer.Option(False, "--force", help="Refresh generated files when they already exist."),
        overwrite: bool = typer.Option(False, "--overwrite", help="Alias for --force."),
        dry_run: bool = typer.Option(False, "--dry-run", help="Preview the backend Make command."),
        script: bool = typer.Option(False, "--script", help="Print dry-run output as a shell script."),
        capture: bool = typer.Option(False, "--capture", help="Capture backend output and print failure hints."),
        json_: bool = typer.Option(False, "--json", help="Print JSON for dry-run or execution results."),
    ) -> None:
        """Run one or more backend targets directly."""

        if _as_bool(info):
            _show_target_info(target, json_=json_)
            return
        _run_targets(
            [target, *(extra_targets or [])],
            set_=set_,
            force=force,
            overwrite=overwrite,
            dry_run=dry_run,
            script=script,
            capture=capture,
            json_=json_,
        )

    command.__name__ = f"fx_{command_name.replace('-', '_')}"
    command.__doc__ = f"Run the {target} backend target."
    return command


def _lint_command(command_name: str, target: str):
    """Create one direct lint command with optional lint-tool selection."""

    def command(
        extra_targets: list[str] | None = typer.Argument(
            None, help="Additional backend targets to run after this one."
        ),
        info: bool = typer.Option(False, "--info", "-h", help="Show target information and exit."),
        tool: str = typer.Option("auto", "--tool", help="Lint backend: auto, verilator, or slang."),
        set_: list[str] | None = typer.Option(None, "--set", help="Override one project setting for this command."),
        force: bool = typer.Option(False, "--force", help="Refresh generated files when they already exist."),
        overwrite: bool = typer.Option(False, "--overwrite", help="Alias for --force."),
        dry_run: bool = typer.Option(False, "--dry-run", help="Preview the backend Make command."),
        script: bool = typer.Option(False, "--script", help="Print dry-run output as a shell script."),
        capture: bool = typer.Option(False, "--capture", help="Capture backend output and print failure hints."),
        json_: bool = typer.Option(False, "--json", help="Print JSON for dry-run or execution results."),
    ) -> None:
        """Run one or more backend targets, starting with one focused RTL lint target."""

        if _as_bool(info):
            _show_target_info(target, json_=json_)
            return
        values = list(set_ or [])
        if tool != "auto":
            values.append(f"LINT_TOOL={tool}")
        _run_targets(
            [target, *(extra_targets or [])],
            set_=values,
            force=force,
            overwrite=overwrite,
            dry_run=dry_run,
            script=script,
            capture=capture,
            json_=json_,
        )

    command.__name__ = f"fx_{command_name.replace('-', '_')}"
    command.__doc__ = f"Run the {target} backend target."
    return command


for _command_name, _target, _purpose in PUBLIC_TARGETS:
    factory = _lint_command if _target.startswith("lint") else _target_command
    app.command(_command_name)(factory(_command_name, _target))


if __name__ == "__main__":
    app()
