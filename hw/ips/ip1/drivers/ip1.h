/**
 * @file
 * @brief Generated register defines for ip1
 */

#ifndef _IP1_REG_DEFS_
#define _IP1_REG_DEFS_


#include <stdint.h>

#define IP1_BASE 0x80000000

typedef void* ip1_t;
int ip1_init(ip1_t ip1);
int ip1_in(ip1_t ip1);
void ip1_out(ip1_t ip1, char c);
int ip1_putchar(int c);
int ip1_puts(const char* str);

#ifdef __cplusplus
extern "C" {
#endif
// Register width
#define IP1_PARAM_REG_WIDTH 32

// Control register
#define IP1_CTRL_REG_OFFSET 0x0
#define IP1_CTRL_REG_RESVAL 0x0u
#define IP1_CTRL_EN_BIT 0
#define IP1_CTRL_RST_BIT 1
#define IP1_CTRL_SETTING_MASK 0xffffu
#define IP1_CTRL_SETTING_OFFSET 16
#define IP1_CTRL_SETTING_FIELD \
  ((bitfield_field32_t) { .mask = IP1_CTRL_SETTING_MASK, .index = IP1_CTRL_SETTING_OFFSET })

// Status register
#define IP1_STATUS_REG_OFFSET 0x4
#define IP1_STATUS_REG_RESVAL 0x0u
#define IP1_STATUS_FULL_BIT 0
#define IP1_STATUS_EMPTY_BIT 1

// read data
#define IP1_RDATA_REG_OFFSET 0x8
#define IP1_RDATA_REG_RESVAL 0x0u
#define IP1_RDATA_RDATA_MASK 0xffu
#define IP1_RDATA_RDATA_OFFSET 0
#define IP1_RDATA_RDATA_FIELD \
  ((bitfield_field32_t) { .mask = IP1_RDATA_RDATA_MASK, .index = IP1_RDATA_RDATA_OFFSET })

// write data
#define IP1_WDATA_REG_OFFSET 0xc
#define IP1_WDATA_REG_RESVAL 0x0u
#define IP1_WDATA_WDATA_MASK 0xffu
#define IP1_WDATA_WDATA_OFFSET 0
#define IP1_WDATA_WDATA_FIELD \
  ((bitfield_field32_t) { .mask = IP1_WDATA_WDATA_MASK, .index = IP1_WDATA_WDATA_OFFSET })

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _IP1_REG_DEFS_
// End generated register defines for ip1