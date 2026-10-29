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
    # This imported, *uncompiled* fixture carries display-only addresses.
    # It must preserve topology without inventing whole-signal bindings.
    dsp = design()
    top = dsp.diagram()
    assert {n['name'] for n in top['nodes'] if n['type'] == 'instance'} == {'u_gain', 'u_filter', 'u_round'}
    assert not top['edges']
    assert top == dsp.diagram()
    assert dsp.follow('/', '/u_filter', '/::sig:mix_i')['status'] == 'unresolved'
    assert dsp.source('/u_filter')['file'] == 'DSP_fir.sv'


def test_generate_stack_explosion_preserves_elaborated_paths():
    dsp = design()
    folded = dsp.diagram('/u_filter')
    stack = next(n for n in folded['nodes'] if n['type'] == 'generate')
    assert stack['count'] == 6 and stack['module'] == 'DSP_mul_lane'
    expanded = dsp.diagram('/u_filter', explode=True)
    instances = [n for n in expanded['nodes'] if n['type'] == 'instance']
    assert len(instances) == 6
    assert len({n['child'] for n in instances}) == 6
    assert not expanded['edges']  # No verified binding addresses in fixture


def test_register_and_cone_do_not_fabricate_missing_references():
    dsp = design()
    lane = dsp.diagram('/u_filter/g_taps/g_taps[0]/u_mult')
    byname = {n['name']: n for n in lane['nodes']}
    assert byname['product_q']['type'] == 'signal'  # No verified sequential write in imported fixture
    assert byname['sample_i']['type'] == 'port'
    assert byname['product_d']['type'] == 'signal'
    assert not lane['edges']
    cone = dsp.cone(lane['path'], byname['sample_i']['id'], byname['product_o']['id'])
    assert cone['status'] != 'resolved'


def test_missing_slang_closes_instead_of_guessing(tmp_path):
    project = SlangProject(ROOT, 'DSP_stream', tuple(Path(n) for n in (
        'DSP_stream.sv', 'DSP_frontend.sv', 'DSP_fir.sv', 'DSP_mul_lane.sv', 'DSP_saturate.sv'
    )), slang='missing-slang-rust-or-something')
    with pytest.raises(RuntimeError, match='missing'):
        project.compile(tmp_path / 'ast.json')
