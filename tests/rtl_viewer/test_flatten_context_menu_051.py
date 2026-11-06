"""Flattened virtual frames have one reversible context action and dismiss cleanly."""
from pathlib import Path
import shutil

import pytest

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_flattened_frame_context_menu_is_unflatten_only_and_dismissible():
    pw = pytest.importorskip('playwright.sync_api')
    chromium = shutil.which('chromium') or shutil.which('chromium-browser')
    if not chromium:
        pytest.skip('Chromium unavailable')
    from flexsoc.backend.dv.rtl_viewer import RtlDesign
    from test_process_virtual_groups_038 import _ast

    graph = RtlDesign(_ast(), root=Path.cwd(), top='demo').diagram(limit=128)
    graph.update({'module': 'demo', 'revision': 'fixture-051', 'path': '/',
                  'ancestors': [{'path': '/', 'name': 'demo', 'module': 'demo'}],
                  'truncated': False, 'connectivity': {}})
    with pw.sync_playwright() as driver:
        browser = driver.chromium.launch(headless=True, executable_path=chromium,
                                         args=['--no-sandbox'])
        try:
            page = browser.new_page(viewport={'width': 1280, 'height': 820})
            page.emulate_media(reduced_motion='reduce')
            errors = []
            page.on('pageerror', lambda e: errors.append(str(e)))
            page.set_content((WEB / 'index.html').read_text())
            for style in ('style.css', 'workbench-017.css', 'workbench-019.css'):
                page.add_style_tag(path=str(WEB / style))
            page.evaluate('''graph=>{
              window.FlexAPI=async(name,params={})=>{
                if(name==='overview')return {top:'demo',instances:1,modules:1,source:'Slang verified'};
                if(name==='hierarchy')return {path:params.path||'/',items:[],offset:0,total:0,has_more:false};
                if(name==='diagram')return {...graph,expanded:String(params.expand||'').split('|')};
                if(name==='source')return {file:'rtl/demo.sv',text:'',lines:[]};
                if(name==='lint')return {status:'unavailable',diagnostics:[]};
                return {status:'unavailable'};
              };
            }''', graph)
            for asset in ('bootstrap-guard.js', 'router.js', 'elk.bundled.js',
                          'symbol-geometry.js', 'symbol-painter.js', 'elk-adapter.js',
                          'layout-engine.js', 'hierarchy-tree.js', 'virtual-process.js',
                          'sv-highlight.js', 'workbench-semantics.js', 'theme-presets.js',
                          'app.js'):
                page.add_script_tag(path=str(WEB / asset))
            toggle = page.locator('#hierarchy .fs-tree-virtual').filter(
                has_text='always_ff').locator('.fs-tree-virtual-flatten')
            toggle.wait_for(timeout=7000)
            toggle.click()
            page.wait_for_function('''()=>state.graph?.processGroups?.some(g=>
                g.kind==='always_ff'&&g.view==='flattened')''')
            page.wait_for_function("()=>layout(state.graph)?.stats?.engine==='elk'", timeout=15000)
            spot = page.evaluate('''()=>{
              const d=layout(state.graph),v=view(),frames=flattenedFrames(
                state.graph,d.positions,d.groupRects);
              const label=frameLabelRects(frames,v,canvas.clientWidth,canvas.clientHeight)
                .find(f=>f.type==='process_group'&&f.name.startsWith('always_ff'));
              if(!label)throw Error('missing flattened frame');
              const body={x:label.x+label.w-3,y:label.y+label.h-3};
              if(flattenedFrameAt(body)?.group!==label.token)
                throw Error('right-click in frame interior must find group');
              return {x:label.labelX+label.labelW-30,y:label.labelY+label.labelH/2};
            }''')
            # Right click on header: only the Unflatten menu action is visible.
            page.locator('#diagram').click(position=spot, button='right')
            page.locator('#context').wait_for(state='visible')
            visible = page.locator('#context button:visible')
            assert visible.count() == 1
            assert visible.first.get_attribute('id') == 'contextFlatten'
            assert 'Unflatten' in visible.first.inner_text()
            assert page.locator('#contextTitle').is_hidden()

            # Clicking on *any* other place, including the same diagram, closes it.
            page.locator('#diagram').click(position={'x': 12, 'y': 140})
            assert page.locator('#context').is_hidden()
            page.locator('#diagram').click(position=spot, button='right')
            assert page.locator('#context').is_visible()
            page.keyboard.press('Escape')
            assert page.locator('#context').is_hidden()
            page.locator('#diagram').click(position=spot, button='right')
            assert page.locator('#context').is_visible()
            page.locator('#toggleInspector').click()
            assert page.locator('#context').is_hidden()
            # Restore the original diagram width before reusing screen-space
            # label coordinates; Inspector changes the Canvas viewport size.
            page.locator('#toggleInspector').click()

            # Right clicking outside a flattened frame retains normal module actions.
            page.evaluate('''()=>context({preventDefault(){},clientX:300,clientY:300},null)''')
            assert page.locator('#contextSource').is_visible()
            assert page.locator('#contextLint').is_visible()
            assert page.locator('#contextFlatten').is_hidden()
            page.keyboard.press('Escape')

            # The single action really collapses the process in the current scope.
            page.wait_for_function("()=>layout(state.graph)?.stats?.engine==='elk'", timeout=15000)
            spot = page.evaluate('''()=>{
              const d=layout(state.graph),v=view(),frames=flattenedFrames(state.graph,d.positions,d.groupRects);
              const label=frameLabelRects(frames,v,canvas.clientWidth,canvas.clientHeight)
                .find(f=>f.type==='process_group'&&f.name.startsWith('always_ff'));
              return {x:label.labelX+label.labelW-30,y:label.labelY+label.labelH/2};
            }''')
            page.locator('#diagram').click(position=spot, button='right')
            assert page.locator('#contextFlatten').is_visible(), 'expected Unflatten context action'
            page.locator('#contextFlatten').click(timeout=5000)
            page.wait_for_function('''()=>state.graph?.processGroups?.some(g=>
                g.kind==='always_ff'&&g.view==='collapsed')''', timeout=10000)
            assert page.locator('#viewName').inner_text() == 'demo'
            assert page.locator('#context').is_hidden()
            assert not errors, errors
        finally:
            browser.close()
