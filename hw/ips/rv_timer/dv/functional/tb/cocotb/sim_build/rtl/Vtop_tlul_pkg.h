// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_TLUL_PKG_H_
#define VERILATED_VTOP_TLUL_PKG_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"
#include "verilated_covergroup.h"
#include "verilated_timing.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_tlul_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;
    uint32_t __Vcoverage[31]{};

    // PARAMETERS
    static constexpr SData/*13:0*/ TL_D_USER_DEFAULT = 0x3fffU;
    static constexpr IData/*23:0*/ ArbiterImpl = 0x00505043U;
    static constexpr IData/*31:0*/ H2DCmdMaxWidth = 0x00000039U;
    static constexpr IData/*31:0*/ H2DCmdIntgWidth = 7U;
    static constexpr IData/*31:0*/ H2DCmdFullWidth = 0x00000040U;
    static constexpr IData/*31:0*/ D2HRspMaxWidth = 0x00000039U;
    static constexpr IData/*31:0*/ D2HRspIntgWidth = 7U;
    static constexpr IData/*31:0*/ D2HRspFullWidth = 0x00000040U;
    static constexpr IData/*31:0*/ DataMaxWidth = 0x00000020U;
    static constexpr IData/*31:0*/ DataIntgWidth = 7U;
    static constexpr IData/*31:0*/ DataFullWidth = 0x00000027U;
    static constexpr IData/*31:0*/ DataWhenInstrError = 0U;
    static constexpr IData/*31:0*/ DataWhenError = 0xffffffffU;
    static constexpr IData/*22:0*/ TL_A_USER_DEFAULT = 0x00027fffU;
    static constexpr IData/*31:0*/ BlankedAData = 0xffffffffU;
    static constexpr VlWide<4>/*108:0*/ TL_H2D_DEFAULT = VlWide<4>{{0xff04ffff, 0x00ffffff, 0x00000000, 0x00000000}};
    static constexpr VlWide<3>/*65:0*/ TL_D2H_DEFAULT = VlWide<3>{{0x0000fffd, 0x00000000, 0x00000000}};

    // CONSTRUCTORS
    Vtop_tlul_pkg();
    ~Vtop_tlul_pkg();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_tlul_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp,
        const char* fsmVarp, const char* fsmFromp, const char* fsmTop, const char* fsmTagp);
    void __vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
};


#endif  // guard
