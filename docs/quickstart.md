# Quickstart

This page is the shortest practical path through FlexSoC.

## Install

```bash
uv sync
source .venv/bin/activate
fx --help
```

## Core ownership rule

```text
HJSON                  -> generated register RTL/docs + regmap_<top>.py
RTL core/top            -> hardware implementation
model_<top>.py          -> behavioral scenarios and expected results
regmap_<top>.py         -> generated CSR metadata/API
model                   -> config.regs + data_in.vec + data_out.vec
SV/cocotb testbenches   -> consume the generated vectors
```

Do not duplicate register offsets or field positions in the behavioral model.
Use the generated CSR objects from `regmap_<top>.py`.

## 🚀 Generated single-clock IP

```bash
fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart CLOCK_MODE=single

fx setup --force
fx hjson --force
fx reg doc --force
fx rtl_stub --force
fx top_from_core --force
fx flist --force
fx lint

fx setup_model --force
fx tests_gen
fx tests
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests
```

Use `setup_model --force` only to create or intentionally reset the editable
model scaffold. After editing the model, refresh an HJSON change with:

```bash
fx reg doc --force
fx regmap_py --force
fx tests_gen --force
```

`regmap_py` rewrites only `model/regmap_<top>.py`.

## ♻️ Existing IP

For an IP already stored under `hw/ips/<top>/`:

```bash
fx settings TOP=uart RUN_TOP=uart RUN_ID=dev HOST=uart CLOCK_MODE=single
fx setup --force
fx ip_load --force

fx reg doc --force
fx flist --force
fx lint
fx lint_latch
fx lint_width
fx lint_unconnected
fx lint_undriven
fx lint_unused

fx regmap_py --force
fx tests_gen --force
fx tests
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests
```

Do not run these as part of the standard existing-IP regression:

```text
hjson
rtl_stub
top_from_core
setup_model
```

They can replace source collateral that the existing IP intentionally owns.
See [Existing IP development](guide_existing_ip_dev.md).

## ⏱️ Multi-clock IP

```bash
fx settings TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart CLOCK_MODE=multi

fx setup --force
fx hjson --force
fx reg doc --force
fx rtl_stub --force
fx top_from_core --force
fx flist --force
fx lint

fx setup_model --force
fx tests_gen
fx tests
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests

fx sdc_multi --force
fx syn sdf sta power --force
```

`CLOCK_MODE=multi` routes the generic model/testbench commands to the multi-clock
backend. See [Multi-clock IP development](guide_multiclock_ip_dev.md).

## Vector-test format

Each test is a directory:

```text
tb/tests/<TEST_NAME>/
├── config.regs   # initial CSR configuration
├── data_in.vec   # direct input drives and/or CSR @write rows
└── data_out.vec  # direct output checks and/or CSR @read rows
```

A model may use ports, CSRs, or both in the same test.

## Debug output

Default output is compact. Add `--live` to an `fx` command to stream full tool
output:

```bash
fx sim_tests --live
fx syn sdf sta power --force --live
```

## 🧪 E2E regression

```bash
pytest -s tests/test_e2e_fx.py
```

Without signoff:

```bash
pytest -s tests/test_e2e_fx.py --no-signoff
```

With live tool output:

```bash
FLEXSOC_E2E_LIVE=1 pytest -s tests/test_e2e_fx.py --no-signoff
```

The E2E suite never uses the repository `workspace/` directory. Each test runs
under `/tmp`; failed workspaces are retained for inspection.
