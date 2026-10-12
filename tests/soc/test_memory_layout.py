from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def test_test_memory_layout_is_fixture_owned() -> None:
    linker = (ROOT / "tests/fixtures/soc/uart_smoke/sw/link.ld").read_text(encoding="utf-8")
    assert "ORIGIN = 0x00100000" in linker
    assert "ORIGIN = 0x0011EFFC" in linker
    assert "ORIGIN = 0x0011F000" in linker


def test_soc_backend_does_not_own_test_memory_policy() -> None:
    import flexsoc.backend.design.soc.soc as soc_module

    source = Path(soc_module.__file__).read_text(encoding="utf-8")
    assert "SoCTestMemoryLayout" not in source
    assert "SOC_TEST_STATUS_SIZE" not in source
    assert "SOC_STACK_SIZE" not in source
    assert "SOC_UART_PASS_MAGIC" not in source
