"""Native Neovim scroll requests and in-view AST jump affordances."""
from pathlib import Path
import http.client
import json
import threading

from flexsoc.backend.dv.rtl_viewer.server import ViewerServer
import flexsoc.backend.dv.rtl_viewer.server as server_module
from test_neovim_bridge_008 import DummyDesign, FakeNativeSession

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_native_scroll_is_local_token_authenticated_and_bounded(monkeypatch, tmp_path):
    monkeypatch.setattr(server_module, 'NeovimSession', FakeNativeSession)
    srv = ViewerServer(('127.0.0.1', 0), DummyDesign(tmp_path), enable_neovim=True)
    thread = threading.Thread(target=srv.serve_forever, daemon=True)
    thread.start()
    try:
        conn = http.client.HTTPConnection('127.0.0.1', srv.server_port, timeout=5)
        def post(action, body):
            conn.request('POST', '/api/neovim/'+action, body=json.dumps(body),
                         headers={'Content-Type':'application/json', 'Host':f'127.0.0.1:{srv.server_port}'})
            response = conn.getresponse()
            return response.status,json.loads(response.read())
        status, data = post('start', {'path':'/'})
        assert status == 200
        token=data['token']
        assert post('scroll', {'token':'invalid','direction':'down','count':3})[0] == 404
        for count in (-1, 0, 61, True, 1.5):
            assert post('scroll', {'token':token,'direction':'up','count':count})[0] == 400
        assert post('scroll', {'token':token,'direction':'side','count':1})[0] == 400
        assert post('scroll', {'token':token,'direction':'down','count':3})[0] == 200
        assert srv.neovim_session.notifications == [
            ('nvim_input_mouse',['wheel','down','',0,0,0]) for _ in range(3)]
        conn.close()
    finally:
        srv.shutdown();srv.server_close();thread.join(timeout=3)


def test_navigation_is_outside_scrollable_code_and_can_freeze_view():
    js=(WEB/'app.js').read_text()
    editor=(WEB/'neovim-editor.js').read_text()
    html=(WEB/'index.html').read_text()
    assert "$('nvimContainer').before(host)" in js
    assert 'code.prepend(host)' not in js
    assert "if(!state.freezeSchematic&&result.status==='resolved'" in js
    assert 'rtlFreezeSchematic' in html
    assert "screen.addEventListener('wheel'" in editor
    assert "post('scroll'" in editor
    assert 'rtl-reference-legend' in (WEB/'style.css').read_text()


def test_browser_reference_toolbar_stays_visible_and_can_lock(monkeypatch):
    from test_workbench_panels_007 import browser_page
    instance, browser, page = browser_page()
    errors=[]
    page.on('pageerror',lambda error:errors.append(str(error)))
    try:
        page.locator('#toggleInspector').click()
        page.locator('#sourceCode .code-line').first.wait_for()
        page.locator('#a11yNodes button').first.evaluate('(el)=>el.click()')
        page.wait_for_timeout(150)
        toolbar=page.locator('#sourcePane > .source-occurrences')
        toolbar.wait_for()
        assert toolbar.is_visible()
        assert toolbar.evaluate('(el)=>el.parentElement.id')=='sourcePane'
        page.locator('#sourceFallback').evaluate('(el)=>{el.scrollTop=1000}')
        assert toolbar.is_visible()
        freeze=page.locator('#rtlFreezeSchematic')
        freeze.click()
        assert freeze.get_attribute('aria-pressed')=='true'
        freeze.click()
        assert freeze.get_attribute('aria-pressed')=='false'
        assert not errors
    finally:
        browser.close();instance.stop()
