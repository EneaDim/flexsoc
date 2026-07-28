# Folder structure

FlexSoC separates versioned source IPs from generated run workspaces.

## Source IPs

Reusable IP source lives under:

```text
hw/ips/<top>/
```

An existing IP can carry its own:

```text
hw/ips/<top>/
├── data/      # HJSON source register maps
├── doc/       # register documentation
├── model/     # behavioral model + generated regmap helper
├── rtl/       # RTL implementation/top/filelists
├── tb/        # vector tests and verification collateral
├── syn/       # synthesis collateral
└── signoff/   # signoff collateral
```

`fx ip_load` copies this source collateral into a run workspace.

## Run workspaces

The default workspace root is `workspace/`, but commands can select another root
with `--workdir`.

```text
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
```

Examples:

```text
workspace/runs/uart/dev/
/tmp/flexsoc-uart-e2e-XXXXXX/runs/uart/dev/
```

A typical run contains:

```text
runs/<RUN_TOP>/<RUN_ID>/
├── data/          # HJSON register descriptions
├── doc/           # generated register documentation
├── logs/          # lint, verification, synthesis, signoff logs
├── model/         # behavioral model + generated CSR helper
├── pnr_openroad/  # physical-design collateral
├── rtl/           # register RTL, implementation, wrappers, filelists
├── signoff/       # STA/power/SDF collateral
├── sim/           # simulation outputs and waveforms
├── syn/           # synthesis collateral/results
└── tb/            # vector tests and SV/cocotb infrastructure
```

## Model ownership

Single-clock model directory:

```text
model/
├── model_<top>.py   # editable behavioral model
└── regmap_<top>.py  # generated from HJSON
```

`model_<top>.py` owns:

- behavioral scenarios;
- functional input stimulus;
- functional output expectations;
- the decision of which CSR fields to write/read and when.

`regmap_<top>.py` owns:

- register/domain names;
- offsets and reset values;
- fields and access metadata;
- encoding and masks;
- `config.regs` serialization;
- CSR `@write` / `@read` vector serialization.

Refresh the generated CSR helper only:

```bash
fx regmap_py --force
```

`fx setup_model --force` rewrites both files and should be treated as a scaffold
reset after the model has been customized.

The current multi-clock scaffold uses an editable
`model_<top>_multiclock.py`; see the dedicated multi-clock guide for that flow.

## Vector tests

```text
tb/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

Semantics:

- `config.regs`: initial CSR configuration;
- `data_in.vec`: direct input drives and/or CSR `@write` operations;
- `data_out.vec`: direct output checks and/or CSR `@read` expectations.

Both SystemVerilog and cocotb consume these files; simulation does not import
the behavioral model.

## SystemVerilog testbench

```text
tb/
├── sv/
│   ├── <top>_tb.sv
│   ├── include_<top>_tb.sv
│   └── drivers/
│       ├── <top>_reg_driver.svh
│       ├── <top>_vec_driver.svh
│       └── <top>_vec_monitor.svh
├── cocotb/
└── tests/
    └── <TEST_NAME>/
```

Exact generated filenames can vary by flow, but the ownership is stable:
verification infrastructure is generated separately from behavioral vectors.

## cocotb

```text
tb/cocotb/
├── Makefile
├── <top>_cocotb_tb.sv
├── <top>_test.py
└── drivers/
    ├── __init__.py
    ├── reg_driver.py
    ├── vec_driver.py
    └── vec_monitor.py
```

## Logs

```text
logs/
├── lint/
├── verification/
└── signoff/
```

The terminal shows compact progress by default. Add `--live` to an `fx` command
when full tool output is required.

## E2E workspace policy

`tests/test_e2e_fx.py` never uses the repository `workspace/` tree. It creates
isolated directories under `/tmp`:

```text
/tmp/flexsoc-full-e2e-XXXXXX/
/tmp/flexsoc-cordic-e2e-XXXXXX/
/tmp/flexsoc-uart-e2e-XXXXXX/
```

Successful directories are deleted. Failed directories are retained for
debugging.
