"""Flattening an FSM may not hide the *other* logic in its always blocks.

FSMs are virtual subgraphs, not procedural scopes. One always_comb can write
both FSM-controlled next-state outputs and unrelated module signals. Opening
only the FSM must leave all non-FSM signals and their source edges visible.
"""
from __future__ import annotations

import json
from pathlib import Path
import shutil
import subprocess

import pytest

from test_fsm_submodule_projection_036 import small_graph
from flexsoc.backend.dv.rtl_viewer.fsm_projection import collapse_fsm_cones

WEB = Path(__file__).resolve().parents[2] / "src/flexsoc/backend/dv/rtl_viewer/web"


def test_fsm_child_process_does_not_swallow_external_signals(tmp_path):
    graph = small_graph()
    scope = graph['path']
    signal = {'id': scope + '::sig:other', 'type': 'signal', 'name': 'other'}
    operation = {'id': scope + '::op:post', 'type': 'operator', 'name': 'POST',
                 'kind': 'BitwiseOp', 'shape': 'logic', 'pins': ['A', 'Y']}
    graph['nodes'].extend([signal, operation])
    graph['edges'].extend([
        {'id': 'after-fsm', 'source': scope + '::sig:flag', 'target': operation['id'],
         'net': scope + '::sig:flag', 'rendered': True, 'type': 'data',
         'pin': 'A', 'targetPin': 'A'},
        {'id': 'after-post', 'source': operation['id'], 'target': signal['id'],
         'net': scope + '::op:post', 'rendered': True, 'type': 'data',
         'sourcePin': 'Y'},
    ])
    graph['processGroups'] = [
        {'token': 'proc:1', 'name': 'always_ff · L10', 'kind': 'always_ff',
         'memberIds': [scope + '::sig:state'],
         'inputIds': [scope + '::sig:clk'],
         'targetIds': [scope + '::sig:state'], 'clockIds': [scope + '::sig:clk'],
         'coverage': 'connected'},
        {'token': 'proc:2', 'name': 'always_comb · L20', 'kind': 'always_comb',
         # The source always_comb owns both FSM and *non-FSM* logic.
         'memberIds': [scope + '::op:case', scope + '::op:mux',
                       scope + '::sig:flag', operation['id'], signal['id']],
         'inputIds': [scope + '::sig:state', scope + '::sig:data'],
         'targetIds': [scope + '::sig:flag', signal['id']],
         'coverage': 'connected'},
    ]
    compact = collapse_fsm_cones(graph, frozenset())
    expanded = collapse_fsm_cones(graph, frozenset({'fsm:state'}))
    assert len(expanded['fsmGroups']) == 1
    payload = {'compact': compact, 'expanded': expanded}
    path = tmp_path / 'fsm.json'
    path.write_text(json.dumps(payload))
    script = r'''
const assert=require('node:assert/strict'),fs=require('node:fs');
const W=process.argv[1], {compact,expanded}=JSON.parse(fs.readFileSync(process.argv[2]));
const VP=require(W+'/virtual-process.js'),A=require(W+'/elk-adapter.js'),C=require(W+'/render-contract.js');
const G=require(W+'/symbol-geometry.js'), ELK=require(W+'/elk.bundled.js').default;
(async()=>{
 const result=VP.project(expanded,new Set(['fsm:state']));
 const child=result.nodes.find(n=>n.type==='process_group'&&n.group==='proc:2');
 assert(child,'immediate process child must remain compact');
 assert.equal(result.processGroups.find(g=>g.token==='proc:2').coverage,'fragment');
 const external=['/rx::sig:flag','/rx::op:post','/rx::sig:other'];
 for(const id of external)
  assert(result.nodes.some(n=>n.id===id),'flattening FSM swallowed external node '+id);
 const ids=new Set(result.edges.map(e=>e.id));
 for(const edge of expanded.edges.filter(e=>e.rendered!==false)){
  const fsmMembers=new Set(expanded.fsmGroups[0].memberIds);
  if(fsmMembers.has(edge.source)!==fsmMembers.has(edge.target))
   assert(ids.has(edge.id),'flattening FSM swallowed boundary edge '+edge.id);
 }
 assert(ids.has('after-fsm')&&ids.has('after-post'));
 assert.deepEqual(C.checkProjection(expanded,result).errors,[]);
 // The formal *rendering* contract must fail on the exact old regression,
 // rather than report PASS because the missing edge is internal to a process.
 const broken={...result,edges:result.edges.filter(e=>e.id!=='output')};
 assert(C.checkProjection(expanded,broken).errors.some(e=>e.code==='fsm_boundary_edge_lost'));
 const swallowed={...result,nodes:result.nodes.filter(n=>n.id!=='/rx::op:post')};
 assert(C.checkProjection(expanded,swallowed).errors.some(e=>e.code==='fsm_external_process_node_lost'));
 assert(result.edges.some(e=>e.id==='output'&&e.source===child.id&&e.target==='/rx::sig:flag'),
  'FSM process must expose the proven output to the external module signal');
 assert(!child.ports.some(p=>p.name.endsWith(':other')),
  'partial FSM child must not advertise an unrelated output as its own pin');
 const el=await A.compute(new ELK(),result,G.boxSize);
 assert.deepEqual(A.checkCompoundOwnership(result,el),[]);
 const groups=result.processGroups.filter(g=>g.view==='collapsed');
 assert.equal(groups.length,2);
 console.log('FSM BOUNDARY PRESERVATION PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    if not shutil.which('node'):
        pytest.skip('Node.js required')
    done = subprocess.run(['node', '-e', script, str(WEB), str(path)],
                          capture_output=True, text=True, timeout=45)
    assert done.returncode == 0, done.stdout + done.stderr
    assert 'FSM BOUNDARY PRESERVATION PASS' in done.stdout
