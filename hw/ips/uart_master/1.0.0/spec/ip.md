# UART Master — Technical Design Specification

**Document class:** TDS · **IP release:** 1.0.0 · **Status:** Engineering specification for qualification
**Upstream product contract:** [Customer Specification](customer.md) · **Derived obligations:** [Requirements](requirements.yaml) · **Verification allocation:** [Testplan](testplan.yaml)

## 1. Purpose and architecture

UART Master is a processor-independent serial command bridge for SoC register access. It comprises a configurable UART receive/transmit engine, a serial command parser, one outstanding host request controller and a read-response formatter. A remote UART peer sends commands; the bridge emits a SoC host request, waits for fabric acceptance and response, then returns to idle or emits read-response data.

The release supplies a **TL-UL device-side CSR package only** (`interfaces/tlul`) for configuring the UART engine. Separately, the outbound host port presents `req_o`, `gnt_i`, address, read/write indication, write data, byte enables, `valid_i`, return data and error. The SoC integrator supplies the host-to-TL-UL fabric adapter; the host port is not itself a second CSR transport. One functional clock and active-low reset are supplied by the SoC.

## 2. Transaction and state overview

A command starts with the frame marker and fixed-length command fields. A valid command triggers one request; request metadata must remain stable until grant. The controller then waits for a response. A completed write returns to command-idle; a completed read captures a reply for serialization. This design supports one outstanding transaction and deliberately does not provide burst or retry machinery.

## 3. Detailed behavioral requirements

### TDS-001 — UART command framing and decode

Customer refs: CRS-001

- A valid command starts with `0xA5` and an opcode (`0x00` for read, `0x01` for write).
- A one-byte byte-enable field follows, then a 32-bit address encoded least-significant byte first.
- A write additionally carries 32-bit write data, least-significant byte first. A read has no write-data payload.
- The parser may issue a host request only after receiving the required fields for a supported complete command. Unsupported/malformed-command recovery is not yet a qualified protocol service.

Allocated requirements: UM-PROTO-001

### TDS-002 — Host request representation

Customer refs: CRS-001

- Host addresses are aligned to 32-bit words before launch.
- A read produces one request with `we_o=0`, `be_o=0xF` and zero `wdata_o`.
- A write produces one request with `we_o=1`, the command payload in `wdata_o`, and the low four byte-enable bits in `be_o`.
- The SoC interconnect must supply a compatible request/grant/response implementation, independent of the device-side TL-UL CSR interface.

Allocated requirements: UM-HOST-001, UM-HOST-002

### TDS-003 — Outstanding transaction, grant and completion

Customer refs: CRS-001

- At most one host request is outstanding. While waiting for `gnt_i`, the bridge keeps `req_o` asserted and address, byte enables, write data and read/write indication stable.
- Grant accepts the request and deasserts `req_o`; the controller then awaits a matching `valid_i` response.
- A completed write returns to command-idle without requiring a serial reply packet.
- There is no automatic retry, timeout, request interleaving or multi-outstanding behavior in this revision.

Allocated requirements: UM-HOST-003, UM-HOST-004, UM-HOST-005

### TDS-004 — Local UART engine and CSR control

Customer refs: CRS-002

- The serial engine uses idle-high eight-bit UART framing, programmable NCO timing, optional parity, FIFO-backed data and status, loopback and digital input filtering.
- The local UART control/status register meanings follow the qualified CSR contract. The engine's device-side register interface is TL-UL only for this release.
- `CTRL.RX` remains visible but there is no release guarantee that clearing it disables the receive path.
- The system supplies the serial pad adaptation and a suitable clock-to-baud configuration.

Allocated requirements: UM-UART-001

### TDS-005 — Reset and pin safety

Customer refs: CRS-002

- Active-low reset returns the command parser and transaction/response state to idle, deasserts `req_o` and `we_o`, and clears the externally visible host address to an aligned idle value.
- The top-level output `cio_tx_en_o` remains asserted according to the digital pin-enable contract.
- A request interrupted by reset is not required to complete; the system handles reset-domain interactions with outstanding fabric transactions.

Allocated requirements: UM-RST-001, UM-TXEN-001

### TDS-006 — Remote read response format

Customer refs: CRS-003

- Read completion captures the fabric return data and error indication.
- The defined eight-byte response is `0x5A`, version `0x01`, echoed read opcode, one status/error byte, followed by read data in **most-significant-byte-first** order (`[31:24]`, `[23:16]`, `[15:8]`, `[7:0]`).
- The reference model shall encode this format independently of any UART bit-level implementation.
- **Verification status:** `UM-RESP-001` is planned. The byte-format model test does not qualify the complete RTL TX serialization path. Release and traceability reports must preserve this open gate.

Allocated requirements: UM-RESP-001

### TDS-007 — Device CSR package and host adaptation

Customer refs: CRS-004

- The released local control/status register package is `tlul` only; neither `reg_iface` nor `axi_lite` is included for UART Master.
- The outbound host side is a request/grant/response interface to be adapted by the SoC integration layer. The serial protocol does not imply any specific physical SoC address map.
- CSR offsets and access semantics are owned by the TL-UL package HJSON; qualification must not be reused as proof of a non-existent package.

Allocated requirements: UM-REG-001

## 4. Protocol examples

| Operation | Request byte order after `0xA5` | Host effect |
|---|---|---|
| Read | `00`, byte-enable, address `[7:0]`, `[15:8]`, `[23:16]`, `[31:24]` | Aligned read, all four byte enables |
| Write | `01`, byte-enable, little-endian address, little-endian write data | Aligned write with low four byte enables |
| Read reply | `5A 01`, echoed opcode, error status, data `[31:24]` … `[7:0]` | Serial return protocol (RTL gate open) |

The host `gnt_i` and `valid_i` may be delayed independently; acceptance and completion are distinct handshake events. No serial output is required for normal write completion.

## 5. Verification strategy and qualification boundary

Directed RTL tests cover parser-to-host read/write requests, alignment, low-nibble byte enables, backpressure and reset/idle. Formal properties target request stability, grant transition, reset state, address alignment and transmit output-enable. Reference-model tests verify command parsing and response-byte encoding using independent known-answer checks. A pass of any one category does not imply full end-to-end serial response coverage.

Post-synthesis GLS, where required by release policy, is bounded to `smoke`, `host_read` and `host_write` over `ss`, `tt`, `ff`. The open `UM-RESP-001` gate shall remain visible until actual serialized read responses are observed and checked. Physical sign-off is not part of this RTL-level technical contract.

## 6. Non-claims and integration assumptions

The remote peer must use supported UART timing and commands, and the SoC must supply legal host grant/response signaling. Burst requests, concurrent transactions, timeout/retry, authentication, access control, system security guarantees and unsupported CSR transports are excluded. Expanding scope requires a technical change, derived requirement, testplan and actual qualification evidence; no assumed customer sign-off is implied.
