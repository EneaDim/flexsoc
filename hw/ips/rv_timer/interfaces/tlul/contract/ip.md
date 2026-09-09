# rv_timer — Digital IP specification

> Baseline: **as-built / derived** from the checked-in CSR, RTL, functional tests and formal properties.
> Once reviewed and committed, the baselined requirements are authoritative for subsequent releases.

## Purpose

RISC-V style memory-mapped timer with programmable prescaler/step, machine-time counter, compare value and interrupt output.

## Functional contract

- A timer tick is generated from active state and the programmed prescaler relation.
- mtime advances by the configured step on the implemented timer update.
- Interrupt assertion compares active mtime against mtimecmp.

## Clock and reset

- The current IP release uses the clock/reset topology declared by FlexSoC metadata and the checked-in RTL.
- Reset behavior is asynchronous assert / synchronous release where implemented by the reset distribution.

## Register interface

- CSR source of truth is the HJSON under the selected interface release.
- OpenTitan reggen uses canonical internal `reg_iface`; `REG_ITF` selects the external register transport (`reg_iface`, `tlul`, or `axi_lite`).

## Assumptions

- Single clock domain clk_i with active-low reset rst_ni.
- Counter transition properties are governed by the local timer reset branch used by tick_count.

## Known limitations

- The current checked-in instance uses the implemented timer/channel count and 32-bit mtime behavior present in the RTL/property set.
