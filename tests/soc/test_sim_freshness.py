from __future__ import annotations

import shutil
from pathlib import Path

from flexsoc.backend.core import BackendContext, CommandResult
from flexsoc.backend.design.soc.soc import SocFlow

ROOT = Path(__file__).resolve().parents[2]


def _context(tmp_path: Path, *, test_name: str = "boot_smoke") -> BackendContext:
    context = BackendContext(
        tmp_path / "project", tmp_path / "work",
        {
            "TOP": "test", "RUN_TOP": "test", "RUN_ID": "dev",
            "HOST": "ibex", "FABRIC": "tlul", "TEST_NAME": test_name,
        },
    )
    context.paths.ensure()
    return context


def test_cpu_firmware_hooks_are_consumed_from_workspace_test(tmp_path: Path) -> None:
    context = _context(tmp_path)
    shutil.copytree(ROOT / "tests/fixtures/soc/boot_smoke", context.paths.tests / "boot_smoke")
    (context.paths.rtl / "soc.sv").write_text(
        'module soc #(parameter string SramInitFile="") (input logic clk_i, input logic rst_ni); endmodule\n',
        encoding="utf-8",
    )
    flow = SocFlow(context)
    flow.dv.generate(flow.resolve_plan())

    tb = (context.paths.tb / "sv/soc_tb.sv").read_text(encoding="utf-8")
    assert "SramInitFile" in tb
    assert "soc_fw_pass_seen" in tb
    assert "[TB][BOOT] FAIL" in tb


def test_native_sim_build_removes_stale_verilator_workdir(tmp_path: Path) -> None:
    context = _context(tmp_path, test_name="smoke")
    (context.paths.rtl / "soc.sv").write_text(
        "module soc(input logic clk_i, input logic rst_ni); endmodule\n", encoding="utf-8"
    )
    (context.paths.rtl / "rtl.f").write_text("rtl/soc.sv\n", encoding="utf-8")
    sv = context.paths.tb / "sv"
    sv.mkdir(parents=True, exist_ok=True)
    (sv / "soc_tb.sv").write_text("module soc_tb; endmodule\n", encoding="utf-8")
    stale_dir = context.paths.sim / "verilator"
    stale_dir.mkdir(parents=True)
    stale = stale_dir / "STALE"
    stale.write_text("old simulator\n", encoding="utf-8")

    class Runner:
        def run(self, request, *, on="local"):
            assert not stale.exists()
            assert request.cwd == context.paths.run
            request.outputs[0].parent.mkdir(parents=True, exist_ok=True)
            request.outputs[0].write_text("fixture simulator\n", encoding="utf-8")
            return CommandResult(0, request.log, 0.0)

    result, simulator = SocFlow(context, Runner()).native_verilator_simulator()
    assert result.returncode == 0
    assert simulator.is_file()
