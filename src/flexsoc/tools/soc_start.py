from __future__ import annotations

import argparse
from pathlib import Path


def _abs(path: str | Path) -> Path:
    return Path(path).expanduser().resolve()


def _loaded_ips(ips_dir: Path) -> list[Path]:
    return sorted(p for p in ips_dir.iterdir() if p.is_dir())


def _read_rtl_list(ip_dir: Path) -> list[str]:
    flist = ip_dir / "rtl" / "rtl_list.f"
    if not flist.exists():
        return []
    out: list[str] = []
    for raw in flist.read_text(encoding="utf-8").splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        out.append(line)
    return out


def _fallback_rtl_sources(ip_dir: Path) -> list[str]:
    rtl_dir = ip_dir / "rtl"
    if not rtl_dir.exists():
        return []
    files = sorted(rtl_dir.glob("*.sv")) + sorted(rtl_dir.glob("*.v"))
    return [f.resolve().as_posix() for f in files if f.is_file()]


def main() -> int:
    ap = argparse.ArgumentParser(description="Initialize a SoC run from loaded IP bundles.")
    ap.add_argument("--workspace", required=True)
    ap.add_argument("--run-top", required=True)
    ap.add_argument("--run-id", required=True)
    args = ap.parse_args()

    workspace = _abs(args.workspace)
    run_dir = workspace / "runs" / args.run_top / args.run_id
    ips_dir = run_dir / "ips"

    if not ips_dir.exists():
        raise SystemExit(f"ERROR: missing ips directory: {ips_dir}")

    ips = _loaded_ips(ips_dir)
    if not ips:
        raise SystemExit(f"ERROR: no loaded IPs under: {ips_dir}")

    rtl_dir = run_dir / "rtl"
    tb_dir = run_dir / "tb"
    sim_dir = run_dir / "sim"
    logs_dir = run_dir / "logs"
    doc_dir = run_dir / "doc"

    for d in (rtl_dir, tb_dir, sim_dir, logs_dir, doc_dir):
        d.mkdir(parents=True, exist_ok=True)

    loaded_ips_txt = ips_dir / "loaded_ips.txt"
    loaded_ips_txt.write_text("".join(f"{ip.name}\n" for ip in ips), encoding="utf-8")

    merged: list[str] = []
    seen: set[str] = set()
    for ip in ips:
        lines = _read_rtl_list(ip)
        if not lines:
            lines = _fallback_rtl_sources(ip)
        for line in lines:
            if line in seen:
                continue
            seen.add(line)
            merged.append(line)

    if not merged:
        raise SystemExit(f"ERROR: no RTL sources found under loaded IPs in: {ips_dir}")

    (rtl_dir / "rtl_list.f").write_text("\n".join(merged) + "\n", encoding="utf-8")

    summary = [
        f"run_top={args.run_top}",
        f"run_id={args.run_id}",
        f"run_dir={run_dir}",
        f"loaded_ips={len(ips)}",
        f"rtl_list={rtl_dir / 'rtl_list.f'}",
    ]
    (doc_dir / "soc_start.txt").write_text("\n".join(summary) + "\n", encoding="utf-8")

    print(f"Initialized SoC run: {run_dir}")
    print(f"Loaded IPs: {', '.join(ip.name for ip in ips)}")
    print(f"RTL filelist: {rtl_dir / 'rtl_list.f'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
