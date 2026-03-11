from __future__ import annotations

import subprocess
from pathlib import Path


def test_make_help_targets_redirect_to_cli():
    flow_dir = Path("src/flexsoc/flow").resolve()

    for target in ["help", "help_ip", "help_soc", "help_doc"]:
        res = subprocess.run(
            ["make", "-C", str(flow_dir), target],
            capture_output=True,
            text=True,
            check=False,
        )
        assert res.returncode == 0, f"{target} failed: {res.stdout}\n{res.stderr}"
        combined = res.stdout + res.stderr
        assert "flexsoc" in combined.lower()
