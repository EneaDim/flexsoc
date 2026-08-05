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
    PSEUDO_COMMANDS = ("settings", "commands", "doctor", "pdk", "eqy_debug", "shell")
    OPTION_WORDS = (
        "--set",
        "--unset",
        "--project-root",
        "--workdir",
        "--tool",
        "--user",
        "--system",
        "--profile",
        "--jobs",
        "--reset",
        "--force",
        "--overwrite",
        "--no-setup",
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
                    ("fx doctor", "Check the Python lock and local EDA toolchain."),
                    ("fx pdk list", "List real/open, predictive, and reference PDK profiles."),
                    ("fx pdk use sky130", "Activate one locally usable PDK for synthesis, GLS, EQY and PnR."),
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
                    ("fx regression", "Run every prepared vector test; setup_tb/setup_cocotb remain explicit."),
                    ("fx regression --no-setup", "Run only the regression target when setup steps are already explicit."),
                    ("fx eqy_debug [partition]", "Explain EQY closure, counterexample, and reset-state diagnosis."),
                    ("fx eqy_debug --wave [partition]", "Open the selected counterexample waveform."),
                    ("fx eqy_debug --files [partition]", "List raw EQY/SBY artifacts for the selected partition."),
                ],
            ),
            section(
                "IP development",
                [
                    ("fx setup hjson reg doc rtl_stub lint --force", "Create a fresh IP workspace and run lint."),
                    ("fx setup_model regression --force", "Generate the model and run the full SV+cocotb regression."),
                    ("fx syn", "Generate SDC and synthesis scripts, then run synthesis; add --no-setup for an explicit pipeline."),
                    ("fx ip_flow --force", "Run lint, regression, property formal, synthesis, sign-off equivalence, SDF, STA, power, then reports."),
                    ("fx manifest_show", "Show the saved run identity and tool versions in color."),
                ],
            ),
            section(
                "Clock domains",
                [
                    ("fx settings N_CLOCKS=3 CLOCK_DOMAINS=cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:6:low", "Describe clock/reset domains once for every backend."),
                    ("fx settings CLOCK_RELATIONSHIPS=async:cfg:rx,async:cfg:dsp,async:rx:dsp", "Declare timing relationships explicitly; none are assumed."),
                    ("fx hjson reg doc rtl_stub setup_model setup_tb setup_cocotb --force", "Use the same public targets for one or many clocks."),
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
                    ("--user / --system", "Select rootless user or shared/system dependency mode."),
                    ("--profile base|impl|riscv", "Select the dependency profile."),
                    ("--jobs N", "Set parallel jobs for dependency builds."),
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
        """Print settings grouped by the flow phase they control."""

        if as_json:
            print(json.dumps(dict(values), indent=2))
            return
        groups = (
            ("Run", ("TOP", "RUN_TOP", "RUN_ID", "HOST")),
            ("Clocking", ("N_CLOCKS", "CLOCK_DOMAINS", "CLOCK_RELATIONSHIPS")),
            ("Technology", ("PDK", "PDK_ROOT")),
            ("Verification", ("REG_ITF", "COMPILER", "GLS_SIMULATOR", "WAVE_FORMAT", "TIMING_MODE")),
            ("Paths", ("WORKSPACE", "RUN_ROOT", "SYN_DIR", "EQUIV_DIR", "PNR_DIR")),
        )
        shown: set[str] = set()
        console.print("[bold orange1]FlexSoC settings[/bold orange1]")
        for title, keys in groups:
            rows = [(key, values[key]) for key in keys if key in values]
            if not rows:
                continue
            console.print(f"[bold bright_cyan]{title}[/bold bright_cyan]")
            table = Table(show_header=False, box=None, pad_edge=False)
            table.add_column("Key", style="grey70", no_wrap=True)
            table.add_column("Value", style="white")
            for key, value in rows:
                shown.add(key)
                table.add_row(key, value)
            console.print(table)
        extra = [(key, value) for key, value in sorted(values.items()) if key not in shown]
        if extra:
            console.print("[bold bright_cyan]Advanced[/bold bright_cyan]")
            table = Table(show_header=False, box=None, pad_edge=False)
            table.add_column("Key", style="grey70", no_wrap=True)
            table.add_column("Value", style="white")
            for key, value in extra:
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

    def _settings(root: Path, workdir: Path | None, items: tuple[str, ...], sets: tuple[str, ...], unsets: tuple[str, ...], reset: bool, as_json: bool) -> None:
        """Show or update persistent project settings plus derived run roots."""

        from .run_layout import layout_from_values

        values = dict(DEFAULT_SETTINGS if reset else _read_settings(root))
        for key in unsets:
            values.pop(key.upper(), None)
        updates = _assignments((*items, *sets))
        if "PDK" in updates and "PDK_ROOT" not in updates:
            values.pop("PDK_ROOT", None)
        clock_updates = {"N_CLOCKS", "CLOCK_DOMAINS", "CLOCK_RELATIONSHIPS"} & updates.keys()
        for legacy in ("CLOCK_MODE", "MULTICLOCK", "MULTICLOCK_DOMAINS"):
            values.pop(legacy, None)
        if {"N_CLOCKS", "CLOCK_DOMAINS"} & updates.keys() and "CLOCK_RELATIONSHIPS" not in updates:
            values.pop("CLOCK_RELATIONSHIPS", None)
        values.update(updates)
        if clock_updates:
            from .clocking import clock_config

            values.update(clock_config(values).make_values())
        if reset or unsets or sets or items:
            _write_settings(root, values)
        display = dict(values)
        if workdir is not None:
            display["WORKSPACE"] = str(workdir.expanduser().resolve())
        layout = layout_from_values(root, display)
        display["RUN_ROOT"] = str(layout.run_root)
        display["SYN_DIR"] = str(layout.syn_dir)
        display["EQUIV_DIR"] = str(layout.equivalence_dir)
        display["PNR_DIR"] = str(layout.pnr_dir)
        _print_settings(display, as_json)

    def _pdk(
        root: Path,
        args: tuple[str, ...],
        sets: tuple[str, ...],
        *,
        force: bool,
        as_json: bool,
    ) -> int:
        """List, inspect, fetch, or activate a PDK profile."""

        from .pdk import describe, discover_views, fetch, json_text, list_data, make_overrides, normalize_name

        action = args[0] if args else "list"
        name = args[1] if len(args) > 1 else None
        extra = _assignments(sets)
        pdk_root = extra.get("PDK_ROOT")

        if action == "list":
            data = list_data(root)
            if as_json:
                print(json_text(data))
                return 0
            table = Table(title="FlexSoC PDK catalogue")
            table.add_column("PDK", style="bright_cyan", no_wrap=True)
            table.add_column("Node", no_wrap=True)
            table.add_column("Class")
            table.add_column("ORFS", no_wrap=True)
            table.add_column("Local")
            for item in data:
                views = item["views"]
                state = "ready" if views["usable"] else ("fetched" if Path(views["root"]).exists() else "-")
                table.add_row(str(item["name"]), str(item["node"]), str(item["classification"]), str(item["orfs_platform"]), state)
            console.print(table)
            return 0

        if action not in {"info", "fetch", "use"}:
            raise typer.BadParameter("pdk action must be list, info, fetch, or use")
        if not name:
            raise typer.BadParameter(f"fx pdk {action} requires a PDK name")
        canonical = normalize_name(name)

        if action == "fetch":
            path = fetch(root, canonical, force=force, version=extra.get("PDK_VERSION"))
            data = describe(root, canonical, path)
            if as_json:
                print(json_text(data))
            else:
                console.print(f"[bold orange1]PDK fetched[/bold orange1]: [bright_cyan]{canonical}[/bright_cyan]")
                console.print(f"[white]path[/white]: {path}")
                ready = bool(data["views"]["usable"])
                state = "ready for digital flow" if ready else "source fetched; digital Liberty/Verilog views still need preparation"
                console.print(f"[white]status[/white]: {state}")
            return 0

        data = describe(root, canonical, pdk_root)
        if action == "info":
            if as_json:
                print(json_text(data))
            else:
                views = data["views"]
                console.print(f"[bold orange1]PDK profile[/bold orange1] · [bold bright_cyan]{data['title']}[/bold bright_cyan]")
                for title, rows in (
                    ("Identity", (("Name", canonical), ("Node", data["node"]), ("Class", data["classification"]), ("OpenROAD platform", data["orfs_platform"]))),
                    ("Source / installation", (("Provider", data["fetch_provider"]), ("Source", data["source_url"]), ("Revision", data.get("fetch", {}).get("revision") or "-"), ("Root", views["root"]), ("Status", "ready" if views["usable"] else "not ready"))),
                    ("Digital views", (("Liberty typical", views.get("liberty_typ") or "missing"), ("Liberty slow", views.get("liberty_slow") or "-"), ("Liberty fast", views.get("liberty_fast") or "-"), ("Functional Verilog", f"{len(views['verilog_models'])} model(s)" if views["verilog_models"] else "missing"))),
                ):
                    console.print(f"[bold bright_cyan]{title}[/bold bright_cyan]")
                    table = Table(show_header=False, box=None, pad_edge=False)
                    table.add_column("Field", style="grey70", no_wrap=True)
                    table.add_column("Value", style="white")
                    for key, value in rows:
                        table.add_row(str(key), str(value))
                    console.print(table)
                if data.get("formal_adapter_required"):
                    console.print(f"[grey70]Formal adapter:[/grey70] [white]{data.get('formal_adapter') or 'missing'}[/white]")
                console.print(f"[grey70]{data['note']}[/grey70]")
            return 0

        install = Path(pdk_root).expanduser().resolve() if pdk_root else Path(data["views"]["root"])
        views = discover_views(install, canonical)
        if not views.usable:
            raise typer.BadParameter(
                f"PDK {canonical} is not ready for digital flow under {install}; "
                "need at least a typical Liberty and functional gate-level Verilog model"
            )
        current = _read_settings(root)
        current.update({"PDK": canonical, "PDK_ROOT": str(install)})
        _write_settings(root, current)
        derived = make_overrides(root, canonical, install)
        if as_json:
            print(json_text({"active": canonical, "settings": current, "derived": derived}))
        else:
            console.print(f"[bold orange1]PDK active[/bold orange1]: [bright_cyan]{canonical}[/bright_cyan]")
            console.print(f"[white]root[/white]: {install}")
            console.print(f"[white]Liberty[/white]: {derived.get('LIB_SYN', '-')}")
            console.print(f"[white]OpenROAD[/white]: {derived.get('ORS_TECH', '-')}")
            console.print(
                "[grey70]Shared RTL, DV, formal, and SDC artifacts remain valid. "
                "Rerun setup_syn/syn, setup_eqy/eqy, setup_signoff, SDF/STA/power, "
                "GLS activity power, manifest, metrics, and check.[/grey70]"
            )
        return 0



    def _eqy_debug(
        root: Path,
        workdir: Path | None,
        args: tuple[str, ...],
        sets: tuple[str, ...],
        *,
        as_json: bool,
    ) -> int:
        """Explain one EQY failure; expensive probes target only the selected partition."""

        from .backend.eqy_debug import (
            choose_trace, describe_partition, discover_result_dir, explain_counterexample, open_wave,
            run_reset_normalized_diagnostic, run_synthesis_boundary_diagnostics,
            scan, select, synthesis_boundary_diagnosis,
        )

        settings = _read_settings(root)
        settings.update(_assignments(sets))
        top = settings.get("TOP", "test")
        run_top = settings.get("RUN_TOP") or top
        run_id = settings.get("RUN_ID", "default")
        pdk = settings.get("PDK", DEFAULT_SETTINGS["PDK"])
        workspace = (workdir or Path(settings.get("WORKSPACE", root / "workspace"))).expanduser().resolve()

        values = list(args)
        action = "show"
        if values and values[0] in {"--wave", "wave", "open"}:
            action = "wave"
            values.pop(0)
        elif values and values[0] in {"--files", "files"}:
            action = "files"
            values.pop(0)
        partition = values.pop(0) if values else None
        trace_kind = values.pop(0) if values else "auto"
        if values:
            error_console.print("[red]eqy_debug accepts at most one partition and one trace kind[/red]")
            return 2

        try:
            result_dir = discover_result_dir(root, workspace, top=top, run_top=run_top, run_id=run_id, pdk=pdk)
            rows = scan(result_dir)
        except (FileNotFoundError, ValueError) as exc:
            error_console.print(f"[red]{exc}[/red]")
            return 2

        total = len(rows)
        passed = sum(row.status == "PASS" for row in rows)
        closure = 100.0 * passed / total if total else 0.0
        non_pass = tuple(row for row in rows if row.status != "PASS")
        if not non_pass:
            payload = {"pdk": pdk, "result_dir": str(result_dir), "passed": passed, "total": total, "closure_pct": closure}
            if as_json:
                print(json.dumps(payload, indent=2))
            else:
                console.print(Panel.fit(
                    f"PDK: [white]{pdk}[/white]\n[green]{passed}/{total} partitions proven · {closure:.2f}%[/green]\n[green]EQY PASS[/green]",
                    title="EQY debug", border_style="green",
                ))
            return 0

        try:
            item = select(rows, partition)
        except ValueError as exc:
            if partition is not None:
                error_console.print(f"[red]{exc}[/red]")
                return 2
            if as_json:
                print(json.dumps({"pdk": pdk, "passed": passed, "total": total, "closure_pct": closure,
                                  "counterexamples": [entry.to_dict() for entry in non_pass]}, indent=2))
            else:
                table = Table(title=f"EQY debug · {passed}/{total} PASS · {closure:.2f}%",
                              header_style="bold grey70", border_style="grey50")
                table.add_column("Partition", style="white")
                table.add_column("Status")
                table.add_column("Strategy", style="grey70")
                max_rows = 24
                for entry in non_pass[:max_rows]:
                    strategy = entry.failing_strategy
                    color = "red" if entry.status == "FAIL" else "orange1"
                    table.add_row(entry.partition, f"[{color}]{entry.status}[/{color}]", strategy.name if strategy else "-")
                console.print(table)
                hidden = len(non_pass) - max_rows
                if hidden > 0:
                    console.print(
                        f"[grey70]Showing {max_rows}/{len(non_pass)} non-PASS partitions; "
                        f"{hidden} omitted. Use[/grey70] [white]fx eqy_debug --json[/white] [grey70]for the complete list.[/grey70]"
                    )
                console.print("[grey70]Select one:[/grey70] [white]fx eqy_debug <partition>[/white]")
            return 0

        strategy = item.failing_strategy
        if strategy is None:
            error_console.print(
                f"[red]partition {item.partition} has no failing strategy[/red]"
            )
            return 2
        if action == "files":
            files = (*strategy.traces, *strategy.logs)
            if as_json:
                print(json.dumps({"partition": item.partition, "strategy": strategy.name,
                                  "directory": str(strategy.directory), "files": [str(path) for path in files]}, indent=2))
            else:
                console.print(f"[orange1]{item.partition}[/orange1] · [white]{strategy.name}[/white]")
                console.print(f"[grey70]directory:[/grey70] [white]{strategy.directory}[/white]")
                for path in files:
                    console.print(f"  [white]{path}[/white]")
            return 0
        if action == "wave":
            try:
                trace = choose_trace(strategy, trace_kind)
                viewer = settings.get("WAVE_VIEWER", "gtkwave")
                session, _ = open_wave(trace, item.partition, viewer=viewer)
            except (FileNotFoundError, ValueError, OSError) as exc:
                error_console.print(f"[red]{exc}[/red]")
                return 2
            if as_json:
                print(json.dumps({"partition": item.partition, "trace": str(trace), "viewer": viewer,
                                  "session": str(session) if session else None}, indent=2))
            else:
                console.print(f"[orange1][eqy_debug][/orange1] waveform · [white]{item.partition}[/white]")
                console.print(f"[grey70]trace:[/grey70] [white]{trace}[/white]")
                console.print(f"[grey70]viewer:[/grey70] [white]{viewer}[/white]")
            return 0

        try:
            explanation = explain_counterexample(item)
        except (FileNotFoundError, ValueError, OSError) as exc:
            error_console.print(f"[red]{exc}[/red]")
            return 2

        if not as_json:
            console.print(Panel.fit(
                f"PDK: [white]{pdk}[/white]\n[white]{passed}/{total} partitions proven[/white] · [orange1]{closure:.2f}%[/orange1]\n"
                f"partition: [white]{item.partition}[/white]\nstatus: [red]{item.status}[/red] · strategy: [white]{strategy.name}[/white]",
                title="EQY debug", border_style="orange1",
            ))
            failure = explanation.get("failure") or {}
            divergence = explanation.get("first_divergence")
            facts = Table(title="Counterexample", header_style="bold grey70", border_style="grey50")
            facts.add_column("Field", style="grey70")
            facts.add_column("Value", style="white")
            phase = failure.get("phase") or "unknown"
            step = failure.get("step")
            facts.add_row("Proof", phase + (f" · step {step}" if step is not None else ""))
            facts.add_row("Class", str(explanation.get("classification", "unclassified")))
            decoded = describe_partition(item.partition)
            if decoded:
                facts.add_row("Signal", decoded)
            if divergence:
                facts.add_row("First divergence", f"t={divergence.get('time')}")
                facts.add_row("Gold", f"{divergence.get('gold_signal')} = {divergence.get('gold')}")
                facts.add_row("Gate", f"{divergence.get('gate_signal')} = {divergence.get('gate')}")
                if divergence.get("gold_x_signal"):
                    facts.add_row("X masks", f"gold={divergence.get('gold_x')} · gate={divergence.get('gate_x')}")
            console.print(facts)

        clock = settings.get("EQY_CLOCK", "clk_i").strip() or "clk_i"
        reset = settings.get("EQY_RESET", "rst_ni").strip() or "rst_ni"
        reset_active = settings.get("EQY_RESET_ACTIVE", "low").strip().lower() or "low"
        explicit_reset = any(key in settings for key in ("EQY_CLOCK", "EQY_RESET", "EQY_RESET_ACTIVE"))
        reset_domains = None
        if not explicit_reset:
            try:
                from .clocking import clock_config
                reset_domains = tuple(
                    (domain.signal, domain.reset, domain.reset_polarity)
                    for domain in clock_config(settings).domains
                )
            except (TypeError, ValueError):
                reset_domains = None
        try:
            reset_cycles = int(settings.get("EQY_RESET_CYCLES", "1"))
        except ValueError:
            reset_cycles = 1
        eqy = str(settings.get("EQY", "eqy"))

        if not as_json:
            console.print(f"[bold orange1][eqy_debug][/bold orange1] reset-state probe · [bright_cyan]{item.partition}[/bright_cyan]")
        try:
            reset_probe = run_reset_normalized_diagnostic(
                result_dir, partition=item.partition, clock=clock, reset=reset,
                reset_active=reset_active, reset_cycles=reset_cycles, eqy=eqy,
                domains=reset_domains,
            )
        except (FileNotFoundError, ValueError, RuntimeError, OSError) as exc:
            reset_probe = {"valid": False, "error": str(exc)}
        if not as_json:
            if reset_probe.get("valid"):
                status = str(reset_probe.get("status", "UNKNOWN"))
                color = "green" if status == "PASS" else "red" if status == "FAIL" else "orange1"
                cached = " · cached" if reset_probe.get("cached") else ""
                console.print(f"  [{color}]{status}[/{color}]{cached}")
            else:
                console.print("  [orange1]INCONCLUSIVE[/orange1]")

        synthesis_probe: dict[str, object] | None = None
        if reset_probe.get("valid") and reset_probe.get("status") != "PASS":
            from .run_layout import pdk_run_layout, run_root
            layout = pdk_run_layout(run_root(workspace, run_top=run_top, run_id=run_id), pdk=pdk, top=top)
            def progress(stage: str) -> None:
                if not as_json:
                    labels = {
                        "generic": "generic synthesis",
                        "dffmap": "after dfflibmap",
                        "abc": "after ABC",
                        "clean": "after final cleanup",
                    }
                    console.print(f"[bold orange1][eqy_debug][/bold orange1] {labels.get(stage, stage)} · [bright_cyan]{item.partition}[/bright_cyan]")
            synthesis_probe = run_synthesis_boundary_diagnostics(
                result_dir, top=top, syn_dir=layout.syn_dir, partition=item.partition,
                eqy=eqy, progress=progress,
            )
            if not as_json:
                for stage_name in ("generic", "dffmap", "abc", "clean"):
                    stage = (synthesis_probe.get("stages") or {}).get(stage_name, {})
                    if stage.get("valid"):
                        status = str(stage.get("status", "UNKNOWN"))
                        color = (
                            "green"
                            if status == "PASS"
                            else "red" if status == "FAIL" else "orange1"
                        )
                        cached = " · cached" if stage.get("cached") else ""
                        console.print(f"  [{color}]{status}[/{color}]{cached}")

        payload = {"pdk": pdk, "result_dir": str(result_dir), "passed": passed, "total": total,
                   "closure_pct": closure, "counterexample": explanation,
                   "reset_probe": reset_probe, "synthesis_probe": synthesis_probe}
        if as_json:
            print(json.dumps(payload, indent=2))
            return 0

        probe = Table(title="Targeted probes", header_style="bold grey70", border_style="grey50")
        probe.add_column("Boundary", style="white")
        probe.add_column("Selected partition", style="white")
        probe.add_row("mapped baseline", f"[red]{item.status}[/red]")
        if reset_probe.get("valid"):
            rs = str(reset_probe.get("status", "UNKNOWN"))
            rc = (
                "green"
                if rs == "PASS"
                else "red" if rs == "FAIL" else "orange1"
            )
            probe.add_row("after reset", f"[{rc}]{rs}[/{rc}]")
        else:
            probe.add_row("after reset", "[orange1]inconclusive[/orange1]")
        stages = (synthesis_probe or {}).get("stages", {}) if synthesis_probe else {}
        for key, label in (
            ("generic", "generic synthesis"),
            ("dffmap", "after dfflibmap"),
            ("abc", "after ABC"),
            ("clean", "after final cleanup"),
        ):
            stage = stages.get(key, {}) if isinstance(stages, dict) else {}
            if stage.get("valid"):
                ss = str(stage.get("status", "UNKNOWN"))
                sc = (
                    "green"
                    if ss == "PASS"
                    else "red" if ss == "FAIL" else "orange1"
                )
                probe.add_row(label, f"[{sc}]{ss}[/{sc}]")
            elif stage.get("missing"):
                probe.add_row(label, "[grey70]checkpoint missing[/grey70]")
        console.print(probe)

        if reset_probe.get("status") == "PASS":
            console.print("[orange1]Diagnosis:[/orange1] [white]mismatch disappears after deterministic reset initialization.[/white]")
        elif synthesis_probe:
            diagnosis = synthesis_boundary_diagnosis(stages if isinstance(stages, dict) else {})
            messages = {
                "missing": "synthesis checkpoints missing; run `fx syn --force`, `fx eqy --force`, then `fx eqy_debug`.",
                "generic_fail": "mismatch already exists after generic Yosys synthesis, before technology mapping.",
                "dffmap_fail": "generic synthesis passes; mismatch appears across dfflibmap/sequential mapping.",
                "abc_fail": "dfflibmap passes; mismatch is introduced by ABC combinational technology mapping.",
                "clean_fail": "ABC mapping passes but the cleanup checkpoint fails. Because cleanup is function-preserving, suspect loss of EQY match-points/names rather than a logic change; keep public names during final cleanup.",
                "serialization": "all RTLIL checkpoints pass; mismatch appears only after final Verilog serialization/readback in the EQY gate flow.",
            }
            message = messages.get(
                diagnosis,
                "synthesis-boundary probe is inconclusive; UNKNOWN and TIMEOUT are not evidence of a logic mismatch.",
            )
            console.print(f"[orange1]Diagnosis:[/orange1] [white]{message}[/white]")
        else:
            console.print("[orange1]Diagnosis:[/orange1] [white]reset probe inconclusive; inspect its log before synthesis-boundary attribution.[/white]")
        console.print(f"[grey70]Waveform:[/grey70] [white]fx eqy_debug --wave {item.partition}[/white]")
        console.print(f"[grey70]Artifacts:[/grey70] [white]fx eqy_debug --files {item.partition}[/white]")
        return 0

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
        no_setup: bool,
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
                auto_setup=not no_setup,
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
        deps_user: Annotated[
            bool,
            typer.Option("--user", help="Use rootless user dependency mode.", rich_help_panel="Dependency tooling"),
        ] = False,
        deps_system: Annotated[
            bool,
            typer.Option("--system", help="Use shared/system dependency mode.", rich_help_panel="Dependency tooling"),
        ] = False,
        deps_profile: Annotated[
            str | None,
            typer.Option("--profile", help="Dependency profile: base, impl, or riscv.", rich_help_panel="Dependency tooling"),
        ] = None,
        deps_jobs: Annotated[
            int | None,
            typer.Option("--jobs", help="Parallel dependency build jobs.", rich_help_panel="Dependency tooling"),
        ] = None,
        reset: Annotated[
            bool,
            typer.Option("--reset", help="Reset settings before applying updates.", rich_help_panel="Settings and overrides"),
        ] = False,
        force: Annotated[
            bool,
            typer.Option("--force", "--overwrite", help="Shortcut for FORCE=1.", rich_help_panel="Target options"),
        ] = False,
        no_setup: Annotated[
            bool,
            typer.Option(
                "--no-setup",
                help="Run only the requested targets; do not prepend generated-script setup steps.",
                rich_help_panel="Target options",
            ),
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
            typer.Option("--live", help="Show generated scripts and the command log while retaining a plain log file.", rich_help_panel="Output"),
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
        if deps_user and deps_system:
            raise click.BadParameter("choose only one of --user or --system")
        if deps_profile is not None and deps_profile not in {"base", "impl", "riscv"}:
            raise click.BadParameter("--profile must be base, impl, or riscv")
        if deps_jobs is not None and deps_jobs < 1:
            raise click.BadParameter("--jobs must be a positive integer")
        if deps_user or deps_system or deps_profile is not None or deps_jobs is not None:
            dep_targets = {"deps-bootstrap", "deps", "deps-doctor", "deps-versions", "deps-env", "deps-status", "deps-prune"}
            if not args or any(arg not in dep_targets for arg in args):
                raise click.BadParameter("--user/--system/--profile/--jobs are only valid for dependency targets")
            dep_sets = []
            if deps_user:
                dep_sets.append("DEPS_MODE=user")
            if deps_system:
                dep_sets.append("DEPS_MODE=system")
            if deps_profile is not None:
                dep_sets.append(f"DEPS_PROFILE={deps_profile}")
            if deps_jobs is not None:
                dep_sets.append(f"DEPS_JOBS={deps_jobs}")
            set_args = (*set_args, *dep_sets)
        client = FlexSoC(FlexSoCConfig(root, workdir), **_read_settings(root))
        if not args:
            _guide()
            return
        if args[0] == "commands":
            _print_commands(client, as_json)
            return
        if args[0] == "settings":
            _settings(root, workdir, args[1:], set_args, unset_args, reset, as_json)
            return
        if args[0] == "doctor":
            from .doctor import run as run_doctor

            raise typer.Exit(run_doctor(root, as_json=as_json))
        if args[0] == "pdk":
            raise typer.Exit(_pdk(root, args[1:], set_args, force=force, as_json=as_json))
        if args[0] == "eqy_debug":
            raise typer.Exit(_eqy_debug(root, workdir, args[1:], set_args, as_json=as_json))
        if args[0] == "shell":
            raise typer.Exit(_shell(root, workdir))
        raise typer.Exit(
            _run(
                client,
                args,
                sets=set_args,
                tool=tool,
                force=force,
                dry_run=dry_run,
                script=script,
                capture=capture,
                live=live,
                as_json=as_json,
                info=info,
                no_setup=no_setup,
            )
        )

    def _click_command() -> click.Command:
        """Build the Click command generated by Typer."""

        return typer.main.get_command(typer_app)

    def app(argv: list[str] | None = None) -> int:
        """Run the fx command-line interface."""

        args = list(sys.argv[1:] if argv is None else argv)
        if "eqy_debug" in args:
            index = args.index("eqy_debug")
            args[index + 1:] = [
                token[2:] if token in {"--wave", "--files"} else token
                for token in args[index + 1:]
            ]
        if args in (["-h"], ["--help"]):
            _guide()
            return 0
        try:
            return _click_command().main(args=args, prog_name="fx", standalone_mode=False) or 0
        except click.exceptions.Exit as exc:
            return int(exc.exit_code or 0)
        except (click.ClickException, typer.BadParameter) as exc:
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
