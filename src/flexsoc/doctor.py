from __future__ import annotations

import shutil
import subprocess
from dataclasses import dataclass
from typing import List, Tuple

from rich import print


@dataclass
class Check:
    name: str
    ok: bool
    detail: str


def _which(cmd: str) -> str | None:
    return shutil.which(cmd)


def _run_version(cmd: List[str]) -> Tuple[bool, str]:
    try:
        p = subprocess.run(cmd, capture_output=True, text=True)
        out = (p.stdout + "\n" + p.stderr).strip()
        return p.returncode == 0, out.splitlines()[0] if out else "(no output)"
    except Exception as e:
        return False, f"{type(e).__name__}: {e}"


def run_doctor() -> int:
    checks: List[Check] = []

    # Python deps
    try:
        import hjson  # noqa: F401
        import yaml  # noqa: F401
        checks.append(Check("python deps (hjson, pyyaml)", True, "OK"))
    except Exception as e:
        checks.append(Check("python deps (hjson, pyyaml)", False, f"{type(e).__name__}: {e}"))

    # Toolchain
    for tool, ver_cmd in [
        ("verilator", ["verilator", "--version"]),
        ("yosys", ["yosys", "-V"]),
        ("openroad", ["openroad", "-version"]),
        ("sv2v", ["sv2v", "--version"]),
    ]:
        path = _which(tool)
        if not path:
            checks.append(Check(tool, False, "not found in PATH"))
            continue
        ok, detail = _run_version(ver_cmd)
        checks.append(Check(tool, ok, detail))

    # Print summary
    exit_code = 0
    for c in checks:
        if c.ok:
            print(f"[green]OK[/green] {c.name}: {c.detail}")
        else:
            print(f"[red]FAIL[/red] {c.name}: {c.detail}")
            exit_code = 1

    return exit_code
