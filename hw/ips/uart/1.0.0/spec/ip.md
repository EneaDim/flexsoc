# UART — Technical Design Specification

**Document class:** TDS · **IP release:** 1.0.0 · **Status:** Engineering specification for qualification
**Upstream product contract:** [Customer Specification](customer.md) · **Derived obligations:** [Requirements](requirements.yaml) · **Verification allocation:** [Testplan](testplan.yaml)

## 1. Purpose and scope

This document specifies a programmable, memory-mapped, full-duplex, eight-bit asynchronous UART. It defines functional interfaces, reset, framing, receive validation, buffering, loopback, error behavior and the software-visible register contract. The same UART behavior applies to its `tlul`, `reg_iface` and `axi_lite` packages; each transport is separately qualified. Package collateral supplies the register map HJSON, which is authoritative for offsets, field access types and reset values. This document defines behavioral meaning, not duplicate address offsets.

**Functional boundary:** serial `rx_i` and `tx_o`, `clk_i`, `rst_ni`, the control/status register transport and FIFOs. Clock generation, physical pads and system-level interrupt policy are external responsibilities. One functional clock domain is used; `rx_i` is asynchronous to it.

## 2. Architecture and data flow

Firmware writes TX data into an eight-entry transmit FIFO. The serializer drives idle-high frames using the programmed NCO timing. The receive pin passes through synchronization and, optionally, digital noise filtering, then a framed receiver; accepted bytes enter a sixteen-entry receive FIFO for firmware readout. Status reports FIFO and serial state. A loopback multiplexer permits pin-level or internal-path diagnostics.

The NCO register controls nominal serial timing. Testbench profile `CTRL.NCO=0x8000` corresponds to a 32-clock bit cell in the reference configuration; this is a verification configuration, **not** a promised accuracy bound for arbitrary system clocks or NCO settings.

## 3. Detailed behavioral requirements

### TDS-001 — Clock, reset and serial framing

Customer refs: CRS-001

- `clk_i` clocks synchronous logic; active-low `rst_ni` establishes the reset state, including timing and receive synchronization.
- The serial signal is idle high. A frame consists of one low start bit, eight data bits transmitted LSB-first, optional parity, then a high stop interval.
- When enabled and given an accepted `WDATA` byte, the TX path transmits the complete payload with the active timing and parity settings. On reception, a correctly framed byte is made available in arrival order through `RDATA`.
- The receive datapath shall preserve at least `0x00`, `0xFF`, `0x55` and `0xAA`, which provide representative corner patterns.
- Reset must leave the externally observable FIFO/status interface in its documented idle/empty condition. The register-map HJSON owns the exact field defaults.

Allocated requirements: UART-RST-001, UART-TX-001, UART-RX-001, UART-DATA-001

### TDS-002 — FIFO and status interface

Customer refs: CRS-001

- `WDATA` is the software enqueue path to TX. `RDATA` is the software dequeue path from RX.
- `FIFO_CTRL.TXRST` and `FIFO_CTRL.RXRST` are independent write-triggered FIFO-clear controls.
- `FIFO_STATUS.TXLVL` and `FIFO_STATUS.RXLVL` report current fill levels.
- `STATUS.TXFULL`, `RXFULL`, `TXEMPTY`, `RXEMPTY`, `TXIDLE` and `RXIDLE` reflect the corresponding live FIFO or serial conditions; firmware shall not infer that a FIFO-empty indication alone guarantees line-idle.
- The reference configuration uses TX depth eight and RX depth sixteen. Overflow/underflow guarantees outside the existing FIFO acceptance semantics are not implied.

Allocated requirements: UART-FIFO-001, UART-FIFO-002, UART-STAT-001

### TDS-003 — Reception validity and parity

Customer refs: CRS-001

- Reception validates the stop framing. Frames with invalid stop framing shall not enter the RX FIFO.
- With `CTRL.PARITY_EN=1`, the receiver checks the parity selected by `CTRL.PARITY_ODD`; a mismatch causes that frame to be dropped.
- TX and RX use compatible parity configuration, and firmware may change parity between completed transactions.
- Dropped erroneous frames shall not be represented as successful received payloads. An independent parity/framing error counter or interrupt is not required by this release.

Allocated requirements: UART-RX-002, UART-PAR-001

### TDS-004 — Software configuration and timing

Customer refs: CRS-002

- `CTRL.TX` enables transmission; `CTRL.NCO` sets baud timing.
- `CTRL.NF`, `CTRL.SLPBK`, `CTRL.LLPBK`, `CTRL.PARITY_EN` and `CTRL.PARITY_ODD` select filtering, loopback and parity functions.
- Configuration settings control subsequent serial transactions. Reconfiguration while a frame is in progress has no separately qualified continuity guarantee.
- `CTRL.RX` remains in the software-visible map, but **RX-disable behavior when it is zero is not part of this release contract**.

Allocated requirements: UART-CFG-001

### TDS-005 — Diagnostic loopback paths

Customer refs: CRS-002

- In line loopback (`LLPBK`), `tx_o` reflects `rx_i`, with the internal RX path held in the loopback-safe idle condition.
- In system loopback (`SLPBK`), the serializer output is routed internally to the RX path, allowing queued transmit data to be received without an external serial connection; the external TX pin assumes the defined idle behavior of that mode.
- Loopback testing must distinguish pin routing from successful internal FIFO-to-FIFO delivery.

Allocated requirements: UART-LOOP-001, UART-LOOP-002

### TDS-006 — Receive-input qualification

Customer refs: CRS-003

- The asynchronous receive input is synchronized before serial decoding.
- `CTRL.NF` optionally selects a three-sample majority filter on the synchronized input.
- A short disturbance rejected by that majority filter shall not create a received byte. A stable correctly timed frame shall remain receivable.
- The filter is a digital rejection mechanism and does not establish physical-layer noise immunity or a calibrated time threshold.

Allocated requirements: UART-FILT-001

### TDS-007 — Register-transport contract

Customer refs: CRS-004

- `tlul`, `reg_iface` and `axi_lite` packages expose equivalent logical control, status and data semantics.
- The generated CSR HJSON and regmap are the source of truth for offsets, access types and field widths; this document fixes the transport-independent meaning.
- The protocol handshake of each transport belongs to its interface adapter and is verified in that interface's qualification. A passing result for one adapter does not qualify another.

Allocated requirements: UART-REG-001

## 4. Register and software integration summary

| Register group | Software purpose | Side effects |
|---|---|---|
| `CTRL` | Mode, transmit enable, NCO, parity, loopback, filter | Alters subsequent transfers |
| `WDATA` / `RDATA` | Enqueue TX / consume RX byte | FIFO push / pop |
| `FIFO_CTRL` | Independent FIFO reset | Write-triggered clear |
| `FIFO_STATUS` | TX/RX occupancy | Live observation |
| `STATUS` | Full, empty, idle states | Live observation |

## 5. Verification and acceptance strategy

Testplan items allocate reset/defaults, representative payloads, FIFO reads and clears, frame rejection, parity reconfiguration, line/system loopback and input-noise scenarios. Model checks can demonstrate abstract framing/parity independently, while RTL simulation must demonstrate actual FIFO and pin behavior. Formal checks address relevant register and state invariants; lint and CDC/RDC assess structural quality. An item linked to a test is *mapped*, not passed until actual evidence exists.

Release evidence is per supported interface and target technology. Post-synthesis GLS scope, where applicable, is `smoke`, `corners`, `reconfig` for `ss`, `tt`, `ff`. Physical sign-off and post-PnR GLS are not within this RTL functional contract.

## 6. Assumptions, exclusions and change policy

The system supplies a valid clock, reset, stable CSR transactions and a serial peer whose bit timing is compatible with the programmed NCO. This specification makes no claim to RTS/CTS, arbitrary data widths, line-break qualification, UART interrupt generation, complete baud accuracy over the NCO range, or `CTRL.RX` gating. A new feature requires a TDS change, derived requirement, verification allocation and execution evidence. Technical completion does not replace customer approval.
