// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_TOP_PKG_H_
#define VERILATED_VTOP_TOP_PKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_top_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ TL_AW = 0x00000020U;
    static constexpr IData/*31:0*/ TL_DW = 0x00000020U;
    static constexpr IData/*31:0*/ TL_AIW = 8U;
    static constexpr IData/*31:0*/ TL_DIW = 1U;
    static constexpr IData/*31:0*/ TL_AUW = 0x00000015U;
    static constexpr IData/*31:0*/ TL_DUW = 0x0000000eU;
    static constexpr IData/*31:0*/ TL_DBW = 4U;
    static constexpr IData/*31:0*/ TL_SZW = 2U;
    static constexpr IData/*31:0*/ SecVolatileRawUnlockEn = 0U;

    // CONSTRUCTORS
    Vtop_top_pkg() = default;
    ~Vtop_top_pkg() = default;
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_top_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
