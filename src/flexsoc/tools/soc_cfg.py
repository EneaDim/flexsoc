from __future__ import annotations

import argparse
from pathlib import Path

KNOWN_BASES = {
    "uart": 0x80000000,
    "pwm": 0x80020000,
    "gpio": 0x80040000,
    "rv_timer": 0x80060000,
    "spi_host": 0x80080000,
}
ALIASES = {
    "uart-master": "uart",
    "uart_master": "uart",
    "ibex-core": "ibex",
    "ibex_core": "ibex",
}
BASE_START = 0x800A0000
BASE_STEP = 0x00020000
DEFAULT_SIZE = 0x00001000


def _run_dir(workspace: str, run_top: str, run_id: str) -> Path:
    return Path(workspace).expanduser().resolve() / "runs" / run_top / run_id


def _canon(name: str) -> str:
    return ALIASES.get(name, name)


def _loaded_ips(workspace: str, run_top: str, run_id: str) -> list[str]:
    ips_dir = _run_dir(workspace, run_top, run_id) / "ips"
    if not ips_dir.exists():
        return []
    return sorted(_canon(p.name) for p in ips_dir.iterdir() if p.is_dir())


def _resolve_host(ip_names: list[str], default_host: str | None) -> str:
    names = set(ip_names)
    if "ibex" in names or "ibex_top_tracing" in names:
        return "ibex"
    if "uart" in names:
        return "uart"
    if default_host:
        return default_host
    raise SystemExit("ERROR: cannot resolve host automatically. Load 'ibex' or 'uart', or pass HOST=...")


def _build_devices(ip_names: list[str], host: str):
    devices: list[tuple[str, str, str, str]] = []

    if host == "ibex":
        devices.append(("sram", "0x00100000", "0x00100000", "True"))

    next_base = BASE_START
    used_bases = set(KNOWN_BASES.values())

    seen: set[str] = set()
    for raw_ip in ip_names:
        ip = _canon(raw_ip)
        if ip in seen:
            continue
        seen.add(ip)

        if ip in {"ibex", "ibex_top_tracing"}:
            continue
        if host == "uart" and ip == "uart":
            continue

        if ip in KNOWN_BASES:
            base = KNOWN_BASES[ip]
        else:
            while next_base in used_bases:
                next_base += BASE_STEP
            base = next_base
            used_bases.add(base)
            next_base += BASE_STEP

        devices.append((ip, f"0x{base:08X}", f"0x{DEFAULT_SIZE:08X}", "False"))

    return devices


def main() -> int:
    ap = argparse.ArgumentParser(description="Generate default HOST/SOC_MEMORY_MAP make vars from loaded SoC IPs")
    ap.add_argument("--workspace", required=True)
    ap.add_argument("--run-top", required=True)
    ap.add_argument("--run-id", required=True)
    ap.add_argument("--default-host", required=False)
    args = ap.parse_args()

    ips = _loaded_ips(args.workspace, args.run_top, args.run_id)
    if not ips:
        raise SystemExit("ERROR: no loaded IPs found under workspace/runs/<run_top>/<run_id>/ips")

    host = _resolve_host(ips, args.default_host)
    devices = _build_devices(ips, host)

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
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
