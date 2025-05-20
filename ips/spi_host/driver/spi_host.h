// Generated register defines for spi_host

#ifndef _SPI_HOST_REG_DEFS_
#define _SPI_HOST_REG_DEFS_

#ifdef __cplusplus
extern "C" {
#endif
// Register width
#define SPI_HOST_PARAM_REG_WIDTH 32

// UART control register
#define SPI_HOST_CTRL_REG_OFFSET 0x0
#define SPI_HOST_CTRL_REG_RESVAL 0x0u
#define SPI_HOST_CTRL_EN_BIT 0
#define SPI_HOST_CTRL_RST_BIT 1
#define SPI_HOST_CTRL_SETTING_MASK 0xffffu
#define SPI_HOST_CTRL_SETTING_OFFSET 16
#define SPI_HOST_CTRL_SETTING_FIELD \
  ((bitfield_field32_t) { .mask = SPI_HOST_CTRL_SETTING_MASK, .index = SPI_HOST_CTRL_SETTING_OFFSET })

// UART live status register
#define SPI_HOST_STATUS_REG_OFFSET 0x4
#define SPI_HOST_STATUS_REG_RESVAL 0x0u
#define SPI_HOST_STATUS_FULL_BIT 0
#define SPI_HOST_STATUS_EMPTY_BIT 1

// read data
#define SPI_HOST_RDATA_REG_OFFSET 0x8
#define SPI_HOST_RDATA_REG_RESVAL 0x0u
#define SPI_HOST_RDATA_RDATA_MASK 0xffu
#define SPI_HOST_RDATA_RDATA_OFFSET 0
#define SPI_HOST_RDATA_RDATA_FIELD \
  ((bitfield_field32_t) { .mask = SPI_HOST_RDATA_RDATA_MASK, .index = SPI_HOST_RDATA_RDATA_OFFSET })

// write data
#define SPI_HOST_WDATA_REG_OFFSET 0xc
#define SPI_HOST_WDATA_REG_RESVAL 0x0u
#define SPI_HOST_WDATA_WDATA_MASK 0xffu
#define SPI_HOST_WDATA_WDATA_OFFSET 0
#define SPI_HOST_WDATA_WDATA_FIELD \
  ((bitfield_field32_t) { .mask = SPI_HOST_WDATA_WDATA_MASK, .index = SPI_HOST_WDATA_WDATA_OFFSET })

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _SPI_HOST_REG_DEFS_
// End generated register defines for spi_host