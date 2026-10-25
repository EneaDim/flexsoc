"""Regression for real Slang source fields and AST-proven literal ports."""
from pathlib import Path

from flexsoc.backend.dv.rtl_viewer.connectivity import PortResolver
from flexsoc.backend.dv.rtl_viewer.model import RtlDesign, extract_location


def test_public_slang_source_file_line():
    assert extract_location({"source_file": "rtl/uart.sv", "source_line": 23}) == ("rtl/uart.sv", 23)
    assert extract_location({"source_file": "rtl/uart.sv", "source_line": "invalid"}) == ("rtl/uart.sv", 0)


def test_constant_port_not_reported_as_unresolved():
    # Slang serializes a sized literal wrapped by an implicit conversion.
    instance = {"connections": [{"port": {"name": "d_i"}, "expr": {
        "kind": "Conversion", "operand": {"kind": "IntegerLiteral", "value": "1'b1", "constant": "1'b1"}}}]}
    resolver = PortResolver((), set())
    bindings, states = resolver.resolve(instance, {"d_i": {"direction": "In"}})
    assert bindings == ()
    assert states == {"d_i": "constant"}


def test_unsupported_expression_still_unresolved():
    instance = {"connections": [{"port": {"name": "d_i"}, "expr": {"kind": "UnknownNode"}}]}
    bindings, states = PortResolver((), set()).resolve(instance, {"d_i": {"direction": "In"}})
    assert bindings == ()
    assert states == {"d_i": "unresolved"}
