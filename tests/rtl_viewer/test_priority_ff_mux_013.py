"""AST-proven priority D choices must not create multiple physical drivers."""
import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def ref(n, typ=None):
    result = {'kind': 'NamedValue', 'symbol': f'{n} unrelated_label'}
    if typ is not None:
        result['type'] = typ
    return result


def assign(dest, rhs):
    return {'kind': 'Assignment', 'left': dest, 'right': rhs}


def cond(n, true, false=None):
    result = {'kind': 'Conditional', 'conditions': [{'expr': ref(n, 'logic')}], 'ifTrue': true}
    if false is not None:
        result['ifFalse'] = false
    return result


def design(stmt, extras=(), *, multi_event=False):
    names = ['q', 'd', 'sel', 'clk', 'other', 'cond2', 'cond3', 'other_q']
    members = [{'kind': 'Variable', 'name': name, 'addr': i}
               for i, name in enumerate(names, 1)]
    timing = {'kind': 'SignalEvent', 'edge': 'PosEdge', 'expr': ref(4)}
    if multi_event:
        timing = {'kind': 'EventList', 'events': [timing,
                  {'kind': 'SignalEvent', 'edge': 'NegEdge', 'expr': ref(5)}]}
    members.append({'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF',
                    'body': {'kind': 'Timed', 'timing': timing, 'stmt': stmt}})
    members.extend(extras)
    ast = {'design': {'members': [{'kind': 'Instance', 'name': 'dut', 'body': {
        'kind': 'InstanceBody', 'name': 'dut', 'members': members}}]}}
    return RtlDesign(ast, root=Path(__file__).parent, top='dut').diagram()


def muxes(g):
    return [n for n in g['nodes'] if n.get('origin') == 'procedural_if_ast']


def cable(g, source, target, pin=None):
    return [e for e in g['edges'] if e['source'] == source and e['target'] == target
            and e['rendered'] and (pin is None or e['pin'] == pin)]


def d_drivers(g, dst='/::sig:q'):
    return [e for e in g['edges'] if e['target'] == dst and e['targetPin'] == 'D'
            and e['rendered']]


def test_else_if_priority_connected_through_mux_outputs_not_multiple_d_drivers():
    stmt = cond(3, assign(ref(1), ref(2)),
                cond(6, assign(ref(1), ref(5)), assign(ref(1), ref(1))))
    g = design(stmt)
    inner, outer = muxes(g)
    assert len(muxes(g)) == 2
    assert len(d_drivers(g)) == 1 and d_drivers(g)[0]['source'] == outer['id']
    assert cable(g, inner['id'], outer['id'], 'A')
    assert cable(g, '/::sig:d', outer['id'], 'B')
    assert cable(g, '/::sig:other', inner['id'], 'B')
    assert cable(g, '/::sig:q', inner['id'], 'A')
    assert cable(g, '/::sig:sel', outer['id'], 'S')
    assert cable(g, '/::sig:cond2', inner['id'], 'S')
    assert all(e['net'] != '/::sig:q' for e in d_drivers(g))
    assert all(not e['rendered'] for e in g['edges'] if e['type'] == 'control'
               and e['target'] == '/::sig:q')


def test_missing_else_from_chain_means_hold_q_and_nested_test_is_conditional():
    g = design(cond(3, assign(ref(1), ref(2)), cond(6, assign(ref(1), ref(5)))))
    inner, outer = muxes(g)
    assert cable(g, '/::sig:q', inner['id'], 'A')
    assert cable(g, inner['id'], outer['id'], 'A')
    assert len(d_drivers(g)) == 1
    assert not any(e['source'] == '/::sig:q' and e['target'] == '/::sig:q'
                   for e in d_drivers(g))


def test_true_branch_nested_if_and_single_statement_blocks():
    nested = cond(6, assign(ref(1), ref(2)), assign(ref(1), ref(5)))
    block = {'kind': 'Block', 'statements': [nested]}
    g = design(cond(3, block, assign(ref(1), ref(1))))
    inner, outer = muxes(g)
    assert cable(g, inner['id'], outer['id'], 'B')
    assert cable(g, '/::sig:q', outer['id'], 'A')
    assert len(d_drivers(g)) == 1


def test_each_leaf_expression_retains_distinct_conductor():
    add = {'kind': 'BinaryOp', 'op': 'Add', 'left': ref(1), 'right': ref(2)}
    xor = {'kind': 'BinaryOp', 'op': 'BitwiseXor', 'left': ref(5), 'right': ref(1)}
    g = design(cond(3, assign(ref(1), add), cond(6, assign(ref(1), xor))))
    assert len(muxes(g)) == 2
    assert len(d_drivers(g)) == 1
    lines = [e for e in g['edges'] if e['rendered'] and e['source'].startswith('/::op:')
             and e['target'].startswith('/::op:')]
    assert len(lines) >= 3
    assert all(e['net'] != '/::sig:q' for e in lines)


@pytest.mark.parametrize('stmt', [
    cond(3, assign(ref(1), ref(2)), cond(6, assign({'kind': 'ElementSelect', 'value': ref(1), 'selector': ref(5)}, ref(2)))),
    cond(3, assign(ref(1), ref(2)), {'kind': 'Block', 'body': [assign(ref(1), ref(5)), assign(ref(1), ref(2))]}),
    cond(3, assign(ref(1), ref(2)), {'kind': 'Conditional', 'condition': ref(6), 'ifTrue': assign(ref(1), ref(5))}),
])
def test_unsupported_nested_ast_fails_closed_without_physical_d_mux(stmt):
    g = design(stmt)
    assert not muxes(g)
    assert not d_drivers(g)
    assert any(e.get('routingStatus') == 'unresolved_D_mux' for e in g['edges'])


def test_other_writer_and_ambiguous_event_list_fail_closed():
    stmt = cond(3, assign(ref(1), ref(2)), cond(6, assign(ref(1), ref(5))))
    other = {'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF',
             'body': {'kind': 'Timed', 'stmt': assign(ref(1), ref(2))}}
    for g in (design(stmt, extras=(other,)), design(stmt, multi_event=True)):
        assert not muxes(g)
        assert not d_drivers(g)


def test_deep_tree_exceeds_bound_and_does_not_route_physical_d():
    node = assign(ref(1), ref(2))
    for _ in range(18):
        node = cond(3, node)
    g = design(node)
    assert not muxes(g)
    assert not d_drivers(g)


@pytest.mark.skipif(shutil.which('node') is None, reason='Node.js required for bundled real ELK')
def test_real_elk_preserves_mux_priority_pin_geometry_and_one_d_driver():
    g = design(cond(3, assign(ref(1), ref(2)), cond(6, assign(ref(1), ref(5)))))
    script = r'''
const fs=require('node:fs'),assert=require('node:assert/strict');
const g=JSON.parse(fs.readFileSync(0,'utf8')),w=process.argv[1];
const G=require(w+'/symbol-geometry.js'), A=require(w+'/elk-adapter.js');
const ELK=require(w+'/elk.bundled.js').default;
(async()=>{
 const out=await A.compute(new ELK(),g,G.boxSize);
 const drawn=g.edges.filter(e=>e.rendered!==false);
 assert.equal(out.edgePaths.size,drawn.length);
 const ms=g.nodes.filter(n=>n.origin==='procedural_if_ast');
 assert.equal(ms.length,2);
 const dy=drawn.filter(e=>e.targetPin==='D'&&e.target.endsWith('sig:q'));
 assert.equal(dy.length,1);
 const cascade=drawn.find(e=>e.source===ms[0].id&&e.target===ms[1].id);
 assert(cascade&&cascade.pin==='A');
 for(const e of [cascade,dy[0]]){
  const s=g.nodes.find(n=>n.id===e.source),t=g.nodes.find(n=>n.id===e.target);
  const path=out.edgePaths.get(e.id);
  const a=G.absoluteAnchor(s,out.positions.get(s.id),'source',e);
  const b=G.absoluteAnchor(t,out.positions.get(t.id),'target',e);
  assert.deepEqual(path[0],[a.x,a.y]);assert.deepEqual(path.at(-1),[b.x,b.y]);
 }
 console.log('ELK priority tree PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    result = subprocess.run(['node','-e',script,str(WEB)],input=json.dumps(g),
                            capture_output=True,text=True,timeout=45)
    assert result.returncode == 0, result.stdout + result.stderr


def test_nested_dynamic_read_has_own_select_node_and_single_d_driver():
    indexed = {'kind': 'ElementSelect', 'value': ref(2), 'selector': ref(5)}
    g = design(cond(3, assign(ref(1), ref(2)), cond(6, assign(ref(1), indexed))))
    selects = [n for n in g['nodes'] if n.get('name') == 'IndexedSelect']
    assert len(selects) == 1
    assert len(muxes(g)) == 2
    assert len(d_drivers(g)) == 1
    for pin, source in [('A', '/::sig:d'), ('S', '/::sig:other')]:
        assert any(e['source'] == source and e['target'] == selects[0]['id']
                   and e['pin'] == pin and e['rendered'] for e in g['edges'])
    assert any(e['source'] == selects[0]['id'] and e['rendered']
               and e['target'] in {m['id'] for m in muxes(g)} for e in g['edges'])
