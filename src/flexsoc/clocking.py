"""Canonical clock-domain configuration shared by FlexSoC backends."""

from __future__ import annotations

import os
from dataclasses import dataclass
from typing import Mapping


@dataclass(frozen=True, slots=True)
class ClockDomain:
    """One named clock/reset domain."""

    name: str
    signal: str
    reset: str
    period_ns: float
    reset_polarity: str = "low"

    def encode(self) -> str:
        return f"{self.name}:{self.signal}:{self.reset}:{self.period_ns:g}:{self.reset_polarity}"


@dataclass(frozen=True, slots=True)
class ClockRelationship:
    """Relationship between two named domains."""

    kind: str
    source: str
    target: str
    divide_by: int = 1

    def encode(self) -> str:
        suffix = f":{self.divide_by}" if self.kind == "generated" else ""
        return f"{self.kind}:{self.source}:{self.target}{suffix}"


@dataclass(frozen=True, slots=True)
class ClockConfig:
    """Clock domains plus explicitly declared relationships."""

    domains: tuple[ClockDomain, ...]
    relationships: tuple[ClockRelationship, ...] = ()

    @property
    def n_clocks(self) -> int:
        return len(self.domains)

    @property
    def multiclock(self) -> bool:
        return self.n_clocks > 1

    @property
    def fastest_period_ns(self) -> float:
        return min(domain.period_ns for domain in self.domains)

    def make_values(self) -> dict[str, str]:
        """Return the canonical Make/Python clock values."""

        return {
            "N_CLOCKS": str(self.n_clocks),
            "CLOCK_DOMAINS": ",".join(domain.encode() for domain in self.domains),
            "CLOCK_RELATIONSHIPS": ",".join(rel.encode() for rel in self.relationships),
            "CLK_PERIOD": f"{self.fastest_period_ns:g}",
        }


def _items(value: str | None) -> tuple[str, ...]:
    return tuple(item.strip() for item in (value or "").replace(";", ",").split(",") if item.strip())


def _domains(value: str) -> tuple[ClockDomain, ...]:
    domains: list[ClockDomain] = []
    for item in _items(value):
        parts = [part.strip() for part in item.split(":")]
        if len(parts) not in {4, 5}:
            raise ValueError(f"invalid CLOCK_DOMAINS entry {item!r}; expected name:clock:reset:period[:low|high]")
        name, signal, reset, period = parts[:4]
        polarity = parts[4].lower() if len(parts) == 5 else "low"
        if polarity not in {"low", "high"}:
            raise ValueError(f"invalid reset polarity {polarity!r} for clock domain {name!r}")
        try:
            period_ns = float(period)
        except ValueError as exc:
            raise ValueError(f"invalid clock period {period!r} for domain {name!r}") from exc
        if not name or not signal or not reset or period_ns <= 0:
            raise ValueError(f"invalid clock domain {item!r}")
        domains.append(ClockDomain(name, signal, reset, period_ns, polarity))
    names = [domain.name for domain in domains]
    signals = [domain.signal for domain in domains]
    if len(set(names)) != len(names) or len(set(signals)) != len(signals):
        raise ValueError("clock domain names and clock signals must be unique")
    return tuple(domains)


def _relationships(value: str, names: set[str]) -> tuple[ClockRelationship, ...]:
    relationships: list[ClockRelationship] = []
    for item in _items(value):
        parts = [part.strip() for part in item.split(":")]
        if len(parts) not in {3, 4}:
            raise ValueError(f"invalid CLOCK_RELATIONSHIPS entry {item!r}; expected kind:source:target[:divide_by]")
        kind, source, target = parts[:3]
        kind = kind.lower()
        if kind not in {"async", "sync", "generated"}:
            raise ValueError(f"invalid clock relationship kind {kind!r}")
        if source not in names or target not in names or source == target:
            raise ValueError(f"invalid clock relationship endpoints in {item!r}")
        divide_by = 1
        if kind == "generated":
            try:
                divide_by = int(parts[3]) if len(parts) == 4 else 1
            except ValueError as exc:
                raise ValueError(f"invalid generated-clock divider in {item!r}") from exc
            if divide_by <= 0:
                raise ValueError(f"generated-clock divider must be positive in {item!r}")
        elif len(parts) == 4:
            raise ValueError(f"only generated clock relationships accept a divider: {item!r}")
        relationships.append(ClockRelationship(kind, source, target, divide_by))
    return tuple(relationships)


def clock_config(values: Mapping[str, object] | None = None) -> ClockConfig:
    """Parse the canonical N_CLOCKS/CLOCK_* settings."""

    raw = {str(key).upper(): str(value) for key, value in (values or os.environ).items() if value is not None}
    domains_text = raw.get("CLOCK_DOMAINS", "").strip()
    relationships_text = raw.get("CLOCK_RELATIONSHIPS", "").strip()
    requested = int(raw.get("N_CLOCKS", "1") or "1")
    if requested < 1:
        raise ValueError("N_CLOCKS must be >= 1")

    if domains_text:
        domains = _domains(domains_text)
    elif requested == 1:
        period = float(raw.get("CLK_PERIOD", "10") or "10")
        domains = (ClockDomain("core", "clk_i", "rst_ni", period),)
    else:
        raise ValueError("CLOCK_DOMAINS is required when N_CLOCKS > 1")

    if requested != len(domains):
        raise ValueError(f"N_CLOCKS={requested} but CLOCK_DOMAINS defines {len(domains)} domain(s)")
    relationships = _relationships(relationships_text, {domain.name for domain in domains})
    return ClockConfig(domains, relationships)
