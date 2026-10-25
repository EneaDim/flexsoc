"""Structural circuit projection from elaborated Slang declarations and port bindings.

This is intentionally *not* a synthesized netlist: process dependencies, casts,
part selects and unresolved bindings cannot be equated to bit-exact copper.
"""
from __future__ import annotations

from dataclasses import dataclass
from typing import TYPE_CHECKING, Any

from .connectivity import PortResolver

if TYPE_CHECKING:
    from .model import RtlDesign


@dataclass(frozen=True)
class Terminal:
    instance: str
    port: str
    direction: str
    mapping: str

    def as_dict(self) -> dict[str, str]:
        return {"instance": self.instance, "port": self.port,
                "direction": self.direction, "mapping": self.mapping}


class Circuit:
    """Scope-local nets with distinct hierarchical component terminals.

    One net per declaration, regardless of fanout; qualified paths keep
    identical signal names in different scopes electrically distinct.
    """

    def __init__(self, design: RtlDesign, path: str):
        scope = design._scope(path)
        signals = design._signals(scope)
        self.path = path
        self.nets = {name: [] for name in signals}
        self.instances: list[dict[str, Any]] = []
        self.pins: list[dict[str, str]] = []
        resolver = PortResolver(scope.node["body"].get("members", ()), set(signals))
        for child_path in scope.children:
            child = design._scope(child_path)
            ports = {name: info for name, info in design._signals(child).items()
                     if info["kind"] in {"Port", "InterfacePort"}}
            bindings, states = resolver.resolve(child.node, ports)
            self.instances.append({"path": child_path, "name": child.name,
                                   "module": child.module})
            for port, info in ports.items():
                self.pins.append({"instance": child_path, "port": port,
                                  "direction": info["direction"],
                                  "state": states.get(port, "unbound")})
            for binding in bindings:
                if binding.signal not in self.nets:
                    raise ValueError(f"binding refers to undeclared parent net: {binding.signal}")
                terminal = Terminal(child_path, binding.port, binding.direction, binding.mapping)
                if terminal not in self.nets[binding.signal]:
                    self.nets[binding.signal].append(terminal)
        self.signals = signals

    def serialize(self) -> dict[str, Any]:
        return {"schema": "flexsoc.rtl_viewer.circuit.v1", "scope": self.path,
                "semantics": "elaborated structural port connectivity; partial mappings are not bit-exact",
                "instances": self.instances,
                "pins": self.pins,
                "nets": [{"id": self.path + "::sig:" + name, "name": name,
                          "direction": info["direction"], "type": info["width"],
                          "terminals": [terminal.as_dict() for terminal in self.nets[name]]}
                         for name, info in self.signals.items()]}
