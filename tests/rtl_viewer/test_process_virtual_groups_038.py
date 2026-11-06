"""Slang process ownership: reversible virtual hierarchy, not new RTL modules."""
from pathlib import Path
import json
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def _ast():
    def ref(index):
        return {"kind": "NamedValue", "symbol": f"{index} member"}
    def assign(dst, rhs, *, nba=False):
        return {"kind": "Assignment", "left": ref(dst), "right": rhs, "isNonBlocking": nba}
    declarations = [
        {"kind": "Variable", "name": name, "addr": address}
        for name,address in [("clk",1),("en",2),("din",3),("q",4),("comb",5),("final",6),("sink",7)]
    ]
    ff = {"kind": "ProceduralBlock", "procedureKind": "AlwaysFF", "source_line": 19,
          "body": {"kind": "Timed", "timing": {"kind": "SignalEvent", "edge": "PosEdge", "expr": ref(1)},
                   "stmt": {"kind": "Conditional", "conditions": [{"expr": ref(2)}],
                            "ifTrue": assign(4, ref(3), nba=True)}}}
    comb = {"kind": "ProceduralBlock", "procedureKind": "AlwaysComb", "source_line": 28,
            "body": {"kind": "Block", "body": {"kind": "List", "list": [
                assign(5, ref(4)),
                assign(6, {"kind": "BinaryOp", "op": "Add", "left": ref(5),
                           "right": {"kind": "IntegerLiteral", "type": "int", "value": "1"}})
            ]}}}
    return {"design": {"members": [{"kind": "Instance", "name": "demo",
        "body": {"kind": "InstanceBody", "name": "demo", "members": declarations + [ff, comb,
        {"kind": "ContinuousAssign", "left": ref(7), "right": ref(6)}]}}]}}


def test_process_groups_have_compiler_process_identity_and_real_boundary_wires():
    design=RtlDesign(_ast(),root=Path.cwd(),top='demo')
    graph=design.diagram(limit=128)
    groups=graph['processGroups']
    assert {g['kind'] for g in groups} == {'always_ff','always_comb'}
    ff=next(g for g in groups if g['kind']=='always_ff')
    assert ff['sourceLine'] == 19
    assert ff['token'].startswith('proc:')
    assert any(member.endswith('::sig:q') for member in ff['memberIds'])
    assert any(node['id'].endswith('::sig:clk') for node in graph['nodes'])
    assert any(item.endswith('::sig:clk') for item in ff['clockIds'])
    assert ff['coverage'] in {'connected', 'partial'}
    assert ff['origin'].startswith('Slang')


def test_virtual_process_projection_preserves_existing_edge_ids(tmp_path):
    if not shutil.which('node'):
        pytest.skip('Node.js not installed')
    graph=RtlDesign(_ast(),root=Path.cwd(),top='demo').diagram(limit=128)
    path=tmp_path/'graph.json'
    path.write_text(json.dumps(graph))
    script=r'''
const assert=require('node:assert/strict');
const fs=require('node:fs'),p=require(process.argv[1]),G=require(process.argv[2]);
const graph=JSON.parse(fs.readFileSync(process.argv[3],'utf8'));
const first=p.project(graph);
assert(first.nodes.some(n=>n.type==='process_group'));
assert(!first.nodes.some(n=>n.name==='q'));
assert(first.edges.every(e=>graph.edges.some(old=>old.id===e.id)));
for(const e of first.edges.filter(e=>e.processProjection)){
 assert(e.processOriginalSource&&e.processOriginalTarget);
 const original=graph.edges.find(old=>old.id===e.id);
 assert.equal(e.processOriginalSource,original.source);
 assert.equal(e.processOriginalTarget,original.target);
}
const ff=first.nodes.find(n=>n.name.startsWith('always_ff'));
assert(ff.ports.some(x=>x.name.startsWith('CLK:')&&x.timingRole==='clock'));
for(const edge of first.edges.filter(e=>e.target===ff.id||e.source===ff.id)){
 const pin=edge.target===ff.id?edge.targetPin:edge.sourcePin;
 assert(ff.ports.some(p=>p.name===pin));
 const role=edge.target===ff.id?'target':'source';
 const a=G.anchor(ff,role,edge);
 assert(Number.isFinite(a.x)&&Number.isFinite(a.y));
}
const token=graph.processGroups.find(g=>g.kind==='always_ff').token;
const expanded=p.project(graph,[token]);
assert(expanded.nodes.some(n=>n.name==='q'));
assert(!expanded.nodes.some(n=>n.type==='process_group'&&n.group===token));
const focused=p.focus(graph,token);
assert(focused.nodes.some(n=>n.name==='q'));
assert(focused.edges.every(e=>graph.edges.some(original=>original.id===e.id)));
assert.equal(focused.module,graph.processGroups.find(g=>g.token===token).name);
assert.deepEqual(graph.nodes.map(n=>n.id),JSON.parse(fs.readFileSync(process.argv[3],'utf8')).nodes.map(n=>n.id));
console.log('PROCESS VIRTUAL ROUNDTRIP PASS');
'''
    cmd=['node','-e',script,str(WEB/'virtual-process.js'),str(WEB/'symbol-geometry.js'),str(path)]
    result=subprocess.run(cmd,text=True,capture_output=True,timeout=20)
    assert result.returncode==0,result.stderr+result.stdout
    assert 'PROCESS VIRTUAL ROUNDTRIP PASS' in result.stdout


def test_compiled_ethernet_process_provenance_when_fixture_present():
    fixture=Path(__file__).parent/'fixtures/ethernet_rx_multidestination_032.json'
    if not fixture.exists():
        pytest.skip('Compiled AST fixture is unavailable')
    graph=RtlDesign(json.loads(fixture.read_text()),root=Path.cwd(),top='u_rx').diagram(limit=800)
    assert isinstance(graph['processGroups'], list)
    assert all(g['origin'].startswith('Slang') for g in graph['processGroups'])
