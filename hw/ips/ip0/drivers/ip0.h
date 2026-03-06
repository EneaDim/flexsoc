/**
 * @file
 * @brief Generated register defines for ip0
 */

#ifndef _IP0_REG_DEFS_
#define _IP0_REG_DEFS_


#include <stdint.h>

#define IP0_BASE 0x80000000

typedef void* ip0_t;
int ip0_init(ip0_t ip0);
int ip0_in(ip0_t ip0);
void ip0_out(ip0_t ip0, char c);
int ip0_putchar(int c);
int ip0_puts(const char* str);

#ifdef __cplusplus
extern "C" {
#endif
// Register width
#define IP0_PARAM_REG_WIDTH 32

// Control register
#define IP0_CTRL_REG_OFFSET 0x0
#define IP0_CTRL_REG_RESVAL 0x0u
#define IP0_CTRL_EN_BIT 0
#define IP0_CTRL_RST_BIT 1
#define IP0_CTRL_SETTING_MASK 0xffffu
#define IP0_CTRL_SETTING_OFFSET 16
#define IP0_CTRL_SETTING_FIELD \
  ((bitfield_field32_t) { .mask = IP0_CTRL_SETTING_MASK, .index = IP0_CTRL_SETTING_OFFSET })

// Status register
#define IP0_STATUS_REG_OFFSET 0x4
#define IP0_STATUS_REG_RESVAL 0x0u
#define IP0_STATUS_FULL_BIT 0
#define IP0_STATUS_EMPTY_BIT 1

// read data
#define IP0_RDATA_REG_OFFSET 0x8
#define IP0_RDATA_REG_RESVAL 0x0u
#define IP0_RDATA_RDATA_MASK 0xffu
#define IP0_RDATA_RDATA_OFFSET 0
#define IP0_RDATA_RDATA_FIELD \
  ((bitfield_field32_t) { .mask = IP0_RDATA_RDATA_MASK, .index = IP0_RDATA_RDATA_OFFSET })

// write data
#define IP0_WDATA_REG_OFFSET 0xc
#define IP0_WDATA_REG_RESVAL 0x0u
#define IP0_WDATA_WDATA_MASK 0xffu
#define IP0_WDATA_WDATA_OFFSET 0
#define IP0_WDATA_WDATA_FIELD \
  ((bitfield_field32_t) { .mask = IP0_WDATA_WDATA_MASK, .index = IP0_WDATA_WDATA_OFFSET })

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _IP0_REG_DEFS_
// End generated register defines for ip0