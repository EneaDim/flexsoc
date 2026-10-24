"""Real Canvas2D pointer interaction (optional Chromium acceptance test)."""
from pathlib import Path
import shutil

import pytest


HTML = Path(__file__).resolve().parents[2] / 'examples/rtl_schematic_dsp_complex/rtl_viewer_mockup.html'


@pytest.mark.e2e
def test_click_a_middle_wire_segment_then_view_module_source():
    browser_binary = shutil.which('chromium') or shutil.which('google-chrome')
    if not browser_binary:
        pytest.skip('Chromium browser not installed')
    pw = pytest.importorskip('playwright.sync_api')
    with pw.sync_playwright() as driver:
        browser = driver.chromium.launch(headless=True, executable_path=browser_binary, args=['--no-sandbox'])
        try:
            page = browser.new_page(viewport={'width': 1600, 'height': 900})
            errors = []
            page.on('pageerror', lambda error: errors.append(str(error)))
            # Embedding avoids headless browser policies against file:// and
            # localhost. The generated HTML contains its own offline fixture API.
            page.set_content(HTML.read_text(encoding='utf-8'), wait_until='domcontentloaded')
            page.wait_for_function("document.getElementById('counts').textContent.includes('routed wires')", timeout=6000)
            position = page.evaluate('''() => {
                const paths=layout(state.graph).edgePaths, v=view(), r=canvas.getBoundingClientRect();
                for(const e of state.graph.edges){
                    if(!e.port) continue;
                    const poly=paths.get(e.id);
                    for(let i=1;i<poly.length;i++){
                        const x=(poly[i-1][0]+poly[i][0])/2,y=(poly[i-1][1]+poly[i][1])/2;
                        if(hit({x,y})?.id!==e.id)continue;
                        const sx=r.left+x*v.z+v.x,sy=r.top+y*v.z+v.y;
                        if(sx>r.left+40&&sx<r.right-40&&sy>r.top+75&&sy<r.bottom-60)
                            return {x:sx,y:sy};
                    }
                }
                return null;
            }''')
            assert position, 'no routed and clickable wire segment found'
            page.mouse.click(position['x'], position['y'])
            assert 'wire' in page.locator('#message').inner_text()
            page.locator('#toggleSource').click()
            assert page.locator('#sourceFile').inner_text() == 'DSP_stream.sv'
            page.locator('#hierarchy button').filter(has_text='u_filter').click()
            assert page.locator('#sourceFile').inner_text() == 'DSP_fir.sv'
            assert page.locator('#explode').count() == 0  # no generate-specific global control
            # Only the chosen generated group exposes expand via the context menu.
            page.evaluate('''() => {
                const n=state.graph.nodes.find(n=>n.type==='generate');
                if(!n)throw Error('generated group missing');
                const r=layout(state.graph).positions.get(n.id),v=view(),rect=canvas.getBoundingClientRect();
                context({preventDefault(){},clientX:rect.left+(r.x+r.w/2)*v.z+v.x,clientY:rect.top+(r.y+r.h/2)*v.z+v.y},n);
            }''')
            assert page.locator('#contextGenerate').is_visible()
            page.locator('#contextGenerate').click()
            assert '27 routed wires' in page.locator('#counts').inner_text()
            assert page.locator('#contextGenerate').is_hidden()
            # The global lint action opens diagnostics for the current RTL module.
            page.locator('#toggleLint').click()
            assert page.locator('#lintTab').get_attribute('aria-selected') == 'true'
            assert page.locator('#lintPane').is_visible()
            assert not errors, errors
        finally:
            browser.close()
