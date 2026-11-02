"""Tests native-Neovim protocol boundary; no mocked test claims real nvim success."""
import http.client
import json
from pathlib import Path
import threading

import pytest

from flexsoc.backend.dv.rtl_viewer.neovim import NeovimGrid, bounded_size, capability
from flexsoc.backend.dv.rtl_viewer.server import ViewerServer
from flexsoc.backend.dv.rtl_viewer.model import RtlDesign
from test_rtl_viewer import fixture_ast, ROOT


def test_linegrid_sequence_and_scroll_without_invented_content():
    grid = NeovimGrid()
    grid.update([['grid_resize', [1, 20, 4]],
                 ['hl_attr_define', [3, {'foreground': 0x123456, 'bold': True}, {}, []]],
                 ['grid_line', [1, 0, 0, [['abc', 3], [' ', 0, 3]]]],
                 ['grid_cursor_goto', [1, 0, 1]], ['flush', []]])
    data = grid.snapshot(-1)
    assert data['width'] == 20 and data['height'] == 4
    assert data['rows'][0][0] == ['abc', 3]
    assert data['styles'][3]['foreground'] == 0x123456
    assert data['cursor'] == [0, 1]
    assert grid.snapshot(data['version']) == {'version': data['version'], 'changed': False}
    grid.update([['grid_scroll', [1, 0, 4, 0, 20, -1, 0]], ['flush', []]])
    assert grid.snapshot(-1)['rows'][1][0][0] == 'abc'
    with pytest.raises(ValueError):
        grid.update([['grid_resize', [1, 9999, 4]]])


def test_dimension_and_capability_are_bounded():
    assert bounded_size('80', 20) == (80, 20)
    for vals in ((0, 24), (80, 200), ('NaN', 20)):
        with pytest.raises(ValueError):
            bounded_size(*vals)
    assert capability(False, True)['enabled'] is False
    assert capability(True, False)['enabled'] is False


def test_source_symbols_never_guess_ambiguous_lines(tmp_path):
    model = RtlDesign(fixture_ast(), root=ROOT, top='DSP')
    with pytest.raises(ValueError):
        model.source_symbols('/', 0)
    assert model.source_symbols('/', 999999)['status'] == 'unresolved'
    for item in model._signals(model.scopes['/']).values():
        if item['line'] and item['file']:
            result = model.source_symbols('/', item['line'])
            assert result['status'] in ('resolved', 'ambiguous', 'unresolved')
            assert all(c['id'].startswith('/::sig:') for c in result['candidates'])


class DummyDesign:
    def __init__(self, root):
        self.root = root

    def source(self, path):
        if path != '/':
            return {'status': 'unresolved'}
        return {'status': 'available', 'code': 'module top; endmodule', 'file': 'top.sv'}


class FakeNativeSession:
    def __init__(self, root, source, *, width, height):
        self.token = 'controlled-session-token'
        self.source = source
        self.dimensions = (width, height)
        self.requests = []
        self.notifications = []
        self.closed = False

    def snapshot(self, since):
        return {'status': 'available', 'changed': False, 'version': 1}

    def request(self, method, arguments, **kw):
        self.requests.append((method, arguments))

    def notify(self, method, arguments):
        self.notifications.append((method, arguments))

    def close(self):
        self.closed = True


def test_local_host_and_session_token_are_enforced(monkeypatch, tmp_path):
    import flexsoc.backend.dv.rtl_viewer.server as module
    monkeypatch.setattr(module, 'NeovimSession', FakeNativeSession)
    srv = ViewerServer(('127.0.0.1', 0), DummyDesign(tmp_path), enable_neovim=True)
    worker = threading.Thread(target=srv.serve_forever, daemon=True)
    worker.start()
    try:
        conn = http.client.HTTPConnection('127.0.0.1', srv.server_port, timeout=5)
        def post(route, body, origin=None, host=None):
            headers = {'Content-Type': 'application/json',
                       'Host': host or f'127.0.0.1:{srv.server_port}'}
            if origin:
                headers['Origin'] = origin
            conn.request('POST', '/api/neovim/'+route, body=json.dumps(body), headers=headers)
            response = conn.getresponse()
            return response.status, json.loads(response.read())
        assert post('start', {'path': '/'}, origin='https://evil.example')[0] == 403
        assert post('start', {'path': '/'}, host='attacker.example')[0] == 403
        assert post('start', {'path': '/../secret'})[0] == 400
        status, initial = post('start', {'path': '/', 'cols': 80, 'rows': 24})
        assert status == 200 and initial['readonly']
        token = initial['token']
        assert post('input', {'token': 'wrong', 'keys': 'x'})[0] == 404
        assert post('input', {'token': token, 'keys': 'j'})[0] == 200
        assert srv.neovim_session.notifications == [('nvim_input', ['j'])]
        assert post('resize', {'token': token, 'cols': 100000, 'rows': 30})[0] == 400
        assert post('cursor', {'token': token, 'line': 3})[0] == 200
        assert srv.neovim_session.requests == [('nvim_win_set_cursor', [0, [3, 0]])]
        assert post('stop', {'token': token})[0] == 200
        assert srv.neovim_session is None
        conn.close()
    finally:
        srv.shutdown()
        srv.server_close()
        worker.join(timeout=3)


def test_native_editor_frontend_uses_rpc_input_and_safe_fallback():
    from test_workbench_panels_007 import browser_page, WEB
    instance, browser, page = browser_page()
    errors = []
    page.on('pageerror', lambda e: errors.append(str(e)))
    try:
        page.evaluate('''() => {
            window.nativeRequests = [];
            window.fetch = async (url, options={}) => {
                const route = String(url);
                if (!route.startsWith('/api/neovim/')) throw Error('Unexpected fetch: '+route);
                const action = route.split('/api/neovim/')[1].split('?')[0];
                const body = options.body ? JSON.parse(options.body) : {};
                window.nativeRequests.push({action,body});
                const grid = [['module top;', 0], ['endmodule ', 0]];
                const result = action === 'start' ? {status:'available',token:'test-token',file:'DSP.sv',readonly:true}
                  : action === 'state' ? {status:'available',changed:true,version:2,
                    width:20,height:4,cursor:[0,1],styles:{},fg:16777215,bg:0,
                    rows:[[['module top;         ',0]],[['endmodule           ',0]],[['                    ',0]],[['                    ',0]]],source_line:1}
                  : {status:'ok'};
                return {ok:true,json:async()=>result};
            };
        }''')
        page.add_script_tag(path=str(WEB / 'neovim-editor.js'))
        page.locator('#toggleSource').click()
        page.locator('#sourceCode .code-line').first.wait_for()
        page.locator('#rtlNeovimToggle').click()
        page.locator('#nvimScreen .nvim-row').first.wait_for()
        assert page.locator('#sourceFallback').is_hidden()
        assert page.locator('#nvimContainer').is_visible()
        page.locator('#nvimScreen').focus()
        page.keyboard.press('j')
        page.wait_for_function("window.nativeRequests.some(r => r.action === 'input' && r.body.keys === 'j')")
        page.locator('#rtlNeovimToggle').click()
        assert page.locator('#sourceFallback').is_visible()
        assert not errors
    finally:
        browser.close()
        instance.stop()


def test_real_rpc_transport_against_mock_protocol_process(monkeypatch, tmp_path):
    """Exercise pipes/MessagePack/UI protocol; still NOT a real Neovim binary."""
    pytest.importorskip('msgpack')
    from flexsoc.backend.dv.rtl_viewer import neovim
    fake = tmp_path / 'fake-nvim'
    fake.write_text('''#!/usr/bin/env python3
import msgpack,sys,os
reader=msgpack.Unpacker(raw=False)
while chunk := os.read(sys.stdin.fileno(), 16384):
    reader.feed(chunk)
    for msg in reader:
        if msg[0] != 0: continue
        _,request_id,method,params=msg
        sys.stdout.buffer.write(msgpack.packb([1,request_id,None,[1,0] if method=='nvim_win_get_cursor' else None],use_bin_type=True))
        if method=='nvim_ui_attach':
            sys.stdout.buffer.write(msgpack.packb([2, 'redraw', [['grid_resize', [1,20,4]], ['grid_line', [1,0,0,[['native',3]]]], ['flush', []]]], use_bin_type=True))
        sys.stdout.buffer.flush()
''')
    fake.chmod(0o755)
    monkeypatch.setattr(neovim.shutil, 'which', lambda _: str(fake))
    session = neovim.NeovimSession(tmp_path, {'code': 'module t; endmodule'}, width=20, height=4)
    try:
        import time
        end = time.monotonic() + 2
        while session.snapshot(-1)['version'] == 0 and time.monotonic() < end:
            time.sleep(.01)
        assert session.snapshot(-1)['rows'][0][0][0] == 'native'
        assert session.request('nvim_win_get_cursor', [0]) == [1, 0]
    finally:
        session.close()
