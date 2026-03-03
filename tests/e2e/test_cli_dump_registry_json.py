from __future__ import annotations

import json
import subprocess
import sys


def test_dump_registry_is_valid_json():
    p = subprocess.run(
        [sys.executable, "-m", "flexsoc.cli", "dump-registry"],
        capture_output=True,
        text=True,
    )
    assert p.returncode == 0
    data = json.loads(p.stdout)
    assert isinstance(data, dict)
    assert "actions" in data
