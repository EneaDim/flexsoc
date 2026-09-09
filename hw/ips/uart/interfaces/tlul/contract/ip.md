# uart — Digital IP specification

> Baseline: **as-built / derived** from the checked-in CSR, RTL, functional tests and formal properties.
> Once reviewed and committed, the baselined requirements are authoritative for subsequent releases.

## Purpose

Memory-mapped UART with transmit/receive FIFOs, programmable line configuration, loopback and receive filtering.

## Functional contract

- TX/RX configuration and FIFO control are software visible through CSR.
- Line loopback selects RX input as the transmitted line; system loopback follows the implemented internal loopback behavior.
- FIFO availability is reflected by STATUS fields.

## Clock and reset

- The current IP release uses the clock/reset topology declared by FlexSoC metadata and the checked-in RTL.
- Reset behavior is asynchronous assert / synchronous release where implemented by the reset distribution.

## Register interface

- CSR source of truth is the HJSON under the selected interface release.
- OpenTitan reggen uses canonical internal `reg_iface`; `REG_ITF` selects the external register transport (`reg_iface`, `tlul`, or `axi_lite`).

## Assumptions

- Single clock domain clk_i with active-low reset rst_ni.
- The register transport is selected by REG_ITF; UART functional pins are independent of that transport.

## Known limitations

- The baseline states only behavior exercised by existing UART RTL, tests and formal properties.
