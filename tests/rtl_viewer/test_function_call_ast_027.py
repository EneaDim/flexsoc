"""Compiler-backed function calls are opaque value nodes, never inferred gates.

The Ethernet fixture includes an authentic Slang gray_of_increment Subroutine
and the genuine always_ff Call expressions from ethernet_core.sv.
"""
from __future__ import annotations

import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

HERE = Path(__file__).parent
FIXTURE = HERE / "fixtures/ethernet_function_call_slang_027.json"
WEB = HERE.parents[1] / "src/flexsoc/backend/dv/rtl_viewer/web"


def model(ast=None):
    return RtlDesign(ast or json.loads(FIXTURE.read_text()), root=HERE, top="top")


def d_paths(graph, name):
    target = next(n for n in graph["nodes"] if n["name"] == name)
    return [e for e in graph["edges"] if e["target"] == target["id"]
            and e["targetPin"] == "D" and e["rendered"]]


def test_real_ethernet_slang_function_call_routes_argument_to_mux_and_d():
    graph = model().diagram()
    nodes = {n["id"]: n for n in graph["nodes"]}
    for target, source in (("rx_bad_event_gray", "rx_bad_event_bin"),
                           ("rx_fcs_event_gray", "rx_fcs_event_bin")):
        driver = d_paths(graph, target)
        assert len(driver) == 1
        mux = nodes[driver[0]["source"]]
        assert mux["shape"] == "mux"
        function_edge = next(e for e in graph["edges"] if e["target"] == mux["id"]
                             and nodes[e["source"]].get("kind") == "Call" and e["rendered"])
        call = nodes[function_edge["source"]]
        assert call["shape"] == "function"
        assert call["function"]["name"] == "gray_of_increment"
        assert call["function"]["arguments"] == ["current"]
        assert call["function"]["definitionLine"] == 249
        assert call["function"]["returnType"] == "logic[31:0]"
        assert call["pins"] == ["I0", "Y"]
        incoming = [e for e in graph["edges"] if e["target"] == call["id"] and e["rendered"]]
        assert len(incoming) == 1 and incoming[0]["pin"] == "I0"
        assert incoming[0]["source"] == "/::sig:" + source
        assert incoming[0]["mapping"] == "direct"
        assert function_edge["sourcePin"] == "Y"
    assert len([n for n in graph["nodes"] if n.get("kind") == "Call"]) == 2


def test_unknown_or_invalid_calls_never_gain_fabricated_d_connection():
    baseline = json.loads(FIXTURE.read_text())
    members = baseline["design"]["members"][0]["body"]["members"]
    definitions = [m for m in members if m.get("kind") == "Subroutine"]
    assert len(definitions) == 1
    for variant in ("missing", "task", "output_formal", "extra_arg", "void_return"):
        ast = json.loads(FIXTURE.read_text())
        items = ast["design"]["members"][0]["body"]["members"]
        definition = next(m for m in items if m.get("kind") == "Subroutine")
        if variant == "missing":
            items.remove(definition)
        elif variant == "task":
            definition["subroutineKind"] = "Task"
        elif variant == "output_formal":
            definition["members"][0]["direction"] = "Out"
        elif variant == "extra_arg":
            stack = [m for m in items if m.get("kind") == "ProceduralBlock"]
            for n in iter_ast(stack):
                if n.get("kind") == "Call" and str(n.get("subroutine", "")).endswith("gray_of_increment"):
                    n["arguments"].append({"kind": "IntegerLiteral", "value": "1'b0"})
        elif variant == "void_return":
            definition["returnType"] = "void"
        g = model(ast).diagram()
        assert not [n for n in g["nodes"] if n.get("kind") == "Call"], variant
        assert not d_paths(g, "rx_bad_event_gray"), variant
        assert not d_paths(g, "rx_fcs_event_gray"), variant


def iter_ast(nodes):
    todo = [nodes]
    while todo:
        value = todo.pop()
        if isinstance(value, dict):
            yield value
            todo.extend(value.values())
        elif isinstance(value, list):
            todo.extend(value)


def test_multiple_arguments_have_distinct_ordered_function_pins():
    ast = {"design": {"members": [{"kind": "Instance", "name": "top", "body": {
        "kind": "InstanceBody", "name": "top", "members": [
            *({"kind": "Variable", "name": n, "addr": a} for n, a in (("a", 1), ("b", 2), ("y", 3))),
            {"kind": "Subroutine", "addr": 99, "name": "combine", "subroutineKind": "Function",
             "returnType": "logic", "body": {"kind": "List", "list": []},
             "members": [{"kind": "FormalArgument", "name": n, "direction": "In"} for n in ("lhs", "rhs")]},
            {"kind": "ContinuousAssign", "left": {"kind": "NamedValue", "symbol": "3 y"},
             "right": {"kind": "Call", "subroutine": "99 combine", "type": "logic",
                       "arguments": [{"kind": "NamedValue", "symbol": "1 a"},
                                     {"kind": "NamedValue", "symbol": "2 b"}]}}
        ]}}]}}
    graph = model(ast).diagram()
    node = next(n for n in graph["nodes"] if n.get("kind") == "Call")
    assert node["pins"] == ["I0", "I1", "Y"]
    assert node["function"]["arguments"] == ["lhs", "rhs"]
    assert {(e["source"], e["pin"]) for e in graph["edges"]
            if e["target"] == node["id"] and e["rendered"]} == {
                ("/::sig:a", "I0"), ("/::sig:b", "I1")}
    assert any(e["source"] == node["id"] and e["target"] == "/::sig:y" and e["rendered"]
               for e in graph["edges"])


@pytest.mark.skipif(not shutil.which("node"), reason="Node.js needed for bundled ELK")
def test_real_elk_function_pins_match_canvas_geometry():
    graph = model().diagram()
    js = r'''
const fs=require('node:fs'),assert=require('node:assert/strict');
const graph=JSON.parse(fs.readFileSync(0,'utf8')),root=process.argv[1];
const Geo=require(root+'/symbol-geometry.js');
const E=require(root+'/elk-adapter.js');
const ELK=require(root+'/elk.bundled.js').default;
(async()=>{
 const result=await E.compute(new ELK(),graph,Geo.boxSize);
 let count=0;
 for(const edge of graph.edges.filter(e=>e.rendered!==false)){
  const src=graph.nodes.find(n=>n.id===edge.source);
  const dst=graph.nodes.find(n=>n.id===edge.target);
  if(src?.shape!=='function'&&dst?.shape!=='function')continue;
  const line=result.edgePaths.get(edge.id);
  assert(line&&line.length>=2,edge.id);
  if(dst.shape==='function'){
   const pin=Geo.absoluteAnchor(dst,result.positions.get(dst.id),'target',edge);
   assert.deepEqual(line.at(-1),[pin.x,pin.y]);
  }
  if(src.shape==='function'){
   const pin=Geo.absoluteAnchor(src,result.positions.get(src.id),'source',edge);
   assert.deepEqual(line[0],[pin.x,pin.y]);
  }
  count++;
 }
 assert(count>=4);
 console.log('ELK function terminals '+count);
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    completed = subprocess.run(["node", "-e", js, str(WEB)], input=json.dumps(graph),
                               text=True, capture_output=True, timeout=45)
    assert completed.returncode == 0, completed.stdout + completed.stderr
    assert "ELK function terminals" in completed.stdout
