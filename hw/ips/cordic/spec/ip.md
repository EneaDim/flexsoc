# cordic — Digital IP specification

> Baseline: **as-built / derived** from the checked-in CSR, RTL, functional tests and formal properties.
> Once reviewed and committed, the baselined requirements are authoritative for subsequent releases.

## Purpose

Configurable CORDIC accelerator with software-visible control/status and X/Y/Z input/output registers.

## Functional contract

- Operations are started and configured through the CSR block.
- BUSY reflects active core state; VALID/ERROR report completion state.
- X/Y/Z results are compared against the functional CORDIC reference model by generated tests.

## Clock and reset

- The current IP release uses the clock/reset topology declared by FlexSoC metadata and the checked-in RTL.
- Reset behavior is asynchronous assert / synchronous release where implemented by the reset distribution.

## Register interface

- CSR source of truth is the HJSON under the selected interface release.
- OpenTitan reggen uses canonical internal `reg_iface`; `REG_ITF` selects the external register transport (`reg_iface`, `tlul`, or `axi_lite`).

## Assumptions

- Single clock domain clk_i with active-low reset rst_ni.
- The register transport is selected by REG_ITF while the CSR definition remains canonical reg_iface.

## Known limitations

- This baseline captures the behavior already implemented and verified; it does not add unsupported CORDIC modes or numerical guarantees beyond the existing model/tests.
