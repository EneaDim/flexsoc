"""Per-register next-state semantics on genuine Slang AST, not RTL-name hacks.

The Ethernet fixture is a minimized exact Slang AST fragment from an elaborated
multi-destination AlwaysFF: independent whole-register NBAs retain their old
state reads and original priority. Unsafe syntax remains unresolved.
"""
import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from flexsoc.backend.dv.rtl_viewer.sequential_projection import project_destination

HERE = Path(__file__).parent
FIXTURE = HERE / 'fixtures/ethernet_rx_multidestination_032.json'
WEB = HERE.parents[1] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def rtl_graph(ast=None):
    return RtlDesign(ast or json.loads(FIXTURE.read_text()), root=HERE, top='u_rx').diagram(limit=1500)


def d_edges(graph, name):
    node = next(n for n in graph['nodes'] if n['name'] == name)
    return node, [e for e in graph['edges'] if e['target'] == node['id'] and e.get('rendered')
                  and e.get('targetPin') == 'D']


def ref(addr):
    return {'kind': 'NamedValue', 'symbol': f'{addr} sv_identity'}


def write(addr, rhs, *, nba=True):
    return {'kind': 'Assignment', 'isNonBlocking': nba, 'left': ref(addr), 'right': rhs}


def slice_ast(body):
    identities = {'1': 'q', '2': 'r'}

    def resolved(lhs):
        if not isinstance(lhs, dict):
            return None
        return identities.get(str(lhs.get('symbol', '')).partition(' ')[0])

    return project_destination(body, 'q',
                               writes=lambda lhs: (resolved(lhs),) if resolved(lhs) else (),
                               direct=resolved)


def test_project_independent_register_nbas_preserves_priority_and_conditions():
    body = {'kind':'Block','body':[
        write(1,ref(2)),
        {'kind':'Conditional','condition':ref(3),'ifTrue':{'kind':'Block','body':[
            write(2,ref(1)),write(1,{'kind':'UnaryOp','op':'BitwiseNot','operand':ref(1)})]}},
        write(2,ref(1))]}
    result = slice_ast(body)
    assert result.supported
    assert result.statement['kind'] == 'Block'
    assert len(result.statement['body']) == 2
    assert result.statement['body'][1]['kind'] == 'Conditional'
    assert result.statement['body'][1]['ifTrue']['right']['kind'] == 'UnaryOp'


@pytest.mark.parametrize('unexpected', [
    write(2,ref(1),nba=False),
    {'kind':'Assignment','isNonBlocking':True, 'left':{'kind':'ElementSelect','value':ref(2),'selector':ref(3)},'right':ref(1)},
    {'kind':'Case','expr':ref(3)},
    {'kind':'ForLoop','body':write(2,ref(1))},
])
def test_unsafe_sibling_statement_never_silently_disappears(unexpected):
    result = slice_ast({'kind':'Block','body':[write(1,ref(2)),unexpected]})
    assert not result.supported and result.statement is None


def test_genuine_ethernet_rx_multiwriter_process_has_one_d_per_register():
    graph = rtl_graph()
    for name in ('mii_odd','start_packet_reg','gmii_rx_dv_d1'):
        node, drivers = d_edges(graph, name)
        assert node['type'] == 'register' and not node.get('dInputStatus')
        assert len(drivers) == 1, (name,drivers)
    odd, [d] = d_edges(graph,'mii_odd')
    mux = next(n for n in graph['nodes'] if n['id'] == d['source'])
    assert mux['shape'] == 'mux'
    assert d['source'] != odd['id']  # Q and D never shorted
    assert any(e.get('rendered') and e['source'] == odd['id']
               and next((n for n in graph['nodes'] if n['id'] == e['target']),{}).get('name') == 'LogicalNot'
               for e in graph['edges'])
    assert any(e.get('rendered') and e['source'] == '/::sig:clk_enable'
               and e.get('pin') == 'S' for e in graph['edges'])
    assert any(e.get('rendered') and e['source'] == '/::sig:mii_select'
               and e.get('pin') == 'S' for e in graph['edges'])
    assert sum(1 for n in graph['nodes'] if n.get('type')=='register' and not n.get('dInputStatus')) >= 20


def test_unproven_parameter_reference_rejects_conditional_d():
    ast = json.loads(FIXTURE.read_text())
    body = ast['design']['members'][0]['body']['members']
    for item in body:
        if item.get('name') == 'ETH_SFD':
            item['initializer'] = {'kind':'Call', 'subroutine':'unknown'}
            break
    else:
        raise AssertionError('missing compiler parameter fixture')
    graph = rtl_graph(ast)
    # A register's D must never be wired through a control predicate whose
    # parameter source has no AST-proven constant value.
    node, drivers = d_edges(graph,'mii_odd')
    assert node['type']=='register' and not drivers and node.get('dInputStatus')


@pytest.mark.skipif(not shutil.which('node'), reason='bundled real ELK needs Node')
def test_real_elk_has_distinct_q_and_d_terminals_on_ethernet_rx():
    graph=rtl_graph()
    script=r'''
const assert=require('node:assert/strict'), fs=require('node:fs');
const g=JSON.parse(fs.readFileSync(0,'utf8')), w=process.argv[1];
const Geo=require(w+'/symbol-geometry.js');
const ElkAdapter=require(w+'/elk-adapter.js');
const ELK=require(w+'/elk.bundled.js').default;
(async()=>{
 const layout=await ElkAdapter.compute(new ELK(),g,Geo.boxSize);
 const reg=g.nodes.find(n=>n.name==='mii_odd');
 const d=g.edges.filter(e=>e.target===reg.id&&e.rendered&&e.targetPin==='D');
 assert.equal(d.length,1);
 const wire=layout.edgePaths.get(d[0].id);
 assert(wire?.length>=2);
 const end=Geo.absoluteAnchor(reg,layout.positions.get(reg.id),'target',d[0]);
 assert.deepEqual(wire.at(-1),[end.x,end.y]);
 const q=g.edges.find(e=>e.source===reg.id&&e.rendered&&e.target!==reg.id);
 assert(q);
 assert.notEqual(q.net,d[0].net);
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    result=subprocess.run(['node','-e',script,str(WEB)],input=json.dumps(graph),
                          capture_output=True,text=True,timeout=45)
    assert result.returncode == 0, result.stderr+result.stdout


def test_enum_reset_is_compiler_value_not_a_physical_signal():
    graph = rtl_graph()
    node, drivers = d_edges(graph, 'state_reg')
    assert node['type'] == 'register' and len(drivers) == 1
    assert not node.get('dInputStatus')
    # The reset enum member is a proven value, not a wire named STATE_IDLE.
    assert not any(n['name'] == 'STATE_IDLE' for n in graph['nodes'])
    assert any(n.get('origin') == 'procedural_if_ast' and
               "3'b0" in n.get('literalOperands', {}).values()
               for n in graph['nodes'])


def test_missing_enum_initializer_never_creates_spurious_d_wire():
    ast = json.loads(FIXTURE.read_text())
    def erase_enum(node):
        if isinstance(node, dict):
            if node.get('kind') == 'EnumValue' and node.get('name') == 'STATE_IDLE':
                node.pop('initializer', None)
                return True
            return any(erase_enum(v) for v in node.values())
        if isinstance(node, list):
            return any(erase_enum(v) for v in node)
        return False
    assert erase_enum(ast)
    graph = rtl_graph(ast)
    state, drivers = d_edges(graph, 'state_reg')
    assert state['type']=='register' and not drivers and state.get('dInputStatus')
    odd, odd_d = d_edges(graph, 'mii_odd')
    assert odd['type']=='register' and len(odd_d)==1
