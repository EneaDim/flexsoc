"""Versioned graph projection of the *elaborated* slang AST.

Unknown language constructs are not interpreted from RTL text. The renderer gets
only proven AST relationships; unsupported relationships remain visibly unknown.
"""
from __future__ import annotations

from collections import deque
from dataclasses import dataclass, field
import json
from pathlib import Path
from typing import Any, Iterator

from .slang import SlangReferences
from .compiler import ast_revision
from .connectivity import GraphEdges, OperatorResolver, PortResolver, SymbolTable as ASTReferences


SIGNAL_KINDS = frozenset({"Port", "Variable", "Net", "NetSymbol", "VariableSymbol", "InterfacePort"})
ASSIGN_KINDS = frozenset({"Assignment", "AssignmentExpression", "ContinuousAssign", "NonblockingAssignment"})
# Only explicit expression nodes in the elaborated AST become functional symbols.
OPERATOR_KINDS = frozenset({"BinaryOp", "UnaryOp", "ConditionalOp", "ConditionalExpression", "Conversion", "Concatenation"})
BLOCK_KINDS = frozenset({"GenerateBlock", "GenerateBlockArray", "GenerateBlockSymbol", "InstanceArray"})


def objects(node: Any) -> Iterator[dict[str, Any]]:
    """Iterate AST objects only (not source code, nor arbitrary string tokens)."""
    if isinstance(node, dict):
        yield node
        for val in node.values():
            if isinstance(val, (dict, list)):
                yield from objects(val)
    elif isinstance(node, list):
        for item in node:
            yield from objects(item)


def name_of(node: dict) -> str:
    return str(node.get("name") or node.get("instanceName") or "")


def module_of(node: dict) -> str:
    body = node.get("body")
    if isinstance(body, dict):
        return str(body.get("name") or body.get("definition") or node.get("type") or "")
    return str(node.get("definition") or node.get("type") or "")


def is_instance(node: dict) -> bool:
    return node.get("kind") == "Instance" and isinstance(node.get("body"), (dict, str))


def extract_location(node: dict) -> tuple[str, int]:
    """Conservative source-location adapter; no source-text parsing."""
    # Public Slang JSON emits source_file/source_line on elaborated symbols.
    file = node.get("source_file")
    if isinstance(file, str) and file:
        try:
            return file, int(node.get("source_line") or 0)
        except (TypeError, ValueError):
            return file, 0
    if isinstance(node.get("source_file_start"), str) and node["source_file_start"]:
        try:
            return node["source_file_start"], int(node.get("source_line_start") or 0)
        except (TypeError, ValueError):
            return node["source_file_start"], 0
    for key in ("sourceRange", "location", "sourceLocation", "source"):
        value = node.get(key)
        if isinstance(value, dict):
            loc = value.get("start", value)
            if isinstance(loc, dict):
                file = loc.get("file") or loc.get("filename") or loc.get("path")
                line = loc.get("line") or loc.get("lineNumber") or 0
                if file:
                    try:
                        return str(file), int(line)
                    except (ValueError, TypeError):
                        pass
        elif isinstance(value, str) and value:
            # Slang may serialize source info as file:line:column.
            segments = value.rsplit(":", 2)
            if len(segments) >= 2 and segments[1].isdigit():
                return segments[0], int(segments[1])
    return "", 0


@dataclass
class Scope:
    path: str
    name: str
    module: str
    node: dict[str, Any]
    children: list[str] = field(default_factory=list)
    group: str = ""
    source: str = ""
    line: int = 0


class RtlDesign:
    """Stable hierarchy identifiers and bounded, lazy graph projections."""

    def __init__(self, ast: dict[str, Any], *, root: Path, top: str, run: Path | None = None, verified: bool = False):
        if not isinstance(ast.get("design"), dict):
            raise ValueError("expected a Slang elaborated AST containing 'design'")
        self.root = root.resolve()
        self.run = run.resolve() if run else None
        self.top = top
        self.verified = verified
        self.revision = ast_revision(ast, top=top)
        self.references = SlangReferences(ast)
        self.scopes: dict[str, Scope] = {}
        self._diagrams: dict[tuple[str, bool, int], dict[str, Any]] = {}
        roots = [item for item in ast["design"].get("members", ()) if isinstance(item, dict) and is_instance(item)]
        matches = [item for item in roots if name_of(item) == top]
        if len(matches) != 1:
            raise ValueError(f"top {top!r} missing or ambiguous in Slang's elaborated design")
        self._index(self.references.instance(matches[0]), "/", "")

    def _index(self, node: dict, path: str, group: str) -> None:
        # The inspector shows the module definition, not the parent instance's
        # instantiation site. Slang can serialize both locations separately.
        # Authored members identify the *module definition*. On some Slang
        # versions InstanceBody carries an instantiation-site source range,
        # which is the wrong file to open for a child module.
        source, line = "", 0
        for declaration in node["body"].get("members", ()):
            if isinstance(declaration, dict) and declaration.get("kind") in SIGNAL_KINDS:
                source, line = extract_location(declaration)
                if source:
                    break
        if not source:
            source, line = extract_location(node["body"])
        if not source:
            source, line = extract_location(node)
        scope = Scope(path, name_of(node), module_of(node), node, group=group, source=source, line=line)
        self.scopes[path] = scope
        seen: set[str] = set()

        def descend(container: dict, ancestors: tuple[str, ...] = ()) -> None:
            for member in container.get("members", ()):
                if not isinstance(member, dict):
                    continue
                kind = member.get("kind")
                if is_instance(member):
                    item_name = name_of(member)
                    if not item_name:
                        continue
                    relative = "/".join((*ancestors, item_name))
                    child_path = (path.rstrip("/") + "/" + relative)
                    if child_path in seen:
                        raise ValueError(f"duplicate elaborated instance path: {child_path}")
                    seen.add(child_path)
                    scope.children.append(child_path)
                    # Collapse replicated generate scopes by their *elaborated*
                    # array identity, never by source-text regex or RTL names.
                    group_parts = []
                    for part in ancestors:
                        stem, bracket, index = part.rpartition("[")
                        group_parts.append(stem if bracket and index.endswith("]") and index[:-1].isdigit() else part)
                    generated = "/".join(group_parts) if ancestors else ""
                    self._index(self.references.instance(member), child_path, generated)
                elif kind in BLOCK_KINDS:
                    label = name_of(member)
                    # A generate block without a name is transparent to the
                    # topology, but remains represented by its elaborated AST.
                    pieces = (*ancestors, label) if label else ancestors
                    descend(member, pieces)
                    # Some slang AST versions serialize an array as 'elements'.
                    for element in member.get("elements", ()):
                        if isinstance(element, dict):
                            descend({"members": [element]}, pieces)
        descend(node["body"])

    def _scope(self, path: str) -> Scope:
        try:
            return self.scopes[path]
        except KeyError as exc:
            raise ValueError(f"unrecognized elaborated hierarchy path: {path}") from exc

    def overview(self) -> dict[str, Any]:
        return {"schema": "flexsoc.rtl_viewer.v1", "source": "Slang verified" if self.verified else "imported AST (unverified)", "top": self.top,
                "sourceFiles": sorted({source.relative_to(self.root).as_posix()
                                       for scope in self.scopes.values()
                                       if (source := self._source_path(scope)) is not None}),
                "revision": self.revision, "instances": len(self.scopes),
                "modules": len({s.module for s in self.scopes.values()}),
                "capabilities": {"hierarchy": True, "generate": "elaborated siblings grouped",
                                 "ports": "AST", "signal_follow": "only explicit direct AST port mapping",
                                 "cone": "AST-proven intra-module dependencies", "timing": False}}

    @staticmethod
    def _signals(scope: Scope) -> dict[str, dict]:
        result: dict[str, dict] = {}
        for item in scope.node["body"].get("members", ()):
            if not isinstance(item, dict) or item.get("kind") not in SIGNAL_KINDS:
                continue
            sig = name_of(item)
            if not sig:
                continue
            file, line = extract_location(item)
            direction = str(item.get("direction") or "").lower()
            # Slang emits both a Port and its backing Variable/Net under the
            # same name. Keep the port's direction and source binding instead
            # of silently replacing it with the backing declaration.
            previous = result.get(sig)
            if previous and previous["kind"] in ("Port", "InterfacePort") and item["kind"] not in ("Port", "InterfacePort"):
                continue
            type_data = item.get("type", "")
            # Preserve Slang's type expression. AST dimension metadata is
            # included only when provided, never guessed from SV text.
            if isinstance(type_data, dict):
                type_label = str(type_data.get("text") or type_data.get("name") or type_data.get("kind") or "")
            else:
                type_label = str(type_data)
            dimensions = {key: item.get(key, type_data.get(key) if isinstance(type_data, dict) else None)
                          for key in ("packedDimensions", "unpackedDimensions")}
            result[sig] = {"name": sig, "kind": item["kind"], "direction": direction,
                           "width": type_label, "typeKind": type_data.get("kind", "") if isinstance(type_data, dict) else "",
                           "dimensions": dimensions,
                           "line": line, "file": file}
        return result

    @staticmethod
    def _assignments(scope: Scope, declared: set[str]) -> tuple[list[dict], set[str], list[dict], set[str], set[str]]:
        """Directed dependencies from elaborated assignments, without source parsing.

        A combinational RHS is not a timing gate: a recognized AST operator
        becomes a symbol; an always_ff destination is a sequential boundary.
        """
        edges: list[dict] = []
        registered: set[str] = set()
        counters: set[str] = set()
        case_selectors: set[str] = set()
        operators: list[dict] = []
        symbols = ASTReferences(scope.node["body"].get("members", ()), declared)
        operands = OperatorResolver(symbols)

        def walk(node: Any, sequential: bool = False, controls: tuple[str, ...] = ()) -> None:
            if isinstance(node, list):
                for item in node:
                    walk(item, sequential, controls)
                return
            if not isinstance(node, dict):
                return
            kind = str(node.get("kind", ""))
            if is_instance(node):
                return
            process = sequential or (kind == "ProceduralBlock" and str(
                node.get("procedureKind", node.get("procedure", ""))).lower() in ("alwaysff", "always_ff"))
            # Context-sensitive traversal: predicates affect every assignment
            # reachable inside the elaborated branch, including nested blocks.
            if kind in {"Conditional", "ConditionalStatement", "IfStatement"}:
                predicates = symbols.refs(node.get("conditions", node.get("condition", node.get("predicate"))))
                active = tuple(dict.fromkeys((*controls, *predicates)))
                for branch in ("ifTrue", "ifFalse", "then", "else"):
                    if branch in node:
                        walk(node[branch], process, active)
                return
            if kind in {"Case", "CaseStatement", "CaseStmt"}:
                selected = symbols.refs(node.get("expr", node.get("expression", node.get("selector"))))
                case_selectors.update(selected)
                destinations = tuple(dict.fromkeys(dst for branch in objects(node)
                                     if branch.get("kind") in ASSIGN_KINDS
                                     for dst in symbols.writes(branch.get("left", branch.get("lhs")))))
                if selected and destinations:
                    op_id = "op:" + str(len(operators))
                    operators.append({"name": "CASE", "key": op_id, "kind": kind,
                                      "shape": "case", "line": extract_location(node)[1]})
                    for signal in selected:
                        edges.append({"source": signal, "target": op_id, "type": "control", "net": signal})
                    for dest in destinations:
                        edges.append({"source": op_id, "target": dest, "type": "control", "net": dest})
                active = tuple(dict.fromkeys((*controls, *selected)))
                for branch in ("items", "defaultCase", "branches", "default"):
                    if branch in node:
                        walk(node[branch], process, active)
                return
            if kind in ASSIGN_KINDS or ("Assignment" in kind and "Pattern" not in kind):
                lhs = node.get("left", node.get("lhs"))
                rhs = node.get("right", node.get("rhs"))
                if lhs is not None and rhs is not None:
                    destinations = symbols.writes(lhs)
                    sources = symbols.refs(rhs)
                    address_sources = symbols.address_reads(lhs)
                    exact_assignment = (symbols.direct(lhs) is not None
                                        and symbols.direct(rhs) is not None)
                    mapping = "direct" if exact_assignment else "partial"
                    for dst in destinations:
                        for signal in controls:
                            edges.append({"source": signal, "target": dst, "type": "control", "net": signal,
                                          "mapping": "partial"})
                        for src in address_sources:
                            edges.append({"source": src, "target": dst, "type": "address", "net": src,
                                          "mapping": "partial"})
                    if process:
                        registered.update(destinations)
                        if isinstance(rhs, dict) and rhs.get("kind") == "BinaryOp" and str(rhs.get("op")) in ("Add", "Subtract", "Sub"):
                            counters.update(set(destinations).intersection(sources))
                    operator = rhs if isinstance(rhs, dict) and rhs.get("kind") in OPERATOR_KINDS else None
                    for dst in destinations:
                        if operator and sources:
                            op_id = "op:" + str(len(operators))
                            op_name = str(operator.get("op") or operator.get("operator") or operator["kind"])
                            shape = "mux" if operator["kind"] in {"ConditionalOp", "ConditionalExpression"} else "arith" if operator["kind"] == "BinaryOp" else "logic"
                            role_inputs = operands.inputs(operator)
                            operators.append({"name": op_name, "key": op_id, "kind": operator["kind"],
                                              "shape": shape, "line": extract_location(operator)[1],
                                              "pins": (["A", "B", "S", "Y"] if shape == "mux" else
                                                       ["A", "B", "Y"] if operator["kind"] == "BinaryOp" else
                                                       ["A", "Y"])})
                            for binding in role_inputs:
                                edges.append({"source": binding.signal, "target": op_id, "type": "data",
                                              "net": binding.signal, "pin": binding.pin,
                                              "mapping": binding.mapping})
                            edges.append({"source": op_id, "target": dst,
                                          "type": "sequential" if process else "data", "net": dst,
                                          "mapping": "partial" if symbols.direct(lhs) is None else "direct"})
                        else:
                            for src in sources:
                                edges.append({"source": src, "target": dst,
                                              "type": "sequential" if process else "data", "net": src,
                                              "mapping": mapping})
                    return
            if kind in {"CaseStatement", "CaseStmt"}:
                selector = next((node[k] for k in ("expr", "expression", "selector")
                                 if isinstance(node.get(k), dict)), None)
                selected = symbols.refs(selector)
                case_selectors.update(selected)
                destinations = []
                for branch in objects(node):
                    if branch.get("kind") not in ASSIGN_KINDS and branch.get("kind") != "Assignment":
                        continue
                    left = branch.get("left", branch.get("lhs"))
                    if left is not None:
                        for dst in symbols.writes(left):
                            if dst not in destinations:
                                destinations.append(dst)
                if selected and destinations:
                    op_id = "op:" + str(len(operators))
                    operators.append({"name": "CASE", "key": op_id, "kind": kind,
                                      "shape": "case", "line": extract_location(node)[1]})
                    for src in selected:
                        edges.append({"source": src, "target": op_id, "type": "control", "net": src})
                    for dst in destinations:
                        edges.append({"source": op_id, "target": dst, "type": "control", "net": dst})
            for value in node.values():
                if isinstance(value, (list, dict)):
                    walk(value, process, controls)

        walk(scope.node["body"].get("members", []))
        # Clock and asynchronous reset are declared in the elaborated event
        # controls, not in the assignment RHS. Bind them to the actual state
        # destinations by declaration identity. Never infer timing from names.
        for member in scope.node["body"].get("members", ()):
            if not isinstance(member, dict) or member.get("kind") != "ProceduralBlock":
                continue
            if str(member.get("procedureKind", "")).lower() not in ("alwaysff", "always_ff"):
                continue
            body = member.get("body", {})
            if not isinstance(body, dict) or body.get("kind") != "Timed":
                continue
            timing = body.get("timing", {})
            if not isinstance(timing, dict):
                continue
            events = timing.get("events", ()) if timing.get("kind") == "EventList" else (timing,)
            destinations = set()
            statement = body.get("stmt")
            for item in objects(statement):
                if item.get("kind") in ASSIGN_KINDS or ("Assignment" in str(item.get("kind", "")) and "Pattern" not in str(item.get("kind", ""))):
                    destinations.update(symbols.writes(item.get("left", item.get("lhs"))))
            for event in events:
                if not isinstance(event, dict) or event.get("kind") != "SignalEvent":
                    continue
                edge_kind = str(event.get("edge", ""))
                if edge_kind not in ("PosEdge", "NegEdge"):
                    continue
                for source in symbols.refs(event.get("expr")):
                    for target in sorted(destinations):
                        edges.append({"source": source, "target": target, "type": "event", "net": source,
                                      "pin": "CLK" if edge_kind == "PosEdge" else "EVENT",
                                      "eventEdge": edge_kind, "mapping": "direct"})
        # This is a *candidate* FSM marker, not synthesis-state extraction.
        # Require an elaborated enum type, a sequential state write and a
        # case that reads the same state. No text-name heuristics.
        enum_state = {name_of(m) for m in scope.node["body"].get("members", ())
                      if isinstance(m, dict) and isinstance(m.get("type"), dict)
                      and m["type"].get("kind") in ("Enum", "EnumType")}
        return edges, registered, operators, counters, registered & case_selectors & enum_state

    @staticmethod
    def _bindings(parent: Scope, child: Scope, signals: set[str]) -> list[tuple[str, str, str, str]]:
        """Resolve Slang instance connections through parent declaration identity."""
        ports = RtlDesign._signals(child)
        resolver = PortResolver(parent.node["body"].get("members", ()), signals)
        return [(b.signal, b.port, b.direction, b.mapping)
                for b in resolver.bindings(child.node, ports)]

    @staticmethod
    def _port_aliases(scope: Scope, signals: set[str]) -> list[tuple[str, str, str]]:
        """Bind port to *different-named* internal declaration via Slang identity.

        A Port.internalSymbol pointer denotes a backing Variable/Net. The name
        of that backing object need not match the public port. Only an exact
        address match authorizes the link, never textual coincidence.
        """
        members = scope.node["body"].get("members", ())
        declarations = {str(m["addr"]): name_of(m) for m in members
                        if isinstance(m, dict) and m.get("kind") in SIGNAL_KINDS - {"Port", "InterfacePort"}
                        and m.get("addr") is not None and name_of(m) in signals}
        aliases = []
        for port in members:
            if not isinstance(port, dict) or port.get("kind") not in {"Port", "InterfacePort"}:
                continue
            name = name_of(port)
            backing = port.get("internalSymbol")
            address = str(backing.get("addr")) if isinstance(backing, dict) and backing.get("addr") is not None else \
                      backing.split(" ", 1)[0] if isinstance(backing, str) else ""
            internal = declarations.get(address)
            if internal is None or internal == name or name not in signals:
                continue
            direction = str(port.get("direction") or "").lower()
            if direction in ("in", "input", "inout"):
                aliases.append((name, internal, "port_alias"))
            if direction in ("out", "output", "inout"):
                aliases.append((internal, name, "port_alias"))
        return aliases

    def diagram(self, path: str = "/", *, explode: bool = False, expanded: tuple[str, ...] = (), limit: int = 320) -> dict[str, Any]:
        if not 1 <= limit <= 1500:
            raise ValueError("limit must be between 1 and 1500")
        expanded_groups = frozenset(expanded)
        if len(expanded_groups) > 32 or any(len(group) > 256 for group in expanded_groups):
            raise ValueError("too many expanded groups")
        key = (path, explode, tuple(sorted(expanded_groups)), limit)
        if key in self._diagrams:
            return self._diagrams[key]
        scope = self._scope(path)
        signals = self._signals(scope)
        logical_edges, registers, operators, counters, fsm_candidates = self._assignments(scope, set(signals))
        nodes: list[dict] = []
        edges: list[dict] = []
        edge_specs: list[tuple[str, str, str, str, str, str, int, str]] = []
        prefix = path + "::"
        for name, sig in signals.items():
            if len(nodes) >= limit:
                break
            nodes.append({"id": prefix + "sig:" + name, "name": name,
                          "type": "counter" if name in counters else "fsm" if name in fsm_candidates else "register" if name in registers else ("port" if sig["kind"] in ("Port", "InterfacePort") else "signal"),
                          "classification": "candidate" if name in fsm_candidates else "AST" ,
                          "direction": sig["direction"], "width": sig["width"], "dimensions": sig["dimensions"], "line": sig["line"]})
        for operator in operators:
            if len(nodes) >= limit:
                break
            nodes.append({"id": prefix + operator["key"], "name": operator["name"],
                          "type": "operator", "kind": operator["kind"], "shape": operator["shape"], "line": operator["line"],
                          "pins": operator.get("pins", [])})
        present = {item["id"] for item in nodes}

        def add_edge(src: str, dst: str, kind: str, *, net: str = "", port: str = "", pin: str = "", aggregate: int = 1, mapping: str = "direct") -> None:
            edge_specs.append((src, dst, kind, net, port, pin, aggregate, mapping))

        for src, dst, relation in self._port_aliases(scope, set(signals)):
            add_edge(prefix + "sig:" + src, prefix + "sig:" + dst, relation, net=src)
        for edge in logical_edges:
            src = prefix + (edge["source"] if edge["source"].startswith("op:") else "sig:" + edge["source"])
            dst = prefix + (edge["target"] if edge["target"].startswith("op:") else "sig:" + edge["target"])
            add_edge(src, dst, edge["type"], net=edge["net"],
                     pin=edge.get("pin", ""), mapping=edge.get("mapping", "direct"))

        groups: dict[str, list[Scope]] = {}
        for child_path in scope.children:
            child = self.scopes[child_path]
            groups.setdefault(child.group or child.path, []).append(child)
        for group, children in groups.items():
            if len(nodes) >= limit:
                break
            if len(children) > 1 and children[0].group and not (explode or group in expanded_groups):
                first = children[0]
                ports = [{"name": n, "direction": d["direction"], "width": d["width"], "dimensions": d["dimensions"]}
                         for n, d in self._signals(first).items() if d["kind"] in ("Port", "InterfacePort")]
                nodes.append({"id": prefix + "gen:" + group, "name": group, "type": "generate",
                              "module": first.module, "count": len(children), "child": first.path, "group": group,
                              "ports": ports, "instancePaths": [c.path for c in children[:64]],
                              "line": first.line, "file": first.source})
            else:
                for child in children:
                    if len(nodes) >= limit:
                        break
                    ports = [{"name": n, "direction": d["direction"], "width": d["width"], "dimensions": d["dimensions"]}
                             for n, d in self._signals(child).items() if d["kind"] in ("Port", "InterfacePort")]
                    nodes.append({"id": prefix + "inst:" + child.path, "name": child.name,
                                  "type": "instance", "module": child.module, "child": child.path,
                                  "group": group if len(children) > 1 and child.group else "",
                                  "ports": ports, "line": child.line,
                                  "file": child.source})
        present = {item["id"] for item in nodes}
        for group, children in groups.items():
            grouped = len(children) > 1 and children[0].group and not (explode or group in expanded_groups)
            # Aggregate identical proven bindings without inventing slice wiring.
            aggregated: dict[tuple[str, str, str, str, str], int] = {}
            for child in children:
                for sig, port, direction, mapping in self._bindings(scope, child, set(signals)):
                    member_id = prefix + ("gen:" + group if grouped else "inst:" + child.path)
                    triple = (sig, port, direction, member_id, mapping)
                    aggregated[triple] = aggregated.get(triple, 0) + 1
            for (sig, port, direction, member_id, mapping), count in aggregated.items():
                signal_id = prefix + "sig:" + sig
                if direction in ("in", "inout"):
                    add_edge(signal_id, member_id, "port_in", net=sig, port=port, aggregate=count, mapping=mapping)
                if direction in ("out", "inout"):
                    add_edge(member_id, signal_id, "port_out", net=sig, port=port, aggregate=count, mapping=mapping)
        # Finalize after ALL nodes exist. Stable edge IDs must not depend on
        # traversal order; a net must never connect to a truncated-off node.
        collector = GraphEdges(prefix, nodes, signals, max_edges=min(20_000, max(350, limit * 12)))
        for src, dst, kind, net, port, pin, count, mapping in edge_specs:
            collector.add(src, dst, kind, net=net, port=port, pin=pin, count=count, mapping=mapping)
        edges = collector.all()
        # Source-truth audit: "unbound" is not the same as "unresolved".
        # A generated stack is fully connected only if EVERY instance has a
        # proven binding for that pin. Never hide a missing lane in a bundle.
        resolver = PortResolver(scope.node["body"].get("members", ()), set(signals))
        states_by_child = {}
        for children in groups.values():
            for child in children:
                _, states_by_child[child.path] = resolver.resolve(child.node, self._signals(child))
        unbound = unresolved = partial = 0
        for node in nodes:
            if node["type"] not in ("instance", "generate"):
                continue
            represented = (groups.get(node["group"], ()) if node["type"] == "generate"
                           else (self.scopes[node["child"]],))
            for port in node.get("ports", []):
                states = [states_by_child[child.path].get(port["name"], "unbound") for child in represented]
                if all(s == "bound" for s in states):
                    connection = "bound"
                elif all(s == "constant" for s in states):
                    connection = "constant"
                elif all(s == "unbound" for s in states):
                    connection = "unbound"
                elif any(s == "unresolved" for s in states):
                    connection = "unresolved"
                else:
                    connection = "partial"  # slice or only some generated instances bound
                port["connection"] = connection
                if connection == "unbound":
                    unbound += 1
                elif connection == "unresolved":
                    unresolved += 1
                elif connection == "partial":
                    partial += 1
        payload = {"schema": "flexsoc.rtl_viewer.module.v2", "path": path, "module": scope.module,
                   "revision": self.revision,
                   "ancestors": [{"path": p, "name": s.name, "module": s.module}
                                 for p, s in self.scopes.items()
                                 if p == "/" or path == p or path.startswith(p.rstrip("/") + "/")],
                   "expanded": sorted(expanded_groups), "nodes": nodes, "edges": edges,
                   "children": len(scope.children), "connectivity": {"unbound_pins": unbound, "unresolved_pins": unresolved, "partial_pins": partial},
                   "total": len(signals) + len(operators) + len(scope.children),
                   "truncated": len(nodes) >= limit or collector.truncated, "limits": [
                       "Sequential markers only where AST explicitly denotes always_ff assignments",
                       "Bindings are derived only from elaborated port expressions; sliced bus bindings indicate partial net dependence, not bit-level correspondence",
                       "Case decision and MUX controls are AST dependencies; encoder/decoder/FSM semantics are not inferred from names",
                       "A wire is a logical RTL dependency, not a physical net or timing path",
                       "Clock/reset/enable not guessed from naming; register/counter only when AST process and feedback prove it"]}
        if len(self._diagrams) > 120:
            self._diagrams.clear()
        self._diagrams[key] = payload
        return payload

    def behavior(self, path: str = "/") -> dict[str, Any]:
        """Return process-level semantic dependencies without graphical interpretation."""
        from .process import BehavioralIR

        return BehavioralIR(self, path).serialize()

    def lowering(self, path: str = "/") -> dict[str, Any]:
        """Return guarded symbolic process values; unsupported operations are explicit."""
        from .lowering import LoweredIR

        return LoweredIR(self, path).serialize()

    def circuit(self, path: str = "/") -> dict[str, Any]:
        """Expose scope-local net identity and instance terminals independently of layout."""
        from .circuit import Circuit

        return Circuit(self, path).serialize()

    def canonical(self, path: str = "/") -> dict[str, Any]:
        """Validated structural and behavioral IR without graphical assumptions."""
        from .canonical import CanonicalCircuit

        return CanonicalCircuit(self, path).serialize()

    def schematic(self, path: str = "/") -> dict[str, Any]:
        """Net-centric CAD contract; no placement or inferred electrical edges."""
        from .schematic import Schematic

        return Schematic(self, path).serialize()

    def audit(self, *, limit: int = 1500) -> dict[str, Any]:
        """Audit every elaborated scope, without pretending to prove net equivalence.

        Reports source mapping, visibly unresolved connections and truncation.
        Unlike a successful Slang exit status, these are *viewer* checks.
        This explicit operation is deliberately separate from lazy UI loading.
        """
        scopes = []
        totals = {"nodes": 0, "edges": 0, "unbound_pins": 0,
                  "unresolved_pins": 0, "partial_pins": 0, "missing_sources": 0,
                  "truncated_scopes": 0}
        for path, scope in self.scopes.items():
            graph = self.diagram(path, limit=limit)
            source = self._source_path(scope)
            file = source.relative_to(self.root).as_posix() if source else ""
            pins = graph["connectivity"]
            row = {"path": path, "module": scope.module, "file": file,
                   "source_status": "available" if source else "unresolved",
                   "nodes": len(graph["nodes"]), "edges": len(graph["edges"]),
                   "truncated": graph["truncated"], **pins}
            scopes.append(row)
            totals["nodes"] += row["nodes"]
            totals["edges"] += row["edges"]
            for key in ("unbound_pins", "unresolved_pins", "partial_pins"):
                totals[key] += pins[key]
            totals["missing_sources"] += int(source is None)
            totals["truncated_scopes"] += int(graph["truncated"])
        return {"schema": "flexsoc.rtl_viewer.audit.v1", "elaboration_verified": self.verified,
                "top": self.top, "revision": self.revision, "scopes": scopes,
                "totals": totals, "qualified": self.verified and not any((
                    totals["unbound_pins"], totals["unresolved_pins"],
                    totals["missing_sources"], totals["truncated_scopes"])),
                "qualification_scope": "structural viewer integrity, not RTL simulation or equivalence"}

    def _source_path(self, scope: Scope) -> Path | None:
        if not scope.source:
            return None
        candidate = Path(scope.source)
        resolved = (self.root / candidate).resolve()
        return resolved if resolved.is_relative_to(self.root) and resolved.is_file() else None

    def source(self, path: str) -> dict[str, Any]:
        scope = self._scope(path)
        source = self._source_path(scope)
        if source is None:
            return {"status": "unresolved", "module": scope.module, "file": scope.source,
                    "code": "", "reason": "Slang AST did not provide a project-local source location"}
        if source.stat().st_size > 2_000_000:
            return {"status": "unresolved", "reason": "source too large (>2 MB)"}
        return {"status": "available", "module": scope.module, "file": source.relative_to(self.root).as_posix(),
                "line": scope.line, "code": source.read_text(encoding="utf-8", errors="replace")}

    def follow(self, path: str, child: str, signal_id: str) -> dict[str, Any]:
        """Allow cross-boundary tracking only when explicit Slang bindings prove it."""
        scope = self._scope(path)
        target = self._scope(child)
        if child not in scope.children:
            return {"status": "unresolved", "reason": "not a direct elaborated child"}
        selected = signal_id.removeprefix(path + "::sig:")
        if selected not in self._signals(scope):
            return {"status": "unresolved", "reason": "signal does not belong to parent scope"}
        matches = [(port, mapping) for sig, port, _direction, mapping
                   in self._bindings(scope, target, set(self._signals(scope))) if sig == selected]
        if len(matches) == 1 and matches[0][1] == "direct":
            port = matches[0][0]
            return {"status": "resolved", "signal_id": child + "::sig:" + port, "signal": port}
        return {"status": "ambiguous" if len(matches) > 1 else "unresolved",
                "candidates": [port for port, _mapping in matches],
                "reason": "Only unambiguous whole-signal elaborated port mappings can be followed; slices are shown but cannot be tracked bit-exactly"}

    def cone(self, path: str, from_id: str, to_id: str, *, limit: int = 12) -> dict[str, Any]:
        if not 1 <= limit <= 100:
            raise ValueError("cone path limit outside 1..100")
        graph = self.diagram(path, limit=1500)
        node_ids = {n["id"] for n in graph["nodes"]}
        if from_id not in node_ids or to_id not in node_ids:
            return {"status": "unresolved", "reason": "endpoints not in current graph slice", "paths": []}
        neighbours: dict[str, list[str]] = {}
        for edge in graph["edges"]:
            if edge["resolved"]:
                neighbours.setdefault(edge["source"], []).append(edge["target"])
        work = deque([[from_id]])
        found: list[list[str]] = []
        visits = 0
        while work and len(found) < limit and visits < 4000:
            chain = work.popleft()
            visits += 1
            if chain[-1] == to_id:
                found.append(chain)
            elif len(chain) < 40:
                work.extend([*chain, nxt] for nxt in neighbours.get(chain[-1], ()) if nxt not in chain)
        sequential = {n["id"] for n in graph["nodes"] if n["type"] in ("register", "counter", "fsm")}
        return {"status": "resolved" if found else "no_path", "paths": found,
                "sequential_boundaries": [list(sequential.intersection(chain)) for chain in found],
                "truncated": bool(work) or graph["truncated"], "scope": "RTL AST dependencies, not STA"}

    def lint(self, path: str) -> dict[str, Any]:
        """Read-only file-level lint evidence; never guess an elaborated instance.

        Lint source paths may be relative to either the project root or the
        qualification run (generated RTL).  Preserve all diagnostics and the
        original provenance, including unmatched paths.
        """
        scope = self._scope(path)
        if not self.run:
            return {"status": "unavailable", "diagnostics": []}
        report = self.run / "dv/lint/slang/summary.json"
        if not report.is_file():
            return {"status": "unavailable", "diagnostics": []}
        source = self._source_path(scope)
        if source is None:
            return {"status": "unresolved", "diagnostics": [], "reason": "source mapping unavailable"}
        payload = json.loads(report.read_text(encoding="utf-8"))
        items = []
        for item in payload.get("diagnostics", []):
            if not isinstance(item, dict):
                continue
            raw = str(item.get("file") or "")
            if not raw:
                continue
            relative = Path(raw)
            if relative.is_absolute():
                candidates = (relative.resolve(),)
            else:
                candidates = ((self.root / relative).resolve(), (self.run / relative).resolve())
            if source in candidates:
                items.append(item)
        return {"status": "available", "diagnostics": items, "total": len(items),
                "scope": "file-level only; instance attribution not established",
                "file": source.relative_to(self.root).as_posix()}
