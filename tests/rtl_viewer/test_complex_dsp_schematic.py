"""Click-through topology contracts over a clearly *uncompiled* AST fixture.

RTL parsing never uses regex. The fixture is for the offline UI; the separate
slang integration test establishes compatibility with real elaboration.
"""
import json
from pathlib import Path

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign, SlangProject


ROOT = Path(__file__).resolve().parents[2] / 'examples/rtl_schematic_dsp_complex'


def design():
    return RtlDesign(json.loads((ROOT / 'DSP_stream.mock_ast.json').read_text()), root=ROOT, top='DSP_stream')


def test_multistage_module_wiring_and_stable_ids():
    dsp = design()
    top = dsp.diagram()
    assert {n['name'] for n in top['nodes'] if n['type'] == 'instance'} == {'u_gain', 'u_filter', 'u_round'}
    assert {e['port'] for e in top['edges'] if e['port']} >= {'sample_i', 'mix_o', 'result_o', 'data_i', 'data_o'}
    assert any(e['net'] == '/::sig:fir_raw' and e['type'] == 'port_in' for e in top['edges'])
    assert all(e['id'].startswith('/::wire:') and e['net'].startswith('/::sig:') for e in top['edges'])
    assert len({e['id'] for e in top['edges']}) == len(top['edges'])
    assert top == dsp.diagram()
    assert dsp.follow('/', '/u_filter', '/::sig:mix_i')['signal_id'] == '/u_filter::sig:sample_i'
    assert dsp.source('/u_filter')['file'] == 'DSP_fir.sv'


def test_generate_stack_explosion_and_clickable_control_wires():
    dsp = design()
    folded = dsp.diagram('/u_filter')
    stack = next(n for n in folded['nodes'] if n['type'] == 'generate')
    assert stack['count'] == 6 and stack['module'] == 'DSP_mul_lane'
    clk_wire = [e for e in folded['edges'] if e['net'] == '/u_filter::sig:clk_i' and e['port'] == 'clk_i']
    assert len(clk_wire) == 1 and clk_wire[0]['count'] == 6
    expanded = dsp.diagram('/u_filter', explode=True)
    assert len([n for n in expanded['nodes'] if n['type'] == 'instance']) == 6
    assert len([e for e in expanded['edges'] if e['port'] == 'clk_i']) == 6
    # Never fabricate a full-bus binding for a part-select port.
    assert not any(e['port'] == 'coeff_i' for e in expanded['edges'])


def test_flop_operator_and_rtl_cone():
    dsp = design()
    lane = dsp.diagram('/u_filter/g_taps/g_taps[0]/u_mult')
    byname = {n['name']: n for n in lane['nodes']}
    assert byname['Mul']['type'] == 'operator'
    assert byname['product_q']['type'] == 'register'
    assert byname['sample_i']['type'] == 'port'
    assert byname['product_d']['type'] == 'signal'
    assert any(e['source'] == byname['Mul']['id'] and e['target'] == byname['product_d']['id'] for e in lane['edges'])
    assert any(e['type'] == 'sequential' and e['target'] == byname['product_q']['id'] for e in lane['edges'])
    cone = dsp.cone(lane['path'], byname['sample_i']['id'], byname['product_o']['id'])
    assert cone['status'] == 'resolved' and cone['sequential_boundaries'][0]


def test_missing_slang_closes_instead_of_guessing(tmp_path):
    project = SlangProject(ROOT, 'DSP_stream', tuple(Path(n) for n in (
        'DSP_stream.sv', 'DSP_frontend.sv', 'DSP_fir.sv', 'DSP_mul_lane.sv', 'DSP_saturate.sv'
    )), slang='missing-slang-rust-or-something')
    with pytest.raises(RuntimeError, match='missing'):
        project.compile(tmp_path / 'ast.json')
