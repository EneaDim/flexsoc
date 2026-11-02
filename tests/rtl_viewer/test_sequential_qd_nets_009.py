"""Compiler-AST-based D/Q net ownership: different SV uses, same declaration.

Synthetic elaborated AST fixtures assert semantic projection; actual ELK
routing is independently exercised with the bundled implementation below.
"""
import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def sig(name, addr):
    return {'kind': 'Variable', 'name': name, 'addr': addr, 'type': 'logic[31:0]'}


def ref(addr):
    return {'kind': 'NamedValue', 'symbol': f'{addr} misleading_alias'}


def write(dest, rhs):
    return {'kind': 'Assignment', 'left': ref(dest), 'right': rhs}


def add_q(addr):
    return {'kind': 'BinaryOp', 'op': 'Add', 'left': ref(addr),
            'right': {'kind': 'IntegerLiteral', 'value': "32'd1"}}


def design(stmt):
    member = {'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF',
              'body': {'kind': 'Timed',
                       'timing': {'kind': 'SignalEvent', 'edge': 'PosEdge', 'expr': ref(4)},
                       'stmt': stmt}}
    members = [sig('q', 1), sig('data', 2), sig('enable', 3), sig('clk', 4), member]
    ast = {'design': {'members': [{'kind': 'Instance', 'name': 'dut',
            'body': {'kind': 'InstanceBody', 'name': 'dut', 'members': members}}]}}
    return RtlDesign(ast, root=Path(__file__).parent, top='dut').diagram()


def test_q_read_and_d_write_are_distinct_physical_nets():
    graph = design(write(1, add_q(1)))
    op = next(node for node in graph['nodes'] if node['type'] == 'operator')
    q = '/::sig:q'
    rhs = next(edge for edge in graph['edges'] if edge['source'] == q and edge['target'] == op['id'])
    lhs = next(edge for edge in graph['edges'] if edge['source'] == op['id'] and edge['target'] == q)
    clock = next(edge for edge in graph['edges'] if edge['type'] == 'event')
    assert rhs['net'] == q
    assert lhs['net'] == '/::expr:op:0'
    assert lhs['signal'] == q, 'retain the declaration for inspection / AST provenance'
    assert rhs['net'] != lhs['net']
    assert rhs['sourcePin'] == 'Q'
    assert lhs['sourcePin'] == 'Y' and lhs['targetPin'] == 'D'
    assert clock['pin'] == 'CLK' and clock['targetPin'] == ''
    assert lhs['rendered'] and rhs['rendered']


def test_guard_is_a_dependency_not_a_second_electrical_d_driver():
    guarded = {'kind': 'Conditional', 'condition': ref(3),
               'ifTrue': write(1, add_q(1)), 'ifFalse': write(1, add_q(1))}
    graph = design(guarded)
    controls = [e for e in graph['edges'] if e['type'] == 'control' and e['target'] == '/::sig:q']
    assert controls and all(e['rendered'] is False for e in controls)
    assert all(e['targetPin'] == 'D' for e in controls)
    assert any(e['type'] == 'event' and e['rendered'] for e in graph['edges'])


def test_unlowered_conditional_writes_fail_closed_instead_of_two_d_drivers():
    guarded = {'kind': 'Conditional', 'condition': ref(3),
               'ifTrue': write(1, add_q(1)), 'ifFalse': write(1, ref(2))}
    # An indexed selector is not a proven one-bit predicate conductor.
    guarded['condition'] = {'kind': 'ElementSelect', 'value': ref(3), 'selector': ref(2)}
    graph = design(guarded)
    q = '/::sig:q'
    data_paths = [e for e in graph['edges'] if e['target'] == q and e['type'] in ('data', 'sequential')]
    assert len(data_paths) == 2, 'retain both AST dependencies'
    assert all(e['rendered'] is False and e['routingStatus'] == 'unresolved_D_mux' for e in data_paths)
    assert next(n for n in graph['nodes'] if n['id'] == q)['dInputStatus'] == 'unresolved conditional D input'
    assert any(e['type'] == 'event' and e['rendered'] for e in graph['edges'])


def test_real_elk_route_keeps_q_feedback_off_d_expression_net():
    if not shutil.which('node'):
        pytest.skip('Node not available')
    graph = design(write(1, add_q(1)))
    code = r'''
const assert=require('node:assert/strict');
const fs=require('fs');const W=process.argv[1];
const graph=JSON.parse(fs.readFileSync(0,'utf8'));
const G=require(W+'/symbol-geometry.js'), A=require(W+'/elk-adapter.js');
const L=require(W+'/layout-engine.js');
const vm=require('vm');const app=fs.readFileSync(W+'/app.js','utf8');
const from=app.indexOf('// FSRTL-0029 net-based Canvas paint');
const to=app.indexOf('// FSRTL-0029 net-based Canvas paint. Only geometry',from+1);
const context={globalThis:{}};vm.runInNewContext(app.slice(from,to),context);
const N=context.globalThis.FlexNetGeometry;
const ELK=require(W+'/elk.bundled.js').default;
const q=graph.nodes.find(n=>n.name==='q');
const incoming=graph.edges.find(e=>e.target===q.id&&e.type==='sequential');
const feedback=graph.edges.find(e=>e.source===q.id&&e.type==='data');
assert(incoming&&feedback&&incoming.net!==feedback.net);
const eg=A.convert(graph,G.boxSize);const reg=eg.children.find(n=>n.id===q.id);
assert(reg.ports.some(p=>p.id.includes('target')));
assert(reg.ports.some(p=>p.id.includes('source')));
(async()=>{
 const layout=await A.compute(new ELK(),graph,G.boxSize);
 assert.equal(layout.edgePaths.size,graph.edges.length);
 assert.equal(L.validate(graph,layout).ok,true);
 const qAnchor=G.absoluteAnchor(q,layout.positions.get(q.id),'source',feedback);
 const dAnchor=G.absoluteAnchor(q,layout.positions.get(q.id),'target',incoming);
 assert(qAnchor.x>dAnchor.x&&qAnchor.y===dAnchor.y);
 const pathQ=layout.edgePaths.get(feedback.id),pathD=layout.edgePaths.get(incoming.id);
 assert.deepEqual(pathQ[0],[qAnchor.x,qAnchor.y]);
 assert.deepEqual(pathD.at(-1),[dAnchor.x,dAnchor.y]);
 const bundles=N.segmentsFor(graph.edges,layout.edgePaths);
 assert(bundles.some(g=>g.net===feedback.net));
 assert(bundles.some(g=>g.net===incoming.net));
 assert.notEqual(bundles.find(g=>g.net===feedback.net),bundles.find(g=>g.net===incoming.net));
 console.log('ELK Q/D independent conductors PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    result = subprocess.run(['node', '-e', code, str(WEB)], input=json.dumps(graph),
                            capture_output=True, text=True, timeout=45)
    assert result.returncode == 0, result.stdout + result.stderr
    assert 'independent conductors PASS' in result.stdout


def test_elk_excludes_non_electrical_dependencies_without_deleting_ast_facts():
    if not shutil.which('node'):
        pytest.skip('Node not available')
    graph = design({'kind': 'Conditional', 'condition': ref(3), 'ifTrue': write(1, ref(2))})
    code = r'''
const assert=require('node:assert/strict'),fs=require('fs');
const W=process.argv[1],g=JSON.parse(fs.readFileSync(0,'utf8'));
const G=require(W+'/symbol-geometry.js'), A=require(W+'/elk-adapter.js');
const L=require(W+'/layout-engine.js'),ELK=require(W+'/elk.bundled.js').default;
(async()=>{
 const input=A.convert(g,G.boxSize);const expected=g.edges.filter(e=>e.rendered!==false);
 assert.equal(input.edges.length,expected.length);
 assert(g.edges.some(e=>e.rendered===false&&e.type==='control'));
 const result=await A.compute(new ELK(),g,G.boxSize);
 assert.equal(result.edgePaths.size,expected.length);
 assert.equal(L.validate(g,result).ok,true);
 assert(g.edges.filter(e=>e.rendered===false).every(e=>!result.edgePaths.has(e.id)));
 console.log('DEPENDENCIES NOT WIRES PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    result = subprocess.run(['node', '-e', code, str(WEB)], input=json.dumps(graph),
                            capture_output=True, text=True, timeout=45)
    assert result.returncode == 0, result.stdout + result.stderr
