## Summary

| Name                       | Offset   |   Length | Description                                        |
|:---------------------------|:---------|---------:|:---------------------------------------------------|
| cordic.[`CTRL`](#ctrl)     | 0x0      |        4 | Control register.                                  |
| cordic.[`STATUS`](#status) | 0x4      |        4 | Status register.                                   |
| cordic.[`X_IN`](#x_in)     | 0x8      |        4 | Signed fixed-point X input operand.                |
| cordic.[`Y_IN`](#y_in)     | 0xc      |        4 | Signed fixed-point Y input operand.                |
| cordic.[`Z_IN`](#z_in)     | 0x10     |        4 | Signed fixed-point Z input operand.                |
| cordic.[`X_OUT`](#x_out)   | 0x14     |        4 | Signed fixed-point X output result.                |
| cordic.[`Y_OUT`](#y_out)   | 0x18     |        4 | Signed fixed-point Y output result.                |
| cordic.[`Z_OUT`](#z_out)   | 0x1c     |        4 | Signed fixed-point Z output result.                |
| cordic.[`CFG`](#cfg)       | 0x20     |        4 | Configuration register for implementation options. |

## CTRL
Control register.
Software writes START to launch one operation.
MODE selects rotation or vectoring behavior.
SOFT_RST clears the internal control state.
- Offset: `0x0`
- Reset default: `0x0`
- Reset mask: `0xffffffff`

### Fields

```wavejson
{"reg": [{"name": "START", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "MODE", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "SOFT_RST", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "RSVD", "bits": 5, "attr": ["rw"], "rotate": 0}, {"name": "N_ITER", "bits": 8, "attr": ["rw"], "rotate": 0}, {"name": "RSVD2", "bits": 16, "attr": ["rw"], "rotate": 0}], "config": {"lanes": 1, "fontsize": 10, "vspace": 100}}
```

|  Bits  |  Type  |  Reset  | Name     | Description                                                                                                                          |
|:------:|:------:|:-------:|:---------|:-------------------------------------------------------------------------------------------------------------------------------------|
| 31:16  |   rw   |   0x0   | RSVD2    | Reserved.                                                                                                                            |
|  15:8  |   rw   |   0x0   | N_ITER   | Number of iterations requested for the current operation. A value of 0 may be interpreted by hardware as the implementation default. |
|  7:3   |   rw   |   0x0   | RSVD     | Reserved.                                                                                                                            |
|   2    |   rw   |   0x0   | SOFT_RST | Software reset pulse for the internal control logic.                                                                                 |
|   1    |   rw   |   0x0   | MODE     | Operation mode: 0 = rotation, 1 = vectoring.                                                                                         |
|   0    |   rw   |   0x0   | START    | Start a new CORDIC operation.                                                                                                        |

## STATUS
Status register.
BUSY is asserted while an operation is in progress.
VALID is asserted when output data are available.
ERROR may be used to signal invalid configuration or internal faults.
- Offset: `0x4`
- Reset default: `0x0`
- Reset mask: `0xffffffff`

### Fields

```wavejson
{"reg": [{"name": "BUSY", "bits": 1, "attr": ["ro"], "rotate": -90}, {"name": "VALID", "bits": 1, "attr": ["ro"], "rotate": -90}, {"name": "ERROR", "bits": 1, "attr": ["ro"], "rotate": -90}, {"name": "RSVD", "bits": 29, "attr": ["ro"], "rotate": 0}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                     |
|:------:|:------:|:-------:|:-------|:------------------------------------------------|
|  31:3  |   ro   |    x    | RSVD   | Reserved.                                       |
|   2    |   ro   |    x    | ERROR  | Sticky or pulse error indication from hardware. |
|   1    |   ro   |    x    | VALID  | Output data are valid.                          |
|   0    |   ro   |    x    | BUSY   | CORDIC core is busy processing an operation.    |

## X_IN
Signed fixed-point X input operand.
For sin/cos usage in rotation mode, software typically programs the
pre-scaled CORDIC gain compensation constant here.
- Offset: `0x8`
- Reset default: `0x0`
- Reset mask: `0xffffffff`

### Fields

```wavejson
{"reg": [{"name": "VALUE", "bits": 32, "attr": ["rw"], "rotate": 0}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                       |
|:------:|:------:|:-------:|:-------|:----------------------------------|
|  31:0  |   rw   |   0x0   | VALUE  | Signed fixed-point X input value. |

## Y_IN
Signed fixed-point Y input operand.
- Offset: `0xc`
- Reset default: `0x0`
- Reset mask: `0xffffffff`

### Fields

```wavejson
{"reg": [{"name": "VALUE", "bits": 32, "attr": ["rw"], "rotate": 0}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                       |
|:------:|:------:|:-------:|:-------|:----------------------------------|
|  31:0  |   rw   |   0x0   | VALUE  | Signed fixed-point Y input value. |

## Z_IN
Signed fixed-point Z input operand.
In rotation mode this is the input angle.
In vectoring mode this may be initialized to zero.
- Offset: `0x10`
- Reset default: `0x0`
- Reset mask: `0xffffffff`

### Fields

```wavejson
{"reg": [{"name": "VALUE", "bits": 32, "attr": ["rw"], "rotate": 0}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                       |
|:------:|:------:|:-------:|:-------|:----------------------------------|
|  31:0  |   rw   |   0x0   | VALUE  | Signed fixed-point Z input value. |

## X_OUT
Signed fixed-point X output result.
In vectoring mode this typically contains the magnitude estimate.
- Offset: `0x14`
- Reset default: `0x0`
- Reset mask: `0xffffffff`

### Fields

```wavejson
{"reg": [{"name": "VALUE", "bits": 32, "attr": ["ro"], "rotate": 0}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                        |
|:------:|:------:|:-------:|:-------|:-----------------------------------|
|  31:0  |   ro   |    x    | VALUE  | Signed fixed-point X output value. |

## Y_OUT
Signed fixed-point Y output result.
In rotation mode this typically contains the rotated Y component.
- Offset: `0x18`
- Reset default: `0x0`
- Reset mask: `0xffffffff`

### Fields

```wavejson
{"reg": [{"name": "VALUE", "bits": 32, "attr": ["ro"], "rotate": 0}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                        |
|:------:|:------:|:-------:|:-------|:-----------------------------------|
|  31:0  |   ro   |    x    | VALUE  | Signed fixed-point Y output value. |

## Z_OUT
Signed fixed-point Z output result.
In vectoring mode this typically contains the angle estimate.
- Offset: `0x1c`
- Reset default: `0x0`
- Reset mask: `0xffffffff`

### Fields

```wavejson
{"reg": [{"name": "VALUE", "bits": 32, "attr": ["ro"], "rotate": 0}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                        |
|:------:|:------:|:-------:|:-------|:-----------------------------------|
|  31:0  |   ro   |    x    | VALUE  | Signed fixed-point Z output value. |

## CFG
Configuration register for implementation options.
DATA_WIDTH and FRAC_WIDTH are exposed as read-only software-visible
constants when driven by hardware.
- Offset: `0x20`
- Reset default: `0x0`
- Reset mask: `0xffffffff`

### Fields

```wavejson
{"reg": [{"name": "DATA_WIDTH", "bits": 8, "attr": ["ro"], "rotate": 0}, {"name": "FRAC_WIDTH", "bits": 8, "attr": ["ro"], "rotate": 0}, {"name": "MAX_ITER", "bits": 8, "attr": ["ro"], "rotate": 0}, {"name": "RSVD", "bits": 8, "attr": ["ro"], "rotate": 0}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name       | Description                            |
|:------:|:------:|:-------:|:-----------|:---------------------------------------|
| 31:24  |   ro   |    x    | RSVD       | Reserved.                              |
| 23:16  |   ro   |    x    | MAX_ITER   | Maximum supported iteration count.     |
|  15:8  |   ro   |    x    | FRAC_WIDTH | Implemented number of fractional bits. |
|  7:0   |   ro   |    x    | DATA_WIDTH | Implemented datapath width in bits.    |

