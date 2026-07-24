# Quickstart 🚀

This guide gets you from a clean checkout to a working generated IP flow.

## 1. Install everything with uv

FlexSoC is designed so a normal `uv sync` installs the Python package and the
Python-side flow dependencies.

```bash
cd ~/github/flexsoc
uv sync
```

Run the CLI through `uv` or activate the environment:

```bash
uv run fx --help
# or
source .venv/bin/activate
fx --help
```

## 2. Configure a run

A run is identified by `TOP`, `RUN_TOP` and `RUN_ID`.

```bash
uv run fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart
```

Meaning:

- `TOP=test`: the IP/module you are working on.
- `RUN_TOP=test`: the workspace group for this run.
- `RUN_ID=dev`: the run name under the workspace.
- `HOST=uart`: the host style used by higher-level generated flows.

You can inspect the current settings with:

```bash
uv run fx settings
```

## 3. Generate the basic IP scaffold

```bash
uv run fx setup hjson reg doc rtl_stub --force
```

This creates:

- `data/test.hjson`: editable register map source.
- `rtl/test_reg_pkg.sv` and `rtl/test_reg_top.sv`: generated register RTL.
- `doc/test.md`: generated register documentation.
- `rtl/test_core.sv` and `rtl/test.sv`: generated RTL stub and wrapper.

## 4. Generate verification collateral

```bash
uv run fx setup_model setup_tb setup_cocotb --force
```

This creates:

- `model/model_test.py`: Python model template.
- `tb/tests/<name>/config.regs`: register writes for each test.
- `tb/tests/<name>/data_in.vec`: input stimulus vectors.
- `tb/tests/<name>/data_out.vec`: expected output vectors.
- `tb/test_tb.sv`: SystemVerilog vector testbench.
- `tb/cocotb/test_tb.py`: cocotb test using the same vectors.

## 5. List and run tests

```bash
uv run fx tests
uv run fx sim --set TEST_NAME=smoke
uv run fx cocotb --set TEST_NAME=smoke
```

Run every generated test:

```bash
uv run fx sim_tests
uv run fx cocotb_tests
```

## 6. Lint and backend checks

```bash
uv run fx lint
uv run fx lint_latch lint_width lint_unconnected lint_undriven lint_unused
```

Focused lint targets may print diagnostics without always meaning the IP is
unusable. Treat the logs as review artifacts.

## 7. Synthesis, timing and power

```bash
uv run fx syn
uv run fx sdf
uv run fx sta
uv run fx power
```

`sta`, `sdf` and `power` assume synthesis collateral already exists. They do not
implicitly rerun `syn`, which keeps the flow explicit and predictable.
