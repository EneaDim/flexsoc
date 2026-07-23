# FlexSoC Flow Smoke Guide

Use this checklist after refactoring or after applying patches. It starts with
safe checks and ends with optional EDA-dependent commands.

## 1. Environment

```bash
make install
source .venv/bin/activate
make lint
make test
```

## 2. CLI and settings

```bash
fx commands
fx settings --set TOP=quick_ip --set RUN_TOP=quick_ip --set RUN_ID=smoke --set HOST=uart
fx settings
fx smoke --json
```

Remember: `--set KEY=VALUE` on a target is one-shot. Use `fx settings --set ...`
when you want future commands to use the same context.

## 3. Preview commands

```bash
fx setup hjson reg doc --dry-run --script
fx setup hjson reg doc rtl_stub flist setup_tb setup_cocotb setup_model --dry-run --script
fx cocotb --dry-run --script --set TEST_NAME=smoke
```

Expected result: a shell script that calls `src/flexsoc/backend/Makefile` with
the resolved variables.

## 4. Generate and test a new IP

```bash
fx setup hjson reg doc rtl_stub flist setup_tb setup_cocotb setup_model --force

fx cocotb --set TEST_NAME=smoke
fx cocotb --set TEST_NAME=corners
fx cocotb --set TEST_NAME=random
fx view_cocotb --set TEST_NAME=random
```

Inspect generated verification inputs:

```bash
cat workspace/runs/quick_ip/smoke/tb/tests/smoke/config.regs
cat workspace/runs/quick_ip/smoke/tb/tests/smoke/smoke.vec
```

## 5. Load and test an existing IP

```bash
fx ip_load flist setup_tb setup_cocotb setup_model \
  --force \
  --set TOP=cordic \
  --set RUN_TOP=cordic \
  --set RUN_ID=smoke

fx cocotb --set TOP=cordic --set RUN_TOP=cordic --set RUN_ID=smoke --set TEST_NAME=smoke
```

The generated `config.regs` should list every software-writable register from the
HJSON regmap. For IPs without a generic top-level datapath pair, generic vector
checks are skipped and register configuration still runs.

## 6. SoC previews

UART-host SoC:

```bash
fx soc_uart_gen --dry-run --script \
  --set TOP=soc \
  --set RUN_TOP=soc_uart \
  --set HOST=uart \
  --set SOC_CFG_MODE=builtin
```

Ibex-host SoC:

```bash
fx soc_ibex_gen --dry-run --script \
  --set TOP=soc \
  --set RUN_TOP=soc_ibex \
  --set HOST=ibex \
  --set SOC_CFG_MODE=builtin
```

Build and simulation targets need the external toolchain:

```bash
fx soc_build_sw soc_run --dry-run --script --set TOP=soc --set RUN_TOP=soc_uart --set HOST=uart
```

## 7. Debug a failing command

```bash
fx TARGET --info --json
fx TARGET --dry-run --script --set TOP=... --set RUN_TOP=... --set RUN_ID=...
fx TARGET --capture --json --set TOP=... --set RUN_TOP=... --set RUN_ID=...
```

For generated files, first check the active settings:

```bash
fx settings
```

Most confusing failures come from running a target with a saved `RUN_ID` that is
different from the run that was generated.
