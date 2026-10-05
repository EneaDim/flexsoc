from flexsoc.backend.design.soc.soc import (
    SRAM_BASE,
    SRAM_SIZE,
    SoCDevice,
    SoCPlan,
    SoCTestMemoryLayout,
)


def test_soc_test_memory_layout_contract() -> None:
    plan = SoCPlan(
        host="ibex",
        fabric="tlul",
        devices=(SoCDevice("sram", SRAM_BASE, SRAM_SIZE, True),),
    )
    layout = SoCTestMemoryLayout.from_plan(plan)

    assert layout.ram_size == 0x0001EFFC
    assert layout.status_addr == 0x0011EFFC
    assert layout.stack_addr == 0x0011F000
    assert layout.status_word == 0x7BFF
    assert layout.status_word_width == 15


def test_soc_signature_consumers_use_memory_layout() -> None:
    from pathlib import Path
    import flexsoc.backend.design.soc.soc as soc_module

    source = Path(soc_module.__file__).read_text(encoding="utf-8")

    assert "status_addr = layout.status_addr" in source
    assert "status_word = layout.status_word" in source
    assert "status_origin = layout.status_addr" in source
    assert "stack_origin = layout.stack_addr" in source

    assert "sram.base + sram.size - SOC_STACK_SIZE - SOC_TEST_STATUS_SIZE" not in source
    assert "(status_addr - sram.base) // 4" not in source
    assert "status_origin = sram.base + sram.size - reserved" not in source
