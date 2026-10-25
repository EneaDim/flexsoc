Referring to the [Comportable guideline for peripheral device functionality](https://opentitan.org/book/doc/contributing/hw/comportability), the module **`ethernet`** has the following hardware interfaces defined
- Primary Clock: **`clk_i`**
- Other Clocks: *none*
- Bus Device Interfaces (TL-UL): **`tl`**
- Bus Host Interfaces (TL-UL): *none*
- Peripheral Pins for Chip IO: *none*
- Inter-Module Signals: *none*
- Security Alerts: *none*
- Security Countermeasures: *none*

## Interrupts

| Interrupt Name   | Type   | Description                                                 |
|:-----------------|:-------|:------------------------------------------------------------|
| tx_underflow     | Event  | TX frame underflow event captured across TX->CSR CDC.       |
| rx_bad_frame     | Event  | RX malformed/error frame event captured across RX->CSR CDC. |
| rx_bad_fcs       | Event  | RX FCS mismatch event captured across RX->CSR CDC.          |

