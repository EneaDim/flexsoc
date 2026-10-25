"""Validated, layout-independent view of structural and behavioral RTL.

Structural terminals are electrical bindings; process dependencies are *not*
converted to wires. No synthesized gates or bit-level equivalence are claimed.
"""
from __future__ import annotations

from typing import Any

from .circuit import Circuit
from .lowering import LoweredIR
from .process import BehavioralIR


class CanonicalCircuit:
    """Combine the independently testable projections with explicit integrity checks."""

    def __init__(self, design: Any, path: str):
        self.structure = Circuit(design, path).serialize()
        self.behavior = BehavioralIR(design, path).serialize()
        self.values = LoweredIR(design, path).serialize()
        self.diagnostics: list[dict[str, str]] = []
        self._validate()

    def _error(self, kind: str, detail: str) -> None:
        self.diagnostics.append({"kind": kind, "detail": detail})

    def _validate(self) -> None:
        instances = {entry["path"] for entry in self.structure["instances"]}
        if len(instances) != len(self.structure["instances"]):
            self._error("duplicate_instance", "multiple instances share a hierarchical path")
        pin_keys = {(p["instance"], p["port"]) for p in self.structure["pins"]}
        if len(pin_keys) != len(self.structure["pins"]):
            self._error("duplicate_pin", "multiple terminals share an instance and port")
        bound: set[tuple[str, str]] = set()
        for net in self.structure["nets"]:
            for terminal in net["terminals"]:
                key = (terminal["instance"], terminal["port"])
                if key not in pin_keys or key[0] not in instances:
                    self._error("orphan_terminal", f"{net['id']} refers to absent terminal {key}")
                if key in bound and terminal["mapping"] == "direct":
                    # More than one whole-net binding for a pin requires an explicit
                    # bit mapping, otherwise a renderer must not merge them.
                    self._error("multiple_direct_bindings", f"{key} has multiple direct nets")
                bound.add(key)
        for pin in self.structure["pins"]:
            key = (pin["instance"], pin["port"])
            if pin["state"] == "bound" and key not in bound:
                self._error("missing_binding", f"{key} marked bound without a net terminal")
        process_ids = [p["id"] for p in self.behavior["processes"]]
        value_ids = [p["id"] for p in self.values["processes"]]
        if process_ids != value_ids:
            self._error("process_mismatch", "behavior and lowering disagree on process identities")
        declared = {net["name"] for net in self.structure["nets"]}
        for process in self.values["processes"]:
            for bucket in ("blocking_final", "scheduled_nba"):
                for name in process[bucket]:
                    if name not in declared:
                        self._error("undeclared_write", f"{process['id']} writes {name}")
            if process["status"] == "unsupported" and (process["blocking_final"] or process["scheduled_nba"]):
                self._error("partial_lowering", f"{process['id']} exposes partial values")

    def serialize(self) -> dict[str, Any]:
        return {
            "schema": "flexsoc.rtl_viewer.canonical.v1",
            "scope": self.structure["scope"],
            "semantics": "structural nets and symbolic processes remain separate; no synthesis equivalence claimed",
            "structure": self.structure,
            "behavior": self.behavior,
            "values": self.values,
            "integrity": {"status": "ok" if not self.diagnostics else "invalid",
                          "diagnostics": self.diagnostics},
        }
