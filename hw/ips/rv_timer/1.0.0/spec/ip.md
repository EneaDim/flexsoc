# RV Timer — Digital IP specification

**Release:** 1.0.0  
**Status:** authored qualification baseline derived from the checked-in CSR, RTL, functional vectors and formal properties.

## 1. Purpose

`rv_timer` is a single-hart, single-channel, 32-bit memory-mapped timer. It provides software-programmable activation, a 12-bit prescaler terminal count, an 8-bit increment step, a writable machine-time value, a compare threshold and one timer-expired interrupt.

## 2. Release scope

Release 1.0.0 supports `tlul`, `reg_iface`, and `axi_lite` package interfaces with identical CSR/timer semantics. Each package interface may be independently qualified for `sky130` and `ihp-sg13g2`. The target is pre-PnR Netlist Qualified; physical sign-off is deferred.

## 3. Clock and reset

The reference implementation uses one `clk_i` domain and active-low `rst_ni`. Reset clears the internal prescaler counter. Register-visible reset values are defined by the HJSON CSR contract.

## 4. Activation, prescale and step

`CTRL.active` enables normal timer operation. While inactive, the internal tick counter is held/returned to zero and the normal compare event is inactive.

While active, the counter increments each cycle until it reaches `CFG0.prescale`, then returns to zero. `tick` is asserted for the active terminal relation. On tick, `TIMER_V0` updates to `TIMER_V0 + CFG0.step` with natural 32-bit wraparound. Software may also write `TIMER_V0` directly.

## 5. Compare and interrupt

`COMPARE_V0` is the compare threshold. The timer event is active when the timer is active and `TIMER_V0 >= COMPARE_V0`.

The event feeds the generated interrupt helper:

- `INTR_ENABLE0.IE` masks the external timer interrupt;
- `INTR_STATE0.IS` records interrupt state with the generated rw1c semantics;
- `INTR_TEST0.T` can inject the interrupt test event;
- updating `COMPARE_V0` clears the implemented interrupt state through the hardware update path.

## 6. GPIO-trigger controls

`CTRL.gpio_intr_0` and `CTRL.gpio_intr_1` select an implementation-specific GPIO-triggered activation path. The checked-in RTL contains this logic, but its current toggle-style state transition is not yet defined by an adequate system-level functional contract. **Release 1.0.0 therefore does not baseline GPIO-triggered activation/capture behavior.** The fields remain software-visible implementation controls and require a future authored requirement plus dedicated DV before qualification.

## 7. Verification intent

Formal properties cover prescaler reset/transitions, tick relation, time arithmetic and compare relation. Directed simulation covers reset/default registers, configuration extremes, runtime reconfiguration, compare-triggered interrupt assertion, interrupt-state observation and compare-write clear. Deterministic random vectors broaden configuration values.

Post-synthesis GLS is bounded to `smoke`, `timer`, and `reconfig` over `ss`, `tt`, and `ff`. Post-PnR GLS and physical sign-off are outside release 1.0.0.

## 8. Non-claims

This release does not claim multiple harts/timers, 64-bit machine time, real-time frequency calibration, qualified GPIO-triggered capture semantics, watchdog behavior, or physical sign-off.
