"""Ordered nonblocking writes: project only AST-proven sequential D value.

These are synthetic compiler-shaped AST cases, not evidence of real Slang elaboration.
"""
import json
from pathlib import Path
import shutil
import subprocess

import pytest
from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def ref(addr, typed=False):
    d = {'kind': 'NamedValue', 'symbol': f'{addr} misleading_name'}
    if typed:
        d['type'] = 'logic'
    return d


def write(addr, rhs, *, nba=True):
    return {'kind': 'Assignment', 'left': ref(addr), 'right': rhs,
            'isNonBlocking': nba}


def cond(sel, true, false=None):
    c = {'kind': 'Conditional', 'condition': ref(sel, True), 'ifTrue': true}
    if false is not None:
        c['ifFalse'] = false
    return c


def block(*statements):
    return {'kind': 'Block', 'body': list(statements)}


def graph(stmt, *, extras=(), event=True):
    members = [{'kind': 'Variable', 'name': n, 'addr': i}
               for i, n in enumerate(('q', 'a', 'sel', 'clk', 'b', 'sel2', 'other_q'), 1)]
    body = {'kind': 'Timed', 'stmt': stmt,
            'timing': {'kind': 'SignalEvent', 'edge': 'PosEdge', 'expr': ref(4)} if event
                      else {'kind': 'EventList', 'events': []}}
    members.append({'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF', 'body': body})
    members.extend(extras)
    ast = {'design': {'members': [{'kind': 'Instance', 'name': 'dut',
                                  'body': {'kind': 'InstanceBody', 'name': 'dut', 'members': members}}]}}
    return RtlDesign(ast, root=Path(__file__).parent, top='dut').diagram()


def wires(g, target='/::sig:q'):
    return [e for e in g['edges'] if e['target'] == target and e['rendered']
            and e['targetPin'] == 'D']


def muxes(g):
    return [n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']


def pin(g, dest, name):
    return [e for e in g['edges'] if e['target'] == dest and e['pin'] == name and e['rendered']]


def test_last_nba_wins_in_two_unconditional_writes():
    g = graph(block(write(1, ref(2)), write(1, ref(5))))
    assert len(wires(g)) == 1 and wires(g)[0]['source'] == '/::sig:b'
    assert not muxes(g)
    assert wires(g)[0]['mapping'] == 'procedural_last_nba'


def test_nba_followed_by_conditional_override_uses_previous_scheduled_value():
    g = graph(block(write(1, ref(2)), cond(3, write(1, ref(5)))))
    m, = muxes(g)
    assert {e['source'] for e in pin(g, m['id'], 'A')} == {'/::sig:a'}
    assert {e['source'] for e in pin(g, m['id'], 'B')} == {'/::sig:b'}
    assert {e['source'] for e in pin(g, m['id'], 'S')} == {'/::sig:sel'}
    assert len(wires(g)) == 1 and wires(g)[0]['source'] == m['id']
    assert not pin(g, m['id'], 'A')[0]['sourcePin'] == 'Q'


def test_conditional_nba_then_unconditional_nba_overrides_earlier_mux():
    g = graph(block(cond(3, write(1, ref(2))), write(1, ref(5))))
    assert not muxes(g)
    assert [e['source'] for e in wires(g)] == ['/::sig:b']


def test_two_guarded_nbas_form_last_write_priority_chain():
    g = graph(block(write(1, ref(2)), cond(3, write(1, ref(5))),
                    cond(6, write(1, ref(1)))))
    ms = muxes(g)
    assert len(ms) == 2
    inner, outer = ms
    assert {e['source'] for e in pin(g, outer['id'], 'A')} == {inner['id']}
    assert {e['source'] for e in pin(g, outer['id'], 'B')} == {'/::sig:q'}
    assert len(wires(g)) == 1 and wires(g)[0]['source'] == outer['id']


def test_nonblocking_feedback_read_uses_q_not_intermediate_scheduled_d():
    add = {'kind': 'BinaryOp', 'op': 'Add', 'left': ref(1), 'right': ref(2)}
    g = graph(block(write(1, ref(5)), cond(3, write(1, add))))
    m, = muxes(g)
    op = next(n for n in g['nodes'] if n['type'] == 'operator' and n['shape'] == 'arith')
    assert {e['source'] for e in pin(g, op['id'], 'A')} == {'/::sig:q'}
    assert {e['source'] for e in pin(g, m['id'], 'A')} == {'/::sig:b'}
    assert len(wires(g)) == 1 and wires(g)[0]['source'] == m['id']


@pytest.mark.parametrize('stmt', [
    block(write(1, ref(2), nba=False), write(1, ref(5))),
    block(write(1, ref(2)), write(1, ref(5), nba=False)),
    block(write(1, ref(2)), {'kind': 'Assignment', 'left': ref(1), 'right': ref(5)}),
    block(write(1, ref(2)), {'kind': 'Case', 'expr': ref(3)}),
])
def test_unsupported_sequence_fails_closed_without_any_claimed_d(stmt):
    g = graph(stmt)
    assert not wires(g) and not muxes(g)
    assert any(e.get('routingStatus') == 'unresolved_D_mux' for e in g['edges'])


def test_second_process_writer_or_event_list_prevents_nba_composition():
    other = {'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF',
             'body': {'kind': 'Timed', 'stmt': write(1, ref(5))}}
    stmt = block(write(1, ref(2)), cond(3, write(1, ref(5))))
    for g in [graph(stmt, extras=(other,)), graph(stmt, event=False)]:
        assert not wires(g) and not muxes(g)


def test_single_guarded_write_without_nba_flag_still_supported_as_before():
    stmt = cond(3, {'kind': 'Assignment', 'left': ref(1), 'right': ref(2)},
                {'kind': 'Assignment', 'left': ref(1), 'right': ref(5)})
    assert len(muxes(graph(stmt))) == 1


@pytest.mark.skipif(shutil.which('node') is None, reason='Node.js ELK not installed')
def test_real_elk_keeps_ordered_mux_nets_and_d_terminal_separate():
    g = graph(block(write(1, ref(2)), cond(3, write(1, ref(5))),
                    cond(6, write(1, ref(1)))))
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
 console.log('ELK ordered NBA PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    r = subprocess.run(['node', '-e', js, str(WEB)], input=json.dumps(g), text=True,
                       capture_output=True, timeout=45)
    assert r.returncode == 0, r.stdout+r.stderr


def test_two_nba_writes_inside_conditional_branch_are_ordered():
    g = graph(block(write(1, ref(2)),
                    cond(3, block(write(1, ref(1)), write(1, ref(5))))))
    m, = muxes(g)
    assert {e['source'] for e in pin(g, m['id'], 'B')} == {'/::sig:b'}
    assert {e['source'] for e in pin(g, m['id'], 'A')} == {'/::sig:a'}
    assert len(wires(g)) == 1


def test_final_literal_without_a_proven_constant_source_fails_closed():
    g = graph(block(write(1, ref(2)), write(1, {'kind': 'IntegerLiteral', 'value': "1'b0"})))
    assert not wires(g)
    assert any(e.get('routingStatus') == 'unresolved_D_mux' for e in g['edges'])


def test_last_nba_can_read_dynamic_index_without_shorting_select_and_data():
    selected = {'kind': 'ElementSelect', 'value': ref(5), 'selector': ref(3)}
    g = graph(block(write(1, ref(2)), write(1, selected)))
    selection = [n for n in g['nodes'] if n.get('name') == 'IndexedSelect']
    assert len(selection) == 1
    assert len(wires(g)) == 1
    assert any(e['target'] == selection[0]['id'] and e['pin'] == 'A'
               and e['rendered'] for e in g['edges'])
    assert any(e['target'] == selection[0]['id'] and e['pin'] == 'S'
               and e['rendered'] for e in g['edges'])
