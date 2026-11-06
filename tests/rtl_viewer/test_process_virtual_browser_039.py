"""Process virtual hierarchy UI: Enter and Flatten are distinct operations."""
from pathlib import Path
import shutil

import pytest

from test_process_virtual_groups_038 import _ast
from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2]/'src/flexsoc/backend/dv/rtl_viewer/web'


def test_browser_process_enter_flatten_and_breadcrumb():
    api = pytest.importorskip('playwright.sync_api')
    chromium = shutil.which('chromium') or shutil.which('chromium-browser')
    if not chromium:
        pytest.skip('Chromium unavailable')
    design=RtlDesign(_ast(),root=Path.cwd(),top='demo')
    graph=design.diagram(limit=800)
    graph.update({'module':'demo','revision':'fixture-039','path':'/',
                  'ancestors':[{'path':'/','name':'demo','module':'demo'}],
                  'truncated':False,'connectivity':{}})
    with api.sync_playwright() as driver:
        browser=driver.chromium.launch(headless=True,executable_path=chromium,args=['--no-sandbox'])
        try:
            page=browser.new_page(viewport={'width':1440,'height':820})
            errors=[]
            page.on('pageerror',lambda e:errors.append(str(e)))
            page.set_content((WEB/'index.html').read_text())
            for css in ('style.css', 'workbench-017.css', 'workbench-019.css'):
                page.add_style_tag(path=str(WEB/css))
            page.evaluate('''graph=>{
             window.FlexAPI=async(name,params={})=>{
              if(name==='overview')return {top:'demo',instances:1,modules:1,source:'Slang verified'};
              if(name==='hierarchy')return {path:params.path||'/',items:[],offset:0,total:0,has_more:false};
              if(name==='diagram')return {...graph,expanded:String(params.expand||'').split('|')};
              if(name==='source')return {file:'rtl/demo.sv',text:'',lines:[]};
              if(name==='lint')return {status:'unavailable',diagnostics:[]};
              if(name==='inspect')return {status:'unresolved'};
              return {status:'unavailable'};
             };
            }''',graph)
            for asset in ('bootstrap-guard.js','router.js','elk.bundled.js',
                          'symbol-geometry.js','symbol-painter.js','elk-adapter.js',
                          'layout-engine.js','hierarchy-tree.js','virtual-process.js',
                          'sv-highlight.js','workbench-semantics.js','theme-presets.js','app.js'):
                page.add_script_tag(path=str(WEB/asset))
            ff=page.locator('#hierarchy .fs-tree-fsm').filter(has_text='always_ff')
            ff.wait_for(timeout=3000)
            group=page.locator('#hierarchy .fs-tree-fsm').filter(has_text='always_ff')
            assert group.count()==1
            assert page.locator('#viewName').inner_text()=='demo'
            # First operation: inline flatten, without changing scope.
            page.locator('#hierarchy .fs-tree-virtual-flatten').first.click()
            page.wait_for_function("document.querySelector('#viewName').textContent === 'demo'")
            assert 'Flatten' not in page.locator('#viewName').inner_text()
            page.locator('#hierarchy .fs-tree-virtual-flatten').first.click()
            # Second operation: dedicated child view and back.
            group.click()
            page.locator('.fsm-crumb-back').wait_for(timeout=5000)
            assert page.locator('#viewName').inner_text().startswith('always_ff')
            page.locator('.fsm-crumb-back').click()
            page.wait_for_function("document.querySelector('#viewName').textContent==='demo'")
            assert not errors, errors
        finally:
            browser.close()


def test_generate_array_enter_flatten_two_modes():
    api = pytest.importorskip('playwright.sync_api')
    chromium=shutil.which('chromium') or shutil.which('chromium-browser')
    if not chromium:
        pytest.skip('Chromium unavailable')
    def leaf():
        return {'kind':'Instance','name':'u_lane','body':{'kind':'InstanceBody',
            'name':'Lane','members':[]}}
    ast={'design':{'members':[{'kind':'Instance','name':'top',
        'body':{'kind':'InstanceBody','name':'top','members':[
            {'kind':'GenerateBlockArray','name':'g_parallel','members':[
                {'kind':'GenerateBlock','branchKind':'LoopIteration','constructIndex':i,
                 'members':[leaf()]} for i in range(3)]}]}}]}}
    d=RtlDesign(ast,root=Path.cwd(),top='top')
    compact=d.diagram('/',limit=128)
    group=next(n['group'] for n in compact['nodes'] if n['type']=='generate')
    expanded=d.diagram('/',limit=128,expanded=(group,))
    assert len([n for n in expanded['nodes'] if n['type']=='instance']) == 3
    for graph in (compact,expanded):
        graph.update({'module':'top','revision':'fixture-gen-039','path':'/',
             'ancestors':[{'path':'/','name':'top','module':'top'}],
             'truncated':False,'connectivity':{}})
    with api.sync_playwright() as driver:
        browser=driver.chromium.launch(headless=True,executable_path=chromium,args=['--no-sandbox'])
        try:
            page=browser.new_page(viewport={'width':1440,'height':820})
            errors=[]
            page.on('pageerror',lambda e:errors.append(str(e)))
            page.set_content((WEB/'index.html').read_text())
            for css in ('style.css', 'workbench-017.css', 'workbench-019.css'):
                page.add_style_tag(path=str(WEB/css))
            page.evaluate('''({compact,expanded,group})=>{
             window.FlexAPI=async (name,params={})=>{
              if(name==='overview')return {top:'top',instances:4,modules:2,source:'Slang verified'};
              if(name==='hierarchy')return {path:params.path||'/',items:[],offset:0,total:0,has_more:false};
              if(name==='diagram')return String(params.expand||'').split('|').includes(group)?
                {...expanded,expanded:[group]}:{...compact,expanded:[]};
              if(name==='source')return {file:'rtl/top.sv',text:'',lines:[]};
              if(name==='lint')return {status:'unavailable',diagnostics:[]};
              return {status:'unavailable'};
             };
            }''',{'compact':compact,'expanded':expanded,'group':group})
            for asset in ('bootstrap-guard.js','router.js','elk.bundled.js',
                          'symbol-geometry.js','symbol-painter.js','elk-adapter.js',
                          'layout-engine.js','hierarchy-tree.js','virtual-process.js',
                          'sv-highlight.js','workbench-semantics.js','theme-presets.js','app.js'):
                page.add_script_tag(path=str(WEB/asset))
            name=page.locator('#hierarchy .fs-tree-fsm').filter(has_text='generate')
            name.wait_for(timeout=3000)
            name.click()
            page.wait_for_function("document.querySelector('#viewName').textContent.startsWith('generate ·')")
            assert page.locator('.fsm-crumb-back').count()==1
            page.locator('.fsm-crumb-back').click()
            page.wait_for_function("document.querySelector('#viewName').textContent==='top'")
            page.locator('#hierarchy .fs-tree-virtual-flatten').first.click()
            page.wait_for_function("document.querySelector('#viewName').textContent==='top'")
            assert page.locator('#hierarchy .fs-tree-fsm').filter(has_text='generate').count()==1
            assert not errors,errors
        finally:
            browser.close()
