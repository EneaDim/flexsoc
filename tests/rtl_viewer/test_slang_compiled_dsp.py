"""Real frontend integration: only runs where MikePopoloski's slang is installed."""
from pathlib import Path
import json
import shutil

import pytest

from flexsoc.backend.dv.rtl_viewer import SlangProject, RtlDesign


ROOT = Path(__file__).resolve().parents[2] / 'examples/rtl_schematic_dsp'


@pytest.mark.e2e
@pytest.mark.skipif(shutil.which('slang') is None, reason='install upstream SystemVerilog slang')
def test_elaborate_parallel_dsp_with_real_slang(tmp_path):
    project = SlangProject(ROOT, 'DSP',
                           (Path('DSP.sv'), Path('DSP_core.sv'), Path('DSP_lane.sv')),
                           expand_cached_instances=True)
    ast = json.loads(project.compile(tmp_path / 'dsp.elaborated.json').read_text())
    design = RtlDesign(ast, root=ROOT, top='DSP', verified=True)
    assert design.overview()['source'] == 'Slang verified'
    assert len(design.scopes) == 10, 'one DSP, one core, eight generated MAC lanes'
    core_scopes = [s for s in design.scopes.values() if s.module == 'DSP_core']
    assert len(core_scopes) == 1
    core = design.diagram(core_scopes[0].path)
    assert any(n['type'] == 'generate' and n['count'] == 8 for n in core['nodes'])
