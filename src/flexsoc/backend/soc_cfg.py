"""Resolve SoC host/device configuration for Make and generator steps.

The module converts a run workspace into one small, importable config object.
"""

from __future__ import annotations

import argparse
from dataclasses import dataclass
from pathlib import Path

SUPPORTED_HOSTS = {"ibex", "uart"}
KNOWN_BASES = {
    "uart": 0x80000000,
    "uart-master": 0x80000000,
    "pwm": 0x80020000,
    "gpio": 0x80040000,
    "rv_timer": 0x80060000,
    "spi_host": 0x80080000,
}
HOST_IPS = {"ibex", "ibex_top_tracing"}


@dataclass(frozen=True, slots=True)
class SoCDevice:
    """Describe one memory-mapped device used by generated SoC flows."""

    name: str
    base: str
    size: str = "0x00001000"
    from_lr: str = "False"

    def make_call(self) -> str:
        """Render this device as one Make `add_device` evaluation."""

        return f"$(eval $(call add_device,{self.name},{self.base},{self.size},{self.from_lr}))"

    def args(self) -> tuple[str, str, str, str]:
        """Return CLI argument fields consumed by SoC backend generators."""

        return self.name, self.base, self.size, self.from_lr


@dataclass(frozen=True, slots=True)
class SoCConfig:
    """Resolved host and memory map emitted for one SoC run."""

    host: str
    devices: tuple[SoCDevice, ...]

    def args(self) -> tuple[str, ...]:
        """Return flat generator arguments for host and devices."""

        parts = ["--host", self.host]
        for device in self.devices:
            parts.extend(("--device", *device.args()))
        return tuple(parts)


def run_dir(workspace: str | Path, run_top: str, run_id: str) -> Path:
    """Return the canonical run directory for a workspace/run identity."""

    return Path(workspace).expanduser().resolve() / "runs" / run_top / run_id


def loaded_ips(workspace: str | Path, run_top: str, run_id: str) -> tuple[str, ...]:
    """List IP directories staged under a run workspace."""

    ips_dir = run_dir(workspace, run_top, run_id) / "ips"
    if not ips_dir.exists():
        return ()
    return tuple(sorted(path.name for path in ips_dir.iterdir() if path.is_dir()))


def builtin_devices(host: str) -> tuple[SoCDevice, ...]:
    """Return the built-in memory map for a supported host profile."""

    if host == "ibex":
        return (
            SoCDevice("sram", "0x00100000", "0x00100000", "True"),
            SoCDevice("uart", "0x80000000"),
            SoCDevice("pwm", "0x80020000"),
            SoCDevice("gpio", "0x80040000"),
            SoCDevice("rv_timer", "0x80060000"),
            SoCDevice("spi_host", "0x80080000"),
        )
    if host == "uart":
        return (
            SoCDevice("uart", "0x80000000"),
            SoCDevice("pwm", "0x80020000"),
            SoCDevice("gpio", "0x80040000"),
            SoCDevice("rv_timer", "0x80060000"),
        )
    raise SystemExit(f"ERROR: Unknown HOST '{host}'. Supported builtin hosts: ibex, uart")


def normalize_host(host: str | None) -> str | None:
    """Normalize and validate an optional host override."""

    if not host:
        return None
    normalized = host.strip().lower()
    if normalized not in SUPPORTED_HOSTS:
        raise SystemExit(f"ERROR: unsupported host '{host}'. Use ibex or uart.")
    return normalized


def resolve_host(ip_names: tuple[str, ...], default_host: str | None = None) -> str:
    """Resolve the host profile from an explicit hint or staged IP names."""

    if default_host:
        return default_host
    names = set(ip_names)
    if names & HOST_IPS:
        return "ibex"
    if names & {"uart", "uart-master"}:
        return "uart"
    raise SystemExit("ERROR: no loaded IPs found under workspace/runs/<run_top>/<run_id>/ips")


def workspace_devices(ip_names: tuple[str, ...], host: str) -> tuple[SoCDevice, ...]:
    """Build a deterministic memory map from staged workspace IP names."""

    devices = [SoCDevice("sram", "0x00100000", "0x00100000", "True")] if host == "ibex" else []
    next_base = 0x800A0000
    used_bases = set(KNOWN_BASES.values())

    for ip in dict.fromkeys(ip_names):
        if ip in HOST_IPS:
            continue
        base = KNOWN_BASES.get(ip)
        if base is None:
            while next_base in used_bases:
                next_base += 0x00020000
            base = next_base
            used_bases.add(base)
            next_base += 0x00020000
        devices.append(SoCDevice(ip, f"0x{base:08X}"))
    return tuple(devices)


def resolve_soc_config(
    workspace: str | Path,
    run_top: str,
    run_id: str,
    *,
    default_host: str | None = None,
    mode: str = "auto",
) -> SoCConfig:
    """Resolve a SoC config from builtin profiles, workspace IPs, or both."""

    host_hint = normalize_host(default_host)
    if mode not in {"workspace", "builtin", "auto"}:
        raise SystemExit("ERROR: --mode must be workspace, builtin, or auto")

    if mode == "builtin":
        if not host_hint:
            raise SystemExit("ERROR: --mode builtin requires --default-host <ibex|uart>")
        return SoCConfig(host_hint, builtin_devices(host_hint))

    ips = loaded_ips(workspace, run_top, run_id)
    if mode == "workspace" or ips:
        host = resolve_host(ips, host_hint)
        return SoCConfig(host, workspace_devices(ips, host))

    if host_hint:
        return SoCConfig(host_hint, builtin_devices(host_hint))
    raise SystemExit(
        "ERROR: no loaded IPs found under workspace/runs/<run_top>/<run_id>/ips "
        "and no supported builtin host selected. Use HOST=ibex or HOST=uart, or load IPs into the run."
    )


def render_make_config(config: SoCConfig) -> str:
    """Render a Make fragment containing host and device memory map data."""

    lines = [
        f"HOST ?= {config.host}",
        "DEVLIST :=",
        "define add_device",
        "DEVLIST += $(1)",
        "BASE_$(1) := $(2)",
        "SIZE_$(1) := $(3)",
        "FROM_LR_$(1) := $(4)",
        "endef",
        *(device.make_call() for device in config.devices),
        "SOC_MEMORY_MAP ?= $(foreach d,$(DEVLIST),--device $(d) $(BASE_$(d)) $(SIZE_$(d)) $(FROM_LR_$(d)))",
    ]
    return "\n".join(lines) + "\n"


def render_args(config: SoCConfig) -> str:
    """Render flat command-line arguments for SoC generators."""

    return " ".join(config.args()) + "\n"


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse command-line options for the SoC config backend."""

    parser = argparse.ArgumentParser(description="Generate HOST/SOC_MEMORY_MAP for SoC flows")
    parser.add_argument("--workspace", required=True)
    parser.add_argument("--run-top", required=True)
    parser.add_argument("--run-id", required=True)
    parser.add_argument("--default-host")
    parser.add_argument("--mode", choices=["workspace", "builtin", "auto"], default="auto")
    parser.add_argument("--format", choices=["make", "args"], default="make")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Run the SoC config backend from the command line."""

    args = parse_args(argv)
    config = resolve_soc_config(
        args.workspace,
        args.run_top,
        args.run_id,
        default_host=args.default_host,
        mode=args.mode,
    )
    print(render_args(config) if args.format == "args" else render_make_config(config), end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
