## Summary

| Name                         | Offset   |   Length | Description               |
|:-----------------------------|:---------|---------:|:--------------------------|
| spi_host.[`CTRL`](#ctrl)     | 0x0      |        4 | UART control register     |
| spi_host.[`STATUS`](#status) | 0x4      |        4 | UART live status register |
| spi_host.[`RDATA`](#rdata)   | 0x8      |        4 | read data                 |
| spi_host.[`WDATA`](#wdata)   | 0xc      |        4 | write data                |

## CTRL
UART control register
- Offset: `0x0`
- Reset default: `0x0`
- Reset mask: `0x7`

### Fields

```wavejson
{"reg": [{"name": "EN", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "TXRST", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "RXRST", "bits": 1, "attr": ["rw"], "rotate": -90}, {"bits": 29}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description   |
|:------:|:------:|:-------:|:-------|:--------------|
|  31:3  |        |         |        | Reserved      |
|   2    |   rw   |   0x0   | RXRST  | RX FIFO reset |
|   1    |   rw   |   0x0   | TXRST  | TX FIFO reset |
|   0    |   rw   |   0x0   | EN     | enable        |

## STATUS
UART live status register
- Offset: `0x4`
- Reset default: `0x0`
- Reset mask: `0xf`

### Fields

```wavejson
{"reg": [{"name": "TXFULL", "bits": 1, "attr": ["ro"], "rotate": -90}, {"name": "TXEMPTY", "bits": 1, "attr": ["ro"], "rotate": -90}, {"name": "RXFULL", "bits": 1, "attr": ["ro"], "rotate": -90}, {"name": "RXEMPTY", "bits": 1, "attr": ["ro"], "rotate": -90}, {"bits": 28}], "config": {"lanes": 1, "fontsize": 10, "vspace": 90}}
```

|  Bits  |  Type  |  Reset  | Name    | Description        |
|:------:|:------:|:-------:|:--------|:-------------------|
|  31:4  |        |         |         | Reserved           |
|   3    |   ro   |    x    | RXEMPTY | RX Buffer is empty |
|   2    |   ro   |    x    | RXFULL  | RX Buffer is full  |
|   1    |   ro   |    x    | TXEMPTY | TX Buffer is empty |
|   0    |   ro   |    x    | TXFULL  | TX Buffer is full  |

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

