"""Focused regression tests for C driver generation."""

from pathlib import Path

import pytest

from flexsoc.backend.design.regs import RegsFlow


ROOT = Path(__file__).resolve().parents[1]


def test_driver_materializes_header_and_uart_master_namespace(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    """Generate the regtool header before adding FlexSoC driver declarations."""

    hjson = tmp_path / "uart_master.hjson"
    hjson.write_text('{ name: "uart_master" }\n', encoding="utf-8")
    output = tmp_path / "drivers"
    flow = RegsFlow(project_root=ROOT)

    def fake_regtool(argv, *, cwd, log, on="local"):
        assert argv[0] == "--cdefines"
        assert argv[1] == "-o"
        Path(argv[2]).write_text(
            "#ifndef _UART_MASTER_REG_DEFS_\n"
            "#define _UART_MASTER_REG_DEFS_\n"
            "#define UART_MASTER_CTRL_REG_OFFSET 0x0\n"
            "#define UART_MASTER_STATUS_REG_OFFSET 0x4\n"
            "#define UART_MASTER_STATUS_RXEMPTY_BIT 5\n"
            "#define UART_MASTER_STATUS_TXFULL_BIT 0\n"
            "#define UART_MASTER_RDATA_REG_OFFSET 0x8\n"
            "#define UART_MASTER_WDATA_REG_OFFSET 0xc\n"
            "#ifdef __cplusplus\n"
            'extern "C" {\n'
            "#endif\n",
            encoding="utf-8",
        )
        return 0

    monkeypatch.setattr(flow, "_run_regtool", fake_regtool)
    header, source = flow.generate_driver(
        hjson,
        output,
        base_address="0x40000000",
    )

    header_text = header.read_text(encoding="utf-8")
    source_text = source.read_text(encoding="utf-8")
    assert "#define UART_MASTER_BASE 0x40000000" in header_text
    assert "typedef uintptr_t uart_master_t;" in header_text
    assert "UART_MASTER_CTRL_REG_OFFSET" in source_text
    assert "UART_MASTER_STATUS_RXEMPTY_BIT" in source_text
    assert "UART_MASTER_WDATA_REG_OFFSET" in source_text
    assert "UART_CTRL_REG_OFFSET" not in source_text
