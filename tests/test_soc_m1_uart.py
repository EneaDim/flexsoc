from __future__ import annotations

import json
import shutil
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def test_ip_release_carries_fusesoc_integration_contract(tmp_path: Path) -> None:
    from flexsoc.backend.release.package import PackageFlow

    staged = tmp_path / "uart"
    rtl = staged / "rtl"
    rtl.mkdir(parents=True)
    for name in ("uart_reg_pkg.sv", "uart.sv"):
        (rtl / name).write_text(f"module {name.removesuffix('.sv')}(); endmodule\n", encoding="utf-8")
    (rtl / "rtl_ip.f").write_text("rtl/uart_reg_pkg.sv\nrtl/uart.sv\n", encoding="utf-8")

    core = PackageFlow._write_fusesoc_core(staged, "uart", "uart")
    assert core is not None
    text = core.read_text(encoding="utf-8")
    assert 'name: "prj:ip:uart:0.1"' in text
    assert "ips:dependecies:all" not in text
    assert "- rtl/uart_reg_pkg.sv" in text
    assert "- rtl/uart.sv" in text
    assert "toplevel: uart" in text


def test_uart_tlul_release_is_soc_consumable() -> None:
    release = ROOT / "hw" / "ips" / "uart" / "1.0.0" / "interfaces" / "tlul"
    manifest = json.loads((release / "ip.json").read_text(encoding="utf-8"))
    assert manifest["content"]["fusesoc_core"] == "uart.core"
    core = (release / "uart.core").read_text(encoding="utf-8")
    assert 'name: "prj:ip:uart:0.1"' in core
    assert "- rtl/uart.sv" in core


def test_soc_m1_uart_release_projects_into_plan_top_and_core(tmp_path: Path) -> None:
    from flexsoc.backend.core import BackendContext, CommandResult
    from flexsoc.backend.design.soc.soc import SocFlow

    project = tmp_path / "project"
    context = BackendContext(
        project, tmp_path / "work",
        {"TOP": "test", "RUN_TOP": "test", "RUN_ID": "dev", "HOST": "ibex", "FABRIC": "tlul"},
    )
    context.paths.ensure()
    staged = context.paths.run / "ips" / "uart"
    shutil.copytree(ROOT / "hw" / "ips" / "uart" / "1.0.0" / "interfaces" / "tlul", staged)

    class Runner:
        def run(self, request, *, on="local"):
            for output in request.outputs:
                output.parent.mkdir(parents=True, exist_ok=True)
                output.write_text("// tlgen fixture\n", encoding="utf-8")
            return CommandResult(0, request.log, 0.0)

    flow = SocFlow(context, Runner())
    result = flow.generate()
    plan = json.loads(result.read_text(encoding="utf-8"))
    uart = next(device for device in plan["devices"] if device["name"] == "uart")
    assert uart["base"] == "0x80000000"
    assert uart["builtin"] is False

    soc = (context.paths.rtl / "soc.sv").read_text(encoding="utf-8")
    assert "input logic rx_i" in soc
    assert "output logic tx_o" in soc
    assert "uart u_uart" in soc
    assert ".tl_i(tl_uart_h2d)" in soc
    assert ".tl_o(tl_uart_d2h)" in soc
    core = (context.paths.run / "soc.core").read_text(encoding="utf-8")
    assert "- prj:ip:uart" in core


def test_soc_fusesoc_searches_shared_ip_core_root(tmp_path: Path) -> None:
    from flexsoc.backend.core import BackendContext, CommandResult
    from flexsoc.backend.design.soc.soc import SocFlow

    project = tmp_path / "project"
    for name in ("lowrisc_ibex", "lowrisc_ip"):
        (project / "vendor" / name).mkdir(parents=True)
    (project / "hw" / "ips").mkdir(parents=True)
    context = BackendContext(
        project, tmp_path / "work",
        {"TOP": "test", "RUN_TOP": "test", "RUN_ID": "dev", "HOST": "ibex", "FABRIC": "tlul"},
    )
    context.paths.ensure()
    requests = []

    class Runner:
        def run(self, request, *, on="local"):
            requests.append(request)
            return CommandResult(0, request.log, 0.0)

    flow = SocFlow(context, Runner())
    roots = flow.vendor_roots()
    flow.fusesoc_build("lint", context.paths.logs / "soc" / "build.log", (), on="local")
    argv = requests[0].argv
    pairs = list(zip(argv, argv[1:]))
    assert ("--cores-root", str(project / "hw" / "ips")) not in pairs
    assert ("--cores-root", str(roots[0])) in pairs
    assert ("--cores-root", str(roots[1])) in pairs
