"""Canonical authored SDC timing intent shared by FlexSoC backends."""

from __future__ import annotations

import re
from dataclasses import dataclass, replace
from pathlib import Path

from flexsoc.backend.core import ClockConfig, ClockDomain, ClockRelationship
from flexsoc.backend.core.templates import templates
from flexsoc.backend.design.rtl import parse_ports


@dataclass(frozen=True, slots=True)
class SdcIoEnvironment:
    """Small I/O environment view needed by non-STA consumers."""

    drive: float | None = None
    driving_cell: str | None = None
    load: float | None = None


def _commands(text: str) -> tuple[str, ...]:
    """Return active SDC commands with line continuations folded."""

    commands: list[str] = []
    current = ""
    for raw in text.splitlines():
        line = raw.split("#", 1)[0].strip()
        if not line:
            continue
        continued = line.endswith("\\")
        if continued:
            line = line[:-1].rstrip()
        current = f"{current} {line}".strip()
        if not continued:
            commands.append(current)
            current = ""
    if current:
        commands.append(current)
    return tuple(commands)


def _float_option(command: str, option: str) -> float | None:
    match = re.search(rf"(?:^|\s){re.escape(option)}\s+([-+0-9.eE]+)(?:\s|$)", command)
    return float(match.group(1)) if match else None


def _clock_name(command: str) -> str | None:
    match = re.search(r"\[get_clocks\s+([^\]\s]+)\]", command)
    return match.group(1) if match else None


def _port_name(command: str) -> str | None:
    matches = re.findall(r"\[get_ports\s+([^\]\s]+)\]", command)
    return matches[-1] if matches else None


@dataclass(frozen=True, slots=True)
class SdcIoGroup:
    """I/O ports timed against one declared clock domain."""

    clock: str
    inputs: tuple[str, ...] = ()
    outputs: tuple[str, ...] = ()


def infer_io_groups(top_file: Path, clocks: ClockConfig) -> tuple[tuple[SdcIoGroup, ...], tuple[str, ...]]:
    """Infer scaffold I/O ownership from ``<clock-domain>_`` port prefixes.

    FlexSoC multi-clock wrappers already use the clock-domain name as the
    prefix for domain-owned ports and register windows. Ports that do not
    follow that contract are deliberately left unassigned for the user to
    constrain in the authored SDC.
    """

    path = Path(top_file)
    if not path.is_file():
        return (), ()

    controls = {item for domain in clocks.domains for item in (domain.signal, domain.reset)}
    grouped = {domain.name: {"input": [], "output": []} for domain in clocks.domains}
    unassigned: list[str] = []

    for port in parse_ports(path):
        if port.name in controls:
            continue
        matches = [domain.name for domain in clocks.domains if port.name.startswith(f"{domain.name}_")]
        if len(matches) != 1:
            unassigned.append(port.name)
            continue
        grouped[matches[0]][port.direction].append(port.name)

    groups = tuple(
        SdcIoGroup(
            domain.name,
            tuple(grouped[domain.name]["input"]),
            tuple(grouped[domain.name]["output"]),
        )
        for domain in clocks.domains
        if grouped[domain.name]["input"] or grouped[domain.name]["output"]
    )
    return groups, tuple(unassigned)


def _clock_lines(clocks: ClockConfig) -> tuple[str, ...]:
    by_name = {domain.name: domain for domain in clocks.domains}
    generated = {rel.target: rel for rel in clocks.relationships if rel.kind == "generated"}
    lines: list[str] = []
    for domain in clocks.domains:
        relation = generated.get(domain.name)
        if relation:
            source = by_name[relation.source]
            lines.append(
                f"create_generated_clock -name {domain.name} -source [get_ports {source.signal}] "
                f"-divide_by {relation.divide_by} [get_ports {domain.signal}]"
            )
            continue
        fall = domain.fall_ns if domain.fall_ns is not None else domain.period_ns / 2.0
        lines.append(
            f"create_clock -name {domain.name} -period {domain.period_ns:g} "
            f"-waveform {{{domain.rise_ns:g} {fall:g}}} [get_ports {domain.signal}]"
        )
    return tuple(lines)


def _clock_quality_lines(clocks: ClockConfig) -> tuple[str, ...]:
    return tuple(
        line
        for domain in clocks.domains
        for line in (
            f"set_clock_latency -source {domain.source_latency_ns:g} [get_clocks {domain.name}]",
            f"set_clock_uncertainty -setup {domain.setup_uncertainty_ns:g} [get_clocks {domain.name}]",
            f"set_clock_uncertainty -hold {domain.hold_uncertainty_ns:g} [get_clocks {domain.name}]",
            f"set_clock_transition {domain.transition_ns:g} [get_clocks {domain.name}]",
        )
    )


def _relationship_lines(clocks: ClockConfig) -> tuple[str, ...]:
    async_rel = [rel for rel in clocks.relationships if rel.kind == "async"]
    if not async_rel:
        return ("# Clocks not declared asynchronous are treated as timing-related.",)
    return tuple(
        f"set_clock_groups -asynchronous -group [get_clocks {rel.source}] -group [get_clocks {rel.target}]"
        for rel in async_rel
    )


def _io_timing_lines(
    clocks: ClockConfig,
    groups: tuple[SdcIoGroup, ...],
    unassigned: tuple[str, ...],
    io_delay_pct: float,
    *,
    direction: str,
) -> tuple[str, ...]:
    if clocks.n_clocks == 1:
        clock = clocks.domains[0]
        delay = clock.period_ns * io_delay_pct
        ports = "$non_clock_inputs" if direction == "input" else "[all_outputs]"
        prefix = ("set non_clock_inputs [all_inputs -no_clocks]",) if direction == "input" else ()
        return (*prefix,
            f"set_{direction}_delay -max {delay:g} -clock {clock.name} {ports}",
            f"set_{direction}_delay -min 0.0 -clock {clock.name} {ports}",
        )

    by_clock = {group.clock: group for group in groups}
    lines: list[str] = []
    for domain in clocks.domains:
        group = by_clock.get(domain.name)
        names = getattr(group, f"{direction}s") if group else ()
        if not names:
            continue
        delay = domain.period_ns * io_delay_pct
        ports = " ".join(names)
        lines += [
            f"set_{direction}_delay -max {delay:g} -clock {domain.name} [get_ports {{{ports}}}]",
            f"set_{direction}_delay -min 0.0 -clock {domain.name} [get_ports {{{ports}}}]",
        ]

    if not lines:
        label = "I/O" if direction == "input" else "output"
        lines += [
            f"# Multi-clock {label} timing is interface-specific and must be authored explicitly.",
            "# Example:",
            f"# set_{direction}_delay -max <delay> -clock <clock> [get_ports {{<{direction}_port> ...}}]",
            f"# set_{direction}_delay -min 0.0     -clock <clock> [get_ports {{<{direction}_port> ...}}]",
        ]
    if unassigned:
        lines.append(f"# Unassigned non-clock ports: {' '.join(unassigned)}")
    return tuple(lines)


def _functional_mode_lines(clocks: ClockConfig) -> tuple[str, ...]:
    if not clocks.multiclock:
        return ("# No additional functional-mode controls are required by the single-clock scaffold.",)

    reset_ports: dict[int, list[str]] = {0: [], 1: []}
    for domain in clocks.domains:
        deasserted = 1 if domain.reset_polarity == "low" else 0
        reset_ports[deasserted].append(domain.reset)
    lines = [
        "# External resets assert asynchronously; functional STA holds them deasserted.",
        "# Generated RTL synchronizes reset release per clock domain; RDC qualifies that structure.",
    ]
    for value in (1, 0):
        ports = reset_ports[value]
        if ports:
            lines.append(f"set_case_analysis {value} [get_ports {{{' '.join(ports)}}}]")
    return tuple(lines)


def render_sdc_scaffold(
    top: str,
    clocks: ClockConfig,
    *,
    io_delay_pct: float = 0.2,
    output_load: float = 0.01,
    io_groups: tuple[SdcIoGroup, ...] = (),
    unassigned_ports: tuple[str, ...] = (),
) -> str:
    """Render one editable SDC from clock metadata and inferred I/O ownership."""

    if not 0.0 <= io_delay_pct <= 1.0:
        raise ValueError("SDC_IO_DELAY_PCT must be between 0 and 1")
    if output_load < 0.0:
        raise ValueError("SDC output load must be non-negative")

    return templates.render(
        "signoff/sdc/design.sdc.j2",
        top=top,
        clock_lines=_clock_lines(clocks),
        clock_quality_lines=_clock_quality_lines(clocks),
        relationship_lines=_relationship_lines(clocks),
        input_timing_lines=_io_timing_lines(
            clocks, io_groups, unassigned_ports, io_delay_pct, direction="input"
        ),
        output_timing_lines=_io_timing_lines(
            clocks, io_groups, unassigned_ports, io_delay_pct, direction="output"
        ),
        functional_mode_lines=_functional_mode_lines(clocks),
        output_load=f"{output_load:g}",
    )


def write_sdc(path: Path, text: str, *, force: bool = False) -> Path:
    """Write the authored SDC, preserving existing user edits unless forced."""

    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists() and not force:
        return path.resolve()
    path.write_text(text, encoding="utf-8")
    return path.resolve()


def init_sdc(
    path: Path,
    *,
    top: str,
    clocks: ClockConfig,
    top_file: Path | None = None,
    io_delay_pct: float = 0.2,
    force: bool = False,
) -> Path:
    """Initialize the single canonical authored ``<top>.sdc``."""

    groups: tuple[SdcIoGroup, ...] = ()
    unassigned: tuple[str, ...] = ()
    if clocks.multiclock and top_file is not None:
        groups, unassigned = infer_io_groups(top_file, clocks)
    return write_sdc(
        path,
        render_sdc_scaffold(
            top,
            clocks,
            io_delay_pct=io_delay_pct,
            io_groups=groups,
            unassigned_ports=unassigned,
        ),
        force=force,
    )


def read_clock_config(path: Path, reset_config: ClockConfig) -> ClockConfig:
    """Read the clock/timing subset shared by TB and CDC while preserving reset metadata."""

    path = Path(path)
    if not path.is_file():
        raise FileNotFoundError(f"canonical SDC not found: {path}; run `fx sdc` first")
    commands = _commands(path.read_text(encoding="utf-8", errors="replace"))
    reset_by_signal = {domain.signal: domain for domain in reset_config.domains}
    reset_by_name = {domain.name: domain for domain in reset_config.domains}
    domains: list[ClockDomain] = []
    generated_commands: list[str] = []

    for command in commands:
        if command.startswith("create_generated_clock "):
            generated_commands.append(command)
            continue
        if not command.startswith("create_clock "):
            continue
        name_match = re.search(r"(?:^|\s)-name\s+([^\s]+)", command)
        period = _float_option(command, "-period")
        signal = _port_name(command)
        if not name_match or period is None or signal is None:
            raise ValueError(f"unsupported create_clock in {path}: {command}")
        name = name_match.group(1)
        wave = re.search(r"-waveform\s+\{\s*([-+0-9.eE]+)\s+([-+0-9.eE]+)\s*\}", command)
        rise = float(wave.group(1)) if wave else 0.0
        fall = float(wave.group(2)) if wave else period / 2.0
        if period <= 0 or rise < 0 or not rise < fall <= period:
            raise ValueError(f"invalid waveform for clock {name!r} in {path}")
        reset = reset_by_signal.get(signal) or reset_by_name.get(name)
        if reset is None:
            raise ValueError(
                f"clock {name!r} on {signal!r} has no reset-domain metadata; "
                "keep CLOCK_DOMAINS only for clock-to-reset ownership/polarity"
            )
        domains.append(
            ClockDomain(
                name, signal, reset.reset, period, reset.reset_polarity,
                rise_ns=rise, fall_ns=fall,
            )
        )

    by_signal = {domain.signal: domain for domain in domains}
    relationships: list[ClockRelationship] = []
    for command in generated_commands:
        name_match = re.search(r"(?:^|\s)-name\s+([^\s]+)", command)
        divide = _float_option(command, "-divide_by")
        ports = re.findall(r"\[get_ports\s+([^\]\s]+)\]", command)
        if not name_match or not ports:
            raise ValueError(f"unsupported create_generated_clock in {path}: {command}")
        target_name = name_match.group(1)
        target_signal = ports[-1]
        source_signal = ports[0] if len(ports) > 1 else None
        source = by_signal.get(source_signal or "")
        reset = reset_by_signal.get(target_signal) or reset_by_name.get(target_name)
        if source is None or reset is None:
            raise ValueError(f"generated clock {target_name!r} cannot be mapped to declared clock/reset metadata")
        divider = int(divide or 1)
        if divider <= 0:
            raise ValueError(f"generated clock {target_name!r} has invalid divide_by={divider}")
        domain = ClockDomain(
            target_name, target_signal, reset.reset, source.period_ns * divider,
            reset.reset_polarity,
        )
        domains.append(domain)
        by_signal[target_signal] = domain
        relationships.append(ClockRelationship("generated", source.name, target_name, divider))

    if not domains:
        raise ValueError(f"no active create_clock commands found in {path}")

    by_name = {domain.name: domain for domain in domains}
    for command in commands:
        name = _clock_name(command)
        if name not in by_name:
            continue
        domain = by_name[name]
        if command.startswith("set_clock_latency "):
            value = _float_option(command, "-source")
            if value is None:
                numbers = re.findall(r"[-+0-9.eE]+", command.split("[get_clocks", 1)[0])
                value = float(numbers[-1]) if numbers else None
            if value is not None:
                by_name[name] = replace(domain, source_latency_ns=value)
        elif command.startswith("set_clock_uncertainty "):
            numbers = re.findall(r"[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?", command.split("[get_clocks", 1)[0])
            if numbers:
                value = float(numbers[-1])
                if "-hold" in command:
                    by_name[name] = replace(domain, hold_uncertainty_ns=value)
                else:
                    by_name[name] = replace(domain, setup_uncertainty_ns=value)
        elif command.startswith("set_clock_transition "):
            numbers = re.findall(r"[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?", command.split("[get_clocks", 1)[0])
            if numbers:
                by_name[name] = replace(domain, transition_ns=float(numbers[-1]))

    for command in commands:
        if not command.startswith("set_clock_groups ") or "-asynchronous" not in command:
            continue
        groups = re.findall(r"-group\s+\[get_clocks\s+([^\]\s]+)\]", command)
        for index, source in enumerate(groups):
            for target in groups[index + 1 :]:
                if source in by_name and target in by_name:
                    relationships.append(ClockRelationship("async", source, target))

    ordered = tuple(by_name[domain.name] for domain in domains)
    return ClockConfig(ordered, tuple(relationships))


def read_io_environment(path: Path) -> SdcIoEnvironment:
    """Extract only drive/load information needed to derive synthesis collateral."""

    drive: float | None = None
    driving_cell: str | None = None
    load: float | None = None
    for command in _commands(Path(path).read_text(encoding="utf-8", errors="replace")):
        if command.startswith("set_drive "):
            match = re.match(r"set_drive\s+([-+0-9.eE]+)", command)
            if match:
                drive = float(match.group(1))
        elif command.startswith("set_driving_cell "):
            match = re.search(r"(?:-lib_cell\s+)?([^\s\[]+)(?:\s|$)", command.removeprefix("set_driving_cell "))
            if match:
                driving_cell = match.group(1)
        elif command.startswith("set_load "):
            match = re.match(r"set_load\s+([-+0-9.eE]+)", command)
            if match:
                load = float(match.group(1))
    return SdcIoEnvironment(drive=drive, driving_cell=driving_cell, load=load)
