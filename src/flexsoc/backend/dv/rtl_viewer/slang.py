"""Identity-preserving adapter for Slang's elaborated JSON object graph.

Slang serializes an object once and subsequent occurrences as ``'<addr> <name>'``.
The address identifies the shared *body*, not the elaborated instance: instance
identity is its hierarchy path. Never merge instances that share a body.
"""
from __future__ import annotations

from collections.abc import Mapping
from typing import Any


class SlangReferences:
    """Resolve serialized object references without guessing from symbol names."""

    def __init__(self, ast: Mapping[str, Any]):
        self._bodies: dict[str, dict[str, Any]] = {}
        self.constants: dict[str, dict[str, Any]] = {}
        self._collect(ast.get("design", {}))
        self._collect(ast.get("definitions", []))

    def _collect(self, value: Any) -> None:
        if isinstance(value, dict):
            if value.get("kind") in {"Parameter", "Specparam"} and value.get("value") is not None:
                address = str(value.get("addr", ""))
                if address.isdecimal():
                    constant = {"op": "literal", "value": str(value["value"]),
                                "type": str(value.get("type", ""))}
                    previous_constant = self.constants.get(address)
                    if previous_constant is not None and previous_constant != constant:
                        raise ValueError(f"conflicting Slang constant address: {address}")
                    self.constants[address] = constant
            if value.get("kind") == "InstanceBody" and value.get("addr") is not None:
                address = str(value["addr"])
                previous = self._bodies.get(address)
                if previous is not None and previous is not value and previous != value:
                    raise ValueError(f"conflicting Slang InstanceBody address: {address}")
                self._bodies[address] = value
            for child in value.values():
                if isinstance(child, (dict, list)):
                    self._collect(child)
        elif isinstance(value, list):
            for child in value:
                self._collect(child)

    def instance(self, node: Mapping[str, Any]) -> dict[str, Any]:
        """Return an instance with a resolved body, preserving its own metadata."""
        if node.get("kind") != "Instance":
            raise ValueError("expected a Slang Instance")
        body = node.get("body")
        if isinstance(body, dict):
            return dict(node)
        if not isinstance(body, str):
            raise ValueError(f"instance {node.get('name')!r} has no resolvable body")
        address = body.split(" ", 1)[0]
        if not address.isdecimal() or address not in self._bodies:
            raise ValueError(f"unresolved Slang InstanceBody reference for {node.get('name')!r}: {body!r}")
        resolved = dict(node)
        resolved["body"] = self._bodies[address]
        return resolved
