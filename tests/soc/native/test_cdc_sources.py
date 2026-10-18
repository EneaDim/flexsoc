from pathlib import Path

from flexsoc.backend.core import BackendContext, CommandResult
from flexsoc.backend.dv.lint.cdc import CdcFlow


def _context(tmp_path: Path, *, soc: bool) -> BackendContext:
    top = "workspace_top"
    context = BackendContext(
        tmp_path / "project",
        tmp_path / "work",
        {
            "TOP": top,
            "RUN_TOP": "test",
            "RUN_ID": "dev",
            "CLOCK_DOMAINS": "core:clk_i:rst_ni:10:low",
            "YOSYS": "yosys-test",
        },
    )
    context.paths.ensure()
    if soc:
        plan = context.paths.run / "soc" / "plan.json"
        plan.parent.mkdir(parents=True)
        plan.write_text(
            '{"schema": 1, "host": "ibex", "fabric": "tlul", "devices": []}\n',
            encoding="utf-8",
        )
        (context.paths.rtl / "rtl.f").write_text("rtl/soc.sv\n", encoding="utf-8")
        (context.paths.rtl / "soc.sv").write_text("module soc; endmodule\n", encoding="utf-8")
    else:
        context.paths.rtl_common.write_text("rtl/common.sv\n", encoding="utf-8")
        context.paths.rtl_ip.write_text("rtl/workspace_top.sv\n", encoding="utf-8")
    return context


def test_cdc_setup_uses_resolved_soc_source_contract(tmp_path: Path) -> None:
    context = _context(tmp_path, soc=True)

    script = CdcFlow(context).setup().read_text(encoding="utf-8")

    assert f"-f {context.paths.rtl / 'rtl.f'}" in script
    assert str(context.paths.rtl_common) not in script
    assert str(context.paths.rtl_ip) not in script
    assert "--top soc" in script
    assert "-D SYNTHESIS" in script
    assert "--ignore-initial" in script


def test_cdc_setup_preserves_ip_split_source_contract(tmp_path: Path) -> None:
    context = _context(tmp_path, soc=False)

    script = CdcFlow(context).setup().read_text(encoding="utf-8")

    assert f"-f {context.paths.rtl_common}" in script
    assert f"-f {context.paths.rtl_ip}" in script
    assert "--top workspace_top" in script


def test_cdc_extraction_executes_from_source_contract_root(tmp_path: Path) -> None:
    context = _context(tmp_path, soc=True)
    context.paths.sdc.write_text(
        "create_clock -name core -period 10 [get_ports clk_i]\n",
        encoding="utf-8",
    )
    flow = CdcFlow(context)
    flow.setup()
    requests = []

    class Runner:
        def run(self, request, *, on="local"):
            requests.append(request)
            return CommandResult(1, request.log, 0.0)

    flow.runner = Runner()

    assert flow.run() == 1
    assert requests[0].cwd == context.rtl_contract.root
    assert requests[0].cwd == context.paths.run


def test_cdc_yosys_projection_preserves_vendor_and_canonical_filelist(tmp_path: Path) -> None:
    context = _context(tmp_path, soc=True)
    vendor = context.project_root / "vendor/lowrisc_ibex/rtl/ibex_top.sv"
    vendor.parent.mkdir(parents=True)
    original = (
        "module ibex_top;\n"
        "  logic unused_scramble_inputs = scramble_key_valid_i &\n"
        "      (|scramble_key_i);\n"
        "endmodule\n"
    )
    vendor.write_text(original, encoding="utf-8")
    canonical = context.paths.rtl / "rtl.f"
    canonical.write_text(f"{vendor}\nrtl/soc.sv\n", encoding="utf-8")

    script = CdcFlow(context).setup().read_text(encoding="utf-8")
    projected = context.paths.cdc_rdc / "yosys_projection"
    source = (projected / "ibex_top.sv").read_text(encoding="utf-8")
    sources = (projected / "sources_0.f").read_text(encoding="utf-8")

    assert "assign unused_scramble_inputs = scramble_key_valid_i" in source
    assert "logic unused_scramble_inputs =" not in source
    assert vendor.read_text(encoding="utf-8") == original
    assert canonical.read_text(encoding="utf-8") == f"{vendor}\nrtl/soc.sv\n"
    assert str(projected / "ibex_top.sv") in sources
    assert f"-f {projected / 'sources_0.f'}" in script
    assert CdcFlow(context).setup().read_text(encoding="utf-8") == script


def test_cdc_yosys_projection_rejects_changed_vendor_initializer(tmp_path: Path) -> None:
    import pytest

    context = _context(tmp_path, soc=True)
    vendor = context.project_root / "vendor/lowrisc_ibex/rtl/ibex_top.sv"
    vendor.parent.mkdir(parents=True)
    vendor.write_text("module ibex_top; endmodule\n", encoding="utf-8")
    canonical = context.paths.rtl / "rtl.f"
    canonical.write_text(f"{vendor}\n", encoding="utf-8")

    with pytest.raises(ValueError, match="projection refused"):
        CdcFlow(context).setup()
    assert vendor.read_text(encoding="utf-8") == "module ibex_top; endmodule\n"
