"""Filelists must be portable across run and repository roots."""
from pathlib import Path

import pytest

from flexsoc.backend.design.ip.rtl import RtlFlow


def test_split_filelists_keep_both_namespaces(tmp_path: Path) -> None:
    project = tmp_path / "project"
    run = project / "workspace/runs/uart/qualification_axi_lite_l2"
    shared = project / "hw/ips/prim/prim_ff_2sync.sv"
    local = run / "rtl/uart.sv"
    for source in (shared, local):
        source.parent.mkdir(parents=True, exist_ok=True)
        source.write_text("module dummy; endmodule\n")

    common = run / "rtl/rtl_common.f"
    ip = run / "rtl/rtl_ip.f"
    RtlFlow._split_flow_filelists(
        common_out=common,
        ip_out=ip,
        modules=[shared, local],
        includes=[shared],
        common_roots=[project / "hw"],
        extra_args="",
        root=run,
        project_root=project,
        synthesis=True,
    )

    common_text = common.read_text()
    ip_text = ip.read_text()
    assert "hw/ips/prim/prim_ff_2sync.sv" in common_text
    assert "+incdir+hw/ips/prim" in common_text
    assert "rtl/uart.sv" in ip_text
    assert str(project) not in common_text + ip_text


def test_external_sources_are_rejected(tmp_path: Path) -> None:
    with pytest.raises(ValueError, match="outside FlexSoC roots"):
        RtlFlow._flow_path(tmp_path / "external.sv", tmp_path / "repo/run", tmp_path / "repo")
