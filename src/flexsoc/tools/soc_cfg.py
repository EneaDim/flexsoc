from __future__ import annotations

import argparse
from pathlib import Path


def _run_dir(workspace: str, run_top: str, run_id: str) -> Path:
    return Path(workspace).expanduser().resolve() / "runs" / run_top / run_id


def _loaded_ips(workspace: str, run_top: str, run_id: str) -> list[str]:
    ips_dir = _run_dir(workspace, run_top, run_id) / "ips"
    if not ips_dir.exists():
        return []
    return sorted(p.name for p in ips_dir.iterdir() if p.is_dir())


def _builtin_devices(host: str) -> list[tuple[str, str, str, str]]:
    if host == "ibex":
        return [
            ("sram", "0x00100000", "0x00100000", "True"),
            ("uart", "0x80000000", "0x00001000", "False"),
            ("pwm", "0x80020000", "0x00001000", "False"),
            ("gpio", "0x80040000", "0x00001000", "False"),
            ("rv_timer", "0x80060000", "0x00001000", "False"),
            ("spi_host", "0x80080000", "0x00001000", "False"),
        ]
    if host == "uart":
        return [
            ("uart", "0x80000000", "0x00001000", "False"),
            ("pwm", "0x80020000", "0x00001000", "False"),
            ("gpio", "0x80040000", "0x00001000", "False"),
            ("rv_timer", "0x80060000", "0x00001000", "False"),
        ]
    raise SystemExit(f"ERROR: Unknown HOST '{host}'. Supported builtin hosts: ibex, uart")


def _resolve_host_workspace(ip_names: list[str], default_host: str | None) -> str:
    # IMPORTANT: explicit host from caller wins.
    if default_host:
        return default_host

    names = set(ip_names)
    if "ibex" in names:
        return "ibex"
    if "ibex_top_tracing" in names:
        return "ibex"
    if "uart" in names or "uart-master" in names:
        return "uart"

    raise SystemExit("ERROR: no loaded IPs found under workspace/runs/<run_top>/<run_id>/ips")


def _build_devices_workspace(ip_names: list[str], host: str) -> list[tuple[str, str, str, str]]:
    devices: list[tuple[str, str, str, str]] = []

    # For ibex-hosted systems, always inject SRAM from vendor/fetched side.
    if host == "ibex":
        devices.append(("sram", "0x00100000", "0x00100000", "True"))

    known_bases = {
        "uart": 0x80000000,
        "uart-master": 0x80000000,
        "pwm": 0x80020000,
        "gpio": 0x80040000,
        "rv_timer": 0x80060000,
        "spi_host": 0x80080000,
    }

    next_base = 0x800A0000
    used_bases = set(known_bases.values())
    seen: set[str] = set()

    for ip in ip_names:
        if ip in seen:
            continue
        seen.add(ip)

        # CPU is the host, not a mapped peripheral device here.
        if ip in {"ibex", "ibex_top_tracing"}:
            continue

        if ip in known_bases:
            base = known_bases[ip]
        else:
            while next_base in used_bases:
                next_base += 0x00020000
            base = next_base
            used_bases.add(base)
            next_base += 0x00020000

        devices.append((ip, f"0x{base:08X}", "0x00001000", "False"))

    return devices


def emit_make(host: str, devices: list[tuple[str, str, str, str]]) -> None:
    print(f"HOST ?= {host}")
    print("DEVLIST :=")
    print("define add_device")
    print("DEVLIST += $(1)")
    print("BASE_$(1) := $(2)")
    print("SIZE_$(1) := $(3)")
    print("FROM_LR_$(1) := $(4)")
    print("endef")
    for name, base, size, from_lr in devices:
        print(f"$(eval $(call add_device,{name},{base},{size},{from_lr}))")
    print('SOC_MEMORY_MAP ?= $(foreach d,$(DEVLIST),--device $(d) $(BASE_$(d)) $(SIZE_$(d)) $(FROM_LR_$(d)))')


def emit_args(host: str, devices: list[tuple[str, str, str, str]]) -> None:
    parts = [f"--host {host}"]
    for name, base, size, from_lr in devices:
        parts.append(f"--device {name} {base} {size} {from_lr}")
    print(" ".join(parts))


def main() -> int:
    ap = argparse.ArgumentParser(description="Generate HOST/SOC_MEMORY_MAP for SoC flows")
    ap.add_argument("--workspace", required=True)
    ap.add_argument("--run-top", required=True)
    ap.add_argument("--run-id", required=True)
    ap.add_argument("--default-host", required=False)
    ap.add_argument("--mode", choices=["workspace", "builtin", "auto"], default="auto")
    ap.add_argument("--format", choices=["make", "args"], default="make")
    args = ap.parse_args()

    host_hint = args.default_host.strip().lower() if args.default_host else None
    if host_hint not in {None, "ibex", "uart"}:
        raise SystemExit(f"ERROR: unsupported --default-host '{args.default_host}'. Use ibex or uart.")

    if args.mode == "builtin":
        if not host_hint:
            raise SystemExit("ERROR: --mode builtin requires --default-host <ibex|uart>")
        host = host_hint
        devices = _builtin_devices(host)

    elif args.mode == "workspace":
        ips = _loaded_ips(args.workspace, args.run_top, args.run_id)
        host = _resolve_host_workspace(ips, host_hint)
        devices = _build_devices_workspace(ips, host)

    else:  # auto
        ips = _loaded_ips(args.workspace, args.run_top, args.run_id)
        if ips:
            host = _resolve_host_workspace(ips, host_hint)
            devices = _build_devices_workspace(ips, host)
        else:
            if host_hint in {"ibex", "uart"}:
                host = host_hint
                devices = _builtin_devices(host)
            else:
                raise SystemExit(
                    "ERROR: no loaded IPs found under workspace/runs/<run_top>/<run_id>/ips "
                    "and no supported builtin host selected. Use HOST=ibex or HOST=uart, "
                    "or load IPs into the run."
                )

    if args.format == "args":
        emit_args(host, devices)
    else:
        emit_make(host, devices)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
