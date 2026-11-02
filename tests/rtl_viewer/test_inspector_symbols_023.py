"""FSRTL-023: AST values are never guessed; inspector boots with actual assets."""
import json
import shutil
import subprocess
from pathlib import Path

import pytest

from flexsoc.backend.dv.rtl_viewer.connectivity import PortResolver

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_actual_constant_metadata_only_when_ast_exposes_literal():
    ports = {'enable': {'direction': 'input'}, 'other': {'direction': 'input'}}
    inst = {'connections': [
        {'port': 'enable', 'expression': {'kind': 'Conversion', 'operand': {
            'kind': 'IntegerLiteral', 'value': "1'b1"}}},
        {'port': 'other', 'expression': {'kind': 'BinaryOp', 'left': {
            'kind': 'NamedValue', 'symbol': 'missing'}, 'right': {'kind': 'IntegerLiteral', 'value': '1'}}},
    ], 'body': {'members': []}}
    resolver = PortResolver([], set())
    assert resolver.literal_values(inst, ports) == {'enable': "1'b1"}
    assert resolver.resolve(inst, ports)[1]['enable'] == 'constant'


def test_slang_literal_is_projected_to_instance_port_without_fake_edge(tmp_path):
    from flexsoc.backend.dv.rtl_viewer import RtlDesign
    ast={'design':{'members':[{'kind':'Instance','name':'top','body':{
        'kind':'InstanceBody','name':'top','members':[
            {'kind':'Instance','name':'u','connections':[
                {'port':'enable','expression':{'kind':'IntegerLiteral','value':"1'b1"}}],
             'body':{'kind':'InstanceBody','name':'child','members':[
                {'kind':'Port','name':'enable','direction':'In','type':'logic'}]}}
        ]}}]}}
    graph=RtlDesign(ast,root=tmp_path,top='top').diagram()
    node=next(n for n in graph['nodes'] if n['type']=='instance')
    port=next(p for p in node['ports'] if p['name']=='enable')
    assert port['connection']=='constant'
    assert port['constantValue']=="1'b1"
    assert not [e for e in graph['edges'] if e['target']==node['id']]


def test_concatenation_is_named_not_mysterious_braces_and_constants_are_external():
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    script = r'''
const assert=require('node:assert/strict'),W=process.argv[1];
const G=require(W+'/symbol-geometry.js'),P=require(W+'/symbol-painter.js');
assert.equal(G.operatorFace({name:'Concatenation'}).mark,'CONCAT');
const ctx={save(){},restore(){}};const cmds=[];
for(const method of ['beginPath','moveTo','lineTo','fill','stroke','arc','closePath','roundRect','fillText','quadraticCurveTo'])ctx[method]=(...args)=>cmds.push([method,...args]);
const colors={instance:'#aaf',operator:'#ffa',symbolFill:'#234',pickedFill:'#345',selected:'#ffc',muted:'#9bc',binding:'#cdf',text:'#fff',generate:'#fa5',stackFill:'#123',stackStroke:'#345'};
const op={type:'operator',name:'Concatenation',kind:'Concatenation',pins:['IN','Y']},s=G.boxSize(op);
P.paint(ctx,op,{x:0,y:0,...s},{colors,names:true,zoom:1,edges:[]});
assert(cmds.some(c=>c[0]==='fillText'&&c[1]==='CONCAT'));
assert.equal(G.anchor(op,'target',{targetPin:'IN'},s).y,s.h/2);
cmds.length=0;
const inst={type:'instance',name:'u',module:'m',ports:[{name:'clk_enable',direction:'in',connection:'constant',constantValue:"1'b1"}]};
P.paint(ctx,inst,{x:10,y:20,...G.boxSize(inst)},{colors,names:true,zoom:1,edges:[]});
const annotation=cmds.find(c=>c[0]==='fillText'&&c[1]==="1'b1");
assert(annotation,'literal must be rendered');
assert(annotation[2]<10,'literal is outside the left border');
assert(!cmds.some(c=>c[0]==='fillText'&&c[1]==='const'));
'''
    r = subprocess.run(['node', '-e', script, str(WEB)], capture_output=True,
                       text=True, timeout=30)
    assert r.returncode == 0, r.stdout + r.stderr


@pytest.mark.e2e
def test_real_web_assets_inspector_tabs_source_and_bootstrap():
    binary = shutil.which('chromium') or shutil.which('google-chrome')
    if not binary:
        pytest.skip('Chromium unavailable')
    pw = pytest.importorskip('playwright.sync_api')
    graph = {'schema':'flexsoc.rtl_viewer.module.v2','revision':'rev-023','path':'/',
             'module':'top', 'ancestors':[{'path':'/','name':'top','module':'top'}],
             'nodes':[{'id':'/::sig:a','name':'a','type':'port','direction':'in','line':1},
                      {'id':'/::sig:y','name':'y','type':'port','direction':'out','line':2}],
             'edges':[{'id':'e1','source':'/::sig:a','target':'/::sig:y','net':'/::sig:a','type':'data','mapping':'direct','rendered':True}],
             'connectivity':{},'expanded':[], 'truncated':False}
    with pw.sync_playwright() as driver:
        browser = driver.chromium.launch(headless=True, executable_path=binary, args=['--no-sandbox'])
        try:
            page = browser.new_page(viewport={'width':1450,'height':880})
            errors=[];page.on('pageerror',lambda error:errors.append(str(error)))
            # Offline Chrome smoke: real deployed script bytes + deterministic
            # API stub. No loopback navigation (blocked in some CI sandboxes).
            html = (WEB/'index.html').read_text()
            html = html.replace('<link rel="stylesheet" href="/style.css">',
                                '<style>'+ (WEB/'style.css').read_text() +'</style>')
            fixture = {'overview':{'top':'top','instances':1,'modules':1,'source':'imported AST (unverified)'},
                       'diagram':graph,'hierarchy':{'items':[],'offset':0,'limit':64,'total':0,'has_more':False,'path':'/'},
                       'source':{'status':'available','file':'top.sv','line':1,'code':'logic a;\nlogic y;'},
                       'occurrences':{'status':'available','sites':[{'file':'top.sv','line':1,'role':'declaration'}],'complete':False,'note':'partial'},
                       'inspect':{'status':'available','id':'/::sig:a','scope':'/','kind':'port','revision':'rev-023','entity':{'name':'a'},'elaboration_verified':False},
                       'evidence':{'status':'unavailable'},'lint':{'status':'unavailable'}}
            stub='<script>window.FlexAPI=(name)=>Promise.resolve('+json.dumps(fixture)+"[name]||{status:'unresolved'});</script>"
            html=html.replace('<script defer src="/bootstrap-guard.js"></script>',
                              stub+'<script>'+ (WEB/'bootstrap-guard.js').read_text()+'</script>')
            for name in ['router.js','elk.bundled.js','symbol-geometry.js','symbol-painter.js','elk-adapter.js','layout-engine.js','hierarchy-tree.js','app.js','neovim-editor.js']:
                html=html.replace('<script defer src="/'+name+'"></script>',
                                  '<script>'+ (WEB/name).read_text()+'</script>')
            page.set_content(html,wait_until='domcontentloaded')
            page.wait_for_function("document.getElementById('counts').textContent.includes('symbols')",timeout=25000)
            page.locator('#toggleSource').click()
            assert page.locator('#rtlSourceStatus').inner_text().startswith('READ ONLY · Mapped source')
            page.locator('#connectionsTab').click()
            assert page.locator('#connectionsPane').is_visible()
            page.locator('#referencesTab').click()
            assert page.locator('#referencesPane').is_visible()
            page.locator('#sourceTab').click()
            assert page.locator('#sourceFile').inner_text()=='top.sv'
            assert not errors,errors
        finally:
            browser.close()
