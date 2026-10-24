"""Conductor rerouting: non-overlapping lines and honest pin markers."""
from pathlib import Path
import json
import shutil
import subprocess
import pytest
from test_v6_connectivity import graph

ROUTER=Path(__file__).resolve().parents[2]/'src/flexsoc/backend/dv/rtl_viewer/web/router.js'


def test_partial_and_unbound_pins_visible_without_fake_link():
    diagram=graph().diagram()
    unconnected=next(n for n in diagram['nodes'] if n['name']=='u_unconnected')
    assert unconnected['ports'][0]['connection']=='unbound'
    producer=next(n for n in diagram['nodes'] if n['name']=='u_producer')
    assert producer['ports'][0]['connection']=='bound'
    assert diagram['connectivity']['unbound_pins']>=1


def test_router_repairs_foreign_box_intersection_and_is_deterministic():
    if not shutil.which('node'):pytest.skip('node unavailable')
    source=r'''
const assert=require('node:assert/strict');
const R=require(process.argv[1]);
const graph={edges:[{id:'signal',source:'a',target:'b',net:'signal'}]};
const nodes=new Map([
 ['a',{x:0,y:100,w:80,h:50}],
 ['b',{x:400,y:100,w:80,h:50}],
 ['obstacle',{x:190,y:70,w:80,h:100}],
]);
const old=new Map([['signal',[[72,125],[210,125],[472,125]]]]);
const before=R.geometryScore('signal',old.get('signal'),nodes,new Map(),new Map(graph.edges.map(e=>[e.id,e])));
assert.ok(before.boxHits>0);
const result=R.refine(graph,nodes,old,380);
assert.ok(result.stats.nodeConflictsAfter===0,JSON.stringify(result.stats));
assert.ok(result.stats.refined===1);
assert.deepEqual([...result.paths],[...R.refine(graph,nodes,old,380).paths]);
const p=result.paths.get('signal');
assert.deepEqual(p[0],old.get('signal')[0]);
assert.equal(p.at(-1)[1],old.get('signal').at(-1)[1]);
assert.ok(p.at(-1)[0]===408||p.at(-1)[0]===472,'end at either valid glyph terminal');
console.log(JSON.stringify(result.stats));
'''
    proc=subprocess.run(['node','-e',source,str(ROUTER)],capture_output=True,text=True,timeout=15)
    assert proc.returncode==0,proc.stdout+proc.stderr


def test_module_input_and_output_pin_stubs_have_distinct_tracks():
    if not shutil.which('node'):pytest.skip('node unavailable')
    source=r'''
const assert=require('node:assert/strict');const R=require(process.argv[1]);
const graph={nodes:[
 {id:'clk',type:'port',direction:'in'},
 {id:'result',type:'port',direction:'out'},
 {id:'u',type:'instance',ports:[{name:'clk_i',direction:'in'},{name:'data_o',direction:'out'}]}
],edges:[
 {id:'ei',source:'clk',target:'u',net:'clk',port:'clk_i',type:'port_in'},
 {id:'eo',source:'u',target:'result',net:'value',port:'data_o',type:'port_out'}
]};
const r=R.compute(graph,{boxSize:R.boxSize,baseRank:R.baseRank});
const input=r.edgePaths.get('ei').at(-1)[1], output=r.edgePaths.get('eo')[0][1];
assert.equal(output-input,12,'separate input/output pin anchors on same module');
'''
    proc=subprocess.run(['node','-e',source,str(ROUTER)],capture_output=True,text=True,timeout=15)
    assert proc.returncode==0,proc.stderr
