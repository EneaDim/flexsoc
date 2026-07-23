<p align="center">
<img src="assets/open-IP-SoC-logo.png" alt="FlexSoC logo" width="300"/>
</p>

# FlexSoC

FlexSoC is a Python package for IP development, generated verification, and SoC
integration. Users enter through the `fx` CLI or the `FlexSoC` Python API; both
route into the canonical backend Makefile.

```text
fx / Python API
    ↓
FlexSoC API layer
    ↓
src/flexsoc/backend/Makefile
    ↓
backend generators and external EDA tools
```

## Install

```bash
make install
source .venv/bin/activate
make test
```

`make install` uses `uv` and installs the editable package with the development
and flow extras from `pyproject.toml`.

## Quickstart

Discover commands and inspect a backend target:

```bash
fx commands
fx hjson --info
```

Save the default run context once:

```bash
fx settings --set TOP=quick_ip --set RUN_TOP=quick_ip --set RUN_ID=smoke --set HOST=uart
fx settings
```

Preview a generator path before running it:

```bash
fx setup hjson reg doc --dry-run --script
```

Generate a small IP with RTL, SystemVerilog TB, Cocotb scaffold, vectors, and a
Python model:

```bash
fx setup hjson reg doc rtl_stub flist setup_tb setup_cocotb setup_model --force
```

Run Cocotb with one generated test:

```bash
fx cocotb --set TEST_NAME=smoke
fx cocotb --set TEST_NAME=corners
fx cocotb --set TEST_NAME=random
```

Open the latest Cocotb waveform:

```bash
fx view_cocotb --set TEST_NAME=random
```

## Generated verification layout

`setup_tb`, `setup_cocotb`, and `setup_model` generate a shared verification
layout under the active run:

```text
workspace/runs/<RUN_TOP>/<RUN_ID>/
├── tb/
│   ├── <top>_tb.sv
│   ├── <top>_reg_sequence.svh
│   ├── <top>_vec_driver.svh          # generated only when useful
│   ├── <top>_vec_monitor.svh         # generated only when useful
│   ├── tests/
│   │   ├── smoke/config.regs + smoke.vec
│   │   ├── corners/config.regs + corners.vec
│   │   └── random/config.regs + random.vec
│   └── cocotb/
│       ├── <top>_tb.py
│       ├── model_<top>.py
│       └── drivers/
│           ├── reg_driver.py
│           ├── vec_driver.py
│           └── vec_monitor.py
└── model/model_<top>.py
```

Each `config.regs` contains all software-writable registers found in the HJSON
regmap. Config files use register names, not raw addresses:

```text
write clk_i.CTRL 0x00000001
write clk_i.WDATA 0x00000002
```

Each `.vec` file contains datapath stimuli and expected values. The final note is
optional:

```text
# cycle input expected latency mask [note]
0 0x00000000 0x00000000 2 0xffffffff
1 0x00000001 0x00000001 2 0xffffffff smoke_1
```

## Existing IP example

Load an existing IP and generate the same verification structure:

```bash
fx ip_load flist setup_tb setup_cocotb setup_model \
  --force \
  --set TOP=cordic \
  --set RUN_TOP=cordic \
  --set RUN_ID=smoke

fx cocotb --set TOP=cordic --set RUN_TOP=cordic --set RUN_ID=smoke --set TEST_NAME=smoke
```

For IPs without a simple top-level datapath pair, the generic vector check is
skipped and the register configuration still runs. Add an IP-specific model or
checker when the datapath contract is known.

## SoC examples

UART-host SoC generation:

```bash
fx ip_load --force --set TOP=uart-master --set LOAD_AS=uart --set RUN_TOP=soc_uart
fx ip_load --force --set TOP=gpio        --set RUN_TOP=soc_uart
fx ip_load --force --set TOP=rv_timer    --set RUN_TOP=soc_uart
fx ip_load --force --set TOP=pwm         --set RUN_TOP=soc_uart
fx soc_uart_gen --set TOP=soc --set RUN_TOP=soc_uart --set HOST=uart --set SOC_CFG_MODE=builtin
```

Ibex-host SoC generation:

```bash
fx fetch --set VENDOR=lowrisc_ip
fx fetch --set VENDOR=lowrisc_ibex
fx ip_load --force --set TOP=uart     --set RUN_TOP=soc_ibex
fx ip_load --force --set TOP=gpio     --set RUN_TOP=soc_ibex
fx ip_load --force --set TOP=rv_timer --set RUN_TOP=soc_ibex
fx ip_load --force --set TOP=pwm      --set RUN_TOP=soc_ibex
fx ip_load --force --set TOP=spi_host --set RUN_TOP=soc_ibex
fx soc_ibex_gen --set TOP=soc --set RUN_TOP=soc_ibex --set HOST=ibex --set SOC_CFG_MODE=builtin
```

Build and run software/simulation only after the required external tools are
installed:

```bash
fx soc_build_sw soc_run --set TOP=soc --set RUN_TOP=soc_uart --set HOST=uart
```

## Development checks

```bash
make lint
make test
fx smoke
fx smoke --json
```

Use `--dry-run --script` before EDA-dependent targets such as `sim`, `syn`,
`sta`, `power`, `pnr`, `cocotb`, and SoC simulation targets.

## Documentation

- `docs/CLI.md` explains day-to-day `fx` usage.
- `docs/API.md` documents the Python API layer.
- `docs/ARCHITECTURE.md` describes the package and generated verification architecture.
- `docs/FLOW_SMOKE.md` gives a short validation checklist.
