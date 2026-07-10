# FlexSoC CLI

`fx` is the user CLI for FlexSoC. It is intentionally small: it saves project
settings, exposes backend targets, previews commands, and runs targets through
the public `FlexSoC` API.

```text
fx -> FlexSoC API -> src/flexsoc/backend/Makefile -> backend generators/tools
```

## Install and activate

```bash
make install
source .venv/bin/activate
```

`make install` installs the editable package with the `dev` and `flow` extras
from `pyproject.toml`.

## Command surface

```bash
fx help
fx commands
fx settings
fx TARGET [TARGET...]
fx TARGET --info
fx smoke
```

Examples of direct targets are `setup`, `hjson`, `reg`, `doc`, `rtl_stub`,
`flist`, `setup_tb`, `setup_cocotb`, `setup_model`, `sim`, `syn`, `sta`,
`power`, `pnr`, `cocotb`, `view_cocotb`, `soc_uart_gen`, and `soc_ibex_gen`.
When more than one target is provided, FlexSoC runs them in the given order.

## Settings

Save defaults for repeated commands:

```bash
fx settings --set TOP=quick_ip --set RUN_TOP=quick_ip --set RUN_ID=smoke --set HOST=uart
fx settings
```

Use `--set KEY=VALUE` on a target for a one-command override. It does not update
`.flexsoc/settings.json`.

```bash
fx lint --set TOP=cordic --set RUN_TOP=cordic --set RUN_ID=smoke
```

Reset saved defaults:

```bash
fx settings --reset
```

## Discovery and previews

```bash
fx commands
fx hjson --info
fx cocotb --info
fx setup hjson reg doc --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx setup hjson reg doc --dry-run --json --set TOP=demo --set RUN_ID=smoke
```

Use `--capture` when you want command output captured and reported by the CLI:

```bash
fx setup --capture
```

## IP from scratch

```bash
fx settings --set TOP=quick_ip --set RUN_TOP=quick_ip --set RUN_ID=smoke --set HOST=uart
fx setup hjson reg doc rtl_stub flist setup_tb setup_cocotb setup_model --force
```

This creates the workspace, HJSON regmap, register RTL, docs, RTL stub, filelist,
SystemVerilog testbench, Cocotb scaffold, generated vectors, register configs,
and Python model.

Run generated tests:

```bash
fx cocotb --set TEST_NAME=smoke
fx cocotb --set TEST_NAME=corners
fx cocotb --set TEST_NAME=random
```

Open the latest Cocotb waveform:

```bash
fx view_cocotb --set TEST_NAME=random
```

## Existing IP

Example with `cordic`:

```bash
fx ip_load flist setup_tb setup_cocotb setup_model \
  --force \
  --set TOP=cordic \
  --set RUN_TOP=cordic \
  --set RUN_ID=smoke

fx cocotb --set TOP=cordic --set RUN_TOP=cordic --set RUN_ID=smoke --set TEST_NAME=smoke
```

If an existing IP has no generic top-level datapath pair, the generated register
configuration still runs and the generic vector checker is skipped. Add an
IP-specific checker when the datapath behavior is defined.

## Generated verification files

For each run, `setup_tb`, `setup_cocotb`, and `setup_model` generate:

```text
workspace/runs/<RUN_TOP>/<RUN_ID>/tb/
├── <top>_tb.sv
├── <top>_reg_sequence.svh
├── tests/<test>/config.regs
├── tests/<test>/<test>.vec
└── cocotb/
    ├── <top>_tb.py
    ├── model_<top>.py
    └── drivers/{reg_driver.py,vec_driver.py,vec_monitor.py}
```

The generated tests are `smoke`, `corners`, and `random`.

`config.regs` lists all software-writable registers from the HJSON regmap:

```text
# write <CLOCK.REG_NAME> <DATA> [MASK] [WAIT_CYCLES] [NOTE]
write clk_i.CTRL 0x00000001
write clk_i.WDATA 0x00000002
```

`.vec` files drive datapath values and expected results. The note field is
optional:

```text
# cycle input expected latency mask [note]
0 0x00000000 0x00000000 2 0xffffffff
1 0x00000001 0x00000001 2 0xffffffff smoke_1
```

## SoC generation

UART-host SoC:

```bash
fx ip_load --force --set TOP=uart-master --set LOAD_AS=uart --set RUN_TOP=soc_uart
fx ip_load --force --set TOP=gpio        --set RUN_TOP=soc_uart
fx ip_load --force --set TOP=rv_timer    --set RUN_TOP=soc_uart
fx ip_load --force --set TOP=pwm         --set RUN_TOP=soc_uart
fx soc_uart_gen --set TOP=soc --set RUN_TOP=soc_uart --set HOST=uart --set SOC_CFG_MODE=builtin
```

Ibex-host SoC:

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

Build/run only after the required software and simulator tools are installed:

```bash
fx soc_build_sw soc_sim soc_run --set TOP=soc --set RUN_TOP=soc_uart --set HOST=uart
```

## Lint

```bash
fx lint
fx lint-latch
fx lint-undriven
fx lint-width
fx lint-unconnected
fx lint-unused
```

Use `--tool auto|verilator|slang` to select the lint backend. `auto` prefers
Verilator when available, otherwise `slang`.

## Useful maintenance commands

```bash
make lint
make test
fx smoke --json
fx clean_all
```

Use `--dry-run --script` before running EDA-heavy targets in a new environment.
