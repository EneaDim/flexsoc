"""Bounded projection of compiler-backed *lowered* combinational values.

ProcessLowerer owns procedural ordering. This module only converts its supported
symbolic value tree into explicit operator terminals; it never re-walks statements
or reconstructs dependencies from source text.
"""
from __future__ import annotations

from typing import Any, Mapping


class UnrepresentableValue(ValueError):
    """No trustworthy electrical projection is available for this expression."""


def project_value(value: Mapping[str, Any], target: str, signals: set[str],
                  *, start: int, max_nodes: int = 96) -> tuple[list[dict], list[dict]]:
    """Return (operators, edges) atomically; caller commits only on success.

    No implicit feedback/latch, unknown constant, dynamic case pattern, or
    unsupported symbolic operator is converted to an electrical conductor.
    """
    operators: list[dict] = []
    edges: list[dict] = []

    def walk(expr: Any, depth: int = 0) -> tuple[str, str]:
        if not isinstance(expr, Mapping) or depth > 96 or len(operators) >= max_nodes:
            raise UnrepresentableValue("symbolic expression exceeds supported bounds")
        op = expr.get("op")
        if op == "ref":
            name = expr.get("name")
            if not isinstance(name, str) or name not in signals or name == target:
                # A self-reference may be a legitimate latch/feedback, but we
                # cannot call it a combinational conductor without proof.
                raise UnrepresentableValue("unknown or implicit-feedback reference")
            return name, "signal"
        if op == "literal":
            value_text = expr.get("value")
            if not isinstance(value_text, str) or not 0 < len(value_text) <= 128:
                raise UnrepresentableValue("missing literal value")
            kind, shape, name, pins = "IntegerLiteral", "constant", "CONST", ["Y"]
            attrs = {"constantValue": value_text, "constantType": str(expr.get("type", "")),
                     "constantOrigin": "Slang symbolic literal"}
            children: list[tuple[str, Any]] = []
        elif op == "case_match_any":
            if expr.get("semantics") != "SystemVerilog four-state case equality":
                raise UnrepresentableValue("unproven case semantics")
            patterns = expr.get("patterns")
            if not isinstance(patterns, list) or not 1 <= len(patterns) <= 16 or any(
                not isinstance(p, Mapping) or p.get("op") != "literal" or
                not isinstance(p.get("value"), str) for p in patterns
            ):
                raise UnrepresentableValue("nonliteral case comparison")
            kind, shape, name, pins = "CaseMatch", "case", "CASE", ["A", "Y"]
            attrs = {"literalOperands": {"patterns": [p["value"] for p in patterns]},
                     "casePatterns": [p["value"] for p in patterns],
                     "operandDetails": {"A": "case selector"},
                     "caseSemantics": expr["semantics"]}
            children = [("A", expr.get("selector"))]
        elif op == "select":
            kind, shape, name, pins = "ConditionalOp", "mux", "MUX", ["A", "B", "S", "Y"]
            attrs = {}
            condition = expr.get("condition")
            if isinstance(condition, Mapping) and condition.get("op") == "case_match_any":
                attrs["controlKind"] = "case"
                selector = condition.get("selector")
                if isinstance(selector, Mapping) and selector.get("op") == "ref":
                    attrs["controlSource"] = selector.get("name", "")
                patterns = condition.get("patterns")
                if isinstance(patterns, list):
                    attrs["controlPatterns"] = [str(p.get("value")) for p in patterns
                                                if isinstance(p, Mapping) and isinstance(p.get("value"), str)]
            children = [("S", expr.get("condition")), ("A", expr.get("true")),
                        ("B", expr.get("false"))]
        elif op == "call":
            name = expr.get("name")
            address = expr.get("subroutineAddr")
            args = expr.get("args")
            formals = expr.get("arguments")
            if (not isinstance(name, str) or not name or
                    not isinstance(address, str) or not address.isdecimal() or
                    not isinstance(args, list) or len(args) > 16 or
                    not isinstance(formals, list) or len(formals) != len(args) or
                    expr.get("returnType") in (None, "", "void") or
                    not isinstance(expr.get("type"), str) or not expr["type"]):
                raise UnrepresentableValue("unproven compiler function value")
            kind, shape, pins = "Call", "function", [f"I{i}" for i in range(len(args))] + ["Y"]
            attrs = {"function": {"name": name,
                                  "subroutineAddr": address,
                                  "returnType": expr["returnType"],
                                  "arguments": formals,
                                  "callFile": expr.get("callFile", ""),
                                  "callLine": expr.get("callLine", 0),
                                  "callColumn": expr.get("callColumn", 0),
                                  "definitionFile": expr.get("definitionFile", ""),
                                  "definitionLine": expr.get("definitionLine", 0),
                                  "semantics": "opaque AST function call"}}
            children = [(f"I{i}", arg) for i, arg in enumerate(args)]
        elif op == "member_access":
            member = expr.get("member")
            if not isinstance(member, str) or not member.strip():
                raise UnrepresentableValue("unresolved struct member identity")
            kind, shape, name, pins = "MemberAccess", "field", "FieldSelect", ["A", "Y"]
            attrs = {"field": member.partition(" ")[2] or member,
                     "fieldSymbol": member,
                     "operandDetails": {"A": "compiler-backed struct value"},
                     "selectionMapping": "AST member projection; bit offsets not inferred"}
            children = [("A", expr.get("base"))]
        elif op == "element_select":
            kind, shape, name, pins = "ElementSelect", "slice", "IndexedSelect", ["A", "S", "Y"]
            attrs = {"selection": "[index]", "selectionKind": "ElementSelect",
                     "selectionMapping": "AST indexed value read; bit offsets not inferred"}
            children = [("A", expr.get("base")), ("S", expr.get("index"))]
        elif op == "range_select":
            selection = expr.get("selection_kind")
            if selection not in ("Simple", "IndexedUp", "IndexedDown"):
                raise UnrepresentableValue("unsupported range selection")
            kind, shape, name, pins = "RangeSelect", "slice", "PartSelect", ["A", "S0", "S1", "Y"]
            attrs = {"selection": "[range]", "selectionKind": selection,
                     "selectionMapping": "AST packed selection; bit offsets not inferred"}
            children = [("A", expr.get("base")), ("S0", expr.get("left")),
                        ("S1", expr.get("right"))]
        elif op == "update":
            # ProcessLowerer needs this expression to preserve procedural write
            # order and distinguish partial fields from whole-bus drivers.
            # It is NOT a cell in the elaborated microarchitecture. Until a
            # width/field-mapping lowering proves its bitwise implementation,
            # do not draw an opaque UPDATE operator or an electrical edge.
            raise UnrepresentableValue("partial aggregate value has no proven circuit projection")
        elif op == "concatenation":
            parts = expr.get("parts")
            if not isinstance(parts, list) or not 1 <= len(parts) <= 32:
                raise UnrepresentableValue("unbounded or malformed concatenation")
            # Concatenation is an AST value operation, not a guessed bus splice.
            # The compiler supplies operand order; do not infer bit offsets.
            kind, shape, name = "Concatenation", "logic", "CONCAT"
            pins = [f"I{i}" for i in range(len(parts))] + ["Y"]
            attrs = {"operandDetails": {f"I{i}": "Slang concatenation operand {i}"
                                        for i in range(len(parts))}}
            children = [(f"I{i}", child) for i, child in enumerate(parts)]
        elif op in {"UnaryOp", "BinaryOp"}:
            operator = expr.get("operator")
            unary = {"LogicalNot", "BitwiseNot", "UnaryPlus", "UnaryMinus"}
            binary = {"LogicalAnd", "LogicalOr", "Equality", "Inequality",
                      "CaseEquality", "CaseInequality", "LessThan", "LessThanEqual",
                      "GreaterThan", "GreaterThanEqual", "Add", "Subtract",
                      "Multiply", "BitwiseAnd", "BitwiseOr", "BitwiseXor",
                      "LogicalShiftRight", "LogicalShiftLeft"}
            if not isinstance(operator, str) or operator not in (unary if op == "UnaryOp" else binary):
                raise UnrepresentableValue("unrecognized elaborated operator")
            args = expr.get("args")
            expected = 1 if op == "UnaryOp" else 2
            if not isinstance(args, list) or len(args) != expected:
                raise UnrepresentableValue("malformed symbolic operator arguments")
            kind, shape, name = op, ("arith" if operator in {"Add", "Subtract", "Multiply"} else "logic"), operator
            pins = ["A", "Y"] if expected == 1 else ["A", "B", "Y"]
            attrs = {"operandDetails": {"A": "Slang " + operator}}
            children = list(zip(("A", "B")[:expected], args))
        elif op == "conversion":
            if not isinstance(expr.get("type"), str) or not expr["type"]:
                raise UnrepresentableValue("untyped conversion")
            kind, shape, name, pins = "Conversion", "logic", "CAST", ["A", "Y"]
            attrs = {"constantType": expr["type"]}
            children = [("A", expr.get("operand"))]
        else:
            raise UnrepresentableValue(f"unsupported symbolic value: {op}")

        identifier = f"op:{start + len(operators)}"
        # A function call is a real compiler-backed expression occurrence:
        # keep its call-site line for the Source inspector and cross-probe.
        # Other lowered symbols do not gain guessed source coordinates.
        call_line = attrs.get("function", {}).get("callLine", 0)
        record = {"key": identifier, "kind": kind, "shape": shape, "name": name,
                  "line": int(call_line or 0), "pins": pins, "literalOperands": {},
                  "operandDetails": {}, "origin": "ProcessLowerer", **attrs}
        operators.append(record)
        for pin, child in children:
            source, source_type = walk(child, depth + 1)
            edges.append({"source": source, "target": identifier, "type": "data",
                          "net": source if source_type == "signal" else "",
                          "pin": pin, "mapping": "expression" if source_type == "operator" else "direct"})
        return identifier, "operator"

    source, source_type = walk(value)
    edges.append({"source": source, "target": target, "type": "data",
                  "net": target if source_type == "operator" else source,
                  "mapping": "expression" if source_type == "operator" else "direct",
                  "proceduralLowering": "ProcessLowerer"})
    return operators, edges


def prune_superseded_operators(operators: list[dict], edges: list[dict],
                               legacy_keys: set[str]) -> None:
    """Remove *only* obsolete operator cones replaced by ordered process values.

    A legacy operator shared with any other live consumer survives. The AST
    itself is untouched; original assignment evidence stays in BehavioralIR.
    """
    dead_candidates = {edge["source"] for edge in edges
                       if edge.get("proceduralStatus") == "superseded by ordered ProcessLowerer value"
                       and edge.get("source") in legacy_keys}
    if not dead_candidates:
        return
    changed = True
    while changed:
        upstream = {edge["source"] for edge in edges
                    if edge["target"] in dead_candidates and edge["source"] in legacy_keys}
        changed = not upstream.issubset(dead_candidates)
        dead_candidates.update(upstream)
    live = {edge["source"] for edge in edges
            if edge["source"] in dead_candidates and edge.get("rendered")
            and edge["target"] not in dead_candidates}
    changed = True
    while changed:
        upstream = {edge["source"] for edge in edges
                    if edge["target"] in live and edge["source"] in dead_candidates}
        changed = not upstream.issubset(live)
        live.update(upstream)
    dead = dead_candidates - live
    if dead:
        operators[:] = [op for op in operators if op.get("key") not in dead]
        edges[:] = [edge for edge in edges
                    if edge["source"] not in dead and edge["target"] not in dead]
