"""Typed, source-faithful aggregate updates and function ownership contracts."""
from __future__ import annotations

import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from flexsoc.backend.dv.rtl_viewer.procedural_value_graph import project_value, UnrepresentableValue
from flexsoc.backend.dv.rtl_viewer.semantic_contracts import audit_scope_semantics


HERE = Path(__file__).parent
WEB = HERE.parents[1] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def ref(addr, name=None):
    return {"kind": "NamedValue", "symbol": f"{addr} {name or 'compiler'}"}


def literal(value):
    return {"kind": "IntegerLiteral", "type": "logic[7:0]", "value": value}


def assignment(lhs, rhs):
    return {"kind": "Assignment", "left": lhs, "right": rhs, "isNonBlocking": False}


def aggregate_ast():
    fields = lambda name: {"kind": "MemberAccess", "member": name, "type": "logic[7:0]", "value": ref(3)}
    members = [
        {"kind": "Variable", "addr": 1, "name": "data"},
        {"kind": "Variable", "addr": 2, "name": "valid"},
        {"kind": "Port", "addr": 100, "name": "out", "internalSymbol": "3 out", "direction": "Out"},
        {"kind": "Variable", "addr": 3, "name": "out"},
        {"kind": "ProceduralBlock", "procedureKind": "AlwaysComb", "source_line": 20,
         "body": {"kind": "Block", "body": {"kind": "List", "list": [
             assignment(ref(3), literal("8'b0")),
             assignment(fields('101 data'), ref(1)),
             assignment(fields('102 valid'), ref(2)),
         ]}}},
    ]
    return {"design": {"members": [{"kind": "Instance", "name": "demo", "body": {
        "kind": "InstanceBody", "name": "demo", "members": members}}]}}


def test_struct_fields_are_not_fake_whole_bus_update_cells():
    design = RtlDesign(aggregate_ast(), root=Path.cwd(), top='demo')
    graph = design.diagram(limit=120)
    output = next(node for node in graph['nodes'] if node['name'] == 'out')
    # Keep AST dependencies distinct. No pseudo-synthesized UPDATE cells,
    # no invented complete bus driver and no forced single-driver claim.
    assert not any(node.get('kind') == 'AggregateUpdate' or node.get('shape') == 'update'
                   for node in graph['nodes'])
    input_edges = [edge for edge in graph['edges'] if edge['target'] == output['id']
                   and edge.get('rendered')]
    assert {(edge['source'], edge['mapping']) for edge in input_edges} == {
        ('/::sig:data', 'partial'), ('/::sig:valid', 'partial')}
    check = audit_scope_semantics(design.scopes['/'].node['body']['members'],
                                  set(design._signals(design.scopes['/'])),
                                  graph, design.subroutines)
    assert check['errors'] == []
    assert check['aggregateValues'] == 1
    assert check['aggregateValuesRepresented'] == 0
    assert any(w['code'] == 'aggregate_value_not_projected' for w in check['warnings'])


def test_missing_initial_assignment_fails_closed_without_fake_aggregate_driver():
    ast = aggregate_ast()
    process = ast['design']['members'][0]['body']['members'][-1]
    process['body']['body']['list'].pop(0)
    design = RtlDesign(ast, root=Path.cwd(), top='demo')
    graph = design.diagram(limit=120)
    out = next(node for node in graph['nodes'] if node['name'] == 'out')
    # The uninitialized base is an implicit feedback read. No UPDATE chain
    # can be called a proved complete next-value conductor.
    assert not any(node.get('kind') == 'AggregateUpdate' for node in graph['nodes'])
    assert not any(edge.get('proceduralLowering') == 'ProcessLowerer' and
                   edge['target'] == out['id'] for edge in graph['edges'])


def test_dynamic_index_partial_write_cannot_become_fake_schematic_cell():
    expression = {"op": "update", "base": literal_value("8'b0"),
                  "path": [{"kind": "element", "index": {"op": "ref", "name": "index"}}],
                  "value": {"op": "ref", "name": "data"}}
    with pytest.raises(UnrepresentableValue, match="no proven circuit projection"):
        project_value(expression, "result", {"index", "data", "result"}, start=10)


def literal_value(value):
    return {"op": "literal", "value": value}


def test_invalid_field_path_cannot_invent_functional_write():
    value = {"op": "update", "base": literal_value("0"),
             "path": [{"kind": "member", "member": ""}], "value": literal_value("1")}
    with pytest.raises(UnrepresentableValue):
        project_value(value, "result", {"result"}, start=0)


def test_compiler_function_calls_match_owner_by_identity_not_name():
    fixture = HERE / 'fixtures/ethernet_function_call_slang_027.json'
    design = RtlDesign(json.loads(fixture.read_text()), root=Path.cwd(), top='top')
    graph = design.diagram(limit=200)
    members = design.scopes['/'].node['body']['members']
    check = audit_scope_semantics(members, set(design._signals(design.scopes['/'])),
                                  graph, design.subroutines)
    assert check['errors'] == [] and check['warnings'] == []
    assert check['functionCalls'] == check['functionCallsRepresented'] == 2
    functions = [n for n in graph['nodes'] if n.get('kind') == 'Call']
    assert len(functions) == 2
    assert all(n['function']['subroutineAddr'].isdecimal() for n in functions)
    # An AST-proven call in an FF must belong to that FF's virtual process.
    altered = json.loads(json.dumps(graph))
    group = next(g for g in altered['processGroups'] if any(
        f['id'] in g['memberIds'] for f in functions))
    group['memberIds'] = [m for m in group['memberIds'] if m != functions[0]['id']]
    broken = audit_scope_semantics(members, set(design._signals(design.scopes['/'])),
                                   altered, design.subroutines)
    assert any(err['code'] == 'function_wrong_process' for err in broken['errors'])
    # A silently dropped user function must show up as a coverage gap.
    altered = json.loads(json.dumps(graph))
    altered['nodes'] = [n for n in altered['nodes'] if n['id'] != functions[0]['id']]
    missing = audit_scope_semantics(members, set(design._signals(design.scopes['/'])),
                                    altered, design.subroutines)
    assert any(item['code'] == 'unrepresented_function_call' for item in missing['warnings'])


@pytest.mark.skipif(not shutil.which('node'), reason='Node.js is needed for ELK')
def test_partial_struct_writes_keep_existing_elk_endpoints(tmp_path):
    design = RtlDesign(aggregate_ast(), root=Path.cwd(), top='demo')
    graph = design.diagram(limit=120)
    path = tmp_path / 'graph.json'
    path.write_text(json.dumps(graph))
    js = r'''
const assert=require('node:assert/strict'),fs=require('node:fs');
const base=process.argv[1],graph=JSON.parse(fs.readFileSync(process.argv[2]));
const A=require(base+'/elk-adapter.js'),G=require(base+'/symbol-geometry.js');
const E=require(base+'/elk.bundled.js').default;
(async()=>{const result=await A.compute(new E(),graph,G.boxSize),nodes=new Map(graph.nodes.map(n=>[n.id,n]));
 let checked=0;
 for(const edge of graph.edges.filter(e=>e.rendered!==false)){
  if(edge.mapping!=='partial')continue;
  const pts=result.edgePaths.get(edge.id);assert(pts&&pts.length>=2,edge.id);
  const a=G.absoluteAnchor(nodes.get(edge.source),result.positions.get(edge.source),'source',edge);
  const b=G.absoluteAnchor(nodes.get(edge.target),result.positions.get(edge.target),'target',edge);
  assert.deepEqual(pts[0],[a.x,a.y]);assert.deepEqual(pts.at(-1),[b.x,b.y]);checked++;
 }
 assert(checked===2);console.log('PARTIAL AST EDGES PASS '+checked);
})().catch(err=>{console.error(err);process.exitCode=1});
'''
    proc = subprocess.run(['node', '-e', js, str(WEB), str(path)],
                          capture_output=True, text=True, timeout=50)
    assert proc.returncode == 0, proc.stdout + proc.stderr
    assert 'PARTIAL AST EDGES PASS' in proc.stdout


def test_supported_function_inside_combinational_case_is_projected_into_its_process():
    members = [
        {'kind': 'Variable', 'addr': 1, 'name': 'sel'},
        {'kind': 'Variable', 'addr': 2, 'name': 'a'},
        {'kind': 'Variable', 'addr': 3, 'name': 'result'},
        {'kind': 'Subroutine', 'addr': 99, 'name': 'transform', 'subroutineKind': 'Function',
         'returnType': 'logic', 'body': {'kind': 'List', 'list': []},
         'members': [{'kind': 'FormalArgument', 'name': 'value', 'direction': 'In'}]},
        {'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysComb', 'source_line': 15,
         'body': {'kind': 'Block', 'body': {'kind': 'List', 'list': [
             assignment(ref(3), literal("1'b0")),
             {'kind': 'Case', 'condition': 'Normal', 'expr': ref(1), 'items': [{
                 'expressions': [literal("1'b1")],
                 'stmt': assignment(ref(3), {'kind': 'Call',
                     'subroutine': '99 transform', 'type': 'logic',
                     'source_file': 'demo.sv', 'source_line': 20, 'source_column': 14,
                     'arguments': [ref(2)]})
             }]},
         ]}}},
    ]
    ast = {'design': {'members': [{'kind': 'Instance', 'name': 'demo', 'body': {
        'kind': 'InstanceBody', 'name': 'demo', 'members': members}}]}}
    design = RtlDesign(ast, root=Path.cwd(), top='demo')
    graph = design.diagram(limit=128)
    calls = [n for n in graph['nodes'] if n.get('kind') == 'Call']
    assert len(calls) == 1
    assert calls[0]['shape'] == 'function'
    assert calls[0]['function']['name'] == 'transform'
    assert calls[0]['function']['subroutineAddr'] == '99'
    assert calls[0]['function']['callLine'] == 20
    assert any(call['id'] in group['memberIds'] for group in graph['processGroups']
               for call in calls)
    check = audit_scope_semantics(members, set(design._signals(design.scopes['/'])),
                                  graph, design.subroutines)
    assert check['errors'] == [] and check['warnings'] == []
    assert check['functionCalls'] == check['functionCallsRepresented'] == 1
    target = next(n for n in graph['nodes'] if n['name'] == 'result')
    assert len([e for e in graph['edges'] if e['target'] == target['id'] and e['rendered']]) == 1
