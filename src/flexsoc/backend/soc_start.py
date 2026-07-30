"""Stage generated IP bundles into one SoC run directory."""

from __future__ import annotations

import argparse
import shutil
from dataclasses import dataclass
from pathlib import Path


@dataclass(frozen=True, slots=True)
class SoCStartConfig:
    """Configuration required to initialize a SoC run."""

    workspace: Path
    run_top: str
    run_id: str

    @property
    def run_dir(self) -> Path:
        """Return the canonical run directory for this SoC build."""

        return self.workspace.expanduser().resolve() / "runs" / self.run_top / self.run_id

    @property
    def ips_dir(self) -> Path:
        """Return the directory containing staged IP bundles."""

        return self.run_dir / "ips"


def loaded_ips(ips_dir: Path) -> tuple[Path, ...]:
    """Return staged IP bundle directories sorted by name."""

    return tuple(sorted(path for path in ips_dir.iterdir() if path.is_dir()))



def _copy_tree(src: Path, dst: Path) -> bool:
    """Copy one optional verification asset tree."""

    if not src.exists():
        return False
    if dst.exists():
        shutil.rmtree(dst)
    shutil.copytree(src, dst)
    return True


def stage_ip_verification_assets(config: SoCStartConfig, ips: tuple[Path, ...]) -> Path:
    """Stage per-IP tests/models into the SoC run root."""

    manifest = config.run_dir / "tests" / "loaded_tests.txt"
    lines: list[str] = []
    for ip in ips:
        copied_tests = _copy_tree(ip / "tb" / "tests", config.run_dir / "tests" / ip.name)
        copied_model = _copy_tree(ip / "model", config.run_dir / "model" / ip.name)
        if copied_tests or copied_model:
            lines.append(f"{ip.name}: tests={int(copied_tests)} model={int(copied_model)}")
    manifest.parent.mkdir(parents=True, exist_ok=True)
    manifest.write_text("\n".join(lines) + ("\n" if lines else ""), encoding="utf-8")
    return manifest

def read_filelists(ip_dir: Path) -> tuple[str, ...]:
    """Read staged IP common/IP filelists, with legacy fallback."""

    rtl = ip_dir / "rtl"
    files = [rtl / "rtl_common.f", rtl / "rtl_ip.f"]
    if not any(path.exists() for path in files):
        files = [rtl / "rtl_list.f"]
    lines: list[str] = []
    for flist in files:
        if flist.exists():
            lines.extend(
                line
                for raw in flist.read_text(encoding="utf-8").splitlines()
                if (line := raw.strip()) and not line.startswith("#")
            )
    return tuple(lines)


def fallback_rtl_sources(ip_dir: Path) -> tuple[str, ...]:
    """Discover RTL files when an IP bundle has no explicit filelist."""

    rtl_dir = ip_dir / "rtl"
    if not rtl_dir.exists():
        return ()
    files = sorted(rtl_dir.glob("*.sv")) + sorted(rtl_dir.glob("*.v"))
    return tuple(path.resolve().as_posix() for path in files if path.is_file())


def merged_rtl_sources(ips: tuple[Path, ...]) -> tuple[str, ...]:
    """Merge IP RTL sources while preserving first-seen ordering."""

    merged: list[str] = []
    seen: set[str] = set()
    for ip_dir in ips:
        for source in read_filelists(ip_dir) or fallback_rtl_sources(ip_dir):
            if source not in seen:
                seen.add(source)
                merged.append(source)
    return tuple(merged)


def write_soc_start_summary(config: SoCStartConfig, ips: tuple[Path, ...], rtl_ip: Path) -> Path:
    """Write a compact summary for the initialized SoC run."""

    doc_dir = config.run_dir / "doc"
    doc_dir.mkdir(parents=True, exist_ok=True)
    path = doc_dir / "soc_start.txt"
    path.write_text(
        "\n".join(
            (
                f"run_top={config.run_top}",
                f"run_id={config.run_id}",
                f"run_dir={config.run_dir}",
                f"loaded_ips={len(ips)}",
                f"rtl_ip={rtl_ip}",
            )
        )
        + "\n",
        encoding="utf-8",
    )
    return path


def initialize_soc_run(config: SoCStartConfig) -> Path:
    """Create SoC run folders and write the merged RTL filelist."""

    if not config.ips_dir.exists():
        raise FileNotFoundError(f"missing ips directory: {config.ips_dir}")

    ips = loaded_ips(config.ips_dir)
    if not ips:
        raise ValueError(f"no loaded IPs under: {config.ips_dir}")

    for dirname in ("rtl", "tb", "sim", "logs", "doc", "tests", "model"):
        (config.run_dir / dirname).mkdir(parents=True, exist_ok=True)

    (config.ips_dir / "loaded_ips.txt").write_text("".join(f"{ip.name}\n" for ip in ips), encoding="utf-8")
    sources = merged_rtl_sources(ips)
    if not sources:
        raise ValueError(f"no RTL sources found under loaded IPs in: {config.ips_dir}")

    rtl_ip = config.run_dir / "rtl" / "rtl_ip.f"
    rtl_ip.write_text("\n".join(sources) + "\n", encoding="utf-8")
    (config.run_dir / "rtl" / "rtl_list.f").unlink(missing_ok=True)
    stage_ip_verification_assets(config, ips)
    write_soc_start_summary(config, ips, rtl_ip)
    return rtl_ip


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse the current SoC start command line."""

    parser = argparse.ArgumentParser(description="Initialize a SoC run from loaded IP bundles.")
    parser.add_argument("--workspace", required=True)
    parser.add_argument("--run-top", required=True)
    parser.add_argument("--run-id", required=True)
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Run the SoC start generator from CLI arguments."""

    args = parse_args(argv)
    config = SoCStartConfig(Path(args.workspace), args.run_top, args.run_id)
    try:
        initialize_soc_run(config)
    except (FileNotFoundError, ValueError) as exc:
        raise SystemExit(f"ERROR: {exc}") from exc

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
