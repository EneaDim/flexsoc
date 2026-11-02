"""FSRTL-022: compact unary glyphs share exact terminals with real ELK.

The field fixture is a preserved slice of the user's real Ethernet Slang AST.
No source-text inference or synthetic connectivity is involved.
"""
import json
import shutil
import subprocess
from pathlib import Path

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'
FIXTURE = Path(__file__).parent / 'fixtures' / 'ethernet_slang_members_021.json'


def node_test(script: str, data: str = '') -> None:
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    p = subprocess.run(['node', '-e', script, str(WEB)], input=data, text=True,
                       capture_output=True, timeout=40)
    assert p.returncode == 0, p.stdout + p.stderr


def test_unary_geometry_and_canvas_leads_are_consistent():
    node_test(r'''
const assert=require('node:assert/strict'),W=process.argv[1];
const G=require(W+'/symbol-geometry.js'),P=require(W+'/symbol-painter.js');
const palette={operator:'#f8b',symbolFill:'#233',pickedFill:'#344',text:'#fff',
 muted:'#9ab',selected:'#ffa',generate:'#ffb'};
const specimens=[
 {type:'operator',name:'FieldSelect',shape:'field',field:'phy_mii_select_i',pins:['A','Y']},
 {type:'operator',name:'Conversion',kind:'Conversion',pins:['A','Y']},
 {type:'operator',name:'UnaryBitwiseNot',kind:'UnaryOp',pins:['A','Y']},
 {type:'operator',name:'UnaryMinus',kind:'UnaryOp',pins:['A','Y']},
 {type:'operator',name:'Concatenation',kind:'Concatenation',pins:['IN','Y']}
];
function paint(n){
 const cmds=[],ctx={save(){},restore(){}};
 for(const m of ['beginPath','moveTo','lineTo','fill','stroke','arc','closePath',
  'roundRect','quadraticCurveTo','fillText'])ctx[m]=(...args)=>cmds.push([m,...args]);
 P.paint(ctx,n,{x:11,y:23,...G.boxSize(n)}, {colors:palette,zoom:1,names:true,edges:[]});
 return cmds;
}
for(const n of specimens){
 const size=G.boxSize(n),role=n.pins[0];
 const a=G.anchor(n,'target',{targetPin:role},size),o=G.anchor(n,'source',{sourcePin:'Y'},size);
 assert.deepEqual(a,{x:0,y:size.h/2,side:'WEST'},n.name);
 assert.deepEqual(o,{x:size.w,y:size.h/2,side:'EAST'},n.name);
 const tr=paint(n);
 assert(tr.some(c=>c[0]==='moveTo'&&c[1]===11&&c[2]===23+size.h/2),n.name+' missing centered lead');
 assert(tr.some(c=>c[0]==='lineTo'&&c[1]===11+size.w&&c[2]===23+size.h/2),n.name+' missing centered output');
}
assert(G.boxSize(specimens[0]).h<=34&&G.boxSize(specimens[0]).w<=126);
assert(G.boxSize(specimens[1]).h<=34&&G.boxSize(specimens[1]).w<=60);
// Multi-input operators keep separate terminals and mux select below the box.
const binary={type:'operator',name:'BinaryAnd',pins:['A','B','Y']};
const s=G.boxSize(binary);
assert(G.anchor(binary,'target',{targetPin:'A'},s).y < s.h/2);
assert(G.anchor(binary,'target',{targetPin:'B'},s).y > s.h/2);
const mux={type:'operator',shape:'mux',pins:['A','B','S','Y']};
assert.equal(G.anchor(mux,'target',{targetPin:'S'}).side,'SOUTH');
assert(paint(specimens[1]).some(c=>c[0]==='fillText'&&c[1]==='CAST'));
assert(paint(specimens[0]).some(c=>c[0]==='fillText'&&String(c[1]).includes('.phy_mii_select_i')));
''')


def test_real_ethernet_slang_fields_route_exactly_to_centered_pins(tmp_path):
    graph = RtlDesign(json.loads(FIXTURE.read_text()), root=tmp_path, top='top').diagram()
    node_test(r'''
const assert=require('node:assert/strict'),W=process.argv[1];
const G=require(W+'/symbol-geometry.js'),A=require(W+'/elk-adapter.js');
const ELK=require(W+'/elk.bundled.js').default;
const graph=JSON.parse(require('node:fs').readFileSync(0,'utf8'));
(async()=>{
 const nodes=new Map(graph.nodes.map(n=>[n.id,n]));
 const fields=graph.nodes.filter(n=>n.shape==='field');
 assert(fields.length>=2,'real Ethernet AST field nodes missing');
 const layout=await A.compute(new ELK(),graph,G.boxSize);
 let connectedInputs=0;
 for(const n of fields){
  const r=layout.positions.get(n.id);
  assert(r.h<=34&&r.w<=126,'compact FIELD size');
  const incoming=graph.edges.filter(e=>e.target===n.id&&e.rendered!==false);
  // Some compiler-backed field nodes have no separately routable base value;
  // do not invent a physical input just to fill the new centered stub.
  for(const e of incoming){
   connectedInputs++;
   const path=layout.edgePaths.get(e.id);
   const a=G.absoluteAnchor(n,r,'target',e);
   assert.deepEqual(path.at(-1),[a.x,a.y]);
   assert.equal(a.y,r.y+r.h/2);
  }
  const leaving=graph.edges.filter(e=>e.source===n.id&&e.rendered!==false);
  for(const e of leaving){
   const a=G.absoluteAnchor(n,r,'source',e);
   assert.deepEqual(layout.edgePaths.get(e.id)[0],[a.x,a.y]);
  }
 }
 assert(connectedInputs>=2,'at least two compiler-backed field inputs must be routed');
 console.log('Ethernet Slang member selection + real ELK terminals PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
''', json.dumps(graph))
