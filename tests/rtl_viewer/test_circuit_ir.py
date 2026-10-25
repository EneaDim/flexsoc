"""Circuit projection contracts: net identity, multiplicity and uncertainty."""
import json
from pathlib import Path

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from test_slang_reference_identity import ast_fixture


def test_one_net_multiple_separate_instance_terminals(tmp_path):
    graph = RtlDesign(ast_fixture(), root=tmp_path, top="top").circuit()
    assert graph["schema"] == "flexsoc.rtl_viewer.circuit.v1"
    assert len(graph["instances"]) == 2
    assert graph["instances"][0]["path"] != graph["instances"][1]["path"]
    assert len(graph["nets"]) == 1
    assert graph["nets"][0]["name"] == "clk"
    assert {(pin["instance"], pin["port"]) for pin in graph["nets"][0]["terminals"]} == {
        ("/first", "clk"), ("/second", "clk")}
    assert len(graph["pins"]) == 2
    assert {pin["state"] for pin in graph["pins"]} == {"bound"}


def test_scope_local_names_do_not_alias(tmp_path):
    design = RtlDesign(ast_fixture(), root=tmp_path, top="top")
    parent = design.circuit("/")
    child = design.circuit("/first")
    assert parent["nets"][0]["id"] != child["nets"][0]["id"]


def test_actual_uart_top_structure_and_shared_nets():
    root = Path(__file__).resolve().parents[2]
    ast_path = root / "workspace/runs/uart/qualification_l2/dv/slang_hier/ast.json"
    if not ast_path.exists():
        pytest.skip("real UART Slang elaboration not supplied")
    design = RtlDesign(json.loads(ast_path.read_text()), root=root, top="uart")
    circuit = design.circuit()
    assert {instance["name"] for instance in circuit["instances"]} == {
        "u_reg_reset_sync", "u_core_reset_sync", "u_uart_reg", "u_uart_core"}
    nets = {net["name"]: net for net in circuit["nets"]}
    for signal in ("clk_i", "rst_ni"):
        terminals = {(p["instance"], p["port"]) for p in nets[signal]["terminals"]}
        assert ("/u_reg_reset_sync", signal) in terminals
        assert ("/u_core_reset_sync", signal) in terminals
    assert ("/u_reg_reset_sync", "q_o") in {(p["instance"], p["port"]) for p in nets["reg_rst_ni"]["terminals"]}
    assert ("/u_core_reset_sync", "q_o") in {(p["instance"], p["port"]) for p in nets["core_rst_ni"]["terminals"]}
