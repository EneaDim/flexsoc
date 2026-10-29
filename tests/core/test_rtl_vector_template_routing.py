"""RTL vector templates are DV-owned without changing generated collateral.

The SHA-256 values protect the emitted Python vector generators.
The single-clock digest intentionally changes in Fix 025 (guarded runtime CSR
scenario); the multi-clock digest remains byte-identical to Fix 024.
"""

from __future__ import annotations

import hashlib
from importlib.resources import files
from pathlib import Path

import pytest

from flexsoc.backend.core import ClockConfig
from flexsoc.backend.design.ip.model import ModelFlow

TEMPLATE_ROOT = files("flexsoc").joinpath("templates")
EXPECTED_DEMO_SHA256 = {
    "single": "5e365ea276902c609474e8acefd031bf0c3847ab92eb7de99956d37ec24ec43c",
    "multi": "0c39147070797703b9429168c4e906a1321c0de9b59128fcab3fde29796a56b3",
}


@pytest.mark.parametrize("protocol", ["axi_lite", "tlul", "reg_iface"])
@pytest.mark.parametrize("topology", ["single", "multi"])
def test_model_backend_renders_dv_owned_vector_sources_unchanged(
    tmp_path: Path, protocol: str, topology: str,
) -> None:
    # REG_ITF is a transport selection. The scenario generator must remain
    # transport-neutral, while producing the same py/rtl output for tests_gen.
    settings = {"N_CLOCKS": "1", "REG_ITF": protocol}
    if topology == "multi":
        settings.update({
            "N_CLOCKS": "3",
            "CLOCK_DOMAINS": (
                "cfg:cfg_clk_i:cfg_rst_ni:20:low,"
                "rx:rx_clk_i:rx_rst_ni:16:low,"
                "dsp:dsp_clk_i:dsp_rst_ni:30:low"
            ),
        })
    clocks = ClockConfig.from_values(settings)
    output = tmp_path / "dv" / "functional" / "py" / "rtl"
    generated = ModelFlow(tmp_path).init_model_tests("demo", output, clocks=clocks)

    assert generated == output / "demo_tests.py"
    expected_hash = EXPECTED_DEMO_SHA256[topology]
    assert hashlib.sha256(generated.read_bytes()).hexdigest() == expected_hash
    assert "from scenarios import SCENARIOS" in generated.read_text(encoding="utf-8")
    assert not (output.parent / "model" / "demo_tests.py").exists()

    # Existing authored generators must survive repeated model setup.
    generated.write_text(generated.read_text() + "\n# authored change\n", encoding="utf-8")
    ModelFlow(tmp_path).init_model_tests("demo", output, clocks=clocks)
    assert generated.read_text().endswith("# authored change\n")


@pytest.mark.parametrize("filename", ["vectors_cycle.py.j2", "vectors_stream.py.j2"])
def test_source_template_is_packaged_under_functional_dv(filename: str) -> None:
    assert TEMPLATE_ROOT.joinpath("dv", "functional", "tests", filename).is_file()


def test_legacy_model_template_paths_are_not_required() -> None:
    assert not TEMPLATE_ROOT.joinpath("design", "model", "tests.py.j2").is_file()
    assert not TEMPLATE_ROOT.joinpath("design", "model", "nclock_tests.py.j2").is_file()
