# FlexSoC ASIC flow guide

> **Purpose.** This document explains the current FlexSoC digital-ASIC lifecycle as one coherent engineering flow: from control/status register intent and generated RTL collateral, through structural and functional verification, synthesis, equivalence, timing/power sign-off, OpenROAD physical implementation, routed gate-level verification, and final physical sign-off. It also defines the two main roadmap blocks that are not yet part of the qualified flow: DFT and hard-memory integration.
>
> The focus is deliberately on **what FlexSoC does, why each stage exists, what scripts and tools are involved, what evidence is produced, and what a PASS actually means**. It is not a tutorial on RTL design itself, nor a reference for every CLI option. For exact command syntax use `docs/command_reference.md`; for project ownership and regeneration policy use `docs/project_lifecycle.md` and `docs/ip_development_guide.md`.

---

## 1. The flow in one page

FlexSoC treats an ASIC build as a chain of contracts. Every stage consumes a small set of explicit inputs and produces artifacts that are checked before the next stage is trusted.

```text
Architecture / clock-reset intent / CSR intent
                    │
                    ▼
        CSR and interface generation
        HJSON → reg RTL/docs/regmap/driver
                    │
                    ▼
               RTL scaffold
       single-clock or N-clock structure
                    │
                    ▼
          ordered RTL elaboration
                    │
       ┌────────────┼─────────────┐
       ▼            ▼             ▼
     Lint        CDC / RDC       Formal
 Slang+Verilator structural       BMC / prove / cover
       │            │             │
       └────────────┼─────────────┘
                    ▼
          Functional verification
         shared scenario/vector DSL
          ┌──────────┴──────────┐
          ▼                     ▼
     SystemVerilog            cocotb
          │                     │
          └──────────┬──────────┘
                     ▼
                  Coverage
                     │
                     ▼
                 Synthesis
            Yosys + ABC + Liberty
                     │
                     ▼
          RTL ↔ synthesis EQY
                     │
                     ▼
      Pre-implementation sign-off
         STA + SDF + power estimate
         + post-syn GLS/activity/fusion
                     │
                     ▼
          Physical implementation
                  ORFS/OpenROAD
 floorplan → PDN → placement → CTS → routing → finish/extraction
                     │
                     ▼
      Post-implementation sign-off
 SPEF STA + routed SDF + GLS + power + fusion
                     │
                     ▼
            Physical sign-off
 route DRC + antenna + GDS DRC + LVS + IR/PDN
                     │
                     ▼
          metrics / manifest / check
```

The same macro-flow is used for one clock or many clocks. The clock topology is configuration, not a separate backend implementation.


### How to read this guide

For a first pass, read the sections in order. For implementation work, the following map is the quickest way to jump from a flow concept to the backend source that generates or qualifies it.

| Flow responsibility | Main FlexSoC implementation |
| --- | --- |
| HJSON CSR templates | `src/flexsoc/backend/design/regs.py` |
| Python CSR/regmap helpers | `src/flexsoc/backend/design/regs.py` |
| software driver collateral | `src/flexsoc/backend/design/regs.py` |
| single/N-clock RTL starter | `src/flexsoc/backend/design/rtl.py` |
| lint orchestration | `src/flexsoc/backend/dv/dv.py` |
| CDC/RDC extraction and qualification | `src/flexsoc/backend/dv/cdc.py` |
| scenario/vector generation | `src/flexsoc/backend/design/model.py`, `src/flexsoc/backend/dv/functional.py`, `dv/testbench.py`, `dv/functional.py` |
| cocotb testbench generation | `src/flexsoc/backend/dv/testbench.py` |
| CSR/design formal generation | `src/flexsoc/backend/dv/formal.py` |
| Yosys/ABC synthesis scripts | `src/flexsoc/backend/syn/syn.py` |
| RTL↔synthesis equivalence | `src/flexsoc/backend/syn/eqy.py` |
| OpenSTA SDC/STA/SDF/power/fusion | `src/flexsoc/backend/signoff/sta.py`, `power.py`, `fusion.py` |
| post-syn/post-PnR GLS | `src/flexsoc/backend/signoff/gls.py` |
| ORFS physical config | `src/flexsoc/backend/impl/impl.py` |
| ORFS execution/tool resolution | `src/flexsoc/backend/impl/impl.py` |
| final DRC/LVS/antenna/IR qualification | `src/flexsoc/backend/signoff/__init__.py` |
| lifecycle metrics/check | `src/flexsoc/backend/core/reporting.py` |
| artifact/tool manifest | `src/flexsoc/backend/core/reporting.py` |

### Compact contents

- **Part I:** CSR generation, multi-clock RTL scaffold, ordered elaboration.
- **Part II:** lint, CDC/RDC, functional SV+cocotb verification, coverage, formal.
- **Part III:** Yosys/ABC synthesis and EQY logical equivalence.
- **Part IV:** pre-implementation STA/SDF/power and mapped-netlist gate verification.
- **Part V:** ORFS/OpenROAD floorplan, PDN, placement, CTS, routing, finish/extraction.
- **Part VI:** routed STA/SDF/GLS/power/fusion.
- **Part VII:** route DRC, antenna, GDS DRC, LVS, IR/PDN.
- **Part VIII–IX:** metrics/manifest/check and the complete current executable flow.
- **Part X–XI:** DFT and SRAM/hard-macro roadmap.
- **Part XII–XIII:** later full-chip considerations and recommended implementation order.

### Current lifecycle status model

FlexSoC intentionally distinguishes three outcomes:

- **PASS** — the evidence exists and the relevant checks are clean.
- **REVIEW** — the flow ran, but an engineering obligation or unsupported/missing capability still needs human sign-off.
- **FAIL** — a real verification/sign-off violation or tool failure occurred.

That distinction is important for CDC/RDC and physical sign-off. A check that cannot be performed must not become a false PASS.

---

## 2. Design principles that hold the flow together

### 2.1 One source of truth per design fact

FlexSoC tries to avoid the classic ASIC-flow problem where the same fact is copied into RTL, testbench code, software headers, constraints, and scripts independently.

| Fact | Source of truth | Derived collateral |
| --- | --- | --- |
| CSR addresses, fields, reset values, access policy | HJSON | register RTL, docs, Python regmap, driver collateral, CSR formal |
| Clock/reset bootstrap | `N_CLOCKS`, `CLOCK_DOMAINS`, `CLOCK_RELATIONSHIPS` | first SDC scaffold, reset ownership/polarity, reset-aware formal/CDC context |
| Functional scenario | generated/authored scenario model | `config.regs`, `data_in.vec`, `data_out.vec` |
| Synthesis mapping | PDK Liberty + synthesis configuration | mapped netlist, checkpoints, area/stat reports |
| Timing intent | canonical FlexSoC SDC | OpenSTA sign-off and ORFS implementation |
| Physical implementation | FlexSoC mapped netlist + SDC + ORFS platform | final netlist, SDC, SPEF, ODB, GDS |
| Run qualification | generated reports/artifacts | `metrics.json`, manifest, `fx check` |

The engineering rule is:

```text
edit intent
→ regenerate only derived collateral
→ rerun every downstream gate whose assumptions changed
```

### 2.2 Generated code versus designer-owned code

Generated files are allowed to be overwritten. Designer-owned files are preserved.

Typical generated collateral:

- HJSON starter maps;
- register RTL and register documentation;
- Python register-map helpers;
- starter top/core RTL;
- ordered filelists;
- testbench scaffolds and generated scenarios;
- synthesis, equivalence, OpenSTA and ORFS configuration scripts;
- metrics and manifests.

Typical designer-owned collateral:

- the actual RTL behavior after the scaffold is adopted;
- architecture-specific CDC protocols;
- authored formal properties;
- functional/reference model behavior;
- meaningful scenario catalogue and acceptance criteria;
- custom integration constraints.

### 2.3 Single-clock and multi-clock are one flow

Clocking is described structurally. For example:

```text
single clock:
  N_CLOCKS=1
  core:clk_i:rst_ni:10ns:active-low

multi clock:
  cfg:cfg_clk_i:cfg_rst_ni:20ns:active-low
  rx:rx_clk_i:rx_rst_ni:16ns:active-low
  dsp:dsp_clk_i:dsp_rst_ni:30ns:active-low
  cfg ↔ rx  asynchronous
  cfg ↔ dsp asynchronous
  rx  ↔ dsp asynchronous
```

The downstream tools use the same flow. What changes is the generated clock/reset context and the analysis policy.

---

## Part I — Design entry and generated collateral

## 3. Automatic control/status register generation

The CSR flow is the first major automation boundary. The software-visible register map is described once in HJSON and then propagated consistently into hardware and verification.

### 3.1 HJSON is the CSR source of truth

A register map describes, at minimum:

- register name and address ordering;
- field bit positions;
- software access policy (`rw`, `ro`, write-one semantics, etc.);
- hardware access direction;
- reset values;
- whether a hardware-owned field is externally driven;
- bus interface metadata.

The current generated register blocks use a TL-UL device interface and 32-bit register width.

A conceptual flow is:

```text
HJSON
  │
  ├─ validate register semantics
  ├─ generate synthesizable register RTL
  ├─ generate human-readable register docs
  ├─ generate Python register/address objects
  ├─ generate software driver collateral
  └─ expose the register primitives to automatic formal checks
```

The relevant FlexSoC targets are centered around:

```bash
fx hjson --force
fx reg doc --force
fx regmap_py --force
fx driver --force
```

Internally, FlexSoC uses the bundled register tooling under `src/util/regtool.py` / `reggen` instead of maintaining a second independent CSR generator.

### 3.2 Multi-clock register-map example

The generated N-clock scaffold demonstrates a useful separation between a configuration domain and a datapath domain.

**Configuration-domain map** (`<top>_cfg.hjson`):

- `CTRL.ENABLE` — global enable distributed toward datapath domains;
- `CTRL.SOFT_RESET` — software-controlled datapath clear request;
- `CTRL.CLK_GATE_EN` — clock-gating policy bit;
- `GAIN.VALUE` — signed datapath coefficient;
- `CFG_STATUS.BUSY` — synchronized status returned to configuration domain;
- `CFG_STATUS.OVERFLOW` — synchronized overflow indication.

**DSP-domain map** (`<top>_dsp.hjson`):

- `DSP_CTRL.OP` — selects operation;
- `DSP_CTRL.SATURATE` — saturation enable;
- `THRESHOLD.VALUE` — threshold comparison value;
- `RESULT.VALUE` — latest result;
- `DSP_STATUS.VALID`;
- `DSP_STATUS.ABOVE_THRESHOLD`;
- `DSP_STATUS.FIFO_EMPTY`;
- `DSP_STATUS.OVERFLOW`.

This division is not only documentation. It makes clock ownership visible early, which later feeds CDC/RDC analysis and verification planning.

### 3.3 Generated register RTL

The generated register RTL converts bus transactions into typed hardware-facing structures. The authored datapath should consume those structures instead of manually decoding addresses.

Natural-language pseudocode:

```text
on TL-UL write:
  decode address
  apply software-access semantics
  update only legal writable fields
  expose q / qe / related hardware signals

on TL-UL read:
  decode address
  select software-visible value
  include hardware-owned status fields where required
  return protocol response
```

This gives three practical benefits:

1. address decode is not handwritten repeatedly;
2. software-visible semantics are generated from the same specification used by documentation;
3. the primitive register semantics can be formally verified independently of the surrounding datapath.

### 3.4 Python regmap and test interface

`design/regs.py` parses the same HJSON with the bundled `reggen` implementation and creates Python helpers for register and field names, masks, values, reads and writes.

The important abstraction is not “Python controls RTL”; it is that **tests no longer need to duplicate numeric CSR addresses and masks**.

For example, a test can logically express:

```text
write CFG.CTRL.ENABLE = 1
write CFG.GAIN.VALUE  = 0x0100
later read DSP.DSP_STATUS and compare only VALID/OVERFLOW bits
```

and the generated regmap turns that intent into the numeric values consumed by the simulator-facing vector files.

### 3.5 C/software collateral

The driver generation path derives software-facing register constants and helper collateral from the same map. FlexSoC therefore keeps the hardware/software contract tied to HJSON rather than manually synchronized header files.

---

## 4. RTL scaffold: the multi-clock example

FlexSoC can generate a starter RTL structure. This is an architectural scaffold, not a replacement for authored RTL.

The multi-clock scaffold is particularly useful because it demonstrates the kinds of structures the downstream analysis is designed to recognize.

### 4.1 Domain structure

The representative scaffold has:

```text
cfg domain          rx domain             dsp domain
-----------         ---------             ----------
CSR control ──────► synchronized enable
     │                                      ▲
     ├────────────────────────────────────► synchronized enable/reset/gate control
     │                                      │
     │             async FIFO ──────────────┤
     │            rx → dsp data             │
     │                                      ▼
     └◄──────────────────────── synchronized status
```

### 4.2 Single-bit CDC controls

Single-bit level controls such as enable, soft-reset request and clock-gate enable use explicit synchronizer primitives:

```systemverilog
prim_flop_2sync #(.Width(1)) u_enable_dsp_sync (
  .clk_i  (dsp_clk_i),
  .rst_ni (dsp_rst_ni),
  .d_i    (cfg_enable),
  .q_o    (enable_dsp)
);
```

The important design rule is not the exact module syntax; it is that the crossing structure is explicit and recognizable:

- asynchronous source level;
- first receiving flop;
- second stabilization flop;
- no combinational logic inserted between synchronizer stages;
- controlled fanout of the metastability-exposed first stage.

### 4.3 Multi-bit configuration policy

A multi-bit bus cannot safely be treated as N unrelated two-flop synchronizers. The starter therefore uses a conservative policy for `GAIN`: update the DSP-domain copy only while the datapath is disabled.

```text
if DSP domain is in reset:
  gain_dsp = reset value
else if datapath is disabled:
  capture configuration bus
else:
  hold the previously captured coherent value
```

This is a scaffold policy, not a universal CDC solution. A production design may instead use a handshake, shadow register, toggle protocol, Gray code, asynchronous FIFO, or another coherency mechanism.

### 4.4 RX-to-DSP asynchronous FIFO

The generated example crosses streaming data with `prim_fifo_async`:

```text
RX clock side:
  valid + ready
  pack sample/coeff into FIFO write data

DSP clock side:
  FIFO read valid
  consume only when DSP pipeline can accept
  separate read-domain ready
```

The async FIFO is important because it demonstrates a coherent multi-bit protocol. CDC analysis should not classify its payload as a collection of independent unsafe bits; instead it should recognize that the burden of proof belongs to the FIFO pointer/storage protocol.

### 4.5 Clock-gating intent

The scaffold instantiates a clock-gating primitive so the intended gate control is visible to lint/timing review. The generated datapath intentionally keeps computation on the ungated DSP clock until the timing/GLS constraints for a fully gated implementation are intentionally adopted.

That distinction is valuable:

```text
architectural intent exists
≠
clock gating is silently assumed safe everywhere
```

---

## 5. Ordered RTL elaboration and filelists

Before any analysis, FlexSoC creates ordered common/IP filelists. This stage is easy to overlook but important: every downstream tool must see a compatible hierarchy, package order and include-path context.

Conceptually:

```text
collect common packages/primitives
+ collect IP RTL
+ resolve SystemVerilog dependencies with Slang
+ emit ordered filelists
→ reuse the same reachable design in lint, synthesis, formal and analysis
```

This reduces “tool A saw a different RTL universe than tool B” failures.

---

## Part II — Pre-synthesis verification

## 6. RTL linting: Slang + Verilator

> **Terminology note:** the current FlexSoC HDL lint flow uses **Slang and Verilator**, not ESLint. ESLint is a JavaScript/TypeScript linter; it is not part of this RTL flow.

The default ordering is deliberate:

```text
Slang first
→ SystemVerilog parsing/type checking/static analysis
→ hierarchy/language diagnostics

Verilator second
→ independent HDL lint implementation
→ additional structural/style warnings
```

Using two frontends provides useful diversity. A construct accepted by one parser may still expose a width, connection or coding issue in the other.

### 6.1 Slang role

Slang performs SystemVerilog compilation and static analysis. In FlexSoC it is run in lint mode with the selected top and synthesis-oriented definitions.

It is particularly useful for:

- syntax and language correctness;
- type checking;
- invalid or ambiguous expression use;
- port width truncation/expansion;
- unused declarations;
- unconnected ports and empty connections;
- inferred latch diagnostics;
- elaboration consistency.

### 6.2 Verilator role

Verilator is invoked with `--lint-only --sv -Wno-fatal` as the base lint behavior. `-Wno-fatal` means warnings remain visible without automatically terminating the run solely because a warning exists; FlexSoC can then collect and classify them.

Typical diagnostics include:

- `LATCH` — an incomplete combinational assignment can infer state;
- `UNDRIVEN` — signal/port has no driver;
- `WIDTH`, `WIDTHEXPAND`, `WIDTHTRUNC` — width mismatch or conversion;
- `PINMISSING`, `PINCONNECTEMPTY`, `PINNOCONNECT` — connection problems;
- `UNUSEDSIGNAL`, `UNUSEDPARAM` — dead or unused declarations;
- broader `-Wall` diagnostics for the full lint stage.

### 6.3 Focused lint suite

`fx lint_suite` runs both tools through focused categories:

| Category | What FlexSoC is asking |
| --- | --- |
| `all` | Is the reachable RTL generally lint-clean? |
| `latch` | Did combinational code accidentally infer storage? |
| `undriven` | Is anything observed without a driver? |
| `width` | Are there truncation/extension/port width mismatches? |
| `unconnected` | Are instantiated ports missing or intentionally empty? |
| `unused` | Is logic/configuration present but not actually used? |

The raw logs are preserved so an engineer can distinguish a legitimate primitive/library warning from an IP-owned warning. The goal is not “zero warnings at all costs”; it is **zero unexplained warnings in design-owned RTL**.

### 6.4 What lint does not prove

Lint cannot prove:

- that an asynchronous crossing is safe;
- that protocol behavior is correct;
- that timing will close;
- that expected output values are correct;
- that synthesis preserves behavior.

Those are separate gates by design.

---

## 7. CDC/RDC: structural clock/reset-domain analysis

FlexSoC implements a technology-neutral structural CDC/RDC pass rather than relying on text-pattern matching.

### 7.1 Extraction stage

`setup_cdc_rdc` creates a flattened Yosys JSON view using the Slang/Yosys frontend:

```text
read ordered RTL
→ hierarchy / process lowering
→ optimization sufficient for structural analysis
→ flatten
→ write JSON
→ build FlexSoC DesignIR
```

`DesignIR` captures:

- top-level ports;
- sequential elements;
- clock assignment;
- reset assignment and polarity;
- combinational/sequential dependency edges;
- source/destination domains.

This is intentionally **pre-technology**. The purpose is to reason about architectural clock/reset intent, not library-cell implementation details.

### 7.2 Scalar CDC synchronizers

For a scalar crossing, FlexSoC tries to recognize an N-flop synchronizer chain and then checks its structural integrity.

Checks include:

- recognized source and destination clock domains;
- enough sequential stages;
- no combinational logic before the receiving synchronizer stage where it would invalidate the intended structure;
- no combinational logic between synchronizer stages;
- first-stage fanout discipline;
- consistent reset semantics across stages;
- declared clock relationship.

A healthy structure is classified as `nff_synchronizer` and can be `SAFE` or `WARN` depending on evidence and remaining sampling assumptions.

A crossing without a recognized protection mechanism becomes `missing_synchronizer` / error-class evidence.

### 7.3 Multi-bit CDC is intentionally stricter

FlexSoC does **not** declare a multi-bit crossing safe merely because every bit passes through a scalar synchronizer.

Possible classifications include:

- `qualified_multibit` — data is associated with a synchronized control; requires stability/polarity/sampling proof;
- `multibit_nff_bus` — bitwise synchronizers exist, but coherence is not proven;
- `multibit_nff_integrity` — synchronizer structure itself is broken;
- `unsynchronized_multibit` — no recognized coherency mechanism;
- `async_fifo_candidate` — paired cross-domain structures resemble an asynchronous FIFO and create explicit proof obligations;
- `closed_loop_handshake` — synchronized forward/back control paths resemble a request/ack protocol;
- `synchronized_reconvergence` — independently synchronized signals reconverge and may create coherent-sampling hazards.

Typical obligations are written explicitly, for example:

```text
prove data is stable before synchronized control
prove data remains stable after synchronized control
prove Gray pointer changes are Hamming-1
prove async-FIFO full/empty pointer safety
prove request/ack liveness and ordering
prove reconvergent controls are coherent at destination
```

The key concept is that a CDC tool should tell the engineer **what must still be proven**, not only print a crossing count.

### 7.4 Reset-domain crossing checks

RDC analysis looks for state interactions involving different reset domains.

Current classifications include:

- `rdc_via_data_synchronizer` — reset interaction protected by a recognized data synchronizer;
- `rdc_control_candidate` — a control protocol may block unsafe reset effects, but needs proof;
- `rdc_via_multibit_protocol` — reset interaction is embedded in a multi-bit CDC protocol;
- `uncontrolled_rdc` — state can interact across different reset domains without recognized protection;
- `reset_synchronizer` — recognized reset synchronization structure;
- `async_reset_release` — asynchronous assertion/release pattern requires review/proof of safe deassertion;
- `reset_sequence_or_control_required` — multiple-reset architecture needs explicit sequencing/blocking intent.

### 7.5 Setup and glitch checks

The same analysis also checks setup quality around the declared clock/reset model:

- sequential element without a declared clock domain → error;
- reset polarity inconsistent with declaration → error;
- undeclared clock relationship → warning;
- multiple reset domains attached to one clock domain → review;
- combinational clock path → error;
- combinational reset path → error.

### 7.6 PASS, REVIEW and obligations

A clean structural count is not necessarily a PASS. For example, one safe-looking asynchronous reset release may legitimately keep the overall stage at `REVIEW` until the reset architecture is formally or manually justified.

This is why `fx check` can show:

```text
CDC / RDC   REVIEW
```

even when raw CDC errors are zero.

---

## 8. Functional verification: one scenario language, two testbench backends

FlexSoC uses the same scenario data for SystemVerilog and cocotb. This is a strong architectural decision: the verification intent is independent of the testbench programming language.

### 8.1 UVM-like mental model

The generated environment is **not full UVM**, but its responsibilities map naturally onto familiar UVM concepts:

| UVM-style responsibility | FlexSoC equivalent |
| --- | --- |
| sequence / sequence item | scenario plus `config.regs`, `data_in.vec`, `data_out.vec` rows |
| sequencer | cycle-indexed vector scheduler / scenario ordering |
| driver | SV vector/TL-UL tasks or cocotb vector/register driver |
| monitor | SV output monitor or cocotb `LatencyMonitor` |
| scoreboard | expected-value comparison from `data_out.vec` and CSR reads |
| register model | generated Python regmap aliases/masks plus TL-UL register driver |
| test | scenario directory such as `smoke`, `corners`, `reconfig` |

What it intentionally does **not** implement is the complete UVM factory, phase mechanism, class hierarchy, objections, TLM infrastructure, etc.

The useful idea is simpler:

```text
scenario intent
→ serialize operations into a small deterministic DSL
→ run exactly the same scenario through SV and cocotb
→ compare outputs/register state against the same expected data
```

### 8.2 Scenario catalogue

The generated shared scenarios currently include examples such as:

- `smoke` — basic functional + CSR transport;
- `corners` — simple 0/1 and boundary-style values plus CSR checks;
- `random_seed_1`, `random_seed_2` — deterministic random stimulus;
- `reconfig` — runtime configuration change;
- `auto_toggle` — broad toggle/activity stimulus used for coverage/power;
- N-clock-specific design scenarios such as MAC, absolute-difference and energy operations.

The generated examples are starters. Real IP qualification should replace “interesting-looking vectors” with requirement-driven scenarios.

### 8.2.1 Relationship to the reference/model layer

The model/scenario layer is used to **prepare verification intent**, not to hide expected behavior inside the simulator process. A typical path is:

```text
model + scenario definition
→ calculate/configure expected transactions and results
→ serialize them into config.regs / data_in.vec / data_out.vec
→ SV and cocotb consume those same files independently
```

That separation is useful because the gate-level simulator does not need to import the high-level model in order to know what to check. The expected contract is already materialized as deterministic test data, so exactly the same scenario can be replayed against RTL, post-synthesis netlists, and routed final netlists.

### 8.3 `config.regs`: initial register programming

`config.regs` describes initial CSR writes.

Logical format:

```text
<REGISTER> <DATA> [MASK] [WAIT_CYCLES] [NOTE]
```

For example:

```text
CFG.CTRL 0x00000001 0x00000001 1 enable_datapath
CFG.GAIN 0x00000100 0x0000ffff 1 program_gain
```

The register names are resolved through the generated regmap instead of being duplicated as numeric addresses in the test.

### 8.4 `data_in.vec`: interface stimulus and runtime control

Ordinary signal drive:

```text
<CYCLE> <SIGNAL> <VALUE> [<SIGNAL> <VALUE> ...]
```

Example:

```text
0 valid_i 0 data_i 0x00000000 coeff_i 0x00000000
4 valid_i 1 data_i 0x00000010 coeff_i 0x00000003
5 valid_i 0
```

Multiple signal/value pairs on one row are applied as one cycle-indexed batch.

Runtime commands extend the same file:

```text
<CYCLE> @write <REGISTER_OR_ADDRESS> <DATA> [MASK]
<CYCLE> @cfg   <PATH_TO_CONFIG.REGS>
<CYCLE> @reset [DOMAIN_OR_RESET] <CYCLES>
```

This is one of the useful FlexSoC properties: **the same scenario can combine datapath stimulus and software-visible control changes**.

For example:

```text
0  @write CFG.CTRL 0x1 0x1
4  rx_valid_i 1 rx_sample_i 0x0123 rx_coeff_i 0x0040
12 @write DSP.DSP_CTRL 0x2 0x3
20 @reset dsp 2
```

### 8.5 `data_out.vec`: output checks and register reads

Fixed-cycle check:

```text
<CYCLE> <SIGNAL> <EXPECTED> [<SIGNAL> <EXPECTED> ...]
```

Register read/check:

```text
<CYCLE> @read <REGISTER_OR_ADDRESS> <EXPECTED> [MASK]
```

Guarded-valid check:

```text
<VALID_SIGNAL> <SIGNAL> <EXPECTED> [<SIGNAL> <EXPECTED> ...]
```

The guarded form is useful when output timing is event-oriented rather than a rigid absolute cycle. Each assertion of the valid signal consumes the next expected row.

### 8.6 SystemVerilog backend

The generated SV testbench includes responsibilities analogous to:

```text
initialization
→ clocks/resets
→ TL-UL register access helpers
→ apply config.regs
→ parse and drive data_in.vec
→ monitor fixed-cycle / valid-guarded outputs
→ issue @read transactions
→ compare expected values
→ count errors / finish
```

The vector driver reports the signal it drives; the monitor reports PASS/FAIL comparisons; register tasks report TL-UL accesses. This makes the same test useful both as regression and as a debugging transcript.

### 8.7 cocotb backend

The cocotb environment consumes the same files and has the same conceptual responsibilities:

- register driver / TL-UL proxy;
- vector driver;
- runtime reset and configuration callbacks;
- `LatencyMonitor` for output checking;
- optional register-reader callback for `@read` expectations;
- waveform generation through the selected simulator.

`LatencyMonitor` loads expected fixed-cycle rows and guarded-valid rows, then performs masked register comparisons and signal comparisons.

The value of having both SV and Python implementations is not duplication for its own sake. It provides two independently implemented execution backends for the same scenario contract.

### 8.8 Coverage

Functional simulation is accompanied by HDL coverage collection. FlexSoC consolidates coverage by scope and type, including categories such as:

- line;
- toggle;
- expression;
- branch;
- FSM/user coverage when provided.

The report distinguishes design-owned RTL from register/common/other infrastructure. That prevents a large generated library from hiding weak coverage in the actual IP.

Coverage is evidence of exercised structure, not proof of correctness. Formal and requirement-driven scenarios remain separate gates.

---

## 9. Formal verification

FlexSoC formal verification has two complementary suites:

```text
CSR formal             design/property formal
----------             ----------------------
automatically derived  starter + designer-owned assertions/covers
from generated reg RTL from the actual IP architecture
```

Each suite runs bounded checks, proof and cover.

### 9.1 Engines and default structure

Current default configuration is approximately:

```text
BMC:
  engine  = smtbmc bitwuzla
  depth   = 30
  append  = 5

PROVE:
  engine  = abc pdr
  depth   = 20 framework context

COVER:
  engine  = btor btormc
```

The exact solver choice is a generated SymbiYosys configuration rather than hardcoded property syntax.

For multi-clock designs, generated SBY files enable `multiclock on`.

### 9.2 Why BMC comes before proof

A useful practical sequence is:

```text
BMC
→ catch shallow bugs quickly and emit short counterexamples
→ if clean, run unbounded/inductive proof engine
→ separately run cover to demonstrate useful states are reachable
```

A proof that passes while all interesting behavior is unreachable is not sufficient, which is why cover is a first-class stage.

### 9.3 Automatic CSR formal

The generated CSR suite binds checkers directly to the register primitives.

The current checkers cover the semantics of primitives including:

- `prim_subreg_arb`;
- `prim_subreg`;
- `prim_subreg_ext`.

They check concepts such as:

- software write enable and write-data arbitration;
- correct `q`/effective value behavior;
- reset value behavior;
- previous-cycle update consistency;
- external-register read/write handshake semantics;
- software access modes including RW/RO/WO and write-one/clear/set/read-clear style behaviors represented by the primitive parameters;
- MuBi-related primitive semantics where applicable.

The CSR cover suite also asks the solver to reach writes to software-writable register primitives. This is useful because it checks that the generated register interface is not only internally consistent but actually reachable under the formal model.

### 9.4 Generated design-property starters

For single-clock scaffolds, starter assertions tie architectural outputs to pipeline state and verify reset-cleared outputs.

For the multi-clock scaffold, generated assertions check structural behavioral contracts such as:

```text
rx_ready == enable_rx AND fifo_write_ready

fifo_read_ready ==
  enable_dsp AND fifo_read_valid AND pipeline_can_accept

dsp_clock_active ==
  enable_dsp AND (gate_disabled OR pending_work)

if DSP reset or software reset was asserted:
  output valid/result/status return to reset-safe values
```

Generated covers exercise states such as:

- configuration enable reached;
- RX valid/ready handshake;
- asynchronous FIFO data becoming readable;
- DSP output valid;
- DSP output valid and downstream ready simultaneously.

### 9.5 Designer ownership

The generated property scaffold is created only when absent. After creation it becomes designer-owned and is not silently overwritten.

That is intentional: meaningful formal properties must evolve with the architecture rather than being regenerated from a generic template forever.

---

## Part III — Synthesis and logical equivalence

## 10. Canonical timing intent: one authored SDC, small derived views

FlexSoC keeps timing intent in one designer-owned file: `constraints/design.sdc`. Backend-specific formats are derived collateral, not competing sources of truth.

```text
bootstrap domain/reset settings
        ↓
fx sdc
        ↓
constraints/design.sdc
        │
        ├─ functional TB: clock waveform/phase/jitter view
        ├─ CDC/RDC: clocks + clock relationships
        ├─ Yosys/ABC: period target + derived abc.constr drive/load
        ├─ ORFS/OpenROAD: implementation timing input
        └─ OpenSTA: complete timing contract
```

This split is intentional: different engines need different subsets, but the engineer authors the timing assumptions once.

### 10.1 Bootstrap topology versus authored timing

A new project starts from:

- `N_CLOCKS`;
- `CLOCK_DOMAINS`;
- `CLOCK_RELATIONSHIPS`;
- per-domain clock signal, reset signal, nominal period, and reset polarity.

Those settings are sufficient to scaffold the first SDC and retain reset-domain metadata. They are not intended to remain a parallel timing database. After structural RTL/lint are clean, initialize the contract:

```bash
fx sdc --force
```

From that point clock period/waveform, generated clocks, latency, uncertainty, transition, clock groups, I/O timing, drive/load, and timing exceptions are authored in `constraints/design.sdc`. Reset ownership/polarity remains separate because ordinary SDC does not model it.

### 10.2 What the SDC scaffold contains

The scaffold is organized so that missing design decisions are visible rather than hidden:

1. primary clocks;
2. generated clocks;
3. clock source latency, setup/hold uncertainty, and transition;
4. clock relationships;
5. input min/max delay;
6. input drive or optional driving cell;
7. output min/max delay;
8. output load;
9. commented false-path and multicycle examples;
10. optional design-rule constraints.

False paths and multicycle paths are never guessed. They are architectural assumptions and must be reviewed as such.

### 10.3 Functional and CDC consumers

`backend/signoff/sdc.py` parses only the small active-command subset needed outside STA. It is deliberately not a general SDC implementation.

Functional SV and cocotb use `create_clock -period/-waveform`, `set_clock_latency -source`, and `set_clock_uncertainty`. The first rising edge is the waveform rise plus source latency; duty cycle comes from the waveform. Later rising edges receive bounded uniform jitter of `±max(setup_uncertainty, hold_uncertainty)` at 1 ps resolution. The existing run `SEED` selects the same xorshift32 sequence in both backends, so phase, relative skew, non-50% duty cycle, and jitter are reproducible. `set_clock_transition` stays an STA/electrical constraint, not an analog simulation slew model.

CDC/RDC reads clock relationships from the same SDC and combines them with reset ownership/polarity from bootstrap metadata. Therefore a clock relationship is not declared once for CDC and again for timing.

### 10.4 What synthesis actually receives

Yosys/ABC does not need the complete SDC timing graph. FlexSoC derives only the mapping information ABC can use effectively:

```text
RTL/SystemVerilog
+ target Liberty
+ optimization strategy
+ clock optimization target
+ abc.constr derived from SDC drive/load
        ↓
Yosys + ABC technology mapping
```

The generated `abc.constr` is a small machine-owned adapter. Depending on the authored SDC/environment it contains the ABC-compatible input-driving and output-load assumptions. It never becomes the owner of timing intent.

### 10.5 `abc.constr` is not an SDC

ABC's `-constr` input is intentionally narrow. It does not represent generated clocks, asynchronous clock groups, full I/O timing, false/multicycle paths, clock propagation, or parasitics. Those semantics remain in `design.sdc` and are consumed by engines that understand them.

This avoids duplicated timing semantics and prevents synthesis-specific approximations from becoming a second constraint database.

### 10.6 STA and implementation use the same authored SDC

Pre-implementation timing uses:

```text
FlexSoC mapped netlist
+ selected Liberty timing views
+ constraints/design.sdc
→ OpenSTA
```

Implementation receives the mapped netlist and the same authored SDC:

```text
ORFS config.mk
  SYNTH_NETLIST_FILES := FlexSoC mapped netlist
  SDC_FILE             := constraints/design.sdc
```

ORFS/OpenROAD may also emit `6_final.sdc` as an implementation artifact, but FlexSoC does not make that file a new design-intent owner. Routed FlexSoC sign-off keeps the authored SDC and changes the physical timing model instead:

```text
final routed netlist (6_final.v)
+ constraints/design.sdc
+ routed SPEF (6_final.spef)
+ propagated clocks
→ post-route OpenSTA
```

The stage therefore changes netlist, parasitics, and clock propagation while preserving one timing contract.

### 10.7 Correct mental model

```text
bootstrap clock/reset topology
          ↓
   constraints/design.sdc
          │
    ┌─────┼───────────────┐
    │     │               │
    ▼     ▼               ▼
functional CDC/RDC   synthesis adapter
   TB                    abc.constr
    │                      │
    └──────────┬───────────┘
               ▼
          mapped netlist
               │
       ┌───────┴────────┐
       ▼                ▼
 pre-route STA      ORFS/OpenROAD
 design.sdc          design.sdc
                         │
                         ▼
                  final netlist + SPEF
                         │
                         ▼
                  post-route STA
                    design.sdc
```

One authored contract, multiple deliberately small consumers.

---

## 11. Synthesis with Yosys and ABC

FlexSoC owns synthesis. ORFS receives the already mapped FlexSoC netlist instead of running a second independent synthesis flow.

### 11.1 Inputs

ASIC synthesis consumes:

- ordered RTL filelists;
- selected top;
- target Liberty library;
- clock optimization target derived from the authored SDC where applicable;
- ABC drive/load collateral derived from the same SDC;
- PDK tie cells and minimum-buffer definitions when available;
- optimization mode: `area`, `delay`, or `none`.

### 11.2 Generated files

`syn/syn.py` generates the synthesis workspace, including:

```text
synth.ys / synth_sv.ys   Yosys synthesis program
abc.constr               ABC I/O timing assumptions
area.abc                 area-oriented ABC recipe, when selected
delay.abc                delay-oriented ABC recipe, when selected
```

> The file is **`abc.constr`**, not `.const`. Yosys passes it to ABC with `-constr`.

### 11.3 What `abc.constr` means

The ABC constraint file is deliberately small and **must not be confused with the canonical SDC**. It can contain:

```text
set_driving_cell <PDK_INPUT_DRIVER_CELL>
set_load 10
```

Conceptually:

- `set_driving_cell` models the type of cell driving primary inputs;
- `set_load` models output load in femtofarads for ABC timing decisions.

FlexSoC does not silently inject a SKY130-specific driver cell into another PDK. The active PDK profile supplies a driving cell when it has one.

### 11.4 Structure of the `.ys` synthesis script

The generated Yosys program is best understood as a sequence of representation changes and validation boundaries:

```text
1. Read target Liberty as library cells
2. Read/elaborate SystemVerilog RTL with Slang/Yosys frontend
3. Resolve hierarchy and synthesize generic logic without ABC final mapping
4. Save generic RTLIL checkpoint
5. Prepare technology FF mapping with dfflibmap
6. Save FF-prepared checkpoint
7. Map combinational logic through ABC
8. Save post-ABC checkpoint
9. Map prepared FF types to final library cells
10. check -assert
11. split/clean nets and insert tie/min-buffer cells when required
12. check -assert -mapped
13. emit statistics
14. write final mapped Verilog + JSON
```

The intermediate RTLIL checkpoints are not decorative. They make synthesis/equivalence failures easier to localize to the generic, FF-mapping, ABC or cleanup boundary.

### 11.5 Flip-flop mapping and combinational mapping

Yosys technology mapping is intentionally split:

```text
dfflibmap
→ map abstract sequential cells to target-library FF possibilities

ABC
→ optimize/map combinational logic to Liberty cells

dfflibmap -map-only
→ finalize the prepared sequential technology mapping
```

This follows the standard Yosys technology-mapping model: sequential and combinational mapping have different constraints and are easier to reason about separately.

### 11.6 Area-oriented ABC recipe

The current `area.abc` flow performs a portable sequence around AIG restructuring and area mapping:

```text
strash
→ dch
→ balance
→ rewrite / refactor / rewrite -z
→ balance / dch
→ map -a
→ topology cleanup
→ downsize
→ static timing estimate
→ stats
```

Intent:

- simplify and restructure logic;
- prefer area-aware mapping;
- recover cell area with downsizing where possible;
- still inspect timing through ABC's timing estimate.

### 11.7 Delay-oriented ABC recipe

The current `delay.abc` flow is biased toward timing:

```text
strash
→ balance
→ rewrite / refactor
→ dch
→ map with delay target context
→ topology cleanup
→ upsize
→ buffer
→ static timing estimate
→ stats
```

Yosys passes a target with `-D <period_ps>` for delay-oriented mapping.

Intent:

- balance logic depth;
- map with timing pressure;
- use cell upsizing and buffering to improve critical delay;
- accept that area may increase.

### 11.8 `none` mode

The `none` optimization mode uses Yosys/ABC's simpler direct Liberty mapping with the clock-period delay target rather than a custom area/delay script.

### 11.9 What FlexSoC does not currently implement: strategy portfolio

Current FlexSoC exposes `area`, `delay`, and `none`. It does **not** currently run a large automatic portfolio of area/delay scripts.

LibreLane is a useful reference for a future exploration layer. It exposes multiple `AREA 0..3` and `DELAY 0..4` ABC strategies and can run synthesis exploration because there is no universal best ABC recipe for every design.

A future FlexSoC extension could therefore do:

```text
for strategy in selected portfolio:
  synthesize
  run quick STA / area extraction
  record area, cell count, WNS/TNS proxy

rank Pareto candidates
→ choose one explicit strategy
→ rerun the normal qualified downstream flow
```

That is a **roadmap idea**, not a current feature.

### 11.10 Final synthesis outputs

The key outputs are:

- `<top>_synth.v` — mapped implementation netlist;
- `<top>_synth.json` — machine-readable mapped design;
- RTLIL checkpoints;
- synthesis log;
- warnings/errors extracts;
- Liberty-based cell/area statistics.

The mapped netlist is the exact logical input handed to equivalence and physical implementation.

---

## 12. RTL ↔ synthesis equivalence with EQY

Synthesis optimization is allowed to radically change structure. Equivalence answers a different question than simulation:

> For all allowed inputs/states represented by the equivalence model, does the mapped synthesized netlist implement the same externally observable behavior as the RTL specification?

### 12.1 Gold and gate sides

```text
gold:
  authored RTL
  read through Slang/Yosys formal frontend

gate:
  mapped synthesis netlist
  plus target cell semantics from Liberty or functional cell model
```

Assertions are ignored while reading the design implementation for EQY; the objective is behavioral equivalence of the design, not re-proving the property suite.

### 12.2 Technology-cell semantics

The gate netlist contains real standard cells, so EQY must know their Boolean behavior.

FlexSoC selects an appropriate approach per technology:

- functional standard-cell Verilog when safe for the Yosys formal frontend;
- Liberty functional semantics as fallback;
- SKY130-specific handling for clock-gating cells where needed;
- IHP currently prefers Liberty where its aggregate Verilog models contain `specify` constructs unsuitable for the Yosys EQY frontend.

### 12.3 Protocol-aware output normalization

A raw bus comparison can create false complexity when protocol bits are don't-care outside valid response conditions.

For the TL-UL response shape used by the scaffold, FlexSoC can create canonical witness outputs such as:

```text
handshake
control/status witness
data witness
metadata witness
```

and normalize fields that are protocol don't-cares when response-valid/error conditions make them irrelevant.

This is not “weakening equivalence.” It is making the compared contract match the protocol semantics rather than comparing meaningless raw bits.

### 12.4 Reset normalization

The generated flow can normalize reset for a small configured number of cycles before comparison. This helps align implementation state where technology mapping changes the exact representation of resettable storage.

### 12.5 Single-clock versus multi-clock strategy

For a single clock, FlexSoC can use a portfolio including SAT, PDR and SMT-oriented strategies.

For multi-clock designs, SAT strategy is disabled and the generated flow uses approaches better suited to the multi-clock formal model such as PDR/SMT.

`async2sync` is applied only in the single-clock case; FlexSoC avoids pretending genuinely asynchronous multi-clock behavior is one synchronous domain.

### 12.6 What is proved

The EQY stage qualifies:

```text
RTL
↕ behaviorally equivalent
mapped post-synthesis netlist
```

It does **not** prove:

- routed layout equivalence;
- analog timing behavior;
- physical DRC/LVS;
- that the SDC is complete;
- that the design meets timing.

Those are deliberately separate gates.

---

## Part IV — Pre-implementation sign-off

## 13. OpenSTA setup shared by sign-off stages

FlexSoC uses one OpenSTA script-generation framework for pre-implementation and post-implementation analysis. The stage changes the timing model, not the fundamental analysis structure.

Common initialization is conceptually:

```text
read corner Liberty files
+ read macro Liberty files if present
→ read mapped/final netlist
→ link design
→ read canonical SDC
→ check setup

if post-route:
  read SPEF
  propagate clocks
else:
  no SPEF
  keep clock network ideal
```

That single distinction is central:

| Stage | Clock network | Interconnect model |
| --- | --- | --- |
| post-synthesis | ideal | none |
| post-implementation | propagated | SPEF |

---

## 14. Pre-implementation STA

Pre-implementation STA answers:

> Does the mapped logical design satisfy the timing constraints **before** routed parasitics and a physical clock tree exist?

For each configured corner and setup/hold mode, FlexSoC records:

- WNS/TNS;
- setup/hold or min/max timing checks;
- max slew;
- max capacitance;
- max fanout;
- recovery/removal;
- minimum pulse width / minimum period;
- explicit unconstrained paths;
- violating paths;
- near-critical met paths.

The report writes its timing model explicitly:

```text
clock_network=ideal
interconnect=none
```

An unconstrained path is not treated as a timing PASS simply because it has no negative slack. It is reported separately for engineering review.

---

## 15. Pre-implementation SDF

FlexSoC asks OpenSTA to serialize the linked timing model with:

```text
write_sdf
  include typ value
  deterministic header (no timestamp/version noise)
```

### 15.1 Min / typ / max completeness

OpenSTA 3.1 can leave the `typ` value empty in PVT header triples even when timing-delay typ values are included. The generated Tcl normalizes only those header fields so the SDF is accepted consistently by timing simulators.

### 15.2 Why post-synthesis SDF intentionally has no `INTERCONNECT`

OpenSTA writes an initial SDF `CELL` block containing `INTERCONNECT` entries even when there is no routed SPEF model.

FlexSoC's pre-implementation timing contract is explicitly:

```text
clock = ideal
physical interconnect = none
```

Therefore the generated post-synthesis SDF Tcl removes that initial interconnect-only cell while preserving cell `IOPATH` timing and timing-check information.

This avoids pretending pre-layout wire delay is routed physical delay and avoids simulator-specific problems mapping meaningless pre-layout inter-module paths.

---

## 16. Pre-implementation power estimate

The first power stage is vectorless/activity-assumption based.

Conceptually:

```text
link corner-specific mapped design
→ apply global/input switching activity assumptions
→ OpenSTA power calculation
→ report internal + switching + leakage + total power
```

This provides an early PDK-aware estimate before a placed/routed implementation or workload-derived activity exists.

It is useful for comparison across corners and synthesis strategies, but it is not the final workload power result.

---

## 17. Post-synthesis gate-level verification in context

Although the compact “pre-implementation sign-off” concept can be summarized as STA + SDF + power estimate, FlexSoC also qualifies the mapped netlist dynamically before PnR.

The same functional tests are replayed in gate-level modes:

```text
zero
unit
ff / min SDF
tt / typ SDF
ss / max SDF
```

For post-synthesis SDF modes:

- cell/path delays are annotated;
- physical interconnect delay is intentionally `none`;
- `-ginterconnect` is not required because the SDF interconnect block is removed.

This stage is deliberately before implementation so a dynamic mapped-netlist problem is not discovered only after an expensive PnR run.

---

## Part V — Physical implementation with ORFS/OpenROAD

## 18. FlexSoC-to-ORFS handoff

FlexSoC owns synthesis and timing intent. ORFS is used as a **physical-only implementation controller**.

The generated ORFS `config.mk` therefore points at:

```text
SYNTH_NETLIST_FILES = FlexSoC <top>_synth.v
SDC_FILE             = FlexSoC canonical SDC
PLATFORM             = selected ORFS technology platform
```

Current physical defaults include, among others:

- core utilization around 50%;
- placement density around 0.58;
- timing-driven global placement enabled;
- routability-driven global placement enabled;
- detailed routing iteration limit 64;
- zero extra setup/hold slack margin;
- detailed metrics and clock-skew reporting enabled.

**Important current detail:** the generated FlexSoC config sets `USE_FILL=0`. ORFS/OpenROAD supports metal fill, but FlexSoC does not currently force fill in this flow. A future tapeout policy should decide when fill becomes mandatory and whether post-fill extraction/sign-off is required.

### 18.1 Tool-path determinism

`impl/impl.py` resolves `openroad`, `yosys` and `klayout` from the active FlexSoC `PATH` and passes those paths to ORFS.

That prevents a stale host variable such as `OPENROAD_EXE=/some/old/path` from silently overriding the toolchain selected by the current environment/container.

---

## 19. OpenROAD implementation stages

ORFS presents the implementation as six broad stages:

```text
1 import
2 floorplan
3 placement
4 CTS
5 routing
6 finish
```

FlexSoC logs those checkpoints and records the final implementation artifacts.

### 19.1 Import and database setup

At import, OpenROAD loads the platform technology/library data, the mapped netlist and the timing constraints into OpenDB/OpenSTA-backed internal representations.

The important contract is:

```text
logical design = FlexSoC mapped netlist
constraints    = FlexSoC canonical SDC
technology     = ORFS platform
```

No second independent synthesis should change the logical implementation here.

### 19.2 Floorplan

Floorplanning establishes the geometry within which every later physical decision must fit.

Typical responsibilities include:

- die/core dimensions from utilization/area policy;
- standard-cell rows and placement sites;
- routing layer context;
- IO/core pin placement policy;
- tap/welltie/endcap style structures according to platform flow;
- macro regions when hard macros exist;
- early congestion and physical feasibility assumptions.

Natural-language pseudocode:

```text
estimate required standard-cell area
→ choose core dimensions from target utilization/aspect ratio
→ create rows/sites
→ reserve blockages / macro regions / boundaries
→ place or constrain top-level pins
→ make floorplan legal for power and placement stages
```

### 19.3 PDN generation: power before standard-cell placement

Power distribution is not something added after routing as decoration. The PDN is established from platform policies so placement/routing operate in a floorplan that already contains the intended power infrastructure.

OpenROAD's PDN generator applies policies such as:

- power/ground nets;
- layers used for rails/straps;
- stripe widths;
- stripe pitches/spacing;
- via connections between grid layers;
- std-cell grid and macro-oriented grids where applicable.

Conceptually:

```text
platform power policy
→ std-cell rails
→ vertical/horizontal straps
→ via connections
→ power grid occupying real routing resources
→ later cells are placed/routed around that physical reality
```

This ordering is essential for realistic congestion and IR analysis.

### 19.4 Global placement

OpenROAD global placement is based on RePlAce-style analytic nonlinear placement.

At a high level, the placer treats placement similarly to an electrostatic optimization problem:

- wirelength pulls connected cells together;
- density forces prevent all cells collapsing into the same area;
- Nesterov optimization iteratively searches for a low-cost placement.

FlexSoC enables both timing-driven and routability-driven behavior.

**Timing-driven placement:**

```text
estimate timing
→ identify low-slack nets
→ increase their placement weight
→ encourage physically shorter/more favorable placement
```

**Routability-driven placement:**

```text
estimate congestion (RUDY / routing demand)
→ identify congested bins
→ inflate effective cell area locally
→ spread cells away from routing hot spots
```

The result is not yet legal site-by-site placement; it is a globally optimized placement solution.

### 19.5 Detailed placement / legalization

Detailed placement converts the global solution into a legal standard-cell layout:

- align cells to rows/sites;
- remove overlap;
- respect cell padding/blockages;
- minimize displacement while maintaining legality.

This is the boundary between “good continuous placement estimate” and “cells have real legal coordinates.”

### 19.6 Timing repair and resizing

OpenROAD's resizer/timing-repair machinery can adjust the implementation around placement/routing estimates using operations such as buffering and gate sizing, subject to the active flow configuration.

The purpose is to correct problems such as:

- excessive transition;
- excessive capacitance/fanout;
- setup/hold pressure;
- long/high-load nets.

This is physical optimization: it changes implementation cells/nets while preserving logical behavior.

### 19.7 Clock-tree synthesis (CTS)

Before CTS, timing analysis conceptually uses ideal clocks. CTS inserts a real clock distribution network.

OpenROAD CTS is based on TritonCTS 2.0 and performs clock-tree construction and buffer insertion with on-the-fly characterization.

At a high level:

```text
collect clock sinks
→ cluster/partition sink geometry
→ choose clock buffer stages
→ build distribution tree
→ balance insertion delay/skew
→ reconnect sinks through real clock buffers/nets
→ repair timing around the new clock network
```

After CTS, clock latency and skew are physical design quantities rather than ideal assumptions.

### 19.8 Global routing

Global routing decides **where routes should broadly travel** through the routing-resource grid rather than assigning every final wire shape immediately.

OpenROAD's global-routing engine is based on FastRoute.

Responsibilities include:

- estimate routing demand/capacity;
- create route guides;
- identify congestion;
- interact with timing/repair flows;
- detect/repair antenna risks where configured, including diode-based repair capability.

### 19.9 Detailed routing

Detailed routing is performed by TritonRoute.

Its major building blocks include:

```text
pin access analysis
→ track assignment
→ initial detailed route
→ DRC-aware search and repair
→ iterative cleanup
```

This is where actual legal wire/via geometry is produced under the technology routing rules represented by the platform.

The generated FlexSoC config allows up to 64 detailed-routing iterations, giving the router room for iterative search/repair.

### 19.10 Antenna handling

Long partially fabricated conductors can accumulate charge during manufacturing and damage gate oxides. The antenna flow therefore checks ratios/rules and can repair violations, for example by adding appropriate diode structures when the platform supports them.

FlexSoC later treats the final ORFS antenna report as physical-sign-off evidence rather than assuming “routing completed” implies antenna-clean.

### 19.11 Finish and extraction

The finish stage produces the implementation artifacts used by downstream sign-off.

The critical FlexSoC artifacts are:

```text
6_final.v      final implementation netlist
6_final.sdc    final implementation constraints
6_final.spef   extracted routed parasitics
6_final.odb    OpenDB database
6_final.gds    final layout stream
```

OpenRCX provides the routed RC extraction used to create SPEF.

Those artifacts define the post-implementation timing model. FlexSoC does not regenerate an unrelated SPEF after ORFS; `6_final.spef` is the canonical routed parasitic artifact.

---

## Part VI — Post-implementation sign-off

## 20. Routed STA: final netlist + authored SDC + SPEF

Post-implementation STA changes the analysis model from ideal/pre-layout to physical/routed while preserving the same timing intent:

```text
read final Liberty corner
→ read 6_final.v
→ link design
→ read constraints/design.sdc
→ read 6_final.spef
→ set clocks propagated
→ analyze setup/hold/electrical constraints
```

ORFS may emit `6_final.sdc` as part of its own result tree, but the FlexSoC timing contract remains `constraints/design.sdc`. A dedicated post-route SDC is used only when an explicit exceptional override is supplied.

The report explicitly records the routed timing model:

```text
clock_network=propagated
interconnect=spef
```

Routed analysis adds SPEF annotation coverage, clock latency/skew, and detailed physical paths. The consolidated public evidence is `signoff/<pdk>/sta/sta.rpt` with machine-readable `sta.json`; scenario-local reports are diagnostic runtime artifacts rather than separate package contracts.

This is the key quantitative distinction from post-synthesis STA: cell delay, routed wire delay and physical clock-tree behavior are analyzed together without changing the authored timing assumptions.

---

## 21. Routed SDF

The post-route SDF is generated from the same linked OpenSTA timing model after SPEF is read and clocks are propagated.

Unlike post-synthesis SDF, FlexSoC **retains `INTERCONNECT` entries**.

Therefore the model is:

```text
Liberty cell delay
+ routed SPEF network parasitics
→ OpenSTA delay calculation
→ SDF IOPATH + INTERCONNECT timing
```

The SDF contains delays, not raw resistance/capacitance values. SPEF is the RC input to timing calculation; SDF is the resulting simulation-delay representation.

---

## 22. Post-implementation GLS

FlexSoC reuses the same functional scenario contract against the final netlist.

Timing modes are:

```text
zero             no SDF
unit             unit-delay style
ff / min         fast-corner SDF
 tt / typ        typical-corner SDF
ss / max         slow-corner SDF
```

For Icarus timing modes, the routed simulation compiles with:

```text
-gspecify
-ginterconnect
-Tmin / -Ttyp / -Tmax
```

`-ginterconnect` is required because the routed SDF contains `INTERCONNECT` paths.

The result JSON explicitly records:

```text
stage=post_pnr
netlist=.../6_final.v
sdf=.../post_pnr/sdf/<corner>/...
interconnect_delays=enabled
```

### 22.1 Strict SDF diagnostics

`SDF_STRICT=1` treats real annotation problems as failures.

Icarus currently emits `TIMINGCHECK not supported` for SDF timing checks it does not implement. FlexSoC records and ignores **only that known capability warning** while preserving true SDF errors as fatal diagnostics.

This means:

```text
unsupported Icarus timing-check feature
→ known limitation, reported

missing cell / bad path / annotation error / incompatible SDF
→ real failure
```

STA remains the authoritative setup/hold/recovery/removal timing checker; GLS exercises the dynamic delayed netlist behavior.

---

## 23. Post-implementation power

FlexSoC has two complementary power views.

### 23.1 Vectorless / assumed-activity power

Same concept as pre-implementation, but now evaluated in the final routed timing/design context.

Useful for:

- corner comparison;
- baseline power sanity;
- consistent report generation even without a workload waveform.

### 23.2 Workload activity power

A qualified GLS workload can provide real switching activity.

Conceptually:

```text
select passing GLS waveform
→ convert FST to VCD when necessary
→ read VCD/SAIF into OpenSTA
→ validate activity annotation coverage
→ report internal/switching/leakage/total power
```

The workload is aligned with the matching timing corner/scenario so a `tt` activity run is correlated with the corresponding sign-off context instead of mixing unrelated artifacts.

---

## 24. Timing / power fusion analysis

Fusion analysis correlates two views of the same implementation context:

```text
timing:
  critical / near-critical paths

power:
  average instance power under selected activity
```

The objective is to answer questions such as:

- are highly active/high-power cells concentrated near timing-critical logic?
- which path instances are both timing-sensitive and power-relevant?
- does a candidate optimization improve one metric while creating pressure in the other?

It is **correlation**, not a full path-energy transient analysis. FlexSoC keeps that distinction explicit.

---

## Part VII — Physical sign-off

## 25. Why physical sign-off is separate from “PnR completed”

A router reaching the finish stage proves that a layout was constructed. It does not automatically prove every final manufacturing check is clean.

FlexSoC therefore has a dedicated `fx physical_signoff` stage after post-implementation analysis.

Current flow:

```text
ORFS implementation already produced route/final artifacts
→ explicitly run ORFS `drc` and `lvs` targets
→ collect route DRC
→ collect antenna
→ collect final GDS DRC
→ collect LVS
→ collect IR/PDN analysis
→ classify PASS / REVIEW / FAIL
```

FlexSoC does not implement its own DRC or LVS engine. It orchestrates and qualifies the ORFS/platform checks.

---

## 26. Route DRC

The detailed router produces `5_route_drc.rpt`.

FlexSoC currently treats non-empty violation entries as a failure.

This check answers:

> Is the detailed routed geometry clean according to the router's in-flow DRC engine?

It is useful but not identical to final GDS DRC; both are retained.

---

## 27. Antenna sign-off

FlexSoC reads the ORFS `antenna.log` and extracts final net/pin violation counts.

Qualification:

```text
0 net violations AND 0 pin violations → PASS
positive violation count              → FAIL
unrecognized/missing report           → REVIEW
```

This prevents antenna repair from being assumed successful merely because the route target returned zero.

---

## 28. Final GDS DRC

FlexSoC explicitly asks ORFS to run its `drc` target on the final layout and collects:

- `6_drc.lyrdb`;
- `6_drc_count.rpt`.

Qualification:

```text
violation count == 0 → PASS
violation count > 0  → FAIL
platform says DRC unsupported → REVIEW/unsupported
missing/unknown output        → REVIEW
```

This is the check closest to “the streamed final layout is rule-clean” within the available open platform deck.

---

## 29. LVS

The ORFS `lvs` target compares the final physical connectivity against the expected circuit/netlist representation using the platform's configured LVS flow.

FlexSoC collects:

- `6_lvs.lvsdb`;
- `6_lvs.log`.

Known mismatch/error patterns are treated as failures. Unsupported or absent capability becomes review rather than pass.

LVS answers a different question from EQY:

```text
EQY:
  RTL behavior == synthesized logic behavior

LVS:
  extracted physical layout connectivity == intended circuit/netlist connectivity
```

Both are needed because they guard different boundaries.

---

## 30. IR-drop / PDN evidence

Where the ORFS platform produces `VDD.rpt` / `VSS.rpt`, FlexSoC collects them and records worst-case IR drop values when present.

OpenROAD's PDNSim capability can report:

- worst IR drop;
- current density over PDN nodes/segments;
- floating PDN stripes;
- optional per-segment current data for EM-oriented analysis.

Current FlexSoC physical-signoff qualification collects the available IR reports and errors. **Dedicated EM acceptance thresholds are not yet a separate required FlexSoC gate.**

This is a remaining tapeout-hardening item rather than something the current report should pretend is already signed off.

---

## 31. Metal fill / density: current status

OpenROAD/ORFS has metal-fill capability, but the current generated FlexSoC ORFS configuration explicitly uses:

```text
USE_FILL=0
```

Therefore this guide does **not** classify final metal fill/density as an already mandatory FlexSoC sign-off stage.

A production tapeout policy should eventually define:

```text
route-clean layout
→ insert required fill using platform/foundry rules
→ regenerate final GDS
→ rerun extraction if fill changes parasitic assumptions materially
→ rerun final STA as required
→ run final DRC/density checks on the actual tapeout layout
```

---

## Part VIII — Run qualification and traceability

## 32. `metrics`, `manifest`, and `check`

A complex ASIC flow is not useful if success can only be inferred by browsing dozens of log folders. FlexSoC therefore collects stage evidence into a lifecycle-oriented summary.

The intended order is:

```text
RTL lint
CDC / RDC
Functional verification
Formal verification
Synthesis
RTL ↔ synthesis equivalence
Pre-implementation sign-off
Implementation / PnR
Post-implementation sign-off
Physical sign-off
```

### 32.1 `metrics`

Metrics are machine-readable evidence:

- verification counts;
- coverage;
- synthesis area/cells;
- timing results;
- GLS pass/missing/fail counts;
- power summaries;
- implementation artifact presence;
- physical-signoff result details.

### 32.2 `manifest`

The manifest ties the run to:

- run identity;
- selected PDK/tool context;
- important generated artifacts;
- sign-off outputs;
- final implementation files.

It is the beginning of a tapeout/release bill of materials.

### 32.3 `check`

`fx check` is the human-readable closure view.

Its purpose is not to dump every report. It should answer, in lifecycle order:

```text
what passed?
what failed?
what needs review?
where is the supporting evidence?
```

For example, routed GLS is only considered fully qualified when the report shows that SDF interconnect support was actually enabled. Pre-synthesis GLS reports `interconnect none`; routed GLS reports `interconnect enabled`.

---

## Part IX — Complete current FlexSoC flow

## 33. Macro-flow with inputs and outputs

### Stage A — CSR and design entry

**Input**

- architecture;
- clock/reset configuration;
- HJSON register intent.

**FlexSoC does**

- generate CSR RTL/docs/regmap/driver collateral;
- generate starter RTL/top structure;
- generate ordered filelists.

**Output**

- coherent hardware/software register contract;
- elaboratable RTL hierarchy.

---

### Stage B — Structural verification

**Input**

- ordered RTL;
- clock/reset relationships.

**FlexSoC does**

- Slang + Verilator lint;
- CDC/RDC extraction and classification;
- explicit verification obligations.

**Output**

- lint reports;
- CDC/RDC PASS/REVIEW/FAIL evidence.

---

### Stage C — Functional and formal verification

**Input**

- RTL;
- scenario/model intent;
- generated register map;
- authored properties.

**FlexSoC does**

- generate shared vector scenarios;
- run SystemVerilog and cocotb implementations;
- collect HDL coverage;
- run CSR BMC/prove/cover;
- run design BMC/prove/cover.

**Output**

- deterministic functional regression evidence;
- counterexamples or formal PASS;
- reachability/cover traces;
- coverage reports.

---

### Stage D — Synthesis and logical equivalence

**Input**

- verified RTL;
- Liberty/PDK mapping context;
- timing target.

**FlexSoC does**

- Yosys generic synthesis;
- dfflibmap;
- ABC mapping according to area/delay policy;
- mapped-netlist checks;
- EQY RTL↔netlist proof.

**Output**

- mapped netlist;
- synthesis statistics;
- equivalence partitions/proof results.

---

### Stage E — Pre-implementation sign-off

**Input**

- mapped netlist;
- Liberty corners;
- canonical SDC.

**FlexSoC does**

- ideal-clock/no-SPEF STA;
- cell-delay SDF generation;
- vectorless power estimate;
- post-synthesis GLS and workload activity/fusion qualification before PnR.

**Output**

- proof that the technology-mapped logical design is ready to spend physical-implementation runtime on.

---

### Stage F — Physical implementation

**Input**

- FlexSoC mapped netlist;
- canonical SDC;
- ORFS platform.

**ORFS/OpenROAD does**

- import/floorplan;
- PDN setup;
- placement and timing/routability optimization;
- CTS;
- global/detailed routing;
- antenna repair/checking;
- finish/extraction.

**Output**

- `6_final.v`;
- `6_final.sdc`;
- `6_final.spef`;
- `6_final.odb`;
- `6_final.gds`.

---

### Stage G — Post-implementation sign-off

**Input**

- final netlist/SDC/SPEF;
- final corner libraries;
- functional scenarios.

**FlexSoC does**

- propagated-clock/SPEF STA;
- routed SDF generation;
- final-netlist GLS with SDF `INTERCONNECT`;
- vectorless and workload power;
- timing/power fusion.

**Output**

- routed timing/dynamic/power closure.

---

### Stage H — Physical sign-off

**Input**

- final ORFS physical database/GDS/reports.

**FlexSoC does**

- call ORFS final DRC/LVS targets;
- collect route DRC;
- collect antenna;
- qualify final GDS DRC;
- qualify LVS;
- collect IR/PDN evidence.

**Output**

- physical-signoff PASS/REVIEW/FAIL summary.

---

## 34. Current flow as executable pseudocode

```text
configure clocks / resets / PDK / run identity

generate HJSON
edit CSR intent
generate register RTL + docs + regmap + driver

generate/adopt RTL scaffold
generate ordered filelists

run lint suite
run CDC/RDC
run CSR + design formal
run SV + cocotb functional regression
collect coverage

build canonical sign-off/SDC context
synthesize with Yosys/ABC
prove RTL ↔ synthesis equivalence

run pre-implementation STA
write pre-implementation SDF
estimate pre-implementation power
run all post-synthesis GLS before PnR
run activity power / timing-power correlation

run ORFS physical implementation

using ORFS final netlist + SDC + SPEF:
  run routed STA
  write routed SDF
  run post-PnR GLS
  run power/activity/fusion

run physical sign-off:
  ORFS GDS DRC
  ORFS LVS
  collect route DRC / antenna / IR

collect metrics
write manifest
print lifecycle check
```

---

## 35. What the current flow proves — and what it does not

### Current qualified evidence

A fully passing current run can demonstrate that:

- the RTL elaborates and is lint-reviewed by two HDL frontends;
- clock/reset crossings are structurally classified with explicit remaining obligations;
- functional scenarios pass through two testbench implementations;
- HDL coverage is measured;
- CSR and authored design properties pass the configured formal stages;
- the synthesized mapped netlist is behaviorally equivalent to RTL under the EQY model;
- pre-layout timing/power assumptions are explicit;
- the design is physically implemented by ORFS/OpenROAD;
- final timing uses routed SPEF and propagated clocks;
- final SDF contains routed interconnect delays and is dynamically exercised by gate-level simulation;
- vectorless and workload activity power are available;
- route DRC, antenna, final GDS DRC, LVS and available IR evidence are collected into final closure.

### Not yet a complete production tapeout contract

The current flow does not yet make the following mandatory qualified stages:

- scan/DFT insertion and manufacturing test coverage;
- ATPG;
- SRAM/hard-memory compiler integration as a first-class IP view set;
- mandatory final metal fill/post-fill re-extraction policy;
- dedicated EM acceptance criteria;
- package/pad-ring/full-chip ESD integration;
- analog/mixed-signal sign-off.

The two biggest next engineering features for a digital-core-oriented FlexSoC are DFT and hard memories.

---

## Part X — Roadmap: DFT

## 36. Why DFT belongs before PnR, not after sign-off

Manufacturing test changes the implemented circuit. Scan-capable flops occupy area, add ports/nets and create long chains that affect placement and routing.

Therefore the target lifecycle should become:

```text
RTL
→ synthesis
→ DFT scan replacement / test-mode insertion
→ DFT structural checks
→ pre-implementation sign-off on the DFT-aware netlist
→ placement
→ physically informed scan-chain stitching
→ CTS / routing
→ post-implementation sign-off
→ ATPG / test coverage qualification
→ physical sign-off
```

OpenROAD's DFT module already provides useful scan insertion/planning primitives, but FlexSoC does not yet orchestrate them as a qualified stage.

---

## 37. DFT building blocks to add

### 37.1 Scan-cell replacement

Normal functional flops are replaced by equivalent scan-capable flops where supported.

A scan flop conceptually selects between:

```text
functional mode:
  D = normal functional next state

test shift mode:
  D = previous scan-chain bit
```

OpenROAD's `scan_replace` is normally run before placement because cell area and implementation topology change.

### 37.2 Scan ports

A minimal DFT architecture needs:

- `scan_in` — serial test stimulus input;
- `scan_out` — serial observed state output;
- `scan_enable` — selects shift versus functional/capture operation;
- optionally test clocks/test-mode control depending on architecture.

For multiple scan chains:

```text
scan_in[0..N-1]
scan_out[0..N-1]
shared or partitioned scan_enable
```

### 37.3 Scan-chain planning

After scan replacement, flops must be partitioned into chains.

Policy includes:

- maximum chain length;
- maximum chain count;
- whether clock domains/edges may mix;
- balancing chain lengths;
- test-access bandwidth versus routing cost.

OpenROAD supports `set_dft_config` controls for max length/chains and clock-mixing policy.

### 37.4 Physically informed stitching

A logical chain order chosen before placement can create enormous scan-wire length.

The preferred sequence is:

```text
replace flops with scan cells
→ run placement
→ inspect proposed DFT chain plan
→ stitch chains using physical locations to reduce wirelength
```

OpenROAD's `report_dft_plan` and `execute_dft_plan` follow this concept.

### 37.5 Shift and capture modes

DFT timing must consider at least two different operational contexts.

**Shift mode**

```text
scan_enable = 1
scan clock shifts state serially
frequency may be lower than functional clock
hold relationships between adjacent chain elements matter
```

**Capture mode**

```text
scan_enable = 0 or capture-defined state
apply functional-speed or at-speed test clock pulse(s)
capture combinational response into scan flops
```

FlexSoC should eventually generate explicit DFT SDC modes rather than reuse the functional SDC blindly.

### 37.6 DFT formal/equivalence checks

A DFT-aware flow should verify:

```text
functional mode (scan_enable=0):
  DFT netlist behaves like pre-DFT synthesized design

shift mode:
  chain ordering/connectivity is structurally correct

reset/test-mode interaction:
  test controls cannot accidentally corrupt normal operation
```

This may involve an additional logical equivalence boundary around DFT insertion.

### 37.7 ATPG

Scan insertion is not the same thing as manufacturing test generation.

ATPG should generate patterns targeting fault models such as:

- stuck-at faults;
- transition/delay faults;
- potentially bridging/cell-aware models depending on the tool and library support.

A future FlexSoC stage should record:

```text
faults targeted
faults detected
untestable faults
aborted/unknown faults
fault coverage
pattern count
shift/capture cycles
```

OpenROAD's current DFT module is primarily scan-architecture/insertion support; it is not a complete ATPG sign-off solution. FlexSoC will need a separate ATPG strategy/tool integration.

### 37.8 DFT acceptance contract

A future `fx dft_check` should eventually be able to say:

```text
scan replacement       PASS
scan chain count        N
max/min chain length    ...
scan connectivity       PASS
functional equivalence PASS
shift-mode STA          PASS
capture-mode STA        PASS
ATPG stuck-at coverage  >= target
ATPG transition cov.    >= target
```

Only then is “DFT complete” meaningful.

---

## Part XI — Roadmap: SRAM and hard macros

## 38. Why SRAM should not be synthesized from flip-flops

A non-trivial memory inferred into standard cells is usually far larger and more power-hungry than a dedicated SRAM macro. ASIC flows therefore treat SRAMs and many other blocks as hard macros.

Examples:

- SRAM / ROM;
- PLL / oscillator;
- analog front-end;
- regulator / power-management block;
- custom datapath macro.

For FlexSoC, SRAM is the first practical hard-macro target.

---

## 39. Required macro views

A hard macro is one logical block represented differently at different flow stages.

A useful FlexSoC macro contract should include:

| View | Used by |
| --- | --- |
| functional Verilog / simulation model | RTL simulation, GLS integration |
| black-box/module declaration | synthesis hierarchy |
| Liberty `.lib` | STA, synthesis boundary timing, power |
| LEF | floorplan, placement, routing obstruction/pins |
| GDS/OASIS | final layout merge / physical sign-off |
| CDL/SPICE | LVS / circuit-level connectivity |
| optional characterization data | power/timing/variation workflows |

The same macro instance must remain consistently named and connected across these views.

### 39.1 Synthesis behavior

Synthesis should preserve the memory instance as a macro boundary rather than flattening it into generic logic.

```text
RTL memory wrapper
→ recognize configured hard macro
→ keep black-box cell/interface
→ map surrounding logic normally
```

### 39.2 STA behavior

The macro Liberty model provides:

- input/output timing arcs;
- setup/hold constraints;
- clock-to-output delay;
- capacitance/load models;
- power information when characterized.

### 39.3 Physical implementation behavior

The macro LEF provides:

- physical dimensions;
- placement origin/orientation rules;
- signal pin geometry;
- power pin geometry;
- routing obstructions.

Floorplanning then becomes macro-aware:

```text
place large SRAM block(s)
→ reserve halos/channels
→ build/connect macro PDN
→ place standard cells around macros
→ route signal and power connections
```

### 39.4 LVS/final layout behavior

Final GDS must contain the real macro layout and LVS needs compatible transistor/circuit representation, normally through CDL/SPICE or the PDK/macro vendor's required view.

---

## 40. OpenRAM as a possible open-source memory path

OpenRAM is an open-source SRAM compiler. It can be a useful source of generated memory views, but support is technology-dependent.

A responsible FlexSoC integration should **not** assume “OpenRAM supports this PDK” merely because the tool is open source. Each PDK requires technology files, base cells, models and DRC/LVS support.

The future integration should look more like:

```text
macro specification:
  depth
  width
  ports
  PDK/compiler profile

OpenRAM or other compiler
→ generate SRAM implementation and characterization views
→ validate required view set
→ register macro in FlexSoC PDK/IP configuration
→ use consistently in synth / STA / ORFS / LVS
```

### 40.1 Macro qualification before use

Before a compiled RAM becomes a trusted IP, FlexSoC should qualify:

- functional simulation of reads/writes/masks;
- timing model presence and corner coverage;
- LEF/GDS pin consistency;
- power-pin connectivity;
- standalone DRC/LVS where possible;
- macro Liberty pin names matching RTL/LEF;
- integration smoke PnR.

---

## Part XII — Longer-term full-chip items

## 41. IO/pad ring and package boundary

For a hardened digital **core**, the current flow can stop at core GDS sign-off. A complete manufactured die eventually needs another integration layer:

- signal pads / bumps;
- VDD/VSS pads or bump grid;
- ESD structures/policy;
- pad-ring/corner/filler cells as required by the PDK;
- package/bond assumptions;
- external IO timing/load constraints.

This is intentionally outside the current core-flow qualification.

---

## 42. Analog and mixed-signal blocks

Analog is not something that must be added merely to call a digital core an ASIC flow. It becomes necessary when the chip architecture requires blocks such as PLLs, ADC/DACs, oscillators, regulators or analog PHYs.

FlexSoC's likely responsibility is not to design those blocks, but to integrate their digital/physical/timing/circuit views consistently as hard macros.

---

## Part XIII — Recommended next implementation order

## 43. Practical roadmap from the current repository

The current flow already covers the majority of the open digital implementation/sign-off path. The next development order should therefore be focused:

### 1. Stabilize physical sign-off in CI

- run the new ORFS DRC/LVS physical-signoff stage on single-clock and multi-clock E2E;
- qualify SKY130 and IHP capability differences explicitly;
- keep missing/unsupported deck capability as REVIEW, never false PASS;
- decide final policy for metal fill and post-fill timing;
- decide whether EM/current-density becomes a mandatory check.

### 2. Add DFT as the next major functional stage

- scan-capable cell discovery;
- scan replacement;
- scan port/test-mode definition;
- placement-aware chain planning/stitching;
- functional-mode equivalence after insertion;
- shift/capture timing modes;
- ATPG integration and manufacturing coverage reporting.

### 3. Add SRAM/hard-macro integration

- define a generic macro manifest/view contract;
- integrate one RAM compiler/profile first;
- teach synthesis/STA/ORFS/LVS to consume the same macro definition;
- add a small memory-backed single-clock/multi-clock E2E IP.

### 4. Promote from core hardening to full-chip integration when needed

- pad ring / bumps;
- ESD and package assumptions;
- full-chip PDN/IR;
- analog hard-macro integration.

---

## Part XIV — Reference command sequence

## 44. Representative development sequence

The exact CLI options depend on the configured run, but the intended lifecycle is visible in this compact sequence:

```bash
# Design-entry collateral
fx setup --force
fx hjson --force
fx reg doc --force
fx regmap_py --force
fx rtl_stub --force
fx flist --force

# Structural closure and authored timing intent
fx lint_suite
fx sdc --force
# review/edit constraints/design.sdc

# Pre-synthesis verification
fx setup_cdc_rdc --force
fx cdc_rdc
fx setup_formal --force
fx setup_formal_csr_prove setup_formal_csr_cover setup_formal_prove setup_formal_cover --force
fx formal
fx tests_gen --force
fx setup_tb setup_cocotb --force
fx regression
fx coverage_detail

# Technology mapping and logical proof
fx setup_syn
fx syn
fx setup_eqy
fx eqy

# Pre-implementation sign-off / gate verification
fx setup_signoff
fx sta
fx sdf
fx power_estimate
fx sim_post_syn_all
fx power_analysis_all
fx fusion_analysis_all

# Implementation
fx pnr --set ORS=/path/to/OpenROAD-flow-scripts/flow

# Routed sign-off
fx setup_signoff_post_pnr --force
fx sta_post_pnr
fx sdf_post_pnr
fx power_estimate_post_pnr
fx sim_post_pnr_all
fx power_analysis_post_pnr_all
fx fusion_analysis_post_pnr_all

# Final physical sign-off
fx physical_signoff --set ORS=/path/to/OpenROAD-flow-scripts/flow

# Qualification / traceability
fx metrics
fx manifest
fx check
fx manifest_show
```

The key ordering rule is that **all post-synthesis verification/sign-off is completed before PnR**, and routed sign-off is performed only after the final implementation artifacts exist.

---

## Part XV — External technical references

The FlexSoC behavior described above is grounded primarily in the repository code. The following upstream references explain the algorithms/capabilities of the external tools used by the flow.

### SystemVerilog lint / elaboration

- Slang documentation: <https://www.sv-lang.com/>
- Slang user manual: <https://www.sv-lang.com/user-manual.html>
- Slang command-line reference: <https://sv-lang.com/command-line-ref.html>
- Verilator warnings: <https://verilator.org/guide/latest/warnings.html>
- Verilator command reference: <https://verilator.org/guide/latest/exe_verilator.html>

### Yosys / synthesis

- Yosys technology mapping and ABC: <https://yosyshq.readthedocs.io/projects/yosys/en/latest/cmd/index_passes_techmap.html>
- ORFS `SDC_FILE` and timing/synthesis variables: <https://openroad-flow-scripts.readthedocs.io/en/latest/user/FlowVariables.html>
- OpenSTA SDC/SPEF timing model: <https://openroad.readthedocs.io/en/latest/main/src/sta/README.html>
- Yosys technology mapping overview: <https://yosyshq.readthedocs.io/projects/yosys/en/v0.55/using_yosys/synthesis/techmap_synth.html>
- LibreLane synthesis strategies: <https://librelane.readthedocs.io/en/latest/reference/step_config_vars.html>
- LibreLane synthesis-exploration concept: <https://librelane.readthedocs.io/en/latest/usage/writing_custom_flows.html>

### OpenROAD / physical implementation

- OpenROAD overview: <https://openroad.readthedocs.io/en/latest/main/README2.html>
- Global placement / RePlAce: <https://openroad.readthedocs.io/en/latest/main/src/gpl/README.html>
- PDN generation: <https://openroad.readthedocs.io/en/latest/main/src/pdn/README.html>
- Clock-tree synthesis / TritonCTS: <https://openroad.readthedocs.io/en/latest/main/src/cts/README.html>
- Detailed routing / TritonRoute: <https://openroad.readthedocs.io/en/latest/main/src/drt/README.html>
- IR-drop / PDNSim: <https://openroad.readthedocs.io/en/latest/main/src/psm/README.html>
- DFT: <https://openroad.readthedocs.io/en/latest/main/src/dft/README.html>

### SRAM roadmap

- OpenRAM: <https://openram.org/>
- OpenRAM technology porting: <https://openram.org/PORTING.html>

---

## 45. Final mental model

FlexSoC should be read as a set of increasingly concrete representations of the same design intent:

```text
register / architectural intent
        ↓
RTL behavior
        ↓
structurally and formally qualified RTL
        ↓
functionally qualified RTL
        ↓
technology-mapped but still logical netlist
        ↓
logically equivalent mapped netlist
        ↓
pre-layout timing/power-qualified netlist
        ↓
placed/clocked/routed physical implementation
        ↓
SPEF-aware timing and dynamically delayed final netlist
        ↓
DRC/LVS/antenna/IR-qualified physical artifact
        ↓
traceable release manifest
```

Every stage answers a different class of question. The strength of the flow comes from **not allowing one tool's PASS to stand in for another tool's job**:

- lint does not replace CDC;
- CDC does not replace formal;
- simulation does not replace equivalence;
- equivalence does not replace STA;
- STA does not replace GLS;
- PnR completion does not replace DRC/LVS;
- physical sign-off does not replace manufacturing test.

The next major boundary is therefore clear: add **DFT/testability** and **hard-memory integration** while preserving the same discipline of explicit inputs, generated scripts, machine-readable evidence, and lifecycle closure.
