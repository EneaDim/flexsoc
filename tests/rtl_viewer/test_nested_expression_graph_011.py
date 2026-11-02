"""Compiler-AST expression lowering, not source-text-based gate synthesis.

All graph cases are synthetic Slang-shaped AST; geometry uses bundled real ELK.
"""
import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def ref(addr):
    return {'kind': 'NamedValue', 'symbol': f'{addr} misleading_name'}


def op(name, a, b):
    return {'kind': 'BinaryOp', 'op': name, 'left': a, 'right': b}


def diagram(rhs, *, two_writers=False):
    members = [{'kind': 'Variable', 'addr': i, 'name': name}
               for i, name in enumerate(('q', 'a', 'b', 'c', 'clk', 'sel'), 1)]
    write = {'kind': 'Assignment', 'left': ref(1), 'right': rhs}
    if two_writers:
        write = {'kind': 'Conditional', 'condition': {'kind': 'ElementSelect', 'value': ref(6), 'selector': ref(3)},
                 'ifTrue': write, 'ifFalse': {'kind': 'Assignment', 'left': ref(1), 'right': ref(2)}}
    members.append({'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF',
                    'body': {'kind': 'Timed',
                             'timing': {'kind': 'SignalEvent', 'edge': 'PosEdge', 'expr': ref(5)},
                             'stmt': write}})
    payload = {'design': {'members': [{'kind': 'Instance', 'name': 'dut', 'body': {
        'kind': 'InstanceBody', 'name': 'dut', 'members': members}}]}}
    return RtlDesign(payload, root=Path(__file__).parent, top='dut').diagram()


def links(g, target):
    return {(e['source'], e['pin'], e['net'], e['rendered']) for e in g['edges']
            if e['target'] == target and e['type'] == 'data'}


def test_nested_binary_expression_has_distinct_elaboration_value_nets():
    g = diagram(op('BitwiseXor', op('Add', ref(2), ref(3)), ref(4)))
    outer, inner = [n for n in g['nodes'] if n['type'] == 'operator']
    assert (outer['name'], inner['name']) == ('BitwiseXor', 'Add')
    assert links(g, outer['id']) == {
        (inner['id'], 'A', '/::expr:op:1', True),
        ('/::sig:c', 'B', '/::sig:c', True)}
    assert links(g, inner['id']) == {
        ('/::sig:a', 'A', '/::sig:a', True),
        ('/::sig:b', 'B', '/::sig:b', True)}
    d = next(e for e in g['edges'] if e['source'] == outer['id'] and e['target'] == '/::sig:q')
    assert d['net'] == '/::expr:op:0' and d['targetPin'] == 'D' and d['rendered']
    assert len({e['net'] for e in g['edges'] if e['rendered'] and e['type'] == 'data'}) == 4
    assert 'operandStatus' not in outer and 'operandStatus' not in inner


def test_nested_unary_conversion_and_mux_are_real_intermediate_nodes():
    expr = {'kind': 'ConditionalOp', 'condition': ref(6),
            'left': {'kind': 'Conversion', 'type': 'logic[7:0]',
                     'operand': {'kind': 'UnaryOp', 'op': 'BitwiseNot', 'operand': ref(2)}},
            'right': op('Subtract', ref(3), ref(4))}
    g = diagram(expr)
    nodes = [n for n in g['nodes'] if n['type'] == 'operator']
    assert {n['name'] for n in nodes} == {'ConditionalOp', 'Conversion', 'BitwiseNot', 'Subtract'}
    mux = next(n for n in nodes if n['shape'] == 'mux')
    cast = next(n for n in nodes if n['name'] == 'Conversion')
    inv = next(n for n in nodes if n['name'] == 'BitwiseNot')
    subtract = next(n for n in nodes if n['name'] == 'Subtract')
    assert (subtract['id'], 'A', '/::expr:' + subtract['id'].split('::')[1], True) in links(g, mux['id'])
    assert (cast['id'], 'B', '/::expr:' + cast['id'].split('::')[1], True) in links(g, mux['id'])
    assert ('/::sig:sel', 'S', '/::sig:sel', True) in links(g, mux['id'])
    assert (inv['id'], 'A', '/::expr:' + inv['id'].split('::')[1], True) in links(g, cast['id'])
    assert ('/::sig:a', 'A', '/::sig:a', True) in links(g, inv['id'])


def test_parenthesized_nested_expression_is_not_short_circuited():
    expr = op('Add', {'kind': 'ParenthesizedExpression',
                      'operand': op('Multiply', ref(2), ref(3))}, ref(4))
    g = diagram(expr)
    assert len([n for n in g['nodes'] if n['type'] == 'operator']) == 2
    assert any(e['source'] == '/::op:1' and e['target'] == '/::op:0' and e['rendered']
               for e in g['edges'])


def test_unsupported_indexed_operand_does_not_create_fake_wire_even_when_nested():
    select = {'kind': 'ElementSelect', 'value': ref(2), 'selector': ref(3)}
    g = diagram(op('BitwiseXor', op('Add', select, ref(4)), ref(2)))
    inner = next(n for n in g['nodes'] if n.get('name') == 'Add')
    bad = [e for e in g['edges'] if e['target'] == inner['id'] and e['pin'] == 'A']
    assert len(bad) == 2 and all(e['rendered'] is False for e in bad)
    assert inner['operandStatus']['A'] == 'composite AST operand; no proven wire'
    assert any(e['source'] == inner['id'] and e['target'] == '/::op:0' and e['rendered']
               for e in g['edges'])


def test_ambiguous_sequential_writers_still_fail_closed_after_expansion():
    g = diagram(op('Add', op('Multiply', ref(2), ref(3)), ref(4)), two_writers=True)
    d = [e for e in g['edges'] if e['target'] == '/::sig:q' and e['type'] in ('sequential', 'data')]
    assert len(d) == 2 and not any(e['rendered'] for e in d)
    assert any(e['routingStatus'] == 'unresolved_D_mux' for e in d)
    assert next(n for n in g['nodes'] if n['id'] == '/::sig:q')['dInputStatus']


def test_nested_expression_depth_bounded_without_fictitious_conductor():
    rhs = ref(2)
    for _ in range(25):
        rhs = op('Add', rhs, ref(3))
    g = diagram(rhs)
    operators = [n for n in g['nodes'] if n['type'] == 'operator']
    assert len(operators) == 16
    deepest = operators[-1]
    fallback = [e for e in g['edges'] if e['target'] == deepest['id'] and e['pin'] == 'A']
    assert fallback and all(not e['rendered'] for e in fallback)
    assert deepest['operandStatus']['A']
    assert len(g['nodes']) <= 32


@pytest.mark.skipif(not shutil.which('node'), reason='Node.js and bundled ELK required')
def test_real_elk_geometry_of_nested_binary_chain():
    g = diagram(op('BitwiseXor', op('Add', ref(2), ref(3)), ref(4)))
    script = r'''
const fs=require('node:fs'), assert=require('node:assert/strict');
const g=JSON.parse(fs.readFileSync(0,'utf8')),w=process.argv[1];
const G=require(w+'/symbol-geometry.js'), A=require(w+'/elk-adapter.js');
const ELK=require(w+'/elk.bundled.js').default;
(async()=>{
 const l=await A.compute(new ELK(),g,G.boxSize);
 assert.equal(l.edgePaths.size,g.edges.filter(e=>e.rendered!==false).length);
 const inner=g.nodes.find(n=>n.name==='Add'),outer=g.nodes.find(n=>n.name==='BitwiseXor');
 const e=g.edges.find(e=>e.source===inner.id&&e.target===outer.id);
 const p=l.edgePaths.get(e.id);
 const q=G.absoluteAnchor(inner,l.positions.get(inner.id),'source',e);
 const r=G.absoluteAnchor(outer,l.positions.get(outer.id),'target',e);
 assert.deepEqual(p[0],[q.x,q.y]);assert.deepEqual(p.at(-1),[r.x,r.y]);
 assert.notEqual(e.net,g.edges.find(e=>e.source===outer.id&&e.target.endsWith('::sig:q')).net);
 console.log('AST nested routing validated');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    result = subprocess.run(['node', '-e', script, str(WEB)], input=json.dumps(g),
                            text=True, capture_output=True, timeout=30)
    assert result.returncode == 0, result.stderr + result.stdout
    assert 'nested routing validated' in result.stdout
