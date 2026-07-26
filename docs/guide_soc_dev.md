# SoC development guide

The SoC flow builds on the same IP flow. Develop and validate IPs first, then
integrate them into a SoC top.

## 1. IP-first strategy

For each IP:

```bash
fx settings TOP=<ip> RUN_TOP=<ip> RUN_ID=dev HOST=uart CLOCK_MODE=single
fx setup hjson reg doc rtl_stub top_from_core --force
fx flist lint
fx setup_model --force
fx tests_gen
fx setup_tb setup_cocotb --force
fx sim_tests
fx cocotb_tests
```

For multi-clock IPs, use:

```bash
fx settings TOP=<ip> RUN_TOP=<ip> RUN_ID=dev HOST=uart CLOCK_MODE=multi
```

and then the same target names.

## 2. Configure the SoC run

```bash
fx settings TOP=soc RUN_TOP=soc RUN_ID=dev HOST=uart CLOCK_MODE=single
```

The SoC can integrate single-clock and multi-clock IP collateral, but the SoC top
has its own top-level integration, filelists, constraints, and verification.

## 3. Load or prepare IPs

Use the SoC/IP loading targets for the project state you are working with:

```bash
fx ip_load --force
```

Then inspect the generated SoC layout and filelists before moving to lint.

## 4. Filelists and lint before verification

```bash
fx flist --force
fx lint
fx lint_latch
fx lint_width
fx lint_unconnected
fx lint_undriven
fx lint_unused
```

Run lint before modelling or verification so structural integration problems are
caught early.

## 5. Model-driven SoC verification

```bash
fx setup_model --force
fx tests_gen
fx tests
```

The model creates vector tests under:

```text
tb/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

Use `test_gen` to create or rewrite one test:

```bash
fx test_gen --set TEST_NAME=my_soc_case
```

## 6. Verification scaffold

```bash
fx setup_tb --force
fx setup_cocotb --force
```

The scaffold creates drivers, monitors, and top-level testbench infrastructure.
It does not define the test vectors.

## 7. Run tests

```bash
fx sim_tests
fx cocotb_tests
```

Or one selected test:

```bash
fx sim --set TEST_NAME=smoke
fx cocotb --set TEST_NAME=smoke
```

## 8. Host/software flow

For UART-hosted SoC flows, use the SoC host targets when applicable:

```bash
fx soc_uart_gen
fx soc_prepare
fx soc_build_sw
fx soc_run
```

## 9. Signoff

The SoC has its own top-level constraints. Do not blindly copy an IP SDC into the
SoC signoff run.

```bash
fx syn sdf sta power --force
```

Use `--live` when you want full tool logs on the terminal.
