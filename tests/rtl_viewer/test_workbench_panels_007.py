"""Browser-level panel contracts against a compiler-backed AST fixture.

The synthetic HTTP bridge is limited to the browser harness; geometry uses the
real vendored ELK and Canvas implementation. No real Slang process is claimed.
"""
import json
from pathlib import Path
import shutil

import pytest

from test_rtl_viewer import fixture_ast, ROOT
from flexsoc.backend.dv.rtl_viewer.model import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def browser_page():
    sync = pytest.importorskip('playwright.sync_api')
    executable = shutil.which('chromium') or shutil.which('chromium-browser')
    if not executable:
        pytest.skip('Chromium unavailable')
    instance = sync.sync_playwright().start()
    try:
        browser = instance.chromium.launch(executable_path=executable, headless=True,
                                           args=['--no-sandbox'])
    except Exception as err:
        instance.stop()
        pytest.skip('Chromium cannot launch: ' + str(err))
    page = browser.new_page(viewport={'width': 1400, 'height': 850})
    design = RtlDesign(fixture_ast(), root=ROOT, top='DSP')
    scopes = {path: {'hierarchy': design.hierarchy_children(path),
                     'diagram': design.diagram(path), 'source': design.source(path)}
              for path in design.scopes}
    page.set_content((WEB / 'index.html').read_text())
    page.add_style_tag(path=str(WEB / 'style.css'))
    page.evaluate('''({overview,scopes})=>{
     window.FlexAPI=async (name,params={})=>{
      const path=params.path||'/',item=scopes[path];
      if(name==='overview')return overview;
      if(name==='hierarchy'){
       const h=item.hierarchy,offset=Number(params.offset||0),limit=Number(params.limit||64);
       return {...h,offset,limit,items:h.items.slice(offset,offset+limit),has_more:offset+limit<h.total};
      }
      if(name==='diagram')return item.diagram;
      if(name==='source')return item.source;
      if(name==='lint')return {status:'unavailable',diagnostics:[]};
      if(name==='inspect')return {status:'unresolved',reason:'No inspector in test bridge'};
      return {status:'unavailable'};
     };
    }''', {'overview': design.overview(), 'scopes': scopes})
    for asset in ('bootstrap-guard.js', 'router.js', 'elk.bundled.js',
                  'symbol-geometry.js', 'symbol-painter.js', 'elk-adapter.js',
                  'layout-engine.js', 'hierarchy-tree.js', 'app.js'):
        page.add_script_tag(path=str(WEB / asset))
    return instance, browser, page


def test_hierarchy_filter_and_keyboard_keep_lazy_semantics():
    instance, browser, page = browser_page()
    errors = []
    page.on('pageerror', lambda error: errors.append(str(error)))
    try:
        page.locator('#hierarchy .fs-tree-label').first.wait_for()
        page.keyboard.press('Control+k')
        assert page.locator('#hierarchyFilter').evaluate('(el)=>document.activeElement===el')
        page.keyboard.type('pipeline')
        assert page.locator('#hierarchy .fs-tree-label').count() == 1
        assert 'not a full-design search' in page.locator('#hierarchyFilterStatus').inner_text()
        page.keyboard.press('ArrowDown')
        assert page.locator('#hierarchy .fs-tree-label').first.evaluate('(el)=>document.activeElement===el')
        page.keyboard.press('Enter')
        page.wait_for_function("document.getElementById('viewName').textContent === 'DSP_core'")
        page.locator('#hierarchyFilter').focus()
        page.keyboard.press('Escape')
        assert page.locator('#hierarchyFilter').input_value() == ''
        assert page.locator('#hierarchy .fs-tree-label').count() > 1
        assert not errors
    finally:
        browser.close()
        instance.stop()


def test_inspector_read_only_source_and_keyboard_tabs():
    instance, browser, page = browser_page()
    errors = []
    page.on('pageerror', lambda error: errors.append(str(error)))
    try:
        page.locator('#toggleInspector').click()
        assert page.locator('#inspector').is_visible()
        assert page.locator('.source-mode').inner_text().startswith('READ ONLY')
        page.locator('#sourceTab').focus()
        page.keyboard.press('ArrowRight')
        assert page.locator('#lintTab').get_attribute('aria-selected') == 'true'
        assert page.locator('#sourceTab').get_attribute('tabindex') == '-1'
        page.keyboard.press('Home')
        assert page.locator('#detailsTab').get_attribute('aria-selected') == 'true'
        page.keyboard.press('End')
        assert page.locator('#coneTab').get_attribute('aria-selected') == 'true'
        assert not errors
    finally:
        browser.close()
        instance.stop()
