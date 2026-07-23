"""Minimal RTL-stub checks for reggen CSR path rules."""

from __future__ import annotations

from flexsoc.backend.rtl_stub_gen import render_core


HJSON = {
    "name": "test",
    "registers": [
        {
            "name": "CTRL",
            "swaccess": "rw",
            "hwaccess": "hro",
            "fields": [{"bits": "0", "name": "EN"}, {"bits": "1", "name": "CLR"}],
        },
        {
            "name": "OPERAND_A",
            "swaccess": "rw",
            "hwaccess": "hro",
            "fields": [{"bits": "31:0", "name": "VALUE"}],
        },
        {
            "name": "SCALE",
            "swaccess": "rw",
            "hwaccess": "hro",
            "fields": [{"bits": "7:0", "name": "VALUE"}],
        },
        {
            "name": "STATUS",
            "swaccess": "ro",
            "hwaccess": "hrw",
            "hwext": "true",
            "fields": [{"bits": "0", "name": "BUSY"}, {"bits": "1", "name": "DONE"}],
        },
        {
            "name": "RESULT",
            "swaccess": "ro",
            "hwaccess": "hrw",
            "hwext": "true",
            "fields": [{"bits": "31:0", "name": "VALUE"}],
        },
    ],
}


def test_rtl_stub_uses_flat_paths_for_single_field_registers() -> None:
    """Single-field registers are flat in reggen structs."""

    core = render_core(HJSON)

    assert "reg2hw.operand_a.q" in core
    assert "reg2hw.scale.q" in core
    assert "hw2reg.result.d" in core
    assert "reg2hw.operand_a.value.q" not in core
    assert "hw2reg.result.value.d" not in core
    assert "reg2hw.ctrl.en.q" in core
    assert "hw2reg.status.done.d" in core
