#include "pwm_ramp.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(addr)) = (val))
#define DEV_READ(addr) (*((volatile uint32_t *)(addr)))

int pwm_ramp_init(pwm_ramp_t pwm_ramp) {
  DEV_WRITE(pwm_ramp + PWM_RAMP_CTRL_REG_OFFSET, 0x1);
  return 0;
}

int pwm_ramp_in(pwm_ramp_t pwm_ramp) {
  int res = -1;
  res = DEV_READ(pwm_ramp + PWM_RAMP_RDATA_REG_OFFSET);
  return res;
}

void pwm_ramp_out(pwm_ramp_t pwm_ramp, char c) {
  DEV_WRITE(pwm_ramp + PWM_RAMP_WDATA_REG_OFFSET, c);
}

int pwm_ramp_putchar(int c) {
  pwm_ramp_out((pwm_ramp_t) PWM_RAMP_BASE, c);
  return c;
}

int pwm_ramp_puts(const char* str) {
  while (*str) {
    pwm_ramp_putchar(*str++);
  }
  return 0;
}