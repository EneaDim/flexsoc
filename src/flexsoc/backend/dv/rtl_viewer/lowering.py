"""Conservative symbolic lowering of ordered RTL assignments.

Only supported constructs receive an expression; no inferred gates, widths or
silently approximated semantics. NBA updates are evaluated against pre-clock
values, while blocking updates change the immediate procedural environment.
"""
from __future__ import annotations

from typing import Any, Mapping
import re

from .connectivity import SymbolTable, _address


class ProcessLowerer:
    """Build a symbolic SSA-like result for one elaborated procedural block."""

    def __init__(self, members: list[Any], declared: set[str],
                 constants: Mapping[str, dict[str, Any]] | None = None):
        self.symbols = SymbolTable(members, declared)
        self.diagnostics: list[str] = []
        # Elaborated parameters are values, not electrical nets. Resolve them
        # by Slang symbol identity, never by their textual names.
        self.parameters = dict(constants or {})
        self.parameters.update({
            _address(member.get("addr")): {"op": "literal", "value": str(member["value"]),
                                           "type": str(member.get("type", ""))}
            for member in members
            if isinstance(member, Mapping) and member.get("kind") in {"Parameter", "Specparam"}
            and _address(member.get("addr")) and member.get("value") is not None
        })

    @staticmethod
    def _ref(name: str) -> dict[str, Any]:
        return {"op": "ref", "name": name}

    @staticmethod
    def _select(condition: dict, yes: dict, no: dict) -> dict:
        return yes if yes == no else {"op": "select", "condition": condition, "true": yes, "false": no}

    @staticmethod
    def _typed(node: Mapping[str, Any], op: str, **fields: Any) -> dict[str, Any]:
        """Keep Slang's elaborated type verbatim; do not guess bit widths."""
        result: dict[str, Any] = {"op": op, **fields}
        if node.get("type"):
            result["type"] = str(node["type"])
        return result

    def _expr(self, node: Any, env: dict[str, dict]) -> dict:
        if not isinstance(node, Mapping):
            raise ValueError("missing expression")
        kind = str(node.get("kind", ""))
        if kind in {"NamedValue", "SymbolReference", "HierarchicalValue"}:
            name = self.symbols.direct(node)
            if name is None:
                parameter = self.parameters.get(_address(node.get("symbol")))
                if parameter is None:
                    raise ValueError("unresolved symbol identity")
                return parameter
            return env.get(name, self._ref(name))
        if kind in {"IntegerLiteral", "UnbasedUnsizedIntegerLiteral"}:
            return self._typed(node, "literal", value=str(node.get("value", "")))
        if kind == "ParenthesizedExpression":
            return self._expr(node.get("expression", node.get("operand")), env)
        if kind in {"Conversion", "ImplicitConversion", "AssignmentConversion"}:
            if not node.get("type"):
                raise ValueError("conversion without elaborated destination type")
            return self._typed(node, "conversion", operand=self._expr(node.get("operand"), env))
        if kind in {"ElementSelect", "BitSelect"}:
            return self._typed(node, "element_select",
                               base=self._expr(node.get("value", node.get("base")), env),
                               index=self._expr(node.get("selector", node.get("index")), env))
        if kind in {"RangeSelect", "PartSelect"}:
            return self._typed(node, "range_select",
                               selection_kind=str(node.get("selectionKind", "Simple")),
                               base=self._expr(node.get("value", node.get("base")), env),
                               left=self._expr(node.get("left"), env),
                               right=self._expr(node.get("right"), env))
        if kind == "MemberAccess":
            member = node.get("member")
            if not isinstance(member, str) or not member:
                raise ValueError("unresolved member identity")
            return self._typed(node, "member_access", member=member,
                               base=self._expr(node.get("value", node.get("base")), env))
        if kind == "Concatenation":
            parts = node.get("operands", node.get("elements"))
            if not isinstance(parts, list) or not parts:
                raise ValueError("invalid concatenation operands")
            return self._typed(node, "concatenation", parts=[self._expr(part, env) for part in parts])
        if kind in {"BinaryOp", "BinaryExpression", "UnaryOp", "UnaryExpression"}:
            keys = ("left", "right") if "Binary" in kind else ("operand",)
            return self._typed(node, kind,
                               operator=str(node.get("op", node.get("operator", ""))),
                               args=[self._expr(node.get(key), env) for key in keys])
        if kind in {"ConditionalOp", "ConditionalExpression"}:
            return self._select(self._expr(node.get("condition"), env),
                                self._expr(node.get("left", node.get("trueExpr")), env),
                                self._expr(node.get("right", node.get("falseExpr")), env))
        raise ValueError(f"unsupported expression {kind or '<unknown>'}")

    def _lvalue(self, node: Any, env: dict[str, dict]) -> tuple[str, list[dict]]:
        """Resolve an lvalue by Slang identity and preserve its ordered selectors.

        This is a symbolic write path, not a claim of bit-accurate synthesis.
        """
        if not isinstance(node, Mapping):
            raise ValueError("invalid assignment destination")
        kind = str(node.get("kind", ""))
        if kind in {"NamedValue", "SymbolReference", "HierarchicalValue"}:
            name = self.symbols.direct(node)
            if name is None:
                raise ValueError("unresolved assignment destination identity")
            return name, []
        if kind in {"ElementSelect", "BitSelect", "RangeSelect", "PartSelect", "MemberAccess"}:
            name, steps = self._lvalue(node.get("value", node.get("base")), env)
            if kind in {"ElementSelect", "BitSelect"}:
                selector = {"kind": "element", "index": self._expr(node.get("selector", node.get("index")), env)}
            elif kind in {"RangeSelect", "PartSelect"}:
                selector = {"kind": "range", "selection_kind": str(node.get("selectionKind", "Simple")),
                            "left": self._expr(node.get("left"), env),
                            "right": self._expr(node.get("right"), env)}
            else:
                member = node.get("member")
                if not isinstance(member, str) or not member:
                    raise ValueError("unresolved assignment member")
                selector = {"kind": "member", "member": member}
            return name, [*steps, selector]
        raise ValueError(f"unsupported assignment destination {kind or '<unknown>'}")

    @staticmethod
    def _width(node: Mapping[str, Any]) -> int:
        """Accept only concrete, single packed integral dimensions from Slang."""
        typ = node.get("type")
        if not isinstance(typ, str):
            raise ValueError("concatenated destination without elaborated type")
        match = re.fullmatch(r"(?:bit|logic|reg)(?:\[(\d+):(\d+)\])?", typ.replace(" ", ""))
        if match is None:
            raise ValueError(f"unhandled concatenated destination type: {typ}")
        return abs(int(match[1]) - int(match[2])) + 1 if match[1] is not None else 1

    def _assign(self, lhs: Any, rhs: dict, env: dict[str, dict], scheduled: dict[str, dict], nba: bool) -> None:
        """One statement may atomically update several destinations."""
        if isinstance(lhs, Mapping) and lhs.get("kind") == "Concatenation":
            parts = lhs.get("operands", lhs.get("elements"))
            if not isinstance(parts, list) or not parts:
                raise ValueError("empty concatenated destination")
            widths = [self._width(part) for part in parts]
            if sum(widths) != self._width(lhs):
                raise ValueError("concatenated destination widths do not match")
            low = sum(widths)
            for part, width in zip(parts, widths):
                low -= width
                part_rhs = {"op": "extract", "base": rhs, "lsb": low, "width": width}
                self._assign(part, part_rhs, env, scheduled, nba)
            return
        target, steps = self._lvalue(lhs, env)
        output = scheduled if nba else env
        base = output.get(target, self._ref(target))
        output[target] = self._write(base, steps, rhs)

    @staticmethod
    def _write(base: dict, steps: list[dict], value: dict) -> dict:
        if not steps:
            return value
        return {"op": "update", "base": base, "path": steps, "value": value}

    def _predicate(self, node: Mapping[str, Any], env: dict[str, dict]) -> dict:
        conditions = node.get("conditions", node.get("condition"))
        if isinstance(conditions, list) and len(conditions) == 1:
            entry = conditions[0]
            if isinstance(entry, Mapping):
                return self._expr(entry.get("expr", entry), env)
        if isinstance(conditions, Mapping):
            return self._expr(conditions, env)
        raise ValueError("unsupported conditional predicate")

    def _walk(self, node: Any, env: dict[str, dict], scheduled: dict[str, dict]) -> None:
        if isinstance(node, list):
            for child in node:
                self._walk(child, env, scheduled)
            return
        if not isinstance(node, Mapping):
            return
        kind = str(node.get("kind", ""))
        if kind in {"Block", "List", "StatementList"}:
            for key in ("body", "statements", "members"):
                if key in node:
                    self._walk(node[key], env, scheduled)
            return
        if kind in {"Timed", "ExpressionStatement"}:
            for key in ("stmt", "statement", "body", "expression", "expr"):
                if key in node:
                    self._walk(node[key], env, scheduled)
                    return
        if kind in {"Conditional", "ConditionalStatement", "IfStatement"}:
            predicate = self._predicate(node, env)
            left_env, right_env = env.copy(), env.copy()
            left_nba, right_nba = scheduled.copy(), scheduled.copy()
            self._walk(node.get("ifTrue", node.get("then")), left_env, left_nba)
            self._walk(node.get("ifFalse", node.get("else")), right_env, right_nba)
            for target in set(left_env) | set(right_env):
                previous = env.get(target, self._ref(target))
                env[target] = self._select(predicate, left_env.get(target, previous),
                                           right_env.get(target, previous))
            for target in set(left_nba) | set(right_nba):
                previous = scheduled.get(target, self._ref(target))
                scheduled[target] = self._select(predicate, left_nba.get(target, previous),
                                                 right_nba.get(target, previous))
            return
        if kind in {"Assignment", "AssignmentExpression", "NonblockingAssignment"}:
            rhs = self._expr(node.get("right", node.get("rhs")), env)
            # Compute the whole RHS before updating any concatenated destination.
            self._assign(node.get("left", node.get("lhs")), rhs, env, scheduled,
                         bool(node.get("isNonBlocking", False)) or kind == "NonblockingAssignment")
            return
        if kind in {"Empty", "EmptyStatement"}:
            return
        raise ValueError(f"unsupported statement {kind or '<unknown>'}")

    def lower(self, block: Mapping[str, Any], index: int) -> dict[str, Any]:
        self.diagnostics = []
        env: dict[str, dict] = {}
        scheduled: dict[str, dict] = {}
        try:
            self._walk(block.get("body"), env, scheduled)
        except ValueError as exc:
            # Never return incomplete semantics as though they were trustworthy.
            self.diagnostics.append(str(exc))
            env.clear()
            scheduled.clear()
        return {"id": f"process:{index}", "kind": block.get("procedureKind", "Unknown"),
                "status": "supported" if not self.diagnostics else "unsupported",
                "blocking_final": env, "scheduled_nba": scheduled,
                "diagnostics": list(self.diagnostics)}


class LoweredIR:
    """Explicitly bounded, non-synthesized process value model."""

    def __init__(self, design: Any, path: str):
        scope = design._scope(path)
        members = list(scope.node["body"].get("members", ()))
        analyzer = ProcessLowerer(members, set(design._signals(scope)), design.references.constants)
        self.path = path
        self.processes = [analyzer.lower(member, index) for index, member in enumerate(members)
                          if isinstance(member, dict) and member.get("kind") == "ProceduralBlock"]

    def serialize(self) -> dict[str, Any]:
        return {"schema": "flexsoc.rtl_viewer.lowering.v1", "scope": self.path,
                "semantics": "typed symbolic expressions and lvalue write paths; no bit-accurate circuit synthesis",
                "processes": self.processes}
