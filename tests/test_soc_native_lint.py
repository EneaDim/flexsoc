from pathlib import Path

from flexsoc.backend.core import BackendContext
from flexsoc.backend.dv.lint.lint import Lint


class Runner:
    pass


def _context(tmp_path: Path) -> BackendContext:
    context = BackendContext(
        tmp_path / "project",
        tmp_path / "work",
        {
            "TOP": "workspace_top",
            "RUN_TOP": "test",
            "RUN_ID": "dev",
            "SLANG": "slang-test",
            "VERILATOR": "verilator-test",
        },
    )
    context.paths.ensure()
    return context


def test_lint_reuses_canonical_ip_reporting_with_native_soc_filelist(tmp_path: Path) -> None:
    context = _context(tmp_path)
    native = context.paths.rtl / "rtl.f"
    native.write_text("rtl/soc.sv\n", encoding="utf-8")
    (context.paths.rtl / "soc.sv").write_text("module soc; endmodule\n", encoding="utf-8")

    lint = Lint(context, Runner())

    slang_diag = context.paths.lint / "slang" / "slang_diag.json"
    verilator_sarif = context.paths.lint / "verilator" / "verilator.sarif"
    slang_cmd = lint.slang._command("everything", slang_diag)
    verilator_cmd = lint.verilator._command("everything", verilator_sarif)

    assert lint._lint_top() == "soc"
    assert slang_cmd[slang_cmd.index("--top") + 1] == "soc"
    assert verilator_cmd[verilator_cmd.index("--top-module") + 1] == "soc"
    assert slang_cmd.count("-f") == 1
    assert verilator_cmd.count("-f") == 1
    assert str(native) in slang_cmd
    assert str(native) in verilator_cmd
    assert str(context.paths.rtl_common) not in slang_cmd
    assert str(context.paths.rtl_ip) not in verilator_cmd


def test_ip_lint_source_contract_is_unchanged_without_native_rtl_f(tmp_path: Path) -> None:
    context = _context(tmp_path)
    context.paths.rtl_common.write_text("rtl/common.sv\n", encoding="utf-8")
    context.paths.rtl_ip.write_text("rtl/ip.sv\n", encoding="utf-8")

    lint = Lint(context, Runner())
    slang_cmd = lint.slang._command(
        "critical", context.paths.lint / "slang" / "slang_diag.json"
    )
    verilator_cmd = lint.verilator._command(
        "critical", context.paths.lint / "verilator" / "verilator.sarif"
    )

    assert lint._lint_top() == context.paths.top
    assert slang_cmd.count("-f") == 2
    assert verilator_cmd.count("-f") == 2
    assert str(context.paths.rtl_common) in slang_cmd
    assert str(context.paths.rtl_ip) in slang_cmd
    assert str(context.paths.rtl_common) in verilator_cmd
    assert str(context.paths.rtl_ip) in verilator_cmd
