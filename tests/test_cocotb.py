"""Focused contracts for generated cocotb scaffold naming."""

from __future__ import annotations

from pathlib import Path

from flexsoc.clocking import ClockConfig, ClockDomain
from flexsoc.backend.post_sim import _cocotb_wrapper
from flexsoc.backend.setup_cocotb import CocotbConfig, write_nclock_cocotb


def test_multiclock_cocotb_uses_canonical_wrapper_name(tmp_path: Path) -> None:
    output = tmp_path / "run" / "dv" / "functional" / "tb" / "cocotb"
    cfg = CocotbConfig(
        top="tri_stream_dsp",
        interface="tlul",
        output=output,
        rtl_dir=tmp_path / "rtl",
    )
    clocks = ClockConfig(
        domains=(
            ClockDomain("cfg", "cfg_clk_i", "cfg_rst_ni", 10.0),
            ClockDomain("rx", "rx_clk_i", "rx_rst_ni", 8.0),
            ClockDomain("dsp", "dsp_clk_i", "dsp_rst_ni", 5.0),
        )
    )

    write_nclock_cocotb(cfg, clocks)

    wrapper = output / "tri_stream_dsp_tb.sv"
    assert wrapper.is_file()
    assert not (output / "tri_stream_dsp_cocotb_tb.sv").exists()
    assert "module tri_stream_dsp_tb;" in wrapper.read_text(encoding="utf-8")

    makefile = (output / "Makefile").read_text(encoding="utf-8")
    assert "COCOTB_TOPLEVEL = tri_stream_dsp_tb" in makefile
    assert "VERILOG_SOURCES += $(PWD)/tri_stream_dsp_tb.sv" in makefile
    assert _cocotb_wrapper(tmp_path / "run", "tri_stream_dsp") == wrapper
