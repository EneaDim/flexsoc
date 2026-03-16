from __future__ import annotations

import importlib
import json
import os
import shutil
import subprocess
from dataclasses import asdict, dataclass
from pathlib import Path
from typing import Sequence

from rich import print
from rich.markup import escape


@dataclass
class Check:
    category: str
    name: str
    ok: bool
    detail: str
    required: bool = True


def _resolve_tool_path(tool: str, candidate_paths: Sequence[str] | None = None) -> str | None:
    found = shutil.which(tool)
    if found:
        return found

    for candidate in candidate_paths or ():
        candidate_path = Path(candidate)
        if candidate_path.is_file() and os.access(candidate_path, os.X_OK):
            return str(candidate_path)

    return None


def _run_version(cmd: Sequence[str]) -> tuple[bool, str]:
    try:
        proc = subprocess.run(
            list(cmd),
            capture_output=True,
            text=True,
            check=False,
        )
    except Exception as exc:
        return False, f"{type(exc).__name__}: {exc}"

    output = ((proc.stdout or "") + "\n" + (proc.stderr or "")).strip()
    first_line = output.splitlines()[0] if output else "(no output)"
    return proc.returncode == 0, first_line


def _expected_value(env_name: str | None) -> str | None:
    if not env_name:
        return None
    value = os.environ.get(env_name, "").strip()
    return value or None


def _check_import(module_name: str, label: str, *, category: str, required: bool) -> Check:
    try:
        importlib.import_module(module_name)
        return Check(
            category=category,
            name=label,
            ok=True,
            detail="OK",
            required=required,
        )
    except Exception as exc:
        return Check(
            category=category,
            name=label,
            ok=False,
            detail=f"{type(exc).__name__}: {exc}",
            required=required,
        )


def _check_tool(
    tool: str,
    version_cmd: Sequence[str],
    *,
    category: str,
    required: bool,
    expected_env: str | None = None,
    candidate_paths: Sequence[str] | None = None,
) -> Check:
    resolved_path = _resolve_tool_path(tool, candidate_paths=candidate_paths)
    if not resolved_path:
        return Check(
            category=category,
            name=tool,
            ok=False,
            detail="not found in PATH or known install locations",
            required=required,
        )

    actual_cmd = [resolved_path, *list(version_cmd)[1:]]

    ok, version_line = _run_version(actual_cmd)
    if not ok:
        return Check(
            category=category,
            name=tool,
            ok=False,
            detail=f"version command failed [{resolved_path}]: {version_line}",
            required=required,
        )

    expected = _expected_value(expected_env)
    if expected and expected not in version_line:
        return Check(
            category=category,
            name=tool,
            ok=False,
            detail=f"version mismatch [{resolved_path}] expected fragment={expected!r}, got={version_line!r}",
            required=required,
        )

    return Check(
        category=category,
        name=tool,
        ok=True,
        detail=f"{version_line} [{resolved_path}]",
        required=required,
    )


def collect_doctor_checks() -> list[Check]:
    checks: list[Check] = []

    python_modules = [
        ("yaml", "python dep: pyyaml (yaml)", "python-core", True),
        ("hjson", "python dep: hjson", "python-core", True),
        ("typer", "python dep: typer", "python-core", True),
        ("rich", "python dep: rich", "python-core", True),
        ("jinja2", "python dep: jinja2", "python-core", True),
        ("mako", "python dep: mako", "python-core", True),
        ("numpy", "python dep: numpy", "python-flow", True),
        ("scipy", "python dep: scipy", "python-flow", True),
        ("cocotb", "python dep: cocotb", "python-flow", True),
        ("edalize", "python dep: edalize", "python-flow", True),
        ("fusesoc", "python dep: fusesoc", "python-flow", True),
    ]

    python_checks: list[Check] = []
    for module_name, label, category, required in python_modules:
        check = _check_import(
            module_name,
            label,
            category=category,
            required=required,
        )
        checks.append(check)
        python_checks.append(check)

    python_required_failures = sum(1 for check in python_checks if check.required and not check.ok)
    checks.append(
        Check(
            category="summary",
            name="python deps summary",
            ok=python_required_failures == 0,
            detail=(
                "all core Python dependencies look available"
                if python_required_failures == 0
                else f"{python_required_failures} Python dependency checks failed"
            ),
            required=True,
        )
    )

    tool_specs = [
        ("verilator", ["verilator", "--version"], "tool-core", True, "FLEXSOC_EXPECT_VERILATOR", ()),
        ("sv2v", ["sv2v", "--version"], "tool-core", True, "FLEXSOC_EXPECT_SV2V", ()),
        ("yosys", ["yosys", "-V"], "tool-flow", True, "FLEXSOC_EXPECT_YOSYS", ()),
        (
            "openroad",
            ["openroad", "-version"],
            "tool-flow",
            True,
            "FLEXSOC_EXPECT_OPENROAD",
            ("/usr/local/OpenROAD/bin/openroad",),
        ),
        (
            "sta",
            ["sta", "-version"],
            "tool-flow",
            True,
            "FLEXSOC_EXPECT_OPENSTA",
            ("/usr/local/OpenROAD/bin/sta",),
        ),
        ("iverilog", ["iverilog", "-V"], "tool-extra", True, "FLEXSOC_EXPECT_IVERILOG", ()),
        ("gtkwave", ["gtkwave", "--version"], "tool-extra", True, "FLEXSOC_EXPECT_GTKWAVE", ()),
        ("netlistsvg", ["netlistsvg", "--version"], "tool-extra", False, "FLEXSOC_EXPECT_NETLISTSVG", ()),
        (
            "riscv32-unknown-elf-gcc",
            ["riscv32-unknown-elf-gcc", "--version"],
            "tool-soc",
            True,
            "FLEXSOC_EXPECT_RISCV_GCC",
            (),
        ),
    ]

    for tool, version_cmd, category, required, expected_env, candidate_paths in tool_specs:
        checks.append(
            _check_tool(
                tool,
                version_cmd,
                category=category,
                required=required,
                expected_env=expected_env,
                candidate_paths=candidate_paths,
            )
        )

    required_failures = sum(1 for check in checks if check.required and not check.ok)
    optional_failures = sum(1 for check in checks if not check.required and not check.ok)

    checks.append(
        Check(
            category="summary",
            name="required checks summary",
            ok=required_failures == 0,
            detail=(
                "all required checks passed"
                if required_failures == 0
                else f"{required_failures} required checks failed"
            ),
            required=True,
        )
    )
    checks.append(
        Check(
            category="summary",
            name="recommended checks summary",
            ok=optional_failures == 0,
            detail=(
                "all recommended checks passed"
                if optional_failures == 0
                else f"{optional_failures} recommended checks missing or mismatched"
            ),
            required=False,
        )
    )

    return checks


def doctor_as_json() -> str:
    checks = collect_doctor_checks()
    payload = {
        "ok": all(check.ok or not check.required for check in checks),
        "checks": [asdict(check) for check in checks],
    }
    return json.dumps(payload, indent=2, sort_keys=True)


def run_doctor(json_mode: bool = False) -> int:
    checks = collect_doctor_checks()

    if json_mode:
        print(doctor_as_json())
        return 0 if all(check.ok or not check.required for check in checks) else 1

    exit_code = 0
    for check in checks:
        safe_name = escape(check.name)
        safe_detail = escape(check.detail)
        if check.ok:
            print(f"[green]OK[/green] {safe_name}: {safe_detail}")
        elif check.required:
            print(f"[red]FAIL[/red] {safe_name}: {safe_detail}")
            exit_code = 1
        else:
            print(f"[yellow]WARN[/yellow] {safe_name}: {safe_detail}")

    return exit_code
