# Copyright 2025 Enea Dimroci
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


import argparse
import json
import sys

def parse_args():
    parser = argparse.ArgumentParser(
        description="Generate a crossbar configuration JSON."
    )

    parser.add_argument(
        '--device',
        action='append',
        nargs=3,
        metavar=('NAME', 'BASE_ADDR', 'SIZE_BYTE'),
        help='Add a device with NAME, BASE_ADDR, and SIZE_BYTE (all in hex format, e.g., 0x80000000)',
        required=True
    )

    parser.add_argument(
        '--output',
        type=str,
        help='Output JSON file (optional). If not set, prints to stdout.'
    )

    return parser.parse_args()

def build_xbar_config(devices):
    xbar_config = {
        "name": "main",
        "type": "xbar",
        "clock": "clk_i",
        "clock_connections": {
            "clk_i": "main",
        },
        "reset": "rst_ni",
        "reset_connections": {
            "rst_ni": "main",
        },
        "nodes": [
            {
                "name": "ibex_lsu",
                "type": "host",
                "clock": "clk_i",
                "reset": "rst_ni",
                "xbar": False,
                "pipeline": False
            }
        ],
        "connections": {
            "ibex_lsu": []
        }
    }

    for name, base_addr, size_byte in devices:
        device_node = {
            "name": name,
            "type": "device",
            "clock": "clk_i",
            "reset": "rst_ni",
            "xbar": False,
            "addr_range": [{
                "base_addr": base_addr,
                "size_byte": size_byte
            }]
        }
        xbar_config["nodes"].append(device_node)
        xbar_config["connections"]["ibex_lsu"].append(name)

    return xbar_config

def main():
    args = parse_args()
    config = build_xbar_config(args.device)

    if args.output:
        with open(args.output, 'w') as f:
            json.dump(config, f, indent=2)
    else:
        print(json.dumps(config, indent=2))

if __name__ == '__main__':
    main()

