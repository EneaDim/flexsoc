"""Canonical authored SDC timing intent shared by FlexSoC backends."""

from __future__ import annotations

import re
from dataclasses import dataclass, replace
from pathlib import Path

from flexsoc.backend.core import ClockConfig, ClockDomain, ClockRelationship


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


def render_sdc_scaffold(
    top: str,
    clocks: ClockConfig,
    *,
    io_delay_pct: float = 0.2,
    output_load: float = 0.01,
) -> str:
    """Render one readable authored SDC scaffold from bootstrap clock/reset settings."""

    if not 0.0 <= io_delay_pct <= 1.0:
        raise ValueError("SDC_IO_DELAY_PCT must be between 0 and 1")
    if output_load < 0.0:
        raise ValueError("SDC output load must be non-negative")

    by_name = {domain.name: domain for domain in clocks.domains}
    generated = {rel.target: rel for rel in clocks.relationships if rel.kind == "generated"}
    lines = [
        "# FlexSoC canonical design timing intent.",
        "# Authored after first generation: edit this file, then validate it through the flows.",
        f"current_design {top}",
        "",
        "# ============================================================",
        "# 1. CLOCKS",
        "# ============================================================",
    ]
    for domain in clocks.domains:
        relation = generated.get(domain.name)
        if relation:
            source = by_name[relation.source]
            lines.append(
                f"create_generated_clock -name {domain.name} -source [get_ports {source.signal}] "
                f"-divide_by {relation.divide_by} [get_ports {domain.signal}]"
            )
        else:
            fall = domain.fall_ns if domain.fall_ns is not None else domain.period_ns / 2.0
            lines.append(
                f"create_clock -name {domain.name} -period {domain.period_ns:g} "
                f"-waveform {{{domain.rise_ns:g} {fall:g}}} [get_ports {domain.signal}]"
            )

    lines += [
        "",
        "# ============================================================",
        "# 2. GENERATED CLOCKS",
        "# ============================================================",
        "# Add generated clocks here when they are architectural timing intent.",
        "# Example:",
        "# create_generated_clock -name divided_clk -source [get_ports clk_i] -divide_by 2 [get_pins u_div/clk_o]",
        "",
        "# ============================================================",
        "# 3. CLOCK QUALITY / ENVIRONMENT",
        "# ============================================================",
    ]
    for domain in clocks.domains:
        lines += [
            f"set_clock_latency -source {domain.source_latency_ns:g} [get_clocks {domain.name}]",
            f"set_clock_uncertainty -setup {domain.setup_uncertainty_ns:g} [get_clocks {domain.name}]",
            f"set_clock_uncertainty -hold {domain.hold_uncertainty_ns:g} [get_clocks {domain.name}]",
            f"set_clock_transition {domain.transition_ns:g} [get_clocks {domain.name}]",
        ]

    lines += [
        "",
        "# ============================================================",
        "# 4. CLOCK RELATIONSHIPS",
        "# ============================================================",
    ]
    async_rel = [rel for rel in clocks.relationships if rel.kind == "async"]
    if async_rel:
        for rel in async_rel:
            lines.append(
                f"set_clock_groups -asynchronous -group [get_clocks {rel.source}] -group [get_clocks {rel.target}]"
            )
    else:
        lines.append("# Clocks not declared asynchronous are treated as timing-related.")

    lines += [
        "",
        "# ============================================================",
        "# 5. INPUT TIMING",
        "# ============================================================",
    ]
    if clocks.n_clocks == 1:
        clock = clocks.domains[0]
        delay = clock.period_ns * io_delay_pct
        lines += [
            "set non_clock_inputs [all_inputs -no_clocks]",
            f"set_input_delay -max {delay:g} -clock {clock.name} $non_clock_inputs",
            f"set_input_delay -min 0.0 -clock {clock.name} $non_clock_inputs",
        ]
    else:
        lines.append("# Multi-clock input delays are interface-specific; add them explicitly here.")

    lines += [
        "",
        "# ============================================================",
        "# 6. INPUT DRIVE",
        "# ============================================================",
        "set_drive 0.1 [all_inputs -no_clocks]",
        "# If the external driver is a known library cell, replace set_drive with:",
        "# set_driving_cell -lib_cell <driver_cell> -pin <output_pin> [all_inputs -no_clocks]",
        "",
        "# ============================================================",
        "# 7. OUTPUT TIMING",
        "# ============================================================",
    ]
    if clocks.n_clocks == 1:
        clock = clocks.domains[0]
        delay = clock.period_ns * io_delay_pct
        lines += [
            f"set_output_delay -max {delay:g} -clock {clock.name} [all_outputs]",
            f"set_output_delay -min 0.0 -clock {clock.name} [all_outputs]",
        ]
    else:
        lines.append("# Multi-clock output delays are interface-specific; add them explicitly here.")

    lines += [
        "",
        "# ============================================================",
        "# 8. OUTPUT LOAD",
        "# ============================================================",
        f"set_load {output_load:g} [all_outputs]",
        "",
        "# ============================================================",
        "# 9. TIMING EXCEPTIONS",
        "# ============================================================",
        "# False paths and multicycle paths are architectural intent and are never inferred.",
        "# Example false path:",
        "# set_false_path -from <startpoints> -to <endpoints>",
        "# Example multicycle path pair:",
        "# set_multicycle_path 2 -setup -from <startpoints> -to <endpoints>",
        "# set_multicycle_path 1 -hold  -from <startpoints> -to <endpoints>",
        "",
        "# ============================================================",
        "# 10. OPTIONAL DESIGN-RULE CONSTRAINTS",
        "# ============================================================",
        "# Enable only when these limits are part of the intended interface/technology contract.",
        "# set_max_transition <value> [current_design]",
        "# set_max_fanout <value> [current_design]",
        "# set_max_capacitance <value> [all_outputs]",
        "",
    ]
    return "\n".join(lines)


def write_sdc(path: Path, text: str, *, force: bool = False) -> Path:
    """Write the authored SDC once unless explicit regeneration was requested."""

    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists() and not force:
        raise FileExistsError(f"SDC already exists: {path}; use --force to regenerate it")
    path.write_text(text, encoding="utf-8")
    return path.resolve()


def init_sdc(
    path: Path,
    *,
    top: str,
    clocks: ClockConfig,
    io_delay_pct: float = 0.2,
    force: bool = False,
) -> Path:
    """Initialize the single canonical authored ``<top>.sdc``."""

    return write_sdc(
        path,
        render_sdc_scaffold(top, clocks, io_delay_pct=io_delay_pct),
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
