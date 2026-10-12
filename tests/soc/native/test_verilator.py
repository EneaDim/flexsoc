from pathlib import Path

from flexsoc.backend.core import BackendContext, CommandResult
from flexsoc.backend.design.soc.soc import SocFlow


def _context(tmp_path: Path) -> BackendContext:
    context = BackendContext(
        tmp_path / "project",
        tmp_path / "work",
        {
            "TOP": "test",
            "RUN_TOP": "test",
            "RUN_ID": "dev",
            "HOST": "ibex",
            "FABRIC": "tlul",
            "VERILATOR": "verilator-test",
        },
    )
    context.paths.ensure()
    return context


def test_native_verilator_lint_consumes_rtl_f_without_fusesoc(tmp_path: Path) -> None:
    context = _context(tmp_path)
    source = context.paths.rtl / "soc.sv"
    source.write_text("module soc; endmodule\n", encoding="utf-8")
    filelist = context.paths.rtl / "rtl.f"
    filelist.write_text("rtl/soc.sv\n", encoding="utf-8")
    requests = []

    class Runner:
        def run(self, request, *, on="local"):
            requests.append(request)
            return CommandResult(0, request.log, 0.0)

    result = SocFlow(context, Runner()).native_verilator_lint(on="fixture")

    assert result.returncode == 0
    assert len(requests) == 1
    argv = requests[0].argv
    assert argv[0] == "verilator-test"
    assert "--lint-only" in argv
    assert "-f" in argv
    assert str(filelist) in argv
    assert "--top-module" in argv
    assert "soc" in argv
    assert not any("fusesoc" in item.lower() for item in argv)
    assert requests[0].cwd == context.paths.run


def test_native_verilator_simulator_rebuilds_from_rtl_f_and_generated_tb(tmp_path: Path) -> None:
    context = _context(tmp_path)
    source = context.paths.rtl / "soc.sv"
    source.write_text("module soc; endmodule\n", encoding="utf-8")
    filelist = context.paths.rtl / "rtl.f"
    filelist.write_text("+define+RVFI\nrtl/soc.sv\n", encoding="utf-8")

    sv_dir = context.paths.tb / "sv"
    sv_dir.mkdir(parents=True)
    tb = sv_dir / "soc_tb.sv"
    tb.write_text("module soc_tb; endmodule\n", encoding="utf-8")

    build_dir = context.paths.sim / "verilator"
    stale = build_dir / "STALE"
    build_dir.mkdir(parents=True)
    stale.write_text("stale\n", encoding="utf-8")
    requests = []

    class Runner:
        def run(self, request, *, on="local"):
            requests.append(request)
            assert not stale.exists()
            simulator = build_dir / "Vsoc_tb"
            simulator.parent.mkdir(parents=True, exist_ok=True)
            simulator.write_text("fixture\n", encoding="utf-8")
            return CommandResult(0, request.log, 0.0)

    result, simulator = SocFlow(context, Runner()).native_verilator_simulator(on="fixture")

    assert result.returncode == 0
    assert simulator == build_dir / "Vsoc_tb"
    argv = requests[0].argv
    assert argv[0] == "verilator-test"
    assert "--binary" in argv
    assert "--timing" in argv
    assert str(filelist) in argv
    assert str(tb) in argv
    assert "--top-module" in argv
    assert "soc_tb" in argv
    assert not any("fusesoc" in item.lower() for item in argv)


def test_soc_runtime_has_no_fusesoc_build_path() -> None:
    import inspect
    import flexsoc.backend.design.soc.soc as soc_module

    source = Path(soc_module.__file__).read_text(encoding="utf-8")

    build_start = source.index("    def build(")
    build_end = source.index("\n    def ", build_start + 10)
    build_method = source[build_start:build_end]

    simulate_start = source.index("    def simulate(")
    simulate_end = source.index("\n    def ", simulate_start + 10)
    simulate_method = source[simulate_start:simulate_end]

    assert "native_verilator_lint" in build_method
    assert "native_verilator_simulator" in simulate_method
    assert "fusesoc_build(" not in build_method
    assert "fusesoc_build(" not in simulate_method
