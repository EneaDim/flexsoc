/**
 * @file
 * @brief Generated register defines for my_ip
 */

#ifndef _MY_IP_REG_DEFS_
#define _MY_IP_REG_DEFS_


#include <stdint.h>

#define MY_IP_BASE 0x80000000

typedef void* my_ip_t;
int my_ip_init(my_ip_t my_ip);
int my_ip_in(my_ip_t my_ip);
void my_ip_out(my_ip_t my_ip, char c);
int my_ip_putchar(int c);
int my_ip_puts(const char* str);

#ifdef __cplusplus
extern "C" {
#endif
// Register width
#define MY_IP_PARAM_REG_WIDTH 32

// Control register
#define MY_IP_CTRL_REG_OFFSET 0x0
#define MY_IP_CTRL_REG_RESVAL 0x0u
#define MY_IP_CTRL_EN_BIT 0
#define MY_IP_CTRL_RST_BIT 1
#define MY_IP_CTRL_SETTING_MASK 0xffffu
#define MY_IP_CTRL_SETTING_OFFSET 16
#define MY_IP_CTRL_SETTING_FIELD \
  ((bitfield_field32_t) { .mask = MY_IP_CTRL_SETTING_MASK, .index = MY_IP_CTRL_SETTING_OFFSET })

// Status register
#define MY_IP_STATUS_REG_OFFSET 0x4
#define MY_IP_STATUS_REG_RESVAL 0x0u
#define MY_IP_STATUS_FULL_BIT 0
#define MY_IP_STATUS_EMPTY_BIT 1

// read data
#define MY_IP_RDATA_REG_OFFSET 0x8
#define MY_IP_RDATA_REG_RESVAL 0x0u
#define MY_IP_RDATA_RDATA_MASK 0xffu
#define MY_IP_RDATA_RDATA_OFFSET 0
#define MY_IP_RDATA_RDATA_FIELD \
  ((bitfield_field32_t) { .mask = MY_IP_RDATA_RDATA_MASK, .index = MY_IP_RDATA_RDATA_OFFSET })

// write data
#define MY_IP_WDATA_REG_OFFSET 0xc
#define MY_IP_WDATA_REG_RESVAL 0x0u
#define MY_IP_WDATA_WDATA_MASK 0xffu
#define MY_IP_WDATA_WDATA_OFFSET 0
#define MY_IP_WDATA_WDATA_FIELD \
  ((bitfield_field32_t) { .mask = MY_IP_WDATA_WDATA_MASK, .index = MY_IP_WDATA_WDATA_OFFSET })

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _MY_IP_REG_DEFS_
// End generated register defines for my_ip