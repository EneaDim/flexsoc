"""Generate a compact FuseSoC core file from ordered RTL sources."""

from __future__ import annotations

import argparse
from pathlib import Path


LICENSE = """# Copyright 2025 Enea Dimroci
#
# Licensed under the Apache License, Version 2.0.
"""


def rtl_sort_key(filename: str, top: str) -> tuple[int, str]:
    """Return a stable RTL order with packages first and the top module last."""

    if filename.endswith("_pkg.sv") and filename != f"{top}_reg_pkg.sv":
        return (0, filename)
    if filename == f"{top}_reg_pkg.sv":
        return (1, filename)
    if filename == f"{top}_reg_top.sv":
        return (2, filename)
    if filename.endswith("_core.sv") or filename == "timer_core.sv":
        return (3, filename)
    if filename == f"{top}.sv":
        return (4, filename)
    return (5, filename)


def list_rtl_sources(rtl_dir: Path, top: str) -> list[str]:
    """List visible SystemVerilog files in FuseSoC-friendly order."""

    files = [p.name for p in rtl_dir.iterdir() if p.is_file() and not p.name.startswith(".")]
    return sorted((name for name in files if name.endswith(".sv")), key=lambda name: rtl_sort_key(name, top))


def render_core(prj: str, top: str, rtl_files: list[str], rtl_ref_dir: str = "rtl") -> str:
    """Render the CAPI2 core description used by FuseSoC."""

    file_lines = "\n".join(f"      - {rtl_ref_dir}/{name}" for name in rtl_files)
    if file_lines:
        file_lines += "\n"
    return (
        "CAPI=2:\n"
        f"name: \"{prj}:ip:{top}:0.1\"\n"
        f"description: \"{top}\"\n"
        "filesets:\n"
        "  files_rtl:\n"
        "    depend:\n"
        "      - ips:dependecies:all\n"
        "    files:\n"
        f"{file_lines}"
        "    file_type: systemVerilogSource\n\n"
        "targets:\n"
        "  default: &default_target\n"
        "    filesets:\n"
        "      - files_rtl\n"
        f"    toplevel: {top}\n\n"
        "  lint:\n"
        "    <<: *default_target\n"
        "    default_tool: verilator\n"
        "    tools:\n"
        "      verilator:\n"
        "        mode: lint-only\n"
        "        verilator_options:\n"
        "          - \"-Wall\"\n"
        "          - \"-Wno-fatal\"\n"
    )


def write_core(prj: str, top: str, rtl_dir: Path, output: Path | None = None) -> Path:
    """Write `<top>.core` and return the generated path."""

    out_dir = output or Path.cwd()
    out_dir.mkdir(parents=True, exist_ok=True)
    core_path = out_dir / f"{top}.core"
    core_path.write_text(render_core(prj, top, list_rtl_sources(rtl_dir, top)), encoding="utf-8")
    return core_path


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse the CLI flags used by the Make flow."""

    parser = argparse.ArgumentParser(description="Generate a FuseSoC .core file from RTL sources.")
    parser.add_argument("-prj", "--prj", required=True, help="Project/vendor prefix for the core name.")
    parser.add_argument("-top", "--top", required=True, help="Top module name.")
    parser.add_argument("-rtldir", "--rtldir", required=True, type=Path, help="Directory with RTL sources.")
    parser.add_argument("-lintdir", "--lintdir", required=True, help="Legacy lint directory flag kept for compatibility.")
    parser.add_argument("-o", "--output", type=Path, help="Output folder for the generated .core file.")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """CLI entrypoint used by the Make targets."""

    args = parse_args(argv)
    write_core(args.prj, args.top, args.rtldir, args.output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
