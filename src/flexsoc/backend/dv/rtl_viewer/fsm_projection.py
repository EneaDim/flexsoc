"""Reversible FSM cone presentation, based solely on compiler-backed graph edges.

An FSM candidate is a registered enum that drives a four-state case match.
This is a *view*, not synthesis or extraction of an independent RTL module.
The expanded graph retains all original semantic identities. In compact mode
all displayed boundary edges retain their ID/net and exact original endpoint.
"""
from __future__ import annotations

from collections import defaultdict
from typing import Any


def collapse_fsm_cones(graph: dict[str, Any], expanded: frozenset[str],
                       *, max_ports: int = 48, max_members: int = 768) -> dict[str, Any]:
    """Collapse AST-evidenced FSM state / case / MUX operator cones.

    Deliberately fail closed on ambiguous input topology, oversized cones or
    overlapping FSM ownership. No electrical edges are inferred or combined.
    """
    nodes = list(graph["nodes"])
    edges = list(graph["edges"])
    by_id = {n["id"]: n for n in nodes}
    outgoing: dict[str, list[dict]] = defaultdict(list)
    incoming: dict[str, list[dict]] = defaultdict(list)
    for edge in edges:
        if edge.get("rendered") is False:
            continue
        outgoing[edge["source"]].append(edge)
        incoming[edge["target"]].append(edge)

    consumed: set[str] = set()
    projected: list[dict] = []
    result_nodes = nodes
    result_edges = edges
    for state in sorted((n for n in nodes if n.get("type") == "fsm"), key=lambda n: n["id"]):
        state_id = state["id"]
        matches = {
            edge["target"] for edge in outgoing.get(state_id, ())
            if (by_id.get(edge["target"], {}).get("kind") == "CaseMatch"
                and (edge.get("targetPin") or edge.get("pin")) == "A")
        }
        if not matches:
            continue
        group_token = "fsm:" + state["name"]
        # Include only operator successors. Any peripheral signal/output is a
        # boundary port, not part of the FSM's private implementation.
        owned = {state_id, *matches}
        queue = sorted(matches)
        while queue:
            src = queue.pop(0)
            for edge in outgoing.get(src, ()):
                dst = edge["target"]
                if dst in owned:
                    continue
                node = by_id.get(dst)
                if node and node.get("type") == "operator":
                    owned.add(dst)
                    queue.append(dst)
        # Bring along AST expression nodes feeding the controlled outputs.
        # This keeps the compact boundary at real RTL signals rather than
        # exposing dozens of internal CAST/NOT/MUX fragments as ports.
        upstream_queue = sorted(owned)
        while upstream_queue and len(owned) <= max_members:
            dst = upstream_queue.pop(0)
            for edge in incoming.get(dst, ()):
                src = edge["source"]
                if src not in owned and by_id.get(src, {}).get("type") == "operator":
                    owned.add(src)
                    upstream_queue.append(src)
        if (len(owned) < 3 or len(owned) > max_members or owned & consumed):
            continue
        boundary = [e for e in result_edges if e.get("rendered") is not False
                    and ((e["source"] in owned) != (e["target"] in owned))]
        # Need at least one external output. Otherwise collapsing would hide
        # a non-functional state-machine marker rather than a driver.
        if not any(e["source"] in owned for e in boundary):
            continue
        inbound = sorted({e["source"] for e in boundary if e["target"] in owned})
        outbound = sorted({e["target"] for e in boundary if e["source"] in owned})
        if not inbound or len(inbound) > max_ports or len(outbound) > max_ports:
            continue
        # Registered timing evidence, not the name 'clk', is what qualifies
        # an incoming source as a clock pin of this virtual schematic box.
        clock_ids = {e["source"] for e in incoming.get(state_id, ())
                     if e.get("type") == "event" and
                     (e.get("timingRole") in {"clock", "single_event"} or e.get("pin") == "CLK")}
        async_reset_ids = {e["source"] for e in incoming.get(state_id, ())
                           if e.get("type") == "event" and
                           (e.get("timingRole") == "async_reset" or e.get("pin") == "RST")}
        # Keep the member IDs solely for a reversible focused *view*; these
        # identities are already compiler-derived and are never new nets.
        summary = {"token": group_token, "state": state["name"], "stateId": state_id,
                   "memberIds": sorted(owned), "inputIds": inbound, "outputIds": outbound,
                   "clockIds": sorted(clock_ids & set(inbound)),
                   "asyncResetIds": sorted(async_reset_ids & set(inbound)),
                   "members": len(owned), "inputs": len(inbound), "outputs": len(outbound),
                   "hiddenDependencies": sum(1 for e in result_edges if e.get("rendered") is False
                                             and (e["source"] in owned or e["target"] in owned)),
                   "view": "expanded" if group_token in expanded else "collapsed"}
        projected.append(summary)
        if group_token in expanded:
            result_nodes = [(dict(n, group=group_token, fsmExpanded=True)
                             if n["id"] == state_id else n) for n in result_nodes]
            consumed.update(owned)
            continue

        group_id = state_id.rsplit("::", 1)[0] + "::fsmgroup:" + state["name"]
        # A stable pin is allocated to each distinct boundary entity, not
        # to an arbitrary edge count or visual position.
        def port_name(prefix: str, item_id: str, index: int) -> str:
            original = by_id.get(item_id)
            label = str(original.get("name", "") if original else item_id.rsplit("::", 1)[-1])
            return f"{prefix}{index:02d}:{label[:36]}"

        # Timing terminals belong to the INPUT side of the virtual FSM.
        # Place them at the top of the west border (CLK, then async RST),
        # followed by normal inputs, including synchronous reset signals.
        # This changes display order only, not any Slang edge identity.
        ordered_inputs = sorted(inbound, key=lambda source: (
            0 if source in clock_ids else 1 if source in async_reset_ids else 2,
            str(by_id[source].get("name", "")), source))
        input_ports = {source: ("CLK:" + str(by_id[source].get("name", ""))
                                if source in clock_ids else
                                "RST:" + str(by_id[source].get("name", ""))
                                if source in async_reset_ids else port_name("I", source, i))
                       for i, source in enumerate(ordered_inputs)}
        output_ports = {target: port_name("O", target, i) for i, target in enumerate(outbound)}
        ports = ([{"name": pin, "direction": "input", "connection": "bound",
                   "timingRole": "clock" if source in clock_ids else
                   "async_reset" if source in async_reset_ids else "data"}
                  for source, pin in input_ports.items()] +
                 [{"name": pin, "direction": "output", "connection": "bound"}
                  for pin in output_ports.values()])
        group = {"id": group_id, "name": "FSM · " + state["name"],
                 "type": "fsm_group", "module": "AST state machine · expand to inspect",
                 "group": group_token, "stateSignal": state["name"],
                 "fsmSummary": summary, "hiddenNodeIds": sorted(owned), "ports": ports,
                 "classification": "compiler-backed registered enum + case selection"}
        transformed = []
        for edge in result_edges:
            src_inside = edge["source"] in owned
            dst_inside = edge["target"] in owned
            if src_inside and dst_inside:
                continue
            if (src_inside or dst_inside) and edge.get("rendered") is False:
                # Still accessible in expanded view and counted in summary.
                continue
            if not src_inside and not dst_inside:
                transformed.append(edge)
                continue
            updated = dict(edge)
            updated["fsmOriginalSource"] = edge["source"]
            updated["fsmOriginalTarget"] = edge["target"]
            updated["fsmProjection"] = "boundary-only"
            if dst_inside:
                updated["target"] = group_id
                updated["targetPin"] = input_ports[edge["source"]]
            else:
                updated["source"] = group_id
                updated["sourcePin"] = output_ports[edge["target"]]
            transformed.append(updated)
        result_nodes = [n for n in result_nodes if n["id"] not in owned] + [group]
        result_edges = transformed
        consumed.update(owned)
    if not projected:
        return graph
    result = dict(graph)
    result["nodes"] = result_nodes
    result["edges"] = result_edges
    result["fsmGroups"] = projected
    return result
