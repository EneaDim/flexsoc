from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

import pytest

from flexsoc.backend.dv.func.functional import FunctionalFlow


@pytest.mark.parametrize('compiler', ['verilator', 'iverilog'])
def test_compile_uses_resolved_execution_filelists(tmp_path, compiler):
    project = tmp_path / 'project'
    run = project / 'workspace/runs/uart/reg'
    (project / 'hw/ips/pkgs').mkdir(parents=True)
    (project / 'hw/ips/prim').mkdir(parents=True)
    (run / 'rtl').mkdir(parents=True)
    (run / 'dv/functional/tb/sv').mkdir(parents=True)
    (project / 'hw/ips/prim/prim_flop.sv').write_text('module prim_flop; endmodule\n')
    (run / 'rtl/uart.sv').write_text('module uart; endmodule\n')
    common = run / 'rtl/rtl_common.f'
    ip = run / 'rtl/rtl_ip.f'
    common.write_text('+incdir+hw/ips/pkgs\nhw/ips/prim/prim_flop.sv\n')
    ip.write_text('rtl/uart.sv\n')
    (run / 'dv/functional/tb/sv/uart_tb.sv').write_text('module uart_tb; endmodule\n')

    requests = []
    class Runner:
        project_root = project
        def run(self, request, *, on='local'):
            requests.append(request)
            return SimpleNamespace(returncode=0)

    flow = FunctionalFlow(Runner())
    flow.run_compile_systemverilog(
        top='uart', tb_dir=run / 'dv/functional/tb', sim_dir=run / 'dv/functional/sim/rtl',
        common_filelist=common, ip_filelist=ip, compiler=compiler,
        log=run / 'compile.log',
    )
    assert len(requests) == 1
    argv = requests[0].argv
    filelists = [Path(argv[i+1]) for i, arg in enumerate(argv[:-1]) if arg == '-f']
    assert len(filelists) == 2
    assert str(project / 'hw/ips/prim/prim_flop.sv') in filelists[0].read_text()
    assert str(project / 'hw/ips/pkgs') in filelists[0].read_text()
    assert str(run / 'rtl/uart.sv') in filelists[1].read_text()
    assert common.read_text().startswith('+incdir+hw/')
    assert ip.read_text() == 'rtl/uart.sv\n'



def test_cocotb_sources_resolve_both_roots(tmp_path):
    project = tmp_path / 'project'
    run = project / 'workspace/runs/uart/reg'
    common = project / 'hw/ips/prim/prim_flop.sv'
    local = run / 'rtl/uart.sv'
    tb = run / 'dv/functional/tb'
    coco = tb / 'cocotb'
    tests = run / 'dv/functional/tests'
    for path in (common, local, coco / 'Makefile', coco / 'uart_tb.sv',
                 tests / 'smoke/config.regs', tests / 'smoke/data_in.vec',
                 tests / 'smoke/data_out.vec'):
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text('')
    requests = []

    class Runner:
        project_root = project

        def run(self, request, *, on='local'):
            requests.append(request)
            return SimpleNamespace(returncode=0)

    flow = FunctionalFlow(Runner())
    flow.run_cocotb(
        top='uart', test_root=tests, tb_dir=tb,
        rtl_sources=(Path('hw/ips/prim/prim_flop.sv'), Path('rtl/uart.sv')),
        log=run / 'cocotb.log',
    )
    assert len(requests) == 1
    command = requests[0].argv
    src_arg = next(arg for arg in command if arg.startswith('VERILOG_SOURCES='))
    assert str(common.resolve()) in src_arg
    assert str(local.resolve()) in src_arg


def test_cocotb_missing_shared_source_fails_closed(tmp_path):
    project = tmp_path / 'project'
    run = project / 'workspace/runs/uart/reg'
    coco = run / 'dv/functional/tb/cocotb'
    tests = run / 'dv/functional/tests'
    for path in (coco / 'Makefile', coco / 'uart_tb.sv',
                 tests / 'smoke/config.regs', tests / 'smoke/data_in.vec',
                 tests / 'smoke/data_out.vec'):
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text('')

    class Runner:
        project_root = project

    with pytest.raises(FileNotFoundError):
        FunctionalFlow(Runner()).run_cocotb(
            top='uart', test_root=tests, tb_dir=run / 'dv/functional/tb',
            rtl_sources=(Path('hw/ips/prim/nonexistent.sv'),),
            log=run / 'cocotb.log',
        )
