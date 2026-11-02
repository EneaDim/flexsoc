"""Conservative, destination-local projection of Slang procedural statements.

A procedural block is a program, *not* a collection of independent electrical
wires.  Nonblocking writes to different whole-register destinations can be
projected separately because their right-hand sides read pre-edge values.
Unrecognized statements, blocking writes and partial destinations cannot be
silently discarded: they may change the next-state expression or control flow.

This module only selects a compiler-authored AST subtree; it does not parse
SystemVerilog source, classify hardware primitives, or emit connectivity.
The downstream bounded priority-MUX lowering is responsible for validating
predicates, expressions, temporary scheduling and actual D nets.
"""
from __future__ import annotations

from dataclasses import dataclass
from typing import Any, Callable

ASSIGNMENTS = frozenset({"Assignment", "AssignmentExpression", "NonblockingAssignment"})
CONDITIONALS = frozenset({"Conditional", "ConditionalStatement", "IfStatement"})
CONTAINERS = frozenset({"Block", "List", "StatementList"})


@dataclass(frozen=True)
class Projection:
    statement: dict[str, Any] | None
    supported: bool
    reason: str = ""


def project_destination(
    statement: Any,
    target: str,
    *,
    writes: Callable[[Any], list[str] | tuple[str, ...] | set[str]],
    direct: Callable[[Any], str | None],
    max_depth: int = 48,
    max_nodes: int = 2048,
) -> Projection:
    """Retain exactly the NBA updates to *target* in AST execution order.

    A different whole-register NBA is safe to elide; an unknown write or
    blocking assignment isn't.  Conditions retain their original Slang AST,
    including distinct true/false branches.  A missing branch means hold.
    An empty projection is valid but does not establish a D driver.
    """
    count = 0
    active: set[int] = set()

    def fail(reason: str) -> Projection:
        return Projection(None, False, reason)

    def visit(node: Any, depth: int) -> Projection:
        nonlocal count
        if not isinstance(node, dict):
            return fail("unrecognized procedural statement")
        count += 1
        if count > max_nodes or depth >= max_depth or id(node) in active:
            return fail("procedural projection bounds exceeded")
        active.add(id(node))
        try:
            kind = node.get("kind")
            if kind == "ExpressionStatement":
                return visit(node.get("expr", node.get("expression")), depth + 1)
            if kind in CONTAINERS:
                raw = (node.get("list") if kind == "List" else
                       node.get("body", node.get("statements")))
                if isinstance(raw, dict):
                    raw = [raw]
                if not isinstance(raw, (list, tuple)) or len(raw) > max_nodes:
                    return fail("invalid statement container")
                remaining = []
                for item in raw:
                    child = visit(item, depth + 1)
                    if not child.supported:
                        return child
                    if child.statement is not None:
                        remaining.append(child.statement)
                if not remaining:
                    return Projection(None, True)
                if len(remaining) == 1:
                    return Projection(remaining[0], True)
                return Projection({"kind": "Block", "body": remaining}, True)
            if kind in ASSIGNMENTS:
                lhs = node.get("left", node.get("lhs"))
                assigned = set(writes(lhs))
                destination = direct(lhs)
                if destination is None or assigned != {destination}:
                    return fail("partial or unsupported assignment destination")
                if node.get("isNonBlocking") is not True and kind != "NonblockingAssignment":
                    return fail("blocking or unknown assignment scheduling")
                if not isinstance(node.get("right", node.get("rhs")), dict):
                    return fail("assignment without an AST expression")
                return Projection(node if destination == target else None, True)
            if kind in CONDITIONALS:
                clone = node.copy()
                any_write = False
                for aliases in (("ifTrue", "then"), ("ifFalse", "else")):
                    present = [key for key in aliases if node.get(key) is not None]
                    if len(present) > 1:
                        return fail("ambiguous conditional branch aliases")
                    if not present:
                        continue
                    key = present[0]
                    child = visit(node[key], depth + 1)
                    if not child.supported:
                        return child
                    if child.statement is None:
                        clone.pop(key, None)
                    else:
                        clone[key] = child.statement
                        any_write = True
                return Projection(clone if any_write else None, True)
            if kind == "EmptyStatement":
                return Projection(None, True)
            # Do not drop a case, loop, event control, task, or blocking
            # temporary.  Future adapters must explicitly prove their effect.
            return fail(f"unsupported procedural statement: {kind}")
        finally:
            active.remove(id(node))

    return visit(statement, 0)
