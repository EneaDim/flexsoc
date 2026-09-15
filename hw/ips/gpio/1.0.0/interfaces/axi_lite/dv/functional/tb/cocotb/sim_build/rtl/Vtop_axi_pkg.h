// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_AXI_PKG_H_
#define VERILATED_VTOP_AXI_PKG_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"
#include "verilated_covergroup.h"
#include "verilated_timing.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_axi_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;
    uint32_t __Vcoverage[79]{};

    // PARAMETERS
    static constexpr CData/*1:0*/ BURST_FIXED = 0U;
    static constexpr CData/*1:0*/ BURST_INCR = 1U;
    static constexpr CData/*1:0*/ BURST_WRAP = 2U;
    static constexpr CData/*1:0*/ RESP_OKAY = 0U;
    static constexpr CData/*1:0*/ RESP_EXOKAY = 1U;
    static constexpr CData/*1:0*/ RESP_SLVERR = 2U;
    static constexpr CData/*1:0*/ RESP_DECERR = 3U;
    static constexpr CData/*3:0*/ CACHE_BUFFERABLE = 1U;
    static constexpr CData/*3:0*/ CACHE_MODIFIABLE = 2U;
    static constexpr CData/*3:0*/ CACHE_RD_ALLOC = 4U;
    static constexpr CData/*3:0*/ CACHE_WR_ALLOC = 8U;
    static constexpr CData/*5:0*/ ATOP_ATOMICSWAP = 0x30U;
    static constexpr CData/*5:0*/ ATOP_ATOMICCMP = 0x31U;
    static constexpr CData/*1:0*/ ATOP_NONE = 0U;
    static constexpr CData/*1:0*/ ATOP_ATOMICSTORE = 1U;
    static constexpr CData/*1:0*/ ATOP_ATOMICLOAD = 2U;
    static constexpr CData/*0:0*/ ATOP_LITTLE_END = 0U;
    static constexpr CData/*0:0*/ ATOP_BIG_END = 1U;
    static constexpr CData/*2:0*/ ATOP_ADD = 0U;
    static constexpr CData/*2:0*/ ATOP_CLR = 1U;
    static constexpr CData/*2:0*/ ATOP_EOR = 2U;
    static constexpr CData/*2:0*/ ATOP_SET = 3U;
    static constexpr CData/*2:0*/ ATOP_SMAX = 4U;
    static constexpr CData/*2:0*/ ATOP_SMIN = 5U;
    static constexpr CData/*2:0*/ ATOP_UMAX = 6U;
    static constexpr CData/*2:0*/ ATOP_UMIN = 7U;
    static constexpr SData/*9:0*/ DemuxAw = 0x0200U;
    static constexpr SData/*9:0*/ DemuxW = 0x0100U;
    static constexpr SData/*9:0*/ DemuxB = 0x0080U;
    static constexpr SData/*9:0*/ DemuxAr = 0x0040U;
    static constexpr SData/*9:0*/ DemuxR = 0x0020U;
    static constexpr SData/*9:0*/ MuxAw = 0x0010U;
    static constexpr SData/*9:0*/ MuxW = 8U;
    static constexpr SData/*9:0*/ MuxB = 4U;
    static constexpr SData/*9:0*/ MuxAr = 2U;
    static constexpr SData/*9:0*/ MuxR = 1U;
    static constexpr IData/*31:0*/ BurstWidth = 2U;
    static constexpr IData/*31:0*/ RespWidth = 2U;
    static constexpr IData/*31:0*/ CacheWidth = 4U;
    static constexpr IData/*31:0*/ ProtWidth = 3U;
    static constexpr IData/*31:0*/ QosWidth = 4U;
    static constexpr IData/*31:0*/ RegionWidth = 4U;
    static constexpr IData/*31:0*/ LenWidth = 8U;
    static constexpr IData/*31:0*/ SizeWidth = 3U;
    static constexpr IData/*31:0*/ LockWidth = 1U;
    static constexpr IData/*31:0*/ AtopWidth = 6U;
    static constexpr IData/*31:0*/ NsaidWidth = 4U;
    static constexpr IData/*31:0*/ ATOP_R_RESP = 5U;

    // CONSTRUCTORS
    Vtop_axi_pkg();
    ~Vtop_axi_pkg();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_axi_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp,
        const char* fsmVarp, const char* fsmFromp, const char* fsmTop, const char* fsmTagp);
    void __vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
};


#endif  // guard
