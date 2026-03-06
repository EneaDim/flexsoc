from __future__ import annotations

from rich.console import Console
from rich.panel import Panel
from rich.table import Table
from rich.text import Text


def _console() -> Console:
    return Console()


def _section_panel(title: str, body: str, *, border_style: str) -> Panel:
    return Panel(
        body,
        title=title,
        title_align="left",
        border_style=border_style,
        padding=(0, 1),
    )


def render_home_help() -> None:
    console = _console()

    title = Text()
    title.append("✨ ", style="bold yellow")
    title.append("flexsoc", style="bold bright_cyan")
    title.append(" — Framework for IP development and SoC integration", style="bold white")
    console.print(title)
    console.print()

    console.print(
        _section_panel(
            "Overview",
            "[bold white]Structured hardware development[/bold white] with a "
            "[green]Python CLI[/green], a [yellow]Make-based backend[/yellow], "
            "and [magenta]workspace-based runs[/magenta].\n\n"
            "Use flexsoc for:\n"
            "  • [cyan]IP development[/cyan]\n"
            "  • [magenta]SoC integration[/magenta]\n"
            "  • [green]deterministic project organization[/green]",
            border_style="bright_blue",
        )
    )
    console.print()

    console.print(
        _section_panel(
            "Learn",
            "[bold green]flexsoc q[/bold green]    Quickstart\n"
            "[bold green]flexsoc ip[/bold green]   IP development guide\n"
            "[bold green]flexsoc t[/bold green]    Tutorials\n"
            "[bold green]flexsoc hd[/bold green]   Detailed help",
            border_style="green",
        )
    )
    console.print()

    console.print(
        _section_panel(
            "Inspect",
            "[bold cyan]runs ls[/bold cyan]      List workspace runs\n"
            "[bold cyan]runs show[/bold cyan]    Inspect one run",
            border_style="cyan",
        )
    )
    console.print()

    console.print(
        _section_panel(
            "Explore",
            "[bold yellow]actions[/bold yellow]        List all actions\n"
            "[bold yellow]action <name>[/bold yellow]  Show one action",
            border_style="yellow",
        )
    )
    console.print()

    console.print(
        _section_panel(
            "Next step",
            "[bold yellow]Suggested next step[/bold yellow]\n\n"
            "New user: [bold green]flexsoc q[/bold green]\n"
            "Working on an IP: [bold green]flexsoc ip[/bold green]\n"
            "Looking for commands: [bold green]flexsoc a[/bold green] or [bold green]hd[/bold green]",
            border_style="bright_yellow",
        )
    )


def render_help_overview() -> None:
    console = _console()
    console.print(
        _section_panel(
            "flexsoc help",
            "[bold green]flexsoc h[/bold green]   Compact home help\n"
            "[bold green]flexsoc hd[/bold green]  Detailed colorful help\n"
            "[bold green]flexsoc q[/bold green]   Quickstart\n"
            "[bold green]flexsoc t[/bold green]   Tutorials\n"
            "[bold green]flexsoc ip[/bold green]  IP development guide\n"
            "[bold green]flexsoc a[/bold green]   List actions",
            border_style="bright_blue",
        )
    )


def render_detailed_help() -> None:
    console = _console()

    title = Text()
    title.append("📘 ", style="bold yellow")
    title.append("flexsoc", style="bold bright_cyan")
    title.append(" — Detailed command guide", style="bold white")
    console.print(title)
    console.print()

    console.print(
        _section_panel(
            "What flexsoc is",
            "[cyan]flexsoc[/cyan] is a lightweight framework for:\n\n"
            "  • [green]IP development[/green]\n"
            "  • [magenta]SoC integration[/magenta]\n"
            "  • [yellow]workspace-based reproducible runs[/yellow]\n\n"
            "It stays close to Make and open-source EDA tools while adding a "
            "cleaner CLI and run model.",
            border_style="bright_blue",
        )
    )
    console.print()

    table = Table(
        title="Main command groups",
        title_style="bold magenta",
        header_style="bold yellow",
        show_header=True,
        expand=True,
    )
    table.add_column("Command", style="bold green", no_wrap=True)
    table.add_column("Description", style="white")
    table.add_row("flexsoc run <action>", "Run a registry-backed high-level action")
    table.add_row("flexsoc exec <plan>", "Execute a prepared action plan")
    table.add_row("flexsoc make <target>", "Direct Make backend entrypoint")
    table.add_row("flexsoc actions", "List all registered actions")
    table.add_row("flexsoc action <name>", "Inspect one action in detail")
    table.add_row("flexsoc runs ls", "List runs in the workspace")
    table.add_row("flexsoc runs show --run-top <name> --run-id <id>", "Show one run manifest and recent history")
    table.add_row("flexsoc q", "Show the recommended quickstart")
    table.add_row("flexsoc t", "Show tutorial entrypoints")
    table.add_row("flexsoc ip", "Show the IP development lifecycle guide")
    console.print(table)
    console.print()

    console.print(
        _section_panel(
            "Run model",
            "Each run is identified by:\n\n"
            "  • [bold]workspace[/bold]\n"
            "  • [bold]run_top[/bold]\n"
            "  • [bold]run_id[/bold]\n"
            "  • [bold]top[/bold] for the active command\n\n"
            "Run contents live under:\n"
            "  [green]workspace/runs/<run_top>/<run_id>[/green]\n\n"
            "CLI execution sessions live under:\n"
            "  [yellow]workspace/sessions/<timestamp>_<action>[/yellow]",
            border_style="green",
        )
    )
    console.print()

    console.print(
        _section_panel(
            "Usage guidance",
            "Prefer [bold green]flexsoc run[bold green] for stable high-level workflows.\n"
            "Use [bold cyan]flexsoc make[/bold cyan] for expert control or raw backend access.\n"
            "Use [bold magenta]run_top = top[/bold magenta] for single-IP work.\n"
            "Use a shared [bold magenta]run_top[/bold magenta] to group multiple IPs for SoC integration.",
            border_style="yellow",
        )
    )


def render_quickstart() -> None:
    console = _console()
    console.print(
        _section_panel(
            "Quickstart",
            "Recommended end-to-end IP flow:\n\n"
            "  1. [bold green]flexsoc run ip_start --top my_ip --run-id dev --ws workspace --overwrite[/bold green]\n"
            "  2. [bold green]flexsoc make view --top my_ip --run-id dev --ws workspace --overwrite[/bold green]\n"
            "  3. [bold green]flexsoc make syn --top my_ip --run-id dev --ws workspace --overwrite[/bold green]\n"
            "  4. [bold green]flexsoc make sta --top my_ip --run-id dev --ws workspace --overwrite[/bold green]\n"
            "  5. [bold green]flexsoc make power --top my_ip --run-id dev --ws workspace --overwrite[/bold green]\n"
            "  6. [bold green]flexsoc make pnr --top my_ip --run-id dev --ws workspace --overwrite[/bold green]\n"
            "  7. [bold green]flexsoc make pnr_gui --top my_ip --run-id dev --ws workspace --overwrite[/bold green]\n\n"
            "[bold yellow]Tip:[/bold yellow]\n"
            "Use [bold cyan]--overwrite[/bold cyan] from the beginning while iterating quickly on the same run.",
            border_style="bright_blue",
        )
    )


def render_tutorials() -> None:
    console = _console()
    console.print(
        _section_panel(
            "Tutorials",
            "Full IP workflow tutorials:\n"
            "  [bold green]flexsoc make full_tutorial[/bold green]\n\n"
            "IP tutorials:\n"
            "  [bold green]flexsoc make ip_tutorial --top spi_host[/bold green]\n"
            "  [bold green]flexsoc make ip_tutorial --top pwm_ramp[/bold green]\n\n"
            "FSM tutorial:\n"
            "  [bold green]flexsoc make fsm_tutorial --top fsm_example[/bold green]\n\n"
            "SoC tutorial:\n"
            "  [bold green]flexsoc make soc_pless[/bold green]\n\n"
            "Tutorials generate example workspaces so you can inspect the structure "
            "and reuse the same flow for your own IPs.",
            border_style="magenta",
        )
    )


def render_ip_guide() -> None:
    console = _console()
    console.print(
        _section_panel(
            "IP development guide",
            "This section describes the recommended lifecycle for building a reusable hardware IP using flexsoc.\n\n"
            "[bold]1. HJSON authoring[/bold]\n"
            "  hjson\n"
            "  Generate a starter register/metadata description, then edit it with the real register map.\n\n"
            "[bold]2. Register collateral and docs[/bold]\n"
            "  reg and doc\n"
            "  Generate register RTL / SW artifacts and documentation.\n\n"
            "[bold]3. Stub generation and RTL authoring[/bold]\n"
            "  rtl_stub\n"
            "  Generate the initial RTL stub, then implement the actual IP logic.\n\n"
            "[bold]4. Testbench setup and verification authoring[/bold]\n"
            "  setup_tb\n"
            "  Generate the TB scaffold, then write or extend the verification environment.\n\n"
            "[bold]5. Pre-silicon quality loop[/bold]\n"
            "  lint\n"
            "      Structural / style checking\n"
            "  sim\n"
            "      Functional simulation\n\n"
            "[bold]6. Implementation and signoff[/bold]\n"
            "  syn\n"
            "      Synthesis\n"
            "  sta\n"
            "      Static timing analysis\n"
            "  power\n"
            "      Power estimation\n"
            "  pnr\n"
            "      Place and route\n"
            "  pnr_gui\n"
            "      Interactive GUI flow for debug\n\n"
            "[bold]7. Software / integration helpers[/bold]\n"
            "  driver\n"
            "      Generate software-facing collateral\n"
            "  fsoc_init\n"
            "      Initialize integration material\n"
            "  ip_save\n"
            "      Save or package the resulting IP state",
            border_style="bright_blue",
        )
    )
