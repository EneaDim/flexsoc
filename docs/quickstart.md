# 🚀 FlexSoC Quickstart

This guide is intentionally short: set the run context, launch `fx` targets, and
inspect the generated workspace.

## 1. Install everything

```bash
uv sync
uv run fx --help
uv run fx commands
```

`uv sync` installs the package and the Python dependencies used by the CLI,
tests, cocotb, and flow helpers.

## 2. IP development from scratch 🧩

Create a new scratch IP run:

```bash
uv run fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart
```

Generate the useful source artifacts:

```bash
uv run fx setup hjson reg doc rtl_stub flist setup_tb setup_cocotb setup_model --force
```

Run one SystemVerilog vector test:

```bash
uv run fx sim --set TEST_NAME=smoke
uv run fx sim --set TEST_ID=1
```

Run the whole SystemVerilog regression:

```bash
uv run fx sim_tests
```

Run one cocotb test, or the full cocotb regression:

```bash
uv run fx cocotb --set TEST_NAME=smoke
uv run fx cocotb --set TEST_ID=1
uv run fx cocotb_tests
```

Run lint, synthesis, timing, and power:

```bash
uv run fx lint lint_latch lint_width lint_unconnected lint_undriven lint_unused
uv run fx syn sdf sta power
```

Focused lint warnings can be useful diagnostics. They should not be treated like
fatal flow errors unless the underlying tool reports a real error.

## 3. Existing IP development 📦

Load an existing IP into a clean run folder:

```bash
uv run fx settings TOP=cordic RUN_TOP=cordic RUN_ID=dev HOST=uart
uv run fx ip_load flist setup_tb setup_cocotb setup_model --force
```

Then use the same commands as the scratch flow:

```bash
uv run fx sim_tests
uv run fx cocotb_tests
uv run fx lint syn sdf sta power
```

Useful IP examples:

```bash
uv run fx settings TOP=cordic      RUN_TOP=cordic      RUN_ID=dev HOST=uart
uv run fx settings TOP=spi_host    RUN_TOP=spi_host    RUN_ID=dev HOST=uart
uv run fx settings TOP=uart_master RUN_TOP=uart_master RUN_ID=dev HOST=uart
uv run fx settings TOP=fft_core    RUN_TOP=fft_core    RUN_ID=dev HOST=uart
```

## 4. SoC development 🌐

UART-host SoC example:

```bash
uv run fx ip_load --force --set TOP=uart_master --set LOAD_AS=uart_master --set RUN_TOP=soc_uart --set RUN_ID=dev
uv run fx ip_load --force --set TOP=gpio        --set RUN_TOP=soc_uart --set RUN_ID=dev
uv run fx ip_load --force --set TOP=rv_timer    --set RUN_TOP=soc_uart --set RUN_ID=dev
uv run fx soc_uart_gen --set TOP=soc --set RUN_TOP=soc_uart --set RUN_ID=dev --set HOST=uart --set SOC_CFG_MODE=builtin
```

Ibex-host SoC example:

```bash
uv run fx fetch --set VENDOR=lowrisc_ip
uv run fx fetch --set VENDOR=lowrisc_ibex
uv run fx ip_load --force --set TOP=uart     --set RUN_TOP=soc_ibex --set RUN_ID=dev
uv run fx ip_load --force --set TOP=gpio     --set RUN_TOP=soc_ibex --set RUN_ID=dev
uv run fx ip_load --force --set TOP=rv_timer --set RUN_TOP=soc_ibex --set RUN_ID=dev
uv run fx ip_load --force --set TOP=spi_host --set RUN_TOP=soc_ibex --set RUN_ID=dev
uv run fx soc_ibex_gen --set TOP=soc --set RUN_TOP=soc_ibex --set RUN_ID=dev --set HOST=ibex --set SOC_CFG_MODE=builtin
```

Build and run only after external toolchains are available:

```bash
uv run fx soc_build_sw soc_run --set TOP=soc --set RUN_TOP=soc_uart --set RUN_ID=dev --set HOST=uart
```

## 5. Helpful CLI commands 🧭

```bash
uv run fx commands
uv run fx <target> --info
uv run fx <target> --dry-run --script
uv run fx shell
```
