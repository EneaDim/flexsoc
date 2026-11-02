"""General AST-backed FF D projection: constant reset expressions and boolean predicates.

Regression source: reduced real Ethernet Slang AST (028 fixture includes mac TX
clock-domain process). Never infer expressions from RTL signal names.
"""
from __future__ import annotations

import copy
import json
from pathlib import Path

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from flexsoc.backend.dv.rtl_viewer.sequential_controls import is_literal_rhs

FIXTURE = Path(__file__).parent / "fixtures/ethernet_reset_compound_029.json"


def diagram(ast=None):
    return RtlDesign(ast or json.loads(FIXTURE.read_text()),
                     root=FIXTURE.parent, top="top").diagram(limit=1500)


def incoming(graph, name):
    node = next(n for n in graph["nodes"] if n["name"] == name)
    return node, [e for e in graph["edges"] if e["target"] == node["id"]
                  and e.get("rendered") and e.get("targetPin") == "D"]


def test_constant_reset_concatenation_is_a_constant_not_an_unconnected_driver():
    # Compiler supplied two literal typed fields; no runtime symbol or wire.
    reset = {"kind": "Conversion", "type": "logic[8:0]", "constant": "9'd12",
             "operand": {"kind": "Concatenation", "constant": "9'd12", "operands": [
                 {"kind": "IntegerLiteral", "value": "1'b0"},
                 {"kind": "IntegerLiteral", "value": "8'd12"}]}}
    assert is_literal_rhs(reset)
    runtime = copy.deepcopy(reset)
    runtime["operand"]["operands"][1] = {"kind": "NamedValue", "constant": "8'd12",
                                                   "symbol": "1 malicious"}
    assert not is_literal_rhs(runtime), "a 'constant' display hint cannot prove a declaration reference"
    assert not is_literal_rhs({"kind": "Call", "constant": "0", "arguments": []})


def test_constant_arithmetic_and_replication_support_is_bounded():
    lit = {"kind": "IntegerLiteral", "value": "2"}
    assert is_literal_rhs({"kind": "BinaryOp", "op": "Add", "left": lit, "right": lit})
    assert is_literal_rhs({"kind": "Replication", "count": 2, "concat": lit})
    assert not is_literal_rhs({"kind": "Replication", "count": "runtime", "concat": lit})
    assert not is_literal_rhs({"kind": "Concatenation", "operands": []})
    assert not is_literal_rhs({"kind": "Concatenation", "operands": [lit] * 100})
    loop = {"kind": "Conversion"}
    loop["operand"] = loop
    assert not is_literal_rhs(loop)


def test_real_slang_compound_predicate_builds_complete_d_and_s_pins():
    graph = diagram()
    cfg, cfg_d = incoming(graph, "tx_cfg_mac")
    ack, ack_d = incoming(graph, "tx_ack_mac")
    assert cfg["type"] == ack["type"] == "register"
    assert not cfg.get("dInputStatus") and not ack.get("dInputStatus")
    assert len(cfg_d) == len(ack_d) == 1
    for edge in cfg_d + ack_d:
        mux = next(n for n in graph["nodes"] if n["id"] == edge["source"])
        assert mux["name"] == "MUX"
        assert any(e["target"] == mux["id"] and e.get("rendered") and e.get("pin") == "S"
                   and e["source"].startswith("/::op:") for e in graph["edges"])
    assert any(n["name"] == "LogicalAnd" for n in graph["nodes"])
    assert any(n["name"] == "Inequality" for n in graph["nodes"])
    assert any(n["name"] == "LogicalNot" for n in graph["nodes"])
    # The register Q net cannot silently short to the MUX Y/D net.
    assert all(edge.get("driverNet") != "/::sig:tx_cfg_mac" for edge in cfg_d)


def test_unsupported_predicate_does_not_fabricate_a_d_wire():
    ast = json.loads(FIXTURE.read_text())
    processes = [m for m in ast["design"]["members"][0]["body"]["members"]
                 if m.get("kind") == "ProceduralBlock"]

    def find_if(node):
        if isinstance(node, dict):
            if node.get("kind") in ("Conditional", "ConditionalStatement", "IfStatement") and node.get("source_line_start") == 142:
                return node
            for value in node.values():
                found = find_if(value)
                if found: return found
        elif isinstance(node, list):
            for item in node:
                found = find_if(item)
                if found: return found
        return None

    target = next((found for p in processes if (found := find_if(p)) is not None), None)
    assert target is not None
    # Prove it cannot infer a physical control from dynamic indexing.
    target["conditions"][0]["expr"]["right"] = {
        "kind": "ElementSelect", "type": "logic",
        "value": {"kind": "NamedValue", "symbol": "6338716881592 mac_gmii_tx_en"},
        "selector": {"kind": "NamedValue", "symbol": "6338716883680 tx_req_sync_mac"},
    }
    graph = diagram(ast)
    cfg, cfg_d = incoming(graph, "tx_cfg_mac")
    assert cfg["type"] == "register"
    assert cfg.get("dInputStatus")
    assert not cfg_d


def test_elk_routes_compound_boolean_predicate_to_s_and_d():
    import shutil
    import subprocess
    import pytest
    if shutil.which("node") is None:
        pytest.skip("Node.js required for real ELK")
    graph = diagram()
    web = Path(__file__).resolve().parents[2] / "src/flexsoc/backend/dv/rtl_viewer/web"
    script = r"""
const fs=require('node:fs'),assert=require('node:assert/strict');
const web=process.argv[1],graph=JSON.parse(fs.readFileSync(0,'utf8'));
const ELK=require(web+'/elk.bundled.js').default;
const adapter=require(web+'/elk-adapter.js'),geo=require(web+'/symbol-geometry.js');
(async()=>{
 const layout=await adapter.compute(new ELK(),graph,geo.boxSize);
 const targets=['tx_cfg_mac','tx_ack_mac'];
 for(const name of targets){
  const node=graph.nodes.find(n=>n.name===name);
  const d=graph.edges.find(e=>e.target===node.id&&e.targetPin==='D'&&e.rendered);
  assert(d,'missing D '+name);
  const mux=graph.nodes.find(n=>n.id===d.source);
  const s=graph.edges.find(e=>e.target===mux.id&&e.pin==='S'&&e.rendered);
  assert(s,'missing S '+name);
  for(const [edge,sym] of [[d,node],[s,mux]]){
   const path=layout.edgePaths.get(edge.id);
   assert(path&&path.length>=2,'missing ELK path '+edge.id);
   const box=layout.positions.get(sym.id);
   const anchor=geo.absoluteAnchor(sym,box,'target',edge);
   assert.deepEqual(path.at(-1),[anchor.x,anchor.y]);
  }
 }
})().catch(e=>{console.error(e);process.exitCode=1});
"""
    result = subprocess.run(["node", "-e", script, str(web)], input=json.dumps(graph),
                            text=True, capture_output=True, timeout=45)
    assert result.returncode == 0, result.stdout + result.stderr


def test_audit_exposes_unresolved_d_coverage_without_fabricating_connections():
    ast = json.loads(FIXTURE.read_text())
    design = RtlDesign(ast, root=FIXTURE.parent, top="top")
    audit = design.audit()
    d = audit["totals"]["d_inputs"]
    assert d["total"] >= 5
    assert d["routed"] >= 4
    assert d["total"] == d["routed"] + d["unresolved"]
    assert audit["scopes"][0]["d_inputs"]["total"] == d["total"]
