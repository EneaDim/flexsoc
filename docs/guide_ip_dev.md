# Single-clock IP development guide

This guide shows the intended single-clock workflow. The same target names also
work for multi-clock designs when `CLOCK_MODE=multi` is set.

## 1. Configure the run

```bash
fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart CLOCK_MODE=single
```

`TOP` is the hardware top to build and verify. The testbench instantiates this
module. To verify a core directly, set `TOP=<top>_core` explicitly.

## 2. Create the run tree and HJSON

```bash
fx setup --force
fx hjson --force
```

Edit:

```text
workspace/runs/test/dev/data/test.hjson
```

Then generate register RTL and docs:

```bash
fx reg doc --force
```

## 3. Generate RTL scaffold

```bash
fx rtl_stub --force
```

This creates:

```text
rtl/test_core.sv
rtl/test.sv
```

Edit the core:

```text
workspace/runs/test/dev/rtl/test_core.sv
```

If you change the core ports, refresh the top wrapper:

```bash
fx top_from_core --force
```

## 4. Filelists and lint

Run this before modelling and verification:

```bash
fx flist --force
fx lint
```

Focused diagnostics:

```bash
fx lint_latch
fx lint_width
fx lint_unconnected
fx lint_undriven
fx lint_unused
```

The general lint log is:

```text
logs/lint/<top>_lint_all.log
```

Focused lint logs are split by kind and part, for example:

```text
logs/lint/<top>_lint_width_ip.log
logs/lint/raw/<top>_lint_width_raw.log
```

## 5. Create the model scaffold

```bash
fx setup_model --force
```

This creates:

```text
model/model_test.py
model/regmap_test.py
```

`model_test.py` is the editable source of truth for expected behaviour and
vector generation. `regmap_test.py` is generated from the HJSON/regmap and
contains register helper names used by the model.

When the register map changes, rerun:

```bash
fx setup_model --force
```

Then update the model logic as needed.

## 6. Generate vector tests from the model

Generate all tests defined by the model:

```bash
fx tests_gen
```

Generate or rewrite one test only:

```bash
fx test_gen --set TEST_NAME=my_case
```

List available tests:

```bash
fx tests
```

Each test is stored as:

```text
tb/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

## 7. Register checks in tests

`config.regs` writes register values before or during the test:

```text
CTRL 0x00000001
MODE 0x00000000
OPERAND_A 0x00000003
```

Vector files drive and check datapath signals:

```text
# data_in.vec
0 data_i 0x00000003
0 coeff_i 0x00000001
0 valid_i 0x00000001
```

```text
# data_out.vec
1 data_o 0x00000004
1 valid_o 0x00000001
```

The model can also emit register-read expectations for status checks when the
helper supports them. Keep those checks close to the test case that produced the
status update, so it is clear why the register value is expected.

## 8. Generate verification scaffold

```bash
fx setup_tb --force
fx setup_cocotb --force
```

These targets create only infrastructure:

```text
tb/test_tb.sv
tb/include_test_tb.sv
tb/drivers/test_vec_driver.svh
tb/drivers/test_vec_monitor.svh
tb/cocotb/...
```

They do not define the tests. The tests come from the model through `tests_gen`
or `test_gen`.

## 9. Run simulations

Single test:

```bash
fx sim --set TEST_NAME=smoke
fx cocotb --set TEST_NAME=smoke
```

All generated tests:

```bash
fx sim_tests
fx cocotb_tests
```

Waveforms:

```bash
fx view --set TEST_NAME=smoke
fx view_cocotb --set TEST_NAME=smoke
```

## 10. Synthesis and signoff

```bash
fx syn sdf sta power --force
```

Use live mode only when you want full tool output:

```bash
fx syn sdf sta power --force --live
```

## 11. Full E2E check

```bash
FLEXSOC_RUN_E2E=1 pytest -s tests/test_e2e_fx.py
```

Skip signoff while debugging:

```bash
FLEXSOC_RUN_E2E=1 FLEXSOC_E2E_SKIP_SIGNOFF=1 pytest -s tests/test_e2e_fx.py
```
