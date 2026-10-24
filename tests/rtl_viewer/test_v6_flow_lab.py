"""Auditable visual AST fixture (NOT compiler verified): unlike port names, bus slices."""
from pathlib import Path
import json
import shutil

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign, SlangProject

EXAMPLE=Path(__file__).resolve().parents[2]/'examples/rtl_schematic_flow_lab'


def lab():
    return RtlDesign(json.loads((EXAMPLE/'DSP_flow_lab.mock_ast.json').read_text()),root=EXAMPLE,top='DSP_flow_lab')


def test_parent_child_signal_flow_through_alias_and_mux():
    g=lab().diagram()
    routes={(e['source'],e['target']) for e in g['edges']}
    assert ('/::inst:/u_right','/::sig:from_producer') in routes
    assert ('/::sig:from_producer','/::sig:middle_wire') in routes
    assert ('/::sig:middle_wire','/::inst:/u_left') in routes
    assert ('/::inst:/u_left','/::sig:after_consumer') in routes
    assert any(n['shape']=='mux' for n in g['nodes'] if n['type']=='operator')
    assert next(n for n in g['nodes'] if n['name']=='tally_q')['type']=='counter'
    result=lab().cone('/','/::inst:/u_right','/::inst:/u_left')
    assert result['status']=='resolved'


def test_generate_packed_unpacked_slices_and_id_stability():
    d=lab()
    g=d.diagram()
    group=next(n for n in g['nodes'] if n['type']=='generate')
    assert group['count']==4
    assert next(e for e in g['edges'] if e['port']=='source_word_i')['mapping']=='partial'
    assert next(e for e in g['edges'] if e['port']=='transformed_o')['mapping']=='partial'
    assert lab().diagram()==g
    assert len([n for n in d.diagram(explode=True)['nodes'] if n['type']=='instance'])==6
    assert d.follow('/','/g_parallel/g_parallel[0]/arbitrary_instance_name','/::sig:lanes_in')['status']=='unresolved'


@pytest.mark.e2e
def test_flow_lab_compiles_with_real_slang_when_available(tmp_path):
    if not shutil.which('slang'):
        pytest.skip('Slang not available in container; run on WSL')
    project=SlangProject(EXAMPLE,'DSP_flow_lab',(Path('DSP_flow_lab.sv'),))
    ast_path=project.compile(tmp_path/'compiled.json')
    compiled=RtlDesign(json.loads(ast_path.read_text()),root=EXAMPLE,top='DSP_flow_lab',verified=True)
    assert {'/u_right','/u_left'} <= set(compiled.scopes)
    diagram=compiled.diagram()
    assert any(e['type']=='port_in' for e in diagram['edges'])
    assert any(e['type']=='port_out' for e in diagram['edges'])
