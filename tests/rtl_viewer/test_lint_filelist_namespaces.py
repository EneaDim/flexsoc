from pathlib import Path

import pytest

from flexsoc.backend.dv.lint.sources import LintSources


def test_shared_and_run_paths_are_distinct(tmp_path):
    project = tmp_path / "project"
    run = project / "workspace" / "runs" / "uart" / "qualification"
    (project / "hw/ips/pkgs").mkdir(parents=True)
    (project / "hw/ips/prim").mkdir(parents=True)
    (run / "rtl").mkdir(parents=True)
    (project / "hw/ips/prim/flop.sv").write_text("module flop; endmodule\n")
    (run / "rtl/uart.sv").write_text("module uart; endmodule\n")
    common = run / "rtl/rtl_common.f"
    ip = run / "rtl/rtl_ip.f"
    common.write_text("+incdir+hw/ips/pkgs\nhw/ips/prim/flop.sv\n")
    ip.write_text("rtl/uart.sv\n")
    output = LintSources(project, run).prepare((common, ip))
    assert len(output) == 2
    assert str(project / "hw/ips/pkgs") in output[0].read_text()
    assert str(project / "hw/ips/prim/flop.sv") in output[0].read_text()
    assert str(run / "rtl/uart.sv") in output[1].read_text()
    assert common.read_text().startswith("+incdir+hw/")
    assert ip.read_text() == "rtl/uart.sv\n"


def test_missing_and_nonportable_paths_rejected(tmp_path):
    project = tmp_path / "p"
    run = project / "run"
    run.mkdir(parents=True)
    sources = LintSources(project, run)
    with pytest.raises(FileNotFoundError):
        sources.resolve("vendor/missing.sv")
    for invalid in ("/tmp/absolute.sv", "rtl/../../outside.sv"):
        with pytest.raises(ValueError):
            sources.resolve(invalid)


def test_unsupported_directives_fail_closed(tmp_path):
    run = tmp_path / "run"
    run.mkdir()
    f = run / "sources.f"
    f.write_text("-y rtl\n")
    with pytest.raises(ValueError, match="unsupported"):
        LintSources(tmp_path, run).prepare((f,))
