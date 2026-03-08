# ruff: noqa
import argparse
import json
from pathlib import Path


def parse_args():
    parser = argparse.ArgumentParser(description="Generate a crossbar configuration JSON.")
    parser.add_argument(
        "--device",
        action="append",
        nargs=4,
        metavar=("NAME", "BASE_ADDR", "SIZE_BYTE", "FROM_LR"),
        help="Add a device with NAME, BASE_ADDR, SIZE_BYTE, FROM_LR",
        required=True,
    )
    parser.add_argument("--host", type=str, required=True)
    parser.add_argument("--output", type=str, required=False)
    return parser.parse_args()


def build_xbar_config(host, devices):
    host = "uart_host" if host == "uart" else "ibex"
    xbar_config = {
        "name": "main",
        "type": "xbar",
        "clock": "clk_i",
        "clock_connections": {"clk_i": "main"},
        "reset": "rst_ni",
        "reset_connections": {"rst_ni": "main"},
        "nodes": [
            {
                "name": host,
                "type": "host",
                "clock": "clk_i",
                "reset": "rst_ni",
                "xbar": False,
                "pipeline": False,
            }
        ],
        "connections": {host: []},
    }

    for name, base_addr, size_byte, _from_lr in devices:
        xbar_config["nodes"].append(
            {
                "name": name,
                "type": "device",
                "clock": "clk_i",
                "reset": "rst_ni",
                "xbar": False,
                "addr_range": [{"base_addr": base_addr, "size_byte": size_byte}],
            }
        )
        xbar_config["connections"][host].append(name)

    return xbar_config


def main():
    args = parse_args()
    config = build_xbar_config(args.host, args.device)

    if args.output:
        out = Path(args.output)
        out.parent.mkdir(parents=True, exist_ok=True)
        with out.open("w", encoding="utf-8") as f:
            json.dump(config, f, indent=2)
    else:
        print(json.dumps(config, indent=2))


if __name__ == "__main__":
    main()
