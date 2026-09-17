# FlexSoC architecture

This document describes the **current repository architecture**: how the Python code is split, how one `fx` command travels through the system, which module owns each lifecycle responsibility, how artifacts and provenance are tracked, and where new functionality should be added.

It is intentionally descriptive rather than aspirational. FlexSoC should remain a **small, readable build and qualification system above EDA tools**, not become a second EDA framework.

## 1. Architectural goals

The backend follows a few constraints that are more important than class count or abstraction depth:

1. **One source of truth per design fact.** Clock/reset intent, authored RTL, generated collateral and technology artifacts must have explicit owners.
2. **Setup and execution are different operations.** Setup creates canonical machine-owned collateral; execution consumes it.
3. **Run is run-only.** Execution never regenerates or normalizes setup files; regeneration is an explicit `fx <keyword> --setup --force` action.
4. **Generated files are controlled, not opaque.** Manual edits are detected, can be explicitly validated, and are tied to current input/parent lineage.
5. **EDA tool and execution machine are independent concerns.** `CommandRequest` describes what to run; an executor decides where/how to run it.
6. **Artifacts are explicit and deterministic.** Do not select a result because it is the first/latest glob match.
7. **Technical result and provenance are separate.** A historical PASS may be `STALE`; a valid run may be based on a `VALIDATED_OVERRIDE`.
8. **No framework for hypothetical futures.** Add a shared abstraction only after a real duplication, bug, or second implementation demonstrates the need.
9. **Prefer few files and readable OOP.** Small dataclasses/facades are useful; deep inheritance, generic registries and wrapper-only helpers are not.
10. **Scale by composition, not special cases.** An IP, complex subsystem, SoC, or complex SoC uses the same StageContract/provenance/qualification primitives; system scale adds authored contract facts and dependencies rather than a parallel framework.

A useful filter before adding an abstraction is:

> What concrete duplication, bug, or second implementation requires this abstraction today?

If the answer is unclear, keep the code local and explicit.

---

## 2. System overview

The architectural unit is a **digital design contract**, not a fixed RTL size. Today the concrete reusable-package flow is IP-oriented, but the orchestration core is equally applicable to hierarchical IP and SoCs. At SoC scale, composition, memory map, interconnect, system clock/reset intent, and software-visible integration become additional source-of-truth inputs to the same graph.

The public path from user intent to EDA execution is:

```text
user / CI / Python caller
        ↓
      fx CLI
   flexsoc/cli.py
        ↓
    public API
   flexsoc/api.py
        ↓
  FlexSoCTarget / FlexSoC
        ↓
 Backend domain facade
 design / dv / syn / signoff / impl
        ↓
 setup generator or execution method
        ↓
 CommandRequest(inputs, outputs, argv, cwd, env)
        ↓
      ToolRunner
        ↓
 LocalExecutor or SshExecutor
        ↓
 existing EDA tool
        ↓
 artifacts + logs + reports
        ↓
 Reporting + Provenance
        ↓
 manifest → metrics snapshot → check dashboard
```

The EDA tools remain authoritative for analysis. FlexSoC owns the **wiring, state, inputs, artifact identity, lifecycle and reproducibility** around them. A status without its supporting artifact is incomplete evidence: release packaging therefore retains normalized lint evidence plus the compact CDC/RDC `summary.json`/`cdc_rdc.rpt` contract at the same run-relative paths consumed by reporting, without copying every raw extraction log.

---

## 3. Main object relationships

```text
FlexSoCConfig
    │
    ├─ project_root
    ├─ workdir
    └─ default settings
          ↓
       FlexSoC
          ↓
    FlexSoCTarget
          ↓
        Backend
  ┌───────┼────────┬────────┬─────────┐
  ↓       ↓        ↓        ↓         ↓
Design   DvFlow    Syn    Signoff   ImplementationFlow
  │               │       │
  ├─ IP            └─ Eqy ├─ StaAnalysis
  ├─ FSM                    │
  └─ SoC                    │
                             ├─ GateLevelSimulation
                             ├─ PowerAnalysis
                             └─ FusionAnalysis
```

`BackendContext`, `FlowPaths`, `ClockConfig`, PDK layout helpers and the execution/reporting primitives are shared core services. Domain modules should not recreate their own path model, clock model, executor or provenance database.

---

## 4. Setup, provenance and execution contract

### 4.1 Normal setup

A setup phase:

1. resolves its canonical inputs and parent stages;
2. generates machine-owned collateral deterministically;
3. returns the **final paths that actually exist after generation/normalization**;
4. records generated/effective hashes in `meta/<pdk>/provenance.json`;
5. leaves the setup state `CLEAN`.

A generator must never return a pre-normalization path that it has already moved or replaced. The returned paths are part of the provenance contract.

### 4.2 StageContract, fingerprints, and run-only provenance gate

`STAGE_CONTRACTS` is the single small dependency DAG. A stage declares semantic configuration, real parent stages, canonical evidence ownership, storage scope (`run` or `pdk`), and the relevant tool contract. Its fingerprint is derived from effective inputs/configuration, parent lineage, stage-specific tool identity, and canonical outputs. This keeps invalidation selective: a PnR change invalidates PnR and post-implementation descendants, while a PDK or OpenROAD change does not make technology-independent RTL evidence stale.

Before an execution target consumes setup collateral, FlexSoC evaluates the current workspace:

```text
MISSING               no current artifact/provenance record
CLEAN                 canonical generated bytes + current lineage
MODIFIED              machine-owned generated file changed
VALIDATED_OVERRIDE    exact current edit explicitly accepted
STALE                 source/config/tool/parent lineage changed
INVALID               required artifact/provenance is inconsistent
```

Only `CLEAN` and `VALIDATED_OVERRIDE` are runnable. Recovery is explicit:

```text
MODIFIED  → validate_override for that exact edit, or `<keyword> --setup --force`
STALE     → `<keyword> --setup --force`
INVALID   → initial setup if never recorded; otherwise repair + `<keyword> --setup --force`
```

Calling a setup phase without `--force` reuses existing `CLEAN` or `VALIDATED_OVERRIDE` collateral. It does not erase a validated experiment. Calling a run target never executes setup implicitly.

A configuration change is therefore not an override workflow. Persist the choice (`fx settings TARGET_OPT=delay1`), regenerate the affected setup explicitly (`fx syn --setup --force`), then run `fx syn`.

`VALIDATED_OVERRIDE` is not a permanent waiver. It is bound to the exact effective file hashes and lineage that were accepted.

### 4.3 Restore behavior

If a modified generated file is restored byte-for-byte to its canonical generated hash, the setup naturally returns to `CLEAN`; no validation is required.

### 4.4 Runtime immutability

Execution must not mutate setup-owned collateral. For example, sign-off setup creates canonical Tcl templates, while each STA/SDF/power scenario executes a scenario-local copy below its report directory.

```text
signoff --setup generated template
signoff/<pdk>/sdf/write_sdf.tcl
             │
             └─ immutable setup artifact

runtime copies
signoff/<pdk>/sdf/ss/write_sdf.tcl
signoff/<pdk>/sdf/tt/write_sdf.tcl
signoff/<pdk>/sdf/ff/write_sdf.tcl
```

This is essential: a validated designer edit must remain `VALIDATED_OVERRIDE` after the consumer runs; the consumer must not make its own setup `MODIFIED`.

---

## 5. Artifact and run layout

One logical run is rooted at:

```text
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
```

Typical contents are:

```text
runs/<top>/<run_id>/
├── csr/                       canonical CSR/register input collateral
│   └── systemrdl/             generated SystemRDL views
├── rtl/                       generated/copied RTL and ordered filelists
├── doc/                       generated documentation
├── constraints/<TOP>.sdc      authored timing contract
├── dv/
│   ├── slang/                 parsing/elaboration artifacts
│   ├── lint/{slang,verilator}/
│   ├── cdc_rdc/               structural CDC/RDC evidence
│   ├── functional/            model, tests, testbenches, simulation
│   └── formal/                SBY/property collateral and results
├── syn/<pdk>/                 synthesis scripts, logs, mapped netlist
├── impl/<pdk>/                ORFS/OpenROAD implementation handoff/results
├── signoff/<pdk>/             EQY, STA, SDF, GLS, power, fusion
├── logs/                      command and tool logs
└── meta/
    ├── design_intent.json
    └── <pdk>/
        ├── settings.json
        ├── provenance.json
        ├── manifest.json
        └── metrics.json
```

Technology-independent design/DV state and technology-dependent implementation/sign-off state intentionally share one logical `RUN_ID` but use PDK-scoped branches where required.

---

## 6. Clock/reset and timing intent

FlexSoC keeps **bootstrap domain/reset metadata** separate from the **authored timing contract**. They have different owners and should not drift into two competing clock models.

```text
fx settings
  N_CLOCKS / CLOCK_DOMAINS / CLOCK_RELATIONSHIPS
        │
        │ bootstrap topology + reset ownership/polarity
        ▼
fx sdc --setup
        ▼
constraints/<TOP>.sdc
        │
        │ authored timing source of truth
        ├── functional SV/cocotb clock generation
        ├── CDC/RDC clock relationships
        ├── synthesis drive/load collateral
        ├── OpenROAD/ORFS timing input
        └── OpenSTA pre-/post-route analysis
```

`ClockConfig` remains the small normalized Python view used by consumers, but once `<TOP>.sdc` exists its clock timing fields are read from SDC. Reset signal ownership and polarity are merged from the bootstrap metadata because ordinary SDC does not describe them.

### 6.1 Bootstrap the topology

Persist run identity and initial clock/reset topology with `fx settings`. The project values live in `.flexsoc/settings.json`; runs also snapshot common technology-independent intent in `meta/design_intent.json` and effective technology configuration in `meta/<pdk>/settings.json`.

Single clock:

```bash
fx settings \
  N_CLOCKS=1 \
  CLOCK_DOMAINS=core:clk_i:rst_ni:10:low
```

Multiple clocks:

```bash
fx settings \
  N_CLOCKS=3 \
  'CLOCK_DOMAINS=cfg:cfg_clk_i:cfg_rst_ni:20:low,rx:rx_clk_i:rx_rst_ni:16:low,dsp:dsp_clk_i:dsp_rst_ni:30:low' \
  'CLOCK_RELATIONSHIPS=async:cfg:rx,async:cfg:dsp,async:rx:dsp'
```

Each `CLOCK_DOMAINS` entry is `name:clock_port:reset_port:period_ns[:low|high]`; relationships are `async`, `sync`, or `generated`. `N_CLOCKS` must match the number of domains. FlexSoC never guesses that unrelated domains are asynchronous.

These values are authoritative while the run is being bootstrapped. They initialize the first SDC and retain the reset-domain information required by reset-aware backends. They are **not** a second authored timing database after the SDC exists.

`top_from_core` also owns reset-release integration at the generated wrapper boundary. For each clock/reset domain it instantiates the existing `prim_ff_2sync` directly with reset value `0` and constant data `1`, producing asynchronous assertion and synchronous deassertion. The core and generated register block consume the synchronized domain reset. FlexSoC does not introduce a wrapper-only `prim_reset_sync` primitive because it would add no hardware behavior.

### 6.2 Initialize and author the SDC

After RTL elaboration/lint are clean, initialize the timing contract once:

```bash
fx sdc --setup --force
```

The resulting `constraints/<TOP>.sdc` is designer-owned timing intent. Its scaffold is deliberately complete and readable: primary/generated clocks, latency/uncertainty/transition, clock relationships, input/output delay, input drive, output load, and commented timing-exception/design-rule sections. False paths and multicycle paths are never inferred.

`SDC_IO_DELAY_PCT` is only a bootstrap value for the initial single-clock I/O-delay scaffold. After generation, edit the SDC itself instead of maintaining the same timing fact in settings.

### 6.3 Shared consumer semantics

Non-STA backends parse only the small SDC subset they actually need; OpenSTA sources the file directly. Do not build a general SDC reimplementation inside FlexSoC.

Functional SV and cocotb derive the same digital clock stimulus from:

```text
create_clock -period/-waveform
set_clock_latency -source
set_clock_uncertainty -setup/-hold
```

The first rising edge is `waveform.rise + source_latency`; high time is `waveform.fall - waveform.rise`. Later rising edges receive uniform bounded jitter of `±max(setup_uncertainty, hold_uncertainty)`, quantized at 1 ps. The existing run `SEED` drives the same xorshift32 sequence in both backends, so clock phase, duty cycle, relative skew, and jitter remain reproducible. `set_clock_transition` remains an STA/electrical constraint rather than an analog slew model.

CDC/RDC derives clock relationships from the same SDC and combines them with reset metadata. Synthesis derives only the small `abc.constr` drive/load boundary required by Yosys/ABC. Pre- and post-route STA source the same authored SDC; the physical stage changes the netlist/parasitics/clock propagation, not the timing-intent file.

When the clock/reset **topology** changes, update bootstrap metadata and intentionally regenerate/review `<TOP>.sdc`. When only timing values or exceptions change, edit `<TOP>.sdc` directly and regenerate only affected setup collateral.

Do not create parallel `*_multi` flows, per-PDK authored SDCs, or a second clock/timing vocabulary.

---

## 7. Command execution model

`CommandRequest` is the boundary between lifecycle semantics and machine execution:

```text
CommandRequest
├── argv
├── cwd
├── env
├── inputs
└── outputs
```

A flow object is responsible for declaring every file the external tool actually consumes and every result that must be available after execution.

`ToolRunner` selects an executor:

- `LocalExecutor`: run directly in the current workspace;
- `SshExecutor` shared mode: execute against a shared path mapping;
- `SshExecutor` rsync mode: transfer declared inputs, run remotely, retrieve declared outputs.

Workspace binding identity matters. A local symlink such as an EQY `rtl_common.f` binding is still the declared artifact path even if rsync dereferences the file content during transfer. Do not call `resolve()` merely to make paths look canonical when it changes the path contract consumed by the tool.

---

## 8. Reporting model

`backend/release/reporting.py` collects evidence; it does not run EDA.

Two dimensions are kept separate:

```text
Evidence outcome:    PASS / FAILED / REVIEW / WAIVED / MISSING
Provenance freshness: MISSING / CLEAN / VALIDATED_OVERRIDE / MODIFIED / STALE / INVALID
```

Examples:

```text
PASS   + CLEAN                 current successful evidence
PASS   + VALIDATED_OVERRIDE    successful evidence using an explicitly accepted setup edit
FAILED + CLEAN                 current, reproducible technical failure
REVIEW + CLEAN                 current evidence that still requires engineering review
PASS   + STALE                 historical success that no longer qualifies current intent
```

Qualification combines these axes; provenance never turns a technical failure into PASS. `WAIVED` is an explicit policy result and remains distinct from PASS.

`fx metrics` collects the current normalized evidence and writes `meta/<pdk>/metrics.json`. `fx check` is intentionally read-only with respect to that snapshot: it renders the saved JSON as the lifecycle dashboard and fails clearly when the snapshot is missing. `fx manifest` separately records run/tool/PDK identity. This separation makes a metrics file a stable comparison point instead of silently changing while it is being viewed.

---

# 9. Repository map

This section maps the source tree by responsibility. Saved IP/generated trees under `hw/ips/**` follow the artifact layout and are not enumerated file-by-file because they are design data, not backend source modules.

## 9.1 Repository root

| Path | Responsibility |
| --- | --- |
| `README.md` | Project entry point, capabilities, installation, minimal flow and documentation index. |
| `pyproject.toml` | Python package metadata, CLI entry points and Python dependencies. |
| `uv.lock` | Reproducible Python dependency lock. |
| `Makefile` | Common contributor workflows for environment setup, lint, API/E2E tests and cleanup. Hardware lifecycle commands themselves are `fx` commands. |
| `LICENCE` | Project license. |
| `.gitignore` | Repository ignore policy for generated/cache/run data. |
| `.github/workflows/ci.yml` | CI qualification orchestration. |
| `.github/workflows/toolchain-image.yml` | Toolchain image build/publish workflow. |
| `docker/` | Reproducible EDA/CI execution image and helper scripts. |
| `vendor/` | Vendor manifests for external RTL dependencies. |
| `hw/ips/` | Saved/reusable IP packages and common RTL/IP support libraries. |
| `tests/` | Public API contract and real end-to-end qualification. |
| `docs/` | User, lifecycle, architecture and flow documentation. |

## 9.2 `src/flexsoc/` — public Python package

| File | Responsibility |
| --- | --- |
| `__init__.py` | Lazy public exports of the main API objects. Keeps import cost/coupling small. |
| `cli.py` | Typer/Rich front-end: parses user options, renders help/status, then delegates behavior to the public API. It should not contain ASIC backend algorithms. |
| `api.py` | Public orchestration API. Defines target metadata, `FlexSoCTarget` execution/routing, setup dependencies, provenance relationships, `FlexSoCConfig`, `FlexSoC` and result objects. This is the lifecycle boundary, not an EDA implementation module. |

### `api.py` flow

```text
CLI target name
   ↓
TARGETS / aliases
   ↓
FlexSoCTarget
   ├─ `--setup` phase: generate → provenance record
   ├─ execution target: validate provenance → backend run
   └─ composite target: ordered lifecycle operations
```

Keep tool-specific Tcl/Yosys/SBY generation out of `api.py`; it belongs in the domain module that owns the stage.

Large Python modules use visible section headers (`# ---`) to keep responsibilities readable in-place. In particular, `api.py`, `cli.py`, and `backend/core/core.py` are divided into data/configuration, routing, settings, technology, execution and shared-infrastructure zones. Section comments describe ownership; they should not narrate obvious individual statements.

---

### Backend operation vocabulary

Backend flow methods use one small operation vocabulary:

- `init_*`: create designer-owned starting content or authored scaffolds;
- backend `setup_*` methods: generate machine-owned execution collateral;
- `run_*`: execute a tool, simulation, proof, or qualification check;
- `collect_*`: normalize existing evidence without rerunning the producing tool;
- `show_*`: render existing structure/evidence for the user;
- `debug_*`: explicit diagnostic execution.

The public and backend vocabularies intentionally expose only the canonical lifecycle names. Migration-only aliases are not retained: stale callers should fail clearly rather than silently extending the API surface.

## 9.3 `src/flexsoc/backend/` — lifecycle implementation

| File | Responsibility |
| --- | --- |
| `backend/backend.py` | Defines `Backend`, the small facade composing Core, Design, DV, synthesis, sign-off, implementation and Release domains. |

The subpackages are organized by ASIC lifecycle responsibility rather than by EDA executable.

---

## 9.4 `backend/core/` — shared infrastructure

`core.py` is the top narrative file for shared backend infrastructure. It owns the
cross-domain data structures and composes the few Core services used by the domain
backends. Details live in three small subpackages only:

```text
backend/core/
├── core.py
├── flow/
│   ├── session.py
│   ├── target.py
│   ├── lifecycle.py
│   └── provenance.py
├── runtime/
│   ├── execution.py
│   └── toolchain.py
└── render/
    ├── show.py
    └── templates.py
```

### `core.py`

Owns shared design/run structures and deterministic filesystem/path logic:

- `Core`, the small composition point for PDK, toolchain and workspace services;
- `ClockDomain`, `ClockRelationship`, `ClockConfig`;
- PDK catalogue/spec/view discovery;
- canonical `PDKRunLayout` and `FlowPaths`;
- deterministic RTL/filelist ordering;
- safe generated-tree/file replacement;
- `BackendContext` and `PdkManager`.

Add logic here only when it is genuinely cross-domain. Do not turn `core.py` into a
generic utilities dump.

### `flow/`

Owns target orchestration and lifecycle state:

- `TargetSession` and workspace/settings operations;
- target catalogue/contract data;
- freshness/lifecycle evaluation;
- provenance hashing, lineage and invalidation.

### `runtime/`

Owns external command execution and tool discovery:

- `CommandRequest` / `CommandResult`;
- `ExecutionTarget`, `LocalExecutor`, `SshExecutor`, `ToolRunner`;
- terminal/log rendering owned by command execution;
- toolchain discovery, doctor checks and locked dependency metadata.

EDA-specific semantics do not belong in executors. Executors know paths, transport,
environment and processes; they do not interpret timing corners, PDK intent or formal
results.

### `render/`

Owns the two small cross-domain renderers:

- `ShowRenderer` for canonical evidence/spec rendering;
- `Templates` for package-owned Jinja scaffold rendering and writing.

The actual scaffold templates remain under `src/flexsoc/templates/`.

---

# 11. Where to put new code

Use this decision order:

1. **Is it public target dispatch/configuration?** → `api.py`.
2. **Is it shared path/clock/PDK/filesystem context?** → `backend/core/core.py`.
3. **Is it target lifecycle/provenance/session policy?** → `backend/core/flow/`.
4. **Is it process/SSH/tool discovery?** → `backend/core/runtime/`.
5. **Is it canonical show/template rendering?** → `backend/core/render/`.
6. **Is it evidence parsing/qualification/package reporting?** → `backend/release/`.
7. **Is it generated design collateral?** → `backend/design/`.
8. **Is it DV-specific?** → `backend/dv/`.
9. **Is it synthesis/EQY?** → `backend/syn/`.
10. **Is it timing/GLS/power/sign-off?** → `backend/signoff/`.
11. **Is it physical ORFS/OpenROAD implementation?** → `backend/impl/`.

Do not add a new module merely to avoid adding ten readable lines to the owning module. Conversely, if one responsibility is repeated across several domains and has a stable contract, extracting one small shared helper may improve clarity.

---

# 12. Architecture evolution and open/private layering

The public FlexSoC core should remain the **single source of truth** for generic lifecycle behavior. A future private/company layer should depend on the public package rather than fork/copy it:

```text
FlexSoC Open
     ↓
private/company package
     ↓
customer/IP project
```

Generic bug fixes, provenance improvements, deterministic artifact handling and reusable open EDA support belong upstream in the open core. Private IP, customer/foundry/NDA material, proprietary qualification rules and AI skills can live above it.

Do not create a universal plugin framework in advance. Introduce an extension point only after multiple real private integrations demonstrate the same small interface.

This preserves the core design objective:

> **Simple enough to read, complete enough to trust, structured enough to extend.**


### Canonical SDC ownership

FlexSoC keeps exactly one authored timing contract per run: `constraints/<TOP>.sdc`. `CLOCK_DOMAINS` and `CLOCK_RELATIONSHIPS` are bootstrap/reset-domain metadata used to create the first scaffold; they are not a second timing database. `sdc.py` owns initialization and the small normalized view needed outside STA. Functional TB consumes clock waveform/phase, CDC/RDC consumes clock relationships, synthesis derives ABC drive/load collateral, and STA sources the SDC directly. False paths and multicycle paths remain authored SDC intent and are never inferred.


### STA scenario evidence

STA keeps the scenario model deliberately small: one scenario is a resolved Liberty corner plus `setup` or `hold`, for one lifecycle stage. The same authored `constraints/<TOP>.sdc` is used in every scenario. OpenSTA scenario-local reports are execution diagnostics; canonical qualification evidence is only `sta/sta.rpt` and `sta/summary.json`. The report is QoR-first (scenario status, WNS/TNS, violating/unconstrained paths, clock minimum-period/Fmax) followed by detailed scenario content. This avoids report proliferation while retaining complete evidence.
