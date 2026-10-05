
from pathlib import Path

import pytest

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
        devices=(
            SoCDevice("sram", 0x00100000, 0x00020000, True),
            SoCDevice("uart", 0x80000000, 0x1000, False),
        ),
    )


def test_native_soc_rtl_filelist_is_slang_dependency_closure(tmp_path: Path) -> None:
    context = _context(tmp_path)

    ibex_root = context.project_root / "vendor" / "lowrisc_ibex"
    lowrisc_root = context.project_root / "vendor" / "lowrisc_ip"
    uart_root = context.paths.run / "ips" / "uart"
    autogen = context.paths.rtl / "autogen"

    for directory in (
        ibex_root / "rtl",
        lowrisc_root / "ip" / "tlul" / "rtl",
        uart_root / "rtl",
        autogen,
    ):
        directory.mkdir(parents=True, exist_ok=True)

    sources = (
        ibex_root / "rtl" / "ibex_pkg.sv",
        ibex_root / "rtl" / "ibex_top_tracing.sv",
        lowrisc_root / "ip" / "tlul" / "rtl" / "tlul_pkg.sv",
        uart_root / "rtl" / "uart.sv",
        autogen / "xbar_main.sv",
        context.paths.rtl / "soc.sv",
    )
    for source in sources:
        source.write_text(f"// {source.name}\n", encoding="utf-8")

    include = lowrisc_root / "ip" / "prim" / "rtl" / "prim_assert.svh"
    include.parent.mkdir(parents=True, exist_ok=True)
    include.write_text("// include\n", encoding="utf-8")

    requests = []

    class Runner:
        def run(self, request, *, on="local"):
            requests.append(request)
            modules, includes = request.outputs
            modules.parent.mkdir(parents=True, exist_ok=True)
            modules.write_text(
                "\n".join(str(source) for source in sources) + "\n",
                encoding="utf-8",
            )
            includes.write_text(str(include) + "\n", encoding="utf-8")
            return CommandResult(0, request.log, 0.0)

    flow = SocFlow(context, Runner())
    output = flow.write_native_rtl_filelist(_plan(), on="fixture")

    assert len(requests) == 1
    argv = requests[0].argv
    assert argv[0] == "slang-test"
    assert argv[1:3] == ("--top", "soc")
    assert str(context.paths.rtl / "soc.sv") == argv[-1]
    assert str((ibex_root / "...").resolve()) in argv
    assert str((lowrisc_root / "...").resolve()) in argv
    assert str((context.paths.run / "ips" / "...").resolve()) in argv

    lines = output.read_text(encoding="utf-8").splitlines()
    assert "+incdir+" + include.parent.resolve().as_posix() in lines
    assert (context.paths.rtl / "soc.sv").resolve().relative_to(
        context.paths.run.resolve()
    ).as_posix() in lines
    assert (context.paths.rtl / "autogen" / "xbar_main.sv").resolve().relative_to(
        context.paths.run.resolve()
    ).as_posix() in lines
    assert (uart_root / "rtl" / "uart.sv").resolve().relative_to(
        context.paths.run.resolve()
    ).as_posix() in lines
    assert (ibex_root / "rtl" / "ibex_top_tracing.sv").resolve().as_posix() in lines
    assert (lowrisc_root / "ip" / "tlul" / "rtl" / "tlul_pkg.sv").resolve().as_posix() in lines


def test_native_soc_rtl_filelist_requires_pinned_vendor_roots(tmp_path: Path) -> None:
    context = _context(tmp_path)
    context.paths.rtl.mkdir(parents=True, exist_ok=True)
    (context.paths.rtl / "soc.sv").write_text("module soc; endmodule\n", encoding="utf-8")

    flow = SocFlow(context)

    with pytest.raises(FileNotFoundError, match="lowRISC IP vendor tree"):
        flow.write_native_rtl_filelist(_plan(), on="fixture")


def test_soc_source_resolution_has_no_fusesoc_dependency() -> None:
    from pathlib import Path
    import flexsoc.backend.design.soc.soc as soc_module

    source = Path(soc_module.__file__).read_text(encoding="utf-8")
    start = source.index("def write_native_rtl_filelist")
    end = source.index("\n    def ", start + 10)
    method = source[start:end]

    assert "RtlFlow.run_flist" in method
    assert "fusesoc" not in method.lower()
    assert 'top="soc"' in method
