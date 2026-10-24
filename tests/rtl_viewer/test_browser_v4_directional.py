"""Browser checks: theme, hierarchy, orthogonal lanes, dense routing."""
from pathlib import Path
import shutil

import pytest

HTML = Path(__file__).resolve().parents[2] / 'examples/rtl_schematic_dsp_complex/rtl_viewer_mockup.html'


def test_browser_light_dark_breadcrumb_and_parallel_lanes():
    chromium = shutil.which('chromium') or shutil.which('google-chrome')
    if not chromium:
        pytest.skip('Chromium not installed')
    pw = pytest.importorskip('playwright.sync_api')
    with pw.sync_playwright() as driver:
        browser = driver.chromium.launch(headless=True, executable_path=chromium, args=['--no-sandbox'])
        try:
            page = browser.new_page(viewport={'width': 1620, 'height': 920})
            errors = []
            page.on('pageerror', lambda e: errors.append(str(e)))
            page.set_content(HTML.read_text(encoding='utf-8'))
            page.wait_for_function('state.graph !== null')
            assert page.locator('#breadcrumb button').all_inner_texts() == ['DSP_stream']
            page.locator('#themeToggle').click()
            assert page.evaluate('document.documentElement.dataset.theme') == 'light'
            page.wait_for_timeout(220)  # complete the color transition
            assert page.evaluate("getComputedStyle(document.documentElement).getPropertyValue('--canvas').trim()") == '#f4f9fd'
            page.locator('#hierarchy button').filter(has_text='u_filter').click()
            page.wait_for_function("state.path==='/u_filter'")
            assert page.locator('#breadcrumb button').all_inner_texts() == ['DSP_stream', 'u_filter']
            assert page.locator('#breadcrumb button').last.get_attribute('aria-current') == 'page'
            page.locator('#breadcrumb button').first.click()
            page.wait_for_function("state.path==='/'")
            assert page.locator('#breadcrumb button').all_inner_texts() == ['DSP_stream']
            dense = page.evaluate('''() => {
              const nodes=[],edges=[];
              for(let i=0;i<150;i++){
               nodes.push({id:'src:'+i,type:'port',name:'source'+i,direction:'in'});
               nodes.push({id:'reg:'+i,type:'register',name:'reg'+i});
               edges.push({id:'edge:'+i,source:'src:'+i,target:'reg:'+i,
                type:'data',net:'src:'+i,width:'logic [63:0]'});
              }
              const start=performance.now();
              const d=layout({path:'/stress',revision:'v4',expanded:[],nodes,edges});
              return {elapsed:performance.now()-start,count:d.edgePaths.size,
               unique:new Set([...d.edgePaths.values()].map(x=>JSON.stringify(x))).size};
            }''')
            assert dense['count'] == dense['unique'] == 150
            # Generous CI limit; this is a regression guard, not an advertised
            # benchmark for production-scale designs.
            assert dense['elapsed'] < 2000
            assert not errors, errors
        finally:
            browser.close()
