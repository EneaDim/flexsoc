# 🚀 Quickstart

This page is the shortest practical path through FlexSoC. For why the flow is
structured this way, read [Project lifecycle and change propagation](project_lifecycle.md).

## 📦 Install

```bash
uv sync
source .venv/bin/activate
fx --help
fx commands
```

## 🧭 Core ownership rule

```text
HJSON
  ├── generated register RTL/docs
  └── <top>_regmap.py

RTL core/top
  └── hardware implementation

<top>_model.py
  └── behavioral/reference model

<top>_tests.py
  └── scenarios + vector generation
        ├── config.regs
        ├── data_in.vec
        └── data_out.vec

rtl_common.f + rtl_ip.f
  └── Slang-resolved hierarchy consumed by lint/sim/synthesis
```

Do not duplicate register offsets or field positions in model/test code. Use
the generated objects from `<top>_regmap.py`.

## 🧱 Generated single-clock IP

```bash
fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart CLOCK_MODE=single

fx setup --force
fx hjson --force
fx reg doc --force
fx rtl_stub --force
fx top_from_core --force

fx flist --force
fx lint_suite

fx setup_model --force
fx tests_gen --force
fx tests
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests
```

Continue to implementation/signoff when needed:

```bash
fx syn sdf sta power --force
```

After `<top>_model.py` or `<top>_tests.py` has been customized, do not use
`setup_model --force` for a routine HJSON change. Refresh only the derived CSR
collateral:

```bash
fx reg doc --force
fx regmap_py --force
fx tests_gen --force
```

`regmap_py` rewrites only `model/<top>_regmap.py`.

## ♻️ Existing/reusable IP

For an IP already stored under `hw/ips/<top>/`:

```bash
fx settings TOP=uart RUN_TOP=uart RUN_ID=dev HOST=uart CLOCK_MODE=single
fx setup --force
fx ip_load --force

fx reg doc --force
fx flist --force
fx lint_suite

fx regmap_py --force
fx tests_gen --force
fx tests
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests
```

The standard existing-IP regression does not regenerate source-owned HJSON,
RTL/top, or behavioral model/test scaffolds. Its purpose is to preserve a
validated block so it can be regression-tested and reused in larger systems.
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
fx lint_suite

fx setup_model --force
fx tests_gen --force
fx tests
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests

fx sdc_multi --force
fx syn sdf sta power --force
```

`CLOCK_MODE=multi` keeps the same high-level model/regmap/tests ownership but
uses domain-aware/event-driven verification and multi-clock constraints.

## 🔍 Lint backend

```bash
fx lint_suite --set LINT_TOOL=verilator
fx lint_suite --set LINT_TOOL=slang
```

## 🧠 Slang analysis utilities

```bash
fx slang_hier --set SLANG_TOP_FILE=/path/top.sv --set SLANG_ROOT=/path/rtl
fx slang_ast --set SLANG_TOP_FILE=/path/top.sv --set SLANG_ROOT=/path/rtl
fx slang_flist --set SLANG_TOP_FILE=/path/top.sv --set SLANG_ROOT=/path/rtl
```

The canonical project flow uses `fx flist`, which emits `rtl_common.f` and
`rtl_ip.f` for downstream tools.

## 🧪 Vector-test format

```text
tb/tests/<TEST_NAME>/
├── config.regs   # initial CSR configuration
├── data_in.vec   # direct input drives and/or CSR @write rows
└── data_out.vec  # direct output checks and/or CSR @read rows
```

Both SystemVerilog and cocotb consume the same materialized vectors.

## 🪵 Debug output

Default output is compact. Add `--live` to stream full tool output:

```bash
fx sim_tests --live
fx syn sdf sta power --force --live
```

Logs are organized under `logs/lint`, `logs/verification`, `logs/synthesis`, and
`logs/signoff`.

## ✅ E2E regression

```bash
pytest -s tests/test_e2e_fx.py
pytest -s tests/test_e2e_fx.py --no-signoff
```

Default E2E workspaces are under `/tmp`. Select another base with:

```bash
pytest -s tests/test_e2e_fx.py --e2e-root ~/flexsoc-e2e
```

or `FLEXSOC_E2E_ROOT`.
