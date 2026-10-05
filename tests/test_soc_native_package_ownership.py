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


def test_native_packages_materialize_top_pkg_and_headers(tmp_path: Path) -> None:
    context = _context(tmp_path)
    source = context.project_root / "hw" / "ips" / "pkgs"
    source.mkdir(parents=True)
    (source / "top_pkg.sv").write_text(
        "package top_pkg; parameter int TL_DW = 32; endpackage\n",
        encoding="utf-8",
    )
    (source / "prim_util_pkg.sv").write_text(
        "package prim_util_pkg; endpackage\n",
        encoding="utf-8",
    )
    (source / "assertions.svh").write_text("// assertions\n", encoding="utf-8")

    output = SocFlow(context).materialize_native_packages()

    assert (output / "top_pkg.sv").is_file()
    assert (output / "prim_util_pkg.sv").is_file()
    assert (output / "assertions.svh").is_file()


def test_native_closure_seeds_top_pkg_before_tlul_pkg(tmp_path: Path) -> None:
    context = _context(tmp_path)
    lowrisc = context.project_root / "vendor" / "lowrisc_ip"
    ibex = context.project_root / "vendor" / "lowrisc_ibex" / "rtl"
    prim_generic = lowrisc / "ip" / "prim_generic" / "rtl"
    tlul = lowrisc / "ip" / "tlul" / "rtl"
    prim = lowrisc / "ip" / "prim" / "rtl"
    pkgs = context.project_root / "hw" / "ips" / "pkgs"
    flex_prims = context.project_root / "hw" / "ips" / "prim_opentitan"

    for directory in (ibex, prim_generic, tlul, prim, pkgs, flex_prims, context.paths.rtl):
        directory.mkdir(parents=True, exist_ok=True)

    (pkgs / "top_pkg.sv").write_text("package top_pkg; endpackage\n", encoding="utf-8")
    (pkgs / "prim_util_pkg.sv").write_text("package prim_util_pkg; endpackage\n", encoding="utf-8")
    (flex_prims / "prim_flop_2sync.sv").write_text(
        "module prim_flop_2sync; endmodule\n", encoding="utf-8"
    )
    (prim_generic / "prim_generic_ram_2p.sv").write_text(
        "module prim_generic_ram_2p; endmodule\n", encoding="utf-8"
    )
    tlul_pkg = tlul / "tlul_pkg.sv"
    tlul_pkg.write_text("package tlul_pkg; endpackage\n", encoding="utf-8")
    top = context.paths.rtl / "soc.sv"
    top.write_text("module soc; endmodule\n", encoding="utf-8")
    (context.paths.rtl / "rtl_soc.f").write_text("rtl/soc.sv\n", encoding="utf-8")

    requests = []

    class Runner:
        def run(self, request, *, on="local"):
            requests.append(request)
            modules, includes = request.outputs
            modules.parent.mkdir(parents=True, exist_ok=True)
            native_pkgs = context.paths.rtl / "pkgs_native"
            modules.write_text(
                "\n".join(
                    (
                        str(native_pkgs / "top_pkg.sv"),
                        str(native_pkgs / "prim_util_pkg.sv"),
                        str(tlul_pkg),
                        str(top),
                    )
                )
                + "\n",
                encoding="utf-8",
            )
            includes.write_text("", encoding="utf-8")
            return CommandResult(0, request.log, 0.0)

    flow = SocFlow(context, Runner())
    plan = SoCPlan(
        host="ibex",
        fabric="tlul",
        devices=(SoCDevice("sram", 0x00100000, 0x00020000, True),),
    )
    output = flow.write_native_rtl_filelist(plan, on="fixture")

    argv = requests[0].argv
    top_pkg_arg = str((context.paths.rtl / "pkgs_native" / "top_pkg.sv").resolve())
    tlul_arg = str(tlul_pkg.resolve())
    assert top_pkg_arg in argv
    assert argv.index(top_pkg_arg) < argv.index(str(top.resolve()))
    assert "-I" in argv
    assert str((context.paths.rtl / "pkgs_native").resolve()) in argv

    lines = output.read_text(encoding="utf-8").splitlines()
    top_pkg_line = "rtl/pkgs_native/top_pkg.sv"
    tlul_line = tlul_pkg.resolve().as_posix()
    assert top_pkg_line in lines
    assert tlul_line in lines
    assert lines.index(top_pkg_line) < lines.index(tlul_line)


def test_soc_ownership_manifest_excludes_private_flexsoc_packages(tmp_path: Path) -> None:
    context = _context(tmp_path)
    release = context.paths.run / "ips" / "uart"
    private = release / "rtl" / "deps" / "flexsoc" / "pkgs"
    private.mkdir(parents=True)
    (private / "top_pkg.sv").write_text("package top_pkg; endpackage\n", encoding="utf-8")
    (release / "rtl" / "uart.sv").write_text("module uart; endmodule\n", encoding="utf-8")
    (release / "rtl" / "rtl_common.f").write_text(
        "rtl/deps/flexsoc/pkgs/top_pkg.sv\n",
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
    entries = flow.resolve_soc_rtl_sources(plan).entries

    assert "ips/uart/rtl/uart.sv" in entries
    assert not any("rtl/deps/flexsoc/pkgs/" in entry for entry in entries)
