from __future__ import annotations

import importlib
import json
import shutil
import subprocess
from dataclasses import asdict, dataclass
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
        p = subprocess.run(cmd, capture_output=True, text=True, check=False)
        out = (p.stdout + "\n" + p.stderr).strip()
        return p.returncode == 0, out.splitlines()[0] if out else "(no output)"
    except Exception as e:
        return False, f"{type(e).__name__}: {e}"


def _check_import(module_name: str, label: str) -> Check:
    try:
        importlib.import_module(module_name)
        return Check(label, True, "OK")
    except Exception as e:
        return Check(label, False, f"{type(e).__name__}: {e}")


def collect_doctor_checks() -> List[Check]:
    checks: List[Check] = []

    python_modules = [
        ("yaml", "python dep: pyyaml (yaml)"),
        ("hjson", "python dep: hjson"),
        ("typer", "python dep: typer"),
        ("rich", "python dep: rich"),
        ("jinja2", "python dep: jinja2"),
        ("mako", "python dep: mako"),
        ("numpy", "python dep: numpy"),
        ("scipy", "python dep: scipy"),
        ("cocotb", "python dep: cocotb"),
    ]

    python_failures = 0
    for module_name, label in python_modules:
        c = _check_import(module_name, label)
        checks.append(c)
        if not c.ok:
            python_failures += 1

    if python_failures == 0:
        checks.append(Check("python deps summary", True, "all core Python dependencies look available"))
    else:
        checks.append(Check("python deps summary", False, f"{python_failures} dependency checks failed"))

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

    return checks


def doctor_as_json() -> str:
    checks = collect_doctor_checks()
    payload = {
        "ok": all(c.ok for c in checks),
        "checks": [asdict(c) for c in checks],
    }
    return json.dumps(payload, indent=2, sort_keys=True)


def run_doctor(json_mode: bool = False) -> int:
    checks = collect_doctor_checks()

    if json_mode:
        print(doctor_as_json())
        return 0 if all(c.ok for c in checks) else 1

    exit_code = 0
    for c in checks:
        if c.ok:
            print(f"[green]OK[/green] {c.name}: {c.detail}")
        else:
            print(f"[red]FAIL[/red] {c.name}: {c.detail}")
            exit_code = 1

    return exit_code
