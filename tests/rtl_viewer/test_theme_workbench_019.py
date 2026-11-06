"""Theme 019: matching Canvas and chrome, accessible icon tabs, unchanged follow.

Smoke includes real browser events and the production static web files; graph facts
are provided by the existing compiled-style RTL fixture (not an invented AST).
"""
from __future__ import annotations

import json
import os
import re
from pathlib import Path
import shutil
import subprocess

import pytest

from test_rtl_viewer import fixture_ast, ROOT
from flexsoc.backend.dv.rtl_viewer.model import RtlDesign

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_theme_contract_has_high_contrast_canvas_palette():
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    script = r'''
const assert=require('node:assert/strict');
const themes=require(process.argv[1]);
for(const [id,preset] of Object.entries(themes.presets)){
 const ink=preset.canvas;
 assert(themes.contrast(ink.wire,ink.canvas)>=7,`${id} wire/background contrast`);
 assert(themes.contrast(ink.text,ink.canvas)>=12,`${id} text/background contrast`);
 assert.equal(themes.normTheme(id),id);
 const res=themes.apply(id,'#888888',null);
 assert(themes.contrast(res.accent,preset.surface)>=4.5,`${id} custom accent contrast`);
}
assert.equal(themes.normTheme('dark'),'graphite','legacy setting is migrated');
assert.equal(themes.normTheme('unknown'),'graphite');
assert.equal(themes.normAccent('<script>'),'teal');
'''
    p = subprocess.run(['node', '-e', script, str(WEB / 'theme-presets.js')],
                       capture_output=True, text=True, timeout=20)
    assert p.returncode == 0, p.stderr + p.stdout


def test_production_theme_assets_and_tab_labels():
    html=(WEB / 'index.html').read_text()
    from flexsoc.backend.dv.rtl_viewer import server
    routes=Path(server.__file__).read_text()
    assert html.index('/workbench-019.css') > html.index('/workbench-017.css')
    assert html.index('/theme-presets.js') < html.index('/app.js')
    assert '"/workbench-019.css": "workbench-019.css"' in routes
    assert '"/theme-presets.js": "theme-presets.js"' in routes
    for name in ('details','connections','references','mapping','source','lint','cone'):
        assert f'id="{name}Tab"' in html
    assert html.count('class="rtl-tab-icon"') == 7
    assert 'id="rtlFreezeSchematic"' in html
    assert 'id="rtlGoSchematic"' in html


def test_browser_theme_switcher_and_inspector_follow():
    pw=pytest.importorskip('playwright.sync_api')
    chromium=shutil.which('chromium') or shutil.which('chromium-browser')
    if not chromium:pytest.skip('Chromium unavailable')
    design=RtlDesign(fixture_ast(),root=ROOT,top='DSP')
    scopes={p:{'hierarchy':design.hierarchy_children(p),'diagram':design.diagram(p),
               'source':design.source(p)} for p in design.scopes}
    setup=json.dumps({'overview':design.overview(),'scopes':scopes})
    errors=[]
    with pw.sync_playwright() as client:
        browser=client.chromium.launch(headless=True, executable_path=chromium,
                                        args=['--no-sandbox'])
        try:
            context=browser.new_context(viewport={'width':1480,'height':850})
            page=context.new_page()
            page.on('pageerror',lambda err:errors.append(str(err)))
            html=(WEB / 'index.html').read_text()
            html=re.sub(r'<link rel="stylesheet"[^>]*>', '', html)
            html=re.sub(r'<script defer src="[^"]+"></script>', '', html)
            page.set_content(html)
            # about:blank has no browser storage; a tiny synchronous shim checks
            # the exact persistence logic without attempting forbidden HTTP.
            page.evaluate('''()=>{
             const data=new Map();
             Object.defineProperty(window,'localStorage',{configurable:true,
              value:{getItem:k=>data.get(k)||null,setItem:(k,v)=>data.set(k,String(v))}});
            }''')
            for css in ('style.css','workbench-017.css','workbench-019.css'):
                page.add_style_tag(path=str(WEB / css))
            page.evaluate('''(testData)=>{
             window.__testData = testData;
             window.FlexAPI = async (name,params={})=>{
              const path=params.path||'/'; const item=window.__testData.scopes[path];
              if(name==='overview')return window.__testData.overview;
              if(name==='hierarchy'){
                const h=item.hierarchy,start=Number(params.offset||0),size=Number(params.limit||64);
                return {...h,offset:start,limit:size,items:h.items.slice(start,start+size),has_more:start+size<h.total};
              }
              if(name==='diagram')return item.diagram;
              if(name==='source')return item.source;
              if(name==='lint')return {status:'unavailable',diagnostics:[]};
              return {status:'unavailable'};
             };
            }''', json.loads(setup))
            for asset in ('bootstrap-guard.js','router.js','elk.bundled.js',
                          'symbol-geometry.js','symbol-painter.js','elk-adapter.js',
                          'layout-engine.js','hierarchy-tree.js','virtual-process.js',
                          'sv-highlight.js','workbench-semantics.js','theme-presets.js',
                          'app.js','neovim-editor.js'):
                page.add_script_tag(path=str(WEB / asset))
            page.wait_for_function('state.graph !== null', timeout=15000)
            assert page.locator('#themeToggle').is_visible()
            page.locator('#themeToggle').click()
            assert page.locator('#themeMenu').is_visible()
            for theme in ('oled','midnight','ocean','graphite','light'):
                if not page.locator('#themeMenu').is_visible():
                    page.locator('#themeToggle').click()
                page.locator(f'[data-theme-choice="{theme}"]').click(timeout=4000)
                assert page.evaluate('document.documentElement.dataset.palette')==theme
                assert page.evaluate('state.graph !== null')
                assert page.evaluate('colors.canvas === FlexRTLThemes.presets[document.documentElement.dataset.palette].canvas.canvas')
            assert page.evaluate('document.documentElement.dataset.theme')=='light'
            canvas_color=page.evaluate('colors.canvas')
            assert canvas_color=='#fbfcff'
            page.locator('#themeToggle').click()
            page.locator('[data-accent-choice="violet"]').click()
            assert page.locator('[data-accent-choice="violet"]').get_attribute('aria-pressed')=='true'
            assert page.evaluate('FlexRTLThemes.contrast(colors.selected,FlexRTLThemes.presets.light.surface)>=4.5')
            page.locator('#accentCustom').fill('#777777')
            assert page.evaluate("FlexRTLThemes.readAccent()") == '#777777'
            assert page.evaluate('FlexRTLThemes.contrast(colors.selected,FlexRTLThemes.presets.light.surface)>=4.5')
            # Return to a named accent to verify persistence and tab behavior.
            page.locator('[data-accent-choice="violet"]').click()
            page.locator('#themeToggle').click()
            assert page.locator('#themeMenu').is_hidden()
            # Verify persistence independently of reloading remote assets.
            page.evaluate('''()=>{
             const chosen=FlexRTLThemes.readTheme(),accent=FlexRTLThemes.readAccent();
             applyTheme('graphite','teal');
             applyTheme(chosen,accent);
            }''')
            assert page.evaluate('document.documentElement.dataset.palette')=='light'
            assert page.evaluate('FlexRTLThemes.readAccent()')=='violet'
            page.locator('#toggleInspector').click()
            assert page.locator('#inspector').is_visible()
            assert page.locator('#inspector .rtl-tab-icon').count()==7
            assert page.locator('#sourceTab .rtl-tab-caption').is_visible()
            assert page.locator('#lintTab .rtl-tab-caption').is_hidden()
            if os.getenv('FLEXSOC_019_PREVIEW'):
                page.evaluate('''()=>{
                 const n=state.graph.nodes.find(node=>node.line>0);
                 if(n)selection(n);
                }''')
                page.wait_for_timeout(180)
                page.locator('#themeToggle').click()
                page.screenshot(path='/mnt/data/flexsoc_patch_019_light_preview.png',full_page=False)
                page.locator('#themeToggle').click()
                page.evaluate("applyTheme('graphite','violet')")
                page.locator('#themeToggle').click()
                page.screenshot(path='/mnt/data/flexsoc_patch_019_graphite_preview.png',full_page=False)
                page.locator('#themeToggle').click()
                page.evaluate("applyTheme('light','violet')")
            follow=page.locator('#rtlFreezeSchematic')
            before=follow.get_attribute('aria-pressed')
            follow.click()
            assert follow.get_attribute('aria-pressed')!=before
            page.locator('#lintTab').click()
            assert page.locator('#lintTab .rtl-tab-caption').is_visible()
            assert page.locator('#sourceTab .rtl-tab-caption').is_hidden()
            assert not errors,errors
        finally:
            browser.close()
