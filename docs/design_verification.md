# 🧪 Design verification

This page is the canonical reference for **PDK-independent design verification
(DV)** in FlexSoC. It explains the logical verification branches, the commands
that belong to each branch, what each result means, and where the generated
artifacts live.

Technology-dependent implementation closure — including RTL ↔ synthesized
netlist equivalence — belongs to [Design sign-off](design_signoff.md).

## 1. 🧭 Verification model

```text
Design Verification
├── 🟠 Functional DV
│   ├── behavioral model + generated CSR API
│   ├── reusable vector tests
│   ├── SystemVerilog simulation
│   ├── cocotb simulation
│   ├── regression
│   ├── code/toggle coverage
│   └── waveform debug
│
├── 🧠 Property formal
│   ├── automatic CSR semantics
│   │   ├── BMC
│   │   ├── PROVE
│   │   └── COVER
│   └── authored design properties
│       ├── BMC
│       ├── PROVE
│       └── COVER
│
└── 🌐 Structural domain verification                 [planned]
    ├── CDC
    └── RDC
```

These branches answer different questions and are intentionally reported
separately.

| Branch | Question | Result |
| --- | --- | --- |
| Functional regression | Does the design behave as expected for the selected scenarios? | test PASS/FAIL |
| Functional coverage | Which RTL structures were exercised? | scope × type percentage |
| Formal BMC | Is there a shallow assertion counterexample? | PASS/FAIL within bound |
| Formal PROVE | Can an assertion be proven inductively? | proof status |
| Formal COVER | Is a requested state/sequence reachable? | reached/unreached |
| CDC/RDC | Are clock/reset-domain crossings structurally safe? | findings/waivers `[planned]` |

> 🔁 RTL-to-netlist equivalence is a formal method, but in FlexSoC it is a
> **sign-off stage** because it validates a technology-mapped implementation.

## 2. 🗂️ DV ownership

PDK-independent DV lives directly under the logical run:

```text
runs/<RUN_TOP>/<RUN_ID>/
├── rtl/
├── dv/
│   ├── functional/
│   │   ├── model/
│   │   ├── tests/
│   │   ├── tb/
│   │   ├── sim/rtl/
│   │   └── coverage/
│   └── formal/
│       ├── csr/
│       ├── properties/
│       └── runs/
└── analysis/
    ├── cdc/                 # planned
    └── rdc/                 # planned
```

Changing `PDK` must not invalidate these artifacts.

Gate-level simulation is still functional verification, but its implementation
artifacts are PDK-dependent. Therefore only that leaf is scoped by technology:

```text
dv/functional/sim/
├── rtl/
├── post_syn/
│   ├── sky130/
│   └── ihp-sg13g2/
└── post_pnr/
    ├── sky130/
    └── ihp-sg13g2/
```

## 3. 🟠 Functional DV flow

### 3.1 Model and CSR API

Bootstrap the model/test layer:

```bash
fx setup_model --force
```

The generated structure is:

```text
dv/functional/model/
├── <top>_model.py       # behavioral/reference model
├── <top>_regmap.py      # Python register API derived from HJSON
└── <top>_tests.py       # test catalogue and expected behavior
```

When only the register map changes, regenerate the derived Python CSR model:

```bash
fx regmap_py --force
```

Do not overwrite authored behavioral-model logic unless intentionally
regenerating the scaffold.

### 3.2 Materialize reusable tests

```bash
fx tests_gen --force
```

Each logical test becomes simulator-independent collateral:

```text
dv/functional/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

SystemVerilog and cocotb consume the same test data. Backend choice must not
silently change test intent.

### 3.3 Generate simulation infrastructure

```bash
fx setup_tb setup_cocotb --force
```

- `setup_tb` creates the SystemVerilog vector-test scaffold.
- `setup_cocotb` creates the cocotb wrapper and Python test infrastructure.
- Multi-clock runs select the corresponding multi-clock generators through
  `CLOCK_MODE=multi` while keeping the public command surface consistent.

RTL simulation is **PDK-independent**. Liberty files and standard-cell models
must never leak into this branch.

### 3.4 Run one test

SystemVerilog:

```bash
fx sim --set TEST_NAME=smoke --force
```

cocotb:

```bash
fx cocotb --set TEST_NAME=smoke --force
```

Use `--live` when the normal compact log is not enough:

```bash
fx cocotb --set TEST_NAME=smoke --force --live
```

### 3.5 Run the regression

```bash
fx regression --force
```

The standard regression executes the generated test catalogue on the selected
functional backends and reports each `<backend>/<test>` independently.

A regression result is behavioral closure; it is not a coverage percentage.

### 3.6 Inspect coverage

```bash
fx coverage
fx coverage_detail
```

The primary report is the scope × type matrix:

```text
Scope          line   toggle   expr   branch   fsm   user   total
design
registers
common
other
all
```

The fixed normalized columns mean:

- `line` — executed code lines;
- `toggle` — signal transitions;
- `expr` — expression coverage;
- `branch` — decision/branch coverage;
- `fsm` — state + arc coverage;
- `user` — user/covergroup points;
- `total` — Verilator aggregate points for the scope.

Coverage is a measurement, not automatically a PASS/FAIL gate.

### 3.7 Waveforms

FST is the default waveform format:

```bash
fx settings WAVE_FORMAT=fst
```

VCD is explicit opt-in:

```bash
fx settings WAVE_FORMAT=vcd
```

The generated testbenches use the canonical runtime contract:

```text
+WAVE=<absolute path>
```

No testbench should invent a relative VCD filename in the repository root.

## 4. 🧠 Property formal

Property formal is PDK-independent and lives entirely under `dv/formal/`.

### 4.1 Automatic CSR checks

Generate the register-semantic checks:

```bash
fx setup_formal_csr_prove
fx setup_formal_csr_cover
```

Run them individually:

```bash
fx formal_csr_bmc
fx formal_csr_prove
fx formal_csr_cover
```

or in logical order:

```bash
fx formal_csr
```

Generated CSR checkers are bound to the reggen primitives without modifying the
DUT implementation:

- `assert` is a property that must hold;
- `cover` is a reachability objective;
- `bind` attaches the checker to the existing RTL hierarchy.

### 4.2 Authored design properties

Prepare the designer-owned formal scaffold:

```bash
fx setup_formal --force
```

Then run the stages independently:

```bash
fx formal_bmc
fx formal_prove
fx formal_cover
```

or as one fail-fast flow:

```bash
fx formal
```

The intended reasoning order is:

```text
BMC
 │  find shallow counterexamples quickly
 ▼
PROVE
 │  close the assertion inductively
 ▼
COVER
    validate reachability / assumptions
```

A COVER result is not a proof result.

## 5. 🕰️ Single-clock vs multi-clock DV

The user-facing commands remain the same; `CLOCK_MODE` selects the correct
scaffold and formal assumptions.

| Topic | Single clock | Multi clock |
| --- | --- | --- |
| Functional tests | one primary clock | per-domain clocks/events |
| Coverage | same scope × type model | same scope × type model |
| Property formal | standard BMC/PROVE/COVER | multiclock-aware assumptions |
| CDC/RDC | limited relevance | fundamental closure axis `[planned]` |

When clocks have known frequency/phase relationships, those relationships must
be represented explicitly in the formal environment. “Multiple clocks” does
not automatically mean “independent clocks.”

## 6. 🌐 CDC / RDC — next verification step

CDC and RDC will be separate structural analyses rather than percentages folded
into functional coverage or property-formal proof.

Planned ownership:

```text
analysis/
├── cdc/
│   ├── findings.json
│   ├── summary.txt
│   └── waivers.*
└── rdc/
    ├── findings.json
    ├── summary.txt
    └── waivers.*
```

The intended implementation combines Slang/Yosys structural data with custom
Python analysis and explicit waiver handling.

## 7. ➡️ Handoff to implementation sign-off

After RTL regression and property formal are clean, implementation closure moves
to the technology-dependent flow:

```text
RTL / DV
   ↓
synthesis/<pdk>
   ↓
signoff/equivalence/<pdk>
   ↓
post-synthesis GLS/<pdk>
   ↓
PnR/<pdk>
   ↓
post-PnR GLS + SDF / STA / power
```

See [Design sign-off](design_signoff.md) for the exact commands, PDK-scoped
folder layout, EQY counterexample workflow, and cross-PDK diagnosis.
