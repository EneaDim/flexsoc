# RV Timer — Technical Design Specification

**Document class:** TDS · **IP release:** 1.0.0 · **Status:** Engineering specification for qualification
**Upstream product contract:** [Customer Specification](customer.md) · **Derived obligations:** [Requirements](requirements.yaml) · **Verification allocation:** [Testplan](testplan.yaml)

## 1. Purpose, scope and interfaces

The RV Timer IP is a memory-mapped, single-hart, single-channel 32-bit timer. Its functional clock is `clk_i`, reset is active-low `rst_ni`, and its single expiry output is `intr_timer_expired_hart0_timer0_o`. Firmware selects activation, a 12-bit prescale terminal value, an eight-bit increment, the 32-bit running count and a 32-bit compare threshold. The CSR HJSON is authoritative for register offsets, widths, access types and reset values.

`tlul`, `reg_iface` and `axi_lite` are supported CSR transport packages with identical timer behavior. SoC integration supplies the source clock, reset, device-side bus attachment and interrupt sink. The timer does not calibrate the input clock to real time.

## 2. Data path and state

The timer has a prescale counter, a tick relation, a software-visible `TIMER_V0` count, and a compare/interrupt path. While enabled, terminal prescale intervals generate ticks; each tick advances the 32-bit count by the programmed step with modulo-2^32 arithmetic. The compare condition is evaluated against the count while active. Generated CSR interrupt logic provides enable, state and test injection.

## 3. Detailed behavioral requirements

### TDS-001 — Clock, reset and activation

Customer refs: CRS-001

- `clk_i` drives synchronous timer state and active-low `rst_ni` establishes the register-defined reset state.
- Reset clears the internal prescale/tick counter. CSR reset defaults are defined by HJSON.
- `CTRL.active=0` prevents the normal timer event and returns/holds the internal tick counter at zero. When active, normal counting resumes according to `CFG0`.
- No timer tick, event or interrupt timing is guaranteed if the input clock does not meet the SoC-level clock contract.

Allocated requirements: RVT-RST-001, RVT-ACT-001

### TDS-002 — Prescaling, tick and count arithmetic

Customer refs: CRS-001

- `CFG0.prescale` selects the 12-bit prescale terminal relation. While active and below this value, the tick counter increments by one per sampled cycle; on reaching the terminal relation it returns to zero.
- `tick` is asserted when active and the tick counter is greater than or equal to `CFG0.prescale`.
- On tick, `TIMER_V0` advances by the zero-extended eight-bit `CFG0.step`, with natural 32-bit wraparound. Step zero therefore results in no tick-driven count increase.
- `TIMER_V0` is also directly software-writable. The TDS does not promise concurrent write/tick ordering beyond the CSR/RTL-defined clocked behavior.

Allocated requirements: RVT-TICK-001, RVT-COUNT-001, RVT-TIME-001

### TDS-003 — Software timer configuration

Customer refs: CRS-001

- Firmware writes `CTRL.active`, `CFG0.prescale`, `CFG0.step`, `TIMER_V0` and `COMPARE_V0` using the register interface.
- Configuration changes affect subsequent sampled behavior, and software may explicitly reinitialize current time and compare threshold.
- Register defaults, field access and update side effects are owned by the HJSON CSR definition; protocol-specific adapter effects do not modify the timer algorithm.

Allocated requirements: RVT-CFG-001

### TDS-004 — Compare-event generation

Customer refs: CRS-002

- A compare event exists when `CTRL.active` is asserted and `TIMER_V0 >= COMPARE_V0`.
- Equality is a valid trigger; the comparator does not require an exact wrap crossing to recognize a threshold.
- An inactive timer suppresses normal compare-event generation. The compare threshold is a register value, not a guaranteed absolute time interval.

Allocated requirements: RVT-CMP-001

### TDS-005 — Interrupt enable, state, test and recovery

Customer refs: CRS-002

- The compare event drives the generated interrupt helper. `INTR_ENABLE0.IE` masks the external expiry interrupt; `INTR_STATE0.IS` records its state with the generated rw1c semantics.
- `INTR_TEST0.T` supports injected interrupt-test state, including the enabled case.
- Updating `COMPARE_V0` clears the implemented timer interrupt state, permitting recovery when the new threshold is not already satisfied.
- The external IRQ output represents the enabled interrupt state; the system owns interrupt-controller handling.

Allocated requirements: RVT-INT-001, RVT-INT-002, RVT-INT-003

### TDS-006 — CSR transport equivalence

Customer refs: CRS-003

- The same single timer, 32-bit arithmetic, compare and interrupt behavior shall be exposed by qualified `tlul`, `reg_iface` and `axi_lite` packages.
- Register semantics and side effects are invariant even though transaction handshakes differ; each transport adapter requires its own qualification.

Allocated requirements: RVT-REG-001

## 4. CSR and integration summary

| Field / register | Technical purpose |
|---|---|
| `CTRL.active` | Enable normal timer counting and comparison |
| `CFG0.prescale` | Terminal divider relation, 12 bits |
| `CFG0.step` | Increment per tick, 8 bits |
| `TIMER_V0` | Software-visible 32-bit running time |
| `COMPARE_V0` | 32-bit trigger threshold; updating clears interrupt state |
| `INTR_ENABLE0.IE` | Interrupt enable/mask |
| `INTR_STATE0.IS`, `INTR_TEST0.T` | Latched state/clear and test injection |

`CTRL.gpio_intr_0` and `CTRL.gpio_intr_1` may remain visible in the register contract, but GPIO-triggered activation/capture is **not qualified behavior** in this specification revision. No requirement or acceptance evidence is assigned to it.

## 5. Verification and acceptance strategy

Directed tests shall cover defaults, activation, prescale extremes, count arithmetic, compare threshold, interrupt state and compare-write clear. Formal assertions cover prescale, tick, time and compare invariants. Model tests independently check selected arithmetic and configuration scenarios but do not substitute for cycle-sensitive RTL tests or interrupt-helper verification. The testplan associates each requirement with executed evidence as it becomes available.

Where needed for netlist qualification, bounded post-synthesis GLS uses `smoke`, `timer`, `reconfig` in `ss`, `tt`, `ff`. Physical sign-off, post-PnR GLS and timing closure are independent future stages.

## 6. Assumptions and exclusions

One input clock, one timer channel and one IRQ output are assumed. No multi-hart, multi-timer, 64-bit time, calibrated real-time measurement, watchdog or qualified GPIO-trigger feature is claimed. Changes to time width, clock assumptions, compare behavior or IRQ semantics require revisions to the TDS, requirements, testplan and qualification evidence.
