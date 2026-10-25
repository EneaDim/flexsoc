"""CDC extraction must resolve shared and run-local RTL before invoking Yosys."""

from pathlib import Path

from flexsoc.backend.dv.lint.cdc import CdcFlow
from flexsoc.backend.dv.lint.sources import LintSources


def test_cdc_filelist_projection_is_tool_local(tmp_path: Path):
    repo = tmp_path / 'project'
    run = repo / 'workspace' / 'runs' / 'uart' / 'run_a'
    (repo / 'hw' / 'ips' / 'pkgs').mkdir(parents=True)
    (repo / 'hw' / 'ips' / 'prim').mkdir(parents=True)
    (run / 'rtl').mkdir(parents=True)
    (repo / 'hw' / 'ips' / 'prim' / 'prim_flop.sv').write_text('module prim_flop; endmodule\n')
    (run / 'rtl' / 'uart.sv').write_text('module uart; endmodule\n')
    common = run / 'rtl' / 'rtl_common.f'
    ip = run / 'rtl' / 'rtl_ip.f'
    common.write_text('+incdir+hw/ips/pkgs\nhw/ips/prim/prim_flop.sv\n')
    ip.write_text('rtl/uart.sv\n')
    original = common.read_text(), ip.read_text()

    prepared = LintSources(repo, run).prepare((common, ip), directory=run / 'dv' / 'cdc_rdc' / 'inputs')
    projected = CdcFlow._yosys_filelists(prepared, run, run / 'dv' / 'cdc_rdc')
    script = CdcFlow.render_extract_script(top='uart', filelists=projected,
                                           repo_root=repo, design_json=run / 'dv' / 'cdc_rdc' / 'design.json')
    assert str((repo / 'hw' / 'ips' / 'prim' / 'prim_flop.sv').resolve()) in prepared[0].read_text()
    assert str((run / 'rtl' / 'uart.sv').resolve()) in prepared[1].read_text()
    assert str((repo / 'hw' / 'ips' / 'pkgs').resolve()) in prepared[0].read_text()
    assert str(prepared[0]) in script
    assert original == (common.read_text(), ip.read_text())


def test_cdc_missing_dependency_fails_before_extraction(tmp_path: Path):
    repo = tmp_path / 'project'
    run = repo / 'workspace' / 'runs' / 'uart' / 'run_a'
    (run / 'rtl').mkdir(parents=True)
    filelist = run / 'rtl' / 'rtl_common.f'
    filelist.write_text('hw/ips/prim/not_present.sv\n')
    try:
        LintSources(repo, run).prepare((filelist,), directory=run / 'dv' / 'cdc_rdc' / 'inputs')
    except FileNotFoundError as exc:
        assert 'not_present.sv' in str(exc)
    else:
        raise AssertionError('Missing shared RTL must fail closed')
