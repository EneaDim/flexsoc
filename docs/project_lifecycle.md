# 🔄 FlexSoC project lifecycle

This document is the canonical engineering guide for developing, verifying,
implementing, signing off, reusing, and releasing a digital ASIC IP or small SoC
with FlexSoC.

It combines the design theory with the practical `fx` workflow. The aim is not
to prescribe one microarchitecture; it is to make every source of truth,
derived artifact, quality gate, and handoff explicit enough for production use.
The exhaustive syntax and lifecycle role of every command is maintained in the
[FlexSoC command reference](command_reference.md).

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
   ├── functional DV: model, scenarios, simulation, coverage
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
   ├── post-synthesis SDF and optional GLS
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

```bash
fx tests_gen --force
fx tests
```

Each scenario is materialized as simulator-independent data:

```text
dv/functional/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

A scenario can combine direct pins with CSR writes and reads. Expected outputs
should express protocol events or architectural latency, not simulator-specific
delays.

### 8.3 Simulation infrastructure

```bash
fx setup_tb setup_cocotb --force
fx sim_tests
fx cocotb_tests
```

Or run the configured regression and coverage flow:

```bash
fx regression
fx coverage_detail
```

SystemVerilog and cocotb consume the same generated vectors. Differences
between the two backends are therefore useful diagnostics rather than separate
test intent.

### 8.4 Coverage and exit criteria

Code coverage is a review tool, not an automatic quality certificate. Inspect:

- line and branch coverage;
- expression and toggle coverage;
- FSM coverage;
- user-defined functional cover points;
- exclusions and unreachable logic.

A production gate should combine coverage thresholds with scenario review,
requirements traceability, assertions, and bug history.

### 8.5 Debug

```bash
fx regression --live
fx view
fx view_cocotb
```

Logs live under `logs/dv/functional/`; waveforms and generated vectors remain in
the run workspace.

---

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

### 13.2 SDF and gate-level simulation

SDF and STA are sibling consumers of the timing model; STA does not require SDF.
SDF is primarily used to annotate delays into gate-level simulation.

```bash
fx sdf --force
fx compile_post_syn --force
fx sim_post_syn --force
```

Post-synthesis GLS can expose:

- reset and initialization assumptions;
- simulation/synthesis semantic differences;
- timing-check behavior;
- missing cell models;
- testbench assumptions that were hidden at RTL.

It does not replace equivalence or STA.

### 13.3 Pre-layout STA

```bash
fx sta --force
fx sta_violators
```

Pre-layout STA uses the mapped netlist, Liberty timing, SDC, and estimated
interconnect. Review setup and hold separately across configured corners.

A clean report requires:

- all clocks recognized;
- all intended endpoints constrained;
- no unexplained unconstrained paths;
- justified exceptions;
- positive or accepted slack policy;
- transition, capacitance, and fanout checks where supported.

### 13.4 Power estimate

```bash
fx power_estimate --force
```

The current flow supports a global-activity estimate controlled by:

```text
POWER_ACTIVITY
POWER_DUTY
```

This is useful for early comparison, not final silicon power sign-off. Later
stages should use realistic activity from representative workloads when the
flow supports it, together with extracted parasitics and appropriate corners.

Run all current post-synthesis analysis with:

```bash
fx signoff_corners --force
```

---

## 14. Physical implementation with OpenROAD

```bash
fx setup_pnr --force
fx pnr --force
fx pnr_gui
```

The implementation stage normally includes:

1. floorplan and pin placement;
2. power-distribution planning;
3. placement and optimization;
4. clock-tree synthesis;
5. routing and post-route optimization;
6. parasitic extraction;
7. final reports and layout collateral.

Implementation is not a mechanical final step. Congestion, clock skew, hold
fixes, buffering, and routing parasitics can expose architectural or constraint
problems that require a return to RTL or floorplanning.

Review:

- utilization and congestion;
- placement/routing completion;
- clock-tree quality;
- setup and hold after CTS and routing;
- antenna and electrical checks where available;
- final netlist and parasitic outputs;
- consistency between SDC used in synthesis, STA, and PnR.

---

## 15. Post-layout sign-off

Final sign-off must use the implemented netlist and extracted parasitics rather
than the pre-layout approximation.

Typical FlexSoC entry points are:

```bash
fx sdf_post_pnr --force \
  --set NETLIST=/path/to/final_netlist.v \
  --set SPEF_FILE=/path/to/final.spef \
  --set PNR_SDC_FILE=/path/to/final.sdc

fx compile_post_pnr --force --set NETLIST=/path/to/final_netlist.v
fx sim_post_pnr --force --set NETLIST=/path/to/final_netlist.v
```

STA and power scripts can consume the selected final netlist, SDC, and SPEF
through their corresponding settings.

A production release also requires project-specific physical checks such as:

- DRC;
- LVS;
- antenna verification;
- IR drop and electromigration;
- clock and power integrity;
- density/fill and foundry deck compliance;
- final logical equivalence after implementation/DFT/ECO where applicable.

These checks are named here as mandatory lifecycle evidence even when execution
is owned by external sign-off tools rather than the current FlexSoC backend.

---

## 16. Release and qualification

A release should be reproducible and reviewable.

```bash
fx manifest --force
fx manifest_show
fx metrics --force
fx check --force
```

Retain or publish, according to project policy:

- exact configuration and clock model;
- source revision and dependency lockfiles;
- generated register documentation;
- lint, regression, coverage, and formal reports;
- synthesis netlist and reports;
- EQY result and strategy summary;
- STA, SDF, power, and PnR reports;
- final netlist/parasitics/layout references;
- known waivers and risk acceptance;
- release notes and interface compatibility statement.

A reusable IP release belongs under `hw/ips/<top>/` only after authored source
and selected qualification evidence have been deliberately saved. Run scratch,
waveforms, solver workdirs, and temporary databases should not be copied into the
source library.

---

## 17. Change-driven workflows

The fastest correct workflow is based on what changed.

### 17.1 Add or change a configuration CSR

1. Edit the HJSON field definition and reset/access policy.
2. Regenerate hardware, docs, Python regmap, and vectors.
3. Update model/tests only if behavior changed.
4. Rerun CSR formal, functional DV, synthesis, and equivalence.

```bash
fx reg doc --force
fx regmap_py --force
fx tests_gen --force
fx flist --force
fx lint_suite
fx regression
fx formal
fx syn eqy --force
```

### 17.2 Add a hardware status CSR

1. Define the status field in HJSON.
2. Connect the generated `hw2reg` path from the owning RTL state.
3. Update the model and read-check scenario.
4. Add an assertion if the status encodes an invariant or sticky event.

Then run the same closure as a CSR behavior change.

### 17.3 Add, remove, or change an RTL port

```bash
# edit rtl/<top>_core.sv
fx top_from_core --force
fx flist --force
fx lint_suite
fx setup_tb setup_cocotb --force
fx regression
fx formal
fx syn eqy --force
```

Review every integration point. A generated wrapper can reconnect ports, but it
cannot decide the new protocol semantics for the model, tests, SoC, or
constraints.

### 17.4 Change behavior without changing interfaces

Update together:

```text
RTL behavior
reference model
functional scenarios
assertions/covers
requirements text
```

Then:

```bash
fx flist --force
fx lint_suite
fx tests_gen --force
fx regression
fx formal
fx syn eqy --force
```

### 17.5 Change latency or handshake timing

Fixed-cycle expectations are part of the interface contract. Prefer explicit
valid/ready or completion events when variable latency is legal.

After a latency change review:

- model timing;
- vector interpretation;
- TB wait conditions;
- assertions;
- CDC queues;
- throughput and back-pressure requirements;
- timing constraints if pipelines or clocks changed.

### 17.6 Add or modify a clock/reset domain

1. Update `N_CLOCKS` and `CLOCK_DOMAINS`.
2. Declare each relationship explicitly.
3. Assign every register window and sequential block to the intended domain.
4. Insert reviewed CDC/RDC structures.
5. Regenerate TB, formal, SDC, synthesis, and sign-off collateral.

```bash
fx setup_tb setup_cocotb --force
fx setup_formal setup_sdc setup_syn setup_eqy setup_signoff --force
fx flist --force
fx lint_suite
fx regression
fx formal
fx syn eqy --force
fx sdf sta power_estimate --force
```

### 17.7 Change constraints only

```bash
fx setup_sdc --force
fx setup_syn setup_signoff setup_pnr --force
fx syn eqy --force
fx sdf sta power_estimate --force
```

If the RTL netlist is unchanged, equivalence should remain stable, but rerunning
it keeps the sign-off run self-contained and confirms the correct artifacts were
selected.

### 17.8 Change only tests

```bash
fx tests_gen --force
fx regression
fx coverage_detail
```

Formal, synthesis, and implementation do not automatically become stale unless
the test change exposed a required design or property modification.

### 17.9 Change only authored properties

```bash
fx formal
```

A property change is a verification-contract change. Review assumptions and
waivers even when RTL is untouched.

### 17.10 Reuse an existing IP

```bash
fx settings \
  TOP=my_ip RUN_TOP=my_ip RUN_ID=dev HOST=uart \
  N_CLOCKS=1 CLOCK_DOMAINS=core:clk_i:rst_ni:10:low CLOCK_RELATIONSHIPS=
fx setup --force
fx ip_load --force
fx flist --force
fx lint_suite
fx tests_gen --force
fx regression
fx formal
fx syn eqy --force
```

Preserve source-owned RTL, HJSON, model, tests, and properties. Regenerate only
collateral that is explicitly derived.

### 17.11 Integrate validated IPs into a SoC

A SoC owns its top-level interfaces, address map, clock/reset plan, system
verification, constraints, and sign-off assumptions.

```bash
fx soc_cfg
fx soc_start
fx soc_flist
fx lint_suite
fx regression
fx formal
fx syn eqy --force
fx setup_pnr pnr --force
```

Standalone IP qualification reduces integration risk but does not replace
system-level verification.

---

## 18. Quality gates

| Gate | Required evidence | Typical commands |
| --- | --- | --- |
| Requirements ready | functions, states, interfaces, clocks, acceptance criteria | project review |
| Design entry ready | HJSON/RTL coherent, hierarchy resolves | `fx reg doc top_from_core flist --force` |
| Structural RTL clean | lint and elaboration accepted | `fx lint_suite` |
| Functional DV clean | scenarios pass, coverage reviewed | `fx regression`, `fx coverage_detail` |
| Property formal clean | BMC/prove/cover reviewed | `fx formal` |
| CDC/RDC clean | crossings classified and waived intentionally | dedicated CDC/RDC stage |
| Synthesis clean | mapped netlist and reports reviewed | `fx syn --force` |
| Logical equivalence clean | all required EQY partitions proven | `fx eqy --force` |
| Pre-layout timing clean | constraints complete, setup/hold acceptable | `fx sta --force` |
| Early power acceptable | estimate within architecture budget | `fx power_estimate --force` |
| Implementation complete | routed design and extraction available | `fx pnr --force` |
| Post-layout sign-off clean | extracted STA/SDF/GLS/power and physical checks | project sign-off commands |
| Release ready | manifest, metrics, reports, waivers, revision captured | `fx manifest metrics check --force` |

---

## 19. Run workspace

```text
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
├── data/                         HJSON register specifications
├── doc/                          generated register documentation
├── rtl/                          core/top/register RTL and filelists
├── constraints/                  logical SDC
├── dv/
│   ├── functional/
│   │   ├── model/                model, generated regmap, scenarios
│   │   ├── tests/                materialized vectors
│   │   ├── tb/                   SV and cocotb infrastructure
│   │   ├── sim/                  RTL/post-syn/post-PnR runs
│   │   └── coverage/
│   └── formal/
│       ├── csr/
│       ├── properties/
│       └── runs/
├── analysis/                     hierarchy and future CDC/RDC results
├── syn/<pdk>/                    synthesis scripts, netlist, reports
├── pnr_openroad/<pdk>/           physical implementation
├── signoff/
│   ├── equivalence/<pdk>/
│   ├── sta/<pdk>/
│   ├── sdf/<pdk>/
│   └── power/<pdk>/
├── logs/
└── meta/<pdk>/                   manifest and metrics
```

Technology-independent source and DV live above PDK-specific implementation
leaves. This allows several technologies or corners to coexist without copying
the logical design.

---

## 20. Production-grade operating rules

- Keep requirements, RTL, model, tests, and properties under review and version control.
- Never hand-copy CSR offsets into model or test code.
- Treat warnings as review items; do not normalize unexplained warnings.
- Keep clock/reset relationships explicit and versioned.
- Require traceability from requirements to scenarios/properties/checks.
- Separate code coverage, proof closure, equivalence closure, timing closure, and physical closure.
- Make waivers narrow, justified, owned, and reviewable.
- Use deterministic tool versions and retain lockfiles/manifests.
- Regenerate derived collateral in CI and fail on stale or obsolete documentation.
- Release from a clean, reproducible run rather than a developer's temporary directory.

The short runnable path is in [Quickstart](quickstart.md).
