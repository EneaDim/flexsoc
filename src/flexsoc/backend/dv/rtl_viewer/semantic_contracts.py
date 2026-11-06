"""Compiler-evidence checks across procedural lowering and diagram ownership.

These checks explicitly separate *verified projections* from *unrepresented*
SystemVerilog constructs. They do not attempt four-state formal equivalence.
Call sites are identified by elaborated Slang subroutine identity and source
coordinates; no textual function-name heuristic is used to establish a call.
"""
from __future__ import annotations

from collections import Counter
from typing import Any, Mapping

from .lowering import ProcessLowerer


def _nested(value: Any):
    if isinstance(value, Mapping):
        yield value
        for child in value.values():
            if isinstance(child, (Mapping, list)):
                yield from _nested(child)
    elif isinstance(value, list):
        for child in value:
            yield from _nested(child)


def _location(value: Mapping[str, Any]) -> tuple[str, int, int]:
    return (str(value.get("source_file_start", value.get("source_file", ""))),
            int(value.get("source_line_start", value.get("source_line", 0)) or 0),
            int(value.get("source_column_start", value.get("source_column", 0)) or 0))


def _call_site(call: Mapping[str, Any]) -> tuple[str, str, int, int]:
    name = str(call.get("subroutine", "")).partition(" ")[0]
    file, line, column = _location(call)
    return (name, file, line, column)


def _has_function_signature(call: Mapping[str, Any], definition: Any) -> bool:
    if not isinstance(definition, Mapping):
        return False
    if (definition.get("subroutineKind") != "Function" or
            not definition.get("name") or not isinstance(definition.get("body"), Mapping) or
            definition.get("returnType") in (None, "", "void") or
            call.get("type") in (None, "", "void")):
        return False
    formals = [member for member in definition.get("members", [])
               if isinstance(member, Mapping) and member.get("kind") == "FormalArgument"]
    actuals = call.get("arguments")
    return (isinstance(actuals, list) and len(actuals) == len(formals) <= 16 and
            all(isinstance(actual, Mapping) and actual.get("kind") != "EmptyArgument"
                for actual in actuals) and
            all(str(formal.get("direction", "")).lower() in {"in", "input"} and
                isinstance(formal.get("name"), str) and bool(formal.get("name"))
                for formal in formals))


def _value_update_count(expression: Any) -> int:
    if not isinstance(expression, Mapping):
        return 0
    return (int(expression.get("op") == "update") +
            sum(_value_update_count(value) if isinstance(value, Mapping) else
                _update_count_list(value) for value in expression.values()
                if isinstance(value, (Mapping, list))))


def _update_count_list(value: Any) -> int:
    if isinstance(value, list):
        return sum(_value_update_count(item) if isinstance(item, Mapping)
                   else _update_count_list(item) for item in value)
    return 0


def audit_scope_semantics(members: list[dict], declared: set[str], graph: dict,
                          subroutines: Mapping[str, dict]) -> dict[str, Any]:
    """Validate evidence-backed function and structured-value projections.

    Missing supported projections are surfaced as coverage warnings rather
    than silently counted as success; incorrect ownership/connections of
    emitted nodes are contract *errors*. This distinction is deliberate.
    """
    findings: dict[str, Any] = {"errors": [], "warnings": [],
                               "functionCalls": 0, "functionCallsRepresented": 0,
                               "aggregateValues": 0, "aggregateValuesRepresented": 0}

    def issue(kind: str, code: str, detail: str, *, owner: str = ""):
        findings[kind].append({"code": code, "description": detail,
                              **({"owner": owner} if owner else {})})

    nodes = {node["id"]: node for node in graph.get("nodes", ())}
    groups = {group["token"]: set(group.get("memberIds", ()))
              for group in graph.get("processGroups", ())}
    all_group_members = {id for members in groups.values() for id in members}
    function_nodes = []
    for node in nodes.values():
        if node.get("kind") != "Call" or not isinstance(node.get("function"), Mapping):
            continue
        func = node["function"]
        site = (str(func.get("subroutineAddr", "")), str(func.get("callFile", "")),
                int(func.get("callLine", 0) or 0), int(func.get("callColumn", 0) or 0))
        function_nodes.append((site, node))

    def same_site(expected, reported) -> bool:
        # Source coordinates are compiler-backed when present. For older AST
        # serializers that do not provide coordinates, identity must still
        # match and the remaining known coordinates must agree.
        return expected[0] == reported[0] and all(
            not known or not actual or known == actual
            for known, actual in zip(expected[1:], reported[1:]))

    for index, member in enumerate(members):
        if not isinstance(member, Mapping) or member.get("kind") not in {"ProceduralBlock", "ContinuousAssign"}:
            continue
        token = f"proc:{index}" if member["kind"] == "ProceduralBlock" else ""
        for call in _nested(member):
            if call.get("kind") != "Call":
                continue
            subroutine = str(call.get("subroutine", "")).partition(" ")[0]
            if not subroutine.isdecimal() or not _has_function_signature(call, subroutines.get(subroutine)):
                # System tasks ($fatal/$error) and unsupported user functions
                # are not value-producing graph calls, nor missing wires.
                continue
            findings["functionCalls"] += 1
            site = _call_site(call)
            witnesses = [node for ref, node in function_nodes if same_site(site, ref)]
            if not witnesses:
                issue("warnings", "unrepresented_function_call",
                      f"No electrical function value for compiler call {site}", owner=token)
                continue
            represented = False
            for node in witnesses:
                # Each compiler function argument must reach its own named
                # input. An unrelated edge on I0, a missing I1 or multiple
                # drivers to one formal are structural errors, even when the
                # function value still has a connected output.
                function = node["function"]
                formals = function.get("arguments", ())
                pins = node.get("pins", ())
                if isinstance(formals, list) and isinstance(pins, list):
                    expected = {f"I{i}" for i in range(len(formals))}
                    actual = [edge.get("targetPin") or edge.get("pin")
                              for edge in graph.get("edges", ())
                              if edge.get("rendered") is not False and edge.get("target") == node["id"]
                              and edge.get("type") == "data"]
                    if set(actual) != expected or len(actual) != len(expected) or not expected.issubset(pins):
                        issue("errors", "function_argument_pin_mismatch",
                              f"Function {node['id']} expects {sorted(expected)} and has {actual}",
                              owner=token)
                if token and token in groups and node["id"] not in groups[token]:
                    issue("errors", "function_wrong_process",
                          f"Function {node['id']} is outside its compiler process {token}", owner=token)
                elif not token and node["id"] in all_group_members:
                    issue("errors", "continuous_function_claimed_by_process",
                          f"Continuous-assignment function {node['id']} claimed by a process")
                elif (token and token not in groups):
                    issue("warnings", "function_process_not_grouped",
                          f"Function call {site} has no present virtual process", owner=token)
                else:
                    represented = True
                if not any(e.get("rendered") is not False and e.get("source") == node["id"]
                           for e in graph.get("edges", ())):
                    issue("warnings", "function_result_not_routed",
                          f"Function {node['id']} lacks a rendered consumer", owner=token)
            if represented:
                findings["functionCallsRepresented"] += 1

        if member["kind"] != "ProceduralBlock" or str(member.get("procedureKind", "")).lower().replace("_", "") != "alwayscomb":
            continue
        lowered = ProcessLowerer(members, declared, subroutines=subroutines).lower(member, index)
        if lowered["status"] != "supported":
            continue
        for target, expression in lowered["blocking_final"].items():
            if not isinstance(expression, Mapping) or expression.get("op") != "update":
                continue
            expected = _value_update_count(expression)
            if not expected:
                continue
            findings["aggregateValues"] += 1
            target_node = next((n for n in nodes.values() if n.get("name") == target and
                                n.get("type") in {"signal", "port"}), None)
            if target_node is None:
                issue("warnings", "aggregate_target_not_in_graph",
                      f"Target {target} is not in the bounded graph", owner=token)
                continue
            inbound = [edge for edge in graph["edges"] if edge.get("rendered") is not False and
                       edge.get("target") == target_node["id"] and
                       edge.get("type") in {"data", "sequential"}]
            projected = [edge for edge in inbound if nodes.get(edge["source"], {}).get("origin") == "ProcessLowerer"
                         and nodes[edge["source"]].get("kind") == "AggregateUpdate"]
            if not projected:
                issue("warnings", "aggregate_value_not_projected",
                      f"Ordered aggregate {target} ({expected} updates) is not a complete value conductor",
                      owner=token)
                continue
            if len(projected) != 1 or len(inbound) != 1:
                issue("errors", "aggregate_multiple_whole_drivers",
                      f"Aggregate {target} must have one projected value, got {len(inbound)} live input(s)",
                      owner=token)
                continue
            # Walk the actual rendered fan-in, not an AST name approximation.
            # Every UPDATE node must have exactly one BASE and VALUE input;
            # the root must be an AggregateUpdate, and no independent partial
            # wire may bypass the ordered chain to the whole aggregate.
            seen = set()
            stack = [projected[0]["source"]]
            while stack:
                source = stack.pop()
                if source in seen:
                    continue
                seen.add(source)
                node = nodes.get(source)
                if not node or node.get("origin") != "ProcessLowerer":
                    continue
                for edge in graph["edges"]:
                    if edge.get("rendered") is not False and edge.get("target") == source:
                        stack.append(edge["source"])
            updates = [nodes[n] for n in seen if n in nodes and nodes[n].get("kind") == "AggregateUpdate"]
            if len(updates) != expected:
                issue("errors", "aggregate_update_chain_incomplete",
                      f"Aggregate {target}: {len(updates)} UPDATE nodes for {expected} compiler writes",
                      owner=token)
                continue
            if not all(isinstance(node.get("writePath"), list) and node["writePath"]
                       for node in updates):
                issue("errors", "aggregate_update_path_missing",
                      f"Aggregate {target} contains an UPDATE node without compiler field path",
                      owner=token)
                continue
            findings["aggregateValuesRepresented"] += 1
    return findings
