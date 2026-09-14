# UART — Digital IP specification

**Release:** 1.0.0  
**Status:** authored qualification baseline derived from the checked-in CSR contract, RTL, functional vectors and formal properties.

This document is the architectural contract for the UART IP release. Requirements marked `baselined` are mandatory. Behavior explicitly listed as a non-claim is not qualified by this release.

## 1. Purpose

`uart` is a software-controlled full-duplex asynchronous serial peripheral with an 8-bit TX/RX datapath, independent transmit and receive FIFOs, NCO-based baud timing, optional parity, line/system loopback, a receive noise filter, and software-visible live FIFO/status state.

The architectural behavior and CSR semantics are common across register transports. FlexSoC may materialize this release with `tlul`, `reg_iface`, or `axi_lite`; changing the external CSR transport shall not change the UART contract.

## 2. Release and qualification scope

Release 1.0.0 supports package interfaces `tlul`, `reg_iface`, and `axi_lite`. Each interface may be independently qualified for `sky130` and `ihp-sg13g2`. The current release target is pre-PnR **Netlist Qualified**; routed physical sign-off is outside this baseline.

A package interface is qualified only when its own evidence satisfies the requested FlexSoC qualification level. The existence of one qualified interface or technology does not qualify the others.

## 3. Clock, reset and serial framing

- One functional clock, `clk_i`, and active-low reset, `rst_ni`.
- Reset assertion is asynchronous; release may be synchronized and distributed internally by FlexSoC-generated reset structures.
- `rx_i` is the asynchronous receive input; `tx_o` is the transmit output.
- Serial idle is logic one.
- Frames are one start bit, eight data bits LSB-first, optional parity, and stop/idle high.
- The reference DV configuration uses `CTRL.NCO=0x8000`, which gives a deterministic 32-clock bit cell in the checked-in model.

## 4. CSR contract

The authoritative register map is the HJSON carried by each materialized interface package. Register offsets and field semantics are invariant across qualified register transports.

### CTRL

`TX`, `NF`, `SLPBK`, `LLPBK`, `PARITY_EN`, `PARITY_ODD`, and `NCO` configure UART behavior. `CTRL.RX` remains software-visible for compatibility with the inherited register map, but the current RTL continuously enables the receive datapath; **release 1.0.0 does not claim RX-disable semantics for `CTRL.RX=0`**.

### Data and FIFO control

- Writing `WDATA` pushes one byte into the TX FIFO when accepted by the implemented FIFO interface.
- Reading `RDATA` consumes the current RX FIFO byte.
- `FIFO_CTRL.RXRST` and `FIFO_CTRL.TXRST` are write-triggered clear actions.
- `FIFO_STATUS.TXLVL/RXLVL` expose live fill levels.
- The current reference instance uses RX depth 16 and TX depth 8.

### Status

`STATUS.TXFULL`, `RXFULL`, `TXEMPTY`, `RXEMPTY`, `TXIDLE`, and `RXIDLE` reflect the live FIFO/serial state implemented by the RTL.

## 5. Transmit path

When TX is enabled, queued bytes are serialized using the active NCO and parity configuration. System-loopback tests exercise the full TX serializer, FIFO, RX deserializer and receive FIFO path without requiring an external serial peer.

## 6. Receive path

The asynchronous RX input is synchronized before decoding. Valid frames are queued in receive order. Frames with a framing error or a parity error are rejected and shall not be inserted into the RX FIFO.

## 7. Loopback modes

- **Line loopback (`LLPBK`)**: `tx_o` follows `rx_i`; the internal receive path is held at the loopback-safe idle value.
- **System loopback (`SLPBK`)**: the internal transmit stream feeds the receive datapath and external `tx_o` remains at the implemented idle behavior.

## 8. Parity

`PARITY_EN` enables parity in both directions and `PARITY_ODD` selects odd/even parity. Correctly formed parity frames are accepted. A frame with incorrect parity is rejected from the RX FIFO. Parity configuration may be changed between completed transactions.

## 9. Receive noise filter

When `NF` is enabled, the synchronized RX stream passes through the implemented three-sample majority filter. A one-cycle disturbance that is rejected by this filter shall not create a spurious byte; stable UART frames shall remain receivable.

## 10. Verification intent

Qualification combines directed vector simulation, deterministic random vectors, CSR/regmap tests, structural CDC/RDC analysis and formal properties. The directed catalogue explicitly covers reset/default status, corner payloads, FIFO consume/reset, line/system loopback, parity reconfiguration, bad-parity rejection, noise-filter rejection and stable-frame reception.

Post-synthesis GLS is intentionally bounded to `smoke`, `corners`, and `reconfig` over `ss`, `tt`, and `ff`. Post-PnR GLS and physical sign-off are not release-1.0.0 requirements.

## 11. Non-claims

Release 1.0.0 does not claim hardware flow control, variable word length, qualified line-break handling, qualified UART interrupt generation, exhaustive baud-rate accuracy over the full NCO range, or `CTRL.RX` disable behavior. Those features require explicit CSR/RTL and requirement/testplan coverage before they can enter the release contract.
