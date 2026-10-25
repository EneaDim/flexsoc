"""Electrical schematic contract, independent of placement and RTL dependency arrows.

A net is a hyperedge with a single identity and multiple terminals. Unresolved
or partial port expressions never become fictitious electrical connections.
"""
from __future__ import annotations

from typing import Any

from .canonical import CanonicalCircuit


class Schematic:
    """Project the validated structural part of a canonical design for CAD layout."""

    def __init__(self, design: Any, path: str = "/"):
        canonical = CanonicalCircuit(design, path).serialize()
        self.path = path
        self.integrity = canonical["integrity"]
        structure = canonical["structure"]
        self.components = [{"id": item["path"], "name": item["name"],
                            "module": item["module"], "kind": "instance"}
                           for item in structure["instances"]]
        self.pins = [{"id": f'{pin["instance"]}::{pin["port"]}',
                      "component": pin["instance"], "name": pin["port"],
                      "direction": pin["direction"], "state": pin["state"]}
                     for pin in structure["pins"]]
        self.ports = []
        self.nets = []
        for net in structure["nets"]:
            terminals = [{"pin": f'{pin["instance"]}::{pin["port"]}',
                          "direction": pin["direction"], "mapping": pin["mapping"]}
                         for pin in net["terminals"]]
            # A top-level port belongs to the same net but is not a submodule terminal.
            # This is a declaration, not a newly invented driver or electrical edge.
            if net["direction"] in ("input", "output", "inout", "ref", "in", "out"):
                port_id = f'{path}::port:{net["name"]}'
                self.ports.append({"id": port_id, "name": net["name"],
                                   "direction": net["direction"], "net": net["id"]})
                terminals.insert(0, {"pin": port_id, "direction": net["direction"],
                                     "mapping": "direct"})
            self.nets.append({"id": net["id"], "name": net["name"],
                              "type": net["type"], "terminals": terminals,
                              "complete": all(pin["mapping"] == "direct" for pin in terminals)})
        self._validate()

    def _validate(self) -> None:
        known = {pin["id"] for pin in self.pins} | {port["id"] for port in self.ports}
        used: set[str] = set()
        for net in self.nets:
            if net["id"] in used:
                raise ValueError(f'duplicate schematic net: {net["id"]}')
            used.add(net["id"])
            for terminal in net["terminals"]:
                if terminal["pin"] not in known:
                    raise ValueError(f'orphan schematic terminal: {terminal["pin"]}')

    def serialize(self) -> dict[str, Any]:
        return {"schema": "flexsoc.rtl_viewer.schematic.v1", "scope": self.path,
                "semantics": "one hyperedge per declared net; layout and process dependencies excluded",
                "components": self.components, "pins": self.pins,
                "ports": self.ports, "nets": self.nets, "integrity": self.integrity}
