# SoC development guide

The SoC flow builds on validated IP source. Develop and verify IPs first, then
load them into a SoC run and add top-level integration.

## 1. Validate IPs before integration

For a generated IP, follow the single-clock or multi-clock development guide.
For a reusable IP already stored under `hw/ips/<top>/`, follow the existing-IP
guide so custom top/model collateral is preserved.

## 2. Configure the SoC run

```bash
fx settings TOP=soc RUN_TOP=soc RUN_ID=dev HOST=uart CLOCK_MODE=single
```

The SoC has its own top-level RTL, filelists, constraints, verification, and
signoff state.

## 3. Load reusable IPs

Use the IP-loading targets required by the SoC configuration. A direct IP load
uses:

```bash
fx ip_load --force
```

When `RUN_TOP` differs from the loaded IP `TOP`, `ip_load` stages the IP below
the SoC run's `ips/` directory rather than replacing the SoC run itself.

## 4. Generate filelists and lint

```bash
fx flist --force
fx lint
fx lint_latch
fx lint_width
fx lint_unconnected
fx lint_undriven
fx lint_unused
```

Resolve structural integration problems before building verification around the
SoC top.

## 5. Model-driven verification

If the SoC uses the generated single-clock model flow:

```bash
fx setup_model --force
fx tests_gen
fx tests
```

After the behavioral model is customized, do not use `setup_model --force` for
an HJSON-only update. Refresh generated CSR metadata with:

```bash
fx reg doc --force
fx regmap_py --force
```

The model can combine top-level direct ports and CSR transactions in the same
scenario.

Generated tests live under:

```text
tb/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

## 6. Verification infrastructure

```bash
fx setup_tb --force
fx setup_cocotb --force
```

Run all generated tests:

```bash
fx sim_tests
fx cocotb_tests
```

Or one selected test:

```bash
fx sim --set TEST_NAME=smoke
fx cocotb --set TEST_NAME=smoke
```

## 7. Host/software flow

For UART-hosted SoC flows, use the SoC host targets when applicable:

```bash
fx soc_uart_gen
fx soc_prepare
fx soc_build_sw
fx soc_run
```

## 8. Signoff

The SoC owns its top-level timing and physical assumptions. Do not reuse an IP
constraint file blindly at SoC level.

```bash
fx syn sdf sta power --force
```

Add `--live` when full tool logs are needed in the terminal.
