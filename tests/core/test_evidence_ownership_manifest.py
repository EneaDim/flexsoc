"""Explicit source/evidence manifests: stage provenance, not filename heuristics."""
import json
from pathlib import Path

import pytest

from flexsoc.backend.release.qualification import QualificationFlow


def setup(root: Path, *, old=False):
    pdk = "sky130"
    items = {
        "rtl/design.sv": "original rtl",
        "dv/functional/tb/cocotb/Makefile": "original makefile",
        "dv/functional/tests/authored.py": "original test",
        "dv/formal/runs/prove/PASS": "original formal",
        f"meta/{pdk}/qualification.json": "{}",
    }
    for name, contents in items.items():
        path = root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(contents)
    if not old:
        provenance = root / "meta/provenance.json"
        provenance.write_text(json.dumps({"stages": {
            "cocotb.setup": {"generated": [{"path": "dv/functional/tb/cocotb/Makefile"}]},
            "formal.prove": {"generated": [{"path": "dv/formal/runs/prove"}]},
        }}))
    QualificationFlow.evidence_integrity(root, pdk, write=True)
    return pdk


def test_explicit_stage_provenance_refresh_and_strict_status(tmp_path):
    pdk = setup(tmp_path)
    manifest = json.loads((tmp_path / f"meta/{pdk}/evidence_integrity.json").read_text())
    assert manifest['schema'] == 2
    assert manifest['generated']['dv/functional/tb/cocotb/Makefile']['stage'] == 'cocotb.setup'
    assert 'dv/functional/tests/authored.py' in manifest['sources']
    (tmp_path / "dv/functional/tb/cocotb/Makefile").write_text("regenerated")
    (tmp_path / "dv/formal/runs/prove/PASS").write_text("regenerated")
    with pytest.raises(ValueError):
        QualificationFlow.evidence_integrity(tmp_path, pdk)
    QualificationFlow.write_qualification_report(tmp_path, pdk, {'maximum_level': 2})
    assert QualificationFlow.evidence_integrity(tmp_path, pdk)


@pytest.mark.parametrize('file', ['rtl/design.sv', 'dv/functional/tests/authored.py'])
def test_authored_inputs_block_reseal(tmp_path, file):
    pdk = setup(tmp_path)
    (tmp_path / file).write_text('modified')
    with pytest.raises(ValueError, match=file):
        QualificationFlow.write_qualification_report(tmp_path, pdk, {})


def test_legacy_without_producer_stays_strict(tmp_path):
    pdk = setup(tmp_path, old=True)
    (tmp_path / 'dv/functional/tb/cocotb/Makefile').write_text('modified')
    with pytest.raises(ValueError, match='Makefile'):
        QualificationFlow.write_qualification_report(tmp_path, pdk, {})


def test_missing_generated_file_blocks_reseal(tmp_path):
    pdk = setup(tmp_path)
    (tmp_path / 'dv/formal/runs/prove/PASS').unlink()
    with pytest.raises(ValueError, match='PASS'):
        QualificationFlow.write_qualification_report(tmp_path, pdk, {})


def test_no_ownership_promotion_during_reseal(tmp_path):
    pdk = setup(tmp_path)
    # A stage later claiming an input cannot downgrade its existing ownership.
    provenance = tmp_path / 'meta/provenance.json'
    data = json.loads(provenance.read_text())
    data['stages']['fake.setup'] = {'generated': [{'path': 'dv/functional/tests/authored.py'}]}
    provenance.write_text(json.dumps(data))
    QualificationFlow.write_qualification_report(tmp_path, pdk, {})
    manifest = json.loads((tmp_path / f'meta/{pdk}/evidence_integrity.json').read_text())
    assert 'dv/functional/tests/authored.py' in manifest['sources']


def test_legacy_manifest_with_recorded_producers_can_migrate(tmp_path):
    pdk = setup(tmp_path)
    record = tmp_path / f'meta/{pdk}/evidence_integrity.json'
    v2 = json.loads(record.read_text())
    old = {'schema': 1, 'files': {**v2['sources'],
            **{name: value['sha256'] for name, value in v2['generated'].items()}}}
    record.write_text(json.dumps(old))
    (tmp_path / 'dv/functional/tb/cocotb/Makefile').write_text('regenerated')
    QualificationFlow.write_qualification_report(tmp_path, pdk, {})
    upgraded = json.loads(record.read_text())
    assert upgraded['schema'] == 2
    assert QualificationFlow.evidence_integrity(tmp_path, pdk)


def test_new_stage_output_requires_producer(tmp_path):
    pdk = setup(tmp_path)
    new = tmp_path / 'dv/formal/runs/prove/new.log'
    new.write_text('created')
    # Parent directory was previously registered as a generated output.
    QualificationFlow.write_qualification_report(tmp_path, pdk, {})
    assert QualificationFlow.evidence_integrity(tmp_path, pdk)
    unrelated = tmp_path / 'dv/unknown/new.log'
    unrelated.parent.mkdir(parents=True)
    unrelated.write_text('unregistered')
    with pytest.raises(ValueError, match='dv/unknown/new.log'):
        QualificationFlow.write_qualification_report(tmp_path, pdk, {})


def test_generated_setup_consumed_by_runtime_remains_generated(tmp_path):
    pdk = setup(tmp_path)
    provenance = tmp_path / 'meta/provenance.json'
    data = json.loads(provenance.read_text())
    data['stages']['regression'] = {'inputs': [
        {'path': 'dv/functional/tb/cocotb/Makefile'}], 'generated': [
        {'path': 'dv/functional/regression/summary.json'}]}
    provenance.write_text(json.dumps(data))
    QualificationFlow.evidence_integrity(tmp_path, pdk, write=True)
    record = json.loads((tmp_path / f'meta/{pdk}/evidence_integrity.json').read_text())
    assert 'dv/functional/tb/cocotb/Makefile' in record['generated']


def test_legacy_runtime_stage_contract_identifies_waveform(tmp_path):
    pdk = setup(tmp_path)
    wave = tmp_path / 'dv/functional/sim/rtl/uart_tb_auto_toggle.fst'
    wave.parent.mkdir(parents=True)
    wave.write_text('original fst')
    provenance = tmp_path / 'meta/provenance.json'
    data = json.loads(provenance.read_text())
    data['stages']['regression'] = {'generated': [
        {'path': 'dv/functional/regression/summary.json'}]}
    provenance.write_text(json.dumps(data))
    QualificationFlow.evidence_integrity(tmp_path, pdk, write=True)
    record = tmp_path / f'meta/{pdk}/evidence_integrity.json'
    v2 = json.loads(record.read_text())
    record.write_text(json.dumps({'schema': 1, 'files': {**v2['sources'], **{
        key: value['sha256'] for key, value in v2['generated'].items()}}}))
    wave.write_text('rerun fst')
    QualificationFlow.write_qualification_report(tmp_path, pdk, {})
    assert QualificationFlow.evidence_integrity(tmp_path, pdk)


def test_l3_stage_artifacts_are_hashed_with_pdk_scope(tmp_path):
    pdk = setup(tmp_path)
    synthesis = tmp_path / f'syn/{pdk}/demo_synth.v'
    synthesis.parent.mkdir(parents=True)
    synthesis.write_text('synth')
    other = tmp_path / 'syn/other/demo_synth.v'
    other.parent.mkdir(parents=True)
    other.write_text('unrelated technology')
    provenance = tmp_path / f'meta/{pdk}/provenance.json'
    provenance.write_text(json.dumps({'stages': {
        'syn': {'generated': [{'path': f'syn/{pdk}/demo_synth.v'}]}
    }}))
    QualificationFlow.evidence_integrity(tmp_path, pdk, write=True)
    record = json.loads((tmp_path / f'meta/{pdk}/evidence_integrity.json').read_text())
    assert f'syn/{pdk}/demo_synth.v' in record['generated']
    assert 'syn/other/demo_synth.v' not in record['generated']
    synthesis.write_text('new synth')
    with pytest.raises(ValueError, match='demo_synth.v'):
        QualificationFlow.evidence_integrity(tmp_path, pdk)
    QualificationFlow.write_qualification_report(tmp_path, pdk, {})
    assert QualificationFlow.evidence_integrity(tmp_path, pdk)

@pytest.mark.parametrize('recorded_path', [
    '/home/builder/workspace/runs/uart/old/dv/formal/csr/cover/uart_csr_auto_cover.sv',
    'dv/formal/csr/cover/uart_csr_auto_cover.sv',
])
def test_v1_relocation_preserves_explicit_formal_producer(tmp_path, recorded_path):
    pdk = setup(tmp_path, old=True)
    target = tmp_path / 'dv/formal/csr/cover/uart_csr_auto_cover.sv'
    target.parent.mkdir(parents=True)
    target.write_text('original')
    record = tmp_path / f'meta/{pdk}/evidence_integrity.json'
    QualificationFlow.evidence_integrity(tmp_path, pdk, write=True)
    v2 = json.loads(record.read_text())
    record.write_text(json.dumps({'schema': 1, 'files': {
        **v2['sources'], **{key: value['sha256'] for key, value in v2['generated'].items()}
    }}))
    provenance = tmp_path / 'meta/provenance.json'
    provenance.write_text(json.dumps({'stages': {
        'formal.csr_cover.setup': {'generated': [
            {'path': recorded_path, 'generated_sha256': 'old'},
        ]},
    }}))
    target.write_text('regenerated')
    QualificationFlow.write_qualification_report(tmp_path, pdk, {})
    upgraded = json.loads(record.read_text())
    assert upgraded['schema'] == 2
    assert upgraded['generated']['dv/formal/csr/cover/uart_csr_auto_cover.sv']['stage'] == 'formal.csr_cover.setup'
    assert QualificationFlow.evidence_integrity(tmp_path, pdk)
    target.write_text('tampered after qualification')
    with pytest.raises(ValueError, match='uart_csr_auto_cover.sv'):
        QualificationFlow.evidence_integrity(tmp_path, pdk)
