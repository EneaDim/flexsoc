from __future__ import annotations

import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def test_uart_smoke_is_cpu_mmio_and_pin_observed(tmp_path: Path) -> None:
    from flexsoc.backend.core import BackendContext, CommandResult
    from flexsoc.backend.design.soc.soc import SocFlow

    project = tmp_path / "project"
    for name in ("lowrisc_ibex", "lowrisc_ip"):
        (project / "vendor" / name).mkdir(parents=True)
    context = BackendContext(
        project,
        tmp_path / "work",
        {
            "TOP": "test",
            "RUN_TOP": "test",
            "RUN_ID": "dev",
            "HOST": "ibex",
            "FABRIC": "tlul",
            "TEST_NAME": "uart_smoke",
        },
    )
    context.paths.ensure()
    shutil.copytree(
        ROOT / "hw/ips/uart/1.0.0/interfaces/tlul",
        context.paths.run / "ips" / "uart",
    )

    class Runner:
        def run(self, request, *, on="local"):
            if request.argv[0] == sys.executable:
                for output in request.outputs:
                    output.parent.mkdir(parents=True, exist_ok=True)
                    output.write_text("// tlgen fixture\n", encoding="utf-8")
            elif request.argv[0] == "make":
                elf, binary = request.outputs
                elf.parent.mkdir(parents=True, exist_ok=True)
                elf.write_bytes(b"ELF-fixture")
                binary.write_bytes(bytes.fromhex("13000000 93001000".replace(" ", "")))
            return CommandResult(0, request.log, 0.0)

    flow = SocFlow(context, Runner())
    flow.generate()
    flow.software.build_uart_smoke(flow.resolve_plan())

    main = (context.paths.tests / "uart_smoke/sw/main.c").read_text(encoding="utf-8")
    assert '#include "soc_memory_map.h"' in main
    assert '#include "uart.h"' in main
    assert "SOC_UART_BASE_ADDR" in main
    assert "#define UART_BASE" not in main
    assert "UART_CTRL_REG_OFFSET" not in main
    assert "UART_STATUS_REG_OFFSET" not in main
    assert "UART_WDATA_REG_OFFSET" not in main
    assert "0x55415254u" in main

    tb = (context.paths.tb / "sv/soc_tb.sv").read_text(encoding="utf-8")
    assert "@(negedge tx_o);" in tb
    assert "repeat (48) @(posedge clk_i);" in tb
    assert "repeat (32) @(posedge clk_i);" in tb
    assert 'uart_frame_byte !== 8\'h55' in tb
    assert "[TB][UART] PASS byte=" in tb
    assert "[TB][UARTFW] PASS entry=" in tb
    assert "32'h55415254" in tb

    vectors = (context.paths.tests / "uart_smoke/data_in.vec").read_text(encoding="utf-8")
    assert "1024 @wait 0" in vectors
    assert (context.paths.tests / "uart_smoke/sw/build/main.vmem").is_file()

def test_uart_smoke_reset_uses_canonical_cycle_directive() -> None:
    template = ROOT / "src/flexsoc/templates/design/soc/dv/uart_smoke/data_in.vec.j2"
    active = [
        line.strip()
        for line in template.read_text(encoding="utf-8").splitlines()
        if line.strip() and not line.lstrip().startswith("#")
    ]
    reset = [line for line in active if "@reset" in line]
    assert reset == ["0 @reset all 4"]
    assert not any(line.startswith("@reset") for line in active)

def test_uart_smoke_uses_soc_memory_map_and_staged_driver() -> None:
    from flexsoc.backend.design.soc.soc import SoCDevice, SoCPlan, SoCSoftware

    plan = SoCPlan(
        "ibex", "tlul",
        (
            SoCDevice("sram", 0x00100000, 0x00020000, True),
            SoCDevice("uart", 0x80000000, 0x00001000, False),
        ),
    )
    header = SoCSoftware.render_memory_map(plan)
    assert "#define SOC_SRAM_BASE_ADDR UINT32_C(0x00100000)" in header
    assert "#define SOC_UART_BASE_ADDR UINT32_C(0x80000000)" in header

    template = (
        ROOT / "src/flexsoc/templates/design/soc/dv/uart_smoke/main.c.j2"
    ).read_text(encoding="utf-8")
    assert '#include "soc_memory_map.h"' in template
    assert '#include "uart.h"' in template
    assert "SOC_UART_BASE_ADDR" in template
    assert "uart_init(uart)" in template
    assert "uart_out(uart" in template
    assert "UART_CTRL_REG_OFFSET" not in template
    assert "UART_STATUS_REG_OFFSET" not in template
    assert "UART_WDATA_REG_OFFSET" not in template

    makefile = (
        ROOT / "src/flexsoc/templates/design/soc/dv/uart_smoke/Makefile.j2"
    ).read_text(encoding="utf-8")
    assert "$(UART_DRIVER_DIR)/uart.c" in makefile
    assert "-I$(SOC_INCLUDE_DIR)" in makefile
    assert "-I$(UART_DRIVER_DIR)" in makefile
