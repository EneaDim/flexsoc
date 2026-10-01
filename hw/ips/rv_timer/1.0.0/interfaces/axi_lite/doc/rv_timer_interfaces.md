Referring to the [Comportable guideline for peripheral device functionality](https://opentitan.org/book/doc/contributing/hw/comportability), the module **`rv_timer`** has the following hardware interfaces defined
- Primary Clock: **`clk_i`**
- Other Clocks: *none*
- Bus Device Interfaces (TL-UL): **`tl`**
- Bus Host Interfaces (TL-UL): *none*
- Peripheral Pins for Chip IO: *none*
- Inter-Module Signals: *none*
- Security Alerts: *none*

## Interrupts

| Interrupt Name             | Type   | Description                                          |
|:---------------------------|:-------|:-----------------------------------------------------|
| timer_expired_hart0_timer0 | Event  | raised if hart0's timer0 expired (mtimecmp >= mtime) |

## Security Countermeasures

| Countermeasure ID      | Description                      |
|:-----------------------|:---------------------------------|
| RV_TIMER.BUS.INTEGRITY | End-to-end bus integrity scheme. |

