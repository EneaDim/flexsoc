"""Readable Typer/Prompt Toolkit front-end for FlexSoC."""

from __future__ import annotations

import json
import shlex
import subprocess
import sys
from pathlib import Path
from typing import Annotated, Any, Iterable, Mapping

from .api import DEFAULT_SETTINGS, TARGETS, FlexSoC, FlexSoCConfig

try:  # Keep the entry point understandable if the new CLI deps are not installed yet.
    import click
    import typer
    from rich.console import Console
    from rich.panel import Panel
    from rich.table import Table
except ModuleNotFoundError as exc:  # pragma: no cover - exercised only in incomplete envs.
    _MISSING = exc.name
else:
    _MISSING = ""


if _MISSING:  # pragma: no cover - exercised only in incomplete envs.

    def app(argv: list[str] | None = None) -> int:
        """Explain how to install the CLI dependencies."""

        print(
            f"missing CLI dependency: {_MISSING}\n"
            "run: uv sync\n"
            "then: uv run fx --help",
            file=sys.stderr,
        )
        return 2

    main = app

else:
    console = Console()
    error_console = Console(stderr=True)
    PSEUDO_COMMANDS = ("settings", "commands", "shell")
    OPTION_WORDS = (
        "--set",
        "--unset",
        "--project-root",
        "--workdir",
        "--tool",
        "--reset",
        "--force",
        "--overwrite",
        "--dry-run",
        "--script",
        "--capture",
        "--live",
        "--json",
        "--info",
        "--install-completion",
        "--show-completion",
    )

    HELP = """\
FlexSoC command runner.

Run `fx` or `fx --help` to show the readable orange/cyan guide.
Use `fx commands` to list every backend Make target.
"""

    typer_app = typer.Typer(
        add_completion=True,
        no_args_is_help=False,
        rich_markup_mode="rich",
        pretty_exceptions_show_locals=False,
        context_settings={"help_option_names": ["-h", "--help"]},
    )

    # -----------------------------------------------------------------------
    # Completion and help text
    # -----------------------------------------------------------------------

    def _completion_words() -> tuple[str, ...]:
        """Return words offered by shell and REPL completion."""

        return tuple(dict.fromkeys((*PSEUDO_COMMANDS, *TARGETS, *OPTION_WORDS)))

    def _complete_items(incomplete: str) -> list[str]:
        """Complete pseudo-commands and backend targets."""

        return [word for word in _completion_words() if word.startswith(incomplete)]

    def _guide() -> None:
        """Print a compact orange/cyan guide with one description per row."""

        def row(cmd: str, desc: str) -> str:
            """Format one command plus its short explanation."""

            return f"  [bold bright_cyan]{cmd}[/bold bright_cyan]\n    [white]{desc}[/white]"

        def section(title: str, rows: list[tuple[str, str]]) -> str:
            """Format one readable help section."""

            body = "\n".join(row(cmd, desc) for cmd, desc in rows)
            return f"[bold orange1]{title}[/bold orange1]\n{body}"

        blocks = [
            section(
                "Main commands",
                [
                    ("fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart", "Save the default IP/run configuration."),
                    ("fx commands", "List every backend target exposed by the Makefile."),
                    ("fx tests", "Show generated verification tests for the current IP."),
                    ("fx shell", "Open the interactive prompt with target completion."),
                ],
            ),
            section(
                "Model + verification",
                [
                    ("fx setup_model --force", "Create the editable model and generate config/data vectors."),
                    ("fx setup_tb setup_cocotb --force", "Generate SystemVerilog and cocotb runners."),
                    ("fx sim --set TEST_NAME=smoke --force", "Run one SystemVerilog vector test by name."),
                    ("fx cocotb --set TEST_NAME=smoke --force", "Run one cocotb vector test by name."),
                    ("fx sim_tests", "Run all generated SystemVerilog tests for this IP."),
                    ("fx cocotb_tests", "Run all generated cocotb tests for this IP."),
                ],
            ),
            section(
                "IP development",
                [
                    ("fx setup hjson reg doc rtl_stub lint --force", "Create a fresh IP workspace and run lint."),
                    ("fx setup_model setup_tb setup_cocotb sim cocotb --force", "Generate and run model-driven verification."),
                    ("fx syn sdf sta power --force", "Run synthesis and signoff checks."),
                ],
            ),
            section(
                "Multi-clock IP",
                [
                    ("fx hjson_multi reg_multi doc_multi --force", "Create and build cfg/dsp register maps."),
                    ("fx rtl_stub_multi --force", "Generate core from regmaps and wrapper from core."),
                    ("fx top_from_core_multi --force", "Refresh the wrapper after editing core ports."),
                    ("fx setup_model_multi setup_tb_multi setup_cocotb_multi --force", "Generate multi-clock model, vectors and runners."),
                    ("fx multiclock_scaffold --force", "Run the decomposed multi-clock bootstrap."),
                ],
            ),
            section(
                "System-on-chip building",
                [
                    ("fx ip_load --set TOP=cordic --set RUN_TOP=cordic", "Load an existing IP into the workspace."),
                    ("fx soc_uart_gen soc_prepare soc_build_sw soc_run", "Build and run a UART-hosted SoC flow."),
                ],
            ),
            section(
                "Useful options",
                [
                    ("--set KEY=VALUE", "Override one Make/config variable for this command."),
                    ("--force", "Overwrite generated files where supported."),
                    ("--dry-run", "Print the Make command without executing it."),
                    ("--info", "Describe selected targets instead of running them."),
                    ("--json", "Print machine-readable output for scripts."),
                    ("--install-completion", "Install shell completion through Typer."),
                ],
            ),
        ]
        text = "\n\n".join(blocks)
        console.print()
        console.print(
            Panel(
                text,
                title="[bold orange1]FlexSoC fx help[/bold orange1]",
                subtitle="[bold bright_cyan]settings • targets • verification[/bold bright_cyan]",
                border_style="orange1",
                padding=(1, 2),
            )
        )
        console.print("[white]Tip:[/white] use [bold bright_cyan]fx commands[/bold bright_cyan] for the full target catalog.\n")

    # -----------------------------------------------------------------------
    # Persistent settings
    # -----------------------------------------------------------------------

    def _upper(values: Mapping[str, Any]) -> dict[str, str]:
        """Convert settings to Make-style uppercase strings."""

        return {str(key).upper(): str(value) for key, value in values.items() if value is not None}

    def _settings_path(root: Path) -> Path:
        """Return the project-local settings file."""

        return root / ".flexsoc" / "settings.json"

    def _read_settings(root: Path) -> dict[str, str]:
        """Read persisted settings merged over defaults."""

        path = _settings_path(root)
        values = json.loads(path.read_text(encoding="utf-8")) if path.exists() else {}
        return {**DEFAULT_SETTINGS, **_upper(values)}

    def _write_settings(root: Path, values: Mapping[str, Any]) -> None:
        """Write project-local settings."""

        path = _settings_path(root)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(_upper(values), indent=2, sort_keys=True) + "\n", encoding="utf-8")

    def _assignments(items: Iterable[str]) -> dict[str, str]:
        """Parse KEY=VALUE items."""

        values: dict[str, str] = {}
        for item in items:
            if "=" not in item:
                raise typer.BadParameter(f"expected KEY=VALUE, got {item!r}")
            key, value = item.split("=", 1)
            values[key.upper()] = value
        return values

    # -----------------------------------------------------------------------
    # Output helpers
    # -----------------------------------------------------------------------

    def _print_commands(client: FlexSoC, as_json: bool) -> None:
        """Print the unified target table."""

        targets = client.targets()
        if as_json:
            print(json.dumps([target.to_dict() for target in targets], indent=2))
            return
        table = Table(title="FlexSoC Make targets", show_lines=False)
        table.add_column("Target", style="cyan", no_wrap=True)
        table.add_column("Group", style="magenta", no_wrap=True)
        table.add_column("Description")
        table.add_column("Variables")
        for target in targets:
            table.add_row(target.name, target.group, target.description, ", ".join(target.params))
        console.print(table)

    def _print_settings(values: Mapping[str, str], as_json: bool) -> None:
        """Print current settings."""

        if as_json:
            print(json.dumps(dict(values), indent=2))
            return
        table = Table(title="FlexSoC settings", show_header=False)
        table.add_column("Key", style="cyan", no_wrap=True)
        table.add_column("Value")
        for key, value in sorted(values.items()):
            table.add_row(key, value)
        console.print(table)

    def _print_info(client: FlexSoC, targets: tuple[str, ...], as_json: bool) -> None:
        """Print metadata for selected targets."""

        data = [client.target_info(target).to_dict() for target in targets]
        if as_json:
            print(json.dumps(data[0] if len(data) == 1 else data, indent=2))
            return
        for item in data:
            text = f"[bold cyan]{item['name']}[/bold cyan]\n{item['description']}\nvars: {', '.join(item['params']) or '-'}"
            console.print(Panel.fit(text, title=item["group"]))

    # -----------------------------------------------------------------------
    # Command handlers
    # -----------------------------------------------------------------------

    def _settings(root: Path, items: tuple[str, ...], sets: tuple[str, ...], unsets: tuple[str, ...], reset: bool, as_json: bool) -> None:
        """Show or update persistent project settings."""

        values = dict(DEFAULT_SETTINGS if reset else _read_settings(root))
        for key in unsets:
            values.pop(key.upper(), None)
        values.update(_assignments((*items, *sets)))
        if reset or unsets or sets or items:
            _write_settings(root, values)
        _print_settings(values, as_json)

    def _overrides(sets: tuple[str, ...], tool: str | None, force: bool) -> dict[str, str]:
        """Collect one-shot Make-variable overrides."""

        values = _assignments(sets)
        if tool:
            values["LINT_TOOL"] = tool
        if force:
            values["FORCE"] = "1"
        return values

    def _run(
        client: FlexSoC,
        targets: tuple[str, ...],
        *,
        sets: tuple[str, ...],
        tool: str | None,
        force: bool,
        dry_run: bool,
        script: bool,
        capture: bool,
        live: bool,
        as_json: bool,
        info: bool,
    ) -> int:
        """Run, preview, or describe requested targets."""

        if info:
            _print_info(client, targets, as_json)
            return 0

        try:
            values = _overrides(sets, tool, force)
            if live:
                values["LIVE"] = "1"

            result = client.run(
                *targets,
                check=False,
                dry_run=dry_run,
                capture=capture,
                live=live,
                **values,
            )
        except (ValueError, RuntimeError, subprocess.CalledProcessError, typer.BadParameter) as exc:
            error_console.print(f"[red]{exc}[/red]")
            return getattr(exc, "returncode", 2) or 2

        items = list(result)

        if dry_run:
            text = "\n".join(item.shell_line() for item in items)
            if script:
                print("#!/usr/bin/env bash\nset -euo pipefail\n" + text)
            else:
                print(text)
            return 0

        if as_json:
            data = [item.to_dict() for item in items]
            print(json.dumps(data[0] if len(data) == 1 else data, indent=2))
        elif capture:
            print("".join(item.stdout or "" for item in items), end="")
        else:
            for item in items:
                log_path = getattr(item, "log_path", None)
                if log_path:
                    target = getattr(getattr(item, "command", None), "target", "target")
                    console.print(f"[bold bright_cyan]{target}[/bold bright_cyan] log: {log_path}")

        failed = [item for item in items if not item.ok]
        return failed[0].returncode if failed else 0

    def _shell(root: Path, workdir: Path | None) -> int:
        """Open a Prompt Toolkit shell with command completion."""

        try:
            from prompt_toolkit import PromptSession
            from prompt_toolkit.completion import WordCompleter
            from prompt_toolkit.history import FileHistory
        except ModuleNotFoundError:
            console.print("[red]missing dependency: prompt_toolkit[/red]")
            return 2
        history = _settings_path(root).with_name("history")
        history.parent.mkdir(parents=True, exist_ok=True)
        session = PromptSession(
            history=FileHistory(str(history)),
            completer=WordCompleter(_completion_words(), ignore_case=True, sentence=True),
        )
        console.print("[bold cyan]fx shell[/bold cyan]  type 'help', 'commands', 'exit' or Make targets")
        while True:
            try:
                line = session.prompt("fx> ").strip()
            except (EOFError, KeyboardInterrupt):
                console.print()
                return 0
            if not line:
                continue
            if line in {"exit", "quit", ":q"}:
                return 0
            if line in {"help", "?"}:
                _guide()
                continue
            app([*shlex.split(line), *( ["--workdir", str(workdir)] if workdir else [] )])

    # -----------------------------------------------------------------------
    # Typer command and entry point
    # -----------------------------------------------------------------------

    @typer_app.command(name="fx", help=HELP, no_args_is_help=False)
    def _entry(
        items: Annotated[
            list[str] | None,
            typer.Argument(
                help="Pseudo-command (`settings`, `commands`, `shell`) or one or more Make targets.",
                autocompletion=_complete_items,
                show_default=False,
            ),
        ] = None,
        sets: Annotated[
            list[str] | None,
            typer.Option("--set", "-s", help="Add KEY=VALUE override.", rich_help_panel="Settings and overrides"),
        ] = None,
        unsets: Annotated[
            list[str] | None,
            typer.Option("--unset", help="Remove a persistent setting.", rich_help_panel="Settings and overrides"),
        ] = None,
        project_root: Annotated[
            Path | None,
            typer.Option("--project-root", help="Repository root used as Make cwd.", rich_help_panel="Paths"),
        ] = None,
        workdir: Annotated[
            Path | None,
            typer.Option("--workdir", help="Workspace passed to Make as WORKSPACE.", rich_help_panel="Paths"),
        ] = None,
        tool: Annotated[
            str | None,
            typer.Option("--tool", help="Shortcut for LINT_TOOL=VALUE.", rich_help_panel="Target options"),
        ] = None,
        reset: Annotated[
            bool,
            typer.Option("--reset", help="Reset settings before applying updates.", rich_help_panel="Settings and overrides"),
        ] = False,
        force: Annotated[
            bool,
            typer.Option("--force", "--overwrite", help="Shortcut for FORCE=1.", rich_help_panel="Target options"),
        ] = False,
        dry_run: Annotated[
            bool,
            typer.Option("--dry-run", help="Print Make commands without running them.", rich_help_panel="Output"),
        ] = False,
        script: Annotated[
            bool,
            typer.Option("--script", help="Render dry-run output as a bash script.", rich_help_panel="Output"),
        ] = False,
        capture: Annotated[
            bool,
            typer.Option("--capture", help="Capture and print target stdout.", rich_help_panel="Output"),
        ] = False,
        live: Annotated[
            bool,
            typer.Option("--live", help="Stream full tool output to the terminal and keep logs.", rich_help_panel="Output"),
        ] = False,
        as_json: Annotated[
            bool,
            typer.Option("--json", help="Print machine-readable JSON.", rich_help_panel="Output"),
        ] = False,
        info: Annotated[
            bool,
            typer.Option("--info", help="Describe targets instead of running them.", rich_help_panel="Output"),
        ] = False,
    ) -> None:
        """Dispatch pseudo-commands or ordered Make targets."""

        root = (project_root or Path.cwd()).resolve()
        args, set_args, unset_args = tuple(items or ()), tuple(sets or ()), tuple(unsets or ())
        client = FlexSoC(FlexSoCConfig(root, workdir), **_read_settings(root))
        if not args:
            _guide()
            return
        if args[0] == "commands":
            _print_commands(client, as_json)
            return
        if args[0] == "settings":
            _settings(root, args[1:], set_args, unset_args, reset, as_json)
            return
        if args[0] == "shell":
            raise typer.Exit(_shell(root, workdir))
        raise typer.Exit(_run(client, args, sets=set_args, tool=tool, force=force, dry_run=dry_run, script=script, capture=capture, live=live, as_json=as_json, info=info))

    def _click_command() -> click.Command:
        """Build the Click command generated by Typer."""

        return typer.main.get_command(typer_app)

    def app(argv: list[str] | None = None) -> int:
        """Run the fx command-line interface."""

        args = list(sys.argv[1:] if argv is None else argv)
        if args in (["-h"], ["--help"]):
            _guide()
            return 0
        try:
            return _click_command().main(args=args, prog_name="fx", standalone_mode=False) or 0
        except click.exceptions.Exit as exc:
            return int(exc.exit_code or 0)
        except click.ClickException as exc:
            exc.show()
            return int(exc.exit_code or 2)
        except KeyboardInterrupt:
            error_console.print("\n[red]interrupted[/red]")
            return 130

    def main(argv: list[str] | None = None) -> int:
        """Alias app for standard console script names."""

        return app(argv)


if __name__ == "__main__":
    raise SystemExit(app())
