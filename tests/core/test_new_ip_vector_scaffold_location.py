"""New IP model setup puts executable RTL vectors in py/rtl, for both clock modes."""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path

import pytest

from flexsoc.backend.core import ClockConfig
from flexsoc.backend.design.ip.model import ModelFlow
from flexsoc.backend.design.ip.regs import RegsFlow
from flexsoc.backend.dv.func.functional import FunctionalFlow


@pytest.mark.parametrize(
    "clocks",
    [
        ClockConfig.from_values({"N_CLOCKS": "1"}),
        ClockConfig.from_values({
            "N_CLOCKS": "3",
            "CLOCK_DOMAINS": "cfg:cfg_clk_i:cfg_rst_ni:10,rx:rx_clk_i:rx_rst_ni:12,dsp:dsp_clk_i:dsp_rst_ni:8",
        }),
    ],
    ids=["single-clock", "multi-clock"],
)
def test_model_setup_places_rtl_generator_with_regmap(tmp_path: Path, clocks: ClockConfig, monkeypatch: pytest.MonkeyPatch) -> None:
    csr = tmp_path / "csr"
    model = tmp_path / "dv/functional/py/model"
    rtl = tmp_path / "dv/functional/py/rtl"
    out = tmp_path / "dv/functional/tests"
    # Use a tiny register API fixture: vendored OpenTitan reggen is not
    # required to verify the model/RTL generator layout contract.
    def fake_regmap(top: str, data_dir: Path, output: Path, *, force: bool = False) -> Path:
        output.mkdir(parents=True, exist_ok=True)
        file = output / f"{top}_regmap.py"
        file.write_text('''from pathlib import Path
class Register:
    def write(self, **fields): return "write"
    def vector_write(self, step, value, mask=None): return f"{step} @write"
    def vector_read(self, step, value, mask=None): return f"{step} @read"
class Domain:
    writable = ()
    def __getattr__(self, name): return Register()
    def __iter__(self): return iter(())
    def has(self, name): return False
PRIMARY = Domain()
DOMAINS = {"cfg": Domain(), "dsp": Domain()}
def domain(name): return DOMAINS[name]
def write_config(path, rows): Path(path).write_text("\\n".join(rows) + "\\n")
''', encoding="utf-8")
        return file

    monkeypatch.setattr(RegsFlow, "generate", staticmethod(fake_regmap))

    regmap, reference, tests, regmap_tests = ModelFlow(tmp_path).setup(
        "demo", csr, model, force=False, clocks=clocks, regmap_output=rtl,
    )

    assert tests == rtl / "demo_tests.py"
    assert regmap == rtl / "demo_regmap.py"
    assert regmap_tests == rtl / "demo_regmap_tests.py"
    assert reference == model / "demo_model.py"
    assert (model / "scenarios.py").is_file()
    assert (model / "demo_model_tests.py").is_file()
    assert not (model / "demo_tests.py").exists()

    result = subprocess.run(
        [sys.executable, str(tests), "--tests-dir", str(out)],
        cwd=rtl, capture_output=True, text=True, check=False,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    assert (out / "smoke" / "config.regs").is_file()
    assert (out / "smoke" / "data_in.vec").is_file()
    assert (out / "smoke" / "data_out.vec").is_file()

    # Exercise the same backend that `fx tests_gen` uses, including the
    # machine-owned register vectors and generation freshness comparison.
    FunctionalFlow().setup_tests(out, "demo")
    assert (out / "auto_toggle" / "data_in.vec").is_file()
    assert FunctionalFlow().check_tests(out, "demo")["ok"]

    # Re-running setup must not destroy edits to the authored RTL test catalogue.
    tests.write_text(tests.read_text(encoding="utf-8") + "\n# user customization\n", encoding="utf-8")
    ModelFlow(tmp_path).setup("demo", csr, model, force=False, clocks=clocks, regmap_output=rtl)
    assert tests.read_text(encoding="utf-8").endswith("# user customization\n")
