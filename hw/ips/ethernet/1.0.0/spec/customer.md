# Ethernet — Customer requirements CANDIDATE (not baselined)

**Lifecycle: DRAFT / PROPOSED / NOT CUSTOMER-APPROVED.**

This file makes the M4 engineering reconstruction discoverable by FlexSoC.
It is not a signed or approved customer specification; the CRS below
contains unresolved product decisions and must be reviewed before L1/L2.

---

# ETH-CRS-001 — Customer Requirements Specification (candidate v0.1)

**Status: PROPOSED / not customer-approved.** This document is an engineering reconstruction of the user's stated product goal and pinned MIT upstream RTL, **not** an approved customer source. Each `CRS-*` claim requires an explicit review; unresolved choices are enumerated below. Any change to the approved scope must propagate through TRS/TDS, requirements, tests, implementation and trace.

## Intended product
A reusable, synthesizable, parameterized FlexSoC Ethernet MAC IP for FPGA and eventual SoC integration with **10/100/1000 Mb/s** over **MII/GMII**, packet transmission and reception, integrity checking, software-visible configuration/status/error statistics/interrupts and repeatable qualification. The SoC control-bus variant is selected by FlexSoC (TL-UL, Reg-IF, AXI-Lite); the register map and semantics must not change between variants. Vendor Verilog is a pinned *reference*, never silently edited.

## Candidate product requirements

### CRS-001 — Candidate requirement

Support full-duplex TX and RX at 10/100/1000 Mb/s via MII/GMII PHY.

Acceptance concept: Functional test for all three actual PHY clock rates and I/O width.

### CRS-002 — Candidate requirement

TX emits valid IEEE 802.3 preamble/SFD, optionally pads short frames, appends correct reflected Ethernet CRC-32 FCS and respects IFG.

Acceptance concept: Independent packet oracle and on-wire checker; boundary/random cases.

### CRS-003 — Candidate requirement

RX accepts valid frames, strips preamble/FCS and reports bad FCS and PHY errors without hiding malformed traffic.

Acceptance concept: Good/bad/error vectors; matching expected output/data/flags.

### CRS-004 — Candidate requirement

One hardware-generated CSR window configures TX/RX enable and IFG; exposes speed/status/3 error counters/3 IRQ events.

Acceptance concept: HJSON ↔ generated RTL ↔ CSR functional vectors.

### CRS-005 — Candidate requirement

Packet streaming datapath is separate from TL-UL/Reg-IF/AXI-Lite control interface.

Acceptance concept: Core top port inventory, throughput and backpressure tests.

### CRS-006 — Candidate requirement

Correct operation across independent SoC, TX and RX clocks/reset domains, including speed changes.

Acceptance concept: CDC/RDC structural evidence and multi-clock dynamic testing.

### CRS-007 — Candidate requirement

Preserve behavior of pinned upstream components during Verilog→SystemVerilog migration.

Acceptance concept: Independent per-cycle A/B with nonvacuous activity.

### CRS-008 — Candidate requirement

Support reusable FlexSoC qualification: CRS→TRS→TDS→REQ→TP→model→model tests→RTL regression→lint→CDC/RDC→L2 traceability.

Acceptance concept: Machine-checkable trace, fresh evidence, no silent PASS.

### CRS-009 — Candidate requirement

FPGA deployment shall use board-appropriate PHY I/O cells, clocks and constraints; GENERIC simulation is not timing signoff.

Acceptance concept: Real board timing and 10/100/1000 hardware tests.

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
