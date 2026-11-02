"""Only complete compiler-backed always_ff choices become physical D MUXs.

Synthetic elaborated AST; a real Slang smoke test is a separate acceptance step.
"""
from pathlib import Path
import json
import shutil
import subprocess

import pytest
from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def ref(addr):
    return {'kind': 'NamedValue', 'symbol': f'{addr} misleading_alias',
            **({'type': 'logic'} if addr == 3 else {})}


def assignment(dest, rhs):
    return {'kind': 'Assignment', 'left': ref(dest), 'right': rhs}


def binop(name, x, y):
    return {'kind': 'BinaryOp', 'op': name, 'left': x, 'right': y}


def ifelse(true, false=None, condition=None):
    result = {'kind': 'Conditional', 'condition': condition or ref(3), 'ifTrue': true}
    if false is not None:
        result['ifFalse'] = false
    return result


def graph(stmt, extras=()):
    members = [dict(kind='Variable', name=name, addr=index)
               for index, name in enumerate(('q', 'd', 'sel', 'clk', 'other'), 1)]
    members += [{'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF',
                 'body': {'kind': 'Timed', 'timing': {'kind': 'SignalEvent',
                          'edge': 'PosEdge', 'expr': ref(4)}, 'stmt': stmt}}, *extras]
    ast = {'design': {'members': [{'kind': 'Instance', 'name': 'dut', 'body': {
        'kind': 'InstanceBody', 'name': 'dut', 'members': members}}]}}
    return RtlDesign(ast, root=Path(__file__).parent, top='dut').diagram()


def wires_to(g, target, *, pin=None, rendered=True):
    return [e for e in g['edges'] if e['target'] == target and e['rendered'] == rendered
            and (pin is None or e['pin'] == pin)]


def mux(g):
    matches = [n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']
    assert len(matches) == 1
    return matches[0]


def test_complete_if_else_maps_select_true_false_to_distinct_mux_pins():
    g = graph(ifelse(assignment(1, binop('Add', ref(1), ref(2))), assignment(1, ref(5))))
    m = mux(g)
    assert (m['shape'], m['pins']) == ('mux', ['A', 'B', 'S', 'Y'])
    assert {e['source'] for e in wires_to(g, m['id'], pin='A')} == {'/::sig:other'}
    assert {e['source'] for e in wires_to(g, m['id'], pin='S')} == {'/::sig:sel'}
    upstream = wires_to(g, m['id'], pin='B')
    assert len(upstream) == 1 and upstream[0]['source'].startswith('/::op:')
    assert upstream[0]['net'] != '/::sig:q'
    direct_d = [e for e in wires_to(g, '/::sig:q') if e['targetPin'] == 'D']
    assert len(direct_d) == 1 and direct_d[0]['source'] == m['id']
    assert direct_d[0]['net'] == '/::expr:' + m['id'].split('::')[1]
    assert 'dInputStatus' not in next(n for n in g['nodes'] if n['id'] == '/::sig:q')
    assert all(not e['rendered'] for e in g['edges'] if e['type'] == 'control' and e['target'] == '/::sig:q')


def test_if_without_else_uses_q_hold_on_a_and_data_on_b():
    g = graph(ifelse(assignment(1, ref(2))))
    m = mux(g)
    hold = wires_to(g, m['id'], pin='A')
    data = wires_to(g, m['id'], pin='B')
    assert len(hold) == 1 and hold[0]['source'] == '/::sig:q'
    assert hold[0]['sourcePin'] == 'Q' and hold[0]['mapping'] == 'sequential_hold'
    assert len(data) == 1 and data[0]['source'] == '/::sig:d'
    assert m['operandDetails']['A'] == 'Q (hold)'
    assert all(e['net'] != '/::sig:q' for e in wires_to(g, '/::sig:q') if e['type'] == 'sequential')


def test_if_without_true_branch_uses_q_hold_on_b():
    g = graph({'kind': 'Conditional', 'condition': ref(3), 'ifFalse': assignment(1, ref(2))})
    m = mux(g)
    assert wires_to(g, m['id'], pin='B')[0]['source'] == '/::sig:q'
    assert wires_to(g, m['id'], pin='A')[0]['source'] == '/::sig:d'


def test_constant_branch_is_not_a_fictitious_net():
    g = graph(ifelse(assignment(1, {'kind': 'IntegerLiteral', 'value': "1'b0"}), assignment(1, ref(2))))
    m = mux(g)
    assert m['literalOperands']['B'] == "1'b0"
    assert not wires_to(g, m['id'], pin='B')
    assert wires_to(g, m['id'], pin='A')[0]['source'] == '/::sig:d'


def test_guarded_mux_can_lower_two_nested_expression_branches():
    g = graph(ifelse(assignment(1, binop('Add', ref(1), ref(2))),
                     assignment(1, binop('BitwiseXor', ref(1), ref(5)))))
    m = mux(g)
    upstream = [e for e in wires_to(g, m['id']) if e['pin'] in ('A', 'B')]
    assert {e['pin'] for e in upstream} == {'A', 'B'}
    assert len({e['net'] for e in upstream}) == 2
    assert len(wires_to(g, '/::sig:q')) == 2  # clock + single physical D


def test_other_writer_in_same_scope_prevents_mux_inference():
    other = {'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF',
             'body': {'kind': 'Timed', 'stmt': assignment(1, ref(5))}}
    g = graph(ifelse(assignment(1, ref(2))), extras=(other,))
    assert not [n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']


@pytest.mark.parametrize('stmt', [
    ifelse(assignment(1, ref(2)), assignment(1, ref(5)),
           {'kind': 'ElementSelect', 'value': ref(3), 'selector': ref(5)}),
    ifelse({'kind': 'Assignment', 'left': {'kind': 'ElementSelect',
            'value': ref(1), 'selector': ref(5)}, 'right': ref(2)}),
    ifelse(assignment(1, {'kind': 'ElementSelect', 'value': ref(2), 'selector': ref(5)})),
    ifelse(assignment(1, ref(2)), assignment(5, ref(1))),
])
def test_unsupported_guarded_writes_do_not_invent_mux(stmt):
    g = graph(stmt)
    assert not [n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']
    assert all(e['rendered'] is False for e in g['edges'] if e['type'] == 'control' and e['target'] == '/::sig:q')


def test_slang_style_single_condition_wrapper_is_supported():
    stmt = {'kind': 'Conditional', 'conditions': [{'expr': ref(3)}],
            'ifTrue': assignment(1, ref(2)), 'ifFalse': assignment(1, ref(5))}
    g = graph(stmt)
    assert wires_to(g, mux(g)['id'], pin='S')[0]['source'] == '/::sig:sel'


def test_multi_event_alwaysff_does_not_claim_synchronous_mux():
    stmt = ifelse(assignment(1, ref(2)), assignment(1, ref(5)))
    members = [{'kind': 'Variable', 'name': n, 'addr': i}
               for i, n in enumerate(('q','d','sel','clk','other'), 1)]
    members.append({'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF',
                    'body': {'kind': 'Timed', 'timing': {'kind': 'EventList', 'events': [
                        {'kind': 'SignalEvent', 'edge': 'PosEdge', 'expr': ref(4)},
                        {'kind': 'SignalEvent', 'edge': 'NegEdge', 'expr': ref(3)}]},
                             'stmt': stmt}})
    ast = {'design': {'members': [{'kind': 'Instance', 'name': 'dut', 'body': {
        'kind': 'InstanceBody', 'name': 'dut', 'members': members}}]}}
    g = RtlDesign(ast, root=Path(__file__).parent, top='dut').diagram()
    assert not [n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']
    assert all(not e['rendered'] for e in g['edges']
               if e['target'] == '/::sig:q' and e['type'] == 'sequential')


def test_unsupported_single_guarded_writer_never_claims_unconditional_d_wire():
    g = graph(ifelse(assignment(1, ref(2)),
                     condition={'kind': 'ElementSelect', 'value': ref(3), 'selector': ref(5)}))
    paths = [e for e in g['edges'] if e['target'] == '/::sig:q' and e['type'] == 'sequential']
    assert len(paths) == 1 and not paths[0]['rendered']
    assert paths[0]['routingStatus'] == 'unresolved_D_mux'
    assert next(n for n in g['nodes'] if n['id'] == '/::sig:q')['dInputStatus']


def test_nested_guard_preserves_outer_condition_as_an_explicit_mux():
    nested = ifelse(assignment(1, ref(2)), assignment(1, ref(5)))
    g = graph(ifelse(nested))
    muxes = [n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']
    assert len(muxes) == 2
    assert len([e for e in wires_to(g, '/::sig:q') if e['targetPin'] == 'D']) == 1
    assert {e['source'] for e in wires_to(g, muxes[-1]['id'], pin='B')} == {muxes[0]['id']}
    assert {e['source'] for e in wires_to(g, muxes[-1]['id'], pin='A')} == {'/::sig:q'}


def test_multibit_truth_predicate_requires_explicit_boolean_lowering():
    sel = ref(3)
    sel['type'] = 'logic[7:0]'
    g = graph(ifelse(assignment(1, ref(2)), assignment(1, ref(5)), sel))
    assert not [n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']
    assert all(not e['rendered'] for e in g['edges']
               if e['target'] == '/::sig:q' and e['type'] == 'sequential')


def test_untyped_predicate_does_not_create_unproved_select_wire():
    sel = ref(3)
    sel.pop('type')
    g = graph(ifelse(assignment(1, ref(2)), assignment(1, ref(5)), sel))
    assert not [n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']


@pytest.mark.skipif(shutil.which('node') is None, reason='Node.js required for real bundled ELK')
def test_actual_elk_routes_mux_only_once_into_d_and_routes_hold_from_q():
    g = graph(ifelse(assignment(1, binop('Add', ref(1), ref(2)))))
    script = r'''
const fs=require('node:fs'),assert=require('node:assert/strict');
const g=JSON.parse(fs.readFileSync(0,'utf8')),w=process.argv[1];
const G=require(w+'/symbol-geometry.js'), A=require(w+'/elk-adapter.js');
const ELK=require(w+'/elk.bundled.js').default;
(async()=>{
 const out=await A.compute(new ELK(),g,G.boxSize);
 const drawn=g.edges.filter(e=>e.rendered!==false);
 assert.equal(out.edgePaths.size,drawn.length);
 const m=g.nodes.find(n=>n.origin==='procedural_if_ast'), q=g.nodes.find(n=>n.name==='q');
 const hold=drawn.find(e=>e.source===q.id&&e.target===m.id&&e.pin==='A');
 const input=drawn.find(e=>e.source===m.id&&e.target===q.id);
 assert(hold&&input&&hold.net!==input.net);
 for(const e of [hold,input]){
  const s=g.nodes.find(n=>n.id===e.source),t=g.nodes.find(n=>n.id===e.target);
  const path=out.edgePaths.get(e.id);
  const a=G.absoluteAnchor(s,out.positions.get(s.id),'source',e);
  const b=G.absoluteAnchor(t,out.positions.get(t.id),'target',e);
  assert.deepEqual(path[0],[a.x,a.y]);assert.deepEqual(path.at(-1),[b.x,b.y]);
 }
 console.log('ELK procedural D mux PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    result = subprocess.run(['node', '-e', script, str(WEB)], input=json.dumps(g),
                            capture_output=True, text=True, timeout=45)
    assert result.returncode == 0, result.stdout + result.stderr
