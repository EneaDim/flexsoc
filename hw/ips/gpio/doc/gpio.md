## Summary

| Name                           | Offset   |   Length | Description                                             |
|:-------------------------------|:---------|---------:|:--------------------------------------------------------|
| gpio.[`DATA_IN`](#data_in)     | 0x0      |        4 | Current filtered GPIO input value.                      |
| gpio.[`DIRECT`](#direct)       | 0x4      |        4 | Direct GPIO output values and output enables.           |
| gpio.[`INTR_CTRL`](#intr_ctrl) | 0x8      |        4 | Per-input interrupt detection and input-filter enables. |

## DATA_IN
Current filtered GPIO input value.
- Offset: `0x0`
- Reset default: `0x0`
- Reset mask: `0xf`

### Fields

```wavejson
{"reg": [{"name": "GPIO_IN", "bits": 4, "attr": ["ro"], "rotate": -90}, {"bits": 28}], "config": {"lanes": 1, "fontsize": 10, "vspace": 90}}
```

|  Bits  |  Type  |  Reset  | Name    | Description                         |
|:------:|:------:|:-------:|:--------|:------------------------------------|
|  31:4  |        |         |         | Reserved                            |
|  3:0   |   ro   |   0x0   | GPIO_IN | Filtered input value for GPIO[3:0]. |

## DIRECT
Direct GPIO output values and output enables.
- Offset: `0x4`
- Reset default: `0x0`
- Reset mask: `0xff`

### Fields

```wavejson
{"reg": [{"name": "GPIO_O", "bits": 4, "attr": ["rw"], "rotate": 0}, {"name": "GPIO_OE", "bits": 4, "attr": ["rw"], "rotate": -90}, {"bits": 24}], "config": {"lanes": 1, "fontsize": 10, "vspace": 90}}
```

|  Bits  |  Type  |  Reset  | Name    | Description                  |
|:------:|:------:|:-------:|:--------|:-----------------------------|
|  31:8  |        |         |         | Reserved                     |
|  7:4   |   rw   |    x    | GPIO_OE | Output enable for GPIO[3:0]. |
|  3:0   |   rw   |    x    | GPIO_O  | Output value for GPIO[3:0].  |

## INTR_CTRL
Per-input interrupt detection and input-filter enables.
- Offset: `0x8`
- Reset default: `0x0`
- Reset mask: `0xfffff`

### Fields

```wavejson
{"reg": [{"name": "EN_RISING", "bits": 4, "attr": ["rw"], "rotate": -90}, {"name": "EN_FALLING", "bits": 4, "attr": ["rw"], "rotate": -90}, {"name": "EN_LVLHIGH", "bits": 4, "attr": ["rw"], "rotate": -90}, {"name": "EN_LVLLOW", "bits": 4, "attr": ["rw"], "rotate": -90}, {"name": "EN_INPUT_FILTER", "bits": 4, "attr": ["rw"], "rotate": -90}, {"bits": 12}], "config": {"lanes": 1, "fontsize": 10, "vspace": 170}}
```

|  Bits  |  Type  |  Reset  | Name            | Description                                                    |
|:------:|:------:|:-------:|:----------------|:---------------------------------------------------------------|
| 31:20  |        |         |                 | Reserved                                                       |
| 19:16  |   rw   |   0x0   | EN_INPUT_FILTER | Enable the 16-sample input filter independently for GPIO[3:0]. |
| 15:12  |   rw   |   0x0   | EN_LVLLOW       | Enable active-low level interrupt detection for GPIO[3:0].     |
|  11:8  |   rw   |   0x0   | EN_LVLHIGH      | Enable active-high level interrupt detection for GPIO[3:0].    |
|  7:4   |   rw   |   0x0   | EN_FALLING      | Enable falling-edge interrupt detection for GPIO[3:0].         |
|  3:0   |   rw   |   0x0   | EN_RISING       | Enable rising-edge interrupt detection for GPIO[3:0].          |

