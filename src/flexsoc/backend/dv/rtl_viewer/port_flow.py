"""Conservative alias normalization for internally reused RTL output ports.

A module output is a boundary sink. It can also be read *inside* its module,
including as an always_ff clock. If its *sole* elaborated driver is a direct
continuous assignment from another signal, all of its internal consumers may
be routed from that original driver without going backwards through the output
port glyph. This is a presentation of a proven conductor, not logic synthesis.

Do not rewrite multiple drivers, expressions, slices, unknown widths or other
cases where the compiler has not proved this exact alias relationship.
"""
from __future__ import annotations
from collections import Counter
from typing import Any, Mapping


def _address(ref: Any) -> str:
    if isinstance(ref, dict):
        ref = ref.get("addr")
    return str(ref or "").partition(" ")[0]


def _walk(node: Any):
    if isinstance(node, dict):
        yield node
        for value in node.values():
            if isinstance(value, (dict, list)):
                yield from _walk(value)
    elif isinstance(node, list):
        for child in node:
            yield from _walk(child)


def proven_output_aliases(members: list[dict], signals: Mapping[str, Mapping],
                          relations: list[dict]) -> dict[str, str]:
    """Return output -> driver for unique, bit-width-compatible AST aliases."""
    # A NamedValue symbol points to the backing Variable, not the Port object.
    owned: dict[str, set[str]] = {}
    for item in members:
        if not isinstance(item, dict) or item.get("kind") not in ("Variable", "Net", "NetSymbol", "VariableSymbol"):
            continue
        name, address = item.get("name"), _address(item.get("addr"))
        if name in signals and address.isdecimal():
            owned.setdefault(address, set()).add(name)
    identities = {addr: next(iter(names)) for addr, names in owned.items() if len(names) == 1}
    output_ports = {item["name"] for item in members
                    if isinstance(item, dict) and item.get("kind") == "Port"
                    and str(item.get("direction", "")).lower() in ("out", "output")
                    and item.get("name") in signals}
    assignments: dict[str, list[str]] = {}
    for item in _walk(members):
        if item.get("kind") != "ContinuousAssign":
            continue
        expr = item.get("assignment")
        if not isinstance(expr, dict) or expr.get("kind") != "Assignment":
            continue
        left, right = expr.get("left"), expr.get("right")
        if not isinstance(left, dict) or not isinstance(right, dict):
            continue
        if left.get("kind") not in ("NamedValue", "SymbolReference") or right.get("kind") not in ("NamedValue", "SymbolReference"):
            continue
        dest, src = identities.get(_address(left.get("symbol"))), identities.get(_address(right.get("symbol")))
        if dest in output_ports and src in signals:
            assignments.setdefault(dest, []).append(src)
    incoming = Counter(r["target"] for r in relations if r.get("target") in output_ports)
    aliases = {}
    for dest, sources in assignments.items():
        if len(sources) != 1 or incoming[dest] != 1 or sources[0] == dest:
            continue
        src = sources[0]
        if (signals[dest].get("width") != signals[src].get("width") or
                not any(r.get("source") == src and r.get("target") == dest
                        and r.get("type") == "data" and r.get("mapping") == "direct"
                        and r.get("rendered", True) for r in relations)):
            continue
        aliases[dest] = src
    return aliases


def normalize_output_clock_consumers(members: list[dict], signals: Mapping[str, Mapping],
                                     relations: list[dict]) -> dict[str, str]:
    """Reroute only verified event clocks from a port to its continuous driver.

    The output assignment remains in place so the RTL output pin still exists.
    Other uses (which may rely on separate net/port provenance) are unchanged.
    """
    aliases = proven_output_aliases(members, signals, relations)
    for relation in relations:
        if relation.get("type") != "event":
            continue
        source = relation.get("source")
        if source not in aliases:
            continue
        relation["outputPortAlias"] = source
        relation["source"] = aliases[source]
        relation["net"] = aliases[source]
    return aliases
