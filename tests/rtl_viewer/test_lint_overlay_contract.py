"""Regression tests for read-only lint evidence shown by rtl-view."""
import json
from pathlib import Path

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from test_rtl_viewer import fixture_ast


def test_lint_resolves_project_and_run_relative_paths_without_truncation(tmp_path):
    root = tmp_path
    (root / 'DSP.sv').write_text('module DSP; endmodule', encoding='utf-8')
    run = root / 'workspace' / 'runs' / 'demo'
    output = run / 'dv' / 'lint' / 'slang'
    output.mkdir(parents=True)
    # Include root-relative, run-relative, absolute and unrelated evidence.
    diagnostic = {'file': 'DSP.sv', 'line': 1, 'priority': 'P0', 'code': 'width-trunc'}
    items = [dict(diagnostic, line=index) for index in range(205)]
    items.append(dict(diagnostic, file=str(root / 'DSP.sv'), line=206))
    items.append(dict(diagnostic, file='not-this-module.sv', line=207))
    (output / 'summary.json').write_text(json.dumps({'diagnostics': items}), encoding='utf-8')
    viewer = RtlDesign(fixture_ast(), root=root, top='DSP', run=run)
    result = viewer.lint('/')
    assert result['status'] == 'available'
    assert result['total'] == len(result['diagnostics']) == 206
    assert result['scope'].startswith('file-level')
    assert result['diagnostics'][-1]['line'] == 206


def test_lint_run_relative_generated_source(tmp_path):
    root = tmp_path
    run = root / 'workspace' / 'runs' / 'demo'
    rtl = run / 'rtl'
    rtl.mkdir(parents=True)
    (rtl / 'DSP.sv').write_text('module DSP; endmodule', encoding='utf-8')
    output = run / 'dv' / 'lint' / 'slang'
    output.mkdir(parents=True)
    (output / 'summary.json').write_text(json.dumps({'diagnostics': [
        {'file': 'rtl/DSP.sv', 'line': 4, 'priority': 'P0', 'code': 'width-expand'}
    ]}), encoding='utf-8')
    ast = fixture_ast()
    # The scope source is derived from the elaborated body and ports.
    def update_sources(node):
        if isinstance(node, dict):
            if node.get('sourceRange', {}).get('start', {}).get('file') == 'DSP.sv':
                node['sourceRange']['start']['file'] = (rtl / 'DSP.sv').relative_to(root).as_posix()
            for value in node.values():
                update_sources(value)
        elif isinstance(node, list):
            for value in node:
                update_sources(value)
    update_sources(ast)
    # RtlDesign may intentionally reject AST paths outside root, so run resides within root.
    viewer = RtlDesign(ast, root=root, top='DSP', run=run)
    result = viewer.lint('/')
    assert result['total'] == 1
    assert result['diagnostics'][0]['code'] == 'width-expand'
