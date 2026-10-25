"""Conservative, source-linked behavioral process projection from elaborated Slang.

This IR describes *dependencies*, not synthesized gates or bit-exact wiring.
Unsupported AST statements are reported rather than silently assumed inert.
"""
from __future__ import annotations

from dataclasses import dataclass
from typing import Any, Mapping

from .connectivity import SymbolTable
from .model import ASSIGN_KINDS, extract_location


@dataclass(frozen=True)
class Dependency:
    destination: str
    source: str
    role: str
    mapping: str = "partial"

    def serialize(self) -> dict[str, str]:
        return vars(self).copy()


class ProcessAnalyzer:
    """Walk behavioral AST with explicit predicate/event context.

    Slang expression nodes are opaque except for symbol references. Unknown
    statement kinds are traversed conservatively and flagged in diagnostics.
    """

    _BRANCHES = frozenset({"Conditional", "ConditionalStatement", "IfStatement"})
    _CASES = frozenset({"Case", "CaseStatement", "CaseStmt"})
    _LOOPS = frozenset({"ForLoop", "WhileLoop", "DoWhileLoop", "RepeatLoop", "ForeachLoop", "ForeverLoop"})
    _CONTAINERS = frozenset({"Block", "List", "ExpressionStatement", "Timed", "Return", "StatementList",
                             "VariableDeclaration", "ConditionalLoop", "CaseItem", "Loop"})

    def __init__(self, members: list[Any], declared: set[str]):
        self.symbols = SymbolTable(members, declared)
        self.records: list[dict[str, Any]] = []
        self.diagnostics: list[dict[str, str]] = []
        self._active: list[Dependency] = []
        self._seen: set[Dependency] = set()
        self._event_index: list[dict[str, str]] = []
        self._assignments: list[dict[str, Any]] = []

    @staticmethod
    def _reads(value: Any, symbols: SymbolTable) -> tuple[str, ...]:
        return symbols.reads(value)

    def _add(self, destination: str, source: str, role: str, mapping: str = "partial") -> None:
        dep = Dependency(destination, source, role, mapping)
        if dep not in self._seen:
            self._seen.add(dep)
            self._active.append(dep)

    def _condition(self, node: Mapping[str, Any]) -> tuple[str, ...]:
        values = node.get("conditions", node.get("condition", node.get("predicate")))
        return self.symbols.reads(values)

    def _events(self, value: Any) -> list[dict[str, str]]:
        events: list[dict[str, str]] = []
        def walk(entry: Any) -> None:
            if isinstance(entry, list):
                for child in entry:
                    walk(child)
            elif isinstance(entry, dict):
                if entry.get("kind") == "SignalEvent":
                    for source in self.symbols.reads(entry.get("expr")):
                        events.append({"source": source, "edge": str(entry.get("edge", "Any"))})
                else:
                    for child in entry.values():
                        if isinstance(child, (dict, list)):
                            walk(child)
        walk(value)
        return events

    @staticmethod
    def _guard(node: Mapping[str, Any], branch: str, index: int = 0) -> dict[str, Any]:
        file, line = extract_location(dict(node))
        return {"kind": str(node.get("kind", "")), "branch": branch,
                "index": index, "source": {"file": file, "line": line}}

    def _statement(self, node: Any, conditions: tuple[str, ...], events: list[dict[str, str]],
                   guards: tuple[dict[str, Any], ...] = ()) -> None:
        if isinstance(node, list):
            for item in node:
                self._statement(item, conditions, events, guards)
            return
        if not isinstance(node, dict):
            return
        kind = str(node.get("kind", ""))
        if kind in self._BRANCHES:
            next_conditions = tuple(dict.fromkeys((*conditions, *self._condition(node))))
            for branch in ("ifTrue", "ifFalse", "then", "else"):
                if branch in node:
                    self._statement(node[branch], next_conditions, events,
                                    (*guards, self._guard(node, branch)))
            return
        if kind in self._CASES:
            selector = self.symbols.reads(node.get("expr", node.get("expression", node.get("selector"))))
            next_conditions = tuple(dict.fromkeys((*conditions, *selector)))
            for branch in ("items", "branches"):
                for index, item in enumerate(node.get(branch, ())):
                    if not isinstance(item, dict):
                        self.diagnostics.append({"kind": kind, "reason": "non-object case item"})
                        continue
                    # Include symbols in case-item expressions as controls.
                    item_conditions = tuple(dict.fromkeys((*next_conditions,
                        *self.symbols.reads(item.get("expressions", ())))))
                    self._statement(item.get("stmt", item.get("statement")), item_conditions, events,
                                    (*guards, self._guard(node, branch, index)))
            for branch in ("defaultCase", "default"):
                if branch in node:
                    self._statement(node[branch], next_conditions, events,
                                    (*guards, self._guard(node, branch)))
            return
        if kind in self._LOOPS:
            predicate = self.symbols.reads([node.get(k) for k in ("stopExpr", "condition", "count", "range")])
            next_conditions = tuple(dict.fromkeys((*conditions, *predicate)))
            for branch in ("initializers", "body", "steps", "statement"):
                if branch in node:
                    self._statement(node[branch], next_conditions, events, guards)
            return
        if kind in ASSIGN_KINDS or ("Assignment" in kind and "Pattern" not in kind):
            lhs = node.get("left", node.get("lhs"))
            rhs = node.get("right", node.get("rhs"))
            if lhs is not None and rhs is not None:
                destinations = self.symbols.writes(lhs)
                mapping = "direct" if self.symbols.direct(lhs) and self.symbols.direct(rhs) else "partial"
                file, line = extract_location(dict(node))
                self._assignments.append({
                    "ordinal": len(self._assignments), "destinations": list(destinations),
                    "reads": list(self.symbols.reads(rhs)),
                    "address_reads": list(self.symbols.address_reads(lhs)),
                    "blocking": str(node.get("isNonBlocking", False)).lower() not in {"true", "1"},
                    "mapping": mapping, "guards": list(guards),
                    "source": {"file": file, "line": line},
                })
                for dst in destinations:
                    for src in self.symbols.reads(rhs):
                        self._add(dst, src, "data", mapping)
                    for src in self.symbols.address_reads(lhs):
                        self._add(dst, src, "address")
                    for src in conditions:
                        self._add(dst, src, "control")
                    for event in events:
                        self._add(dst, event["source"], "event")
                return
        if kind == "Timed":
            discovered = self._events(node.get("timing"))
            for event in discovered:
                if event not in self._event_index:
                    self._event_index.append(event)
            next_events = [*events, *discovered]
            for key in ("stmt", "statement", "body"):
                if key in node:
                    self._statement(node[key], conditions, next_events, guards)
            return
        if kind in self._CONTAINERS or not kind:
            for key, value in node.items():
                if isinstance(value, (dict, list)):
                    self._statement(value, conditions, events, guards)
            return
        # Expressions not standing for statements contain no additional writes;
        # report opaque statements instead of claiming complete lowering.
        if kind in {"Call", "SubroutineCall", "Disable", "Wait", "WaitFork", "ForkJoin"}:
            self.diagnostics.append({"kind": kind, "reason": "requires behavioral lowering"})
            return
        for value in node.values():
            if isinstance(value, (dict, list)):
                self._statement(value, conditions, events, guards)

    def process(self, block: Mapping[str, Any], index: int) -> dict[str, Any]:
        self._active = []
        self._seen = set()
        self._event_index = []
        self._assignments = []
        self.diagnostics = []
        location, line = extract_location(dict(block))
        self._statement(block.get("body"), (), [])
        return {"id": f"process:{index}", "kind": str(block.get("procedureKind", "Unknown")),
                "source": {"file": location, "line": line},
                "events": list(self._event_index),
                "assignments": list(self._assignments),
                "dependencies": [entry.serialize() for entry in self._active],
                "diagnostics": list(self.diagnostics)}


class BehavioralIR:
    """Process dependency projection attached to a single elaborated scope."""

    def __init__(self, design: Any, path: str):
        scope = design._scope(path)
        members = scope.node["body"].get("members", ())
        analyzer = ProcessAnalyzer(list(members), set(design._signals(scope)))
        self.path = path
        self.processes = [analyzer.process(member, index) for index, member in enumerate(members)
                          if isinstance(member, dict) and member.get("kind") == "ProceduralBlock"]

    def serialize(self) -> dict[str, Any]:
        return {"schema": "flexsoc.rtl_viewer.behavior.v1", "scope": self.path,
                "semantics": "conservative behavioral dependencies, not synthesized circuit or bit mapping",
                "processes": self.processes}
