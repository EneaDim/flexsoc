"""Concatenations are ordered AST values, not a single unproven IN conductor.

The Ethernet-shaped MemberAccess tree is reduced from the actual Slang
serialization of ``{reg2hw.ctrl.tx_enable.q, reg2hw.ifg.q}``.
"""
import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def ref(number):
    return {'kind': 'NamedValue', 'symbol': f'{number} unknown'}


def field(base, name):
    return {'kind': 'MemberAccess', 'member': f'12345 {name}', 'value': base}


def graph(rhs):
    decl = [{'kind': 'Variable', 'name': name, 'addr': number}
            for number, name in ((1, 'out'), (2, 'a'), (3, 'b'), (4, 'reg2hw'))]
    decl.append({'kind': 'ContinuousAssign', 'left': ref(1), 'right': rhs})
    ast = {'design': {'members': [{'kind': 'Instance', 'name': 'dut',
                                  'body': {'kind': 'InstanceBody', 'name': 'dut', 'members': decl}}]}}
    return RtlDesign(ast, root=Path(__file__).parent, top='dut').diagram()


def incoming(g, node):
    return [e for e in g['edges'] if e['target'] == node['id'] and e['type'] == 'data']


def test_concat_two_struct_field_values_from_ethernet_slang_shape():
    first = field(field(field(ref(4), 'ctrl'), 'tx_enable'), 'q')
    second = field(field(ref(4), 'ifg'), 'q')
    g = graph({'kind': 'Concatenation', 'operands': [first, second]})
    concat = next(n for n in g['nodes'] if n.get('kind') == 'Concatenation')
    assert concat['pins'] == ['I0', 'I1', 'Y']
    assert set(e['pin'] for e in incoming(g, concat)) == {'I0', 'I1'}
    assert len(incoming(g, concat)) == 2
    assert all(e['rendered'] and e['mapping'] == 'expression' for e in incoming(g, concat))
    assert len(set(e['net'] for e in incoming(g, concat))) == 2
    assert len([n for n in g['nodes'] if n.get('kind') == 'MemberAccess']) == 5
    assert not concat.get('operandStatus')


def test_const_and_nested_concat_keep_exact_ordinal_pins():
    inner = {'kind': 'Concatenation', 'operands': [ref(2), ref(3)]}
    rhs = {'kind': 'Concatenation', 'operands': [
        {'kind': 'IntegerLiteral', 'value': "1'b0"}, inner,
        {'kind': 'Conversion', 'operand': ref(2)}]}
    g = graph(rhs)
    nodes = [n for n in g['nodes'] if n.get('kind') == 'Concatenation']
    assert len(nodes) == 2
    outer, nested = nodes
    assert outer['pins'] == ['I0', 'I1', 'I2', 'Y']
    assert outer['literalOperands'] == {'I0': "1'b0"}
    assert {(e['pin'], e['source']) for e in incoming(g, outer)} == {
        ('I1', nested['id']), ('I2', '/::op:2')}
    assert {(e['pin'], e['source']) for e in incoming(g, nested)} == {
        ('I0', '/::sig:a'), ('I1', '/::sig:b')}
    assert outer.get('operandStatus') is None


def test_unresolvable_concat_input_remains_a_visible_unwired_terminal():
    rhs = {'kind': 'Concatenation', 'operands': [ref(2),
           {'kind': 'Call', 'subroutine': 'opaque', 'arguments': []}, ref(3)]}
    g = graph(rhs)
    node = next(n for n in g['nodes'] if n.get('kind') == 'Concatenation')
    assert node['pins'] == ['I0', 'I1', 'I2', 'Y']
    assert node['operandStatus']['I1'] == 'AST operand unavailable'
    assert {e['pin'] for e in incoming(g, node) if e['rendered']} == {'I0', 'I2'}


def test_oversized_concat_does_not_fabricate_truncated_wiring():
    g = graph({'kind': 'Concatenation', 'operands': [ref(2)] * 33})
    node = next(n for n in g['nodes'] if n.get('kind') == 'Concatenation')
    assert node['pins'] == ['IN', 'Y']
    assert not any(e['rendered'] for e in incoming(g, node))
    assert node['operandStatus']['IN']


def test_replication_retains_subexpression_not_multiple_fake_wires():
    g = graph({'kind': 'Replication', 'count': {'kind': 'IntegerLiteral', 'constant': '3'},
               'concat': {'kind': 'Concatenation', 'operands': [ref(2), ref(3)]}})
    rep = next(n for n in g['nodes'] if n.get('kind') == 'Replication')
    concat = next(n for n in g['nodes'] if n.get('kind') == 'Concatenation')
    assert rep['pins'] == ['I0', 'Y'] and rep['repeatCount'] == 3
    assert [(e['source'], e['pin']) for e in incoming(g, rep)] == [(concat['id'], 'I0')]


@pytest.mark.skipif(not shutil.which('node'), reason='Node.js required for bundled ELK')
def test_concat_independent_pins_real_elk_and_canvas_anchors():
    g = graph({'kind': 'Concatenation', 'operands': [ref(2), ref(3),
               {'kind': 'IntegerLiteral', 'value': "1'b1"}]})
    script = r'''
const fs=require('node:fs'),assert=require('node:assert/strict');
const g=JSON.parse(fs.readFileSync(0,'utf8')),p=process.argv[1];
const G=require(p+'/symbol-geometry.js'), A=require(p+'/elk-adapter.js');
const ELK=require(p+'/elk.bundled.js').default;
(async()=>{
 const n=g.nodes.find(n=>n.kind==='Concatenation'), s=G.boxSize(n);
 assert.deepEqual(n.pins,['I0','I1','I2','Y']);
 assert(s.h>=80);
 assert.deepEqual(['I0','I1','I2'].map(pin=>G.anchor(n,'target',{pin},{w:s.w,h:s.h}).y),[20,40,60]);
 const result=await A.compute(new ELK(),g,G.boxSize);
 for(const e of g.edges.filter(e=>e.rendered!==false&&e.target===n.id)){
  const path=result.edgePaths.get(e.id), t=G.absoluteAnchor(n,result.positions.get(n.id),'target',e);
  assert.deepEqual(path.at(-1),[t.x,t.y]);
 }
 console.log('concat geometry ok');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    result = subprocess.run(['node', '-e', script, str(WEB)], input=json.dumps(g),
                            text=True, capture_output=True, timeout=35)
    assert result.returncode == 0, result.stderr + result.stdout
    assert 'concat geometry ok' in result.stdout
