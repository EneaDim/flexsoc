"""Schematic topology is a hypergraph, not one routed edge per destination."""
import json
from pathlib import Path

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from test_slang_reference_identity import ast_fixture


def test_one_shared_hyperedge_for_two_instances(tmp_path):
    design = RtlDesign(ast_fixture(), root=tmp_path, top="top")
    graph = design.schematic()
    assert graph["integrity"]["status"] == "ok"
    assert len(graph["components"]) == 2
    assert len(graph["nets"]) == 1
    net = graph["nets"][0]
    assert net["complete"]
    assert {p["pin"] for p in net["terminals"] if "::port:" not in p["pin"]} == {
        "/first::clk", "/second::clk"}
    assert len({p["pin"] for p in net["terminals"]}) == len(net["terminals"])
    assert design.schematic("/first")["nets"][0]["id"] != net["id"]


def test_uart_actual_instance_identity_and_fanout():
    root = Path(__file__).resolve().parents[2]
    source = root / "workspace/runs/uart/qualification_l2/dv/slang_hier/ast.json"
    if not source.exists():
        pytest.skip("actual UART AST not supplied")
    design = RtlDesign(json.loads(source.read_text()), root=root, top="uart")
    graph = design.schematic()
    assert graph["integrity"]["status"] == "ok"
    assert len(graph["components"]) == 4
    components = {c["name"] for c in graph["components"]}
    assert {"u_core_reset_sync", "u_reg_reset_sync", "u_uart_core", "u_uart_reg"} == components
    nets = {n["name"]: n for n in graph["nets"]}
    assert {p["pin"] for p in nets["clk_i"]["terminals"] if "::port:" not in p["pin"]} == {
        "/u_core_reset_sync::clk_i", "/u_reg_reset_sync::clk_i",
        "/u_uart_core::clk_i", "/u_uart_reg::clk_i"}
    assert {p["pin"] for p in nets["rst_ni"]["terminals"] if "::port:" not in p["pin"]} == {
        "/u_core_reset_sync::rst_ni", "/u_reg_reset_sync::rst_ni"}
    assert {p["pin"] for p in nets["reg_rst_ni"]["terminals"]} == {
        "/u_reg_reset_sync::q_o", "/u_uart_reg::rst_ni"}
    assert {p["pin"] for p in nets["core_rst_ni"]["terminals"]} == {
        "/u_core_reset_sync::q_o", "/u_uart_core::rst_ni"}
