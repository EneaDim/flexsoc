#include "pwm.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(addr)) = (val))
#define DEV_READ(addr) (*((volatile uint32_t *)(addr)))

int pwm_init(pwm_t pwm_base) {
  DEV_WRITE(pwm_base + 0x8, 0xB8000010);  // Phase cnt enable, dc_res = 7, clk_div
  DEV_WRITE(pwm_base + 0x14, 0xF); // Phase delay
  DEV_WRITE(pwm_base + 0xc, 0x1);   // ENable
  return 0;
}

int pwm_deinit(pwm_t pwm_base) {
  DEV_WRITE(pwm_base + 0xc, 0x0);
  return 0;
}


