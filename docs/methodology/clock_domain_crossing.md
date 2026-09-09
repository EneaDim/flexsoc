# Clock-domain and reset-domain crossing methodology

This guide defines the preferred FlexSoC methodology for **clock-domain crossing
(CDC)** and **reset-domain crossing (RDC)** design, analysis, review, and
qualification.

It applies to both single-clock and multi-clock IPs. A single-clock IP is not
exempt from reset-domain analysis, generated/gated-clock intent, or structural
sanity checks; it simply has no intentional asynchronous clock-domain crossing
when its clock contract is genuinely single-domain.

The methodology is deliberately evidence-oriented:

```text
architectural clock/reset intent
        ↓
explicit RTL crossing mechanism
        ↓
structural CDC/RDC analysis
        ↓
review / verification obligations
        ↓
qualification evidence
```

FlexSoC does not replace a CDC/RDC engine or prove an unsafe structure safe by
policy. It records the clock/reset contract, orchestrates structural analysis,
classifies recognizable mechanisms, exposes unresolved obligations, and keeps
that evidence traceable into qualification.

---

## 1. Start from clock/reset architecture, not from tool warnings

Before writing crossing logic, define the domains that actually exist.

The canonical FlexSoC settings are:

```text
N_CLOCKS
CLOCK_DOMAINS
CLOCK_RELATIONSHIPS
```

A domain entry names:

```text
name : clock signal : reset signal : period : reset polarity
```

Example:

```text
cfg:cfg_clk_i:cfg_rst_ni:20:low
rx:rx_clk_i:rx_rst_ni:16:low
dsp:dsp_clk_i:dsp_rst_ni:30:low
```

Clock relationships are explicit architectural intent:

```text
async:cfg:rx
async:cfg:dsp
async:rx:dsp
```

Do not rely on the checker to infer an asynchronous relationship from frequency,
phase, naming, or observed connectivity.

A useful rule is:

```text
if two state elements may sample without a guaranteed common phase relationship,
model the crossing explicitly
```

---

## 2. Single-clock methodology

A true single-clock IP normally has:

```text
one primary clock domain
one reset ownership model
zero intentional asynchronous clock crossings
```

The expected CDC result is therefore simple, but the analysis still matters.
It should catch accidental secondary clocks, combinational clock paths, and
state that cannot be assigned to the declared domain.

For a single-clock IP, review these points:

1. every sequential element maps to the declared clock domain;
2. no data signal is accidentally used as a clock;
3. any gated or derived internal clock has explicit architectural intent;
4. reset assertion/deassertion follows the documented reset policy;
5. additional reset branches do not silently create uncontrolled RDC paths;
6. structural CDC/RDC status is PASS before the evidence is considered closed.

A single-clock design can still contain RDC. For example, two groups of flops
clocked by the same clock but independently reset can exchange state while one
reset domain is active and the other is not.

Therefore:

```text
same clock != same reset domain
```

---

## 3. Multi-clock methodology

A multi-clock IP starts with explicit domain ownership.

Each stateful block should have one clear clock/reset owner. Crossings should be
visible in the architecture rather than emerging accidentally from ordinary RTL.

Preferred structure:

```text
source domain
    │
    ├── source-local state
    │
    └── explicit CDC mechanism
              │
              ▼
        destination domain
```

Avoid designs in which a large combinational cone freely spans domains and is
then sampled somewhere downstream. The crossing mechanism should sit at a
reviewable boundary.

### Keep controls domain-local when possible

Do not create a CDC merely because a control register could be placed in a
different software-visible window. If a control is consumed only by one domain
and that domain has an always-available CSR/control path, prefer to own the
control in that destination domain.

For example:

```text
less direct:
  cfg CSR -> synchronizer -> DSP-only software reset

preferred when the DSP CSR window is always clocked:
  DSP CSR -> DSP-only software reset
```

This removes an unnecessary crossing and also avoids false or real coherency
questions when independently synchronized controls later reconverge.

### Synchronized reconvergence

Two independently synchronized signals from the same source domain may arrive
in different destination cycles. If downstream logic consumes them together,
the destination can observe a combination that never existed simultaneously at
the source. Structural analysis therefore reports synchronized reconvergence.

Do not close reconvergence by counting destinations or adding a blanket waiver.
First ask whether the signals actually need to cross independently. Preferred
responses are, in order:

1. keep destination-only controls in the destination domain;
2. transfer related controls coherently with a handshake/snapshot/bundled-data protocol;
3. prove that incoherent arrival is functionally harmless when that is genuine design intent.

---

## 4. Choose the CDC mechanism from the information being transferred

There is no universal synchronizer for every crossing.

### Stable single-bit level

Use an explicit multi-flop synchronizer when the source is a level that remains
stable long enough to be sampled.

Typical examples:

```text
enable
mode_active
interrupt_level
status_flag
```

A two-flop synchronizer addresses metastability propagation. It does **not** by
itself prove that a short source pulse will be observed.

### Pulse or event

For a pulse/event crossing, establish an event-transfer protocol appropriate to
the required loss/duplication semantics, such as:

```text
pulse stretching
request/acknowledge handshake
toggle/event synchronizer
counter/event accumulation
```

The verification obligation is not merely metastability containment. It also
includes event observability and, where required, exactly-once behavior.

### Multi-bit configuration or status

Do not independently synchronize every bit of a coherent bus unless incoherent
sampling is explicitly acceptable.

Preferred choices include:

```text
bundled data + synchronized control
request/acknowledge snapshot
Gray-coded state where mathematically appropriate
asynchronous FIFO
```

A bundled-data scheme needs an explicit stability rule. For example:

```text
software updates data only while destination enable is inactive
        ↓
data is stable before the synchronized enable is observed
        ↓
data remains stable for the required sampling interval
```

FlexSoC may classify such a structure as requiring review rather than declaring
it safe automatically. The corresponding stability/polarity/sampling obligation
must be discharged by design intent or verification evidence.

### Streaming payload

Use an asynchronous FIFO for sustained multi-bit traffic between asynchronous
clock domains.

The FIFO contract must cover more than the storage array:

- write-side ownership;
- read-side ownership;
- pointer synchronization;
- coherent full/empty generation;
- safe data visibility;
- reset interaction between the two sides.

The FIFO should be treated as a reviewable CDC boundary rather than allowing the
checker to interpret every internal pointer synchronizer as an unrelated design
crossing.

---

## 5. Gated and derived clocks

A glitch-free clock gate does not create a new asynchronous clock domain merely
because it creates a new clock net.

For a 1:1 gated clock:

```text
parent clock ── glitch-free gate ── gated clock
      domain A                         domain A
```

The internal gated clock must still be represented explicitly in CDC intent so
that sequential state clocked by that net remains assigned to the parent
logical domain.

Do not solve this by teaching the generic backend a particular primitive name.
FlexSoC uses explicit CDC contracts on the design boundary. The implementation
module may change without changing the logical clock-domain contract.

A genuinely divided or otherwise generated architectural clock is different.
When it is part of timing intent, represent it with the canonical clock
relationship/SDC generated-clock mechanism rather than pretending it is an
unrelated asynchronous domain.

---

## 6. Reset methodology and RDC

The preferred reset pattern for an asynchronous external reset is:

```text
external reset
    │
    ├── asynchronous assertion
    │
    └── synchronous release in each owning clock domain
```

Each clock domain owns its reset release.

Do not distribute one synchronizer output across unrelated clock domains.
Likewise, do not generate arbitrary combinational reset trees unless the reset
composition itself is part of reviewed architecture.

### Reset families and physical distribution trees

Physical implementation may intentionally split one synchronized reset into
multiple branches to control fanout, buffering, placement, or reset-tree load.
Those branch signals are distinct nets, but they are not automatically distinct
RDC domains. FlexSoC therefore distinguishes **reset signals** from **reset
families**.

A reset family is derived from structural ancestry, not from signal names or a
fixed tree depth. A pure tree may be arbitrarily deep:

```text
external reset
    └── synchronizer / release chain
          ├── distribution stage
          │     ├── distribution stage -> consumers
          │     └── distribution stage -> consumers
          └── distribution stage
                └── distribution stage -> consumers
```

All leaves above belong to the same logical reset family when the checker can
trace them to one root through conservative reset-tree structures. The accepted
ancestry is intentionally narrow: simple aliases/polarity normalization and
scalar reset-release/distribution state whose data path represents deassertion.

The family trace must stop when it encounters dynamic reset logic, arbitrary
combinational control, or an unrecognized state element. Such a derived reset
remains a separate family and normal RDC analysis applies.

This distinction preserves both goals:

- synthesis/physical design may split reset networks for fanout and distribution;
- CDC/RDC analysis still detects genuinely independent or functionally controlled
  reset domains.

The analysis/reporting should therefore expose both counts where useful:

```text
reset signals   = structural reset nets observed at sequential state
reset families  = logical roots after conservative ancestry resolution
```

### Independent resets

An asynchronous FIFO or other CDC protocol may have independently reset source
and destination sides. That is not automatically unsafe, but it creates an RDC
question:

```text
what happens if one side resets while the other side remains active?
```

The design must define one of the following:

- the primitive/protocol is safe under independent reset events;
- traffic is blocked while reset states are inconsistent;
- a reset assertion/release sequence is required and documented;
- a higher-level recovery/reinitialization protocol restores coherence.

Do not turn this into a waiver merely because the crossing is inside a known
FIFO primitive.

### Software reset

Keep software reset semantics separate from hardware reset semantics.

A synchronous software clear may intentionally reset only datapath/pipeline
state. It should not be described as a FIFO flush unless the RTL really flushes
the FIFO and the protocol defines the consequences for both domains.

---

## 7. Explicit FlexSoC CDC contracts

Some structures are intentionally trusted architectural boundaries whose
internal implementation should not be reclassified as top-level crossings.

FlexSoC represents that intent with generic RTL attributes rather than module or
IP names.

Clock-gate boundary example:

```systemverilog
(*
  flexsoc_cdc_contract       = "clock_gate",
  flexsoc_cdc_domain         = "dsp",
  flexsoc_cdc_clock_in_port  = "clk_i",
  flexsoc_cdc_clock_out_port = "clk_o"
*)
clock_gate u_gate (...);
```

Async-FIFO boundary example:

```systemverilog
(*
  flexsoc_cdc_contract                 = "async_fifo",
  flexsoc_cdc_source_domain            = "rx",
  flexsoc_cdc_destination_domain       = "dsp",
  flexsoc_cdc_source_clock_port        = "clk_wr_i",
  flexsoc_cdc_destination_clock_port   = "clk_rd_i",
  flexsoc_cdc_source_reset_port        = "rst_wr_ni",
  flexsoc_cdc_destination_reset_port   = "rst_rd_ni",
  flexsoc_cdc_partial_reset_safe       = "true"
*)
async_fifo u_fifo (...);
```

These attributes are **design intent**, not a bypass switch.

The backend must validate:

- referenced domains exist;
- clock/reset ports are present and scalar where required;
- observed clock connectivity matches the declared domains;
- a clock-gate output inherits the declared parent domain;
- async-FIFO reset safety is represented explicitly rather than assumed.

A malformed contract is a setup error.

---

## 8. Structural extraction is part of the CDC contract

CDC analysis operates on a technology-neutral structural representation.
Contract boundaries must survive that extraction.

The extraction policy is:

```text
preserve explicitly contracted cell boundaries
flatten ordinary hierarchy
analyze the resulting structural graph
```

If the RTL contains CDC contracts but `design.json` contains none, do **not**
interpret the resulting thousands of internal FIFO/gate findings independently.
The extraction boundary is broken and must be fixed first.

This is why `fx cdc_rdc --debug` reports contract survival before presenting
protocol-level findings.

---

## 9. Canonical FlexSoC workflow

The normal workflow is:

```bash
fx cdc_rdc --setup
fx cdc_rdc
fx cdc_rdc --debug
```

`--setup` prepares the structural extraction and canonical configuration.

`fx cdc_rdc` executes the structural analysis and writes the canonical evidence:

```text
analysis/cdc_rdc/
├── extract.ys
├── design.json
├── summary.json
└── cdc_rdc.rpt
```

`fx cdc_rdc --debug` is read-only. It does not rerun the checker or modify the
evidence. It renders the existing artifacts in root-cause order.

For machine consumption:

```bash
fx cdc_rdc --debug --json
```

---

## 10. Read `--debug` in root-cause order

The debug renderer follows these phases:

```text
1. extraction / CDC-contract survival
2. clock/reset setup and glitch checks
3. CDC protocol classification
4. RDC classification
5. review obligations
6. closure
```

If an earlier phase is broken, later findings are marked as downstream/deferred.
For example:

```text
RTL contracts present
       +
design.json contracts absent
       ↓
extraction BLOCKED
       ↓
CDC/RDC internal findings are secondary symptoms
```

Do not fix or waive secondary findings until the earlier phase is closed.

The debug command intentionally separates:

```text
debug execution = command successfully read/rendered artifacts
analysis closure = PASS / REVIEW / FAIL recorded by CDC/RDC
```

A successful `--debug` command does not convert a failed CDC analysis into PASS.

---

## 11. Finding states and obligations

Use the states consistently:

### SAFE

The structural mechanism is recognized and no open structural problem remains.
SAFE is evidence about the analyzed mechanism; it is not permission to ignore
functional requirements around pulse width, coherency, reset recovery, or
throughput when those are part of the design contract.

### INFO

Recorded structural fact that does not block closure.

### WARN

Potential concern or incomplete declaration that should be reviewed. Do not
silently treat WARN as PASS.

### REVIEW

The structure is plausible/recognized but still requires explicit design intent
or verification evidence.

### ERROR

The current structural analysis finds an uncontrolled or inconsistent crossing,
clock/reset setup problem, or invalid contract.

### Verification obligations

An obligation is an explicit piece of evidence still required to close a REVIEW
or other non-closed classification.

Examples:

```text
prove_data_stability_before_control
prove_data_stability_after_control
confirm_control_polarity_and_sampling_edge
prove_protocol_safe_across_independent_reset_events
specify_reset_assertion_sequence_or_rdc_blocking_control
```

Count both:

```text
obligation findings    = number of findings carrying obligations
obligation checks      = number of atomic checks still requested
```

FlexSoC debug output reports both values.

---

## 12. Qualification rule

CDC/RDC qualification should follow the evidence, not the desire for a green
pipeline.

Do not:

```text
hide failing crossings
convert ERROR to REVIEW without structural reason
waive a primitive merely by module name
remove tests because they expose a crossing
claim PASS because the analysis command itself completed successfully
```

Do:

```text
fix clock/reset intent first
use the correct CDC mechanism for the data semantics
make trusted boundaries explicit and generic
close or explicitly review remaining obligations
preserve canonical summary/report/provenance
let qualification consume the recorded outcome
```

`WAIVED` remains distinct from `PASS`.

---

## 13. Review checklist

Before accepting CDC/RDC evidence, review:

### Clock architecture

- every clock domain is declared;
- every sequential element belongs to a declared logical domain;
- asynchronous relationships are explicit;
- gated/generated clock intent is explicit;
- there are no unexplained combinational clock paths.

### Crossing architecture

- single-bit levels use appropriate synchronizers;
- pulses/events have an observability protocol;
- coherent multi-bit data is not synchronized bit-by-bit without justification;
- streaming data uses an appropriate asynchronous protocol/FIFO;
- independently synchronized controls do not reconverge unsafely.

### Reset architecture

- each domain owns reset release;
- asynchronous release is synchronized where required;
- interacting reset domains have a defined policy;
- FIFO/protocol behavior during partial reset is explicit;
- software reset semantics match the RTL.

### Evidence

- contract boundaries survive structural extraction;
- setup/glitch ERROR count is zero;
- CDC ERROR count is zero;
- RDC ERROR count is zero;
- REVIEW/WARN items are understood and have appropriate evidence;
- open obligations are intentionally discharged, not hidden;
- qualification reflects the real recorded result.

The goal is not to produce zero lines of CDC/RDC output. The goal is to make
every crossing and reset interaction **intentional, structurally recognizable,
reviewable, and backed by sufficient evidence**.
