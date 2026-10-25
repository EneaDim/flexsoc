## Summary

| Name                                                 | Offset   |   Length | Description                                                                                                                                                |
|:-----------------------------------------------------|:---------|---------:|:-----------------------------------------------------------------------------------------------------------------------------------------------------------|
| ethernet.[`INTR_STATE`](#intr_state)                 | 0x0      |        4 | Interrupt State Register                                                                                                                                   |
| ethernet.[`INTR_ENABLE`](#intr_enable)               | 0x4      |        4 | Interrupt Enable Register                                                                                                                                  |
| ethernet.[`INTR_TEST`](#intr_test)                   | 0x8      |        4 | Interrupt Test Register                                                                                                                                    |
| ethernet.[`CTRL`](#ctrl)                             | 0xc      |        4 | TX/RX enable requests. Software writes are held in CSR clock domain and transferred to respective MAC clock domains.                                       |
| ethernet.[`IFG`](#ifg)                               | 0x10     |        4 | Requested TX inter-frame gap in octet-times. Hardware must follow preserved upstream behavior; legal range and update policy await specification approval. |
| ethernet.[`STATUS`](#status)                         | 0x14     |        4 | Synchronized view of MAC configuration and detected speed; NOT PHY link state.                                                                             |
| ethernet.[`TX_UNDERFLOW_COUNT`](#tx_underflow_count) | 0x18     |        4 | Number of TX underflow events captured in CSR domain since reset; wraps modulo 2^32.                                                                       |
| ethernet.[`RX_BAD_FRAME_COUNT`](#rx_bad_frame_count) | 0x1c     |        4 | Number of RX bad frame events captured in CSR domain since reset; wraps modulo 2^32.                                                                       |
| ethernet.[`RX_BAD_FCS_COUNT`](#rx_bad_fcs_count)     | 0x20     |        4 | Number of RX bad-FCS events captured in CSR domain since reset; wraps modulo 2^32.                                                                         |

## INTR_STATE
Interrupt State Register
- Offset: `0x0`
- Reset default: `0x0`
- Reset mask: `0x7`

### Fields

```wavejson
{"reg": [{"name": "tx_underflow", "bits": 1, "attr": ["rw1c"], "rotate": -90}, {"name": "rx_bad_frame", "bits": 1, "attr": ["rw1c"], "rotate": -90}, {"name": "rx_bad_fcs", "bits": 1, "attr": ["rw1c"], "rotate": -90}, {"bits": 29}], "config": {"lanes": 1, "fontsize": 10, "vspace": 140}}
```

|  Bits  |  Type  |  Reset  | Name         | Description                                                 |
|:------:|:------:|:-------:|:-------------|:------------------------------------------------------------|
|  31:3  |        |         |              | Reserved                                                    |
|   2    |  rw1c  |   0x0   | rx_bad_fcs   | RX FCS mismatch event captured across RX->CSR CDC.          |
|   1    |  rw1c  |   0x0   | rx_bad_frame | RX malformed/error frame event captured across RX->CSR CDC. |
|   0    |  rw1c  |   0x0   | tx_underflow | TX frame underflow event captured across TX->CSR CDC.       |

## INTR_ENABLE
Interrupt Enable Register
- Offset: `0x4`
- Reset default: `0x0`
- Reset mask: `0x7`

### Fields

```wavejson
{"reg": [{"name": "tx_underflow", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "rx_bad_frame", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "rx_bad_fcs", "bits": 1, "attr": ["rw"], "rotate": -90}, {"bits": 29}], "config": {"lanes": 1, "fontsize": 10, "vspace": 140}}
```

|  Bits  |  Type  |  Reset  | Name         | Description                                                            |
|:------:|:------:|:-------:|:-------------|:-----------------------------------------------------------------------|
|  31:3  |        |         |              | Reserved                                                               |
|   2    |   rw   |   0x0   | rx_bad_fcs   | Enable interrupt when [`INTR_STATE.rx_bad_fcs`](#intr_state) is set.   |
|   1    |   rw   |   0x0   | rx_bad_frame | Enable interrupt when [`INTR_STATE.rx_bad_frame`](#intr_state) is set. |
|   0    |   rw   |   0x0   | tx_underflow | Enable interrupt when [`INTR_STATE.tx_underflow`](#intr_state) is set. |

## INTR_TEST
Interrupt Test Register
- Offset: `0x8`
- Reset default: `0x0`
- Reset mask: `0x7`

### Fields

```wavejson
{"reg": [{"name": "tx_underflow", "bits": 1, "attr": ["wo"], "rotate": -90}, {"name": "rx_bad_frame", "bits": 1, "attr": ["wo"], "rotate": -90}, {"name": "rx_bad_fcs", "bits": 1, "attr": ["wo"], "rotate": -90}, {"bits": 29}], "config": {"lanes": 1, "fontsize": 10, "vspace": 140}}
```

|  Bits  |  Type  |  Reset  | Name         | Description                                                     |
|:------:|:------:|:-------:|:-------------|:----------------------------------------------------------------|
|  31:3  |        |         |              | Reserved                                                        |
|   2    |   wo   |   0x0   | rx_bad_fcs   | Write 1 to force [`INTR_STATE.rx_bad_fcs`](#intr_state) to 1.   |
|   1    |   wo   |   0x0   | rx_bad_frame | Write 1 to force [`INTR_STATE.rx_bad_frame`](#intr_state) to 1. |
|   0    |   wo   |   0x0   | tx_underflow | Write 1 to force [`INTR_STATE.tx_underflow`](#intr_state) to 1. |

## CTRL
TX/RX enable requests. Software writes are held in CSR clock domain and transferred to respective MAC clock domains.
- Offset: `0xc`
- Reset default: `0x0`
- Reset mask: `0x3`

### Fields

```wavejson
{"reg": [{"name": "TX_ENABLE", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "RX_ENABLE", "bits": 1, "attr": ["rw"], "rotate": -90}, {"bits": 30}], "config": {"lanes": 1, "fontsize": 10, "vspace": 110}}
```

|  Bits  |  Type  |  Reset  | Name      | Description                               |
|:------:|:------:|:-------:|:----------|:------------------------------------------|
|  31:2  |        |         |           | Reserved                                  |
|   1    |   rw   |   0x0   | RX_ENABLE | Request RX enable; default 0 after reset. |
|   0    |   rw   |   0x0   | TX_ENABLE | Request TX enable; default 0 after reset. |

## IFG
Requested TX inter-frame gap in octet-times. Hardware must follow preserved upstream behavior; legal range and update policy await specification approval.
- Offset: `0x10`
- Reset default: `0xc`
- Reset mask: `0xff`

### Fields

```wavejson
{"reg": [{"name": "VALUE", "bits": 8, "attr": ["rw"], "rotate": 0}, {"bits": 24}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                              |
|:------:|:------:|:-------:|:-------|:-----------------------------------------------------------------------------------------|
|  31:8  |        |         |        | Reserved                                                                                 |
|  7:0   |   rw   |   0xc   | VALUE  | Inter-frame gap parameter delivered coherently to TX clock domain; reset 12 octet-times. |

## STATUS
Synchronized view of MAC configuration and detected speed; NOT PHY link state.
- Offset: `0x14`
- Reset default: `0x0`
- Reset mask: `0x3f`

### Fields

```wavejson
{"reg": [{"name": "SPEED", "bits": 2, "attr": ["ro"], "rotate": -90}, {"name": "SPEED_VALID", "bits": 1, "attr": ["ro"], "rotate": -90}, {"name": "TX_ENABLED", "bits": 1, "attr": ["ro"], "rotate": -90}, {"name": "RX_ENABLED", "bits": 1, "attr": ["ro"], "rotate": -90}, {"name": "CFG_PENDING", "bits": 1, "attr": ["ro"], "rotate": -90}, {"bits": 26}], "config": {"lanes": 1, "fontsize": 10, "vspace": 130}}
```

|  Bits  |  Type  |  Reset  | Name        | Description                                                                           |
|:------:|:------:|:-------:|:------------|:--------------------------------------------------------------------------------------|
|  31:6  |        |         |             | Reserved                                                                              |
|   5    |   ro   |   0x0   | CFG_PENDING | At least one CTRL/IFG update has not yet been acknowledged by its destination domain. |
|   4    |   ro   |   0x0   | RX_ENABLED  | Effective RX enable acknowledged by RX domain.                                        |
|   3    |   ro   |   0x0   | TX_ENABLED  | Effective TX enable acknowledged by TX domain.                                        |
|   2    |   ro   |   0x0   | SPEED_VALID | Detector has held a stable speed for the specified qualification interval.            |
|  1:0   |   ro   |   0x0   | SPEED       | Detected speed: 0=10M,1=100M,2=1000M,3=invalid/unknown. Sampled via coherent CDC.     |

## TX_UNDERFLOW_COUNT
Number of TX underflow events captured in CSR domain since reset; wraps modulo 2^32.
- Offset: `0x18`
- Reset default: `0x0`
- Reset mask: `0xffffffff`

### Fields

```wavejson
{"reg": [{"name": "VALUE", "bits": 32, "attr": ["ro"], "rotate": 0}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                       |
|:------:|:------:|:-------:|:-------|:------------------------------------------------------------------|
|  31:0  |   ro   |   0x0   | VALUE  | CSR-domain event counter, coherently readable as 32-bit register. |

## RX_BAD_FRAME_COUNT
Number of RX bad frame events captured in CSR domain since reset; wraps modulo 2^32.
- Offset: `0x1c`
- Reset default: `0x0`
- Reset mask: `0xffffffff`

### Fields

```wavejson
{"reg": [{"name": "VALUE", "bits": 32, "attr": ["ro"], "rotate": 0}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                       |
|:------:|:------:|:-------:|:-------|:------------------------------------------------------------------|
|  31:0  |   ro   |   0x0   | VALUE  | CSR-domain event counter, coherently readable as 32-bit register. |

## RX_BAD_FCS_COUNT
Number of RX bad-FCS events captured in CSR domain since reset; wraps modulo 2^32.
- Offset: `0x20`
- Reset default: `0x0`
- Reset mask: `0xffffffff`

### Fields

```wavejson
{"reg": [{"name": "VALUE", "bits": 32, "attr": ["ro"], "rotate": 0}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                       |
|:------:|:------:|:-------:|:-------|:------------------------------------------------------------------|
|  31:0  |   ro   |   0x0   | VALUE  | CSR-domain event counter, coherently readable as 32-bit register. |

