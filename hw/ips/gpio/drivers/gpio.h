/**
 * @file
 * @brief Generated register defines for gpio
 */

#ifndef _GPIO_REG_DEFS_
#define _GPIO_REG_DEFS_


#include <stdint.h>

#define GPIO_BASE 0x0

typedef uintptr_t gpio_t;
int gpio_init(gpio_t base);
int gpio_in(gpio_t base);
void gpio_out(gpio_t base, char c);
int gpio_putchar(int c);
int gpio_puts(const char* str);

#ifdef __cplusplus
extern "C" {
#endif
// Register width
#define GPIO_PARAM_REG_WIDTH 32

// Current filtered GPIO input value.
#define GPIO_DATA_IN_REG_OFFSET 0x0
#define GPIO_DATA_IN_REG_RESVAL 0x0u
#define GPIO_DATA_IN_GPIO_IN_MASK 0xfu
#define GPIO_DATA_IN_GPIO_IN_OFFSET 0
#define GPIO_DATA_IN_GPIO_IN_FIELD \
  ((bitfield_field32_t) { .mask = GPIO_DATA_IN_GPIO_IN_MASK, .index = GPIO_DATA_IN_GPIO_IN_OFFSET })

// Direct GPIO output values and output enables.
#define GPIO_DIRECT_REG_OFFSET 0x4
#define GPIO_DIRECT_REG_RESVAL 0x0u
#define GPIO_DIRECT_GPIO_O_MASK 0xfu
#define GPIO_DIRECT_GPIO_O_OFFSET 0
#define GPIO_DIRECT_GPIO_O_FIELD \
  ((bitfield_field32_t) { .mask = GPIO_DIRECT_GPIO_O_MASK, .index = GPIO_DIRECT_GPIO_O_OFFSET })
#define GPIO_DIRECT_GPIO_OE_MASK 0xfu
#define GPIO_DIRECT_GPIO_OE_OFFSET 4
#define GPIO_DIRECT_GPIO_OE_FIELD \
  ((bitfield_field32_t) { .mask = GPIO_DIRECT_GPIO_OE_MASK, .index = GPIO_DIRECT_GPIO_OE_OFFSET })

// Per-input interrupt detection and input-filter enables.
#define GPIO_INTR_CTRL_REG_OFFSET 0x8
#define GPIO_INTR_CTRL_REG_RESVAL 0x0u
#define GPIO_INTR_CTRL_EN_RISING_MASK 0xfu
#define GPIO_INTR_CTRL_EN_RISING_OFFSET 0
#define GPIO_INTR_CTRL_EN_RISING_FIELD \
  ((bitfield_field32_t) { .mask = GPIO_INTR_CTRL_EN_RISING_MASK, .index = GPIO_INTR_CTRL_EN_RISING_OFFSET })
#define GPIO_INTR_CTRL_EN_FALLING_MASK 0xfu
#define GPIO_INTR_CTRL_EN_FALLING_OFFSET 4
#define GPIO_INTR_CTRL_EN_FALLING_FIELD \
  ((bitfield_field32_t) { .mask = GPIO_INTR_CTRL_EN_FALLING_MASK, .index = GPIO_INTR_CTRL_EN_FALLING_OFFSET })
#define GPIO_INTR_CTRL_EN_LVLHIGH_MASK 0xfu
#define GPIO_INTR_CTRL_EN_LVLHIGH_OFFSET 8
#define GPIO_INTR_CTRL_EN_LVLHIGH_FIELD \
  ((bitfield_field32_t) { .mask = GPIO_INTR_CTRL_EN_LVLHIGH_MASK, .index = GPIO_INTR_CTRL_EN_LVLHIGH_OFFSET })
#define GPIO_INTR_CTRL_EN_LVLLOW_MASK 0xfu
#define GPIO_INTR_CTRL_EN_LVLLOW_OFFSET 12
#define GPIO_INTR_CTRL_EN_LVLLOW_FIELD \
  ((bitfield_field32_t) { .mask = GPIO_INTR_CTRL_EN_LVLLOW_MASK, .index = GPIO_INTR_CTRL_EN_LVLLOW_OFFSET })
#define GPIO_INTR_CTRL_EN_INPUT_FILTER_MASK 0xfu
#define GPIO_INTR_CTRL_EN_INPUT_FILTER_OFFSET 16
#define GPIO_INTR_CTRL_EN_INPUT_FILTER_FIELD \
  ((bitfield_field32_t) { .mask = GPIO_INTR_CTRL_EN_INPUT_FILTER_MASK, .index = GPIO_INTR_CTRL_EN_INPUT_FILTER_OFFSET })

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _GPIO_REG_DEFS_
// End generated register defines for gpio