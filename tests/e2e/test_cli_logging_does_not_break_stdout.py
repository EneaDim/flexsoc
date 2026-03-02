from __future__ import annotations

import json
import os
import subprocess
import sys


def test_dump_registry_stdout_is_json_even_with_debug_logs():
    env = os.environ.copy()
    env["FLEXSOC_LOG_LEVEL"] = "DEBUG"

    p = subprocess.run(
        [sys.executable, "-m", "flexsoc.cli", "dump-registry"],
        capture_output=True,
        text=True,
        env=env,
    )

    assert p.returncode == 0
    # stdout must remain pure JSON
    data = json.loads(p.stdout)
    assert isinstance(data, dict)
    assert "actions" in data
