from __future__ import annotations

from rich.console import Console
from rich.panel import Panel
from rich.table import Table
from rich.text import Text


def _console() -> Console:
    return Console(stderr=True)


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
    title.append("flexsoc", style="bold orange1")
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
            "[orange1]flexsoc[/orange1] [bold green]q[/bold green] [cyan][/cyan]   Quickstart\n"
            "[orange1]flexsoc[/orange1] [bold green]t[/bold green] [cyan][/cyan]   Tutorials\n"
            "[orange1]flexsoc[/orange1] [bold green]ip[/bold green] [cyan][/cyan]  IP development guide\n"
            "[orange1]flexsoc[/orange1] [bold green]fsm[/bold green] [cyan][/cyan] FSM development guide\n"
            "[orange1]flexsoc[/orange1] [bold green]hd[/bold green] [cyan][/cyan]  Detailed help",
            border_style="green",
        )
    )
    console.print()

    console.print(
        _section_panel(
            "Inspect",
            "[orange1]flexsoc[/orange1] [bold green]runs[/bold green] [cyan]ls[/cyan]    List workspace runs\n"
            "[orange1]flexsoc[/orange1] [bold green]runs[/bold green] [cyan]show[/cyan]  Inspect one run",
            border_style="cyan",
        )
    )
    console.print()

    console.print(
        _section_panel(
            "Explore",
            "[orange1]flexsoc[/orange1] [bold green]actions[/bold green] [cyan][/cyan]       List all actions\n"
            "[orange1]flexsoc[/orange1] [bold green]action[/bold green] [cyan]<name>[/cyan]  Show one action",
            border_style="yellow",
        )
    )
    console.print()

    console.print(
        _section_panel(
            "Next step",
            "[bold yellow]Suggested next step[/bold yellow]\n\n"
            "New user: [orange1]flexsoc[/orange1] [bold green]q[/bold green]\n"
            "Working on an IP: [orange1]flexsoc[/orange1] [bold green]ip[/bold green]\n"
            "Looking for commands: [orange1]flexsoc[/orange1] [bold green]a[/bold green] or [bold green]hd[/bold green]",
            border_style="bright_yellow",
        )
    )


def render_help_overview() -> None:
    console = _console()
    console.print(
        _section_panel(
            "flexsoc help",
            "[orange1]flexsoc[/orange1] [bold green]h[/bold green] [cyan][/cyan]   Compact home help\n"
            "[orange1]flexsoc[/orange1] [bold green]hd[/bold green] [cyan][/cyan]  Detailed colorful help\n"
            "[orange1]flexsoc[/orange1] [bold green]q[/bold green] [cyan][/cyan]   Quickstart\n"
            "[orange1]flexsoc[/orange1] [bold green]t[/bold green] [cyan][/cyan]   Tutorials\n"
            "[orange1]flexsoc[/orange1] [bold green]ip[/bold green] [cyan][/cyan]  IP development guide\n"
            "[orange1]flexsoc[/orange1] [bold green]a[/bold green] [cyan][/cyan]   List actions",
            border_style="bright_blue",
        )
    )


def render_detailed_help() -> None:
    console = _console()

    title = Text()
    title.append("📘 ", style="bold yellow")
    title.append("flexsoc", style="bold orange1")
    title.append(" — Detailed command guide", style="bold white")
    console.print(title)
    console.print()

    console.print(
        _section_panel(
            "What flexsoc is",
            "[orange1]flexsoc[/orange1] is a lightweight framework for:\n\n"
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
    table.add_column("Command", style="white", no_wrap=True)
    table.add_column("Description", style="white")
    table.add_row(
        "[orange1]flexsoc[/orange1] [bold green]run[/bold green] [cyan]<action>[/cyan]",
        "Run a registry-backed high-level action",
    )
    table.add_row(
        "[orange1]flexsoc[/orange1] [bold green]exec[/bold green] [cyan]<plan>[/cyan]",
        "Execute a prepared action plan",
    )
    table.add_row(
        "[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]<target>[/cyan]",
        "Direct Make backend entrypoint",
    )
    table.add_row(
        "[orange1]flexsoc[/orange1] [bold green]actions[/bold green]",
        "List all registered actions",
    )
    table.add_row(
        "[orange1]flexsoc[/orange1] [bold green]action[/bold green] [cyan]<name>[/cyan]",
        "Inspect one action in detail",
    )
    table.add_row(
        "[orange1]flexsoc[/orange1] [bold green]runs[/bold green] [cyan]ls[/cyan]",
        "List runs in the workspace",
    )
    table.add_row(
        "[orange1]flexsoc[/orange1] [bold green]runs[/bold green] [cyan]show --run-top <name> --run-id <id>[/cyan]",
        "Show one run manifest and recent history",
    )
    table.add_row(
        "[orange1]flexsoc[/orange1] [bold green]q[/bold green]",
        "Show the recommended quickstart",
    )
    table.add_row(
        "[orange1]flexsoc[/orange1] [bold green]t[/bold green]",
        "Show tutorial entrypoints",
    )
    table.add_row(
        "[orange1]flexsoc[/orange1] [bold green]ip[/bold green]",
        "Show the IP development lifecycle guide",
    )
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
            "Prefer [orange1]flexsoc[/orange1] [bold green]run[/bold green] for stable high-level workflows.\n"
            "Use [orange1]flexsoc[/orange1] [bold green]make[/bold green] for expert control or raw backend access.\n"
            "Use [bold magenta]run_top = top[/bold magenta] for single-IP work.\n"
            "Use a shared [bold magenta]run_top[/bold magenta] to group multiple IPs for SoC integration.",
            border_style="yellow",
        )
    )

def render_quickstart() -> None:
    c = _console()
    c.print(Panel.fit(
        """[bold]Quickstart[/bold]

[bold]1. Standalone IP flow[/bold]
[orange1]flexsoc[/orange1] [bold green]use[/bold green] [cyan]--ws workspace --run-id dev --run-top gpio --top gpio[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_load[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]flist[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]sim[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]syn[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]sta[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]power[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]driver[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_save --overwrite[/cyan]

[bold]2. SoC with UART host[/bold]
[orange1]flexsoc[/orange1] [bold green]use[/bold green] [cyan]--ws workspace --run-id dev --run-top soc_uart --top soc[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_load --top uart-master --load-as uart[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_load --top gpio[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_load --top rv_timer[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_load --top pwm[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]xbar soc[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]soc_flist setup_tb[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]sim view[/cyan]

[bold]3. SoC with IBEX host[/bold]
[orange1]flexsoc[/orange1] [bold green]use[/bold green] [cyan]--ws workspace --run-id dev --run-top soc_ibex --top soc[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]soc_ibex_fetch[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_load --top uart[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_load --top gpio[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_load --top rv_timer[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_load --top pwm[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_load --top spi_host[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]xbar soc HOST=ibex[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]sw_soc soc_run HOST=ibex[/cyan]""",
        title="Quickstart",
        border_style="blue",
    ))

def render_tutorials() -> None:
    console = _console()
    console.print(
        _section_panel(
            "Tutorials",
            "Full IP workflow tutorials:\n"
            "  [orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]full_tutorial[/cyan]\n\n"
            "IP tutorials:\n"
            "  [orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_tutorial --top cache_wrapper[/cyan]\n"
            "  [orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_tutorial --top fft_core[/cyan]\n"
            "  [orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_tutorial --top spi_host[/cyan]\n"
            "  [orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_tutorial --top pwm_ramp[/cyan]\n\n"
            "FSM tutorial:\n"
            "  [orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]fsm_tutorial --top fsm_example[/cyan]\n\n"
            "SoC tutorials:\n"
            "  [orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]soc_pless[/cyan]\n"
            "  [orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]soc_ibex_tutorial[/cyan]\n\n"
            "Tutorial targets generate complete example runs so you can inspect the "
            "workspace structure, replay the steps manually, and reuse the same flow "
            "for your own IPs and SoCs.",
            border_style="magenta",
        )
    )

def render_ip_guide() -> None:
    c = _console()
    c.print(Panel.fit(
        """[bold]IP flow guide[/bold]
[orange1]flexsoc[/orange1] [bold green]use[/bold green] [cyan]--ws workspace --run-id dev --run-top my_ip --top my_ip[/cyan]
[orange1]flexsoc[/orange1] [bold green]run[/bold green] [cyan]ip_start[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]sim view[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]syn sdf sta power[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]driver fsoc_init[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]ip_save[/cyan]""",
        title="IP flow guide",
        border_style="blue",
    ))

def render_fsm_development_guide() -> None:
    c = _console()
    c.print(Panel.fit(
        """[bold]FSM development guide[/bold]
[orange1]flexsoc[/orange1] [bold green]use[/bold green] [cyan]--ws workspace --run-id dev --run-top my_ip --top my_ip[/cyan]

[dim]# 1) Prepare the IP run workspace[/dim]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]setup[/cyan]

[dim]# 2) Create one FSM workspace inside the IP run[/dim]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]fsm_init[/cyan] [dim]--[/dim] [cyan]FSM=rx_fsm[/cyan]

[dim]# 3) Load an example FSM as a starting point[/dim]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]fsm_example_load[/cyan] [dim]--[/dim] [cyan]FSM=rx_fsm[/cyan]

[dim]# 4) Edit the FSM sources[/dim]
[cyan]workspace/runs/my_ip/dev/fsms/rx_fsm/inputs/rx_fsm.txt[/cyan]
[cyan]workspace/runs/my_ip/dev/fsms/rx_fsm/inputs/rx_fsm.csv[/cyan]

[dim]# 5) Generate FSM artifacts[/dim]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]fsm_gen[/cyan] [dim]--[/dim] [cyan]FSM=rx_fsm[/cyan]

[dim]# 6) Install generated RTL/TB/GTKWave files into the IP run[/dim]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]fsm_install[/cyan] [dim]--[/dim] [cyan]FSM=rx_fsm[/cyan]

[dim]# 7) Simulate only the FSM testbench inside the IP run[/dim]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]flist sim[/cyan] [bold yellow]--top[/bold yellow] [cyan]rx_fsm[/cyan] [dim]--[/dim] [cyan]TESTBENCH=rx_fsm_tb[/cyan]

[dim]# 8) Optional: inspect the graph[/dim]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]fsm_plot[/cyan] [dim]--[/dim] [cyan]FSM=rx_fsm[/cyan]

[dim]# 9) Repeat for more FSMs in the same IP[/dim]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]fsm_init fsm_gen fsm_install[/cyan] [dim]--[/dim] [cyan]FSM=tx_fsm[/cyan]
[orange1]flexsoc[/orange1] [bold green]make[/bold green] [cyan]fsm_init fsm_gen fsm_install[/cyan] [dim]--[/dim] [cyan]FSM=ctrl_fsm[/cyan]""",
        title="FSM development guide",
        border_style="blue",
    ))
