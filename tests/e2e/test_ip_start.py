import os
import subprocess
from pathlib import Path

def test_ip_start_e2e(tmp_path: Path):
    # Workspace isolated
    ws = tmp_path / "ws"
    ws.mkdir(parents=True, exist_ok=True)

    env = os.environ.copy()
    # Force all outputs into tmp workspace by overriding dirs if your Makefile supports it.
    # If not supported yet, you can at least run from ws and keep artifacts there.
    # env["WORKSPACE"] = str(ws)

    # Run ip_start (creates template IP + sim)
    p = subprocess.run(
        ["make", "-C", "flow", "ip_start", "TOP=test_ip", "REG_ITF=tlul"],
        cwd=".",
        env=env,
        capture_output=True,
        text=True,
    )

    # Debug help if fails
    if p.returncode != 0:
        print("STDOUT:\n", p.stdout)
        print("STDERR:\n", p.stderr)

    assert p.returncode == 0

    # Minimal assertions: generated artifacts exist in flow outputs (adjust if you redirect to ws)
    # These are placeholders—adapt to your actual dirs once standardized
    # Example checks (tune to your repo):
    # assert (Path("flow/rtl") / "test_ip.sv").exists()
