"""True RTL -> Slang elaboration -> graph acceptance gate (optional tool)."""
import json
from pathlib import Path
import shutil

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign, SlangProject

ROOT = Path(__file__).resolve().parents[2] / 'examples/rtl_schematic_dsp_complex'
FILES = ('DSP_stream.sv', 'DSP_frontend.sv', 'DSP_fir.sv', 'DSP_mul_lane.sv', 'DSP_saturate.sv')


@pytest.mark.e2e
@pytest.mark.skipif(shutil.which('slang') is None, reason='Slang executable not installed in this environment')
def test_real_slang_complex_fir_generate(tmp_path):
    project = SlangProject(ROOT, 'DSP_stream', tuple(Path(file) for file in FILES), expand_cached_instances=True)
    payload = json.loads(project.compile(tmp_path / 'elaborated.json').read_text())
    rtl = RtlDesign(payload, root=ROOT, top='DSP_stream', verified=True)
    assert rtl.overview()['source'] == 'Slang verified'
    assert len(rtl.scopes) == 10  # stream, frontend, FIR, 6 multipliers, saturate
    fir = next(s.path for s in rtl.scopes.values() if s.module == 'DSP_fir')
    assert len(rtl.scopes[fir].children) == 6
    assert rtl.diagram(fir)['nodes']
    assert any(node['type'] == 'generate' and node['count'] == 6 for node in rtl.diagram(fir)['nodes'])
