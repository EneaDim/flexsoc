"""Build OpenTitan-style crossbar JSON configuration.

This utility remains functional so API and CLI callers can reuse it later.
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any


def normalize_host(host: str) -> str:
    """Map user-facing host names to generated crossbar node names."""

    return "uart_host" if host == "uart" else "ibex"


def build_xbar_config(host: str, devices: list[list[str]]) -> dict[str, Any]:
    """Build a JSON-ready crossbar configuration from host and device rows."""

    host_name = normalize_host(host)
    config: dict[str, Any] = {
        "name": "main",
        "type": "xbar",
        "clock": "clk_i",
        "clock_connections": {"clk_i": "main"},
        "reset": "rst_ni",
        "reset_connections": {"rst_ni": "main"},
        "nodes": [{"name": host_name, "type": "host", "clock": "clk_i", "reset": "rst_ni", "xbar": False, "pipeline": False}],
        "connections": {host_name: []},
    }
    for name, base_addr, size_byte, _from_lr in devices:
        config["nodes"].append(
            {
                "name": name,
                "type": "device",
                "clock": "clk_i",
                "reset": "rst_ni",
                "xbar": False,
                "addr_range": [{"base_addr": base_addr, "size_byte": size_byte}],
            }
        )
        config["connections"][host_name].append(name)
    return config


def write_json(path: Path, payload: dict[str, Any]) -> Path:
    """Write a JSON payload to disk and return the resolved path."""

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    return path.resolve()


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
    config = build_xbar_config(args.host, args.device)
    if args.output:
        write_json(Path(args.output), config)
    else:
        print(json.dumps(config, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
