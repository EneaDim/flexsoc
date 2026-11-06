"""ELK topological constraints and reversible inline virtual process groups.

Port directions are semantic roles; a focused boundary may still have an
AST-backed incoming edge. Such mixed-role ports must not get FIRST/LAST.
"""
from pathlib import Path
import shutil
import subprocess

import pytest

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_real_elk_mixed_role_port_does_not_get_impossible_layer_constraints():
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    js = r'''
const assert=require('node:assert/strict');
const base=process.argv[1],A=require(base+'/elk-adapter.js');
const G=require(base+'/symbol-geometry.js');
const ELK=require(base+'/elk.bundled.js').default;
const nodes=[
 {id:'producer',type:'signal',name:'source'},
 {id:'boundaryIn',type:'port',name:'tx_count_now',direction:'input'},
 {id:'consumer',type:'signal',name:'load'},
 {id:'boundaryOut',type:'port',name:'output_alias',direction:'output'},
 {id:'downstream',type:'signal',name:'downstream'},
 {id:'pureIn',type:'port',name:'clk',direction:'input'},
 {id:'pureOut',type:'port',name:'result',direction:'output'}
];
const edges=[
 {id:'p',source:'producer',target:'boundaryIn',net:'n1',rendered:true},
 {id:'c',source:'boundaryIn',target:'consumer',net:'n2',rendered:true},
 {id:'out',source:'producer',target:'boundaryOut',net:'n3',rendered:true},
 {id:'out-read',source:'boundaryOut',target:'downstream',net:'n4',rendered:true},
 {id:'clk',source:'pureIn',target:'consumer',net:'n5',rendered:true},
 {id:'res',source:'consumer',target:'pureOut',net:'n6',rendered:true},
 {id:'nonphysical',source:'consumer',target:'pureIn',net:'n7',rendered:false}
];
const graph={nodes,edges};
const copy=JSON.stringify(graph),layout=A.convert(graph,G.boxSize);
const option=id=>layout.children.find(n=>n.id===id).layoutOptions['org.eclipse.elk.layered.layering.layerConstraint'];
assert.equal(option('boundaryIn'),undefined,'incoming edge forbids FIRST');
assert.equal(option('boundaryOut'),undefined,'outgoing edge forbids LAST');
assert.equal(option('pureIn'),'FIRST');
assert.equal(option('pureOut'),'LAST');
assert.equal(JSON.stringify(graph),copy,'conversion must not modify the canonical graph');
(async()=>{
 const routed=await A.compute(new ELK(),graph,G.boxSize);
 assert.equal(routed.edgePaths.size,edges.filter(e=>e.rendered).length);
 for(const edge of edges.filter(e=>e.rendered))assert(routed.edgePaths.has(edge.id));
 console.log('MIXED ROLE REAL ELK PASS');
})().catch(err=>{console.error(err);process.exitCode=1});
'''
    proc = subprocess.run(['node', '-e', js, str(WEB)], capture_output=True,
                          text=True, timeout=40)
    assert proc.returncode == 0, proc.stdout + proc.stderr
    assert 'MIXED ROLE REAL ELK PASS' in proc.stdout


def test_browser_unflatten_here_from_canvas_and_sidebar():
    pw = pytest.importorskip('playwright.sync_api')
    chromium = shutil.which('chromium') or shutil.which('chromium-browser')
    if not chromium:
        pytest.skip('Chromium unavailable')
    from flexsoc.backend.dv.rtl_viewer import RtlDesign
    from test_process_virtual_groups_038 import _ast
    graph = RtlDesign(_ast(), root=Path.cwd(), top='demo').diagram(limit=128)
    graph.update({'module': 'demo', 'revision': 'fixture-050', 'path': '/',
                  'ancestors': [{'path': '/', 'name': 'demo', 'module': 'demo'}],
                  'truncated': False, 'connectivity': {}})
    with pw.sync_playwright() as driver:
        browser = driver.chromium.launch(headless=True, executable_path=chromium,
                                         args=['--no-sandbox'])
        try:
            page = browser.new_page(viewport={'width': 1280, 'height': 820})
            # Keep frame-header coordinates stable while the test clicks the
            # overlay: the production UI normally animates camera moves.
            page.emulate_media(reduced_motion='reduce')
            errors=[]
            page.on('pageerror', lambda e: errors.append(str(e)))
            page.set_content((WEB / 'index.html').read_text())
            for style in ('style.css','workbench-017.css','workbench-019.css'):
                page.add_style_tag(path=str(WEB/style))
            page.evaluate('''graph=>{
              window.FlexAPI=async(name,params={})=>{
                if(name==='overview')return {top:'demo',instances:1,modules:1,source:'Slang verified'};
                if(name==='hierarchy')return {path:params.path||'/',items:[],offset:0,total:0,has_more:false};
                if(name==='diagram')return {...graph,expanded:String(params.expand||'').split('|')};
                if(name==='source')return {file:'rtl/demo.sv',text:'',lines:[]};
                if(name==='lint')return {status:'unavailable',diagnostics:[]};
                return {status:'unavailable'};
              };
            }''',graph)
            for asset in ('bootstrap-guard.js','router.js','elk.bundled.js',
                          'symbol-geometry.js','symbol-painter.js','elk-adapter.js',
                          'layout-engine.js','hierarchy-tree.js','virtual-process.js',
                          'sv-highlight.js','workbench-semantics.js','theme-presets.js','app.js'):
                page.add_script_tag(path=str(WEB/asset))
            toggle = page.locator('#hierarchy .fs-tree-virtual').filter(has_text='always_ff').locator('.fs-tree-virtual-flatten')
            toggle.wait_for(timeout=5000)
            compact_edges=page.evaluate("()=>state.graph.edges.map(e=>[e.id,e.source,e.target,e.net])")
            toggle.click()
            page.wait_for_function("()=>state.graph?.processGroups?.some(g=>g.kind==='always_ff'&&g.view==='flattened')")
            page.wait_for_function("()=>layout(state.graph)?.stats?.engine==='elk'",timeout=15000)
            assert 'Unflatten' in toggle.get_attribute('title')
            # Canvas overlay click rather than the sidebar: same scope, same original edges.
            spot=page.evaluate('''()=>{
              const frames=flattenedFrames(state.graph,layout(state.graph).positions,layout(state.graph).groupRects);
              const labels=frameLabelRects(frames,view(),canvas.clientWidth,canvas.clientHeight);
              const item=labels.find(f=>f.type==='process_group'&&f.name.startsWith('always_ff'));
              if(!item)throw Error('no flattened process label');
              return {x:item.labelX+item.labelW-40,y:item.labelY+item.labelH/2};
            }''')
            page.locator('#diagram').click(position=spot)
            page.wait_for_function("()=>state.graph?.processGroups?.some(g=>g.kind==='always_ff'&&g.view==='collapsed')",timeout=10000)
            assert page.locator('#viewName').inner_text()=='demo'
            assert 'Flatten here' in toggle.get_attribute('title')
            restored_edges=page.evaluate("()=>state.graph.edges.map(e=>[e.id,e.source,e.target,e.net])")
            assert restored_edges==compact_edges, 'unflatten must restore original compact edge identities'
            toggle.click()
            page.wait_for_function("()=>state.graph?.processGroups?.some(g=>g.kind==='always_ff'&&g.view==='flattened')")
            toggle.click()
            page.wait_for_function("()=>state.graph?.processGroups?.some(g=>g.kind==='always_ff'&&g.view==='collapsed')")
            assert not errors, errors
        finally:
            browser.close()
