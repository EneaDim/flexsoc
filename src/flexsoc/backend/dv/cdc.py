"""Structural CDC/RDC analysis and qualification."""

from __future__ import annotations

from collections import Counter
from dataclasses import asdict, dataclass
import json
import os
from pathlib import Path
import subprocess
import threading
import time
from typing import Any, Callable, Mapping, Sequence, TypeVar

from flexsoc.backend.core import ClockConfig, ClockDomain, clock_config
from flexsoc.backend.core.execution import print_label, print_log, print_script, print_status_label
_T = TypeVar("_T")


# Structural model and shared dependency graph

NetBit = int | str


@dataclass(frozen=True, slots=True)
class PortDomainIntent:
    """Portable interface intent aligned with Accellera CDC/RDC concepts."""

    name: str
    direction: str
    kind: str = "data"
    associated_from_clocks: tuple[str, ...] = ()
    associated_to_clocks: tuple[str, ...] = ()
    reset_polarity: str | None = None


@dataclass(frozen=True, slots=True)
class SequentialElement:
    """One pre-technology sequential element and its clock/reset controls."""

    name: str
    cell_type: str
    clock_bit: NetBit
    clock_domain: str | None
    data_bits: tuple[NetBit, ...]
    q_bits: tuple[NetBit, ...]
    async_reset_bit: NetBit | None = None
    sync_reset_bit: NetBit | None = None
    reset_signal: str | None = None
    reset_polarity: str | None = None
    source: str | None = None


@dataclass(frozen=True, slots=True)
class Endpoint:
    """One bit-level source or sink used by the crossing graph."""

    kind: str
    name: str
    bit_index: int
    clock_domain: str | None = None
    reset_signal: str | None = None


@dataclass(frozen=True, slots=True)
class Crossing:
    """One raw domain crossing before synchronizer/protocol classification."""

    source: Endpoint
    destination: Endpoint
    relationship: str
    path: tuple[str, ...] = ()


@dataclass(frozen=True, slots=True)
class SynchronizerFinding:
    """Structural classification of one CDC crossing as an N-FF synchronizer."""

    crossing: Crossing
    status: str
    classification: str
    stages: tuple[Endpoint, ...]
    issues: tuple[str, ...] = ()


@dataclass(frozen=True, slots=True)
class DomainFinding:
    """One CDC/RDC/setup/glitch result with structural evidence and obligations."""

    scope: str
    status: str
    classification: str
    crossings: tuple[Crossing, ...] = ()
    issues: tuple[str, ...] = ()
    obligations: tuple[str, ...] = ()
    evidence: tuple[str, ...] = ()
    primary: bool = True


@dataclass(frozen=True, slots=True)
class ComprehensiveAnalysis:
    """Classification views layered on the shared structural dependency graph."""

    cdc: tuple[DomainFinding, ...]
    rdc: tuple[DomainFinding, ...]
    setup: tuple[DomainFinding, ...]
    glitch: tuple[DomainFinding, ...]


@dataclass(frozen=True, slots=True)
class DesignIR:
    """Technology-neutral connectivity and domain information for one top."""

    top: str
    clocks: tuple[ClockDomain, ...]
    ports: tuple[PortDomainIntent, ...]
    sequential: tuple[SequentialElement, ...]
    module: Mapping[str, Any]


@dataclass(frozen=True, slots=True)
class DomainAnalysis:
    """Shared dependency graph with CDC and RDC views."""

    dependencies: tuple[Crossing, ...]
    clock_crossings: tuple[Crossing, ...]
    reset_crossings: tuple[Crossing, ...]


_SEQ_PORTS: dict[str, tuple[str, str, str | None, str | None]] = {
    "$dff": ("CLK", "D", None, None),
    "$dffe": ("CLK", "D", None, None),
    "$adff": ("CLK", "D", "ARST", None),
    "$adffe": ("CLK", "D", "ARST", None),
    "$sdff": ("CLK", "D", None, "SRST"),
    "$sdffe": ("CLK", "D", None, "SRST"),
    "$sdffce": ("CLK", "D", None, "SRST"),
}


def _bits(cell: Mapping[str, Any], port: str | None) -> tuple[NetBit, ...]:
    if port is None:
        return ()
    return tuple(cell.get("connections", {}).get(port, ()))


def _parameter_bool(cell: Mapping[str, Any], name: str) -> str | None:
    value = cell.get("parameters", {}).get(name)
    if value is None:
        return None
    text = str(value).strip()
    if not text:
        return None
    return "high" if text[-1] == "1" else "low"


def _net_names(module: Mapping[str, Any]) -> dict[NetBit, str]:
    """Return a stable readable name for every represented net bit."""

    aliases: dict[NetBit, list[str]] = {}
    for name, port in module.get("ports", {}).items():
        bits = tuple(port.get("bits", ()))
        for index, bit in enumerate(bits):
            label = name if len(bits) == 1 else f"{name}[{index}]"
            aliases.setdefault(bit, []).append(label)
    for name, net in module.get("netnames", {}).items():
        bits = tuple(net.get("bits", ()))
        for index, bit in enumerate(bits):
            label = name if len(bits) == 1 else f"{name}[{index}]"
            aliases.setdefault(bit, []).append(label)
    return {
        bit: min(names, key=lambda item: (item.count("."), len(item), item))
        for bit, names in aliases.items()
    }


def _domain_bit_map(module: Mapping[str, Any], clocks: ClockConfig) -> dict[NetBit, str]:
    names = _net_names(module)
    by_name = {name.split("[")[0]: bit for bit, name in names.items()}
    result: dict[NetBit, str] = {}
    for domain in clocks.domains:
        port = module.get("ports", {}).get(domain.signal)
        bits = tuple(port.get("bits", ())) if port else ()
        if not bits and domain.signal in by_name:
            bits = (by_name[domain.signal],)
        if len(bits) == 1:
            result[bits[0]] = domain.name
    return result


def _port_intent(module: Mapping[str, Any], clocks: ClockConfig) -> tuple[PortDomainIntent, ...]:
    """Seed interface intent from the canonical FlexSoC clock/reset contract."""

    domains_by_clock = {domain.signal: domain for domain in clocks.domains}
    domains_by_reset = {domain.reset: domain for domain in clocks.domains}
    result: list[PortDomainIntent] = []
    for name, port in module.get("ports", {}).items():
        direction = str(port.get("direction", ""))
        if name in domains_by_clock:
            result.append(PortDomainIntent(name, direction, "clock"))
            continue
        if name in domains_by_reset:
            domain = domains_by_reset[name]
            result.append(
                PortDomainIntent(
                    name,
                    direction,
                    "async_reset",
                    associated_to_clocks=(domain.name,),
                    reset_polarity=domain.reset_polarity,
                )
            )
            continue
        result.append(PortDomainIntent(name, direction))
    return tuple(result)


def load_yosys_json(data: Mapping[str, Any], top: str, clocks: ClockConfig) -> DesignIR:
    """Build the shared IR from a pre-technology Yosys ``write_json`` design."""

    modules = data.get("modules", {})
    if top not in modules:
        raise ValueError(f"top module not found in Yosys JSON: {top}")
    module = modules[top]
    names = _net_names(module)
    domain_by_bit = _domain_bit_map(module, clocks)
    sequential: list[SequentialElement] = []

    for name, cell in module.get("cells", {}).items():
        cell_type = str(cell.get("type", ""))
        spec = _SEQ_PORTS.get(cell_type)
        if spec is None:
            continue
        clk_port, data_port, async_port, sync_port = spec
        clock_bits = _bits(cell, clk_port)
        data_bits = _bits(cell, data_port)
        q_bits = _bits(cell, "Q")
        if len(clock_bits) != 1 or not data_bits or not q_bits:
            continue
        async_bits = _bits(cell, async_port)
        sync_bits = _bits(cell, sync_port)
        reset_bit = async_bits[0] if async_bits else (sync_bits[0] if sync_bits else None)
        polarity = None
        if async_bits:
            polarity = _parameter_bool(cell, "ARST_POLARITY")
        elif sync_bits:
            polarity = _parameter_bool(cell, "SRST_POLARITY")
        sequential.append(
            SequentialElement(
                name=name,
                cell_type=cell_type,
                clock_bit=clock_bits[0],
                clock_domain=domain_by_bit.get(clock_bits[0]),
                data_bits=data_bits,
                q_bits=q_bits,
                async_reset_bit=async_bits[0] if async_bits else None,
                sync_reset_bit=sync_bits[0] if sync_bits else None,
                reset_signal=names.get(reset_bit) if reset_bit is not None else None,
                reset_polarity=polarity,
                source=cell.get("attributes", {}).get("src"),
            )
        )

    return DesignIR(
        top=top,
        clocks=clocks.domains,
        ports=_port_intent(module, clocks),
        sequential=tuple(sequential),
        module=module,
    )


def _relationship(clocks: ClockConfig, source: str | None, target: str | None) -> str:
    if source is None or target is None:
        return "unknown"
    if source == target:
        return "same"
    for rel in clocks.relationships:
        if {rel.source, rel.target} == {source, target}:
            return rel.kind
    known = {domain.name for domain in clocks.domains}
    return "sync" if source in known and target in known else "unknown"


def _graph(ir: DesignIR) -> tuple[
    dict[NetBit, Endpoint],
    dict[NetBit, tuple[str, ...]],
    dict[str, Mapping[str, Any]],
]:
    module = ir.module
    seq_by_name = {item.name: item for item in ir.sequential}
    sources: dict[NetBit, Endpoint] = {}
    for seq in ir.sequential:
        for index, bit in enumerate(seq.q_bits):
            sources[bit] = Endpoint(
                "seq", seq.name, index, seq.clock_domain, seq.reset_signal
            )
    for name, port in module.get("ports", {}).items():
        if port.get("direction") != "input":
            continue
        bits = tuple(port.get("bits", ()))
        for index, bit in enumerate(bits):
            sources.setdefault(bit, Endpoint("input", name, index))

    drivers: dict[NetBit, tuple[str, ...]] = {}
    cells = module.get("cells", {})
    for name, cell in cells.items():
        if name in seq_by_name:
            continue
        directions = cell.get("port_directions", {})
        for port_name, direction in directions.items():
            if direction != "output":
                continue
            for bit in cell.get("connections", {}).get(port_name, ()):
                drivers[bit] = (name, port_name)
    return sources, drivers, cells


def _endpoint_key(endpoint: Endpoint) -> tuple[str, str, int, str, str]:
    return (
        endpoint.kind,
        endpoint.name,
        endpoint.bit_index,
        endpoint.clock_domain or "",
        endpoint.reset_signal or "",
    )


def _upstream_sources(
    bit: NetBit,
    *,
    sources: Mapping[NetBit, Endpoint],
    drivers: Mapping[NetBit, tuple[str, ...]],
    cells: Mapping[str, Mapping[str, Any]],
    memo: dict[NetBit, tuple[tuple[Endpoint, tuple[str, ...]], ...]],
    active: set[NetBit],
) -> tuple[tuple[Endpoint, tuple[str, ...]], ...]:
    """Return one representative path per upstream endpoint for ``bit``."""

    if isinstance(bit, str):
        return ()
    if bit in sources:
        return ((sources[bit], ()),)
    cached = memo.get(bit)
    if cached is not None:
        return cached
    if bit in active:
        return ()

    driver = drivers.get(bit)
    if driver is None:
        memo[bit] = ()
        return ()

    cell_name, _ = driver
    cell = cells[cell_name]
    active.add(bit)
    found: dict[Endpoint, tuple[str, ...]] = {}
    try:
        for port_name, direction in cell.get("port_directions", {}).items():
            if direction != "input":
                continue
            for input_bit in cell.get("connections", {}).get(port_name, ()):
                for endpoint, path in _upstream_sources(
                    input_bit,
                    sources=sources,
                    drivers=drivers,
                    cells=cells,
                    memo=memo,
                    active=active,
                ):
                    candidate = path + (cell_name,)
                    previous = found.get(endpoint)
                    if previous is None or (len(candidate), candidate) < (
                        len(previous),
                        previous,
                    ):
                        found[endpoint] = candidate
    finally:
        active.remove(bit)

    result = tuple(
        sorted(found.items(), key=lambda item: (_endpoint_key(item[0]), item[1]))
    )
    memo[bit] = result
    return result


def _sequential_dependencies(ir: DesignIR, clocks: ClockConfig) -> tuple[Crossing, ...]:
    """Return sequential dependencies using a memoized combinational fan-in walk."""

    sources, drivers, cells = _graph(ir)
    memo: dict[NetBit, tuple[tuple[Endpoint, tuple[str, ...]], ...]] = {}
    result: dict[tuple[Endpoint, Endpoint], Crossing] = {}
    for dest in ir.sequential:
        for index, bit in enumerate(dest.data_bits):
            destination = Endpoint(
                "seq", dest.name, index, dest.clock_domain, dest.reset_signal
            )
            for source, path in _upstream_sources(
                bit,
                sources=sources,
                drivers=drivers,
                cells=cells,
                memo=memo,
                active=set(),
            ):
                if source.kind != "seq":
                    continue
                crossing = Crossing(
                    source,
                    destination,
                    _relationship(clocks, source.clock_domain, dest.clock_domain),
                    path,
                )
                key = (source, destination)
                previous = result.get(key)
                if previous is None or (len(path), path) < (
                    len(previous.path),
                    previous.path,
                ):
                    result[key] = crossing
    return tuple(
        sorted(
            result.values(),
            key=lambda item: (
                _endpoint_key(item.source),
                _endpoint_key(item.destination),
                item.path,
            ),
        )
    )


def analyze_domains(ir: DesignIR, clocks: ClockConfig) -> DomainAnalysis:
    """Build the dependency graph once and derive both CDC and RDC views."""

    dependencies = _sequential_dependencies(ir, clocks)
    clock_crossings = tuple(
        crossing
        for crossing in dependencies
        if crossing.source.clock_domain != crossing.destination.clock_domain
    )
    reset_crossings = tuple(
        crossing
        for crossing in dependencies
        if crossing.source.reset_signal is not None
        and crossing.destination.reset_signal is not None
        and crossing.source.reset_signal != crossing.destination.reset_signal
    )
    return DomainAnalysis(dependencies, clock_crossings, reset_crossings)


def find_clock_crossings(ir: DesignIR, clocks: ClockConfig) -> tuple[Crossing, ...]:
    """Return raw sequential CDC candidates before protocol classification."""

    return analyze_domains(ir, clocks).clock_crossings


def find_reset_crossings(ir: DesignIR, clocks: ClockConfig) -> tuple[Crossing, ...]:
    """Return raw RDC candidates between differently reset sequential state."""

    return analyze_domains(ir, clocks).reset_crossings

def _bit_consumers(ir: DesignIR, bit: NetBit) -> tuple[tuple[str, str, str], ...]:
    """Return structural consumers of one net bit as ``(kind, name, port)``."""

    uses: set[tuple[str, str, str]] = set()
    for name, cell in ir.module.get("cells", {}).items():
        directions = cell.get("port_directions", {})
        for port_name, direction in directions.items():
            if direction not in {"input", "inout"}:
                continue
            if bit in cell.get("connections", {}).get(port_name, ()):
                uses.add(("cell", name, port_name))
    for name, port in ir.module.get("ports", {}).items():
        if port.get("direction") not in {"output", "inout"}:
            continue
        if bit in port.get("bits", ()):
            uses.add(("output", name, ""))
    return tuple(sorted(uses))


def _seq_q_bit(seq: SequentialElement, index: int) -> NetBit | None:
    if 0 <= index < len(seq.q_bits):
        return seq.q_bits[index]
    return None


def _same_domain_successors(
    endpoint: Endpoint,
    dependencies: tuple[Crossing, ...],
) -> tuple[Crossing, ...]:
    return tuple(
        item
        for item in dependencies
        if item.source == endpoint
        and item.destination.clock_domain == endpoint.clock_domain
    )


def _classify_synchronizer_crossing(
    ir: DesignIR,
    analysis: DomainAnalysis,
    crossing: Crossing,
) -> SynchronizerFinding | None:
    """Classify one bit crossing when it structurally resembles an N-FF chain."""

    if crossing.relationship not in {"async", "unknown"}:
        return None
    seq_by_name = {item.name: item for item in ir.sequential}
    first = crossing.destination
    first_seq = seq_by_name.get(first.name)
    if first_seq is None:
        return None

    successors = _same_domain_successors(first, analysis.dependencies)
    if not successors:
        return None

    direct = tuple(item for item in successors if not item.path)
    if not direct:
        candidate = min(
            successors,
            key=lambda item: (len(item.path), item.path, _endpoint_key(item.destination)),
        )
        return SynchronizerFinding(
            crossing=crossing,
            status="ERROR",
            classification="nff_synchronizer",
            stages=(first, candidate.destination),
            issues=("combinational_between_stages",),
        )

    next_dep = min(direct, key=lambda item: _endpoint_key(item.destination))
    issues: list[str] = []
    if crossing.path:
        issues.append("combinational_before_first_stage")
    if crossing.relationship == "unknown":
        issues.append("undeclared_clock_relationship")

    q_bit = _seq_q_bit(first_seq, first.bit_index)
    next_seq = seq_by_name.get(next_dep.destination.name)
    if q_bit is None or next_seq is None:
        return None
    data_port = _SEQ_PORTS.get(next_seq.cell_type, ("", "D", None, None))[1]
    allowed = ("cell", next_seq.name, data_port)
    extra_uses = tuple(use for use in _bit_consumers(ir, q_bit) if use != allowed)
    if len(direct) != 1 or extra_uses:
        issues.append("first_stage_fanout")
    if (
        first_seq.reset_signal != next_seq.reset_signal
        or first_seq.reset_polarity != next_seq.reset_polarity
    ):
        issues.append("reset_mismatch_between_stages")

    # Two clean destination stages identify a structural synchronizer.
    # Do not absorb downstream functional registers into that chain.
    stages = [first, next_dep.destination]

    fatal = {
        "combinational_before_first_stage",
        "combinational_between_stages",
        "first_stage_fanout",
        "reset_mismatch_between_stages",
        "synchronizer_cycle",
    }
    if any(issue in fatal for issue in issues):
        status = "ERROR"
    elif issues:
        status = "WARN"
    else:
        status = "SAFE"
    return SynchronizerFinding(
        crossing=crossing,
        status=status,
        classification="nff_synchronizer",
        stages=tuple(stages),
        issues=tuple(dict.fromkeys(issues)),
    )


def _crossing_group_key(crossing: Crossing) -> tuple[str, str, str, str]:
    return (
        crossing.source.name,
        crossing.destination.name,
        crossing.source.clock_domain or "",
        crossing.destination.clock_domain or "",
    )


def classify_synchronizers(
    ir: DesignIR,
    analysis: DomainAnalysis,
) -> tuple[SynchronizerFinding, ...]:
    """Recognize only scalar N-FF synchronizers and check chain integrity."""

    widths: dict[tuple[str, str, str, str], int] = {}
    for crossing in analysis.clock_crossings:
        key = _crossing_group_key(crossing)
        widths[key] = widths.get(key, 0) + 1

    findings = []
    for crossing in analysis.clock_crossings:
        if widths[_crossing_group_key(crossing)] != 1:
            continue
        finding = _classify_synchronizer_crossing(ir, analysis, crossing)
        if finding is not None:
            findings.append(finding)
    return tuple(
        sorted(
            findings,
            key=lambda item: (
                _endpoint_key(item.crossing.source),
                _endpoint_key(item.crossing.destination),
            ),
        )
    )


def _crossing_groups(crossings: tuple[Crossing, ...]) -> tuple[tuple[Crossing, ...], ...]:
    groups: dict[tuple[str, str, str, str], list[Crossing]] = {}
    for crossing in crossings:
        groups.setdefault(_crossing_group_key(crossing), []).append(crossing)
    return tuple(
        tuple(sorted(items, key=lambda item: (item.source.bit_index, item.destination.bit_index)))
        for _, items in sorted(groups.items())
    )


def _control_source_endpoints(ir: DesignIR, seq: SequentialElement) -> tuple[Endpoint, ...]:
    """Return sequential endpoints driving a destination register enable."""

    cell = ir.module.get("cells", {}).get(seq.name, {})
    enable_bits = tuple(cell.get("connections", {}).get("EN", ()))
    if not enable_bits:
        return ()
    sources, drivers, cells = _graph(ir)
    memo: dict[NetBit, tuple[tuple[Endpoint, tuple[str, ...]], ...]] = {}
    result: set[Endpoint] = set()
    for bit in enable_bits:
        for endpoint, _ in _upstream_sources(
            bit,
            sources=sources,
            drivers=drivers,
            cells=cells,
            memo=memo,
            active=set(),
        ):
            if endpoint.kind == "seq":
                result.add(endpoint)
    return tuple(sorted(result, key=_endpoint_key))


def _input_paths(ir: DesignIR, bit: NetBit) -> tuple[tuple[Endpoint, tuple[str, ...]], ...]:
    sources, drivers, cells = _graph(ir)
    return tuple(
        item
        for item in _upstream_sources(
            bit,
            sources=sources,
            drivers=drivers,
            cells=cells,
            memo={},
            active=set(),
        )
        if item[0].kind == "input"
    )


def _declared_port_bits(ir: DesignIR, names: set[str]) -> set[NetBit]:
    result: set[NetBit] = set()
    for name in names:
        port = ir.module.get("ports", {}).get(name)
        if port:
            result.update(port.get("bits", ()))
    return result


def _finding_for_crossing(
    findings: tuple[DomainFinding, ...] | list[DomainFinding], crossing: Crossing
) -> DomainFinding | None:
    key = (crossing.source, crossing.destination)
    for finding in findings:
        if not finding.primary:
            continue
        if any((item.source, item.destination) == key for item in finding.crossings):
            return finding
    return None


def _setup_and_glitch_findings(ir: DesignIR, analysis: DomainAnalysis) -> tuple[tuple[DomainFinding, ...], tuple[DomainFinding, ...]]:
    setup: list[DomainFinding] = []
    glitch: list[DomainFinding] = []
    declared_clocks = {domain.signal for domain in ir.clocks}
    declared_resets = {domain.reset for domain in ir.clocks}
    clock_bits = _declared_port_bits(ir, declared_clocks)
    reset_bits = _declared_port_bits(ir, declared_resets)
    domain_by_name = {domain.name: domain for domain in ir.clocks}

    for seq in ir.sequential:
        if seq.clock_domain is None:
            setup.append(DomainFinding(
                "setup", "ERROR", "unassigned_clock_domain",
                issues=(f"sequential={seq.name}",),
                evidence=(seq.source or "-",),
            ))
        elif seq.reset_signal:
            domain = domain_by_name[seq.clock_domain]
            if seq.reset_signal == domain.reset and seq.reset_polarity not in {None, domain.reset_polarity}:
                setup.append(DomainFinding(
                    "setup", "ERROR", "reset_polarity_mismatch",
                    issues=(f"declared={domain.reset_polarity}", f"observed={seq.reset_polarity}"),
                    evidence=(seq.name,),
                ))

        if seq.clock_bit not in clock_bits:
            for endpoint, path in _input_paths(ir, seq.clock_bit):
                if endpoint.name in declared_clocks and path:
                    glitch.append(DomainFinding(
                        "glitch", "ERROR", "combinational_clock_path",
                        issues=("potentially_glitching_clock_logic",),
                        evidence=(f"clock={endpoint.name}", f"sequential={seq.name}", f"path={'/'.join(path)}"),
                    ))
                    break

        reset_bit = seq.async_reset_bit if seq.async_reset_bit is not None else seq.sync_reset_bit
        if reset_bit is not None and reset_bit not in reset_bits:
            for endpoint, path in _input_paths(ir, reset_bit):
                if endpoint.name in declared_resets and path:
                    glitch.append(DomainFinding(
                        "glitch", "ERROR", "combinational_reset_path",
                        issues=("potentially_glitching_reset_logic",),
                        evidence=(f"reset={endpoint.name}", f"sequential={seq.name}", f"path={'/'.join(path)}"),
                    ))
                    break

    unknown_pairs = sorted({
        (item.source.clock_domain or "?", item.destination.clock_domain or "?")
        for item in analysis.clock_crossings if item.relationship == "unknown"
    })
    for source, destination in unknown_pairs:
        setup.append(DomainFinding(
            "setup", "WARN", "undeclared_clock_relationship",
            issues=(f"{source}->{destination}",),
        ))

    resets_by_clock: dict[str, set[str]] = {}
    for seq in ir.sequential:
        if seq.clock_domain and seq.reset_signal:
            resets_by_clock.setdefault(seq.clock_domain, set()).add(seq.reset_signal)
    for clock, resets in sorted(resets_by_clock.items()):
        if len(resets) > 1:
            setup.append(DomainFinding(
                "setup", "REVIEW", "multiple_reset_domains_on_clock",
                issues=(f"clock_domain={clock}",),
                evidence=tuple(sorted(resets)),
            ))
    return tuple(setup), tuple(glitch)


def _reset_synchronizer_findings(ir: DesignIR, analysis: DomainAnalysis) -> tuple[DomainFinding, ...]:
    """Recognize async-assert/synchronous-release reset synchronizer chains."""

    findings: list[DomainFinding] = []
    seq_by_name = {seq.name: seq for seq in ir.sequential}
    for first in ir.sequential:
        if first.async_reset_bit is None or len(first.data_bits) != 1 or len(first.q_bits) != 1:
            continue
        deasserted = "1" if first.reset_polarity == "low" else "0"
        if first.data_bits[0] != deasserted:
            continue
        first_ep = Endpoint("seq", first.name, 0, first.clock_domain, first.reset_signal)
        direct = tuple(
            dep for dep in _same_domain_successors(first_ep, analysis.dependencies)
            if not dep.path
        )
        if len(direct) != 1:
            continue
        stages = [first_ep]
        current = direct[0].destination
        current_seq = seq_by_name.get(current.name)
        if current_seq is None or current_seq.async_reset_bit != first.async_reset_bit:
            continue
        stages.append(current)
        while True:
            dep = tuple(
                item for item in _same_domain_successors(current, analysis.dependencies)
                if not item.path
            )
            if len(dep) != 1:
                break
            nxt = dep[0].destination
            nxt_seq = seq_by_name.get(nxt.name)
            if nxt_seq is None or nxt_seq.async_reset_bit != first.async_reset_bit:
                break
            stages.append(nxt)
            current = nxt
        final_seq = seq_by_name[current.name]
        final_q = _seq_q_bit(final_seq, current.bit_index)
        if final_q is None:
            continue
        reset_users = []
        for name, cell in ir.module.get("cells", {}).items():
            for port in ("ARST", "SRST"):
                if final_q in cell.get("connections", {}).get(port, ()):
                    reset_users.append(name)
        if not reset_users:
            continue
        findings.append(DomainFinding(
            "rdc", "SAFE", "reset_synchronizer",
            issues=(),
            evidence=(
                f"clock_domain={first.clock_domain}",
                f"reset={first.reset_signal}",
                f"stages={len(stages)}",
                f"consumers={len(reset_users)}",
            ),
            primary=False,
        ))
    return tuple(findings)


CDC_CHECK_ORDER = (
    "scalar_and_multibit_crossings",
    "async_fifo_candidates",
    "closed_loop_handshakes",
    "synchronized_reconvergence",
)

SETUP_GLITCH_CHECK_ORDER = (
    "domain_setup",
    "glitch_hazards",
)

RDC_CHECK_ORDER = (
    "reset_domain_crossings",
    "reset_synchronizers",
    "async_reset_release",
    "reset_sequence",
)


def _classify_primary_cdc(
    ir: DesignIR,
    analysis: DomainAnalysis,
) -> tuple[
    list[DomainFinding],
    list[DomainFinding],
    dict[tuple[Endpoint, Endpoint], SynchronizerFinding | None],
]:
    """Classify scalar and multibit clock-domain crossings."""

    seq_by_name = {item.name: item for item in ir.sequential}
    groups = _crossing_groups(analysis.clock_crossings)
    all_sync_candidates = {
        (crossing.source, crossing.destination): _classify_synchronizer_crossing(ir, analysis, crossing)
        for crossing in analysis.clock_crossings
    }

    single_syncs = [
        finding for group in groups if len(group) == 1
        for finding in [all_sync_candidates[(group[0].source, group[0].destination)]]
        if finding is not None
    ]
    final_sync_origin: dict[Endpoint, str | None] = {
        finding.stages[-1]: finding.crossing.source.clock_domain
        for finding in single_syncs
        if finding.status in {"SAFE", "WARN"}
    }

    cdc: list[DomainFinding] = []
    multibit_findings: list[DomainFinding] = []
    for group in groups:
        if len(group) == 1:
            crossing = group[0]
            sync = all_sync_candidates[(crossing.source, crossing.destination)]
            if sync is None:
                status = "ERROR" if crossing.relationship == "async" else "WARN"
                issues = ["missing_synchronizer"]
                if crossing.path:
                    issues.append("combinational_cross_domain_path")
                cdc.append(DomainFinding(
                    "cdc", status, "missing_synchronizer", (crossing,),
                    tuple(issues),
                    evidence=(f"path={'/'.join(crossing.path) if crossing.path else '-'}",),
                ))
                continue
            cdc.append(DomainFinding(
                "cdc", sync.status, "nff_synchronizer", (crossing,),
                sync.issues,
                ("minimum_pulse_width_or_sampling_window",) if sync.status != "ERROR" else (),
                tuple(f"stage={stage.name}[{stage.bit_index}]" for stage in sync.stages),
            ))
            continue

        dest = seq_by_name.get(group[0].destination.name)
        controls = _control_source_endpoints(ir, dest) if dest is not None else ()
        qualified = tuple(
            endpoint for endpoint in controls
            if final_sync_origin.get(endpoint) == group[0].source.clock_domain
        )
        if qualified:
            finding = DomainFinding(
                "cdc", "REVIEW", "qualified_multibit", group,
                obligations=(
                    "prove_data_stability_before_control",
                    "prove_data_stability_after_control",
                    "confirm_control_polarity_and_sampling_edge",
                ),
                evidence=(
                    f"width={len(group)}",
                    *(f"control={item.name}[{item.bit_index}]" for item in qualified),
                ),
            )
            cdc.append(finding)
            multibit_findings.append(finding)
            continue

        bit_syncs = [all_sync_candidates[(item.source, item.destination)] for item in group]
        if all(item is not None for item in bit_syncs):
            typed = [item for item in bit_syncs if item is not None]
            if any(item.status == "ERROR" for item in typed):
                issues = tuple(sorted({issue for item in typed for issue in item.issues}))
                finding = DomainFinding(
                    "cdc", "ERROR", "multibit_nff_integrity", group, issues,
                    evidence=(f"width={len(group)}",),
                )
            else:
                finding = DomainFinding(
                    "cdc", "REVIEW", "multibit_nff_bus", group,
                    obligations=("prove_gray_hamming1_or_coherent_protocol",),
                    evidence=(f"width={len(group)}", "bitwise_nff_chains=yes"),
                )
            cdc.append(finding)
            multibit_findings.append(finding)
            continue

        finding = DomainFinding(
            "cdc", "ERROR", "unsynchronized_multibit", group,
            issues=("no_recognized_coherency_mechanism",),
            evidence=(f"width={len(group)}",),
        )
        cdc.append(finding)
        multibit_findings.append(finding)

    return cdc, multibit_findings, all_sync_candidates


def _check_async_fifo_candidates(
    cdc: list[DomainFinding],
    multibit_findings: Sequence[DomainFinding],
) -> None:
    """Append paired Gray-style bus candidates for asynchronous FIFOs."""

    for index, left in enumerate(multibit_findings):
        if left.classification != "multibit_nff_bus":
            continue
        a = left.crossings[0]
        for right in multibit_findings[index + 1:]:
            if right.classification != "multibit_nff_bus":
                continue
            b = right.crossings[0]
            if (
                a.source.clock_domain == b.destination.clock_domain
                and a.destination.clock_domain == b.source.clock_domain
            ):
                cdc.append(DomainFinding(
                    "cdc", "REVIEW", "async_fifo_candidate",
                    left.crossings + right.crossings,
                    obligations=(
                        "prove_gray_hamming1_pointer_encoding",
                        "prove_dual_clock_storage_protocol",
                        "prove_full_empty_pointer_safety",
                    ),
                    evidence=(
                        f"domains={a.source.clock_domain}<->{a.destination.clock_domain}",
                        f"forward_width={len(left.crossings)}",
                        f"reverse_width={len(right.crossings)}",
                    ),
                    primary=False,
                ))


def _clean_scalar_synchronizers(
    cdc: Sequence[DomainFinding],
    all_sync_candidates: Mapping[tuple[Endpoint, Endpoint], SynchronizerFinding | None],
) -> list[tuple[DomainFinding, SynchronizerFinding]]:
    """Return primary scalar synchronizers safe enough for protocol checks."""

    return [
        (finding, sync)
        for finding in cdc
        if finding.primary
        and finding.classification == "nff_synchronizer"
        and finding.status in {"SAFE", "WARN"}
        for sync in [all_sync_candidates[(finding.crossings[0].source, finding.crossings[0].destination)]]
        if sync is not None
    ]


def _check_closed_loop_handshakes(
    cdc: list[DomainFinding],
    analysis: DomainAnalysis,
    clean_scalar: Sequence[tuple[DomainFinding, SynchronizerFinding]],
) -> None:
    """Append causally connected request/acknowledge handshake candidates."""

    dep_pairs = {(dep.source, dep.destination) for dep in analysis.dependencies}
    for index, (left, left_sync) in enumerate(clean_scalar):
        a = left.crossings[0]
        for right, right_sync in clean_scalar[index + 1:]:
            b = right.crossings[0]
            if not (
                a.source.clock_domain == b.destination.clock_domain
                and a.destination.clock_domain == b.source.clock_domain
            ):
                continue
            if (
                (left_sync.stages[-1], b.source) in dep_pairs
                and (right_sync.stages[-1], a.source) in dep_pairs
            ):
                cdc.append(DomainFinding(
                    "cdc", "REVIEW", "closed_loop_handshake",
                    (a, b),
                    obligations=("prove_request_ack_protocol_and_liveness",),
                    evidence=(f"domains={a.source.clock_domain}<->{a.destination.clock_domain}",),
                    primary=False,
                ))


def _check_synchronized_reconvergence(
    cdc: list[DomainFinding],
    analysis: DomainAnalysis,
    clean_scalar: Sequence[tuple[DomainFinding, SynchronizerFinding]],
) -> None:
    """Append coherency hazards after independent scalar synchronizers reconverge."""

    reconv: dict[tuple[Endpoint, str | None], list[tuple[DomainFinding, SynchronizerFinding]]] = {}
    for finding, sync in clean_scalar:
        origin = finding.crossings[0].source.clock_domain
        final = sync.stages[-1]
        for dep in analysis.dependencies:
            if dep.source == final and dep.destination.clock_domain == final.clock_domain:
                reconv.setdefault((dep.destination, origin), []).append((finding, sync))
    for (destination, origin), items in sorted(reconv.items(), key=lambda item: (_endpoint_key(item[0][0]), str(item[0][1]))):
        unique = {(item[0].crossings[0].source.name, item[0].crossings[0].source.bit_index) for item in items}
        if len(unique) < 2:
            continue
        cdc.append(DomainFinding(
            "cdc", "WARN", "synchronized_reconvergence",
            tuple(item[0].crossings[0] for item in items),
            issues=("independently_synchronized_signals_reconverge",),
            obligations=("prove_destination_coherency",),
            evidence=(f"destination={destination.name}[{destination.bit_index}]", f"source_domain={origin}"),
            primary=False,
        ))


def _classify_reset_domain_crossings(
    analysis: DomainAnalysis,
    cdc: Sequence[DomainFinding],
) -> list[DomainFinding]:
    """Classify reset-domain crossings against recognized CDC protection."""

    rdc: list[DomainFinding] = []
    for group in _crossing_groups(analysis.reset_crossings):
        crossing = group[0]
        cdc_finding = _finding_for_crossing(cdc, crossing)
        if cdc_finding and cdc_finding.classification == "nff_synchronizer" and cdc_finding.status in {"SAFE", "WARN"}:
            rdc.append(DomainFinding(
                "rdc", "SAFE", "rdc_via_data_synchronizer", group,
                obligations=("minimum_pulse_width_or_sampling_window",),
            ))
        elif cdc_finding and cdc_finding.classification == "qualified_multibit":
            rdc.append(DomainFinding(
                "rdc", "REVIEW", "rdc_control_candidate", group,
                obligations=("prove_control_blocks_source_reset_effect",),
                evidence=(f"width={len(group)}",),
            ))
        elif cdc_finding and cdc_finding.classification == "multibit_nff_bus":
            rdc.append(DomainFinding(
                "rdc", "REVIEW", "rdc_via_multibit_protocol", group,
                obligations=("prove_protocol_safe_across_reset_events",),
                evidence=(f"width={len(group)}",),
            ))
        else:
            rdc.append(DomainFinding(
                "rdc", "ERROR", "uncontrolled_rdc", group,
                issues=("different_reset_domains_without_recognized_protection",),
                evidence=(f"width={len(group)}",),
            ))
    return rdc


def _check_async_reset_release(
    rdc: list[DomainFinding],
    ir: DesignIR,
    analysis: DomainAnalysis,
    reset_sync: Sequence[DomainFinding],
) -> None:
    """Append review obligations for direct asynchronous reset release."""

    declared_reset_bits = {
        domain.name: _declared_port_bits(ir, {domain.reset}) for domain in ir.clocks
    }
    protected_domains = {
        item.split("=", 1)[1]
        for finding in reset_sync
        for item in finding.evidence
        if item.startswith("clock_domain=")
    }
    for domain in ir.clocks:
        direct_async = any(
            seq.clock_domain == domain.name
            and seq.async_reset_bit in declared_reset_bits[domain.name]
            for seq in ir.sequential
        )
        if direct_async and domain.name not in protected_domains:
            rdc.append(DomainFinding(
                "rdc", "REVIEW", "async_reset_release", (),
                obligations=("prove_synchronous_reset_deassertion_or_safe_reset_sequence",),
                evidence=(f"clock_domain={domain.name}", f"reset={domain.reset}"),
                primary=False,
            ))


def _check_reset_sequence(
    rdc: list[DomainFinding],
    ir: DesignIR,
    analysis: DomainAnalysis,
) -> None:
    """Append a sequencing obligation when multiple reset domains interact."""

    if len({seq.reset_signal for seq in ir.sequential if seq.reset_signal}) > 1 and analysis.reset_crossings:
        rdc.append(DomainFinding(
            "rdc", "REVIEW", "reset_sequence_or_control_required", (),
            obligations=("specify_reset_assertion_sequence_or_rdc_blocking_control",),
            primary=False,
        ))


def classify_cdc_rdc(ir: DesignIR, analysis: DomainAnalysis) -> ComprehensiveAnalysis:
    """Run the ordered structural CDC/RDC qualification checks."""

    # CDC_CHECK_ORDER[0]: scalar and multibit crossing classification.
    cdc, multibit_findings, all_sync_candidates = _classify_primary_cdc(ir, analysis)

    # CDC_CHECK_ORDER[1]: paired bitwise synchronizers that resemble async FIFOs.
    _check_async_fifo_candidates(cdc, multibit_findings)

    clean_scalar = _clean_scalar_synchronizers(cdc, all_sync_candidates)

    # CDC_CHECK_ORDER[2]: causal request/acknowledge loops.
    _check_closed_loop_handshakes(cdc, analysis, clean_scalar)

    # CDC_CHECK_ORDER[3]: independently synchronized controls/data that reconverge.
    _check_synchronized_reconvergence(cdc, analysis, clean_scalar)

    # SETUP_GLITCH_CHECK_ORDER: environment/domain setup and combinational hazards.
    setup, glitch = _setup_and_glitch_findings(ir, analysis)

    # RDC_CHECK_ORDER[0]: reset-domain crossings and their recognized protection.
    rdc = _classify_reset_domain_crossings(analysis, cdc)

    # RDC_CHECK_ORDER[1]: async-assert/synchronous-release reset synchronizers.
    reset_sync = _reset_synchronizer_findings(ir, analysis)
    rdc.extend(reset_sync)

    # RDC_CHECK_ORDER[2]: direct asynchronous reset release obligations.
    _check_async_reset_release(rdc, ir, analysis, reset_sync)

    # RDC_CHECK_ORDER[3]: sequencing/control obligations across interacting resets.
    _check_reset_sequence(rdc, ir, analysis)

    return ComprehensiveAnalysis(tuple(cdc), tuple(rdc), setup, glitch)


# Extraction, reporting, and command-line runner

def _read_slang_command(top: str, filelists: Sequence[Path], repo_root: Path) -> str:
    """Render the canonical pre-technology Slang/Yosys frontend."""

    include_dirs = (
        repo_root / "hw" / "ips" / "pkgs",
        repo_root / "hw" / "ips" / "prim",
        repo_root / "hw" / "ips" / "prim_opentitan",
        repo_root / "hw" / "ips" / "tlul",
    )
    options = [*(f"-I {path}" for path in include_dirs), "-D SYNTHESIS", "--ignore-assertions"]
    options.extend(f"-f {path}" for path in filelists)
    options.append(f"--top {top}")
    return "read_slang " + " ".join(options)


def render_extract_script(
    *,
    top: str,
    filelists: Sequence[Path],
    repo_root: Path,
    design_json: Path,
) -> str:
    """Return a flattened, technology-neutral structural extraction script."""

    lines = [
        _read_slang_command(top, filelists, repo_root),
        f"hierarchy -check -top {top}",
        "proc",
        "opt",
        "flatten",
        "opt_clean",
        f"write_json {design_json}",
        "",
    ]
    return "\n".join(lines)


def _write_json(path: Path, payload: Mapping[str, Any] | list[Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def _clock_values(args: Any) -> ClockConfig:
    return clock_config(
        {
            "N_CLOCKS": args.n_clocks,
            "CLOCK_DOMAINS": args.clock_domains,
            "CLOCK_RELATIONSHIPS": args.clock_relationships,
            "CLK_PERIOD": args.clk_period,
        }
    )


def _crossing_dict(crossing: Any) -> dict[str, Any]:
    return {
        "source": asdict(crossing.source),
        "destination": asdict(crossing.destination),
        "relationship": crossing.relationship,
        "path": list(crossing.path),
    }


def _crossing_key(crossing: Any) -> tuple[str, int, str, int]:
    return (
        crossing.source.name,
        crossing.source.bit_index,
        crossing.destination.name,
        crossing.destination.bit_index,
    )


def _finding_code(finding: DomainFinding, index: int) -> str:
    prefix = {
        "cdc": "CDC",
        "rdc": "RDC",
        "setup": "SETUP",
        "glitch": "GLITCH",
    }.get(finding.scope, finding.scope.upper())
    return f"{prefix}-{index:04d}"


def _finding_record(finding: DomainFinding, index: int) -> dict[str, Any]:
    return {
        "id": _finding_code(finding, index),
        "scope": finding.scope,
        "status": finding.status,
        "classification": finding.classification,
        "primary": finding.primary,
        "crossings": [_crossing_dict(item) for item in finding.crossings],
        "issues": list(finding.issues),
        "obligations": list(finding.obligations),
        "evidence": list(finding.evidence),
    }


def _finding_records(findings: Sequence[DomainFinding]) -> list[dict[str, Any]]:
    return [_finding_record(finding, index) for index, finding in enumerate(findings, 1)]


def _primary_by_crossing(findings: Sequence[DomainFinding]) -> dict[tuple[str, int, str, int], dict[str, Any]]:
    result: dict[tuple[str, int, str, int], dict[str, Any]] = {}
    for index, finding in enumerate(findings, 1):
        if not finding.primary:
            continue
        record = _finding_record(finding, index)
        for crossing in finding.crossings:
            result[_crossing_key(crossing)] = record
    return result


def _inventory(ir: DesignIR) -> dict[str, Any]:
    reset_names = sorted({item.reset_signal for item in ir.sequential if item.reset_signal})
    return {
        "schema": "flexsoc.domain_inventory.v2",
        "top": ir.top,
        "clock_domains": [asdict(domain) for domain in ir.clocks],
        "reset_domains": reset_names,
        "ports": [asdict(port) for port in ir.ports],
        "sequential": [asdict(item) for item in ir.sequential],
    }


def _pair_counts(crossings: Sequence[Any], *, reset: bool = False) -> list[dict[str, Any]]:
    if reset:
        counter = Counter((item.source.reset_signal, item.destination.reset_signal) for item in crossings)
        return [
            {"source": src, "destination": dst, "count": count}
            for (src, dst), count in sorted(counter.items(), key=lambda item: str(item[0]))
        ]
    counter = Counter(
        (item.source.clock_domain, item.destination.clock_domain, item.relationship)
        for item in crossings
    )
    return [
        {"source": src, "destination": dst, "relationship": rel, "count": count}
        for (src, dst, rel), count in sorted(counter.items(), key=lambda item: str(item[0]))
    ]


def _status_counts(findings: Sequence[DomainFinding]) -> dict[str, int]:
    counts = Counter(item.status for item in findings)
    return {
        "safe": counts.get("SAFE", 0),
        "warnings": counts.get("WARN", 0),
        "errors": counts.get("ERROR", 0),
        "review": counts.get("REVIEW", 0),
        "info": counts.get("INFO", 0),
    }


def _class_counts(findings: Sequence[DomainFinding]) -> dict[str, int]:
    return dict(sorted(Counter(item.classification for item in findings).items()))


def _overall_status(result: ComprehensiveAnalysis) -> str:
    findings = (*result.cdc, *result.rdc, *result.setup, *result.glitch)
    if any(item.status == "ERROR" for item in findings):
        return "fail"
    if any(item.status in {"WARN", "REVIEW"} for item in findings):
        return "review"
    return "pass"


def _summary(ir: DesignIR, analysis: DomainAnalysis, result: ComprehensiveAnalysis) -> dict[str, Any]:
    reset_names = {item.reset_signal for item in ir.sequential if item.reset_signal}
    cdc_counts = _status_counts(result.cdc)
    rdc_counts = _status_counts(result.rdc)
    setup_counts = _status_counts(result.setup)
    glitch_counts = _status_counts(result.glitch)
    return {
        "schema": "flexsoc.cdc_rdc_summary.v2",
        "top": ir.top,
        "status": _overall_status(result),
        "clock_domains": len(ir.clocks),
        "reset_domains": len(reset_names),
        "sequential_elements": len(ir.sequential),
        "dependencies": len(analysis.dependencies),
        "cdc": {
            "raw_crossings": len(analysis.clock_crossings),
            **cdc_counts,
            "classifications": _class_counts(result.cdc),
            "pairs": _pair_counts(analysis.clock_crossings),
        },
        "rdc": {
            "raw_crossings": len(analysis.reset_crossings),
            **rdc_counts,
            "classifications": _class_counts(result.rdc),
            "pairs": _pair_counts(analysis.reset_crossings, reset=True),
        },
        "setup": {**setup_counts, "classifications": _class_counts(result.setup)},
        "glitch": {**glitch_counts, "classifications": _class_counts(result.glitch)},
        "verification_obligations": sum(
            len(item.obligations)
            for item in (*result.cdc, *result.rdc, *result.setup, *result.glitch)
        ),
    }


def _crossing_records(
    crossings: Sequence[Any], findings: Sequence[DomainFinding]
) -> list[dict[str, Any]]:
    primary = _primary_by_crossing(findings)
    records = []
    for crossing in crossings:
        record = _crossing_dict(crossing)
        finding = primary.get(_crossing_key(crossing))
        if finding is None:
            record.update({"status": "PENDING", "classification": "pending"})
        else:
            record.update({
                "status": finding["status"],
                "classification": finding["classification"],
                "finding_id": finding["id"],
            })
        records.append(record)
    return records


def _finding_line(record: Mapping[str, Any]) -> str:
    crossing = record["crossings"][0] if record["crossings"] else None
    route = ""
    if crossing:
        src = crossing["source"]
        dst = crossing["destination"]
        route = f" {src['name']}[{src['bit_index']}] -> {dst['name']}[{dst['bit_index']}]"
    issues = ",".join(record["issues"]) or "-"
    obligations = ",".join(record["obligations"]) or "-"
    evidence = ",".join(record["evidence"]) or "-"
    return (
        f"{record['id']} {record['status']} {record['classification']}{route} "
        f"issues={issues} obligations={obligations} evidence={evidence}"
    )


def write_reports(
    ir: DesignIR,
    analysis: DomainAnalysis,
    *,
    analysis_dir: Path,
    log_dir: Path,
    result: ComprehensiveAnalysis | None = None,
) -> dict[str, Any]:
    """Write comprehensive structural findings and verification obligations."""

    analysis_dir.mkdir(parents=True, exist_ok=True)
    log_dir.mkdir(parents=True, exist_ok=True)
    classified = result if result is not None else classify_cdc_rdc(ir, analysis)
    inventory = _inventory(ir)
    cdc_records = _finding_records(classified.cdc)
    rdc_records = _finding_records(classified.rdc)
    setup_records = _finding_records(classified.setup)
    glitch_records = _finding_records(classified.glitch)
    summary = _summary(ir, analysis, classified)

    cdc = {
        "schema": "flexsoc.cdc.v2",
        "top": ir.top,
        "status": summary["status"],
        "findings": cdc_records,
        "crossings": _crossing_records(analysis.clock_crossings, classified.cdc),
    }
    rdc = {
        "schema": "flexsoc.rdc.v2",
        "top": ir.top,
        "status": summary["status"],
        "findings": rdc_records,
        "crossings": _crossing_records(analysis.reset_crossings, classified.rdc),
    }
    obligations = [
        {
            "finding_id": record["id"],
            "scope": record["scope"],
            "classification": record["classification"],
            "obligations": record["obligations"],
        }
        for record in (*cdc_records, *rdc_records, *setup_records, *glitch_records)
        if record["obligations"]
    ]
    _write_json(analysis_dir / "inventory.json", inventory)
    _write_json(analysis_dir / "cdc.json", cdc)
    _write_json(analysis_dir / "rdc.json", rdc)
    _write_json(analysis_dir / "setup.json", {"schema": "flexsoc.domain_setup.v1", "findings": setup_records})
    _write_json(analysis_dir / "glitch.json", {"schema": "flexsoc.glitch.v1", "findings": glitch_records})
    _write_json(analysis_dir / "obligations.json", {"schema": "flexsoc.domain_obligations.v1", "items": obligations})
    _write_json(analysis_dir / "summary.json", summary)

    cdc_lines = [
        "FlexSoC CDC structural analysis",
        f"top={ir.top}",
        f"status={summary['status']}",
        f"raw={summary['cdc']['raw_crossings']} safe={summary['cdc']['safe']} "
        f"review={summary['cdc']['review']} warn={summary['cdc']['warnings']} "
        f"error={summary['cdc']['errors']}",
        "",
        "[findings]",
        *(_finding_line(record) for record in cdc_records),
    ]
    (log_dir / "cdc.log").write_text("\n".join(cdc_lines) + "\n", encoding="utf-8")

    rdc_lines = [
        "FlexSoC RDC structural analysis",
        f"top={ir.top}",
        f"status={summary['status']}",
        f"raw={summary['rdc']['raw_crossings']} safe={summary['rdc']['safe']} "
        f"review={summary['rdc']['review']} warn={summary['rdc']['warnings']} "
        f"error={summary['rdc']['errors']}",
        "",
        "[findings]",
        *(_finding_line(record) for record in rdc_records),
    ]
    (log_dir / "rdc.log").write_text("\n".join(rdc_lines) + "\n", encoding="utf-8")

    lines = [
        "FlexSoC CDC/RDC structural analysis",
        f"top={ir.top}",
        f"status={summary['status']}",
        f"clock_domains={summary['clock_domains']}",
        f"reset_domains={summary['reset_domains']}",
        f"sequential_elements={summary['sequential_elements']}",
        f"dependencies={summary['dependencies']}",
        f"verification_obligations={summary['verification_obligations']}",
        "",
        "[CDC]",
        *(_finding_line(record) for record in cdc_records),
        "",
        "[RDC]",
        *(_finding_line(record) for record in rdc_records),
        "",
        "[setup]",
        *(_finding_line(record) for record in setup_records),
        "",
        "[glitch]",
        *(_finding_line(record) for record in glitch_records),
    ]
    (log_dir / "cdc_rdc.log").write_text("\n".join(lines) + "\n", encoding="utf-8")
    return summary


class _Heartbeat:
    """Emit lightweight progress while a normally quiet phase is running."""

    def __init__(self, label: str, seconds: float, detail: str = "") -> None:
        self.label = label
        self.seconds = max(0.0, seconds)
        self.detail = detail
        self.started = time.perf_counter()
        self.stop = threading.Event()
        self.thread: threading.Thread | None = None

    def __enter__(self) -> "_Heartbeat":
        if self.seconds > 0:
            self.thread = threading.Thread(target=self._loop, daemon=True)
            self.thread.start()
        return self

    def _loop(self) -> None:
        while not self.stop.wait(self.seconds):
            elapsed = time.perf_counter() - self.started
            suffix = f" · {self.detail}" if self.detail else ""
            print(f"[{self.label}] working {elapsed:.1f}s{suffix}", flush=True)

    def __exit__(self, *_: object) -> None:
        self.stop.set()
        if self.thread is not None:
            self.thread.join(timeout=0.2)


def _timed(label: str, action: Callable[[], _T], heartbeat: float, detail: str = "") -> tuple[_T, float]:
    started = time.perf_counter()
    with _Heartbeat(label, heartbeat, detail):
        result = action()
    return result, time.perf_counter() - started


def _live() -> bool:
    """Return whether the public CLI requested the live transcript."""

    return os.environ.get("FLEXSOC_LIVE", "0").strip().lower() in {"1", "true", "yes", "on"}


def _detail(live: bool, label: str, text: str) -> None:
    """Render analyzer detail only for ``fx ... --live``."""

    if live:
        print_label(label, text)


def run_analysis(
    args: Any, *, runner=None, inputs: Sequence[Path] = (), on: str = "local"
) -> int:
    """Run structural CDC/RDC, setup, glitch, and protocol-candidate checks."""

    live = _live()
    heartbeat = args.heartbeat if live else 0.0
    script = Path(args.script).resolve()
    design_json = Path(args.design_json).resolve()
    analysis_dir = Path(args.analysis_dir).resolve()
    log_dir = Path(args.log_dir).resolve()
    extract_log = log_dir / "extract.log"
    if not script.is_file():
        raise FileNotFoundError(f"missing CDC/RDC extraction script: {script}; run setup_cdc_rdc")
    log_dir.mkdir(parents=True, exist_ok=True)
    analysis_dir.mkdir(parents=True, exist_ok=True)

    _detail(live, "extract", f"top={args.top} · script={script}")

    def extract():
        command = (args.yosys, "-ql", str(extract_log), str(script))
        if runner is None:
            return subprocess.run(command, check=False, text=True)
        from flexsoc.backend.core import CommandRequest
        driver_log = log_dir / "extract_driver.log"
        request = CommandRequest(
            command, script.parent, {}, driver_log,
            inputs=tuple(dict.fromkeys((script, *(path.resolve() for path in inputs)))),
            outputs=(design_json, extract_log),
        )
        return runner.run(request, on=on)

    proc, extract_dt = _timed("extract", extract, heartbeat, f"log={extract_log}")
    if proc.returncode:
        print_status_label("extract", "fail", f"rc={proc.returncode} · log={extract_log}")
        return proc.returncode
    if not design_json.is_file():
        raise FileNotFoundError(f"Yosys did not produce structural JSON: {design_json}")
    _detail(live, "extract", f"done {extract_dt:.3f}s · design={design_json}")

    data, json_dt = _timed(
        "json",
        lambda: json.loads(design_json.read_text(encoding="utf-8")),
        heartbeat,
        f"file={design_json}",
    )
    module = data.get("modules", {}).get(args.top, {})
    cells = module.get("cells", {})
    _detail(
        live,
        "design",
        f"cells={len(cells)} netnames={len(module.get('netnames', {}))} "
        f"ports={len(module.get('ports', {}))} · json={json_dt:.3f}s",
    )
    if live:
        for cell_type, count in Counter(str(cell.get("type", "")) for cell in cells.values()).most_common(20):
            print_label("debug", f"cell_type={cell_type} count={count}")

    clocks = _clock_values(args)
    ir, ir_dt = _timed(
        "ir",
        lambda: load_yosys_json(data, args.top, clocks),
        heartbeat,
    )
    reset_names = {item.reset_signal for item in ir.sequential if item.reset_signal}
    _detail(
        live,
        "domains",
        f"clocks={len(ir.clocks)} resets={len(reset_names)} sequential={len(ir.sequential)} "
        f"· ir={ir_dt:.3f}s",
    )
    if live:
        for domain in ir.clocks:
            count = sum(1 for item in ir.sequential if item.clock_domain == domain.name)
            print_label(
                "domain",
                f"{domain.name} clock={domain.signal} reset={domain.reset} "
                f"period={domain.period_ns:g}ns sequential={count}",
            )

    analysis, graph_dt = _timed(
        "graph",
        lambda: analyze_domains(ir, clocks),
        heartbeat,
        f"sequential={len(ir.sequential)}",
    )
    _detail(live, "graph", f"dependencies={len(analysis.dependencies)} · {graph_dt:.3f}s")

    result, classify_dt = _timed(
        "classify",
        lambda: classify_cdc_rdc(ir, analysis),
        heartbeat,
        f"cdc={len(analysis.clock_crossings)} rdc={len(analysis.reset_crossings)}",
    )
    cdc_counts = _status_counts(result.cdc)
    rdc_counts = _status_counts(result.rdc)
    setup_counts = _status_counts(result.setup)
    glitch_counts = _status_counts(result.glitch)
    cdc_pairs = _pair_counts(analysis.clock_crossings)
    rdc_pairs = _pair_counts(analysis.reset_crossings, reset=True)
    _detail(
        live,
        "CDC",
        f"raw={len(analysis.clock_crossings)} safe={cdc_counts['safe']} "
        f"review={cdc_counts['review']} warn={cdc_counts['warnings']} "
        f"error={cdc_counts['errors']} · classify={classify_dt:.3f}s",
    )
    if live:
        for name, count in _class_counts(result.cdc).items():
            print_label("CDC", f"check={name} findings={count}")
        for pair in cdc_pairs:
            print_label(
                "CDC",
                f"{pair['source']} -> {pair['destination']} "
                f"{pair['relationship']} raw={pair['count']}",
            )
    _detail(
        live,
        "RDC",
        f"raw={len(analysis.reset_crossings)} safe={rdc_counts['safe']} "
        f"review={rdc_counts['review']} warn={rdc_counts['warnings']} "
        f"error={rdc_counts['errors']}",
    )
    if live:
        for name, count in _class_counts(result.rdc).items():
            print_label("RDC", f"check={name} findings={count}")
        for pair in rdc_pairs:
            print_label("RDC", f"{pair['source']} -> {pair['destination']} raw={pair['count']}")
    _detail(
        live,
        "setup",
        f"review={setup_counts['review']} warn={setup_counts['warnings']} error={setup_counts['errors']}",
    )
    _detail(
        live,
        "glitch",
        f"review={glitch_counts['review']} warn={glitch_counts['warnings']} error={glitch_counts['errors']}",
    )
    if live:
        for scope, findings in (
            ("CDC", result.cdc),
            ("RDC", result.rdc),
            ("SETUP", result.setup),
            ("GLITCH", result.glitch),
        ):
            for index, finding in enumerate(findings, 1):
                crossing = finding.crossings[0] if finding.crossings else None
                route = ""
                if crossing is not None:
                    route = (
                        f" {crossing.source.name}[{crossing.source.bit_index}] -> "
                        f"{crossing.destination.name}[{crossing.destination.bit_index}]"
                    )
                print_status_label(
                    scope,
                    finding.status,
                    f"{scope}-{index:04d} {finding.classification}{route} "
                    f"issues={','.join(finding.issues) or '-'} "
                    f"obligations={','.join(finding.obligations) or '-'}",
                )

    summary = write_reports(
        ir,
        analysis,
        analysis_dir=analysis_dir,
        log_dir=log_dir,
        result=result,
    )
    if live:
        print_label("report", f"summary={analysis_dir / 'summary.json'}")
        print_label("report", f"obligations={analysis_dir / 'obligations.json'}")
        print_label("report", f"detail={log_dir / 'cdc_rdc.log'}")
    print_status_label(
        "cdc_rdc",
        summary["status"],
        f"clocks={summary['clock_domains']} resets={summary['reset_domains']} "
        f"sequential={summary['sequential_elements']} · "
        f"CDC raw={summary['cdc']['raw_crossings']} safe={summary['cdc']['safe']} "
        f"review={summary['cdc']['review']} warn={summary['cdc']['warnings']} "
        f"error={summary['cdc']['errors']} · "
        f"RDC raw={summary['rdc']['raw_crossings']} safe={summary['rdc']['safe']} "
        f"review={summary['rdc']['review']} warn={summary['rdc']['warnings']} "
        f"error={summary['rdc']['errors']} · "
        f"obligations={summary['verification_obligations']}",
    )
    if not live:
        print_log(log_dir / "cdc_rdc.log")
    return 2 if args.strict and summary["status"] == "fail" else 0


def setup_analysis(args: Any) -> int:
    """Write the deterministic pre-technology Yosys extraction script."""

    script = Path(args.script).resolve()
    design_json = Path(args.design_json).resolve()
    repo_root = Path(args.repo_root).resolve()
    filelists = tuple(Path(path).resolve() for path in args.filelist)
    missing = [path for path in filelists if not path.is_file()]
    if missing:
        raise FileNotFoundError("missing RTL filelist(s): " + ", ".join(str(path) for path in missing))
    script.parent.mkdir(parents=True, exist_ok=True)
    design_json.parent.mkdir(parents=True, exist_ok=True)
    text = render_extract_script(
        top=args.top,
        filelists=filelists,
        repo_root=repo_root,
        design_json=design_json,
    )
    script.write_text(text, encoding="utf-8")
    if _live():
        print_script(script, details={"state": "generated"})
    return 0


@dataclass(slots=True)
class CdcFlow:
    """Prepare and run structural CDC/RDC analysis with explicit inputs."""

    runner: object | None = None

    def setup(
        self,
        *,
        top: str,
        script: Path,
        design_json: Path,
        repo_root: Path,
        filelists: Sequence[Path],
    ) -> int:
        """Write the deterministic pre-technology extraction script."""

        from types import SimpleNamespace

        return setup_analysis(SimpleNamespace(
            top=top,
            script=str(script),
            design_json=str(design_json),
            repo_root=str(repo_root),
            filelist=[str(path) for path in filelists],
        ))

    def run(
        self,
        *,
        top: str,
        script: Path,
        design_json: Path,
        analysis_dir: Path,
        log_dir: Path,
        yosys: str = "yosys",
        n_clocks: int = 1,
        clock_domains: str = "",
        clock_relationships: str = "",
        clk_period: float = 10.0,
        heartbeat: float = 5.0,
        strict: bool = False,
        inputs: Sequence[Path] = (),
        on: str = "local",
    ) -> int:
        """Run CDC/RDC and write normalized reports."""

        from types import SimpleNamespace

        return run_analysis(SimpleNamespace(
            top=top,
            script=str(script),
            design_json=str(design_json),
            analysis_dir=str(analysis_dir),
            log_dir=str(log_dir),
            yosys=yosys,
            n_clocks=str(n_clocks),
            clock_domains=clock_domains,
            clock_relationships=clock_relationships,
            clk_period=str(clk_period),
            heartbeat=heartbeat,
            strict=strict,
        ), runner=self.runner, inputs=inputs, on=on)

    def run_from_context(
        self, context, *, inputs: Sequence[Path] = (), on: str = "local"
    ):
        """Run CDC/RDC from an already prepared extraction script."""

        paths, values = context.paths, context.values
        analysis = paths.run / "analysis" / "cdc_rdc"
        from flexsoc.backend.signoff.sdc import read_clock_config
        clocks = read_clock_config(paths.sdc, context.clocks)
        clock_values = clocks.to_settings()
        return self.run(
            top=paths.top, script=analysis / "extract.ys", design_json=analysis / "design.json",
            analysis_dir=analysis, log_dir=paths.logs / "analysis" / "cdc_rdc",
            yosys=values.get("YOSYS", "yosys"), n_clocks=clocks.n_clocks,
            clock_domains=clock_values["CLOCK_DOMAINS"],
            clock_relationships=clock_values["CLOCK_RELATIONSHIPS"],
            clk_period=clocks.fastest_period_ns,
            heartbeat=float(values.get("CDC_RDC_HEARTBEAT", "5")),
            strict=values.get("CDC_RDC_STRICT", "0") in {"1", "true", "yes"},
            inputs=inputs, on=on,
        )

    def flow_from_context(self, context, *, on: str = "local"):
        """Prepare and run CDC/RDC from one BackendContext."""

        paths = context.paths
        analysis = paths.run / "analysis" / "cdc_rdc"
        self.setup(
            top=paths.top, script=analysis / "extract.ys", design_json=analysis / "design.json",
            repo_root=context.project_root, filelists=(paths.rtl_common, paths.rtl_ip),
        )
        return self.run_from_context(context, on=on)

