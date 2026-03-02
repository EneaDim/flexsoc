import subprocess
import sys

def test_cli_smoke_dump_registry():
    p = subprocess.run([sys.executable, "-m", "flexsoc.cli", "dump-registry"], capture_output=True, text=True)
    assert p.returncode == 0
    assert "actions" in p.stdout
