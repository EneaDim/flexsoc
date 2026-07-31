# 🚀 Quickstart

This page is the shortest practical path through the current FlexSoC IP flow.
For the engineering reasoning behind selective regeneration, read
[Project lifecycle and change propagation](project_lifecycle.md).

## 📦 Install

```bash
uv sync
source .venv/bin/activate
fx doctor
fx --help
fx commands
```

## 🧭 Core ownership rule

```text
HJSON
  ├── generated register RTL/docs
  ├── generated <top>_regmap.py
  └── generated CSR formal semantics

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
  └── Slang-resolved hierarchy used by lint / sim / formal / synthesis
```

Do not duplicate register offsets or field positions in model/test code. Use the
generated objects from `<top>_regmap.py`.

## 🧱 Generated single-clock IP

```bash
fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart CLOCK_MODE=single

# Specification + RTL
fx setup --force
fx hjson --force
fx reg doc --force
fx rtl_stub --force
fx top_from_core --force
fx flist --force
fx lint_suite

# Functional DV
fx setup_model --force
fx tests_gen --force
fx setup_tb setup_cocotb --force
fx regression
fx coverage_detail

# Formal DV
fx formal

# Implementation + equivalence + signoff
fx syn --force
fx equiv --force
fx sdf sta power_estimate --force

# Consolidated closure
fx manifest metrics check --force
```

Functional coverage is reported as a scope × type matrix:

```text
Scope          line   toggle   expr   branch   fsm   user   total
design          ...     ...     ...      ...    ...    ...     ...
registers       ...     ...     ...      ...    ...    ...     ...
common          ...     ...     ...      ...    ...    ...     ...
other           ...     ...     ...      ...    ...    ...     ...
all             ...     ...     ...      ...    ...    ...     ...
```

Formal proof and EQY partition closure stay separate from these code-coverage
percentages.

After `<top>_model.py` or `<top>_tests.py` has been customized, do **not** use
`setup_model --force` for a routine HJSON change. Refresh only the derived CSR
collateral:

```bash
fx reg doc --force
fx regmap_py --force
fx tests_gen --force
fx regression
fx formal
```

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
fx setup_tb setup_cocotb --force
fx regression
fx coverage_detail
fx formal

fx sdc_multi --force
fx syn --force
fx equiv --force
fx sdf sta power_estimate --force
fx metrics check --force
```

`CLOCK_MODE=multi` preserves the model/regmap/tests ownership contract but uses
multi-domain register maps, event/domain-aware verification, multi-clock timing
constraints, and multi-clock formal/equivalence assumptions.

> 🌐 **Next step:** CDC and RDC structural analysis will be added as explicit
> multi-clock/reset closure stages. They will remain separate from functional
> coverage and formal/EQY percentages.

## ♻️ Existing/reusable IP

For an IP already stored under `hw/ips/<top>/`:

```bash
fx settings TOP=uart RUN_TOP=uart RUN_ID=dev HOST=uart CLOCK_MODE=single
fx setup --force
fx ip_load --force

fx reg doc --force
fx regmap_py --force
fx flist --force
fx lint_suite

fx tests_gen --force
fx setup_tb setup_cocotb --force
fx regression
fx coverage_detail
fx formal
fx syn --force
fx equiv --force
fx sdf sta power_estimate --force
```

The existing-IP flow preserves source-owned HJSON, RTL/top, model, tests, and
properties unless replacement is intentional. See
[Existing IP development](guide_existing_ip_dev.md).

## 🔍 Lint backends

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

The canonical project flow still uses `fx flist`, which emits `rtl_common.f` and
`rtl_ip.f` for downstream tools.

## 🧪 Vector-test format

```text
dv/functional/tests/<TEST_NAME>/
├── config.regs   # initial CSR configuration
├── data_in.vec   # direct input drives and/or CSR @write rows
└── data_out.vec  # direct output checks and/or CSR @read rows
```

Both SystemVerilog and cocotb consume the same materialized vectors.

## 🔁 Equivalence checking

EQY compares the RTL representation against the mapped post-synthesis netlist:

```bash
fx syn --force
fx equiv --force
```

The report distinguishes:

- partitions proven equivalent;
- real failed partitions;
- solver/engine errors;
- timeouts;
- unknown/incomplete partitions.

A partial percentage is therefore diagnostic closure information, not functional
coverage and not automatically a demonstrated RTL mismatch.

## 🪵 Debug output

Default output stays compact. Add `--live` where full tool output is useful:

```bash
fx regression --live
fx formal --live
fx syn equiv sdf sta power_estimate --force --live
```

Logs are grouped under `logs/lint`, `logs/dv/functional`, `logs/dv/formal`,
`logs/synthesis`, and `logs/signoff`.

## ✅ E2E regression

The project test entry point is:

```bash
make test E2E_ROOT=work
```

or directly:

```bash
pytest -s tests/test_e2e_fx.py --e2e-root work
```

Skip implementation/signoff while iterating on frontend-only changes with:

```bash
pytest -s tests/test_e2e_fx.py --no-signoff --e2e-root work
```

Successful temporary workspaces are removed; failed ones are retained for
debugging.
