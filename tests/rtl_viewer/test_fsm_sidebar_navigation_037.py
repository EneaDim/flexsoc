"""Browser contract: enter virtual FSM schematic and return to real parent."""
import json
from pathlib import Path
import shutil

import pytest

from test_fsm_submodule_projection_036 import small_graph
from flexsoc.backend.dv.rtl_viewer.fsm_projection import collapse_fsm_cones

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_fsm_sidebar_and_breadcrumb_round_trip():
    sync = pytest.importorskip('playwright.sync_api')
    chromium = shutil.which('chromium') or shutil.which('chromium-browser')
    if not chromium:
        pytest.skip('Chromium unavailable')
    original = small_graph()
    original['nodes'].append({'id':'/rx::sig:unrelated','type':'signal','name':'unrelated'})
    compact = collapse_fsm_cones(original, frozenset())
    expanded = collapse_fsm_cones(original, frozenset({'fsm:state'}))
    for graph in (compact, expanded):
        graph.update({'module': 'ethernet_rx', 'revision': 'fixture-037',
                      'path': '/rx', 'ancestors': [
                          {'path': '/', 'name': 'ethernet', 'module': 'ethernet'},
                          {'path': '/rx', 'name': 'rx', 'module': 'ethernet_rx'}],
                      'connectivity': {}, 'truncated': False})
    root = {'path': '/', 'module': 'ethernet', 'revision': 'fixture-037',
            'ancestors': [{'path': '/', 'name': 'ethernet', 'module': 'ethernet'}],
            'nodes': [], 'edges': [], 'connectivity': {}, 'truncated': False}
    with sync.sync_playwright() as driver:
        browser = driver.chromium.launch(headless=True, executable_path=chromium,
                                          args=['--no-sandbox'])
        try:
            page = browser.new_page(viewport={'width': 1400, 'height': 850})
            errors = []
            page.on('pageerror', lambda e: errors.append(str(e)))
            page.set_content((WEB / 'index.html').read_text())
            page.add_style_tag(path=str(WEB / 'style.css'))
            page.evaluate('''({root,compact,expanded})=>{
                window.FlexAPI=async (name, params={})=>{
                    const path=params.path||'/';
                    if(name==='overview')return {top:'ethernet',instances:2,modules:2,source:'Slang verified'};
                    if(name==='hierarchy')return {path,items:path==='/'?[{path:'/rx',name:'rx',module:'ethernet_rx',has_children:false}]:[],
                        offset:Number(params.offset||0),limit:64,total:path==='/'?1:0,has_more:false};
                    if(name==='diagram')return path==='/'?root:(String(params.expand||'').split('|').includes('fsm:state')?expanded:compact);
                    if(name==='source')return {file:'rtl/ethernet_rx.sv',text:'',lines:[]};
                    if(name==='lint')return {status:'unavailable',diagnostics:[]};
                    if(name==='inspect')return {status:'unresolved'};
                    return {status:'unavailable'};
                };
            }''', {'root': root, 'compact': compact, 'expanded': expanded})
            for asset in ('bootstrap-guard.js', 'router.js', 'elk.bundled.js',
                          'symbol-geometry.js', 'symbol-painter.js', 'elk-adapter.js',
                          'layout-engine.js', 'hierarchy-tree.js', 'virtual-process.js',
                          'sv-highlight.js', 'workbench-semantics.js','theme-presets.js', 'app.js'):
                page.add_script_tag(path=str(WEB / asset))
            page.locator('#hierarchy .fs-tree-label[data-path="/rx"]').click()
            virtual = page.locator('#hierarchy .fs-tree-fsm[data-fsm-group="fsm:state"]')
            virtual.wait_for()
            assert virtual.get_attribute('aria-expanded') == 'false'
            assert page.locator('#hierarchy .fs-tree-label[data-path="/rx"]').count() == 1
            virtual.click()
            page.locator('.fsm-crumb-back').wait_for()
            assert virtual.get_attribute('aria-expanded') == 'true'
            assert 'FSM · state' in page.locator('.fsm-crumb-label').inner_text()
            assert page.locator('#viewName').inner_text() == 'FSM · state'
            assert '6 symbols' in page.locator('#counts').inner_text()
            assert page.locator('#viewName').inner_text() == 'FSM · state'
            page.locator('.fsm-crumb-back').click()
            page.wait_for_function("document.querySelector('.fsm-crumb-back')===null")
            assert virtual.get_attribute('aria-expanded') == 'false'
            assert page.locator('#viewName').inner_text() == 'ethernet_rx'
            virtual.click()
            page.locator('.fsm-crumb-back').wait_for()
            virtual.click()  # The same persistent sidebar entry goes back.
            page.wait_for_function("document.querySelector('.fsm-crumb-back')===null")
            assert virtual.get_attribute('aria-expanded') == 'false'
            assert not errors, errors
        finally:
            browser.close()
