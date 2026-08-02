<p align="center">
  <img src="assets/open-IP-SoC-logo.png" alt="FlexSoC — Open IP SoC" width="440"/>
</p>

# ⚡ FlexSoC

FlexSoC is an open-source orchestration framework for developing digital ASIC IP
and small SoCs through one command-line interface: `fx`.

Its purpose is not to hide the EDA tools. Its purpose is to keep the design
intent, generated collateral, verification environments, constraints,
implementation data, reports, and logs synchronized while the IP evolves.

```text
requirements and architecture
        ↓
CSR / register map + RTL interfaces + RTL behavior
        ↓
functional DV + property formal + CDC/RDC planning
        ↓
constraints + synthesis
        ↓
RTL ↔ synthesized-netlist equivalence
        ↓
post-synthesis SDF / GLS / STA / power estimate
        ↓
OpenROAD implementation
        ↓
post-layout timing / SDF / GLS / power / physical sign-off
        ↓
qualified reusable IP or SoC release
```

## Why FlexSoC

A hardware change rarely affects only one file. Adding a status register can
change HJSON, generated register RTL, the Python CSR API, model behavior, tests,
formal properties, synthesis, and software-visible documentation. Adding a
clock domain changes constraints, testbench timing, formal assumptions, CDC/RDC
requirements, and implementation closure.

FlexSoC makes those dependencies explicit:

- authored sources stay separate from generated collateral;
- `N_CLOCKS`, `CLOCK_DOMAINS`, and `CLOCK_RELATIONSHIPS` describe clock intent once;
- Slang resolves the reachable RTL hierarchy and produces ordered filelists;
- the same vector tests can drive SystemVerilog and cocotb environments;
- functional coverage, property proof, and RTL/netlist equivalence remain separate metrics;
- synthesis, STA, SDF, power, and OpenROAD runs share one run identity;
- failed runs retain logs and tool workspaces for diagnosis.

The final goal is a repeatable path from an IP requirement to evidence that the
implemented hardware still matches its specification and RTL intent.

## Main capabilities

### IP definition and generation

- HJSON register specifications;
- register RTL and documentation generation;
- generated Python CSR/regmap API;
- editable RTL core plus generated top wrapper;
- single-clock and arbitrary N-clock configuration;
- reusable IP loading and saving under `hw/ips/<top>/`.

### Design verification

- editable Python reference model;
- scenario-based vector generation;
- SystemVerilog and cocotb execution;
- Verilator code coverage;
- automatic CSR formal checks;
- authored assertions and covers through SymbiYosys;
- waveform, log, and counterexample inspection.

### Implementation and sign-off

- logical SDC generation;
- Yosys synthesis;
- EQY RTL-to-mapped-netlist equivalence;
- post-synthesis and post-PnR gate-level simulation;
- SDF generation;
- OpenSTA timing and power estimation;
- OpenROAD place and route;
- consolidated metrics and run manifests.

CDC/RDC analysis, DFT insertion, and final foundry physical verification are
identified as explicit lifecycle gates. They are not treated as substitutes for
functional verification or formal equivalence.

## Install

```bash
uv sync
source .venv/bin/activate
fx doctor
fx --help
fx commands
```

## Minimal single-clock flow

```bash
fx settings \
  TOP=my_ip RUN_TOP=my_ip RUN_ID=dev HOST=uart \
  N_CLOCKS=1 \
  CLOCK_DOMAINS=core:clk_i:rst_ni:10:low \
  CLOCK_RELATIONSHIPS=

fx setup --force
fx hjson reg doc rtl_stub top_from_core flist --force
fx lint_suite

fx setup_model --force
fx tests_gen setup_tb setup_cocotb --force
fx regression
fx coverage_detail
fx formal

fx setup_sdc syn --force
fx eqy --force
fx sdf sta power_estimate --force
fx manifest metrics check --force
```

## Minimal N-clock configuration

```bash
fx settings \
  TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart \
  N_CLOCKS=3 \
  'CLOCK_DOMAINS=cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:6:low' \
  'CLOCK_RELATIONSHIPS=async:cfg:rx,async:cfg:dsp,async:rx:dsp'
```

The command vocabulary remains the same for one or many clocks. Clock
relationships are explicit; FlexSoC does not silently infer that every pair is
asynchronous.

## Development principles

1. Edit the real source of truth.
2. Regenerate only the derived boundary that became stale.
3. Preserve authored RTL, model, tests, and properties.
4. Rerun every quality gate whose assumptions changed.
5. Treat `PASS`, coverage, proof closure, timing closure, and physical closure as different evidence.
6. Release only from a reproducible run with retained configuration, logs, metrics, and manifests.

## Documentation

- [Quickstart](docs/quickstart.md) — the shortest runnable single-clock and N-clock workflows.
- [Project lifecycle](docs/project_lifecycle.md) — the complete ASIC design, verification, implementation, sign-off, change-propagation, reuse, and release guide.
- [Command reference](docs/command_reference.md) — every `fx` pseudo-command, backend target, option, variable, lifecycle role, and diagnostic workflow.

## Run layout

A run is isolated by `RUN_TOP` and `RUN_ID`:

```text
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
├── data/             # register specifications
├── rtl/              # RTL and ordered filelists
├── doc/              # generated register documentation
├── dv/               # functional and property-formal collateral
├── constraints/      # SDC
├── syn/<pdk>/        # synthesized implementation
├── pnr_openroad/<pdk>/
├── signoff/          # equivalence, STA, SDF, power
├── logs/
└── meta/             # manifest and metrics
```

## API and end-to-end regression

Run the public API/CLI contract tests:

```bash
pytest -q tests/test_api.py
```

Run the complete generated flows:

```bash
pytest -s tests/test_e2e_fx.py
```

Use a retained workspace while debugging:

```bash
pytest -s tests/test_e2e_fx.py --e2e-root ~/flexsoc-e2e
```

Skip implementation and sign-off for frontend-only iterations:

```bash
pytest -s tests/test_e2e_fx.py --no-signoff --e2e-root ~/flexsoc-e2e
```
