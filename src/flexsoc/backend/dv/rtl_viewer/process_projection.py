"""Evidence-based ownership of *view-only* procedural process groups.

A process is not a SystemVerilog module.  This adapter records which existing
circuit nodes are attributable to one elaborated ProceduralBlock, without
modifying any signal, D/Q pin, net, or wire.  The browser may project these
already-proven boundaries as a virtual hierarchy.
"""
from __future__ import annotations

from collections import Counter, defaultdict
from typing import Any

from .connectivity import SymbolTable

_ASSIGNMENT_KINDS = {"Assignment", "AssignmentExpression", "NonblockingAssignment"}
_PROCEDURE_KINDS = {"alwayscomb": "always_comb", "alwaysff": "always_ff",
                    "alwayslatch": "always_latch"}


def _descendants(value: Any):
    if isinstance(value, dict):
        yield value
        for child in value.values():
            if isinstance(child, (dict, list)):
                yield from _descendants(child)
    elif isinstance(value, list):
        for child in value:
            yield from _descendants(child)


def process_groups(graph: dict[str, Any], members: list[dict], declared: set[str],
                   *, max_members: int = 768, max_ports: int = 128) -> list[dict]:
    """Return conservative grouping metadata for complete source processes.

    Only renderable graph nodes and unique process writes qualify.  Shared
    operator cones stay outside the box; their exact existing boundary edges
    remain visible. Unsupported assignments are never represented as a valid
    D/next-state driver merely because their targets were declared.
    """
    nodes = graph.get("nodes", ())
    edges = graph.get("edges", ())
    by_id = {n["id"]: n for n in nodes}
    by_name = {n["name"]: n for n in nodes if n.get("type") in
               {"signal", "register", "counter", "fsm", "port"}}
    resolved = [e for e in edges if e.get("rendered") is not False
                and e.get("source") in by_id and e.get("target") in by_id]
    incoming: dict[str, list[dict]] = defaultdict(list)
    outgoing: dict[str, list[dict]] = defaultdict(list)
    for edge in resolved:
        incoming[edge["target"]].append(edge)
        outgoing[edge["source"]].append(edge)
    resolver = SymbolTable(members, declared)
    process_candidates = []
    writer_count: Counter = Counter()
    for index, member in enumerate(members):
        if not isinstance(member, dict) or member.get("kind") != "ProceduralBlock":
            continue
        kind = _PROCEDURE_KINDS.get(str(member.get("procedureKind", "")).lower().replace("_", ""))
        if not kind:
            continue
        writes = set()
        for node in _descendants(member.get("body")):
            if node.get("kind") in _ASSIGNMENT_KINDS:
                writes.update(resolver.writes(node.get("left", node.get("lhs"))))
        if not writes:
            continue
        process_candidates.append((index, member, kind, writes))
        writer_count.update(writes)
    groups = []
    for index, member, kind, writes in process_candidates:
        if any(writer_count[name] != 1 or name not in by_name for name in writes):
            continue
        targets = {by_name[name]["id"] for name in writes}
        # Report incomplete lowering rather than hiding the process.  An
        # absent D/data driver remains absent in the compact and focused view.
        unresolved = sorted(name for name in writes if
            by_name[name].get("dInputStatus") or
            not any(edge.get("type") in {"data", "sequential", "port_out"}
                    for edge in incoming.get(by_name[name]["id"], ())))
        owned = set(targets)
        # Project pure expression DAGs that feed these process destinations;
        # never consume a shared combinational node with other consumers.
        for _ in range(max_members):
            added = False
            for op in nodes:
                oid = op["id"]
                if op.get("type") != "operator" or oid in owned:
                    continue
                consumers = outgoing.get(oid, ())
                if consumers and all(e["target"] in owned for e in consumers):
                    owned.add(oid)
                    added = True
            if not added:
                break
        if len(owned) > max_members:
            continue
        # A public module output is the terminal OUTSIDE the virtual process,
        # not private process storage. Keep it visible in the parent graph so
        # original AST-backed driver edges can cross the virtual boundary.
        # First discover the operators while the output is owned; otherwise
        # their consumer would not appear inside the process cone.
        public_outputs = {target for target in targets
                          if by_id[target].get("type") == "port"
                          and str(by_id[target].get("direction", "")).lower() in {"out", "output"}}
        # A whole-structure Port may have individual AST-backed *field*
        # assignments. The old per-assignment graph also contains direct
        # source->Port dependencies for bare RHS references. Those are NOT
        # independent whole-bus drivers: they are read operands inside this
        # process. Preserve their original edge IDs, but authorize the compact
        # view to terminate them on the process INPUT instead of drawing a
        # misleading bypass around the process block.
        #
        # Authorize ONLY a direct RHS whose LHS is an explicit selector of a
        # public output written by this exact process. A general expression,
        # an unknown lvalue, or a continuous assign cannot be reclassified.
        partial_port_inputs: set[tuple[str, str]] = set()
        for assignment in _descendants(member.get("body")):
            if assignment.get("kind") not in _ASSIGNMENT_KINDS:
                continue
            lhs = assignment.get("left", assignment.get("lhs"))
            rhs = assignment.get("right", assignment.get("rhs"))
            if not isinstance(lhs, dict) or lhs.get("kind") not in {
                    "MemberAccess", "ElementSelect", "BitSelect", "RangeSelect", "PartSelect"}:
                continue
            source_name = resolver.direct(rhs)
            if source_name not in by_name:
                continue
            for output_name in resolver.writes(lhs):
                if output_name in by_name and by_name[output_name]["id"] in public_outputs:
                    partial_port_inputs.add((by_name[source_name]["id"], by_name[output_name]["id"]))
        # A complete ordered aggregate projection supersedes the legacy
        # individual RHS -> public-port facts. Those suppressed edges must
        # not be reused as projected virtual inputs: the value now flows
        # through the UPDATE chain with its own compiler-backed terminals.
        live_public_pairs = {(edge["source"], edge["target"]) for edge in resolved
                             if edge.get("mapping") == "partial"
                             and edge["target"] in public_outputs}
        partial_port_inputs.intersection_update(live_public_pairs)
        owned.difference_update(public_outputs)
        if not owned:
            # No owned producer is available to draw the virtual boundary;
            # leave the original port-level connectivity untouched.
            continue
        # A process block may be a simple direct assignment without gates;
        # its own AST declaration still authorizes a virtual scope.
        boundary = [edge for edge in resolved
                    if (edge["source"] in owned) != (edge["target"] in owned)]
        inputs = sorted({e["source"] for e in boundary if e["target"] in owned})
        # Slang can prove a process READ even if the value cannot be lowered
        # into a physical conductor. Expose those inputs as *unresolved* ports,
        # but never add an edge that bypasses an operator or control predicate.
        read_names = set(resolver.reads(member.get("body"))) - writes
        unresolved_inputs = sorted(by_name[name]["id"] for name in read_names
                                   if name in by_name and by_name[name]["id"] not in owned
                                   and by_name[name]["id"] not in inputs)
        # One output port per INTERNAL producer (Q or Y), not per consumer.
        # This keeps FF fanout (hundreds of consumers) as a single Q pin.
        outputs = sorted({e["source"] for e in boundary if e["source"] in owned})
        # Some direct source-to-public-port assignments bypass the currently
        # supported operator graph. Preserve those compiler-backed edges
        # unchanged; mark the virtual boundary partial rather than claiming
        # all writes have been represented inside the process.
        exterior_port_writes = any(e["target"] in public_outputs and e["source"] not in owned
                                   for e in resolved)
        # Every written signal is a declared process output even when there is
        # no consumer in the bounded parent diagram. Do not invent an output
        # wire: expose an unconnected/unresolved pin in that case.
        target_ids = sorted(targets)
        output_targets = sorted({e["target"] for e in boundary if e["source"] in owned})
        # A single public output bus can have many Slang-backed partial
        # drivers (one per field). They remain separate electrical facts,
        # but occupy ONE *display* port on the virtual process boundary.
        # Count the public bus once rather than one pin per expression node.
        exposed = {("port", e["target"]) if e["target"] in public_outputs
                   else ("producer", e["source"], str(e.get("sourcePin") or ""))
                   for e in boundary if e["source"] in owned}
        for target in targets - public_outputs:
            if not any(e["source"] == target and e["target"] not in owned for e in boundary):
                exposed.add(("unbound", target))
        if len(inputs) + len(unresolved_inputs) > max_ports or len(exposed) > max_ports:
            continue
        clock = sorted({e["source"] for e in boundary if e["target"] in owned
                        and e.get("type") == "event" and
                        (e.get("pin") == "CLK" or e.get("timingRole") in {"clock", "single_event"})})
        async_reset = sorted({e["source"] for e in boundary if e["target"] in owned
                              and e.get("type") == "event" and
                              (e.get("pin") == "RST" or e.get("timingRole") == "async_reset")})
        source = member.get("source_file", "")
        line = member.get("source_line", 0)
        groups.append({"token": f"proc:{index}", "kind": kind,
                       "name": kind + (f" · L{line}" if isinstance(line, int) and line > 0 else f" · #{index}"),
                       "sourceFile": source, "sourceLine": line,
                       "memberIds": sorted(owned), "inputIds": inputs,
                       "unresolvedInputIds": unresolved_inputs, "outputIds": outputs,
                       "targetIds": target_ids, "outputTargets": output_targets,
                       "partialPortInputs": [{"source": src, "target": dst}
                                             for src, dst in sorted(partial_port_inputs)],
                       "clockIds": clock, "asyncResetIds": async_reset,
                       "targets": sorted(writes),
                       "unresolvedTargets": unresolved,
                       "coverage": "partial" if unresolved or exterior_port_writes else "connected",
                       "members": len(owned), "inputs": len(inputs) + len(unresolved_inputs),
                       "outputs": len(exposed),
                       "view": "collapsed", "origin": "Slang ProceduralBlock + resolved graph edges"})
    return groups
