"""Build OpenTitan-style crossbar JSON configuration.

Small config objects keep crossbar generation import-safe and API friendly.
"""

from __future__ import annotations

import argparse
import json
from dataclasses import dataclass
from pathlib import Path
from typing import Any


@dataclass(frozen=True, slots=True)
class XbarDevice:
    """Describe one device node attached to the generated crossbar."""

    name: str
    base_addr: str
    size_byte: str
    from_lr: str = "False"


@dataclass(frozen=True, slots=True)
class XbarConfig:
    """Group all inputs needed to render one crossbar configuration."""

    host: str
    devices: tuple[XbarDevice, ...]


def normalize_host(host: str) -> str:
    """Map user-facing host names to generated crossbar node names."""

    return "uart_host" if host.strip().lower() == "uart" else "ibex"


def device_node(device: XbarDevice) -> dict[str, Any]:
    """Render one device as a JSON-ready crossbar node."""

    return {
        "name": device.name,
        "type": "device",
        "clock": "clk_i",
        "reset": "rst_ni",
        "xbar": False,
        "addr_range": [{"base_addr": device.base_addr, "size_byte": device.size_byte}],
    }


def host_node(name: str) -> dict[str, Any]:
    """Render the host node shared by all generated configurations."""

    return {
        "name": name,
        "type": "host",
        "clock": "clk_i",
        "reset": "rst_ni",
        "xbar": False,
        "pipeline": False,
    }


def build_xbar_config(config: XbarConfig) -> dict[str, Any]:
    """Build a JSON-ready crossbar configuration from normalized inputs."""

    host_name = normalize_host(config.host)
    nodes = [host_node(host_name), *(device_node(device) for device in config.devices)]
    return {
        "name": "main",
        "type": "xbar",
        "clock": "clk_i",
        "clock_connections": {"clk_i": "main"},
        "reset": "rst_ni",
        "reset_connections": {"rst_ni": "main"},
        "nodes": nodes,
        "connections": {host_name: [device.name for device in config.devices]},
    }


def write_json(path: Path, payload: dict[str, Any]) -> Path:
    """Write a JSON payload to disk and return the resolved path."""

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    return path.resolve()


def parse_device_rows(rows: list[list[str]]) -> tuple[XbarDevice, ...]:
    """Convert argparse device rows into typed crossbar devices."""

    return tuple(XbarDevice(name, base_addr, size_byte, from_lr) for name, base_addr, size_byte, from_lr in rows)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse command line options for crossbar generation."""

    parser = argparse.ArgumentParser(description="Generate a crossbar configuration JSON.")
    parser.add_argument("--device", action="append", nargs=4, metavar=("NAME", "BASE_ADDR", "SIZE_BYTE", "FROM_LR"), required=True)
    parser.add_argument("--host", required=True)
    parser.add_argument("--output")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Generate crossbar JSON from CLI options."""

    args = parse_args(argv)
    config = XbarConfig(args.host, parse_device_rows(args.device))
    payload = build_xbar_config(config)
    if args.output:
        write_json(Path(args.output), payload)
    else:
        print(json.dumps(payload, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
