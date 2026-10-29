"""Versioned graph projection of the *elaborated* slang AST.

Unknown language constructs are not interpreted from RTL text. The renderer gets
only proven AST relationships; unsupported relationships remain visibly unknown.
"""
from __future__ import annotations
import stat
import os

from collections import deque
from dataclasses import dataclass, field
import json
from pathlib import Path
from typing import Any, Iterator

from .slang import SlangReferences
from .compiler import ast_revision
from .connectivity import GraphEdges, OperatorResolver, PortResolver, SymbolTable as ASTReferences
from .sequential_controls import collect as collect_sequential_controls
from .sequential_profile import summarize as summarize_sequential_profile


SIGNAL_KINDS = frozenset({"Port", "Variable", "Net", "NetSymbol", "VariableSymbol", "InterfacePort"})
ASSIGN_KINDS = frozenset({"Assignment", "AssignmentExpression", "ContinuousAssign", "NonblockingAssignment"})
# Only explicit expression nodes in the elaborated AST become functional symbols.
OPERATOR_KINDS = frozenset({"BinaryOp", "UnaryOp", "ConditionalOp", "ConditionalExpression", "Conversion", "Concatenation"})
BLOCK_KINDS = frozenset({"GenerateBlock", "GenerateBlockArray", "GenerateBlockSymbol", "InstanceArray"})


def _fsrtl_evidence_read_report(run: Path, max_bytes: int = 8_000_000) -> tuple[str, Any]:
    """Safely read run-scoped JSON; never follow symlinks below the run root."""
    flags = os.O_RDONLY | getattr(os, "O_CLOEXEC", 0)
    nofollow = getattr(os, "O_NOFOLLOW", 0)
    directory = getattr(os, "O_DIRECTORY", 0)
    try:
        fd = os.open(run, flags | directory)
        try:
            for component in ("dv", "lint", "slang"):
                child = os.open(component, flags | directory | nofollow, dir_fd=fd)
                os.close(fd)
                fd = child
            report_fd = os.open("summary.json", flags | nofollow | getattr(os, "O_NONBLOCK", 0), dir_fd=fd)
            try:
                meta = os.fstat(report_fd)
                if not stat.S_ISREG(meta.st_mode):
                    return "unavailable", "lint report is not a regular file"
                if meta.st_size > max_bytes:
                    return "unsupported", "lint report exceeds 8 MB limit"
                with os.fdopen(report_fd, "rb", closefd=False) as stream:
                    raw = stream.read(max_bytes + 1)
                if len(raw) > max_bytes:
                    return "unsupported", "lint report exceeds 8 MB limit"
            finally:
                os.close(report_fd)
        finally:
            os.close(fd)
    except OSError:
        return "unavailable", "lint report cannot be accessed safely"
    try:
        payload = json.loads(raw.decode("utf-8"))
    except (UnicodeError, json.JSONDecodeError):
        return "unsupported", "lint report is not valid UTF-8 JSON"
    if not isinstance(payload, dict) or not isinstance(payload.get("diagnostics"), list):
        return "unsupported", "lint report lacks a diagnostics array"
    return "available", payload


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
                    # Slang may serialize the elaborated loop iteration as an
                    # unnamed GenerateBlock with constructIndex. Preserve the
                    # array element in the hierarchy identity: g/g[0], g/g[1].
                    if (member.get("branchKind") == "LoopIteration"
                            and isinstance(member.get("constructIndex"), int)
                            and ancestors and not (label and label.endswith("]"))):
                        pieces = (*ancestors, f"{ancestors[-1]}[{member['constructIndex']}]")
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

    def hierarchy_children(self, path: str = "/", *, offset: int = 0, limit: int = 64) -> dict[str, Any]:
        """Page direct elaborated children without projecting their RTL graphs.

        The compiler-derived scope index is authoritative. This endpoint only
        reduces the data transferred to the UI; initial AST elaboration/indexing
        is still eager and is not advertised as incremental compilation.
        """
        parent = self._scope(path)
        if offset < 0 or not 1 <= limit <= 256:
            raise ValueError("hierarchy offset must be nonnegative and limit 1..256")
        children = sorted(parent.children)
        page = children[offset:offset + limit]
        items = []
        for child_path in page:
            child = self.scopes[child_path]
            items.append({"path": child.path, "name": child.name,
                          "module": child.module, "group": child.group,
                          "has_children": bool(child.children),
                          "children_count": len(child.children)})
        return {"schema": "flexsoc.rtl_viewer.hierarchy.v1", "revision": self.revision,
                "path": path, "offset": offset, "limit": limit,
                "total": len(children), "has_more": offset + len(items) < len(children),
                "items": items}

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
            # Slang can prefix a type display with its internal object address.
            # Do not expose identity tokens as RTL type names.
            type_parts = type_label.split(None, 1)
            if len(type_parts) == 2 and type_parts[0].isdigit() and len(type_parts[0]) >= 8:
                type_label = type_parts[1]
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

        def literal_operands(expr: dict) -> dict[str, str]:
            """Only show AST-proven literals, never inferred constants/net names."""
            kind = str(expr.get("kind", ""))
            if kind == "BinaryOp":
                candidates = (("A", expr.get("left")), ("B", expr.get("right")))
            elif kind in {"ConditionalOp", "ConditionalExpression"}:
                predicate = next((expr.get(key) for key in ("condition", "predicate", "selector", "cond")
                                  if isinstance(expr.get(key), dict)), None)
                candidates = (("A", expr.get("right", expr.get("falseExpr"))),
                              ("B", expr.get("left", expr.get("trueExpr"))), ("S", predicate))
            else:
                candidates = ()
            result: dict[str, str] = {}
            for role, value in candidates:
                if not isinstance(value, dict):
                    continue
                # A literal may be wrapped by an explicit Slang conversion.
                # Follow only AST expression wrappers, never invent a constant.
                candidate = value
                for _ in range(5):
                    if candidate.get("kind") in {"IntegerLiteral", "IntegerLiteralExpression", "UnbasedUnsizedLiteral",
                                                 "UnbasedUnsizedIntegerLiteral", "StringLiteral", "RealLiteral"}:
                        break
                    if candidate.get("kind") not in {"Conversion", "ConversionExpression", "ImplicitConversion"}:
                        break
                    candidate = next((candidate[k] for k in ("operand", "expression", "expr", "value")
                                      if isinstance(candidate.get(k), dict)), {})
                if candidate.get("kind") not in {"IntegerLiteral", "IntegerLiteralExpression", "UnbasedUnsizedLiteral",
                                                  "UnbasedUnsizedIntegerLiteral", "StringLiteral", "RealLiteral"}:
                    continue
                raw = candidate.get("value")
                if isinstance(raw, (str, int, float)) and str(raw):
                    result[role] = str(raw)[:80]
            return result

        def describe_operand(value: Any) -> str:
            """AST-only pin annotation. Never creates an electrical connection."""
            if not isinstance(value, dict):
                return ""
            kind = str(value.get("kind", ""))
            if kind in {"IntegerLiteral", "IntegerLiteralExpression", "UnbasedUnsizedLiteral",
                        "UnbasedUnsizedIntegerLiteral", "RealLiteral", "StringLiteral"}:
                raw = value.get("value")
                return str(raw)[:72] if isinstance(raw, (str, int, float)) else ""
            if kind in {"MemberAccess", "MemberSelect"}:
                base = value.get("value", value.get("expression"))
                member = value.get("member", value.get("memberName", value.get("name")))
                if isinstance(member, dict):
                    member = member.get("name", member.get("memberName"))
                if isinstance(member, str) and member:
                    prefix = describe_operand(base)
                    if not prefix:
                        refs = symbols.refs(base)
                        prefix = refs[0] if len(refs) == 1 else ""
                    return (prefix + "." + member)[:72] if prefix else "." + member[:71]
            if kind in {"Conversion", "ConversionExpression", "ImplicitConversion"}:
                wrapped = next((value[k] for k in ("operand", "expression", "expr", "value")
                                if isinstance(value.get(k), dict)), None)
                if wrapped is not None:
                    inner = describe_operand(wrapped)
                    if inner:
                        return inner
            refs = symbols.refs(value)
            if len(refs) == 1:
                return refs[0][:72]
            return ""

        def operand_details(expr: dict) -> dict[str, str]:
            kind = str(expr.get("kind", ""))
            if kind == "BinaryOp":
                roles = (("A", expr.get("left")), ("B", expr.get("right")))
            elif kind in {"ConditionalOp", "ConditionalExpression"}:
                predicate = next((expr.get(k) for k in ("condition", "predicate", "selector", "cond")
                                  if isinstance(expr.get(k), dict)), expr.get("conditions"))
                roles = (("A", expr.get("right", expr.get("falseExpr"))),
                         ("B", expr.get("left", expr.get("trueExpr"))), ("S", predicate))
            else:
                roles = ()
            return {role: label for role, value in roles
                    if (label := describe_operand(value))}

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
                        if operator and (sources or operator.get("kind") in OPERATOR_KINDS):
                            op_id = "op:" + str(len(operators))
                            op_name = str(operator.get("op") or operator.get("operator") or operator["kind"])
                            shape = "mux" if operator["kind"] in {"ConditionalOp", "ConditionalExpression"} else "arith" if operator["kind"] == "BinaryOp" else "logic"
                            role_inputs = operands.inputs(operator)
                            # Only AST-proven literal operands. Do not create a
                            # fictitious signal/edge for a constant input.
                            operators.append({"name": op_name, "key": op_id, "kind": operator["kind"],
                                              "literalOperands": literal_operands(operator),
                                              "operandDetails": operand_details(operator),
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
            # A multi-event sensitivity list is NOT proof that each rising
            # event is a clock. Preserve edge polarity and avoid labeling an
            # asynchronous reset as CLK based on polarity alone.
            valid_events = [e for e in events if isinstance(e, dict)
                            and e.get("kind") == "SignalEvent"
                            and str(e.get("edge", "")) in ("PosEdge", "NegEdge")]
            unique_event = len(valid_events) == 1
            for event in valid_events:
                edge_kind = str(event["edge"])
                for source in symbols.refs(event.get("expr")):
                    for target in sorted(destinations):
                        edges.append({"source": source, "target": target, "type": "event", "net": source,
                                      "pin": "CLK" if unique_event else "EVENT",
                                      "eventEdge": edge_kind, "timingRole": "single_event" if unique_event else "ambiguous_event",
                                      "mapping": "direct"})
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
        # Facts for symbol rendering: edge sensitivity is AST verified;
        # reset/enable/load roles are deliberately NOT inferred from names.
        event_facts: dict[str, list[dict[str, str]]] = {}
        for relation in logical_edges:
            if relation.get("type") != "event" or relation.get("target") not in registers:
                continue
            fact = {"signal": relation["source"], "edge": relation.get("eventEdge", ""),
                    "role": relation.get("timingRole", "ambiguous_event")}
            facts = event_facts.setdefault(relation["target"], [])
            if fact not in facts:
                facts.append(fact)
        # Enumerate AST-proven guard paths for sequential destinations.
        # Constant RHS and guarded assignment are CANDIDATES, not reset/enable proof.
        symbols_for_controls = ASTReferences(scope.node["body"].get("members", ()), set(signals))
        sequential_guards: dict[str, list[dict]] = {}
        for process in scope.node["body"].get("members", ()):
            if not isinstance(process, dict) or process.get("kind") != "ProceduralBlock":
                continue
            if str(process.get("procedureKind", process.get("procedure", ""))).lower() not in ("alwaysff", "always_ff"):
                continue
            process_body = process.get("body", {})
            if isinstance(process_body, dict) and process_body.get("kind") == "Timed":
                process_body = process_body.get("stmt")
            for target, paths in collect_sequential_controls(process_body, symbols_for_controls).items():
                for p in paths:
                    dest_paths = sequential_guards.setdefault(target, [])
                    if p not in dest_paths:
                        dest_paths.append(p)
        # Classify two-event always_ff controls only when AST guard paths prove
        # an asynchronous reset branch. Never derive roles from signal names.
        for target, facts in event_facts.items():
            if len(facts) != 2 or any(f["role"] != "ambiguous_event" for f in facts):
                continue
            candidates = []
            for fact in facts:
                sig = fact["signal"]
                paths = sequential_guards.get(target, ())
                reset_paths = [p for p in paths if p.get("constantRhsCandidate") is True
                               and any(sig in g.get("signals", ()) for g in p.get("guards", ()))]
                if reset_paths and all(len(g.get("signals", ())) == 1
                                       for p in reset_paths for g in p.get("guards", ())
                                       if sig in g.get("signals", ())):
                    candidates.append(sig)
            if len(candidates) == 1:
                for fact in facts:
                    fact["role"] = "async_reset" if fact["signal"] == candidates[0] else "clock"
        for relation in logical_edges:
            if relation.get("type") != "event":
                continue
            matched = next((f for f in event_facts.get(relation["target"], ())
                            if f["signal"] == relation["source"] and f["edge"] == relation.get("eventEdge")), None)
            if matched and matched["role"] in ("clock", "async_reset"):
                relation["pin"] = "CLK" if matched["role"] == "clock" else "RST"
                relation["timingRole"] = matched["role"]
        # The guarded reset branch is already described by sequentialGuards.
        # When the same AST-proven async reset also has an RST terminal, a
        # second control edge to D is NOT a second physical wire. Remove only
        # that duplicate graph relationship, leaving every other control edge.
        reset_terminals = {(r["source"], r["target"]) for r in logical_edges
                           if r.get("type") == "event" and r.get("pin") == "RST"
                           and r.get("timingRole") == "async_reset"}
        logical_edges = [r for r in logical_edges
                         if not (r.get("type") == "control"
                                 and (r.get("source"), r.get("target")) in reset_terminals)]
        # A guard reading the register's own Q does not create a second D pin.
        # Keep the AST guard evidence in sequentialGuards/sequentialProfile;
        # only suppress the synthetic direct physical self-edge. Real
        # feedback through an AST expression/operator remains untouched.
        logical_edges = [r for r in logical_edges
                         if not (r.get("type") == "control"
                                 and r.get("source") == r.get("target")
                                 and r.get("target") in registers)]
        # An AST-proven async reset constant write is handled by the RST pin,
        # not a second normal D driver. Restrict suppression to *unfed*
        # conversion operators at the exact guarded assignment line.
        # Unlike a generic sequential-edge filter, this keeps genuine D
        # computation and every operand-bearing operator intact.
        reset_write_lines = {
            (target, int(path["line"]))
            for target, facts in event_facts.items()
            if any(f["role"] == "async_reset" for f in facts)
            for path in sequential_guards.get(target, ())
            if path.get("constantRhsCandidate") is True
            and isinstance(path.get("line"), int)
            and any(any(f["signal"] in guard.get("signals", ())
                        for guard in path.get("guards", ()))
                    for f in facts if f["role"] == "async_reset")
        }
        fed_operator_keys = {str(r["target"]) for r in logical_edges
                             if str(r.get("target", "")).startswith("op:")}
        removable_casts = {
            str(op["key"])
            for op in operators
            if op.get("kind") == "Conversion"
            and str(op.get("key", "")) not in fed_operator_keys
            and any(r.get("source") == op.get("key")
                    and r.get("type") == "sequential"
                    and (r.get("target"), op.get("line")) in reset_write_lines
                    for r in logical_edges)
        }
        if removable_casts:
            # Do not discard an operator used anywhere else.
            removable_casts = {
                key for key in removable_casts
                if all(r.get("type") == "sequential"
                       and (r.get("target"), next(op["line"] for op in operators
                                                  if str(op["key"]) == key)) in reset_write_lines
                       for r in logical_edges if r.get("source") == key)
            }
            logical_edges = [r for r in logical_edges
                             if r.get("source") not in removable_casts]
            operators = [op for op in operators
                         if str(op.get("key")) not in removable_casts]
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
                          "direction": sig["direction"], "width": sig["width"], "dimensions": sig["dimensions"], "line": sig["line"],
                          "sequentialTiming": sorted(event_facts.get(name, []), key=lambda item: (item["signal"], item["edge"])) if name in registers else [],
                          "sequentialGuards": sequential_guards.get(name, []) if name in registers else [],
                          "sequentialProfile": summarize_sequential_profile(event_facts.get(name, []), sequential_guards.get(name, [])) if name in registers else None})
        for operator in operators:
            if len(nodes) >= limit:
                break
            nodes.append({"id": prefix + operator["key"], "name": operator["name"],
                          "type": "operator", "kind": operator["kind"], "shape": operator["shape"], "line": operator["line"],
                          "literalOperands": operator.get("literalOperands", {}),
                          "operandDetails": operator.get("operandDetails", {}),
                          "pins": operator.get("pins", [])})

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
                  "truncated_scopes": 0, "edge_mapping": {}, "partial_by_type": {}}
        for path, scope in self.scopes.items():
            graph = self.diagram(path, limit=limit)
            source = self._source_path(scope)
            file = source.relative_to(self.root).as_posix() if source else ""
            pins = graph["connectivity"]
            # Count the graph's existing semantic labels. An edge marked
            # ``partial`` is not evidence for a bit-exact connection.
            edge_mapping: dict[str, int] = {}
            partial_by_type: dict[str, int] = {}
            for edge in graph["edges"]:
                mapping = str(edge.get("mapping", "unknown"))
                edge_mapping[mapping] = edge_mapping.get(mapping, 0) + 1
                if mapping == "partial":
                    kind = str(edge.get("type", "unknown"))
                    partial_by_type[kind] = partial_by_type.get(kind, 0) + 1
            row = {"path": path, "module": scope.module, "file": file,
                   "source_status": "available" if source else "unresolved",
                   "nodes": len(graph["nodes"]), "edges": len(graph["edges"]),
                   "edge_mapping": dict(sorted(edge_mapping.items())),
                   "partial_by_type": dict(sorted(partial_by_type.items())),
                   "truncated": graph["truncated"], **pins}
            scopes.append(row)
            totals["nodes"] += row["nodes"]
            totals["edges"] += row["edges"]
            for key in ("edge_mapping", "partial_by_type"):
                accumulator = totals[key]
                for label, count in row[key].items():
                    accumulator[label] = accumulator.get(label, 0) + count
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

    def occurrences(self, path: str, signal: str) -> dict[str, Any]:
        from .occurrences import occurrences
        return occurrences(self, path, signal)

    def follow(self, path: str, child: str, signal_id: str) -> dict[str, Any]:
        """Allow cross-boundary tracking only when explicit Slang bindings prove it."""
        scope = self._scope(path)
        target = self._scope(child)
        if child not in scope.children:
            return {"status": "unresolved", "reason": "not a direct elaborated child"}
        prefix = path + "::sig:"
        if not signal_id.startswith(prefix):
            return {"status": "unresolved", "reason": "signal ID does not belong to parent scope"}
        selected = signal_id[len(prefix):]
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
            return {"status": "unresolved", "reason": "endpoints not in current graph slice", "paths": [],
                    "truncated": graph["truncated"]}
        neighbours: dict[str, set[str]] = {}
        unresolved_edges = False
        for edge in graph["edges"]:
            if edge["resolved"]:
                neighbours.setdefault(edge["source"], set()).add(edge["target"])
            else:
                # Unknown or partial relations cannot prove path absence.
                unresolved_edges = True
        work = deque([[from_id]])
        found: list[list[str]] = []
        visits = 0
        depth_limited = False
        frontier_limited = False
        while work and len(found) < limit and visits < 4000:
            chain = work.popleft()
            visits += 1
            if chain[-1] == to_id:
                found.append(chain)
                continue
            next_hops = [nxt for nxt in sorted(neighbours.get(chain[-1], ())) if nxt not in chain]
            if len(chain) >= 40:
                depth_limited |= bool(next_hops)
                continue
            for nxt in next_hops:
                if len(work) >= 4000:
                    frontier_limited = True
                    break
                work.append([*chain, nxt])
        sequential = {n["id"] for n in graph["nodes"] if n["type"] in ("register", "counter", "fsm")}
        truncated = bool(work) or graph["truncated"] or depth_limited or frontier_limited or unresolved_edges
        status = "resolved" if found else "incomplete" if truncated else "no_path"
        return {"status": status, "paths": found,
                "sequential_boundaries": [sorted(sequential.intersection(chain)) for chain in found],
                "truncated": truncated, "scope": "RTL AST dependencies, not STA"}

    def evidence(self) -> dict[str, Any]:
        """Run-wide lint inventory; no implicit attribution to elaborated instances.

        Keep original diagnostics in the source report. Return only aggregate
        metadata and a bounded set of distinct source labels to the browser.
        """
        if not self.run:
            return {"status": "unavailable", "total": 0, "reason": "no run attached"}
        status, report = _fsrtl_evidence_read_report(self.run)
        if status != "available":
            return {"status": status, "total": 0, "reason": report}
        diagnostics = [item for item in report["diagnostics"] if isinstance(item, dict)]
        priorities: dict[str, int] = {}
        for item in diagnostics:
            priority = str(item.get("priority") or item.get("severity") or "unknown")
            priorities[priority] = priorities.get(priority, 0) + 1
        # Labels may refer to external or generated files. They are *not*
        # treated as authoritative mappings to a hierarchy instance.
        return {"status": "available", "total": len(diagnostics),
                "priorities": dict(sorted(priorities.items())),
                "source_files": len({str(d.get("file")) for d in diagnostics if d.get("file")}),
                "tool": "slang", "attribution": "run-level only; no instance mapping",
                "report": "dv/lint/slang/summary.json"}

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
