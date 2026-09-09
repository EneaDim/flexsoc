<p align="center">
  <img src="assets/open-IP-SoC-logo.png" alt="FlexSoC — Open IP SoC" width="440"/>
</p>

# ⚡ FlexSoC

FlexSoC is an open-source Python/EDA framework for **contract-driven digital design development, qualification, and release**. It applies the same small set of core mechanisms to a single reusable IP, a complex multi-clock IP, a complete SoC, or a large SoC assembled from reusable subsystems.

FlexSoC does not replace synthesis, formal, STA, PnR, simulation, or physical-sign-off tools. Those tools remain authoritative for their analyses. FlexSoC adds the layer that is usually missing between them: **source-of-truth ownership, machine-readable requirements and test plans, provenance, selective invalidation, evidence lifecycle, qualification policy, repeatability, and release packaging** through one Python API and CLI (`fx`).

The current frozen package command is IP-oriented (`fx ip_save` / `fx ip_load`). SoC-specific composition contracts and packaging are built on the same core model rather than on a second framework: IP composition, memory map, interconnect, clock/reset topology, software-visible contract, technology branches, and system-level evidence become additional authored inputs and StageContract dependencies.

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
qualified reusable design release
```

## Why FlexSoC

The value of FlexSoC is not proportional to the size of the RTL generator. It comes from making a digital design **reviewable, reproducible, incrementally re-qualifiable, and releasable** while several independent EDA tools operate on it. The same model scales by composition:

- **IP** — a peripheral, register block, arithmetic unit, or small datapath can have a concise contract and a bounded qualification flow.
- **Complex IP** — accelerators, protocol engines, DMA-style blocks, and multi-clock subsystems add richer CDC/RDC, formal, performance, timing, and implementation evidence without changing the core lifecycle model.
- **SoC** — IP composition, address space, interconnect, clocks/resets, software-visible integration, and system verification become first-class design intent connected to the same provenance and qualification graph.
- **Complex SoC** — hierarchy, multiple clock/reset domains, reusable subsystems, multiple technology branches, and partial re-qualification remain manageable because invalidation follows actual dependencies rather than rerunning everything by habit.

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

The final goal is a repeatable path from a requirement to evidence that the implemented hardware still matches its specification and design intent, whether the release unit is an IP, a subsystem, or an SoC. The concise
contract, provenance, invalidation, evidence and L1-L5 qualification model is defined
in [`docs/digital_ip_contract.md`](docs/digital_ip_contract.md).

## Main capabilities

### IP definition and generation

- HJSON register specifications;
- register RTL and documentation generation;
- generated Python CSR/regmap API;
- editable RTL core plus generated top wrapper;
- single-clock and arbitrary N-clock configuration;
- per-domain asynchronous-assert/synchronous-release reset integration;
- authoritative `spec/` requirements/test-plan shared across register interfaces;
- reusable interface releases under `hw/ips/<top>/interfaces/<REG_ITF>/`, with explicit qualification levels and multi-PDK evidence.

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

Persist project intent once with `fx settings`; normal commands then reuse `TOP`, `RUN_ID`, `REG_ITF`, qualification target, selected PDK, and derived run paths instead of requiring them on every invocation. Explicit `--workdir` overrides are useful for isolated tests/E2E workspaces, not as the normal user experience.

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

# Current scaffold baseline: generate EQY collateral only.
# EQY setup is not equivalence PASS and therefore does not satisfy L3.
fx eqy --setup

fx signoff --setup
fx sdf
fx sta
fx power_estimate

fx manifest
fx metrics
fx check
fx qualify
fx ip_save
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

- [Digital IP Contract](docs/digital_ip_contract.md) — the core contract, provenance, lifecycle-state, qualification, traceability, and release model that scales from IP to SoC.
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
├── csr/                   canonical CSR/register specifications
│   └── systemrdl/         generated SystemRDL views
├── rtl/                   RTL and ordered filelists
├── doc/                   generated register documentation
├── constraints/<TOP>.sdc  authored timing contract
├── dv/                    functional and property-formal collateral
├── analysis/
│   ├── slang/             parsing/elaboration artifacts
│   ├── lint/
│   │   ├── slang/
│   │   └── verilator/
│   └── cdc_rdc/           structural CDC/RDC evidence
├── syn/<pdk>/             synthesis branch
├── impl/<pdk>/            physical implementation branch
├── signoff/<pdk>/         qualification evidence
│   ├── post_syn/          sta / power / fusion on synthesized netlist
│   └── post_pnr/          sta / power / fusion + physical checks after PnR
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
