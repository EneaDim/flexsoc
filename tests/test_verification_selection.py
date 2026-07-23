"""Minimal checks for generated verification test selection."""

from __future__ import annotations

from flexsoc.backend.setup_tb import TEST_NAMES, render_data_in, render_sv_test_selector, render_sv_vec_driver


def test_sv_test_selector_supports_name_index_and_path_overrides() -> None:
    """The generated TB can pick tests without hardcoded smoke file paths."""
    sv = render_sv_test_selector()

    assert tuple(TEST_NAMES) == ("smoke", "corners", "random")
    assert "TEST_ID=%d" in sv
    assert "TEST_NAME=%s" in sv
    assert "cfg_path      = {\"tests/\", test_name, \"/config.regs\"};" in sv
    assert "tests/smoke/config.regs" not in sv


def test_vector_driver_accepts_mid_sim_config_change() -> None:
    """data_in.vec can request a config file at a simulation cycle."""
    sv = render_sv_vec_driver("test", "clk_i", ["data_i"], ["data_o"])

    assert 'n0 == "@cfg"' in sv
    assert "run_reg_config(cfg_path)" in sv
    assert "tb_wait_cycle(cycle, now_cycle, data_out_path)" in sv


def test_data_in_template_documents_config_changes() -> None:
    """Generated vectors explain how to reconfigure during simulation."""
    text = render_data_in("test", "smoke")

    assert "@cfg <PATH_TO_CONFIG.REGS>" in text
