/**
 * @file
 * @brief Generated register defines for fft_core
 */

#ifndef _FFT_CORE_REG_DEFS_
#define _FFT_CORE_REG_DEFS_


#include <stdint.h>

#define FFT_CORE_BASE 0x80000000

typedef uintptr_t fft_core_t;
int fft_core_init(fft_core_t base);
int fft_core_in(fft_core_t base);
void fft_core_out(fft_core_t base, char c);
int fft_core_putchar(int c);
int fft_core_puts(const char* str);

#ifdef __cplusplus
extern "C" {
#endif
// Register width
#define FFT_CORE_PARAM_REG_WIDTH 32

// UART control register
#define FFT_CORE_CTRL_REG_OFFSET 0x0
#define FFT_CORE_CTRL_REG_RESVAL 0x0u
#define FFT_CORE_CTRL_EN_BIT 0
#define FFT_CORE_CTRL_RST_BIT 1
#define FFT_CORE_CTRL_SETTING_MASK 0xffffu
#define FFT_CORE_CTRL_SETTING_OFFSET 16
#define FFT_CORE_CTRL_SETTING_FIELD \
  ((bitfield_field32_t) { .mask = FFT_CORE_CTRL_SETTING_MASK, .index = FFT_CORE_CTRL_SETTING_OFFSET })

// UART live status register
#define FFT_CORE_STATUS_REG_OFFSET 0x4
#define FFT_CORE_STATUS_REG_RESVAL 0x0u
#define FFT_CORE_STATUS_FULL_BIT 0
#define FFT_CORE_STATUS_EMPTY_BIT 1

// read data
#define FFT_CORE_RDATA_REG_OFFSET 0x8
#define FFT_CORE_RDATA_REG_RESVAL 0x0u
#define FFT_CORE_RDATA_RDATA_MASK 0xffu
#define FFT_CORE_RDATA_RDATA_OFFSET 0
#define FFT_CORE_RDATA_RDATA_FIELD \
  ((bitfield_field32_t) { .mask = FFT_CORE_RDATA_RDATA_MASK, .index = FFT_CORE_RDATA_RDATA_OFFSET })

// write data
#define FFT_CORE_WDATA_REG_OFFSET 0xc
#define FFT_CORE_WDATA_REG_RESVAL 0x0u
#define FFT_CORE_WDATA_WDATA_MASK 0xffu
#define FFT_CORE_WDATA_WDATA_OFFSET 0
#define FFT_CORE_WDATA_WDATA_FIELD \
  ((bitfield_field32_t) { .mask = FFT_CORE_WDATA_WDATA_MASK, .index = FFT_CORE_WDATA_WDATA_OFFSET })

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _FFT_CORE_REG_DEFS_
// End generated register defines for fft_core