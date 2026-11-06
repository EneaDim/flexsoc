"""A flattened virtual parent must not steal its compact child's context menu."""
from pathlib import Path
import shutil

import pytest

from test_virtual_fsm_one_level_050 import _fixture


WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_context_menu_can_flatten_child_inside_flattened_fsm():
    playwright = pytest.importorskip('playwright.sync_api')
    chromium = shutil.which('chromium') or shutil.which('chromium-browser')
    if not chromium:
        pytest.skip('Chromium unavailable')
    compact, expanded = _fixture()
    root = {'path': '/', 'module': 'top', 'revision': 'fixture-052',
            'ancestors': [{'path': '/', 'name': 'top', 'module': 'top'}],
            'nodes': [], 'edges': [], 'connectivity': {}, 'truncated': False}
    for graph in (compact, expanded):
        graph.update({'path': '/rx', 'module': 'rx', 'revision': 'fixture-052',
                      'ancestors': [{'path': '/', 'name': 'top', 'module': 'top'},
                                    {'path': '/rx', 'name': 'rx', 'module': 'rx'}],
                      'connectivity': {}, 'truncated': False})
    with playwright.sync_playwright() as driver:
        browser = driver.chromium.launch(headless=True, executable_path=chromium,
                                         args=['--no-sandbox'])
        try:
            page = browser.new_page(viewport={'width': 1440, 'height': 850})
            page.emulate_media(reduced_motion='reduce')
            errors = []
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
                        {...(String(params.expand||'').split('|').includes('fsm:state')?expanded:compact),
                         expanded:String(params.expand||'').split('|')};
                    if(name==='source')return {file:'rtl/rx.sv',text:'',lines:[]};
                    if(name==='lint')return {status:'unavailable',diagnostics:[]};
                    return {status:'unavailable'};
                };
            }''', {'root': root, 'compact': compact, 'expanded': expanded})
            for asset in ('bootstrap-guard.js', 'router.js', 'elk.bundled.js',
                          'symbol-geometry.js', 'symbol-painter.js', 'elk-adapter.js',
                          'layout-engine.js', 'hierarchy-tree.js', 'virtual-process.js',
                          'sv-highlight.js', 'workbench-semantics.js', 'theme-presets.js', 'app.js'):
                page.add_script_tag(path=str(WEB / asset))
            page.locator('#hierarchy .fs-tree-label[data-path="/rx"]').click()
            page.locator('.fs-tree-row[data-fsm-group="fsm:state"] .fs-tree-virtual-flatten').click()
            page.wait_for_function('''()=>state.graph?.nodes?.some(n=>n.type==='process_group'&&n.group==='proc:2')''')
            page.wait_for_function("()=>layout(state.graph)?.stats?.engine==='elk'", timeout=15000)

            def child_position(token):
                return page.evaluate('''token=>{
                    const node=state.graph.nodes.find(n=>n.type==='process_group'&&n.group===token);
                    if(!node)throw Error('compact child is missing: '+token);
                    const p=layout(state.graph).positions.get(node.id),v=view();
                    if(!p)throw Error('ELK child coordinates are missing');
                    const xy={x:(p.x+p.w/2)*v.z+v.x,y:(p.y+p.h/2)*v.z+v.y};
                    const hitItem=contextTargetAt({x:p.x+p.w/2,y:p.y+p.h/2});
                    if(hitItem?.group!==token)throw Error('parent stole child hit: '+hitItem?.group);
                    return xy;
                }''', token)

            # Right clicking the compact process inside the flattened FSM
            # must offer Flatten (and optionally Enter), NOT parent Unflatten.
            page.locator('#diagram').click(position=child_position('proc:2'), button='right')
            page.locator('#context').wait_for(state='visible')
            assert page.locator('#contextFlatten').is_visible()
            assert 'Flatten here' in page.locator('#contextFlatten').inner_text()
            assert page.locator('#contextGenerate').is_visible()
            page.locator('#contextFlatten').click()
            page.wait_for_function('''()=>state.graph?.processGroups?.some(g=>g.token==='proc:2'&&g.view==='flattened')''')
            assert page.evaluate("expandedGroups().has('fsm:state')")
            assert page.evaluate("expandedGroups().has('proc:2')")
            assert page.evaluate("state.graph.nodes.some(n=>n.type==='process_group'&&n.group==='proc:1')")
            assert not page.evaluate("state.graph.nodes.some(n=>n.type==='process_group'&&n.group==='proc:2')")
            # The sibling always_ff has NOT been opened automatically.
            page.wait_for_function("()=>layout(state.graph)?.stats?.engine==='elk'", timeout=15000)
            page.locator('#diagram').click(position=child_position('proc:1'), button='right')
            assert 'Flatten here' in page.locator('#contextFlatten').inner_text()
            page.keyboard.press('Escape')
            # Closing the selected child does not close the FSM parent.
            page.locator('.fs-tree-row[data-fsm-group="proc:2"] .fs-tree-virtual-flatten').click()
            page.wait_for_function('''()=>state.graph?.nodes?.some(n=>n.type==='process_group'&&n.group==='proc:2')''')
            assert page.evaluate("expandedGroups().has('fsm:state')")
            # The flattened parent's header remains Unflatten-only.
            page.wait_for_function("()=>layout(state.graph)?.stats?.engine==='elk'", timeout=15000)
            parent_label = page.evaluate('''()=>{
                const d=layout(state.graph),v=view();
                const f=frameLabelRects(flattenedFrames(state.graph,d.positions,d.groupRects),
                    v,canvas.clientWidth,canvas.clientHeight).find(x=>x.token==='fsm:state');
                if(!f)throw Error('parent frame is missing');
                return {x:f.labelX+f.labelW-20,y:f.labelY+f.labelH/2};
            }''')
            page.locator('#diagram').click(position=parent_label, button='right')
            assert 'Unflatten here' in page.locator('#contextFlatten').inner_text()
            assert page.locator('#context button:visible').count() == 1
            assert not errors, errors
        finally:
            browser.close()
