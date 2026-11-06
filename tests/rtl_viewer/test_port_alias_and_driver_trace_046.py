"""Direct-clock aliases and compiler-backed producer navigation contracts."""
from __future__ import annotations

import copy
import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

HERE = Path(__file__).parent
WEB = HERE.parents[1] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def phy_fixture():
    return json.loads((HERE / 'fixtures/ethernet_phy_select_031.json').read_text())


def add_direct_alias(ast):
    members = ast['design']['members'][0]['body']['members']
    target = next(m for m in members if m.get('kind') == 'Port' and m.get('name') == 'mac_gmii_tx_clk')
    original_ref = target['internalSymbol']
    members[:0] = [
        {'kind': 'Port', 'name': 'clk', 'direction': 'In', 'type': 'logic',
         'addr': 900001, 'internalSymbol': '900002 clk'},
        {'kind': 'Variable', 'name': 'clk', 'type': 'logic', 'addr': 900002},
        {'kind': 'ContinuousAssign', 'assignment': {
            'kind': 'Assignment', 'isNonBlocking': False,
            'left': {'kind': 'NamedValue', 'type': 'logic', 'symbol': original_ref},
            'right': {'kind': 'NamedValue', 'type': 'logic', 'symbol': '900002 clk'},
        }},
    ]
    return members


def graph(ast):
    return RtlDesign(ast, root=HERE, top='u_phy').diagram(limit=1500)


def source_of_clock(graph, reg='tx_rst_reg'):
    nodes = {n['id']: n for n in graph['nodes']}
    dest = next(n['id'] for n in nodes.values() if n['name'] == reg)
    event = next(e for e in graph['edges'] if e['target'] == dest and e.get('pin') == 'CLK'
                 and e['type'] == 'event')
    return nodes[event['source']]['name'], event


def test_output_clock_alias_is_not_a_backwards_ff_clock_wire():
    ast = phy_fixture()
    add_direct_alias(ast)
    g = graph(ast)
    clock, event = source_of_clock(g)
    assert clock == 'clk'
    assert event['rendered']
    nodes = {n['id']: n for n in g['nodes']}
    aliases = [e for e in g['edges'] if nodes[e['source']]['name'] == 'clk'
               and nodes[e['target']]['name'] == 'mac_gmii_tx_clk' and e['rendered']]
    assert len(aliases) == 1
    assert nodes[aliases[0]['target']]['direction'] == 'out'
    assert not any(e['type'] == 'event' and
                   nodes[e['source']]['name'] == 'mac_gmii_tx_clk' and
                   nodes[e['target']]['name'] == 'tx_rst_reg' for e in g['edges'])
    reset = [e for e in g['edges'] if e['type'] == 'event'
             and nodes[e['target']]['name'] == 'tx_rst_reg' and e['pin'] == 'RST']
    assert len(reset) == 1 and nodes[reset[0]['source']]['name'] == 'rst'


def test_unproved_clock_alias_does_not_invent_an_input():
    original = phy_fixture()
    assert source_of_clock(graph(original))[0] == 'mac_gmii_tx_clk'

    duplicate = phy_fixture()
    members = add_direct_alias(duplicate)
    copy_assignment = copy.deepcopy(next(m for m in members if m.get('kind') == 'ContinuousAssign'))
    members.append(copy_assignment)
    assert source_of_clock(graph(duplicate))[0] == 'mac_gmii_tx_clk'

    converted = phy_fixture()
    members = add_direct_alias(converted)
    assignment = next(m for m in members if m.get('kind') == 'ContinuousAssign')['assignment']
    assignment['right'] = {'kind': 'Conversion', 'type': 'logic',
                           'operand': assignment['right']}
    assert source_of_clock(graph(converted))[0] == 'mac_gmii_tx_clk'


@pytest.mark.skipif(not shutil.which('node'), reason='Node.js unavailable')
def test_producer_trace_is_exact_and_does_not_guess(tmp_path):
    fixture = json.loads((HERE / 'fixtures/ethernet_function_call_slang_027.json').read_text())
    g = RtlDesign(fixture, root=HERE, top='top').diagram(limit=400)
    file = tmp_path / 'graph.json'
    file.write_text(json.dumps(g))
    js = r'''
const assert=require('node:assert/strict'),fs=require('node:fs');
const graph=JSON.parse(fs.readFileSync(process.argv[2], 'utf8'));
const trace=require(process.argv[1]);
const dest=graph.nodes.find(n=>n.name==='rx_bad_event_gray');
const result=trace.producer(graph,dest.id);
assert.equal(result.status,'unique');
assert.equal(result.source.shape,'mux');
const damaged=structuredClone(graph);
damaged.edges=damaged.edges.filter(e=>e.target!==dest.id);
assert.equal(trace.producer(damaged,dest.id).status,'no_visible_driver');
const ambiguous=structuredClone(graph);
const edge=ambiguous.edges.find(e=>e.target===dest.id && e.rendered!==false);
ambiguous.edges.push({...edge,id:'different-driver',source:graph.nodes.find(n=>n.name==='rx_bad_event_bin').id});
assert.equal(trace.producer(ambiguous,dest.id).status,'multiple_drivers');
const comb={nodes:[
 {id:'sig:reg2hw',name:'reg2hw',type:'signal'},
 {id:'op:field1',name:'ctrl.tx_enable.q',type:'operator',shape:'field'},
 {id:'op:field2',name:'ifg.q',type:'operator',shape:'field'},
 {id:'op:concat',name:'CONCAT',type:'operator',shape:'logic',kind:'Concatenation',line:108},
 {id:'sig:desired',name:'tx_desired_csr',type:'signal'}
],edges:[
 {id:'wire:1',source:'sig:reg2hw',target:'op:field1',pin:'A',rendered:true},
 {id:'wire:2',source:'sig:reg2hw',target:'op:field2',pin:'A',rendered:true},
 {id:'wire:3',source:'op:field1',target:'op:concat',pin:'I0',rendered:true},
 {id:'wire:4',source:'op:field2',target:'op:concat',pin:'I1',rendered:true},
 {id:'wire:5',source:'op:concat',target:'sig:desired',rendered:true}
]};
const aggregate=trace.producer(comb,'sig:desired');
assert.equal(aggregate.status,'unique');
assert.equal(aggregate.source.name,'CONCAT');
assert.deepEqual(aggregate.inputs.map(x=>x.pin),['I0','I1']);
console.log('PROVEN DRIVER TRACE PASS');
'''
    result = subprocess.run(['node', '-e', js, str(WEB / 'driver-trace.js'), str(file)],
                            capture_output=True, text=True, timeout=40)
    assert result.returncode == 0, result.stdout + result.stderr
    assert 'PROVEN DRIVER TRACE PASS' in result.stdout
