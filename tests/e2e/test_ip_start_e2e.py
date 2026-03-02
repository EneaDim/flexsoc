import os
import re
import subprocess
from pathlib import Path

ANSI_RE = re.compile(r"\x1b\[[0-9;]*m")

def test_ip_start_e2e(tmp_path: Path):
    ws = tmp_path / "workspace"
    ws.mkdir(parents=True, exist_ok=True)

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
    assert (run_dir / "logs").exists()

    # Assert invariants in sim log (not stdout)
    sim_logs = sorted((run_dir / "logs").glob("*_sim.log"))
    assert sim_logs, "No *_sim.log found in logs/"
    sim_text = ANSI_RE.sub("", sim_logs[0].read_text(encoding="utf-8", errors="replace"))

    assert "Coverage:" in sim_text
    assert "TLUL READ DONE" in sim_text
    assert "$finish" in sim_text
