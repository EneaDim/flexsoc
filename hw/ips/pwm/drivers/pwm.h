/**
 * @file
 * @brief Generated register defines for pwm
 */

// Copyright information found in source file:
// Copyright lowRISC contributors (OpenTitan project).

// Licensing information found in source file:
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#ifndef _PWM_REG_DEFS_
#define _PWM_REG_DEFS_


#include <stdint.h>

#define PWM_BASE 0x80000000

typedef uintptr_t pwm_t;
int pwm_init(pwm_t base);
int pwm_in(pwm_t base);
void pwm_out(pwm_t base, char c);
int pwm_putchar(int c);
int pwm_puts(const char* str);

#ifdef __cplusplus
extern "C" {
#endif
// Number of PWM outputs
#define PWM_PARAM_N_OUTPUTS 1

// Register width
#define PWM_PARAM_REG_WIDTH 32

// Configuration register
#define PWM_CFG_REG_OFFSET 0x0
#define PWM_CFG_REG_RESVAL 0x38008000u
#define PWM_CFG_CLK_DIV_MASK 0x7ffffffu
#define PWM_CFG_CLK_DIV_OFFSET 0
#define PWM_CFG_CLK_DIV_FIELD \
  ((bitfield_field32_t) { .mask = PWM_CFG_CLK_DIV_MASK, .index = PWM_CFG_CLK_DIV_OFFSET })
#define PWM_CFG_DC_RESN_MASK 0xfu
#define PWM_CFG_DC_RESN_OFFSET 27
#define PWM_CFG_DC_RESN_FIELD \
  ((bitfield_field32_t) { .mask = PWM_CFG_DC_RESN_MASK, .index = PWM_CFG_DC_RESN_OFFSET })
#define PWM_CFG_CNTR_EN_BIT 31

// Enable PWM operation for each channel (common parameters)
#define PWM_PWM_EN_EN_FIELD_WIDTH 1
#define PWM_PWM_EN_MULTIREG_COUNT 1

// Enable PWM operation for each channel
#define PWM_PWM_EN_REG_OFFSET 0x4
#define PWM_PWM_EN_REG_RESVAL 0x0u
#define PWM_PWM_EN_EN_0_BIT 0

// Basic PWM Channel Parameters (common parameters)
#define PWM_PWM_PARAM_PHASE_DELAY_FIELD_WIDTH 16
#define PWM_PWM_PARAM_DUTY_CYCLE_FIELD_WIDTH 16
#define PWM_PWM_PARAM_MULTIREG_COUNT 1

// Basic PWM Channel Parameters
#define PWM_PWM_PARAM_REG_OFFSET 0x8
#define PWM_PWM_PARAM_REG_RESVAL 0x7fff0000u
#define PWM_PWM_PARAM_PHASE_DELAY_0_MASK 0xffffu
#define PWM_PWM_PARAM_PHASE_DELAY_0_OFFSET 0
#define PWM_PWM_PARAM_PHASE_DELAY_0_FIELD \
  ((bitfield_field32_t) { .mask = PWM_PWM_PARAM_PHASE_DELAY_0_MASK, .index = PWM_PWM_PARAM_PHASE_DELAY_0_OFFSET })
#define PWM_PWM_PARAM_DUTY_CYCLE_0_MASK 0xffffu
#define PWM_PWM_PARAM_DUTY_CYCLE_0_OFFSET 16
#define PWM_PWM_PARAM_DUTY_CYCLE_0_FIELD \
  ((bitfield_field32_t) { .mask = PWM_PWM_PARAM_DUTY_CYCLE_0_MASK, .index = PWM_PWM_PARAM_DUTY_CYCLE_0_OFFSET })

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _PWM_REG_DEFS_
// End generated register defines for pwm