from __future__ import annotations

from pathlib import Path


def test_sta_and_power_use_pipefail():
    mk = Path("src/flexsoc/flow/mk/20-ip-flow.mk").read_text(encoding="utf-8")
    assert "bash -o pipefail -c '$(STA) -exit -no_init $(SIGNOFFDIR)/sta.tcl 2>&1 | tee $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log'" in mk
    assert "bash -o pipefail -c '$(STA) -exit -no_init $(SIGNOFFDIR)/power.tcl 2>&1 | tee $(LOGDIR)/$(TOP)_power.log'" in mk
