# GPIO — Customer Specification

**Document class:** Customer/Product Requirements Specification (CRS)
**Product:** Four-channel GPIO peripheral · **Specification revision:** 1.0
**Lifecycle:** Draft for stakeholder review; not yet customer-approved
**Applies to:** GPIO functional capability independently of the register transport

## 1. Product objective

The product requires four software-controlled digital I/O channels for simple board-level control, observation and event notification. Each channel must be independently controllable as an output and usable as an input without a dedicated external interrupt controller inside the GPIO block. The product must offer optional rejection of short input disturbances.

## 2. Context, users and system boundary

Firmware configures the peripheral through a memory-mapped interface. The SoC supplies the functional clock, reset, CSR transport, and pad electrical implementation. External circuitry drives the input signals and consumes the outputs and output-enable signals. Physical pad drive strength and board-level voltage compatibility are outside this digital IP specification.

**Stakeholders:** firmware and board-support developers, SoC integrator, verification and release engineering.

**Use cases:** enable a digital output; sample an external state; ignore a transient input glitch; raise an interrupt on a selected edge or sustained level.

## 3. Product requirements

### CRS-001 — Configurable digital pads

Firmware shall independently drive four digital output values and output-enable controls and read four accepted digital input levels. The output values and enables shall be deterministic after reset, and shall retain a programmed value until changed by firmware or reset.

**Acceptance expectation:** every channel's output and output-enable can be programmed and read back; each input becomes visible through a synchronized software observation path.

### CRS-002 — Input conditioning

Firmware shall enable or disable digital input qualification separately for each pin. Enabled qualification shall reject short transients and eventually accept a sufficiently stable new input state, without impairing independently configured channels.

**Acceptance expectation:** transient and stable transitions are distinguished per selected pin, and the accepted state is visible to software.

### CRS-003 — Interrupt events

For each pin, firmware shall independently select rising-edge, falling-edge, high-level and low-level interrupt conditions. The externally visible interrupt indication shall assert when any enabled condition for that pin is satisfied.

**Acceptance expectation:** programmed edge and level events produce the expected pin-specific indication; disabled conditions do not contribute; level conditions reflect the current accepted input state.

### CRS-004 — Integration consistency

The four-channel feature set, register meanings and observable interrupt behavior shall remain consistent across the supported qualified memory-mapped register transports.

**Acceptance expectation:** equivalent functional results for each qualified register-interface variant, with transport protocol correctness verified in that variant's own qualification.

## 4. Product constraints and acceptance conditions

- Four channels are required; expansion beyond four channels is a separate product change.
- There is one SoC-supplied functional clock and active-low reset.
- Asynchronous pins require a defined input synchronization/qualification path before software observation and interrupt detection.
- Input filtering is specified by digital qualification behavior, not milliseconds; no board-level debounce duration is guaranteed.
- The product does not require an interrupt-status latch or software acknowledgement register in this revision.
- Acceptance requires exercised reset, output, input, filter and interrupt behaviors as well as recorded traceability and qualification results.

## 5. Out of scope

Open-drain output, alternate-function pin multiplexing, programmable drive strength, physical pad cells, software-cleared interrupt latches and analog/noise immunity guarantees are excluded. They must not be implied by completion of a GPIO digital-IP regression.

## 6. Approval and changes

This draft defines the intended product behavior pending stakeholder acceptance. The downstream technical specification determines implementation-level timing, registers and sampling rules. Product approval and engineering qualification remain separate gates. Material changes shall propagate through the CRS → TDS → requirements → testplan links.
