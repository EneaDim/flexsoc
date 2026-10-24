"""Semantic connectivity for elaborated Slang ASTs.

This module does not parse SystemVerilog source or infer wires from names.
Symbol identities resolve within one elaborated scope. Unsupported expressions
become partial dependencies (never claimed to be bit-exact connections).
"""
from __future__ import annotations

from dataclasses import dataclass
from hashlib import sha256
from typing import Any, Iterable, Mapping


SIGNAL_KINDS = frozenset({"Port", "Variable", "Net", "NetSymbol", "VariableSymbol", "InterfacePort"})
REFERENCES = frozenset({"NamedValue", "SymbolReference", "HierarchicalValue"})
SELECTORS = frozenset({"ElementSelect", "RangeSelect", "MemberAccess", "BitSelect", "PartSelect"})
CONVERSIONS = frozenset({"Conversion", "ImplicitConversion", "AssignmentConversion", "ParenthesizedExpression"})
ASSIGNMENT_EXPRESSIONS = frozenset({"Assignment", "AssignmentExpression", "NonblockingAssignment"})


def _name(node: Mapping[str, Any]) -> str:
    return str(node.get("name") or node.get("instanceName") or "")


def _address(value: Any) -> str:
    if isinstance(value, Mapping):
        value = value.get("addr", "")
    if value is None:
        return ""
    raw = str(value).partition(" ")[0]
    return raw if raw.isdigit() else ""


def _children(value: Any):
    if isinstance(value, Mapping):
        yield value
        for child in value.values():
            if isinstance(child, (Mapping, list, tuple)):
                yield from _children(child)
    elif isinstance(value, (list, tuple)):
        for child in value:
            yield from _children(child)


class SymbolTable:
    """Resolve only declarations belonging to this elaborated module scope.

    A known but unmatched address never falls back to textual spelling.
    Backing declarations take priority over a Port.internalSymbol alias, even
    if Slang emits declarations in a different order.
    """

    def __init__(self, members: Iterable[Any], declared: set[str]):
        self.declared = declared
        self.by_address: dict[str, str] = {}
        self.ports: dict[str, str] = {}
        self.port_addresses: dict[str, str] = {}
        members = tuple(m for m in members if isinstance(m, Mapping))
        for member in members:
            if member.get("kind") not in SIGNAL_KINDS:
                continue
            name = _name(member)
            if name not in declared:
                continue
            address = _address(member.get("addr"))
            if member.get("kind") in {"Port", "InterfacePort"}:
                if address:
                    self.port_addresses[address] = name
                backing = _address(member.get("internalSymbol"))
                if backing:
                    self.ports[backing] = name
            if address:
                self.by_address[address] = name
        for address, port in self.ports.items():
            self.by_address.setdefault(address, port)

    def _symbol(self, expression: Mapping[str, Any]) -> str | None:
        ref = expression.get("symbol")
        if isinstance(ref, Mapping):
            address = _address(ref.get("addr"))
            if address:
                if address in self.by_address:
                    return self.by_address[address]
                if self.by_address:
                    return None
                name = _name(ref)
            else:
                name = _name(ref)
        elif isinstance(ref, str):
            address = _address(ref)
            if address:
                if address in self.by_address:
                    return self.by_address[address]
                if self.by_address:
                    return None
                name = ref.partition(" ")[2] if " " in ref else ref
            else:
                name = ref
        else:
            address = _address(expression.get("addr"))
            if address:
                return self.by_address.get(address)
            name = _name(expression)
        return name if name in self.declared else None

    def reads(self, expression: Any) -> tuple[str, ...]:
        seen: dict[str, None] = {}
        for entry in _children(expression):
            if entry.get("kind") in REFERENCES:
                name = self._symbol(entry)
                if name:
                    seen[name] = None
        return tuple(seen)

    # Original API name retained for the graph model.
    refs = reads

    @staticmethod
    def _operand(expression: Mapping[str, Any]) -> Any:
        return next((expression[key] for key in ("operand", "expression", "value", "base")
                     if isinstance(expression.get(key), Mapping)), None)

    def direct(self, expression: Any) -> str | None:
        while isinstance(expression, Mapping) and expression.get("kind") == "ParenthesizedExpression":
            expression = self._operand(expression)
        if not isinstance(expression, Mapping) or expression.get("kind") not in REFERENCES:
            return None
        return self._symbol(expression)

    def base(self, expression: Any) -> str | None:
        if not isinstance(expression, Mapping) or expression.get("kind") not in SELECTORS:
            return None
        child = self._operand(expression)
        return self.direct(child) or self.base(child)

    def writes(self, lhs: Any) -> tuple[str, ...]:
        """The lvalue's destination, never an array index used to address it."""
        if isinstance(lhs, (list, tuple)):
            return tuple(dict.fromkeys(name for item in lhs for name in self.writes(item)))
        if not isinstance(lhs, Mapping):
            return ()
        kind = lhs.get("kind")
        if kind in REFERENCES:
            name = self._symbol(lhs)
            return (name,) if name else ()
        if kind in SELECTORS | CONVERSIONS:
            return self.writes(self._operand(lhs))
        if kind in {"Concatenation", "StreamingConcatenation", "AssignmentPattern"}:
            parts = next((lhs.get(key) for key in ("operands", "elements", "parts", "expressions")
                          if isinstance(lhs.get(key), (list, tuple))), ())
            return self.writes(parts)
        return ()

    def address_reads(self, lhs: Any) -> tuple[str, ...]:
        """Dynamic array selectors are read dependencies, never write targets."""
        if not isinstance(lhs, Mapping):
            return ()
        if lhs.get("kind") in SELECTORS:
            selected = [lhs.get(k) for k in ("selector", "index", "range", "selection", "left", "right")]
            return tuple(dict.fromkeys((*self.reads(selected), *self.address_reads(self._operand(lhs)))))
        if lhs.get("kind") in {"Concatenation", "StreamingConcatenation"}:
            parts = next((lhs.get(k) for k in ("operands", "elements", "parts", "expressions")
                          if isinstance(lhs.get(k), (list, tuple))), ())
            return tuple(dict.fromkeys(name for part in parts for name in self.address_reads(part)))
        return ()

    def port_actuals(self, expression: Any) -> tuple[tuple[str, str], ...]:
        """Parent-side dependencies of one elaborated port connection.

        ``direct`` means a whole-symbol identity. Casts, selectors, operations
        and concatenations have known dependencies but unknown bit mapping.
        """
        if not isinstance(expression, Mapping):
            return ()
        kind = expression.get("kind")
        if kind == "ParenthesizedExpression":
            return self.port_actuals(self._operand(expression))
        direct = self.direct(expression)
        if direct:
            return ((direct, "direct"),)
        if kind in SELECTORS:
            selected = self.base(expression)
            return ((selected, "partial"),) if selected else tuple((n, "partial") for n in self.reads(expression))
        if kind in CONVERSIONS:
            return tuple((n, "partial") for n in self.reads(expression))
        if kind in ASSIGNMENT_EXPRESSIONS:
            # Slang represents implicit output port connections with an
            # AssignmentExpression. The parent reference can be on either side
            # depending on version/direction: preserve only proven identities.
            left = self.port_actuals(expression.get("left", expression.get("lhs")))
            right = self.port_actuals(expression.get("right", expression.get("rhs")))
            unique = dict.fromkeys(name for name, _ in (*left, *right))
            if len(unique) == 1:
                name = next(iter(unique))
                return ((name, "direct" if (not left or not right) and all(m == "direct" for _, m in (*left, *right)) else "partial"),)
            return tuple((name, "partial") for name in unique)
        return tuple((n, "partial") for n in self.reads(expression))


@dataclass(frozen=True)
class OperandBinding:
    """A connection to one *named* functional-symbol input pin."""

    pin: str
    signal: str
    mapping: str


class OperatorResolver:
    """Derive pin roles from elaborated expression fields, never from wire order.

    For the SV conditional ``S ? TRUE : FALSE``: A = FALSE, B = TRUE,
    S = selector. This is consistent with Yosys' Y = S ? B : A mux model.
    Unknown serializer variants are explicitly classified as generic inputs.
    """

    def __init__(self, symbols: SymbolTable):
        self.symbols = symbols

    def inputs(self, expression: Mapping[str, Any]) -> tuple[OperandBinding, ...]:
        kind = str(expression.get("kind", ""))
        operands: list[tuple[str, Any]] = []
        if kind in {"ConditionalOp", "ConditionalExpression"}:
            condition = next((expression.get(k) for k in ("condition", "predicate", "selector", "cond")
                              if isinstance(expression.get(k), (Mapping, list))), None)
            if condition is None:
                condition = expression.get("conditions")
            operands = [("A", expression.get("right", expression.get("falseExpr"))),
                        ("B", expression.get("left", expression.get("trueExpr"))),
                        ("S", condition)]
        elif kind == "BinaryOp":
            operands = [("A", expression.get("left")), ("B", expression.get("right"))]
        elif kind == "UnaryOp":
            operands = [("A", expression.get("operand"))]
        else:
            operands = [("IN", expression)]
        result = []
        seen = set()
        for pin, operand in operands:
            for signal in self.symbols.reads(operand):
                key = (pin, signal)
                if key in seen:
                    continue
                seen.add(key)
                # An array element, slice or concatenation is a proven
                # dependency, but not a whole-vector bijection.
                mapping = "direct" if self.symbols.direct(operand) == signal else "partial"
                result.append(OperandBinding(pin, signal, mapping))
        return tuple(result)


@dataclass(frozen=True)
class PortBinding:
    signal: str
    port: str
    direction: str
    mapping: str


class PortResolver:
    """Project elaborated instance-port expressions into a parent scope."""

    def __init__(self, members: Iterable[Any], declared: set[str]):
        self.symbols = SymbolTable(members, declared)

    @staticmethod
    def _port_name(binding: Mapping[str, Any], port_by_address: Mapping[str, str], ports: Mapping[str, Any]) -> str:
        raw = binding.get("port", binding.get("name"))
        if isinstance(raw, Mapping):
            address = _address(raw.get("addr", raw.get("symbol")))
            name = port_by_address.get(address, _name(raw)) if address else _name(raw)
        elif isinstance(raw, str):
            address = _address(raw)
            name = port_by_address.get(address, "") if address else raw
        else:
            name = ""
        return name if name in ports else ""

    def resolve(self, instance: Mapping[str, Any], ports: Mapping[str, Mapping[str, Any]]) -> tuple[tuple[PortBinding, ...], dict[str, str]]:
        """Return proven bindings AND explicit unknown/unconnected pin states."""
        body = instance.get("body", {})
        body_members = body.get("members", ()) if isinstance(body, Mapping) else ()
        port_by_address = {_address(p.get("addr")): _name(p)
                           for p in body_members if isinstance(p, Mapping) and p.get("kind") in {"Port", "InterfacePort"}
                           and _address(p.get("addr"))}
        explicit = instance.get("connections") or instance.get("portConnections") or ()
        if isinstance(explicit, Mapping):
            explicit = ({"port": name, "expression": expr} for name, expr in explicit.items())
        explicit = [p for p in explicit if isinstance(p, Mapping)]
        provided = {self._port_name(p, port_by_address, ports) for p in explicit}
        # Different Slang serializers place bindings either on the instance or
        # on individual Port objects. Merge both by declared port identity;
        # never use textual similarity between parent and child signals.
        body_bindings = (p for p in body_members if isinstance(p, Mapping)
                         and p.get("kind") in {"Port", "InterfacePort"}
                         and _name(p) not in provided)
        result: dict[tuple[str, str, str], PortBinding] = {}
        states = {name: "unbound" for name in ports}
        for item in (*explicit, *body_bindings):
            if not isinstance(item, Mapping):
                continue
            port = self._port_name(item, port_by_address, ports)
            if not port:
                continue
            direction = str(ports[port].get("direction", "")).lower()
            direction = {"input": "in", "in": "in", "output": "out", "out": "out", "inout": "inout"}.get(direction)
            if direction is None:
                continue
            expression = next((item.get(key) for key in ("expression", "externalExpr", "expr", "value", "connection")
                               if isinstance(item.get(key), Mapping)), None)
            if expression is None:
                continue
            actuals = self.symbols.port_actuals(expression)
            if not actuals:
                states[port] = "unresolved"  # syntax/binding present but cannot be projected
            else:
                states[port] = "partial" if any(mapping != "direct" for _, mapping in actuals) else "bound"
            for signal, mapping in actuals:
                record = PortBinding(signal, port, direction, mapping)
                key = (signal, port, direction)
                previous = result.get(key)
                if previous is None or previous.mapping != "direct":
                    result[key] = record
        return tuple(result.values()), states

    def bindings(self, instance: Mapping[str, Any], ports: Mapping[str, Mapping[str, Any]]) -> tuple[PortBinding, ...]:
        return self.resolve(instance, ports)[0]


class GraphEdges:
    """Stable net-oriented edge IDs; discard duplicates from repeated AST walks."""

    def __init__(self, prefix: str, nodes: Iterable[Mapping[str, Any]], signals: Mapping[str, Mapping[str, Any]], *, max_edges: int = 20_000):
        self.prefix = prefix
        self.max_edges = max_edges
        self.truncated = False
        self.present = {node["id"] for node in nodes}
        self.signals = signals
        self._edges: dict[tuple[str, ...], dict[str, Any]] = {}

    def add(self, source: str, target: str, kind: str, *, net: str = "", port: str = "", pin: str = "", count: int = 1, mapping: str = "direct") -> None:
        if source not in self.present or target not in self.present:
            return
        key = (source, target, kind, net, port, pin, mapping)
        if key in self._edges:
            return
        if len(self._edges) >= self.max_edges:
            self.truncated = True
            return
        digest = sha256(repr(key).encode()).hexdigest()[:20]
        self._edges[key] = {"id": self.prefix + "wire:" + digest, "source": source, "target": target,
                            "type": kind, "resolved": True, "net": self.prefix + "sig:" + net if net else "",
                            "width": self.signals.get(net, {}).get("width", "") if net else "",
                            "port": port, "pin": pin, "count": count, "mapping": mapping}

    def all(self) -> list[dict[str, Any]]:
        return list(self._edges.values())
