"""Exact virtual-port geometry and truthful port inventories.

Every edge retains compiler provenance, including event controls. A missing
consumer makes an unbound port, never an invented wire. Flattened frames are
presentation-only and never alter graph routing.
"""
from __future__ import annotations

import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from test_process_virtual_groups_038 import _ast
from test_async_reset_enable_016 import graph as async_reset_graph

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_process_outputs_survive_even_without_any_external_consumers():
    ast = _ast()
    members = ast['design']['members'][0]['body']['members']
    members[:] = [item for item in members if item.get('kind') != 'ContinuousAssign']
    graph = RtlDesign(ast, root=Path.cwd(), top='demo').diagram(limit=128)
    comb = next(g for g in graph['processGroups'] if g['kind'] == 'always_comb')
    assert {'comb', 'final'} <= set(comb['targets'])
    assert {'/::sig:comb', '/::sig:final'} <= set(comb['targetIds'])
    assert comb['outputs'] >= 2


def test_async_reset_and_clock_are_extracted_from_event_edge_roles():
    graph = async_reset_graph()
    ff = next(g for g in graph['processGroups'] if g['kind'] == 'always_ff')
    assert '/::sig:clk' in ff['clockIds']
    assert '/::sig:rst_n' in ff['asyncResetIds']
    assert '/::sig:product_q' in ff['targetIds']
    assert '/::sig:accum_q' in ff['targetIds']


def test_real_ethernet_processes_publish_every_written_output_if_fixture_present():
    fixture = Path(__file__).parent / 'fixtures/ethernet_rx_multidestination_032.json'
    if not fixture.exists():
        pytest.skip('compiled Ethernet RX fixture unavailable')
    graph = RtlDesign(json.loads(fixture.read_text()), root=Path.cwd(), top='u_rx').diagram(limit=800)
    for group in graph['processGroups']:
        assert set(group['targets']) <= {n['name'] for n in graph['nodes'] if n['id'] in group['targetIds']}
        assert group['outputs'] >= len(group['targetIds'])


@pytest.mark.skipif(not shutil.which('node'), reason='Node required')
def test_rewritten_virtual_clock_reset_data_and_output_pins_match_real_elk(tmp_path):
    graph = async_reset_graph()
    path = tmp_path / 'graph.json'
    path.write_text(json.dumps(graph))
    script = r'''
const assert=require('node:assert/strict'),fs=require('node:fs');
const W=process.argv[1], graph=JSON.parse(fs.readFileSync(process.argv[2],'utf8'));
const G=require(W+'/symbol-geometry.js'), P=require(W+'/virtual-process.js');
const Adapter=require(W+'/elk-adapter.js'),ELK=require(W+'/elk.bundled.js').default;
(async()=>{
 const compact=P.project(graph);
 const block=compact.nodes.find(n=>n.type==='process_group'&&n.name.startsWith('always_ff'));
 assert(block,'always_ff must become a virtual submodule');
 const clk=block.ports.find(p=>p.name==='CLK:clk');
 const reset=block.ports.find(p=>p.name==='RST:rst_n');
 assert(clk&&clk.timingRole==='clock'&&clk.direction==='input');
 assert(reset&&reset.timingRole==='async_reset'&&reset.direction==='input');
 assert(!block.ports.some(p=>p.direction==='output'&&(p.timingRole==='clock'||p.timingRole==='async_reset')));
 assert(G.portRows(block,'target')[0].port.name==='CLK:clk',
   'clock must be the first WEST input, not placed among output pins');
 for(const dest of ['product_q','accum_q']){
  assert(block.ports.some(p=>p.direction==='output'&&p.name.endsWith(':'+dest)));
 }
 const boundary=compact.edges.filter(e=>e.rendered!==false&&(e.target===block.id||e.source===block.id));
 assert(boundary.some(e=>e.target===block.id&&e.type==='event'&&e.targetPin==='CLK:clk'));
 assert(boundary.some(e=>e.target===block.id&&e.type==='event'&&e.targetPin==='RST:rst_n'));
 const layout=await Adapter.compute(new ELK(),compact,G.boxSize);
 for(const edge of boundary){
  const role=edge.target===block.id?'target':'source';
  const pin=G.pinName(edge,role);
  assert(block.ports.some(p=>p.name===pin),'missing named port '+pin);
  const row=G.portRows(block,role).find(r=>r.port.name===pin);
  assert(row,'missing terminal row '+pin);
  const position=layout.positions.get(block.id);
  const anchor=G.absoluteAnchor(block,position,role,edge);
  assert.equal(anchor.y,position.y+row.y,'anchor must be at the labelled port row');
  assert.equal(anchor.x,position.x+(role==='source'?G.boxSize(block).w:0),
   'input pins on WEST, outputs on EAST');
  const points=layout.edgePaths.get(edge.id);
  assert(points,'real ELK must route each real edge '+edge.id);
  const end=role==='target'?points.at(-1):points[0];
  assert.deepEqual(end,[anchor.x,anchor.y],'ELK wire end must coincide with glyph port');
 }
 const expanded=P.project(graph,[graph.processGroups.find(g=>g.kind==='always_ff').token]);
 assert.deepEqual(expanded.edges.map(e=>e.id),graph.edges.map(e=>e.id),
  'flatten must preserve all original edge identities');
 assert(!expanded.nodes.some(n=>n.type==='process_group'));
 console.log('VIRTUAL PIN/ELK CONTRACT PASS');
})().catch(e=>{console.error(e);process.exitCode=1;});
'''
    result = subprocess.run(['node', '-e', script, str(WEB), str(path)], text=True,
                            capture_output=True, timeout=50)
    assert result.returncode == 0, result.stdout + result.stderr
    assert 'VIRTUAL PIN/ELK CONTRACT PASS' in result.stdout


@pytest.mark.skipif(not shutil.which('node'), reason='Node required')
def test_unconnected_process_output_is_visible_without_fabricated_edge(tmp_path):
    ast = _ast()
    members = ast['design']['members'][0]['body']['members']
    members[:] = [x for x in members if x.get('kind') != 'ContinuousAssign']
    graph = RtlDesign(ast, root=Path.cwd(), top='demo').diagram(limit=128)
    path = tmp_path/'graph.json';path.write_text(json.dumps(graph))
    script = r'''
const assert=require('node:assert/strict'),fs=require('fs');
const P=require(process.argv[1]);
const graph=JSON.parse(fs.readFileSync(process.argv[2],'utf8'));
const compact=P.project(graph), block=compact.nodes.find(n=>n.name.startsWith('always_comb'));
assert(block);
const output=block.ports.find(p=>p.name.endsWith(':final'));
assert(output&&output.direction==='output','declared final must appear');
assert(output.connection==='unbound'||output.connection==='unresolved');
assert(!compact.edges.some(e=>e.source===block.id&&e.sourcePin===output.name));
for(const e of compact.edges)assert(graph.edges.some(original=>original.id===e.id));
console.log('UNCONSUMED OUTPUT PASS');
'''
    result=subprocess.run(['node','-e',script,str(WEB/'virtual-process.js'),str(path)],
                          capture_output=True,text=True,timeout=20)
    assert result.returncode == 0, result.stdout+result.stderr


@pytest.mark.skipif(not shutil.which('node'), reason='Node required')
def test_nested_virtual_clock_is_still_an_input_after_source_id_rewrite(tmp_path):
    """A prior grouping changes edge.source, not its Slang event direction."""
    graph = async_reset_graph()
    path = tmp_path / 'nested.json'
    path.write_text(json.dumps(graph))
    script = r'''const assert=require('node:assert/strict'),fs=require('fs');
const W=process.argv[1],G=require(W+'/symbol-geometry.js'),P=require(W+'/virtual-process.js');
const graph=JSON.parse(fs.readFileSync(process.argv[2],'utf8'));
const clk=graph.nodes.find(n=>n.name==='clk');
const groupId=graph.path+'::procgroup:upstream';
const groupPort='O06:clk';
graph.nodes.push({id:groupId,name:'upstream',type:'process_group',ports:[
  {name:groupPort,direction:'output',connection:'bound'}]});
const clocks=graph.edges.filter(e=>e.type==='event'&&e.source===clk.id&&e.pin==='CLK');
assert(clocks.length>0);
for(const e of clocks){e.source=groupId;e.sourcePin=groupPort;}
// processGroups keep original compiler identities; a nested projection must
// recover the role from the event edge, not reinterpret its new source ID.
const compact=P.project(graph);
const block=compact.nodes.find(n=>n.type==='process_group'&&n.name.startsWith('always_ff'));
assert(block);
const pin=block.ports.find(p=>p.name==='CLK:clk');
assert(pin&&pin.direction==='input'&&pin.timingRole==='clock');
assert(!block.ports.some(p=>p.direction==='output'&&/CLK:clk|O\d+:clk/.test(p.name)));
assert(!block.ports.some(p=>/I\d+:O\d+:/.test(p.name)),'no recursive port labels');
const e=compact.edges.find(e=>clocks.some(old=>old.id===e.id));
assert(e&&e.target===block.id&&e.targetPin==='CLK:clk');
assert.equal(G.anchor(block,'target',e).side,'WEST');
const row=G.portRows(block,'target').find(p=>p.port.name===e.targetPin);
assert(row&&row.index===0,'clock must be the first input on the left');
console.log('NESTED CLOCK INPUT PASS');
'''
    result = subprocess.run(['node', '-e', script, str(WEB), str(path)],
                            text=True, capture_output=True, timeout=20)
    assert result.returncode == 0, result.stdout + result.stderr
    assert 'NESTED CLOCK INPUT PASS' in result.stdout
