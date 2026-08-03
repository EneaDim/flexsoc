"""Check the local FlexSoC development environment."""

from __future__ import annotations

import hashlib
import json
import re
import shutil
import subprocess
import sys
from pathlib import Path

from rich.console import Console
from rich.table import Table

TOOLS = (
    ("uv", "uv", ("--version",), True, None),
    ("Slang", "slang", ("--version",), True, "SLANG"),
    ("Verilator", "verilator", ("--version",), True, "VERILATOR"),
    ("Yosys", "yosys", ("-V",), False, "YOSYS"),
    ("SymbiYosys", "sby", ("--version",), False, "SBY"),
    ("EQY", "eqy", ("--version",), False, "EQY"),
    ("Bitwuzla", "bitwuzla", ("--version",), False, "BITWUZLA"),
    ("Boolector", "boolector", ("--version",), False, "BOOLECTOR"),
    ("BTOR model checker", "btormc", ("--version",), False, None),
    ("BTOR simulator", "btorsim", ("--version",), False, None),
    ("OpenSTA", "sta", ("-version",), False, "OPENSTA"),
    ("Icarus", "iverilog", ("-V",), False, "IVERILOG"),
    ("Slang hierarchy", "slang-hier", ("--version",), False, None),
    ("GTKWave", "gtkwave", ("--version",), False, "GTKWAVE"),
    ("FST to VCD converter", "fst2vcd", ("--help",), True, None),
    ("Surfer", "surfer", ("--version",), False, "SURFER"),
    ("sv2v", "sv2v", ("--version",), False, "SV2V"),
    ("netlistsvg", "netlistsvg", ("--version",), False, "NETLISTSVG"),
    ("OpenROAD", "openroad", ("-version",), False, "OPENROAD"),
    ("KLayout", "klayout", ("-v",), False, None),
)

# These are compatibility floors for features used by FlexSoC.  The lock may
# deliberately pin a newer version for reproducibility without making an older
# compatible system installation unusable.
DEFAULT_MINIMUMS = {
    "verilator": "5.050",
    "iverilog": "12.0",
}


def load_toolchain_lock(root: Path) -> dict[str, str]:
    """Parse simple KEY=VALUE entries from the native toolchain lock."""

    path = root / "src" / "flexsoc" / "backend" / "toolchain.lock"
    if not path.is_file():
        return {}
    values: dict[str, str] = {}
    for raw in path.read_text(encoding="utf-8").splitlines():
        line = raw.strip()
        if not line or line.startswith("#") or "=" not in line:
            continue
        key, value = line.split("=", 1)
        values[key.strip()] = value.strip()
    return values


def _file_sha256(path: Path) -> str | None:
    if not path.is_file():
        return None
    return hashlib.sha256(path.read_bytes()).hexdigest()


def toolchain_metadata(root: Path) -> dict[str, object]:
    """Return lock identity and compact expected-tool metadata."""

    path = root / "src" / "flexsoc" / "backend" / "toolchain.lock"
    lock = load_toolchain_lock(root)
    expected: dict[str, dict[str, str]] = {}
    for _, executable, _, _, key in TOOLS:
        if not key:
            continue
        row: dict[str, str] = {}
        if lock.get(f"{key}_VERSION"):
            row["locked_version"] = lock[f"{key}_VERSION"]
        minimum = lock.get(f"{key}_MIN_VERSION") or DEFAULT_MINIMUMS.get(executable)
        if minimum:
            row["minimum_version"] = minimum
        if lock.get(f"{key}_REF"):
            row["ref"] = lock[f"{key}_REF"]
        if lock.get(f"{key}_REF_PREFIX"):
            row["ref_prefix"] = lock[f"{key}_REF_PREFIX"]
        if lock.get(f"{key}_INSTALL_MODE"):
            row["install_mode"] = lock[f"{key}_INSTALL_MODE"]
        if row:
            expected[executable] = row
    return {
        "path": str(path),
        "sha256": _file_sha256(path),
        "lock_version": lock.get("LOCK_VERSION"),
        "expected": expected,
    }


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
    text = ((result.stdout or "") + "\n" + (result.stderr or "")).strip()
    version = next((line.strip() for line in text.splitlines() if line.strip()), "unknown")
    return path, version


def _numeric_version(version: str | None, executable: str) -> tuple[int, ...] | None:
    """Extract a comparable numeric version for tools with semantic releases."""

    if not version:
        return None
    patterns = {
        "verilator": r"\bVerilator\s+(\d+(?:\.\d+)+)",
        "iverilog": r"\bversion\s+(\d+(?:\.\d+)+)",
    }
    pattern = patterns.get(executable)
    if not pattern:
        return None
    match = re.search(pattern, version, flags=re.IGNORECASE)
    if not match:
        return None
    return tuple(int(part) for part in match.group(1).split("."))


def _numeric_text(value: str) -> tuple[int, ...]:
    return tuple(int(part) for part in value.split("."))


def _assess_tool(
    executable: str,
    version: str | None,
    expected: dict[str, str],
) -> tuple[bool, bool | None]:
    """Return compatibility and lock-match status for one resolved tool."""

    minimum = expected.get("minimum_version")
    current_numeric = _numeric_version(version, executable)
    version_ok = True
    if minimum:
        version_ok = current_numeric is not None and current_numeric >= _numeric_text(minimum)

    locked = expected.get("locked_version")
    ref_prefix = expected.get("ref_prefix")
    lock_match: bool | None = None
    if locked or ref_prefix:
        lock_match = True
        if locked:
            if current_numeric is not None and re.fullmatch(r"\d+(?:\.\d+)+", locked):
                lock_match = current_numeric == _numeric_text(locked)
            else:
                lock_match = locked.lower() in (version or "").lower()
        if ref_prefix:
            lock_match = bool(lock_match and ref_prefix.lower() in (version or "").lower())
    return version_ok, lock_match


def collect(root: Path) -> dict[str, object]:
    """Collect deterministic environment checks for one repository."""

    uv_lock = root / "uv.lock"
    toolchain = toolchain_metadata(root)
    expected_all = toolchain["expected"]
    assert isinstance(expected_all, dict)
    tools = []
    for name, executable, args, required, _ in TOOLS:
        found = _version(executable, args)
        version = found[1] if found else None
        expected = expected_all.get(executable, {})
        assert isinstance(expected, dict)
        version_ok, lock_match = _assess_tool(executable, version, expected) if found else (False, None)
        tools.append(
            {
                "name": name,
                "executable": executable,
                "required": required,
                "found": found is not None,
                "version_ok": version_ok if found else False,
                "lock_match": lock_match,
                "path": found[0] if found else None,
                "version": version,
                "minimum_version": expected.get("minimum_version"),
                "locked_version": expected.get("locked_version"),
                "locked_ref": expected.get("ref") or expected.get("ref_prefix"),
                "install_mode": expected.get("install_mode", "managed" if expected else None),
            }
        )

    required_ok = all(
        item["found"] and item.get("version_ok", True)
        for item in tools
        if item["required"]
    )
    python_ok = sys.version_info >= (3, 10)
    uv_lock_ok = uv_lock.is_file()
    toolchain_lock_ok = bool(toolchain.get("sha256"))
    return {
        "ok": python_ok and uv_lock_ok and toolchain_lock_ok and required_ok,
        "python": {
            "ok": python_ok,
            "version": sys.version.split()[0],
            "executable": sys.executable,
        },
        "uv_lock": {"ok": uv_lock_ok, "path": str(uv_lock)},
        "toolchain_lock": {"ok": toolchain_lock_ok, **toolchain},
        "tools": tools,
    }


def run(root: Path, *, as_json: bool = False) -> int:
    """Print environment checks grouped by the flow phase that consumes them."""

    data = collect(root)
    if as_json:
        print(json.dumps(data, indent=2))
        return 0 if data["ok"] else 2

    console = Console()
    console.print("[bold orange1]FlexSoC doctor[/bold orange1]")
    project = Table(show_header=False, box=None, pad_edge=False)
    project.add_column("Check", style="grey70", no_wrap=True); project.add_column("Value", style="white")
    python = data["python"]; uv_lock = data["uv_lock"]; toolchain = data["toolchain_lock"]
    project.add_row("Python", f"{python['version']} · {python['executable']}")
    project.add_row("uv.lock", str(uv_lock["path"]) if uv_lock["ok"] else "missing")
    project.add_row("toolchain.lock", f"v{toolchain.get('lock_version') or '?'} · {toolchain['path']}" if toolchain["ok"] else "missing")
    console.print(project)

    groups = (
        ("RTL / lint", {"slang", "verilator", "slang-hier"}),
        ("Formal / equivalence", {"yosys", "sby", "eqy", "bitwuzla", "boolector", "btormc", "btorsim"}),
        ("Simulation / debug", {"iverilog", "gtkwave", "fst2vcd", "surfer", "sv2v", "netlistsvg"}),
        ("Implementation / sign-off", {"sta", "openroad", "klayout"}),
        ("Environment", {"uv"}),
    )
    by_exe = {tool["executable"]: tool for tool in data["tools"]}
    for title, executables in groups:
        rows = [by_exe[name] for name in executables if name in by_exe]
        if not rows:
            continue
        console.print(f"\n[bold bright_cyan]{title}[/bold bright_cyan]")
        table = Table(box=None, pad_edge=False, header_style="bold grey70")
        table.add_column("Status"); table.add_column("Tool", style="white"); table.add_column("Version / note", style="grey70"); table.add_column("Role", style="grey70")
        for tool in sorted(rows, key=lambda item: str(item["name"])):
            found = bool(tool["found"]); version_ok = bool(tool.get("version_ok", True)); lock_match = tool.get("lock_match")
            if found and version_ok and lock_match is not False:
                mark = "[bright_cyan]OK[/bright_cyan]"
            elif found and version_ok:
                mark = "[orange1]COMPAT[/orange1]"
            elif tool["required"]:
                mark = "[orange1]MISSING[/orange1]"
            else:
                mark = "[grey70]optional[/grey70]"
            detail = str(tool["version"]) if found else "not found"
            if found and not version_ok and tool.get("minimum_version"):
                detail += f" · need >= {tool['minimum_version']}"
            elif found and lock_match is False and tool.get("locked_version"):
                detail += f" · tested {tool['locked_version']}"
            table.add_row(mark, str(tool["name"]), detail, "required" if tool["required"] else "optional")
        console.print(table)

    if data["ok"]:
        console.print("\n[bold bright_cyan]Environment: PASS[/bold bright_cyan]")
        return 0
    console.print("\n[bold orange1]Environment: FAIL[/bold orange1]")
    return 2


if __name__ == "__main__":
    raise SystemExit(run(Path.cwd().resolve()))
