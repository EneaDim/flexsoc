# Ethernet MAC — engineering draft (not customer approved)

**Status: PROPOSED; not a qualified FlexSoC release.**

These sections derive from the M4 authored engineering package, not a signed customer CRS.
External packet transfer, overflow policy, physical FPGA target, PHY clock/reset
constraints and 10/100/1000 dynamic qualification remain unresolved.


---

## M4 source: CRS.md

# ETH-CRS-001 — Customer Requirements Specification (candidate v0.1)

**Status: PROPOSED / not customer-approved.** This document is an engineering reconstruction of the user's stated product goal and pinned MIT upstream RTL, **not** an approved customer source. Each `CRS-*` claim requires an explicit review; unresolved choices are enumerated below. Any change to the approved scope must propagate through TRS/TDS, requirements, tests, implementation and trace.

## Intended product
A reusable, synthesizable, parameterized FlexSoC Ethernet MAC IP for FPGA and eventual SoC integration with **10/100/1000 Mb/s** over **MII/GMII**, packet transmission and reception, integrity checking, software-visible configuration/status/error statistics/interrupts and repeatable qualification. The SoC control-bus variant is selected by FlexSoC (TL-UL, Reg-IF, AXI-Lite); the register map and semantics must not change between variants. Vendor Verilog is a pinned *reference*, never silently edited.

## Candidate product requirements
| ID | Candidate requirement | Acceptance concept |
|---|---|---|
| CRS-001 | Support full-duplex TX and RX at 10/100/1000 Mb/s via MII/GMII PHY. | Functional test for all three actual PHY clock rates and I/O width. |
| CRS-002 | TX emits valid IEEE 802.3 preamble/SFD, optionally pads short frames, appends correct reflected Ethernet CRC-32 FCS and respects IFG. | Independent packet oracle and on-wire checker; boundary/random cases. |
| CRS-003 | RX accepts valid frames, strips preamble/FCS and reports bad FCS and PHY errors without hiding malformed traffic. | Good/bad/error vectors; matching expected output/data/flags. |
| CRS-004 | One hardware-generated CSR window configures TX/RX enable and IFG; exposes speed/status/3 error counters/3 IRQ events. | HJSON ↔ generated RTL ↔ CSR functional vectors. |
| CRS-005 | Packet streaming datapath is separate from TL-UL/Reg-IF/AXI-Lite control interface. | Core top port inventory, throughput and backpressure tests. |
| CRS-006 | Correct operation across independent SoC, TX and RX clocks/reset domains, including speed changes. | CDC/RDC structural evidence and multi-clock dynamic testing. |
| CRS-007 | Preserve behavior of pinned upstream components during Verilog→SystemVerilog migration. | Independent per-cycle A/B with nonvacuous activity. |
| CRS-008 | Support reusable FlexSoC qualification: CRS→TRS→TDS→REQ→TP→model→model tests→RTL regression→lint→CDC/RDC→L2 traceability. | Machine-checkable trace, fresh evidence, no silent PASS. |
| CRS-009 | FPGA deployment shall use board-appropriate PHY I/O cells, clocks and constraints; GENERIC simulation is not timing signoff. | Real board timing and 10/100/1000 hardware tests. |

## Out of scope unless explicitly commissioned
- TCP/IP, UDP/IP, ARP, PTP clock service, MDIO management/autonegotiation, RGMII, 10G and Ethernet switch fabric.
- CPU packet I/O via CSR registers; DMA and asynchronous packet FIFOs are **not** implicitly delivered by the current HJSON. Those must be separately specified if the SoC needs software/network access.
- Half-duplex CSMA/CD, pause frames, jumbo frames, automatic PHY link-state reporting and specific FPGA family primitives are **not** silently assumed.

## Decision log: customer signoff required before closure
| ID | Decision | Default for current engineering work |
|---|---|---|
| DEC-01 | TX/RX interface ownership and backpressure | Byte-stream with valid/ready/last at TX; RX valid/last/user, no backpressure at PHY-facing RX |
| DEC-02 | RX overflow behavior and destination buffering | Undecided. Must define FIFO sizing/drop policy before final SoC top |
| DEC-03 | External packet interface (SoC fabric DMA/FIFO/stream) | Undecided. Standalone core exposes packet stream; CSR remains separate |
| DEC-04 | Speed detection and legal speed change behavior | Explicit test for all rates; switching while frame active must be specified |
| DEC-05 | IP clock topology and FPGA target | CSR + TX + RX asynchronous domains; board and PHY to be chosen |
| DEC-06 | IFG software range and update timing | Reset 12 octet-times; change commits between frames; standards minimum must not be bypassed |
| DEC-07 | Error counter and interrupt exact semantics | Proposed modulo-2^32 counters, sticky W1C interrupt events; overflow simultaneity needs approval |
| DEC-08 | Padding threshold/oversized frame limit | Upstream default minimum 64 including FCS; max/oversize policy pending approval |
| DEC-09 | PHY pinout and MDIO | Physical GMII/MII pins; MDIO left to separate owner unless requested |
| DEC-10 | CSR-generated top multi-clock support | Verify with actual `fx top_from_core`; never duplicate CSR registers per clock |

## Normative references
Ethernet IEEE 802.3 applies subject to the applicable licensed specification and independent conformance testing. Open-source `alexforencich/verilog-ethernet`, MIT license, pinned commit `77320a9471d19c7dd383914bc049e02d9f4f1ffb`, is **implementation reference**, not proof of IEEE compliance. The taxi project is a design reference only, with distinct licensing; no taxi source is included.


---

## M4 source: TRS.md

# ETH-TRS-001 — Technical Requirements Specification (candidate v0.1)

**Status: PROPOSED.** Derived from CRS candidate; not independent regulatory/certification proof.

| ID | Source | Technical SHALL | Verification |
|---|---|---|---|
| TRS-001 | CRS-001 | GMII mode shall process one octet per enabled MAC tick at 125 MHz for Gigabit; MII shall process low nibble first at 25 or 2.5 MHz at 100 or 10M. | Mode, cadence, nibble-order tests, hardware timing |
| TRS-002 | CRS-002 | TX shall generate 7×0x55 + 0xD5, data bytes, pad to 60 octets before FCS by default, append little-endian FCS of CRC32(poly reflected 0xEDB88320, init/final XOR 0xffffffff). | Known answer + frame oracle |
| TRS-003 | CRS-002 | TX IFG shall be no less than minimum applicable IEEE requirement; legal programmable values must be enforced once customer accepts range. | Boundary + on-wire idle-cycle monitor |
| TRS-004 | CRS-003 | RX shall verify FCS, classify errors and deliver payload excluding preamble/FCS with reliable end-of-frame indication. | Good, bad FCS, PHY error, reset tests |
| TRS-005 | CRS-004 | Exactly one CSR HJSON shall be authoritative; 9 registers at generated offsets 0x00..0x20; `reg2hw` drives controls and `hw2reg` drives statuses/events. | Source hash, reggen, generated SV consistency |
| TRS-006 | CRS-004 | Hardware error counts shall update without lost pulses across TX/RX→CSR crossings; sticky interrupts are independently testable via INTR_ENABLE and INTR_TEST. | Pulse burst, simultaneous clear, async clocks |
| TRS-007 | CRS-005 | Packet data shall not flow through the CSR address space; TX ready/valid handshake shall hold until accepted. RX traffic shall have a documented sink/drop/overflow policy. | Stream protocol assertions |
| TRS-008 | CRS-006 | Cross-domain multi-bit config (`IFG`, enable) shall transfer coherently using a documented commit/ack scheme. Status and events shall use proper synchronizers/handshakes or async queues; async resets shall deassert synchronously. | CDC signoff + dynamic stress |
| TRS-009 | CRS-007 | Every converted leaf shall be reproducible from pinned upstream source SHA and shall match it cycle-by-cycle for bounded verified stimuli. | M1/M2/M3 summary.json freshness |
| TRS-010 | CRS-008 | Functional test intent shall originate in Python; projected `config.regs`, `data_in.vec`, `data_out.vec` shall be generated, checked for freshness and shared across control-bus variants. | `tests_gen --check`, vector generation tests |
| TRS-011 | CRS-008 | Qualification PASS shall require evidenced RTL, lint, CDC/RDC, regression and traceability. | `fx qualify`, provenance summary |
| TRS-012 | CRS-009 | Real FPGA PHY shall use approved clock resources and timing constraints; `TARGET=GENERIC` shall never be accepted as a board timing guarantee. | I/O timing reports and link tests |

## Controlled ambiguities
TRS-003 programmable IFG below 12, TRS-004 RX error flag combinations, TRS-006 lossless event counters across fast domains, TRS-007 RX overflow and TRS-008 speed-change transaction policy are **open until implemented and bench-qualified**. A model assumption is not a delivered feature.


---

## M4 source: TDS.md

# ETH-TDS-001 — Technical Design Specification (integration design, unimplemented)

## Hierarchy, ownership and licensing
- **GENERATED `ethernet.sv`** is FlexSoC top, external TL-UL/Reg-IF/AXI-Lite only; not authored by hand.
- **GENERATED `ethernet_reg_top.sv`, `ethernet_reg_core.sv`, `ethernet_reg_pkg.sv`** implement one CSR window. From actual user reggen evidence `reg_core` and `reg_pkg` exist; `reg_top` must be generated later by `fx top_from_core`.
- **AUTHORED `ethernet_core.sv`** connects CSR structs, TX/RX, PHY interface, packet path, error/status signals and CDC. No extra bus wrappers. This module has **not** yet been implemented or simulated; M1–M3 verify isolated components only.
- **AUTHORED `ethernet_tx.sv`, `ethernet_rx.sv`, `ethernet_phy_if.sv`** were independently generated from pinned MIT source in user's workspace and have bounded A/B tests. Include pinned upstream `lfsr.v`, `ssio_sdr_in.v`, `ssio_sdr_out.v`, `oddr.v` as dependencies, keep copyright and license.

## Control and status: generated names are authoritative
`reg2hw.ctrl.tx_enable.q`, `reg2hw.ctrl.rx_enable.q`, `reg2hw.ifg.q[7:0]` are SoC→core. `hw2reg.status.speed.{d,de}`, `speed_valid.{d,de}`, `tx_enabled.{d,de}`, `rx_enabled.{d,de}`, `cfg_pending.{d,de}`, plus three `*_count.{d,de}` and `hw2reg.intr_state.{tx_underflow,rx_bad_frame,rx_bad_fcs}.{d,de}` are core→CSR. The actual structs are in `source/rtl/ethernet_reg_pkg.sv`. Do not infer `status.speed` from reset zero without checking `speed_valid`.

## Clock and reset ownership
`clk_i,rst_ni`: CSR domain. Distinct `tx_clk,tx_rst`, `rx_clk,rx_rst` derived from PHY reference clocks: actual names to be aligned with PHY interface. For 1000M GMII, reference ~125MHz. For MII 100M/10M the nibble clocks are 25MHz/2.5MHz at pins; MAC-internal GTX clock enable/clock division need explicit strategy consistent with pinned upstream.

**CDC specification, mandatory before RTL closure:**
1. CSR→TX: capture CTRL.TX_ENABLE and IFG as one stable snapshot, req/ack toggle handshake. Source must hold bus through acknowledge; destination applies at frame boundary. Include reset/reconfiguration pending bit.
2. CSR→RX: capture RX_ENABLE with synchronized control/ack; apply safely between frames.
3. TX/RX→CSR: events may be much faster than CSR clock. Two-flop synchronizing a pulse is **not lossless**. Use event toggle with acceptance backpressure where event rate permits, or Gray-coded accumulators/crossing FIFO with explicit overflow semantics; demonstrate no lost counts under bounded bursts. IRQ state derives from captured events.
4. Speed detector: independently qualify rate and coherently deliver `{speed,speed_valid}` to CSR. No per-bit raw synchronizers; `speed_valid` must invalidate during rate changes.
5. Reset: asynchronously assert if required; deassert each domain synchronously, document reset relationships and ownership. No combinational CDC of clock enables.
6. RX payload crossing: RX cannot backpressure PHY. An async FIFO or sink in RX clock domain is required when SoC packet interface cannot consume at line rate. Define FIFO fullness, packet-atomic drop policy and overflow notification before delivery.

## Datapath contract
TX byte-stream `{data[7:0],valid,ready,last,user_error}`; receiver byte-stream `{data[7:0],valid,last,user_error}`; PHY `{gmii_rxd[7:0],gmii_rx_dv,gmii_rx_er,gmii_txd[7:0],gmii_tx_en,gmii_tx_er}` and I/O-specific clocks. These are **conceptual net names** until core signature is agreed; the legacy upstream `s_axis_*` names are implementation-internal, not the CSR protocol. In separate-domain SoC integration provide FIFO/async handshake; direct timing-domain wiring is not permitted without a written synchronous-clock proof.

## PHY interface boundary
`ethernet_phy_if.sv` is justified for source-synchronous clock/data registration and TX clock forwarding. Generic oddr/sdr simulation proves behavior only, not FPGA I/O timing. Hardware variant shall select explicit `TARGET`/IODDR style, clocks, pinout and timing constraints for the chosen FPGA/PHY. External MDIO and link status are out of scope until commissioned.

## Counter and interrupt semantics (candidate)
Counter rolls modulo `2^32`, resets on CSR reset, increments for each captured event. A bad-FCS frame commonly qualifies also as a bad-frame event: both counters may increment; normative RX classification to be checked against RTL and customer signoff. `INTR_STATE` sticky/clear, `INTR_ENABLE` mask and `INTR_TEST` behavior follow generated reg core. On simultaneous event and SW W1C, the selected priority shall be explicitly tested. No manual replication of reggen interrupt logic.

## Completion blocker
This package intentionally provides no invented `ethernet_core.sv` claiming to connect multi-clock paths. Full RTL is **not** 'done' until a real synthesizable core is written, the FlexSoC generated top is elaborated with accurate SDC, and full-system RTL, lint and CDC/RDC pass.


---

## M4 source: TESTPLAN.md

# ETH-TP-001 — Verification and qualification plan

**Status:** engineering draft; model-only tests do not qualify integrated RTL. Machine-readable `spec/traceability.json` is the authoritative requirement↔test index (25 requirements; 21 testplan items).

| Gate | Test intent | Expected evidence | Closing criterion |
|---|---|---|---|
| A. M1/M2/M3 leaf differential | FCS 5 configs; TX GMII/MII/CE/PTP/padding 5 configs; RX 4 configs including bad FCS, PHY error; PHY GENERIC activity | M1 model + A/B JSON, M2 TX JSON, M3 RX and PHY JSON; pinned SHA-256 | Every leaf PASS with source hash freshness. User reports those gates PASS; verify stored files in WSL. |
| B. Independent model | Reflected Ethernet CRC32, preamble+SFD, FCS insertion/check, short padding, MII nibble ordering, 10/100/1000 mapping; candidate CSR state/IRQ counters | `pytest` log, JUnit, source-hash summary | All Python tests PASS; candidate policy explicitly unapproved. |
| C. CSR projection | Source of truth `functional/py/scenarios.py` and `ethernet_tests.py`; 4 CSR cases | `config.regs`, `data_in.vec`, `data_out.vec`, freshness check | Exact nine generated offsets match `ethernet_reg_pkg.sv`; actual `fx tests_gen --check` when installed. |
| D. Packet vector projection | Nine frame/error/speed examples from same scenario source | `packet_cases.json` with independently computed expected data, CRC and nibble order | Currently MODEL-ONLY. Add packet driver and capture when `ethernet_core.sv` port signature and clocks exist. |
| E. MAC integration | Functional TX/RX+PHY+CSR in one top; packet loopback through PHY BFM | RTL SV+cocotb logs/waves, tests for packet content and true clocked latency | **NOT RUN** until core/top implemented; user-reported leaf A/B does not close this. |
| F. 3-speed & CDC | 2.5M/25M/125M PHY clocks; CSR async phase; configure during frame; event bursts, reset, FIFO overflow | Multi-clock testbenches, asserted protocol properties, SDC, `fx cdc_rdc` report | No unsynchronized crossings or unresolved RDC; events accounted for without loss. |
| G. Lint/formal | Whole generated Ethernet top with vendor leaf filelist; assertions for stream stability/FCS and CDC handshakes | `fx lint` Slang+Verilator, `fx formal` proofs/cover | No unresolved P0/P1, valid proof scopes; waivers reviewed individually. |
| H. FlexSoC L2 | Common spec, trace, model, vectors, SV/cocotb RTL regression, qualification view | `fx tests_gen --check`, `fx mtest --check` (where supported), `fx regression`, `fx qualify` | L2 only after real tool evidence passes. |
| I. FPGA | 10M/100M/1000M on chosen hardware PHY with vendor-target I/O/clock implementation | STA/setup/hold, pin constraints, on-board loopback and FCS counters | Target and PHY specified; no claim based solely on GENERIC PHY. |

## Functional CSR tests (ready as machine-owned vectors)
`reset_defaults`: CTRL 0, IFG 12, INTR_ENABLE 0. `control_rw`: CTRL 0→3→0 readback. `ifg_rw`: IFG 12→16→12 readback. `irq_enable_rw`: INTR_ENABLE 0→7→0 readback. These check **CSR storage**, not live TX/RX behavior. All other readback/status requirements need integrated core test support.

## Packet tests (oracle-derived, not RTL vectors yet)
`gmii_min_1000`, `gmii_pad_1000`, `mii_100`, `mii_10`, `gmii_bad_fcs`, `mii_phy_error`, `gmii_no_pad`, `gmii_long`, `gmii_ifg_20` exercise normal and negative frame semantics; actual PHY timing/error assertions must be added to the integrated testbench and linked to these IDs.

## Required nonvacuity and robustness
- At least one complete frame, preamble/SFD, payload and FCS per positive scenario; negative scenarios must trigger specific error signals.
- Verify **contents**, lengths, endings and idle spacing, not only activity counters.
- TX handshake stable under stalls; RX has no PHY backpressure; explicitly test FIFO overflow/drop behavior once specified.
- `INTR_STATE` sticky/W1C and counter coherence tested across asynchronous clock phase and reset.
- Toggling speed while a frame is in progress must be either forbidden/detected or have specified behavior; do not guess.
- Preserve all binary evidence/logs and generated source SHA; no auto-PASS from file existence.


---

## M4 source: CDC_RDC.md

# ETH-CDC-001 — CDC / RDC signoff checklist

**Current status: not analyzed for integrated MAC.** Single CSR clock in existing codegen was a **register generation convenience**, not a valid declaration for the final multi-clock IP.

| Crossing | Source → Destination | Proposed protection | Required stress/structural checks |
|---|---|---|---|
| CTRL.TX_ENABLE+IFG | CSR → TX | stable snapshot req/ack, frame-boundary apply | asynchronous phase, rapid writes, reset mid-handshake |
| CTRL.RX_ENABLE | CSR → RX | two-phase control ack, frame-boundary apply | disable in-frame, asynchronous reset |
| TX_UNDERFLOW event | TX → CSR | lossless event counter/queue, not raw 2FF pulse | back-to-back event stress, wrap, reset |
| RX_BAD_FRAME/FCS | RX → CSR | lossless event transfer or proved bounded source rate | same-cycle events, overlapping flags |
| STATUS.TX/RX_ENABLED | MAC domain → CSR | stable ack payload | coherent status vs CFG_PENDING |
| STATUS.SPEED_VALID+SPEED | PHY detector → CSR | coherent sample with validation interval | 10↔100↔1000 switch, link glitches |
| Packets TX | System packet source → TX | async FIFO if unrelated clock | overflow/underflow, packet atomicity, full/empty |
| Packets RX | RX → system sink | async frame FIFO, overflow/drop policy | no receiver backpressure, burst/frame errors |
| Reset | each clock island | per-domain reset synchronizer | async assert and sync release, reset sequencing |
| PHY clock forwarding | GTX/MII ↔ I/O | FPGA resources and timing constraints | generated clocks, pin skew, timing STA |

Never waive an unknown crossing as 'false' solely to make `fx cdc_rdc` pass. Review the actual `dv/cdc_rdc/summary.json`, `cdc_rdc.rpt`, SDC, and lint warnings. Evidence from `TARGET=GENERIC` does not satisfy hardware I/O CDC/STA review.

---

## Traceable technical design allocation (engineering DRAFT)

The entries below are an indexing projection of the M4 technical requirements and existing
engineering requirements. They do not assert that implementation or testing is complete.

### TDS-001 — Allocation of TRS-001

Customer refs: CRS-001

GMII mode shall process one octet per enabled MAC tick at 125 MHz for Gigabit; MII shall process low nibble first at 25 or 2.5 MHz at 100 or 10M.

Allocated requirements: REQ-PHY-01

Verification intent: Mode, cadence, nibble-order tests, hardware timing

**Lifecycle: PROPOSED; evidence NOT CLOSED.**

### TDS-002 — Allocation of TRS-002

Customer refs: CRS-002

TX shall generate 7×0x55 + 0xD5, data bytes, pad to 60 octets before FCS by default, append little-endian FCS of CRC32(poly reflected 0xEDB88320, init/final XOR 0xffffffff).

Allocated requirements: REQ-TX-01, REQ-TX-02

Verification intent: Known answer + frame oracle

**Lifecycle: PROPOSED; evidence NOT CLOSED.**

### TDS-003 — Allocation of TRS-003

Customer refs: CRS-002, CRS-004

TX IFG shall be no less than minimum applicable IEEE requirement; legal programmable values must be enforced once customer accepts range.

Allocated requirements: REQ-CSR-03, REQ-TX-03

Verification intent: Boundary + on-wire idle-cycle monitor

**Lifecycle: PROPOSED; evidence NOT CLOSED.**

### TDS-004 — Allocation of TRS-004

Customer refs: CRS-003

RX shall verify FCS, classify errors and deliver payload excluding preamble/FCS with reliable end-of-frame indication.

Allocated requirements: REQ-RX-01, REQ-RX-02, REQ-RX-03

Verification intent: Good, bad FCS, PHY error, reset tests

**Lifecycle: PROPOSED; evidence NOT CLOSED.**

### TDS-005 — Allocation of TRS-005

Customer refs: CRS-004

Exactly one CSR HJSON shall be authoritative; 9 registers at generated offsets 0x00..0x20; `reg2hw` drives controls and `hw2reg` drives statuses/events.

Allocated requirements: REQ-CSR-01, REQ-CSR-02, REQ-CSR-07

Verification intent: Source hash, reggen, generated SV consistency

**Lifecycle: PROPOSED; evidence NOT CLOSED.**

### TDS-006 — Allocation of TRS-006

Customer refs: CRS-004

Hardware error counts shall update without lost pulses across TX/RX→CSR crossings; sticky interrupts are independently testable via INTR_ENABLE and INTR_TEST.

Allocated requirements: REQ-CSR-04, REQ-CSR-06

Verification intent: Pulse burst, simultaneous clear, async clocks

**Lifecycle: PROPOSED; evidence NOT CLOSED.**

### TDS-007 — Allocation of TRS-007

Customer refs: CRS-002, CRS-003, CRS-005

Packet data shall not flow through the CSR address space; TX ready/valid handshake shall hold until accepted. RX traffic shall have a documented sink/drop/overflow policy.

Allocated requirements: REQ-TX-04, REQ-RX-04, REQ-CDC-04

Verification intent: Stream protocol assertions

**Lifecycle: PROPOSED; evidence NOT CLOSED.**

### TDS-008 — Allocation of TRS-008

Customer refs: CRS-004, CRS-006

Cross-domain multi-bit config (`IFG`, enable) shall transfer coherently using a documented commit/ack scheme. Status and events shall use proper synchronizers/handshakes or async queues; async resets shall deassert synchronously.

Allocated requirements: REQ-CSR-05, REQ-CDC-01, REQ-CDC-02, REQ-CDC-03

Verification intent: CDC signoff + dynamic stress

**Lifecycle: PROPOSED; evidence NOT CLOSED.**

### TDS-009 — Allocation of TRS-009

Customer refs: CRS-002, CRS-007

Every converted leaf shall be reproducible from pinned upstream source SHA and shall match it cycle-by-cycle for bounded verified stimuli.

Allocated requirements: REQ-TX-05, REQ-QUAL-01

Verification intent: M1/M2/M3 summary.json freshness

**Lifecycle: PROPOSED; evidence NOT CLOSED.**

### TDS-010 — Allocation of TRS-010

Customer refs: CRS-008

Functional test intent shall originate in Python; projected `config.regs`, `data_in.vec`, `data_out.vec` shall be generated, checked for freshness and shared across control-bus variants.

Allocated requirements: REQ-QUAL-02

Verification intent: `tests_gen --check`, vector generation tests

**Lifecycle: PROPOSED; evidence NOT CLOSED.**

### TDS-011 — Allocation of TRS-011

Customer refs: CRS-008

Qualification PASS shall require evidenced RTL, lint, CDC/RDC, regression and traceability.

Allocated requirements: REQ-QUAL-03

Verification intent: `fx qualify`, provenance summary

**Lifecycle: PROPOSED; evidence NOT CLOSED.**

### TDS-012 — Allocation of TRS-012

Customer refs: CRS-009

Real FPGA PHY shall use approved clock resources and timing constraints; `TARGET=GENERIC` shall never be accepted as a board timing guarantee.

Allocated requirements: REQ-PHY-02

Verification intent: I/O timing reports and link tests

**Lifecycle: PROPOSED; evidence NOT CLOSED.**

