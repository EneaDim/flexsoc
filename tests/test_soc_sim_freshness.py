from pathlib import Path

from flexsoc.backend.core import BackendContext, CommandResult
from flexsoc.backend.design.soc.soc import SocFlow


def _context(tmp_path: Path, *, test_name: str = "boot_smoke") -> BackendContext:
    project = tmp_path / "project"
    for name in ("lowrisc_ibex", "lowrisc_ip"):
        (project / "vendor" / name).mkdir(parents=True, exist_ok=True)
    context = BackendContext(
        project,
        tmp_path / "work",
        {
            "TOP": "test",
            "RUN_TOP": "test",
            "RUN_ID": "dev",
            "HOST": "ibex",
            "FABRIC": "tlul",
            "TEST_NAME": test_name,
            "FUSESOC": "fusesoc-test",
        },
    )
    context.paths.ensure()
    return context


def test_cpu_firmware_timeout_reaches_rendered_soc_tb(tmp_path: Path) -> None:
    context = _context(tmp_path)
    flow = SocFlow(context)
    flow.dv.generate(flow.resolve_plan())

    tb = (context.paths.tb / "sv" / "soc_tb.sv").read_text(encoding="utf-8")

    assert "soc_boot_pass_seen" in tb
    assert "soc_fw_wait < 1024 && !soc_boot_pass_seen" in tb
    assert "@(posedge clk_i);" in tb
    assert "[TB][BOOT] FAIL" in tb


def test_sim_build_removes_stale_verilator_workdir_before_fusesoc(tmp_path: Path) -> None:
    context = _context(tmp_path, test_name="smoke")
    stale_dir = context.paths.run / "fusesoc" / "sim-verilator"
    stale_dir.mkdir(parents=True)
    stale = stale_dir / "STALE"
    stale.write_text("old simulator\n", encoding="utf-8")

    class Runner:
        def run(self, request, *, on="local"):
            assert not stale.exists()
            assert "--target=sim" in request.argv
            return CommandResult(0, request.log, 0.0)

    flow = SocFlow(context, Runner())
    simulator = stale_dir / "Vsoc_tb"
    result = flow.fusesoc_build(
        "sim",
        context.paths.logs / "soc" / "sim-build.log",
        (simulator,),
    )
    assert result.returncode == 0
