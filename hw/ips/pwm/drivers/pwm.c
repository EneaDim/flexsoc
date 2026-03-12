#include "pwm.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(uintptr_t)(addr)) = (uint32_t)(val))
#define DEV_READ(addr) (*((volatile uint32_t *)(uintptr_t)(addr)))

int pwm_init(pwm_t base) {
#ifdef PWM_CTRL_REG_OFFSET
  DEV_WRITE(base + PWM_CTRL_REG_OFFSET, 0x1u);
#else
  DEV_WRITE(base + 0x0u, 0x1u);
#endif
  return 0;
}

int pwm_in(pwm_t base) {
#ifdef PWM_RDATA_REG_OFFSET
  return (int)DEV_READ(base + PWM_RDATA_REG_OFFSET);
#else
  return (int)DEV_READ(base + 0x0u);
#endif
}

void pwm_out(pwm_t base, char c) {
#ifdef PWM_WDATA_REG_OFFSET
  DEV_WRITE(base + PWM_WDATA_REG_OFFSET, (uint32_t)(uint8_t)c);
#else
  DEV_WRITE(base + 0x0u, (uint32_t)(uint8_t)c);
#endif
}

int pwm_putchar(int c) {
  pwm_out((pwm_t)PWM_BASE, (char)c);
  return c;
}

int pwm_puts(const char* str) {
  while (*str) {
    pwm_putchar(*str++);
  }
  return 0;
}
