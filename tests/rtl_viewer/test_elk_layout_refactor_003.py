"""ELK/Canvas layout regression: deterministic ports, bidirectional pins, wire hops.

Node tests use the shipped ELK runtime, not a fake layout engine. These are
geometric checks only; Slang provenance/connectivity have independent tests.
"""
from pathlib import Path
import shutil
import subprocess

import pytest

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_real_elk_multioutput_same_net_and_reordered_ast():
    if not shutil.which('node'):
        pytest.skip('Node.js is not installed')
    script = r'''
const assert=require('node:assert/strict');
const W=process.argv[1],ELK=require(W+'/elk.bundled.js').default;
const G=require(W+'/symbol-geometry.js'),A=require(W+'/elk-adapter.js');
const L=require(W+'/layout-engine.js');
const nodes=[
 {id:'mod',type:'instance',ports:[{name:'a',direction:'out'},
   {name:'b',direction:'output'},{name:'io',direction:'inout'},
   {name:'clk',direction:'in'}]},
 {id:'source',type:'port',direction:'input'},
 {id:'tapA',type:'signal'},{id:'tapB',type:'signal'},
 {id:'both',type:'port',direction:'inout'},
 {id:'sink',type:'port',direction:'output'}
];
const edges=[
 {id:'a',source:'mod',target:'tapA',port:'a',net:'shared'},
 {id:'b',source:'mod',target:'tapB',port:'b',net:'shared'},
 {id:'inout-source',source:'mod',target:'both',port:'io',net:'shared'},
 {id:'inout-target',source:'both',target:'mod',port:'io',net:'shared'},
 {id:'clock',source:'source',target:'mod',port:'clk',net:'clock'},
 {id:'output',source:'tapA',target:'sink',net:'tapa'}
];
const graph={nodes,edges};const before=JSON.stringify(graph);
const input=A.convert(graph,G.boxSize);
assert.deepEqual(input.children.map(n=>n.id),nodes.map(n=>n.id).sort());
assert.deepEqual(input.edges.map(e=>e.id),edges.map(e=>e.id).sort());
const module=input.children.find(n=>n.id==='mod');
const eA=edges.find(e=>e.id==='a'),eB=edges.find(e=>e.id==='b');
const pA=module.ports.find(p=>p.id===module.id+':source:'+encodeURIComponent(A.pinKey(eA,'source')));
const pB=module.ports.find(p=>p.id===module.id+':source:'+encodeURIComponent(A.pinKey(eB,'source')));
assert(pA&&pB,'both separately named source pins must exist');
assert.notEqual(pA.id,pB.id);
assert.notEqual(pA.y,pB.y,'distinct output rows');
const io=G.portRows(nodes[0],'source').filter(p=>p.port.name==='io');
const ioIn=G.portRows(nodes[0],'target').filter(p=>p.port.name==='io');
assert.equal(io.length,1);assert.equal(ioIn.length,1);
assert.equal(io[0].x,G.boxSize(nodes[0]).w);assert.equal(ioIn[0].x,0);
assert.equal(G.anchor(nodes[4],'source',edges[3]).side,'EAST');
assert.equal(G.anchor(nodes[4],'target',edges[2]).side,'WEST');
(async()=>{
 const elk=new ELK(),first=await A.compute(elk,graph,G.boxSize);
 const reordered={nodes:nodes.toReversed(),edges:edges.toReversed()};
 const second=await A.compute(elk,reordered,G.boxSize);
 const snapshot=g=>JSON.stringify({p:[...g.positions].sort(),r:[...g.edgePaths].sort()});
 assert.equal(snapshot(first),snapshot(second),'same layout independent of AST enumeration');
 assert.deepEqual(L.validate(graph,first),{ok:true,errors:[]});
 for(const e of edges){
   const path=first.edgePaths.get(e.id);
   const from=G.absoluteAnchor(nodes.find(n=>n.id===e.source),first.positions.get(e.source),'source',e);
   const to=G.absoluteAnchor(nodes.find(n=>n.id===e.target),first.positions.get(e.target),'target',e);
   assert(Math.abs(path[0][0]-from.x)<.001&&Math.abs(path[0][1]-from.y)<.001,'source pin '+e.id);
   assert(Math.abs(path.at(-1)[0]-to.x)<.001&&Math.abs(path.at(-1)[1]-to.y)<.001,'target pin '+e.id);
 }
 assert.equal(JSON.stringify(graph),before,'layout must not mutate RTL graph');
 console.log('REAL ELK MULTI-OUTPUT PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    proc = subprocess.run(['node', '-e', script, str(WEB)], capture_output=True,
                          text=True, timeout=45)
    assert proc.returncode == 0, proc.stdout + proc.stderr
    assert 'REAL ELK MULTI-OUTPUT PASS' in proc.stdout


def test_crossings_are_decorative_and_only_on_distinct_nets():
    if not shutil.which('node'):
        pytest.skip('Node.js is not installed')
    script = r'''
const assert=require('node:assert/strict');
const L=require(process.argv[1]+'/layout-engine.js');
const edges=[{id:'horizontal',source:'a',target:'b',net:'H'},
             {id:'vertical',source:'c',target:'d',net:'V'}];
const base={edgePaths:new Map([
 ['horizontal',[[0,50],[100,50]]],
 ['vertical',[[50,0],[50,100]]]
])};
const graph={edges};
assert.deepEqual(L.crossingBridges(graph,base),
 {bridges:[{edge:'horizontal',x:50,y:50}],limited:false});
assert.deepEqual(L.crossingBridges({edges:edges.toReversed()},base),
 L.crossingBridges(graph,base),'permutation invariant');
assert.deepEqual(L.crossingBridges({edges:[{...edges[0],net:'same'},{...edges[1],net:'same'}]},base).bridges,[],
 'same-net wires never gain an invented bridge');
assert.deepEqual(L.crossingBridges(graph,{edgePaths:new Map([
 ['horizontal',[[0,50],[50,50]]],['vertical',[[50,0],[50,100]]]])}).bridges,[],
 'endpoint contact is not an interior crossing');
assert.equal(L.crossingBridges(graph,base,{limit:1}).limited,true);
assert.equal(typeof L.separateLanes,'undefined','obsolete alternative router removed');
assert.equal(typeof globalThis.FlexNetTree,'undefined','obsolete custom net-tree removed');
console.log('CROSSING GEOMETRY PASS');
'''
    proc = subprocess.run(['node', '-e', script, str(WEB)], capture_output=True,
                          text=True, timeout=10)
    assert proc.returncode == 0, proc.stdout + proc.stderr


def test_bounded_semantic_input_conversion_on_large_graph():
    if not shutil.which('node'):
        pytest.skip('Node.js is not installed')
    script = r'''
const assert=require('node:assert/strict');
const A=require(process.argv[1]+'/elk-adapter.js');
const nodes=Array.from({length:900},(_,i)=>({id:'n'+String(i).padStart(4,'0'),type:'signal'}));
const edges=Array.from({length:3600},(_,i)=>({id:'e'+String(i).padStart(4,'0'),
 source:nodes[i%900].id,target:nodes[(i*7+23)%900].id,net:'net'+i}));
const g={nodes,edges};let calls=0;
const input=A.convert(g,n=>{calls++;return {w:120,h:40}});
assert.equal(calls,nodes.length);
assert.equal(input.children.length,nodes.length);
assert.equal(input.edges.length,edges.length);
assert.equal(new Set(input.edges.map(e=>e.id)).size,edges.length);
console.log('BOUNDED GRAPH CONVERSION PASS');
'''
    proc = subprocess.run(['node', '-e', script, str(WEB)], capture_output=True,
                          text=True, timeout=15)
    assert proc.returncode == 0, proc.stdout + proc.stderr
