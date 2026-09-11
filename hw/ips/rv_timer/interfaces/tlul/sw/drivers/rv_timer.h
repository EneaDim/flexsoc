/**
 * @file
 * @brief Generated register defines for rv_timer
 */

// Copyright information found in source file:
// Copyright lowRISC contributors (OpenTitan project).

// Licensing information found in source file:
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#ifndef _RV_TIMER_REG_DEFS_
#define _RV_TIMER_REG_DEFS_


#include <stdint.h>

#define RV_TIMER_BASE 0x80000000

typedef uintptr_t rv_timer_t;
int rv_timer_init(rv_timer_t base);
int rv_timer_in(rv_timer_t base);
void rv_timer_out(rv_timer_t base, char c);
int rv_timer_putchar(int c);
int rv_timer_puts(const char* str);

#ifdef __cplusplus
extern "C" {
#endif
// Number of harts
#define RV_TIMER_PARAM_N_HARTS 1

// Number of timers per Hart
#define RV_TIMER_PARAM_N_TIMERS 1

// Register width
#define RV_TIMER_PARAM_REG_WIDTH 32

// Control register (common parameters)
#define RV_TIMER_CTRL_ACTIVE_FIELD_WIDTH 1
#define RV_TIMER_CTRL_GPIO_INTR_0_FIELD_WIDTH 1
#define RV_TIMER_CTRL_GPIO_INTR_1_FIELD_WIDTH 1
#define RV_TIMER_CTRL_MULTIREG_COUNT 1

// Control register
#define RV_TIMER_CTRL_REG_OFFSET 0x0
#define RV_TIMER_CTRL_REG_RESVAL 0x0u
#define RV_TIMER_CTRL_ACTIVE_0_BIT 0
#define RV_TIMER_CTRL_GPIO_INTR_0_0_BIT 1
#define RV_TIMER_CTRL_GPIO_INTR_1_0_BIT 2

// Interrupt Enable (common parameters)
#define RV_TIMER_INTR_ENABLE0_IE_FIELD_WIDTH 1
#define RV_TIMER_INTR_ENABLE0_MULTIREG_COUNT 1

// Interrupt Enable
#define RV_TIMER_INTR_ENABLE0_REG_OFFSET 0x4
#define RV_TIMER_INTR_ENABLE0_REG_RESVAL 0x0u
#define RV_TIMER_INTR_ENABLE0_IE_0_BIT 0

// Interrupt Status (common parameters)
#define RV_TIMER_INTR_STATE0_IS_FIELD_WIDTH 1
#define RV_TIMER_INTR_STATE0_MULTIREG_COUNT 1

// Interrupt Status
#define RV_TIMER_INTR_STATE0_REG_OFFSET 0x8
#define RV_TIMER_INTR_STATE0_REG_RESVAL 0x0u
#define RV_TIMER_INTR_STATE0_IS_0_BIT 0

// Interrupt test register (common parameters)
#define RV_TIMER_INTR_TEST0_T_FIELD_WIDTH 1
#define RV_TIMER_INTR_TEST0_MULTIREG_COUNT 1

// Interrupt test register
#define RV_TIMER_INTR_TEST0_REG_OFFSET 0xc
#define RV_TIMER_INTR_TEST0_REG_RESVAL 0x0u
#define RV_TIMER_INTR_TEST0_T_0_BIT 0

// Configuration for Hart 0
#define RV_TIMER_CFG0_REG_OFFSET 0x10
#define RV_TIMER_CFG0_REG_RESVAL 0x10000u
#define RV_TIMER_CFG0_PRESCALE_MASK 0xfffu
#define RV_TIMER_CFG0_PRESCALE_OFFSET 0
#define RV_TIMER_CFG0_PRESCALE_FIELD \
  ((bitfield_field32_t) { .mask = RV_TIMER_CFG0_PRESCALE_MASK, .index = RV_TIMER_CFG0_PRESCALE_OFFSET })
#define RV_TIMER_CFG0_STEP_MASK 0xffu
#define RV_TIMER_CFG0_STEP_OFFSET 16
#define RV_TIMER_CFG0_STEP_FIELD \
  ((bitfield_field32_t) { .mask = RV_TIMER_CFG0_STEP_MASK, .index = RV_TIMER_CFG0_STEP_OFFSET })

// Timer value
#define RV_TIMER_TIMER_V0_REG_OFFSET 0x14
#define RV_TIMER_TIMER_V0_REG_RESVAL 0x0u

// Timer value to compare
#define RV_TIMER_COMPARE_V0_REG_OFFSET 0x18
#define RV_TIMER_COMPARE_V0_REG_RESVAL 0xffffffffu

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _RV_TIMER_REG_DEFS_
// End generated register defines for rv_timer