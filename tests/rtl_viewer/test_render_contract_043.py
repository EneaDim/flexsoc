"""Property checks for compiler graph -> virtual blocks -> ELK/Canvas.

Unlike screenshot-only regressions, these assert edge identity, attribution,
terminal directions, and exact physical anchors for arbitrary process layouts.
"""
from __future__ import annotations

import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def _struct_writer_ast():
    """Two process owners: FF data is consumed by a COMB struct field write."""
    def ref(index):
        return {'kind': 'NamedValue', 'symbol': f'{index} compiler'}

    def assign(lhs, rhs, nba=False):
        return {'kind': 'Assignment', 'left': lhs, 'right': rhs, 'isNonBlocking': nba}

    def field(member):
        return {'kind': 'MemberAccess', 'value': ref(4), 'member': member,
                'type': 'logic'}

    members = [
        {'kind': 'Variable', 'addr': 1, 'name': 'clk'},
        {'kind': 'Variable', 'addr': 2, 'name': 'input_data'},
        {'kind': 'Variable', 'addr': 3, 'name': 'q'},
        {'kind': 'Port', 'addr': 40, 'name': 'hw2reg', 'direction': 'Out', 'internalSymbol': '4 hw2reg'},
        {'kind': 'Variable', 'addr': 4, 'name': 'hw2reg'},
        {'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF', 'source_line': 10,
         'body': {'kind': 'Timed', 'timing': {'kind': 'SignalEvent', 'edge': 'PosEdge', 'expr': ref(1)},
                  'stmt': assign(ref(3), ref(2), True)}},
        {'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysComb', 'source_line': 20,
         'body': {'kind': 'Block', 'body': {'kind': 'List', 'list': [
             assign(field('101 data'), ref(3)),
             assign(field('102 valid'), {'kind': 'Conversion', 'type': 'logic', 'operand': ref(2)}),
         ]}}},
    ]
    return {'design': {'members': [{'kind': 'Instance', 'name': 'demo',
            'body': {'kind': 'InstanceBody', 'name': 'demo', 'members': members}}]}}


def _node_case(tmp_path: Path, script: str, graph: dict, *, timeout: int = 35):
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    graph_file = tmp_path / 'graph.json'
    graph_file.write_text(json.dumps(graph))
    proc = subprocess.run(['node', '-e', script, str(WEB), str(graph_file)],
                          capture_output=True, text=True, timeout=timeout)
    assert proc.returncode == 0, proc.stderr + proc.stdout
    return proc.stdout


def test_each_direct_partial_write_is_attributed_to_its_actual_process():
    graph = RtlDesign(_struct_writer_ast(), root=Path.cwd(), top='demo').diagram(limit=128)
    ff = next(p for p in graph['processGroups'] if p['kind'] == 'always_ff')
    comb = next(p for p in graph['processGroups'] if p['kind'] == 'always_comb')
    assert ff['partialPortInputs'] == []
    assert len(comb['partialPortInputs']) == 1
    assert comb['partialPortInputs'][0]['source'].endswith('::sig:q')
    assert comb['partialPortInputs'][0]['target'].endswith('::sig:hw2reg')
    assert all('hw2reg' not in s for s in ff['targets'])


def test_compact_struct_writes_are_inputs_to_comb_not_bypass_drivers(tmp_path):
    graph = RtlDesign(_struct_writer_ast(), root=Path.cwd(), top='demo').diagram(limit=128)
    script = r'''
const assert=require('node:assert/strict');const fs=require('node:fs');
const W=process.argv[1],P=require(W+'/virtual-process.js'),C=require(W+'/render-contract.js');
const G=require(W+'/symbol-geometry.js'),A=require(W+'/elk-adapter.js'),
 ELK=require(W+'/elk.bundled.js').default;
const original=JSON.parse(fs.readFileSync(process.argv[2]));
(async()=>{
 const compact=P.project(original),check=C.checkProjection(original,compact);
 assert.deepEqual(check.errors,[],JSON.stringify(check.errors));
 const ff=compact.nodes.find(n=>n.type==='process_group'&&n.name.startsWith('always_ff'));
 const comb=compact.nodes.find(n=>n.type==='process_group'&&n.name.startsWith('always_comb'));
 const hw=compact.nodes.find(n=>n.name==='hw2reg');
 assert(ff&&comb&&hw);
 assert(!ff.ports.some(p=>p.direction==='output'&&p.name.includes('hw2reg')),
   'a sequential producer must not claim an aggregate output written by another process');
 assert(comb.ports.some(p=>p.direction==='output'&&p.name.endsWith(':hw2reg')));
 const redirected=compact.edges.filter(e=>e.processProjection==='partial-field input');
 assert.equal(redirected.length,1);
 assert.equal(redirected[0].source,ff.id);
 assert.equal(redirected[0].target,comb.id);
 assert(redirected[0].sourcePin.endsWith(':q'));
 assert(redirected[0].targetPin.endsWith(':q'));
 assert(!compact.edges.some(e=>e.source===ff.id&&e.target===hw.id),
  'an upstream FF cannot bypass the actual always_comb writer');
 assert(compact.edges.some(e=>e.source===comb.id&&e.target===hw.id));
 assert(compact.edges.every(e=>original.edges.some(o=>o.id===e.id)));
 const elk=await C.checkLayout(compact,new ELK());
 assert.deepEqual(elk.errors,[],JSON.stringify(elk.errors));
 console.log('COMPACT STRUCT WRITE CONTRACT PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    assert 'CONTRACT PASS' in _node_case(tmp_path, script, graph)


def test_validator_catches_fabricated_edge_and_miswired_virtual_terminal(tmp_path):
    graph = RtlDesign(_struct_writer_ast(), root=Path.cwd(), top='demo').diagram(limit=128)
    script = r'''
const assert=require('node:assert/strict');const fs=require('node:fs');
const W=process.argv[1],P=require(W+'/virtual-process.js'),C=require(W+'/render-contract.js');
const original=JSON.parse(fs.readFileSync(process.argv[2])),compact=P.project(original);
const broken={...compact,edges:[...compact.edges]};
broken.edges.push({...compact.edges[0],id:'invented-edge-777'});
assert(C.checkProjection(original,broken).errors.some(e=>e.code==='invented_edge'));
const broken2=JSON.parse(JSON.stringify(compact));
const rewritten=broken2.edges.find(e=>e.target.includes('procgroup:'));
assert(rewritten);rewritten.targetPin='CLK:injected';
assert(C.checkProjection(original,broken2).errors.some(e=>e.code==='missing_group_terminal'));
const broken3=JSON.parse(JSON.stringify(compact));
const port=broken3.nodes.find(n=>n.type==='process_group');
assert(port);port.ports.find(p=>p.direction==='input').direction='output';
assert(C.checkProjection(original,broken3).errors.some(e=>e.code==='missing_group_terminal'));
console.log('NEGATIVE CONTRACTS PASS');
'''
    assert 'NEGATIVE CONTRACTS PASS' in _node_case(tmp_path, script, graph)


def test_render_audit_invocation_and_machine_report(tmp_path):
    graph = _struct_writer_ast()
    astfile = tmp_path / 'ast.json'
    report = tmp_path / 'report.json'
    astfile.write_text(json.dumps(graph))
    script = Path(__file__).resolve().parents[2] / 'scripts/rtl_viewer_render_audit.py'
    p = subprocess.run(['python', str(script), '--ast', str(astfile), '--top', 'demo',
                        '--report', str(report), '--elk-scope', '/'],
                       capture_output=True, text=True, timeout=60)
    assert p.returncode == 0, p.stdout + p.stderr
    data = json.loads(report.read_text())
    assert data['summary']['scopes'] == 1
    assert data['summary']['layoutScopes'] == 1
    assert data['summary']['errors'] == 0
    assert any(item['view'] == 'compact' for item in data['results'][0]['checks'])
    assert 'MemberAccess' in data['astKinds']


def test_focus_external_register_is_input_not_clockless_flip_flop(tmp_path):
    """A combinational process may read another process's Q, not its FF timing."""
    graph = RtlDesign(_struct_writer_ast(), root=Path.cwd(), top='demo').diagram(limit=128)
    script = r'''
const assert=require('node:assert/strict'),fs=require('node:fs');
const W=process.argv[1],P=require(W+'/virtual-process.js'),C=require(W+'/render-contract.js');
const graph=JSON.parse(fs.readFileSync(process.argv[2]));
const comb=graph.processGroups.find(p=>p.kind==='always_comb');
assert(comb,'test requires a process that reads a different process\'s register');
const focused=P.focus(graph,comb.token);
const external=focused.nodes.find(n=>n.name==='q');
assert(external,'external Q must be a visible process input');
assert.equal(external.type,'port','Q of another process must not be a dangling FF');
assert.equal(external.direction,'in');
assert.equal(external.boundaryOriginalType,'register');
assert(focused.edges.some(e=>e.source===external.id), 'preserve Q consumer wires');
assert.deepEqual(C.checkProjection(graph,focused).errors,[]);
// The invariant must detect exactly the old bug if a future refactor
// reintroduces the full FF symbol without its event source.
const broken=JSON.parse(JSON.stringify(focused));
const b=broken.nodes.find(n=>n.id===external.id);
b.type='register';b.sequentialTiming=[{signal:'clk',role:'clock',edge:'PosEdge'}];
assert(C.check(broken).errors.some(e=>e.code==='missing_sequential_terminal'));
console.log('PROCESS FOCUS SEQUENTIAL BOUNDARY PASS');
'''
    assert 'SEQUENTIAL BOUNDARY PASS' in _node_case(tmp_path, script, graph)
