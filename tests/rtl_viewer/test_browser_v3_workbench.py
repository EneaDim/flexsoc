"""Browser acceptance for V3 generic toolbar and symbol-specific menus."""
from pathlib import Path
import shutil

import pytest

HTML = Path(__file__).resolve().parents[2] / 'examples/rtl_schematic_dsp_complex/rtl_viewer_mockup.html'


def test_global_inspector_search_and_contextual_generate():
    chromium = shutil.which('chromium') or shutil.which('google-chrome')
    if not chromium:
        pytest.skip('Chromium unavailable')
    pw = pytest.importorskip('playwright.sync_api')
    with pw.sync_playwright() as driver:
        browser = driver.chromium.launch(headless=True, executable_path=chromium, args=['--no-sandbox'])
        try:
            page = browser.new_page(viewport={'width': 1600, 'height': 900})
            errors = []
            page.on('pageerror', lambda error: errors.append(str(error)))
            page.set_content(HTML.read_text(encoding='utf-8'), wait_until='domcontentloaded')
            page.wait_for_function("document.getElementById('counts').textContent.includes('routed wires')")
            assert 'explode' not in ' '.join(page.locator('.toolbar button').all_inner_texts()).lower()
            page.keyboard.press('/')
            assert page.evaluate("document.activeElement.id") == 'search'
            page.locator('#search').fill('fir_raw')
            assert page.locator('#searchResults button').count() >= 1
            page.keyboard.press('Enter')
            assert 'fir_raw' in page.locator('#message').inner_text()
            page.locator('#toggleLint').click()
            assert page.locator('#lintPane').is_visible()
            page.locator('#toggleSource').click()
            assert page.locator('#sourceFile').inner_text() == 'DSP_stream.sv'
            page.locator('#hierarchy button').filter(has_text='u_filter').click()
            assert page.locator('#sourceFile').inner_text() == 'DSP_fir.sv'
            count_before = page.locator('#counts').inner_text()
            page.evaluate('''() => {
                const n = state.graph.nodes.find(n=>n.type==='generate');
                if(!n)throw Error('missing grouped generate');
                const r=canvas.getBoundingClientRect();
                context({preventDefault(){},clientX:r.left+190,clientY:r.top+220},n);
            }''')
            assert page.locator('#contextGenerate').is_visible()
            assert 'Expand instances' in page.locator('#contextGenerate').inner_text()
            page.locator('#contextGenerate').click()
            assert page.locator('#counts').inner_text() != count_before
            page.evaluate('''() => {
                const n=state.graph.nodes.find(n=>n.type==='instance'&&n.group);
                const r=canvas.getBoundingClientRect();
                context({preventDefault(){},clientX:r.left+190,clientY:r.top+220},n);
            }''')
            assert 'Collapse instances' in page.locator('#contextGenerate').inner_text()
            page.locator('#contextGenerate').click()
            assert page.locator('#counts').inner_text() == count_before
            assert not errors, errors
        finally:
            browser.close()
