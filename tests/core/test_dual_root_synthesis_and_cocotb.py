"""Regression checks for FlexSoC's portable two-root RTL source contract."""
from pathlib import Path

import pytest

from flexsoc.backend.core import BackendContext
from flexsoc.backend.syn.syn import Syn


def _project(tmp_path: Path, *, interface: str, n_clocks: int):
    project = tmp_path / "flexsoc"
    run = project / "workspace" / "runs" / "my_ip" / "check"
    (run / "rtl").mkdir(parents=True)
    shared = project / "hw" / "ips" / "prim_opentitan" / "prim_flop.sv"
    vendor = project / "vendor" / "pulp" / "axi" / "src" / "axi_pkg.sv"
    local = run / "rtl" / "my_ip.sv"
    for path in (shared, vendor, local):
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("module example; endmodule\n")
    common = run / "rtl" / "rtl_common.f"
    ip = run / "rtl" / "rtl_ip.f"
    common.write_text(
        "+define+SYNTHESIS\n"
        "+incdir+hw/ips/prim_opentitan+vendor/pulp/axi/src\n"
        "hw/ips/prim_opentitan/prim_flop.sv\n"
        "vendor/pulp/axi/src/axi_pkg.sv\n"
    )
    ip.write_text("+incdir+rtl\nrtl/my_ip.sv\n")
    orfs = project / "ORFS" / "flow"
    (orfs / "platforms" / "sky130").mkdir(parents=True)
    (orfs / "Makefile").write_text("all:\n\t@true\n")
    (orfs / "platforms" / "sky130" / "config.mk").write_text("# test\n")
    ctx = BackendContext(
        project_root=project,
        workspace=project / "workspace",
        values={"TOP": "my_ip", "RUN_TOP": "my_ip", "RUN_ID": "check",
                "REG_ITF": interface, "N_CLOCKS": str(n_clocks),
                "ORS": str(orfs), "LIB_SYN": str(project / "lib.lib"),
                "PDK": "sky130", "CLK_PERIOD": "10"},
    )
    return ctx, common, ip, shared, vendor, local


@pytest.mark.parametrize("interface", ("axi_lite", "tlul", "reg_iface"))
@pytest.mark.parametrize("n_clocks", (1, 3))
def test_synthesis_and_standalone_cocotb_have_same_two_roots(tmp_path, monkeypatch, interface, n_clocks):
    ctx, common, ip, shared, vendor, local = _project(tmp_path, interface=interface, n_clocks=n_clocks)
    captured = {}

    def fake_setup_asic(self, **kwargs):
        captured.update(kwargs)
        return tuple(kwargs["filelists"])

    monkeypatch.setattr(Syn, "setup_asic", fake_setup_asic)
    generated = Syn(context=ctx).setup()
    prepared = generated[:2]
    assert len(generated) == 4  # includes resolved filelists for provenance
    assert all(filelist.is_relative_to(ctx.paths.syn / "inputs") for filelist in prepared)
    text = "\n".join(path.read_text() for path in prepared)
    for source in (shared, vendor, local):
        assert str(source.resolve()) in text
    assert str((ctx.project_root / "hw/ips/prim_opentitan").resolve()) in text
    assert str((ctx.paths.run / "rtl").resolve()) in text
    assert common.read_text().startswith("+define+SYNTHESIS\n+incdir+hw/")
    assert ip.read_text() == "+incdir+rtl\nrtl/my_ip.sv\n"
    assert ctx.rtl_contract.sources() == (shared.resolve(), vendor.resolve(), local.resolve())
    assert captured["filelists"] == prepared
    script = Syn.yosys_presynth_asic_slang(
        "my_ip", ctx.project_root / "lib.lib", ctx.paths.syn, prepared,
    )
    assert all(f"-f {path.resolve()}" in script for path in prepared)


def test_missing_shared_dependency_fails_before_synthesis(tmp_path, monkeypatch):
    ctx, _, _, shared, _, _ = _project(tmp_path, interface="axi_lite", n_clocks=1)
    shared.unlink()
    monkeypatch.setattr(Syn, "setup_asic", lambda self, **kw: None)
    with pytest.raises(FileNotFoundError, match="prim_flop.sv"):
        Syn(context=ctx).setup()
