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
  Create a run folder, generate HJSON register maps, register RTL,
  documentation, RTL stubs, top wrappers, filelists, and verification scaffolds.

- ✅ **Model-driven verification**  
  `setup_model` creates an editable Python model. The model generates vector
  tests under `tb/tests/<TEST_NAME>/`. SystemVerilog and cocotb consume the same
  generated files: `config.regs`, `data_in.vec`, and `data_out.vec`.

- 🔍 **Lint flow**  
  Run full lint or focused diagnostics for latch, width, unconnected, undriven,
  and unused issues. Long tool output goes to logs; the terminal stays readable.

- 🧪 **SystemVerilog and cocotb testbenches**  
  Generate ordered verification structure with `tb/drivers/` and
  `tb/cocotb/drivers/`. Testbenches are generated for the selected top module,
  not for the core unless you explicitly set `TOP=<name>_core`.

- ⏱️ **Single-clock and multi-clock IPs**  
  Use the same command names for both flows. Set `CLOCK_MODE=single` or
  `CLOCK_MODE=multi`, then run `fx hjson`, `fx reg`, `fx doc`, `fx rtl_stub`,
  `fx setup_model`, `fx setup_tb`, and `fx setup_cocotb`.

- 🏗️ **Implementation and signoff**  
  Run synthesis, SDF generation, static timing analysis, and power analysis with
  Yosys, OpenSTA, and signoff-oriented scripts.

- 🌐 **SoC-oriented development**  
  Stage reusable IPs, build SoC layouts, prepare host-based flows, and keep IP
  and SoC collateral organized under a common workspace.

## Tools used

FlexSoC orchestrates common open-source RTL and implementation tools instead of
hiding them:

- `slang`, `sv2v`, and `verible` for SystemVerilog handling;
- `verilator` for lint and fast simulation;
- `cocotb` for Python-driven verification;
- `yosys` for synthesis;
- `OpenSTA` for timing and power analysis;
- `OpenROAD` for physical-design oriented collateral.

## Install

Use `uv` once to create/sync the environment, then activate it and run `fx`
directly:

```bash
uv sync
source .venv/bin/activate
fx --help
fx commands
```

## Single-clock quick flow

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

## Multi-clock quick flow

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

The `_multi` commands still exist as explicit aliases, but the recommended
workflow is to set `CLOCK_MODE=multi` and use the same command names as the
single-clock flow.

## Verification model

The verification flow has clear ownership:

```text
setup_model        -> create editable model/model_<top>.py and regmap helpers
tests_gen/test_gen -> generate tb/tests/<TEST_NAME>/ from the model
setup_tb           -> generate SystemVerilog testbench, drivers, monitor
setup_cocotb       -> generate cocotb scaffold, drivers, monitor
sim/cocotb         -> run generated vector tests only
```

Generated tests are plain files:

```text
tb/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

Generate all tests:

```bash
fx tests_gen
```

Generate or rewrite one test:

```bash
fx test_gen --set TEST_NAME=my_case
```

Run one test:

```bash
fx sim --set TEST_NAME=my_case
fx cocotb --set TEST_NAME=my_case
```

Run all generated tests:

```bash
fx sim_tests
fx cocotb_tests
```

## Project layout

Most generated work lives under `workspace/runs/<TOP>/<RUN_ID>/`:

```text
workspace/runs/<TOP>/<RUN_ID>/
├── data/        # HJSON register descriptions
├── doc/         # generated register documentation
├── model/       # editable Python model and regmap helpers
├── rtl/         # generated RTL, core, wrapper, filelists
├── tb/          # SystemVerilog testbench, drivers, vector tests, cocotb
├── sim/         # simulation outputs and waveforms
├── logs/        # lint, verification, signoff, and command logs
└── pnr_openroad/# timing constraints and implementation collateral
```

## Documentation

Start here:

- [Quickstart](docs/quickstart.md) — practical command sequence.
- [Folder structure](docs/folder_structure.md) — generated folders and files.
- [IP development guide](docs/guide_ip_dev.md) — single-clock IP workflow.
- [Multi-clock IP guide](docs/guide_multiclock_ip_dev.md) — multi-clock workflow.
- [SoC development guide](docs/guide_soc_dev.md) — SoC-oriented workflow.

## End-to-end regression

The full practical regression lives in `tests/test_e2e_fx.py` and is opt-in
because it runs external EDA tools and can take time:

```bash
FLEXSOC_RUN_E2E=1 pytest -s tests/test_e2e_fx.py
```

To print full tool output while debugging:

```bash
FLEXSOC_RUN_E2E=1 FLEXSOC_E2E_LIVE=1 pytest -s tests/test_e2e_fx.py
```

To skip signoff while iterating on the frontend/verification flow:

```bash
FLEXSOC_RUN_E2E=1 FLEXSOC_E2E_SKIP_SIGNOFF=1 pytest -s tests/test_e2e_fx.py
```
