"""Viewport chrome stability and single navigation surface for RTL/Lint.

Only the parent navigator, schematic and right inspector are separate regions.
Lint and source actions end up in the same inspector tabs.
"""
from pathlib import Path

from test_workbench_panels_007 import WEB, browser_page


def test_unique_inspector_navigation_and_fixed_viewport():
    html = (WEB / 'index.html').read_text()
    assert html.count('id="toggleInspector"') == 1
    assert html.count('id="sourceTab"') == 1
    assert html.count('id="lintTab"') == 1
    assert 'id="lintOverlay"' not in html
    assert 'id="showLintOverlay"' not in html
    assert 'id="toggleSource"' not in html
    assert 'id="toggleLint"' not in html
    assert 'id="rtlGoSource"' not in html
    assert 'id="rtlGoLint"' not in html

    instance, browser, page = browser_page()
    errors = []
    page.on('pageerror', lambda err: errors.append(str(err)))
    try:
        opener = page.locator('#toggleInspector')
        assert opener.get_attribute('aria-expanded') == 'false'
        assert page.locator('#inspector').is_hidden()
        opener.click()
        assert page.locator('#inspector').is_visible()
        assert opener.get_attribute('aria-expanded') == 'true'
        page.locator('#lintTab').click()
        assert page.locator('#lintPane').is_visible()
        assert page.locator('#sourcePane').is_hidden()
        page.locator('#sourceTab').click()
        assert page.locator('#sourcePane').is_visible()
        assert page.locator('#lintPane').is_hidden()
        opener.click()
        assert page.locator('#inspector').is_hidden()
        opener.click()
        assert page.locator('#sourcePane').is_visible(), 'Reopen last inspector tab'
        # Browser/page scrolling must not move the application header.
        first = page.locator('.header').bounding_box()
        assert first and first['y'] == 0
        page.evaluate('window.scrollTo(0, 300)')
        page.wait_for_timeout(60)
        after = page.locator('.header').bounding_box()
        assert after and after['y'] == 0
        assert page.evaluate('window.scrollY') == 0
        assert not errors, errors
    finally:
        browser.close()
        instance.stop()
