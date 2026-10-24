import copy
from pathlib import Path
import json
import stat

import pytest

from test_rtl_viewer import fixture_ast, ROOT
from flexsoc.backend.dv.rtl_viewer import SlangProject, RtlDesign


def test_revision_ignores_slang_process_addresses():
    payload = fixture_ast()
    shifted = copy.deepcopy(payload)
    refs = shifted['design']['members'][0]['body']['members'][3]['body']['members']
    # Also test root-level Slang pointer fields.
    shifted['design']['addr'] = 999
    assert RtlDesign(shifted, root=ROOT, top='DSP').revision == RtlDesign(payload, root=ROOT, top='DSP').revision
    old = payload['design']['members'][0]['body']['members'][3]['connections'][0]['expression']
    new = shifted['design']['members'][0]['body']['members'][3]['connections'][0]['expression']
    new['symbol'] = '985100 samples_i'
    assert RtlDesign(shifted, root=ROOT, top='DSP').revision == RtlDesign(payload, root=ROOT, top='DSP').revision


def test_compiler_invokes_slang_ast_flags_and_top(tmp_path):
    fake = tmp_path / 'slang'
    # Fake executable tests argv contract; it is not a real language compilation.
    fake.write_text('''#!/usr/bin/env python3
import json,sys
from pathlib import Path
args=sys.argv[1:]
Path(sys.argv[sys.argv.index('--ast-json')+1]).write_text(json.dumps({'design':{'members':[]}}))
Path(sys.argv[sys.argv.index('--ast-json')+1]).with_suffix('.argv').write_text(json.dumps(args))
''')
    fake.chmod(fake.stat().st_mode | stat.S_IXUSR)
    result = tmp_path/'out.json'
    project = SlangProject(ROOT, 'DSP', (Path('DSP.sv'), Path('DSP_core.sv'), Path('DSP_lane.sv')),
                           includes=(Path('.'),), defines=('DSP_ON=1',), slang=str(fake))
    project.compile(result)
    argv = json.loads(result.with_suffix('.argv').read_text())
    assert argv[:2] == ['--top','DSP']
    assert '--ast-json-source-info' in argv
    assert '-DDSP_ON=1' in argv
    assert len([x for x in argv if x.endswith('.sv')]) == 3
    assert not any('shell' in x for x in argv)


def test_limits_and_unknown_paths():
    viewer = RtlDesign(fixture_ast(), root=ROOT, top='DSP')
    with pytest.raises(ValueError, match='limit'):
        viewer.diagram(limit=1501)
    assert viewer.diagram('/pipeline_abc',explode=True,limit=2)['truncated']
    with pytest.raises(ValueError, match='hierarchy'):
        viewer.follow('/', '/missing', '/::sig:samples_i')


def test_source_stays_within_project_root(tmp_path):
    payload = fixture_ast()
    payload['design']['members'][0]['sourceRange']['start']['file'] = '/etc/passwd'
    for port in payload['design']['members'][0]['body']['members']:
        if port.get('kind') == 'Port':
            port['sourceRange']['start']['file'] = '/etc/passwd'
    viewer = RtlDesign(payload,root=ROOT,top='DSP')
    assert viewer.source('/')['status'] == 'unresolved'


def test_no_guessed_ports_without_ast_bindings():
    payload = fixture_ast()
    core = payload['design']['members'][0]['body']['members'][3]
    core['connections'] = []
    viewer = RtlDesign(payload, root=ROOT, top='DSP')
    assert viewer.follow('/','/pipeline_abc','/::sig:samples_i')['status'] == 'unresolved'


def test_ast_source_and_lint_are_read_only(tmp_path):
    root=tmp_path
    path=root/'DSP.sv'
    path.write_text('module DSP; endmodule')
    payload=fixture_ast()
    viewer=RtlDesign(payload,root=root,top='DSP')
    assert viewer.source('/')['code']=='module DSP; endmodule'
    assert viewer.lint('/')['diagnostics']==[]
