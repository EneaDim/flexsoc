# FlexSoC Architecture

FlexSoC has one public API layer, one compact CLI, and one canonical backend
Makefile. Generated files live in the workspace; source files stay under
`src/flexsoc` and `hw/`.

```text
fx / Python API
    ↓
FlexSoC API layer
    ↓
src/flexsoc/backend/Makefile
    ↓
backend Python generators and external tools
```

## Package layout

```text
src/flexsoc/
├── __init__.py          # public package exports
├── __main__.py          # python -m flexsoc entrypoint
├── api.py               # public API facade
├── cli.py               # fx CLI frontend
└── backend/
    ├── Makefile         # canonical flow runner
    ├── setup_tb.py      # SystemVerilog TB generator
    ├── setup_cocotb.py  # Cocotb scaffold generator
    ├── setup_model.py   # Python model generator
    └── *.py             # backend helpers
```

External callers should use:

```python
from flexsoc import FlexSoC
```

or:

```bash
fx commands
fx settings
fx TARGET [TARGET...]
```

Backend modules are implementation details. User-facing execution should go
through `fx` or `FlexSoC`.

## Settings and run context

`fx settings` stores project defaults in `.flexsoc/settings.json`:

```bash
fx settings --set TOP=quick_ip --set RUN_TOP=quick_ip --set RUN_ID=smoke --set HOST=uart
```

Important settings:

| Setting | Purpose |
| --- | --- |
| `TOP` | IP or SoC top requested by the current target. |
| `RUN_TOP` | Workspace run directory name. Defaults to `TOP` when not set. |
| `RUN_ID` | Run instance directory. Use an explicit value such as `smoke`. |
| `HOST` | SoC host type, for example `uart` or `ibex`. |
| `WORKSPACE` | Computed workspace root. |

Target-level `--set KEY=VALUE` overrides a value for one command only. Save
settings when you want repeated commands to use the same run context.

## Generated verification architecture

`setup_tb`, `setup_cocotb`, and `setup_model` generate aligned SystemVerilog,
Cocotb, config, vector, and model artifacts.

```text
workspace/runs/<RUN_TOP>/<RUN_ID>/
├── rtl/
├── tb/
│   ├── <top>_tb.sv
│   ├── <top>_reg_sequence.svh
│   ├── <top>_vec_driver.svh          # only when a generic vector checker is useful
│   ├── <top>_vec_monitor.svh         # only when a generic vector checker is useful
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
└── model/
    └── model_<top>.py
```

Design rules for generated verification code:

- generated code must be readable and commented;
- config files carry test intent, not raw bus addresses;
- register addresses come from the HJSON regmap;
- every software-writable register is listed in each generated `config.regs`;
- `.vec` files are shared by SystemVerilog and Cocotb;
- empty placeholder helpers should not be generated;
- IP-specific checkers should be added only when the datapath contract is known.

## Register config format

A config line writes a register by clock-qualified name:

```text
write clk_i.CTRL 0x00000001
write clk_i.WDATA 0x00000002 0xffffffff 1 optional_note
```

Format:

```text
write <CLOCK.REG_NAME> <DATA> [MASK] [WAIT_CYCLES] [NOTE]
```

The generated `<top>_reg_sequence.svh` and Cocotb `reg_driver.py` translate
`CLOCK.REG_NAME` into the TL-UL byte address generated from the HJSON regmap.

## Vector format

A vector line drives one input value and checks the expected output after the
configured latency. The note is optional.

```text
# cycle input expected latency mask [note]
0 0x00000000 0x00000000 2 0xffffffff
1 0x00000001 0x00000001 2 0xffffffff smoke_1
```

The default generated model matches the current RTL stub behavior: a simple
2-cycle pipeline. Existing IPs without a generic top-level datapath still use the
register config flow; generic vector checks are skipped until an IP-specific
checker is added.

## Waveforms

Cocotb waveforms are enabled by default through `COCOTB_WAVES=1`.

```bash
fx cocotb --set TEST_NAME=smoke
fx view_cocotb --set TEST_NAME=smoke
```

Disable waves for one command:

```bash
fx cocotb --set TEST_NAME=smoke --set COCOTB_WAVES=0
```

`view_cocotb` opens the latest `.fst`, `.vcd`, or `.ghw` under the active Cocotb
run directory.

## SoC flow

SoC generation is explicit and target-based:

```bash
fx soc_uart_gen --set TOP=soc --set RUN_TOP=soc_uart --set HOST=uart --set SOC_CFG_MODE=builtin
fx soc_ibex_gen --set TOP=soc --set RUN_TOP=soc_ibex --set HOST=ibex --set SOC_CFG_MODE=builtin
```

Software build and simulation targets depend on external tools:

```bash
fx soc_build_sw soc_sim soc_run --set TOP=soc --set RUN_TOP=soc_uart --set HOST=uart
```

## Developer checks

```bash
make install
source .venv/bin/activate
make lint
make test
fx smoke --json
```

Use dry-run previews before changing a new flow:

```bash
fx TARGET --dry-run --script --set TOP=... --set RUN_TOP=... --set RUN_ID=...
```
