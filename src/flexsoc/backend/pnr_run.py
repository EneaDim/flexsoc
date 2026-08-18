"""Run ORFS while retaining a full log and compact FlexSoC checkpoints."""

from __future__ import annotations

import argparse
import os
import re
import shutil
import subprocess
from pathlib import Path

from flexsoc.backend.output import print_label, print_live_line, print_log, print_path_label, strip_ansi

_STAGE = re.compile(r"stage\s+([1-6])(?:_|\b)", re.IGNORECASE)
_PHASE = {
    "1": "import",
    "2": "floorplan",
    "3": "placement",
    "4": "CTS",
    "5": "routing",
    "6": "finish",
}


def checkpoint(line: str) -> str | None:
    """Return one stable macro-phase label for an ORFS transcript line."""

    plain = strip_ansi(line)
    lower = plain.lower()
    if "extract_parasitics" in lower or "write_spef" in lower or "openrcx" in lower:
        return "extraction"
    match = _STAGE.search(plain)
    return _PHASE.get(match.group(1)) if match else None


def _final_artifacts(workdir: Path) -> tuple[tuple[str, Path], ...]:
    results = workdir / "results"
    names = (
        ("netlist", "6_final.v"),
        ("sdc", "6_final.sdc"),
        ("spef", "6_final.spef"),
        ("odb", "6_final.odb"),
        ("gds", "6_final.gds"),
    )
    found: list[tuple[str, Path]] = []
    for kind, name in names:
        candidates = sorted(results.glob(f"**/{name}")) if results.is_dir() else []
        if candidates:
            found.append((kind, candidates[-1]))
    return tuple(found)


def _orfs_env() -> dict[str, str]:
    """Resolve ORFS tool executables from the active FlexSoC PATH."""

    env = os.environ.copy()
    for variable, executable in (
        ("OPENROAD_EXE", "openroad"),
        ("YOSYS_EXE", "yosys"),
        ("KLAYOUT_CMD", "klayout"),
    ):
        env.pop(variable, None)
        if resolved := shutil.which(executable):
            env[variable] = resolved
    return env


def run(*, makefile: Path, config: Path, workdir: Path, log: Path) -> int:
    """Run the ORFS Makefile and return its exit status."""

    live = os.environ.get("FLEXSOC_LIVE", "0").strip().lower() in {"1", "true", "yes", "on"}
    makefile = makefile.expanduser().resolve()
    config = config.expanduser().resolve()
    workdir = workdir.expanduser().resolve()
    log = log.expanduser().resolve()
    if not makefile.is_file():
        raise ValueError(f"OpenROAD-flow-scripts Makefile not found: {makefile}")
    if not config.is_file():
        raise ValueError(f"OpenROAD config.mk not found: {config}")
    workdir.mkdir(parents=True, exist_ok=True)
    log.parent.mkdir(parents=True, exist_ok=True)
    print_log(log)
    seen: set[str] = set()
    pending_finish = False
    command = ("make", f"--file={makefile}", "--no-print-dir", f"DESIGN_CONFIG={config}")
    env = _orfs_env()
    with log.open("w", encoding="utf-8") as handle:
        for variable in ("OPENROAD_EXE", "YOSYS_EXE", "KLAYOUT_CMD"):
            if value := env.get(variable):
                handle.write(f"[flexsoc] {variable}={value}\n")
        proc = subprocess.Popen(
            command,
            cwd=workdir,
            env=env,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            bufsize=1,
        )
        assert proc.stdout is not None
        for line in proc.stdout:
            plain = strip_ansi(line)
            handle.write(plain)
            handle.flush()
            if live:
                print_live_line(line)
                continue
            phase = checkpoint(plain)
            if phase == "finish":
                pending_finish = True
            elif phase and phase not in seen:
                seen.add(phase)
                print_label("pnr", phase)
            if "[ERROR" in plain or plain.startswith("Error:"):
                print_live_line(line)
        returncode = proc.wait()
    if returncode == 0:
        if pending_finish and "finish" not in seen:
            print_label("pnr", "finish")
        for kind, path in _final_artifacts(workdir):
            print_path_label("report", path, details={"kind": kind})
    else:
        print_label("pnr", f"failed; see {log}")
    return returncode


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run ORFS with compact implementation checkpoints.")
    parser.add_argument("--makefile", type=Path, required=True)
    parser.add_argument("--config", type=Path, required=True)
    parser.add_argument("--workdir", type=Path, required=True)
    parser.add_argument("--log", type=Path, required=True)
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    try:
        return run(makefile=args.makefile, config=args.config, workdir=args.workdir, log=args.log)
    except ValueError as exc:
        print(exc)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
