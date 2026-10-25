"""Filelist paths stay portable across frozen run reloads."""
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import Mock

import pytest

from flexsoc.backend.dv.lint.slang_hier import SlangHierarchy


def _flow(tmp_path):
    project = tmp_path / "project"
    run = project / "workspace" / "runs" / "uart" / "qualification_l2"
    rtl = run / "rtl"
    rtl.mkdir(parents=True)
    (rtl / "uart.sv").write_text("module uart; endmodule\n")
    shared = project / "hw" / "ips" / "pkgs"
    shared.mkdir(parents=True)
    (shared / "top_pkg.sv").write_text("package top_pkg; endpackage\n")
    vendor = project / "vendor" / "lib"
    vendor.mkdir(parents=True)
    (vendor / "support.sv").write_text("module support; endmodule\n")
    (rtl / "rtl_common.f").write_text(
        "+incdir+hw/ips/pkgs\nhw/ips/pkgs/top_pkg.sv\nvendor/lib/support.sv\n"
    )
    (rtl / "rtl_ip.f").write_text("rtl/uart.sv\n")
    context = SimpleNamespace(project_root=project, values={}, paths=SimpleNamespace(
        top="uart", run=run, rtl=rtl,
        rtl_common=rtl / "rtl_common.f", rtl_ip=rtl / "rtl_ip.f",
    ))
    return SlangHierarchy(context, Mock()), project, run


def test_shared_paths_are_project_relative_and_ip_sources_run_relative(tmp_path):
    flow, project, run = _flow(tmp_path)
    _, top, roots, _ = flow._inputs()
    assert top == run / "rtl" / "uart.sv"
    assert project / "hw" / "ips" / "pkgs" in roots
    command, _, _ = flow._command(ast=run / "ast.json", on="grid", resolve_tool=False)
    assert str(project / "hw" / "ips" / "pkgs" / "top_pkg.sv") in command
    assert str(project / "vendor" / "lib" / "support.sv") in command
    assert str(run / "rtl" / "uart.sv") == command[-1]
    assert not (run / "hw").exists()


@pytest.mark.parametrize("bad", ["/tmp/foreign.sv", "rtl/../outside.sv", "hw/ips/../../bad.sv"])
def test_shared_filelists_reject_nonportable_paths(tmp_path, bad):
    flow, _, run = _flow(tmp_path)
    (run / "rtl" / "rtl_common.f").write_text(bad + "\n")
    with pytest.raises(ValueError, match="nonportable filelist path"):
        flow._command(ast=run / "ast.json", on="grid", resolve_tool=False)
