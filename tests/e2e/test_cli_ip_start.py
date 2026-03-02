import os
import re
import subprocess
import sys
from pathlib import Path

def test_cli_ip_start(tmp_path: Path):
    ws = tmp_path / "workspace"
    ws.mkdir(parents=True, exist_ok=True)

    cmd = [
        sys.executable, "-m", "flexsoc.cli",
        "run", "ip_start",
        "--top", "my_ip",
        "--reg-itf", "tlul",
        "--workspace", str(ws),
        "--run-id", "e2e_cli",
        "--overwrite", "--force",
    ]
    p = subprocess.run(cmd, capture_output=True, text=True, env=os.environ.copy())

    if p.returncode != 0:
        print("STDOUT:\n", p.stdout)
        print("STDERR:\n", p.stderr)

    assert p.returncode == 0

    out = re.sub(r"\x1b\[[0-9;]*m", "", p.stdout + "\n" + p.stderr)
    assert "Flow dir:" in out

    run_dir = ws / "runs" / "my_ip" / "e2e_cli"
    assert run_dir.exists()
    assert (run_dir / "rtl" / "rtl_list.f").exists()
    assert (run_dir / "tb" / "my_ip_tb.sv").exists()
    assert (run_dir / "manifest.json").exists()
    assert (run_dir / "report.json").exists()
