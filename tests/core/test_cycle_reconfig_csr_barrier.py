"""Guard the generated cycle-vector reconfiguration scenario.

These are catalogue/backend contract checks, not RTL simulator signoff.
The transport is intentionally chosen outside the scenario generator; it
must keep emitting protocol-independent vectors for all register interfaces.
"""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path

import pytest

from flexsoc.backend.core import ClockConfig
from flexsoc.backend.design.ip.model import ModelFlow
from flexsoc.backend.dv.tb.cocotb import CocotbTestbench
from flexsoc.backend.dv.tb.sv import SystemVerilogTestbench


@pytest.mark.parametrize("interface", ["axi_lite", "tlul", "reg_iface"])
def test_runtime_csr_write_completes_before_guarded_functional_check(
    tmp_path: Path, interface: str,
) -> None:
    """Real generated Python executes and produces compatible vector syntax."""

    py = tmp_path / "dv/functional/py"
    model_dir = py / "model"
    rtl_dir = py / "rtl"
    model_dir.mkdir(parents=True)
    rtl_dir.mkdir(parents=True)
    (model_dir / "demo_model.py").write_text('''INPUTS = ("data_i", "coeff_i", "valid_i")
OUTPUTS = ("data_o", "valid_o")
LATENCY = 2
class ReferenceModel:
    def compute(self, inputs):
        return {"data_o": inputs["data_i"] + inputs["coeff_i"],
                "valid_o": inputs["valid_i"]}
''', encoding="utf-8")
    (model_dir / "scenarios.py").write_text('''from dataclasses import dataclass
@dataclass(frozen=True)
class Scenario:
    id: str
SCENARIOS = tuple(Scenario(name) for name in
    ("smoke", "corners", "random_seed_1", "random_seed_2", "reconfig"))
''', encoding="utf-8")
    (rtl_dir / "demo_regmap.py").write_text('''from pathlib import Path
class Field:
    swaccess = "rw"
    hwaccess = "hro"
    mask = 0xF
class Register:
    name = "MODE"
    reset = 0
    fields = (Field(),)
    def vector_write(self, cycle, value, mask=None):
        return f"{cycle} @write clk_i.MODE 0x{value:08x} 0x{mask:08x}"
    def vector_read(self, cycle, value, mask=None):
        return f"{cycle} @read clk_i.MODE 0x{value:08x} 0x{mask:08x}"
    def write(self, value, mask=None):
        return f"clk_i.MODE 0x{value:08x} 0x{mask:08x}"
class Domain:
    def __iter__(self): return iter((Register(),))
    def has(self, name): return False
PRIMARY = Domain()
def write_config(path, rows):
    Path(path).write_text("\\n".join(rows) + "\\n", encoding="utf-8")
''', encoding="utf-8")

    path = ModelFlow(tmp_path).init_model_tests(
        "demo", rtl_dir, clocks=ClockConfig.from_values({"N_CLOCKS": "1", "REG_ITF": interface})
    )
    vector_root = tmp_path / "tests"
    result = subprocess.run(
        [sys.executable, str(path), "--tests-dir", str(vector_root)],
        cwd=rtl_dir, capture_output=True, text=True, check=False,
    )
    assert result.returncode == 0, (result.stdout, result.stderr)

    generated_in = (vector_root / "reconfig/data_in.vec").read_text(encoding="utf-8")
    generated_out = (vector_root / "reconfig/data_out.vec").read_text(encoding="utf-8")
    inputs = [line for line in generated_in.splitlines() if line and not line.startswith("#")]
    outputs = [line for line in generated_out.splitlines() if line and not line.startswith("#")]
    assert inputs == [
        "8 @write clk_i.MODE 0x00000000 0x0000000f",
        "20 data_i 0x00000001 coeff_i 0x00000001 valid_i 0x00000001",
    ]
    assert outputs == [
        "valid_o data_o 0x00000002",
        "16 @read clk_i.MODE 0x00000000 0x0000000f",
    ]

    # The existing, verified fixed-cycle catalogue remains unchanged.
    corners_in = (vector_root / "corners/data_in.vec").read_text(encoding="utf-8")
    corners_out = (vector_root / "corners/data_out.vec").read_text(encoding="utf-8")
    assert "12 data_i 0x00000001" in corners_in
    assert "14 data_o 0x00000002 valid_o 0x00000001" in corners_out

    # Both backends already support the guarded-output command for all bus types.
    clocks = ClockConfig.from_values({"N_CLOCKS": "1", "REG_ITF": interface})
    signature = {
        "ports_in": [( "clk_i", "1"), ("rst_ni", "1"), ("data_i", "32"),
                     ("coeff_i", "32"), ("valid_i", "1")],
        "ports_out": [("data_o", "32"), ("valid_o", "1")],
    }
    sv_monitor = SystemVerilogTestbench.render_vec_monitor("demo", clocks, signature, interface)
    cocotb_monitor = CocotbTestbench.render_vec_monitor(clocks, signature)
    assert "tb_wait_signal(cycle_raw, 32'd1, 4096, seen);" in sv_monitor
    assert "tb_check_read_one(cycle, t1, t2, t3);" in sv_monitor
    assert "await self._wait_signal(parts[0], 1, 4096)" in cocotb_monitor
    assert "got = await read_reg(self.dut, parts[2])" in cocotb_monitor
    compile(cocotb_monitor, "<cycle-monitor>", "exec")


def test_non_valid_interfaces_retain_existing_reconfig_semantics(tmp_path: Path) -> None:
    """Do not silently apply valid_o assumptions to arbitrary authored IPs."""
    template = ModelFlow._tests_text("demo")
    assert 'if "valid_i" in INPUTS and "valid_o" in OUTPUTS:' in template
    assert "second_in, second_out = csr_roundtrip(24, 32)" in template
