from pathlib import Path

from flexsoc.backend.core import BackendContext, CommandResult
from flexsoc.backend.design.soc.soc import SoCDevice, SoCPlan, SocFlow


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
            "SLANG": "slang-test",
        },
    )
    context.paths.ensure()
    return context


def test_ibex_soc_uses_production_top_and_not_tracing_wrapper() -> None:
    root = Path(__file__).resolve().parents[3]
    defaults = (
        root / "src/flexsoc/templates/design/soc/defaults_ibex.sv.j2"
    ).read_text(encoding="utf-8")
    core = (root / "src/flexsoc/templates/design/soc/soc.core.j2").read_text(
        encoding="utf-8"
    )

    assert "ibex_top #(\n" in defaults
    assert ") u_ibex_top (" in defaults
    assert "ibex_top_tracing" not in defaults
    assert "lowrisc:ibex:ibex_top" in core
    assert "ibex_top_tracing" not in core


def test_ibex_native_closure_discovery_does_not_require_rvfi(tmp_path: Path) -> None:
    context = _context(tmp_path)
    rtl = context.paths.rtl
    (rtl / "soc.sv").write_text("module soc; endmodule\n", encoding="utf-8")
    (rtl / "rtl_soc.f").write_text("rtl/soc.sv\n", encoding="utf-8")

    prims = rtl / "prim_native"
    pkgs = rtl / "pkgs_native"
    prims.mkdir(parents=True)
    pkgs.mkdir(parents=True)
    (pkgs / "top_pkg.sv").write_text("package top_pkg; endpackage\n", encoding="utf-8")

    lowrisc = context.project_root / "vendor/lowrisc_ip"
    ibex = context.project_root / "vendor/lowrisc_ibex/rtl"
    (lowrisc / "ip/prim/rtl").mkdir(parents=True)
    (lowrisc / "ip/tlul/rtl").mkdir(parents=True)
    ibex.mkdir(parents=True)
    ibex_top = ibex / "ibex_top.sv"
    ibex_top.write_text("module ibex_top; endmodule\n", encoding="utf-8")

    requests = []

    class Runner:
        def run(self, request, *, on="local"):
            requests.append(request)
            modules, includes = request.outputs
            modules.parent.mkdir(parents=True, exist_ok=True)
            modules.write_text(
                f"{ibex_top}\n{rtl / 'soc.sv'}\n",
                encoding="utf-8",
            )
            includes.write_text("", encoding="utf-8")
            return CommandResult(0, request.log, 0.0)

    flow = SocFlow(context, Runner())
    flow.materialize_native_primitives = lambda: prims
    flow.materialize_native_packages = lambda: pkgs
    plan = SoCPlan(
        "ibex",
        "tlul",
        (SoCDevice("sram", 0x00100000, 0x20000, True),),
    )

    output = flow.write_native_rtl_filelist(plan, on="fixture")

    assert len(requests) == 1
    assert "-DSYNTHESIS" in requests[0].argv
    assert "-DRVFI" not in requests[0].argv
    lines = output.read_text(encoding="utf-8").splitlines()
    assert "+define+RVFI" not in lines
    assert ibex_top.resolve().as_posix() in lines
