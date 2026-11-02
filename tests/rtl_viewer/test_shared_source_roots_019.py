"""Imported Slang run sources may live in trusted shared IP directories.

Do not guess a file by its basename or allow an AST to escape authorized roots.
"""
from __future__ import annotations

import copy
from pathlib import Path

from test_rtl_viewer import fixture_ast
from flexsoc.backend.dv.rtl_viewer import RtlDesign


def run_with_shared_ip(tmp_path):
    run = tmp_path / 'workspace' / 'runs' / 'ethernet' / 'rtlviewer_axi_lite'
    run.mkdir(parents=True)
    repo = tmp_path / 'checkout'
    authored = repo / 'hw' / 'ips' / 'fifo' / 'rtl' / 'fifo_v3.sv'
    authored.parent.mkdir(parents=True)
    authored.write_text('module fifo_v3;\nlogic valid;\nendmodule\n', encoding='utf8')
    ast = copy.deepcopy(fixture_ast())
    # All scope provenance must be compiler locations, not names reconstructed
    # from a module declaration or a search by basename.
    root = ast['design']['members'][0]
    root['body']['members'][0]['sourceRange']['start'].update(file=authored.as_posix(), line=2)
    return run, repo, authored, ast


def test_shared_source_file_requires_authorized_root(tmp_path):
    run, repo, authored, ast = run_with_shared_ip(tmp_path)
    blocked = RtlDesign(ast, root=run, top='DSP')
    assert blocked.source('/')['status'] == 'unresolved'
    permitted = RtlDesign(ast, root=run, top='DSP', source_roots=(repo,))
    result = permitted.source('/')
    assert result['status'] == 'available'
    assert result['file'] == 'hw/ips/fifo/rtl/fifo_v3.sv'
    assert result['code'] == authored.read_text()
    assert 'hw/ips/fifo/rtl/fifo_v3.sv' in permitted.overview()['sourceFiles']


def test_run_local_source_remains_first_and_scope_crossprobe_works(tmp_path):
    run, repo, authored, ast = run_with_shared_ip(tmp_path)
    run_file = run / 'DSP.sv'
    run_file.write_text('module DSP; endmodule\n')
    ast['design']['members'][0]['body']['members'][0]['sourceRange']['start']['file'] = 'DSP.sv'
    design = RtlDesign(ast, root=run, top='DSP', source_roots=(repo,))
    assert design.source('/')['file'] == 'DSP.sv'
    assert design.source_symbols('/', 2)['status'] == 'resolved'
    # Reference the shared compiler source again and verify source→schematic.
    ast['design']['members'][0]['body']['members'][0]['sourceRange']['start']['file'] = authored.as_posix()
    design = RtlDesign(ast, root=run, top='DSP', source_roots=(repo,))
    assert design.source_symbols('/', 2)['status'] == 'resolved'


def test_ast_cannot_read_outside_authorized_roots_or_symlink_escape(tmp_path):
    run, repo, authored, ast = run_with_shared_ip(tmp_path)
    private = tmp_path / 'secret.sv'
    private.write_text('do not expose this')
    ast['design']['members'][0]['body']['members'][0]['sourceRange']['start']['file'] = str(private)
    design = RtlDesign(ast, root=run, top='DSP', source_roots=(repo,))
    assert design.source('/')['status'] == 'unresolved'
    evil_link = repo / 'hw' / 'ips' / 'fifo' / 'rtl' / 'escape.sv'
    evil_link.symlink_to(private)
    ast['design']['members'][0]['body']['members'][0]['sourceRange']['start']['file'] = str(evil_link)
    design = RtlDesign(ast, root=run, top='DSP', source_roots=(repo,))
    assert design.source('/')['status'] == 'unresolved'


def test_relative_paths_are_only_anchored_to_explicit_roots(tmp_path):
    run, repo, authored, ast = run_with_shared_ip(tmp_path)
    ast['design']['members'][0]['body']['members'][0]['sourceRange']['start']['file'] = 'hw/ips/fifo/rtl/fifo_v3.sv'
    assert RtlDesign(ast, root=run, top='DSP').source('/')['status'] == 'unresolved'
    result = RtlDesign(ast, root=run, top='DSP', source_roots=(repo,)).source('/')
    assert result['status'] == 'available'
