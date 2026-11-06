"""Value-path view: electrical identities and source-backed function visibility.

The projection is deliberately view-only. It must never invent signal drivers,
change pin identities, or show an external sequential cell without its events.
"""
from __future__ import annotations

from pathlib import Path
import shutil
import subprocess

import pytest

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


@pytest.mark.skipif(not shutil.which('node'), reason='Node.js unavailable')
def test_value_cone_preserves_function_inputs_and_struct_field_reads():
    js = r'''
const assert = require('node:assert/strict');
const path = require(process.argv[1]);
const graph = {
 path:'/unit',module:'unit',nodes:[
  {id:'clk',name:'clk',type:'port',direction:'in'},
  {id:'arg',name:'gray_sync',type:'register',pins:['D','Q','CLK']},
  {id:'fun',name:'gray_to_bin',type:'operator',shape:'function',kind:'Call',pins:['I0','Y'],
   function:{name:'gray_to_bin',callLine:11}},
  {id:'out',name:'count_now',type:'signal'},
  {id:'reg',name:'count_seen',type:'register',pins:['D','Q','CLK']},
  {id:'record',name:'reg2hw',type:'signal'},
  {id:'f1',name:'FieldSelect',type:'operator',shape:'field',kind:'MemberAccess',pins:['A','Y']},
  {id:'f2',name:'FieldSelect',type:'operator',shape:'field',kind:'MemberAccess',pins:['A','Y']},
  {id:'concat',name:'CONCAT',type:'operator',shape:'logic',kind:'Concatenation',pins:['I0','I1','Y']},
  {id:'csr',name:'tx_desired_csr',type:'signal'},
  {id:'fake',name:'foreign partial writer',type:'signal'}
 ],edges:[
  {id:'c',source:'clk',target:'arg',type:'event',pin:'CLK',rendered:true},
  {id:'a',source:'arg',target:'fun',type:'data',pin:'I0',rendered:true,net:'arg'},
  {id:'b',source:'fun',target:'out',type:'data',rendered:true,net:'out'},
  {id:'d',source:'out',target:'reg',type:'data',pin:'D',rendered:true},
  {id:'e',source:'clk',target:'reg',type:'event',pin:'CLK',rendered:true},
  {id:'f',source:'record',target:'f1',type:'data',pin:'A',mapping:'partial',rendered:true},
  {id:'g',source:'record',target:'f2',type:'data',pin:'A',mapping:'partial',rendered:true},
  {id:'h',source:'f1',target:'concat',type:'data',pin:'I0',rendered:true},
  {id:'i',source:'f2',target:'concat',type:'data',pin:'I1',rendered:true},
  {id:'j',source:'concat',target:'csr',type:'data',rendered:true},
  {id:'k',source:'fake',target:'csr',type:'data',mapping:'partial',rendered:true}
 ]};
const original=JSON.stringify(graph);
const f=path.valuePath(graph,'out');
assert.equal(f.status,'available');
assert.deepEqual(f.graph.nodes.filter(n=>n.shape==='function').map(n=>n.name),['gray_to_bin']);
assert.deepEqual(f.graph.edges.map(e=>e.id).sort(),['a','b','d']);
assert.equal(f.graph.nodes.find(n=>n.id==='arg').type,'signal');
assert.equal(f.graph.nodes.find(n=>n.id==='reg').type,'signal');
assert.deepEqual(f.graph.traceInfo.missingPins,[]);
const csr=path.valuePath(graph,'csr');
assert.equal(csr.status,'available');
assert.deepEqual(csr.graph.edges.map(e=>e.id).sort(),['f','g','h','i','j']);
assert(csr.graph.nodes.some(n=>n.id==='record'));
assert(!csr.graph.edges.some(e=>e.id==='k'));
assert.deepEqual(csr.graph.traceInfo.missingPins,[]);
assert.equal(JSON.stringify(graph),original,'projection must not mutate compiler graph');
const missing=structuredClone(graph);missing.edges=missing.edges.filter(e=>e.id!=='a');
const broken=path.valuePath(missing,'out');
assert.equal(broken.status,'incomplete');
assert.deepEqual(broken.graph.traceInfo.missingPins,[{nodeId:'fun',pin:'I0'}]);
assert.equal(path.valuePath(graph,'unknown').status,'not_visible');
assert.equal(path.valuePath({...graph,truncated:true},'out').status,'source_graph_limited');
console.log('VALUE PATH IDENTITY CONTRACT PASS');
'''
    result = subprocess.run(['node', '-e', js, str(WEB / 'driver-trace.js')],
                            capture_output=True, text=True, timeout=25)
    assert result.returncode == 0, result.stdout + result.stderr
    assert 'VALUE PATH IDENTITY CONTRACT PASS' in result.stdout


@pytest.mark.skipif(not shutil.which('node'), reason='Node.js unavailable')
def test_value_path_does_not_claim_missing_or_ambiguous_driver():
    js = r'''
const assert=require('node:assert/strict');
const api=require(process.argv[1]);
const g={path:'/',nodes:[
 {id:'a',name:'a',type:'signal'},
 {id:'b',name:'b',type:'signal'},
 {id:'q',name:'q',type:'signal'}
],edges:[
 {id:'x',source:'a',target:'q',type:'data',rendered:true},
 {id:'y',source:'b',target:'q',type:'data',rendered:true}
]};
assert.equal(api.valuePath(g,'q').status,'multiple_drivers');
const no={...g,edges:[]};
assert.equal(api.valuePath(no,'q').status,'no_proven_driver');
const suppressed={...g,edges:g.edges.map(e=>({...e,rendered:false}))};
assert.equal(api.valuePath(suppressed,'q').status,'no_proven_driver');
const partial={...g,edges:g.edges.map(e=>({...e,mapping:'partial'}))};
assert.equal(api.valuePath(partial,'q').status,'no_proven_driver');
assert.deepEqual(api.valuePath(g,'q').graph.edges.map(e=>e.id),['x','y']);
console.log('AMBIGUOUS AND MISSING DRIVER CONTRACT PASS');
'''
    result = subprocess.run(['node', '-e', js, str(WEB / 'driver-trace.js')],
                            capture_output=True, text=True, timeout=25)
    assert result.returncode == 0, result.stdout + result.stderr
