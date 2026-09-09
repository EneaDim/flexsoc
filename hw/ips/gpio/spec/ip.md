# gpio — Digital IP specification

> Baseline: **as-built / derived** from the checked-in CSR, RTL, functional tests and formal properties.
> Once reviewed and committed, the baselined requirements are authoritative for subsequent releases.

## Purpose

Four-bit memory-mapped GPIO with direct output/output-enable control, sampled inputs, programmable input filtering and interrupt conditions.

## Functional contract

- DIRECT.GPIO_O and GPIO_OE control the external GPIO output and output-enable state.
- DATA_IN exposes sampled input state.
- Interrupt generation supports rising, falling, high-level and low-level conditions.

## Clock and reset

- The current IP release uses the clock/reset topology declared by FlexSoC metadata and the checked-in RTL.
- Reset behavior is asynchronous assert / synchronous release where implemented by the reset distribution.

## Register interface

- CSR source of truth is the HJSON under the selected interface release.
- OpenTitan reggen uses canonical internal `reg_iface`; `REG_ITF` selects the external register transport (`reg_iface`, `tlul`, or `axi_lite`).

## Assumptions

- Single clock domain clk_i with active-low reset rst_ni.
- State assertions are governed by the local state reset branch used by the GPIO flops.

## Known limitations

- The current baseline covers the implemented 4-bit GPIO instance and its existing filter/interrupt behavior.
