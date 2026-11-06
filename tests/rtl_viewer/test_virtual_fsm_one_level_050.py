"""Flatten is one virtual hierarchy level: FSM -> compact processes -> gates.

These are presentation-only transformations.  Nodes, nets and event edges
always retain their Slang-backed identity and their exact Canvas terminals.
"""
from __future__ import annotations

import json
from pathlib import Path
import shutil
import subprocess

import pytest

from test_fsm_submodule_projection_036 import small_graph
from flexsoc.backend.dv.rtl_viewer.fsm_projection import collapse_fsm_cones

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def _fixture():
    graph = small_graph()
    graph['processGroups'] = [
        {'token': 'proc:1', 'name': 'always_ff · L10', 'kind': 'always_ff',
         'memberIds': ['/rx::sig:state'], 'inputIds': ['/rx::sig:clk'],
         'targetIds': ['/rx::sig:state'], 'clockIds': ['/rx::sig:clk'],
         'coverage': 'connected'},
        {'token': 'proc:2', 'name': 'always_comb · L20', 'kind': 'always_comb',
         'memberIds': ['/rx::op:case', '/rx::op:mux'],
         'inputIds': ['/rx::sig:state', '/rx::sig:data'],
         'targetIds': ['/rx::sig:flag'], 'coverage': 'connected'},
    ]
    compact = collapse_fsm_cones(graph, frozenset())
    expanded = collapse_fsm_cones(graph, frozenset({'fsm:state'}))
    assert len(expanded['fsmGroups']) == 1
    return compact, expanded


@pytest.mark.skipif(not shutil.which('node'), reason='Node required')
def test_flatten_fsm_exposes_compact_processes_and_elk_exact_containment(tmp_path):
    compact, expanded = _fixture()
    assert any(n['type'] == 'fsm_group' for n in compact['nodes'])
    file = tmp_path / 'expanded.json'
    file.write_text(json.dumps(expanded))
    script = r'''
const assert=require('node:assert/strict'),fs=require('node:fs');
const W=process.argv[1],graph=JSON.parse(fs.readFileSync(process.argv[2],'utf8'));
const VP=require(W+'/virtual-process.js'), A=require(W+'/elk-adapter.js');
const G=require(W+'/symbol-geometry.js'),ELK=require(W+'/elk.bundled.js').default;
(async()=>{
 const flattenedFSM=VP.project(graph,new Set(['fsm:state']));
 assert.equal(flattenedFSM.nodes.filter(n=>n.type==='process_group').length,2,
  'an expanded FSM reveals its immediate process children, not raw gates');
 assert(!flattenedFSM.nodes.some(n=>n.name==='MUX'||n.name==='CASE'));
 assert.deepEqual(flattenedFSM.processGroups.map(g=>g.view),['collapsed','collapsed']);
 const originalEdgeIDs=new Set(graph.edges.map(e=>e.id));
 assert(flattenedFSM.edges.every(e=>originalEdgeIDs.has(e.id)));
 const layout=await A.compute(new ELK(),flattenedFSM,G.boxSize);
 assert(layout.groupRects.has('fsm:state'), 'FSM flatten must have a real ELK container');
 assert.deepEqual(A.checkCompoundOwnership(flattenedFSM,layout),[]);
 const region=layout.groupRects.get('fsm:state');
 for(const n of flattenedFSM.nodes){
  const r=layout.positions.get(n.id);
  const inside=r.x>=region.x-.001&&r.y>=region.y-.001&&
   r.x+r.w<=region.x+region.w+.001&&r.y+r.h<=region.y+region.h+.001;
  assert.equal(inside,n.type==='process_group',
    'the flattened FSM must contain only its two immediate processes: '+n.name);
 }
 const combOnly=VP.project(graph,new Set(['fsm:state','proc:2']));
 assert(combOnly.nodes.some(n=>n.type==='process_group'&&n.name.startsWith('always_ff')),
    'opening the combinational process must not also flatten the always_ff');
 assert(!combOnly.nodes.some(n=>n.type==='process_group'&&n.name.startsWith('always_comb')));
 assert(combOnly.nodes.some(n=>n.name==='MUX'));
 const nestedLayout=await A.compute(new ELK(),combOnly,G.boxSize);
 assert(nestedLayout.groupRects.has('fsm:state'));
 assert(nestedLayout.groupRects.has('proc:2'));
 assert.deepEqual(A.checkCompoundOwnership(combOnly,nestedLayout),[]);
 for(const [view,geometry] of [[flattenedFSM,layout],[combOnly,nestedLayout]]){
  const byId=new Map(view.nodes.map(n=>[n.id,n]));
  for(const edge of view.edges.filter(e=>e.rendered!==false)){
   const points=geometry.edgePaths.get(edge.id);
   assert(points?.length>=2,'ELK lost edge: '+edge.id);
   const source=G.absoluteAnchor(byId.get(edge.source),geometry.positions.get(edge.source),'source',edge);
   const target=G.absoluteAnchor(byId.get(edge.target),geometry.positions.get(edge.target),'target',edge);
   assert.deepEqual(points[0],[source.x,source.y]);
   assert.deepEqual(points.at(-1),[target.x,target.y]);
  }
 }
 console.log('FSM ONE LEVEL + ELK PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    result = subprocess.run(['node', '-e', script, str(WEB), str(file)],
                            capture_output=True, text=True, timeout=40)
    assert result.returncode == 0, result.stdout + result.stderr
    assert 'FSM ONE LEVEL + ELK PASS' in result.stdout


@pytest.mark.skipif(not shutil.which('node'), reason='Node required')
def test_literal_on_instance_pin_is_vertically_centered():
    script = r'''
const assert=require('node:assert/strict');
const W=process.argv[1];
const G=require(W+'/symbol-geometry.js'),P=require(W+'/symbol-painter.js');
const ports=[{name:'ptp_ts',direction:'input',connection:'constant',constantValue:"1'b1"},
 {name:'txd',direction:'output',connection:'bound'}];
const n={id:'u_tx',name:'u_tx',module:'ethernet_tx',type:'instance',ports};
const box=G.boxSize(n),origin={x:43,y:19,...box},trace=[];
const ctx={save(){},restore(){}};
for(const name of ['beginPath','moveTo','lineTo','stroke','fill','arc','roundRect','fillText',
 'rect','clip','strokeRect'])ctx[name]=(...a)=>trace.push([name,...a,ctx.textBaseline]);
const colors={instance:'#abc',symbolFill:'#223',pickedFill:'#334',muted:'#aaa',text:'#fff',
 binding:'#def',generate:'#ffe',sequential:'#fa0'};
P.paint(ctx,n,origin,{colors,zoom:1,names:true,edges:[]});
const literal=trace.find(v=>v[0]==='fillText'&&v[1]==="1'b1");
assert(literal,'the Slang-proven instance actual is visible');
const pin=G.portRows(n,'target',box).find(v=>v.port.name==='ptp_ts');
assert.equal(literal[3],origin.y+pin.y,'literal centre must be on its exact ELK port Y');
assert.equal(literal.at(-1),'middle','Canvas text baseline must be vertically centred');
assert(literal[2]<origin.x,'label remains left of the input pin');
console.log('INSTANCE LITERAL CENTER PASS');
'''
    result = subprocess.run(['node', '-e', script, str(WEB)],
                            capture_output=True, text=True, timeout=15)
    assert result.returncode == 0, result.stdout + result.stderr
    assert 'INSTANCE LITERAL CENTER PASS' in result.stdout


def test_browser_fsm_flatten_one_level_and_child_unflatten():
    sync = pytest.importorskip('playwright.sync_api')
    chromium = shutil.which('chromium') or shutil.which('chromium-browser')
    if not chromium:
        pytest.skip('Chromium unavailable')
    compact, expanded = _fixture()
    root = {'path': '/', 'module': 'top', 'revision': 'fixture-050',
            'ancestors': [{'path': '/', 'name': 'top', 'module': 'top'}],
            'nodes': [], 'edges': [], 'connectivity': {}, 'truncated': False}
    for graph in (compact, expanded):
        graph.update({'module': 'rx', 'revision': 'fixture-050', 'path': '/rx',
                      'ancestors': [{'path': '/', 'name': 'top', 'module': 'top'},
                                    {'path': '/rx', 'name': 'rx', 'module': 'rx'}],
                      'connectivity': {}, 'truncated': False})
    with sync.sync_playwright() as driver:
        browser = driver.chromium.launch(headless=True, executable_path=chromium,
                                         args=['--no-sandbox'])
        try:
            page = browser.new_page(viewport={'width': 1400, 'height': 820})
            errors: list[str] = []
            page.on('pageerror', lambda e: errors.append(str(e)))
            page.set_content((WEB / 'index.html').read_text())
            for css in ('style.css', 'workbench-017.css', 'workbench-019.css'):
                page.add_style_tag(path=str(WEB / css))
            page.evaluate('''({root,compact,expanded})=>{
                window.FlexAPI=async(name,params={})=>{
                    const path=params.path||'/';
                    if(name==='overview')return {top:'top',instances:2,modules:2,source:'Slang'};
                    if(name==='hierarchy')return {path,items:path==='/'?
                      [{path:'/rx',name:'rx',module:'rx',has_children:false}]:[],
                      offset:0,total:path==='/'?1:0,has_more:false};
                    if(name==='diagram')return path==='/'?root:
                      (String(params.expand||'').split('|').includes('fsm:state')?expanded:compact);
                    if(name==='source')return {file:'rtl/rx.sv',text:'',lines:[]};
                    if(name==='lint')return {status:'unavailable',diagnostics:[]};
                    if(name==='inspect')return {status:'unresolved'};
                    return {status:'unavailable'};
                };
            }''', {'root': root, 'compact': compact, 'expanded': expanded})
            for asset in ('bootstrap-guard.js', 'router.js', 'elk.bundled.js',
                          'symbol-geometry.js', 'symbol-painter.js', 'elk-adapter.js',
                          'layout-engine.js', 'hierarchy-tree.js', 'virtual-process.js',
                          'sv-highlight.js', 'workbench-semantics.js', 'theme-presets.js', 'app.js'):
                page.add_script_tag(path=str(WEB / asset))
            page.locator('#hierarchy .fs-tree-label[data-path="/rx"]').click()
            fsm = page.locator('.fs-tree-row[data-fsm-group="fsm:state"] .fs-tree-virtual-flatten')
            fsm.wait_for(timeout=5000)
            fsm.click()
            page.wait_for_function("document.querySelector('#a11yNodes').textContent.includes('always_comb · L20 · process_group')")
            a11y = page.locator('#a11yNodes').text_content()
            assert 'always_ff · L10 · process_group' in a11y
            assert 'always_comb · L20 · process_group' in a11y
            assert 'MUX · operator' not in a11y  # only one FSM hierarchy layer
            comb = page.locator('.fs-tree-row[data-fsm-group="proc:2"] .fs-tree-virtual-flatten')
            comb.click()
            page.wait_for_function("document.querySelector('#a11yNodes').textContent.includes('MUX · operator')")
            a11y = page.locator('#a11yNodes').text_content()
            assert 'always_ff · L10 · process_group' in a11y
            assert 'always_comb · L20 · process_group' not in a11y
            comb.click()  # unflatten child only
            page.wait_for_function("document.querySelector('#a11yNodes').textContent.includes('always_comb · L20 · process_group')")
            fsm.click()  # unflatten parent
            page.wait_for_function("document.querySelector('#a11yNodes').textContent.includes('FSM · state · fsm_group')")
            assert not errors, errors
        finally:
            browser.close()
