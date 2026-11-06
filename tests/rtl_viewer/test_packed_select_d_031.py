"""Compiler-backed packed selections in async FF D cones.

The fixture retains Slang JSON statement, symbol, event and expression shapes
from the real Ethernet ethernet_phy_if.sv run; not source-regex-derived graphs.
"""
from __future__ import annotations

import copy
import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

HERE = Path(__file__).parent
WEB = HERE.parents[1] / 'src/flexsoc/backend/dv/rtl_viewer/web'
FIXTURE = HERE / 'fixtures/ethernet_phy_select_031.json'


def graph(ast=None):
    return RtlDesign(ast if ast is not None else json.loads(FIXTURE.read_text()),
                     root=HERE, top='u_phy').diagram(limit=1500)


def d_wires(g, name):
    target = next(n for n in g['nodes'] if n['name'] == name)
    return target, [e for e in g['edges'] if e['target'] == target['id']
                    and e.get('rendered') and e.get('targetPin') == 'D']


def test_real_ethernet_ast_shift_registers_have_distinct_q_slice_concat_d():
    g = graph()
    for name in ('tx_rst_reg', 'rx_rst_reg'):
        reg, wires = d_wires(g, name)
        assert reg['type'] == 'register'
        assert not reg.get('dInputStatus')
        assert len(wires) == 1
        [wire] = wires
        assert wire['mapping'] in ('procedural_mux', 'procedural_last_nba')
        concat = next(n for n in g['nodes'] if n['id'] == wire['source'])
        assert concat['kind'] == 'Concatenation'
        assert concat['literalOperands']['I0'] == "1'b0"
        slice_edge = next(e for e in g['edges'] if e['target'] == concat['id']
                          and e.get('pin') == 'I1' and e.get('rendered'))
        slice_node = next(n for n in g['nodes'] if n['id'] == slice_edge['source'])
        assert slice_node['kind'] == 'RangeSelect'
        assert slice_node['shape'] == 'slice'
        assert slice_node['selection'] == '[3:1]'
        assert slice_node['pins'] == ['A', 'Y']
        [read] = [e for e in g['edges'] if e['target'] == slice_node['id']
                  and e.get('rendered') and e.get('pin') == 'A']
        assert read['source'] == '/::sig:' + name
        assert read['mapping'] == 'partial'
        assert read['source'] != wire['source']  # Q never shorted to D
        event_pins = {e.get('pin') for e in g['edges'] if e['target'] == reg['id']
                      and e.get('type') == 'event' and e.get('rendered')}
        assert event_pins == {'CLK', 'RST'}


def change_range(ast, *, target='tx_rst_reg', selector=None, left=None, right=None):
    for proc in ast['design']['members'][0]['body']['members']:
        if proc.get('kind') != 'ProceduralBlock':
            continue
        stmt = proc['body']['stmt']['body']
        assign = stmt['ifFalse']['body']['expr']
        if target not in str(assign['left'].get('symbol')):
            continue
        part = assign['right']['operands'][1]
        if selector is not None:
            part['selectionKind'] = selector
        if left is not None:
            part['left'] = left
        if right is not None:
            part['right'] = right
        return
    raise AssertionError('target not found')


@pytest.mark.parametrize('bad', [
    {'left': {'kind': 'NamedValue', 'symbol': '6338718852192 tx_rst_reg'}},
    {'right': {'kind': 'IntegerLiteral', 'value': '100'}},
    {'selector': 'IndexedUp'},
    {'left': {'kind': 'IntegerLiteral', 'value': "8'hff"}},
])
def test_unproven_select_fails_closed_without_hiding_other_processes(bad):
    ast = json.loads(FIXTURE.read_text())
    change_range(ast, **bad)
    g = graph(ast)
    tx, wires = d_wires(g, 'tx_rst_reg')
    assert not wires
    assert tx.get('dInputStatus')
    rx, rx_wires = d_wires(g, 'rx_rst_reg')
    assert rx['type'] == 'register' and len(rx_wires) == 1


def test_static_element_select_is_value_projection_without_shorting_q_and_d():
    ast = json.loads(FIXTURE.read_text())
    for proc in ast['design']['members'][0]['body']['members']:
        if proc.get('kind')=='ProceduralBlock' and proc.get('source_line')==132:
            rhs=proc['body']['stmt']['body']['ifFalse']['body']['expr']['right']
            sel=rhs['operands'][1]
            sel['kind']='ElementSelect'
            sel['selector']={'kind':'IntegerLiteral','value':'2'}
            sel.pop('left',None);sel.pop('right',None);sel.pop('selectionKind',None)
    g=graph(ast)
    reg,ins=d_wires(g,'tx_rst_reg')
    assert len(ins)==1 and not reg.get('dInputStatus')
    s=next(n for n in g['nodes'] if n.get('shape')=='slice' and n['selection']=='[2]')
    assert any(e['source']==s['id'] and e.get('rendered') for e in g['edges'])


@pytest.mark.skipif(not shutil.which('node'), reason='real ELK requires Node')
def test_real_elk_and_canvas_agree_on_slice_and_d_geometry():
    g=graph()
    js=r'''
const fs=require('node:fs'),assert=require('node:assert/strict');
const g=JSON.parse(fs.readFileSync(0,'utf8')),web=process.argv[1];
const Geo=require(web+'/symbol-geometry.js');
const Painter=require(web+'/symbol-painter.js');
const ELK=require(web+'/elk.bundled.js').default;
const Adapter=require(web+'/elk-adapter.js');
(async()=>{
 const result=await Adapter.compute(new ELK(),g,Geo.boxSize);
 for(const regName of ['tx_rst_reg','rx_rst_reg']){
  const r=g.nodes.find(n=>n.name===regName);
  const d=g.edges.find(e=>e.target===r.id&&e.targetPin==='D'&&e.rendered);
  const concat=g.nodes.find(n=>n.id===d.source);
  const sEdge=g.edges.find(e=>e.target===concat.id&&e.pin==='I1'&&e.rendered);
  const slice=g.nodes.find(n=>n.id===sEdge.source);
  assert.equal(slice.selection,'[3:1]');
  const qEdge=g.edges.find(e=>e.target===slice.id&&e.pin==='A'&&e.rendered);
  for(const [edge,node] of [[d,r],[sEdge,concat],[qEdge,slice]]){
   const path=result.edgePaths.get(edge.id);
   assert(path&&path.length>=2,'missing path '+edge.id);
   const end=Geo.absoluteAnchor(node,result.positions.get(node.id),'target',edge);
   assert.deepEqual(path.at(-1),[end.x,end.y]);
  }
  const size=Geo.boxSize(slice);
  assert.equal(size.h,Math.max(36,20+(slice.pins.length-1)*20));
  const ctx=new Proxy({labels:[],save(){},restore(){},fillText(t){this.labels.push(t)}},
    {get(t,k){return k in t?t[k]:()=>{}}});
  Painter.paint(ctx,slice,{x:0,y:0,...size},{colors:{operator:'#e0b',text:'#fff',muted:'#aaa',
    symbolFill:'#224',pickedFill:'#334',selected:'#fa0',signal:'#48a'},zoom:1});
  assert(ctx.labels.includes('[3:1]'),JSON.stringify(ctx.labels));
  assert(!ctx.labels.includes('OP'));
 }
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    p=subprocess.run(['node','-e',js,str(WEB)],input=json.dumps(g),capture_output=True,text=True,timeout=45)
    assert p.returncode == 0, p.stderr + p.stdout
