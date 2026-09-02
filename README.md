<p align="center">
  <img src="assets/open-IP-SoC-logo.png" alt="FlexSoC — Open IP SoC" width="440"/>
</p>

# ⚡ FlexSoC

FlexSoC is an open-source orchestration framework for developing digital ASIC IP
and SoCs through one command-line interface: `fx`.

Its purpose is not to hide the EDA tools. Its purpose is to keep design intent,
generated collateral, verification environments, constraints, implementation
data, reports, and logs synchronized while the IP evolves.

```text
requirements and architecture
        ↓
CSR / register map + RTL interfaces + RTL behavior
        ↓
lint → authored timing contract → CDC/RDC
        ↓
functional DV + property formal
        ↓
synthesis → RTL/netlist equivalence
        ↓
pre-layout SDF / GLS / STA / power
        ↓
OpenROAD implementation
        ↓
post-route timing / SDF / GLS / power / physical sign-off
        ↓
metrics snapshot + human closure check
        ↓
qualified reusable IP or SoC release
```

## Why FlexSoC

A hardware change rarely affects only one file. Adding a status register can
change CSR configuration file (HJSON), generated register RTL, the Python CSR API,
model behavior, tests,formal properties, synthesis, and software-visible documentation.
Adding a clock domain changes constraints, testbench timing, formal assumptions, CDC/RDC
requirements, reset integration, and implementation closure.

FlexSoC makes those dependencies explicit:

- authored sources stay separate from generated collateral;
- bootstrap clock/reset settings initialize one authored `constraints/<TOP>.sdc`; after that the SDC is the timing source of truth;
- Slang resolves the reachable RTL hierarchy and produces ordered filelists;
- the same scenario/model intent can drive SystemVerilog and cocotb environments;
- functional coverage, property proof, and RTL/netlist equivalence remain separate evidence classes;
- synthesis, STA, SDF, power, and OpenROAD runs share one logical run identity;
- raw evidence is normalized into analysis JSON and one `metrics.json` snapshot;
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
- per-domain asynchronous-assert/synchronous-release reset integration;
- reusable IP loading and multi-PDK saving under `hw/ips/<top>/`.

### Design verification

- editable Python reference model;
- scenario-based vector generation;
- SystemVerilog and cocotb execution;
- Verilator code coverage;
- automatic CSR formal checks;
- authored assertions and covers through SymbiYosys;
- custom structural CDC/RDC, protocol, reset, and glitch analysis;
- waveform, log, counterexample, and filtered `--debug` inspection.

### Implementation and sign-off

- one authored SDC timing contract shared by DV, CDC/RDC, synthesis setup, implementation, and STA;
- Yosys synthesis with drive/load collateral derived from that SDC;
- EQY RTL-to-mapped-netlist equivalence;
- post-synthesis and post-PnR gate-level simulation;
- SDF generation;
- OpenSTA timing and power analysis;
- OpenROAD physical implementation;
- normalized metrics, manifests, and a colored lifecycle `fx check` dashboard.

CDC/RDC analysis is an explicit post-lint/post-SDC lifecycle gate. DFT insertion
and final foundry physical verification remain separate later-stage gates; none
substitutes for functional verification or formal equivalence.

## Install and run the toolchain

The Python package alone is **not** the complete ASIC environment. `uv sync`
installs FlexSoC and its Python dependencies, but full lint/formal/synthesis/STA/
GLS/OpenROAD flows also require the pinned EDA toolchain.

For normal full-flow use, the recommended path is the immutable Docker image
recorded in `docker/ci/image.lock`.

Clone the repository, then resolve and pull the exact verified image:

```bash
IMAGE_REF="$(bash -lc 'source docker/scripts/common.sh; validate_lock')"
docker pull "$IMAGE_REF"
```

Open an interactive development shell with the current checkout mounted at
`/workspace`:

```bash
docker run --rm -it \
  --pull=missing \
  --volume "$PWD:/workspace" \
  --workdir /workspace \
  --env PYTHONPATH=src \
  --env DEPS_MODE=system \
  "$IMAGE_REF" \
  bash
```

Inside the container, bind the current source tree and verify the environment:

```bash
uv pip install --python "$VIRTUAL_ENV/bin/python" --no-deps --editable .
fx deps-doctor
fx doctor
fx --help
```

A host installation is still useful for Python/API/documentation development:

```bash
uv sync
source .venv/bin/activate
```

but a host can run the complete ASIC flow only when the matching EDA toolchain is
already installed and `fx doctor` reports it ready. Image build/publish details
belong in [docker/README.md](docker/README.md).

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
fx sdc --setup --force
# edit constraints/my_ip.sdc

fx cdc_rdc --setup --force
fx cdc_rdc

fx model --setup --force
fx tests_gen --force
fx tb cocotb --setup --force
fx regression
fx coverage_detail

fx formal --setup --force
fx formal

fx pdk use sky130
fx syn --setup
fx syn
fx eqy --setup
fx eqy
fx signoff --setup
fx sdf
fx sta
fx power_estimate

fx manifest
fx metrics
fx check
```

`fx sdc --setup` is the handoff from bootstrap settings to authored timing intent.
Functional SV/cocotb clocks, CDC/RDC clock relationships, synthesis drive/load
setup, implementation, and STA all consume the same `constraints/<TOP>.sdc`.
Functional clocks honor SDC waveform and source latency and model clock
uncertainty as bounded reproducible jitter using the run `SEED`.

`fx metrics` writes the normalized snapshot to `meta/<pdk>/metrics.json`.
`fx check` reads that saved snapshot and renders the colored lifecycle dashboard;
it does not recollect or modify metrics.

## Minimal N-clock configuration

```bash
fx settings \
  TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart \
  N_CLOCKS=3 \
  'CLOCK_DOMAINS=cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:6:low' \
  'CLOCK_RELATIONSHIPS=async:cfg:rx,async:cfg:dsp,async:rx:dsp'
```

The command vocabulary remains the same for one or many clocks. Bootstrap
metadata initializes the first SDC and retains reset ownership/polarity. Once
`constraints/tri_stream_dsp.sdc` exists, edit clock timing and relationships
there rather than maintaining a parallel timing configuration. `top_from_core`
adds one domain-local reset synchronizer per clock/reset domain using the common
`prim_ff_2sync` primitive.

## Development principles

1. Edit the real source of truth.
2. Regenerate only the derived boundary that became stale.
3. Preserve authored RTL, model, tests, properties, and timing intent.
4. Rerun every quality gate whose assumptions changed.
5. Treat lint, CDC/RDC, simulation, coverage, proof, equivalence, timing, power, and physical closure as different evidence.
6. Prefer few complete artifacts over many overlapping reports.
7. Release only from a reproducible run with retained configuration, provenance, metrics, and manifest.

## Documentation

- [Quickstart](docs/quickstart.md) — the shortest runnable single-clock and N-clock workflows.
- [Project lifecycle](docs/project_lifecycle.md) — what happens to a project from design intent through qualification and reusable release.
- [IP development guide](docs/ip_development_guide.md) — detailed step-by-step IP development and qualification flow.
- [Command reference](docs/command_reference.md) — exact `fx` commands, options, variables, target responsibilities, and diagnostics.
- [Architecture](docs/architecture.md) — repository/backend structure, ownership boundaries, execution, provenance, and evidence model.
- [Docker and CI](docker/README.md) — locked EDA image construction, verification, publication, and CI execution.

## Run layout

A run is isolated by `RUN_TOP` and `RUN_ID`:

```text
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
├── data/                  register specifications
├── rtl/                   RTL and ordered filelists
├── doc/                   generated register documentation
├── constraints/<TOP>.sdc  authored timing contract
├── dv/                    functional and property-formal collateral
├── analysis/cdc_rdc/      compact structural CDC/RDC evidence
├── syn/<pdk>/             synthesis branch
├── impl/<pdk>/            physical implementation branch
├── signoff/<pdk>/         pre/post-route sign-off evidence
├── logs/                  raw command/tool logs
└── meta/
    ├── design_intent.json
    └── <pdk>/             settings/provenance/manifest/metrics
```

## API and end-to-end regression

Run the public API/CLI contract tests:

```bash
pytest -q tests/test_api.py
```

Run complete generated flows:

```bash
pytest -s tests/test_e2e_fx.py
```

Retain E2E workspaces while debugging:

```bash
pytest -s tests/test_e2e_fx.py --e2e-root ~/flexsoc-e2e
```

Skip implementation/sign-off for frontend-only iterations:

```bash
pytest -s tests/test_e2e_fx.py --no-signoff --e2e-root ~/flexsoc-e2e
```
