"""Flatten remains a visibly labelled virtual frame in the real Canvas."""
from __future__ import annotations

from pathlib import Path
import shutil

import pytest
from flexsoc.backend.dv.rtl_viewer import RtlDesign
from test_process_virtual_groups_038 import _ast

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_chromium_flatten_keeps_box_and_enter_remains_independent():
    pw = pytest.importorskip('playwright.sync_api')
    chromium = shutil.which('chromium') or shutil.which('chromium-browser')
    if not chromium:
        pytest.skip('Chromium unavailable')
    graph = RtlDesign(_ast(), root=Path.cwd(), top='demo').diagram(limit=128)
    graph.update({'module': 'demo', 'revision': 'fixture-041', 'path': '/',
                  'ancestors': [{'path': '/', 'name': 'demo', 'module': 'demo'}],
                  'truncated': False, 'connectivity': {}})
    with pw.sync_playwright() as driver:
        browser = driver.chromium.launch(headless=True, executable_path=chromium,
                                         args=['--no-sandbox'])
        try:
            page = browser.new_page(viewport={'width': 1280, 'height': 780})
            errors = []
            page.on('pageerror', lambda e: errors.append(str(e)))
            page.set_content((WEB / 'index.html').read_text())
            for style in ('style.css', 'workbench-017.css', 'workbench-019.css'):
                page.add_style_tag(path=str(WEB / style))
            page.evaluate('''graph=>{
              window.FlexAPI=async (name,params={})=>{
               if(name==='overview')return {top:'demo',instances:1,modules:1,source:'Slang verified'};
               if(name==='hierarchy')return {path:params.path||'/',items:[],offset:0,total:0,has_more:false};
               if(name==='diagram')return {...graph,expanded:String(params.expand||'').split('|')};
               if(name==='source')return {file:'rtl/demo.sv',text:'',lines:[]};
               if(name==='lint')return {status:'unavailable',diagnostics:[]};
               if(name==='inspect')return {status:'unresolved'};
               return {status:'unavailable'};
              };
            }''', graph)
            for asset in ('bootstrap-guard.js', 'router.js', 'elk.bundled.js',
                          'symbol-geometry.js', 'symbol-painter.js', 'elk-adapter.js',
                          'layout-engine.js', 'hierarchy-tree.js', 'virtual-process.js',
                          'sv-highlight.js', 'workbench-semantics.js',
                          'theme-presets.js', 'app.js'):
                page.add_script_tag(path=str(WEB / asset))
            ff = page.locator('#hierarchy .fs-tree-virtual').filter(has_text='always_ff')
            ff.wait_for(timeout=7000)
            toggle = ff.locator('.fs-tree-virtual-flatten')
            toggle.click()
            page.wait_for_function('''()=>state.graph?.processGroups?.some(g=>
              g.kind==='always_ff'&&g.view==='flattened')''')
            page.wait_for_function('''()=>layout(state.graph)?.stats?.engine==='elk' ''', timeout=15000)
            result = page.evaluate('''()=>{
             const v=view(), d=layout(state.graph),frames=flattenedFrames(state.graph,d.positions);
             const ff=frames.find(f=>f.type==='process_group'&&f.name.startsWith('always_ff'));
             const label=frameLabelRects(frames,v,diagram.clientWidth,diagram.clientHeight)
              .find(f=>f.name===ff?.name);
             return {frame:ff&&{w:ff.w,h:ff.h},label:label&&{x:label.labelX,y:label.labelY},
              virtualNodes:state.graph.nodes.filter(n=>n.type==='process_group'&&n.group==='proc:7').length};
            }''')
            assert result['frame'] and result['frame']['w'] > 0
            assert result['frame']['h'] > 0
            assert result['label'] and result['label']['y'] >= 0
            assert not errors, errors
            toggle.click()
            ff.click()
            page.locator('.fsm-crumb-back').wait_for(timeout=5000)
            page.locator('.fsm-crumb-back').click()
            page.wait_for_function("()=>document.getElementById('viewName').textContent==='demo'")
            assert not errors, errors
        finally:
            browser.close()
