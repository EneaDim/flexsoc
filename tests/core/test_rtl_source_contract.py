from pathlib import Path

import pytest

from flexsoc.backend.core import BackendContext


def _context(tmp_path: Path) -> BackendContext:
    context = BackendContext(
        tmp_path / "project",
        tmp_path / "work",
        {"TOP": "uart", "RUN_TOP": "uart", "RUN_ID": "dev"},
    )
    context.paths.ensure()
    return context


def test_ip_source_contract_uses_split_filelists_and_run_root(tmp_path: Path) -> None:
    context = _context(tmp_path)
    context.paths.rtl_common.write_text("rtl/common.sv\n", encoding="utf-8")
    context.paths.rtl_ip.write_text("rtl/uart.sv\n", encoding="utf-8")
    (context.paths.rtl / "common.sv").write_text("module common; endmodule\n", encoding="utf-8")
    (context.paths.rtl / "uart.sv").write_text("module uart; endmodule\n", encoding="utf-8")
    (context.paths.rtl / "rtl.f").write_text("rtl/stale_soc.sv\n", encoding="utf-8")

    contract = context.rtl_contract.require()

    assert contract.design == "ip"
    assert contract.top == "uart"
    assert contract.root == context.paths.run
    assert contract.filelists == (context.paths.rtl_common, context.paths.rtl_ip)
    assert contract.sources() == (
        (context.paths.run / "rtl/common.sv").resolve(),
        (context.paths.run / "rtl/uart.sv").resolve(),
    )


def test_soc_source_contract_is_selected_by_plan_not_stale_files(tmp_path: Path) -> None:
    context = _context(tmp_path)
    plan = context.paths.run / "soc" / "plan.json"
    plan.parent.mkdir(parents=True)
    plan.write_text(
        '{"schema": 1, "host": "ibex", "fabric": "tlul", "devices": []}\n',
        encoding="utf-8",
    )
    context.paths.rtl_common.write_text("rtl/old_common.sv\n", encoding="utf-8")
    context.paths.rtl_ip.write_text("rtl/old_ip.sv\n", encoding="utf-8")

    contract = context.rtl_contract

    assert contract.design == "soc"
    assert contract.top == "soc"
    assert contract.root == context.paths.run
    assert contract.filelists == (context.paths.rtl / "rtl.f",)
    with pytest.raises(FileNotFoundError, match="missing soc RTL filelist"):
        contract.require()


def test_soc_source_contract_resolves_native_entries_from_run_root(tmp_path: Path) -> None:
    context = _context(tmp_path)
    plan = context.paths.run / "soc" / "plan.json"
    plan.parent.mkdir(parents=True)
    plan.write_text(
        '{"schema": 1, "host": "ibex", "fabric": "tlul", "devices": []}\n',
        encoding="utf-8",
    )
    native = context.paths.rtl / "rtl.f"
    native.write_text("+define+RVFI\nrtl/soc.sv\n", encoding="utf-8")
    (context.paths.rtl / "soc.sv").write_text("module soc; endmodule\n", encoding="utf-8")

    contract = context.rtl_contract.require()

    assert contract.sources() == ((context.paths.run / "rtl/soc.sv").resolve(),)
