"""The value path is a navigable focused ELK view, not an invented connection."""
from __future__ import annotations

import json
import shutil
from pathlib import Path
import pytest
from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'
FIXTURE = Path(__file__).resolve().parent / 'fixtures/ethernet_function_call_slang_027.json'


def test_chromium_value_path_function_and_parent_breadcrumb():
    pw = pytest.importorskip('playwright.sync_api')
    chromium = shutil.which('chromium') or shutil.which('chromium-browser')
    if not chromium:
        pytest.skip('Chromium unavailable')
    graph = RtlDesign(json.loads(FIXTURE.read_text()), root=Path.cwd(), top='top').diagram(limit=800)
    graph.update({'module':'top','path':'/','revision':'fixture-value-027',
                  'ancestors':[{'path':'/','name':'top','module':'top'}],
                  'truncated':False,'connectivity':{},'processGroups':[],'fsmGroups':[]})
    with pw.sync_playwright() as driver:
        browser = driver.chromium.launch(headless=True,executable_path=chromium,args=['--no-sandbox'])
        try:
            page = browser.new_page(viewport={'width':1440,'height':820})
            errors=[]
            page.on('pageerror',lambda error:errors.append(str(error)))
            page.set_content((WEB/'index.html').read_text())
            for name in ('style.css','workbench-017.css','workbench-019.css'):
                page.add_style_tag(path=str(WEB/name))
            page.evaluate('''graph=>{
              window.FlexAPI=async(name,params={})=>{
               if(name==='overview')return {top:'top',instances:1,modules:1,source:'Slang verified'};
               if(name==='hierarchy')return {path:params.path||'/',items:[],offset:0,total:0,has_more:false};
               if(name==='diagram')return {...graph,expanded:String(params.expand||'').split('|')};
               if(name==='source')return {file:'rtl/top.sv',text:'',lines:[]};
               if(name==='lint')return {status:'unavailable',diagnostics:[]};
               return {status:'unavailable'};
              };
            }''',graph)
            for name in ('bootstrap-guard.js','router.js','elk.bundled.js',
                         'symbol-geometry.js','symbol-painter.js','elk-adapter.js',
                         'layout-engine.js','hierarchy-tree.js','virtual-process.js',
                         'driver-trace.js','sv-highlight.js','workbench-semantics.js',
                         'theme-presets.js','app.js'):
                page.add_script_tag(path=str(WEB/name))
            page.wait_for_function("state.graph?.nodes?.some(n=>n.name==='rx_bad_event_gray')",timeout=9000)
            page.evaluate('''()=>{
               const node=state.graph.nodes.find(n=>n.name==='rx_bad_event_gray');
               selection(node);inspector(true,'connections');
            }''')
            page.get_by_role('button',name='↗ View value path').click()
            page.wait_for_function("state.graph?.virtualFocus?.startsWith('value:')",timeout=10000)
            result = page.evaluate('''()=>({
              module:state.graph.module,
              names:state.graph.nodes.map(n=>n.name),
              functionNodes:state.graph.nodes.filter(n=>n.shape==='function').map(n=>n.name),
              status:state.graph.traceInfo.status,
              edges:state.graph.edges.map(e=>e.id),
              viewKey:layoutKey(state.graph)
            })''')
            assert result['module'].startswith('Value path')
            assert result['functionNodes']==['gray_of_increment']
            assert result['status']=='available'
            page.wait_for_function("layout(state.graph)?.stats?.engine==='elk'",timeout=15000)
            geometry=page.evaluate('''()=>{
              const d=layout(state.graph);
              return {nodes:d.positions.size,edges:d.edgePaths.size,
                expectedNodes:state.graph.nodes.length,
                expectedEdges:state.graph.edges.filter(e=>e.rendered!==false).length};
            }''')
            assert geometry['nodes']==geometry['expectedNodes']
            assert geometry['edges']==geometry['expectedEdges']
            assert page.locator('#breadcrumb .fsm-crumb-back').count()==1
            page.locator('#breadcrumb .fsm-crumb-back').click()
            page.wait_for_function("state.graph?.module==='top'&&state.valueFocus===null",timeout=10000)
            assert not errors,errors
        finally:
            browser.close()
