from pathlib import Path

from flexsoc.backend.core import BackendContext
from flexsoc.backend.design.soc.soc import SocFlow


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
        },
    )
    context.paths.ensure()
    return context


def test_native_primitives_prefer_flexsoc_and_fill_missing_lowrisc(tmp_path: Path) -> None:
    context = _context(tmp_path)
    flexsoc = context.project_root / "hw" / "ips" / "prim_opentitan"
    generic = (
        context.project_root
        / "vendor"
        / "lowrisc_ip"
        / "ip"
        / "prim_generic"
        / "rtl"
    )
    flexsoc.mkdir(parents=True)
    generic.mkdir(parents=True)

    (flexsoc / "prim_flop_2sync.sv").write_text(
        "module prim_flop_2sync; // flexsoc\nendmodule\n",
        encoding="utf-8",
    )
    (generic / "prim_generic_flop_2sync.sv").write_text(
        "module prim_generic_flop_2sync; // vendor\nendmodule\n",
        encoding="utf-8",
    )
    (generic / "prim_generic_ram_2p.sv").write_text(
        "module prim_generic_ram_2p; endmodule\n",
        encoding="utf-8",
    )
    (generic / "prim_generic_clock_gating.sv").write_text(
        "module prim_generic_clock_gating; endmodule\n",
        encoding="utf-8",
    )

    output = SocFlow(context).materialize_native_primitives()

    flop = (output / "prim_flop_2sync.sv").read_text(encoding="utf-8")
    ram = (output / "prim_ram_2p.sv").read_text(encoding="utf-8")
    clock = (output / "prim_clock_gating.sv").read_text(encoding="utf-8")

    assert "// flexsoc" in flop
    assert "// vendor" not in flop
    assert "module prim_ram_2p" in ram
    assert "module prim_clock_gating" in clock
    assert "prim_generic_" not in ram
    assert "prim_generic_" not in clock


def test_soc_source_manifest_drops_release_private_prim_copies(tmp_path: Path) -> None:
    from flexsoc.backend.design.soc.soc import SoCDevice, SoCPlan

    context = _context(tmp_path)
    release = context.paths.run / "ips" / "uart"
    private = release / "rtl" / "deps" / "flexsoc" / "prim_opentitan"
    private.mkdir(parents=True)
    (private / "prim_flop_2sync.sv").write_text(
        "module prim_flop_2sync; endmodule\n", encoding="utf-8"
    )
    (release / "rtl" / "uart.sv").write_text(
        "module uart; endmodule\n", encoding="utf-8"
    )
    (release / "rtl" / "rtl_common.f").write_text(
        "rtl/deps/flexsoc/prim_opentitan/prim_flop_2sync.sv\n",
        encoding="utf-8",
    )
    (release / "rtl" / "rtl_ip.f").write_text("rtl/uart.sv\n", encoding="utf-8")

    autogen = context.paths.rtl / "autogen"
    autogen.mkdir(parents=True)
    (autogen / "tl_main_pkg.sv").write_text("package tl_main_pkg; endpackage\n", encoding="utf-8")
    (autogen / "xbar_main.sv").write_text("module xbar_main; endmodule\n", encoding="utf-8")
    (context.paths.rtl / "soc.sv").write_text("module soc; endmodule\n", encoding="utf-8")

    flow = SocFlow(context)
    plan = SoCPlan(
        host="ibex",
        fabric="tlul",
        devices=(
            SoCDevice("sram", 0x00100000, 0x00020000, True),
            SoCDevice("uart", 0x80000000, 0x1000, False),
        ),
    )
    lines = flow.resolve_soc_rtl_sources(plan).entries

    assert "ips/uart/rtl/uart.sv" in lines
    assert not any("rtl/deps/flexsoc/prim_opentitan/" in line for line in lines)
