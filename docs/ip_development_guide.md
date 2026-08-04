# 🧩 FlexSoC IP development guide

This document explains how FlexSoC turns an IP idea into reproducible design,
verification, synthesis, sign-off, and release evidence. It follows the same
order as [Project lifecycle](project_lifecycle.md) and
[Command reference](command_reference.md), but focuses on the implementation
model behind the commands:

- what FlexSoC considers a source of truth;
- which scaffold each stage creates;
- which files are safe to edit;
- which files are regenerated;
- why each quality gate exists;
- what a PASS proves and does not prove;
- how to recover when a stage fails.

Use the documents together:

| Document | Primary use |
| --- | --- |
| [Quickstart](quickstart.md) | Run the shortest supported flow. |
| [Project lifecycle](project_lifecycle.md) | Decide what engineering work and evidence are required next. |
| [Command reference](command_reference.md) | Find exact commands, variables, targets, and diagnostics. |
| **This guide** | Understand the generated architecture, ownership boundaries, and reasoning behind the flow. |

> **Design rule:** authored intent is edited; generated collateral is refreshed.
> A failed gate is repaired at the earliest source that owns the failure, not by
> patching a later report or generated artifact.

---

## 1. FlexSoC mental model

FlexSoC is a framework around a run workspace. It is not a monolithic compiler
and it does not hide the underlying EDA tools. Each `fx` target establishes one
small boundary, generates a script or scaffold where needed, executes the
selected tool, and archives evidence under one run identity.

```text
repository checkout
    owns FlexSoC source, reusable IPs, tests, docs, lockfiles

WORKSPACE / RUN_TOP / RUN_ID / PDK
    owns one generated and executed design run

PDK profile
    owns technology views and corner mapping

toolchain.lock + uv.lock
    own reproducible EDA and Python environments
```

The canonical run identity is:

```text
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
```

Technology-independent design and DV artifacts live above PDK-specific leaves.
Mapped netlists, timing, power, SDF, GLS, and implementation results are keyed
by PDK so several technologies can coexist in one logical run.

### 1.1 Authored versus generated ownership

| Artifact | Owner | Normal action |
| --- | --- | --- |
| Requirements and acceptance criteria | designer/system architect | edit and review |
| HJSON register specification | IP designer | edit |
| RTL core and custom RTL | RTL designer | edit |
| Behavioral model | verification/IP designer | edit |
| Scenario catalogue and expected behavior | verification designer | edit |
| Design assertions and covers | RTL/formal designer | edit |
| Register RTL, docs, and Python regmap | generator | regenerate |
| Top wrapper around the core | generator | regenerate after port/CSR changes |
| Ordered RTL filelists | elaboration | regenerate after hierarchy changes |
| Vector files | scenario generator | regenerate from authored tests |
| SV/cocotb/formal/SDC/synthesis/sign-off scaffolds | generator | regenerate after owning inputs change |
| Tool scripts, reports, waves, metrics, manifests | run | retain as evidence; do not edit |

`--force` is for machine-owned files. It is not permission to overwrite an
edited model, test catalogue, core, or property file without review.

### 1.2 Execution and logging model

A target may have Make prerequisites that remain fail-fast. Explicit top-level
targets written on the same command line are launched in the order supplied.
Use shell `&&` or a composite target when later work must not run after a
failure.

```bash
fx lint_suite regression formal
```

For diagnosis:

```bash
fx <target> --info
fx <target> --dry-run --script
fx <target> --live
```

Gate simulation and activity-power targets are quiet by default. The terminal
shows status and the log path; complete compiler, simulator, converter, and
OpenSTA output stays in the run logs. `--live` streams the same output without
removing the archived log.

---

## 2. Run workspace anatomy

A developed IP run normally contains:

```text
runs/<RUN_TOP>/<RUN_ID>/
├── data/                         HJSON register sources
├── doc/                          generated register documentation
├── rtl/                          authored/generated RTL and ordered filelists
├── constraints/                  generated and authored SDC
├── dv/
│   ├── functional/
│   │   ├── model/                behavioral model, regmap API, scenarios
│   │   ├── tests/                generated config and vector files
│   │   ├── tb/
│   │   │   ├── sv/               generated SystemVerilog harness
│   │   │   └── cocotb/           generated cocotb harness and drivers
│   │   ├── sim/
│   │   │   ├── rtl/              RTL simulations and waves
│   │   │   ├── post_syn/<pdk>/   post-synthesis GLS
│   │   │   └── post_pnr/<pdk>/   post-route GLS
│   │   └── coverage/             merged coverage and reports
│   └── formal/
│       ├── csr/                   generated CSR formal collateral
│       ├── properties/            authored design properties/configuration
│       └── runs/                  BMC/prove/cover results
├── analysis/                     hierarchy and future CDC/RDC results
├── syn/<pdk>/                    synthesis scripts, netlist, reports
├── pnr_openroad/<pdk>/           physical implementation
├── signoff/
│   ├── equivalence/<pdk>/        RTL-to-netlist EQY evidence
│   ├── sdf/<pdk>/                generated SDF corners
│   ├── sta/<pdk>/                timing scripts and reports
│   ├── power/<pdk>/              vectorless and activity-based power
│   └── path_view/<pdk>/          timing path views
├── logs/                         command and stage logs
└── meta/<pdk>/                   manifest and metrics
```

Do not diagnose a run by looking at only one report. The retained settings,
command log, stage log, generated script, input artifact, result artifact, and
manifest form one evidence set.

---

### 2.8 Recovering a Docker doctor failure

The `toolchain-installed` image is a recovery boundary, not a disposable
intermediate. If doctor fails after installation, preserve the checkpoint and
fix only the runtime or validation defect.

SBY and EQY version reporting are representative cases. Upstream normally
derives each release string from Git description metadata, but FlexSoC uses
shallow, detached, content-pinned checkouts. The installer therefore injects
the versions from `toolchain.lock`. Legacy launchers that print only `SBY` or
`EQY` are repaired in place on the next build; Verilator, Slang, Icarus, Yosys,
solvers, OpenSTA, and GTKWave are not rebuilt.

GTKWave is handled differently from ordinary CLI tools during doctor. Starting
its main executable initializes GTK and can fail in a headless container even
when the installation is correct. FlexSoC therefore records the locked GTKWave
version at install time, checks the source marker and prefix-local `gtkwave` and
`fst2vcd` executables, and verifies that the viewer has no unresolved shared
libraries. The doctor does not require `DISPLAY` and does not weaken the
provenance check.

## 3. Phase 0 — environment, toolchain, and PDK

Before generating an IP, establish the execution authority.

```bash
uv sync
source .venv/bin/activate
fx doctor
fx commands
fx pdk list
fx pdk info <pdk>
fx pdk use <pdk>
```

### 3.1 Toolchain authority

FlexSoC supports a managed host toolchain and a pinned Docker image. A project
should choose one authority for qualification and releases rather than mixing
arbitrary host versions with container results.

For a Docker-authoritative workflow:

```bash
docker/scripts/system-inventory.sh
docker/scripts/preflight.sh
FLEXSOC_JOBS=2 docker/scripts/build.sh
docker/scripts/verify.sh
FULL_E2E=1 docker/scripts/verify.sh
```

The normal CI consumes the immutable digest from `docker/ci/image.lock`; it does
not build the EDA stack during every source job.

### 3.2 PDK readiness

`fx pdk use` validates the selected digital views. The logical flow needs at
least a synthesis/typical Liberty and functional gate-level Verilog. Sign-off
also needs the configured corner libraries, primitive/support models, and the
correct directory hierarchy for that PDK.

### 3.3 When environment setup fails

| Symptom | Interpretation | Repair path |
| --- | --- | --- |
| `fx doctor` reports MISSING | required executable is not available | activate the pinned environment or rebuild the image/toolchain |
| tool is `COMPAT` rather than `OK` | executable works but differs from the tested revision | use only for diagnosis; qualify with the pinned image before release |
| PDK profile exists but `pdk use` fails | expected views are missing or rooted incorrectly | inspect `fx pdk info`, `PDK_ROOT`, and actual Liberty/Verilog paths |
| Docker build runs out of memory | parallel source builds exceed WSL/Docker limits | lower `FLEXSOC_JOBS`, inspect `docker system df`, and configure WSL memory/swap |
| local and CI disagree | tool or image identity differs | compare manifest, lock hashes, image digest, and command settings |

---

## 4. Phase 1 — requirements and acceptance criteria

FlexSoC cannot infer the intended behavior. Before scaffolding, define:

- supported functions and modes;
- legal and illegal inputs;
- latency, throughput, ordering, and back-pressure;
- reset and recovery behavior;
- software configuration and observable status;
- clock/reset domains and crossing mechanisms;
- timing, area, power, safety, and test requirements;
- functional scenarios, properties, covers, and sign-off criteria.

A requirement should map to one or more evidence mechanisms:

```text
behavioral scenario
assertion or cover
CSR semantic rule
CDC/RDC structural review
synthesis/equivalence requirement
STA constraint or exception
power workload and budget
physical sign-off check
```

The designer owns ambiguity. If a test and RTL disagree because the requirement
is vague, first settle the requirement and then update both sources of intent.

---

## 5. Phase 2 — CSR and register-map development

### 5.1 Bootstrap

```bash
fx setup --force
fx hjson --force
```

`fx setup` creates the run directory structure. `fx hjson` creates a starter
register specification under `data/`.

For a single register window, the default starter includes control, mode,
status, and result examples. For N-clock scaffolds, FlexSoC can create named
register windows aligned with owning domains, such as configuration and DSP
windows.

### 5.2 Source of truth

HJSON owns:

- register offsets;
- field bit positions and width;
- reset values;
- software and hardware access policies;
- side effects and descriptions;
- register-window identity.

Generate the derived collateral:

```bash
fx reg doc --force
fx regmap_py --force
```

Typical outputs are:

```text
rtl/<top>_reg_pkg.sv
rtl/<top>_reg_top.sv
doc/<top>.md
dv/functional/model/<top>_regmap.py
```

The exact generated register files depend on interface and window structure.
Tests and models should import addresses, masks, and field information from the
generated Python regmap rather than copying constants.

### 5.3 Why the split matters

The HJSON-to-RTL-to-Python chain guarantees that software-visible metadata,
hardware decode, documentation, formal CSR semantics, and DV access helpers are
derived from one specification. Manual edits to generated register RTL create a
fork that later regeneration will erase and that other consumers cannot see.

### 5.4 CSR failure recovery

| Failure | First evidence | Designer action | FlexSoC rerun |
| --- | --- | --- | --- |
| HJSON parse or generation error | `reg`/`doc` log | fix syntax, duplicate names, access policy, or invalid fields | `fx reg doc regmap_py --force` |
| CSR test uses wrong offset or mask | generated regmap versus handwritten constant | remove duplicated constants and use the generated API | `fx regmap_py tests_gen --force` |
| register reset differs from RTL | CSR formal counterexample or regression | correct HJSON reset or hardware update ownership | `fx reg doc regmap_py setup_formal --force`, then `fx formal` |
| new register is absent from wrapper | top wrapper or filelist is stale | regenerate the mechanical boundary | `fx top_from_core flist --force` |
| multi-domain register access crosses unsafely | architecture/CDC review | add synchronizer, handshake, shadow register, or FIFO | regenerate wrappers/tests/constraints and rerun all affected gates |

---

## 6. Phase 3 — RTL core, wrapper, and hierarchy

### 6.1 Starter scaffold

```bash
fx rtl_stub --force
```

For a new single-clock IP this creates a starter core and aligned top wrapper.
The core demonstrates sequential state, CSR control/status wiring, a small
functional datapath, reset behavior, and externally visible ports. It is a
bootstrap example, not a required architecture.

For N-clock IPs, the scaffold demonstrates:

- explicit clocks and resets per domain;
- domain-owned sequential logic;
- conservative single-bit control synchronization;
- safe handling of multi-bit configuration while disabled;
- a generated wrapper with register windows and domain interfaces.

### 6.2 Authored core versus generated wrapper

```text
rtl/<top>_core.sv   authored hardware behavior
rtl/<top>.sv        generated mechanical top integration
```

Edit the core. After a port change:

```bash
fx top_from_core --force
```

The generator parses the core port list, preserves infrastructure ownership,
connects register blocks, and exposes non-hidden functional ports at the top.

### 6.3 Ordered hierarchy

```bash
fx flist --force
```

Slang elaborates downward from the selected top and emits ordered filelists:

```text
rtl/rtl_common.f
rtl/rtl_ip.f
```

Those lists feed lint, simulation, formal, synthesis, and equivalence. A stale
hierarchy can make every downstream stage analyze the wrong design.

### 6.4 Structural checks

```bash
fx lint_suite
fx slang_hier
fx slang_ast
```

Lint checks syntax, widths, latches, unused signals, and tool-specific structural
rules. Hierarchy inspection verifies the reachable design and helps identify an
unexpected module, duplicate definition, or missing package.

### 6.5 RTL failure recovery

| Symptom | Likely owner | Repair |
| --- | --- | --- |
| top port missing or duplicated | generated wrapper stale | regenerate `top_from_core`, then `flist` and both testbenches |
| unresolved module/package | filelist or source path | inspect `slang_hier`, includes, package order, and `rtl_common.f`/`rtl_ip.f` |
| inferred latch | authored combinational RTL | complete assignments or make state explicit; do not waive an accidental latch |
| width/sign warning | interface/algorithm definition | define signedness and conversion intentionally; update model and tests too |
| reset warning or simulation X | reset architecture | make reset ownership and deassertion policy explicit |
| multi-clock logic works only in simulation | CDC/RDC structure | replace direct crossings with reviewed synchronizers, handshakes, or FIFOs |

After an RTL repair, rerun at least:

```bash
fx flist lint_suite --force
fx regression
fx formal
```

and every implementation/sign-off stage whose logic changed.

---

## 7. Phase 4 — functional design verification

Functional DV uses one authored model and scenario catalogue to generate one
backend-neutral command stream consumed by RTL simulation and GLS.

### 7.1 Model and scenario scaffold

```bash
fx setup_model --force
```

The command creates four files in `dv/functional/model/`:

```text
<top>_model.py          editable behavioral reference model
<top>_regmap.py         generated CSR API from HJSON
<top>_tests.py          editable scenario catalogue and vector policy
<top>_regmap_tests.py   generated CSR/input toggle scenario
```

The split prevents three common mistakes:

1. putting register layout constants in the behavioral model;
2. putting test selection and vector formatting in the algorithm model;
3. editing generated coverage/CSR tests by hand.

The starter model exposes a transaction-level `compute()` method and a declared
latency. Stateful or protocol-driven IPs may replace that simple contract, but
the model should remain independent of one simulator backend.

### 7.2 Scenario materialization

```bash
fx tests_gen --force
fx test_gen --force --set TEST_NAME=smoke
fx tests
```

Each test becomes:

```text
dv/functional/tests/<test>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

The vector grammar supports:

- timed direct signal drives;
- timed fixed-cycle checks;
- event-driven checks guarded by a valid signal;
- generated CSR `@write` and `@read` commands;
- reset/config commands where supported.

Rows with the same cycle form one atomic batch. SV and cocotb drive the complete
batch before the active edge and check after the same generated settling phase.
A command row that consumes time cannot share a cycle with an unrelated command
or direct drive. This common contract is essential: backend agreement is only
meaningful when both drivers execute the same architectural schedule.

### 7.3 SystemVerilog scaffold

```bash
fx setup_tb --force
```

The generated SV environment includes:

- clock/reset generation from `ClockConfig`;
- the DUT instance;
- TL-UL or register-interface transport helpers;
- vector parsing and atomic batching;
- deterministic waveform dumping;
- fixed/event-driven monitors;
- reportable PASS/FAIL behavior.

Canonical single-clock testbenches instantiate the DUT as `u_<TOP>`; for
`TOP=test`, the VCD scope is `test_tb/u_test`.

### 7.4 cocotb scaffold

```bash
fx setup_cocotb --force
```

The cocotb environment includes:

- a simulator Makefile;
- a SystemVerilog wrapper;
- Python test entry point;
- vector driver and monitor modules;
- register/protocol helpers;
- deterministic waveform ownership.

N-clock and cocotb wrappers use the generated `u_dut` convention. The vectors,
expected values, cycles, and unit-delay value remain shared with SV.

### 7.5 Run one test and the regression

```bash
fx sim --live --set TEST_NAME=smoke
fx cocotb --live --set TEST_NAME=smoke

fx regression --live \
  --set COMPILER=verilator \
  --set 'REGRESSION_BACKENDS=sv cocotb'

fx coverage_detail
```

The regression cleans generated tests and previous regression artifacts,
regenerates the selected harnesses and scenarios, runs every test on every
selected backend, uses deterministic seeds, and merges Verilator coverage.

### 7.6 What functional PASS proves

It proves that selected scenarios produced the declared expected behavior in the
selected RTL simulator backends. It does not prove:

- all legal input sequences;
- absence of an untested corner;
- clock-domain safety;
- synthesis equivalence;
- timing closure;
- physical feasibility.

Coverage shows exercised implementation structures. It does not replace a
requirements-to-test review or formal proof.

### 7.7 Functional failure recovery

Use the smallest reproducible test:

```bash
fx tests
fx test_gen --force --set TEST_NAME=<test>
fx setup_tb setup_cocotb --force
fx sim --live --set TEST_NAME=<test>
fx cocotb --live --set TEST_NAME=<test>
```

Inspect, in order:

1. generated `config.regs`, `data_in.vec`, and `data_out.vec`;
2. first failing vector or protocol transaction;
3. model result and declared latency;
4. reset and configuration state before the event;
5. SV/cocotb scheduling around the event;
6. the RTL stage that first diverges.

If only one backend fails, first verify common vector batching and sampling
semantics. Do not add a backend-specific expected result to make the test pass.

---

## 8. Phase 5 — property formal verification

```bash
fx setup_formal --force
fx formal
```

The formal scaffold creates separate suites for generated CSR semantics and
authored design properties.

### 8.1 Generated CSR properties

```bash
fx formal_csr_bmc
fx formal_csr_prove
fx formal_csr_cover
```

These derive reset values, access behavior, and reachable CSR transactions from
HJSON-generated collateral.

### 8.2 Authored design properties

```bash
fx formal_bmc
fx formal_prove
fx formal_cover
```

Use BMC for short counterexamples, prove for invariants, and cover for
reachability. Appropriate properties include protocol stability, legal state
transitions, mutual exclusion, FIFO safety, overflow policy, and reset
convergence.

### 8.3 Formal assumptions

Assumptions define the legal environment. They must not hide a DUT failure.
Review:

- reset and initial-state assumptions;
- protocol legality assumptions;
- clock behavior;
- memory abstraction;
- unreachable states;
- engine and depth choices.

### 8.4 Formal failure recovery

| Result | Meaning | Action |
| --- | --- | --- |
| counterexample | property is violated under current assumptions | inspect earliest divergence; fix RTL or correct an invalid property |
| cover unreachable | scenario cannot be reached under model/assumptions | review assumptions, reset, and state transition design |
| timeout/unknown | no proof result within resources | simplify cone, strengthen valid invariants, change engine/depth, or partition |
| vacuous PASS | property antecedent never activates | add cover for activation and review environment assumptions |

A formal repair can change the verification contract even if RTL is unchanged;
rerun regression when assumptions or expected legal behavior changes.

---

## 9. Phase 6 — clocks, resets, and SDC

One `ClockConfig` feeds simulation, formal, synthesis, SDC, EQY, STA, and PnR.

Single clock:

```bash
fx settings \
  TOP=my_ip RUN_TOP=my_ip RUN_ID=dev \
  N_CLOCKS=1 \
  CLOCK_DOMAINS=core:clk_i:rst_ni:10:low \
  CLOCK_RELATIONSHIPS=
```

N clocks:

```bash
fx settings \
  TOP=my_ip RUN_TOP=my_ip RUN_ID=dev \
  N_CLOCKS=3 \
  'CLOCK_DOMAINS=cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:6:low' \
  'CLOCK_RELATIONSHIPS=async:cfg:rx,async:cfg:dsp,async:rx:dsp'
```

Generate constraints:

```bash
fx setup_sdc --force
```

The generated SDC creates declared clocks, generated clocks where specified,
and explicit asynchronous groups. A real project may add reviewed input/output
delays, uncertainty, latency, false paths, multicycle paths, case analysis, and
transition/capacitance/fanout policy.

### 9.1 Current CDC/RDC position

FlexSoC carries clock relationships and generates N-clock scaffolds, but the
current target catalogue does not yet expose a dedicated CDC/RDC analysis
command. CDC/RDC remains an explicit architecture and review gate. Do not treat
multi-clock simulation or formal as a substitute for structural crossing
analysis.

### 9.2 Constraint failure recovery

| Symptom | Repair |
| --- | --- |
| clock is not recognized | fix `CLOCK_DOMAINS`, top port names, or SDC generation inputs |
| many unconstrained paths | add missing I/O/path constraints or correct hierarchy; do not call them passing |
| false/multicycle exception fixes timing unexpectedly | prove the architectural reason and scope the exception narrowly |
| simulation and STA use different periods | correct persistent settings and regenerate all clock-derived scaffolds |
| clock relationship changes | regenerate TB, formal, SDC, synthesis, EQY, and sign-off scaffolds; review CDC/RDC |

---

## 10. Phase 7 — synthesis

```bash
fx setup_syn --force
fx syn
```

The synthesis scaffold consumes:

- ordered RTL filelists;
- selected top;
- clock and reset configuration;
- generated SDC;
- selected PDK profile and synthesis Liberty;
- synthesis/optimization strategy.

It produces a mapped netlist under:

```text
syn/<pdk>/<top>_synth.v
```

with logs, statistics, area/cell reports, and generated scripts.

### 10.1 What synthesis PASS proves

It proves that the selected RTL hierarchy can be elaborated and mapped with the
selected technology and strategy. It does not prove that synthesis preserved
behavior; that is the role of equivalence. It also does not prove timing closure
or routability.

### 10.2 Synthesis failure recovery

| Symptom | First checks | Repair |
| --- | --- | --- |
| frontend parse/elaboration failure | filelists, defines, unsupported constructs | repair source or synthesis-specific lowering without changing intended behavior |
| unmapped cell/operator | library availability and synthesis strategy | add correct technology view or rewrite unsupported RTL construct |
| latch/memory unexpectedly inferred | RTL intent | make storage explicit or correct incomplete combinational logic |
| area/cell explosion | arithmetic widths, duplicated logic, missing constraints | inspect statistics and architecture before adding tool-only optimization |
| generated netlist is stale | timestamps/settings/PDK leaf | rerun `setup_syn syn --force` and verify run identity |

After synthesis changes, always rerun equivalence.

---

## 11. Phase 8 — RTL-to-netlist equivalence

```bash
fx setup_eqy --force
fx eqy
```

EQY compares the RTL representation with the mapped netlist. FlexSoC prepares
technology/formal cell views, reset strategy, partitioning, and a configurable
solver strategy.

Diagnostic commands:

```bash
fx eqy_debug
fx eqy_debug <partition>
fx eqy_debug --wave <partition>
fx eqy_debug --files <partition>
```

### 11.1 Result classification

| Result | Interpretation |
| --- | --- |
| proven | partition is equivalent under the configured model |
| failed mismatch | a concrete logical difference was found |
| timeout | solver did not close within the time budget |
| unknown/error | engine or modelling issue prevented a result |

A timeout is not proof of a mismatch. A checkpoint that times out at every
boundary indicates nonclosure, not necessarily a faulty synthesis result.

### 11.2 EQY failure recovery

1. Confirm the RTL and netlist correspond to the same run, PDK, top, and settings.
2. Inspect the first unresolved partition with `eqy_debug`.
3. Distinguish mismatch from timeout/error.
4. Check reset polarity/state, X semantics, memories, black boxes, and cell models.
5. Use partition/strategy/depth/job controls for genuine solver nonclosure.
6. Repair the earliest owned source; do not waive a real output mismatch.

Equivalence complements simulation and formal. A passing regression cannot show
that mapping preserved behavior, and an EQY PASS does not validate test intent.

---

## 12. Phase 9 — SDF, STA, and vectorless power scaffolds

```bash
fx setup_signoff --force
fx sdf
fx sta
fx power_estimate
```

The sign-off generator prepares scripts for the selected PDK and corner set.

### 12.1 SDF

`fx sdf` writes generated corner files under:

```text
signoff/sdf/<pdk>/<top>_ff.sdf
signoff/sdf/<pdk>/<top>_tt.sdf
signoff/sdf/<pdk>/<top>_ss.sdf
```

Corner aliases are resolved by the PDK profile. File presence alone is not
sufficient evidence; GLS qualification checks that the SDF contains real delay
records and that the intended file was requested by the simulator.

### 12.2 Pre-layout STA

`fx sta` reads the mapped netlist, Liberty, SDC, and pre-layout interconnect
assumptions. Review setup and hold separately, recognized clocks, unconstrained
paths, exceptions, and electrical checks where supported.

The current `fx check` report may show no violations while still listing
unconstrained endpoints. Unconstrained paths are missing analysis coverage, not
a timing PASS.

### 12.3 Vectorless power estimate

`fx power_estimate` applies global activity and duty-cycle assumptions:

```text
POWER_ACTIVITY
POWER_DUTY
```

It is useful for architecture comparison and early budget checks. It is not
workload-specific and remains separate from post-GLS activity power in metrics
and `fx check`.

### 12.4 Failure recovery

| Stage | Failure | Repair |
| --- | --- | --- |
| SDF | missing/empty corner | inspect PDK corner mapping, Liberty selection, and generated Tcl/log |
| STA | unconstrained paths | repair SDC and hierarchy before interpreting slack |
| STA | negative setup/hold | review constraints, architecture, pipelining, mapping, and later physical effects |
| Power estimate | implausible number | verify units, Liberty power tables, activity/duty assumptions, clocks, and netlist |

---

## 13. Phase 10 — post-synthesis GLS

GLS executes the same functional tests on the mapped netlist and selected cell
models.

```bash
fx compile_post_syn
fx sim_post_syn \
  --set GLS_BACKEND=sv \
  --set TIMING_MODE=typ \
  --set TEST_NAME=smoke \
  --set SDF_STRICT=1
```

### 13.1 Shared SV/cocotb semantics

Both backends use:

- the same generated vectors;
- atomic same-cycle drive batches;
- the same reset pulse;
- the same clock configuration;
- the same resolved unit delay;
- the same expected values and CSR accesses;
- deterministic waves and machine-readable reports.

Backend-specific scheduling must not change the architectural command stream.
A difference is a harness bug or simulator/model compatibility issue until
proven otherwise.

### 13.2 Timing modes

| Mode | Model | SDF | Purpose |
| --- | --- | --- | --- |
| `zero` | functional cells, zero delay, no specify | no | fastest mapped-netlist and model smoke test |
| `unit` | one uniform representable primitive delay | no | expose races, delta-cycle assumptions, and sampling errors |
| `min` | supported path delays | `ff` | fastest path-delay corner |
| `typ` | supported path delays | `tt` | nominal path-delay corner |
| `max` | supported path delays | `ss` | slowest path-delay corner |

`zero` and `unit` are diagnostic modes. They are not PVT sign-off corners. For
normal timing-oriented work, run `typ` first and then `min/max`. Keep all five
in framework/image qualification because the diagnostic modes isolate model,
netlist, reset, and harness failures faster than SDF runs.

### 13.3 Unit-delay normalization

`GLS_UNIT_DELAY` is a physical request, `1ps` by default. FlexSoC reads the
selected model `timescale` directives, rounds up to the coarsest representable
precision, and passes Icarus a suffix-free numeric delay.

Example:

```text
model timescale       1ns/10ps
requested             1ps
effective             10ps
Icarus define         #0.01
```

The same resolved value is passed to SV and cocotb.

### 13.4 PDK support and the Icarus compatibility view

The original PDK library is never edited. FlexSoC stages a run-local derived
copy under:

```text
dv/functional/sim/post_syn/<pdk>/icarus_timing_models/
```

For IHP, the compile set includes support UDPs such as `sg13g2_udp.v` before the
aggregate standard-cell model. The derived aggregate view may:

- remove timing-check system tasks unsupported by Icarus;
- bind `delayed_*` or `*_delayed` functional inputs;
- initialize notifier state where required;
- remove unsupported edge-sensitive `ifnone` clauses;
- preserve functional equations and supported path arcs;
- inject zero/unit primitive delays only in diagnostic modes.

The model manifest records transformation counts. This makes compatibility
explicit and reproducible.

### 13.5 What Icarus GLS proves

It provides strong evidence for:

- mapped-netlist functionality;
- reset and initialization assumptions;
- cell-model and primitive completeness;
- protocol behavior at gate level;
- shared SV/cocotb test semantics;
- supported SDF path delays in `min/typ/max`;
- representative switching waveforms.

It does **not** dynamically execute the complete foundry-style timing-check
semantics for setup, hold, recovery, removal, width, period, notifier behavior,
and every conditional/interconnect construct. Reports therefore label SDF GLS
as `icarus-path-delay-only`.

Authoritative production timing requires unmodified Liberty/SDC/post-route SPEF
in STA and, where required, a separately qualified simulator that can consume
the original PDK timing models without sanitization.

### 13.6 Strict evidence

With `SDF_STRICT=1`, an SDF run passes only when:

- the selected SDF exists and contains real delay records;
- the testbench logs the `$sdf_annotate` request;
- recognized annotation warnings/errors are absent;
- simulation passes;
- report and waveform are present and non-empty;
- the timing-model manifest matches the expected path-delay classification.

The E2E qualification archives every combination under:

```text
dv/functional/sim/post_syn/<pdk>/e2e_qualification/
├── matrix.json
├── reports/
├── logs/
└── waves/
```

### 13.7 GLS failure recovery

| First failure | Likely area | Action |
| --- | --- | --- |
| unknown primitive/module | PDK model discovery/order | include support primitive/UDP view before aggregate model |
| syntax error in derived model | sanitizer or delay macro | inspect exact staged line and generated compile define |
| zero fails | netlist/model/reset/protocol mismatch | debug zero before SDF |
| unit alone fails | race, atomic drive, sampling, timescale resolution | compare SV/cocotb schedules and resolved unit delay |
| SDF file missing/wrong corner | PDK corner mapping/sign-off generation | inspect SDF path, payload, and corner aliases |
| annotation marker/warning failure | simulator/SDF compatibility | inspect strict log; do not disable strict mode for release |
| SV and cocotb disagree | harness semantics | compare vectors, batching, clock/reset, and sampling phase |
| waveform/report missing | archival/command failure | inspect command log and machine-readable stage report |

Use `fx check` to identify the exact failed matrix stem and archived evidence.

---

## 14. Phase 11 — activity-based power from GLS

`power_estimate` uses a global assumption. `power_analysis` uses activity from a
qualified SDF-backed GLS test.

```bash
fx power_analysis \
  --set POWER_TEST_NAME=smoke \
  --set POWER_GLS_BACKEND=sv \
  --set POWER_TIMING_MODE=typ

fx power_analysis_all \
  --set POWER_TEST_NAMES=all \
  --set POWER_GLS_BACKEND=sv \
  --set POWER_TIMING_MODE=typ
```

### 14.1 Accepted activity sources

Only `min`, `typ`, and `max` GLS reports are accepted because they prove that
back-annotation was requested. `zero` and `unit` are intentionally rejected as
technology power references.

The default E2E analysis uses one SV `typ` trace per test. Running the same
vectors again through cocotb would normally duplicate the same logical workload.
Explicit backend/mode matrices remain available for investigations.

### 14.2 FST to VCD

OpenSTA imports VCD/SAIF, while simulations normally retain compact FST. When the
qualified wave is FST, FlexSoC automatically runs:

```text
fst2vcd -f <input.fst> -o <output.vcd>
```

It validates the resulting VCD and retains a conversion log. A stdout fallback
supports older wrappers.

`fst2vcd` is therefore a required simulation/debug tool and is included with the
pinned GTKWave toolchain/image.

### 14.3 VCD hierarchy resolution

OpenSTA uses `/` as the hierarchy separator. `POWER_VCD_SCOPE=auto` inspects the
VCD and recognizes generated DUT conventions:

```text
single-clock SV        test_tb/u_<TOP>
N-clock/cocotb wrapper test_tb/u_dut
```

For `TOP=test`, the single-clock scope is `test_tb/u_test`. An explicit dotted
path is normalized only after validation. The run fails before OpenSTA when no
DUT scope can be resolved.

### 14.4 OpenSTA analysis

For each selected test and Liberty corner, the generated Tcl:

1. reads the Liberty and mapped netlist;
2. links the design and reads constraints;
3. reads the scoped VCD;
4. reports activity annotation;
5. reports internal, switching, leakage, and total power.

If OpenSTA explicitly reports zero annotated activities, the analysis fails even
when `report_power` returns numeric values. This prevents default-activity
numbers from being mislabeled as workload-based results.

Outputs are stored under:

```text
signoff/power/<pdk>/activity/
├── captures/                     converted VCD and converter logs
├── scripts/                      OpenSTA Tcl per test/corner
├── reports/                      JSON per test
└── summary.json
```

### 14.5 What activity power proves

It is a stronger post-synthesis workload reference than vectorless estimation.
It compares the same captured switching behavior against each configured
Liberty corner.

It is not final silicon power sign-off because it does not yet include the final
clock tree, post-route glitch behavior, extracted interconnect capacitance,
representative system workloads, voltage-drop effects, or rail analysis.

### 14.6 Power failure recovery

| Failure | Repair |
| --- | --- |
| `fst2vcd` fails | inspect converter invocation/log and input wave validity |
| VCD scope cannot be resolved | inspect VCD `$scope` hierarchy and generated DUT instance convention |
| annotated activity is zero | correct scope/name mapping; do not accept returned default power numbers |
| OpenSTA link/read error | inspect netlist, Liberty, top, and cell mapping |
| one corner differs implausibly | verify Liberty units/tables and corner selection |
| all tests show identical power unexpectedly | verify vectors contain distinct activity and VCD time windows are complete |

---

## 15. Phase 12 — metrics, closure, and release

```bash
fx manifest
fx metrics
fx check
```

### 15.1 Manifest

`manifest.json` records run identity, Git state, FlexSoC/Python/platform data,
lock hashes, tool versions, PDK, and artifact paths. It answers: **what produced
this run?**

### 15.2 Metrics

`metrics.json` collects structured evidence from lint, regression, coverage,
formal, synthesis, equivalence, SDF, STA, vectorless power, GLS qualification,
and activity power. It answers: **what did the run achieve?**

### 15.3 Check

`fx check` refreshes metrics and renders the human-readable closure summary. It
keeps evidence classes separate:

```text
power            vectorless estimate
post_syn_gls     functional/path-delay matrix
power_activity   qualified post-GLS activity analysis
```

A standard closure PASS still does not imply final production physical sign-off.
Review warnings, unconstrained timing paths, coverage, waivers, and current flow
limitations in addition to the summary word.

### 15.4 Save reusable IP

```bash
fx ip_save --set IP_NAME=<name>
```

Save authored sources and reusable collateral, not transient run outputs. A SoC
integration must establish its own address map, clocks/resets, DV, constraints,
and sign-off assumptions.

---

## 16. Change-impact recipes

### 16.1 CSR-only change

```bash
fx reg doc regmap_py --force
fx top_from_core flist --force
fx tests_gen --force
fx lint_suite regression formal
fx syn eqy --force
fx sdf sta power_estimate --force
```

Rerun representative GLS and activity power when the CSR affects runtime
configuration or switching.

### 16.2 RTL behavior or latency change

```bash
fx flist lint_suite --force
fx tests_gen regression --force
fx formal
fx syn eqy --force
fx sdf sta power_estimate --force
```

Then qualify GLS. Start with `zero`, use `unit` if timing-ordering assumptions
are suspect, and run `typ,min,max` for SDF evidence.

### 16.3 Port change

```bash
fx top_from_core flist setup_tb setup_cocotb --force
fx lint_suite regression formal
fx syn eqy sdf sta power_estimate --force
```

### 16.4 Clock/reset change

```bash
fx settings N_CLOCKS=<n> CLOCK_DOMAINS=<domains> CLOCK_RELATIONSHIPS=<relations>
fx setup_tb setup_cocotb setup_formal setup_sdc setup_syn setup_eqy setup_signoff --force
fx flist lint_suite regression formal
fx syn eqy sdf sta power_estimate --force
```

Review CDC/RDC and rerun the full GLS matrix because reset and sampling behavior
changed.

### 16.5 Test/model change

```bash
fx tests_gen --force
fx setup_tb setup_cocotb --force
fx regression
```

If the new test is intended for GLS/power qualification, rerun the selected GLS
modes and `power_analysis_all` so the archived matrix and workload summary stay
complete.

### 16.6 Constraint-only change

```bash
fx setup_sdc setup_syn setup_eqy setup_signoff --force
fx syn eqy sdf sta power_estimate --force
```

A timing exception is an architectural change to the analysis contract and must
be reviewed even when RTL is untouched.

---

## 17. Complete single-clock qualification example

```bash
PDK_NAME=ihp-sg13g2
PDK_ROOT="$HOME/github/flexsoc/.flexsoc/pdks/$PDK_NAME"
E2E_ROOT="$HOME/github/flexsoc/workspace/e2e-$PDK_NAME-single-full"

fx pdk use "$PDK_NAME"

fx settings \
  TOP=test RUN_TOP=test RUN_ID=dev HOST=uart \
  PDK="$PDK_NAME" PDK_ROOT="$PDK_ROOT" \
  N_CLOCKS=1 \
  CLOCK_DOMAINS=core:clk_i:rst_ni:10:low \
  CLOCK_RELATIONSHIPS= \
  GLS_UNIT_DELAY=1ps \
  FST2VCD=fst2vcd \
  POWER_VCD_SCOPE=auto \
  POWER_DUT_INSTANCE=auto

FLEXSOC_E2E_LIVE=0 \
FLEXSOC_E2E_KEEP=1 \
FLEXSOC_E2E_PDKS="$PDK_NAME" \
pytest -s -vv \
  tests/test_e2e_fx.py::test_fx_single_clock_flow_debug \
  --e2e-root "$E2E_ROOT" \
  --e2e-pdks "$PDK_NAME" \
  --e2e-gls-tests all
```

For six generated tests, two backends, and five modes, the GLS matrix contains
60 combinations. The default activity analysis then uses the six qualified SV
`typ` waves, one per test.

---

## 18. Production-grade evidence hierarchy

The current framework can provide reproducible logical verification,
post-synthesis path-delay GLS, and activity-based power references. A true
production-grade silicon sign-off requires a broader authority chain:

1. requirements and reviewed architecture;
2. lint, dual-backend functional regression, coverage, and property formal;
3. reviewed CDC/RDC analysis for every clock/reset crossing;
4. technology mapping and complete RTL-to-netlist equivalence;
5. post-synthesis GLS for functional/path-delay compatibility;
6. post-route netlist, unmodified Liberty, complete SDC, and extracted SPEF;
7. MCMM setup/hold and recovery/removal timing closure;
8. original-model dynamic timing qualification when required;
9. post-route workload power with clock-tree/glitch/parasitic activity;
10. DRC, LVS, antenna, extraction completeness, IR drop, and EM;
11. correlation against the selected PDK/foundry reference flow;
12. immutable tools, PDK revision, settings, waivers, reports, and release manifest.

The Icarus-derived view is an explicit compatibility artifact at step 5. It is
not the timing authority for steps 6–10. Production-grade operation depends on
retaining that distinction rather than labelling every PASS as equivalent.

---

## 19. Practical troubleshooting rule

When a stage fails:

1. identify the earliest failing gate;
2. read the command log and generated script;
3. inspect the exact input artifact consumed by that stage;
4. classify the result as design mismatch, missing assumption, stale generated
   boundary, tool/model compatibility, timeout/nonclosure, or archival failure;
5. repair the authored source or generator that owns the defect;
6. regenerate only the dependent boundary;
7. rerun the smallest reproducer;
8. rerun every downstream quality gate whose assumptions changed;
9. refresh `manifest`, `metrics`, and `check` before release.

This discipline is the central purpose of FlexSoC: not to make failures
disappear, but to make their ownership, evidence, and repair path explicit.


## Equivalence protocol-view discipline

For TL-UL responses, the formal wrapper keeps raw packed outputs internal and exposes only canonical witnesses. The default PDR engine is `abc pdr`; engine failures without traces are not design mismatches.
