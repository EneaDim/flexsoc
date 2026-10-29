"""rtl_stub owns only the core; top_from_core owns all integration wrappers."""

from pathlib import Path

import pytest

from flexsoc.backend.core import ClockConfig
from flexsoc.backend.design.ip.rtl import RtlFlow


@pytest.mark.parametrize("multiclock", (False, True))
def test_scaffold_creates_core_only_and_top_is_explicit(tmp_path: Path, multiclock: bool) -> None:
    top = "demo"
    rtl = tmp_path / "rtl"
    rtl.mkdir()
    cfg = ClockConfig.from_values({
        "N_CLOCKS": "3" if multiclock else "1",
        "CLOCK_DOMAINS": (
            "cfg:cfg_clk_i:cfg_rst_ni:20:low,rx:rx_clk_i:rx_rst_ni:16:low,"
            "dsp:dsp_clk_i:dsp_rst_ni:30:low"
            if multiclock else "core:clk_i:rst_ni:10:low"
        ),
    })
    hjson = tmp_path / "demo.hjson"
    if not multiclock:
        hjson.write_text('{"name": "demo", "registers": []}\n', encoding="utf-8")
    flow = RtlFlow(tmp_path)
    result = flow.init_scaffold(
        None if multiclock else hjson, "axi_lite", rtl, top=top, clocks=cfg,
    )
    core = rtl / "demo_core.sv"
    assert result == core
    assert core.is_file()
    assert sorted(file.name for file in rtl.iterdir()) == ["demo_core.sv"]

    # Repeating the scaffold is forbidden without an explicit overwrite.
    with pytest.raises(FileExistsError):
        flow.init_scaffold(
            None if multiclock else hjson, "axi_lite", rtl, top=top, clocks=cfg,
        )
    assert sorted(file.name for file in rtl.iterdir()) == ["demo_core.sv"]

    wrapper = flow.setup_top(top, rtl, "axi_lite", clocks=cfg)
    assert wrapper == rtl / "demo.sv"
    assert wrapper.is_file()
    assert "demo_core " in wrapper.read_text(encoding="utf-8")
    assert any(file.name.endswith("_reg_top.sv") for file in rtl.iterdir())

    before = {file.name: file.read_bytes() for file in rtl.iterdir()}
    # Regenerating the core alone with --force must not regenerate the wrapper.
    flow.init_scaffold(
        None if multiclock else hjson, "axi_lite", rtl, top=top, force=True, clocks=cfg,
    )
    assert {file.name: file.read_bytes() for file in rtl.iterdir()} == before
