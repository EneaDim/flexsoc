import json
import subprocess
import sys
from pathlib import Path

def test_plan_and_exec(tmp_path: Path):
    ws = tmp_path / "workspace"
    ws.mkdir(parents=True, exist_ok=True)

    plan_path = tmp_path / "plan.json"

    p1 = subprocess.run(
        [sys.executable, "-m", "flexsoc.cli", "plan", "create ip", "--out", str(plan_path)],
        capture_output=True,
        text=True,
    )
    assert p1.returncode == 0
    assert plan_path.exists()

    plan = json.loads(plan_path.read_text(encoding="utf-8"))
    assert plan["action"] == "ip_start"

    p2 = subprocess.run(
        [
            sys.executable, "-m", "flexsoc.cli", "exec", str(plan_path),
            "--workspace", str(ws),
            "--run-id", "e2e_plan",
            "--top", "my_ip",
            "--reg-itf", "tlul",
            "--overwrite", "--force",
        ],
        capture_output=True,
        text=True,
    )
    assert p2.returncode == 0

    run_dir = ws / "runs" / "my_ip" / "e2e_plan"
    assert (run_dir / "report.json").exists()
    assert (run_dir / "manifest.json").exists()
