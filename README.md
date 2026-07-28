<p align="center">
  <img src="assets/open-IP-SoC-logo.png" alt="Open IP SoC logo" width="280"/>
</p>

# FlexSoC

FlexSoC is a lightweight hardware development framework for building,
checking, verifying, and signing off SystemVerilog IP blocks and small SoCs
from one command-line interface: `fx`.

The idea is simple: generate the boring project structure, keep generated files
readable, and let the designer focus on architecture, RTL, constraints, models,
and tests.

FlexSoC is useful when you want a practical flow that goes from a register map
to RTL, lint, model-driven verification, cocotb, synthesis, SDF, STA, and power
without manually wiring the same scaffolding every time.

## What FlexSoC gives you

- 🧩 **IP development flow**  
  Generate HJSON register maps, register RTL, documentation, editable RTL
  scaffolds, wrappers, filelists, and verification infrastructure.

- ♻️ **Existing-IP flow**  
  Load an IP from `hw/ips/<top>/` into an isolated run, preserve its custom RTL
  top and behavioral model, regenerate derived register collateral, and run the
  same lint, verification, synthesis, and signoff stages.

- 🔍 **Lint flow**  
  Run full lint or focused diagnostics for latch, width, unconnected, undriven,
  and unused issues. Detailed tool output is written to logs.

- ✅ **Model-driven verification**  
  The editable Python model owns test behavior. It can combine direct port
  stimulus/checks with CSR writes/reads generated from the HJSON register map.
  SystemVerilog and cocotb consume the same generated vector tests.

- 🧪 **Shared vector tests**  
  Every test is materialized as `config.regs`, `data_in.vec`, and
  `data_out.vec`, so the expected behavior is visible and simulator-independent.

- ⏱️ **Single-clock and multi-clock IPs**  
  The high-level command names stay consistent; `CLOCK_MODE` selects the
  appropriate backend flow.

- 🏗️ **Implementation and signoff**  
  Run synthesis, SDF generation, static timing analysis, and power analysis
  through the same CLI.

- 🌐 **SoC-oriented development**  
  Stage reusable IPs and integrate them into SoC runs while keeping source IP
  collateral separate from generated run artifacts.

## Tools used

FlexSoC orchestrates common open-source RTL and implementation tools instead of
hiding them:

- `slang`, `sv2v`, and `verible` for SystemVerilog handling;
- `verilator` for lint and simulation;
- `cocotb` for Python-driven verification;
- `yosys` for synthesis;
- `OpenSTA` for timing and power analysis;
- `OpenROAD` for physical-design-oriented collateral.

## Install

```bash
uv sync
source .venv/bin/activate
fx --help
fx commands
```

## 🚀 Generated single-clock IP

Use this flow when FlexSoC owns the initial HJSON, RTL scaffold, top wrapper, and
model scaffold:

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

fx syn sdf sta power --force
```

`setup_model --force` is a bootstrap/reset operation: it rewrites both
`model_<top>.py` and `regmap_<top>.py`. After the model has been customized, do
not use `--force` unless you intentionally want to replace it.

When only the HJSON changes, refresh the generated CSR helper without touching
the model:

```bash
fx reg doc --force
fx regmap_py --force
```

## ♻️ Existing IP

An existing IP is loaded from `hw/ips/<top>/`. Its RTL top and behavioral model
are source collateral and may be custom, so the standard existing-IP flow does
not regenerate them.

```bash
fx settings TOP=uart RUN_TOP=uart RUN_ID=dev HOST=uart CLOCK_MODE=single
fx setup --force
fx ip_load --force

fx reg doc --force
fx flist --force
fx lint

fx regmap_py --force
fx tests_gen --force
fx tests
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests
```

The standard existing-IP flow intentionally skips `hjson`, `rtl_stub`,
`top_from_core`, and `setup_model`.

See [Existing IP development](docs/guide_existing_ip_dev.md) for the complete
ownership rules and flow.

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

## Verification ownership

The single-clock model flow has a strict split:

```text
HJSON
  └── fx regmap_py --force
        └── model/regmap_<top>.py      generated; do not hand-edit

behavior / scenarios
  └── model/model_<top>.py             editable
        └── fx tests_gen
              └── tb/tests/<TEST_NAME>/
                  ├── config.regs
                  ├── data_in.vec
                  └── data_out.vec
```

`model_<top>.py` can mix both verification transports:

- direct DUT inputs and output checks;
- CSR `@write` stimulus and CSR `@read` checks.

The generated `regmap_<top>.py` owns register names, offsets, fields, reset
values, access information, encoding, masks, and vector serialization. The
behavioral model should use those generated objects rather than duplicate CSR
layout information.

## Project layout

By default, run artifacts live under:

```text
workspace/runs/<RUN_TOP>/<RUN_ID>/
├── data/         # HJSON register descriptions
├── doc/          # generated register documentation
├── model/        # editable model + generated CSR regmap
├── rtl/          # register RTL, core/top, filelists
├── tb/           # SV/cocotb infrastructure and vector tests
├── sim/          # simulation outputs
├── logs/         # lint, verification, synthesis, signoff logs
├── syn/          # synthesis collateral/results
├── signoff/      # STA/power/SDF collateral
└── pnr_openroad/ # physical-design collateral
```

A different workspace root can be selected with `--workdir`.

## Documentation

- [Quickstart](docs/quickstart.md) — minimal command sequences and ownership rules.
- [Single-clock IP development](docs/guide_ip_dev.md) — generated IP workflow.
- [Existing IP development](docs/guide_existing_ip_dev.md) — preserve custom RTL/model collateral.
- [Multi-clock IP development](docs/guide_multiclock_ip_dev.md) — multi-clock workflow.
- [SoC development](docs/guide_soc_dev.md) — IP integration into SoC runs.
- [Folder structure](docs/folder_structure.md) — source and generated file ownership.

## 🧪 End-to-end regression

The E2E suite runs real `fx` commands and external EDA tools:

```bash
pytest -s tests/test_e2e_fx.py
```

Skip synthesis/signoff while iterating on frontend and verification stages:

```bash
pytest -s tests/test_e2e_fx.py --no-signoff
```

Stream full `fx` tool output:

```bash
FLEXSOC_E2E_LIVE=1 pytest -s tests/test_e2e_fx.py --no-signoff
```

All E2E runs use isolated workspaces under `/tmp`. Successful temporary
workspaces are removed automatically; a failed workspace is retained and its
path is printed for debugging.
