"""Compiler-backed process boundaries and actual ELK compound containment.

A continuous assign is external to an always_comb. Its value must enter the
process as an INPUT terminal. Flattening never puts other circuits inside the
process rectangle, nor rewrites an original edge or pin identity.
"""
from __future__ import annotations

import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def _ast():
    def ref(index):
        return {"kind": "NamedValue", "symbol": f"{index} member"}
    members = [
        {"kind": "Variable", "name": name, "addr": addr}
        for addr, name in enumerate(("clk", "arg", "external_value", "out", "q", "outside"), 1)
    ]
    members += [
        {"kind": "Subroutine", "name": "decode", "addr": 99,
         "subroutineKind": "Function", "returnType": "logic",
         "members": [{"kind": "FormalArgument", "name": "value", "direction": "In"}],
         "body": {"kind": "List", "list": []}},
        {"kind": "ContinuousAssign", "left": ref(3),
         "right": {"kind": "Call", "subroutine": "99 decode", "type": "logic",
                   "arguments": [ref(2)]}},
        {"kind": "ProceduralBlock", "procedureKind": "AlwaysComb", "source_line": 30,
         "body": {"kind": "Block", "body": {"kind": "List", "list": [
             {"kind": "Assignment", "left": ref(4),
              "right": {"kind": "BinaryOp", "op": "Add", "left": ref(3),
                        "right": {"kind": "IntegerLiteral", "type": "logic", "value": "1'b1"}}}
         ]}}},
        {"kind": "ProceduralBlock", "procedureKind": "AlwaysFF", "source_line": 40,
         "body": {"kind": "Timed", "timing": {"kind": "SignalEvent", "edge": "PosEdge", "expr": ref(1)},
                  "stmt": {"kind": "Assignment", "left": ref(5), "right": ref(4),
                           "isNonBlocking": True}}},
        {"kind": "ContinuousAssign", "left": ref(6), "right": ref(5)},
    ]
    return {"design": {"members": [{"kind": "Instance", "name": "demo",
        "body": {"kind": "InstanceBody", "name": "demo", "members": members}}]}}


def test_external_function_stays_outside_combinational_process():
    graph = RtlDesign(_ast(), root=Path.cwd(), top="demo").diagram(limit=128)
    functions = [n for n in graph["nodes"] if n.get("shape") == "function"]
    assert len(functions) == 1 and functions[0]["function"]["name"] == "decode"
    group = next(g for g in graph["processGroups"] if g["kind"] == "always_comb")
    assert functions[0]["id"] not in group["memberIds"]
    input_node = next(n for n in graph["nodes"] if n["name"] == "external_value")
    assert input_node["id"] in group["inputIds"]
    assert any(e["source"] == functions[0]["id"] and e["target"] == input_node["id"]
               and e["rendered"] for e in graph["edges"])


@pytest.mark.skipif(not shutil.which('node'), reason='Node.js needed for ELK test')
def test_compact_focus_and_flatten_preserve_process_inputs_and_compound_bounds(tmp_path):
    graph = RtlDesign(_ast(), root=Path.cwd(), top="demo").diagram(limit=128)
    path = tmp_path / 'graph.json'
    path.write_text(json.dumps(graph))
    js = r'''
const assert = require('node:assert/strict');
const fs = require('node:fs');
const root = process.argv[1];
const graph = JSON.parse(fs.readFileSync(process.argv[2], 'utf8'));
const VP = require(root+'/virtual-process.js');
const A = require(root+'/elk-adapter.js');
const G = require(root+'/symbol-geometry.js');
const ELK = require(root+'/elk.bundled.js').default;
const comb = graph.processGroups.find(g=>g.kind==='always_comb');
const ff = graph.processGroups.find(g=>g.kind==='always_ff');
const call = graph.nodes.find(n=>n.shape==='function');
const external = graph.nodes.find(n=>n.name==='external_value');
const focused = VP.focus(graph,comb.token);
const boundary = focused.nodes.find(n=>n.id===external.id);
assert.equal(boundary.type,'port');
assert.equal(boundary.direction,'in');
assert.equal(boundary.boundaryOriginalType,'signal');
assert.equal(focused.nodes.some(n=>n.id===call.id),false,
 'continuous-assignment function must NOT be inside always_comb');
assert(focused.edges.some(e=>e.source===external.id&&
 focused.nodes.some(n=>n.id===e.target&&n.type==='operator')));
const compact = VP.project(graph);
const box = compact.nodes.find(n=>n.group===comb.token);
assert(box.ports.some(p=>p.direction==='input'&&p.name.includes('external_value')&&
 p.connection==='bound'),'external result must have an input on the compact process');
assert(compact.edges.some(e=>e.source===external.id&&e.target===box.id&&
 e.targetPin.includes('external_value')));
const flattened = VP.project(graph,[comb.token,ff.token]);
assert(flattened.edges.every(e=>graph.edges.some(original=>original.id===e.id)));
assert(!flattened.nodes.some(n=>n.type==='process_group'));
(async()=>{
 const layout=await A.compute(new ELK(),flattened,G.boxSize);
 const ids=new Set(flattened.nodes.map(n=>n.id));
 assert.equal(layout.positions.size,ids.size);
 const edgeIds=new Set(flattened.edges.filter(e=>e.rendered!==false).map(e=>e.id));
 assert.equal(layout.edgePaths.size,edgeIds.size);
 const byId=new Map(flattened.nodes.map(n=>[n.id,n]));
 for(const g of [comb,ff]){
  const r=layout.groupRects.get(g.token);
  assert(r&&r.w>0&&r.h>0,'ELK must return a real compound rectangle');
  const owned=new Set(g.memberIds);
  for(const n of flattened.nodes){
   const pos=layout.positions.get(n.id);
   const enclosed=pos.x>=r.x-0.01&&pos.y>=r.y-0.01&&
      pos.x+pos.w<=r.x+r.w+0.01&&pos.y+pos.h<=r.y+r.h+0.01;
   assert.equal(enclosed,owned.has(n.id),
    'flatten frame wrongly contains an external symbol: '+n.name);
  }
 }
 assert.deepEqual(A.checkCompoundOwnership(flattened,layout),[]);
 const first=layout.groupRects.get(comb.token);
 const malformed={...layout,groupRects:new Map(layout.groupRects)};
 malformed.groupRects.set(comb.token,{x:first.x-100000,y:first.y-100000,
  w:first.w+200000,h:first.h+200000});
 assert(A.checkCompoundOwnership(flattened,malformed).some(x=>
  x.startsWith('false flattened ownership')),
  'audit must reject a frame enclosing unrelated cells');
 for(const e of flattened.edges.filter(e=>e.rendered!==false)){
  const path=layout.edgePaths.get(e.id);
  assert(path?.length>=2,'missing wire '+e.id);
  for(const [role,index] of [['source',0],['target',path.length-1]]){
   const pos=layout.positions.get(e[role]);
   const anchor=G.absoluteAnchor(byId.get(e[role]),pos,role,e);
   assert(Math.hypot(path[index][0]-anchor.x,path[index][1]-anchor.y)<.001,
    'ELK/Canvas terminal mismatch: '+e.id);
  }
 }
 // Virtual FSM focus may contain only part of an owned process cone.
 // The flattened compound must enclose ONLY the visible subset, and must
 // never silently claim nodes removed by the parent view.
 const missing=comb.memberIds.at(-1);
 const sliced={...graph,nodes:graph.nodes.filter(n=>n.id!==missing),
  edges:graph.edges.filter(e=>e.source!==missing&&e.target!==missing)};
 const partial=VP.project(sliced,[comb.token],{allowPartial:true});
 const g=partial.processGroups.find(g=>g.token===comb.token);
 assert.equal(g.coverage,'fragment');
 assert(g.originalMemberIds.includes(missing));
 assert(!g.memberIds.includes(missing));
 const inner=await A.compute(new ELK(),partial,G.boxSize);
 assert(inner.groupRects.has(comb.token));
 assert.deepEqual(A.checkCompoundOwnership(partial,inner),[]);
 console.log('COMPOUND PROCESS CONTRACT PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    result = subprocess.run(['node', '-e', js, str(WEB), str(path)],
                            text=True, capture_output=True, timeout=55)
    assert result.returncode == 0, result.stdout + result.stderr
    assert 'COMPOUND PROCESS CONTRACT PASS' in result.stdout
