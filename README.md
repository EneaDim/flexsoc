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
functional DV + property formal + structural CDC/RDC analysis
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
- bootstrap clock/reset settings initialize one authored `constraints/design.sdc`; after that the SDC is the timing source of truth;
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
- custom structural CDC/RDC, protocol, reset, and glitch analysis;
- waveform, log, and counterexample inspection.

### Implementation and sign-off

- one authored SDC timing contract shared by DV, CDC/RDC, synthesis setup, implementation, and STA;
- Yosys synthesis with drive/load collateral derived from that SDC;
- EQY RTL-to-mapped-netlist equivalence;
- post-synthesis and post-PnR gate-level simulation;
- SDF generation;
- OpenSTA timing and power estimation;
- OpenROAD physical implementation;
- consolidated metrics and run manifests.

CDC/RDC analysis is an explicit post-lint lifecycle gate. DFT insertion and final
foundry physical verification remain separate later-stage gates; none substitutes
for functional verification or formal equivalence.

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

# Initialize once, then review/edit as authored timing intent.
fx sdc --force

fx setup_cdc_rdc --force
fx cdc_rdc

fx setup_model --force
fx tests_gen --force
fx setup_tb setup_cocotb --force
fx regression
fx coverage_detail

fx setup_formal --force
fx setup_formal_csr_prove setup_formal_csr_cover setup_formal_prove setup_formal_cover --force
fx formal

fx pdk use sky130
fx setup_syn
fx syn
fx setup_eqy
fx eqy
fx setup_signoff
fx sdf
fx sta
fx power_estimate
fx manifest
fx metrics
fx check
```

`fx sdc` is the handoff from bootstrap settings to authored timing intent. Functional SV/cocotb clocks, CDC/RDC clock relationships, synthesis drive/load setup, implementation, and STA all consume the same `constraints/design.sdc`. Functional clocks honor SDC waveform and source latency, and model `set_clock_uncertainty` as bounded reproducible jitter using the run `SEED`.

## Minimal N-clock configuration

```bash
fx settings \
  TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart \
  N_CLOCKS=3 \
  'CLOCK_DOMAINS=cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:6:low' \
  'CLOCK_RELATIONSHIPS=async:cfg:rx,async:cfg:dsp,async:rx:dsp'
```

The command vocabulary remains the same for one or many clocks. `N_CLOCKS`, `CLOCK_DOMAINS`, and `CLOCK_RELATIONSHIPS` are bootstrap/reset-domain metadata used to initialize the first SDC and retain reset ownership/polarity. Once `constraints/design.sdc` exists, edit clock timing and clock relationships there rather than maintaining a parallel timing configuration. FlexSoC does not silently infer asynchronous relationships.

## Development principles

1. Edit the real source of truth.
2. Regenerate only the derived boundary that became stale.
3. Preserve authored RTL, model, tests, and properties.
4. Rerun every quality gate whose assumptions changed.
5. Treat `PASS`, coverage, proof closure, timing closure, and physical closure as different evidence.
6. Release only from a reproducible run with retained configuration, logs, metrics, and manifests.

## Documentation

- [Quickstart](docs/quickstart.md) — the shortest runnable single-clock and N-clock workflows.
- [Architecture](docs/architecture.md) — code structure, backend responsibilities, execution/provenance contracts, and end-to-end data flow.
- [Project lifecycle](docs/project_lifecycle.md) — the complete ASIC design, verification, implementation, sign-off, change-propagation, troubleshooting, reuse, and release guide.
- [IP development guide](docs/ip_development_guide.md) — the detailed scaffold architecture, ownership boundaries, artifacts, rationale, failure recovery, GLS model policy, and activity-power flow.
- [Command reference](docs/command_reference.md) — every `fx` pseudo-command, backend target, option, variable, lifecycle role, and diagnostic workflow.

## Run layout

A run is isolated by `RUN_TOP` and `RUN_ID`:

```text
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
├── data/             # register specifications
├── rtl/              # RTL and ordered filelists
├── doc/              # generated register documentation
├── constraints/      # authored design.sdc timing contract
├── dv/               # functional and property-formal collateral
├── analysis/         # normalized CDC/RDC evidence
├── syn/<pdk>/        # synthesized implementation
├── impl/<pdk>/
├── signoff/          # equivalence, STA, SDF, power
├── logs/             # tool logs, including packaged lint/CDC evidence
└── meta/             # design intent + per-PDK settings/manifest/metrics/provenance
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
