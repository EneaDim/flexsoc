from __future__ import annotations

import argparse
from pathlib import Path


ALIASES = {
    "uart-master": "uart",
    "uart_master": "uart",
}


def canon(name: str) -> str:
    return ALIASES.get(name, name)


def add_path(path: Path, seen: set[str], ordered: list[str]) -> None:
    p = path.resolve()
    s = p.as_posix()
    if p.exists() and s not in seen:
        seen.add(s)
        ordered.append(s)


def remap_ip_flist_line(line: str, ip_rtl_dir: Path) -> Path:
    p = Path(line)
    if p.is_absolute():
        if "/hw/ips/" in p.as_posix():
            return p.resolve()
        return (ip_rtl_dir / p.name).resolve()
    return (ip_rtl_dir / line).resolve()


def read_ip_flist(ip_flist: Path, ip_rtl_dir: Path) -> list[Path]:
    out: list[Path] = []
    if not ip_flist.exists():
        return out

    for raw in ip_flist.read_text(encoding="utf-8").splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        if line.startswith("+incdir+"):
            continue
        out.append(remap_ip_flist_line(line, ip_rtl_dir))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--workspace", required=True)
    ap.add_argument("--run-top", required=True)
    ap.add_argument("--run-id", required=True)
    ap.add_argument("--top", required=True)
    args = ap.parse_args()

    run_dir = Path(args.workspace).expanduser().resolve() / "runs" / args.run_top / args.run_id
    rtl_dir = run_dir / "rtl"
    ips_dir = run_dir / "ips"
    out = rtl_dir / "rtl_list.f"

    rtl_dir.mkdir(parents=True, exist_ok=True)

    ordered: list[str] = []
    seen: set[str] = set()

    # First all loaded IP sources
    if ips_dir.exists():
        for ip_dir in sorted(p for p in ips_dir.iterdir() if p.is_dir()):
            ip_rtl_dir = ip_dir / "rtl"
            ip_flist = ip_rtl_dir / "rtl_list.f"

            if ip_flist.exists():
                for p in read_ip_flist(ip_flist, ip_rtl_dir):
                    add_path(p, seen, ordered)
            else:
                for p in sorted(ip_rtl_dir.glob("*.sv")):
                    add_path(p, seen, ordered)
                for p in sorted(ip_rtl_dir.glob("*.v")):
                    add_path(p, seen, ordered)

            name = canon(ip_dir.name)
            add_path(ip_rtl_dir / f"{name}_reg_pkg.sv", seen, ordered)
            add_path(ip_rtl_dir / f"{name}_reg_top.sv", seen, ordered)
            add_path(ip_rtl_dir / f"{name}_core.sv", seen, ordered)
            add_path(ip_rtl_dir / f"{name}.sv", seen, ordered)

    # Then SoC-local generated files at the bottom
    add_path(rtl_dir / "tl_main_pkg.sv", seen, ordered)
    add_path(rtl_dir / "xbar_main.sv", seen, ordered)
    add_path(rtl_dir / f"{args.top}.sv", seen, ordered)

    out.write_text("\n".join(ordered) + "\n", encoding="utf-8")
    print(out)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
