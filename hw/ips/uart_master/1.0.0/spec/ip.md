# UART Master — Digital IP specification

**Release:** 1.0.0  
**Status:** authored qualification baseline derived from the checked-in UART engine, host bridge, CSR contract, vector tests and formal properties.

## 1. Purpose

`uart_master` is a processorless SoC configuration/debug bridge. It receives compact commands over an asynchronous UART, converts them into a single outstanding host transaction toward the SoC interconnect, and serializes read responses back to the UART transmitter.

The release also exposes the UART control/status CSR set for local configuration of the serial engine.

## 2. Release scope

Release 1.0.0 publishes **only `interfaces/tlul`**. No `reg_iface` or `axi_lite` package is claimed for this IP release.

The CSR device-side package is TL-UL. The outbound host bridge exposes the checked-in request/grant/response contract (`req/gnt`, address, write indication/data/byte enables, response valid/data/error) intended to connect through the FlexSoC TL-UL host adapter to the SoC crossbar. The TL-UL adaptation itself remains an integration-layer responsibility.

Technology branches may be qualified independently for `sky130` and `ihp-sg13g2`. The release target is pre-PnR Netlist Qualified; routed physical sign-off is outside this baseline.

## 3. UART engine

The serial engine uses one clock and active-low reset, idle-high UART framing, eight data bits, NCO timing, optional parity, FIFOs, and the same loopback/filter behavior as the companion UART implementation. `cio_tx_en_o` is asserted by the current top-level contract.

`CTRL.RX` is retained in the inherited CSR map, but the current implementation continuously enables receive operation; release 1.0.0 does not claim RX-disable behavior.

## 4. Host command protocol

A request starts with `0xA5` followed by:

1. opcode: `0x00` read or `0x01` write;
2. one byte of byte-enable information;
3. 32-bit address encoded least-significant byte first;
4. for writes only, 32-bit write data encoded least-significant byte first.

The launched host address is aligned to a 32-bit word boundary. Reads launch with `be_o=0xF`, `we_o=0`, and zero write data. Writes propagate the low four byte-enable bits and payload.

Only one command is outstanding. Once launched, request metadata is held stable while `req_o` waits for `gnt_i`. Grant removes `req_o` and the bridge waits for `valid_i`.

## 5. Response behavior

For a write, completion at `valid_i` returns the parser to idle and no UART response packet is required by this protocol revision.

For a read, the bridge captures `rdata_i` and `err_i` and supplies an eight-byte response stream to the UART TX path:

`0x5A, 0x01, echoed opcode, status(error), data[31:24], data[23:16], data[15:8], data[7:0]`.

The response byte format is architecturally defined. Release 1.0.0 qualification directly proves the request-side handshake and models the response encoding; full bit-accurate end-to-end response serialization is retained as a stated verification gap until a dedicated serial response checker is enabled in the functional harness.

## 6. Reset and safety behavior

Parser, bus-request and response/TX state are reset through separate functional reset branches derived from the synchronized IP reset. After reset, no host request is active, write indication is clear, the aligned address is zero, and the bridge is ready to search for the next request SOF.

## 7. Verification intent

Directed UART tests cover serial/CSR basics. Host-directed tests cover read and write launch, address alignment, byte enables and deliberate grant backpressure. Formal properties cover reset state, request stability until grant, request removal after grant, address alignment and TX-enable contract. The Python protocol model is the executable reference for request and response byte encoding.

Post-synthesis GLS is bounded to `smoke`, `host_read`, and `host_write` over `ss`, `tt`, and `ff`. Physical sign-off is outside this release.

## 8. Non-claims

No concurrent/multiple-outstanding commands, burst transactions, protocol discovery, authentication, retransmission, timeout/retry policy, or non-TLUL CSR package is claimed. Full end-to-end serial checking of read-response bytes is a known qualification gap and prevents that sub-feature from being represented as independently closed evidence in release 1.0.0.
