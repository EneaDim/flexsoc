"""A function's electrical value must remain visible inside its actual process.

Compiler identities, operand pins, feedback MUXs and event timing must survive
both the canonical graph and the virtual process projection. No UPDATE glyphs.
"""
from __future__ import annotations

import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from flexsoc.backend.dv.rtl_viewer.semantic_contracts import audit_scope_semantics

HERE = Path(__file__).parent
WEB = HERE.parents[1] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def _fixture():
    ast = json.loads((HERE / 'fixtures/ethernet_function_call_slang_027.json').read_text())
    design = RtlDesign(ast, root=Path.cwd(), top='top')
    graph = design.diagram(limit=300)
    return design, graph


def test_functions_feed_muxes_and_ff_d_with_one_ast_operand_each():
    design, graph = _fixture()
    nodes = {node['id']: node for node in graph['nodes']}
    functions = [node for node in nodes.values() if node.get('shape') == 'function']
    ff = next(group for group in graph['processGroups'] if group['kind'] == 'always_ff')
    assert len(functions) == 2
    assert not any(node.get('shape') == 'update' or node.get('kind') == 'AggregateUpdate'
                   for node in nodes.values())

    clock = set(ff['clockIds'])
    async_reset = set(ff['asyncResetIds'])
    assert {nodes[id]['name'] for id in clock} == {'mac_rx_clk'}
    assert {nodes[id]['name'] for id in async_reset} == {'mac_rx_rst'}
    for function in functions:
        assert function['id'] in ff['memberIds']
        assert function['function']['callLine'] == function['line']
        incoming = [edge for edge in graph['edges']
                    if edge.get('rendered') and edge['target'] == function['id']]
        assert len(incoming) == 1 and incoming[0]['pin'] == 'I0'
        source = nodes[incoming[0]['source']]
        assert source['name'] in {'rx_bad_event_bin', 'rx_fcs_event_bin'}
        # The function output feeds a MUX and then the register's D value.
        mux_edges = [edge for edge in graph['edges']
                     if edge.get('rendered') and edge['source'] == function['id']]
        assert len(mux_edges) == 1
        mux = nodes[mux_edges[0]['target']]
        assert mux['shape'] == 'mux'
        d_edges = [edge for edge in graph['edges']
                   if edge.get('rendered') and edge['source'] == mux['id']]
        assert len(d_edges) == 1
        register = nodes[d_edges[0]['target']]
        assert register['type'] == 'register'
        assert register['name'] in {'rx_bad_event_gray', 'rx_fcs_event_gray'}
        assert any(edge.get('rendered') and edge['type'] == 'event' and
                   edge['source'] in clock and edge['target'] == register['id'] and
                   edge['pin'] == 'CLK' for edge in graph['edges'])
        assert any(edge.get('rendered') and edge['type'] == 'event' and
                   edge['source'] in async_reset and edge['target'] == register['id'] and
                   edge['pin'] == 'RST' for edge in graph['edges'])

    members = design.scopes['/'].node['body']['members']
    evidence = audit_scope_semantics(members, set(design._signals(design.scopes['/'])),
                                     graph, design.subroutines)
    assert evidence['errors'] == []
    assert evidence['functionCalls'] == evidence['functionCallsRepresented'] == 2


def test_missing_function_argument_is_a_structural_violation():
    design, graph = _fixture()
    function = next(n for n in graph['nodes'] if n.get('shape') == 'function')
    broken = json.loads(json.dumps(graph))
    broken['edges'] = [edge for edge in broken['edges']
                       if not (edge['target'] == function['id'] and edge.get('rendered'))]
    evidence = audit_scope_semantics(design.scopes['/'].node['body']['members'],
                                     set(design._signals(design.scopes['/'])),
                                     broken, design.subroutines)
    assert any(error['code'] == 'function_argument_pin_mismatch'
               for error in evidence['errors'])


@pytest.mark.skipif(not shutil.which('node'), reason='Node.js unavailable')
def test_clock_reset_are_inputs_of_compact_ff_and_function_reappears_in_focus(tmp_path):
    _, graph = _fixture()
    graph_path = tmp_path / 'graph.json'
    graph_path.write_text(json.dumps(graph))
    js = r'''
const assert=require('node:assert/strict'),fs=require('fs');
const web=process.argv[1],P=require(web+'/virtual-process.js'),
 C=require(web+'/render-contract.js');
const original=JSON.parse(fs.readFileSync(process.argv[2]));
const compact=P.project(original);
const blocks=compact.nodes.filter(n=>n.type==='process_group');
assert.equal(blocks.length,1);
const block=blocks[0];
const clk=block.ports.find(p=>p.name==='CLK:mac_rx_clk');
const rst=block.ports.find(p=>p.name==='RST:mac_rx_rst');
assert(clk&&rst&&clk.direction==='input'&&rst.direction==='input');
assert(!block.ports.some(p=>p.direction==='output'&&/mac_rx_(clk|rst)/.test(p.name)));
const edgeTo=(pin)=>compact.edges.some(e=>e.rendered!==false&&e.target===block.id&&e.targetPin===pin);
assert(edgeTo(clk.name)&&edgeTo(rst.name));
assert.deepEqual(C.checkProjection(original,compact).errors,[]);
const focus=P.focus(original,block.group);
assert.equal(focus.nodes.filter(n=>n.shape==='function').length,2);
assert.deepEqual(C.check(focus,{checkOriginalGroups:false}).errors,[]);
console.log('FF FUNCTION AND TIMING PORTS PASS');
'''
    run = subprocess.run(['node', '-e', js, str(WEB), str(graph_path)],
                         text=True, capture_output=True, timeout=45)
    assert run.returncode == 0, run.stdout + run.stderr
    assert 'FF FUNCTION AND TIMING PORTS PASS' in run.stdout
