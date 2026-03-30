/**
 * @file
 * @brief Generated register defines for cordic
 */

#ifndef _CORDIC_REG_DEFS_
#define _CORDIC_REG_DEFS_


#include <stdint.h>

#define CORDIC_BASE 0x80000000

typedef uintptr_t cordic_t;
int cordic_init(cordic_t base);
int cordic_in(cordic_t base);
void cordic_out(cordic_t base, char c);
int cordic_putchar(int c);
int cordic_puts(const char* str);

#ifdef __cplusplus
extern "C" {
#endif
// Register width
#define CORDIC_PARAM_REG_WIDTH 32

// Control register.
#define CORDIC_CTRL_REG_OFFSET 0x0
#define CORDIC_CTRL_REG_RESVAL 0x0u
#define CORDIC_CTRL_START_BIT 0
#define CORDIC_CTRL_MODE_BIT 1
#define CORDIC_CTRL_SOFT_RST_BIT 2
#define CORDIC_CTRL_RSVD_MASK 0x1fu
#define CORDIC_CTRL_RSVD_OFFSET 3
#define CORDIC_CTRL_RSVD_FIELD \
  ((bitfield_field32_t) { .mask = CORDIC_CTRL_RSVD_MASK, .index = CORDIC_CTRL_RSVD_OFFSET })
#define CORDIC_CTRL_N_ITER_MASK 0xffu
#define CORDIC_CTRL_N_ITER_OFFSET 8
#define CORDIC_CTRL_N_ITER_FIELD \
  ((bitfield_field32_t) { .mask = CORDIC_CTRL_N_ITER_MASK, .index = CORDIC_CTRL_N_ITER_OFFSET })
#define CORDIC_CTRL_RSVD2_MASK 0xffffu
#define CORDIC_CTRL_RSVD2_OFFSET 16
#define CORDIC_CTRL_RSVD2_FIELD \
  ((bitfield_field32_t) { .mask = CORDIC_CTRL_RSVD2_MASK, .index = CORDIC_CTRL_RSVD2_OFFSET })

// Status register.
#define CORDIC_STATUS_REG_OFFSET 0x4
#define CORDIC_STATUS_REG_RESVAL 0x0u
#define CORDIC_STATUS_BUSY_BIT 0
#define CORDIC_STATUS_VALID_BIT 1
#define CORDIC_STATUS_ERROR_BIT 2
#define CORDIC_STATUS_RSVD_MASK 0x1fffffffu
#define CORDIC_STATUS_RSVD_OFFSET 3
#define CORDIC_STATUS_RSVD_FIELD \
  ((bitfield_field32_t) { .mask = CORDIC_STATUS_RSVD_MASK, .index = CORDIC_STATUS_RSVD_OFFSET })

// Signed fixed-point X input operand.
#define CORDIC_X_IN_REG_OFFSET 0x8
#define CORDIC_X_IN_REG_RESVAL 0x0u

// Signed fixed-point Y input operand.
#define CORDIC_Y_IN_REG_OFFSET 0xc
#define CORDIC_Y_IN_REG_RESVAL 0x0u

// Signed fixed-point Z input operand.
#define CORDIC_Z_IN_REG_OFFSET 0x10
#define CORDIC_Z_IN_REG_RESVAL 0x0u

// Signed fixed-point X output result.
#define CORDIC_X_OUT_REG_OFFSET 0x14
#define CORDIC_X_OUT_REG_RESVAL 0x0u

// Signed fixed-point Y output result.
#define CORDIC_Y_OUT_REG_OFFSET 0x18
#define CORDIC_Y_OUT_REG_RESVAL 0x0u

// Signed fixed-point Z output result.
#define CORDIC_Z_OUT_REG_OFFSET 0x1c
#define CORDIC_Z_OUT_REG_RESVAL 0x0u

// Configuration register for implementation options.
#define CORDIC_CFG_REG_OFFSET 0x20
#define CORDIC_CFG_REG_RESVAL 0x0u
#define CORDIC_CFG_DATA_WIDTH_MASK 0xffu
#define CORDIC_CFG_DATA_WIDTH_OFFSET 0
#define CORDIC_CFG_DATA_WIDTH_FIELD \
  ((bitfield_field32_t) { .mask = CORDIC_CFG_DATA_WIDTH_MASK, .index = CORDIC_CFG_DATA_WIDTH_OFFSET })
#define CORDIC_CFG_FRAC_WIDTH_MASK 0xffu
#define CORDIC_CFG_FRAC_WIDTH_OFFSET 8
#define CORDIC_CFG_FRAC_WIDTH_FIELD \
  ((bitfield_field32_t) { .mask = CORDIC_CFG_FRAC_WIDTH_MASK, .index = CORDIC_CFG_FRAC_WIDTH_OFFSET })
#define CORDIC_CFG_MAX_ITER_MASK 0xffu
#define CORDIC_CFG_MAX_ITER_OFFSET 16
#define CORDIC_CFG_MAX_ITER_FIELD \
  ((bitfield_field32_t) { .mask = CORDIC_CFG_MAX_ITER_MASK, .index = CORDIC_CFG_MAX_ITER_OFFSET })
#define CORDIC_CFG_RSVD_MASK 0xffu
#define CORDIC_CFG_RSVD_OFFSET 24
#define CORDIC_CFG_RSVD_FIELD \
  ((bitfield_field32_t) { .mask = CORDIC_CFG_RSVD_MASK, .index = CORDIC_CFG_RSVD_OFFSET })

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _CORDIC_REG_DEFS_
// End generated register defines for cordic