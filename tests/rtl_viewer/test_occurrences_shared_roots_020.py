"""Occurrence positions must use the same provenance roots as the source panel.

These tests use explicit AST ranges, not source-text searching.  Actual Ethernet
Slang output is inspected separately because the run lives in the user's WSL.
"""
from pathlib import Path

from flexsoc.backend.dv.rtl_viewer import RtlDesign


def _at(kind, file, line, **data):
    return {"kind": kind, "sourceRange": {"start": {"file": str(file), "line": line}}, **data}


def _design(tmp_path, location="relative", with_ref_ranges=True):
    run = tmp_path / 'workspace' / 'runs' / 'ethernet' / 'rtlviewer_axi_lite'
    run.mkdir(parents=True)
    checkout = tmp_path / 'checkout'
    source = checkout / 'vendor' / 'pulp' / 'register_interface' / 'src' / 'axi_lite_to_reg.sv'
    source.parent.mkdir(parents=True)
    source.write_text(('\n' * 71) + 'logic write_resp_fifo_pop;\n', encoding='utf8')
    file = source if location == 'absolute' else source.relative_to(checkout)

    def ref(name, line):
        if with_ref_ranges:
            return _at('NamedValue', file, line, symbol=name)
        return {'kind': 'NamedValue', 'symbol': name}

    members = [
        _at('Variable', file, 72, name='write_resp_fifo_pop', type='logic'),
        _at('Variable', file, 73, name='ready', type='logic'),
        {'kind': 'ExpressionStatement', 'expr': {
            'kind': 'Assignment', 'left': ref('write_resp_fifo_pop', 84),
            'right': ref('ready', 84)}},
        {'kind': 'ExpressionStatement', 'expr': {
            'kind': 'Assignment', 'left': ref('ready', 91),
            'right': ref('write_resp_fifo_pop', 91)}},
    ]
    ast = {'design': {'kind': 'Root', 'members': [
        {'kind': 'Instance', 'name': 'ethernet',
         'body': {'kind': 'InstanceBody', 'name': 'ethernet', 'members': members}}
    ]}}
    return RtlDesign(ast, root=run, top='ethernet', source_roots=(checkout,)), source


def test_occurrences_resolve_checkout_relative_slang_paths(tmp_path):
    viewer, source = _design(tmp_path)
    assert viewer.source('/')['status'] == 'available'
    outcome = viewer.occurrences('/', 'write_resp_fifo_pop')
    assert outcome['status'] == 'available'
    assert [(site['role'], site['line']) for site in outcome['sites']] == [
        ('declaration', 72), ('write', 84), ('read', 91)]
    assert {site['file'] for site in outcome['sites']} == {
        'vendor/pulp/register_interface/src/axi_lite_to_reg.sv'}
    assert all(site['evidence'] == 'slang-ast' for site in outcome['sites'])


def test_occurrences_resolve_absolute_authorized_paths(tmp_path):
    viewer, source = _design(tmp_path, 'absolute')
    outcome = viewer.occurrences('/', 'write_resp_fifo_pop')
    assert len(outcome['sites']) == 3
    assert outcome['sites'][0]['file'] == 'vendor/pulp/register_interface/src/axi_lite_to_reg.sv'


def test_missing_ast_reference_ranges_never_invent_read_write_locations(tmp_path):
    viewer, source = _design(tmp_path, with_ref_ranges=False)
    outcome = viewer.occurrences('/', 'write_resp_fifo_pop')
    assert outcome['status'] == 'available'
    assert [(site['role'], site['line']) for site in outcome['sites']] == [('declaration', 72)]
    assert not outcome['complete']
