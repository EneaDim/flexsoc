"""A Slang-proven parameter expression may be shown as one value source.

The real Ethernet fixture is reduced from the user's WSL elaborated AST at
ethernet_core.sv lines 198-199; no SystemVerilog is reparsed for the assertion.
"""
from __future__ import annotations

import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

HERE = Path(__file__).parent
WEB = HERE.parents[1] / 'src/flexsoc/backend/dv/rtl_viewer/web'
FIXTURE = HERE / 'fixtures/ethernet_constant_replication_030.json'


def model(ast):
    return RtlDesign(ast, root=HERE, top='top').diagram()


def test_real_ethernet_ast_two_elaborated_parameter_replications_become_values():
    graph = model(json.loads(FIXTURE.read_text()))
    operators = [n for n in graph['nodes'] if n['type'] == 'operator']
    assert len(operators) == 2  # not six CAST/REP/CONCAT glyphs
    assert {n['constantValue'] for n in operators} == {"2'b0"}
    assert {n['line'] for n in operators} == {198, 199}
    assert all(n['kind'] == 'Conversion' and n['shape'] == 'constant'
               and n['constantOrigin'] == 'Conversion'
               and n['constantType'] == 'logic[1:0]' and n['pins'] == ['Y']
               for n in operators)
    by_id = {n['id']: n for n in graph['nodes']}
    outputs = [e for e in graph['edges'] if e['rendered']]
    assert len(outputs) == 2
    assert {by_id[e['target']]['name'] for e in outputs} == {'tx_mii_sync', 'rx_mii_sync'}
    assert all(by_id[e['source']]['shape'] == 'constant' for e in outputs)
    assert all(e['mapping'] == 'direct' for e in outputs)


def test_dynamic_replication_keeps_its_actual_operand_graph():
    base = json.loads(FIXTURE.read_text())
    members = base['design']['members'][0]['body']['members']
    members.insert(2, {'kind': 'Variable', 'name': 'mode', 'addr': 123456})
    rhs = next(n for n in members if n.get('source_line') == 198)['assignment']['right']
    # An AST lacking compiler-proven constant values cannot be folded.
    for item in (rhs, rhs['operand'], rhs['operand']['concat']):
        item.pop('constant', None)
    rhs['operand']['concat']['operands'][0] = {'kind': 'NamedValue', 'symbol': '123456 mode'}
    graph = model(base)
    nodes = [n for n in graph['nodes'] if n['type'] == 'operator' and n['line'] == 198]
    assert {n['kind'] for n in nodes} == {'Conversion', 'Replication', 'Concatenation'}
    assert all(n['shape'] != 'constant' for n in nodes)
    edges = graph['edges']
    concat = next(n for n in nodes if n['kind'] == 'Concatenation')
    rep = next(n for n in nodes if n['kind'] == 'Replication')
    assert any(e['source'] == '/::sig:mode' and e['target'] == concat['id']
               and e['pin'] == 'I0' for e in edges)
    assert any(e['source'] == concat['id'] and e['target'] == rep['id'] for e in edges)


def test_partial_constant_evidence_does_not_fold_parent():
    base = json.loads(FIXTURE.read_text())
    members = base['design']['members'][0]['body']['members']
    rhs = next(n for n in members if n.get('source_line') == 198)['assignment']['right']
    rhs.pop('constant')
    graph = model(base)
    operators = [n for n in graph['nodes'] if n['type'] == 'operator' and n['line'] == 198]
    assert len(operators) == 2
    assert any(n['kind'] == 'Conversion' and n['shape'] != 'constant' for n in operators)
    assert any(n['kind'] == 'Replication' and n['constantValue'] == "2'b0" for n in operators)


@pytest.mark.skipif(not shutil.which('node'), reason='Node.js needed for bundled ELK')
def test_constant_value_visible_and_elk_terminal_exact():
    graph = model(json.loads(FIXTURE.read_text()))
    script = r'''
const fs=require('node:fs'), assert=require('node:assert/strict');
const graph=JSON.parse(fs.readFileSync(0,'utf8')),dir=process.argv[1];
const Geo=require(dir+'/symbol-geometry.js');
const Painter=require(dir+'/symbol-painter.js');
const Adapter=require(dir+'/elk-adapter.js');
const ELK=require(dir+'/elk.bundled.js').default;
(async()=>{
 const result=await Adapter.compute(new ELK(),graph,Geo.boxSize);
 const ops=graph.nodes.filter(n=>n.shape==='constant');
 assert.equal(ops.length,2);
 for(const n of ops){
  assert.equal(n.pins.join(','),'Y');
  const size=Geo.boxSize(n);
  assert.equal(size.h,34);
  const ctx=new Proxy({labels:[],save(){},restore(){},fillText(text){this.labels.push(text)}},{get(t,k){return k in t?t[k]:()=>{}}});
  Painter.paint(ctx,n,{x:0,y:0,w:size.w,h:size.h},{colors:{operator:'#e0b',text:'#fff',muted:'#aaa',symbolFill:'#224',pickedFill:'#334',selected:'#fa0',signal:'#48a'},zoom:1});
  assert(ctx.labels.includes("2'b0"),JSON.stringify(ctx.labels));
  assert(!ctx.labels.includes('CONST'));
  const edge=graph.edges.find(e=>e.source===n.id);
  const p=result.positions.get(n.id),path=result.edgePaths.get(edge.id);
  const out=Geo.absoluteAnchor(n,p,'source',edge);
  assert.deepEqual(path[0],[out.x,out.y]);
 }
 console.log('constant ELK + Canvas OK');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    result = subprocess.run(['node', '-e', script, str(WEB)], input=json.dumps(graph),
                            text=True, capture_output=True, timeout=45)
    assert result.returncode == 0, result.stderr + result.stdout
    assert 'constant ELK + Canvas OK' in result.stdout
