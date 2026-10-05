
from pathlib import Path

from flexsoc.backend.core import BackendContext, CommandResult
from flexsoc.backend.design.soc.soc import SoCDevice, SoCPlan, SocFlow


def _context(tmp_path: Path) -> BackendContext:
    project = tmp_path / "project"
    context = BackendContext(
        project,
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


def _plan() -> SoCPlan:
    return SoCPlan(
        host="ibex",
        fabric="tlul",
        devices=(SoCDevice("sram", 0x00100000, 0x00020000, True),),
    )


def test_native_generic_primitives_are_materialized_under_abstract_names(tmp_path: Path) -> None:
    context = _context(tmp_path)
    generic = context.project_root / "vendor" / "lowrisc_ip" / "ip" / "prim_generic" / "rtl"
    generic.mkdir(parents=True)
    (generic / "prim_generic_ram_2p.sv").write_text(
        "module prim_generic_ram_2p; prim_generic_flop u_flop(); endmodule\n",
        encoding="utf-8",
    )
    (generic / "prim_generic_flop.sv").write_text(
        "module prim_generic_flop; endmodule\n",
        encoding="utf-8",
    )

    output = SocFlow(context).materialize_native_generic_primitives()

    ram = output / "prim_ram_2p.sv"
    flop = output / "prim_flop.sv"
    assert ram.is_file()
    assert flop.is_file()
    assert "module prim_ram_2p" in ram.read_text(encoding="utf-8")
    assert "prim_flop u_flop" in ram.read_text(encoding="utf-8")
    assert "prim_generic_" not in ram.read_text(encoding="utf-8")


def test_ibex_native_closure_uses_materialized_prims_and_rvfi(tmp_path: Path) -> None:
    context = _context(tmp_path)

    ibex = context.project_root / "vendor" / "lowrisc_ibex"
    lowrisc = context.project_root / "vendor" / "lowrisc_ip"
    generic = lowrisc / "ip" / "prim_generic" / "rtl"
    for directory in (ibex / "rtl", generic, context.paths.rtl):
        directory.mkdir(parents=True, exist_ok=True)

    (generic / "prim_generic_ram_2p.sv").write_text(
        "module prim_generic_ram_2p; endmodule\n", encoding="utf-8"
    )
    (generic / "prim_generic_flop_2sync.sv").write_text(
        "module prim_generic_flop_2sync; endmodule\n", encoding="utf-8"
    )
    (ibex / "rtl" / "ibex_top_tracing.sv").write_text(
        "module ibex_top_tracing; endmodule\n", encoding="utf-8"
    )
    (context.paths.rtl / "soc.sv").write_text(
        "module soc; endmodule\n", encoding="utf-8"
    )

    captured = []

    class Runner:
        def run(self, request, *, on="local"):
            captured.append(request)
            modules, includes = request.outputs
            modules.parent.mkdir(parents=True, exist_ok=True)
            prim_root = context.paths.rtl / "prim_generic"
            modules.write_text(
                "\n".join(
                    (
                        str(prim_root / "prim_ram_2p.sv"),
                        str(prim_root / "prim_flop_2sync.sv"),
                        str(ibex / "rtl" / "ibex_top_tracing.sv"),
                        str(context.paths.rtl / "soc.sv"),
                    )
                )
                + "\n",
                encoding="utf-8",
            )
            includes.write_text("", encoding="utf-8")
            return CommandResult(0, request.log, 0.0)

    output = SocFlow(context, Runner()).write_native_rtl_filelist(_plan(), on="fixture")

    assert len(captured) == 1
    argv = captured[0].argv
    assert "-DRVFI" in argv
    assert str((context.paths.rtl / "prim_generic" / "...").resolve()) in argv

    lines = output.read_text(encoding="utf-8").splitlines()
    assert "+define+RVFI" in lines
    assert "rtl/prim_generic/prim_ram_2p.sv" in lines
    assert "rtl/prim_generic/prim_flop_2sync.sv" in lines
