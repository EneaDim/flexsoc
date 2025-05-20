// Generated register defines for pwm_ramp

#ifndef _PWM_RAMP_REG_DEFS_
#define _PWM_RAMP_REG_DEFS_

#ifdef __cplusplus
extern "C" {
#endif
// Register width
#define PWM_RAMP_PARAM_REG_WIDTH 32

// UART control register
#define PWM_RAMP_CTRL_REG_OFFSET 0x0
#define PWM_RAMP_CTRL_REG_RESVAL 0x0u
#define PWM_RAMP_CTRL_EN_BIT 0
#define PWM_RAMP_CTRL_RST_BIT 1
#define PWM_RAMP_CTRL_SETTING_MASK 0xffffu
#define PWM_RAMP_CTRL_SETTING_OFFSET 16
#define PWM_RAMP_CTRL_SETTING_FIELD \
  ((bitfield_field32_t) { .mask = PWM_RAMP_CTRL_SETTING_MASK, .index = PWM_RAMP_CTRL_SETTING_OFFSET })

// UART live status register
#define PWM_RAMP_STATUS_REG_OFFSET 0x4
#define PWM_RAMP_STATUS_REG_RESVAL 0x0u
#define PWM_RAMP_STATUS_FULL_BIT 0
#define PWM_RAMP_STATUS_EMPTY_BIT 1

// read data
#define PWM_RAMP_RDATA_REG_OFFSET 0x8
#define PWM_RAMP_RDATA_REG_RESVAL 0x0u
#define PWM_RAMP_RDATA_RDATA_MASK 0xffu
#define PWM_RAMP_RDATA_RDATA_OFFSET 0
#define PWM_RAMP_RDATA_RDATA_FIELD \
  ((bitfield_field32_t) { .mask = PWM_RAMP_RDATA_RDATA_MASK, .index = PWM_RAMP_RDATA_RDATA_OFFSET })

// write data
#define PWM_RAMP_WDATA_REG_OFFSET 0xc
#define PWM_RAMP_WDATA_REG_RESVAL 0x0u
#define PWM_RAMP_WDATA_WDATA_MASK 0xffu
#define PWM_RAMP_WDATA_WDATA_OFFSET 0
#define PWM_RAMP_WDATA_WDATA_FIELD \
  ((bitfield_field32_t) { .mask = PWM_RAMP_WDATA_WDATA_MASK, .index = PWM_RAMP_WDATA_WDATA_OFFSET })

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _PWM_RAMP_REG_DEFS_
// End generated register defines for pwm_ramp