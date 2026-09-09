"""Structural CDC/RDC analysis and qualification."""

from __future__ import annotations

from collections import Counter
from dataclasses import asdict, dataclass
import json
import os
from pathlib import Path
import re
import subprocess
import threading
import time
from typing import Any, Callable, Mapping, Sequence, TypeVar

from flexsoc.backend.core import ClockConfig, ClockDomain, clock_config
from flexsoc.backend.core.execution import print_label, print_script, print_status_label
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


_CDC_CONTRACT_ATTR = "flexsoc_cdc_contract"
_CDC_DOMAIN_ATTR = "flexsoc_cdc_domain"
_CDC_SOURCE_DOMAIN_ATTR = "flexsoc_cdc_source_domain"
_CDC_DESTINATION_DOMAIN_ATTR = "flexsoc_cdc_destination_domain"
_CDC_CLOCK_IN_PORT_ATTR = "flexsoc_cdc_clock_in_port"
_CDC_CLOCK_OUT_PORT_ATTR = "flexsoc_cdc_clock_out_port"
_CDC_SOURCE_CLOCK_PORT_ATTR = "flexsoc_cdc_source_clock_port"
_CDC_DESTINATION_CLOCK_PORT_ATTR = "flexsoc_cdc_destination_clock_port"
_CDC_SOURCE_RESET_PORT_ATTR = "flexsoc_cdc_source_reset_port"
_CDC_DESTINATION_RESET_PORT_ATTR = "flexsoc_cdc_destination_reset_port"
_CDC_PARTIAL_RESET_SAFE_ATTR = "flexsoc_cdc_partial_reset_safe"


def _attribute_text(item: Mapping[str, Any], name: str) -> str | None:
    """Return one normalized Yosys attribute value."""

    value = item.get("attributes", {}).get(name)
    if value is None:
        return None
    text = str(value).strip().strip('"')
    return text or None


def _attribute_bool(item: Mapping[str, Any], name: str) -> bool:
    value = (_attribute_text(item, name) or "").lower()
    return value in {"1", "true", "yes", "on"} or (set(value) <= {"0", "1"} and value.endswith("1"))


def _cdc_contract(item: Mapping[str, Any]) -> str | None:
    return (_attribute_text(item, _CDC_CONTRACT_ATTR) or "").lower() or None


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
    """Map primary and explicitly contracted internal clocks to logical domains."""

    names = _net_names(module)
    by_name = {name.split("[")[0]: bit for bit, name in names.items()}
    result: dict[NetBit, str] = {}
    known_domains = {domain.name for domain in clocks.domains}
    for domain in clocks.domains:
        port = module.get("ports", {}).get(domain.signal)
        bits = tuple(port.get("bits", ())) if port else ()
        if not bits and domain.signal in by_name:
            bits = (by_name[domain.signal],)
        if len(bits) == 1:
            result[bits[0]] = domain.name

    # Clock-gate contracts are explicit design intent. Resolve them iteratively
    # so cascaded glitch-free gates can inherit their declared parent domain.
    pending = [
        (name, cell)
        for name, cell in module.get("cells", {}).items()
        if _cdc_contract(cell) == "clock_gate"
    ]
    while pending:
        unresolved: list[tuple[str, Mapping[str, Any]]] = []
        progress = False
        for name, cell in pending:
            domain = _attribute_text(cell, _CDC_DOMAIN_ATTR)
            in_port = _attribute_text(cell, _CDC_CLOCK_IN_PORT_ATTR)
            out_port = _attribute_text(cell, _CDC_CLOCK_OUT_PORT_ATTR)
            if domain not in known_domains:
                raise ValueError(f"clock-gate contract {name!r} references unknown domain {domain!r}")
            if not in_port or not out_port:
                raise ValueError(f"clock-gate contract {name!r} is missing clock port metadata")
            in_bits = tuple(cell.get("connections", {}).get(in_port, ()))
            out_bits = tuple(cell.get("connections", {}).get(out_port, ()))
            if len(in_bits) != 1 or len(out_bits) != 1:
                raise ValueError(f"clock-gate contract {name!r} requires scalar clock ports")
            parent = result.get(in_bits[0])
            if parent is None:
                unresolved.append((name, cell))
                continue
            if parent != domain:
                raise ValueError(
                    f"clock-gate contract {name!r} declares domain {domain!r} but parent clock belongs to {parent!r}"
                )
            previous = result.get(out_bits[0])
            if previous not in {None, domain}:
                raise ValueError(f"clock-gate output for {name!r} has conflicting domain intent")
            result[out_bits[0]] = domain
            progress = True
        if unresolved and not progress:
            names_text = ", ".join(name for name, _ in unresolved)
            raise ValueError(f"clock-gate contract parent clock is unresolved: {names_text}")
        pending = unresolved
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
        if name in seq_by_name or _cdc_contract(cell) == "async_fifo":
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


def _reset_bit(seq: SequentialElement) -> NetBit | None:
    """Return the effective reset bit of one sequential element."""

    return seq.async_reset_bit if seq.async_reset_bit is not None else seq.sync_reset_bit

def _reset_stage_deasserted_value(seq: SequentialElement) -> str | None:
    """Return the constant D value expected for a pure reset-release stage."""

    if seq.reset_polarity == "low":
        return "1"
    if seq.reset_polarity == "high":
        return "0"
    return None

def _reset_tree_stage_names(
    ir: DesignIR,
    dependencies: Sequence[Crossing],
) -> set[str]:
    """Return sequential cells that are pure reset synchronizer/distribution stages.

    Recognition is structural and depth-independent. A stage must be scalar, have
    a reset, and either drive the deasserted constant while its parent reset is
    asserted or continue a direct same-reset synchronizer chain. Arbitrary data
    logic is deliberately excluded so reset controllers/gating remain separate
    RDC families.
    """

    seq_by_name = {seq.name: seq for seq in ir.sequential}
    direct_parent: dict[str, str] = {}
    for dep in dependencies:
        if dep.path or dep.destination.bit_index != 0 or dep.source.bit_index != 0:
            continue
        if dep.destination.name in direct_parent:
            direct_parent[dep.destination.name] = ""
        else:
            direct_parent[dep.destination.name] = dep.source.name

    stages: set[str] = set()
    changed = True
    while changed:
        changed = False
        for seq in ir.sequential:
            if seq.name in stages or _reset_bit(seq) is None:
                continue
            if len(seq.data_bits) != 1 or len(seq.q_bits) != 1:
                continue
            expected = _reset_stage_deasserted_value(seq)
            if expected is None:
                continue
            if seq.data_bits[0] == expected:
                stages.add(seq.name)
                changed = True
                continue
            parent = seq_by_name.get(direct_parent.get(seq.name, ""))
            if parent is None or parent.name not in stages:
                continue
            if _reset_bit(parent) != _reset_bit(seq):
                continue
            if parent.reset_polarity != seq.reset_polarity:
                continue
            stages.add(seq.name)
            changed = True
    return stages

def _reset_family_map(
    ir: DesignIR,
    dependencies: Sequence[Crossing] | None = None,
) -> dict[str, str]:
    """Map reset consumers to the root of their structural reset family.

    A reset family follows the complete ancestry of a pure reset tree, not one
    fixed split level. Alias/buffer/inverter paths and arbitrarily deep scalar
    reset-release/distribution stages inherit the same declared reset root. When
    lineage crosses dynamic logic or an unrecognized state element, tracing stops
    conservatively and that derived reset remains a distinct family.
    """

    deps = tuple(dependencies) if dependencies is not None else _sequential_dependencies(ir, ClockConfig(ir.clocks))
    declared: dict[NetBit, str] = {}
    for domain in ir.clocks:
        port = ir.module.get("ports", {}).get(domain.reset)
        if port:
            for bit in port.get("bits", ()):
                declared[bit] = domain.reset

    sources, drivers, cells = _graph(ir)
    seq_by_name = {seq.name: seq for seq in ir.sequential}
    tree_stages = _reset_tree_stage_names(ir, deps)
    simple_reset_cells = {"$not", "$pos", "$_NOT_", "$_BUF_"}
    inversion_cells = {"$not", "$_NOT_"}
    domain_reset_polarity = {domain.reset: domain.reset_polarity for domain in ir.clocks}
    memo: dict[str, str] = {}
    active: set[str] = set()

    def path_polarity(origin: str | None, path: tuple[str, ...]) -> str | None:
        if origin not in {"low", "high"}:
            return None
        polarity = origin
        for cell_name in path:
            cell_type = str(cells.get(cell_name, {}).get("type", ""))
            if cell_type not in simple_reset_cells:
                return None
            if cell_type in inversion_cells:
                polarity = "high" if polarity == "low" else "low"
        return polarity

    def family(seq: SequentialElement) -> str:
        cached = memo.get(seq.name)
        if cached is not None:
            return cached
        fallback = seq.reset_signal or "-"
        if seq.name in active:
            return fallback
        active.add(seq.name)
        try:
            bit = _reset_bit(seq)
            if bit is None:
                result = fallback
            elif bit in declared:
                result = declared[bit]
            else:
                upstream = _upstream_sources(
                    bit, sources=sources, drivers=drivers, cells=cells, memo={}, active=set()
                )
                candidates: list[str] = []
                for endpoint, path in upstream:
                    if any(
                        str(cells.get(name, {}).get("type", "")) not in simple_reset_cells
                        for name in path
                    ):
                        continue
                    if endpoint.kind == "input":
                        port = ir.module.get("ports", {}).get(endpoint.name, {})
                        bits = tuple(port.get("bits", ()))
                        if endpoint.bit_index < len(bits) and bits[endpoint.bit_index] in declared:
                            root = declared[bits[endpoint.bit_index]]
                            if path_polarity(domain_reset_polarity.get(root), path) == seq.reset_polarity:
                                candidates.append(root)
                    elif endpoint.kind == "seq" and endpoint.name in tree_stages:
                        parent = seq_by_name.get(endpoint.name)
                        if parent is not None and path_polarity(parent.reset_polarity, path) == seq.reset_polarity:
                            candidates.append(family(parent))
                unique = sorted(set(candidates))
                result = unique[0] if len(unique) == 1 else fallback
            memo[seq.name] = result
            return result
        finally:
            active.remove(seq.name)

    return {
        seq.name: family(seq)
        for seq in ir.sequential
        if _reset_bit(seq) is not None
    }

def analyze_domains(ir: DesignIR, clocks: ClockConfig) -> DomainAnalysis:
    """Build the dependency graph once and derive both CDC and RDC views."""

    dependencies = _sequential_dependencies(ir, clocks)
    clock_crossings = tuple(
        crossing
        for crossing in dependencies
        if crossing.source.clock_domain != crossing.destination.clock_domain
    )
    reset_families = _reset_family_map(ir, dependencies)
    reset_crossings = tuple(
        crossing
        for crossing in dependencies
        if crossing.source.reset_signal is not None
        and crossing.destination.reset_signal is not None
        and reset_families.get(crossing.source.name, crossing.source.reset_signal)
        != reset_families.get(crossing.destination.name, crossing.destination.reset_signal)
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
    clock_bits = set(_domain_bit_map(ir.module, ClockConfig(ir.clocks)))
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

    reset_families = _reset_family_map(ir, analysis.dependencies)
    families_by_clock: dict[str, set[str]] = {}
    leaves_by_clock_family: dict[tuple[str, str], set[str]] = {}
    for seq in ir.sequential:
        if not seq.clock_domain or not seq.reset_signal:
            continue
        family = reset_families.get(seq.name, seq.reset_signal)
        families_by_clock.setdefault(seq.clock_domain, set()).add(family)
        leaves_by_clock_family.setdefault((seq.clock_domain, family), set()).add(seq.reset_signal)
    for clock, families in sorted(families_by_clock.items()):
        if len(families) > 1:
            setup.append(DomainFinding(
                "setup", "INFO", "multiple_reset_domains_on_clock",
                issues=(f"clock_domain={clock}",),
                evidence=tuple(sorted(families)),
            ))
        for family in sorted(families):
            leaves = leaves_by_clock_family.get((clock, family), set())
            if len(leaves) > 1:
                setup.append(DomainFinding(
                    "setup", "INFO", "distributed_reset_family",
                    issues=(f"clock_domain={clock}", f"reset_family={family}"),
                    evidence=tuple(sorted(leaves)),
                    primary=False,
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
                ("minimum_pulse_width_or_sampling_window",) if sync.status == "WARN" else (),
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
    """Request reset sequencing only when an interacting RDC is not already SAFE."""

    unsafe = any(
        finding.primary and finding.crossings and finding.status in {"ERROR", "WARN", "REVIEW"}
        for finding in rdc
    )
    if (
        unsafe
        and len(set(_reset_family_map(ir, analysis.dependencies).values())) > 1
        and analysis.reset_crossings
    ):
        rdc.append(DomainFinding(
            "rdc", "REVIEW", "reset_sequence_or_control_required", (),
            obligations=("specify_reset_assertion_sequence_or_rdc_blocking_control",),
            primary=False,
        ))

def _cdc_contract_findings(ir: DesignIR) -> tuple[list[DomainFinding], list[DomainFinding]]:
    """Validate explicit trusted CDC boundaries without naming implementation modules."""

    cdc: list[DomainFinding] = []
    setup: list[DomainFinding] = []
    clocks = ClockConfig(ir.clocks)
    domain_by_bit = _domain_bit_map(ir.module, clocks)
    known_domains = {domain.name for domain in ir.clocks}
    names = _net_names(ir.module)
    for name, cell in ir.module.get("cells", {}).items():
        contract = _cdc_contract(cell)
        if contract is None or contract == "clock_gate":
            continue
        if contract != "async_fifo":
            setup.append(DomainFinding(
                "setup", "ERROR", "unsupported_cdc_contract", (),
                issues=(f"cell={name}", f"contract={contract}"),
                primary=False,
            ))
            continue
        src_domain = _attribute_text(cell, _CDC_SOURCE_DOMAIN_ATTR)
        dst_domain = _attribute_text(cell, _CDC_DESTINATION_DOMAIN_ATTR)
        src_clk_port = _attribute_text(cell, _CDC_SOURCE_CLOCK_PORT_ATTR)
        dst_clk_port = _attribute_text(cell, _CDC_DESTINATION_CLOCK_PORT_ATTR)
        src_rst_port = _attribute_text(cell, _CDC_SOURCE_RESET_PORT_ATTR)
        dst_rst_port = _attribute_text(cell, _CDC_DESTINATION_RESET_PORT_ATTR)
        partial_reset_safe = _attribute_bool(cell, _CDC_PARTIAL_RESET_SAFE_ATTR)
        if src_domain not in known_domains or dst_domain not in known_domains or src_domain == dst_domain:
            setup.append(DomainFinding(
                "setup", "ERROR", "invalid_async_fifo_contract", (),
                issues=(f"cell={name}", f"domains={src_domain}->{dst_domain}"),
                primary=False,
            ))
            continue
        required_ports = (src_clk_port, dst_clk_port, src_rst_port, dst_rst_port)
        if any(not port for port in required_ports):
            setup.append(DomainFinding(
                "setup", "ERROR", "invalid_async_fifo_contract", (),
                issues=(f"cell={name}", "missing_clock_or_reset_port_metadata"),
                primary=False,
            ))
            continue
        connections = cell.get("connections", {})
        src_clk_bits = tuple(connections.get(str(src_clk_port), ()))
        dst_clk_bits = tuple(connections.get(str(dst_clk_port), ()))
        src_rst_bits = tuple(connections.get(str(src_rst_port), ()))
        dst_rst_bits = tuple(connections.get(str(dst_rst_port), ()))
        if not all(len(bits) == 1 for bits in (src_clk_bits, dst_clk_bits, src_rst_bits, dst_rst_bits)):
            setup.append(DomainFinding(
                "setup", "ERROR", "invalid_async_fifo_contract", (),
                issues=(f"cell={name}", "clock_and_reset_ports_must_be_scalar"),
                primary=False,
            ))
            continue
        observed = (domain_by_bit.get(src_clk_bits[0]), domain_by_bit.get(dst_clk_bits[0]))
        if observed != (src_domain, dst_domain):
            setup.append(DomainFinding(
                "setup", "ERROR", "async_fifo_clock_domain_mismatch", (),
                issues=(f"cell={name}", f"declared={src_domain}->{dst_domain}", f"observed={observed[0]}->{observed[1]}"),
                primary=False,
            ))
            continue
        status = "SAFE" if partial_reset_safe else "REVIEW"
        obligations = () if partial_reset_safe else ("prove_protocol_safe_across_independent_reset_events",)
        cdc.append(DomainFinding(
            "cdc", status, "async_fifo_contract", (),
            obligations=obligations,
            evidence=(
                f"cell={name}",
                f"domains={src_domain}->{dst_domain}",
                f"source_reset={names.get(src_rst_bits[0], src_rst_port)}",
                f"destination_reset={names.get(dst_rst_bits[0], dst_rst_port)}",
                f"partial_reset_safe={str(partial_reset_safe).lower()}",
            ),
            primary=False,
        ))
    return cdc, setup


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

    contract_cdc, contract_setup = _cdc_contract_findings(ir)
    cdc.extend(contract_cdc)

    # SETUP_GLITCH_CHECK_ORDER: environment/domain setup and combinational hazards.
    setup, glitch = _setup_and_glitch_findings(ir, analysis)
    setup = (*setup, *contract_setup)

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
    options = [
        *(f"-I {path}" for path in include_dirs),
        "-D SYNTHESIS",
        "-D FLEXSOC_CDC_ANALYSIS",
        # read_slang flattens hierarchy during frontend elaboration by default.
        # CDC contracts are instance-level intent, so preserve hierarchy until
        # Yosys can mark only contracted boundaries before the explicit flatten.
        "--keep-hierarchy",
        "--ignore-assertions",
    ]
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
        # Contract cells are trusted CDC boundaries. Set keep_hierarchy on the
        # selected cell objects explicitly; all other hierarchy is flattened.
        "setattr -set keep_hierarchy 1 a:flexsoc_cdc_contract",
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
    reset_family_roots = sorted(set(_reset_family_map(ir, analysis.dependencies).values()))
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
        "reset_families": len(reset_family_roots),
        "reset_family_roots": reset_family_roots,
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
    """Write one complete machine analysis and one human-readable report."""

    analysis_dir.mkdir(parents=True, exist_ok=True)
    log_dir.mkdir(parents=True, exist_ok=True)
    classified = result if result is not None else classify_cdc_rdc(ir, analysis)
    cdc_records = _finding_records(classified.cdc)
    rdc_records = _finding_records(classified.rdc)
    setup_records = _finding_records(classified.setup)
    glitch_records = _finding_records(classified.glitch)
    summary = _summary(ir, analysis, classified)
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
    summary = {
        **summary,
        "schema": "flexsoc.cdc_rdc.v3",
        "cdc": {
            **summary["cdc"],
            "findings": cdc_records,
            "crossings": _crossing_records(analysis.clock_crossings, classified.cdc),
        },
        "rdc": {
            **summary["rdc"],
            "findings": rdc_records,
            "crossings": _crossing_records(analysis.reset_crossings, classified.rdc),
        },
        "setup": {**summary["setup"], "findings": setup_records},
        "glitch": {**summary["glitch"], "findings": glitch_records},
        "obligations": obligations,
    }

    summary_path = analysis_dir / "summary.json"
    report_path = analysis_dir / "cdc_rdc.rpt"
    _write_json(summary_path, summary)
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
    report_path.write_text("\n".join(lines) + "\n", encoding="utf-8")

    # Clean outputs from the older split-report contract when rerunning an existing workspace.
    for name in (
        "inventory.json", "cdc.json", "rdc.json", "setup.json",
        "glitch.json", "obligations.json",
    ):
        (analysis_dir / name).unlink(missing_ok=True)
    for name in ("cdc.log", "rdc.log", "cdc_rdc.log"):
        (log_dir / name).unlink(missing_ok=True)
    return summary


# ---------------------------------------------------------------------------
# Read-only debug/triage of canonical CDC/RDC artifacts
# ---------------------------------------------------------------------------

_NON_PASS = {"ERROR", "WARN", "REVIEW"}
_CONTRACT_RE = re.compile(r"flexsoc_cdc_contract\s*=\s*[\"']([^\"']+)[\"']")


def _load_json(path: Path) -> dict[str, Any]:
    if not path.is_file():
        raise FileNotFoundError(f"CDC/RDC artifact not found: {path}; run `fx cdc_rdc` first")
    data = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(data, dict):
        raise ValueError(f"CDC/RDC artifact is not a JSON object: {path}")
    return data


def _source_contracts(rtl_dir: Path) -> Counter[str]:
    contracts: Counter[str] = Counter()
    if not rtl_dir.is_dir():
        return contracts
    for path in sorted((*rtl_dir.glob("*.sv"), *rtl_dir.glob("*.v"))):
        text = path.read_text(encoding="utf-8", errors="replace")
        contracts.update(match.group(1).strip().lower() for match in _CONTRACT_RE.finditer(text))
    return contracts


def _design_contracts(design: Mapping[str, Any], top: str) -> Counter[str]:
    contracts: Counter[str] = Counter()
    module = design.get("modules", {}).get(top, {})
    for cell in module.get("cells", {}).values():
        value = cell.get("attributes", {}).get("flexsoc_cdc_contract")
        if value is None:
            continue
        text = str(value).strip().strip('"').lower()
        if text:
            contracts[text] += 1
    return contracts


def _scope_payload(summary: Mapping[str, Any], scope: str) -> dict[str, Any]:
    section = summary.get(scope, {})
    findings = section.get("findings", []) if isinstance(section, dict) else []
    non_pass = [
        item for item in findings
        if isinstance(item, dict) and str(item.get("status", "")).upper() in _NON_PASS
    ]
    classes = Counter(str(item.get("classification", "unknown")) for item in non_pass)
    samples: list[dict[str, Any]] = []
    seen: set[str] = set()
    for item in non_pass:
        classification = str(item.get("classification", "unknown"))
        if classification in seen:
            continue
        seen.add(classification)
        samples.append({
            "id": item.get("id"),
            "status": item.get("status"),
            "classification": classification,
            "issues": list(item.get("issues") or ()),
            "evidence": list(item.get("evidence") or ()),
            "obligations": list(item.get("obligations") or ()),
        })
    return {
        "errors": int(section.get("errors", 0) or 0),
        "warnings": int(section.get("warnings", 0) or 0),
        "review": int(section.get("review", 0) or 0),
        "safe": int(section.get("safe", 0) or 0),
        "info": int(section.get("info", 0) or 0),
        "classes": dict(sorted(classes.items())),
        "samples": samples,
    }


def _contract_guard_state(
    *, source_contracts: Counter[str], design_contracts: Counter[str], guard_present: bool
) -> str:
    source_total = sum(source_contracts.values())
    design_total = sum(design_contracts.values())
    if source_total == 0:
        return "not_applicable"
    if design_total >= source_total:
        return "effective" if guard_present else "survived_without_guard"
    if design_total > 0:
        return "partial" if guard_present else "partial_without_guard"
    return "present_but_ineffective" if guard_present else "missing"


def _diagnoses(
    summary: Mapping[str, Any],
    scopes: Mapping[str, Mapping[str, Any]],
    *,
    source_contracts: Counter[str],
    design_contracts: Counter[str],
    guard_state: str,
) -> list[dict[str, str]]:
    diagnoses: list[dict[str, str]] = []
    setup_classes = scopes["setup"]["classes"]
    glitch_classes = scopes["glitch"]["classes"]

    source_total = sum(source_contracts.values())
    design_total = sum(design_contracts.values())
    if source_total and not design_total:
        diagnoses.append({
            "code": "contract_lost_in_extraction",
            "severity": "ERROR",
            "message": (
                "Explicit flexsoc_cdc_contract markers exist in RTL but no contracted cell survives in the "
                "top-level structural design. Fix extraction before interpreting downstream CDC/RDC findings."
            ),
        })
    elif source_total and design_total < source_total:
        diagnoses.append({
            "code": "contract_partially_preserved",
            "severity": "ERROR",
            "message": "Only part of the explicit CDC contract boundary set survives structural extraction.",
        })
    elif guard_state == "survived_without_guard":
        diagnoses.append({
            "code": "extract_contract_guard_missing",
            "severity": "WARN",
            "message": "Contracts currently survive, but extraction does not explicitly protect contracted cells before flattening.",
        })

    if setup_classes.get("unassigned_clock_domain") or glitch_classes.get("combinational_clock_path"):
        diagnoses.append({
            "code": "clock_domain_mapping_incomplete",
            "severity": "ERROR",
            "message": "Sequential state is clocked through a network that the structural IR has not assigned to a declared domain.",
        })

    # Once extraction/domain setup is known broken, detailed CDC/RDC classifications
    # are downstream symptoms. Keep them in JSON, but do not promote each family to
    # another root-cause diagnosis.
    extraction_broken = source_total > design_total
    mapping_broken = bool(
        setup_classes.get("unassigned_clock_domain") or glitch_classes.get("combinational_clock_path")
    )
    if not extraction_broken and not mapping_broken:
        if scopes["cdc"]["errors"]:
            diagnoses.append({
                "code": "cdc_errors_remain",
                "severity": "ERROR",
                "message": "CDC structural errors remain after extraction and clock/domain setup are closed.",
            })
        if scopes["rdc"]["errors"]:
            diagnoses.append({
                "code": "rdc_errors_remain",
                "severity": "ERROR",
                "message": "RDC structural errors remain after extraction and reset-domain setup are closed.",
            })

    non_error_review = sum(
        int(scopes[name]["warnings"]) + int(scopes[name]["review"])
        for name in ("setup", "glitch", "cdc", "rdc")
    )
    cdc_non_pass_classes = set(scopes["cdc"]["classes"])
    reconvergence_only = (
        not any(item["severity"] == "ERROR" for item in diagnoses)
        and non_error_review
        and cdc_non_pass_classes == {"synchronized_reconvergence"}
        and not any(
            int(scopes[name]["warnings"]) + int(scopes[name]["review"])
            for name in ("setup", "glitch", "rdc")
        )
    )
    if reconvergence_only:
        diagnoses.append({
            "code": "synchronized_reconvergence_only",
            "severity": "REVIEW",
            "message": (
                "Only synchronized reconvergence remains. Prefer removing unnecessary cross-domain controls or "
                "using an explicit coherent transfer before adding a waiver or weakening the checker."
            ),
        })
    elif not any(item["severity"] == "ERROR" for item in diagnoses) and non_error_review:
        diagnoses.append({
            "code": "review_required",
            "severity": "REVIEW",
            "message": "No structural ERROR remains, but WARN/REVIEW findings still require design-intent confirmation or evidence.",
        })

    obligations = summary.get("obligations", []) or []
    if not any(item["severity"] == "ERROR" for item in diagnoses) and obligations:
        diagnoses.append({
            "code": "open_verification_obligations",
            "severity": "REVIEW",
            "message": "Structural classification is not fully closed because verification obligations remain open.",
        })

    if str(summary.get("status", "")).lower() == "pass" and not diagnoses:
        diagnoses.append({
            "code": "closed",
            "severity": "PASS",
            "message": "CDC/RDC structural closure is complete for the recorded analysis.",
        })
    return diagnoses


def _triage(
    scopes: Mapping[str, Mapping[str, Any]],
    diagnoses: list[dict[str, str]],
) -> dict[str, str]:
    codes = {item["code"] for item in diagnoses}
    if {"contract_lost_in_extraction", "contract_partially_preserved"} & codes:
        return {
            "phase": "extraction",
            "state": "BLOCKED",
            "next_action": "Preserve explicit CDC contract cells in design.json, then rerun CDC/RDC before interpreting downstream crossings.",
            "downstream": "deferred",
        }
    if "clock_domain_mapping_incomplete" in codes:
        return {
            "phase": "clock_reset_setup",
            "state": "BLOCKED",
            "next_action": "Close unassigned clock domains and combinational clock/reset paths before classifying CDC/RDC protocols.",
            "downstream": "deferred",
        }
    if scopes["cdc"]["errors"]:
        return {
            "phase": "cdc",
            "state": "BLOCKED",
            "next_action": "Resolve the remaining CDC ERROR classes, then rerun and inspect RDC.",
            "downstream": "active",
        }
    if scopes["rdc"]["errors"]:
        return {
            "phase": "rdc",
            "state": "BLOCKED",
            "next_action": "Resolve reset-domain protection or reset sequencing for the remaining RDC ERROR classes.",
            "downstream": "active",
        }
    if "synchronized_reconvergence_only" in codes:
        return {
            "phase": "cdc_reconvergence",
            "state": "REVIEW",
            "next_action": (
                "Remove unnecessary independently synchronized controls or replace them with an explicit coherent "
                "transfer; rerun CDC before considering any waiver."
            ),
            "downstream": "active",
        }
    if any(int(scopes[name]["warnings"]) + int(scopes[name]["review"]) for name in scopes):
        return {
            "phase": "review",
            "state": "REVIEW",
            "next_action": "Discharge remaining review obligations with explicit design intent or verification evidence.",
            "downstream": "active",
        }
    return {
        "phase": "closed",
        "state": "PASS",
        "next_action": "CDC/RDC structural closure is complete for this recorded analysis.",
        "downstream": "closed",
    }


def collect_cdc_debug(
    *,
    summary_path: Path,
    design_json: Path,
    extract_script: Path,
    rtl_dir: Path,
) -> dict[str, Any]:
    """Return a compact diagnosis from existing canonical CDC/RDC artifacts only."""

    summary = _load_json(summary_path)
    design = _load_json(design_json)
    top = str(summary.get("top") or "")
    if not top:
        raise ValueError(f"CDC/RDC summary has no top: {summary_path}")

    source_contracts = _source_contracts(rtl_dir)
    design_contracts = _design_contracts(design, top)
    extract_text = extract_script.read_text(encoding="utf-8", errors="replace") if extract_script.is_file() else ""
    frontend_hierarchy = "--keep-hierarchy" in extract_text
    selective_guard = (
        "setattr -set keep_hierarchy 1 a:flexsoc_cdc_contract" in extract_text
        or "keep_hierarchy a:flexsoc_cdc_contract" in extract_text
    )
    guard_present = frontend_hierarchy and selective_guard
    guard_state = _contract_guard_state(
        source_contracts=source_contracts,
        design_contracts=design_contracts,
        guard_present=guard_present,
    )
    scopes = {name: _scope_payload(summary, name) for name in ("setup", "glitch", "cdc", "rdc")}
    obligations = [
        {
            "finding_id": item.get("finding_id"),
            "scope": item.get("scope"),
            "classification": item.get("classification"),
            "obligations": list(item.get("obligations") or ()),
        }
        for item in (summary.get("obligations", []) or [])
        if isinstance(item, dict)
    ]
    obligation_checks = sum(len(item["obligations"]) for item in obligations)
    diagnoses = _diagnoses(
        summary,
        scopes,
        source_contracts=source_contracts,
        design_contracts=design_contracts,
        guard_state=guard_state,
    )
    triage = _triage(scopes, diagnoses)
    return {
        "schema": "flexsoc.cdc_rdc_debug.v2",
        "top": top,
        "status": summary.get("status"),
        "clock_domains": summary.get("clock_domains"),
        "reset_domains": summary.get("reset_domains"),
        "reset_families": summary.get("reset_families", summary.get("reset_domains")),
        "reset_family_roots": list(summary.get("reset_family_roots") or ()),
        "sequential_elements": summary.get("sequential_elements"),
        "verification_obligations": obligation_checks,
        "obligation_findings": len(obligations),
        "contracts": {
            "source": dict(sorted(source_contracts.items())),
            "structural_design": dict(sorted(design_contracts.items())),
            "frontend_hierarchy_preserved": frontend_hierarchy,
            "selective_contract_guard": selective_guard,
            "extract_guard": guard_present,
            "extract_guard_state": guard_state,
        },
        "triage": triage,
        "scopes": scopes,
        "diagnoses": diagnoses,
        "obligations": obligations,
        "artifacts": {
            "summary": str(summary_path),
            "design_json": str(design_json),
            "extract_script": str(extract_script),
            "rtl_dir": str(rtl_dir),
        },
    }


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
        raise FileNotFoundError(f"missing CDC/RDC extraction script: {script}; run `fx cdc_rdc --setup`")
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
    print_status_label(
        "cdc_rdc",
        summary["status"],
        f"clocks={summary['clock_domains']} reset_families={summary.get('reset_families', summary['reset_domains'])} "
        f"reset_signals={summary['reset_domains']} sequential={summary['sequential_elements']} · "
        f"CDC raw={summary['cdc']['raw_crossings']} safe={summary['cdc']['safe']} "
        f"review={summary['cdc']['review']} warn={summary['cdc']['warnings']} "
        f"error={summary['cdc']['errors']} · "
        f"RDC raw={summary['rdc']['raw_crossings']} safe={summary['rdc']['safe']} "
        f"review={summary['rdc']['review']} warn={summary['rdc']['warnings']} "
        f"error={summary['rdc']['errors']} · "
        f"obligations={summary['verification_obligations']}",
    )
    print_label("report", str(analysis_dir / "cdc_rdc.rpt"))
    print_label("summary", str(analysis_dir / "summary.json"))
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

    def debug(
        self,
        *,
        summary_path: Path,
        design_json: Path,
        extract_script: Path,
        rtl_dir: Path,
    ) -> dict[str, Any]:
        """Read canonical CDC/RDC artifacts and return compact root-cause triage."""

        return collect_cdc_debug(
            summary_path=summary_path,
            design_json=design_json,
            extract_script=extract_script,
            rtl_dir=rtl_dir,
        )

    def debug_from_context(self, context) -> dict[str, Any]:
        """Read CDC/RDC debug state from one BackendContext without rerunning analysis."""

        paths = context.paths
        analysis = paths.run / "analysis" / "cdc_rdc"
        return self.debug(
            summary_path=analysis / "summary.json",
            design_json=analysis / "design.json",
            extract_script=analysis / "extract.ys",
            rtl_dir=paths.rtl,
        )

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

