#!/usr/bin/env python3
"""Build the *unverified* self-contained DSP mockup from the current workbench.

No regex-based SystemVerilog parsing and no fake claim of Slang compilation.
"""
from __future__ import annotations

import json
import argparse
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'src'))
from flexsoc.backend.dv.rtl_viewer import RtlDesign  # noqa: E402


def main() -> None:
    parser = argparse.ArgumentParser(description='Build an offline, UNVERIFIED AST fixture-based interactive RTL viewer')
    parser.add_argument('--complex', action='store_true', help='Multi-stage FIR with 6 generated multiplier lanes')
    parser.add_argument('--flow-lab', action='store_true', help='Different port names, assignment chains, MUX, counter and packed/unpacked bus lanes')
    args = parser.parse_args()
    example = ROOT / ('examples/rtl_schematic_flow_lab' if args.flow_lab else 'examples/rtl_schematic_dsp_complex' if args.complex else 'examples/rtl_schematic_dsp')
    top = 'DSP_flow_lab' if args.flow_lab else 'DSP_stream' if args.complex else 'DSP'
    assets = ROOT / 'src/flexsoc/backend/dv/rtl_viewer/web'
    design = RtlDesign(json.loads((example / (top + '.mock_ast.json')).read_text()),
                       root=example, top=top)
    snapshots = {'overview': design.overview(), 'diagram': {}, 'source': {}, 'lint': {}, 'follow': {}}
    for path, scope in design.scopes.items():
        collapsed = design.diagram(path)
        expanded_all = design.diagram(path, explode=True)
        groups = [node['group'] for node in collapsed['nodes'] if node['type'] == 'generate']
        snapshots['diagram'][path] = {'0': collapsed, '1': expanded_all}
        for group in groups:
            snapshots['diagram'][path]['group:' + group] = design.diagram(path, expanded=(group,))
        snapshots['source'][path] = design.source(path)
        snapshots['lint'][path] = design.lint(path)
        for child in scope.children:
            for signal in design.diagram(path)['nodes']:
                if signal['type'] not in ('port', 'signal', 'register', 'counter', 'fsm'):
                    continue
                query = json.dumps([path, child, signal['id']], separators=(',', ':'))
                snapshots['follow'][query] = design.follow(path, child, signal['id'])
    mock_api = '''// OFFLINE DEMO only: fixtures are hand-authored, not compiled by Slang.
const __mock = ''' + json.dumps(snapshots, separators=(',', ':'), ensure_ascii=False).replace('</', '<\\/') + ''';
window.fetch = async function(input) {
 const url = new URL(input, 'http://localhost');
 const params = url.searchParams, path = params.get('path') || '/';
 const name = url.pathname.split('/').pop();
 let data = null;
 if (name === 'overview') data = __mock.overview;
 if (name === 'diagram') {
   const expanded = params.get('expand') || '';
   data = __mock.diagram[path]?.[expanded ? 'group:' + expanded : (params.get('explode') === '1' ? '1' : '0')];
 }
 if (name === 'source' || name === 'lint') data = __mock[name][path];
 if (name === 'follow') data = __mock.follow[JSON.stringify([path, params.get('child'), params.get('signal')])]
   || {status:'unresolved',reason:'No direct AST port binding in this offline fixture'};
 if (name === 'cone') data = {status:'unresolved', paths:[], reason:'Run localhost Slang viewer for cone queries'};
 return {ok: Boolean(data), status:data ? 200 : 404,
         json: async () => data || {error:'Not in offline fixture'}};
};'''
    page = (assets / 'index.html').read_text()
    page = page.replace('<title>FlexSoC · RTL Explorer</title><link rel="stylesheet" href="/style.css">',
                        '<title>FlexSoC · RTL Explorer — Offline mockup</title>\n<style>'
                        + (assets / 'style.css').read_text() + '</style>')
    page = page.replace('<script defer src="/app.js"></script>',
                        '<script>' + mock_api + '</script>\n<script>'
                         + (assets / 'router.js').read_text() + '\n' + (assets / 'app.js').read_text() + '</script>')
    output = example / 'rtl_viewer_mockup.html'
    output.write_text(page)
    print(output.relative_to(ROOT), output.stat().st_size, 'bytes')


if __name__ == '__main__':
    main()
