from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path


def _run(*args: str):
    repo_root = Path(__file__).resolve().parents[2]
    src = str(repo_root / "src")
    env = os.environ.copy()
    env["PYTHONPATH"] = src + (":" + env["PYTHONPATH"] if env.get("PYTHONPATH") else "")
    return subprocess.run(
        [sys.executable, "-m", "flexsoc.cli", *args],
        capture_output=True,
        text=True,
        env=env,
        cwd=repo_root,
    )


def test_soc_start_builds_aggregate_rtl_list(tmp_path: Path):
    ws = tmp_path / "workspace"
    run_dir = ws / "runs" / "soc0" / "dev"
    ip0_rtl = run_dir / "ips" / "ip0" / "rtl"
    ip1_rtl = run_dir / "ips" / "ip1" / "rtl"
    ip0_rtl.mkdir(parents=True, exist_ok=True)
    ip1_rtl.mkdir(parents=True, exist_ok=True)

    a = ip0_rtl / "ip0_pkg.sv"
    b = ip0_rtl / "ip0.sv"
    c = ip1_rtl / "ip1.sv"
    for f in (a, b, c):
        f.write_text(f"// {f.name}\n", encoding="utf-8")

    (ip0_rtl / "rtl_list.f").write_text(f"{a.resolve().as_posix()}\n{b.resolve().as_posix()}\n", encoding="utf-8")
    (ip1_rtl / "rtl_list.f").write_text(f"{c.resolve().as_posix()}\n", encoding="utf-8")

    p = _run("run", "soc_start", "--workspace", str(ws), "--run-top", "soc0", "--run-id", "dev")
    assert p.returncode == 0, (p.stdout, p.stderr)

    merged = run_dir / "rtl" / "rtl_list.f"
    loaded = run_dir / "ips" / "loaded_ips.txt"
    summary = run_dir / "doc" / "soc_start.txt"
    run_yaml = run_dir / "run.yaml"
    hist_dir = run_dir / "history"

    assert merged.exists()
    assert loaded.exists()
    assert summary.exists()
    assert run_yaml.exists()
    assert hist_dir.exists()

    merged_text = merged.read_text(encoding="utf-8")
    assert a.resolve().as_posix() in merged_text
    assert b.resolve().as_posix() in merged_text
    assert c.resolve().as_posix() in merged_text

    loaded_text = loaded.read_text(encoding="utf-8")
    assert "ip0" in loaded_text
    assert "ip1" in loaded_text


def test_soc_start_appears_in_actions():
    p = _run("actions")
    out = (p.stdout or "") + (p.stderr or "")
    assert p.returncode == 0
    assert "soc_start" in out
