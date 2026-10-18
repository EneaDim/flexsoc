# UART — Customer Specification

**Document class:** Customer/Product Requirements Specification (CRS)
**Product:** UART peripheral · **Specification revision:** 1.0
**Lifecycle:** Draft for stakeholder review; not yet customer-approved
**Applies to:** UART functional capability, independently of the host register transport

## 1. Product objective

The product requires a compact, software-managed serial communication peripheral for exchanging bytes with an external asynchronous serial peer. It must support simultaneous transmission and reception, basic fault rejection, local diagnostics, and predictable integration into a memory-mapped system. No external hardware-flow-control pins are required.

## 2. Operating context and boundaries

The peripheral is a device controlled by firmware through a register interface. It presents one serial receive input and one serial transmit output and operates from the system-provided functional clock and reset. The SoC integrator supplies the bus attachment, clock, reset and any external pad adaptation. The serial peer is outside the product boundary.

**Stakeholders:** firmware developer (configuration and diagnostics), SoC integrator (bus and pin integration), verification team (acceptance evidence).

**Use cases:** firmware sends a command stream; firmware receives bytes from a serial peer; firmware exercises loopback during bring-up; firmware enables input conditioning in a noisy environment.

## 3. Product requirements

### CRS-001 — Serial communication

The peripheral shall transmit and receive independent streams of eight-bit payloads over idle-high, asynchronous serial signals. Firmware shall be able to queue outgoing bytes, consume incoming bytes in order, and observe whether transmission or reception has pending data. Malformed serial frames shall not be delivered as valid received data.

**Acceptance expectation:** representative payloads, including all-zero, all-one and alternating-bit values, can be transferred in order; framing errors are rejected; FIFO occupancy and idle/busy indications are observable.

### CRS-002 — Configuration and diagnostics

Firmware shall configure the serial bit timing, optional parity and local diagnostic operating modes without requiring modification of the peripheral hardware. It shall be able to reset pending TX/RX data independently and inspect live state. Configuration changes between completed exchanges shall have predictable effects on subsequent traffic.

**Acceptance expectation:** programmed operating modes alter subsequent transfers; line and internal loopback permit basic bring-up without an external traffic generator; reset and status behavior are verifiable.

### CRS-003 — Input robustness

The peripheral shall offer software-selectable filtering of short disturbances on the asynchronous receive signal. When enabled, filtering shall reject disturbances below its qualification window while preserving the reception of stable, correctly timed frames.

**Acceptance expectation:** short noise pulses produce no spurious received byte, and stable serial frames remain receivable with filtering enabled.

### CRS-004 — Integration consistency

The same software-visible UART features and register-field behavior shall be offered through each supported and qualified memory-mapped register transport. Transport selection shall not change the serial behavior.

**Acceptance expectation:** the supported transports expose equivalent functional and register semantics in their respective qualification results.

## 4. Product constraints and quality expectations

- A single SoC-supplied functional clock and active-low reset are assumed.
- Only eight-bit payload framing and software-managed data flow are in scope for this specification revision.
- The integrator is responsible for selecting an appropriate clock and serial timing configuration for the connected peer.
- Reset, normal operation, error rejection and control/status observation must be covered by a verification plan; successful documentation mapping alone is not acceptance evidence.
- No numerical throughput, maximum clock frequency or silicon power target is specified at this level. Such limits require a separate system-level budget and qualification.

## 5. Exclusions

Hardware RTS/CTS flow control, configurable payload widths, a qualified break-detection feature, interrupt-delivery guarantees, and a full-range baud accuracy guarantee are not requested for this revision. Product changes to these boundaries require a CRS revision and downstream technical assessment.

## 6. Product acceptance and change control

Acceptance requires an approved technical specification, requirements derived from CRS-001 through CRS-004, a linked testplan, and recorded results for the implemented transport(s). Product approval of this draft is a separate decision from a successful engineering regression. Any changed product requirement retains its ID only if its intent is unchanged; otherwise allocate a new stable ID.
