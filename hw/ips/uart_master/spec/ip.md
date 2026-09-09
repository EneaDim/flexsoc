# uart_master — Digital IP specification

> Baseline: **as-built / derived** from the checked-in CSR, RTL, functional tests and formal properties.
> Once reviewed and committed, the baselined requirements are authoritative for subsequent releases.

## Purpose

UART-based host bridge that converts supported host commands into a simple request/grant memory-style master interface.

## Functional contract

- The host bridge creates aligned read/write requests with address, write data and byte enables.
- Outstanding requests remain stable until granted.
- The UART transport/configuration remains software visible through its CSR block.

## Clock and reset

- The current IP release uses the clock/reset topology declared by FlexSoC metadata and the checked-in RTL.
- Reset behavior is asynchronous assert / synchronous release where implemented by the reset distribution.

## Register interface

- CSR source of truth is the HJSON under the selected interface release.
- OpenTitan reggen uses canonical internal `reg_iface`; `REG_ITF` selects the external register transport (`reg_iface`, `tlul`, or `axi_lite`).

## Assumptions

- Single clock domain clk_i with active-low reset rst_ni.
- gnt_i completes an asserted host request according to the implemented request/grant contract.

## Known limitations

- This baseline does not claim host protocols or transaction classes beyond those exercised by the existing host bridge tests.
