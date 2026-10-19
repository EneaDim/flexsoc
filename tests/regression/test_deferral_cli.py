import json
from pathlib import Path
import pytest
from flexsoc.backend.release.deferrals import manage_deferrals


def test_add_list_remove_preserves_gate(tmp_path, capsys):
    meta = tmp_path / 'meta' / 'sky130'
    meta.mkdir(parents=True)
    report = {'contract_fingerprint':'123', 'evidence': {'cdc_rdc':'FAILED','lint':'PASS'}}
    (meta/'qualification.json').write_text(json.dumps(report))
    assert manage_deferrals(meta, ['add','cdc_rdc','Clock switch needs signoff'], {'OWNER':'ip-team','RESOLVE_BY':'before L2 release'}) == 0
    data = json.loads((meta/'qualification_deferrals.json').read_text())
    assert data['deferrals'][0]['fingerprint']=='123'
    assert json.loads((meta/'qualification.json').read_text())['evidence']['cdc_rdc']=='FAILED'
    manage_deferrals(meta,['list'],{})
    assert 'Clock switch' in capsys.readouterr().out
    with pytest.raises(ValueError,match='already has'):
        manage_deferrals(meta,['add','cdc_rdc','dup'], {'OWNER':'x','RESOLVE_BY':'y'})
    with pytest.raises(ValueError,match='already PASS'):
        manage_deferrals(meta,['add','lint','bad'], {'OWNER':'x','RESOLVE_BY':'y'})
    manage_deferrals(meta,['remove','cdc_rdc'],{})
    assert json.loads((meta/'qualification_deferrals.json').read_text())['deferrals']==[]


def test_requires_existing_qualification(tmp_path):
    with pytest.raises(ValueError,match='qualify'):
        manage_deferrals(tmp_path,['add','cdc_rdc','reason'], {'OWNER':'x','RESOLVE_BY':'y'})


def test_refuses_symlink(tmp_path):
    meta = tmp_path/'meta'
    meta.mkdir()
    (meta/'qualification.json').write_text(json.dumps({'contract_fingerprint':'abc','evidence':{'cdc_rdc':'FAILED'}}))
    outside = tmp_path/'outside.json'
    outside.write_text('{"schema":1,"deferrals":[]}')
    (meta/'qualification_deferrals.json').symlink_to(outside)
    with pytest.raises(ValueError,match='symlink'):
        manage_deferrals(meta,['add','cdc_rdc','reason'], {'OWNER':'x','RESOLVE_BY':'y'})


def test_defer_cli_uses_explicit_workspace(tmp_path, monkeypatch, capsys):
    from flexsoc.cli import app
    from flexsoc.backend.core.flow.session import WorkspaceFlow, DEFAULT_SETTINGS

    repo = tmp_path / 'repo'
    repo.mkdir()
    ws = tmp_path / 'external_workspace'
    values = {**DEFAULT_SETTINGS, 'TOP': 'unit', 'RUN_TOP': 'unit', 'RUN_ID': 'run1', 'PDK': 'sky130'}
    WorkspaceFlow.write_settings(repo, values, ws)
    meta = ws / 'runs' / 'unit' / 'run1' / 'meta' / 'sky130'
    meta.mkdir(parents=True)
    (meta / 'qualification.json').write_text(json.dumps({
        'contract_fingerprint': 'fp123', 'evidence': {'cdc_rdc': 'FAILED'}
    }))
    assert app(['defer', 'add', 'cdc_rdc', 'Clock mux review',
                '--set', 'OWNER=team', '--set', 'RESOLVE_BY=pre-release',
                '--project-root', str(repo), '--workdir', str(ws)]) == 0
    assert json.loads((meta / 'qualification_deferrals.json').read_text())['deferrals'][0]['stage'] == 'cdc_rdc'
    assert app(['defer', 'list', '--project-root', str(repo), '--workdir', str(ws)]) == 0
    assert 'Clock mux review' in capsys.readouterr().out
