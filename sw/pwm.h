#ifndef PWM_H
#define PWM_H

#include <stdint.h>

#define PWM_BASE 0x80020000

typedef void* pwm_t;
int  pwm_init(pwm_t pwm);
int  pwm_deinit(pwm_t pwm);
void pwm_enable(pwm_t pwm);


#ifdef __cplusplus
}  // extern "C"
#endif
#endif
