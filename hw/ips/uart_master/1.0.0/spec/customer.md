# UART Master — Customer Specification

**Document class:** Customer/Product Requirements Specification (CRS)
**Product:** Serial-to-SoC register access bridge · **Specification revision:** 1.0
**Lifecycle:** Draft for stakeholder review; not yet customer-approved
**Applies to:** Remote command reception, SoC host requests and supported responses

## 1. Product objective

The product requires a compact way for a remote serial peer to initiate individual memory-mapped register transactions inside a SoC without executing code on the target CPU. The bridge is intended for controlled configuration and bring-up in a trusted environment. This revision is not a security-hardened debug port.

## 2. Use context and interfaces

A remote controller transmits framed commands over an asynchronous UART. The bridge is a device for local configuration registers and a host toward the SoC interconnect. The SoC integrator provides a compatible host adapter, clock, reset and serial pad connection. The remote controller owns command framing and interpretation of the response protocol.

**Stakeholders:** system bring-up engineer, firmware/test automation developer, SoC integrator, verification/release engineering.

**Use cases:** read a SoC configuration register; write selected bytes of a register; hold a request until the SoC grants it; recover from reset and send a subsequent command.

## 3. Product requirements

### CRS-001 — Remote host access

A remote UART peer shall issue single, bounded-length register read and write commands. The bridge shall translate a complete supported command into one correctly formed SoC host request, retain that request until accepted, and permit at most one outstanding transaction. No CPU participation is required for the bridge's transaction sequencing.

**Acceptance expectation:** read and write commands produce the intended aligned address, data and byte-enable information; backpressure does not corrupt a waiting request; a completed write permits a subsequent command.

### CRS-002 — Serial management and reset

The bridge shall provide software-configurable UART timing and framing controls, observable local serial state, and defined reset behavior. Serial pins and the outbound SoC request interface shall return to a documented safe state after reset.

**Acceptance expectation:** serial configuration behaves predictably, output enable has a defined state, and no stale host request survives reset.

### CRS-003 — Remote read results

A successful remote read shall have a defined, machine-decodable serial reply containing the operation identity, completion status and returned data. The protocol shall identify errors separately from returned data so the peer can make an explicit decision.

**Acceptance expectation:** reference reply encoding matches the protocol; end-to-end serialization on the physical UART must be separately demonstrated before this capability is considered RTL-qualified.

### CRS-004 — SoC attachment

The bridge shall expose a well-defined device-side register interface for configuration and a separate outbound host transaction contract suitable for attachment to the supported SoC interconnect. The initial release shall have an explicit supported interface list rather than implicitly claiming all bus formats.

**Acceptance expectation:** the qualified device interface and host adapter responsibilities are documented and verified at their appropriate boundaries.

## 4. System constraints and risk boundaries

- One host transaction at a time; no burst, pipelined or concurrent commands.
- The remote peer operates in a trusted environment. Authentication, authorization and secure debug policy belong to system integration, not this IP.
- A malformed or unsupported serial request shall not be assumed to have a recoverable response until that behavior is specified and qualified.
- No transaction timeout, automatic retry, retransmission or throughput requirement is imposed in this revision.
- Passing a Python encoder test is not evidence of the physical serial TX response path; acceptance reports must distinguish planned and executed coverage.

## 5. Exclusions

Burst transfers, multi-command queues, authentication, protocol discovery, recovery/retry guarantees, non-supported bus package variants, full system security and analog pad qualification are outside the initial release.

## 6. Approval and release criteria

The technical specification fixes serial and host formats; requirements allocate the behaviors; testplan items connect model, RTL and formal verification. CRS-003 has a recognized additional RTL evidence gate: release documentation must show it as open or partially covered until full response serialization is checked. Product sign-off of this draft is pending and is not inferred from an engineering PASS.
