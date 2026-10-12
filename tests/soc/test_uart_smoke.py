from __future__ import annotations

import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FIXTURE = ROOT / "tests/fixtures/soc/uart"
UART_TEST = FIXTURE / "tests/uart_smoke"


def test_uart_smoke_is_workspace_owned_and_cpu_driven(tmp_path: Path) -> None:
    from flexsoc.backend.core import BackendContext, CommandResult
    from flexsoc.backend.design.soc.soc import SocFlow

    project = tmp_path / "project"
    for name in ("lowrisc_ibex", "lowrisc_ip"):
        (project / "vendor" / name).mkdir(parents=True)
    context = BackendContext(
        project,
        tmp_path / "work",
        {
            "TOP": "test", "RUN_TOP": "test", "RUN_ID": "dev",
            "HOST": "ibex", "FABRIC": "tlul", "TEST_NAME": "uart_smoke",
        },
    )
    context.paths.ensure()
    shutil.copytree(FIXTURE, context.paths.tests.parent, dirs_exist_ok=True)
    shutil.copytree(ROOT / "hw/ips/uart/1.0.0/interfaces/tlul", context.paths.run / "ips/uart")

    class Runner:
        def run(self, request, *, on="local"):
            if request.argv[0] == "make":
                elf, binary = request.outputs
                elf.parent.mkdir(parents=True, exist_ok=True)
                elf.write_bytes(b"ELF-fixture")
                binary.write_bytes(bytes.fromhex("1300000093001000"))
            return CommandResult(0, request.log, 0.0)

    (context.paths.rtl / "soc.sv").write_text(
        "module soc #(parameter string SramInitFile=\"\") (input logic clk_i, input logic rst_ni, output logic tx_o); endmodule\n",
        encoding="utf-8",
    )
    flow = SocFlow(context, Runner())
    plan = flow.resolve_plan()
    flow.software.generate_memory_map(plan)
    flow.software.build("uart_smoke")
    flow.dv.generate(plan)

    tb = (context.paths.tb / "sv/soc_tb.sv").read_text(encoding="utf-8")
    assert 'SramInitFile("' in tb
    assert "flexsoc_event_sequence" in tb
    assert "u_dut.sram_data_req" in tb
    assert "tb_wait_event" in tb
    assert "tb_wait_signal" in tb
    assert "uart_frame_byte" not in tb
    assert (context.paths.tests / "uart_smoke/sw/build/main.vmem").is_file()


def test_soc_backend_has_no_named_functional_test_knowledge() -> None:
    import flexsoc.backend.design.soc.soc as soc_module

    source = Path(soc_module.__file__).read_text(encoding="utf-8")
    assert "uart_smoke" not in source
    assert "boot_smoke" not in source
    assert not (ROOT / "src/flexsoc/templates/design/soc/dv").exists()
    assert (FIXTURE / "model/tests.py").is_file()
    assert (UART_TEST / "sw/main.c").is_file()
    assert not (UART_TEST / "tb").exists()


def test_uart_fixture_uses_cpu_mmio_not_config_transport() -> None:
    config = (UART_TEST / "config.regs").read_text(encoding="utf-8")
    main = (UART_TEST / "sw/main.c").read_text(encoding="utf-8")
    assert "no direct register transport" not in config.lower() or "CPU-driven" in config
    assert "SOC_UART_BASE_ADDR" in main
    assert "uart_init(uart)" in main
    assert "uart_in(uart)" in main
    assert "uart_out(uart" in main
    assert "TEST_READY_RX" in main


def test_soc_dv_requires_workspace_test_only_for_simulation_contract(tmp_path: Path) -> None:
    from flexsoc.backend.core import BackendContext
    from flexsoc.backend.design.soc.soc import SocFlow

    context = BackendContext(
        tmp_path / "project", tmp_path / "work",
        {"TOP": "test", "RUN_TOP": "test", "RUN_ID": "dev", "HOST": "ibex", "FABRIC": "tlul"},
    )
    context.paths.ensure()
    (context.paths.rtl / "soc.sv").write_text(
        "module soc(input logic clk_i, input logic rst_ni); endmodule\n", encoding="utf-8"
    )
    flow = SocFlow(context)
    flow.dv.generate(flow.resolve_plan())
    assert not any(context.paths.tests.iterdir())

    try:
        flow.dv.validate("uart_smoke")
    except FileNotFoundError as exc:
        assert "functional test 'uart_smoke' is incomplete" in str(exc)
    else:
        raise AssertionError("missing workspace test must fail validation")


def test_uart_fixture_generator_uses_ip_model_and_firmware_event(tmp_path: Path) -> None:
    import shutil

    from flexsoc.backend.core import BackendContext
    from flexsoc.backend.dv.func.functional import FunctionalFlow

    context = BackendContext(
        tmp_path / "project", tmp_path / "work",
        {"TOP": "soc", "RUN_TOP": "soc", "RUN_ID": "dev"},
    )
    context.paths.ensure()
    shutil.copytree(FIXTURE, context.paths.tests.parent, dirs_exist_ok=True)
    shutil.copytree(
        ROOT / "hw/ips/uart/1.0.0/interfaces/tlul",
        context.paths.run / "ips/uart",
    )

    flow = FunctionalFlow()
    flow.setup_test("uart_smoke", context.paths.tests, "soc")
    generated = context.paths.tests / "uart_smoke"
    data_in = (generated / "data_in.vec").read_text(encoding="utf-8")
    data_out = (generated / "data_out.vec").read_text(encoding="utf-8")
    assert "@wait_event READY_RX 0x52584459" in data_in
    assert "32 rx_i 0x00000000" in data_in
    assert "@wait_event READY_TX 0x54584459" in data_out
    assert "@wait_signal tx_o 0x00000000" in data_out
    assert "48 tx_o" in data_out
    assert "@wait_event PASS 0x55415254" in data_out
    assert flow.check_tests(context.paths.tests, "soc")["ok"] is True


def test_shared_vector_engines_support_common_event_and_signal_barriers() -> None:
    from flexsoc.backend.core import ClockConfig
    from flexsoc.backend.dv.tb.cocotb import CocotbTestbench
    from flexsoc.backend.dv.tb.sv import SystemVerilogTestbench

    clocks = ClockConfig.from_values()
    signature = {
        "ports_in": [("clk_i", 1), ("rst_ni", 1), ("rx_i", 1)],
        "ports_out": [("tx_o", 1)],
    }
    sv_driver = SystemVerilogTestbench.render_vec_driver("soc", clocks, signature, "tlul")
    sv_monitor = SystemVerilogTestbench.render_vec_monitor("soc", clocks, signature, "tlul")
    py_driver = CocotbTestbench.render_vec_driver(clocks, signature)
    py_monitor = CocotbTestbench.render_vec_monitor(clocks, signature)
    for rendered in (sv_driver, sv_monitor, py_driver, py_monitor):
        assert "@wait_event" in rendered or "WAIT_EVENT_TOKENS" in rendered
        assert "@wait_signal" in rendered or "WAIT_SIGNAL_TOKENS" in rendered
    assert "run_output_vectors(output_path)" in sv_driver
    assert "CycleMonitor" in py_driver
