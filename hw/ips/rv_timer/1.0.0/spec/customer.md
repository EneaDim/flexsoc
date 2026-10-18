# RV Timer — Customer Specification

**Document class:** Customer/Product Requirements Specification (CRS)
**Product:** Software-programmable timer · **Specification revision:** 1.0
**Lifecycle:** Draft for stakeholder review; not yet customer-approved
**Applies to:** One software-visible timer channel and its interrupt

## 1. Product objective

The system requires a low-complexity, memory-mapped timer that firmware can start, stop and configure. It shall maintain a programmable count and notify firmware when the count reaches a programmable threshold. It is intended for scheduling and software timeout use cases, not as a calibrated real-time clock or watchdog.

## 2. Context and stakeholders

Firmware programs the timer through a CSR interface. The SoC supplies a functional clock, active-low reset and interrupt routing. The timer provides a single logical channel for one hart. The firmware team owns the desired time-base conversion; the SoC integrator owns the physical clock frequency and interrupt destination.

**Use cases:** generate a one-shot notification using a threshold; change the effective tick rate; inspect or reinitialize the current timer count; mask or exercise the interrupt path during software bring-up.

## 3. Product requirements

### CRS-001 — Programmable time base

Firmware shall start and stop a timer, configure its division and increment behavior, inspect and write the current time value, and choose the compare threshold. The timer shall behave deterministically across reset, disable and reconfiguration. Count arithmetic shall use a documented bounded width and wrap behavior.

**Acceptance expectation:** the timer can be stopped, programmed, started and observed; changing the prescale and increment alters future count progression; reset returns all documented state to defaults.

### CRS-002 — Threshold interrupt and diagnostics

The timer shall produce a software-manageable event when the running time reaches or exceeds the programmed compare value. Firmware shall enable or mask the outgoing interrupt, observe the event state and exercise the interrupt path through a test mechanism. Reprogramming the threshold shall support recovery from a previously asserted compare condition.

**Acceptance expectation:** compare crossing, interrupt enable/mask, state clearing and test-event injection have deterministic outcomes.

### CRS-003 — Integration consistency

The programmed timer behavior, register meanings and interrupt semantics shall remain consistent across the supported and qualified register transport variants.

**Acceptance expectation:** identical functional tests are meaningful for each qualified interface package and actual execution results are recorded per variant.

## 4. Constraints and boundaries

- One hart, one timer channel and one interrupt are in scope.
- The timer runs from a SoC-provided digital clock; it does not establish wall-clock accuracy by itself.
- The implementation-level time width, division and step sizes shall be fixed in the technical specification and reflected in the CSR contract.
- Normal timing functions, reset, reconfiguration, compare and interrupt behavior require verification evidence before release.
- Performance and power targets are not specified in this customer-level contract.

## 5. Exclusions

Multi-hart/multi-channel capability, 64-bit machine time, clock calibration, watchdog features and GPIO-triggered activation/capture are not acceptance features for this revision. Any exposed implementation control outside the baseline must not be described as customer-qualified until a future specification and testplan covers it.

## 6. Product acceptance and evolution

Acceptance is based on an approved technical specification and a derived, tested set of requirements linked to these three product intents. The testplan may grow as verification proceeds, but missing executable evidence shall never be reported as a passed requirement. Stakeholder approval of this draft remains outstanding.
