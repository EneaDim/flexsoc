"""Compiler-shaped asynchronous reset plus synchronous enable D-cone regressions."""
import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def ref(addr, *, typed=False):
    result = {'kind': 'NamedValue', 'symbol': f'{addr} misleading_display_name'}
    if typed:
        result['type'] = 'logic'
    return result


def assign(addr, rhs, *, nba=True):
    return {'kind': 'Assignment', 'left': ref(addr), 'right': rhs, 'isNonBlocking': nba}


def block(*items):
    return {'kind': 'Block', 'statements': list(items)}


def graph(*, bad_reset=False, bad_clock=False, unknown_branch=False, second_writer=False, wrappers=False):
    members = [{'kind': 'Variable', 'name': name, 'addr': addr} for addr, name in (
        (1, 'a'), (2, 'b'), (3, 'en'), (4, 'clk'), (5, 'rst_n'),
        (6, 'product_d'), (7, 'accum_d'), (8, 'product_q'), (9, 'accum_q'))]
    reset = {'kind': 'UnaryOp', 'op': 'LogicalNot', 'operand': ref(5), 'type': 'logic'}
    if bad_reset:
        reset = ref(5, typed=True)  # active-high predicate on negedge is not proven
    wrap = (lambda x: {'kind': 'ExpressionStatement', 'expr': x}) if wrappers else (lambda x: x)
    sync = {'kind': 'Conditional', 'condition': ref(3, typed=not unknown_branch),
            'ifTrue': block(wrap(assign(8, ref(6))), wrap(assign(9, ref(7))))}
    process = {'kind': 'Conditional', 'condition': reset,
               'ifTrue': block(wrap(assign(8, {'kind': 'IntegerLiteral', 'value': "1'b0"})),
                               wrap(assign(9, {'kind': 'IntegerLiteral', 'value': "1'b0"}))),
               'ifFalse': sync}
    timing = {'kind': 'EventList', 'events': [
        {'kind': 'SignalEvent', 'edge': 'PosEdge', 'expr': ref(4)},
        {'kind': 'SignalEvent', 'edge': 'NegEdge' if not bad_clock else 'PosEdge', 'expr': ref(5)}]}
    members += [
        {'kind': 'ContinuousAssign', 'assignment': assign(6, {'kind': 'BinaryOp',
            'op': 'Multiply', 'left': ref(1), 'right': ref(2)})},
        {'kind': 'ContinuousAssign', 'assignment': assign(7, {'kind': 'BinaryOp',
            'op': 'Add', 'left': ref(8), 'right': ref(9)})},
        {'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF',
         'body': {'kind': 'Timed', 'timing': timing, 'stmt': process}},
    ]
    if second_writer:
        members.append({'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF',
                        'body': {'kind': 'Timed', 'timing': {'kind': 'SignalEvent',
                            'edge': 'PosEdge', 'expr': ref(4)}, 'stmt': assign(8, ref(1))}})
    ast = {'design': {'members': [{'kind': 'Instance', 'name': 'dut',
            'body': {'kind': 'InstanceBody', 'name': 'dut', 'members': members}}]}}
    return RtlDesign(ast, root=Path(__file__).parent, top='dut').diagram()


def d_wires(graph, target):
    return [e for e in graph['edges'] if e['target'] == '/::sig:' + target
            and e['targetPin'] == 'D' and e['rendered']]


def test_two_registers_async_reset_enable_each_get_independent_d_mux():
    g = graph()
    muxes = [n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']
    assert len(muxes) == 2
    for q, d in [('product_q', 'product_d'), ('accum_q', 'accum_d')]:
        dest = '/::sig:' + q
        [wire] = d_wires(g, q)
        m = next(n for n in muxes if n['id'] == wire['source'])
        assert {e['source'] for e in g['edges'] if e['target'] == m['id'] and e['rendered']
                and e['pin'] == 'A'} == {dest}  # hold Q
        assert {e['source'] for e in g['edges'] if e['target'] == m['id'] and e['rendered']
                and e['pin'] == 'B'} == {'/::sig:' + d}
        assert {e['source'] for e in g['edges'] if e['target'] == m['id'] and e['rendered']
                and e['pin'] == 'S'} == {'/::sig:en'}
        assert len([e for e in g['edges'] if e['target'] == dest and e['rendered']
                    and e['type'] == 'event']) == 2
        assert not next(n for n in g['nodes'] if n['id'] == dest).get('dInputStatus')


def test_slang_expression_statement_wrappers_keep_separate_d_cones():
    g = graph(wrappers=True)
    assert len(d_wires(g, 'product_q')) == 1
    assert len(d_wires(g, 'accum_q')) == 1
    assert len([n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']) == 2


@pytest.mark.parametrize('opts', [
    {'bad_reset': True}, {'bad_clock': True}, {'unknown_branch': True},
])
def test_ambiguous_async_reset_or_another_writer_does_not_invent_mux(opts):
    g = graph(**opts)
    assert not [n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']
    assert not d_wires(g, 'product_q')


def test_multiple_process_writer_blocks_only_the_affected_register():
    # An unrelated register with a proven single writer must retain its D
    # network. The multiply-driven register itself must not acquire a D wire.
    g = graph(second_writer=True)
    assert not d_wires(g, 'product_q')
    assert len(d_wires(g, 'accum_q')) == 1


@pytest.mark.skipif(shutil.which('node') is None, reason='Node.js required for ELK')
def test_real_elk_two_distinct_d_paths_and_matched_anchors():
    g = graph()
    script = r'''
const fs=require('node:fs'),assert=require('node:assert/strict');
const g=JSON.parse(fs.readFileSync(0,'utf8')), w=process.argv[1];
const A=require(w+'/elk-adapter.js'),G=require(w+'/symbol-geometry.js');
const ELK=require(w+'/elk.bundled.js').default;
(async()=>{
 const out=await A.compute(new ELK(),g,G.boxSize);
 const drawn=g.edges.filter(e=>e.rendered!==false);
 assert.equal(out.edgePaths.size,drawn.length);
 for(const e of drawn){
   const s=g.nodes.find(n=>n.id===e.source), t=g.nodes.find(n=>n.id===e.target);
   const p=out.edgePaths.get(e.id);
   assert(p, e.id);
   const a=G.absoluteAnchor(s,out.positions.get(s.id),'source',e);
   const b=G.absoluteAnchor(t,out.positions.get(t.id),'target',e);
   assert.deepEqual(p[0],[a.x,a.y]);
   assert.deepEqual(p.at(-1),[b.x,b.y]);
 }
 console.log('async reset dual-D ELK PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    r = subprocess.run(['node','-e',script,str(WEB)], input=json.dumps(g),
                       capture_output=True, text=True, timeout=45)
    assert r.returncode == 0, r.stdout + r.stderr
