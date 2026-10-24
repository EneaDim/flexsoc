"""The CSR setup provenance must agree with the declared stage owner."""
from pathlib import Path
from types import SimpleNamespace

import pytest

from flexsoc.backend.core.flow.lifecycle import STAGE_CONTRACTS
from flexsoc.backend.core.flow.session import TargetSession


@pytest.mark.parametrize("mode", ("prove", "cover"))
def test_csr_setup_provenance_reports_own_generated_sv(tmp_path: Path, mode: str):
    stage = f"formal.csr_{mode}.setup"
    rel = f"dv/formal/csr/{mode}/uart_csr_auto_{mode}.sv"
    assert STAGE_CONTRACTS[stage].owned_outputs == (
        f"dv/formal/csr/{mode}/{{top}}_csr_auto_{mode}.sv",
    )
    generated = tmp_path / rel
    generated.parent.mkdir(parents=True)
    generated.write_text("module p; endmodule\n")
    sby = tmp_path / f"dv/formal/runs/csr/{mode}/uart_csr_{mode}.sby"
    fake = SimpleNamespace(
        paths=SimpleNamespace(run=tmp_path, top="uart", pdk="ihp-sg13g2"),
        _result_paths=lambda result: (result,),
    )
    produced = TargetSession._generated_paths(fake, stage, sby)
    assert generated in produced
    assert sby in produced
    assert (tmp_path / f"dv/formal/csr/{'cover' if mode == 'prove' else 'prove'}/uart_csr_auto_{'cover' if mode == 'prove' else 'prove'}.sv") not in produced
