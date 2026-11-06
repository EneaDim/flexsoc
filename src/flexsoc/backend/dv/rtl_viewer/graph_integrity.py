"""Deterministic evidence audit at the semantic-graph / ELK boundary.

This is a read-only classification: it cannot add edges or decide RTL semantics.
Unroutable dependencies are retained as evidence, not silently counted as wires.
"""
from __future__ import annotations

from collections import Counter
from typing import Any, Mapping, Sequence


def inspect_graph(nodes: Sequence[Mapping[str, Any]], edges: Sequence[Mapping[str, Any]], *, sample_limit: int = 64) -> dict[str, Any]:
    node_ids = [node.get("id") for node in nodes]
    known = set(node_ids)
    invalid: list[dict[str, str]] = []
    if len(known) != len(node_ids) or any(not value for value in node_ids):
        invalid.append({"reason": "duplicate_or_missing_node_id", "edge": ""})
    ids: set[str] = set()
    states: Counter[str] = Counter()
    kinds: Counter[str] = Counter()
    blocked: Counter[str] = Counter()
    samples: list[dict[str, str]] = []
    for edge in edges:
        edge_id = str(edge.get("id", ""))
        if not edge_id or edge_id in ids:
            invalid.append({"reason": "duplicate_or_missing_edge_id", "edge": edge_id})
        ids.add(edge_id)
        if edge.get("source") not in known or edge.get("target") not in known:
            invalid.append({"reason": "missing_endpoint", "edge": edge_id})
        kind = str(edge.get("type", "unknown"))
        kinds[kind] += 1
        if edge.get("rendered") is False:
            status = str(edge.get("routingStatus") or (
                "nonphysical_dependency" if kind in ("address", "control") else "unclassified_suppression"))
            blocked[status] += 1
            states["not_rendered"] += 1
            if len(samples) < sample_limit:
                samples.append({"id": edge_id, "source": str(edge.get("source", "")),
                                "target": str(edge.get("target", "")),
                                "pin": str(edge.get("pin", "") or edge.get("targetPin", "")),
                                "type": kind, "reason": status})
        else:
            states["rendered"] += 1
    return {"status": "invalid" if invalid else "ok", "edges": len(edges),
            "rendered": states["rendered"], "not_rendered": states["not_rendered"],
            "by_type": dict(sorted(kinds.items())), "suppressed_by_reason": dict(sorted(blocked.items())),
            "suppressed_sample": samples, "sample_truncated": states["not_rendered"] > len(samples),
            "invalid": invalid[:sample_limit], "invalid_truncated": len(invalid) > sample_limit}
