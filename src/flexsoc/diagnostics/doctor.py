from __future__ import annotations

import importlib
import json
import os
import shutil
import subprocess
from dataclasses import asdict, dataclass
from typing import List, Sequence

from rich import print
from rich.markup import escape


@dataclass
class Check:
    category: str
    name: str
    ok: bool
    detail: str
    required: bool = True


def _which(cmd: str) -> str | None:
    return shutil.which(cmd)


def _run_version(cmd: Sequence[str]) -> tuple[bool, str]:
    try:
        p = subprocess.run(list(cmd), capture_output=True, text=True, check=False)
        out = (p.stdout + "\n" + p.stderr).strip()
        return p.returncode == 0, out.splitlines()[0] if out else "(no output)"
    except Exception as e:
        return False, f"{type(e).__name__}: {e}"


def _check_import(module_name: str, label: str, *, category: str, required: bool) -> Check:
    try:
        importlib.import_module(module_name)
        return Check(category=category, name=label, ok=True, detail="OK", required=required)
    except Exception as e:
        return Check(
            category=category,
            name=label,
            ok=False,
            detail=f"{type(e).__name__}: {e}",
            required=required,
        )


def _expected_value(env_name: str | None) -> str | None:
    if not env_name:
        return None
    value = os.environ.get(env_name, "").strip()
    return value or None


def _check_tool(
    tool: str,
    ver_cmd: Sequence[str],
    *,
    category: str,
    required: bool,
    expected_env: str | None = None,
) -> Check:
    path = _which(tool)
    if not path:
        return Check(
            category=category,
            name=tool,
            ok=False,
            detail="not found in PATH",
            required=required,
        )

    ok, detail = _run_version(ver_cmd)
    if not ok:
        return Check(
            category=category,
            name=tool,
            ok=False,
            detail=f"version command failed [{path}]: {detail}",
            required=required,
        )

    expected = _expected_value(expected_env)
    if expected and expected not in detail:
        return Check(
            category=category,
            name=tool,
            ok=False,
            detail=f"version mismatch [{path}] expected fragment={expected!r}, got={detail!r}",
            required=required,
        )

    return Check(
        category=category,
        name=tool,
        ok=True,
        detail=f"{detail} [{path}]",
        required=required,
    )


def collect_doctor_checks() -> List[Check]:
    checks: List[Check] = []

    python_modules = [
        ("yaml", "python dep: pyyaml (yaml)", "python-core", True),
        ("hjson", "python dep: hjson", "python-core", True),
        ("typer", "python dep: typer", "python-core", True),
        ("rich", "python dep: rich", "python-core", True),
        ("jinja2", "python dep: jinja2", "python-core", True),
        ("mako", "python dep: mako", "python-core", True),
        ("numpy", "python dep: numpy", "python-flow", False),
        ("scipy", "python dep: scipy", "python-flow", False),
        ("cocotb", "python dep: cocotb", "python-flow", False),
        ("edalize", "python dep: edalize", "python-flow", False),
        ("fusesoc", "python dep: fusesoc", "python-flow", False),
    ]

    python_results = []
    for module_name, label, category, required in python_modules:
        check = _check_import(
            module_name,
            label,
            category=category,
            required=required,
        )
        checks.append(check)
        python_results.append(check)

    python_required_failures = sum(1 for c in python_results if c.required and not c.ok)
    checks.append(
        Check(
            category="summary",
            name="python deps summary",
            ok=python_required_failures == 0,
            detail="all core Python dependencies look available"
            if python_required_failures == 0
            else f"{python_required_failures} Python dependency checks failed",
            required=True,
        )
    )

    tool_specs = [
        ("verilator", ["verilator", "--version"], "tool-core", True, "FLEXSOC_EXPECT_VERILATOR"),
        ("sv2v", ["sv2v", "--version"], "tool-core", True, "FLEXSOC_EXPECT_SV2V"),
        ("yosys", ["yosys", "-V"], "tool-flow", True, "FLEXSOC_EXPECT_YOSYS"),
        ("openroad", ["openroad", "-version"], "tool-flow", True, "FLEXSOC_EXPECT_OPENROAD"),
        ("sta", ["sta", "-version"], "tool-flow", True, "FLEXSOC_EXPECT_OPENSTA"),
        ("iverilog", ["iverilog", "-V"], "tool-extra", True, "FLEXSOC_EXPECT_IVERILOG"),
        ("gtkwave", ["gtkwave", "--version"], "tool-extra", True, "FLEXSOC_EXPECT_GTKWAVE"),
        ("netlistsvg", ["netlistsvg", "--version"], "tool-extra", False, "FLEXSOC_EXPECT_NETLISTSVG"),
        (
            "riscv32-unknown-elf-gcc",
            ["riscv32-unknown-elf-gcc", "--version"],
            "tool-soc",
            True,
            "FLEXSOC_EXPECT_RISCV_GCC",
        ),
    ]

    for tool, ver_cmd, category, required, expected_env in tool_specs:
        checks.append(
            _check_tool(
                tool,
                ver_cmd,
                category=category,
                required=required,
                expected_env=expected_env,
            )
        )

    required_failures = sum(1 for c in checks if c.required and not c.ok)
    optional_failures = sum(1 for c in checks if not c.required and not c.ok)

    checks.append(
        Check(
            category="summary",
            name="required checks summary",
            ok=required_failures == 0,
            detail="all required checks passed"
            if required_failures == 0
            else f"{required_failures} required checks failed",
            required=True,
        )
    )
    checks.append(
        Check(
            category="summary",
            name="recommended checks summary",
            ok=optional_failures == 0,
            detail="all recommended checks passed"
            if optional_failures == 0
            else f"{optional_failures} recommended checks missing or mismatched",
            required=False,
        )
    )

    return checks


def doctor_as_json() -> str:
    checks = collect_doctor_checks()
    payload = {
        "ok": all(c.ok or not c.required for c in checks),
        "checks": [asdict(c) for c in checks],
    }
    return json.dumps(payload, indent=2, sort_keys=True)


def run_doctor(json_mode: bool = False) -> int:
    checks = collect_doctor_checks()

    if json_mode:
        print(doctor_as_json())
        return 0 if all(c.ok or not c.required for c in checks) else 1

    exit_code = 0
    for c in checks:
        safe_name = escape(c.name)
        safe_detail = escape(c.detail)
        if c.ok:
            print(f"[green]OK[/green] {safe_name}: {safe_detail}")
        elif c.required:
            print(f"[red]FAIL[/red] {safe_name}: {safe_detail}")
            exit_code = 1
        else:
            print(f"[yellow]WARN[/yellow] {safe_name}: {safe_detail}")

    return exit_code
