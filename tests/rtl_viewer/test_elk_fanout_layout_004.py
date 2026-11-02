"""ELK fanout layout contract: AST edges stay independent; physical pin fanout is shared."""
from pathlib import Path
import shutil
import subprocess

import pytest

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_elks_real_fanout_reuses_terminal_and_keeps_independent_module_pins():
    if not shutil.which('node'):
        pytest.skip('Node.js not available')
    script = r'''
const assert=require('node:assert/strict');
const W=process.argv[1], ELK=require(W+'/elk.bundled.js').default;
const G=require(W+'/symbol-geometry.js'),A=require(W+'/elk-adapter.js');
const L=require(W+'/layout-engine.js');
const sinks=Array.from({length:12},(_,i)=>({id:'sink'+String(i).padStart(2,'0'),type:'instance',
  ports:[{name:'clk_i'+i,direction:'input'},{name:'data_o',direction:'output'}]}));
const nodes=[{id:'clk',type:'port',direction:'in'}, ...sinks,
 {id:'other',type:'signal'},{id:'mod',type:'instance',ports:[
  {name:'y0',direction:'output'},{name:'y1',direction:'output'}]}];
const edges=sinks.map((sink,i)=>({id:'clk'+i,source:'clk',target:sink.id,
  port:'clk_i'+i,net:'clk_net',type:'event',pin:'CLK'}));
edges.push({id:'separate',source:'clk',target:'other',net:'different_net'},
 {id:'out0',source:'mod',target:sinks[0].id,port:'y0',net:'shared_output'},
 {id:'out1',source:'mod',target:sinks[1].id,port:'y1',net:'shared_output'});
const graph={nodes,edges},snapshot=JSON.stringify(graph);
const converted=A.convert(graph,G.boxSize);
const clkPorts=converted.children.find(n=>n.id==='clk').ports;
assert.equal(clkPorts.length,2,'one physical source terminal per distinct net');
assert.equal(new Set(converted.edges.slice(0,12).map(e=>e.sources[0])).size,1,
 'all 12 loads of clk_net must use the same ELK source port');
assert.notEqual(converted.edges[12].sources[0],converted.edges[0].sources[0],
 'separate net must not be merged into clock net');
assert.notEqual(converted.edges[13].sources[0],converted.edges[14].sources[0],
 'module output terminals must remain distinct even on the same net label');
assert.equal(converted.edges.length,edges.length,'all semantic edges retained');
assert.equal(converted.layoutOptions['elk.layered.spacing.nodeNodeBetweenLayers'],'184');
assert.equal(A.convert({nodes:nodes.slice(0,3),edges:edges.slice(0,2)},G.boxSize)
 .layoutOptions['elk.layered.spacing.nodeNodeBetweenLayers'],'120');
(async()=>{
 const elk=new ELK();const first=await A.compute(elk,graph,G.boxSize);
 assert.deepEqual(L.validate(graph,first),{ok:true,errors:[]});
 for(const e of edges){
  const from=G.absoluteAnchor(nodes.find(n=>n.id===e.source),first.positions.get(e.source),'source',e);
  const to=G.absoluteAnchor(nodes.find(n=>n.id===e.target),first.positions.get(e.target),'target',e);
  const path=first.edgePaths.get(e.id);
  assert(path?.length>=2,'route '+e.id);
  assert(Math.abs(path[0][0]-from.x)<.001&&Math.abs(path[0][1]-from.y)<.001,'start '+e.id);
  assert(Math.abs(path.at(-1)[0]-to.x)<.001&&Math.abs(path.at(-1)[1]-to.y)<.001,'end '+e.id);
  for(let i=1;i<path.length;i++)assert(path[i][0]===path[i-1][0]||path[i][1]===path[i-1][1],'orthogonal '+e.id);
 }
 const second=await A.compute(elk,{nodes:nodes.toReversed(),edges:edges.toReversed()},G.boxSize);
 assert.equal(JSON.stringify([...first.positions].sort()),JSON.stringify([...second.positions].sort()));
 assert.equal(JSON.stringify([...first.edgePaths].sort()),JSON.stringify([...second.edgePaths].sort()));
 assert.equal(JSON.stringify(graph),snapshot,'no mutation of semantic connectivity');
 console.log('REAL ELK FANOUT PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    result = subprocess.run(['node', '-e', script, str(WEB)], text=True,
                            capture_output=True, timeout=45)
    assert result.returncode == 0, result.stdout + result.stderr
    assert 'REAL ELK FANOUT PASS' in result.stdout


def test_converter_is_bounded_for_high_degree_fanout():
    if not shutil.which('node'):
        pytest.skip('Node.js not available')
    script = r'''
const assert=require('node:assert/strict');
const W=process.argv[1],A=require(W+'/elk-adapter.js'),G=require(W+'/symbol-geometry.js');
const nodes=[{id:'root',type:'signal'},...Array.from({length:1600},(_,i)=>({id:'n'+i,type:'signal'}))];
const edges=nodes.slice(1).map((n,i)=>({id:'e'+i,source:'root',target:n.id,net:'root_net',port:'sink'+i}));
const converted=A.convert({nodes,edges},G.boxSize);
assert.equal(converted.children.find(n=>n.id==='root').ports.length,1);
assert.equal(converted.layoutOptions['elk.layered.spacing.nodeNodeBetweenLayers'],'184');
assert.equal(converted.edges.length,1600);
console.log('BOUNDED FANOUT PASS');
'''
    result = subprocess.run(['node', '-e', script, str(WEB)], text=True,
                            capture_output=True, timeout=15)
    assert result.returncode == 0, result.stdout + result.stderr
