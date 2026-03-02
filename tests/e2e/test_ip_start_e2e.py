import os
import subprocess
from pathlib import Path

def test_ip_start_e2e(tmp_path: Path):
    ws = tmp_path / "workspace"
    ws.mkdir(parents=True, exist_ok=True)

    # Run via make directly (backend truth) - fast + stable
    cmd = [
        "make", "-C", "flow", "ip_start",
        "TOP=my_ip",
        "REG_ITF=tlul",
        f"WORKSPACE={ws}",
        "RUN_ID=e2e",
        "OVERWRITE=--force",
    ]
    p = subprocess.run(cmd, capture_output=True, text=True, env=os.environ.copy())

    if p.returncode != 0:
        print("STDOUT:\n", p.stdout)
        print("STDERR:\n", p.stderr)

    assert p.returncode == 0

    run_dir = ws / "runs" / "my_ip" / "e2e"
    assert run_dir.exists()

    # Key artifacts
    assert (run_dir / "rtl" / "rtl_list.f").exists()
    assert (run_dir / "tb" / "my_ip_tb.sv").exists()
    assert (run_dir / "logs" / "my_ip_lint.log").exists()

    sim_log = run_dir / "logs" / "my_ip_sim.log"
    # some flows might name it differently; accept either
    if not sim_log.exists():
        sim_log = run_dir / "logs" / "my_ip_sim.log"
    # Accept matching from stdout too if logs differ
    out = p.stdout

    # Robust invariants (avoid timestamps/paths)
    assert "Coverage:" in out
    assert "TLUL READ DONE" in out
    assert "Verilator:" in out
    assert "$finish" in out
