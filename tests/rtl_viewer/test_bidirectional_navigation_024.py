"""FSRTL-024: cross-probing uses AST identities, never source text guesses."""
import json
import shutil
from pathlib import Path
from threading import Thread
from urllib.parse import quote
from urllib.request import urlopen

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from flexsoc.backend.dv.rtl_viewer.server import ViewerServer

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def _ast():
    def loc(line): return {'start': {'file': 'top.sv', 'line': line}}
    def decl(name, line):
        return {'kind': 'Variable', 'name': name, 'type': 'logic', 'sourceRange': loc(line)}
    def ref(name, line):
        return {'kind': 'NamedValue', 'symbol': name, 'sourceRange': loc(line)}
    members = [decl('a', 1), decl('b', 2), decl('z', 3),
               {'kind': 'ContinuousAssign', 'assignment': {'kind': 'Assignment',
                'left': ref('z', 6), 'right': {'kind': 'BinaryOp',
                'left': ref('a', 6), 'right': ref('b', 6)}}},
               {'kind': 'ContinuousAssign', 'assignment': {'kind': 'Assignment',
                'left': ref('z', 8), 'right': ref('a', 8)}}]
    return {'design': {'members': [{'kind': 'Instance', 'name': 'top',
            'body': {'kind': 'InstanceBody', 'name': 'top', 'members': members}}]}}


def test_ast_reads_writes_ambiguity_and_no_text_matching(tmp_path):
    (tmp_path/'top.sv').write_text('logic a;\nlogic b;\nlogic z;\n\n\nassign z=a+b;\n\nassign z=a;\n// b here is not AST evidence\n')
    model = RtlDesign(_ast(), root=tmp_path, top='top')
    assert model.source_symbols('/', 1)['candidates'][0]['roles'] == ['declaration']
    at6 = model.source_symbols('/', 6)
    assert at6['status'] == 'ambiguous'
    assert {c['name'] for c in at6['candidates']} == {'a', 'b', 'z'}
    assert {tuple(c['roles']) for c in at6['candidates']} == {('read',), ('write',)}
    at8 = model.source_symbols('/', 8)
    assert at8['status'] == 'ambiguous'
    assert model.source_symbols('/', 9)['status'] == 'unresolved'
    assert model.source_symbols('/', 9)['candidates'] == []
    with pytest.raises(ValueError): model.source_symbols('/', -1)


def test_coverage_distinguishes_missing_source_from_not_in_graph(tmp_path, monkeypatch):
    (tmp_path/'top.sv').write_text('module top; endmodule')
    ast = _ast()
    # No compiler provenance for b: do not fabricate one from source text.
    ast['design']['members'][0]['body']['members'][1].pop('sourceRange')
    model = RtlDesign(ast, root=tmp_path, top='top')
    full = model.source_coverage('/')
    statuses = {r['name']:r['status'] for r in full['signals']}
    assert statuses == {'a':'visible_mapped','b':'visible_unmapped','z':'visible_mapped'}
    base_diagram = model.diagram('/')
    monkeypatch.setattr(model, 'diagram', lambda *a, **kw: {**base_diagram, 'nodes': [n for n in base_diagram['nodes'] if n['name'] != 'a'], 'truncated': True})
    limited = model.source_coverage('/')
    assert limited['graph_truncated']
    assert limited['counts']['not_in_graph'] == 1
    assert any(r['name']=='a' and r['status']=='not_in_graph' for r in limited['signals'])
    source_match = model.source_symbols('/', 1)
    assert source_match['status'] == 'outside_view'
    assert source_match['candidates'][0]['visible'] is False


def test_new_coverage_endpoint(tmp_path):
    (tmp_path/'top.sv').write_text('module top; endmodule')
    server = ViewerServer(('127.0.0.1', 0), RtlDesign(_ast(), root=tmp_path, top='top'))
    thread = Thread(target=server.serve_forever, daemon=True);thread.start()
    try:
        with urlopen('http://127.0.0.1:'+str(server.server_port)+'/api/source_coverage?path=%2F') as reply:
            data = json.load(reply)
        assert data['total'] == 3
        assert data['counts']['visible_mapped'] == 3
    finally:
        server.shutdown();server.server_close();thread.join(timeout=3)


@pytest.mark.e2e
def test_inspector_round_trip_ambiguity_mapping_and_lint():
    chromium = shutil.which('chromium') or shutil.which('google-chrome')
    if not chromium:pytest.skip('Chromium unavailable')
    pw = pytest.importorskip('playwright.sync_api')
    graph={'schema':'flexsoc.rtl_viewer.module.v2','revision':'rev-024','path':'/','module':'top',
           'ancestors':[{'path':'/','name':'top','module':'top'}],
           'nodes':[{'id':'/::sig:a','name':'a','type':'port','direction':'in','line':1},
                    {'id':'/::sig:b','name':'b','type':'port','direction':'in','line':2},
                    {'id':'/::sig:z','name':'z','type':'port','direction':'out','line':3}],
           'edges':[],'connectivity':{},'expanded':[],'truncated':False}
    fixture={'overview':{'top':'top','instances':1,'modules':1,'source':'imported AST (unverified)'},
      'diagram':graph,'hierarchy':{'items':[],'offset':0,'limit':64,'total':0,'has_more':False,'path':'/'},
      'source':{'status':'available','file':'top.sv','line':1,'code':'logic a;\nlogic b;\nlogic z;\nassign z = a & b;'},
      'source_symbols':None,
      'source_coverage':{'status':'available','total':4,'counts':{'visible_mapped':3,'visible_unmapped':0,'not_in_graph':1},
           'signals':[{'id':'/::sig:a','name':'a','status':'visible_mapped','line':1,'file':'top.sv','in_scope_source':True},
                      {'id':'/::sig:missing','name':'missing','status':'not_in_graph','line':5,'file':'top.sv','in_scope_source':True}],
           'note':'AST declarations only','graph_truncated':True},
      'occurrences':{'status':'available','sites':[],'complete':False,'note':'partial'},
      'evidence':{'status':'available','total':1,'source_files':1},
      'lint':{'status':'available','file':'top.sv','diagnostics':[{'file':'top.sv','line':4,'severity':'warning','message':'test warning'}]}}
    script='''<script>
const data=%s;
window.FlexAPI=(name,params={})=>{
 if(name==='source_symbols'){
  const n=Number(params.line),cs=n===1?[{id:'/::sig:a',name:'a',line:n,roles:['declaration'],visible:true}]:
   n===4?[{id:'/::sig:a',name:'a',line:n,roles:['read'],visible:true},{id:'/::sig:b',name:'b',line:n,roles:['read'],visible:true}]:[];
  return Promise.resolve({status:cs.length>1?'ambiguous':cs.length?'resolved':'unresolved',candidates:cs,line:n,scope:'/'});
 }
 return Promise.resolve(data[name]||{status:'unresolved'});
};</script>''' % json.dumps(fixture)
    html=(WEB/'index.html').read_text().replace('<link rel="stylesheet" href="/style.css">','<style>'+(WEB/'style.css').read_text()+'</style>')
    html=html.replace('<script defer src="/bootstrap-guard.js"></script>',script+'<script>'+(WEB/'bootstrap-guard.js').read_text()+'</script>')
    for name in ['router.js','elk.bundled.js','symbol-geometry.js','symbol-painter.js','elk-adapter.js','layout-engine.js','hierarchy-tree.js','app.js','neovim-editor.js']:
        html=html.replace('<script defer src="/'+name+'"></script>','<script>'+(WEB/name).read_text()+'</script>')
    with pw.sync_playwright() as runner:
        browser=runner.chromium.launch(headless=True,executable_path=chromium,args=['--no-sandbox'])
        try:
            page=browser.new_page(viewport={'width':1500,'height':880});errors=[]
            page.on('pageerror',lambda error: errors.append(str(error)))
            page.set_content(html, wait_until='domcontentloaded')
            page.wait_for_function("document.getElementById('counts').textContent.includes('symbols')", timeout=25000)
            page.locator('#rtlGoSource').click() if page.locator('#rtlGoSource').is_visible() else page.locator('#toggleSource').click()
            page.locator('#sourceCode .code-line[data-line="1"]').click()
            page.wait_for_function("document.getElementById('rtlProbeStatus').textContent.includes('Revealed a')")
            page.locator('#sourceCode .code-line[data-line="4"]').click()
            page.wait_for_function("document.querySelectorAll('#sourceProbeChoices button').length===2")
            assert 'ambiguous' in page.locator('#sourceProbeChoices').inner_text()
            page.locator('#sourceProbeChoices button').nth(1).click()
            assert 'Revealed b' in page.locator('#rtlProbeStatus').inner_text()
            page.locator('#mappingTab').click()
            assert 'outside current graph 1' in page.locator('#mappingResults').inner_text()
            page.locator('#rtlMappingFilter').select_option('not_in_graph')
            assert 'missing' in page.locator('#mappingResults').inner_text()
            page.locator('#rtlGoLint').click()
            page.locator('#lintPane button',has_text='Find in schematic').click()
            page.wait_for_function("document.querySelector('#sourceCode') && !document.querySelector('#sourcePane').hidden")
            assert not errors,errors
        finally:browser.close()
