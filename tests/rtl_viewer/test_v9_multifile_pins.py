"""Cross-file source mapping and pin-accurate schematic geometry.

This is an AST contract fixture, not a substitute for real slang elaboration.
The optional e2e test below uses the actual SystemVerilog sources.
"""
from __future__ import annotations

import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign, SlangProject


ROOT = Path(__file__).resolve().parents[2] / "examples/rtl_schematic_dsp_system"
FILES = (
    "dsp_ops_pkg.sv", "dsp_coeff_bank.sv", "dsp_mul_lane.sv",
    "dsp_mac_array.sv", "dsp_alu.sv", "dsp_round_sat.sv",
    "dsp_control.sv", "dsp_system.sv",
)


def location(file: str, line: int = 5) -> dict:
    return {"sourceRange": {"start": {"file": file, "line": line}}}


def signal(name: str, addr: int, file: str, direction: str = "", kind: str = "Variable") -> dict:
    return {"kind": kind, "name": name, "addr": addr, "type": "logic [15:0]",
            "direction": direction, **location(file)}


def reference(addr: int, name: str = "misleading") -> dict:
    return {"kind": "NamedValue", "symbol": f"{addr} {name}"}


def child(name: str, module: str, file: str, ports: list[dict], bindings: list[tuple[str, int]]) -> dict:
    return {"kind": "Instance", "name": name,
            # The *instantiation site* is not the definition to open in RTL.
            **location("dsp_system.sv", 53),
            "body": {"kind": "InstanceBody", "name": module, "members": ports,
                     **location("dsp_system.sv", 55)},
            "connections": [{"port": port, "expression": reference(addr)} for port, addr in bindings]}


def fixture_design() -> RtlDesign:
    # Names are intentionally all different across parent/child boundaries.
    alu = child("u_arithmetic", "dsp_alu", "dsp_alu.sv", [
        signal("mac_i", 801, "dsp_alu.sv", "In", "Port"),
        signal("offset_i", 802, "dsp_alu.sv", "In", "Port"),
        signal("bypass_i", 803, "dsp_alu.sv", "In", "Port"),
        signal("chosen_o", 804, "dsp_alu.sv", "Out", "Port"),
        signal("opcode_i", 807, "dsp_alu.sv", "In", "Port"),
    ], [("mac_i", 101), ("offset_i", 102), ("bypass_i", 103),
        ("chosen_o", 104), ("opcode_i", 106)])
    # An AST contract excerpt of the *actual* named signals and MUX equation
    # in dsp_alu.sv; still not compiled by Slang in this environment.
    alu["body"]["members"].extend([
        signal("offset_ext", 805, "dsp_alu.sv"),
        signal("arith_d", 806, "dsp_alu.sv"),
        {"kind": "ContinuousAssign", "assignment": {"kind": "Assignment",
            "left": reference(805), "right": {"kind": "Conversion", "operand": reference(802)}}},
        {"kind": "CaseStatement", "expression": reference(807), "items": [
            {"kind": "CaseItem", "body": {"kind": "Assignment",
                "left": reference(806), "right": {"kind": "BinaryOp", "op": "Add",
                "left": reference(801), "right": reference(805)}}}
        ]},
        {"kind": "ContinuousAssign", "assignment": {
            "kind": "Assignment", "left": reference(804),
            "right": {"kind": "ConditionalOp", "condition": reference(803),
                      "left": reference(805), "right": reference(806)}}}
    ])
    result = child("u_output", "dsp_round_sat", "dsp_round_sat.sv", [
        signal("data_i", 811, "dsp_round_sat.sv", "In", "Port"),
        signal("data_o", 812, "dsp_round_sat.sv", "Out", "Port"),
    ], [("data_i", 104), ("data_o", 105)])
    root_members = [
        signal("parallel_sum", 101, "dsp_system.sv"),
        signal("external_offset", 102, "dsp_system.sv"),
        signal("external_bypass", 103, "dsp_system.sv"),
        signal("operation", 106, "dsp_system.sv"),
        signal("alu_result", 104, "dsp_system.sv"),
        signal("final_output", 105, "dsp_system.sv", "Out", "Port"),
        alu, result,
    ]
    top = {"kind": "Instance", "name": "dsp_system", "body": {
        "kind": "InstanceBody", "name": "dsp_system", "members": root_members}}
    return RtlDesign({"design": {"kind": "Root", "members": [top]}}, root=ROOT, top="dsp_system")


def test_source_files_follow_definition_not_instantiation():
    design = fixture_design()
    assert design.source("/")["file"] == "dsp_system.sv"
    assert design.source("/u_arithmetic")["file"] == "dsp_alu.sv"
    assert design.source("/u_output")["file"] == "dsp_round_sat.sv"
    assert set(design.overview()["sourceFiles"]) == {"dsp_system.sv", "dsp_alu.sv", "dsp_round_sat.sv"}
    for path in ("/", "/u_arithmetic", "/u_output"):
        assert design.source(path)["status"] == "available"
        assert "module " in design.source(path)["code"]


def test_parent_to_child_bindings_and_source_selection():
    design = fixture_design()
    graph = design.diagram()
    edges = {(e["source"], e["target"], e["port"]) for e in graph["edges"]}
    assert ("/::sig:parallel_sum", "/::inst:/u_arithmetic", "mac_i") in edges
    assert ("/::inst:/u_arithmetic", "/::sig:alu_result", "chosen_o") in edges
    assert ("/::sig:alu_result", "/::inst:/u_output", "data_i") in edges
    assert ("/::inst:/u_output", "/::sig:final_output", "data_o") in edges
    assert design.follow("/", "/u_output", "/::sig:alu_result")["signal_id"] == "/u_output::sig:data_i"
    assert design.cone("/", "/::sig:parallel_sum", "/::sig:final_output")["status"] == "resolved"
    assert not graph["connectivity"]["unbound_pins"]


def mux_semantic_graph():
    members = [
        signal("mux_false", 11, "dsp_alu.sv"),
        signal("mux_true", 12, "dsp_alu.sv"),
        signal("select", 13, "dsp_alu.sv"),
        signal("selected", 14, "dsp_alu.sv"),
        {"kind": "ContinuousAssign", "assignment": {"kind": "Assignment",
            "left": reference(14), "right": {"kind": "ConditionalOp",
                "condition": reference(13), "left": reference(12), "right": reference(11)}}},
    ]
    ast = {"design": {"kind": "Root", "members": [{"kind": "Instance", "name": "dsp_alu",
        "body": {"kind": "InstanceBody", "name": "dsp_alu", "members": members}}]}}
    graph = RtlDesign(ast, root=ROOT, top="dsp_alu").diagram()
    mux = next(n for n in graph["nodes"] if n.get("shape") == "mux")
    assert mux["pins"] == ["A", "B", "S", "Y"]
    connections = {(e["source"].split("::sig:")[-1], e["pin"])
                   for e in graph["edges"] if e["target"] == mux["id"]}
    assert connections == {("mux_false", "A"), ("mux_true", "B"), ("select", "S")}
    assert any(e["source"] == mux["id"] and e["target"] == "/::sig:selected" for e in graph["edges"])
    return graph


def test_mux_semantic_input_roles():
    mux_semantic_graph()


@pytest.mark.skipif(shutil.which("node") is None, reason="Node.js required for JS router")
def test_router_draws_selector_from_bottom_not_as_data(tmp_path):
    graph = mux_semantic_graph()
    graph_path = tmp_path / "graph.json"
    graph_path.write_text(json.dumps(graph), encoding="utf-8")
    router = Path(__file__).resolve().parents[2] / "src/flexsoc/backend/dv/rtl_viewer/web/router.js"
    script = r"""
const fs = require('fs'), router = require(process.argv[1]);
const graph = JSON.parse(fs.readFileSync(process.argv[2]));
const result = router.compute(graph, {boxSize:router.boxSize,baseRank:router.baseRank});
const mux = graph.nodes.find(n=>n.shape==='mux');
const rect = result.positions.get(mux.id);
const roles = {};
for(const edge of graph.edges.filter(e=>e.target===mux.id)){
 const points = result.edgePaths.get(edge.id);
 const expected = router.pinGeometry(mux,rect,edge.pin,'in');
 const actual = points[points.length-1];
 if(Math.abs(actual[0]-expected.x)>0.01 || Math.abs(actual[1]-expected.y)>0.01)
   throw Error('wrong endpoint for '+edge.pin+': '+actual+' != '+JSON.stringify(expected));
 if(edge.pin==='S' && (points[points.length-2][0]!==actual[0] || points[points.length-2][1]<=actual[1]))
   throw Error('selector must enter from bottom: '+JSON.stringify(points));
 roles[edge.pin] = actual;
}
if(new Set(Object.keys(roles)).size !== 3 || roles.A[1]===roles.B[1] || roles.B[1]===roles.S[1])
 throw Error('pin roles overlapped');
console.log(JSON.stringify(roles));
"""
    proc = subprocess.run(["node", "-e", script, str(router), str(graph_path)],
                          capture_output=True, text=True, timeout=12)
    assert proc.returncode == 0, proc.stderr


@pytest.mark.e2e
@pytest.mark.skipif(shutil.which("slang") is None, reason="upstream slang is not installed")
def test_elaborate_actual_multifile_dsp_and_source_links(tmp_path):
    project = SlangProject(ROOT, "dsp_system", tuple(Path(name) for name in FILES),
                           expand_cached_instances=True)
    payload = json.loads(project.compile(tmp_path / "dsp_system.ast.json").read_text())
    design = RtlDesign(payload, root=ROOT, top="dsp_system", verified=True)
    assert len(design.scopes) == 6 + 8  # top + five child modules + eight generated lanes
    assert set(FILES[1:]).issuperset({Path(design.source(path)["file"]).name
                                   for path in design.scopes if design.source(path)["status"] == "available"})
    assert all(design.source(path)["status"] == "available" for path in design.scopes)
    graph = design.diagram()
    assert not graph["connectivity"]["unbound_pins"]
    assert len([n for n in graph["nodes"] if n["type"] == "instance"]) == 5

@pytest.mark.skipif(shutil.which("node") is None, reason="Node.js required for JS router")
def test_backward_driver_enters_functional_pin_from_correct_face(tmp_path):
    router = Path(__file__).resolve().parents[2] / "src/flexsoc/backend/dv/rtl_viewer/web/router.js"
    script = r"""
const r=require(process.argv[1]);
const graph={nodes:[
 {id:'driver',type:'port',direction:'out',name:'late_signal'},
 {id:'mux',type:'operator',name:'select',shape:'mux'},
 {id:'sink',type:'port',direction:'out',name:'target'}],
 edges:[{id:'e',source:'driver',target:'mux',pin:'A',net:'late_signal',type:'data',mapping:'direct'},
        {id:'y',source:'mux',target:'sink',net:'target',type:'data',mapping:'direct'}]};
const out=r.compute(graph,{boxSize:r.boxSize,baseRank:r.baseRank});
const driver=out.positions.get('driver'),mux=out.positions.get('mux');
if(!(driver.x>mux.x))throw Error('fixture is not a reverse connection');
const path=out.edgePaths.get('e'),last=path[path.length-1],prior=path[path.length-2];
const p=r.pinGeometry(graph.nodes[1],mux,'A','in');
if(last[0]!==p.x||last[1]!==p.y||prior[0]>=p.x||prior[1]!==p.y)
 throw Error('data pin A was approached from wrong face: '+JSON.stringify(path));
"""
    proc = subprocess.run(["node", "-e", script, str(router)], capture_output=True, text=True, timeout=12)
    assert proc.returncode == 0, proc.stderr


def test_full_audit_identifies_unverified_fixture_and_source_links():
    design = fixture_design()
    report = design.audit()
    assert report["totals"]["missing_sources"] == 0
    assert report["totals"]["unbound_pins"] == 0
    assert report["totals"]["unresolved_pins"] == 0
    assert report["elaboration_verified"] is False
    assert report["qualified"] is False  # Fixture != Slang compilation.
    assert {s["file"] for s in report["scopes"]} == {"dsp_system.sv", "dsp_alu.sv", "dsp_round_sat.sv"}


def test_binary_arithmetic_has_distinct_A_B_inputs():
    ast = {"design": {"kind": "Root", "members": [{"kind": "Instance", "name": "alu",
        "body": {"kind": "InstanceBody", "name": "alu", "members": [
            signal("lhs", 1011, "dsp_alu.sv"), signal("rhs", 1012, "dsp_alu.sv"),
            signal("sum", 1013, "dsp_alu.sv"),
            {"kind": "ContinuousAssign", "assignment": {"kind": "Assignment", "left": reference(1013),
                "right": {"kind": "BinaryOp", "op": "Add", "left": reference(1011), "right": reference(1012)}}}
        ]}}]}}
    graph = RtlDesign(ast, root=ROOT, top="alu").diagram()
    operator = next(n for n in graph["nodes"] if n["type"] == "operator")
    assert operator["pins"] == ["A", "B", "Y"]
    assert {(e["source"], e["pin"]) for e in graph["edges"] if e["target"] == operator["id"]} == {
        ("/::sig:lhs", "A"), ("/::sig:rhs", "B")}


def test_example_filelist_contains_all_real_sv_sources():
    files = tuple(line.strip() for line in (ROOT / "files.f").read_text().splitlines() if line.strip())
    assert files == FILES
    assert all((ROOT / name).is_file() for name in files)
    project = SlangProject(ROOT, "dsp_system", tuple(Path(name) for name in FILES))
    assert len(project.files) == 8
    assert SlangProject(ROOT, "dsp_system", filelists=(Path("files.f"),)).filelists
