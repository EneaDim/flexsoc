# GPIO — Digital IP specification

**Release:** 1.0.0  
**Status:** authored qualification baseline derived from the checked-in 4-bit CSR, RTL, vectors and formal properties.

## 1. Purpose

`gpio` is a four-bit memory-mapped general-purpose I/O controller. It provides direct output/output-enable state, synchronized software-visible inputs, independently programmable input filtering, and per-pin rising/falling/high/low interrupt conditions.

## 2. Release scope

Release 1.0.0 supports `tlul`, `reg_iface`, and `axi_lite` package interfaces. The functional/CSR contract is invariant across these transports. Each interface may be independently qualified for `sky130` and `ihp-sg13g2`; pre-PnR Netlist Qualified is the current release target.

## 3. Clock, reset and pads

- one functional clock `clk_i` and active-low reset `rst_ni`;
- four asynchronous input pads `cio_gpio_i[3:0]`;
- four direct outputs `cio_gpio_o[3:0]`;
- four output enables `cio_gpio_en_o[3:0]`;
- four interrupt outputs `intr_gpio_o[3:0]`.

Reset clears the stored direct output and output-enable state. Input filtering/synchronization has its own reset-distribution branch but remains in the same reset family.

## 4. Direct I/O

`DIRECT.GPIO_O` and `DIRECT.GPIO_OE` update stored output/output-enable values when their generated register write strobes are asserted. Otherwise each stored value holds. Live state is returned through the CSR hardware-to-register path.

`DATA_IN.GPIO_IN` reports the accepted input value after synchronization/filtering.

## 5. Input filtering

`INTR_CTRL.EN_INPUT_FILTER` independently enables the filter for each pin. The implementation uses a four-bit counter threshold (`0xF`) and asynchronous-input synchronization. A short excursion shall be rejected while a sufficiently stable new input shall eventually become the accepted value.

## 6. Interrupt detection

For each pin, interrupt output is the OR of enabled conditions:

- `EN_RISING`: accepted input changes 0→1;
- `EN_FALLING`: accepted input changes 1→0;
- `EN_LVLHIGH`: accepted input is high;
- `EN_LVLLOW`: accepted input is low.

Edge detection compares the current accepted input against the previous accepted sample. Level detection is combinational from the accepted input.

## 7. Verification intent

Directed vectors cover reset/defaults, direct output/OE programming and hold behavior, input readback, level interrupts and filter rejection/acceptance. Formal properties cover output state behavior and the edge/level interrupt equations, closing requirements whose one-cycle edge pulses are less robustly expressed as fixed-cycle vectors. Deterministic random tests broaden CSR/input values.

Post-synthesis GLS is bounded to `smoke`, `interrupt_levels`, and `input_filter` over `ss`, `tt`, and `ff`. Physical sign-off is outside release 1.0.0.

## 8. Non-claims

This release is fixed at four GPIOs. It does not claim open-drain behavior, alternate-function muxing, drive-strength control, persistent/latched interrupt state, debounce timing expressed in real-world time, or physical pad-cell qualification.
