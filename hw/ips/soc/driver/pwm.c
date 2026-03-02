#include "pwm.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(addr)) = (val))
#define DEV_READ(addr) (*((volatile uint32_t *)(addr)))

int pwm_init(pwm_t pwm) {
  DEV_WRITE(pwm + PWM_CTRL_REG_OFFSET, 0x1);
  return 0;
}

int pwm_in(pwm_t pwm) {
  int res = -1;
  res = DEV_READ(pwm + PWM_RDATA_REG_OFFSET);
  return res;
}

void pwm_out(pwm_t pwm, char c) {
  DEV_WRITE(pwm + PWM_WDATA_REG_OFFSET, c);
}

int pwm_putchar(int c) {
  pwm_out((pwm_t) PWM_BASE, c);
  return c;
}

int pwm_puts(const char* str) {
  while (*str) {
    pwm_putchar(*str++);
  }
  return 0;
}