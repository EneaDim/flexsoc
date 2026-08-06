# 🔄 FlexSoC project lifecycle

This document is the canonical engineering guide for developing, verifying,
implementing, signing off, reusing, and releasing a digital ASIC IP or small SoC
with FlexSoC.

It combines the design theory with the practical `fx` workflow. The aim is not
to prescribe one microarchitecture; it is to make every source of truth,
derived artifact, quality gate, and handoff explicit enough for production use.
The exhaustive syntax and lifecycle role of every command is maintained in the
[FlexSoC command reference](command_reference.md). The generated scaffold
architecture, file ownership, and stage-by-stage implementation reasoning are
documented in [IP development guide](ip_development_guide.md).

> **Core rule:** edit the design intent, regenerate the smallest derived
> boundary, and rerun every gate whose assumptions changed.

---

## 1. Final goal

The output of the flow is not merely synthesizable RTL. A qualified release
needs evidence that:

- the implemented behavior matches the IP requirements;
- configuration and status are represented consistently in hardware and software-visible metadata;
- the reachable RTL hierarchy is structurally sound;
- planned scenarios pass in simulation;
- important invariants hold formally;
- clock and reset crossings are intentionally designed and reviewed;
- synthesis preserves the RTL behavior;
- timing and power constraints are explicit;
- physical implementation is feasible;
- final netlist, timing parasitics, and release collateral are traceable to one configuration.

FlexSoC organizes that evidence under a reproducible run identity:

```text
WORKSPACE / RUN_TOP / RUN_ID / PDK
```

---

## 2. Complete ASIC flow

```text
1. Requirements and architecture
   ├── functions and operating modes
   ├── interfaces and protocols
   ├── configuration and observable status
   ├── clock/reset domains
   ├── performance, area, power, and test requirements
   └── verification and acceptance criteria

2. IP design entry
   ├── CSR / register map specification
   ├── generated register RTL and documentation
   ├── RTL core and top-level interfaces
   ├── reset behavior and state transitions
   └── ordered elaborated RTL hierarchy

3. Design verification
   ├── functional DV: model, scenarios, shared vectors, SV/cocotb simulation
   ├── regression: per-test logs, deterministic waveforms, coverage review
   ├── property formal: BMC, unbounded proof, cover
   └── CDC/RDC structural closure for multi-domain designs

4. Pre-implementation definition
   ├── clocks and relationships
   ├── I/O and path constraints
   ├── synthesis intent
   └── PDK/corner selection

5. Synthesis and post-synthesis sign-off
   ├── mapped netlist
   ├── RTL ↔ netlist equivalence
   ├── post-synthesis GLS on the same functional tests
   ├── zero/unit-delay and SDF min/typ/max modes
   ├── pre-layout STA
   └── power estimate

6. Physical implementation
   ├── floorplan
   ├── placement
   ├── clock-tree synthesis
   ├── routing
   └── extraction

7. Post-layout sign-off
   ├── final-netlist timing with SPEF
   ├── post-layout SDF and optional GLS
   ├── power with realistic activity when available
   ├── physical verification and reliability checks
   └── release qualification
```

These stages are iterative. A timing failure can change the RTL. A formal
counterexample can change the architecture. A new CSR can change software,
verification, and synthesis. The lifecycle is therefore a dependency graph, not
a one-way script.

---

## 3. Sources of truth and ownership

A production flow remains maintainable only when each fact has one owner.

| Design fact | Source of truth | Derived collateral |
| --- | --- | --- |
| IP behavior and modes | requirements + authored RTL/model/properties | tests, reports, implementation |
| CSR addresses and fields | HJSON | register RTL, docs, Python regmap, CSR formal |
| Hardware interfaces | RTL core ports | generated top wrapper, TB connections, filelists |
| Clock/reset intent | `N_CLOCKS`, `CLOCK_DOMAINS`, `CLOCK_RELATIONSHIPS` | TB timing, SDC, formal and sign-off configuration |
| Expected functional behavior | authored model + scenarios | vectors consumed by simulators |
| Timing intent | SDC inputs and clock configuration | synthesis, STA, PnR, SDF |
| Technology mapping | PDK profile and synthesis settings | mapped netlist and timing reports |
| Physical implementation | OpenROAD configuration + implementation inputs | final netlist, DEF/GDS collateral, SPEF |

### Authored collateral

Normally preserved across regeneration:

```text
requirements / architecture documents
RTL core and custom RTL
behavioral/reference model
scenario catalogue
hand-authored assertions and covers
custom constraints and integration policy
software and integration code
```

### Generated collateral

Regenerated from an explicit source:

```text
register RTL and register documentation
Python CSR/regmap API
starter RTL wrapper
ordered Slang filelists
test vectors
testbench scaffolds
formal configurations
SDC, synthesis, EQY, STA, SDF, power, and PnR scripts
metrics and manifests
```

`--force` is appropriate for generated files. It must not become a habit that
overwrites authored model, tests, or RTL without review.

---

## 4. Define the IP before writing RTL

Each IP should begin with a concise specification. The exact document format can
be introduced per IP later, but the engineering content should already be
explicit.

### 4.1 Functional definition

State what the IP does and what it does not do:

- accepted inputs and produced outputs;
- supported modes and mode transitions;
- data widths, signedness, saturation, overflow, and rounding;
- throughput, latency, back-pressure, and ordering;
- invalid-input and error behavior;
- reset values and recovery behavior.

A useful requirement is observable and testable. “Process samples quickly” is
not sufficient; “accept one sample per cycle when `ready` is asserted and
produce the corresponding result after four DSP-domain cycles” is.

### 4.2 Configuration and state

Separate software-controlled configuration from hardware-observed state.

```text
configuration CSR
    software → hardware
    selects operating policy or parameters

status CSR
    hardware → software
    reports current state, events, counters, or faults

command / event CSR
    triggers an action or acknowledges a sticky condition
```

For every field define:

- reset value;
- access policy;
- legal values;
- side effects;
- update clock domain;
- whether synchronization is required;
- how verification observes the result.

### 4.3 CSR and RegMap

HJSON is the software-visible register source of truth. A typical flow is:

```bash
fx hjson --force
# edit data/<top>.hjson or data/<top>_<window>.hjson
fx reg doc --force
fx regmap_py --force
```

Generated register collateral includes:

- register RTL;
- Markdown register documentation;
- Python register and field objects;
- automatic CSR semantic properties.

Do not manually duplicate offsets, masks, or field positions in the model or
tests. Import them from the generated regmap API.

For multiple register windows, use stable names that align with the owning clock
domain where appropriate:

```text
<top>_cfg.hjson  ↔ cfg_reg2hw_i / cfg_hw2reg_o ↔ cfg clock domain
<top>_dsp.hjson  ↔ dsp_reg2hw_i / dsp_hw2reg_o ↔ dsp clock domain
```

> **When CSR development goes wrong:** inspect the HJSON first. Regenerate
> `reg`, `doc`, and `regmap_py`; do not patch generated register RTL, Markdown,
> or Python offsets independently. If a new field/window changes ports or
> ownership, refresh `top_from_core`, `flist`, tests, and CSR formal before
> continuing.

### 4.4 RTL core and top wrapper

The RTL core owns the hardware behavior. The generated top wrapper owns
mechanical integration such as generated register blocks.

```bash
fx rtl_stub --force          # bootstrap only
# edit rtl/<top>_core.sv
fx top_from_core --force     # refresh generated wrapper after port changes
fx flist --force
```

The core should make these aspects obvious:

- which domain owns each sequential process;
- reset polarity and reset state;
- combinational versus registered outputs;
- protocol handshake semantics;
- CDC primitives or queues at domain boundaries;
- assertions close to delicate control logic.

---

> **When RTL entry goes wrong:** use `slang_hier`, the ordered filelists, and
> `lint_suite` to decide whether the defect is authored RTL or a stale generated
> wrapper. Repair the core for behavioral/structural defects; regenerate
> `top_from_core` and `flist` for mechanical drift. Port changes also invalidate
> both simulation harnesses.

## 5. Configure one or many clock domains

FlexSoC uses one clock model for all backends.

### 5.1 Single-clock example

```bash
fx settings \
  TOP=my_ip RUN_TOP=my_ip RUN_ID=dev HOST=uart \
  N_CLOCKS=1 \
  CLOCK_DOMAINS=core:clk_i:rst_ni:10:low \
  CLOCK_RELATIONSHIPS=
```

### 5.2 N-clock example

```bash
fx settings \
  TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart \
  N_CLOCKS=3 \
  'CLOCK_DOMAINS=cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:6:low' \
  'CLOCK_RELATIONSHIPS=async:cfg:rx,async:cfg:dsp,async:rx:dsp'
```

Domain encoding:

```text
name:clock_signal:reset_signal:period_ns:reset_polarity
```

Relationship encoding:

```text
async:source:target
sync:source:target
generated:source:target:divide_by
```

Relationships are explicit. Absence of a relationship does not mean that two
clocks should automatically be treated as asynchronous.

The same configuration drives:

- generated testbench clocks and resets;
- formal multi-clock mode;
- synthesis clock selection;
- SDC clock creation and clock grouping;
- STA and PnR inputs;
- EQY strategy selection.

---

## 6. Bootstrap the run

Create the logical run and the initial generated collateral:

```bash
fx setup --force
fx hjson --force
fx reg doc --force
fx rtl_stub --force
fx top_from_core --force
fx flist --force
fx lint_suite
```

For a complete starter workspace:

```bash
fx ip_start --force
```

Treat `ip_start` as a bootstrap convenience. Once the model, tests, RTL, and
properties contain authored work, prefer selective regeneration.

### Elaboration and filelists

`fx flist` uses Slang to elaborate downward from the selected top and emits:

```text
rtl_common.f   shared packages, primitives, and protocol infrastructure
rtl_ip.f       reachable run/IP hierarchy
```

These ordered command files are consumed by lint, simulation, formal,
synthesis, and equivalence. A stale filelist can invalidate every downstream
gate, so regenerate it after hierarchy, package, include-path, or port changes.

---

## 7. Design verification plan

Verification should be planned from the requirements, not added after RTL is
complete.

For each requirement identify at least one of:

- directed functional scenario;
- constrained-random or parameterized scenario;
- assertion/invariant;
- cover objective;
- CDC/RDC structural rule;
- implementation or timing check.

The main evidence classes are different:

```text
functional simulation  proves selected scenarios behave as expected
code coverage           shows which implementation structures were exercised
property formal         proves or explores declared RTL properties
CDC/RDC analysis        checks clock/reset crossing structure and assumptions
equivalence             proves synthesis preserved the RTL representation
STA                      proves timing against declared constraints
physical sign-off       checks the implemented layout and extracted design
```

No single percentage replaces the others.

---

## 8. Functional design verification

### 8.1 Model and CSR API

Bootstrap the functional workspace once:

```bash
fx setup_model --force
```

Ownership:

```text
dv/functional/model/<top>_model.py   authored expected behavior
dv/functional/model/<top>_regmap.py  generated CSR API
dv/functional/model/<top>_tests.py   authored scenarios and vector policy
```

After customization, an HJSON-only change should normally use:

```bash
fx reg doc --force
fx regmap_py --force
```

rather than recreating the complete model workspace.

### 8.2 Scenario and vector generation

Generate every declared scenario or one selected scenario:

```bash
fx tests_gen --force
fx test_gen --force --set TEST_NAME=smoke
fx tests
```

Each scenario is materialized as simulator-independent data:

```text
dv/functional/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

`config.regs` describes initial CSR configuration. `data_in.vec` contains timed
pin activity, CSR writes, resets, and other commands. `data_out.vec` contains
expected pin values and CSR reads. SystemVerilog, cocotb, post-synthesis GLS,
and post-PnR GLS consume the same files; a backend-specific expectation does
not belong in the vector set.

A scenario should express architectural events and declared latency. Avoid
using zero-delay behavior as an implicit specification. In particular, tests
that inspect live status after protocol activity should return the interface to
an idle state, reset or drain transient state when required, and wait long
enough for the configured protocol timing.

### 8.3 Generate and run the RTL simulation environments

Generate both drivers after changing ports, clocks, resets, vector syntax, or
register interfaces:

```bash
fx setup_tb setup_cocotb
```

Run one named test with the SystemVerilog driver:

```bash
WORKDIR="$HOME/flexsoc-workspace"
TOP=my_ip
RUN_TOP=my_ip
RUN_ID=dev
RUN="$WORKDIR/runs/$RUN_TOP/$RUN_ID"
WAVE="$RUN/dv/functional/sim/rtl/${TOP}_tb_sv_smoke.fst"

fx sim --live \
  --workdir "$WORKDIR" \
  --set COMPILER=verilator \
  --set TEST_NAME=smoke \
  --set WAVE_FILE="$WAVE"
```

Run the same vectors with cocotb:

```bash
WAVE="$RUN/dv/functional/sim/rtl/${TOP}_tb_cocotb_smoke.fst"

fx cocotb --live \
  --workdir "$WORKDIR" \
  --set COMPILER=verilator \
  --set TEST_NAME=smoke \
  --set COCOTB_WAVES=1 \
  --set WAVE_FILE="$WAVE"
```

Run all generated tests on one backend:

```bash
fx sim_tests --live
fx cocotb_tests --live
```

A single-test run is the fastest debug loop because it preserves a stable test
name, log, seed, and waveform. Use it before rerunning the full regression.

### 8.4 Regression semantics

The normal dual-backend gate is:

```bash
fx regression --live \
  --set COMPILER=verilator \
  --set 'REGRESSION_BACKENDS=sv cocotb'

fx coverage_detail
```

`fx regression` consumes the prepared vector catalogue without recreating it. Driver preparation is always explicit: run `setup_tb` and `setup_cocotb` before regression when machine-owned reset/vector support must be refreshed. The regression target itself:

1. requires an existing vector-test directory and SystemVerilog testbench;
2. requires an existing cocotb scaffold when that backend is selected;
3. removes only previous coverage data and regression logs;
4. runs every existing test on every selected backend;
5. assigns `random_seed_<n>` tests seed `<n>` and uses `SEED` for the others;
6. collects and merges coverage when `COMPILER=verilator`.

Run `fx tests_gen` explicitly when the editable vector catalogue must be recreated. After `fx ip_load`, use the literal sequence `regmap_py`, `tests_gen`, `setup_tb`, `setup_cocotb`, then `regression --no-setup`. The model scenarios remain authored, while both testbench trees are recreated completely from the current source of truth. This removes stale saved-IP files, refreshes the shared vector/reset grammar, and rebases cocotb RTL sources to the loaded workspace. No `--force` is required.

The default backend set is `sv cocotb`. Restrict it only for diagnosis:

```bash
fx regression --live --set 'REGRESSION_BACKENDS=sv'
fx regression --live --set 'REGRESSION_BACKENDS=cocotb'
```

A backend-only PASS is useful evidence, but release qualification should return
to the configured full backend set. When `COMPILER` is not Verilator, the tests
still run but the Verilator coverage stage is skipped explicitly.

The default regression waveform name is deterministic:

```text
dv/functional/sim/rtl/<testbench>_<backend>_<test>.<fst|vcd>
```

Regression logs are separated by backend:

```text
logs/dv/functional/regression/sv/
logs/dv/functional/regression/cocotb/
```

### 8.5 Inspect one waveform from a regression

`fx view` is a convenience command for a waveform in the default RTL simulation
directory. For a particular regression test, select the exact file rather than
relying on viewer discovery:

```bash
RUN="$WORKDIR/runs/$RUN_TOP/$RUN_ID"

find "$RUN/dv/functional/sim/rtl" \
  -maxdepth 1 -type f \( -name '*.fst' -o -name '*.vcd' \) \
  -printf '%f\n' | sort

WAVE="$RUN/dv/functional/sim/rtl/${TOP}_tb_sv_smoke.fst"
test -s "$WAVE"
gtkwave "$WAVE" &
```

Use Surfer instead when configured:

```bash
surfer "$WAVE" &
```

For side-by-side driver comparison, open one viewer process per waveform:

```bash
gtkwave "$RUN/dv/functional/sim/rtl/${TOP}_tb_sv_smoke.fst" &
gtkwave "$RUN/dv/functional/sim/rtl/${TOP}_tb_cocotb_smoke.fst" &
```

The top-level clock, reset, pins, and protocol buses are the most stable debug
signals. Internal synthesized or generated names may change after regeneration.
A waveform is evidence only when paired with the exact test vectors, backend,
seed, log, and run settings that produced it.

### 8.6 Coverage and exit criteria

Code coverage is a review tool, not an automatic quality certificate. Inspect:

- line and branch coverage;
- expression and toggle coverage;
- FSM coverage;
- user-defined functional cover points;
- exclusions and unreachable logic.

A production gate should combine coverage thresholds with scenario review,
requirements traceability, assertions, and bug history. Coverage should be
collected from representative tests; adding tests only to increase a percentage
without exercising a requirement does not improve verification quality.

### 8.7 Functional debug order

> **When functional DV goes wrong:** reduce to one named test and keep the
> expectation backend-neutral. Compare vectors, model result, declared latency,
> reset/configuration, and the first differing waveform event before rerunning
> the complete regression. A failure on only SV or only cocotb normally points
> to harness scheduling or sampling, not an alternate legal output.

Use the smallest reproducible boundary:

```bash
fx tests
fx test_gen --force --set TEST_NAME=<test>
fx setup_tb setup_cocotb
fx sim --live --set TEST_NAME=<test>
fx cocotb --live --set TEST_NAME=<test>
```

Then compare:

1. the generated `config.regs`, `data_in.vec`, and `data_out.vec`;
2. the first differing command or expected event;
3. the first `X/Z`, timeout, or protocol error in each log;
4. the exact waveform around that event;
5. the authored model and RTL behavior that own the expectation.

Only after the named test is understood should the full regression and coverage
be rerun.

## 9. Property formal verification

Property formal operates on the RTL and is PDK-independent. It is separate from
RTL-to-netlist equivalence.

### 9.1 Automatic CSR semantics

FlexSoC generates checks for register behavior derived from HJSON:

```bash
fx formal_csr_bmc
fx formal_csr_prove
fx formal_csr_cover
```

The aggregate target is:

```bash
fx formal_csr
```

Typical properties cover reset values, access policy, field behavior, and
reachable CSR transactions.

### 9.2 Authored design properties

Design-specific assertions and covers belong with the IP:

```bash
fx formal_bmc
fx formal_prove
fx formal_cover
```

The complete property-formal flow is:

```bash
fx formal
```

Use:

- **BMC** to find short counterexamples quickly;
- **prove** for invariants over unbounded execution;
- **cover** to check that important states and sequences are reachable.

Good formal candidates include protocol invariants, FIFO safety, mutual
exclusion, legal state transitions, overflow policy, and reset convergence.

### 9.3 Formal modelling discipline

Formal assumptions are part of the verification contract. They must describe
legal environment behavior without hiding design bugs. Review:

- clock/reset assumptions;
- protocol input assumptions;
- initial state modelling;
- memory abstraction or lowering;
- unreachable-state assumptions;
- proof depth and engine selection.

---

> **When formal goes wrong:** classify counterexample, unreachable cover,
> timeout, and vacuous PASS separately. Repair RTL/property intent for a real
> trace; change engine, depth, partitioning, or invariants for genuine
> nonclosure. Assumptions are reviewed verification contracts, not a mechanism
> for hiding illegal DUT behavior.

## 10. CDC and RDC closure

A multi-clock simulation or proof does not replace structural CDC/RDC analysis.

For every crossing classify the mechanism:

```text
single-bit level       synchronizer
single-cycle pulse     pulse/toggle synchronizer or handshake
multi-bit control      encoded handshake with stability guarantee
stream/data payload    asynchronous FIFO or explicit bridge
reset crossing         synchronized release and domain-specific reset policy
```

The design review should verify:

- source and destination domains;
- data-coherency assumptions;
- synchronizer depth;
- FIFO pointer encoding and reset behavior;
- reconvergence hazards;
- reset assertion/deassertion policy;
- exceptions and waived paths.

FlexSoC already carries clock relationships through `ClockConfig`. Dedicated
CDC/RDC tool execution is an explicit planned quality gate and should be added
without merging its results into functional coverage or EQY closure.

---

## 11. Constraints and pre-synthesis checks

Timing constraints express the design contract seen by synthesis, STA, and PnR.
They should be reviewed before synthesis, not created after timing fails.

```bash
fx setup_sdc --force
```

The generated SDC contains declared clocks, generated clocks, and explicit
asynchronous groups. A complete project may additionally require authored:

- input and output delays;
- false paths;
- multicycle paths;
- clock uncertainty and latency;
- case analysis;
- maximum transition, capacitance, or fanout policy.

Constraints are assumptions. An unconstrained path is not a passing path.
Exceptions must have an architectural reason and a review owner.

Before synthesis run:

```bash
fx flist --force
fx lint_suite
fx regression
fx formal
fx setup_sdc --force
```

---

> **When constraints go wrong:** missing clocks and unconstrained endpoints are
> incomplete analysis, not passing timing. Correct the persistent clock model
> and SDC source, regenerate every clock-derived scaffold, and review CDC/RDC
> whenever domain relationships change. Keep exceptions narrow and owned.

## 12. Synthesis

Synthesis transforms the RTL hierarchy into a technology-mapped logical
implementation.

```bash
fx setup_syn --force
fx syn --force
```

Inputs include:

- ordered RTL filelists;
- selected top;
- clock target from `ClockConfig`;
- selected PDK and Liberty data;
- synthesis and optimization strategy;
- constraints and cell models.

Review more than command success:

- inferred latches and memories;
- unmapped or black-box cells;
- clock-gating treatment;
- reset mapping;
- warnings and removed logic;
- area and cell distribution;
- critical-path estimates;
- whether hierarchy and debug visibility remain appropriate.

> **When synthesis goes wrong:** inspect the ordered hierarchy, generated script,
> selected Liberty, inferred storage, and mapping statistics. Repair authored
> RTL or synthesis intent rather than editing the mapped netlist. Every changed
> synthesis result must return through RTL-to-netlist equivalence.

### DFT insertion point

DFT normally enters near the end of synthesis or between synthesis and physical
implementation. A production flow may add:

- scan replacement and scan-chain stitching;
- test-mode controls;
- memory BIST;
- boundary scan;
- ATPG constraints and coverage.

DFT changes the netlist and therefore requires its own equivalence policy,
timing constraints, test-mode verification, and implementation handoff. FlexSoC
currently identifies this integration point but does not claim a complete DFT
flow.

---

## 13. Post-synthesis sign-off

### 13.1 RTL-to-netlist equivalence

After synthesis, prove that the mapped netlist preserves the RTL behavior:

```bash
fx setup_eqy --force
fx eqy --force
```

EQY compares common formal views of RTL and gate representations. It is not a
functional test and it is not code coverage.

FlexSoC applies a strategy portfolio:

```text
single-clock default: SAT → SMTBMC → PDR
N-clock default:      PDR → SMTBMC
```

- **SAT** is economical for small single-clock partitions and induction-friendly logic.
- **SMTBMC** is useful for bit-vector arithmetic, bounded exploration, induction, and detailed traces.
- **PDR/IC3** is an unbounded state-space proof and often performs best on sequential invariants, FIFOs, and multi-clock cones.

Strategies are attempted only for unresolved partitions. Override when the
design evidence supports another order:

```bash
fx eqy --force --set EQY_STRATEGY_ORDER=pdr,smt
fx eqy --force --set EQY_STRATEGY_ORDER=sat,smt,pdr
```

Parallelism and time limits are explicit:

```bash
fx eqy --force \
  --set EQY_JOBS=8 \
  --set EQY_QUICK_TIMEOUT=5 \
  --set EQY_TIMEOUT=60
```

All top-level vector outputs are collected as buses rather than proving each bit
as an unrelated partition. This keeps related cone logic together and avoids
repeating the same proof work.

Interpret outcomes carefully:

| Result | Meaning |
| --- | --- |
| `PASS` | all required partitions were proven |
| `FAIL` | at least one partition has a demonstrated mismatch or unresolved required proof |
| `UNKNOWN` | the selected strategy did not conclude |
| `TIMEOUT` | resource limit reached without a conclusion |
| `ERROR` | setup, modelling, engine, or tool failure |

Debug with:

```bash
fx eqy_debug
fx eqy_debug <partition>
fx eqy_debug --wave <partition>
fx eqy_debug --files <partition>
```

A solver timeout is not proof of inequivalence. A counterexample with a concrete
first divergence is.

> **When equivalence goes wrong:** use `eqy_debug` to distinguish a concrete
> mismatch from TIMEOUT, UNKNOWN, or engine error. A timeout is inconclusive; a
> mismatch belongs to RTL/netlist/reset/X/cell-model ownership. Do not trade one
> classification for another merely to obtain a green aggregate status.

### 13.2 SDF and gate-level simulation

SDF and STA are sibling consumers of the timing model; STA does not require SDF.
SDF is used to annotate delays into a gate-level simulation of the mapped
netlist. GLS reuses the functional vector tests so that RTL and gate behavior
are compared against the same scenario intent.

Prepare the artifacts:

```bash
fx setup_tb setup_cocotb
fx syn --force
fx sdf --force
```

The post-synthesis simulator supports two drivers and five timing modes:

| Setting | Meaning | SDF used | Expected timing model |
| --- | --- | --- | --- |
| `GLS_BACKEND=sv` | generated SystemVerilog driver | mode-dependent | Icarus |
| `GLS_BACKEND=cocotb` | generated Python/cocotb driver | mode-dependent | Icarus |
| `TIMING_MODE=zero` | functional cells with `#0` delay and no `specify` | no | `functional-zero-delay` |
| `TIMING_MODE=unit` | functional cells with uniform requested `GLS_UNIT_DELAY` (`1ps` by default), normalized to model precision | no | `functional-unit-delay` |
| `TIMING_MODE=min` | fastest generated SDF corner | `<top>_ff.sdf` | `icarus-path-delay-only` |
| `TIMING_MODE=typ` | nominal generated SDF corner | `<top>_tt.sdf` | `icarus-path-delay-only` |
| `TIMING_MODE=max` | slowest generated SDF corner | `<top>_ss.sdf` | `icarus-path-delay-only` |

`zero` and `unit` are useful gate-netlist checks, but they are not
back-annotation. `zero` provides the quickest proof that the mapped netlist,
cell models, reset, protocol drivers, and vector expectations still agree.
`unit` deliberately adds one uniform representable primitive delay and is most
valuable for finding race, ordering, and sampling assumptions shared by the SV
and cocotb backends. These modes are diagnostic qualification modes, not PVT
corners. For normal timing-oriented work use `typ` first and then `min`/`max`,
which correspond to the generated `tt`, `ff`, and `ss` SDF views. A full GLS qualification sweep keeps all five modes because a failure in `zero` or `unit` is usually
faster to diagnose than the same issue hidden inside an SDF run.

The default requested unit delay is `1ps`. FlexSoC reads the selected model
`timescale` directives, rounds the request up to their coarsest representable
precision, and passes Icarus a suffix-free numeric delay. For example, an IHP
model declared as `1ns/10ps` receives `#0.01`, while a `1ns/1ps` model receives
`#0.001`. SV and cocotb use the same resolved value. This exposes ordering and
race problems without inventing a nanosecond-per-cell critical path;
`GLS_UNIT_DELAY` remains explicit and overrideable. Back-annotation
is requested only by `min`, `typ`, or `max`,
where the generated testbench executes:

```systemverilog
$sdf_annotate(sdf_path, u_dut);
```

Run one selected test explicitly:

```bash
WORKDIR="$HOME/flexsoc-workspace"
TOP=my_ip
RUN_TOP=my_ip
RUN_ID=dev
RUN="$WORKDIR/runs/$RUN_TOP/$RUN_ID"
PDK=sky130
MODE=typ
BACKEND=sv
TEST=smoke
WAVE="$RUN/dv/functional/sim/post_syn/$PDK/${TOP}_${TEST}_${BACKEND}_${MODE}.fst"

fx sim_post_syn --live \
  --workdir "$WORKDIR" \
  --set GLS_BACKEND="$BACKEND" \
  --set TIMING_MODE="$MODE" \
  --set TEST_NAME="$TEST" \
  --set SDF_STRICT=1 \
  --set WAVE_FORMAT=fst \
  --set WAVE_FILE="$WAVE"
```

`compile_post_syn` stops after compilation. `sim_post_syn` compiles, runs, and
writes a machine-readable report. Missing SDF files are fatal in `min/typ/max`;
providing an SDF in `zero/unit` is rejected rather than silently ignored.

SV and cocotb use the same vector-cycle contract. All signal rows with the same
cycle are coalesced into one atomic batch, driven together before the active
clock edge, and checked after the same generated settling interval. A command
row (`@write`, `@cfg`, or `@reset`) cannot share a cycle with another command or
a direct signal drive. Newly generated scaffold vectors serialize every
transaction on one line, while legacy one-signal-per-line files remain valid.

Runtime reset rows are backend-neutral:

```text
<cycle> @reset <cycles>
<cycle> @reset <domain-or-reset-signal> <cycles>
```

The first form pulses all reset domains. The second selects a domain name or reset signal from `CLOCK_DOMAINS`. SV and cocotb assert the same selected resets with the configured polarity, hold them concurrently for the requested number of edges in their own clock domains, release them on falling edges, and reject unknown selectors. This keeps single-clock and N-clock command streams identical.

> **When GLS goes wrong:** debug `zero` first, then `unit`, then SDF modes. A
> `zero` failure points to netlist/model/reset/protocol compatibility; a
> `unit`-only failure points to races, batching, sampling, or timescale
> precision; an SDF-only failure points to corner generation, annotation, or
> supported path-model behavior. Compare SV and cocotb only after confirming the
> same vectors, clock/reset model, and resolved delay.

#### Automatic setup versus literal pipelines

Atomic execution commands prepare generated scripts and configurations by default. `syn` prepends `setup_sdc` and `setup_syn`; formal execution prepends the matching SBY setup; `eqy` prepends `setup_eqy`; sign-off execution prepends `setup_signoff`; and `pnr` prepends `setup_sdc` and `setup_pnr`. Functional and gate-level simulation drivers are always prepared explicitly with `setup_tb` and `setup_cocotb`.

Use `--no-setup` in E2E and debugging sequences where every step is intentionally visible. Gate-level compile/sim commands do not refresh SV or cocotb drivers implicitly. After each PDK switch, explicit pipelines rerun `setup_tb` and `setup_cocotb` before the technology-specific GLS stages. Automatic setup never substitutes for earlier result-producing stages: EQY still requires a synthesized netlist, activity power still requires a completed GLS report, and changing PDK still requires rerunning the technology-bound synthesis and sign-off stages.

#### What Icarus back-annotation proves

Icarus can exercise `specify` path delays but does not implement the complete
SKY130/IHP timing-check behavior used for setup, hold, recovery/removal, pulse
width, and notifier propagation. FlexSoC therefore stages an unmodified-module
copy of the cell models under:

```text
dv/functional/sim/post_syn/<pdk>/icarus_timing_models/
```

The staged model retains path delays and removes unsupported timing-check calls.
Its `manifest.json` records how many checks were removed and delayed inputs were
bound. Reports identify this honestly as:

```text
timing_model = icarus-path-delay-only
timing_checks = disabled-unsupported-by-icarus
```

This is real SDF path-delay back-annotation. It is not full dynamic timing
sign-off. Full setup/hold and recovery/removal simulation requires a simulator
that implements those timing checks; STA remains the primary timing-closure
gate.

#### Strict evidence and reports

With the default `SDF_STRICT=1`, an SDF run passes only when:

- the requested SDF exists and contains real delay records;
- the testbench reports the `$sdf_annotate` request;
- the simulation exits successfully;
- the log contains no recognized SDF annotation error or warning;
- the report and waveform are written successfully.

The report is stored at:

```text
dv/functional/sim/post_syn/<pdk>/<top>_post_syn_<test>_<backend>_<mode>.json
```

Important fields are:

```text
status
backend
simulator
timing_mode
timing_model
timing_checks
netlist
sdf
wave
log
annotation.requested_marker
annotation.markers
annotation.warnings
annotation.errors
```

`SDF_STRICT=0` is a diagnostic escape hatch only. A run that passes solely after
disabling strict diagnostics is not qualified back-annotation evidence.

Report, log, executable, and default waveform names are keyed by
`TEST_NAME`, backend, and timing mode. Independent GLS commands therefore retain
their own evidence without copying files or generating a matrix manifest.

#### Manual post-synthesis sweep

Start with one test and both drivers:

```bash
for mode in zero unit min typ max; do
  for backend in sv cocotb; do
    fx sim_post_syn --live \
      --workdir "$WORKDIR" \
      --set GLS_BACKEND="$backend" \
      --set TIMING_MODE="$mode" \
      --set TEST_NAME=smoke \
      --set SDF_STRICT=1 \
      --set WAVE_FILE="$RUN/dv/functional/sim/post_syn/$PDK/${TOP}_smoke_${backend}_${mode}.fst"
  done
done
```

Then repeat representative reconfiguration, random, protocol, and error tests.
A test that is valid only at zero delay should be fixed or explicitly scoped; it
must not be allowed to create false confidence in `unit` or SDF modes.

#### View one post-synthesis waveform

```bash
find "$RUN/dv/functional/sim/post_syn/$PDK" \
  -type f \( -name '*.fst' -o -name '*.vcd' \) \
  -printf '%p\n' | sort

gtkwave \
  "$RUN/dv/functional/sim/post_syn/$PDK/${TOP}_smoke_sv_typ.fst" &
```

Compare SV and cocotb waveforms only after confirming they used the same vectors,
netlist, cell models, timing mode, SDF, and seed. Absolute transaction times may
differ because the drivers schedule work differently; the architectural command
stream and checked results must agree.

#### Automated E2E qualification

The four E2E tests exercise generated single-clock and multi-clock scaffolds plus
saved CORDIC and UART IPs. `make test` runs both `sky130` and `ihp-sg13g2`,
with one GLS backend and timing mode per pytest invocation. Shared RTL, DV,
formal, and SDC stages run once; each technology branch then compiles, simulates,
checks, and—when SDF-backed—sends every shared/custom vector to
`fx power_analysis` through explicit `uv run --no-sync fx ...` commands.

```bash
make test E2E_ROOT="$HOME/flexsoc-e2e"
```

Direct evidence is written under:

```text
dv/functional/sim/post_syn/<pdk>/
├── <top>_post_syn_<test>_<backend>_<mode>.json
├── <top>_<test>_<backend>_<mode>.fst
└── ...
```

There is no qualification matrix. Each report owns its test/backend/mode
identity and records the exact netlist, SDF, waveform, annotation evidence, and
log. `fx check` discovers these direct reports and prints totals by backend,
timing mode, and test.

```bash
fx check --workdir "$WORKDIR" --set PDK=ihp-sg13g2
```

To inspect one failed command, rerun the exact line printed by pytest with
`--live`. Live mode shows only the generated `[script]` blocks and the `[log]`
transcript; `make test` itself remains non-live.


- Make waivers narrow, justified, owned, and reviewable.
- Use deterministic tool versions and retain lockfiles/manifests.
- Regenerate derived collateral in CI and fail on stale or obsolete documentation.
- Release from a clean, reproducible run rather than a developer's temporary directory.

The short runnable path is in [Quickstart](quickstart.md).


### 21.3 Activity-based power after GLS

The primary-input-assumption `power_estimate` stage is useful before representative stimulus exists, but it is an assumption-based estimate. After a direct post-synthesis GLS command has produced a successful SDF-backed `min`, `typ`, or `max` trace, FlexSoC can use the actual switching activity of each vector test:

```text
qualified GLS report + FST/VCD
        ↓ verify SDF annotation evidence
VCD scoped automatically to test_tb/u_<TOP> or test_tb/u_dut
        ↓ OpenSTA read_vcd
activity annotation report
        ↓ Liberty internal/switching/leakage models
per-corner report_power
```

`fx power_analysis` selects one direct GLS report. `fx power_analysis_all` discovers every matching direct report already present under the selected PDK's post-synthesis directory; no matrix manifest is required. Repeated singular analyses accumulate into the common activity-power summary. OpenSTA uses `/` as the VCD hierarchy separator. FlexSoC therefore inspects the converted VCD, resolves the generated DUT scope automatically (`POWER_VCD_SCOPE=auto`), validates explicit scopes, and records both the requested and resolved scope in every report. The resolver understands the canonical single-clock `u_<TOP>` convention and the N-clock/cocotb `u_dut` convention; `POWER_DUT_INSTANCE` is only an optional hint. This prevents a syntactically valid `read_vcd` call from silently annotating zero activities because of a dotted or nonexistent hierarchy path. When the qualified trace is FST, FlexSoC calls `fst2vcd -f <input> -o <output>` automatically, validates the generated VCD, and retries through the converter's stdout interface only for compatibility with older wrappers. The conversion log is retained under `signoff/<pdk>/power/activity/captures`. `fx check` keeps vectorless power and post-GLS activity power separate so their assumptions cannot be confused.

This is a stronger post-synthesis reference, not final silicon sign-off. Final power closure should repeat the activity flow on the post-route netlist with extracted SPEF, validated foundry Liberty power tables, representative operating windows, voltage/temperature corners, clock-tree activity, and rail/IR-drop analysis.
## 22. Failure-driven lifecycle playbook

The normal lifecycle is iterative. A failure is useful when it identifies the
boundary that no longer matches its assumptions. FlexSoC should be used to
reduce the failure to the earliest owned source, not to accumulate overrides at
the final stage.

The full generated architecture and scaffold rationale are documented in
[IP development guide](ip_development_guide.md).

### 22.1 Standard triage sequence

For every failure:

1. identify the first failing stage, not merely the last command that returned nonzero;
2. confirm `WORKSPACE`, `RUN_TOP`, `RUN_ID`, `PDK`, and persistent clock settings;
3. open the command log and generated tool script;
4. verify the exact input artifact consumed by the stage;
5. classify the failure;
6. repair the earliest source or generator that owns it;
7. regenerate the smallest stale boundary;
8. rerun the smallest named reproducer;
9. rerun all downstream gates whose assumptions changed;
10. refresh manifest, metrics, and check before release.

Useful classification:

| Class | Examples | Correct response |
| --- | --- | --- |
| design mismatch | wrong output, assertion failure, EQY mismatch | repair requirement/model/RTL/property ownership |
| stale generated boundary | old wrapper, filelist, testbench, SDC | regenerate the specific scaffold |
| missing assumption | unconstrained path, illegal formal environment | add a narrow reviewed requirement/constraint/assumption |
| tool/model compatibility | unsupported PDK construct, parser failure | create a declared compatibility adapter without editing the original authority |
| timeout/nonclosure | EQY/formal engine cannot close | change proof strategy/resources; do not label it a mismatch |
| archival failure | missing direct report or waveform | repair command/report handling and rerun the affected combination |

### 22.2 CSR and register-map problems

Common warning signs:

- documentation, RTL, and tests disagree on a field;
- a register reads the wrong reset value;
- generated CSR formal fails;
- a new window is absent from the top wrapper;
- tests contain handwritten offsets or masks.

Designer response:

```bash
# edit data/<top>*.hjson
fx reg doc regmap_py --force
fx top_from_core flist --force
fx tests_gen --force
fx formal_csr
```

Do not patch generated register RTL or Python metadata. If the HJSON itself is
wrong, fixing downstream consumers separately creates several incompatible
register maps.

### 22.3 RTL and hierarchy problems

Common warning signs:

- a package/module is unresolved;
- a port appears in the core but not the top;
- lint finds a latch or width/sign ambiguity;
- simulation, formal, and synthesis elaborate different hierarchies;
- reset or clock ownership is not obvious.

Designer response:

```bash
fx top_from_core --force
fx flist --force
fx slang_hier
fx lint_suite --live
```

Repair authored RTL for real structural problems. Regenerate wrappers/filelists
for mechanical drift. After the repair rerun regression, formal, synthesis, and
downstream sign-off if behavior or state changed.

### 22.4 Functional-DV problems

Common warning signs:

- expected value differs from RTL;
- output appears at a different cycle;
- SV and cocotb disagree;
- CSR access times out;
- coverage is high but a requirement has no scenario;
- a test passes at RTL but not on the gate netlist.

Designer/verification response:

```bash
fx tests
fx test_gen --force --set TEST_NAME=<test>
fx setup_tb setup_cocotb
fx sim --live --set TEST_NAME=<test>
fx cocotb --live --set TEST_NAME=<test>
```

Inspect the first failing vector, model result, declared latency, reset/config
state, and waveform. Preserve one backend-neutral expectation. A backend-only
special case is usually a harness scheduling defect, not a valid alternate
architecture.

### 22.5 Formal problems

Common warning signs:

- a short BMC counterexample;
- prove times out;
- cover is unreachable;
- a property passes instantly but never activates.

Designer response:

```bash
fx formal_bmc
fx formal_prove
fx formal_cover
```

A counterexample requires an RTL/property/requirement decision. A timeout is
inconclusive and may require a smaller cone, stronger valid invariant, another
engine, or additional resources. Add covers for property activation to prevent
vacuous closure.

### 22.6 Clock, reset, and constraint problems

Common warning signs:

- a clock is missing from STA;
- a large endpoint set is unconstrained;
- a false path is used to hide a real crossing;
- simulation and STA use different periods;
- changing a reset/domain breaks only one scaffold.

Designer response:

```bash
fx settings
fx setup_tb setup_cocotb setup_formal setup_sdc setup_syn setup_eqy setup_signoff --force
```

Review CDC/RDC explicitly whenever domain relationships change. An exception is
an architectural statement and requires a narrow scope, rationale, and owner.

### 22.7 Synthesis and equivalence problems

Common synthesis signs:

- unsupported RTL construct;
- unexpected inferred memory/latch;
- large area growth;
- wrong technology cells;
- mapped netlist is absent or stale.

Common equivalence signs:

- one partition reports a concrete mismatch;
- every strategy times out;
- black-box/reset/X modelling differs;
- a technology primitive is missing from the formal view.

Response:

```bash
fx setup_syn syn --force --live
fx setup_eqy eqy --force --live
fx eqy_debug
fx eqy_debug <partition>
```

Keep mismatch, timeout, unknown, and engine error distinct. A synthesis PASS is
not enough; equivalence must prove the representation change preserved logic.

### 22.8 GLS problems

Use the timing modes diagnostically:

```text
zero   mapped-netlist/model/reset/protocol smoke
unit   race, ordering, delta-cycle, sampling, and model-precision smoke
min    ff SDF path-delay qualification
typ    tt SDF path-delay qualification
max    ss SDF path-delay qualification
```

Recommended isolation order:

```bash
fx sim_post_syn --live --set GLS_BACKEND=sv     --set TIMING_MODE=zero --set TEST_NAME=smoke
fx sim_post_syn --live --set GLS_BACKEND=sv     --set TIMING_MODE=unit --set TEST_NAME=smoke
fx sim_post_syn --live --set GLS_BACKEND=cocotb --set TIMING_MODE=unit --set TEST_NAME=smoke
fx sim_post_syn --live --set GLS_BACKEND=sv     --set TIMING_MODE=typ  --set TEST_NAME=smoke --set SDF_STRICT=1
fx sim_post_syn --live --set GLS_BACKEND=cocotb --set TIMING_MODE=typ  --set TEST_NAME=smoke --set SDF_STRICT=1
```

If `zero` fails, repair the netlist/model/reset/protocol boundary before looking
at SDF. If only `unit` fails, inspect atomic drive batching, sample phase,
timescale precision, and the resolved uniform delay. If only SDF modes fail,
inspect corner mapping, annotation evidence, and supported path-model behavior.

The generated Icarus view is a compatibility adapter. Repair its generator or
model-discovery logic when needed; never edit the original PDK library or the
staged generated copy manually.

### 22.9 STA and power problems

For timing:

```bash
fx sta --live
fx sta_violators
```

Treat unconstrained endpoints as incomplete analysis. Negative slack requires a
constraint/architecture/mapping/physical decision; it should not be converted
into a broad exception merely to obtain a green summary.

For early power:

```bash
fx power_estimate --live
```

Review global activity, duty cycle, clocks, Liberty units/tables, and mapped
netlist.

For workload power:

```bash
fx power_analysis --live --set POWER_TEST_NAME=smoke
fx power_analysis_all --live --set POWER_TEST_NAMES=all
```

A failed FST conversion, unresolved VCD hierarchy, or zero activity annotation
means the workload was not applied. Numeric `report_power` output in that state
must not be accepted as activity-based evidence.

### 22.10 Release problems

A run is not release-ready merely because `fx check` prints PASS. Review:

- tool/PDK/image identity;
- Git cleanliness and source revision;
- warnings and waivers;
- coverage and requirements traceability;
- formal and EQY nonclosure classification;
- unconstrained timing endpoints;
- direct GLS report completeness;
- workload relevance for activity power;
- current post-synthesis versus post-route limitations;
- immutable Docker digest and CI verification.

Refresh evidence:

```bash
fx manifest
fx metrics
fx check
```

After closure, save each technology branch explicitly:

```bash
fx pdk use sky130
fx ip_save --set IP_NAME=<name>
fx pdk use ihp-sg13g2
fx ip_save --set IP_NAME=<name>
```

The package retains EQY plus the STA, SDF, vectorless-power, and activity-power
Tcl scripts under `signoff/<function>/<pdk>/`. It deliberately excludes logs,
reports, SDF outputs, waveforms, and converted activity data.


The E2E suite always passes an `IP_LIBRARY_ROOT` below its temporary workspace and compares the complete repository-owned package hash tree before and after the test. `make test` therefore verifies both PDK saves without writing into `hw/ips`.

For Docker-authoritative releases:

```bash
docker/scripts/verify.sh
FULL_E2E=1 docker/scripts/verify.sh
docker/scripts/publish.sh
docker/scripts/check-lock.sh
```

Normal CI should consume the committed digest and fail on an unpublished or
stale lock rather than rebuilding the complete toolchain inside each job.

## 23. Recovering a failed Docker toolchain build

A Docker toolchain failure must be classified by stage.

- A failure in `toolchain-prereqs` means an Ubuntu package or bootstrap problem.
- A failure in `toolchain-installed` means one pinned tool failed to compile.
  Retry without pruning: downloaded sources, build trees, installed tools, and
  completion markers are retained in named BuildKit caches.
- A failure in `toolchain-verified` means the binaries exist but a runtime
  dependency, version check, or smoke command is incomplete. The local
  `*-installed` checkpoint remains available and the retry starts after the
  expensive compilation work.
- A failure in `runtime` or `verify.sh` means the EDA checkpoint is already
  valid; fix Python or project-level verification and rebuild.

The designer should inspect the first failing stage and its command rather than
pruning all Docker state. `docker/scripts/inspect.sh` reports the retained
checkpoint. Builder pruning is appropriate only when intentionally invalidating
the whole toolchain cache. A checkpoint never counts as release evidence: the
final runtime image must still pass the managed doctor and complete E2E.

A doctor-only version-reporting failure must be repaired above the checkpoint,
not by discarding it. SymbiYosys and EQY are installed with release strings
from `toolchain.lock` rather than relying on `git describe` in shallow detached
checkouts. If a legacy checkpoint prints only `SBY` or `EQY`, rerun the build:
FlexSoC reinstalls only the affected launcher/plugin files and resumes at doctor
while retaining the compiled EDA prefix.

GTKWave requires a graphical GTK environment for normal startup, but the Docker
doctor is intentionally headless. It validates the lock-bound source marker,
the install-time version receipt, both managed executables (`gtkwave` and
`fst2vcd`), and the viewer's shared-library resolution. Do not add a fake
`DISPLAY` or X server merely to query a version: a GUI initialization failure
is not evidence that the installed binaries or FST conversion path are broken.
## 24. Equivalence recovery for protocol outputs

A timeout on a packed protocol response is not evidence of a logic mismatch. FlexSoC first canonicalizes protocol-defined don't-care fields and projects TL-UL `tl_o` into bounded formal witnesses. The packed response is internal to the formal wrapper and is not retained as a second public output; otherwise EQY would still generate raw bit partitions alongside the witnesses. Single-clock equivalence is initialized through the declared reset contract, so the default claim is equivalence after legal reset rather than equivalence from arbitrary uninitialized flop states.

The designer should respond according to the evidence:

- a witness `FAIL` with a concrete trace requires RTL/synthesis-boundary investigation;
- a witness `TIMEOUT` remains inconclusive and should be replayed with `fx eqy_debug`;
- an engine error with no trace is a tool/strategy failure, not a demonstrated RTL mismatch; use the stable `abc pdr` default before changing the design;
- a reset-normalized PASS indicates an initialization-state problem, not permission to hide a functional mismatch;
- multi-clock reset normalization remains opt-in and must follow an explicitly reviewed domain-reset sequence.

Do not waive a whole `tl_o` bus because one solver timed out. Work at the field witness that failed, preserve the generated formal view, and archive the EQY configuration and diagnostic result with the run manifest.


## PDK-first sign-off and analysis ownership

Technology-dependent outputs use one consistent PDK-first hierarchy:

```text
runs/<design>/<variant>/
├── syn/<pdk>/
├── pnr_openroad/<pdk>/
└── signoff/<pdk>/
    ├── equivalence/rtl_vs_syn/
    ├── sta/<corner>/<setup|hold>/
    ├── sdf/<corner>/
    ├── power/
    │   ├── activity/captures/
    │   ├── estimate/<corner>/
    │   └── analysis/<workload>/<corner>/
    └── fusion/<workload>/<corner>/<setup|hold>/
```

`activity/` contains only VCD/SAIF captures and conversion logs. Each analysis
family owns one canonical Tcl under its stage root; workload/corner/mode
directories contain reports only. There is no `activity/scripts` directory and
no additional activity manifest.

The backend ownership is deliberately narrow:

```text
Makefile -> setup_signoff.py -> OpenSTA Tcl, execution, logs and reports
Makefile -> setup_eqy.py     -> EQY config, execution inputs and portable export
```

`setup_signoff.py` owns `sta`, `power_estimate`, `power_analysis` and
`fusion_analysis`; `setup_eqy.py` owns only RTL-to-netlist equivalence. The old
`power_analysis.py` entry point has been removed so activity discovery, scope
resolution, Tcl generation and OpenSTA execution cannot diverge.

The four OpenSTA Tcl families are generated by `fx setup_signoff`. Static
analyses create concrete per-corner scripts when executed. Workload analyses
create concrete scripts only after a qualified GLS report and VCD/SAIF exist.
`fx fusion_analysis` and `fx fusion_analysis_all` preserve independent
TIMING_DRIVEN and POWER_DRIVEN selections; a power-driven path is never filtered
by slack and may therefore be timing-safe.

Fusion emits `TIMING_VIOLATING`, `TIMING_NEAR_CRITICAL`, and independently ranked
`POWER_DRIVEN` paths.  `FUSION_POWER_METRIC=dynamic|total` selects the
hotspot and path-power ranking metric.  Path reports include launch/data/capture
roles, pin and instance sequences, timing attributes, per-instance power, slew,
complete-net capacitance and fanout.  `paths.csv` and `path_instances.csv` feed
separate rankings for dynamic power, total power, capacitance, fanout, and slew;
activity-weighted capacitance remains blank unless reliable pin/net activity is
available from the pinned OpenSTA build.

### OpenSTA compatibility boundary

The repository pins OpenSTA commit `d5761004cd2cd2bcfa85d73327867966c279c83d` in
`src/flexsoc/backend/toolchain.lock`. Fusion treats `find_timing_paths`,
`sta::instance_power`, `sta::cmd_scene`, `sta::network_leaf_instances`,
`get_full_name`, `get_pins`, `get_cells`, and `get_nets` as indispensable and
terminates with a named diagnostic when one is unavailable. Optional JSON
formats and optional pin/net detail APIs are protected with Tcl `catch` or
fallback probes. Missing optional data remains blank; FlexSoC does not invent
activity, capacitance, fanout, slew, or power values.
