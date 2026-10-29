"""Slang JSON reference identity contract and real UART integration."""
from __future__ import annotations

import json
from pathlib import Path

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from flexsoc.backend.dv.rtl_viewer.slang import SlangReferences


def ast_fixture():
    shared = {"kind": "InstanceBody", "name": "sync", "addr": 42, "members": [
        {"kind": "Port", "name": "clk", "direction": "In", "addr": 44},
    ]}
    return {"design": {"members": [{"kind": "Instance", "name": "top", "body": {
        "kind": "InstanceBody", "name": "top", "addr": 10, "members": [
            {"kind": "Port", "name": "clk", "direction": "In", "addr": 12},
            {"kind": "Instance", "name": "first", "body": shared,
             "connections": [{"port": "clk", "expression": {"kind": "NamedValue", "symbol": "12 clk"}}]},
            {"kind": "Instance", "name": "second", "body": "42 sync",
             "connections": [{"port": "clk", "expression": {"kind": "NamedValue", "symbol": "12 clk"}}]},
        ]}}]}, "definitions": []}


def test_cached_body_does_not_merge_instance_identity(tmp_path):
    ast = ast_fixture()
    design = RtlDesign(ast, root=tmp_path, top="top")
    assert set(design.scopes) == {"/", "/first", "/second"}
    assert design.scopes["/first"].node["body"] is design.scopes["/second"].node["body"]
    assert [node["name"] for node in design.diagram()["nodes"] if node["type"] == "instance"] == ["first", "second"]
    assert isinstance(ast["design"]["members"][0]["body"]["members"][2]["body"], str)


def test_unknown_reference_fails_closed(tmp_path):
    ast = ast_fixture()
    ast["design"]["members"][0]["body"]["members"][2]["body"] = "999 sync"
    with pytest.raises(ValueError, match="unresolved Slang InstanceBody"):
        RtlDesign(ast, root=tmp_path, top="top")


def test_repeated_body_reference_requires_address_not_matching_name():
    refs = SlangReferences(ast_fixture())
    with pytest.raises(ValueError, match="unresolved"):
        refs.instance({"kind": "Instance", "name": "second", "body": "7 sync"})


def test_real_uart_ast_has_all_four_children_and_two_syncs():
    root = Path(__file__).resolve().parents[2]
    source = root / "workspace/runs/uart/qualification_l2/dv/slang_hier/ast.json"
    if not source.exists():
        pytest.skip("optional actual UART qualification Slang AST not provided")
    design = RtlDesign(json.loads(source.read_text()), root=root, top="uart")
    children = {design.scopes[p].name: design.scopes[p].module for p in design.scopes["/"].children}
    assert children == {
        "u_reg_reset_sync": "prim_ff_2sync", "u_core_reset_sync": "prim_ff_2sync",
        "u_uart_reg": "uart_reg_top", "u_uart_core": "uart_core",
    }
    diagram = design.diagram()
    visible = {n["name"] for n in diagram["nodes"] if n["type"] == "instance"}
    assert visible == set(children)


def test_colliding_symbol_addresses_never_select_an_arbitrary_signal():
    from flexsoc.backend.dv.rtl_viewer.connectivity import SymbolTable

    members = (
        {"kind": "Variable", "name": "alpha", "addr": 7},
        {"kind": "Variable", "name": "beta", "addr": 7},
        {"kind": "Variable", "name": "unique", "addr": 8},
    )
    symbols = SymbolTable(members, {"alpha", "beta", "unique"})
    assert symbols.ambiguous_addresses == {"7"}
    assert symbols.direct({"kind": "NamedValue", "symbol": "7 alpha"}) is None
    assert symbols.direct({"kind": "NamedValue", "symbol": "7 beta"}) is None
    assert symbols.port_actuals({"kind": "NamedValue", "symbol": "7 beta"}) == ()
    assert symbols.direct({"kind": "NamedValue", "symbol": "8 unique"}) == "unique"


def test_port_backing_alias_preserves_unique_declaration_identity():
    from flexsoc.backend.dv.rtl_viewer.connectivity import SymbolTable

    symbols = SymbolTable((
        {"kind": "Port", "name": "data_i", "addr": 11, "internalSymbol": "12 wire"},
        {"kind": "Variable", "name": "storage", "addr": 12},
    ), {"data_i", "storage"})
    assert symbols.direct({"kind": "NamedValue", "symbol": "12 storage"}) == "storage"
    assert symbols.direct({"kind": "NamedValue", "symbol": "11 data_i"}) == "data_i"
