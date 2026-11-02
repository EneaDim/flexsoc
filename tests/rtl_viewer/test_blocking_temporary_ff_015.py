"""Compiler-identity local blocking temporaries in an always_ff D projection.

Synthetic Slang-shaped AST regressions; real Slang execution is separately gated.
"""
import json
from pathlib import Path
import shutil
import subprocess

import pytest
from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def ref(addr, display='q', *, typed=False):
    value = {'kind': 'NamedValue', 'symbol': f'{addr} {display}'}
    if typed:
        value['type'] = 'logic'
    return value


def local(addr=100):
    return {'kind': 'Variable', 'addr': addr, 'name': 'temporary', 'type': 'logic[7:0]'}


def assign(addr, rhs, *, nba):
    return {'kind': 'Assignment', 'left': ref(addr), 'right': rhs, 'isNonBlocking': nba}


def block(*items):
    return {'kind': 'Block', 'body': list(items)}


def cond(select, true, false=None):
    result = {'kind': 'Conditional', 'condition': ref(select, 'sel', typed=True), 'ifTrue': true}
    if false is not None:
        result['ifFalse'] = false
    return result


def graph(statement):
    members = [{'kind': 'Variable', 'name': name, 'addr': addr}
               for addr, name in ((1, 'q'), (2, 'a'), (3, 'b'), (4, 'sel'), (5, 'clk'))]
    members.append({'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF',
                    'body': {'kind': 'Timed', 'stmt': statement,
                             'timing': {'kind': 'SignalEvent', 'edge': 'PosEdge',
                                        'expr': ref(5, 'clk')}}})
    ast = {'design': {'members': [{'kind': 'Instance', 'name': 'dut',
                                  'body': {'kind': 'InstanceBody', 'name': 'dut',
                                           'members': members}}]}}
    return RtlDesign(ast, root=Path(__file__).parent, top='dut').diagram()


def d_wires(g):
    return [e for e in g['edges'] if e['target'] == '/::sig:q'
            and e['targetPin'] == 'D' and e['rendered']]


def input_wires(g, op, pin):
    return [e for e in g['edges'] if e['rendered'] and e['target'] == op
            and e['pin'] == pin]


def test_local_blocking_value_is_not_a_second_register_or_net():
    g = graph(block(local(), assign(100, ref(2, 'a'), nba=False),
                    assign(1, ref(100, 'q'), nba=True)))
    assert [e['source'] for e in d_wires(g)] == ['/::sig:a']
    assert not [n for n in g['nodes'] if n['name'] == 'temporary']
    assert len(d_wires(g)) == 1


def test_operator_temp_is_substituted_as_an_expression_not_short_q_to_d():
    add = {'kind': 'BinaryOp', 'op': 'Add', 'left': ref(1), 'right': ref(2)}
    g = graph(block(local(), assign(100, add, nba=False),
                    assign(1, ref(100), nba=True)))
    op, = [n for n in g['nodes'] if n.get('name') == 'Add']
    assert [e['source'] for e in d_wires(g)] == [op['id']]
    assert [e['source'] for e in input_wires(g, op['id'], 'A')] == ['/::sig:q']
    assert [e['source'] for e in input_wires(g, op['id'], 'B')] == ['/::sig:a']
    assert all(e['net'] != 'q' for e in d_wires(g))


def test_reassigned_local_reads_the_previous_blocking_value():
    xor = {'kind': 'BinaryOp', 'op': 'Xor', 'left': ref(100), 'right': ref(3)}
    g = graph(block(local(), assign(100, ref(2), nba=False),
                    assign(100, xor, nba=False), assign(1, ref(100), nba=True)))
    op, = [n for n in g['nodes'] if n.get('name') == 'Xor']
    assert [e['source'] for e in input_wires(g, op['id'], 'A')] == ['/::sig:a']
    assert [e['source'] for e in input_wires(g, op['id'], 'B')] == ['/::sig:b']
    assert len(d_wires(g)) == 1 and d_wires(g)[0]['source'] == op['id']


def test_two_nbas_capture_temporary_at_their_respective_write_sites():
    g = graph(block(local(), assign(100, ref(2), nba=False),
                    assign(1, ref(100), nba=True), assign(100, ref(3), nba=False),
                    assign(1, ref(100), nba=True)))
    assert [e['source'] for e in d_wires(g)] == ['/::sig:b']


def test_guarded_register_write_with_prewritten_temp_and_q_hold():
    g = graph(block(local(), assign(100, ref(2), nba=False),
                    cond(4, assign(1, ref(100), nba=True))))
    mux, = [n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']
    assert [e['source'] for e in input_wires(g, mux['id'], 'A')] == ['/::sig:q']
    assert [e['source'] for e in input_wires(g, mux['id'], 'B')] == ['/::sig:a']
    assert len(d_wires(g)) == 1 and d_wires(g)[0]['source'] == mux['id']


@pytest.mark.parametrize('statement', [
    block(local(), assign(1, ref(100), nba=True)),
    block(local(), assign(100, ref(2), nba=True), assign(1, ref(100), nba=True)),
    block(local(), assign(100, ref(2), nba=False), assign(1, ref(3), nba=False),
          assign(1, ref(100), nba=True)),
    block(local(), cond(4, assign(100, ref(2), nba=False)),
          assign(1, ref(100), nba=True)),
    block(local(), assign(100, ref(100), nba=False), assign(1, ref(100), nba=True)),
    block({'kind': 'Variable', 'addr': 100, 'name': 'temporary', 'initializer': ref(2)},
          assign(100, ref(2), nba=False), assign(1, ref(100), nba=True)),
    block(local(), local(), assign(100, ref(2), nba=False), assign(1, ref(100), nba=True)),
])
def test_unsupported_temporary_semantics_fail_closed(statement):
    g = graph(statement)
    assert not d_wires(g)
    assert not [n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']
    assert next(n for n in g['nodes'] if n['name'] == 'q')['dInputStatus'] in {
        'unresolved procedural D input', 'unresolved conditional D input'}


@pytest.mark.skipif(shutil.which('node') is None, reason='Node.js unavailable')
def test_real_elk_has_one_verified_d_terminal_with_blocking_temp():
    g = graph(block(local(), assign(100, {'kind': 'BinaryOp', 'op': 'Add',
                                         'left': ref(1), 'right': ref(2)}, nba=False),
                    assign(1, ref(100), nba=True)))
    js = r'''
const assert=require('node:assert/strict'),fs=require('node:fs');
const g=JSON.parse(fs.readFileSync(0,'utf8')),w=process.argv[1];
const G=require(w+'/symbol-geometry.js'),A=require(w+'/elk-adapter.js');
const ELK=require(w+'/elk.bundled.js').default;
(async()=>{const out=await A.compute(new ELK(),g,G.boxSize);
 const rendered=g.edges.filter(e=>e.rendered!==false);
 assert.equal(out.edgePaths.size,rendered.length);
 for(const e of rendered){
  const s=g.nodes.find(n=>n.id===e.source),t=g.nodes.find(n=>n.id===e.target);
  const path=out.edgePaths.get(e.id);
  const from=G.absoluteAnchor(s,out.positions.get(s.id),'source',e);
  const to=G.absoluteAnchor(t,out.positions.get(t.id),'target',e);
  assert.deepEqual(path[0],[from.x,from.y]);
  assert.deepEqual(path.at(-1),[to.x,to.y]);
 }
 console.log('ELK blocking temp PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    result = subprocess.run(['node', '-e', js, str(WEB)], input=json.dumps(g), text=True,
                            capture_output=True, timeout=45)
    assert result.returncode == 0, result.stdout+result.stderr
