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
from .sequential_controls import collect as collect_sequential_controls, is_literal_rhs
from .sequential_profile import summarize as summarize_sequential_profile
from .sequential_projection import project_destination


SIGNAL_KINDS = frozenset({"Port", "Variable", "Net", "NetSymbol", "VariableSymbol", "InterfacePort"})
ASSIGN_KINDS = frozenset({"Assignment", "AssignmentExpression", "ContinuousAssign", "NonblockingAssignment"})
# Only explicit expression nodes in the elaborated AST become functional symbols.
OPERATOR_KINDS = frozenset({"BinaryOp", "UnaryOp", "ConditionalOp", "ConditionalExpression", "Conversion", "Concatenation", "Replication", "MemberAccess", "Call", "RangeSelect", "ElementSelect"})
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


def member_field_name(expr: dict[str, Any]) -> str:
    """An AST member's display name, never a guessed RTL-text field.

    Slang's JSON member value may be '6338716865104 aw_valid': the
    numeric token is a compiler address, not part of the field name.
    Reject missing/non-identifier metadata instead of inventing a selector.
    """
    if expr.get("kind") != "MemberAccess":
        return ""
    member = expr.get("member")
    if isinstance(member, dict):
        member = member.get("name")
    if not isinstance(member, str):
        return ""
    address, sep, label = member.partition(" ")
    if sep and address.isdigit():
        member = label
    if not member or not (member[0].isalpha() or member[0] in "_$"):
        return ""
    if any(not (c.isalnum() or c in "_$") for c in member):
        return ""
    return member[:80]


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

    def __init__(self, ast: dict[str, Any], *, root: Path, top: str, run: Path | None = None,
                 verified: bool = False, source_roots: tuple[Path, ...] = ()):
        if not isinstance(ast.get("design"), dict):
            raise ValueError("expected a Slang elaborated AST containing 'design'")
        self.root = root.resolve()
        # The run has generated RTL, while shared IP may be authored elsewhere
        # in the same repository. Only explicitly authorized roots are readable.
        # Never search arbitrary filesystem directories or match basenames.
        self.run = run.resolve() if run else None
        roots = (self.root, *((self.run,) if self.run else ()),
                 *(Path(candidate).expanduser().resolve() for candidate in source_roots))
        self.source_roots = tuple(dict.fromkeys(r for r in roots if r.is_dir()))
        self.top = top
        self.verified = verified
        self.revision = ast_revision(ast, top=top)
        self.references = SlangReferences(ast)
        # Slang references to functions carry globally unique object addresses.
        # Build this registry once: functions may be declared in packages, not
        # just in the module containing their Call expression.
        self.subroutines: dict[str, dict[str, Any]] = {}
        conflicted: set[str] = set()
        for entry in objects(ast):
            if entry.get("kind") != "Subroutine":
                continue
            address = str(entry.get("addr", ""))
            if not address.isdecimal():
                continue
            previous = self.subroutines.get(address)
            if previous is not None and previous != entry:
                conflicted.add(address)
            else:
                self.subroutines[address] = entry
        for address in conflicted:
            self.subroutines.pop(address, None)
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
                "sourceFiles": sorted({self._source_label(source)
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
    def _assignments(scope: Scope, declared: set[str],
                     subroutines: dict[str, dict[str, Any]] | None = None) -> tuple[list[dict], set[str], list[dict], set[str], set[str]]:
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
        # Elaborated parameters AND enum members are value sources, never
        # electrical nets. Use compiler addresses and proven constant initializers,
        # not display names (which may repeat in different scopes).
        constant_values: dict[str, str] = {}
        constant_collisions: set[str] = set()
        for declaration in objects(scope.node["body"].get("members", ())):
            if declaration.get("kind") not in {"Parameter", "ParameterSymbol", "EnumValue"}:
                continue
            address = str(declaration.get("addr", ""))
            val = declaration.get("value")
            if (address.isdecimal() and address not in symbols.by_address
                    and isinstance(val, (int, str)) and not isinstance(val, bool)
                    and len(str(val)) <= 80 and str(val)
                    and isinstance(declaration.get("initializer"), dict)
                    and is_literal_rhs(declaration["initializer"])):
                if address in constant_values or address in constant_collisions:
                    constant_values.pop(address, None)
                    constant_collisions.add(address)
                else:
                    constant_values[address] = str(val)

        def compiler_constant_ref(expr: Any) -> str | None:
            if not isinstance(expr, dict) or expr.get("kind") not in {
                    "NamedValue", "SymbolReference", "HierarchicalValue"}:
                return None
            reference = expr.get("symbol")
            if isinstance(reference, dict):
                reference = reference.get("addr")
            address = str(reference or "").partition(" ")[0]
            return constant_values.get(address) if address.isdecimal() else None

        # Slang's Call.subroutine is an address-qualified reference to a
        # Subroutine, not its display name. Only an exact, unique, scope-local
        # function definition can authorize a FUNCTION value node. This is
        # an opaque function call, NOT an inlined/synthesized implementation.
        functions: dict[str, dict] = dict(subroutines or {})
        duplicate_functions: set[str] = set()
        for member in scope.node["body"].get("members", ()):
            if not isinstance(member, dict) or member.get("kind") != "Subroutine":
                continue
            address = str(member.get("addr", ""))
            if not address.isdecimal():
                continue
            previous = functions.get(address)
            if previous is not None and previous != member:
                duplicate_functions.add(address)
            else:
                functions[address] = member
        for address in duplicate_functions:
            functions.pop(address, None)

        def function_info(expr: dict) -> tuple[dict, list[tuple[str, dict]]] | None:
            """Validate call target, argument order/directions and return type.

            Function calls may have side effects; we do not claim bit-level
            connectivity inside them. We only project AST argument values and
            the return value as an opaque expression boundary.
            """
            if expr.get("kind") != "Call" or not isinstance(expr.get("subroutine"), str):
                return None
            raw = expr["subroutine"].partition(" ")[0]
            definition = functions.get(raw) if raw.isdecimal() else None
            if (not definition or definition.get("subroutineKind") != "Function"
                    or not isinstance(definition.get("name"), str)
                    or not definition["name"] or not isinstance(definition.get("body"), dict)
                    or definition.get("returnType") in (None, "", "void")
                    or expr.get("type") in (None, "", "void")):
                return None
            formals = [m for m in definition.get("members", ())
                       if isinstance(m, dict) and m.get("kind") == "FormalArgument"]
            actuals = expr.get("arguments")
            if (not isinstance(actuals, list) or not 0 <= len(actuals) <= 16
                    or len(formals) != len(actuals)
                    or any(not isinstance(a, dict) or a.get("kind") == "EmptyArgument" for a in actuals)
                    or any(not isinstance(f.get("name"), str) or not f["name"]
                           or str(f.get("direction", "")).lower() not in {"in", "input"}
                           for f in formals)):
                return None
            return definition, [(f"I{i}", actual) for i, actual in enumerate(actuals)]

        def static_select(expr: dict) -> str | None:
            """Compiler-authored packed select, with an exact, bounded index.

            Slang supplies the index AST and source base independently. Reject
            computed/dynamic positions here: this is a value *projection*,
            never a claim of a bit-exact electrical splice or bus wiring.
            """
            kind = expr.get("kind")
            if kind not in {"RangeSelect", "ElementSelect"}:
                return None
            base = expr.get("value")
            if not isinstance(base, dict) or not (symbols.direct(base) is not None
                                                    or base.get("kind") in nested_kinds):
                return None

            def literal_number(part: Any) -> int | None:
                if not isinstance(part, dict) or part.get("kind") not in {
                        "IntegerLiteral", "IntegerLiteralExpression"}:
                    return None
                value = part.get("constant", part.get("value"))
                # Decimals only. Slang's sized / based literals are left
                # unsupported rather than implementing another SV evaluator.
                if not isinstance(value, (int, str)) or isinstance(value, bool):
                    return None
                raw = str(value)
                if not raw or len(raw) > 9 or not raw.isdecimal():
                    return None
                number = int(raw)
                return number if number <= 1_000_000 else None

            if kind == "ElementSelect":
                index = next((expr[k] for k in ("selector", "index") if isinstance(expr.get(k), dict)), None)
                number = literal_number(index)
                label = f"[{number}]" if number is not None else None
            else:
                if expr.get("selectionKind") not in {"Simple", None}:
                    return None
                left, right = literal_number(expr.get("left")), literal_number(expr.get("right"))
                label = f"[{left}:{right}]" if left is not None and right is not None else None
            if label is None:
                return None
            # If Slang supplies the base packed dimension, enforce bounds.
            # A missing or composite type is not parsed heuristically.
            import re
            typ = str(base.get("type") or "")
            width = re.fullmatch(r"(?:bit|logic|reg)\[(\d+):(\d+)\]", typ)
            if width:
                low, high = sorted((int(width[1]), int(width[2])))
                indices = ([left, right] if kind == "RangeSelect" else [number])
                if any(i is None or i < low or i > high for i in indices):
                    return None
            return label

        def expression_roles(expr: dict) -> tuple[tuple[str, Any], ...]:
            if expr.get("kind") == "Call":
                info = function_info(expr)
                return tuple(info[1]) if info else ()
            if expr.get("kind") in {"RangeSelect", "ElementSelect"}:
                return (("A", expr.get("value")),) if static_select(expr) else ()
            return operands.roles(expr)

        def literal_operands(expr: dict) -> dict[str, str]:
            """Only explicit AST literal operands, including CONCAT inputs."""
            result: dict[str, str] = {}
            for role, value in expression_roles(expr):
                if not isinstance(value, dict):
                    continue
                literal_parameter = compiler_constant_ref(value)
                if literal_parameter is not None:
                    result[role] = literal_parameter
                    continue
                candidate = value
                # Compiler-provided conversions may wrap a real literal.
                for _ in range(5):
                    if candidate.get("kind") in {"IntegerLiteral", "IntegerLiteralExpression",
                                                 "UnbasedUnsizedLiteral", "UnbasedUnsizedIntegerLiteral",
                                                 "StringLiteral", "RealLiteral"}:
                        break
                    if candidate.get("kind") not in {"Conversion", "ConversionExpression", "ImplicitConversion"}:
                        break
                    candidate = next((candidate[k] for k in ("operand", "expression", "expr", "value")
                                      if isinstance(candidate.get(k), dict)), {})
                if candidate.get("kind") not in {"IntegerLiteral", "IntegerLiteralExpression",
                                                   "UnbasedUnsizedLiteral", "UnbasedUnsizedIntegerLiteral",
                                                   "StringLiteral", "RealLiteral"}:
                    continue
                raw = candidate.get("value", candidate.get("literal"))
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
                if value.get("kind") == "MemberAccess":
                    member = member_field_name(value)
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
            return {role: label for role, value in expression_roles(expr)
                    if (label := describe_operand(value))}

        # An if/else is a proven *single* D-input MUX only when it is the
        # complete write site for one whole register in this elaborated scope.
        # Count all writes, including writes in other processes and selects,
        # before attempting to lower the procedural guard.
        write_counts: dict[str, int] = {}
        counted: set[int] = set()
        for statement in objects(scope.node["body"].get("members", ())):
            if id(statement) in counted:
                continue
            counted.add(id(statement))
            kind = str(statement.get("kind", ""))
            if kind in ASSIGN_KINDS or ("Assignment" in kind and "Pattern" not in kind):
                for target in symbols.writes(statement.get("left", statement.get("lhs"))):
                    write_counts[target] = write_counts.get(target, 0) + 1

        # A register written by multiple procedural processes has no single
        # compiler-proven D driver. Preserve the AST relationships for the
        # inspector, but never draw one process's write as the physical D.
        process_writers: dict[str, int] = {}
        for process in scope.node["body"].get("members", ()):
            if not isinstance(process, dict) or process.get("kind") != "ProceduralBlock":
                continue
            destinations = {target for item in objects(process.get("body"))
                            if item.get("kind") in ASSIGN_KINDS
                            for target in symbols.writes(item.get("left", item.get("lhs")))}
            for target in destinations:
                process_writers[target] = process_writers.get(target, 0) + 1
        multi_process_writes = {target for target, count in process_writers.items() if count > 1}

        # Only a compiler-backed expression node becomes a functional glyph.
        # Bounds avoid expanding pathological ASTs into unmanageable graphs.
        nested_kinds = OPERATOR_KINDS
        transparent_kinds = frozenset({"ParenthesizedExpression"})

        def unwrap_parentheses(value: Any) -> Any:
            for _ in range(16):
                if not isinstance(value, dict) or value.get("kind") not in transparent_kinds:
                    return value
                value = symbols._operand(value)
            return value

        def add_expression(expr: dict, *, depth: int = 0,
                           ancestors: frozenset[int] = frozenset()) -> str | None:
            """Lower one proven AST expression tree, never parsing source text.

            Each subexpression is a separate output conductor. Unsupported
            operands remain explicit, non-rendered dependencies. This is an
            expression graph, NOT a synthesized gate-level netlist.
            """
            if (depth >= 16 or len(operators) >= 256 or id(expr) in ancestors
                    or expr.get("kind") not in nested_kinds):
                return None
            call = function_info(expr) if expr.get("kind") == "Call" else None
            if expr.get("kind") == "Call" and call is None:
                return None
            # Slang can elaborate an entire expression into a compile-time
            # constant (including parameter references and replications).
            # Prefer one value source over several CAST/REP/CONCAT glyphs only
            # when the compiler explicitly supplies the result. An unknown
            # or dynamic expression is still lowered operand by operand.
            value = expr.get("constant")
            constant = (str(value) if isinstance(value, (str, int)) and
                        not isinstance(value, bool) and 0 < len(str(value)) <= 128 and
                        not any(ord(c) < 32 for c in str(value)) else None)
            if (constant is not None and expr.get("kind") in {
                    "Conversion", "Concatenation", "Replication", "BinaryOp",
                    "UnaryOp", "ConditionalOp", "ConditionalExpression"}):
                op_id = "op:" + str(len(operators))
                operators.append({"name": "CONST", "key": op_id,
                                  "kind": str(expr["kind"]), "shape": "constant",
                                  "constantValue": constant,
                                  "constantOrigin": str(expr["kind"]),
                                  "constantType": str(expr.get("type") or ""),
                                  "line": extract_location(expr)[1],
                                  "pins": ["Y"], "literalOperands": {},
                                  "operandDetails": {}})
                return op_id
            # Only an AST-backed, named struct member can be represented as
            # a field projection. Unknown selector metadata stays non-wired.
            field = member_field_name(expr) if expr.get("kind") == "MemberAccess" else ""
            if expr.get("kind") == "MemberAccess" and (
                    not field or not isinstance(expr.get("value"), dict)):
                return None
            selection = (static_select(expr) if expr.get("kind") in
                         {"RangeSelect", "ElementSelect"} else None)
            if expr.get("kind") in {"RangeSelect", "ElementSelect"} and selection is None:
                return None
            op_id = "op:" + str(len(operators))
            kind = str(expr["kind"])
            name = (call[0]["name"] if call else
                    "SliceSelect" if selection else "FieldSelect" if field else
                    str(expr.get("op") or expr.get("operator") or kind))
            shape = ("function" if call else "slice" if selection else "field" if field else
                     "mux" if kind in {"ConditionalOp", "ConditionalExpression"}
                     else "arith" if kind == "BinaryOp" else "logic")
            roles = expression_roles(expr)
            # A replication count is AST evidence, not a new input signal.
            repeat_count = None
            if kind == "Replication" and isinstance(expr.get("count"), dict):
                count = expr["count"].get("constant")
                if isinstance(count, (int, str)) and str(count).isdigit():
                    repeat_count = int(count)
            record = {"name": name, "key": op_id, "kind": kind,
                              **({"field": field} if field else {}),
                              **({"selection": selection, "selectionKind": kind,
                                  "selectionMapping": "AST partial bus projection"}
                                 if selection else {}),
                              "literalOperands": literal_operands(expr),
                              "operandDetails": operand_details(expr),
                              "shape": shape, "line": extract_location(expr)[1],
                              "pins": [*(pin for pin, _ in roles), "Y"],
                              **({"function": {"name": name,
                                                "definitionFile": call[0].get("source_file", ""),
                                                "definitionLine": call[0].get("source_line", 0),
                                                "returnType": call[0]["returnType"],
                                                "arguments": [formal["name"] for formal in
                                                              call[0].get("members", ())
                                                              if isinstance(formal, dict) and
                                                              formal.get("kind") == "FormalArgument"],
                                                "semantics": "opaque AST function call"}}
                                 if call else {}),
                              **({"repeatCount": repeat_count} if repeat_count is not None else {})}
            operators.append(record)
            parent_chain = ancestors | {id(expr)}
            for pin, raw in roles:
                operand = unwrap_parentheses(raw)
                if isinstance(operand, dict) and operand.get("kind") in nested_kinds:
                    inner = add_expression(operand, depth=depth+1, ancestors=parent_chain)
                    if inner is not None:
                        # A compiler AST value flows from inner.Y to outer.pin.
                        # It must not borrow the SV declaration identity of
                        # any signal referenced inside the nested expression.
                        edges.append({"source": inner, "target": op_id, "type": "data",
                                      "net": "", "pin": pin, "mapping": "expression"})
                        continue
                # A reference is a direct conductor. Complex unsupported
                # ASTs (select, concatenate, call, ...) keep only dependency
                # evidence and never tie several signals to one physical pin.
                bindings = operands.inputs_for_operand(pin, raw)
                for binding in bindings:
                    edges.append({"source": binding.signal, "target": op_id, "type": "data",
                                  "net": binding.signal, "pin": pin,
                                  # Concatenation membership is an AST-proven
                                  # value relationship, not a bit-exact offset.
                                  "mapping": "partial" if field or selection or kind in {"Concatenation", "Replication"}
                                  else binding.mapping,
                                  "rendered": binding.rendered})
                if (kind in {"Concatenation", "Replication"} and not bindings
                        and pin not in record["literalOperands"]):
                    # Preserve even a completely unknown input terminal. Do
                    # not pretend an absent source is a literal zero.
                    record.setdefault("operandStatus", {})[pin] = "AST operand unavailable"
            return op_id

        def statement_children(statement: dict) -> list[dict] | None:
            """Normalize Slang's statement containers, not expression semantics.

            Slang JSON emits both ``Block(body=List(list=[...]))`` and
            ``Block(body=<statement>)`` as well as simplified fixture forms
            with ``body`` / ``statements`` arrays. A named ``List`` contains
            statements under ``list``, not ``body``. Do not guess the contents
            of unknown objects or silently discard any member of a sequence.
            """
            kind = statement.get("kind")
            if kind not in {"Block", "List", "StatementList"}:
                return None
            raw = (statement.get("list") if kind == "List" else
                   statement.get("body", statement.get("statements")))
            if isinstance(raw, dict):
                raw = [raw]
            if not isinstance(raw, (list, tuple)) or not 1 <= len(raw) <= 32:
                return None
            return list(raw) if all(isinstance(item, dict) for item in raw) else None

        def unwrap_statement(statement: Any) -> Any:
            """Discard only provably transparent *single-statement* wrappers."""
            seen: set[int] = set()
            for _ in range(16):
                if not isinstance(statement, dict) or id(statement) in seen:
                    return None
                seen.add(id(statement))
                kind = statement.get("kind")
                if kind == "ExpressionStatement":
                    statement = statement.get("expr", statement.get("expression"))
                elif kind in {"Block", "List", "StatementList"}:
                    items = statement_children(statement)
                    if items is None or len(items) != 1:
                        return statement
                    statement = items[0]
                else:
                    return statement
            return None

        def lower_guarded_ff(node: dict, *, reset_writes: int = 0, expected_target: str | None = None) -> bool:
            """Lower a bounded, complete AST decision tree into priority D MUXes.

            The decision tree describes *one* register's next-state value,
            including implicit Q holds on unassigned paths. Each conditional
            tests its selector only if all enclosing conditions reached it.
            Preflight every branch and all writes before adding any graph
            objects: unsupported syntax cannot leave a partially routed D.
            This is a compiler-AST expression projection, not synthesis.
            """
            mux_limit = 16
            depth_limit = 12
            assignments: list[tuple[str, dict]] = []
            mux_count = 0
            # More than one procedural statement has scheduling semantics.
            # Only explicit nonblocking assignments may be folded: their RHS
            # reads pre-edge state, while the last executed NBA for a target
            # wins. A blocking assignment could alter later reads.
            sequence_mode = any(
                (children := statement_children(item)) is not None and len(children) > 1
                for item in objects(node)
            )

            # Process-local blocking temporaries are *values*, not flop pins.
            # Resolve only exact Slang declaration addresses inside this tree;
            # never infer a temporary from its display name.
            local_addrs: set[str] = set()
            local_ambiguous = False
            for declaration in objects(node):
                if declaration.get("kind") not in {"Variable", "VariableSymbol"}:
                    continue
                addr = str(declaration.get("addr", ""))
                if not addr.isdigit() or addr in local_addrs or any(
                        symbol_addr == addr for symbol_addr in symbols.by_address):
                    local_ambiguous = True
                    break
                # Initializers have elaboration / lifetime semantics which are
                # not yet modeled by this projection.
                if any(declaration.get(k) is not None
                       for k in ("initializer", "initialValue", "init")):
                    local_ambiguous = True
                    break
                local_addrs.add(addr)

            def local_ref(value: Any) -> str | None:
                if not isinstance(value, dict) or value.get("kind") not in {
                        "NamedValue", "SymbolReference", "HierarchicalValue"}:
                    return None
                ref = value.get("symbol", value.get("addr"))
                if isinstance(ref, dict):
                    ref = ref.get("addr")
                addr = str(ref or "").partition(" ")[0]
                return addr if addr in local_addrs else None

            substitution_budget = [0]

            def substitute(value: Any, temps: dict[str, dict], depth: int = 0) -> Any:
                """Snapshot blocking values at the AST read site (SSA-like)."""
                substitution_budget[0] += 1
                if depth >= 20 or substitution_budget[0] > 4096:
                    raise ValueError("temporary expression expansion limit")
                addr = local_ref(value)
                if addr is not None:
                    if addr not in temps:
                        raise ValueError("read of uninitialized process temporary")
                    # Clone so each read is the value at that exact statement,
                    # not the final value of the temporary after the block.
                    return substitute(temps[addr], {}, depth + 1)
                if isinstance(value, dict):
                    return {k: substitute(v, temps, depth + 1) for k, v in value.items()}
                if isinstance(value, list):
                    return [substitute(v, temps, depth + 1) for v in value]
                if isinstance(value, tuple):
                    return tuple(substitute(v, temps, depth + 1) for v in value)
                return value

            def predicate_proven(expr: Any, depth: int = 0,
                                seen: frozenset[int] = frozenset()) -> bool:
                """Every leaf of an AST predicate must have a proven source.

                A partial array select or unrecognized operator is not proof
                of a physical control wire. Reject whole predicates rather
                than silently connecting some of their operand dependencies.
                """
                expr = unwrap_parentheses(expr)
                if not isinstance(expr, dict) or depth >= 12 or id(expr) in seen:
                    return False
                if (symbols.direct(expr) is not None or is_literal_rhs(expr)
                        or compiler_constant_ref(expr) is not None):
                    return True
                if expr.get("kind") not in nested_kinds:
                    return False
                if expr.get("kind") == "Call" and function_info(expr) is None:
                    return False
                if expr.get("kind") in {"RangeSelect", "ElementSelect"} and static_select(expr) is None:
                    return False
                roles = expression_roles(expr)
                return (0 < len(roles) <= 16 and
                        all(predicate_proven(item, depth + 1, seen | {id(expr)})
                            for _, item in roles))

            def parse(statement: Any, depth: int, ancestors: frozenset[int], previous,
                      temps: dict[str, dict]):
                nonlocal mux_count
                statement = unwrap_statement(statement)
                if not isinstance(statement, dict) or depth >= depth_limit or id(statement) in ancestors:
                    return None
                chain = ancestors | {id(statement)}
                kind = str(statement.get("kind", ""))
                if kind in {"Block", "List", "StatementList"}:
                    sequence = statement_children(statement)
                    if sequence is None:
                        return None
                    # Fold in AST statement order. Unassigned conditional paths
                    # inherit the value scheduled by preceding statements, not
                    # always Q. This is the priority of nonblocking writes.
                    value = previous
                    for item in sequence:
                        value = parse(item, depth + 1, chain, value, temps)
                        if value is None:
                            return None
                    return value
                if kind in {"Variable", "VariableSymbol"}:
                    return previous if str(statement.get("addr", "")) in local_addrs else None
                if kind in ASSIGN_KINDS:
                    lhs = statement.get("left", statement.get("lhs"))
                    rhs = statement.get("right", statement.get("rhs"))
                    if not isinstance(rhs, dict):
                        return None
                    nba = (statement.get("isNonBlocking") is True
                           or kind == "NonblockingAssignment")
                    temporary = local_ref(lhs)
                    if temporary is not None:
                        # Only explicit blocking writes to process-local, whole
                        # temporaries may affect reads of later statements.
                        if nba or statement.get("isNonBlocking") is not False:
                            return None
                        try:
                            temps[temporary] = substitute(rhs, temps)
                        except ValueError:
                            return None
                        return previous
                    if sequence_mode and not nba:
                        return None
                    target = symbols.direct(lhs)
                    if target is None:
                        return None
                    try:
                        resolved_rhs = substitute(rhs, temps)
                    except ValueError:
                        return None
                    assignments.append((target, resolved_rhs))
                    return ("write", target, resolved_rhs)
                if kind not in {"Conditional", "ConditionalStatement", "IfStatement"}:
                    return None
                mux_count += 1
                if mux_count > mux_limit:
                    return None
                condition = next((statement.get(k) for k in ("condition", "predicate", "conditions")
                                  if statement.get(k) is not None), None)
                if isinstance(condition, list):
                    if len(condition) != 1 or not isinstance(condition[0], dict):
                        return None
                    condition = condition[0].get("expr")
                # A procedural predicate can itself be a compiler-backed
                # boolean expression (AND, comparison, NOT, etc.), not just a
                # declared signal. Its value must feed the S pin through a
                # *separate* expression graph, never by shorting its sources.
                # The entire predicate is validated before emitting anything.
                condition = unwrap_parentheses(condition)
                if (not isinstance(condition, dict)
                        or condition.get("type") not in ("bit", "logic", "reg", "bit[0:0]", "logic[0:0]")):
                    return None
                selector = symbols.direct(condition)
                if selector is None:
                    if not predicate_proven(condition):
                        return None
                    selector = ("ast_predicate", condition)
                branches = []
                environments = []
                for aliases in (("ifFalse", "else"), ("ifTrue", "then")):
                    present = [statement[k] for k in aliases if statement.get(k) is not None]
                    if len(present) > 1:
                        return None
                    child = present[0] if present else None
                    branch_temps = temps.copy()
                    branch = (parse(child, depth + 1, chain, previous, branch_temps)
                              if child is not None else previous)
                    if branch is None:
                        return None
                    branches.append(branch)
                    environments.append(branch_temps)
                # A temporary modified on only one branch has an unresolved
                # subsequent value. Never silently select an arbitrary path.
                if environments[0] != environments[1]:
                    return None
                temps.clear()
                temps.update(environments[0])
                if branches[0] == ("hold",) and branches[1] == ("hold",):
                    return None
                return ("mux", selector, branches[0], branches[1], extract_location(statement)[1])

            tree = (parse(node, 0, frozenset(), ("hold",), {})
                    if not local_ambiguous else None)
            if tree is None or not assignments:
                return False
            # A final constant has no modeled D-input constant source. Keep
            # it unresolved instead of silently dropping a physical driver.
            if (tree[0] == "write" and
                    (is_literal_rhs(tree[2]) or compiler_constant_ref(tree[2]) is not None)):
                return False
            targets = {target for target, _ in assignments}
            if len(targets) != 1:
                return False
            target = next(iter(targets))
            # Global scope count includes other processes, procedural blocks,
            # and partial writes. A second write makes this D tree ambiguous.
            if ((expected_target is not None and target != expected_target)
                    or write_counts.get(target) != len(assignments) + reset_writes):
                return False

            def expression_count(raw: Any, depth: int = 0) -> int | None:
                raw = unwrap_parentheses(raw)
                if (symbols.direct(raw) is not None or is_literal_rhs(raw)
                        or compiler_constant_ref(raw) is not None):
                    return 0
                if (not isinstance(raw, dict) or raw.get("kind") not in nested_kinds
                        or depth >= 16):
                    return None
                total = 1
                if raw.get("kind") == "Call" and function_info(raw) is None:
                    return None
                if raw.get("kind") in {"RangeSelect", "ElementSelect"} and static_select(raw) is None:
                    return None
                for _, operand in expression_roles(raw):
                    count = expression_count(operand, depth + 1)
                    if count is None:
                        return None
                    total += count
                return total

            required = mux_count
            for _, rhs in assignments:
                count = expression_count(rhs)
                if count is None:
                    return False
                required += count
            # Preflight every operator needed by compound control expressions,
            # including their nested sources, before adding any graph nodes.
            def selector_count(tree: tuple) -> int | None:
                if tree[0] != "mux":
                    return 0
                selector = tree[1]
                own = (expression_count(selector[1]) if isinstance(selector, tuple)
                       and selector[0] == "ast_predicate" else 0)
                left = selector_count(tree[2])
                right = selector_count(tree[3])
                if own is None or left is None or right is None:
                    return None
                return own + left + right
            predicates = selector_count(tree)
            if predicates is None or len(operators) + required + predicates > 256:
                return False

            def attach(value, mux_id: str, pin: str, record: dict) -> None:
                """Attach a proven value to one mux terminal without shorting nets."""
                if value[0] == "hold":
                    edges.append({"source": target, "target": mux_id, "type": "data",
                                  "net": target, "pin": pin, "mapping": "sequential_hold"})
                    record["operandDetails"][pin] = "Q (hold)"
                elif value[0] == "operator":
                    edges.append({"source": value[1], "target": mux_id, "type": "data",
                                  "net": "", "pin": pin, "mapping": "expression"})
                elif value[0] == "direct":
                    edges.append({"source": value[1], "target": mux_id, "type": "data",
                                  "net": value[1], "pin": pin, "mapping": "direct"})
                else:
                    record["literalOperands"][pin] = value[1]

            def emit(part):
                if part[0] == "hold":
                    return ("hold",)
                if part[0] == "write":
                    rhs = unwrap_parentheses(part[2])
                    direct = symbols.direct(rhs)
                    if direct is not None:
                        return ("direct", direct)
                    constant_ref = compiler_constant_ref(rhs)
                    if constant_ref is not None:
                        return ("literal", constant_ref)
                    if is_literal_rhs(rhs):
                        candidate = rhs
                        for _ in range(16):
                            if not isinstance(candidate, dict) or candidate.get("kind") not in {
                                    "Conversion", "ImplicitConversion", "AssignmentConversion", "ParenthesizedExpression"}:
                                break
                            candidate = symbols._operand(candidate)
                        value = candidate.get("value") if isinstance(candidate, dict) else None
                        return ("literal", str(value)[:80])
                    upstream = add_expression(rhs)
                    assert upstream is not None  # preflight guarantees bound
                    return ("operator", upstream)
                # Emit children first so the lower-priority else-if output
                # feeds A of the outer MUX, instead of being shorted to D.
                false_value = emit(part[2])
                true_value = emit(part[3])
                mux_id = "op:" + str(len(operators))
                record = {"name": "MUX", "key": mux_id, "kind": "ConditionalOp",
                          "shape": "mux", "line": part[4],
                          "pins": ["A", "B", "S", "Y"],
                          "origin": "procedural_if_ast", "operandDetails": {},
                          "literalOperands": {}}
                operators.append(record)
                selector = part[1]
                if isinstance(selector, tuple) and selector[0] == "ast_predicate":
                    selector_id = add_expression(selector[1])
                    assert selector_id is not None  # preflight complete
                    edges.append({"source": selector_id, "target": mux_id, "type": "data",
                                  "net": "", "pin": "S", "mapping": "expression"})
                else:
                    selector_id = selector
                    edges.append({"source": selector_id, "target": mux_id, "type": "data",
                                  "net": selector_id, "pin": "S", "mapping": "direct"})
                attach(false_value, mux_id, "A", record)
                attach(true_value, mux_id, "B", record)
                # Inspector-only control relationship; never a second D wire.
                edges.append({"source": selector_id, "target": target, "type": "control",
                              "net": "", "mapping": "partial", "rendered": False})
                return ("operator", mux_id)

            result = emit(tree)
            if result[0] not in {"operator", "direct"}:
                return False  # preflight above prevents an unsupported terminal
            edges.append({"source": result[1], "target": target, "type": "sequential",
                          "net": result[1] if result[0] == "direct" else target,
                          "mapping": "procedural_last_nba" if sequence_mode else "procedural_mux"})
            registered.add(target)
            return True

        def lower_async_reset_ff(statement: Any, timing: dict) -> bool:
            """Project an AST-proven async reset + synchronous D logic.

            The reset write belongs to RST, *not* the combinational D cone.
            Multiple independent registered destinations are projected one at a
            time, without collapsing their assignments into multiple D drivers.
            Require a matching event polarity, exact symbol identity, literal
            reset writes and explicit nonblocking writes on the clock branch.
            Fail closed for unknown language constructs.
            """
            if timing.get("kind") != "EventList":
                return False
            events = timing.get("events")
            if not isinstance(events, (list, tuple)) or len(events) != 2:
                return False
            event_polarity = {}
            for event in events:
                if not isinstance(event, dict) or event.get("kind") != "SignalEvent":
                    return False
                signal = symbols.direct(event.get("expr"))
                if signal is None or signal in event_polarity or event.get("edge") not in {"PosEdge", "NegEdge"}:
                    return False
                event_polarity[signal] = event["edge"]

            def children_of(node):
                node = unwrap_statement(node)
                if not isinstance(node, dict):
                    return None
                if node.get("kind") in {"Block", "List", "StatementList"}:
                    return statement_children(node)
                return [node]

            outer = unwrap_statement(statement)
            if not isinstance(outer, dict) or outer.get("kind") not in {
                    "Conditional", "ConditionalStatement", "IfStatement"}:
                return False
            condition = next((outer.get(k) for k in ("condition", "predicate", "conditions")
                              if outer.get(k) is not None), None)
            if isinstance(condition, list):
                if len(condition) != 1 or not isinstance(condition[0], dict):
                    return False
                condition = condition[0].get("expr")
            if not isinstance(condition, dict):
                return False
            candidate = unwrap_parentheses(condition)
            inverted = False
            if isinstance(candidate, dict) and candidate.get("kind") in {"UnaryOp", "UnaryExpression"}:
                if candidate.get("op", candidate.get("operator")) not in {"LogicalNot", "!"}:
                    return False
                inverted = True
                candidate = next((candidate.get(k) for k in ("operand", "expression", "expr")
                                  if candidate.get(k) is not None), None)
            reset_signal = symbols.direct(candidate)
            if (reset_signal not in event_polarity or
                    event_polarity[reset_signal] != ("NegEdge" if inverted else "PosEdge")):
                return False
            true = [outer.get(k) for k in ("ifTrue", "then") if outer.get(k) is not None]
            false = [outer.get(k) for k in ("ifFalse", "else") if outer.get(k) is not None]
            if len(true) != 1 or len(false) != 1:
                return False
            reset_statements = children_of(true[0])
            if reset_statements is None:
                return False
            # A reset value can be unsupported for one destination (for
            # example a concatenation of constants), without invalidating
            # independent registers updated in the same always_ff. Validate
            # *all* reset writes as whole-target NBAs, but qualify their reset
            # expressions separately. Never treat an unproven reset as proven.
            reset_written: set[str] = set()
            reset_targets: set[str] = set()
            for item in reset_statements:
                item = unwrap_statement(item)
                if not isinstance(item, dict) or item.get("kind") not in ASSIGN_KINDS:
                    return False
                lhs = item.get("left", item.get("lhs"))
                rhs = item.get("right", item.get("rhs"))
                target = symbols.direct(lhs)
                if (target is None or target in reset_written
                        or not (item.get("isNonBlocking") is True or item.get("kind") == "NonblockingAssignment")):
                    return False
                reset_written.add(target)
                if is_literal_rhs(rhs):
                    reset_targets.add(target)
            if not reset_targets:
                return False

            # Each register has an independent next-state function even when
            # its siblings are updated in the same always_ff. An unsupported
            # expression for one destination (e.g. a function call producing a
            # Gray code) must not suppress a proven D MUX for another register.
            # All writes to any one target are still checked atomically by
            # lower_guarded_ff, including the reset assignment and other
            # process writers. Never commit half of a target's D graph.
            lowered = False
            for target in sorted(reset_targets):
                registered.add(target)
                if target in multi_process_writes:
                    continue
                projection = project_destination(false[0], target, writes=symbols.writes,
                                                 direct=symbols.direct)
                if not projection.supported or projection.statement is None:
                    continue
                clock_tree = projection.statement
                original_edges = len(edges)
                original_ops = len(operators)
                if lower_guarded_ff(clock_tree, reset_writes=1, expected_target=target):
                    lowered = True
                else:
                    del edges[original_edges:]
                    del operators[original_ops:]
            if lowered:
                # Other reset destinations remain storage, even when their
                # reset expression or clock-side D cannot be represented.
                registered.update(reset_written)
            # On partial success, unsupported registers remain explicit D ?
            # (registered but without a proven D conductor). Source occurrences
            # still come from the independent compiler AST index.
            return lowered

        def walk(node: Any, sequential: bool = False, controls: tuple[str, ...] = (),
                 guarded: bool = False, single_event_ff: bool = False) -> None:
            if isinstance(node, list):
                for item in node:
                    walk(item, sequential, controls, guarded, single_event_ff)
                return
            if not isinstance(node, dict):
                return
            kind = str(node.get("kind", ""))
            if is_instance(node):
                return
            process = sequential or (kind == "ProceduralBlock" and str(
                node.get("procedureKind", node.get("procedure", ""))).lower() in ("alwaysff", "always_ff"))
            if kind == "ProceduralBlock":
                body = node.get("body")
                timing = body.get("timing") if isinstance(body, dict) and body.get("kind") == "Timed" else None
                single_event_ff = (str(node.get("procedureKind", node.get("procedure", ""))).lower()
                                   in ("alwaysff", "always_ff")
                                   and isinstance(timing, dict)
                                   and timing.get("kind") == "SignalEvent"
                                   and timing.get("edge") in ("PosEdge", "NegEdge"))
                statement = body.get("stmt") if isinstance(body, dict) else None
                if single_event_ff and isinstance(statement, dict):
                    # Analyze the *whole* process in one pass before emitting
                    # destination-specific next-state cones. Only different
                    # whole-register nonblocking writes can be discarded:
                    # their RHS reads old state, so they cannot alter this D.
                    destinations = {dst for item in objects(statement)
                                    if item.get("kind") in ASSIGN_KINDS
                                    for dst in symbols.writes(item.get("left", item.get("lhs")))}
                    if len(destinations) > 1:
                        registered.update(destinations)
                        for target in sorted(destinations - multi_process_writes):
                            projection = project_destination(
                                statement, target, writes=symbols.writes,
                                direct=symbols.direct)
                            if not projection.supported or projection.statement is None:
                                continue
                            before_edges, before_ops = len(edges), len(operators)
                            if not lower_guarded_ff(projection.statement, expected_target=target):
                                del edges[before_edges:]
                                del operators[before_ops:]
                        return  # Never fall back to independent physical D wires.
                if (isinstance(statement, dict) and isinstance(timing, dict)
                        and not single_event_ff and lower_async_reset_ff(statement, timing)):
                    return
                if isinstance(statement, dict) and statement.get("kind") in {"Block", "List", "StatementList"}:
                    items = statement_children(statement)
                    if items is not None and len(items) > 1:
                        # A sequence is one atomic next-state definition. If it
                        # cannot be proven, never lower an individual nested if
                        # or draw another write as an unconditional D driver.
                        if single_event_ff and lower_guarded_ff(statement):
                            return
                        guarded = True
            # Context-sensitive traversal: predicates affect every assignment
            # reachable inside the elaborated branch, including nested blocks.
            if kind in {"Conditional", "ConditionalStatement", "IfStatement"}:
                if single_event_ff and not guarded and lower_guarded_ff(node):
                    return
                predicates = symbols.refs(node.get("conditions", node.get("condition", node.get("predicate"))))
                active = tuple(dict.fromkeys((*controls, *predicates)))
                for branch in ("ifTrue", "ifFalse", "then", "else"):
                    if branch in node:
                        walk(node[branch], process, active, True, single_event_ff)
                return
            if kind in {"Case", "CaseStatement", "CaseStmt"}:
                selected = symbols.refs(node.get("expr", node.get("expression", node.get("selector"))))
                case_selectors.update(selected)
                destinations = tuple(dict.fromkeys(dst for branch in objects(node)
                                     if branch.get("kind") in ASSIGN_KINDS
                                     for dst in symbols.writes(branch.get("left", branch.get("lhs")))))
                # A procedural case is a control-flow statement, not an
                # electrical operator. A standalone CASE glyph fed by a
                # selector has no defined output value or terminal contract.
                # Preserve case evidence in BehavioralIR / LoweredIR; do not
                # synthesize a fake electrical block or its wires here.
                active = tuple(dict.fromkeys((*controls, *selected)))
                for branch in ("items", "defaultCase", "branches", "default"):
                    if branch in node:
                        walk(node[branch], process, active, True, single_event_ff)
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
                    operator = unwrap_parentheses(rhs)
                    for dst in destinations:
                        if isinstance(operator, dict) and operator.get("kind") in nested_kinds:
                            op_id = add_expression(operator)
                            if op_id is not None:
                                edges.append({"source": op_id, "target": dst,
                                              "type": "sequential" if process else "data", "net": dst,
                                              "mapping": "partial" if symbols.direct(lhs) is None else "direct",
                                              "rendered": not (process and guarded)})
                                continue
                        # Other expressions preserve AST reads but are not
                        # lowered into fabricated operator terminals.
                        for src in sources:
                            edges.append({"source": src, "target": dst,
                                          "type": "sequential" if process else "data", "net": src,
                                          "mapping": mapping,
                                          "rendered": not (process and guarded) and not (
                                              isinstance(operator, dict) and operator.get("kind") in nested_kinds)})
                    return
            for value in node.values():
                if isinstance(value, (list, dict)):
                    walk(value, process, controls, guarded, single_event_ff)

        walk(scope.node["body"].get("members", []))
        # A branch of a procedural `case` is not an independent continuous
        # driver. The default assignment before a case and the assignments in
        # its arms together define ONE blocking next-value function. Until a
        # verified case/priority lowering is translated into value geometry,
        # never draw one branch as the complete conductor for that destination.
        # Keep every AST dependency for the inspector and behavioral analysis.
        case_controlled: set[str] = set()
        for process_node in scope.node["body"].get("members", ()):
            if (not isinstance(process_node, dict) or
                    process_node.get("kind") != "ProceduralBlock" or
                    str(process_node.get("procedureKind", "")).lower() not in
                    {"alwayscomb", "always_comb", "alwayslatch", "always_latch"}):
                continue
            for case in objects(process_node.get("body")):
                if case.get("kind") not in {"Case", "CaseStatement", "CaseStmt"}:
                    continue
                for assignment in objects(case):
                    if assignment.get("kind") in ASSIGN_KINDS:
                        case_controlled.update(symbols.writes(
                            assignment.get("left", assignment.get("lhs"))))
        for edge in edges:
            if (edge.get("type") == "sequential" and edge.get("target") in multi_process_writes):
                edge["rendered"] = False
            if (edge.get("target") in case_controlled and
                    edge.get("type") in {"data", "sequential"}):
                edge["rendered"] = False
                edge["proceduralStatus"] = "case-controlled value not yet routed"
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
        return edges, registered, operators, counters, registered & case_selectors & enum_state, case_controlled

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
        logical_edges, registers, operators, counters, fsm_candidates, case_controlled = self._assignments(
            scope, set(signals), self.subroutines)
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
        edge_specs: list[tuple[str, str, str, str, str, str, int, str, str]] = []
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
                          **({"function": operator["function"]} if operator.get("function") else {}),
                          **({"repeatCount": operator["repeatCount"]} if "repeatCount" in operator else {}),
                          **({"operandStatus": operator["operandStatus"]} if operator.get("operandStatus") else {}),
                          **({"field": operator["field"]} if operator.get("field") else {}),
                          **({"selection": operator["selection"],
                              "selectionKind": operator["selectionKind"],
                              "selectionMapping": operator["selectionMapping"]}
                             if operator.get("selection") else {}),
                          **({"constantValue": operator["constantValue"],
                              "constantOrigin": operator["constantOrigin"],
                              "constantType": operator["constantType"]}
                             if "constantValue" in operator else {}),
                          **({"origin": operator["origin"]} if operator.get("origin") else {}),
                          "pins": operator.get("pins", [])})

        def add_edge(src: str, dst: str, kind: str, *, net: str = "", port: str = "", pin: str = "",
                     aggregate: int = 1, mapping: str = "direct", driver_net: str = "",
                     rendered: bool = True) -> None:
            edge_specs.append((src, dst, kind, net, port, pin, aggregate, mapping, driver_net, rendered))

        for src, dst, relation in self._port_aliases(scope, set(signals)):
            add_edge(prefix + "sig:" + src, prefix + "sig:" + dst, relation, net=src)
        for edge in logical_edges:
            src = prefix + (edge["source"] if edge["source"].startswith("op:") else "sig:" + edge["source"])
            dst = prefix + (edge["target"] if edge["target"].startswith("op:") else "sig:" + edge["target"])
            # The operator's Y net is not the destination declaration's Q net.
            # Preserve the destination signal as provenance, but use the
            # elaborated expression identity as the separate physical net.
            driver_net = prefix + "expr:" + edge["source"] if edge["source"].startswith("op:") else ""
            add_edge(src, dst, edge["type"], net=edge["net"], driver_net=driver_net,
                     pin=edge.get("pin", ""), mapping=edge.get("mapping", "direct"),
                     rendered=edge.get("rendered", True))

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
        for src, dst, kind, net, port, pin, count, mapping, driver_net, rendered in edge_specs:
            collector.add(src, dst, kind, net=net, port=port, pin=pin, count=count,
                          mapping=mapping, driver_net=driver_net, rendered=rendered)
        edges = collector.all()
        # Each glyph input corresponds to at most one proven conductor. Keep
        # composite operands in the AST and make their uncertainty visible in
        # the graphical inspector instead of joining unrelated nets at A/B/S.
        unresolved_inputs: dict[str, dict[str, str]] = {}
        for edge in edges:
            if (edge.get("routingStatus", "").startswith("unresolved_operand_")
                    and edge["target"] in collector.present):
                unresolved_inputs.setdefault(edge["target"], {})[edge["pin"] or "IN"] = (
                    "composite AST operand; no proven wire")
        for node in nodes:
            if node.get("name") in case_controlled and node.get("type") not in {"instance", "generate"}:
                node["proceduralStatus"] = "case-controlled next-value not yet represented as a conductor"
            if node["id"] in unresolved_inputs:
                node["operandStatus"] = dict(sorted({**node.get("operandStatus", {}),
                                                     **unresolved_inputs[node["id"]]}.items()))
        # An unresolved conditional D mux must not be presented as multiple
        # physical drivers; the AST relationships remain inspectable.
        unresolved_d = {edge["target"] for edge in edges
                        if edge.get("routingStatus") == "unresolved_D_mux"}
        # A failed procedural lowering may have *no* source edge (for
        # example, an uninitialized process-local temporary). Missing wires
        # must not cause the D pin to appear silently valid or connected.
        proven_d = {edge["target"] for edge in edges
                    if edge.get("rendered") and edge.get("targetPin") == "D"}
        for node in nodes:
            if (node["id"] in unresolved_d or
                    (node.get("type") in {"register", "counter", "fsm"}
                     and node["id"] not in proven_d)):
                node["dInputStatus"] = ("unresolved conditional D input" if node["id"] in unresolved_d
                                         else "unresolved procedural D input")
        # Source-truth audit: "unbound" is not the same as "unresolved".
        # A generated stack is fully connected only if EVERY instance has a
        # proven binding for that pin. Never hide a missing lane in a bundle.
        resolver = PortResolver(scope.node["body"].get("members", ()), set(signals))
        states_by_child = {}
        constants_by_child = {}
        for children in groups.values():
            for child in children:
                child_ports = self._signals(child)
                _, states_by_child[child.path] = resolver.resolve(child.node, child_ports)
                constants_by_child[child.path] = resolver.literal_values(child.node, child_ports)
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
                if connection == "constant":
                    # Display a value only when every represented instance
                    # proves the same literal. Never guess generated lanes.
                    values = [constants_by_child[child.path].get(port["name"]) for child in represented]
                    if values and all(v is not None and v == values[0] for v in values):
                        port["constantValue"] = values[0]
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
                  "truncated_scopes": 0, "edge_mapping": {}, "partial_by_type": {},
                  "d_inputs": {"total": 0, "routed": 0, "unresolved": 0}}
        for path, scope in self.scopes.items():
            graph = self.diagram(path, limit=limit)
            source = self._source_path(scope)
            file = self._source_label(source) if source else ""
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
            # D-input coverage is a bounded, graph-level visibility metric,
            # not a synthesis equivalence check. Unresolved regs remain
            # inspectable; no extra edges are inferred to improve this count.
            registers = [n for n in graph["nodes"] if n.get("type") in
                         {"register", "counter", "fsm"}]
            drivers = {e["target"] for e in graph["edges"]
                       if e.get("rendered") and e.get("targetPin") == "D"}
            missing = [n for n in registers if n["id"] not in drivers]
            d_inputs = {"total": len(registers), "routed": len(registers) - len(missing),
                        "unresolved": len(missing),
                        "unresolved_nodes": [{"id": n["id"], "name": n["name"],
                                              "reason": n.get("dInputStatus", "D not routed")}
                                             for n in missing[:128]],
                        "list_truncated": len(missing) > 128}
            row = {"path": path, "module": scope.module, "file": file,
                   "source_status": "available" if source else "unresolved",
                   "nodes": len(graph["nodes"]), "edges": len(graph["edges"]),
                   "edge_mapping": dict(sorted(edge_mapping.items())),
                   "partial_by_type": dict(sorted(partial_by_type.items())),
                   "d_inputs": d_inputs,
                   "truncated": graph["truncated"], **pins}
            scopes.append(row)
            totals["nodes"] += row["nodes"]
            totals["edges"] += row["edges"]
            for key in ("total", "routed", "unresolved"):
                totals["d_inputs"][key] += d_inputs[key]
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

    def _resolve_source_reference(self, raw: str) -> Path | None:
        """Resolve only compiler-supplied locations within authorized source roots.

        No filename/glob search: an ambiguous basename must never silently
        select an unrelated module. Resolution follows root order (run first).
        A symlink escaping every authorized root cannot become an AST source.
        """
        if not raw or "\x00" in raw:
            return None
        location = Path(raw)
        candidates = ((location,) if location.is_absolute() else
                      tuple(root / location for root in self.source_roots))
        for candidate in candidates:
            try:
                resolved = candidate.resolve(strict=True)
                if resolved.is_file() and any(resolved.is_relative_to(root) for root in self.source_roots):
                    return resolved
            except (OSError, RuntimeError, ValueError):
                continue
        return None

    def _source_label(self, resolved: Path) -> str:
        for root in self.source_roots:
            if resolved.is_relative_to(root):
                return resolved.relative_to(root).as_posix()
        raise ValueError('source outside authorized roots')

    def _source_path(self, scope: Scope) -> Path | None:
        return self._resolve_source_reference(scope.source)

    def source(self, path: str) -> dict[str, Any]:
        scope = self._scope(path)
        source = self._source_path(scope)
        if source is None:
            return {"status": "unresolved", "module": scope.module, "file": scope.source,
                    "code": "", "reason": "Compiler source missing or outside authorized source roots"}
        if source.stat().st_size > 2_000_000:
            return {"status": "unresolved", "reason": "source too large (>2 MB)"}
        return {"status": "available", "module": scope.module, "file": self._source_label(source),
                "line": scope.line, "code": source.read_text(encoding="utf-8", errors="replace")}

    def source_symbols(self, path: str, line: int) -> dict[str, Any]:
        """Map AST declarations, writes and reads to this elaborated scope."""
        from .source_navigation import source_line_candidates
        return source_line_candidates(self, path, line)

    def source_coverage(self, path: str) -> dict[str, Any]:
        """Audit signal visibility versus compiler source provenance.

        Absence from the diagram is NOT proof a signal is absent from RTL;
        likewise no source location does not mean a missing RTL declaration.
        """
        scope = self._scope(path)
        signals = self._signals(scope)
        graph = self.diagram(path, limit=1500)
        ids = {node['id'] for node in graph['nodes']}
        source = self._source_path(scope)
        rows = []
        counts = {'visible_mapped': 0, 'visible_unmapped': 0, 'not_in_graph': 0}
        for name, item in sorted(signals.items()):
            identifier = path + '::sig:' + name
            visible = identifier in ids
            resolved = self._resolve_source_reference(item['file']) if item['file'] else None
            mapped = bool(resolved and item['line'] > 0)
            status = 'not_in_graph' if not visible else 'visible_mapped' if mapped else 'visible_unmapped'
            counts[status] += 1
            rows.append({'id': identifier, 'name': name, 'status': status,
                         'line': item['line'] if mapped else 0,
                         'file': self._source_label(resolved) if mapped else '',
                         'in_scope_source': bool(source is not None and resolved == source),
                         'type': item['kind']})
        return {'status': 'available', 'scope': path, 'revision': self.revision,
                'graph_truncated': bool(graph.get('truncated')),
                'counts': counts, 'total': len(rows), 'signals': rows,
                'note': 'AST signal declarations only. No text-name matching, bit-exact claim, or proof of connectivity.'}

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
        status, payload = _fsrtl_evidence_read_report(self.run)
        if status != "available":
            return {"status": status, "diagnostics": [], "reason": payload}
        source = self._source_path(scope)
        if source is None:
            return {"status": "unresolved", "diagnostics": [], "reason": "source mapping unavailable"}
        items = []
        for item in payload.get("diagnostics", []):
            if not isinstance(item, dict):
                continue
            raw = str(item.get("file") or "")
            if not raw:
                continue
            relative = Path(raw)
            if self._resolve_source_reference(raw) == source:
                items.append(item)
        return {"status": "available", "diagnostics": items, "total": len(items),
                "scope": "file-level only; instance attribution not established",
                "file": self._source_label(source)}
