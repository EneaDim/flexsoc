"""Generate ordered RTL filelists for IP and SoC flow runs."""

from __future__ import annotations

import argparse
import re
from pathlib import Path

IP_NAME_MAP = {"uart-master": "uart", "uart_master": "uart"}
COMMON_RE = re.compile(r"/hw/ips/(pkgs|prim|prim_opentitan|tlul)/")


def canon(name: str) -> str:
    """Normalize known IP name variants."""
    return IP_NAME_MAP.get(name, name)


def add_unique(out: list[str], seen: set[str], value: str) -> None:
    """Append one non-empty line once."""
    value = value.strip()
    if value and value not in seen:
        seen.add(value)
        out.append(value)


def add_file(out: list[str], seen: set[str], path: Path) -> None:
    """Append one existing file as an absolute path."""
    if path.exists():
        add_unique(out, seen, str(path.resolve()))


def common_dirs(repo_root: Path) -> list[Path]:
    """Return shared RTL include directories."""
    root = repo_root / "hw" / "ips"
    return [root / "pkgs", root / "prim", root / "prim_opentitan", root / "tlul"]


def common_files(repo_root: Path) -> list[Path]:
    """Return shared package and primitive RTL files."""
    pkgs, prim, prim_ot, tlul = common_dirs(repo_root)
    packages = [
        pkgs / "top_pkg.sv",
        prim / "prim_reg_pkg.sv",
        pkgs / "prim_mubi_pkg.sv",
        pkgs / "prim_secded_pkg.sv",
        pkgs / "prim_subreg_pkg.sv",
        pkgs / "prim_util_pkg.sv",
        pkgs / "tlul_pkg.sv",
        pkgs / "prim_assert.sv",
        pkgs / "prim_count_pkg.sv",
        pkgs / "prim_flop_macros.sv",
        pkgs / "prim_alert_pkg.sv",
    ]
    return packages + sorted(p for p in prim.glob("*.sv") if p.name != "prim_reg_pkg.sv") + sorted(prim_ot.glob("*.sv")) + sorted(tlul.glob("*.sv"))


def local_ip_files(top: str, rtldir: Path) -> list[Path]:
    """Return local IP RTL files in compile order."""
    pkg, other, core, top_file = [], [], None, None
    for path in sorted(rtldir.glob("*.sv")):
        if path.name == f"{top}_core.sv":
            core = path
        elif path.name == f"{top}.sv":
            top_file = path
        elif "pkg" in path.name:
            pkg.append(path)
        else:
            other.append(path)
    return [*pkg, *other, *([core] if core else []), *([top_file] if top_file else [])]


def write_lines(path: Path, lines: list[str]) -> Path:
    """Write one filelist."""
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")
    return path


def split_common_ip(lines: list[str]) -> tuple[list[str], list[str]]:
    """Split merged filelist lines into common and IP lists."""
    common, ip, seen_common, seen_ip = [], [], set(), set()
    for line in lines:
        if COMMON_RE.search(line):
            add_unique(common, seen_common, line)
        else:
            add_unique(ip, seen_ip, line)
    return common, ip


def read_filelist(path: Path) -> list[str]:
    """Read raw filelist lines if the file exists."""
    if not path.exists():
        return []
    return [line.strip() for line in path.read_text(encoding="utf-8").splitlines() if line.strip()]


def remap_soc_line(line: str, ip_rtl_dir: Path) -> str | None:
    """Map one bundled IP filelist line into the SoC run."""
    if not line or line.startswith("#") or line.startswith("+incdir+"):
        return None
    path = Path(line)
    if path.is_absolute() and COMMON_RE.search(path.as_posix()):
        return str(path.resolve())
    return str((ip_rtl_dir / path.name).resolve())


def write_ip_lists(top: str, common_out: Path, ip_out: Path, rtldir: Path, repo_root: Path) -> None:
    """Write clean IP common/IP filelists."""
    common, ip = ["# Auto-generated common RTL"], ["# Auto-generated IP RTL"]
    seen_common, seen_ip = set(common), set(ip)
    for path in common_dirs(repo_root):
        add_unique(common, seen_common, f"+incdir+{path.resolve()}")
    add_unique(ip, seen_ip, f"+incdir+{rtldir.resolve()}")
    for path in common_files(repo_root):
        add_file(common, seen_common, path)
    for path in local_ip_files(top, rtldir):
        add_file(ip, seen_ip, path)
    write_lines(common_out, common)
    write_lines(ip_out, ip)


def write_soc_lists(top: str, common_out: Path, ip_out: Path, run_dir: Path, repo_root: Path) -> None:
    """Write clean SoC common/IP filelists."""
    common, ip = ["# Auto-generated common RTL"], ["# Auto-generated SoC/IP RTL"]
    seen_common, seen_ip = set(common), set(ip)
    for path in common_dirs(repo_root):
        add_unique(common, seen_common, f"+incdir+{path.resolve()}")
    for path in common_files(repo_root):
        add_file(common, seen_common, path)
    for ip_dir in sorted((run_dir / "ips").glob("*")):
        rtl = ip_dir / "rtl"
        lines = read_filelist(rtl / "rtl_ip.f") or read_filelist(rtl / "rtl_list.f")
        for line in lines:
            mapped = remap_soc_line(line, rtl)
            if mapped:
                add_unique(ip, seen_ip, mapped)
        if not lines:
            name = canon(ip_dir.name)
            for path in sorted(rtl.glob("*.sv")) + sorted(rtl.glob("*.v")):
                add_file(ip, seen_ip, path)
            for name_part in ("reg_pkg", "reg_top", "core"):
                add_file(ip, seen_ip, rtl / f"{name}_{name_part}.sv")
            add_file(ip, seen_ip, rtl / f"{name}.sv")
    rtl_dir = run_dir / "rtl"
    for path in (rtl_dir / "tl_main_pkg.sv", rtl_dir / "xbar_main.sv", rtl_dir / f"{top}.sv"):
        add_file(ip, seen_ip, path)
    write_lines(common_out, common)
    write_lines(ip_out, ip)


def write_legacy_merged(out: Path, common: Path, ip: Path) -> None:
    """Write a temporary merged list only for old direct callers."""
    lines = read_filelist(common) + read_filelist(ip)
    write_lines(out, lines or ["# Empty FlexSoC filelist"])


def parse_args() -> argparse.Namespace:
    """Parse filelist generator arguments."""
    ap = argparse.ArgumentParser(description="Generate FlexSoC RTL filelists.")
    ap.add_argument("--top", required=True)
    ap.add_argument("--out")
    ap.add_argument("--common-out")
    ap.add_argument("--ip-out")
    ap.add_argument("--ips-root")
    ap.add_argument("--rtldir")
    ap.add_argument("--workspace")
    ap.add_argument("--run-top")
    ap.add_argument("--run-id")
    ap.add_argument("--soc", action="store_true")
    return ap.parse_args()


def main() -> int:
    """Run the filelist generator."""
    args = parse_args()
    repo_root = Path(__file__).resolve().parents[3]
    out = Path(args.out).expanduser().resolve() if args.out else None
    common = Path(args.common_out or (out.parent / "rtl_common.f" if out else "rtl_common.f")).expanduser().resolve()
    ip = Path(args.ip_out or (out.parent / "rtl_ip.f" if out else "rtl_ip.f")).expanduser().resolve()

    if args.soc:
        if not args.workspace or not args.run_top or not args.run_id:
            raise SystemExit("ERROR: --soc requires --workspace --run-top --run-id")
        run_dir = Path(args.workspace).expanduser().resolve() / "runs" / args.run_top / args.run_id
        write_soc_lists(args.top, common, ip, run_dir, repo_root)
    else:
        if not args.rtldir:
            raise SystemExit("ERROR: IP mode requires --rtldir")
        write_ip_lists(args.top, common, ip, Path(args.rtldir).expanduser().resolve(), repo_root)
    if out:
        write_legacy_merged(out, common, ip)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
