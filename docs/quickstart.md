# Quickstart 🚀


> 🧰 **Shell setup used in this guide**
>
> Install/sync dependencies once, then activate the project environment:
>
> ```bash
> uv sync
> source .venv/bin/activate
> ```
>
> After activation, run commands directly with `fx ...`.

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
fx --help
# or
source .venv/bin/activate
fx --help
```

## 2. Configure a run

A run is identified by `TOP`, `RUN_TOP` and `RUN_ID`.

```bash
fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart
```

Meaning:

- `TOP=test`: the IP/module you are working on.
- `RUN_TOP=test`: the workspace group for this run.
- `RUN_ID=dev`: the run name under the workspace.
- `HOST=uart`: the host style used by higher-level generated flows.

You can inspect the current settings with:

```bash
fx settings
```

## 3. Generate the basic IP scaffold

```bash
fx setup hjson reg doc rtl_stub --force
```

This creates:

- `data/test.hjson`: editable register map source.
- `rtl/test_reg_pkg.sv` and `rtl/test_reg_top.sv`: generated register RTL.
- `doc/test.md`: generated register documentation.
- `rtl/test_core.sv` and `rtl/test.sv`: generated RTL stub and wrapper.

## 4. Generate verification collateral

```bash
fx setup_model setup_tb setup_cocotb --force
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
fx tests
fx sim --set TEST_NAME=smoke
fx cocotb --set TEST_NAME=smoke
```

Run every generated test:

```bash
fx sim_tests
fx cocotb_tests
```

## 6. Lint and backend checks

```bash
fx lint
fx lint_latch lint_width lint_unconnected lint_undriven lint_unused
```

Focused lint targets may print diagnostics without always meaning the IP is
unusable. Treat the logs as review artifacts.

## 7. Synthesis, timing and power

```bash
fx syn
fx sdf
fx sta
fx power
```

`sta`, `sdf` and `power` assume synthesis collateral already exists. They do not
implicitly rerun `syn`, which keeps the flow explicit and predictable.

### Logs and reports

Verification logs are kept separate so SystemVerilog and cocotb runs do not overwrite each other:

```bash
logs/verification/<top>_sv_compile_<test>.log
logs/verification/<top>_sv_sim_<test>.log
logs/verification/<top>_cocotb_<test>.log
```

Signoff logs are grouped under `logs/signoff/`. `fx sta` runs setup and hold analysis for every configured corner, and `fx power` runs power for every corner.
