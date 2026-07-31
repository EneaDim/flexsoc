"""Check the local FlexSoC development environment."""

from __future__ import annotations

import json
import re
import shutil
import subprocess
import sys
from pathlib import Path

VERILATOR_MIN_VERSION = (5, 50)
VERILATOR_MIN_TEXT = "5.050"

TOOLS = (
    ("uv", "uv", ("--version",), True),
    ("Slang", "slang", ("--version",), True),
    ("Verilator", "verilator", ("--version",), True),
    ("Yosys", "yosys", ("-V",), False),
    ("SymbiYosys", "sby", ("--version",), False),
    ("EQY", "eqy", ("--version",), False),
    ("Bitwuzla", "bitwuzla", ("--version",), False),
    ("Boolector", "boolector", ("--version",), False),
    ("BTOR model checker", "btormc", ("--version",), False),
    ("BTOR simulator", "btorsim", ("--version",), False),
    ("OpenSTA", "sta", ("-version",), False),
    ("Icarus", "iverilog", ("-V",), False),
    ("Slang hierarchy", "slang-hier", ("--version",), False),
    ("GTKWave", "gtkwave", ("--version",), False),
    ("Surfer", "surfer", ("--version",), False),
    ("sv2v", "sv2v", ("--version",), False),
    ("netlistsvg", "netlistsvg", ("--version",), False),
    ("OpenROAD", "openroad", ("-version",), False),
    ("KLayout", "klayout", ("-v",), False),
)


def _version(executable: str, args: tuple[str, ...]) -> tuple[str, str] | None:
    """Return executable path and the first version line."""

    path = shutil.which(executable)
    if not path:
        return None
    try:
        result = subprocess.run(
            [path, *args],
            check=False,
            capture_output=True,
            text=True,
            timeout=5,
        )
    except (OSError, subprocess.TimeoutExpired):
        return path, "version unavailable"
    text = (result.stdout or result.stderr).strip()
    version = next((line.strip() for line in text.splitlines() if line.strip()), "unknown")
    return path, version


def _verilator_version_ok(version: str | None) -> bool:
    """Return whether Verilator supports the normalized 5.050 coverage surface."""

    if not version:
        return False
    match = re.search(r"\bVerilator\s+(\d+)\.(\d+)", version, flags=re.IGNORECASE)
    if not match:
        return False
    return (int(match.group(1)), int(match.group(2))) >= VERILATOR_MIN_VERSION


def collect(root: Path) -> dict[str, object]:
    """Collect deterministic environment checks for one repository."""

    lock = root / "uv.lock"
    tools = []
    for name, executable, args, required in TOOLS:
        found = _version(executable, args)
        version = found[1] if found else None
        version_ok = (
            _verilator_version_ok(version)
            if executable == "verilator" and found is not None
            else True
        )
        tools.append(
            {
                "name": name,
                "executable": executable,
                "required": required,
                "found": found is not None,
                "version_ok": version_ok,
                "path": found[0] if found else None,
                "version": version,
            }
        )

    required_ok = all(
        item["found"] and item.get("version_ok", True)
        for item in tools
        if item["required"]
    )
    python_ok = sys.version_info >= (3, 10)
    lock_ok = lock.is_file()
    return {
        "ok": python_ok and lock_ok and required_ok,
        "python": {
            "ok": python_ok,
            "version": sys.version.split()[0],
            "executable": sys.executable,
        },
        "uv_lock": {"ok": lock_ok, "path": str(lock)},
        "tools": tools,
    }


def run(root: Path, *, as_json: bool = False) -> int:
    """Print the environment status and return non-zero for missing essentials."""

    data = collect(root)
    if as_json:
        print(json.dumps(data, indent=2))
        return 0 if data["ok"] else 2

    python = data["python"]
    print("FlexSoC doctor")
    print(f"  {'✓' if python['ok'] else '✗'} Python      {python['version']}  {python['executable']}")

    lock = data["uv_lock"]
    if lock["ok"]:
        print(f"  ✓ uv.lock     {lock['path']}")
    else:
        print(f"  ✗ uv.lock     missing — run: make lock")

    print("\nTools")
    for tool in data["tools"]:
        ok = bool(tool["found"] and tool.get("version_ok", True))
        mark = "✓" if ok else ("✗" if tool["required"] else "·")
        detail = tool["version"] if tool["found"] else "not found"
        if tool["executable"] == "verilator" and tool["found"] and not tool.get("version_ok", True):
            detail = f"{detail} — need >= {VERILATOR_MIN_TEXT}"
        role = "required" if tool["required"] else "optional"
        print(f"  {mark} {tool['name']:<16} {detail}  [{role}]")

    if data["ok"]:
        print("\nEnvironment: PASS")
        return 0
    print("\nEnvironment: FAIL")
    return 2


if __name__ == "__main__":
    raise SystemExit(run(Path.cwd().resolve()))
