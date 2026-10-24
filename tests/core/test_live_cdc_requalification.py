"""Loaded releases can be requalified after rerunning CDC without trusting changed RTL."""

import json

import pytest

from flexsoc.backend.release.qualification import QualificationFlow


def seal_with_test_provenance(root, pdk):
    """Fixtures declare generators; production derives them from Lifecycle."""
    created = {path.relative_to(root).as_posix() for path in root.rglob('*') if path.is_file()}
    authored = ('rtl/', 'csr/', 'constraints/', 'dv/formal/properties/',
                'dv/functional/py/', 'dv/functional/model/',
                'dv/functional/tests/', 'dv/functional/tb/', 'dv/unknown/')
    generated = sorted(name for name in created if name.startswith('dv/')
                       and not name.startswith(authored))
    provenance = root / 'meta/provenance.json'
    provenance.parent.mkdir(parents=True, exist_ok=True)
    provenance.write_text(json.dumps({'stages': {'fixture.setup': {
        'generated': [{'path': name} for name in generated]
    }}}))
    QualificationFlow.evidence_integrity(root, pdk, write=True)


@pytest.mark.parametrize("name", ("extract.ys", "design.json", "summary.json", "cdc_rdc.rpt"))
def test_cdc_outputs_can_be_regenerated_before_requalification(tmp_path, name):
    pdk = "ihp-sg13g2"
    originals = {
        "rtl/demo.sv": "module demo; endmodule\n",
        **{f"dv/cdc_rdc/{item}": f"old {item}\n" for item in
           ("extract.ys", "design.json", "summary.json", "cdc_rdc.rpt")},
        f"meta/{pdk}/qualification.json": '{"maximum_level":2}\n',
    }
    for relative, contents in originals.items():
        file = tmp_path / relative
        file.parent.mkdir(parents=True, exist_ok=True)
        file.write_text(contents)
    seal_with_test_provenance(tmp_path, pdk)
    (tmp_path / "dv/cdc_rdc" / name).write_text("regenerated\n")
    with pytest.raises(ValueError, match=name):
        QualificationFlow.evidence_integrity(tmp_path, pdk)
    QualificationFlow.write_qualification_report(tmp_path, pdk, {"maximum_level": 2})
    assert QualificationFlow.evidence_integrity(tmp_path, pdk)


def test_missing_cdc_artifact_is_not_accepted(tmp_path):
    pdk = "ihp-sg13g2"
    for relative in ("rtl/demo.sv", "dv/cdc_rdc/design.json", f"meta/{pdk}/qualification.json"):
        path = tmp_path / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("original\n")
    seal_with_test_provenance(tmp_path, pdk)
    (tmp_path / "dv/cdc_rdc/design.json").unlink()
    with pytest.raises(ValueError, match="design.json"):
        QualificationFlow.write_qualification_report(tmp_path, pdk, {"maximum_level": 2})


def test_changed_rtl_still_blocks_requalification(tmp_path):
    pdk = "ihp-sg13g2"
    for relative in ("rtl/demo.sv", "dv/cdc_rdc/cdc_rdc.rpt", f"meta/{pdk}/qualification.json"):
        file = tmp_path / relative
        file.parent.mkdir(parents=True, exist_ok=True)
        file.write_text("original\n")
    seal_with_test_provenance(tmp_path, pdk)
    (tmp_path / "rtl/demo.sv").write_text("tampered\n")
    (tmp_path / "dv/cdc_rdc/cdc_rdc.rpt").write_text("updated\n")
    with pytest.raises(ValueError, match="rtl/demo.sv"):
        QualificationFlow.write_qualification_report(tmp_path, pdk, {"maximum_level": 2})

@pytest.mark.parametrize("relative", (
    "dv/formal/csr/cover/uart_csr_auto_cover.sv",
    "dv/formal/csr/prove/uart_csr_auto_prove.sv",
    "dv/formal/runs/csr/cover/uart_csr_cover.sby",
    "dv/formal/runs/csr/cover/uart_csr_cover/PASS",
    "dv/formal/runs/csr/prove/uart_csr_prove/logfile.txt",
    "dv/formal/summary.json",
))
def test_generated_formal_can_be_refreshed_for_qualification(tmp_path, relative):
    pdk = "ihp-sg13g2"
    for name in ("rtl/uart.sv", relative, f"meta/{pdk}/qualification.json"):
        path = tmp_path / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("original\n")
    seal_with_test_provenance(tmp_path, pdk)
    (tmp_path / relative).write_text("generated again\n")
    with pytest.raises(ValueError, match="packaged qualification"):
        QualificationFlow.evidence_integrity(tmp_path, pdk)
    QualificationFlow.write_qualification_report(tmp_path, pdk, {"maximum_level": 2})
    assert QualificationFlow.evidence_integrity(tmp_path, pdk)


def test_authored_formal_property_stays_protected(tmp_path):
    pdk = "ihp-sg13g2"
    authored = "dv/formal/properties/cover/uart_cover.sv"
    for name in ("rtl/uart.sv", authored, f"meta/{pdk}/qualification.json"):
        path = tmp_path / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("original\n")
    seal_with_test_provenance(tmp_path, pdk)
    (tmp_path / authored).write_text("tampered\n")
    with pytest.raises(ValueError, match="uart_cover.sv"):
        QualificationFlow.write_qualification_report(tmp_path, pdk, {"maximum_level": 2})


def test_missing_formal_run_result_is_not_accepted(tmp_path):
    pdk = "ihp-sg13g2"
    result = tmp_path / "dv/formal/runs/csr/cover/uart_csr_cover/PASS"
    result.parent.mkdir(parents=True)
    result.write_text("ok\n")
    report = tmp_path / "meta" / pdk / "qualification.json"
    report.parent.mkdir(parents=True)
    report.write_text('{"maximum_level": 2}\n')
    seal_with_test_provenance(tmp_path, pdk)
    result.unlink()
    with pytest.raises(ValueError, match="PASS"):
        QualificationFlow.write_qualification_report(tmp_path, pdk, {"maximum_level": 2})


@pytest.mark.parametrize("relative", (
    "dv/functional/coverage/annotate.log",
    "dv/functional/coverage/merge.log",
    "dv/functional/coverage/summary.json",
    "dv/functional/coverage/merged.dat",
    "dv/functional/coverage/annotated/rtl/uart.sv",
))
def test_coverage_outputs_can_be_regenerated_for_qualification(tmp_path, relative):
    pdk = "ihp-sg13g2"
    for name in ("rtl/uart.sv", relative, f"meta/{pdk}/qualification.json"):
        file = tmp_path / name
        file.parent.mkdir(parents=True, exist_ok=True)
        file.write_text("original\n")
    seal_with_test_provenance(tmp_path, pdk)
    (tmp_path / relative).write_text("regenerated\n")
    with pytest.raises(ValueError, match="packaged qualification"):
        QualificationFlow.evidence_integrity(tmp_path, pdk)
    QualificationFlow.write_qualification_report(tmp_path, pdk, {"maximum_level": 2})
    assert QualificationFlow.evidence_integrity(tmp_path, pdk)


def test_missing_packaged_coverage_still_blocks_requalification(tmp_path):
    pdk = "ihp-sg13g2"
    relative = "dv/functional/coverage/annotate.log"
    for name in (relative, f"meta/{pdk}/qualification.json"):
        file = tmp_path / name
        file.parent.mkdir(parents=True, exist_ok=True)
        file.write_text("original\n")
    seal_with_test_provenance(tmp_path, pdk)
    (tmp_path / relative).unlink()
    with pytest.raises(ValueError, match="annotate.log"):
        QualificationFlow.write_qualification_report(tmp_path, pdk, {"maximum_level": 2})

@pytest.mark.parametrize('relative', (
    'dv/functional/sim/rtl/uart_tb_auto_toggle.fst',
    'dv/functional/regression/summary.json',
    'dv/lint/summary.json',
    'dv/formal/runs/csr/cover/uart_csr_cover/PASS',
    'dv/cdc_rdc/design.json',
))
def test_all_generated_outputs_refresh_without_weakening_release_integrity(tmp_path, relative):
    pdk = 'ihp-sg13g2'
    files = ('rtl/uart.sv', 'dv/formal/properties/prove/authored.sv',
             'dv/functional/py/model/uart_model.py', relative,
             f'meta/{pdk}/qualification.json')
    for item in files:
        file = tmp_path / item
        file.parent.mkdir(parents=True, exist_ok=True)
        file.write_text('old\n')
    seal_with_test_provenance(tmp_path, pdk)
    (tmp_path / relative).write_text('new\n')
    with pytest.raises(ValueError, match='packaged qualification'):
        QualificationFlow.evidence_integrity(tmp_path, pdk)
    QualificationFlow.write_qualification_report(tmp_path, pdk, {'maximum_level': 2})
    assert QualificationFlow.evidence_integrity(tmp_path, pdk)

@pytest.mark.parametrize('relative', (
    'rtl/uart.sv', 'dv/formal/properties/prove/authored.sv',
    'dv/functional/py/model/uart_model.py',
    'dv/functional/tests/smoke/test.py',
))
def test_authored_inputs_are_never_resealed(tmp_path, relative):
    pdk = 'ihp-sg13g2'
    for item in (relative, f'meta/{pdk}/qualification.json'):
        file = tmp_path / item
        file.parent.mkdir(parents=True, exist_ok=True)
        file.write_text('old\n')
    seal_with_test_provenance(tmp_path, pdk)
    (tmp_path / relative).write_text('new\n')
    with pytest.raises(ValueError, match='packaged qualification'):
        QualificationFlow.write_qualification_report(tmp_path, pdk, {'maximum_level': 2})

@pytest.mark.parametrize('relative', (
    'dv/unknown/custom_rule.sv',
    'dv/functional/tb/sv/authored_tb.sv',
    'dv/formal/properties/prove/authored_property.sv',
    'csr/uart.hjson',
))
def test_unowned_and_authored_files_fail_closed(tmp_path, relative):
    pdk = 'ihp-sg13g2'
    for name in (relative, f'meta/{pdk}/qualification.json'):
        path = tmp_path / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text('original\n')
    seal_with_test_provenance(tmp_path, pdk)
    (tmp_path / relative).write_text('modified\n')
    with pytest.raises(ValueError, match='packaged qualification'):
        QualificationFlow.write_qualification_report(tmp_path, pdk, {'maximum_level': 2})


def test_qualification_flow_accepts_backend_context():
    # ReleaseFlow constructs the qualification component with its context.
    context = object()
    flow = QualificationFlow(context)
    assert flow.context is context
