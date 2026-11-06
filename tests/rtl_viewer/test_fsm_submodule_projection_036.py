"""FSM compaction is reversible presentation, not inferred circuit synthesis."""
from __future__ import annotations

from pathlib import Path

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from flexsoc.backend.dv.rtl_viewer.fsm_projection import collapse_fsm_cones


def small_graph():
    scope = '/rx'
    ids = {name: scope + '::' + name for name in
           ['sig:clk', 'sig:state', 'sig:data', 'sig:flag', 'op:case', 'op:mux']}
    def edge(name, source, target, pin='', typ='data'):
        return {'id': name, 'source': ids[source], 'target': ids[target],
                'type': typ, 'pin': pin, 'targetPin': pin, 'net': 'wire:'+name,
                'rendered': True, 'mapping': 'direct'}
    return {
        'path': scope,
        'nodes': [
            {'id': ids['sig:clk'], 'type': 'signal', 'name': 'clk'},
            {'id': ids['sig:state'], 'type': 'fsm', 'name': 'state'},
            {'id': ids['sig:data'], 'type': 'signal', 'name': 'data'},
            {'id': ids['sig:flag'], 'type': 'signal', 'name': 'flag'},
            {'id': ids['op:case'], 'type': 'operator', 'name': 'CASE',
             'kind': 'CaseMatch'},
            {'id': ids['op:mux'], 'type': 'operator', 'name': 'MUX',
             'kind': 'ConditionalOp'},
        ],
        'edges': [
            edge('clock', 'sig:clk', 'sig:state', 'CLK', 'event'),
            edge('sel', 'sig:state', 'op:case', 'A'),
            edge('condition', 'op:case', 'op:mux', 'S'),
            edge('data', 'sig:data', 'op:mux', 'A'),
            edge('output', 'op:mux', 'sig:flag'),
            edge('unused', 'sig:data', 'sig:flag'),
        ],
    }


def test_fsm_collapse_retains_every_external_edge_and_port_identity():
    original = small_graph()
    compact = collapse_fsm_cones(original, frozenset())
    group = next(n for n in compact['nodes'] if n['type'] == 'fsm_group')
    assert group['group'] == 'fsm:state'
    assert group['fsmSummary']['inputs'] == 2
    assert group['fsmSummary']['outputs'] == 1
    assert set(group['hiddenNodeIds']) == {
        '/rx::sig:state', '/rx::op:case', '/rx::op:mux'}
    assert {e['id'] for e in compact['edges']} == {'clock', 'data', 'output', 'unused'}
    assert all(e.get('fsmProjection') == 'boundary-only' for e in compact['edges'] if e['id'] != 'unused')
    assert next(e for e in compact['edges'] if e['id'] == 'output')['sourcePin'].startswith('O')
    assert next(e for e in compact['edges'] if e['id'] == 'data')['targetPin'].startswith('I')
    clock_edge = next(e for e in compact['edges'] if e['id'] == 'clock')
    assert clock_edge['targetPin'] == 'CLK:clk'
    assert next(p for p in group['ports'] if p['name'] == 'CLK:clk')['timingRole'] == 'clock'
    assert group['ports'][0]['name'] == 'CLK:clk'
    assert group['ports'][0]['direction'] == 'input'
    assert not any(p.get('timingRole') == 'clock' and p['direction'] == 'output'
                   for p in group['ports'])
    assert group['fsmSummary']['clockIds'] == ['/rx::sig:clk']
    assert next(e for e in compact['edges'] if e['id'] == 'unused') == original['edges'][-1]
    assert len({e['id'] for e in compact['edges']}) == len(compact['edges'])
    assert original['nodes'][1]['type'] == 'fsm'  # no graph mutation


def test_expanded_fsm_restores_all_internal_entities_and_relations():
    graph = small_graph()
    expanded = collapse_fsm_cones(graph, frozenset({'fsm:state'}))
    assert {e['id'] for e in expanded['edges']} == {e['id'] for e in graph['edges']}
    assert {n['id'] for n in expanded['nodes']} == {n['id'] for n in graph['nodes']}
    assert next(n for n in expanded['nodes'] if n['name'] == 'state')['fsmExpanded'] is True
    assert not any(n['type'] == 'fsm_group' for n in expanded['nodes'])


def test_only_proven_fsm_candidate_is_grouped():
    g = small_graph()
    next(n for n in g['nodes'] if n['name'] == 'state')['type'] = 'register'
    assert collapse_fsm_cones(g, frozenset()) is g
    g = small_graph()
    next(n for n in g['nodes'] if n.get('kind') == 'CaseMatch')['kind'] = 'BinaryOp'
    assert collapse_fsm_cones(g, frozenset()) is g


def test_bounded_fsm_group_fails_closed():
    g = small_graph()
    assert collapse_fsm_cones(g, frozenset(), max_members=2) is g
    assert collapse_fsm_cones(g, frozenset(), max_ports=1) is g


def test_realistic_compiler_typealias_to_enum_type_is_not_name_heuristic():
    """A state type comes from Slang TypeAlias.addr -> EnumType.addr."""
    members = [
        {'kind': 'EnumType', 'name': 'mode_e', 'addr': 9001,
         'members': [{'kind': 'EnumValue', 'name': 'IDLE', 'addr': 9002,
                      'value': "2'b00"}]},
        {'kind': 'TypeAlias', 'name': 'mode_e', 'addr': 9003, 'target': '9001 demo.mode_e'},
        {'kind': 'Variable', 'name': 'clk', 'addr': 1, 'type': 'logic'},
        {'kind': 'Variable', 'name': 'state', 'addr': 2, 'type': '9003 demo.mode_e'},
        {'kind': 'Variable', 'name': 'state_next', 'addr': 3, 'type': '9003 demo.mode_e'},
        {'kind': 'Variable', 'name': 'flag', 'addr': 4, 'type': 'logic'},
        {'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF', 'body': {
            'kind': 'Timed', 'timing': {'kind': 'SignalEvent', 'edge': 'PosEdge',
                                      'expr': {'kind': 'NamedValue', 'symbol': '1 clk'}},
            'stmt': {'kind': 'Assignment', 'isNonBlocking': True,
                     'left': {'kind': 'NamedValue', 'symbol': '2 state'},
                     'right': {'kind': 'NamedValue', 'symbol': '3 state_next'}}}},
        {'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysComb', 'body': {
            'kind': 'Block', 'body': {'kind': 'List', 'list': [
                {'kind': 'Assignment', 'left': {'kind': 'NamedValue', 'symbol': '4 flag'},
                 'right': {'kind': 'IntegerLiteral', 'type': 'logic', 'value': "1'b0"}},
                {'kind': 'Case', 'condition': 'Normal',
                 'expr': {'kind': 'NamedValue', 'symbol': '2 state'}, 'items': [
                     {'expressions': [{'kind': 'NamedValue', 'symbol': '9002 IDLE'}],
                      'stmt': {'kind': 'Assignment',
                               'left': {'kind': 'NamedValue', 'symbol': '4 flag'},
                               'right': {'kind': 'IntegerLiteral', 'type': 'logic', 'value': "1'b1"}}}
                 ]},
            ]}}},
    ]
    ast = {'design': {'members': [{'kind': 'Instance', 'name': 'demo',
           'body': {'kind': 'InstanceBody', 'name': 'demo', 'members': members}}]}}
    design = RtlDesign(ast, root=Path.cwd(), top='demo')
    full = design.diagram(limit=128)
    state = next(n for n in full['nodes'] if n['name'] == 'state')
    assert state['type'] == 'fsm'
    compact = design.diagram(limit=128, fsm_view=True)
    assert any(n['type'] == 'fsm_group' for n in compact['nodes'])
    expanded = design.diagram(limit=128, fsm_view=True, expanded=('fsm:state',))
    assert {e['id'] for e in expanded['edges']} == {e['id'] for e in full['edges']}


def test_compact_fsm_terminal_geometry_and_elk_layout(tmp_path):
    import json
    import shutil
    import subprocess

    import pytest

    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    graph = collapse_fsm_cones(small_graph(), frozenset())
    path = tmp_path / 'graph.json'
    path.write_text(json.dumps(graph))
    web = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'
    script = r'''
const assert=require('node:assert/strict'),fs=require('node:fs');
const W=process.argv[1],data=JSON.parse(fs.readFileSync(process.argv[2],'utf8'));
const Elk=require(W+'/elk.bundled.js').default;
const G=require(W+'/symbol-geometry.js'),A=require(W+'/elk-adapter.js');
(async()=>{
 const group=data.nodes.find(n=>n.type==='fsm_group');
 assert(group,'collapsed FSM exists');
 const size=G.boxSize(group);
 assert(size.h>100,'FSM module reserves room for its ports');
 const output=data.edges.find(e=>e.id==='output');
 const input=data.edges.find(e=>e.id==='data');
 assert.equal(G.anchor(group,'source',output,size).side,'EAST');
 assert.equal(G.anchor(group,'target',input,size).side,'WEST');
 const result=await A.compute(new Elk(),data,G.boxSize);
 assert.equal(result.positions.size,data.nodes.length);
 assert.equal(result.edgePaths.size,data.edges.length);
 for(const edge of [output,input]){
   const byId=Object.fromEntries(data.nodes.map(n=>[n.id,n]));
   const pts=result.edgePaths.get(edge.id);
   assert.deepEqual(pts[0],Object.values(G.absoluteAnchor(byId[edge.source],result.positions.get(edge.source),'source',edge)).slice(0,2));
   assert.deepEqual(pts.at(-1),Object.values(G.absoluteAnchor(byId[edge.target],result.positions.get(edge.target),'target',edge)).slice(0,2));
 }
})().catch(error=>{console.error(error);process.exitCode=1});
'''
    result = subprocess.run(['node', '-e', script, str(web), str(path)],
                            capture_output=True, text=True, timeout=30)
    assert result.returncode == 0, result.stderr + result.stdout


def test_fsm_focus_metadata_is_reversible_without_new_net_identities():
    original = small_graph()
    expanded = collapse_fsm_cones(original, frozenset({'fsm:state'}))
    summary = next(g for g in expanded['fsmGroups'] if g['token'] == 'fsm:state')
    assert set(summary['memberIds']) == {'/rx::sig:state', '/rx::op:case', '/rx::op:mux'}
    assert summary['inputIds'] == ['/rx::sig:clk', '/rx::sig:data']
    assert summary['outputIds'] == ['/rx::sig:flag']
    focused = set(summary['memberIds'] + summary['inputIds'] + summary['outputIds'])
    assert {e['id'] for e in expanded['edges']
            if e['source'] in focused and e['target'] in focused} == {e['id'] for e in original['edges']}
