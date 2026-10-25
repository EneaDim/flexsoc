"""Unimplemented test-plan coverage remains visible without corrupting the contract."""
from pathlib import Path

from flexsoc.backend.release.qualification import QualificationFlow


def test_unplanned_requirements_remain_explicit(tmp_path: Path) -> None:
    spec = tmp_path / 'spec'
    spec.mkdir()
    (spec / 'ip.md').write_text('# Demo\n', encoding='utf-8')
    (spec / 'requirements.yaml').write_text(
        'schema: 1\nip: demo\nversion: 1.0.0\nrequirements:\n'
        '  - id: DEMO-001\n    statement: First\n    status: baselined\n'
        '  - id: DEMO-002\n    statement: Second\n    status: baselined\n', encoding='utf-8')
    (spec / 'testplan.yaml').write_text(
        'schema: 1\nip: demo\nversion: 1.0.0\nitems:\n'
        '  - id: DEMO-TP-001\n    requirements: [DEMO-001]\n'
        '    methods: [simulation]\n    tests: [smoke]\n', encoding='utf-8')
    snapshot = QualificationFlow.validate_spec_bundle(spec, ip_name='demo')
    assert snapshot['covered_requirements'] == 1
    assert snapshot['uncovered_requirements'] == ['DEMO-002']
    report = QualificationFlow.build_qualification_report(
        ip_name='demo', reg_interface='tlul', pdk='test', spec=snapshot,
        stage_states={}, contract_ready=True, requested_level=2)
    assert report['requirements']['uncovered'] == ['DEMO-002']
    assert report['requirements']['status'] == 'PARTIAL'
    assert report['levels']['2']['status'] == 'BLOCKED'
    assert 'requirements_coverage' in report['levels']['2']['blocking_evidence']


def test_explicit_coverage_deferral_is_conditional_but_not_l2_pass(tmp_path: Path) -> None:
    spec_dir = tmp_path / 'spec'
    spec_dir.mkdir()
    (spec_dir / 'ip.md').write_text('# Demo\n')
    (spec_dir / 'requirements.yaml').write_text(
        'schema: 1\nip: demo\nversion: 1.0.0\nrequirements:\n'
        '  - id: DEMO-001\n    statement: First\n    status: baselined\n'
        '  - id: DEMO-002\n    statement: Second\n    status: baselined\n'
    )
    (spec_dir / 'testplan.yaml').write_text(
        'schema: 1\nip: demo\nversion: 1.0.0\nitems:\n'
        '  - id: DEMO-TP-001\n    requirements: [DEMO-001]\n'
        '    methods: [simulation]\n    tests: [smoke]\n'
    )
    spec = QualificationFlow.validate_spec_bundle(spec_dir, ip_name='demo')
    required = QualificationFlow.required_stages(spec, 2)
    notes = {'requirements_coverage': {'stage': 'requirements_coverage',
             'fingerprint': str(spec['fingerprint']), 'owner': 'DV',
             'reason': 'DEMO-002 is scheduled for a later milestone',
             'resolve_by': 'next qualification'}}
    report = QualificationFlow.build_qualification_report(
        ip_name='demo', reg_interface='tlul', pdk='arbitrary', spec=spec,
        stage_states={key: 'CLEAN' for key in required},
        stage_outcomes={key: 'PASS' for key in required},
        contract_ready=True, requested_level='rtl', deferrals=notes,
    )
    level = report['levels']['2']
    assert level['status'] == 'BLOCKED'
    assert level['development_status'] == 'CONDITIONAL'
    assert level['deferred_evidence'] == ['requirements_coverage']
    assert report['target_satisfied'] is False
    assert report['requirements']['uncovered'] == ['DEMO-002']
    assert report['evidence']['requirements_coverage'] == 'REVIEW'
