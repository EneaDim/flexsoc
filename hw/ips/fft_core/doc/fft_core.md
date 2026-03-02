## Summary

| Name                         | Offset   |   Length | Description               |
|:-----------------------------|:---------|---------:|:--------------------------|
| fft_core.[`CTRL`](#ctrl)     | 0x0      |        4 | UART control register     |
| fft_core.[`STATUS`](#status) | 0x4      |        4 | UART live status register |
| fft_core.[`RDATA`](#rdata)   | 0x8      |        4 | read data                 |
| fft_core.[`WDATA`](#wdata)   | 0xc      |        4 | write data                |

## CTRL
UART control register
- Offset: `0x0`
- Reset default: `0x0`
- Reset mask: `0xffff0003`

### Fields

```wavejson
{"reg": [{"name": "EN", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "RST", "bits": 1, "attr": ["rw"], "rotate": -90}, {"bits": 14}, {"name": "SETTING", "bits": 16, "attr": ["rw"], "rotate": 0}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name    | Description            |
|:------:|:------:|:-------:|:--------|:-----------------------|
| 31:16  |   rw   |   0x0   | SETTING | Basic setting 16 bits. |
|  15:2  |        |         |         | Reserved               |
|   1    |   rw   |   0x0   | RST     | reset                  |
|   0    |   rw   |   0x0   | EN      | enable                 |

## STATUS
UART live status register
- Offset: `0x4`
- Reset default: `0x0`
- Reset mask: `0x3`

### Fields

```wavejson
{"reg": [{"name": "FULL", "bits": 1, "attr": ["ro"], "rotate": -90}, {"name": "EMPTY", "bits": 1, "attr": ["ro"], "rotate": -90}, {"bits": 30}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description     |
|:------:|:------:|:-------:|:-------|:----------------|
|  31:2  |        |         |        | Reserved        |
|   1    |   ro   |    x    | EMPTY  | Buffer is empty |
|   0    |   ro   |    x    | FULL   | Buffer is full  |

## RDATA
read data
- Offset: `0x8`
- Reset default: `0x0`
- Reset mask: `0xff`

### Fields

```wavejson
{"reg": [{"name": "RDATA", "bits": 8, "attr": ["ro"], "rotate": 0}, {"bits": 24}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description   |
|:------:|:------:|:-------:|:-------|:--------------|
|  31:8  |        |         |        | Reserved      |
|  7:0   |   ro   |    x    | RDATA  |               |

## WDATA
write data
- Offset: `0xc`
- Reset default: `0x0`
- Reset mask: `0xff`

### Fields

```wavejson
{"reg": [{"name": "WDATA", "bits": 8, "attr": ["wo"], "rotate": 0}, {"bits": 24}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description   |
|:------:|:------:|:-------:|:-------|:--------------|
|  31:8  |        |         |        | Reserved      |
|  7:0   |   wo   |   0x0   | WDATA  |               |

